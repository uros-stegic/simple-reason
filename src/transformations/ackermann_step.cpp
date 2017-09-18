#include <ackermann_step.hpp>
#include <formulae.hpp>
#include <algorithm>
#include <numeric>
#include <stdexcept>
#include <sstream>

using namespace art;

void print_table(const std::map<Term, Term, TermCompare>& sym)
{
	std::cout << "substitutions: [";
	for(auto&& eq : sym) {
		std::cout << eq.first << " := " << eq.second << ", ";
	}
	std::cout << "]" << std::endl;
}

AckermannStep::AckermannStep()
	: next(0)
{}

Formula AckermannStep::transform(const Formula& f) const
{
	auto res = extract(f);
	//print_table(m_symbols);
	auto fml = reduce();
	return std::make_shared<If>(fml, res);
}

Formula AckermannStep::extract(const Formula& f) const
{
	switch( f->get_type() ) {
		case NEGATION: {
			auto l = extract(static_cast<const Not*>(f.get())->get_operand());
			return std::make_shared<Not>(l);
		}
		case CONJUNCTION: {
			auto l = extract(static_cast<const And*>(f.get())->get_left_operand());
			auto r = extract(static_cast<const And*>(f.get())->get_right_operand());
			return std::make_shared<And>(l, r);
		}

		case DISJUNCTION: {
			auto l = extract(static_cast<const Or*>(f.get())->get_left_operand());
			auto r = extract(static_cast<const Or*>(f.get())->get_right_operand());
			return std::make_shared<Or>(l, r);
		}

		case IMPLICATION: {
			auto l = extract(static_cast<const If*>(f.get())->get_left_operand());
			auto r = extract(static_cast<const If*>(f.get())->get_right_operand());
			return std::make_shared<If>(l, r);
		}

		case EQUIVALENCE: {
			auto l = extract(static_cast<const Iff*>(f.get())->get_left_operand());
			auto r = extract(static_cast<const Iff*>(f.get())->get_right_operand());
			return std::make_shared<Iff>(l, r);
		}
		case EXISTS:
		case FOR_ALL: {
			throw new std::runtime_error("Cannot perform Ackermann's transformation on quantified formulas.");
		}
		default: {
			return f->copy();
		}
		case PREDICATE: {
			const Predicate* th = static_cast<const Predicate*>(f.get());

			std::vector<Term> new_terms;
			auto terms = th->terms();
			std::back_insert_iterator<std::vector<Term>> new_iter(new_terms);
			std::transform(
				std::begin(terms),
				std::end(terms),
				new_iter,
				[this](const Term& t) {
					return extract(t);
				}
			);
			
			return std::make_shared<Predicate>(new_terms, th->name());
		}
		case EQUALS: {
			const Equals* th = static_cast<const Equals*>(f.get());

			std::vector<Term> new_terms;
			auto terms = th->terms();
			std::transform(
				std::begin(terms),
				std::end(terms),
				std::back_insert_iterator<std::vector<Term>>(new_terms),
				[this](const Term& t) {
					return extract(t);
				}
			);
			
			return std::make_shared<Equals>(new_terms[0], new_terms[1]);
		}
		case NOT_EQUALS: {
			const NotEquals* th = static_cast<const NotEquals*>(f.get());

			std::vector<Term> new_terms;
			auto terms = th->terms();
			std::transform(
				std::begin(terms),
				std::end(terms),
				std::back_insert_iterator<std::vector<Term>>(new_terms),
				[this](const Term& t) {
					return extract(t);
				}
			);
			
			return std::make_shared<NotEquals>(new_terms[0], new_terms[1]);
		}
	}
}

Term AckermannStep::extract(const Term& t) const
{
	switch( t->get_type() ) {
		case FUNCTION: {
			const Function* th = static_cast<const Function*>(t.get());

			std::vector<Term> new_terms;
			auto terms = th->terms();
			std::transform(
				std::begin(terms),
				std::end(terms),
				std::back_insert_iterator<std::vector<Term>>(new_terms),
				[this](const Term& t) {
					auto rr = extract(t);
					auto syn = m_symbols.find(t);
					if( syn != m_symbols.end() ) {
						return syn->second;
					}
					return rr;
				}
			);

			auto resurrect = std::make_shared<Function>(th->name(), new_terms);
			Term res;
			auto fnd = m_symbols.find(resurrect);
			if( fnd != m_symbols.end() ) {
				res = fnd->second;
			}
			else {
				auto new_var = next_free_var();
				m_symbols[resurrect] = new_var;
				res = new_var;
			}
			
			return res;
		}
		default: {
			return t->copy();
		}
	}
}

Term AckermannStep::next_free_var() const
{
	std::stringstream ss;
	ss << "uf" << (++next);
	return std::make_shared<Var>(ss.str());
}

Formula AckermannStep::reduce() const
{
	std::map<std::set<std::pair<Term, Term>, compare_pair>, Formula> res;
	TermCompare comparator;
	for(auto&& sub1 : m_symbols) {
		auto f1 = sub1.first;
		auto f1_raw = static_cast<const Function*>(f1.get());
		for(auto&& sub2 : m_symbols) {
			auto f2 = sub2.first;
			auto f2_raw = static_cast<const Function*>(f2.get());

			//npr: f(x, y), f(x, z), ali ne f(x, y), g(x, z) i ne f(x, y), f(x, y)
			if( (comparator(f1, f2) || comparator(f2, f1)) && f1_raw->name() == f2_raw->name() ) { 
				auto ts1 = f1_raw->terms(); //npr: x, y
				auto ts2 = f2_raw->terms(); //npr: x, z

				//pravimo {(x, y), (y, z), (x, z), ...}
				std::set<std::pair<Term, Term>, compare_pair> f;
				for(int i = 0; i < ts1.size(); i++) {
					f.insert(std::make_pair(ts1[i], ts2[i]));
				}
				res.insert(std::make_pair(f, std::make_shared<Equals>(sub1.second, sub2.second)));
			}
		}
	}

	if( res.size() == 0 ) {
		return std::make_shared<True>();
	}
	Formula f = std::make_shared<If>(make_cons(res.begin()->first), res.begin()->second);
	int i = 0;
	for(auto&& pr : res) {
		if( i++ == 0 ) {
			continue;
		}
		f = std::make_shared<And>(f, std::make_shared<If>(make_cons(pr.first), pr.second));
	}

	return f;
}

Formula AckermannStep::make_cons(const std::set<std::pair<Term, Term>, compare_pair>& pair_set) const
{
	if( pair_set.size() == 0 ) {
		return std::make_shared<False>();
	}
	auto first = pair_set.begin();
	Formula acc = std::make_shared<Equals>(first->first, first->second);
	return std::accumulate(
		++std::begin(pair_set),
		std::end(pair_set),
		acc,
		[](const Formula& acc, const std::pair<Term, Term>& nxt) {
			return std::make_shared<And>(acc, std::make_shared<Equals>(nxt.first, nxt.second));
		}
	);
}

bool compare_pair::operator()(const std::pair<Term, Term>& a, const std::pair<Term, Term>& b) const
{
	auto left = (comparator(a.first, a.second) ? a : std::make_pair(a.second, a.first));
	auto righ = (comparator(b.first, b.second) ? b : std::make_pair(b.second, b.first));

	if( comparator(left.first, righ.first) ) { return true; }
	if( comparator(righ.first, left.first) ) { return comparator(left.second, righ.second); }
	return false;
}


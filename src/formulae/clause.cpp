#include <clause.hpp>
#include <numeric>
#include <algorithm>
#include <stdexcept>
#include <formulae.hpp>
#include <boost/iterator/zip_iterator.hpp>
#include <boost/tuple/tuple.hpp>

using namespace AR;

Clause::Clause()
{}

Clause::Clause(const std::initializer_list<Formula> &F)
{
    m_formulas = std::set<Formula, FormulaCompare>(F.begin(), F.end());
}

FormulaType Clause::get_type() const
{
    return CNF_CLAUSE;
}

void Clause::print_formula(std::ostream& out) const
{
	if( m_formulas.empty() ) {
		return;
	}

    if( m_formulas.size() > 1 ) {
        out << "(";
    }

    out << *(m_formulas.begin());
	std::for_each(
        ++m_formulas.begin(),
		m_formulas.end(),
		[&](const Formula& f) {
			out << " | ";
            f->print_formula(out);
		}
	);

    if( m_formulas.size() > 1 ) {
        out << ")";
    }
}

bool Clause::is_literal() const
{
    return false;
}

int Clause::complexity() const
{
    if( m_formulas.empty() ) {
        return 0;
    }
    return (m_formulas.size() - 1) +
		std::accumulate(
        	m_formulas.begin(),
        	m_formulas.end(),
        	0, 
        	[](int acc, const Formula& f) {
        	    return f->complexity();
        	}
    	);
}

bool Clause::evaluate(const Valuation &v) const
{
    return std::accumulate(
        m_formulas.begin(),
        m_formulas.end(),
        true,
        [&](bool acc, const Formula& f) {
            return acc && f->evaluate(v);
        }
    );
}

Formula Clause::substitute(const Formula& f, const Formula& g) const
{
	if( m_formulas.empty() ) {
        return std::make_shared<Clause>();
	}
	Formula first;
    if( (*m_formulas.begin())->equals(f) ) {
		first = g;
	}
	else {
        first = *(m_formulas.begin());
	}
    return std::make_shared<Clause>(std::initializer_list<Formula>{first});
}

bool Clause::m_is_equal(const Formula& f) const
{
    if( f->get_type() != get_type() ) {
        return false;
    }
    const Clause *c = static_cast<const Clause*>(f.get());
    return c->m_formulas == m_formulas;
}
void Clause::m_get_atoms(AtomSet &atoms) const
{
    std::for_each(
        m_formulas.begin(),
        m_formulas.end(),
        [&](const Formula& f) {
            AtomSet A = f->get_atoms();
            for(auto &&i : A) {
                atoms.insert(i);
            }
        }
    );
}

bool Clause::operator<(const Formula& f) const
{
    const Clause *fc = static_cast<const Clause*>(f.get());

    return std::accumulate(
        boost::make_zip_iterator(
            boost::make_tuple(
                m_formulas.begin(),
                fc->m_formulas.begin()
            )
        ),
        boost::make_zip_iterator(
            boost::make_tuple(
                m_formulas.end(),
                fc->m_formulas.end()
            )
        ),
        false,
        [&](bool acc, const boost::tuple<const Formula&, const Formula&>& t) {
            return acc || t.get<0>() < t.get<1>();
        }
    );

}

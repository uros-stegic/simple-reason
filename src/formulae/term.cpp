#include <iostream>
#include <memory>
#include <set>
#include <term.hpp>
#include <transformation.hpp>
#include <formulae.hpp>

using namespace art;

bool BaseTerm::equals(const Term& other) const
{
    if( get_type() == other->get_type() ) {
        return m_is_equal(other);
    }
    return false;
}

Term BaseTerm::copy() const
{
    return shared_from_this();
}

std::ostream& operator <<(std::ostream& out, const art::Term& t)
{
    t->print_term(out);
    return out;
}

Term BaseTerm::transform(const Transformation& t) const
{
    return t.transform(shared_from_this());
}

bool TermCompare::operator()(const Term& f, const Term& g) const
{
	//std::cout << "Poredi: " << f << " sa " << g << std::endl; 
	if( f->get_type() != g->get_type() ) {
		auto br = f->get_type() < g->get_type();
		if( br ) {
	//		std::cout << "\ttip je manji" << std::endl;
		}
		else {
	//		std::cout << "\ttip je veci" << std::endl;
		}
		return br;
	}
	if( f->get_type() == VARIABLE ) {
		auto f_raw = static_cast<const Var*>(f.get());
		auto g_raw = static_cast<const Var*>(g.get());
		auto br = f_raw->name() < g_raw->name();
		if( br ) {
	//		std::cout << "varijabla je manja" << std::endl;
		}
		else {
	//		std::cout << "varijabla je veca" << std::endl;
		}
		return br;
	}
	if( f->get_type() == CONSTANT ) {
		auto f_raw = static_cast<const Constant*>(f.get());
		auto g_raw = static_cast<const Constant*>(g.get());
		auto br = f_raw->name() < g_raw->name();
		if( br ) {
	//		std::cout << "const je manja" << std::endl;
		}
		else {
	//		std::cout << "const je veca" << std::endl;
		}
		return br;
	}
	else { // function term
		auto f_raw = static_cast<const Function*>(f.get());
		auto g_raw = static_cast<const Function*>(g.get());

		if( f_raw->name() != g_raw->name() ) {
	//		std::cout << "razlicita imena" << std::endl;
			return f_raw->name() < g_raw->name();
		}

		// they must be the same arity, not checking!

		auto f_terms = f_raw->terms();
		auto g_terms = g_raw->terms();
		for(auto i = 0; i < f_terms.size(); i++) {
			if( operator()(f_terms[i], g_terms[i]) ) {
				return true;
			}
			else if( operator()(g_terms[i], f_terms[i]) ) {
				return false;
			}
		}
		return false;
	}
}


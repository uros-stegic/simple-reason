#include <formulae.hpp>
#include <transformation.hpp>

#include <iostream>

using namespace art;

bool FormulaCompare::operator()(const Formula& f, const Formula& g) const
{
    return f < g;
}

bool BaseFormula::equals(const Formula& f) const
{
    /*
    if( get_type() != f->get_type() ) {
        return false;
    }
    return m_is_equal(f);
    */
    return !(shared_from_this() < f || f < shared_from_this());
}

Formula BaseFormula::copy() const
{
    return shared_from_this();
}

AtomSet BaseFormula::get_atoms() const
{
    AtomSet atoms;
    m_get_atoms(atoms);
    return atoms;
}

void BaseFormula::m_get_atoms(AtomSet&) const
{}

Formula BaseFormula::transform(const Transformation &t) const
{
    return t.transform(shared_from_this());
}

std::ostream& operator <<(std::ostream& out, const Formula& f)
{
    f->print_formula(out);
    return out;
}

bool operator<(const Formula& f, const Formula& g)
{
    if( f->complexity() < g->complexity() ) {
        return true;
    }
    else if( f->complexity() > g->complexity() ) {
        return false;
    }
    else {
        if( f->get_type() < g->get_type() ) {
            return true;
        }
        else if( f->get_type() < g->get_type() ) {
            return true;
        }
        else {
            return *f < g;
        }
    }
    /*
    return f->complexity() <= g->complexity() &&
           f->get_type() <= g->get_type() &&
           *f < g;
    */
}
bool operator !=(const Formula& f, const Formula& g) {
    return f < g || g < f;
}
bool operator ==(const Formula& f, const Formula& g) {
    return !(f < g || g < f);
}
bool operator >(const Formula& f, const Formula& g) {
    return !(f < g) && (g < f);
}
bool operator <=(const Formula& f, const Formula& g) {
    return f < g || !(g < f);
}
bool operator >=(const Formula& f, const Formula& g) {
    return !(f < g);
}

std::string BaseFormula::unique()
{
    std::string result = "uv" + std::to_string(BaseFormula::m_next_unique);
    BaseFormula::m_next_unique++;
    return result;
}

unsigned int BaseFormula::m_next_unique = 0;

bool BaseFormula::has_free(const Term& var) const
{
	if( var->get_type() == VARIABLE ) {
		return has_free(static_cast<const Var*>(var.get())->name());
	}
	return false;
}


#include <formula.hpp>
#include <transformation.hpp>
#include <definitions.hpp>

#include <iostream>

using namespace AR;

bool BaseFormula::equals(const Formula& f) const
{
    if( get_type() != f->get_type() ) {
        return false;
    }
    return m_is_equal(f);
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

bool BaseFormula::is_satisfiable() const
{
    AtomSet atoms = get_atoms();
    Valuation val(atoms);

    do {
        if( evaluate(val) ) {
            return true;
        }
    }
    while( val.next() );

    return false;
}
bool BaseFormula::is_tautology() const
{
    AtomSet atoms = get_atoms();
    Valuation val(atoms);

    do {
        if( !evaluate(val) ) {
            return false;
        }
    }
    while( val.next() );

    return true;
}
bool BaseFormula::is_contradiction() const
{
    return !is_satisfiable();
}
bool BaseFormula::is_deniable() const
{
    return !is_tautology();
}

Formula BaseFormula::transform(const Transformation &t) const
{
    return t.transform(shared_from_this());
}

std::ostream& operator <<(std::ostream& out, const Formula& f)
{
    f->print_formula(out);
    return out;
}


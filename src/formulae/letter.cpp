#include <letter.hpp>
#include <valuation.hpp>

#include <iostream>

using namespace AR;

Letter::Letter(unsigned int id)
    : m_id(id)
{}

FormulaType Letter::get_type() const
{
    return PROP_LETTER;
}

unsigned int Letter::get_id() const
{
    return m_id;
}

void Letter::print_formula(std::ostream& out) const
{
    out << "p" << m_id;
}

bool Letter::m_is_equal(const Formula& f) const
{
    return m_id == ((Letter*)f.get())->m_id;
}

void Letter::m_get_atoms(AtomSet &atoms) const
{
    atoms.insert(m_id);
}

bool Letter::evaluate(const Valuation& val) const
{
    return val.get_value(m_id);
}

bool Letter::operator <(const Formula& f) const
{
    const Letter *v = static_cast<const Letter*>(f.get());
    return m_id < v->m_id;
}

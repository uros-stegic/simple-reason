#include <letter.hpp>

using namespace AR;

Var::Var(unsigned int id)
    : m_id(id) {}

FormulaType Var::get_type() const
{
    return PROP_LETTER;
}

unsigned int Var::get_id() const
{
    return m_id;
}

void Var::print_formula(std::ostream& out) const
{
    out << "p" << m_id;
}

bool Var::m_is_equal(const Formula& f) const
{
    return m_id == ((Var*)f.get())->m_id;
}

void Var::m_get_atoms(AtomSet &atoms) const
{
    atoms.insert(m_id);
}

bool Var::evaluate(const Valuation& val) const
{
    return val.get_value(m_id);
}


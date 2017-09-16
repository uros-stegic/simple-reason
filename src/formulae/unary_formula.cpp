#include <unary_formula.hpp>

#include <iostream>

using namespace art;

UnaryFormula::UnaryFormula(const Formula &f)
    : m_operand(f)
{}

Formula UnaryFormula::get_operand() const
{
    return m_operand;
}

int UnaryFormula::complexity() const
{
    return 1 + m_operand->complexity();
}

bool UnaryFormula::operator <(const Formula& f) const
{
    const UnaryFormula *fu = static_cast<const UnaryFormula*>(f.get());
    return m_operand < fu->m_operand;
}

bool UnaryFormula::m_is_equal(const Formula& f) const
{
    return m_operand->equals(((UnaryFormula*)f.get())->get_operand());
}

void UnaryFormula::m_get_atoms(AtomSet& atoms) const
{
    AtomSet sub_atoms = m_operand->get_atoms();
    atoms.insert(sub_atoms.cbegin(), sub_atoms.cend());
}

void UnaryFormula::print_formula(std::ostream& out) const
{
    Formula op = get_operand();

    m_print_formula(out);

    if( op->get_type() > get_type() ) {
        out << "(";
    }
    op->print_formula(out);
    if( op->get_type() > get_type() ) {
        out << ")";
    }
}

bool UnaryFormula::has_free(const std::string& var) const
{
	return m_operand->has_free(var);
}


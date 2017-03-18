#include <binary_formula.hpp>

using namespace AR;

BinaryFormula::BinaryFormula(const Formula &f, const Formula &g)
    : m_left_operand(f)
    , m_right_operand(g) {}

Formula BinaryFormula::get_left_operand() const
{
    return m_left_operand;
}
Formula BinaryFormula::get_right_operand() const
{
    return m_right_operand;
}

int BinaryFormula::complexity() const
{
    return 1 + m_left_operand->complexity() + m_right_operand->complexity();
}

bool BinaryFormula::m_is_equal(const Formula& f) const
{
    return  m_left_operand->equals(((BinaryFormula*)f.get())->get_left_operand())
        && m_right_operand->equals(((BinaryFormula*)f.get())->get_right_operand());
}

void BinaryFormula::m_get_atoms(AtomSet& atoms) const
{
    AtomSet tmp = m_left_operand->get_atoms();
    atoms.insert(tmp.cbegin(), tmp.cend());

    tmp = m_right_operand->get_atoms();
    atoms.insert(tmp.cbegin(), tmp.cend());
}

void BinaryFormula::print_formula(std::ostream& out) const
{
    Formula l = get_left_operand();
    Formula r = get_right_operand();

    if( l->get_type() > get_type() ) {
        out << "(";
    }
    l->print_formula(out);
    if( l->get_type() > get_type() ) {
        out << ")";
    }

    m_print_formula(out);

    if( r->get_type() > get_type() ) {
        out << "(";
    }
    r->print_formula(out);
    if( r->get_type() > get_type() ) {
        out << ")";
    }
}

Formula BinaryFormula::m_cnf() const
{
    return shared_from_this();
}


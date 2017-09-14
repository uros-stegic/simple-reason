#include <negation.hpp>

#include <iostream>

using namespace art;

FormulaType Not::get_type() const
{
    return NEGATION;
}

void Not::m_print_formula(std::ostream& out) const
{
    out << "¬";
}

bool Not::is_literal() const
{
    return get_operand()->is_literal() && get_operand()->get_type() != NEGATION;
}

Formula Not::substitute(const Formula& from, const Formula& to) const
{
    if( get_type() != from->get_type() || !equals(from) ) {
        return std::make_shared<Not>(get_operand()->substitute(from, to));
    }
    return to;
}

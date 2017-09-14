#include <implication.hpp>

#include <iostream>

using namespace art;

FormulaType If::get_type() const
{
    return IMPLICATION;
}

void If::m_print_formula(std::ostream& out) const
{
    out << " ⇒ ";
}

Formula If::substitute(const Formula& from, const Formula& to) const
{
    if( get_type() != from->get_type() || !equals(from) ) {
        return std::make_shared<If>(
                    get_left_operand() ->substitute(from, to),
                    get_right_operand()->substitute(from, to)
                );
    }
    return to;
}

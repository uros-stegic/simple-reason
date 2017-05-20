#include <conjunction.hpp>
#include <valuation.hpp>

#include <iostream>

using namespace art;

FormulaType And::get_type() const
{
    return CONJUNCTION;
}

void And::m_print_formula(std::ostream& out) const
{
    out << " Λ ";
}

Formula And::substitute(const Formula& from, const Formula& to) const
{
    if( get_type() != from->get_type() || !equals(from) ) {
        return std::make_shared<And>(
                    get_left_operand() ->substitute(from, to),
                    get_right_operand()->substitute(from, to)
                );
    }
    return to;
}

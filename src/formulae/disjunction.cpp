#include <disjunction.hpp>

#include <iostream>

using namespace art;

FormulaType Or::get_type() const
{
    return DISJUNCTION;
}

void Or::m_print_formula(std::ostream& out) const
{
    out << " ν ";
}

Formula Or::substitute(const Formula& from, const Formula& to) const
{
    if( get_type() != from->get_type() || !equals(from) ) {
        return std::make_shared<Or>(
                    get_left_operand() ->substitute(from, to),
                    get_right_operand()->substitute(from, to)
                );
    }
    return to;
}

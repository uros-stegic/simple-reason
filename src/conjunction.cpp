#include <conjunction.hpp>
#include <valuation.hpp>
#include <false_constant.hpp>

#include <iostream>

using namespace AR;

FormulaType And::get_type() const
{
    return CONJUNCTION;
}

void And::m_print_formula(std::ostream& out) const
{
    out << " & ";
}

bool And::evaluate(const Valuation& val) const
{
    return get_left_operand()->evaluate(val) && get_right_operand()->evaluate(val);
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

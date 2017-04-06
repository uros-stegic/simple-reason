#include <implication.hpp>
#include <valuation.hpp>

#include <iostream>

using namespace AR;

FormulaType If::get_type() const
{
    return IMPLICATION;
}

void If::m_print_formula(std::ostream& out) const
{
    out << " => ";
}

bool If::evaluate(const Valuation& val) const
{
    return !get_left_operand()->evaluate(val) || get_right_operand()->evaluate(val);
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

#include <disjunction.hpp>
#include <valuation.hpp>
#include <conjunction.hpp>
#include <true_constant.hpp>
#include <false_constant.hpp>

using namespace AR;

FormulaType Or::get_type() const
{
    return DISJUNCTION;
}

void Or::m_print_formula(std::ostream& out) const
{
    out << " | ";
}

bool Or::evaluate(const Valuation& val) const
{
    return get_left_operand()->evaluate(val) || get_right_operand()->evaluate(val);
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

#include <letter.hpp>
#include <true_constant.hpp>
#include <false_constant.hpp>
#include <negation.hpp>
#include <conjunction.hpp>
#include <disjunction.hpp>
#include <implication.hpp>
#include <equivalence.hpp>
#include <memory>

using namespace AR;

FormulaType Not::get_type() const
{
    return NEGATION;
}

void Not::m_print_formula(std::ostream& out) const
{
    out << "~";
}

bool Not::evaluate(const Valuation& val) const
{
    return !get_operand()->evaluate(val);
}

Formula Not::substitute(const Formula& from, const Formula& to) const
{
    if( get_type() != from->get_type() || !equals(from) ) {
        return std::make_shared<Not>(get_operand()->substitute(from, to));
    }
    return to;
}

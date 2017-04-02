#include <valuation.hpp>
#include <true_constant.hpp>
#include <negation.hpp>
#include <disjunction.hpp>
#include <implication.hpp>

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

Formula If::simplify() const
{
    Formula left  = get_left_operand() ->simplify();
    Formula right = get_right_operand()->simplify();

    if( left->get_type() == PROP_TRUE ) {
        return right;
    }
    else if( left->get_type() == PROP_FALSE ) {
        return std::make_shared<True>();
    }
    else if( right->get_type() == PROP_FALSE ) {
        return left;
    }
    else if( right->get_type() == PROP_TRUE ) {
        return std::make_shared<True>();
    }
    return std::make_shared<If>(left, right);
}

Formula If::m_nnf() const
{
    Formula left  = get_left_operand();
    Formula right = get_right_operand()->nnf();
    
    return std::make_shared<Or>(
        std::make_shared<Not>(left)->nnf(),
        right
    );
}


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

Formula And::simplify() const
{
    Formula left  = get_left_operand() ->simplify();
    Formula right = get_right_operand()->simplify();

    if( left->get_type() == PROP_FALSE || right->get_type() == PROP_FALSE) {
        return std::make_shared<False>();
    }
    else if( left->get_type() == PROP_TRUE ) {
        return right;
    }
    else if( right->get_type() == PROP_TRUE ) {
        return left;
    }
    return std::make_shared<And>(left, right);
}

Formula And::m_nnf() const
{
    return std::make_shared<And>(
             get_left_operand() ->nnf(),
             get_right_operand()->nnf()
    );
}

Formula And::m_cnf() const
{
    return std::make_shared<And>(
             get_left_operand() ->cnf(),
             get_right_operand()->cnf()
    );
}


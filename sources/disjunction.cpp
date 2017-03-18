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

Formula Or::simplify() const
{
    Formula left  = get_left_operand() ->simplify();
    Formula right = get_right_operand()->simplify();

    if( left->get_type() == PROP_TRUE || right->get_type() == PROP_TRUE) {
        return std::make_shared<True>();
    }
    else if( left->get_type() == PROP_FALSE ) {
        return right;
    }
    else if( right->get_type() == PROP_FALSE ) {
        return left;
    }
    return std::make_shared<Or>(left, right);
}

Formula Or::m_nnf() const
{
    return std::make_shared<Or>(
             get_left_operand() ->nnf(),
             get_right_operand()->nnf()
    );
}

Formula Or::m_cnf() const
{
    Formula left  =  get_left_operand();
    Formula right = get_right_operand();

    Formula result;
    if( right->get_type() == CONJUNCTION ) {
        const And* con = static_cast<const And*>(right.get());
        Formula lright = con->get_left_operand();
        Formula rright = con->get_right_operand();
        result = std::make_shared<And>(
            std::make_shared<Or>(
                left,
                lright
            )->cnf(),
            std::make_shared<Or>(
                left,
                rright
            )->cnf()
        );
    }

    else if( left->get_type() == CONJUNCTION ) {
        const And* con = static_cast<const And*>(left.get());
        Formula lleft = con->get_left_operand();
        Formula rleft = con->get_right_operand();
        result = std::make_shared<And>(
            std::make_shared<Or>(
                lleft,
                right
            )->cnf(),
            std::make_shared<Or>(
                rleft,
                right
            )->cnf()
        );
    }
    else {
        result = std::make_shared<Or>(
            left->cnf(),
            right->cnf()
        );
    }
    return result;
}


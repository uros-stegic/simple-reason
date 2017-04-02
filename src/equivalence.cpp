#include <true_constant.hpp>
#include <negation.hpp>
#include <conjunction.hpp>
#include <disjunction.hpp>
#include <equivalence.hpp>

using namespace AR;

FormulaType Iff::get_type() const
{
    return EQUIVALENCE;
}

void Iff::m_print_formula(std::ostream& out) const
{
    out << " <=> ";
}

bool Iff::evaluate(const Valuation& val) const
{
    return get_left_operand()->evaluate(val) == get_right_operand()->evaluate(val);
}

Formula Iff::substitute(const Formula& from, const Formula& to) const
{
    if( get_type() != from->get_type() || !equals(from) ) {
        return std::make_shared<Iff>(
                    get_left_operand() ->substitute(from, to),
                    get_right_operand()->substitute(from, to)
                );
    }
    return to;
}

Formula Iff::simplify() const
{
    Formula left  = get_left_operand() ->simplify();
    Formula right = get_right_operand()->simplify();

    if( left ->get_type() == PROP_FALSE
     && right->get_type() == PROP_FALSE ) {
        return std::make_shared<True>();
    }
    if( left ->get_type() == PROP_TRUE
     && right->get_type() == PROP_TRUE ) {
        return std::make_shared<True>();
    }
    if( left->get_type() == PROP_TRUE ) {
        return right;
    }
    else if( left->get_type() == PROP_FALSE ) {
        return std::make_shared<Not>(right);
    }

    else if( right->get_type() == PROP_TRUE ) {
        return left;
    }
    else if( right->get_type() == PROP_FALSE ) {
        return std::make_shared<Not>(left);
    }
    return std::make_shared<Iff>(left, right);
}

Formula Iff::m_nnf() const
{
    Formula left  = get_left_operand();
    Formula right = get_right_operand();
    return std::make_shared<And>(
        std::make_shared<Or>(
            std::make_shared<Not>(left)->nnf(),
            right->nnf()
        ),
        std::make_shared<Or>(
            left->nnf(),
            std::make_shared<Not>(right)->nnf()
        )
    );
}


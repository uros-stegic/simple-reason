#include <simplification.hpp>
#include <formulae.hpp>
#include <memory>

using namespace art;

/*
 * FIXME: refactor this with method extraction.
 */
Formula Simplification::transform(const Formula &f) const
{
    switch (f->get_type()) {
    case PROP_LETTER:
    case PROP_TRUE:
    case PROP_FALSE:
        return f->copy();
    case NEGATION: {
        const Not *neg = static_cast<const Not*>(f.get());
        Formula sub = neg->get_operand()->transform(*this);
        if( sub->get_type() == PROP_FALSE ) return std::make_shared<True >();
        if( sub->get_type() == PROP_TRUE )  return std::make_shared<False>();
        if( sub->get_type() == NEGATION ) return static_cast<const Not*>(sub.get())->get_operand()->transform(*this);
        return std::make_shared<Not>(sub);
    }
    case CONJUNCTION: {
        const And *con = static_cast<const And*>(f.get());
        Formula left  = con->get_left_operand() ->transform(*this);
        Formula right = con->get_right_operand()->transform(*this);

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
    case DISJUNCTION: {
        const Or *dis = static_cast<const Or*>(f.get());
        Formula left  = dis->get_left_operand() ->transform(*this);
        Formula right = dis->get_right_operand()->transform(*this);

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
    case IMPLICATION: {
        const If *imp = static_cast<const If*>(f.get());
        Formula left  = imp->get_left_operand() ->transform(*this);
        Formula right = imp->get_right_operand()->transform(*this);

        if( left->get_type() == PROP_FALSE || right->get_type() == PROP_TRUE ) {
            return std::make_shared<True>();
        }
        else if( left->get_type() == PROP_TRUE ) {
            return right;
        }
        else if( right->get_type() == PROP_FALSE ) {
            return left;
        }
        return std::make_shared<If>(left, right);
    }
    case EQUIVALENCE: {
        const Iff *iff = static_cast<const Iff*>(f.get());
        Formula left  = iff->get_left_operand() ->transform(*this);
        Formula right = iff->get_right_operand()->transform(*this);

        if( left ->get_type() == PROP_FALSE
         && right->get_type() == PROP_FALSE ) {
            return std::make_shared<True>();
        }
        if( left ->get_type() == PROP_TRUE
         && right->get_type() == PROP_TRUE ) {
            return std::make_shared<True>();
        }
        if( left ->get_type() == PROP_TRUE
         && right->get_type() == PROP_FALSE ) {
            return std::make_shared<False>();
        }
        if( left ->get_type() == PROP_FALSE
         && right->get_type() == PROP_TRUE ) {
            return std::make_shared<False>();
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
    }
}

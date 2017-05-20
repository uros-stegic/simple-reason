#include <negation_distribuition.hpp>
#include <formulae.hpp>

using namespace art;

/*
 * FIXME: Refactor this using method extraction
 */
Formula NegationDistribution::transform(const Formula &f) const
{
    switch( f->get_type() ) {
    case PROP_LETTER:
    case PROP_FALSE:
    case PROP_TRUE:
        return f->copy();
    case NEGATION: {
        const Not *notF = static_cast<const Not*>(f.get());
        Formula operand = notF->get_operand()->transform(*this);
        switch( operand->get_type() ) {
        case PROP_LETTER:
        case PROP_FALSE:
        case PROP_TRUE:
        case NEGATION: {
            return f->copy();
        }
        case CONJUNCTION: {
            const And *conO = static_cast<const And*>(operand.get());
            Formula left  = (std::make_shared<Not>(conO->get_left_operand())) ->transform(*this);
            Formula right = (std::make_shared<Not>(conO->get_right_operand()))->transform(*this);
            return std::make_shared<Or>(left, right);
        }
        case DISJUNCTION: {
            const Or *disO = static_cast<const Or*>(operand.get());
            Formula left  = (std::make_shared<Not>(disO->get_left_operand())) ->transform(*this);
            Formula right = (std::make_shared<Not>(disO->get_right_operand()))->transform(*this);
            return std::make_shared<And>(left, right);
        }
        case IMPLICATION: {
            const If *impO = static_cast<const If*>(operand.get());
            Formula left  = (std::make_shared<Not>(impO->get_left_operand())) ->transform(*this);
            Formula right = (std::make_shared<Not>(impO->get_right_operand()))->transform(*this);
            return std::make_shared<If>(right, left);
        }
        case EQUIVALENCE: {
            const Iff *equO = static_cast<const Iff*>(operand.get());
            Formula left  = (std::make_shared<Not>(equO->get_left_operand())) ->transform(*this);
            Formula right = equO->get_right_operand()->transform(*this);
            return std::make_shared<Iff>(left, right);
        }
        }
    }
    case CONJUNCTION: {
        const And *con = static_cast<const And*>(f.get());
        Formula left  = con->get_left_operand() ->transform(*this);
        Formula right = con->get_right_operand()->transform(*this);
        return std::make_shared<And>(left, right);
    }
    case DISJUNCTION: {
        const Or *dis = static_cast<const Or*>(f.get());
        Formula left  = dis->get_left_operand() ->transform(*this);
        Formula right = dis->get_right_operand()->transform(*this);
        return std::make_shared<Or>(left, right);
    }
    case IMPLICATION: {
        const If *imp = static_cast<const If*>(f.get());
        Formula left  = imp->get_left_operand() ->transform(*this);
        Formula right = imp->get_right_operand()->transform(*this);
        return std::make_shared<If>(left, right);
    }
    case EQUIVALENCE: {
        const Iff *equ = static_cast<const Iff*>(f.get());
        Formula left  = equ->get_left_operand() ->transform(*this);
        Formula right = equ->get_right_operand()->transform(*this);
        return std::make_shared<Iff>(left, right);
    }
    }
}

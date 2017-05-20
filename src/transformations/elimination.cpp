#include <elimination.hpp>
#include <formulae.hpp>

using namespace art;

Formula Elimination::transform(const Formula &f) const
{
    switch( f->get_type() ) {
    case PROP_FALSE:
    case PROP_TRUE:
    case PROP_LETTER:
        return f->copy();
    case NEGATION: {
        const Not *neg = static_cast<const Not*>(f.get());
        return std::make_shared<Not>(neg->get_operand()->transform(*this));
    }
    case CONJUNCTION: {
        const And *con = static_cast<const And*>(f.get());
        return std::make_shared<And>(
            con->get_left_operand()->transform(*this),
            con->get_right_operand()->transform(*this)
        );
    }
    case DISJUNCTION: {
        const Or *dis = static_cast<const Or*>(f.get());
        return std::make_shared<Or>(
            dis->get_left_operand()->transform(*this),
            dis->get_right_operand()->transform(*this)
        );
    }
    case IMPLICATION: {
        const If *imp = static_cast<const If*>(f.get());
        return std::make_shared<Or>(
            std::make_shared<Not>(imp->get_left_operand())->transform(*this),
            imp->get_right_operand()->transform(*this)
        );
    }
    case EQUIVALENCE: {
        const Iff *equ = static_cast<const Iff*>(f.get());
        return std::make_shared<And>(
            std::make_shared<Or>(
                std::make_shared<Not>(equ->get_left_operand()),
                equ->get_right_operand()
            )->transform(*this),
            std::make_shared<Or>(
                equ->get_left_operand(),
                std::make_shared<Not>(equ->get_right_operand())
            )->transform(*this)
        );
    }
    }
}

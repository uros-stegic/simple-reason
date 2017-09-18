#include <formulae.hpp>
#include <disjunction_distribution.hpp>
#include <stdexcept>

using namespace art;

Formula DisjunctionDistribution::transform(const Formula &f) const
{
    switch( f->get_type() ) {
    	case PROP_FALSE:
    	case PROP_TRUE:
    	case PROP_LETTER:
		case EQUALS:
		case NOT_EQUALS:
		case PREDICATE: {
    	    return f->copy();
    	}
    	case NEGATION: {
    	    auto sub = static_cast<const Not*>(f.get())->get_operand();
    	    return std::make_shared<Not>(sub->transform(*this));
    	}
    	case DISJUNCTION: {
    	    auto left  = static_cast<const Or*>(f.get())->get_left_operand();
    	    auto right = static_cast<const Or*>(f.get())->get_right_operand();
    	    if( left->get_type() > DISJUNCTION || right->get_type() > DISJUNCTION ) {
    	        throw new std::runtime_error("Cannot distribute disjunction over implication or equivalence");
    	    }
    	    if( right->get_type() == CONJUNCTION ) {
    	        return std::make_shared<And>(
    	                    std::make_shared<Or>(
    	                        left,
    	                        static_cast<const And*>(right.get())->get_left_operand()
    	                    )->transform(*this),
    	                    std::make_shared<Or>(
    	                        left,
    	                        static_cast<const And*>(right.get())->get_right_operand()
    	                    )->transform(*this)
    	               );
    	    }
    	    else if( left->get_type() == CONJUNCTION ) {
    	        return std::make_shared<And>(
    	                    std::make_shared<Or>(
    	                        static_cast<const And*>(left.get())->get_left_operand(),
    	                        right
    	                    )->transform(*this),
    	                    std::make_shared<Or>(
    	                        static_cast<const And*>(left.get())->get_right_operand(),
    	                        right
    	                    )->transform(*this)
    	               );
    	    }

    	    return std::make_shared<Or>(left->transform(*this), right->transform(*this));
    	}
    	case CONJUNCTION: {
    	    auto left  = static_cast<const And*>(f.get())->get_left_operand() ->transform(*this);
    	    auto right = static_cast<const And*>(f.get())->get_right_operand()->transform(*this);
    	    return std::make_shared<And>(left, right);
    	}
    	case IMPLICATION: {
    	    auto left  = static_cast<const If*>(f.get())->get_left_operand() ->transform(*this);
    	    auto right = static_cast<const If*>(f.get())->get_right_operand()->transform(*this);
    	    return std::make_shared<If>(left, right);
    	}
    	case EQUIVALENCE: {
    	    auto left  = static_cast<const Iff*>(f.get())->get_left_operand() ->transform(*this);
    	    auto right = static_cast<const Iff*>(f.get())->get_right_operand()->transform(*this);
    	    return std::make_shared<Iff>(left, right);
    	}
		case FOR_ALL: {
			const ForAll* fall = static_cast<const ForAll*>(f.get());
			return std::make_shared<ForAll>(fall->get_operand()->transform(*this), fall->var());
		}
		case EXISTS: {
			const Exists* exs = static_cast<const Exists*>(f.get());
			return std::make_shared<Exists>(exs->get_operand()->transform(*this), exs->var());
		}
    }
}

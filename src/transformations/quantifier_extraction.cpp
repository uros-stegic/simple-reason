#include <quantifier_extraction.hpp>
#include <rename.hpp>
#include <formulae.hpp>

using namespace art;

Formula QuantifierExtraction::transform(const Formula& f) const
{
    switch( f->get_type() ) {
    	case PROP_FALSE:
    	case PROP_TRUE:
    	case PROP_LETTER:
		case PREDICATE:
		case NEGATION: {
    	    return f->copy();
    	}
    	case DISJUNCTION:
    	case CONJUNCTION: {
    	    auto left  = static_cast<const And*>(f.get())->get_left_operand() ->transform(*this);
    	    auto right = static_cast<const And*>(f.get())->get_right_operand()->transform(*this);

			if( left->get_type() == FOR_ALL ) {
				auto left_raw = static_cast<const ForAll*>(left.get());

				if( right->has_free(left_raw->var()) ) {
					left = left->transform(Rename(left_raw->var()));
					left_raw = static_cast<const ForAll*>(left.get());
				}

				Formula res;
				if( f->get_type() == CONJUNCTION ) {
					res = std::make_shared<And>(left_raw->get_operand(), right)->transform(*this);
				}
				else {
					res = std::make_shared<Or>(left_raw->get_operand(), right)->transform(*this);
				}
				return std::make_shared<ForAll>(res, left_raw->var());
			}
			else if( left->get_type() == EXISTS ) {
				auto left_raw = static_cast<const Exists*>(left.get());

				if( right->has_free(left_raw->var()) ) {
					left = left->transform(Rename(left_raw->var()));
					left_raw = static_cast<const Exists*>(left.get());
				}

				Formula res;
				if( f->get_type() == CONJUNCTION ) {
					res = std::make_shared<And>(left_raw->get_operand(), right)->transform(*this);
				}
				else {
					res = std::make_shared<Or>(left_raw->get_operand(), right)->transform(*this);
				}
				return std::make_shared<Exists>(res, left_raw->var());

			}
			else if( right->get_type() == FOR_ALL ) {
				auto right_raw = static_cast<const ForAll*>(right.get());

				if( left->has_free(right_raw->var()) ) {
					right = right->transform(Rename(right_raw->var()));
					right_raw = static_cast<const ForAll*>(right.get());
				}

				Formula res;
				if( f->get_type() == CONJUNCTION ) {
					res = std::make_shared<And>(left, right_raw->get_operand())->transform(*this);
				}
				else {
					res = std::make_shared<Or>(left, right_raw->get_operand())->transform(*this);
				}
				return std::make_shared<ForAll>(res, right_raw->var());
			}
			else if( right->get_type() == EXISTS ) {
				auto right_raw = static_cast<const Exists*>(right.get());

				if( left->has_free(right_raw->var()) ) {
					right = right->transform(Rename(right_raw->var()));
					right_raw = static_cast<const Exists*>(right.get());
				}

				Formula res;
				if( f->get_type() == CONJUNCTION ) {
					res = std::make_shared<And>(left, right_raw->get_operand())->transform(*this);
				}
				else {
					res = std::make_shared<Or>(left, right_raw->get_operand())->transform(*this);
				}
				return std::make_shared<Exists>(res, right_raw->var());

			}
			return f->copy();
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

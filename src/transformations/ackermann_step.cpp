#include <ackermann_step.hpp>
#include <formulae.hpp>
#include <algorithm>

using namespace art;

Formula AckermannStep::transform(const Formula& f) const
{
    switch( f->get_type() ) {
        case CONJUNCTION: {
        }
        case DISJUNCTION: {
        }
        case IMPLICATION: {
        }
        case EQUIVALENCE: {
        }
        case NEGATION: {
        }
        case PREDICATE: {
        }
        case FOR_ALL: {
        }
        case EXISTS: {
        }
        default: {
        }
    }
	return f->copy();
}


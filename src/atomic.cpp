#include <atomic.hpp>

using namespace AR;

int AtomicFormula::complexity() const
{
    return 0;
}

Formula AtomicFormula::substitute(const Formula& from, const Formula& to) const
{
    if( equals(from) ) {
        return to;
    }
    return shared_from_this();
}

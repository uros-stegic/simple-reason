#include <prenex.hpp>

using namespace art;

Formula Prenex::transform(const Formula& f) const
{
    return f->copy();
}

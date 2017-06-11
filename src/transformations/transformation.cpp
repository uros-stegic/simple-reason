#include <transformation.hpp>

using namespace art;

Term Transformation::transform(const Term& t) const
{
    return t->copy();
}

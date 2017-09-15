#include <quantifier_extraction.hpp>

using namespace art;

Formula QuantifierExtraction::transform(const Formula& f) const
{
    return f->copy();
}

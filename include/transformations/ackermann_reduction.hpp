#ifndef ACKERMANN_REDUCTION_HPP
#define ACKERMANN_REDUCTION_HPP

#include <composite_transformation.hpp>

/*
 * Performs ackerman reduction to EUF as described in:
 *   - http://symbolaris.com/course/dcd/04-equality.pdf
 */
namespace art {
class AckermannReduction : public CompositeTransformation {
public:
    AckermannReduction();
};
}

#endif // ACKERMANN_REDUCTION_HPP

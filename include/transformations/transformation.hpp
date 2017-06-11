#ifndef TRANSFORMATION_HPP
#define TRANSFORMATION_HPP

#include <formula.hpp>
#include <term.hpp>

namespace art {
/**
 * @brief The Transformation class is combination of
 * "Visitor" and "Composite" design patterns from GoF.
 * Transformation transforms immutable Formula object
 * with transformations: CNF, NNF, Simplification etc.
 */
class Transformation {
public:
    virtual Formula transform(const Formula&) const = 0;
    virtual Term transform(const Term&) const;
};
}

#endif // TRANSFORMATION_HPP

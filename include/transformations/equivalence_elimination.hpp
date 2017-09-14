#ifndef EQUIVALENCE_ELIMINATION_HPP
#define EQUIVALENCE_ELIMINATION_HPP

#include <transformation.hpp>
#include <formula.hpp>

namespace art {
/**
 * @brief The Elimination class performs the following:
 * p => q == !p | q
 * p <=> q == (!p | q) & (p | !q)
 */
class EquivalenceElimination : public Transformation {
    virtual Formula transform(const Formula &) const;
};
}

#endif // EQUIVALENCE_ELIMINATION_HPP

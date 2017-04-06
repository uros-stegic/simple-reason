#ifndef ELIMINATION_HPP
#define ELIMINATION_HPP

#include <transformation.hpp>
#include <formula.hpp>

namespace AR {
/**
 * @brief The Elimination class performs the following:
 * p => q == !p | q
 * p <=> q == (!p | q) & (p | !q)
 */
class Elimination : public Transformation {
    virtual Formula transform(const Formula &) const;
};
}

#endif // ELIMINATION_HPP

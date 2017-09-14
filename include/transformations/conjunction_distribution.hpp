#ifndef CONJUNCTION_DISTRIBUTION_HPP
#define CONJUNCTION_DISTRIBUTION_HPP

#include <transformation.hpp>
#include <formula.hpp>

namespace art {
/*
 * p & (r | s) == (p & r) | (p & s)
 * (r | s) & p == (r & p) | (s & p)
 */
class ConjunctionDistribution : public Transformation {
public:
    virtual Formula transform(const Formula &) const override;
};
}

#endif // CONJUNCTION_DISTRIBUTION_HPP

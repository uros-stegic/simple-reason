#ifndef DISJUNCTION_DISTRIBUTION_HPP
#define DISJUNCTION_DISTRIBUTION_HPP

#include <transformation.hpp>
#include <formula.hpp>

namespace AR {
class DisjunctionDistribution : public Transformation {
public:
    virtual Formula transform(const Formula &) const override;
};
}

#endif // DISJUNCTION_DISTRIBUTION_HPP

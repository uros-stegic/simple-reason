#ifndef CONJUNCTION_DISTRIBUTION_HPP
#define CONJUNCTION_DISTRIBUTION_HPP

#include <transformation.hpp>
#include <formula.hpp>

namespace art {
class ConjunctionDistribution : public Transformation {
public:
    virtual Formula transform(const Formula &) const override;
};
}

#endif // CONJUNCTION_DISTRIBUTION_HPP

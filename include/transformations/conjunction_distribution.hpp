#ifndef CONJUNCTION_DISTRIBUTION_HPP
#define CONJUNCTION_DISTRIBUTION_HPP

#include <transformation.hpp>
#include <formula.hpp>

namespace AR {
class ConjunctionDistribution : public Transformation {
public:
    virtual Formula transform(const Formula &) const override;
};
}

#endif // CONJUNCTION_DISTRIBUTION_HPP

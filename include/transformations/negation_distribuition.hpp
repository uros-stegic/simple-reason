#ifndef NEGATION_DISTRIBUTION_HPP
#define NEGATION_DISTRIBUTION_HPP

#include <transformation.hpp>
#include <definitions.hpp>

namespace AR {
/**
 * @brief The NegationDistribution class performs following laws:
 * !(p  &  q) == !p  |  !q
 * !(p  |  q) == !p  &  !q
 * !(p  => q) == !q  => !p
 * !(p <=> q) == !p <=>  q
 */
class NegationDistribution : public Transformation {
public:
    virtual Formula transform(const Formula &) const override;
};
}

#endif // NEGATION_DISTRIBUTION

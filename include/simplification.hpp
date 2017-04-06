#ifndef SIMPLIFICATION_HPP
#define SIMPLIFICATION_HPP

#include <transformation.hpp>
#include <definitions.hpp>

namespace AR {
/**
 * @brief The Simplification class performs following laws:
 * !T == F
 * !F == T
 *
 * !!p == p
 *
 * T & p == p & T == p
 * F & p == p & F == F
 *
 * T | p == p | T == T
 * F | p == p | F == p
 *
 * T => p == p
 * p => T == T
 * F => p == T
 * p => F == p
 *
 * T <=> T == T
 * F <=> F == T
 * T <=> F == F
 * F <=> T == F
 * p <=> T == p
 * p <=> F == !p
 * T <=> p == p
 * F <=> p == !p
 *
 */
class Simplification : public Transformation {
public:
    virtual Formula transform(const Formula&) const override;
};
}

#endif // SIMPLIFICATION_HPP

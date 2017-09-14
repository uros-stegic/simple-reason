#ifndef NEGATION_HPP
#define NEGATION_HPP

#include <iostream>

#include <unary_formula.hpp>
#include <formula.hpp>

/**
 *This class provides us the unary operator NOT using UnaryFormula constructor and methods.
 *
 */

namespace art {
class Not : public UnaryFormula {
public:
    using UnaryFormula::UnaryFormula;

    virtual FormulaType get_type() const override;
    virtual bool is_literal() const override;

    virtual Formula substitute(const Formula&, const Formula&) const override;

protected:
    virtual void m_print_formula(std::ostream&) const override;
};
}

#endif // NEGATION_HPP


#ifndef CONJUNCTION_HPP
#define CONJUNCTION_HPP

#include <iostream>

#include <binary_formula.hpp>
#include <valuation.hpp>
#include <formula.hpp>

/**
 *This class provides us application of binary "And" operator (aka. conjunction) to the formulas we
 * provide to BinaryFormula. Class And is using BinaryFormula constructor and methods, but it provides few
 * more methods of it's own.
 * For protected method m_print_formula we use operator &, since it means "and".
 *
 *  virtual bool evaluate(const Valuation&) const override;
 * This method is allowing us to evaluate some formula for the given valuation. We do that by fetching
 * and evaluating recursevly for each right and left operand. Recursion allows us to evaluate longer
 * formulas. This method is overriden from binary formula.
 *
 * virtual Formula substitute(const Formula&, const Formula&) const override;
 *
 * QUESTIONS:
 * 1. What is formula type? Where is it defined?
 * 2. Return in substitute.
 * 3. In get_type return CONJUNCTION --> from the enum made in formula.hpp
 */

namespace AR {
class And : public BinaryFormula {
public:
    using BinaryFormula::BinaryFormula;

    virtual FormulaType get_type() const override;
    virtual bool evaluate(const Valuation&) const override;

    virtual Formula substitute(const Formula&, const Formula&) const override;

protected:
    virtual void m_print_formula(std::ostream&) const override;
};
}

#endif // CONJUNCTION_HPP


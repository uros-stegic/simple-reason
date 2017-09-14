#ifndef CONJUNCTION_HPP
#define CONJUNCTION_HPP

#include <iostream>

#include <binary_formula.hpp>
#include <formula.hpp>

/**
 *This class provides us application of binary "And" operator (aka. conjunction) to the formulas we
 * provide to BinaryFormula. Class And is using BinaryFormula constructor and methods, but it provides few
 * more methods of it's own.
 * For protected method m_print_formula we use operator &, since it means "and".
 *                                             ~~~~~~~~
 *                                             symbol
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
 * 		Types are defined in include/formulae/formula.hpp. It's the type of the object, so that
 * 		you could check in run-time what is the type of the object (is it variable, true_constant, implication...)
 * 2. Return in substitute.
 * 		Which one? First one means that this node (object) is not what we are substituting (in a sense this != from)
 * 		and we should recursevley aplly substitutions to subformulas. The second return means that this object is
 * 		exactly what we were searching for so we need to return the substitute. (Notice that formulas are immutable
 * 		so we do not substitute INSIDE our formule, but return new formula with that substitution already done).
 * 3. In get_type return CONJUNCTION --> from the enum made in formula.hpp
 *
 */

namespace art {
class And : public BinaryFormula {
public:
    using BinaryFormula::BinaryFormula;

    virtual FormulaType get_type() const override;
    virtual Formula substitute(const Formula&, const Formula&) const override;

protected:
    virtual void m_print_formula(std::ostream&) const override;
};
}

#endif // CONJUNCTION_HPP


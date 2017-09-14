#ifndef DISJUNCTION_HPP
#define DISJUNCTION_HPP

#include <iostream>

#include <binary_formula.hpp>
#include <formula.hpp>

/**
 * This class provides us application of binary "OR" operator (aka. disjunction) to the formulas we
 * provide to BinaryFormula. Class OR is using BinaryFormula constructor and methods, but it provides few
 * more methods of it's own.
 * For protected method m_print_formula we use operator |, since it means "or".
 *
 *  virtual bool evaluate(const Valuation&) const override;
 * This method is allowing us to evaluate some formula for the given valuation.
 * We do that on the provided valuation and evaluating recursevly for each right and left operand.
 * Recursion allows us to evaluate longer formulas. This method is overriden from binary formula.
 *
 * virtual Formula substitute(const Formula&, const Formula&) const override;
 *
 * QUESTIONS:
 * 1. SAME AS IN CONJUNCTION
*/

namespace art {
class Or : public BinaryFormula {
public:
    using BinaryFormula::BinaryFormula;

    virtual FormulaType get_type() const override;
    virtual Formula substitute(const Formula&, const Formula&) const override;

protected:
    virtual void m_print_formula(std::ostream&) const override;
};
}

#endif // JUNCTION_HPP


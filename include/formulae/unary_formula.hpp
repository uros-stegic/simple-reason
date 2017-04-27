#ifndef UNARY_FORMULA_HPP
#define UNARY_FORMULA_HPP

#include <iostream>

#include <formula.hpp>

/**
 *This class inherits methods from base formula. The main purpose of this class is to later provide
 * us application of NOT operator.
 *
 *  virtual void print_formula(std::ostream&) const override;
 * This method is allowing us to properly print this class given the output stream.
 * When we print this type of formula we want it to be surrounded by brackets.
 *
    virtual int complexity() const override;

    virtual bool operator <(const Formula&) const override;

    Formula get_operand() const;
   This method returns the operand on which we are later applying unary operator.

 *
 * QUESTIONS:
 * 1. Static_cast
 * 2. This explanation of class is bad.
 */

namespace AR {
class UnaryFormula : public BaseFormula {
public:
    UnaryFormula(const Formula&);

    virtual void print_formula(std::ostream&) const override;
    virtual int complexity() const override;
    virtual bool operator <(const Formula&) const override;

    Formula get_operand() const;

protected:
    bool m_is_equal(const Formula&) const override;
    virtual void m_get_atoms(AtomSet& atoms) const override;
    virtual void m_print_formula(std::ostream&) const = 0;

private:
    Formula m_operand;
};
}

#endif // UNARY_FORMULA_HPP


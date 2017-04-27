#ifndef BINARY_FORMULA_HPP
#define BINARY_FORMULA_HPP

#include <iostream>

#include <formula.hpp>

/**
 *This class is allowing us to apply binary operators to formulas. Class BinaryFormula, provided with
 * two formulas, sets m_left_operand to the first, and m_right_operand to the second formula.
 * Class BinaryFormula, since it inherits (and overrides) methods of BaseFormula, provides following
 * methods, for manipulation with these formulas:
 *  -public methods:
 *          Formula get_left_operand() const;
 *          Formula get_right_operand() const;
        These methods return whole formula of the left or right operand, returning m_left_operand or
        m_right_operand, respectively.

             virtual bool is_literal() const override;
        This method is returning false because, obviously, none of the binary formulas is a literal.
        Note that this method will be overriden in further classes inherited from this one (for them
        it will make sense checking whether we came up with a literal or not).

            virtual int complexity() const override;

            virtual bool operator <(const Formula&) const override;
      -protected methods:
            virtual bool m_is_equal(const Formula&) const override;
        This method is checking whether one binary formula is equal to another by comparing their
        left and right operand. We fetch formula's value with ((BinaryFormula*)f.get())->get_left_operand()
        because we have to reference what we get with f.get and then get it's left/right operand for comparison.

            virtual void m_get_atoms(AtomSet& atoms) const override;

            virtual void m_print_formula(std::ostream&) const = 0;
        This method allows us to print a formula.
   QUESTIONS:
   1. Not sure if I truly understand what complexity is for.
   2. Operator method ?
   3. Why protected?
   4. m_get_atoms
 */

namespace AR {
class BinaryFormula : public BaseFormula {
public:
    BinaryFormula(const Formula&, const Formula&);

    virtual void print_formula(std::ostream&) const override;

    Formula get_left_operand() const;
    Formula get_right_operand() const;

    virtual bool is_literal() const override;
    virtual int complexity() const override;
    virtual bool operator <(const Formula&) const override;

protected:
    virtual bool m_is_equal(const Formula&) const override;
    virtual void m_get_atoms(AtomSet& atoms) const override;
    virtual void m_print_formula(std::ostream&) const = 0;

private:
    Formula m_left_operand;
    Formula m_right_operand;
};
}

#endif // BINARY_FORMULA_HPP


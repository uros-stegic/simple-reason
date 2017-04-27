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
 * 		We want to use methods like get_operand(). This method is not defined in BaseFormula
 * 		so we need to `downcast` object to a class which has that method defined so that we
 * 		can call it. For example:
 * 			Formula f = std::make_shared<Not>(p);
 * 			Formula g = f->get_operand(); // Throws error, because BaseFormula doesn't have method `get_operand()`
 *
 * 			Formula f = std::make_shared<Not>(p);
 * 			Not *n = (Not*)f.get();
 * 			Formula g = n->get_operand(); // Works, because now n is an object of class Not which has said method
 *
 * 		This is kinda slow, because this casting is happening in runtime, when user runs the program. Since the compiler
 * 		is our bitch, we can make it do that casting in compile time, so when user runs our program, that object is
 * 		already in a form we want it to be. static_cast is a way of doing that.
 * 2. This explanation of class is bad.
 * 		It's ok. You kinda missed a point of all of these classes, but it's a subtle difference between what you wrote
 * 		and what's actually going on, so don't feel bad, you're good. :)
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


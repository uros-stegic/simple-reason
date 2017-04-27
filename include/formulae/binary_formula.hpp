#ifndef BINARY_FORMULA_HPP
#define BINARY_FORMULA_HPP

#include <iostream>

#include <formula.hpp>

/**
 * ***********
 * The purpose of this class is to abstract methods that all binary operators have in common, so that
 * you don't end up implementing the same methods over and over again in those classes (And, Or, If, Iff)
 * It's purpose is to minimize code repetitions. If it's still not clear, ask me again about this. :)
 * ***********
 * This class is allowing us to apply binary operators to formulas. Class BinaryFormula, provided with
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

		*** NOT TRUE ***
        * Note that this method will be overriden in further classes inherited from this one (for them
        * it will make sense checking whether we came up with a literal or not).
		****************

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
   		Proofs of correctness for some transformations (such as CNF) is done via induction over complexity.
		Complexity is property that basically counts the number of operators (and number of variables by some definitions)
   2. Operator method ?
   		I assume that you meant operator<. In C++ you can override what some operator means for your class. Let's say
		you are writing a library for linear algebra. You'd like to have a class that represents matricies, and you would
		like to be able to add two matrices together. One way is to create a method add(Matrix B) and to use it like this:
			Matrix A = read_matrix();
			Matrix B = read_matrix();
			std::cout << A.add(B) << std::endl;
		It is than better to implement operator+(Matrix B) in our Matrix class so we could call it like this:
			Matrix A = read_matrix();
			Matrix B = read_matrix();
			std::cout << A+B << std::endl;
		In our example, we implemented operator< so that we could calculate expressions like: f < g, for some formulas f and g.
		Why do we need to compute this kid of expressions? Well, at some time, we will need to have a set of formulas (`set` in
		a mathematical sense, a list in which no two elements are the same). We will use std::set for that purpose. std::set is
		a container class with a property that all it's elements are different (not only that, but it keeps the linear ordering).
		But how it knows if two elements are the same if you provide it your custom class? Well it expects that you implement
		operator< and after that it uses the fact that f == g if and only if !((f < g) || (g < f)) for arbitrary objects f and g.
   3. Why protected?
   		When you have many classes that are similar and all of them contains some method that differs only a little between them,
		then you can create some top-level class (and derive all your classes from this class), implement that method in a manner
		where you take the code that is the same in all those classes and put it inside this method from top-level class, then
		create a helper virtual method that will contain only the code that is different in your classes. For example, you want
		to print formulas. One way would be to implement the following method four times (in classes And, Or, If, Iff):
		  print_formula(std::ostream& out) {
			Formula l = get_left_operand();
			Formula r = get_left_operand

			l->print_formula(out);

			std::cout << " & " << std::endl; //this is the only line that will be different in all classes, other lines from this method would be the same.

			r->print_formula(out);
		  }
		Instead, we implement method here (only once):
		  print_formula(std::ostream& out) {
			Formula l = get_left_operand();
			Formula r = get_left_operand

			l->print_formula(out);

			m_print_formula(out); // <--- this is the only part that will differ in all of the classes

			r->print_formula(out);
		  }
		and the we implement four method (one in every class: And, Or...):
		  m_print_formula(std::ostream& out) {
			std::cout << " & " << std::endl;
		  }
		  m_print_formula(std::ostream& out) {
			std::cout << " | " << std::endl;
		  }
		  ...
		Why protected? Well, this is a helper method and it's not intended that user of our classes use this method. If he isn't going
		to use it, then why should he see that it exists? It's a good practice to hide implementation detail from user. Why not private than?
		If we declare this method as private, then the derived classes (And, Or, ...) would also not see that it exists. This access modifier
		(protected) is the golden middle. :)
   4. m_get_atoms
   		See the above. Ask if it's still not clear. :)
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


#ifndef FORMULA_HPP
#define FORMULA_HPP

#include <iostream>
#include <set>
#include <memory>

namespace art {
enum FormulaType {
    PROP_LETTER,
    PROP_TRUE,
    PROP_FALSE,
    NEGATION,
    CONJUNCTION,
    DISJUNCTION,
    IMPLICATION,
    EQUIVALENCE,
    PREDICATE,
    FOR_ALL,
    EXISTS
};

class BaseFormula;
class Transformation;
class Valuation;

typedef std::shared_ptr<const BaseFormula> Formula;
typedef std::set<unsigned int> AtomSet;

struct FormulaCompare {
    bool operator()(const Formula&, const Formula&) const;
};

/**
 * @brief The BaseFormula class
 * This class provides us basic methods for working with formulas. This class is at the top of
 *  formulas hierarchy. All methods here are abstract, we cannot instantiate a BaseFormula object.
    We enable shared from this...
    QUESTIONS:
    1. What should I explain from here? Each class will be explained in classes lower in hierarchy.
		Folder include/formulae contains nodes of Abstract Syntax Tree. AST is data structure that
		we need in order to keep syntactical constructs in memory. It is implemented as a (binary)
		tree. This AST contains nodes (objects) of the formula. BaseFormula class is the abstraction
		of all possible nodes. It contains a pattern that must be filled in order for some class
		can be called node of this tree (this pattern is described by `pure virtual` methods).
		See: https://en.wikipedia.org/wiki/Abstract_syntax_tree
    2. How to properly explain shared from this?
		Shared pointers wrap around regular pointers. They are awesome as long as no one messes with
		the undelying regular pointers that they wrapped. If someone break those pointers, then
		the shared pointer will be broken as well. When we do `return this` it will return regular
		pointer, since `this` is a regular pointer. This is not what we want, we want to return shared
		pointer, not the regular one. If we use make_shared on `this` then new pointer will be created.
		We then use shared_from_this() method that will wrap `this` pointer in a good way. In order
		to have that method in our class, we need to extend the class enable_shared_from_this.
    3. What is the difference between const = 0 and const?
		const means that this method will not modify object which it's called from in any way. `= 0`
		is explained in include/formulae/atomic.hpp. `const` and `=0` are independent of each other
		which means all of these are valid:
			virtual void f();
			virtual void f() const;
			virtual void f() const = 0;
			virtual void f() = 0;
			void f()
			void f() const;

    COMMENT: This part we should pass together again :(
	So true. :)
*/

class BaseFormula : public std::enable_shared_from_this<BaseFormula> {
public:
    virtual FormulaType get_type() const = 0;
    virtual void print_formula(std::ostream&) const = 0;
    virtual int complexity() const = 0;
    virtual bool equals(const Formula&) const;
    Formula copy() const;

    virtual AtomSet get_atoms() const;
    virtual bool is_literal() const = 0;
    virtual bool operator <(const Formula&) const = 0;
    bool operator !=(const Formula&) const;
    bool operator ==(const Formula&) const;
    bool operator >(const Formula&) const;
    bool operator <=(const Formula&) const;
    bool operator >=(const Formula&) const;

    Formula transform(const Transformation&) const;
    virtual Formula substitute(const Formula&, const Formula&) const = 0;

    static std::string unique();
    
protected:
    virtual bool m_is_equal(const Formula&) const = 0;
    virtual void m_get_atoms(AtomSet&) const;

private:
    static unsigned int m_next_unique;

};
}
std::ostream& operator <<(std::ostream& out, const art::Formula& f);
bool operator <(const art::Formula&, const art::Formula&);
bool operator !=(const art::Formula&, const art::Formula&);
bool operator ==(const art::Formula&, const art::Formula&);
bool operator >(const art::Formula&, const art::Formula&);
bool operator <=(const art::Formula&, const art::Formula&);
bool operator >=(const art::Formula&, const art::Formula&);

#endif // FORMULA_HPP


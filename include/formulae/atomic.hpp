#ifndef ATOMIC_HPP
#define ATOMIC_HPP

#include <formula.hpp>

/**
 *This class provides us some methods for work with atomic formulas, it is inherited from class
 * BaseFormula. This class is providing few virtual methods such as: for checking wheter a formula is
 * literal, for complexity and for substitution of one formula with another.
 *
 * QUESTIONS:
 * 1. After looking through some files, I am still unable to find BaseFormula class. Not sure if
 *  blind or what. Where can I find it's definition and declaration?
 *  	Declaration and definition of class BaseFormula are written in files include/formualae/formula.hpp
 *  	and src/formulae/formula.cpp respectively. What's confusing with this filename/classname is the
 *  	fact that we are using the type Formula for our formulas (which is the main reason for that filename).
 *  	Type Formula is not our class, but purely a typedef (to a wrapper around BaseFormula).
 * 2. Is this class abstract? That means we cannot instantiate it but only the classes which inherit
 *  from this class. ---> Yes (because all the methods are virtual and will be overriden in later
 * in classes which inherit this one).
 * 		This class is abstract but not because it has virtual methods. This class publicly extends class
 * 		BaseFormula. The effect of public extension is (in a sense) that it "copies" all public stuff from 
 * 		the base class (in our example it's from BaseFormula). Class BaseFormula contains `pure virtual`
 * 		methods. Method is virtual if you give it's implementation but suggest that when program runs it's
 * 		better to execute that same method from derived class if it exists, and you provide this implementation
 * 		`just in case`. Method is `pure virtual` if you explicitly say that you are NOT going
 * 		to implement it and that you expect from derived classes to do that. If your class contains `pure virtual`
 * 		method, that means that your class is abstract and you cannot instatiate it (if you could, how would you
 * 		execute that pure virtual method for whom you didn't give an implementation). If your class extends abstract
 * 		class, AND fails to implement those `pure virtual` methods, than that derived class is also abstract. By the
 * 		way, you give a virtual method purity by saying " = 0" at the end of its declaration. In our example, BaseClass has a
 * 		pure virtual method `virtual void print_formula(std::ostream&) const = 0` and this class, AtomicFormula, doesn't implement
 * 		it, so that method remains pure virtual in this class (/wo explicitly writing it). Hence, this class is also abstract.
 */

namespace art {
class AtomicFormula : public BaseFormula {
public:
    virtual bool is_literal() const override;
    virtual int complexity() const override;
    virtual Formula substitute(const Formula&, const Formula&) const override;
	virtual bool has_free(const std::string&) const override;
};
}

#endif // ATOMIC_HPP


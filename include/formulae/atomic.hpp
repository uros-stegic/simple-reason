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
 * 2. Is this class abstract? That means we cannot instantiate it but only the classes which inherit
 *  from this class. ---> Yes (because all the methods are virtual and will be overriden in later
 * in classes which inherit this one).
 */

namespace AR {
class AtomicFormula : public BaseFormula {
public:
    virtual bool is_literal() const override;
    virtual int complexity() const override;
    virtual Formula substitute(const Formula&, const Formula&) const override;
};
}

#endif // ATOMIC_HPP


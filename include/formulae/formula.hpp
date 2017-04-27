#ifndef FORMULA_HPP
#define FORMULA_HPP

#include <iostream>
#include <set>
#include <memory>

namespace AR {
enum FormulaType {
    PROP_LETTER,
    PROP_TRUE,
    PROP_FALSE,
    NEGATION,
    CONJUNCTION,
    DISJUNCTION,
    IMPLICATION,
    EQUIVALENCE
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
    2. How to properly explain shared from this?
    3. What is the difference between const = 0 and const?

    COMMENT: This part we should pass together again :(
*/

class BaseFormula : public std::enable_shared_from_this<BaseFormula> {
public:
    virtual FormulaType get_type() const = 0;
    virtual void print_formula(std::ostream&) const = 0;
    virtual int complexity() const = 0;
    virtual bool equals(const Formula&) const;
    Formula copy() const;

    virtual AtomSet get_atoms() const;
    virtual bool evaluate(const Valuation&) const = 0;
    virtual bool is_literal() const = 0;
    virtual bool operator <(const Formula&) const = 0;
    bool operator !=(const Formula&) const;
    bool operator ==(const Formula&) const;
    bool operator >(const Formula&) const;
    bool operator <=(const Formula&) const;
    bool operator >=(const Formula&) const;

    Formula transform(const Transformation&) const;
    virtual Formula substitute(const Formula&, const Formula&) const = 0;
    
protected:
    virtual bool m_is_equal(const Formula&) const = 0;
    virtual void m_get_atoms(AtomSet&) const;
};
}
std::ostream& operator <<(std::ostream& out, const AR::Formula& f);
bool operator <(const AR::Formula&, const AR::Formula&);
bool operator !=(const AR::Formula&, const AR::Formula&);
bool operator ==(const AR::Formula&, const AR::Formula&);
bool operator >(const AR::Formula&, const AR::Formula&);
bool operator <=(const AR::Formula&, const AR::Formula&);
bool operator >=(const AR::Formula&, const AR::Formula&);

#endif // FORMULA_HPP


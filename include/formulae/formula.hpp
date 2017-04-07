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

class BaseFormula : public std::enable_shared_from_this<BaseFormula> {
public:
    virtual FormulaType get_type() const = 0;
    virtual void print_formula(std::ostream&) const = 0;
    virtual int complexity() const = 0;
    virtual bool equals(const Formula&) const;
    Formula copy() const;

    virtual AtomSet get_atoms() const;
    virtual bool evaluate(const Valuation&) const = 0;

    Formula transform(const Transformation&) const;
    virtual Formula substitute(const Formula&, const Formula&) const = 0;
    
protected:
    virtual bool m_is_equal(const Formula&) const = 0;
    virtual void m_get_atoms(AtomSet&) const;
};
}
std::ostream& operator <<(std::ostream& out, const AR::Formula& f);

#endif // FORMULA_HPP


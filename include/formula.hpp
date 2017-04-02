#ifndef FORMULA_HPP
#define FORMULA_HPP

#include <iostream>

#include <definitions.hpp>
#include <valuation.hpp>

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

class BaseFormula : public std::enable_shared_from_this<BaseFormula> {
public:
    virtual FormulaType get_type() const = 0;
    virtual void print_formula(std::ostream&) const = 0;
    virtual int complexity() const = 0;
    virtual bool equals(const Formula&) const;

    virtual AtomSet get_atoms() const;
    virtual bool evaluate(const Valuation&) const = 0;

    bool is_satisfiable() const;
    bool is_tautology() const;
    bool is_contradiction() const;
    bool is_deniable() const;

    virtual Formula substitute(const Formula&, const Formula&) const = 0;
    virtual Formula simplify() const = 0;
    virtual Formula nnf() const;
    virtual Formula cnf() const;
    
protected:
    virtual bool m_is_equal(const Formula&) const = 0;
    virtual void m_get_atoms(AtomSet&) const;
    virtual Formula m_nnf() const = 0;
    virtual Formula m_cnf() const = 0;
};
}
std::ostream& operator <<(std::ostream& out, const AR::Formula& f);

#endif // FORMULA_HPP


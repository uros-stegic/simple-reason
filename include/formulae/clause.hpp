#ifndef CLAUSE_HPP
#define CLAUSE_HPP

#include <formula.hpp>
#include <set>
#include <initializer_list>

namespace AR {

class Clause : public BaseFormula {
public:
    Clause();
    Clause(const std::initializer_list<Formula>&);

    virtual FormulaType get_type() const override;
    virtual void print_formula(std::ostream&) const override;
    virtual int complexity() const override;
    virtual bool is_literal() const override;
    virtual bool operator <(const Formula&) const override;

    virtual bool evaluate(const Valuation&) const override;
    virtual Formula substitute(const Formula&, const Formula&) const override;

protected:
    virtual bool m_is_equal(const Formula&) const override;
    virtual void m_get_atoms(AtomSet &) const override;

private:
    std::set<Formula,FormulaCompare> m_formulas;
};
}

#endif // CLAUSE_HPP

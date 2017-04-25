#ifndef CNF_HPP
#define CNF_HPP

#include <formula.hpp>
#include <clause.hpp>
#include <set>
#include <iterator>
#include <initializer_list>

namespace AR {
class CNF : public BaseFormula {
public:
    CNF();
    CNF(const std::initializer_list<Formula>&);

    virtual FormulaType get_type() const override;
    virtual void print_formula(std::ostream&) const override;
    virtual int complexity() const override;
    virtual bool is_literal() const override;
    virtual bool operator <(const Formula&) const override;

    virtual bool evaluate(const Valuation&) const override;

    virtual Formula substitute(const Formula&, const Formula&) const override;
    Formula add_clause(const Formula&) const;
    Formula join(const Formula&) const;

protected:
    virtual bool m_is_equal(const Formula&) const override;
    virtual void m_get_atoms(AtomSet&) const;

private:
    std::set<Formula,FormulaCompare> m_clauses;
};
}

#endif // CNF_HPP

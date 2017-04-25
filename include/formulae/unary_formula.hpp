#ifndef UNARY_FORMULA_HPP
#define UNARY_FORMULA_HPP

#include <iostream>

#include <formula.hpp>

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


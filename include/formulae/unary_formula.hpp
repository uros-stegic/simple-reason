#ifndef UNARY_FORMULA_HPP
#define UNARY_FORMULA_HPP

#include <iostream>

#include <formula.hpp>

namespace AR {
class UnaryFormula : public BaseFormula {
public:
    UnaryFormula(const Formula&);

    virtual void print_formula(std::ostream&) const;
    Formula get_operand() const;

    virtual int complexity() const;

protected:
    bool m_is_equal(const Formula&) const;
    virtual void m_get_atoms(AtomSet& atoms) const;
    virtual void m_print_formula(std::ostream&) const = 0;

private:
    Formula m_operand;
};
}

#endif // UNARY_FORMULA_HPP


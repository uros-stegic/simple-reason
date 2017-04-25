#ifndef BINARY_FORMULA_HPP
#define BINARY_FORMULA_HPP

#include <iostream>

#include <formula.hpp>

namespace AR {
class BinaryFormula : public BaseFormula {
public:
    BinaryFormula(const Formula&, const Formula&);

    virtual void print_formula(std::ostream&) const override;

    Formula get_left_operand() const;
    Formula get_right_operand() const;

    virtual bool is_literal() const override;
    virtual int complexity() const override;
    virtual bool operator <(const Formula&) const override;

protected:
    virtual bool m_is_equal(const Formula&) const override;
    virtual void m_get_atoms(AtomSet& atoms) const override;
    virtual void m_print_formula(std::ostream&) const = 0;

private:
    Formula m_left_operand;
    Formula m_right_operand;
};
}

#endif // BINARY_FORMULA_HPP


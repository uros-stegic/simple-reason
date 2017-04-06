#ifndef BINARY_FORMULA_HPP
#define BINARY_FORMULA_HPP

#include <iostream>

#include <definitions.hpp>
#include <formula.hpp>

namespace AR {
class BinaryFormula : public BaseFormula {
public:
    BinaryFormula(const Formula&, const Formula&);

    virtual void print_formula(std::ostream&) const;

    Formula get_left_operand() const;
    Formula get_right_operand() const;

    virtual int complexity() const;

protected:
    virtual bool m_is_equal(const Formula&) const;
    virtual void m_get_atoms(AtomSet& atoms) const;
    virtual void m_print_formula(std::ostream&) const = 0;

private:
    Formula m_left_operand;
    Formula m_right_operand;
};
}

#endif // BINARY_FORMULA_HPP


#ifndef LETTER_HPP
#define LETTER_HPP

#include <iostream>

#include <atomic.hpp>
#include <formula.hpp>
#include <valuation.hpp>

namespace AR {
class Var : public AtomicFormula {
public:
    Var(unsigned int id);

    virtual FormulaType get_type() const override;
    virtual void print_formula(std::ostream&) const override;
    virtual bool evaluate(const Valuation&) const override;
    virtual bool operator <(const Formula&) const override;

    unsigned int get_id() const;

protected:
    bool m_is_equal(const Formula&) const override;
    void m_get_atoms(AtomSet&) const override;

private:
    unsigned int m_id;
};
}

#endif // LETTER_HPP


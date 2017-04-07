#ifndef EQUIVALENCE_HPP
#define EQUIVALENCE_HPP

#include <iostream>

#include <binary_formula.hpp>
#include <valuation.hpp>
#include <formula.hpp>

namespace AR {
class Iff : public BinaryFormula {
public:
    using BinaryFormula::BinaryFormula;

    virtual FormulaType get_type() const;
    virtual bool evaluate(const Valuation&) const;

    virtual Formula substitute(const Formula&, const Formula&) const;

protected:
    virtual void m_print_formula(std::ostream&) const;
};
}

#endif // EQUIVALENCE_HPP


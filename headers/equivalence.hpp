#ifndef EQUIVALENCE_HPP
#define EQUIVALENCE_HPP

#include <iostream>

#include <definitions.hpp>
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
    virtual Formula simplify() const;

protected:
    virtual void m_print_formula(std::ostream&) const;
    virtual Formula m_nnf() const;
};
}

#endif // EQUIVALENCE_HPP


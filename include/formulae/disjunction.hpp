#ifndef DISJUNCTION_HPP
#define DISJUNCTION_HPP

#include <iostream>

#include <binary_formula.hpp>
#include <valuation.hpp>
#include <formula.hpp>

namespace AR {
class Or : public BinaryFormula {
public:
    using BinaryFormula::BinaryFormula;

    virtual FormulaType get_type() const;
    virtual bool evaluate(const Valuation&) const;

    virtual Formula substitute(const Formula&, const Formula&) const;

protected:
    virtual void m_print_formula(std::ostream&) const;
};
}

#endif // JUNCTION_HPP


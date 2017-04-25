#ifndef IMPLICATION_HPP
#define IMPLICATION_HPP

#include <iostream>

#include <binary_formula.hpp>
#include <formula.hpp>
#include <valuation.hpp>

namespace AR {
class If : public BinaryFormula {
public:
    using BinaryFormula::BinaryFormula;

    virtual FormulaType get_type() const override;
    virtual bool evaluate(const Valuation&) const override;

    virtual Formula substitute(const Formula&, const Formula&) const override;

protected:
    virtual void m_print_formula(std::ostream&) const override;
};
}

#endif // IMPLICATION_HPP


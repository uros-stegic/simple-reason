#ifndef NEGATION_HPP
#define NEGATION_HPP

#include <iostream>

#include <unary_formula.hpp>
#include <formula.hpp>
#include <valuation.hpp>

namespace AR {
class Not : public UnaryFormula {
public:
    using UnaryFormula::UnaryFormula;

    virtual FormulaType get_type() const override;
    virtual bool evaluate(const Valuation&) const override;
    virtual bool is_literal() const override;

    virtual Formula substitute(const Formula&, const Formula&) const override;

protected:
    virtual void m_print_formula(std::ostream&) const override;
};
}

#endif // NEGATION_HPP


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

    virtual FormulaType get_type() const;
    virtual bool evaluate(const Valuation&) const;

    virtual Formula substitute(const Formula&, const Formula&) const;

protected:
    virtual void m_print_formula(std::ostream&) const;
};
}

#endif // NEGATION_HPP


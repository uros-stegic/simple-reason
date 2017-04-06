#ifndef IMPLICATION_HPP
#define IMPLICATION_HPP

#include <iostream>

#include <binary_formula.hpp>
#include <definitions.hpp>
#include <formula.hpp>
#include <valuation.hpp>

namespace AR {
class If : public BinaryFormula {
public:
    using BinaryFormula::BinaryFormula;

    virtual FormulaType get_type() const;
    virtual bool evaluate(const Valuation&) const;

    virtual Formula substitute(const Formula&, const Formula&) const;

protected:
    virtual void m_print_formula(std::ostream&) const;
};
}

#endif // IMPLICATION_HPP


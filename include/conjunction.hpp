#ifndef CONJUNCTION_HPP
#define CONJUNCTION_HPP

#include <iostream>

#include <definitions.hpp>
#include <binary_formula.hpp>
#include <valuation.hpp>
#include <formula.hpp>

namespace AR {
class And : public BinaryFormula {
public:
    using BinaryFormula::BinaryFormula;

    virtual FormulaType get_type() const;
    virtual bool evaluate(const Valuation&) const;

    virtual Formula substitute(const Formula&, const Formula&) const;

protected:
    virtual void m_print_formula(std::ostream&) const;
};
}

#endif // CONJUNCTION_HPP


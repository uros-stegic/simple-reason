#ifndef TRUE_CONSTANT_HPP
#define TRUE_CONSTANT_HPP

#include <iostream>

#include <constant.hpp>
#include <valuation.hpp>
#include <formula.hpp>

namespace AR {
class True : public Constant {
public:
    virtual FormulaType get_type() const override;
    virtual void print_formula(std::ostream&) const override;
    virtual bool evaluate(const Valuation&) const override;
};
}

#endif // TRUE_CONSTANT_HPP


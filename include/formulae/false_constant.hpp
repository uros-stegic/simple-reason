#ifndef FALSE_CONSTANT_HPP
#define FALSE_CONSTANT_HPP

#include <iostream>

#include <constant.hpp>
#include <formula.hpp>
#include <valuation.hpp>

namespace AR {
class False : public Constant {
public:
    virtual FormulaType get_type() const override;
    virtual void print_formula(std::ostream&) const override;
    virtual bool evaluate(const Valuation&) const override;
};
}

#endif // FALSE_CONSTANT_HPP


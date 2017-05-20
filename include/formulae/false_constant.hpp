#ifndef FALSE_CONSTANT_HPP
#define FALSE_CONSTANT_HPP

#include <iostream>

#include <logic_constant.hpp>
#include <formula.hpp>
#include <valuation.hpp>

namespace art {
class False : public LogicConstant {
public:
    virtual FormulaType get_type() const override;
    virtual void print_formula(std::ostream&) const override;

};
}

#endif // FALSE_CONSTANT_HPP


#ifndef TRUE_CONSTANT_HPP
#define TRUE_CONSTANT_HPP

#include <iostream>

#include <logic_constant.hpp>
#include <formula.hpp>

/**
 *This class provides us with T (always true), with following methods:
 *      virtual FormulaType get_type() const override;
 *  This method returns enum type provided in formula.hpp PROP_TRUE.
        virtual void print_formula(std::ostream&) const override;
    This method returns 1, because 1 is always true.
        virtual bool evaluate(const Valuation&) const override;
    Evaluation of something that is always true is obviously true.

 *
 */

namespace art {
class True : public LogicConstant {
public:
    virtual FormulaType get_type() const override;
    virtual void print_formula(std::ostream&) const override;

};
}

#endif // TRUE_CONSTANT_HPP


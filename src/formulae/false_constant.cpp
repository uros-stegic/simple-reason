#include <false_constant.hpp>
#include <valuation.hpp>

#include <iostream>

using namespace AR;

FormulaType False::get_type() const
{
    return PROP_FALSE;
}
void False::print_formula(std::ostream& out) const
{
    out << "0";
}


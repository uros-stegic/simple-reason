#include <false_constant.hpp>

#include <iostream>

using namespace art;

FormulaType False::get_type() const
{
    return PROP_FALSE;
}
void False::print_formula(std::ostream& out) const
{
    out << "⊥";
}


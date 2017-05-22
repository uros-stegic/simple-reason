#include <true_constant.hpp>
#include <valuation.hpp>

#include <iostream>

using namespace art;

FormulaType True::get_type() const
{
    return PROP_TRUE;
}
void True::print_formula(std::ostream& out) const
{
    out << "⊤";
}



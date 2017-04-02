#include <false_constant.hpp>

using namespace AR;

FormulaType False::get_type() const
{
    return PROP_FALSE;
}
void False::print_formula(std::ostream& out) const
{
    out << "0";
}

bool False::evaluate(const Valuation& val) const
{
    return false;
}


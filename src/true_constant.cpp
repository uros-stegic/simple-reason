#include <true_constant.hpp>

using namespace AR;

FormulaType True::get_type() const
{
    return PROP_TRUE;
}
void True::print_formula(std::ostream& out) const
{
    out << "1";
}

bool True::evaluate(const Valuation& val) const
{
    return true;
}


#include <iostream>
#include <quantifier.hpp>
#include <exists.hpp>

using namespace art;

void Exists::m_print_formula(std::ostream& out) const
{
    out << "∃";
    var()->print_term(out);
    out << ". ";

}

Formula Exists::substitute(const Formula&, const Formula&) const
{
    return shared_from_this();
}

FormulaType Exists::get_type() const
{
    return EXISTS;
}


#include <iostream>
#include <quantifier.hpp>
#include <for_all.hpp>

using namespace AR;

void ForAll::m_print_formula(std::ostream& out) const
{
    out << "Ɐ" << var_name() << ". ";

}

Formula ForAll::substitute(const Formula&, const Formula&) const
{
    return shared_from_this();
}

FormulaType ForAll::get_type() const
{
    return FOR_ALL;
}


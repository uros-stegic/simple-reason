#include <iostream>
#include <string>
#include <var.hpp>

using namespace art;

Var::Var(std::string n)
    : m_name(n)
{}

void Var::print_term(std::ostream & out) const
{
    out << m_name;
}

std::string Var::name() const
{
    return m_name;
}

TermType Var::get_type() const
{
    return VARIABLE;
}

int Var::complexity() const
{
    return 1;
}

bool Var::m_is_equal(const Term& other) const
{
    return m_name == static_cast<const Var*>(other.get())->name();
}

bool Var::has_free(const std::string& var) const
{
	return var == m_name;
}


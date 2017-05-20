#include <iostream>
#include <string>
#include <constant.hpp>

using namespace art;

Constant::Constant(std::string n)
    : m_name(n)
{}

void Constant::print_term(std::ostream & out) const
{
    out << m_name;
}

std::string Constant::name() const
{
    return m_name;
}

TermType Constant::get_type() const
{
    return CONSTANT;
}

int Constant::complexity() const
{
    return 0;
}

bool Constant::m_is_equal(const Term& other) const
{
//    const BaseTerm* r = c.get();
//    const Constant* con = static_cast<const Constant*>(r);
    return m_name == static_cast<const Constant*>(other.get())->name();
}

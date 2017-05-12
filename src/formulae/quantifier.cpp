#include <iostream>
#include <memory>
#include <string>
#include <unary_formula.hpp>
#include <quantifier.hpp>

using namespace AR;

Quantifier::Quantifier(const Formula &f, std::string n)
    : UnaryFormula(f)
    , m_var_name(n)
{}

std::string Quantifier::var_name() const
{
    return m_var_name;
}

bool Quantifier::is_literal() const
{
    return false;
}

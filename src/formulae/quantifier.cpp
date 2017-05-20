#include <iostream>
#include <memory>
#include <string>
#include <unary_formula.hpp>
#include <quantifier.hpp>

using namespace art;

Quantifier::Quantifier(const Formula& f, const Term& t)
    : UnaryFormula(f)
    , m_term(t)
{}

Term Quantifier::var() const
{
    return m_term;
}

bool Quantifier::is_literal() const
{
    return false;
}

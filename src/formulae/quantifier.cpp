#include <iostream>
#include <memory>
#include <string>
#include <formulae.hpp>

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

bool Quantifier::has_free(const std::string& var) const
{
	if( get_operand()->has_free(var) ) {
		return static_cast<const Var*>(m_term.get())->name() != var;
	}
	return false;
}


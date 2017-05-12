#include <iostream>
#include <memory>
#include <vector>
#include <string>
#include <algorithm>
#include <term.hpp>
#include <predicate.hpp>

using namespace AR;

Predicate::Predicate(std::string n, const std::vector<Term> &t)
    : m_name(n)
    , m_terms(t)
{}


void Predicate::print_formula(std::ostream & out) const
{
    out << m_name;
    out << "(";

    (*std::begin(m_terms))->print_term(out);

    std::for_each(
        ++std::begin(m_terms),
        std::end(m_terms),
        [&](const Term& term) {
            out << ", ";
            term->print_term(out);
        }
    );

    out << ")";
}

std::string Predicate::name() const
{
    return m_name;
}

FormulaType Predicate::get_type() const
{
    return PREDICATE;
}


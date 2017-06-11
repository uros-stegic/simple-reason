#include <iostream>
#include <memory>
#include <vector>
#include <string>
#include <algorithm>
#include <term.hpp>
#include <predicate.hpp>

using namespace art;

Predicate::Predicate(const std::vector<Term> &t, std::string n)
    : m_terms(t)
    , m_name(n)
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

bool Predicate::operator <(const Formula& f) const
{
    return false;
}

bool Predicate::m_is_equal(const Formula& other) const
{
    return m_name == static_cast<const Predicate*>(other.get())->name();
}

std::vector<Term> Predicate::terms() const
{
    return m_terms;
}

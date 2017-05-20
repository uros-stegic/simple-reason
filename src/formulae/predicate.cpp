#include <iostream>
#include <memory>
#include <vector>
#include <string>
#include <algorithm>
#include <term.hpp>
#include <predicate.hpp>

using namespace AR;

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

virtual bool operator <(const Formula& f) const
{

}

virtual bool m_is_equal(const Formula& other) const
{
    return m_name == static_cast<const Predicate*>(other.get())->name();
}

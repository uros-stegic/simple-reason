#include <iostream>
#include <memory>
#include <vector>
#include <algorithm>
#include <numeric>
#include <function.hpp>

using namespace art;

Function::Function(std::string n, const std::vector<Term> &t)
    : m_name(n)
    , m_terms(t)
{}

void Function::print_term(std::ostream & out) const
{
    out << m_name;
    out << "(";
    (*std::begin(m_terms))->print_term(out);
    std::for_each(
        ++std::begin(m_terms),
        std::end(m_terms),
        [&](const Term& term){
            out << ", ";
            term->print_term(out);
        }
    );
    out << ")";
}

std::string Function::name() const
{
    return m_name;
}

TermType Function::get_type() const
{
    return FUNCTION;
}

int Function::complexity() const
{
   return std::accumulate(
        std::begin(m_terms),
        std::end(m_terms),
        1,
        [&](int acc, const Term &term){
          return acc + term->complexity();
        }
    );
}

bool Function::m_is_equal(const Term&) const
{
    return false;
}

std::vector<Term> Function::terms() const
{
    return m_terms;
}

bool Function::has_free(const std::string& var) const
{
   return std::accumulate(
        std::begin(m_terms),
        std::end(m_terms),
        false,
        [var](bool acc, const Term &term){
          return acc || term->has_free(var);
        }
    );
}


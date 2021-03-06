#include <vector>
#include <equals.hpp>

using namespace art;

Equals::Equals(const Term& t1, const Term& t2)
    : Predicate(std::vector<Term>{t1, t2}, "=")
    , m_t1(t1)
    , m_t2(t2)
{}

void Equals::print_formula(std::ostream & out) const
{
    m_t1->print_term(out);
    out << " " << name() << " ";
    m_t2->print_term(out);
}

FormulaType Equals::get_type() const
{
    return EQUALS;
}


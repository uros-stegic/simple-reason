#include <vector>
#include <not_equals.hpp>

using namespace art;

NotEquals::NotEquals(const Term& t1, const Term& t2)
    : Predicate(std::vector<Term>{t1, t2}, "≠")
    , m_t1(t1)
    , m_t2(t2)
{}

void NotEquals::print_formula(std::ostream & out) const
{
    m_t1->print_term(out);
    out << " " << name() << " ";
    m_t2->print_term(out);
}

FormulaType NotEquals::get_type() const
{
    return NOT_EQUALS;
}


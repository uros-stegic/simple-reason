#include <equivalence.hpp>

#include <iostream>

using namespace art;

FormulaType Iff::get_type() const
{
    return EQUIVALENCE;
}

void Iff::m_print_formula(std::ostream& out) const
{
    out << " ⇔ ";
}

Formula Iff::substitute(const Formula& from, const Formula& to) const
{
    if( get_type() != from->get_type() || !equals(from) ) {
        return std::make_shared<Iff>(
                    get_left_operand() ->substitute(from, to),
                    get_right_operand()->substitute(from, to)
                );
    }
    return to;
}

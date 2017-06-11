#include <iostream>
#include <memory>
#include <set>
#include <term.hpp>
#include <transformation.hpp>

using namespace art;

bool BaseTerm::equals(const Term& other) const
{
    if( get_type() == other->get_type() ) {
        return m_is_equal(other);
    }
    return false;
}

Term BaseTerm::copy() const
{
    return shared_from_this();
}

std::ostream& operator <<(std::ostream& out, const art::Term& t)
{
    t->print_term(out);
    return out;
}

Term BaseTerm::transform(const Transformation& t) const
{
    return t.transform(shared_from_this());
}

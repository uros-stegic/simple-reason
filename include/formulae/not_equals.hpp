#ifndef NOT_EQUALS_HPP
#define NOT_EQUALS_HPP

#include <predicate.hpp>

namespace art {
class NotEquals : public Predicate{
  public:
    NotEquals(const Term&, const Term&);
    virtual void print_formula(std::ostream & out) const override;

private:
    Term m_t1, m_t2;
};
}

#endif // NOT_EQUALS_HPP


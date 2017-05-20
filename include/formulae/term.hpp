#ifndef TERM_HPP
#define TERM_HPP

#include <iostream>
#include <memory>
#include <set>

namespace art{
enum TermType {
    VARIABLE,
    CONSTANT,
    FUNCTION
};

class BaseTerm;

typedef std::shared_ptr<const BaseTerm> Term;

struct TermCompare{
    bool operator()(const Term&, const Term&) const;
};

class BaseTerm : public std::enable_shared_from_this<BaseTerm> {
public:
    virtual TermType get_type() const = 0;
    virtual void print_term(std::ostream&) const = 0;
    virtual int complexity() const = 0;
    virtual bool equals(const Term&) const;
    Term copy() const;


protected:
    virtual bool m_is_equal(const Term&) const = 0;
};
}
std::ostream& operator <<(std::ostream& out, const art::Term& t);

#endif //TERM_HPP

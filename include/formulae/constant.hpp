#ifndef CONSTANT_HPP
#define CONSTANT_HPP

#include <iostream>
#include <string>
#include <term.hpp>

namespace AR{
class Constant : public BaseTerm {
public:
    Constant(std::string);
    virtual void print_term(std::ostream &) const;
    virtual std::string name() const;
    virtual TermType get_type() const;
    virtual int complexity() const;

protected:
    virtual bool m_is_equal(const Term&) const;

private:
    std::string m_name;
};
}

#endif

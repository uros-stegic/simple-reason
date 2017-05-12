#ifndef FUNCTION_HPP
#define FUNCTION_HPP

#include <iostream>
#include <vector>
#include <memory>
#include <string>
#include <term.hpp>

namespace AR{
class Function : public BaseTerm{
public:
    Function(std::string, const std::vector<Term> &);
    virtual void print_term(std::ostream &) const;
    virtual std::string name() const;

    virtual TermType get_type() const;
    virtual int complexity() const;

protected:
    bool m_is_equal(const Term&) const;

private:
    std::string m_name;
    std::vector<Term> m_terms;
};
}

#endif

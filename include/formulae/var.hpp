#ifndef VAR_HPP
#define VAR_HPP

#include <iostream>
#include <string>
#include <term.hpp>

namespace AR{
class Var : public BaseTerm {
public:
    Var(std::string);
    virtual std::string name() const;
    virtual void print_term(std::ostream &) const override;
    virtual TermType get_type() const override;
    virtual int complexity() const override;

protected:
     virtual bool m_is_equal(const Term&) const override;

private:
    std::string m_name;
};
}

#endif //VAR_HPP

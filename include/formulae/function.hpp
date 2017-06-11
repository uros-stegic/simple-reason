#ifndef FUNCTION_HPP
#define FUNCTION_HPP

#include <iostream>
#include <vector>
#include <memory>
#include <string>
#include <term.hpp>

namespace art{
class Function : public BaseTerm{
public:
    Function(std::string, const std::vector<Term> &);
    virtual std::string name() const;
    virtual void print_term(std::ostream &) const override;
    virtual TermType get_type() const override;
    virtual int complexity() const override;
    std::vector<Term> terms() const;

protected:
    bool m_is_equal(const Term&) const override;

private:
    std::string m_name;
    std::vector<Term> m_terms;
};
}

#endif //FUNCTION_HPP

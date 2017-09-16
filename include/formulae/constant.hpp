#ifndef CONSTANT_HPP
#define CONSTANT_HPP

#include <iostream>
#include <string>
#include <term.hpp>

namespace art{
class Constant : public BaseTerm {
public:
    Constant(std::string);
    virtual std::string name() const;
    virtual void print_term(std::ostream &) const override;
    virtual TermType get_type() const override;
    virtual int complexity() const override;
	bool has_free(const std::string&) const override;

protected:
    virtual bool m_is_equal(const Term&) const override;

private:
    std::string m_name;
};
}

#endif //CONSTANT_HPP

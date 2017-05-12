/* Quantifier која наслеђује класу Unarni operator и
садржи сопствен назив (std::string) и
подформулу (Formula);*/
#ifndef QUANTIFIER_HPP
#define QUANTIFIER_HPP

#include <stdio.h>
#include <string>
#include <memory>
#include <unary_formula.hpp>

namespace AR{
class Quantifier : public UnaryFormula {
public:
    Quantifier(const Formula&, std::string);
    virtual std::string var_name() const;
    virtual bool is_literal() const;

private:
    std::string m_var_name;
};
}

#endif

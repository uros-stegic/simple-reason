#ifndef QUANTIFIER_HPP
#define QUANTIFIER_HPP

#include <stdio.h>
#include <string>
#include <memory>
#include <unary_formula.hpp>
#include <term.hpp>

namespace art{
class Quantifier : public UnaryFormula {
public:
    Quantifier(const Formula&, const Term&);
    virtual Term var() const;
    virtual bool is_literal() const override;

private:
    Term m_term;
};
}

#endif //QUANTIFIER_HPP

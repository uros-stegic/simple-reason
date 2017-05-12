#ifndef FOR_ALL_HPP
#define FOR_ALL_HPP

#include <iostream>
#include <string>
#include <quantifier.hpp>

namespace AR{
class ForAll : public Quantifier {
public:
    using Quantifier::Quantifier;
    virtual FormulaType get_type() const;

protected:
    virtual void m_print_formula(std::ostream&) const;
    virtual bool evaluate(const Valuation&) const;
    virtual Formula substitute(const Formula&, const Formula&) const;

};
}

#endif
#ifndef EXISTS_HPP
#define EXISTS_HPP

#include <iostream>
#include <string>
#include <quantifier.hpp>

namespace art{
class Exists : public Quantifier {
public:
    using Quantifier::Quantifier;

    virtual FormulaType get_type() const;

protected:
    virtual void m_print_formula(std::ostream&) const override;
    virtual Formula substitute(const Formula&, const Formula&) const override;

};
}

#endif //EXISTS_HPP

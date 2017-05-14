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
    virtual void m_print_formula(std::ostream&) const override;
    virtual Formula substitute(const Formula&, const Formula&) const override;

};
}

#endif //FOR_ALL_HPP

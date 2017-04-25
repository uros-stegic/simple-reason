#ifndef ATOMIC_HPP
#define ATOMIC_HPP

#include <formula.hpp>

namespace AR {
class AtomicFormula : public BaseFormula {
public:
    virtual bool is_literal() const override;
    virtual int complexity() const override;
    virtual Formula substitute(const Formula&, const Formula&) const override;
};
}

#endif // ATOMIC_HPP


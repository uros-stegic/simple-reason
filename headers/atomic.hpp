#ifndef ATOMIC_HPP
#define ATOMIC_HPP

#include <definitions.hpp>
#include <formula.hpp>

namespace AR {
class AtomicFormula : public BaseFormula {
public:
    virtual int complexity() const;
    virtual Formula substitute(const Formula&, const Formula&) const;
    virtual Formula simplify() const;

protected:
    virtual Formula m_nnf() const;
    virtual Formula m_cnf() const;
};
}

#endif // ATOMIC_HPP


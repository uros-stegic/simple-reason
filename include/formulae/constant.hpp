#ifndef CONSTANT_HPP
#define CONSTANT_HPP

#include <atomic.hpp>

namespace AR {
class Constant : public AtomicFormula {
protected:
    bool operator <(const Formula&) const override;
    bool m_is_equal(const Formula&) const override;
};
}

#endif // CONSTANT_HPP


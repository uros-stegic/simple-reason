#ifndef CONSTANT_HPP
#define CONSTANT_HPP

#include <definitions.hpp>
#include <atomic.hpp>

namespace AR {
class Constant : public AtomicFormula {
protected:
    bool m_is_equal(const Formula&) const;
};
}

#endif // CONSTANT_HPP


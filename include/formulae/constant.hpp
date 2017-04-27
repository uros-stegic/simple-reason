#ifndef CONSTANT_HPP
#define CONSTANT_HPP

#include <atomic.hpp>

/**
 * This class alows us to have constants and provides exactly two comparison methods for
 * working with them.
 *
 *
 * QUESTIONS:
 * 1. Why do both methods return true?
 * 2. I see they will be overriden later, but I still haven't got that far. Will return here
 * when the time comes. Where are they overriden?
 */

namespace AR {
class Constant : public AtomicFormula {
protected:
    bool operator <(const Formula&) const override;
    bool m_is_equal(const Formula&) const override;
};
}

#endif // CONSTANT_HPP


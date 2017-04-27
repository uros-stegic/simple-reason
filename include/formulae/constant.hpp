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
 * 		Because this method wont get called unless the operands (of operator <) are of same type.
 * 		This is part of some extremly complicated logic that needs to be revisited. Don't pay attention
 * 		to operator<.
 * 2. I see they will be overriden later, but I still haven't got that far. Will return here
 * when the time comes. Where are they overriden?
 * 		Keyword `override` doesn't mean that they WILL be overriden, but that THIS is the overriding
 * 		of the previous declarations from above the class hierarchy.
 */

namespace AR {
class Constant : public AtomicFormula {
protected:
    bool operator <(const Formula&) const override;
    bool m_is_equal(const Formula&) const override;
};
}

#endif // CONSTANT_HPP


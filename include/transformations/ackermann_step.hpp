#ifndef ACKERMANN_STEP_HPP
#define ACKERMANN_STEP_HPP

#include <vector>
#include <string>

#include <transformation.hpp>
#include <formula.hpp>
#include <formulae.hpp>

namespace art{

class AckermannStep : public Transformation {
public:
    virtual Formula transform(const Formula&) const override;

private:
	std::vector<std::string> m_symbols;
};
}

#endif // ACKERMANN_STEP_HPP


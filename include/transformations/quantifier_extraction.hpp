#ifndef QUANTIFIER_EXTRACTION_HPP_HPP
#define QUANTIFIER_EXTRACTION_HPP_HPP

#include <transformation.hpp>
#include <formula.hpp>

namespace art{

class QuantifierExtraction : public Transformation {
public:
    virtual Formula transform(const Formula&) const;
};
}

#endif //QUANTIFIER_EXTRACTION_HPP_HPP

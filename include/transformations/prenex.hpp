#ifndef PRENEX_HPP
#define PRENEX_HPP

#include <transformation.hpp>
#include <formula.hpp>

namespace art{

class Prenex : public Transformation {
public:
    virtual Formula transform(const Formula&) const;
};
}

#endif //PRENEX_HPP

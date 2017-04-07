#ifndef VALUATION_H
#define VALUATION_H

#include <map>
#include <iostream>
#include <formula.hpp>

namespace AR {
class Valuation {
public:
    Valuation(const AtomSet& atoms);
    bool get_value(unsigned int n) const;
    void set_value(unsigned int n, bool value);
    void init(const AtomSet& atoms);
    bool next();
    void print_valuation() const;

private:
    std::map<unsigned int, bool> m_valuation;
};
}

#endif // VALUATION_H


#ifndef CNF_HPP
#define CNF_HPP

#include <vector>
#include <iostream>

#include <definitions.hpp>
#include <clause.hpp>

using namespace std;

namespace AR {
class CNF : public std::vector<Clause> {
    using vector::vector;

public:
    explicit operator Formula() const;
    CNF static get_cnf(const Formula&);
    CNF merge(const CNF&) const;
};
std::ostream& operator <<(std::ostream&, const CNF&);
std::istream& operator >>(std::istream& in, AR::CNF&);
}

#endif // CNF_HPP


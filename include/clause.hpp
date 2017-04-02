#ifndef CLAUSE_HPP
#define CLAUSE_HPP

#include <vector>
#include <iostream>

#include <definitions.hpp>

using namespace std;

namespace AR {
class Clause : public std::vector<Formula> {
public:
    using vector::vector;
    explicit operator Formula() const;
    Clause static get_clause(const Formula&);
    Clause merge(const Clause&) const;
};
std::ostream& operator <<(std::ostream&, const Clause&);
std::istream& operator >>(std::istream& in, AR::Clause&);
}

#endif // CLAUSE_HPP


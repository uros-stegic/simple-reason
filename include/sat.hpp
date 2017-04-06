#ifndef SAT_HPP
#define SAT_HPP

#include <string>
#include <memory>
#include <utility>

#include <definitions.hpp>
#include <formula.hpp>
#include <cnf.hpp>
#include <clause.hpp>

namespace AR {
class SAT {
public:
    SAT();
    SAT static from_dimacs(const std::string&);
    void to_dimacs(const std::string&) const;
    explicit operator Formula() const;
    unsigned int count_vars() const;

    void set_name(const std::string&);
    SAT& operator <<(const Clause&);

private:
    int m_num_clauses;
    std::string m_name;
    std::shared_ptr<CNF> m_cnf;
    AtomSet m_vars;

    friend std::ostream& operator <<(std::ostream&, const AR::SAT&);
    friend std::istream& operator >>(std::istream&, SAT&);
};
std::ostream& operator <<(std::ostream&, const AR::SAT&);
std::istream& operator >>(std::istream& in, AR::SAT&);
}

#endif // SAT_HPP


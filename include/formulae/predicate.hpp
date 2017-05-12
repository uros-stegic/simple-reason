#ifndef PREDICATE_HPP
#define PREDICATE_HPP

#include <iostream>
#include <vector>
#include <memory>
#include <string>
#include <term.hpp>
#include <atomic.hpp>

namespace AR{
class Predicate : public AtomicFormula{
public:
    Predicate(std::string, const std::vector<Term>&);
    void print_formula(std::ostream & out) const;
    virtual std::string name() const;
    virtual FormulaType get_type() const;

private:
    std::string m_name;
    std::vector<Term> m_terms;
};
}

#endif

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
    Predicate(const std::vector<Term> &, std::string);
    virtual std::string name() const;
    void print_formula(std::ostream & out) const override;
    virtual FormulaType get_type() const override;
    virtual bool operator <(const Formula&) const override;
    virtual bool m_is_equal(const Formula&) const override;

private:
    std::string m_name;
    std::vector<Term> m_terms;
};
}

#endif //PREDICATE_HPP

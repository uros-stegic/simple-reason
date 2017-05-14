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
    virtual std::string name() const;
    void print_formula(std::ostream & out) const override;
    virtual FormulaType get_type() const override;
//evaluate obrisati iz cele hijerarhije, operator<, m_is_equal
private:
    std::string m_name;
    std::vector<Term> m_terms;
};
}

#endif //PREDICATE_HPP

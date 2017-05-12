#ifndef LETTER_HPP
#define LETTER_HPP

#include <iostream>

#include <atomic.hpp>
#include <formula.hpp>
#include <valuation.hpp>

/**
 *
 *
 * QUESTIONS:
 * 1. Again, the namespace AR. // the reason this question is repeated here is because this is in
 *  formulae folder and not in semantics
 *  Not sure what the question is. As I see, I'll find it again in other classes.
 * 2.
 *
 * COMMENT: Not sure from where to begin with reading these files, so I am doing it quite randomly.
 *  Some of the answers to my questions will come as I get more into this code. The answers I consider
 * true will be provided after a right arrow "---> ", they should be checked twice! Fool me once shame
 * on you, fool me twice shame on me! :)
 *
 *
 */

namespace AR {
class Letter : public AtomicFormula {
public:
    Letter(unsigned int id);

    virtual FormulaType get_type() const override;
    virtual void print_formula(std::ostream&) const override;
    virtual bool evaluate(const Valuation&) const override;
    virtual bool operator <(const Formula&) const override;

    unsigned int get_id() const;

protected:
    bool m_is_equal(const Formula&) const override;
    void m_get_atoms(AtomSet&) const override;

private:
    unsigned int m_id;
};
}

#endif // LETTER_HPP


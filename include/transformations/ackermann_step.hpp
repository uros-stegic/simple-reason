#ifndef ACKERMANN_STEP_HPP
#define ACKERMANN_STEP_HPP

#include <map>
#include <set>
#include <utility>
#include <string>

#include <transformation.hpp>
#include <formula.hpp>
#include <formulae.hpp>

namespace art{
struct compare_pair {
	bool operator()(const std::pair<Term, Term>&, const std::pair<Term, Term>&) const;

private:
	TermCompare comparator;
};

class AckermannStep : public Transformation {
public:
	AckermannStep();
    virtual Formula transform(const Formula&) const override;

private:
	mutable int next;
	mutable std::map<Term, Term, TermCompare> m_symbols;

	Formula extract(const Formula&) const;
	Term extract(const Term&) const;
	
	Formula reduce() const;
	Formula make_cons(const std::set<std::pair<Term, Term>, compare_pair>&) const;

	Term next_free_var() const;

};
}

#endif // ACKERMANN_STEP_HPP


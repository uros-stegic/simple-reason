#ifndef VALUATION_H
#define VALUATION_H

#include <map>
#include <iostream>
#include <formula.hpp>

/**
 *This class creates an instance (object) in some valuation for the atoms we provide and provides
 * basic methods for manipulation of it, such as: set/get valuation, initialization of
 * valuation (given the atom set), making next valuation from the current one and also provides
 * print method.
 * Private map m_valuation consists of an unsigned int, which represents n-th letter in current
 * valuation, and a bool value, which represents the value of that letter's valuation (obviously,
 * 1 or 0, true or false).
 *
 * Setting valuation:
 *  void Valuation::set_value(unsigned int n, bool val);
 * With this method we set the value of n-th letter in valuation to some value val.
 *
 * Getting valuation:
 *  bool get_value(unsigned int n) const;
 * We go through an array of letters (letters are represented with an int) and we are searching for
 * the one we send as a parameter. If none is found, we say it doesen't exists. Otherwise, second
 * value in the map (bool, valuation) is returned.
 *
 * Initialization of valuation:
 *  void init(const AtomSet& atoms);
 * For the atoms given (letters) we are initializing new Valuation having all bool values of valuation
 * set to false.
 *
 * Getting the next valuation:
 *  bool Valuation::next();
   We iterate through m_valuation, from the end, finished is

   1 1 0 0 1 1 0

    auto it = m_valuation.rbegin();
    bool over = true;
    bool finished = true;
    for(;it != m_valuation.rend(); it++) {
        finished = finished && it->second;
        bool next_over = over && it->second;
        it->second = !(over == it->second);
        over = next_over;
    }
    return !finished;
}
 *
 *
 * QUESTIONS:
 * 1. Why namespace AR?
 * 2. Not sure about whether we are talking about a /\ b /\ c ---> a = 0 b = 1 c = 1 so the valuation
 * is 0, or we are talking about valuation for each letter alone? (ironically, I wrote whole explanation
 * in a way I thought it was)----> First one is the answer.
 * 3. Still not quite sure how next() here works. What is finished for?
 */

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


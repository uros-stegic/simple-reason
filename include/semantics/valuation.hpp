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
 * 1. Why namespace art?
 * 		Why namespace at all, or why art? It's good practice to use namespace for your project (also, logical parts of a
 * 		project can have (sub)namespaces of their on, i.e. art::syntax::And, art::semantics::Valuation) so that you
 * 		do not polute the global namespace with the names that you made up. This way, you only polute it with one
 * 		name - art. Why art - well, Automated Reasoning (the name of Maric's class :)). This should be refactored
 * 		at some time. First of all, usualy, namspaces are lowercased (like std, boost, ...) and second, why ar, when
 * 		this project is called simple-reason, which means namespace should be called sr.
 * 2. Not sure about whether we are talking about a /\ b /\ c ---> a = 0 b = 1 c = 1 so the valuation
 * is 0, or we are talking about valuation for each letter alone? (ironically, I wrote whole explanation
 * in a way I thought it was)----> First one is the answer.
 * 		Not sure what that second one means (each letter alone) but never mind, the first one is correct anyways. :)
 * 3. Still not quite sure how next() here works. What is finished for?
 * 		Consider valuation (p, q, r, s) -> (0, 1, 1, 0). It can be read as number 6 in binary. Method next increments
 * 		binary representation by one. over is carrige from previous position (1 + 1 = 0, and we carry 1), next_over is
 * 		what carrige will be in the next position, finished is true when we go from (1, 1, ..., 1) -> (0, 0, ..., 0).
 * 		Why does this method returns this information? This way, when someone keeps calling this method in a loop, 
 * 		he can know that he looped over all the valuation and can jump out of his loop.
 */

namespace art {
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


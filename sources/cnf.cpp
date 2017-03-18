#include <cnf.hpp>
#include <clause.hpp>
#include <true_constant.hpp>
#include <conjunction.hpp>

#include <iostream>
#include <memory>
#include <numeric>
#include <algorithm>

using namespace AR;

CNF::operator Formula() const
{
    if( size() == 0 ) {
        return std::make_shared<True>();
    }
    return std::accumulate(
        cbegin()+1,
        cend(),
        static_cast<Formula>(*cbegin()),
        [](Formula acc, Clause next) {
            return std::make_shared<And>(acc, static_cast<Formula>(next));
        }
    );
}

std::ostream& AR::operator <<(std::ostream& out, const CNF& f)
{
    for(auto &i : f) {
        out << i << endl;
    }
    return out;
}


std::istream& AR::operator >>(std::istream& in, CNF& cnf)
{
    Clause c;
    
    while( in >> c ) {
        cnf.push_back(c);
        c.clear();
    }

    return in;
}

CNF CNF::merge(const CNF& other) const
{
    CNF tmp;
    tmp.reserve(size() + other.size());
    std::merge(begin(), end(), other.begin(), other.end(), std::back_inserter(tmp));
    return tmp;
}
CNF CNF::get_cnf(const Formula& f)
{
    CNF result;
    switch( f->get_type() ) {
        case PROP_LETTER:
        case PROP_TRUE:
        case PROP_FALSE:
        case NEGATION:
        case DISJUNCTION: {
            result.push_back(Clause::get_clause(f));
            break;
        }
        case CONJUNCTION: {
            const And *l = static_cast<const And*>(f.get());
            CNF left =  CNF::get_cnf(l->get_left_operand());
            CNF right = CNF::get_cnf(l->get_right_operand());
            result = left.merge(right);
            break;
        }
        default: {}
    }
    return result;
}


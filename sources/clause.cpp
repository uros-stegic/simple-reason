#include <definitions.hpp>
#include <formula.hpp>
#include <clause.hpp>
#include <letter.hpp>
#include <negation.hpp>
#include <false_constant.hpp>
#include <disjunction.hpp>

#include <iostream>
#include <numeric>
#include <memory>
#include <algorithm>

using namespace AR;

Clause::operator Formula() const
{
    if( size() == 0 ) {
        return std::make_shared<False>();
    }
    return std::accumulate(
        cbegin()+1,
        cend(),
        *cbegin(),
        [](Formula acc, Formula next) {
            return std::make_shared<Or>(acc, next);
        }
    );
}

std::ostream& AR::operator <<(std::ostream& out, const Clause& c)
{
    for(auto &i : c) {
        switch(i->get_type()) {
            case PROP_LETTER:
                out << static_cast<const Var*>(i.get())->get_id();
                break;
            case NEGATION:
                out << "-" <<
                    static_cast<const Var*>(static_cast<const Not*>(i.get())->get_operand().get())->get_id();
                break;
            default:
                out << "?";
        }
        out << " ";
    }
    out << 0;
    return out;
}
std::istream& AR::operator >>(std::istream& in, Clause& c)
{
    int tmp;
    Formula f;

    while( (in >> tmp) && (tmp != 0) ) {
        if( tmp < 0 ) {
            f = std::make_shared<Not>(std::make_shared<Var>(-tmp));
        }
        else {
            f = std::make_shared<Var>(tmp);
        }
        c.push_back(f);
    }

    return in;
}

Clause Clause::merge(const Clause& other) const
{
    Clause tmp;
    tmp.reserve(size() + other.size());
    std::merge(begin(), end(), other.begin(), other.end(), std::back_inserter(tmp));
    return tmp;
}

Clause Clause::get_clause(const Formula& f)
{
    Clause result;
    switch( f->get_type() ) {
        case PROP_LETTER:
        case PROP_TRUE:
        case PROP_FALSE:
        case NEGATION: {
            result.push_back(f);
            break;
        }
        case DISJUNCTION: {
            const Or *l = static_cast<const Or*>(f.get());
            Clause left =  Clause::get_clause(l->get_left_operand());
            Clause right = Clause::get_clause(l->get_right_operand());
            result = left.merge(right);
            break;
        }
        default: {}
    }
    return result;
}






















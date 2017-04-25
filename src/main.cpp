#include <iostream>
#include <formulae.hpp>
#include <transformations.hpp>
#include <iterator>

using namespace AR;

struct cmp {
    bool operator()(const Formula& f, const Formula& g) const {
        return f < g;
    }
};

int main(int argc, char **argv) {
    Formula ct = std::make_shared<True>();
    Formula cf = std::make_shared<False>();

    Formula p = std::make_shared<Var>(1);
    Formula q = std::make_shared<Var>(2);
    Formula r = std::make_shared<Var>(3);
    Formula s = std::make_shared<Var>(4);
    
    Formula _p = std::make_shared<Not>(p);
    Formula _q = std::make_shared<Not>(q);
    Formula _r = std::make_shared<Not>(r);
    Formula _s = std::make_shared<Not>(s);

    /*
    Formula r1  = std::make_shared<If>(p,q);
    Formula r2  = std::make_shared<And>(_r,s);
    Formula r3  = std::make_shared<And>(p,_q);
    Formula r4  = std::make_shared<If>(r2,r1);

    Formula r5  = std::make_shared<Or>(r1,r2);
    Formula r6  = std::make_shared<Or>(r3,r);
    Formula r7  = std::make_shared<If>(s,r6);
    Formula r8  = std::make_shared<And>(r5,r7);
    Formula r9  = std::make_shared<If>(r8,r1);

    //(((p⇒q)∨(¬r∧s))∧(s⇒((p∧¬q)∨r))⇒(p⇒q))⇒((¬r∧s)⇒(p⇒q))
    Formula f = std::make_shared<If>(r9,r4);
    std::cout << f << std::endl;
    */

    Formula c1 = std::make_shared<Clause>(std::initializer_list<Formula>{_p, q, _s}); // (p2 | ~p1 | ~p4)
    Formula c2 = std::make_shared<Clause>(std::initializer_list<Formula>{p, _q, _s}); // (p1 | ~p2 | ~p4)
    Formula c3 = std::make_shared<Clause>(std::initializer_list<Formula>{r, _q, s});  // (p3 | p4 | ~p2)

    Formula cnf = std::make_shared<CNF>(std::initializer_list<Formula>{c1, c2, c3});
    std::cout << cnf << std::endl;
//    Formula cnf1 = static_cast<const CNF*>(cnf.get())->add_clause(c4);
//    std::cout << cnf1 << std::endl;

    return 0;
}


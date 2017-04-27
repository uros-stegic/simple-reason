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

    Formula pp = std::make_shared<Not>(r2);
    std::cout << pp << std::endl;

    Transformation *tr1 = new NegationDistribution();
    Transformation *rt2 = new Simplification();

    Formula res = pp->transform(*tr1);


    std::cout << res->transform(*rt2) << std::endl;

    delete tr1;
    delete rt2;

    return 0;
}


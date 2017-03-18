#include <iostream>
#include <formulae.hpp>

using namespace AR;

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

    Formula pq = std::make_shared<If>(p, q);
    Formula _r_q = std::make_shared<If>(_r, _s);

    Formula f1 = std::make_shared<Iff>(pq, _r_q);

    Formula ss = std::make_shared<And>(p, q);
    Formula f2 = std::make_shared<Iff>(r, ss);
    Formula f = std::make_shared<Not>(f2);

    Formula g = f->cnf();
    SAT instance(g);

    std::cout << f << std::endl;
    std::cout << g << std::endl;
    std::cout << instance << std::endl;
}


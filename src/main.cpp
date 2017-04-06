#include <iostream>
#include <formulae.hpp>
#include <transformations.hpp>

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

    Formula pq = std::make_shared<And>(q,r);
    Formula pOq = std::make_shared<Or>(q,r);
    Formula ptq = std::make_shared<If>(p,q);
    Formula peq = std::make_shared<Iff>(std::make_shared<Not>(ptq),pOq);

    Formula __p = std::make_shared<Not>(_p);


    Formula t1 = std::make_shared<Or>(pq, pOq);

    Transformation* neg_dist = new NaiveCNF();

    std::cout << peq << "\t--->  " << peq->transform(*neg_dist) << std::endl;
//              << t2 << "\t--->  " << t2->transform(*neg_dist) << std::endl
//              << t3 << "\t--->  " << t3->transform(*neg_dist) << std::endl
//              << t4 << "\t--->  " << t4->transform(*neg_dist) << std::endl;

    delete neg_dist;

    return 0;
}


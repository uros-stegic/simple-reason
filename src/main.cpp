#include <iostream>
#include <formulae.hpp>
#include <transformations.hpp>
#include <iterator>
#include <string>
#include <parser.tab.hpp>

#ifndef forever
#define forever while(true)
#endif

using namespace art;

extern FILE* yyin;
bool interactive = false;

void run_repl()
{
	interactive = true;
	forever {
		std::cout << "> ";
		yyparse();
	}
}
void parse_input_file(char* filename)
{
	interactive = false;
	yyin = fopen(filename, "r");
	if( !yyin ) {
		std::cerr	<< "Cannot open input file "
					<< "\"" << filename << "\""
					<< std::endl;
		std::exit(EXIT_FAILURE);
	}
	yyparse();
	fclose(yyin);
}

int main(int argc, char **argv) {
	/*
    Formula ct = std::make_shared<True>();
    Formula cf = std::make_shared<False>();

    Formula p = std::make_shared<Letter>(1);
    Formula q = std::make_shared<Letter>(2);
    Formula r = std::make_shared<Letter>(3);
    Formula s = std::make_shared<Letter>(4);
    
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


    //Formula oo = std::make_shared<ForAll>(p, "x");
    //std::cout << oo << std::endl;

    //Term pred = std::make_shared<Constant>("C");
    //std::cout << pred << std::endl;

    Term x = std::make_shared<Var>("x");
    std::cout << x << std::endl;

    Term y = std::make_shared<Var>("y");
    std::cout << y << std::endl;

    Term plusl = std::make_shared<Function>("+", std::vector<Term>{x,y});
    Term plusr = std::make_shared<Function>("+", std::vector<Term>{x,y});

    Formula eq = std::make_shared<Predicate>(std::vector<Term>{plusl, plusr}, "=");

    Formula fy = std::make_shared<ForAll>(eq, y);
    Formula fx = std::make_shared<ForAll>(fy, x);

    std::cout << fx << std::endl;
	*/

	if( argc == 1 ) {
		run_repl();
	}
	else {
		parse_input_file(argv[1]);
	}

    return 0;
}


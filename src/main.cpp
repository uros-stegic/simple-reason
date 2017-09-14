#include <iostream>
#include <formulae.hpp>
#include <transformations.hpp>
#include <iterator>
#include <string>
#include <formulae.hpp>
#include <parser.tab.hpp>

#ifndef forever
#define forever while(true)
#endif


extern art::Formula* formula;
extern FILE* yyin;
bool interactive = false;

void run_repl()
{
	interactive = true;
	forever {
		std::cout << "> ";
		int err = yyparse();
		if( !err && formula != nullptr ) {
            std::cout << *formula << std::endl;
            art::Transformation *t = new art::ConjunctionDistribution();
			auto res = (*formula)->transform(*t);
            std::cout << res << std::endl << std::endl;
            delete formula;
            delete t;
            formula = nullptr;
		}
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
	int err = yyparse();
	if( !err && formula != nullptr ) {
		std::cout << *formula << std::endl;
		delete formula;
		formula = nullptr;
	}
	fclose(yyin);
}

int main(int argc, char **argv) {
	if( argc == 1 ) {
		run_repl();
	}
	else {
		parse_input_file(argv[1]);
	}

    return 0;
}


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
	try {
		if( argc == 1 ) {
			run_repl();
		}
		else {
			parse_input_file(argv[1]);
		}
	} catch(std::runtime_error* err) {
		std::cerr << err->what() << std::endl;
	}

    return 0;
}


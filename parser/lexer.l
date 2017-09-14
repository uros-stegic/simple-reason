%option noyywrap
%option nounput

%{
#include <iostream>
#include <cstdlib>
#include <string>
#include <formulae.hpp>

#include <parser.tab.hpp>

void llerror(const std::string& token)
{
	std::cerr << "[ERROR]: Unrecognized token \"" << token << "\"" << std::endl;
}
%}

UNIVERSAL		"A"
EXISTANCE		"E"
EQUIVALENCE		"<=>"
IMPLICATION		"=>"
DISJUNCTION		"|"
CONJUNCTION		"&"
NEGATION		"~"
LOG_TRUE		"T"
LOG_FALSE		"F"

PREDICATE		[pqr][0-9]*
VARIABLE		[xyz][0-9]*
FUNCTION		[fgh][0-9]*
CONSTANT		c[0-9]*

EQUALS			"="
NOT_EQUALS		"=/="

EXIT			"exit"|"quit"
END_OF_EXPRESSION		"\n"
%%

{EXIT}			{ return EXIT_TOKEN;	}
{END_OF_EXPRESSION}		{ return END_OF_EXPRESSION;		}

{VARIABLE}		{ yylval.string = new std::string(yytext); return VAR_TOKEN;	}
{PREDICATE}		{ yylval.string = new std::string(yytext); return PRED_TOKEN;	}
{FUNCTION}		{ yylval.string = new std::string(yytext); return FUN_TOKEN;	}
{CONSTANT}		{ yylval.string = new std::string(yytext); return CONST_TOKEN;	}

{UNIVERSAL}		{ return UNIV_TOKEN;		}
{EXISTANCE}		{ return EXIST_TOKEN;		}
{EQUIVALENCE}	{ return EQUIV_TOKEN;		}
{IMPLICATION}	{ return IMPL_TOKEN;		}
{DISJUNCTION}	{ return DISJ_TOKEN;		}
{CONJUNCTION}	{ return CONJ_TOKEN;		}
{NEGATION}		{ return NEG_TOKEN;			}
{LOG_TRUE}		{ return LOG_CONST_T;		}
{LOG_FALSE}		{ return LOG_CONST_F;		}

{EQUALS}		{ return EQUALS_TOKEN;		}
{NOT_EQUALS}	{ return NOT_EQUALS_TOKEN;	}
[().,\n]		{ return *yytext; 			}

[ \t\r]+		{ /* DON'T DO ANYTHING IN CASE OF BLANKS */						}
.				{ llerror(std::string(yytext));									}

%%


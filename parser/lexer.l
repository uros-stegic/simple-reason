%option noyywrap
%option nounput

%{
#include <iostream>
#include <cstdlib>
#include <string>
#include <formulae.hpp>
#include <transformations.hpp>

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
CONSTANT		[abc1-9][0-9]*

EQUALS			"="
NOT_EQUALS		"=/="

IDENT			\$[a-zA-Z][a-zA-Z0-9]*
ASSIGN_TOKEN	":="
CNF_TOKEN		"cnf"|"CNF"
NNF_TOKEN		"nnf"|"NNF"
C_DISTR_TOKEN	"c_distr"|"C_DISTR"
D_DISTR_TOKEN	"d_distr"|"D_DISTR"
N_DISTR_TOKEN	"n_distr"|"N_DISTR"
SIMPLIFY_TOKEN	"simplify"|"SIMPLIFY"
NO_IMPS_TOKEN	"no_imps"|"NO_IMPS"
DELETE_TOKEN	"delete"|"DELETE"
QUANT_UP		"quant_up"|"QUANT_UP"
PRENEX_TOKEN	"prenex"|"PRENEX"
ACK_TOKEN		"ack"|"ACK"

EXIT			"exit"|"quit"
END_OF_EXPRESSION		"\n"
%%

{PRENEX_TOKEN}		{ return PRENEX_TOKEN; }
{QUANT_UP}			{ return QUANT_UP; }
{DELETE_TOKEN}		{ return DELETE_TOKEN; }
{CNF_TOKEN}			{ return CNF_TOKEN; }
{NNF_TOKEN}			{ return NNF_TOKEN; }
{NO_IMPS_TOKEN}		{ return NO_IMPS_TOKEN; }
{C_DISTR_TOKEN}		{ return C_DISTR_TOKEN; }
{D_DISTR_TOKEN}		{ return D_DISTR_TOKEN; }
{N_DISTR_TOKEN}		{ return N_DISTR_TOKEN; }
{SIMPLIFY_TOKEN}	{ return SIMPLIFY_TOKEN; }
{EXIT}				{ return EXIT_TOKEN;	}
{END_OF_EXPRESSION}	{ return END_OF_EXPRESSION;		}

{VARIABLE}		{ yylval.string = new std::string(yytext); return VAR_TOKEN;	}
{PREDICATE}		{ yylval.string = new std::string(yytext); return PRED_TOKEN;	}
{FUNCTION}		{ yylval.string = new std::string(yytext); return FUN_TOKEN;	}
{CONSTANT}		{ yylval.string = new std::string(yytext); return CONST_TOKEN;	}

{IDENT}			{ yylval.string = new std::string(yytext); return IDENT;		}

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
{ASSIGN_TOKEN}	{ return ASSIGN_TOKEN;		}
[().,\n]		{ return *yytext; 			}

[ \t\r]+		{ /* DON'T DO ANYTHING IN CASE OF BLANKS */						}
.				{ llerror(std::string(yytext));									}

%%


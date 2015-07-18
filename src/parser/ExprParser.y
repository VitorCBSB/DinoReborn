%{

#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <memory>
#include "ExprNodes.h"

extern int yylex();
typedef struct yy_buffer_state *YY_BUFFER_STATE;
extern void yy_delete_buffer(YY_BUFFER_STATE);
extern YY_BUFFER_STATE yy_scan_string(const char*);

void yyerror(std::unique_ptr<Expr>& root, const char* message) {
}

%}

%code requires {
	#include <memory>
	#include "ExprNodes.h"
}

%code provides {
	std::unique_ptr<Expr> parse_and_get_ast(const std::string& expression);
}

%union{
	double val;
	Expr* expr;
}

%token NUMERO
%token RAND_VAL
%token REPEAT_VAL
%token SIN_VAL
%token COS_VAL
%left '-' '+'
%left '*' '/'
%precedence NEG

%type <expr> exp
%type <val> NUMERO
%type <expr> expressao

%parse-param { std::unique_ptr<Expr>& root }

%start expressao

%%

expressao : exp                { $$ = $1; root = std::unique_ptr<Expr>($$); }
	  ;
exp:
     NUMERO                    { $$ = new Num($1);       }
| RAND_VAL                     { $$ = new Rand();        }
| REPEAT_VAL                   { $$ = new Repeat();      }
| SIN_VAL '(' exp ')'          { $$ = new Sin($3);       }
| COS_VAL '(' exp ')'          { $$ = new Cos($3);       }
| exp '+' exp                  { $$ = new Add($1, $3);   }
| exp '-' exp                  { $$ = new Sub($1, $3);   }
| exp '*' exp                  { $$ = new Mult($1, $3);  }
| exp '/' exp                  { $$ = new Div($1, $3);   }
| '-' exp  %prec NEG           { $$ = new Neg($2);       }
| '(' exp ')'                  { $$ = $2;                }
;

%%

std::unique_ptr<Expr> parse_and_get_ast(const std::string& expression) {
	std::unique_ptr<Expr> root_node;
	YY_BUFFER_STATE buffer = yy_scan_string(expression.c_str());
	if (yyparse(root_node) == 0) {
		yy_delete_buffer(buffer);
		return root_node;
	}
	yy_delete_buffer(buffer);
	fprintf(stderr, "Error while parsing expression %s.\n", expression.c_str());
	exit(1);
}


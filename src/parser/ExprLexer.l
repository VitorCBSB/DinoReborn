%{
#include "ExprParser.tab.h"
#include <stdlib.h>
#include <string.h>

%}

digit	[0-9]

%%

$rand						{return RAND_VAL;}
$repeat						{return REPEAT_VAL;}
$sin						{return SIN_VAL;}
$cos						{return COS_VAL;}

{digit}+(\.{digit}+)?				{sscanf(yytext, "%lf", &yylval.val); return (NUMERO);}
"+"						{return ('+');}
"-"						{return ('-');}
"*"						{return ('*');}
"/"						{return ('/');}
"("						{return ('(');}
")"						{return (')');}
[ \t\n]

%%


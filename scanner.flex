%{
    #include "token.h"
%}
DIGIT [0-9]
LETTER [a-zA-Z]
%%
(" "|\t|\n|\r) /* skip whitespace */
<<EOF>>         { return TOKEN_EOF; }
\/\/.*$                   { return TOKEN_CPP_COMMENT; }
\/\*.*?\*\/                 {return TOKEN_C_COMMENT; }
array           { return TOKEN_ARRAY; }
boolean         { return TOKEN_BOOLEAN; }
char            { return TOKEN_CHARACTER; }
float           { return TOKEN_FLOAT; }
integer         { return TOKEN_INTEGER; }
string          { return TOKEN_STRING; }
function        { return TOKEN_FUNCTION; }
void            { return TOKEN_VOID; }
auto            { return TOKEN_AUTO; }
else            { return TOKEN_ELSE; }
false           { return TOKEN_FALSE; }
for             { return TOKEN_FOR; }
if              { return TOKEN_IF; }
print           { return TOKEN_PRINT; }
return          { return TOKEN_RETURN; }
true            { return TOKEN_TRUE; }
while           { return TOKEN_WHILE; }
\(              { return TOKEN_L_PAREN; }
\)              { return TOKEN_R_PAREN; }
\{              { return TOKEN_L_BRACE; }
\}              { return TOKEN_R_BRACE; }
\[              { return TOKEN_L_BRACKET; }
\]              { return TOKEN_R_BRACKET; }
\+\+            { return TOKEN_POSTINC; }
\-\-            { return TOKEN_POSTDEC; }
\^              { return TOKEN_EXP; }
\*              { return TOKEN_MUL; }
\/              { return TOKEN_DIV; }
%               { return TOKEN_MOD; }
\+              { return TOKEN_ADD; }
\-              { return TOKEN_SUB; }
\<=             { return TOKEN_LE; }
>=              { return TOKEN_GE; }
==              { return TOKEN_EQUAL; }
!=              { return TOKEN_NEQUAL; }
\<              { return TOKEN_LESS; }
>               { return TOKEN_GREATER; }
&&              { return TOKEN_AND; }
\|\|            { return TOKEN_OR; }
=               { return TOKEN_ASSIGN; }
!               { return TOKEN_NOT; }

;               { return TOKEN_SEMICOLON; }
,               { return TOKEN_COMMA; }
:               { return TOKEN_COLON; }
\\              { return TOKEN_BACKSLASH; }


({LETTER}|_)({LETTER}|{DIGIT}|_){0,255} { return TOKEN_IDENTIFIER; }

\"(([^\"\\]|\\.)*)\"    { return TOKEN_STRING_LITERAL; }
\'[\\0-9a-zA-Z]{1,4}\' { return TOKEN_CHARACTER_LITERAL; } /* need post-processing */

[+-]?{DIGIT}*\.{DIGIT}+  { return TOKEN_FLOAT_LITERAL; }
{DIGIT}*\.?{DIGIT}[eE][-]?{DIGIT}+ { return TOKEN_FLOAT_LITERAL; } /* may match integer section, flex need match int first */

{DIGIT}+       { return TOKEN_INTEGER_LITERAL; }


.               { return TOKEN_ERROR; }


%%
int yywrap() {return 1;}
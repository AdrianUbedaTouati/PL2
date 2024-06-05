/*------------------------------ ejemplo.l -------------------------------*/
D       [0-9]
L       [a-zA-Z]
LD      [0-9a-zA-Z]
ID      {L}({LD})*
NUMENTERO   {D}+
NUMREAL     {D}+(\.){D}+
OPAS    "-"|"+"
OPMD    "/"|"*"
OPREL   "<"|">"|"=="|"!="|">="|"<="


%{
#include <string.h> 
#include <string>
#include <iostream>

using namespace std;

#include "comun.h"
#include "plp5.tab.h"

int ncol = 1,
    nlin = 1;

int findefichero = 0;

int ret(int token);  
// función que actualiza 'nlin' y 'ncol' y devuelve el token

void msgError(int nerror, int nlin,int ncol,const char *s);
// función para producir mensajes de error

void errorSemantico(int nerror,char *lexema,int fila,int columna);
// función para producir mensajes de semantico

%}

%x COMENTARIO

%%

" "                {ncol++;}
[\t]               {ncol++;}
[\n]               {nlin++;ncol=1;}
"/*"                    {ncol += strlen(yytext);BEGIN(COMENTARIO);}
"//"(.)*           {; /* comentarios de una linea, no hacer nada */}
<COMENTARIO>[^/*\n]+    {ncol += strlen(yytext);}
<COMENTARIO>\n          {nlin++;ncol=1;}
<COMENTARIO><<EOF>>     {msgError(ERRLEXEOF,-1,-1,"");}
<COMENTARIO>"*/"        {ncol+=strlen(yytext); BEGIN(INITIAL);}
<COMENTARIO>[*/]        {ncol += strlen(yytext);}

"main"            {return ret(tmain);}
"int"             {return ret(tint);}
"float"                {return ret(tfloat);}
"printf"                {return ret(tprintf);}
"scanf"                {return ret(tscanf);}
"if"                {return ret(tif);}
"else"                {return ret(telse);}
"while"                {return ret(twhile);}
"for"                {return ret(tfor);}

{ID}               {return ret(id);}
{NUMENTERO}        {return ret(nentero);}
{NUMREAL}          {return ret(nreal);}

","                {return ret(coma);}
";"                {return ret(pyc);}
"("                {return ret(pari);}
")"                {return ret(pard);}
{OPREL}            {return ret(oprel);}
{OPAS}             {return ret(opas);}
{OPMD}             {return ret(opmd);}
"="                {return ret(asig);}
"&"                {return ret(referencia);}
"["                {return ret(cori);}
"]"                {return ret(cord);}
"{"                {return ret(llavei);}
"}"                {return ret(llaved);}
"\"%d\"" | "\"%g\""      {return ret(formato);}
"++" | "--"              {return ret(incrdecr);}
.                  {msgError(ERRLEXICO,nlin,ncol,yytext);}

%%

int yywrap(void) {findefichero=1; return 1;} /* para no tener que linkar con la
                                libreria del lex */

int ret(int token)
{
   yylval.lexema=strdup(yytext);
   yylval.nlin=nlin;
   yylval.ncol=ncol;
   ncol+=(strlen(yytext));
   return(token);
}
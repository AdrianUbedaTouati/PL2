/*------------------------------ ejemplo.l -------------------------------*/
D       [0-9]
L       [a-zA-Z]
LD      [0-9a-zA-Z]
ID      {L}({LD})*
NUMENTERO   {D}+
NUMREAL     {D}+(\.){D}+
OPAS    "-"|"+"
OPMUL   "*"|"/"|"//"|"%"

%{
#include <string.h> 
#include <string>
#include <iostream>

using namespace std;

#include "comun.h"
#include "plp4.tab.h"

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
%{
/* codigo local */
%}

" "                {ncol++;}
[\t]               {ncol++;}
[\n]               {nlin++;ncol=1;}
"/*"                    {ncol += strlen(yytext);BEGIN(COMENTARIO);}
<COMENTARIO>[^/*\n]+    {ncol += strlen(yytext);}
<COMENTARIO>\n          {nlin++;ncol=1;}
<COMENTARIO><<EOF>>     {msgError(ERRLEXEOF,-1,-1,"");}
<COMENTARIO>"*/"        {ncol+=strlen(yytext); BEGIN(INITIAL);}
<COMENTARIO>[*/]        {ncol += strlen(yytext);}

"("                {return ret(pari);}
")"                {return ret(pard);}
";"                {return ret(pyc);}
","                {return ret(coma);}
":"                {return ret(dosp);}
"["                {return ret(cori);}
"]"                {return ret(cord);}
":="               {return ret(asig);}
".."               {return ret(ptopto);}
{OPAS}             {return ret(opas);}
{OPMUL}            {return ret(opmul);}
"funcion"          {return ret(funcion);}
"var"              {return ret(var);}
"fvar"             {return ret(fvar);}
"entero"           {return ret(entero);}
"real"             {return ret(real);}
"tabla"            {return ret(tabla);}
"de"               {return ret(de);}
"puntero"          {return ret(puntero);}
"blq"              {return ret(blq);}
"fblq"             {return ret(fblq);}
"escribe"          {return ret(escribe);}
{ID}               {return ret(id);}
{NUMENTERO}        {return ret(numentero);}
{NUMREAL}          {return ret(numreal);}
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

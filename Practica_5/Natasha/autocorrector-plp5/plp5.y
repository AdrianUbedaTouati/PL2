/*##########################################################
#                                                          #
#   Autor: Natallia Tsuranava                              #
#   PL 2022/23                                             #
#   Modificacion: ejemplo.y (ejemploHT)                    #
#                                                          #
##########################################################*/

//==========================================================
// COMPONENTES LEXICOS
//==========================================================
%token algoritmo falgoritmo
%token var fvar
%token entero real logico
%token tabla de
%token escribe lee
%token si entonces sino
%token mientras hacer repetir hasta
%token blq fblq
%token cierto falso
%token id nentero nreal
%token coma pyc dospto
%token pari pard
%token oprel opas opmd opasig 
%token cori cord
%token ybool obool nobool

%{

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>


using namespace std;

#include "comun.h"
#include "TablaSimbolos.h"
#include "TablaTipos.h"

//==========================================================
// variables y funciones del A. Léxico
//==========================================================
extern int ncol,nlin,findefichero;

extern int yylex();
extern char *yytext;
extern FILE *yyin;

int yyerror(char *s);

//==========================================================
// CONSTANTES
//==========================================================
int MAX_DIR_VAR = 15999;   // ultima dirección posible para variables 
int MAX_DIR_TEMP = 16383;  // ultima dirección posible para temporales

//==========================================================
// VARIABLES
//==========================================================
TablaSimbolos *tsActual = new TablaSimbolos(nullptr);
TablaTipos *ttipos = new TablaTipos();
int cvar = 0;        // contador de direcciones de variables
int ctemp = 16000;   // contador de direcciones temporales

//==========================================================
// FUNCIONES
//==========================================================
int nuevaTemp(void);
int nuevaVar(void);
bool esArray(int tipo);


%}

%%


S        : algoritmo dospto id SDec SInstr falgoritmo
         ;

SDec     : Dec
         | /* epsilon */
         ;

Dec      : var DVar MDVar fvar
         ;

DVar     : Tipo dospto id LId pyc
         ;

MDVar    : DVar MDVar
         | /* epsilon */
         ;

LId      : coma id LId
         | /* epsilon */
         ;

Tipo     : entero
         | real
         | logico
         | tabla nentero de Tipo
         ;

SInstr   : SInstr pyc Instr
         | Instr
         ;

Instr    : escribe Expr
         | lee Ref
         | si Expr entonces Instr
         | si Expr entonces Instr sino Instr
         | mientras Expr hacer Instr
         | repetir Instr hasta Expr
         | Ref opasig Expr
         | blq SDec SInstr fblq
         ;

Expr     : Expr obool Econj
         | Econj
         ;

Econj    : Econj ybool Ecomp
         | Ecomp
         ;

Ecomp    : Esimple oprel Esimple
         | Esimple
         ;

Esimple  : Esimple opas Term
         | Term
         | opas Term
         ;

Term     : Term opmd Factor
         | Factor
         ;

Factor   : Ref
         | nentero
         | nreal
         | pari Expr pard
         | nobool Factor
         | cierto
         | falso
         ;

Ref      : id                 {  Simbolo *simbolo = tsActual->searchSymb($1.lexema);
                              if (simbolo == nullptr) {
                                 errorSemantico(ERR_NODECL, $1.nlin, $1.ncol, $1.lexema);
                              }
                              if ((ctemp = nuevaTemp()) == -1) {
                                 errorSemantico(ERR_MAXTMP, $1.nlin, $1.ncol, $1.lexema);
                              }
                              $$.dir = ctemp;
                              $$.cod = "mov #0 " + to_string(ctemp) + "\n";
                              $$.tipo = simbolo->tipo;
                              $$.dbase = simbolo->dir;
                              
                              $$.lexema = $1.lexema;
                              $$.nlin = $1.nlin;
                              $$.ncol = $1.ncol;
                           }
         | Ref cori           {  // si Ref no es un array, no puede tener [
                              if (!esArray($1.tipo)) {
                                 errorSemantico(ERR_SOBRAN, 0, 0, "");
                              }

                           }
          Esimple cord
      ;

%%

void msgError(int nerror,int nlin,int ncol,const char *s)
{
   switch (nerror) {
      case ERRLEXICO: fprintf(stderr,"Error lexico (%d,%d): caracter '%s' incorrecto\n",nlin,ncol,s);
         break;
      case ERRSINT: fprintf(stderr,"Error sintactico (%d,%d): en '%s'\n",nlin,ncol,s);
         break;
      case ERREOF: fprintf(stderr,"Error sintactico: fin de fichero inesperado\n");
         break;
     }

   exit(1);
}

void errorSemantico(int nerror,int nlin,int ncol,const char *s)
{
	fprintf(stderr,"Error semantico (%d,%d): ", nlin,ncol);
   switch(nerror) {
      case ERR_YADECL: fprintf(stderr,"variable '%s' ya declarada\n",s);
         break;
      case ERR_NODECL: fprintf(stderr,"variable '%s' no declarada\n",s);
         break;
      case ERR_DIM: fprintf(stderr,"la dimension debe ser mayor que cero\n");
         break;
      case ERR_FALTAN: fprintf(stderr,"faltan indices\n");
         break;
      case ERR_SOBRAN: fprintf(stderr,"sobran indices\n");
         break;
      case ERR_INDICE_ENTERO: fprintf(stderr,"la expresion entre corchetes debe ser de tipo entero\n");
         break;
      case ERR_EXP_LOG: fprintf(stderr,"la expresion debe ser de tipo logico\n");
         break;
      case ERR_EXDER_LOG: fprintf(stderr,"la expresion a la derecha de '%s' debe ser de tipo logico\n",s);
         break;
      case ERR_EXDER_ENT: fprintf(stderr,"la expresion a la derecha de '%s' debe ser de tipo entero\n",s);
         break;
      case ERR_EXDER_RE:fprintf(stderr,"la expresion a la derecha de '%s' debe ser de tipo real o entero\n",s);
         break;        
      case ERR_EXIZQ_LOG:fprintf(stderr,"la expresion a la izquierda de '%s' debe ser de tipo logico\n",s);
         break;       
      case ERR_EXIZQ_RE:fprintf(stderr,"la expresion a la izquierda de '%s' debe ser de tipo real o entero\n",s);
         break;       
      case ERR_NOCABE:fprintf(stderr,"la variable '%s' ya no cabe en memoria\n",s);
         break;
      case ERR_MAXTMP:fprintf(stderr,"no hay espacio para variables temporales\n");
         break;
   }
   exit(-1);
}

int yyerror(char *s)
{
    if (findefichero) 
    {
       msgError(ERREOF,0,0,"");
    }
    else
    {  
       msgError(ERRSINT,nlin,ncol-strlen(yytext),yytext);
    }
    exit(1);
}

int nuevaTemp(void) {
   if (ctemp > MAX_DIR_TEMP) {
      return -1;
   }
   return ++ctemp;
}

int nuevaVar(void) {
   if (cvar > MAX_DIR_VAR) {
      return -1;
   }
   return ++cvar;
}

bool esArray(int tipo) {
   return (ttipos->tipos)[tipo].clase == ARRAY;
}

int main(int argc,char *argv[])
{
    FILE *fent;

    if (argc==2)
    {
        fent = fopen(argv[1],"rt");
        if (fent)
        {
            yyin = fent;
            yyparse();
            fclose(fent);
        }
        else
            fprintf(stderr,"No puedo abrir el fichero\n");
    }
    else
        fprintf(stderr,"Uso: ejemplo <nombre de fichero>\n");
}

/*------------------------------ plp5.y -------------------------------*/
// Tokens
//==========================================================
%token tmain tint tfloat tprintf tif telse twhile tfor
%token id nentero nreal
%token coma
%token pyc
%token pari
%token pard
%token oprel
%token opas
%token opmd
%token asig
%token referencia
%token cori
%token cord
%token llavei
%token llaved
%token formato
%token incrdecr

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

// variables y funciones del A. Léxico
extern int ncol,nlin,findefichero;

extern int yylex();
extern char *yytext;
extern FILE *yyin;

int yyerror(char *s);

//Direciones
int LIM_DIR_VAR = 15999;   // ultima dirección posible para variables
int LIM_DIR_TEMP = 16383;  // ultima dirección posible para temporales

//varibles
TablaSimbolos *tablaSimbolos = new TablaSimbolos(nullptr);
TablaTipos *ttipos = new TablaTipos();
unsigned int numvar = 0;        // contador de direcciones de variables
unsigned int numtemp = 16000;   // contador de direcciones temporales
unsigned int numetq = 0;       // contador de etiquetas


//funciones
unsigned int nVar(char *lexema, int nlin, int ncol);
unsigned int nTemp(int nlin, int ncol);
unsigned int nuevaEtiqueta(void);
bool esArray(int tipo);

string operador, s1, s2;  // string auxiliares

%}

%%

S    : FVM  {/* comprobar que después del programa no hay ningún token más */
                int tk = yylex();
                if (tk != 0) yyerror("");
                else{
                    cout << $1.cod.c_str() ;
                }
          }
      ;

FVM   : DVar FVM  {
                    $$.cod = $1.cod + $2.cod;
                 }
     | tint tmain pari pard Bloque  {$$.cod = "";}
     ;

Tipo   : tint   {$$.cod = $1.lexema;}
       | tfloat {$$.cod = $1.lexema;}
       ;

Bloque : llavei BDecl SeqInstr llaved   {$$.cod = "";}
       ;

BDecl  : BDecl DVar {$$.cod = "";}
       | /* epsilon */   {$$.cod = "";}
       ;

DVar  : Tipo LIdent pyc {$$.cod = "";}
      ;

LIdent : LIdent coma Variable {$$.cod = "";}
       |  Variable {$$.cod = "";}
       ;

Variable : id V {$$.cod = "";}
         ;

V :  {$$.cod = "";}
  | cori nentero cord V {$$.cod = "";}
  ;





SeqInstr : SeqInstr Instr {$$.cod = "";}
         | /* epsilon */   {$$.cod = "";}
         ;

Instr : pyc {$$.cod = "";}
         | Bloque {$$.cod = "";}
         | Ref asig Expr pyc {$$.cod = "";}
         | printf pari formato coma Expr pard pyc {$$.cod = "";}
         | scanf pari formato coma referencia Ref pard pyc {$$.cod = "";}
         | tif pari Expr pard Instr {$$.cod = "";}
         | tif pari Expr pard Instr else Instr {$$.cod = "";}
         | while pari Expr pard Instr {$$.cod = "";}
         | tfor pari id asig Esimple pyc Expr pyc id incrdecr pard Instr {$$.cod = "";}
         ;




Expr : Expr oprel Esimple {$$.cod = "";}
     | Esimple {$$.cod = "";}
     ;

Esimple : Esimple opas Term {$$.cod = "";}
     | Term {$$.cod = "";}
     ;

Term : Term opmd Factor {$$.cod = "";}
     | Factor {$$.cod = "";}
     ;

Factor : Ref {$$.cod = "";}
     | nentero {$$.cod = "";}
     | nreal {$$.cod = "";}
     | pari Expr pard {$$.cod = "";}
     ;

Ref : id {$$.cod = "";}
     | Ref cori Esimple cord {$$.cod = "";}
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
         case ERRLEXEOF: fprintf(stderr,"Error lexico: fin de fichero inesperado\n");
            break;
     }
        
     exit(1);
}

void errorSemantico(int nerror,char *lexema,int fila,int columna)
{
    fprintf(stderr,"Error semantico (%d,%d): en '%s', ",fila,columna,lexema);
    switch (nerror) {
             case ERRYADECL: fprintf(stderr,"simbolo ya declarado\n");
               break;
             case ERRNODECL: fprintf(stderr,"identificador no declarado\n");
               break;
             case ERRDIM: fprintf(stderr,"la dimension debe ser mayor que cero\n");
               break;
             case ERRFALTAN: fprintf(stderr,"faltan indices\n");
               break;
             case ERRSOBRAN: fprintf(stderr,"sobran indices\n");
               break;
             case ERR_NOENTERO: fprintf(stderr,"debe ser de tipo entero\n");
               break;

             case ERR_NOCABE:fprintf(stderr,"la variable ya no cabe en memoria\n");
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
}

unsigned int nTemp(int nlin, int ncol) {
   if (ctemp == MAX_DIR_TEMP) {
      errorSemantico(ERR_MAXTMP, nlin, ncol, "");
   }
   ++ctemp
   return ctemp;
}

unsigned int nVar(char *lexema, int nlin, int ncol) {
   if (cvar == MAX_DIR_VAR) {
      errorSemantico(ERR_NOCABE, nlin, ncol, lexema);
   }
   ++cvar
   return cvar;
}

unsigned int nEtiqueta(void) {
   ++cetiq
   return cetiq;
}

bool esArray(int tipo) {
   if(ARRAY == (ttipos->tipos)[tipo].clase){
     return true;
   }else{
     return false;
   }
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

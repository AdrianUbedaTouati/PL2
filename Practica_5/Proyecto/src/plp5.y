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
unsigned int nuevaTemp(int nlin, int ncol);
unsigned int nuevaVar(char *lexema, int nlin, int ncol);
unsigned int nuevaEtiqueta(void);
bool esArray(int tipo);

string operador, s1, s2;  // string auxiliares

%}

%%

X    : S  {/* comprobar que después del programa no hay ningún token más */
                int tk = yylex();
                if (tk != 0) yyerror("");
                else{
                    cout << $1.cod.c_str() ;
                }
          }
      ;

FVM   : DVar FVM  {
                    $$.cod = $4.cod + "\n\nfloat " + $2.lexema + "()" + $6.cod;
                 }
     | tint tmain pari pard Bloque/*epsilon*/       {$$.cod = "";}
     ;

Tipo   : int   {$$.cod = "";}
       | float {$$.cod = "";}
       ;

Bloque : llavei BDecl SeqInstr llaved   {$$.cod = "";}
       ;

BDecl  : BDecl DVar {$$.cod = "";}
       |  {$$.cod = "";}
       ;

DVar  : Tipo LIdent pyc {$$.cod = "";}
      |  {$$.cod = "";}
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
         |  {$$.cod = "";}
         ;

Instr : pyc {$$.cod = "";}
         | Bloque {$$.cod = "";}
         | Ref asig Expr pyc {$$.cod = "";}
         | printf pari formato coma Expr pard pyc {$$.cod = "";}
         | scanf pari formato coma referencia Ref pard pyc {$$.cod = "";}
         | if pari Expr pard Instr {$$.cod = "";}
         | if pari Expr pard Instr else Instr {$$.cod = "";}
         | while pari Expr pard Instr {$$.cod = "";}
         | for pari id asig Esimple pyc Expr pyc id incrdecr pard Instr {$$.cod = "";}
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
      case ERRYADECL: fprintf(stderr,"ya existe en este ambito\n");
         break;
      case ERRNOMFUNC: fprintf(stderr,"no puede llamarse igual que la funcion");
         break;
      case ERRNOSIMPLE: fprintf(stderr,"debe ser de tipo entero o real\n");
         break;
      case ERRNODECL: fprintf(stderr,"no ha sido declarado\n");
         break;
      case ERRTIPOS: fprintf(stderr,"tipos incompatibles entero/real\n");
         break;
      case ERRNOENTEROIZQ: fprintf(stderr,"el operando izquierdo debe ser entero\n");
         break;
      case ERRNOENTERODER: fprintf(stderr,"el operando derecho debe ser entero\n");
         break;
      case ERRRANGO: fprintf(stderr,"rango incorrecto\n");
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

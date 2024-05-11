/*------------------------------ plp4.y -------------------------------*/
// Tokens
//==========================================================
%token funcion id pyc
%token var fvar
%token dosp
%token tabla cori cord de
%token coma
%token numentero ptopto
%token puntero
%token entero
%token real
%token blq fblq
%token asig
%token escribe pari pard
%token opas
%token opmul
%token numreal

%{

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>


using namespace std;

#include "comun.h"
#include "TablaSimbolos.h"

// variables y funciones del A. Léxico
extern int ncol,nlin,findefichero;

extern int yylex();
extern char *yytext;
extern FILE *yyin;

int yyerror(char *s);

//varibles
TablaSimbolos *tablaSimbolos = new TablaSimbolos(nullptr);

//funciones
unsigned int nuevaVar(char *lexema, int nlin, int ncol);

const int ENTERO=1;
const int REAL=2;

string operador, s1, s2;  // string auxiliares

%}

%%

X    : S  {/* comprobar que después del programa no hay ningún token más */
                int tk = yylex();
                if (tk != 0) yyerror("");
                else{
                    cout << $1 ;
                }
          }

S    : funcion id pyc S {$$.cod = $2.lexema} B  { /* comprobar que después del programa no hay ningún token más */
                           	                       $$.cod = $4.cod + "float" + $2.lexema + "()" + $6.cod;
                                                }
     | /*epsilon*/       {$$.cod = "";}
     ;


D : var L fvar     { $$.cod = $2.cod; }
     ;


L       : L V        { $$.cod = $1.cod + $2.cod;}
        | V         /* $$ = $1 */
        ;

L       : V        { $$.cod = $1.cod }
        ;

V : id dosp {$$.cod = $1.lexema} C pyc
                            {
                                if (strcmp(cadena1, cadena2) == 0){
                                    errorSemantico(ERRYADECL,$1.lexema,$1.nlin,$1.ncol);
                                }
                                if (tablaSimbolos->buscarAmbito($1.lexema) != nullptr){
                                    errorSemantico(ERRNOMFUNC,$1.lexema,$1.nlin,$1.ncol);
                                }
                                string idTrad = tablaSimbolos->crearVariable($1.lexema);

                                Simbolo *simbolo = new Simbolo();
                                simbolo->nombre = $4.lexema;
                                simbolo->tipo = $4.tipo;
                                simbolo->nombretrad = idTrad;

                                tablaSimbolos->nuevoSimbolo(*simbolo);

                                $$.cod = $4.cod + ";" + "\n";
                             }
     ;

C : A {$$.cod = $0.lexema + $1.lexema} C
                            {
                                $$.tipo = TABLA;
                                $$.cod = $2.cod;
                            }
     | P
         {
            if($$.tipo == PUNTERO){
                $$.tipo = PUNTERO;
            }else if($$.tipo == ENTERO){
                $$.tipo = ENTERO;
            }else if($$.tipo == REAL){
                $$.tipo = REAL;
            }
            $$.cod = p + " " + $0.cod;
         }
     ;

A : tabla cori R cord de     { $$.cod = $3.cod; }
     ;

R : R coma G     { $$.cod = $1.cod + $3.cod; }
     | G         { $$.cod = $1.cod; }
     ;

G : numentero ptopto numentero     {
                                        int num1,num2;
                                        num1 = atoi($1.lexema);

                                        if($$.tipo == NUMENTERO){
                                            num2 = atoi($3.lexema);
                                        }else num2 = 0 //no se si esta bien

                                        if(num2<num1){
                                            errorSemantico(ERRRANGO,$3.lexema,$3.nlin,$3.ncol);
                                        }

                                        $$.cod = "["+(num2-num1+1)+"]";
                                    }
     ;

P : puntero de P     { $$.cod = $3.cod + "*"; }
     | Tipo               { $$.cod = $1.cod; }
     ;

Tipo : entero    { $$.cod = $1.lexema; }
     | real               { $$.cod = $1.lexema; }
     ;

B : blq {$$.cod = $0.cod } D {$$.cod = $0.cod } SI fblq     {
                                                                tablaSimbolos = new TablaSimbolos(tablaSimbolos);
                                                                $$.cod =  "\n{\n" + $3.cod + $5.cod + "\n}";
                                                            }
     ;

SI : {$$.cod = $0.cod } SI pyc {$$.cod = $0.cod }  I     { $$.cod = $2.cod + $5.cod}
     | {$$.cod = $0.cod } I               { $$.cod = $2.cod; }
     ;

I : id asig E                {
                                Simbolo *simbolo = tablaSimbolos->buscar($1.lexema);
                                if(!(strcmp($1.cod, $0.cod) == 0)){
                                    if(simbolo == nullptr){
                                        errorSemantico(ERRNODECL,$1.lexema,$1.nlin,$1.ncol);
                                    } else if(simbolo.tipo != ENTERO && simbolo.tipo != REAL){
                                        errorSemantico(ERRNOSIMPLE,$1.lexema,$1.nlin,$1.ncol);
                                    }
                                }

                                if(strcmp($1.cod, $0.cod) == 0)
                                {
                                    if(REAL == $3.tipo)
                                    {
                                        $$.cod = "\n  return " + $3.cod + ";";
                                     } else
                                     {
                                        $$.cod = "\n  return itor(" + $3.cod + ");"
                                     }
                                } else
                                {
                                    if(simbolo.tipo == $3.tipo)
                                    {
                                        $$.cod = "\n  "+simbolo.nomtrad + " = " + $3.cod+";";
                                    } if(simbolo.tipo == REAL && $3.tipo == ENTERO)
                                    {
                                        $$.cod = "\n  "+simbolo.nomtrad + " = " + "itor("+$3.cod+")"+";";
                                    } else if (simbolo.tipo == ENTERO && $3.tipo == REAL)
                                    {
                                        errorSemantico(ERRTIPOS,$1.lexema,$1.nlin,$1.ncol);
                                    }
                                }


                             }
     | escribe pari E pard               {
                                            if(REAL == $3.tipo)
                                            {
                                                $$.cod = "\n  "+"printf("+"\"%f\","+ $3.cod +")"+";";
                                            } else
                                            {
                                                $$.cod = "\n  "+"printf("+"\"%d\","+ $3.cod +")"+";";
                                            }
                                         }
     | {$$.cod = $0.lexema} B             {
                                                $$.cod = $2.cod;
                                          }
     ;

E : E opas T     { $$.cod = $3.cod; }  //estara mal seguramnte
     | T               {
                            $$.cod = $1.cod;
                            $$.tipo = $1.tipo;
                        }
     ;

T : T opmul F     {
                        if(strcmp($2.cod, "//") == 0 || strcmp($2.cod, "%") == 0){
                            if ($0.tipo == REAL){
                                errorSemantico(ERRNOENTEROIZQ,$2.lexema,$2.nlin,$2.ncol);
                            }

                            if ($3.tipo == REAL){
                                errorSemantico(ERRNOENTERODER,$2.lexema,$2.nlin,$2.ncol);
                             }
                        }

                        if ($0.TIPO




                   }
     | F               {
                           $$.cod = $1.cod;
                           $$.tipo = $1.tipo;
                        }
     ;

F : numentero    { $$.tipo = ENTERO;
                   $$.cod = $1.lexema;
                  }
     | numreal    { $$.tipo = REAL;
                    $$.cod = $1.lexema;
                  }
     | id         { $$.tipo = tablaSimbolos->buscar($1.lexema).tipo;
                    $$.cod = tablaSimbolos->buscar($1.lexema).trad;
                   }
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

unsigned int nuevaVar(char *lexema, int nlin, int ncol) {
   if (cvar == MAX_DIR_VAR) {
      errorSemantico(ERR_NOCABE, nlin, ncol, lexema);
   }
   return ++cvar;
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

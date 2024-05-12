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

S    : funcion id pyc S {$$.cod = $2.lexema;} B  {
                                                    $$.cod = $4.cod + "\n\nfloat " + $2.lexema + "()" + $6.cod;
                                                }
     | /*epsilon*/       {$$.cod = "";}
     ;


D : var { $$.cod = $0.cod;} L fvar { $$.cod = $3.cod; }
     ;


L       : L { $$.cod = $0.cod;} V     { $$.cod = $1.cod + $3.cod;}
        | { $$.cod = $0.cod;} V       { $$.cod = $2.cod; }
        ;


V : id {
                if (strcmp($1.lexema, $0.cod.c_str()) == 0){
                    errorSemantico(ERRNOMFUNC,$1.lexema,$1.nlin,$1.ncol);
                }
                if (tablaSimbolos->buscarAmbito($1.lexema) != nullptr){
                    errorSemantico(ERRYADECL,$1.lexema,$1.nlin,$1.ncol);
                }
      } dosp  {
        $$.cod = $1.lexema;
      } C pyc
              {
                  string idTrad = tablaSimbolos->crearVariable($1.lexema,false);

                  Simbolo *simbolo = new Simbolo();
                  simbolo->nombre = $1.lexema;
                  simbolo->tipo = $5.tipo;
                  simbolo->nomtrad = idTrad;

                  tablaSimbolos->nuevoSimbolo(*simbolo);

                  $$.cod = $5.cod + ";" + "\n";
              }
     ;

C : A {$$.cod = $0.cod + $1.cod;} C
                            {
                                $$.tipo = TABLA;
                                $$.cod = $3.cod;
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
            string idTrad = tablaSimbolos->crearVariable($0.cod,false);
            $$.cod = $1.cod + " " + idTrad;
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
                                        num2 = atoi($3.lexema);

                                        if(num2<num1){
                                            errorSemantico(ERRRANGO,$3.lexema,$3.nlin,$3.ncol);
                                        }

                                        $$.cod = "["+to_string((num2-num1+1))+"]";
                                    }
     ;

P : puntero de P     {
                        $$.tipo = PUNTERO;
                        $$.cod = $3.cod + "*";
                     }
     | Tipo          {
                        $$.tipo = $1.tipo;
                        $$.cod = $1.cod;
                     }
     ;

Tipo : entero    {
                    $$.cod = "int";
                    $$.tipo = ENTERO;
                  }
     | real       {
                    $$.tipo = REAL;
                    $$.cod = "float";
                   }
     ;

B :     {
            tablaSimbolos = new TablaSimbolos(tablaSimbolos);
        }
        blq {
            $$.cod = $0.cod;
        } D {
        $$.cod = $0.cod;
        } SI fblq {
            tablaSimbolos->getAmbitoAnterior();
            $$.cod =  "\n{\n" + $4.cod + $6.cod + "\n}";
        }
     ;

SI : SI pyc {
                $$.cod = $0.cod;
             } I {
                    $$.cod = $1.cod + $4.cod;
                 }
     | {
            $$.cod = $0.cod;
        } I {
            $$.cod = $2.cod;
        }
     ;

I : id asig {
                 Simbolo *simbolo = tablaSimbolos->buscar($1.lexema);
                 if(!(strcmp($1.lexema, $0.cod.c_str()) == 0))
                 {
                    if(simbolo == nullptr)
                    {
                        errorSemantico(ERRNODECL,$1.lexema,$1.nlin,$1.ncol);
                    } else if(simbolo->tipo != ENTERO && simbolo->tipo != REAL)
                    {
                     errorSemantico(ERRNOSIMPLE,$1.lexema,$1.nlin,$1.ncol);
                    }
                  }
              } E {

                if(strcmp($1.lexema, $0.cod.c_str()) == 0)
                {
                    if(REAL == $4.tipo)
                    {
                        $$.cod = "\n  return " + $4.cod + ";";
                    } else
                    {
                        $$.cod = "\n  return itor(" + $4.cod + ");";
                    }
                } else
                {
                    Simbolo *simbolo = tablaSimbolos->buscar($1.lexema);
                    if(simbolo->tipo == $4.tipo)
                    {
                        $$.cod = "\n  "+simbolo->nomtrad + " = " + $4.cod+";";
                    } if(simbolo->tipo == REAL && $4.tipo == ENTERO)
                    {
                        $$.cod = "\n  "+simbolo->nomtrad + " = " + "itor("+$4.cod+")"+";";
                    } else if (simbolo->tipo == ENTERO && $4.tipo == REAL)
                    {
                       errorSemantico(ERRTIPOS,$2.lexema,$2.nlin,$2.ncol);
                    }
                }
           }
     | escribe pari E pard  {
                                if(REAL == $3.tipo)
                                {
                                    $$.cod = "\n  printf(\"%f\","+ $3.cod +");";
                                } else
                                {
                                   $$.cod = "\n  printf(\"%d\","+ $3.cod +");";
                                }
                             }
     | {$$.cod = $0.cod;} B {
                              $$.cod = $2.cod;
                           }
     ;

E : E opas T   {
                    if($1.tipo == REAL && $3.tipo == REAL)
                    {
                        $$.cod = $1.cod +" " + $2.lexema + "r " + $3.cod;
                        $$.tipo  = REAL;
                    } else if ($1.tipo == REAL && $3.tipo == ENTERO)
                    {
                       $$.cod = $1.cod + " " +$2.lexema + "r " + "itor(" + $3.cod +")";
                       $$.tipo  = REAL;
                    } else if ($1.tipo == ENTERO && $3.tipo == REAL)
                    {
                       $$.cod = "itor(" + $1.cod + ") " + $2.lexema + "r " + $3.cod;
                       $$.tipo  = REAL;
                    } else{
                       $$.cod = $1.cod +" " + $2.lexema + "i " + $3.cod;
                       $$.tipo  = ENTERO;
                    }
               }
     | T  {
             $$.cod = $1.cod;
             $$.tipo = $1.tipo;
          }
     ;

T : T opmul
            {
                if(strcmp($2.lexema, "//") == 0 || strcmp($2.lexema, "%") == 0)
                {
                    if($1.tipo == REAL){
                        errorSemantico(ERRNOENTEROIZQ, $2.lexema,$2.nlin, $2.ncol);
                    }
                }
             } F {
                    if(strcmp($2.lexema, "//") == 0 || strcmp($2.lexema, "%") == 0)
                    {
                        if($4.tipo == REAL)
                        {
                           errorSemantico(ERRNOENTERODER, $2.lexema, $2.nlin, $2.ncol);
                         }
                    }

                    if($1.tipo == REAL && $4.tipo == REAL){
                        $$.tipo = REAL;
                        $$.cod =  $1.cod + " " + $2.lexema + "r " + $4.cod;
                    } else if($1.tipo == REAL && $4.tipo == ENTERO)
                    {
                        $$.cod = $1.cod + " " +$2.lexema + "r " + "itor(" + $4.cod + ")";
                        $$.tipo = REAL;
                    }else if ($1.tipo == ENTERO && $4.tipo == REAL) {
                        $$.cod = "itor(" + $1.cod + ")" +" " + $2.lexema + "r " + $4.cod;
                        $$.tipo = REAL;
                     } else{
                        if(strcmp("%", $2.lexema) == 0)
                        {
                             $$.cod = $1.cod+" " + $2.lexema +" " + $4.cod;
                             $$.tipo = ENTERO;
                        }else if(strcmp("//", $2.lexema) == 0)
                        {
                             $$.cod = $1.cod +" " + "/i " + $4.cod;
                             $$.tipo = ENTERO;
                        }
                        else if(strcmp("/", $2.lexema) == 0)
                        {
                             $$.cod = "itor("+$1.cod+")" +" " + $2.lexema + "r " +"itor("+ $4.cod + ")";
                             $$.tipo = REAL;
                         }
                         else{
                             $$.cod = $1.cod +" " + $2.lexema + "i " + $4.cod;
                             $$.tipo = ENTERO;
                         }
                      }
                }
     | F
     {
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
     | id         {
                    Simbolo *simbolo = tablaSimbolos->buscar($1.lexema);

                    if (simbolo == nullptr){
                       errorSemantico(ERRNODECL, $1.lexema, $1.nlin, $1.ncol);
                    }else if(simbolo->tipo !=  ENTERO && simbolo->tipo != REAL) {
                       errorSemantico(ERRNOSIMPLE, $1.lexema, $1.nlin, $1.ncol);
                    }

                    $$.cod = simbolo->nomtrad;
                    $$.tipo = simbolo->tipo;
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

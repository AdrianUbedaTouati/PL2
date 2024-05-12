/*------------------------------ plp4.y -------------------------------*/
%token pari pard 
%token cori cord
%token coma dosp pyc
%token asig
%token ptopto
%token opas opmul
%token funcion
%token var fvar
%token entero real tabla de puntero
%token blq fblq
%token escribe
%token id numentero numreal


%{

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>


using namespace std;

#include "comun.h"
#include "TablaSimbolos.h"


// ####################################
// variables y funciones del A. Léxico
// ####################################
extern int ncol,nlin,findefichero;


extern int yylex();
extern char *yytext;
extern FILE *yyin;


int yyerror(char *s);

// #############################
//     constantes
// #############################


// #############################
//     variables
// #############################
TablaSimbolos *tsa = new TablaSimbolos(nullptr);
Simbolo *simb;

int anidamiento = 0;
int auxAnidamiento;
string operador, s1, s2;  // string auxiliares

%}

%%

X     : S   { /* comprobar que después del programa no hay ningún token más */
                              int tk = yylex();
                              if (tk == 0){
                                    s1 = $1.cod;
                                    cout << s1; 
                                 
                              }
                              else{ 
                                    yyerror("");
                              }
            }

S     : funcion id  pyc  S { $$.cod = $2.lexema;}
                        B    {      
                                    $$.cod = $4.cod + "float " + $2.lexema + "()" + $6.cod;
                              }
	
      | /* epsilon */          {$$.cod = "";}
      ;


D     : var { $$.cod = $0.cod;} L fvar  { $$.cod = $3.cod; }
      ;


L     : L { $$.cod = $0.cod;} V    { $$.cod = $1.cod + $3.cod; }

      | { $$.cod = $0.cod;} V     { $$.cod = $2.cod; }
      ;

V     : id { 
                  if($1.lexema == $0.cod){ 
                        errorSemantico(ERRNOMFUNC, $1.nlin, $1.ncol, $1.lexema); 
                  }
                  s1 = $1.lexema;
                  Simbolo *simbolo = tsa->buscarAmbito(s1);
                  if(simbolo != nullptr){
                        errorSemantico(ERRYADECL, $1.nlin, $1.ncol, $1.lexema);
                  }

           } dosp { $$.cod = $1.lexema;} C pyc {  
                  s1 = "";
                  auxAnidamiento = 0;
                  while(auxAnidamiento < anidamiento-1){
                        s1 += "_";
                        auxAnidamiento++;
                  }
                  Simbolo *simbolo = new Simbolo();
                  simbolo->nombre = $1.lexema;
                  simbolo->tipo = $5.tipo;
                  simbolo->nomtrad = s1 + $1.lexema;
                  tsa->nuevoSimbolo(*simbolo);

                  $$.cod = $5.cod + ";\n";
           }
      ;


C     : A { $$.cod = $0.cod + $1.cod;} C  { 
                                              $$.cod = $3.cod;  
                                              $$.tipo = TABLA;
                                          }

      | P   { 
                  if($1.tipo == PUNTERO){
                        $$.tipo = PUNTERO;
                  }
                  else if($1.tipo == ENTERO){
                        $$.tipo = ENTERO;
                  }
                  else if($1.tipo == REAL){
                        $$.tipo = REAL;
                  }
                  s1 = "";
                  auxAnidamiento = 0;
                  while(auxAnidamiento < anidamiento-1){
                        s1 += "_";
                        auxAnidamiento++;
                  }
                  $$.cod = $1.cod + " " + s1 + $0.cod;
      }
      ;


A     : tabla cori R cord de    { $$.cod = $3.cod; }
      ;

R     : R coma G   { $$.cod = $1.cod + $3.cod; }

      | G      { $$.cod = $1.cod; }
      ;

G     : numentero ptopto numentero  {
                        if(stoi($1.lexema) > stoi($3.lexema)){
                              errorSemantico(ERRRANGO, $3.nlin, $3.ncol, $3.lexema);
                        }
                        $$.cod = "[" + to_string(stoi($3.lexema) - stoi($1.lexema) + 1) + "]";
      }
      ;


P     : puntero de P    { $$.cod = $3.cod + "*";
                          $$.tipo = PUNTERO;    
                        }

      | Tipo      { $$.cod = $1.cod;
                    $$.tipo = $1.tipo; }
      ;


Tipo  : entero    { $$.cod = "int";
                    $$.tipo = ENTERO; }

      | real      { $$.cod = "float";
                    $$.tipo = REAL; }
      ;


B     : blq {   
                  tsa = new TablaSimbolos(tsa);
                  anidamiento++;
                  $$.cod = $0.cod;
            } 
            D { $$.cod = $0.cod;;} SI fblq {    
                                                tsa = tsa->getAmbitoAnterior();
                                                anidamiento--;
                                                $$.cod = "\n{\n" + $3.cod + $5.cod + "}\n";
                                                
            }
      ;


SI    : SI pyc { $$.cod = $0.cod;} I    { $$.cod = $1.cod + $4.cod;}

      | { $$.cod = $0.cod;} I      { $$.cod = $2.cod; }
      ;

      


I     : id asig {     
                        Simbolo *simbolo = tsa->buscar($1.lexema);
                        if( simbolo == nullptr){
                              if( strcmp($0.cod.c_str(), $1.lexema) != 0){
                                    errorSemantico(ERRNODECL, $1.nlin, $1.ncol, $1.lexema);
                              }
                              
                        }else{
                              if( simbolo->tipo != REAL && simbolo->tipo != ENTERO){
                                    errorSemantico(ERRNOSIMPLE, $1.nlin, $1.ncol, $1.lexema);
                              }
                              
                        }

      } E{ 
            if( strcmp($0.cod.c_str(), $1.lexema) == 0){
                  if($4.tipo == REAL){
                        $$.cod = "return " + $4.cod + ";\n";
                  }
                  else if($4.tipo == ENTERO){
                        $$.cod = "return itor(" + $4.cod + ");\n";
                  }
            }
            else{
                  Simbolo *simbolo = tsa->buscar($1.lexema);
                  if((simbolo->tipo == ENTERO && $4.tipo == ENTERO) ||
                     (simbolo->tipo == REAL && $4.tipo == REAL))
                  {     
                        $$.cod = simbolo->nomtrad + " = " + $4.cod + ";\n";
                  }
                  else if(simbolo->tipo == REAL && $4.tipo == ENTERO)
                  {
                        $$.cod = simbolo->nomtrad + " = itor(" + $4.cod + ");\n";
                  }
                  else if(simbolo->tipo == ENTERO && $4.tipo == REAL)
                  {
                        errorSemantico(ERRTIPOS, $2.nlin, $2.ncol, $2.lexema);
                  }
            }
      
            
      }

      | escribe pari E pard   { 
                                    if($3.tipo == REAL){
                                          $$.cod = "printf(\"%f\"," + $3.cod  + ");\n";
                                    } 
                                    else if($3.tipo == ENTERO){
                                          $$.cod = "printf(\"%d\"," + $3.cod + ");\n";
                                    } 
      }

      | { $$.cod = $0.cod;} B { $$.cod = $2.cod;}
      ;


E     : E opas T    { 
                        s1 = $2.lexema;
                        if($1.tipo == ENTERO && $3.tipo == ENTERO)
                        {
                              $$.tipo = ENTERO;
                              $$.cod = $1.cod + " " + s1 + "i "+ $3.cod;
                        
                        }else if($1.tipo == REAL && $3.tipo == ENTERO)
                        {   
                              $$.tipo = REAL;
                              $$.cod = $1.cod + " " + s1 + "r itor(" + $3.cod + ")";
                        }else if($1.tipo == ENTERO && $3.tipo == REAL)
                        {
                              $$.tipo = REAL;
                              $$.cod = "itor(" + $1.cod + ") " + s1 + "r " + $3.cod;
                        }else if($1.tipo == REAL && $3.tipo == REAL)
                        {
                              $$.tipo = REAL;
                              $$.cod =  $1.cod + " " + s1 + "r " + $3.cod;                              
                        }
                        s1 = "";
}

      | T   {$$.cod = $1.cod;
             $$.tipo = $1.tipo; }
      ;


T     : T opmul   {           s1 = $2.lexema;
                              if(strcmp(s1.c_str(), "/") == 0){
                                    s1 = "/r";
                              }
                              else if(strcmp(s1.c_str(), "//") == 0){
                                    s1 = "/i";
                              }

                              if(strcmp(s1.c_str(), "%") == 0 || strcmp(s1.c_str(), "/i") == 0){
                                    if($1.tipo != ENTERO){
                                          errorSemantico(ERRNOENTEROIZQ, $2.nlin, $2.ncol, $2.lexema);
                                    }
                              }                                        
                  } F {     
                        

                        if(strcmp(s1.c_str(), "%") == 0 || strcmp(s1.c_str(), "/i") == 0){
                              if($4.tipo != ENTERO){
                                    errorSemantico(ERRNOENTERODER, $2.nlin, $2.ncol, $2.lexema);
                              }
                        }

                        if($1.tipo == ENTERO && $4.tipo == ENTERO)
                        {
                              if(strcmp(s1.c_str(), "%") == 0 || strcmp(s1.c_str(), "/i") == 0){
                                    $$.tipo = ENTERO;
                                    $$.cod = $1.cod + " " + s1 + " " + $4.cod;
                              }
                              else if(strcmp(s1.c_str(), "/r") == 0){
                                    $$.tipo = REAL;
                                    $$.cod = "itor(" + $1.cod + ") " + s1 + " itor(" + $4.cod + ")";
                              }
                              else{
                                    $$.tipo = ENTERO;
                                    $$.cod = $1.cod + " " + s1 + "i "+ $4.cod;
                              }
                        
                        }
                        else if($1.tipo == REAL && $4.tipo == ENTERO)
                        {   
                              $$.tipo = REAL;
                              if(strcmp(s1.c_str(), "/r")==0){
                                    $$.cod =  $1.cod + " " + s1 + " itor(" + $4.cod + ")";
                              }
                              else{
                                    $$.cod = $1.cod + " " + s1 + "r itor(" + $4.cod + ")";
                              }
                        }
                        else if($1.tipo == ENTERO && $4.tipo == REAL)
                        {
                              $$.tipo = REAL;
                              if(strcmp(s1.c_str(), "/r")==0){
                                    $$.cod = "itor(" + $1.cod + ") " + s1 + " " + $4.cod;
                              }
                              else{
                                    $$.cod = "itor(" + $1.cod + ") " + s1 + "r " + $4.cod;
                              }
                        }
                        else if($1.tipo == REAL && $4.tipo == REAL)
                        {
                              $$.tipo = REAL;
                              if(strcmp(s1.c_str(), "/r")==0){
                                    $$.cod =  $1.cod + " " + s1 + " " + $4.cod;
                              }
                              else{
                                    $$.cod =  $1.cod + " " + s1 + "r " + $4.cod;
                              }
                              
                        }
                        s1 = "";
            
      }

      | F   {$$.cod = $1.cod;
             $$.tipo = $1.tipo;}
      ;


F     : numentero {$$.tipo = ENTERO;
                   $$.cod = $1.lexema;}

      | numreal   {$$.tipo = REAL;
                   $$.cod = $1.lexema;}

      | id  {     
                  Simbolo *simbolo = tsa->buscar($1.lexema);
                  if(simbolo == nullptr){
                        errorSemantico(ERRNODECL, $1.nlin, $1.ncol, $1.lexema);
                  }
                  if(simbolo->tipo == TABLA || simbolo->tipo == PUNTERO){
                        errorSemantico(ERRNOSIMPLE, $1.nlin, $1.ncol, $1.lexema);
                  }
                  $$.tipo = simbolo->tipo;
                  $$.cod = simbolo->nomtrad;


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
        
     exit(-1);
}

void errorSemantico(int nerror,int fila,int columna, char *lexema)
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
    exit(1);
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

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
int LIM_DIR_TEMP = 16383;
int LIM_DIR_VAR = 15999;


//varibles objeto
TablaTipos *tablaTipos = new TablaTipos();
TablaSimbolos *tablaSimbolos = new TablaSimbolos(nullptr);


//variables
unsigned int numtemp = 16000;
unsigned int numetq = 0;
unsigned int numvar = 0;



//funciones
unsigned int nVar(char *lexema, int nlin, int ncol);
unsigned int nTemp(int nlin, int ncol);
unsigned int nuevaEtiqueta(void);

bool isArray(int tipo);

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

Expr : Expr oprel Esimple {
                                if($3.tipo != REAL && $3.tipo != ENTERO){
                                     errorSemantico(ERR_EXIZQ_RE, $2.nlin, $2.ncol, $2.lexema);
                                } else if($1.tipo != REAL && $1.tipo != ENTERO){
                                     errorSemantico(ERR_EXDER_RE, $2.nlin, $2.ncol, $2.lexema);
                                } else {
                                    $$.dir = nTemp($3.nlin, $3.ncol);
                                    $$.cod = $1.cod + $3.cod;
                                    $$.tipo = LOGICO;

                                     string op = "";
                                     if ($2.lexema ==  ">") {
                                        op = "gtr";
                                     } else if ($2.lexema == "<") {
                                        op = "lss";
                                     } else if ($2.lexema ==  "<>") {
                                        op = "neq";
                                     } else if ($2.lexema ==  "=") {
                                        op = "eql";
                                     } else if ($2.lexema ==  "<=") {
                                        op = "leq";
                                     } else {
                                        op = "geq";
                                     }

                                    if ($1.tipo == $3.tipo && $1.tipo == ENTERO) {  // ENTERO && ENTERO, REAL && REAL
                                       string tip =  "i";

                                       string dir1 = to_string($1.dir);
                                       string dir3 = to_string($3.dir);

                                       $$.cod += "mov " + dir1 + " A" + "\n";
                                       $$.cod += op + tip + dir3 + "\n";
                                    } else if ($1.tipo == $3.tipo && $1.tipo == REAL) {  // ENTERO && ENTERO, REAL && REAL
                                          string ri =  "r";

                                          string dir1 = to_string($1.dir);
                                          string dir3 = to_string($3.dir);

                                          $$.cod += "mov " + dir1 + " A" + "\n";
                                          $$.cod += op + tip + dir3 + "\n";
                                     }else if ($1.tipo == REAL && $3.tipo == ENTERO) {
                                       string dir3 = to_string($3.dir);
                                       $$.cod += "mov " + dir3 + " A" + "\n";

                                       $$.cod += "itor\n";

                                       string stemp = to_string(numtemp);

                                       $$.cod += "mov A " + stemp + "\n";

                                       string dir1 = to_string($1.dir);

                                       $$.cod += "mov " + dir1 + " A" + "\n";

                                       string stemp = to_string(numtemp);

                                       $$.cod += op + "r " + stemp + "\n";

                                    } else if ($1.tipo == ENTERO && $3.tipo == REAL) {
                                       string dir1 = to_string($1.dir);

                                       $$.cod += "mov " + dir1 + " A" + "\n";

                                       $$.cod += "itor\n";

                                       string dir3 = to_string($3.dir);

                                       $$.cod += op + "r " + dir3 + "\n";
                                    }
                                    string stemp = to_string(numtemp)

                                    $$.cod += "mov A " + stemp + "\n";
                                }
                           }
     | Esimple {$$.dir = $1.dir;
                $$.tipo = $1.tipo;
                $$.cod = $1.cod;}
     ;

Esimple : Esimple opas Term {
                         if($3.tipo != REAL && $3.tipo != ENTERO){
                              errorSemantico(ERR_EXIZQ_RE, $2.nlin, $2.ncol, $2.lexema);
                         } else if($1.tipo != REAL && $1.tipo != ENTERO){
                              errorSemantico(ERR_EXDER_RE, $2.nlin, $2.ncol, $2.lexema);
                         } else {
                             $$.dir = nTemp($3.nlin, $3.ncol);
                             $$.cod = $1.cod + $3.cod;

                             if ($1.tipo == ENTERO && $3.tipo == ENTERO){
                                $$.tipo = ENTERO;
                             } else {
                                $$.tipo = REAL;
                             }

                             if ("+" == $2.lexema){
                                string op = "add";
                             } else {
                                string op = "sub";
                             }

                             if ($1.tipo == $3.tipo && $1.tipo == ENTERO) {  // ENTERO && ENTERO, REAL && REAL
                                string tip =  "i";

                                string dir1 = to_string($1.dir);
                                string dir3 = to_string($3.dir);

                                $$.cod += "mov " + dir1 + " A" + "\n";
                                $$.cod += op + tip + dir3 + "\n";
                             } else if ($1.tipo == $3.tipo && $1.tipo == REAL) {  // ENTERO && ENTERO, REAL && REAL
                                   string ri =  "r";

                                   string dir1 = to_string($1.dir);
                                   string dir3 = to_string($3.dir);

                                   $$.cod += "mov " + dir1 + " A" + "\n";
                                   $$.cod += op + tip + dir3 + "\n";
                              }else if ($1.tipo == REAL && $3.tipo == ENTERO) {
                                string dir3 = to_string($3.dir);
                                $$.cod += "mov " + dir3 + " A" + "\n";

                                $$.cod += "itor\n";

                                string stemp = to_string(numtemp);

                                $$.cod += "mov A " + stemp + "\n";

                                string dir1 = to_string($1.dir);

                                $$.cod += "mov " + dir1 + " A" + "\n";

                                string stemp = to_string(numtemp);

                                $$.cod += op + "r " + stemp + "\n";

                             } else if ($1.tipo == ENTERO && $3.tipo == REAL) {
                                string dir1 = to_string($1.dir);

                                $$.cod += "mov " + dir1 + " A" + "\n";

                                $$.cod += "itor\n";

                                string dir3 = to_string($3.dir);

                                $$.cod += op + "r " + dir3 + "\n";
                             }
                             string stemp = to_string(numtemp)

                             $$.cod += "mov A " + stemp + "\n";
                         }
                    }
     | Term { $$.dir = $1.dir;
              $$.tipo = $1.tipo;
              $$.cod = $1.cod;}
     ;

Term : Term opmd Factor {
                             if($3.tipo != REAL && $3.tipo != ENTERO){
                                  errorSemantico(ERR_EXIZQ_RE, $2.nlin, $2.ncol, $2.lexema);
                             } else if($1.tipo != REAL && $1.tipo != ENTERO){
                                  errorSemantico(ERR_EXDER_RE, $2.nlin, $2.ncol, $2.lexema);
                             } else {
                                 $$.dir = nTemp($3.nlin, $3.ncol);
                                 $$.cod = $1.cod + $3.cod;

                                 if ($1.tipo == ENTERO && $3.tipo == ENTERO){
                                    $$.tipo = ENTERO;
                                 } else {
                                    $$.tipo = REAL;
                                 }

                                 if ("*" == $2.lexema){
                                    string op = "mul";
                                 } else {
                                    string op = "div";
                                 }

                                 if ($1.tipo == $3.tipo && $1.tipo == ENTERO) {  // ENTERO && ENTERO, REAL && REAL
                                    string tip =  "i";

                                    string dir1 = to_string($1.dir);
                                    string dir3 = to_string($3.dir);

                                    $$.cod += "mov " + dir1 + " A" + "\n";
                                    $$.cod += op + tip + dir3 + "\n";
                                 } else if ($1.tipo == $3.tipo && $1.tipo == REAL) {  // ENTERO && ENTERO, REAL && REAL
                                       string ri =  "r";

                                       string dir1 = to_string($1.dir);
                                       string dir3 = to_string($3.dir);

                                       $$.cod += "mov " + dir1 + " A" + "\n";
                                       $$.cod += op + tip + dir3 + "\n";
                                  }else if ($1.tipo == REAL && $3.tipo == ENTERO) {
                                    string dir3 = to_string($3.dir);
                                    $$.cod += "mov " + dir3 + " A" + "\n";

                                    $$.cod += "itor\n";

                                    string stemp = to_string(numtemp);

                                    $$.cod += "mov A " + stemp + "\n";

                                    string dir1 = to_string($1.dir);

                                    $$.cod += "mov " + dir1 + " A" + "\n";

                                    string stemp = to_string(numtemp);

                                    $$.cod += op + "r " + stemp + "\n";

                                 } else if ($1.tipo == ENTERO && $3.tipo == REAL) {
                                    string dir1 = to_string($1.dir);

                                    $$.cod += "mov " + dir1 + " A" + "\n";

                                    $$.cod += "itor\n";

                                    string dir3 = to_string($3.dir);

                                    $$.cod += op + "r " + dir3 + "\n";
                                 }
                                 string stemp = to_string(numtemp)

                                 $$.cod += "mov A " + stemp + "\n";
                             }
                        }
     | Factor {
                $$.dir = $1.dir;
                $$.tipo = $1.tipo;
                $$.cod = $1.cod;
              }
     ;

Factor : Ref {
                 if ((tablaTipos->tipos)[$1.tipo].clase != ARRAY) {
                      $$.cod = $1.cod;
                      $$.dir = nTemp($1.nlin, $1.ncol);
                      $$.tipo = $1.tipo;

                      String dir1 = to_string($1.dir);
                      String sdbase = to_string($1.dbase);
                      String stemp = to_string(numtemp);

                      $$.cod += "mov " + dir1 + " A\n";
                      $$.cod += "addi #" + sdbase + "\n";
                      $$.cod += "mov @A " + stemp + "\n";

                 } else {
                    errorSemantico(ERR_FALTAN, $1.nlin, $1.ncol, $1.lexema);
                 }
             }
     | nentero {
                     numTemp = nTemp($1.nlin, $1.ncol);
                     $$.dir = numTemp;

                     String stemp = " " + to_string(numTemp);
                     $$.cod = "mov #" + $1.lexema + stemp + "\n";

                     $$.tipo = ENTERO;
               }
     | nreal {
                     numTemp = nTemp($1.nlin, $1.ncol);
                     $$.dir = numTemp;

                     String stemp = " " + to_string(numTemp);
                     $$.cod = "mov $" + $1.lexema + stemp + "\n";

                     $$.tipo = REAL
             }
     | pari Expr pard {
                          $$.dir = $2.dir;
                          $$.tipo = $2.tipo;
                          $$.cod = $2.cod;
                      }
     ;

Ref : id {
            Simbolo *simb = tablaActual->searchSymb($1.lexema);
            if (simb != nullptr) {
              numtemp = nTemp($1.nlin, $1.ncol);

              String stemp = to_string(temp);

              $$.cod = "mov #0 " + stemp + "\n";
              $$.tipo = simb->tipo;

              $$.dir = numtemp;
              $$.dbase = simb->dir;

              $$.nlin = $1.nlin;
              $$.ncol = $1.ncol;
              $$.lexema = $1.lexema;

             } else {
                errorSemantico(ERR_NODECL, $1.nlin, $1.ncol, $1.lexema);
             }
         }
     | Ref cori {
                    if (!isArray($1.tipo)) {
                        if($1.lexema != "]") {
                           errorSemantico(ERR_SOBRAN, $1.nlin, $1.ncol, $1.lexema);
                        } else {
                           errorSemantico(ERR_SOBRAN, $2.nlin, $2.ncol, $2.lexema);
                        }
                     }
                }
     Esimple cord {
                     if ($4.tipo == ENTERO) {
                         $$.tipo = (tablaTipos->tipos)[$1.tipo].tipoBase;
                         $$.dbase = $1.dbase;

                         numtemp = nTemp($2.nlin, $2.ncol);

                         $$.dir = numtemp;

                         $$.cod = $1.cod + $4.cod;

                         String dir1 = to_string($1.dir);
                         String tam1 = to_string((tablaTipos->tipos)[$1.tipo].tamanyo);
                         String dir4 = to_string($4.dir);
                         String stemp = to_string(numtemp);

                         $$.cod += "mov " + dir1 + " A" + "\n";
                         $$.cod += "muli #" + tam1 + "\n";
                         $$.cod += "addi " + dir4 + "\n";
                         $$.cod += "mov A " +stemp + "\n";

                         $$.nlin = $5.nlin;
                         $$.ncol = $5.ncol;
                         $$.lexema = $5.lexema;

                     } else {
                        errorSemantico(ERR_INDICE_ENTERO, $4.nlin, $4.ncol, $4.lexema);
                     }
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
   if (ctemp == LIM_DIR_TEMP) {
      errorSemantico(ERR_MAXTMP, nlin, ncol, "");
   }
   ++ctemp
   return ctemp;
}

unsigned int nVar(char *lexema, int nlin, int ncol) {
   if (cvar == LIM_DIR_VAR) {
      errorSemantico(ERR_NOCABE, nlin, ncol, lexema);
   }
   ++cvar
   return cvar;
}

unsigned int nEtiqueta(void) {
   ++cetiq
   return cetiq;
}

bool isArray(int tipo) {
   if(ARRAY == (tablaTipos->tipos)[tipo].clase){
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

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
%token tscanf

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
unsigned int nEtiqueta(void);

bool isArray(int tipo);

%}

%%

S    : FVM  {/* comprobar que después del programa no hay ningún token más */
                int tk = yylex();
                if (tk != 0) yyerror("");
                else{
                    cout << $1.cod.c_str() << "halt\n";
                }
             }
     ;

FVM   : DVar FVM  {
                    $$.cod = $1.cod + $2.cod;
                  }
     | tint tmain pari pard Bloque  {$$.cod = $5.cod;}
     ;

Tipo   : tint   {$$.cod = ENTERO;}
       | tfloat {$$.cod = REAL;}
       ;

Bloque : llavei { tablaSimbolos = new TablaSimbolos(tablaSimbolos); }
         BDecl SeqInstr { tablaSimbolos = tablaSimbolos->getAmbitoAnterior(); } llaved
         {
            $$.cod = $3.cod + $4.cod;
         }
       ;

BDecl  : BDecl DVar {$$.cod = "";}
       | /* epsilon */   {$$.cod = "";}
       ;

DVar  : Tipo {$$.tipo = $0.tipo;} LIdent pyc {$$.cod = "";}
      ;

LIdent : LIdent coma {$$.tipo = $0.tipo;} Variable {$$.cod = "";}
       | {$$.tipo = $0.tipo;} Variable {$$.cod = "";}
       ;

Variable : id {
                   if (tablaSimbolos->buscarAmbito($1.lexema)!=nullptr) {
                     errorSemantico(ERRYADECL, $1.lexema,$1.nlin, $1.ncol);
                   }
                   $$.tipo = $0.tipo;
               }
           V {
                Simbolo *simbolo = new Simbolo();
                simbolo->dir = nVar($1.lexema, $1.nlin, $1.ncol);
                simbolo->nombre = $1.lexema;
                simbolo->tam = $3.tam;
                simbolo->tipo = $3.tipo;

                if (numvar + simbolo->tam >= LIM_DIR_VAR) {
                    errorSemantico(ERR_NOCABE,$1.lexema, $1.nlin, $1.ncol);
                }
                numvar += simbolo->tam;
                tablaSimbolos->nuevoSimbolo(*simbolo);
             }
         ;

V :  {$$.tipo = $0.tipo; $$.tam = $0.tam;}
  | cori nentero cord {$$.tam = 1; $$.tipo = $0.tipo;}
  V {
      if(stoi($2.lexema) > 0){
        $$.tipo = tablaTipos->nuevoTipoArray(stoi($2.lexema),$5.tipo);
        $$.tam = $5.tam * stoi($2.lexema);
      } else {
        errorSemantico(ERRDIM,$2.lexema, $2.nlin, $2.ncol);
      }
  }
  ;


SeqInstr : SeqInstr {$$.nlin = numtemp;} Instr {$$.cod = $1.cod + $3.cod;
                                                numtemp = $2.nlin;}
         | /* epsilon */   {$$.cod = "";}
         ;

Instr :   pyc {$$.cod = "";}
         | Bloque {$$.cod = $1.cod;}
         | Ref asig Expr pyc {
                                 if ((tablaTipos->tipos)[$1.tipo].clase == ARRAY) {
                                    errorSemantico(ERRFALTAN,$1.lexema, $1.nlin, $1.ncol);
                                 }else{
                                    $$.cod = $1.cod + $3.cod;
                                 }

                                 if ($3.tipo == ENTERO && $1.tipo == REAL) {
                                    string dir3 = to_string($3.dir);
                                    $$.cod += "mov " + dir3 + " A" + "\n";
                                    $$.cod += "itor\n";

                                    string dir3_2 = to_string($3.dir);
                                    $$.cod += "mov A " + dir3_2 + "\n";
                                 }

                                 if ($3.tipo == REAL && $1.tipo == ENTERO) {
                                     string dir3 = to_string($3.dir);
                                     $$.cod += "mov " + dir3 + " A" + "\n";
                                     $$.cod += "rtoi\n";

                                     string dir3_2 = to_string($3.dir);
                                     $$.cod += "mov A " + dir3_2 + "\n";
                                 }

                                     string dir1 = to_string($1.dir);
                                     $$.cod += "mov " + dir1 + " A" + "\n";

                                     string dbase_1 =  to_string($1.dbase);
                                     $$.cod += "addi #" + dbase_1 + "\n";

                                     string dir3_3 = to_string($3.dir);
                                     $$.cod += "mov " + dir3_3 + " @A\n";
                                }
         | tprintf pari formato coma Expr pard pyc {
                                                        $$.cod = $5.cod;
                                                        if(strcmp($3.lexema, "\"%d\"") == 0){
                                                            if($5.tipo != ENTERO){
                                                                string dir5 = to_string($5.dir);
                                                                $$.cod += "mov " + dir5 + " A" + "\n";
                                                                $$.cod += "rtoi\n";
                                                                $$.cod += "wri A\n";
                                                            } else {
                                                                string dir5 = to_string($5.dir);
                                                                $$.cod += "mov " + dir5 + " A" + "\n";
                                                                $$.cod += "wri A\n";
                                                            }
                                                        } else {
                                                            if($5.tipo == ENTERO){
                                                                string dir5 = to_string($5.dir);
                                                                $$.cod += "mov " + dir5 + " A" + "\n";
                                                                $$.cod += "itor\n";
                                                                $$.cod += "wrr A\n";
                                                            } else {
                                                                string dir5 = to_string($5.dir);
                                                                $$.cod += "mov " + dir5 + " A" + "\n";
                                                                $$.cod += "wrr A\n";
                                                            }
                                                        }
                                                        $$.cod += "wrl \n";
                                                  }

         | tscanf pari formato coma referencia Ref pard pyc {
                                                             if ((tablaTipos->tipos)[$6.tipo].clase == ARRAY) {
                                                                errorSemantico(ERRFALTAN, $6.lexema, $6.nlin, $6.ncol);
                                                             } else {
                                                                $$.cod = $6.cod;

                                                                if($6.tipo ==  ENTERO) {
                                                                    $$.cod += "rdi A\n";
                                                                    if(strcmp($3.lexema, "\"%g\"") == 0){
                                                                        $$.cod += "itor\n";
                                                                    }
                                                                }else {
                                                                    $$.cod += "rdr A\n";
                                                                    if(strcmp($3.lexema,"\"%d\"") == 0){
                                                                        $$.cod += "rtoi\n";
                                                                    }
                                                                }
                                                                string stemp = to_string(nTemp($6.nlin,$6.ncol));
                                                                $$.cod += "mov A" + stemp + "\n";
                                                                string dir6 = to_string($6.dir);

                                                                $$.cod += "mov " + dir6 + " A" + "\n";
                                                                string dbase = to_string($6.dbase);
                                                                $$.cod += "addi #" + dbase +"\n";
                                                                $$.cod += "mov " + stemp +" @A\n";
                                                             }
                                                           }
         | tif pari Expr pard Instr {
                                         $$.cod = $3.cod;

                                         string dir3 = to_string($3.dir);
                                         $$.cod += "mov " + dir3 + " A" + "\n";

                                         int etiqueta = nEtiqueta();
                                         string setiqueta = to_string(etiqueta);

                                         $$.cod += "jz L" + setiqueta +"\n";

                                         $$.cod += $5.cod;

                                         $$.cod += "L" + setiqueta + " ";
                                    }
         | tif pari Expr pard Instr telse Instr {

                                                 $$.cod = $3.cod;

                                                 string dir2 = to_string($3.dir);
                                                 $$.cod += "mov " + dir2 + " A\n";

                                                 int etiqueta_1 = nEtiqueta();
                                                 string setiqueta_1 = to_string(etiqueta_1);

                                                 $$.cod += "jz L" + setiqueta_1 + "\n";

                                                 $$.cod += $5.cod;

                                                 int etiqueta_2 = nEtiqueta();
                                                 string setiqueta_2 = to_string(etiqueta_2);

                                                 $$.cod += "jmp L" + setiqueta_2 + "\n";

                                                 $$.cod += "L" + setiqueta_1 + " " + $7.cod;
                                                 $$.cod += "L" + setiqueta_2 + " ";
                                              }
         | twhile pari Expr pard Instr {
                                           int etiqueta_1 = nEtiqueta();
                                           string setiqueta_1 = to_string(etiqueta_1);

                                           $$.cod = "L" + setiqueta_1 + " " + $3.cod;

                                           string dir2 = to_string($2.dir);
                                           $$.cod += "mov " + dir2 + " A" +"\n";

                                           int etiqueta_2 = nEtiqueta();
                                           string setiqueta_2 = to_string(etiqueta_2);
                                           $$.cod += "jz L" + setiqueta_2 + "\n";

                                           $$.cod += $5.cod;

                                           $$.cod += "jmp L" + setiqueta_1 + "\n";

                                           $$.cod += "L" + setiqueta_2 + " ";
                                      }
         | tfor pari id asig Esimple pyc Expr pyc id incrdecr pard Instr
                                       {

                                        }
         ;

Expr : Expr oprel Esimple {
                                    $$.dir = nTemp($3.nlin, $3.ncol);
                                    $$.cod = $1.cod + $3.cod;
                                    $$.tipo = ENTERO;

                                     string op = "";
                                     if (strcmp($2.lexema,">") == 0) {
                                        op = "gtr";
                                     } else if (strcmp($2.lexema,"<") == 0) {
                                        op = "lss";
                                     } else if (strcmp($2.lexema,"<>") == 0) {
                                        op = "neq";
                                     } else if (strcmp($2.lexema,"=") == 0) {
                                        op = "eql";
                                     } else if (strcmp($2.lexema,"<=") == 0) {
                                        op = "leq";
                                     } else {
                                        op = "geq";
                                     }

                                    if ($1.tipo == $3.tipo && $1.tipo == ENTERO) {
                                       string tip =  "i";

                                       string dir1 = to_string($1.dir);
                                       string dir3 = to_string($3.dir);

                                       $$.cod += "mov " + dir1 + " A" + "\n";
                                       $$.cod += op + tip + dir3 + "\n";
                                    } else if ($1.tipo == $3.tipo && $1.tipo == REAL) {
                                          string tip =  "r";

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

                                       string stemp_2 = to_string(numtemp);

                                       $$.cod += op + "r " + stemp_2 + "\n";

                                    } else if ($1.tipo == ENTERO && $3.tipo == REAL) {
                                       string dir1 = to_string($1.dir);

                                       $$.cod += "mov " + dir1 + " A" + "\n";

                                       $$.cod += "itor\n";

                                       string dir3 = to_string($3.dir);

                                       $$.cod += op + "r " + dir3 + "\n";
                                    }
                                    string stemp = to_string(numtemp);

                                    $$.cod += "mov A " + stemp + "\n";
                                }

     | Esimple {$$.dir = $1.dir;
                $$.tipo = $1.tipo;
                $$.cod = $1.cod;}
     ;

Esimple : Esimple opas Term {
                             $$.dir = nTemp($3.nlin, $3.ncol);
                             $$.cod = $1.cod + $3.cod;

                             if ($1.tipo == ENTERO && $3.tipo == ENTERO){
                                $$.tipo = ENTERO;
                             } else {
                                $$.tipo = REAL;
                             }
                                string op;
                             if (strcmp("+", $2.lexema) == 0) {
                                op = "add";
                             } else {
                                op = "sub";
                             }

                             if ($1.tipo == $3.tipo && $1.tipo == ENTERO) {  // ENTERO && ENTERO, REAL && REAL

                                string dir1 = to_string($1.dir);
                                string dir3 = to_string($3.dir);

                                $$.cod += "mov " + dir1 + " A" + "\n";
                                $$.cod += op + "i" + dir3 + "\n";
                             } else if ($1.tipo == $3.tipo && $1.tipo == REAL) {  // ENTERO && ENTERO, REAL && REAL
                                   string dir1 = to_string($1.dir);
                                   string dir3 = to_string($3.dir);

                                   $$.cod += "mov " + dir1 + " A" + "\n";
                                   $$.cod += op + "r" + dir3 + "\n";
                             }else if ($1.tipo == REAL && $3.tipo == ENTERO) {
                                string dir3 = to_string($3.dir);
                                $$.cod += "mov " + dir3 + " A" + "\n";

                                $$.cod += "itor\n";

                                string stemp_2 = to_string(numtemp);

                                $$.cod += "mov A " + stemp_2 + "\n";

                                string dir1 = to_string($1.dir);

                                $$.cod += "mov " + dir1 + " A" + "\n";

                                string stemp_3 = to_string(numtemp);

                                $$.cod += op + "r " + stemp_3 + "\n";

                             } else if ($1.tipo == ENTERO && $3.tipo == REAL) {
                                string dir1 = to_string($1.dir);

                                $$.cod += "mov " + dir1 + " A" + "\n";

                                $$.cod += "itor\n";

                                string dir3 = to_string($3.dir);

                                $$.cod += op + "r " + dir3 + "\n";
                             }
                             string stemp = to_string(numtemp);

                             $$.cod += "mov A " + stemp + "\n";
                         }

     | Term { $$.dir = $1.dir;
              $$.tipo = $1.tipo;
              $$.cod = $1.cod;}
     ;

Term : Term opmd Factor {
                                 $$.dir = nTemp($3.nlin, $3.ncol);
                                 $$.cod = $1.cod + $3.cod;

                                 if ($1.tipo == ENTERO && $3.tipo == ENTERO){
                                    $$.tipo = ENTERO;
                                 } else {
                                    $$.tipo = REAL;
                                 }
                                    string op;
                                 if (strcmp("*", $2.lexema) == 0){
                                     op = "mul";
                                 } else {
                                     op = "div";
                                 }

                                 if ($1.tipo == $3.tipo && $1.tipo == ENTERO) {
                                    string dir1 = to_string($1.dir);
                                    string dir3 = to_string($3.dir);

                                    $$.cod += "mov " + dir1 + " A" + "\n";
                                    $$.cod += op + "i" + dir3 + "\n";
                                 } else if ($1.tipo == $3.tipo && $1.tipo == REAL) {
                                       string dir1 = to_string($1.dir);
                                       string dir3 = to_string($3.dir);

                                       $$.cod += "mov " + dir1 + " A" + "\n";
                                       $$.cod += op + "r" + dir3 + "\n";
                                  }else if ($1.tipo == REAL && $3.tipo == ENTERO) {
                                    string dir3 = to_string($3.dir);
                                    $$.cod += "mov " + dir3 + " A" + "\n";

                                    $$.cod += "itor\n";

                                    string stemp = to_string(numtemp);

                                    $$.cod += "mov A " + stemp + "\n";

                                    string dir1 = to_string($1.dir);

                                    $$.cod += "mov " + dir1 + " A" + "\n";

                                    string stemp_2 = to_string(numtemp);

                                    $$.cod += op + "r " + stemp_2 + "\n";

                                 } else if ($1.tipo == ENTERO && $3.tipo == REAL) {
                                    string dir1 = to_string($1.dir);

                                    $$.cod += "mov " + dir1 + " A" + "\n";

                                    $$.cod += "itor\n";

                                    string dir3 = to_string($3.dir);

                                    $$.cod += op + "r " + dir3 + "\n";
                                 }
                                 string stemp = to_string(numtemp);

                                 $$.cod += "mov A " + stemp + "\n";
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

                      string dir1 = to_string($1.dir);
                      string sdbase = to_string($1.dbase);
                      string stemp = to_string(numtemp);

                      $$.cod += "mov " + dir1 + " A\n";
                      $$.cod += "addi #" + sdbase + "\n";
                      $$.cod += "mov @A " + stemp + "\n";

                 } else {
                    errorSemantico(ERRFALTAN,$1.lexema ,$1.nlin, $1.ncol);
                 }
             }
     | nentero {

                     $$.dir = nTemp($1.nlin, $1.ncol);

                     string stemp = " " + to_string($$.dir);
                     $$.cod = "mov #" + string($1.lexema) + stemp + "\n";

                     $$.tipo = ENTERO;
               }
     | nreal {
                     $$.dir = nTemp($1.nlin, $1.ncol);

                     string stemp = " " + to_string($$.dir);
                     $$.cod = "mov $" + string($1.lexema) + stemp + "\n";

                     $$.tipo = REAL;
             }
     | pari Expr pard {
                          $$.dir = $2.dir;
                          $$.tipo = $2.tipo;
                          $$.cod = $2.cod;
                      }
     ;

Ref : id {
            Simbolo *simb = tablaSimbolos->buscar($1.lexema);
            if (simb != nullptr) {
              string stemp = to_string(nTemp($1.nlin, $1.ncol));

              $$.cod = "mov #0 " + stemp + "\n";
              $$.tipo = simb->tipo;

              $$.dir = numtemp;
              $$.dbase = simb->dir;

              $$.nlin = $1.nlin;
              $$.ncol = $1.ncol;
              $$.lexema = $1.lexema;

             } else {
                errorSemantico(ERRNODECL,$1.lexema, $1.nlin, $1.ncol);
             }
         }
     | Ref cori {
                    if (!isArray($1.tipo)) {
                        if(strcmp($1.lexema, "]") == 0) {
                           errorSemantico(ERRSOBRAN,$2.lexema, $2.nlin, $2.ncol);
                        } else {
                           errorSemantico(ERRSOBRAN,$1.lexema, $1.nlin, $1.ncol);
                        }
                    }
                }
     Esimple cord {
                     if ($4.tipo == ENTERO) {
                         $$.tipo = (tablaTipos->tipos)[$1.tipo].tipoBase;
                         $$.dbase = $1.dbase;


                         $$.dir = nTemp($2.nlin, $2.ncol);

                         $$.cod = $1.cod + $4.cod;

                         string dir1 = to_string($1.dir);
                         string tam1 = to_string((tablaTipos->tipos)[$1.tipo].tamanyo);
                         string dir4 = to_string($4.dir);
                         string stemp = to_string(numtemp);

                         $$.cod += "mov " + dir1 + " A" + "\n";
                         $$.cod += "muli #" + tam1 + "\n";
                         $$.cod += "addi " + dir4 + "\n";
                         $$.cod += "mov A " +stemp + "\n";

                         $$.nlin = $5.nlin;
                         $$.ncol = $5.ncol;
                         $$.lexema = $5.lexema;
                    }else {
                         errorSemantico(ERR_NOENTERO,$5.lexema, $5.nlin, $5.ncol);
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
    return -1;
}

unsigned int nTemp(int nlin, int ncol) {
   if (numtemp == LIM_DIR_TEMP) {
      errorSemantico(ERR_MAXTMP,"", nlin, ncol);
   }
   ++numtemp;
   return numtemp;
}

unsigned int nVar(char *lexema, int nlin, int ncol) {
   if (numvar == LIM_DIR_VAR) {
      errorSemantico(ERR_NOCABE,lexema, nlin, ncol );
   }
   ++numvar;
   return numvar;
}

unsigned int nEtiqueta(void) {
   ++numetq;
   return numetq;
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

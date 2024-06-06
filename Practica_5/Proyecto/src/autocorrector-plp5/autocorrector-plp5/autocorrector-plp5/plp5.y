/*------------------------------ plp4.y -------------------------------*/
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
int FIN_DIR_VAR = 15999;   // dirección final de variables 
int FIN_DIR_TMP = 16383;  // dirección final de temporales

// #############################
//     variables
// #############################
TablaSimbolos *tsimbs = new TablaSimbolos(nullptr);
TablaTipos *ttipos = new TablaTipos();

int cont_pos_vars =-1;
int cont_pos_temps = 16000;
int cont_etiqueta = 0;

string operador, s1, s2;  // string auxiliares

// #############################
//     funciones
// #############################
int nuevaTemporal(char *lexema, int linea, int columna);
int nuevaVariable(char *lexema, int linea, int columna);
int incrementarEtiqueta();
bool esArray(int tipo);

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

Tipo   : tint   {$$.tipo = ENTERO;}
       | tfloat {$$.tipo = REAL;}
       ;

Bloque : llavei { tsimbs = new TablaSimbolos(tsimbs); }
         BDecl SeqInstr { tsimbs = tsimbs->getAmbitoAnterior(); } llaved
         {
            $$.cod = $3.cod + $4.cod;
         }

BDecl  : BDecl DVar {$$.cod = $1.cod + $2.cod;}
       | /* epsilon */   {$$.cod = "";}
       ;

DVar        : Tipo      {
                              $$.tipo = $1.tipo;
                        }
            LIdent pyc  {$$.cod = "";}
            ;

LIdent      :  LIdent coma {$$.tipo = $0.tipo;} Variable   {$$.cod = ""; }
            |  {$$.tipo = $0.tipo;} Variable   {$$.cod = ""; }
            ;

Variable : id {
                   if (tsimbs->buscarAmbito($1.lexema)!=nullptr) {
                     errorSemantico(ERRYADECL, $1.lexema,$1.nlin, $1.ncol);
                   }
                   $$.tipo = $0.tipo;
               }
           V {
                Simbolo *simbolo = new Simbolo();
                simbolo->dir = nuevaVariable($1.lexema, $1.nlin, $1.ncol);
                simbolo->nombre = $1.lexema;
                simbolo->tam = $3.tamanyo;
                simbolo->tipo = $3.tipo;

                if (cont_pos_vars + simbolo->tam >= FIN_DIR_VAR) {
                    errorSemantico(ERR_NOCABE,$1.lexema, $1.nlin, $1.ncol);
                }
                cont_pos_vars += simbolo->tam;
                tsimbs->nuevoSimbolo(*simbolo);
             }
         ;

V :  {$$.tipo = $0.tipo; $$.tamanyo = $0.tamanyo;}
  | cori nentero cord {$$.tamanyo = 1; $$.tipo = $0.tipo;}
  V {
      if(stoi($2.lexema) > 0){
        $$.tipo = ttipos->nuevoTipoArray(stoi($2.lexema),$5.tipo);
        $$.tamanyo = $5.tamanyo * stoi($2.lexema);
      } else {
        errorSemantico(ERRDIM,$2.lexema, $2.nlin, $2.ncol);
      }
  }
  ;


SeqInstr : SeqInstr {$$.nlin = cont_pos_temps;} Instr {$$.cod = $1.cod + $3.cod;
                                                cont_pos_temps = $2.nlin;}
         | /* epsilon */   {$$.cod = "";}
         ;
Instr :   pyc {$$.cod = "";}
         | Bloque {$$.cod = $1.cod;}
         | Ref asig Expr pyc {
                                 if ((ttipos->tipos)[$1.tipo].clase == ARRAY) {
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
                                                                $$.cod += "wri "+ dir5 + "\n";
                                                            }
                                                        } else {
                                                            if($5.tipo == ENTERO){
                                                                string dir5 = to_string($5.dir);
                                                                $$.cod += "mov " + dir5 + " A" + "\n";
                                                                $$.cod += "itor\n";
                                                                $$.cod += "wrr A\n";
                                                            } else {
                                                                string dir5 = to_string($5.dir);
                                                                $$.cod += "wrr "+dir5+"\n";
                                                            }
                                                        }
                                                        $$.cod += "wrl\n";
                                                  }

         | tscanf pari formato coma referencia Ref pard pyc {
                                                             if ((ttipos->tipos)[$6.tipo].clase == ARRAY) {
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
                                                                string stemp = to_string(nuevaTemporal($6.lexema,$6.nlin,$6.ncol));
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

                                         int etiqueta = incrementarEtiqueta();
                                         string setiqueta = to_string(etiqueta);

                                         $$.cod += "jz L" + setiqueta +"\n";

                                         $$.cod += $5.cod;

                                         $$.cod += "L" + setiqueta + " ";
                                    }
         | tif pari Expr pard Instr telse Instr {

                                                 $$.cod = $3.cod;

                                                 string dir3 = to_string($3.dir);
                                                 $$.cod += "mov " + dir3 + " A\n";

                                                 int etiqueta_1 = incrementarEtiqueta();
                                                 string setiqueta_1 = to_string(etiqueta_1);

                                                 $$.cod += "jz L" + setiqueta_1 + "\n";

                                                 $$.cod += $5.cod;

                                                 int etiqueta_2 = incrementarEtiqueta();
                                                 string setiqueta_2 = to_string(etiqueta_2);

                                                 $$.cod += "jmp L" + setiqueta_2 + "\n";

                                                 $$.cod += "L" + setiqueta_1 + " " + $7.cod;
                                                 $$.cod += "L" + setiqueta_2 + " ";
                                              }
         | twhile pari Expr pard Instr {
                                           int etiqueta_1 = incrementarEtiqueta();
                                           string setiqueta_1 = to_string(etiqueta_1);

                                           $$.cod = "L" + setiqueta_1 + " " + $3.cod;

                                           string dir3 = to_string($3.dir);
                                           $$.cod += "mov " + dir3 + " A" +"\n";

                                           int etiqueta_2 = incrementarEtiqueta();
                                           string setiqueta_2 = to_string(etiqueta_2);
                                           $$.cod += "jz L" + setiqueta_2 + "\n";

                                           $$.cod += $5.cod;

                                           $$.cod += "jmp L" + setiqueta_1 + "\n";

                                           $$.cod += "L" + setiqueta_2 + " ";
                                      }
         | tfor pari id asig Esimple {
                                         Simbolo *simbolo = tsimbs->buscar($3.lexema);
                                         if(simbolo == nullptr){
                                                errorSemantico(ERRNODECL, $3.lexema, $3.nlin, $3.ncol);
                                         }else if(simbolo->tipo != ENTERO){
                                               errorSemantico(ERR_NOENTERO, $3.lexema, $3.nlin, $3.ncol);
                                         }else if((ttipos->tipos)[$3.tipo].clase == ARRAY){
                                               errorSemantico(ERRFALTAN, $3.lexema, $3.nlin, $3.ncol);
                                         }
                                     }
         pyc Expr pyc id {
                                 Simbolo *simbolo = tsimbs->buscar($10.lexema);
                                 if(simbolo == nullptr){
                                       errorSemantico(ERRNODECL, $10.lexema, $10.nlin, $10.ncol);
                                  }else if(simbolo->tipo != ENTERO){
                                        errorSemantico(ERR_NOENTERO, $10.lexema, $10.nlin, $10.ncol);
                                  }else if((ttipos->tipos)[$3.tipo].clase == ARRAY){
                                        errorSemantico(ERRFALTAN, $10.lexema, $10.nlin, $10.ncol);
                                  }

                          }incrdecr pard Instr{
                                             Simbolo *simbolo = tsimbs->buscar($3.lexema);
                                             $$.cod = $5.cod;
                                             if ($5.tipo != ENTERO) {
                                                   string dir5 = to_string($5.dir);
                                                   $$.cod += "mov " + dir5 + " A" + "\n";
                                                   $$.cod += "rtoi\n";
                                                   $$.cod += "mov A " + dir5 + "\n";
                                             }

                                             $$.cod += "mov #0 A\n";

                                             string sim_dir = to_string(simbolo->dir);
                                             $$.cod += "addi #" + sim_dir + "\n";

                                             string dir5 = to_string($5.dir);
                                             $$.cod += "mov " + dir5 + " @A" + "\n";

                                             // Expr
                                             string setiqueta_1 = to_string(incrementarEtiqueta());

                                             $$.cod += "L" + setiqueta_1 + " " + $8.cod;

                                             string dir8 = to_string($8.dir);
                                             $$.cod += "mov " + dir8 + " A\n";

                                             string setiqueta_2 = to_string(incrementarEtiqueta());
                                             $$.cod += "jz L" + setiqueta_2 + "\n";
                                             $$.cod += $14.cod;

                                             Simbolo *simbolo_2 = tsimbs->buscar($10.lexema);
                                             string sim_dir_2 = to_string(simbolo->dir);
                                             $$.cod += "mov " + sim_dir_2 + " A\n";
                                             if( strcmp($12.lexema, "++") != 0){
                                                   $$.cod += "subi #1\n";

                                             }
                                             else{
                                                   $$.cod += "addi #1\n";
                                             }

                                             $$.cod += "mov A " +  sim_dir_2 + "\n";
                                             $$.cod += "jmp L" + setiqueta_1 + "\n";

                                             $$.cod += "L" + setiqueta_2 + " ";
                                        }
         ;

Expr : Expr oprel Esimple {
                                    $$.dir = nuevaTemporal($3.lexema,$3.nlin, $3.ncol);
                                    $$.cod = $1.cod + $3.cod;
                                    $$.tipo = ENTERO;

                                     string op = "";
                                     if (strcmp($2.lexema,">") == 0) {
                                        op = "gtr";
                                     } else if (strcmp($2.lexema,"<") == 0) {
                                        op = "lss";
                                     } else if (strcmp($2.lexema,"!=") == 0) {
                                        op = "neq";
                                     } else if (strcmp($2.lexema,"==") == 0) {
                                        op = "eql";
                                     } else if (strcmp($2.lexema,">=") == 0) {
                                        op = "geq";
                                     } else {
                                        op = "leq";
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


                                       string stemp = to_string(cont_pos_temps);

                                       $$.cod += "mov A " + stemp + "\n";

                                       string dir1 = to_string($1.dir);

                                       $$.cod += "mov " + dir1 + " A" + "\n";

                                       string stemp_2 = to_string(cont_pos_temps);

                                       $$.cod += op + "r " + stemp_2 + "\n";

                                    } else if ($1.tipo == ENTERO && $3.tipo == REAL) {
                                       string dir1 = to_string($1.dir);

                                       $$.cod += "mov " + dir1 + " A" + "\n";

                                       $$.cod += "itor\n";

                                       string dir3 = to_string($3.dir);

                                       $$.cod += op + "r " + dir3 + "\n";
                                    }
                                    string stemp = to_string(cont_pos_temps);

                                    $$.cod += "mov A " + stemp + "\n";
                                }

     | Esimple {$$.dir = $1.dir;
                $$.tipo = $1.tipo;
                $$.cod = $1.cod;}
     ;

Esimple : Esimple opas Term {
                             cont_pos_temps = nuevaTemporal($3.lexema,$3.nlin, $3.ncol);
                             $$.dir = cont_pos_temps;
                             $$.cod = $1.cod + $3.cod;

                              string op;
                              if (strcmp("+", $2.lexema) != 0) {
                                 op = "sub";
                              } else {
                                 op = "add";
                              }

                             if ($1.tipo == ENTERO && $3.tipo == ENTERO){
                                $$.tipo = ENTERO;
                                string dir1 = to_string($1.dir);
                                $$.cod += "mov " + dir1 + " A\n";

                                string dir3 = to_string($3.dir);
                                $$.cod += op + "i " + dir3 + "\n";
                             } else if($1.tipo == REAL && $3.tipo == REAL) {
                                $$.tipo = REAL;
                                string dir1 = to_string($1.dir);
                                $$.cod += "mov " + dir1 + " A\n";

                                string dir3 = to_string($3.dir);
                                $$.cod += op + "r " + dir3 + "\n";
                             } else if ($1.tipo == REAL && $1.tipo == ENTERO) {
                               $$.tipo = REAL;
                               string dir3 = to_string($3.dir);
                               $$.cod += "mov " + dir3 + " A\n";

                               $$.cod += "itor\n";

                               string snumtep = to_string(cont_pos_temps);
                               $$.cod += "mov A " + snumtep + "\n";

                               string dir1= to_string($1.dir);
                               $$.cod += "mov " + dir1 + " A\n";

                               $$.cod += op + "r " + snumtep + "\n";
                             }else {
                               $$.tipo = REAL;
                               string dir1 = to_string($1.dir);
                               $$.cod += "mov " + dir1 + " A\n";

                               $$.cod += "itor\n";

                               string dir3= to_string($3.dir);
                               $$.cod += op + "r " + dir3 + "\n";
                             }
                             string snumtep = to_string(cont_pos_temps);
                             $$.cod += "mov A " + snumtep + "\n";
                           }

     | Term { $$.dir = $1.dir;
              $$.tipo = $1.tipo;
              $$.cod = $1.cod;}
     ;

Term        : Term opmd Factor      {     
                                          s1 = $1.cod + $3.cod;
                                          cont_pos_temps = nuevaTemporal($3.lexema, $3.nlin, $3.ncol);
                                          $$.dir = cont_pos_temps;
                                          
                                          if(strcmp($2.lexema, "*") == 0){
                                                s2 = "mul";
                                          }else{
                                                s2 = "div";
                                          }
                                          
                                          if($1.tipo == $3.tipo){
                                                $$.tipo = $1.tipo;

                                                s1 += "mov " + to_string($1.dir) + " A\n";
                                                
                                                if($1.tipo == ENTERO){
                                                      s1 += s2 + "i " + to_string($3.dir) + "\n";
                                                }
                                                else{
                                                      s1 += s2 + "r " + to_string($3.dir) + "\n";
                                                }
                                          }
                                          else if($1.tipo == REAL && $3.tipo == ENTERO){
                                                $$.tipo =  REAL;
                                                s1 += "mov " + to_string($3.dir) + " A\n";
                                                s1 += "itor\n";
                                                s1 += "mov A " + to_string(cont_pos_temps) + "\n";
                                                s1 += "mov " + to_string($1.dir) + " A\n";
                                                s1 += s2 + "r " + to_string(cont_pos_temps) + "\n";
                                          }
                                          else{    
                                                $$.tipo = REAL;
                                                s1 += "mov " + to_string($1.dir) + " A\n";
                                                s1 += "itor\n";
                                                s1 += s2 + "r " + to_string($3.dir) + "\n";
                                          }

                                          s1 += "mov A " + to_string(cont_pos_temps) + "\n";
                                          $$.cod = s1;
                                    }
            | Factor          {     
                                    $$.cod = $1.cod;
                                    $$.dir = $1.dir;
                                    $$.tipo = $1.tipo;
                              }
            ;

Factor      : Ref       {     
                              if((ttipos->tipos)[$1.tipo].clase == ARRAY){
                                    errorSemantico(ERRFALTAN, $1.lexema, $1.nlin, $1.ncol);
                              }

                              s1 = $1.cod;
                              cont_pos_temps = nuevaTemporal($1.lexema, $1.nlin, $1.ncol);
                              $$.tipo = $1.tipo;
                              $$.dir = cont_pos_temps;

                              s1 += "mov " + to_string($1.dir) + " A\n";
                              s1 += "addi #" + to_string($1.dbase) + "\n";
                              s1 += "mov @A " + to_string(cont_pos_temps) + "\n";
                              $$.cod = s1;
                        }
            | nentero         {     $$.tipo = ENTERO;
                                    cont_pos_temps = nuevaTemporal($1.lexema, $1.nlin, $1.ncol);
                                    $$.dir = cont_pos_temps;
                                    s1 = "mov #" + string($1.lexema) + " " + to_string(cont_pos_temps) + "\n";
                                    $$.cod = s1;
                              }
            | nreal           {     $$.tipo = REAL;
                                    cont_pos_temps = nuevaTemporal($1.lexema, $1.nlin, $1.ncol);
                                    $$.dir = cont_pos_temps;
                                    $$.cod = "mov $" + string($1.lexema) + " " + to_string(cont_pos_temps) + "\n";
                              }
            | pari Expr pard        {     $$.cod = $2.cod;
                                          $$.dir = $2.dir;
                                          $$.tipo = $2.tipo;
                                    }
            ;

Ref         : id        {     Simbolo *simb = tsimbs->buscar($1.lexema);
                              if (simb == nullptr){
                                    errorSemantico(ERRNODECL, $1.lexema, $1.nlin, $1.ncol);
                              }

                              cont_pos_temps = nuevaTemporal($1.lexema, $1.nlin, $1.ncol);
                              $$.cod = "mov #0 " + to_string(cont_pos_temps) + "\n";
                              $$.tipo = simb->tipo;
                              $$.dbase = simb->dir;
                              $$.dir = cont_pos_temps;

                              $$.lexema = $1.lexema;
                              $$.nlin = $1.nlin;
                              $$.ncol = $1.ncol;
                        }

            | Ref cori  {     if (!esArray($1.tipo)) {
                                    if(strcmp($1.lexema, "]") == 0) {
                                       errorSemantico(ERRSOBRAN, $2.lexema, $2.nlin, $2.ncol); 
                                    } else {
                                       errorSemantico(ERRSOBRAN, $2.lexema, $1.nlin, $1.ncol);
                                    }
                                 }                   
                        }
              Esimple cord    {     if($4.tipo != ENTERO){
                                          errorSemantico(ERR_NOENTERO, $5.lexema, $5.nlin, $5.ncol);
                                    }

                                    $$.tipo = (ttipos->tipos)[$1.tipo].tipoBase;
                                    $$.dbase = $1.dbase;

                                    cont_pos_temps = nuevaTemporal($1.lexema, $1.nlin, $1.ncol);
                                    $$.dir = cont_pos_temps;

                                    s1 = $1.cod + $4.cod;
                                    s1 += "mov " + to_string($1.dir) + " A\n";
                                    s1 += "muli #" + to_string((ttipos->tipos)[$1.tipo].tamanyo) + "\n";
                                    s1 += "addi " + to_string($4.dir) + "\n";
                                    s1 += "mov A " + to_string(cont_pos_temps) + "\n";

                                    $$.cod = s1;

                                    $$.lexema = $5.lexema;
                                    $$.nlin = $5.nlin;
                                    $$.ncol = $5.ncol;

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
    exit(1);
}

int nuevaVariable(char *lexema, int linea, int columna){
      if(FIN_DIR_VAR == cont_pos_vars){
            errorSemantico(ERR_NOCABE, lexema, linea, columna);
      }
       return ++cont_pos_vars;

}

int nuevaTemporal(char *lexema, int linea, int columna){
      if(FIN_DIR_TMP == cont_pos_temps){
            errorSemantico(ERR_MAXTMP, lexema, linea, columna);
      }
      return ++cont_pos_temps;
}

int incrementarEtiqueta(){
      return ++cont_etiqueta;
}

bool esArray(int tipo){
      if((ttipos->tipos)[tipo].clase == ARRAY){
            return true;
      }
   return false;
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


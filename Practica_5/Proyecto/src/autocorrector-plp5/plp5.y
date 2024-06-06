/*------------------------------ plp4.y -------------------------------*/
%token cuerpo
%token pari pard
%token ent real
%token llavei llaved
%token pyc coma
%token id nentero nreal
%token cori cord
%token asig
%token imprimir leer formato referencia
%token si sino
%token mientras para incrdecr
%token oprel opas opmd


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

S           : FVM       {
                              int tk = yylex();
                              if(tk == 0){
                                    cout << $1.cod << "halt\n";
                              } 
                              else{
                                    yyerror("");
                              }
                        }
            ;


FVM         : DVar FVM        {
                                    $$.cod = $1.cod + $2.cod;
                              }

            | ent cuerpo pari pard Bloque   {
                                                $$.cod = $5.cod;
                                          }
            ;

Tipo        : ent       {
                              $$.tipo = ENTERO;
                        }
            | real     {
                              $$.tipo = REAL;
                        }
            ;

Bloque      : llavei {  tsimbs = new TablaSimbolos(tsimbs);} 
              BDecl SeqInstr llaved      {
                                                $$.cod = $3.cod + $4.cod;
                                                tsimbs = tsimbs->getAmbitoAnterior();
                                          }
            ;

BDecl       : BDecl DVar      {
                                    $$.cod = $1.cod + $2.cod;
                              }
            | /* epsilon */   {     $$.cod = ""; }
            ;

DVar        : Tipo      {
                              $$.tipo = $1.tipo;
                        } 
            LIdent pyc  {$$.cod = "";}   
            ;

LIdent      :  LIdent coma {$$.tipo = $0.tipo;} Variable   {$$.cod = ""; }
            |  {$$.tipo = $0.tipo;} Variable   {$$.cod = ""; }
            ;

Variable    : id  {     
                        if (tsimbs->buscarAmbito($1.lexema) != nullptr) {
                              errorSemantico(ERRYADECL, $1.lexema, $1.nlin, $1.ncol);
                        }
                        $$.tipo = $0.tipo;
                  }  
                  V     {
                              Simbolo *simb = new Simbolo();
                              simb->nombre = $1.lexema;
                              simb->dir = nuevaVariable($1.lexema, $1.nlin, $1.ncol);
                              simb->tam = $3.tamanyo;
                              simb->tipo = $3.tipo;

                              if(cont_pos_vars + simb->tam >= FIN_DIR_VAR) {
                                    errorSemantico(ERR_NOCABE, $1.lexema, $1.nlin, $1.ncol);
                              }
                              cont_pos_vars += simb->tam;  
                              tsimbs->nuevoSimbolo(*simb);
                        }
            ;

V           : cori nentero cord {$$.tipo = $0.tipo; $$.tamanyo = 1;}
                                    V   {      
                                          if (stoi($2.lexema) <= 0) {
                                                errorSemantico(ERRDIM, $2.lexema, $2.nlin, $2.ncol); 
                                          }
                                          $$.tipo = ttipos->nuevoTipoArray(stoi($2.lexema), $5.tipo);
                                          $$.tamanyo = $5.tamanyo * stoi($2.lexema);
                                    }
            | /* epsilon */   { $$.tipo = $0.tipo; $$.tamanyo = $0.tamanyo;}
            ;

SeqInstr    : SeqInstr {  $$.nlin = cont_pos_temps;  } 
                  Instr       {
                                    $$.cod = $1.cod + $3.cod;
                                    cont_pos_temps = $2.nlin;
                              }
            | /* epsilon */   { $$.cod = "";}
            ;

Instr       : pyc       {
                              $$.cod = "";
                        }
            | Bloque    {
                              $$.cod = $1.cod;
                        }
            | Ref asig Expr pyc     {
                                          if((ttipos->tipos)[$1.tipo].clase == ARRAY){
                                                errorSemantico(ERRFALTAN, $1.lexema, $1.nlin, $1.ncol);
                                          }
                                          
                                          s1 = $1.cod + $3.cod;

                                          if ($1.tipo == REAL && $3.tipo == ENTERO) {
                                                s1 += "mov " + to_string($3.dir) + " A\n";
                                                s1 += "itor\n";
                                                s1 += "mov A " + to_string($3.dir) + "\n";
                                          }
                                          if ($1.tipo == ENTERO && $3.tipo == REAL) {
                                                s1 += "mov " + to_string($3.dir) + " A\n";
                                                s1 += "rtoi\n";
                                                s1 += "mov A " + to_string($3.dir) + "\n";
                                          }

                                          s1 += "mov " + to_string($1.dir) + " A\n";
                                          s1 += "addi #" + to_string($1.dbase) + "\n";

                                          s1 += "mov " + to_string($3.dir) + " @A\n";
                                          $$.cod = s1;
                                    }
            | imprimir pari formato coma Expr pard pyc        {
                                                                  s1 = $5.cod;
                                                                  if(strcmp($3.lexema, "\"%d\"") ==0){
                                                                        if($5.tipo == REAL){
                                                                              s1 += "mov " + to_string($5.dir) + " A\n";
                                                                              s1 += "rtoi\n";
                                                                              s1 += "wri A\n";    
                                                                        }
                                                                        else{
                                                                              s1 += "wri " + to_string($5.dir) + "\n";
                                                                        }
                                                                  }
                                                                  else{
                                                                        if($5.tipo == ENTERO){
                                                                              s1 += "mov " + to_string($5.dir) + " A\n";
                                                                              s1 += "itor\n";
                                                                              s1 += "wrr A\n";    
                                                                        }
                                                                        else{
                                                                              s1 += "wrr " + to_string($5.dir) + "\n";
                                                                        }
                                                                  }
                                                                  s1 += "wrl\n";
                                                                  $$.cod = s1;
                                                            }
            | leer pari formato coma referencia Ref pard pyc     {
                                                                        if ((ttipos->tipos)[$6.tipo].clase == ARRAY) {
                                                                              errorSemantico(ERRFALTAN, $6.lexema, $6.nlin, $6.ncol);
                                                                        }
                                                                              
                                                                        s1 = $6.cod;

                                                                        if($6.tipo == ENTERO){
                                                                              s1 += "rdi A\n";
                                                                              if(strcmp($3.lexema, "\"%g\"") ==0){
                                                                                    s1 += "itor\n";
                                                                              }
                                                                              
                                                                              cont_pos_temps = nuevaTemporal($6.lexema, $6.nlin, $6.ncol);
                                                                              s1 += "mov A " + to_string(cont_pos_temps) + "\n";

                                                                              s1 += "mov " + to_string($6.dir) + " A\n";
                                                                              s1 += "addi #" + to_string($6.dbase) + "\n";

                                                                              s1 += "mov " + to_string(cont_pos_temps) + " @A\n";
                                                                        }
                                                                        else{
                                                                              s1 += "rdr A\n";
                                                                              if(strcmp($3.lexema, "\"%d\"") ==0){
                                                                                    s1 += "rtoi\n";
                                                                              }
                                                                              
                                                                              cont_pos_temps = nuevaTemporal($6.lexema, $6.nlin, $6.ncol);
                                                                              s1 += "mov A " + to_string(cont_pos_temps) + "\n";

                                                                              s1 += "mov " + to_string($6.dir) + " A\n";
                                                                              s1 += "addi #" + to_string($6.dbase) + "\n";

                                                                              s1 += "mov " + to_string(cont_pos_temps) + " @A\n";
                                                                        }
                                                                        $$.cod = s1;
                                                                  }
            | si pari Expr pard Instr     {
                                                s1 = $3.cod;
                                                int label = incrementarEtiqueta();

                                                s1 += "mov " + to_string($3.dir) + " A\n";
                                                s1 += "jz L" + to_string(label) +"\n";
                                                s1 += $5.cod;
                                                s1 += "L" + to_string(label) + " ";
                                                $$.cod = s1;
                                          }
            | si pari Expr pard Instr sino Instr      {
                                                            s1 = $3.cod;
                                                            int label1 = incrementarEtiqueta();
                                                            int label2 = incrementarEtiqueta();

                                                            s1 += "mov " + to_string($3.dir) + " A\n";
                                                            s1 += "jz L" + to_string(label1) +"\n";
                                                            s1 += $5.cod;
                                                            s1 += "jmp L" + to_string(label2) + "\n";
                                                            s1 += "L" + to_string(label1) + " " + $7.cod;
                                                            s1 += "L" + to_string(label2) + " ";
                                                            $$.cod = s1;

                                                      }
            | mientras pari Expr pard Instr        {
                                                      int label1 = incrementarEtiqueta();
                                                      int label2 = incrementarEtiqueta();
                                                
                                                      s1 = "L" + to_string(label1) + " " + $3.cod;
                                                      s1 += "mov " + to_string($3.dir) + " A\n";
                                                      s1 += "jz L" + to_string(label2) + "\n";
                                                      s1 += $5.cod;
                                                      s1 += "jmp L" + to_string(label1) + "\n";
                                                      s1 += "L" + to_string(label2) + "\n";
                                                      $$.cod = s1;
                                                }
            | para pari id asig Esimple    {
                                                Simbolo *simb = tsimbs->buscar($3.lexema);
                                                if(simb == nullptr){
                                                      errorSemantico(ERRNODECL, $3.lexema, $3.nlin, $3.ncol);
                                                }
                                                if(simb->tipo != ENTERO){
                                                      errorSemantico(ERR_NOENTERO, $3.lexema, $3.nlin, $3.ncol);
                                                }

                                                if((ttipos->tipos)[$3.tipo].clase == ARRAY){
                                                      errorSemantico(ERRFALTAN, $3.lexema, $3.nlin, $3.ncol);
                                                }
                                          }
                pyc Expr pyc id     {
                                          Simbolo *simb = tsimbs->buscar($10.lexema);
                                          if(simb == nullptr){
                                                errorSemantico(ERRNODECL, $10.lexema, $10.nlin, $10.ncol);
                                          }
                                          if(simb->tipo != ENTERO){
                                                errorSemantico(ERR_NOENTERO, $10.lexema, $10.nlin, $10.ncol);
                                          }

                                          if((ttipos->tipos)[$3.tipo].clase == ARRAY){
                                                errorSemantico(ERRFALTAN, $10.lexema, $10.nlin, $10.ncol);
                                          }  
                                    }
                  incrdecr pard Instr         {                                                                       
                                                      s1 = $5.cod;
                                                                  
                                                      // id = Esimple
                                                      Simbolo *simb = tsimbs->buscar($3.lexema);
                                                           
                                                      if ($5.tipo == REAL) {
                                                            s1 += "mov " + to_string($5.dir) + " A\n";
                                                            s1 += "rtoi\n";
                                                            s1 += "mov A " + to_string($5.dir) + "\n";
                                                      }

                                                      s1 += "mov #0 A\n";
                                                      s1 += "addi #" + to_string(simb->dir) + "\n";
                                                      s1 += "mov " + to_string($5.dir) + " @A\n";

                                                      // Expr
                                                      int label1 = incrementarEtiqueta();
                                                      int label2 = incrementarEtiqueta(); 
                                                      s1 += "L" + to_string(label1) + " " + $8.cod;
                                                      s1 += "mov " + to_string($8.dir) + " A\n";
                                                      s1 += "jz L" + to_string(label2) + "\n";
                                                      s1 += $14.cod;
                                                      
                                                      // incrdecr
                                                      Simbolo *simb2 = tsimbs->buscar($10.lexema);
                                                      s1 += "mov " + to_string(simb2->dir) + " A\n";
                                                      if( strcmp($12.lexema, "++") == 0){
                                                            s1 += "addi #1\n";
                                                      }
                                                      else{
                                                            s1 += "subi #1\n";
                                                      }
                                                
                                                      s1 += "mov A " +  to_string(simb2->dir) + "\n";
                                                      s1 += "jmp L" + to_string(label1) + "\n";

                                                      // salir del for
                                                      s1 += "L" + to_string(label2) + " ";
                                                      $$.cod = s1;


                                                }
            ;

Expr        : Expr oprel Esimple          {
                                                s1 = $1.cod + $3.cod;
                                                cont_pos_temps = nuevaTemporal($3.lexema, $3.nlin, $3.ncol);
                                                $$.dir = cont_pos_temps;
                                                $$.tipo = ENTERO;

                                                if(strcmp($2.lexema, "==") == 0){
                                                      s2 = "eql";
                                                }
                                                else if(strcmp($2.lexema, "!=") == 0){
                                                      s2 = "neq";
                                                }
                                                else if(strcmp($2.lexema, ">") == 0){
                                                      s2 = "gtr";
                                                }
                                                else if(strcmp($2.lexema, ">=") == 0){
                                                      s2 = "geq";
                                                }
                                                else if(strcmp($2.lexema, "<") == 0){
                                                      s2 = "lss";
                                                }
                                                else{
                                                      s2 = "leq";
                                                }
                                                
                                                if($1.tipo == $3.tipo){
                                                      s1 += "mov " + to_string($1.dir) + " A\n";
                                                      
                                                      if($1.tipo == ENTERO){
                                                            s1 += s2 + "i " + to_string($3.dir) + "\n";
                                                      }
                                                      else{
                                                            s1 += s2 + "r " + to_string($3.dir) + "\n";
                                                      }
                                                }
                                                else if($1.tipo == REAL && $3.tipo == ENTERO){
                                                      s1 += "mov " + to_string($3.dir) + " A\n";
                                                      s1 += "itor\n";
                                                      s1 += "mov A " + to_string(cont_pos_temps) + "\n";
                                                      s1 += "mov " + to_string($1.dir) + " A\n";
                                                      s1 += s2 + "r " + to_string(cont_pos_temps) + "\n";
                                                }
                                                else{
                                                      s1 += "mov " + to_string($1.dir) + " A\n";
                                                      s1 += "itor\n";
                                                      s1 += s2 + "r " + to_string($3.dir) + "\n";
                                                }

                                                s1 += "mov A " + to_string(cont_pos_temps) + "\n";
                                                $$.cod = s1;

                                          }
            | Esimple         {
                                    $$.cod = $1.cod;
                                    $$.dir = $1.dir;
                                    $$.tipo = $1.tipo;

                              }
            ;

Esimple     : Esimple opas Term     {
                                          s1 = $1.cod + $3.cod;
                                          cont_pos_temps = nuevaTemporal($3.lexema, $3.nlin, $3.ncol);
                                          $$.dir = cont_pos_temps;
                                          
                                          if(strcmp($2.lexema, "+") == 0){
                                                s2 = "add";
                                          }else{
                                                s2 = "sub";
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
            | Term      {     
                              $$.cod = $1.cod;
                              $$.dir = $1.dir;
                              $$.tipo = $1.tipo;
                        }
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


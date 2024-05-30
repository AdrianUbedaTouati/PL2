/*########################################################*/
/*                                                        */
/*   Autor: Natallia Tsuranava                            */
/*   PL 2022/23                                           */
/*   Modificacion: ejemplo.y (ejemploHT)                  */
/*                                                        */
/*########################################################*/

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
unsigned int cvar = 0;        // contador de direcciones de variables
unsigned int ctemp = 16000;   // contador de direcciones temporales
unsigned int cetiq = 0;       // contador de etiquetas

//==========================================================
// FUNCIONES
//==========================================================
unsigned int nuevaTemp(int nlin, int ncol);
unsigned int nuevaVar(char *lexema, int nlin, int ncol);
unsigned int nuevaEtiqueta(void);
bool esArray(int tipo);


%}

%%


S        : algoritmo dospto id SDec SInstr falgoritmo
                              {  /* comprobar que después del programa no hay ningún token más */
                                 int tk = yylex();
                                 if (tk == 0) {
                                    // SDec.cod | SInstr.cod | halt (detener el programa) 
                                    cout << $4.cod << $5.cod << "halt\n";
                                 } else {
                                    yyerror("");
                                 }
                              }
         ;

SDec     : Dec                {  $$.cod = $1.cod;  }
         | /* epsilon */      {  $$.cod = "";   }
         ;

Dec      : var DVar MDVar fvar
                              {  $$.cod = $2.cod + $3.cod;  }
         ;

DVar     : Tipo dospto id     {  // Para crear nuevo simbolo necesitamos:
                                 // nombre = id, tipo, dir, tam
                                 Simbolo *simbolo = new Simbolo();
                                 simbolo->nombre = $3.lexema;
                                 simbolo->dir = nuevaVar($3.lexema, $3.nlin, $3.ncol);

                                 // Bucle para obtener el tamanyo
                                 $$.tipo = $1.tipo;
                                 simbolo->tam = (ttipos->tipos)[$1.tipo].tamanyo;
                                 while ((ttipos->tipos)[$$.tipo].clase != TIPOBASICO) {
                                    // quitar la dimension
                                    $$.tipo = (ttipos->tipos)[$$.tipo].tipoBase;

                                    simbolo->tam *= (ttipos->tipos)[$$.tipo].tamanyo;
                                 }
                                 simbolo->tipo = $1.tipo;

                                 // Comprobar el espacio para todo el array
                                 if (cvar + simbolo->tam >= MAX_DIR_VAR) {
                                    errorSemantico(ERR_NOCABE, 0, 0, $3.lexema);
                                 }
                                 cvar += simbolo->tam;      // actualizar contador
                                 
                                 // comprueba si el simbolo se repite en el ambito
                                 // si no se repite, se anade a tsActual
                                 if (!tsActual->newSymb(*simbolo)) {
                                    errorSemantico(ERR_YADECL, $3.nlin, $3.ncol, $3.lexema);
                                 }

                              }
           LId pyc
         ;

MDVar    : DVar MDVar         {  $$.cod = $1.cod + $2.cod;  }
         | /* epsilon */      {  $$.cod = "";   }
         ;

LId      : coma id            {  // Para crear nuevo simbolo necesitamos:
                                 // nombre = id, tipo, dir, tam
                                 Simbolo *simbolo = new Simbolo();
                                 simbolo->nombre = $2.lexema;
                                 simbolo->dir = nuevaVar($2.lexema, $2.nlin, $2.ncol);

                                 // Bucle para obtener el tamanyo
                                 $$.tipo = $0.tipo;
                                 simbolo->tam = (ttipos->tipos)[$0.tipo].tamanyo;
                                 while ((ttipos->tipos)[$$.tipo].clase != TIPOBASICO) {
                                    // quitar la dimension
                                    $$.tipo = (ttipos->tipos)[$$.tipo].tipoBase;

                                    simbolo->tam *= (ttipos->tipos)[$$.tipo].tamanyo;
                                 }
                                 simbolo->tipo = $0.tipo;

                                 // Comprobar el espacio para todo el array
                                 if (cvar + simbolo->tam >= MAX_DIR_VAR) {
                                    errorSemantico(ERR_NOCABE, 0, 0, $2.lexema);
                                 }
                                 cvar += simbolo->tam;      // actualizar contador

                                 // comprueba si el simbolo se repite en el ambito
                                 // si no se repite, se anade a tsActual
                                 if (!tsActual->newSymb(*simbolo)) {
                                    errorSemantico(ERR_YADECL, $2.nlin, $2.ncol, $2.lexema);
                                 }
                              }
           LId
         | /* epsilon */      {  $$.cod = "";   }
         ;

Tipo     : entero             {  $$.tipo = ENTERO; }
         | real               {  $$.tipo = REAL;   }
         | logico             {  $$.tipo = LOGICO; }
         | tabla nentero de Tipo
                              {  if (stoi($2.lexema) <= 0) {
                                    errorSemantico(ERR_DIM, $2.nlin, $2.ncol, $2.lexema); 
                                 }
                                 $$.tipo = ttipos->nuevoTipoArray(stoi($2.lexema), $4.tipo);
                              }
         ;

SInstr   : SInstr pyc         {  $$.nlin = ctemp;  } 
           Instr              {  $$.cod = $1.cod + $4.cod;  
                                 ctemp = $1.nlin;
                              }
         |                    {  $$.nlin = ctemp;  }
           Instr              {  $$.cod = $2.cod;
                                 ctemp = $1.nlin;
                              }
         ;

Instr    : escribe Expr       {  $$.cod = $2.cod;

                                 if ($2.tipo == LOGICO) {
                                    int etq1 = nuevaEtiqueta();   // etiqueta si la expr es falsa
                                    int etq2 = nuevaEtiqueta();   // etiqueta de salida
                                    
                                    // El valor de A debe ser entero
                                    // mov Expr.dir A
                                    $$.cod += "mov " + to_string($2.dir) + " A\n";

                                    // Salta a la posicion de programa indicada por 
                                    // el valor L1 si en A hay un cero (falso)
                                    // jz L1 
                                    $$.cod += "jz L" + to_string(etq1) + "\n";

                                    // se escribira una ‘c’ minuscula si el valor es cierto
                                    $$.cod += "wrc #" + to_string(static_cast<int>('c')) + "\n";
                                    
                                    // saltar a la etiqueta de salida
                                    $$.cod += "jmp L" + to_string(etq2) + "\n";

                                    // la etiqueta de falso
                                    $$.cod += "L" + to_string(etq1);

                                    // se escribira una ‘f’ minuscula si el valor es falso
                                    $$.cod += " wrc #" + to_string(static_cast<int>('f')) + "\n";

                                    // la etiqueta de salida
                                    $$.cod += "L" + to_string(etq2) + " ";
                                 } else {
                                    // si el tipo es real tenemos wrr, sino wri
                                    string ri = ($2.tipo == REAL) ? "r" : "i";
                                    
                                    $$.cod += "wr" + ri + " " + to_string($2.dir) + "\n";
                                 }

                                 $$.cod += "wrl\n";
                              }
         | lee Ref            {  // si el tipo de Ref que nos llega es array, es decir no es un tipo basico,
                                 // entonces se necesitan corchetes
                                 if ((ttipos->tipos)[$2.tipo].clase == ARRAY) {
                                    errorSemantico(ERR_FALTAN, $2.nlin, $2.ncol, $2.lexema);
                                 }
                                 
                                 $$.cod = $2.cod;

                                 if ($2.tipo == LOGICO) {
                                    //  Al leer del teclado una variable logica, 
                                    // si se lee el caracter ‘c’ se entendera que el valor es cierto, 
                                    // y si se lee cualquier otro caracter se entendera que es falso
                                    
                                    // Lee un caracter de la consola y carga su codigo ASCII en destino
                                    $$.cod += "rdc A\n";

                                    // si en A esta 'c', A se carga con 1
                                    $$.cod += "eqli #" + to_string(static_cast<int>('c')) + "\n";

                                    // movemos 1 o 0 a la temporal
                                    $$.cod += "mov A " + to_string(nuevaTemp($1.nlin, $1.ncol)) + "\n";
                                    
                                    // calcular la direccion
                                    $$.cod += "mov " + to_string($2.dir) + " A\n";
                                    $$.cod += "addi #" + to_string($2.dbase) + "\n";

                                    // guardar ctemp en la direccion calculada en A
                                    $$.cod += "mov " + to_string(ctemp) + " @A\n";
                                 } else {
                                    // calcular la direccion
                                    $$.cod += "mov " + to_string($2.dir) + " A\n";
                                    $$.cod += "addi #" + to_string($2.dbase) + "\n";

                                    // si el tipo es real tenemos rdr, sino rdi
                                    string ri = ($2.tipo == REAL) ? "r" : "i";

                                    // Lee un numero de la consola en la direccion calculada en A
                                    $$.cod += "rd" + ri + " @A\n";
                                 }
                              }
         | si Expr entonces Instr
                              {  if ($2.tipo != LOGICO) {
                                    errorSemantico(ERR_EXP_LOG, $1.nlin, $1.ncol, $1.lexema);
                                 }
                                 
                                 // Expr.cod
                                 $$.cod = $2.cod;

                                 int etq = nuevaEtiqueta();    // etiqueta si expr es falsa

                                 // mov Expr.dir A (debe ser un valor entero)
                                 $$.cod += "mov " + to_string($2.dir) + " A\n";

                                 // jz L1 (saltar si vale 0)
                                 $$.cod += "jz L" + to_string(etq) +"\n";

                                 // Instr1.cod
                                 $$.cod += $4.cod;

                                 // Etq a la siguiente instruccion
                                 $$.cod += "L" + to_string(etq) + " ";
                              }         
         | si Expr entonces Instr sino Instr
                              {  if ($2.tipo != LOGICO) {
                                    errorSemantico(ERR_EXP_LOG, $1.nlin, $1.ncol, $1.lexema);
                                 }

                                 // Expr.cod
                                 $$.cod = $2.cod;

                                 int etq1 = nuevaEtiqueta();   // etiqueta si la expr es falsa
                                 int etq2 = nuevaEtiqueta();   // etiqueta de salida

                                 // mov Expr.dir A
                                 $$.cod += "mov " + to_string($2.dir) + " A\n";

                                 // jz L1
                                 $$.cod += "jz L" + to_string(etq1) + "\n";

                                 // Instr1.cod
                                 $$.cod += $4.cod;

                                 // jmp L2
                                 $$.cod += "jmp L" + to_string(etq2) + "\n";

                                 // L1 Instr2.cod
                                 $$.cod += "L" + to_string(etq1) + " " + $6.cod;

                                 // L2 (siguiente instr)
                                 $$.cod += "L" + to_string(etq2) + " ";
                              }
         | mientras Expr hacer Instr
                              {  if ($2.tipo != LOGICO) {
                                    errorSemantico(ERR_EXP_LOG, $1.nlin, $1.ncol, $1.lexema);
                                 }

                                 int etq1 = nuevaEtiqueta();
                                 int etq2 = nuevaEtiqueta();

                                 // L1 Expr.cod
                                 $$.cod = "L" + to_string(etq1) + " " + $2.cod;

                                 // mov Expr.dir A
                                 $$.cod += "mov " + to_string($2.dir) + " A\n";

                                 // jz L2
                                 $$.cod += "jz L" + to_string(etq2) + "\n";

                                 // Instr1.cod
                                 $$.cod += $4.cod;

                                 // jmp L1
                                 $$.cod += "jmp L" + to_string(etq1) + "\n";

                                 // L2 (siguiente inst)
                                 $$.cod += "L" + to_string(etq2) + " ";
                              }   
         | repetir Instr hasta Expr
                              {  if ($4.tipo != LOGICO) {
                                    errorSemantico(ERR_EXP_LOG, $3.nlin, $3.ncol, $3.lexema);
                                 }

                                 int etq = nuevaEtiqueta();    // etiqueta de bucle

                                 // L1 Instr1.cod
                                 $$.cod = "L" + to_string(etq) + " " + $2.cod;

                                 // Expr.cod
                                 $$.cod += $4.cod;

                                 // mov Expr.dir A
                                 $$.cod += "mov " + to_string($4.dir) + " A\n";

                                 // jz L1
                                 $$.cod += "jz L" + to_string(etq) + "\n";                                 
                              }   
         | Ref opasig Expr    {  // si el tipo de Ref que nos llega es array, es decir no es un tipo basico,
                                 // entonces se necesitan corchetes
                                 if ((ttipos->tipos)[$1.tipo].clase == ARRAY) {
                                    errorSemantico(ERR_FALTAN, $1.nlin, $1.ncol, $1.lexema);
                                 }

                                 // no esta permitido asignar un valor real a una variable entera
                                 // no se permite asignar valores logicos a variables enteras
                                 if ($1.tipo == ENTERO && ($3.tipo == REAL || $3.tipo == LOGICO)) {
                                    errorSemantico(ERR_EXDER_ENT, $2.nlin, $2.ncol, $2.lexema);
                                 }
                                 
                                 // no se permite asignar valores logicos a variables reales
                                 if ($1.tipo == REAL && $3.tipo == LOGICO) {
                                    errorSemantico(ERR_EXDER_RE, $2.nlin, $2.ncol, $2.lexema);
                                 }

                                 // no se permite asignar valores reales o enteros a variables logicas
                                 if ($1.tipo == LOGICO && ($3.tipo == ENTERO || $3.tipo == REAL)) {
                                    errorSemantico(ERR_EXDER_LOG, $2.nlin, $2.ncol, $2.lexema);
                                 }
                                 
                                 // Ref.cod + Expr.cod
                                 $$.cod = $1.cod + $3.cod;

                                 // si es REAL := ENTERO, hay que convertir
                                 if ($1.tipo == REAL && $3.tipo == ENTERO) {
                                    // mov Expr.dir A
                                    $$.cod += "mov " + to_string($3.dir) + " A\n";

                                    // itor
                                    $$.cod += "itor\n";

                                    // mov A Expr.dir
                                    $$.cod += "mov A " + to_string($3.dir) + "\n";
                                 }

                                 // calcular la direccion
                                 // mov Ref.dir A
                                 $$.cod += "mov " + to_string($1.dir) + " A\n";

                                 // addi #Ref.dbase
                                 $$.cod += "addi #" + to_string($1.dbase) + "\n";

                                 // guardar el valor de Expr en la direccion calculada en A
                                 // mov Expr.dir @A
                                 $$.cod += "mov " + to_string($3.dir) + " @A\n";
                              }
         | blq                {  tsActual = new TablaSimbolos(tsActual);   }
           SDec SInstr fblq   {  $$.cod = $3.cod + $4.cod; 
                                 tsActual = tsActual->getAmbitoAnterior();
                              }
         ;

Expr     : Expr obool Econj   {  // los operadores logicos solamente pueden utilizarse con valores logicos,
                                 // nunca con valores reales o enteros
                                 if ($1.tipo != LOGICO) {
                                    errorSemantico(ERR_EXIZQ_LOG, $2.nlin, $2.ncol, $2.lexema);
                                 }
                                 if ($3.tipo != LOGICO) {
                                    errorSemantico(ERR_EXDER_LOG, $2.nlin, $2.ncol, $2.lexema);
                                 }

                                 $$.cod = $1.cod + $3.cod;
                                 $$.dir = nuevaTemp($3.nlin, $3.ncol);
                                 $$.tipo = LOGICO;

                                 // mov Expr1.dir A
                                 $$.cod += "mov " + to_string($1.dir) + " A\n";

                                 // las expresiones logicas son 0 o 1
                                 // ori Econj.dir
                                 $$.cod += "ori " + to_string($3.dir) + "\n";

                                 // mov A ctemp
                                 $$.cod += "mov A " + to_string(ctemp) + "\n";
                              }
         | Econj              {  $$.cod = $1.cod;
                                 $$.dir = $1.dir;
                                 $$.tipo = $1.tipo;
                              }
         ;

Econj    : Econj ybool Ecomp  {  // los operadores logicos solamente pueden utilizarse con valores logicos,
                                 // nunca con valores reales o enteros
                                 if ($1.tipo != LOGICO) {
                                    errorSemantico(ERR_EXIZQ_LOG, $2.nlin, $2.ncol, $2.lexema);
                                 }
                                 if ($3.tipo != LOGICO) {
                                    errorSemantico(ERR_EXDER_LOG, $2.nlin, $2.ncol, $2.lexema);
                                 }

                                 $$.cod = $1.cod + $3.cod;
                                 $$.dir = nuevaTemp($3.nlin, $3.ncol);
                                 $$.tipo = LOGICO;

                                 // mov Expr1.dir A
                                 $$.cod += "mov " + to_string($1.dir) + " A\n";

                                 // las expresiones logicas son 0 o 1
                                 // andi Econj.dir
                                 $$.cod += "andi " + to_string($3.dir) + "\n";

                                 // mov A ctemp
                                 $$.cod += "mov A " + to_string(ctemp) + "\n";
                              }
         | Ecomp              {  $$.cod = $1.cod;
                                 $$.dir = $1.dir;
                                 $$.tipo = $1.tipo;
                              }
         ;

Ecomp    : Esimple oprel Esimple
                              {  // los operadores relacionales admiten expresiones reales o enteras
                                 if ($1.tipo != REAL && $1.tipo != ENTERO) {
                                    errorSemantico(ERR_EXIZQ_RE, $2.nlin, $2.ncol, $2.lexema);
                                 }
                                 if ($3.tipo != REAL && $3.tipo != ENTERO) {
                                    errorSemantico(ERR_EXDER_RE, $2.nlin, $2.ncol, $2.lexema);
                                 }

                                 $$.cod = $1.cod + $3.cod;
                                 $$.dir = nuevaTemp($3.nlin, $3.ncol);
                                 $$.tipo = LOGICO;
                                 
                                 // operacion
                                 string op = "";
                                 if (strcmp($2.lexema, "=") == 0) {
                                    op = "eql";
                                 } else if (strcmp($2.lexema, "<>") == 0) {
                                    op = "neq";
                                 } else if (strcmp($2.lexema, "<") == 0) {
                                    op = "lss";
                                 } else if (strcmp($2.lexema, "<=") == 0) {
                                    op = "leq";
                                 } else if (strcmp($2.lexema, ">") == 0) {
                                    op = "gtr";
                                 } else {    // >=
                                    op = "geq";
                                 }

                                 if ($1.tipo == $3.tipo) {  // ENTERO && ENTERO, REAL && REAL
                                    string ri = $1.tipo == ENTERO ? "i" : "r";
                                    
                                    // mov Esimple1.dir A
                                    $$.cod += "mov " + to_string($1.dir) + " A\n";

                                    // opri Esimple2.dir
                                    $$.cod += op + ri + to_string($3.dir) + "\n";

                                 } else if ($1.tipo == REAL && $3.tipo == ENTERO) {
                                    // mov Esimple2.dir A
                                    $$.cod += "mov " + to_string($3.dir) + " A\n";

                                    // itor
                                    $$.cod += "itor\n";

                                    // mov A ctemp
                                    $$.cod += "mov A " + to_string(ctemp) + "\n";

                                    // mov Esimple1.dir A
                                    $$.cod += "mov " + to_string($1.dir) + " A\n";

                                    // opr ctemp
                                    $$.cod += op + "r " + to_string(ctemp) + "\n";

                                 } else {    // ENTERO && REAL
                                    // mov Esimple1.dir A
                                    $$.cod += "mov " + to_string($1.dir) + " A\n";

                                    // itor
                                    $$.cod += "itor\n";

                                    // opr Esimple2.dir
                                    $$.cod += op + "r " + to_string($3.dir) + "\n";
                                 }

                                 // mov A ctemp
                                 $$.cod += "mov A " + to_string(ctemp) + "\n";
                              }
         | Esimple            {  $$.cod = $1.cod;
                                 $$.dir = $1.dir;
                                 $$.tipo = $1.tipo;
                              }
         ;

Esimple  : Esimple opas Term  {  // los operadores aritmeticos solamente pueden utilizarse con valores reales o enteros, 
                                 // nunca con valores logicos
                                 if ($1.tipo != REAL && $1.tipo != ENTERO) {
                                    errorSemantico(ERR_EXIZQ_RE, $2.nlin, $2.ncol, $2.lexema);
                                 }
                                 if ($3.tipo != REAL && $3.tipo != ENTERO) {
                                    errorSemantico(ERR_EXDER_RE, $2.nlin, $2.ncol, $2.lexema);
                                 }
                                 
                                 $$.cod = $1.cod + $3.cod;
                                 $$.dir = nuevaTemp($3.nlin, $3.ncol);
                                 $$.tipo = ($1.tipo == ENTERO && $3.tipo == ENTERO) ? ENTERO : REAL;
                                 
                                 // operacion
                                 string op = (strcmp($2.lexema, "+") == 0) ? "add" : "sub";
                                 
                                 if ($1.tipo == $3.tipo) {  // ENTERO && ENTERO, REAL && REAL
                                    string ri = $1.tipo == ENTERO ? "i" : "r";
                                    
                                    // mov Esimple1.dir A
                                    $$.cod += "mov " + to_string($1.dir) + " A\n";

                                    // opri Term.dir
                                    $$.cod += op + ri + to_string($3.dir) + "\n";

                                 } else if ($1.tipo == REAL && $3.tipo == ENTERO) {
                                    // mov Term.dir A
                                    $$.cod += "mov " + to_string($3.dir) + " A\n";

                                    // itor
                                    $$.cod += "itor\n";

                                    // mov A ctemp
                                    $$.cod += "mov A " + to_string(ctemp) + "\n";

                                    // mov Esimple1.dir A
                                    $$.cod += "mov " + to_string($1.dir) + " A\n";

                                    // opr ctemp
                                    $$.cod += op + "r " + to_string(ctemp) + "\n";

                                 } else {    // ENTERO && REAL
                                    // mov Esimple1.dir A
                                    $$.cod += "mov " + to_string($1.dir) + " A\n";

                                    // itor
                                    $$.cod += "itor\n";

                                    // opr Term.dir
                                    $$.cod += op + "r " + to_string($3.dir) + "\n";
                                 }

                                 // mov A ctemp
                                 $$.cod += "mov A " + to_string(ctemp) + "\n";
                              }
         | Term               {  $$.cod = $1.cod;
                                 $$.dir = $1.dir;
                                 $$.tipo = $1.tipo;
                              }
         | opas Term          {  // los operadores aritmeticos solamente pueden utilizarse con valores reales o enteros, 
                                 // nunca con valores logicos
                                 if ($2.tipo != REAL && $2.tipo != ENTERO) {
                                    errorSemantico(ERR_EXDER_RE, $1.nlin, $1.ncol, $1.lexema);
                                 }

                                 $$.cod = $2.cod;
                                 $$.dir = nuevaTemp($2.nlin, $2.ncol);
                                 $$.tipo = $2.tipo;

                                 // si operacion es '-', hay que cambiar el signo
                                 if(strcmp($1.lexema, "+") == 0) {
                                    // mov Term.dir ctemp
                                    $$.cod += "mov " + to_string($2.dir) + " " + to_string(ctemp) + "\n";

                                 } else {
                                    // mov Term.dir A
                                    $$.cod += "mov " + to_string($2.dir) +" A\n";
                                          
                                    // muli #-1
                                    $$.cod += "muli #-1\n";
                                    
                                    // mov A ctemp
                                    $$.cod += "mov A " + to_string(ctemp) + "\n";
                                 }
                              }
         ;

Term     : Term opmd Factor   {  // los operadores aritmeticos solamente pueden utilizarse con valores reales o enteros, 
                                 // nunca con valores logicos
                                 if ($1.tipo != REAL && $1.tipo != ENTERO) {
                                    errorSemantico(ERR_EXIZQ_RE, $2.nlin, $2.ncol, $2.lexema);
                                 }
                                 if ($3.tipo != REAL && $3.tipo != ENTERO) {
                                    errorSemantico(ERR_EXDER_RE, $2.nlin, $2.ncol, $2.lexema);
                                 }

                                 $$.cod = $1.cod + $3.cod;
                                 $$.dir = nuevaTemp($3.nlin, $3.ncol);
                                 $$.tipo = ($1.tipo == ENTERO && $3.tipo == ENTERO) ? ENTERO : REAL;
                                 
                                 // operacion
                                 string op = (strcmp($2.lexema, "*") == 0) ? "mul" : "div";
                                 
                                 if ($1.tipo == $3.tipo) {  // ENTERO && ENTERO, REAL && REAL
                                    string ri = $1.tipo == ENTERO ? "i" : "r";
                                    
                                    // mov Term1.dir A
                                    $$.cod += "mov " + to_string($1.dir) + " A\n";

                                    // opri Factor.dir
                                    $$.cod += op + ri + to_string($3.dir) + "\n";

                                 } else if ($1.tipo == REAL && $3.tipo == ENTERO) {
                                    // mov Factor.dir A
                                    $$.cod += "mov " + to_string($3.dir) + " A\n";

                                    // itor
                                    $$.cod += "itor\n";

                                    // mov A ctemp
                                    $$.cod += "mov A " + to_string(ctemp) + "\n";

                                    // mov Term1.dir A
                                    $$.cod += "mov " + to_string($1.dir) + " A\n";

                                    // opr ctemp
                                    $$.cod += op + "r " + to_string(ctemp) + "\n";

                                 } else {    // ENTERO && REAL
                                    // mov Term1.dir A
                                    $$.cod += "mov " + to_string($1.dir) + " A\n";

                                    // itor
                                    $$.cod += "itor\n";

                                    // opr Factor.dir
                                    $$.cod += op + "r " + to_string($3.dir) + "\n";
                                 }

                                 // mov A ctemp
                                 $$.cod += "mov A " + to_string(ctemp) + "\n";
                              }
         | Factor             {  $$.cod = $1.cod;
                                 $$.dir = $1.dir;
                                 $$.tipo = $1.tipo;
                              }
         ;

Factor   : Ref                {  // si el tipo de Ref que nos llega es array, es decir no es un tipo basico,
                                 // entonces se necesitan corchetes
                                 if ((ttipos->tipos)[$1.tipo].clase == ARRAY) {
                                    errorSemantico(ERR_FALTAN, $1.nlin, $1.ncol, $1.lexema);
                                 }

                                 $$.cod = $1.cod;
                                 $$.dir = nuevaTemp($1.nlin, $1.ncol);
                                 $$.tipo = $1.tipo;

                                 // mov Ref.dir A
                                 $$.cod += "mov " + to_string($1.dir) + " A\n";

                                 // addi #Ref.dbase
                                 $$.cod += "addi #" + to_string($1.dbase) + "\n";

                                 // mov @A ctemp
                                 $$.cod += "mov @A " + to_string(ctemp) + "\n";
                              }
         | nentero            {  $$.tipo = ENTERO; 

                                 // si no hay espacio para la variable, salta el error 
                                 // (lexema se necesita para el mensaje de error) 
                                 ctemp = nuevaTemp($1.nlin, $1.ncol); 
                                 
                                 $$.dir = ctemp;
                                 $$.cod = "mov #" + string($1.lexema) + " " + to_string(ctemp) + "\n";
                              }
         | nreal              {  $$.tipo = REAL; 

                                 // si no hay espacio para la variable, salta el error 
                                 // (lexema se necesita para el mensaje de error) 
                                 ctemp = nuevaTemp($1.nlin, $1.ncol); 
                                 
                                 $$.dir = ctemp;
                                 $$.cod = "mov $" + string($1.lexema) + " " + to_string(ctemp) + "\n";
                              }
         | pari Expr pard     {  $$.cod = $2.cod;
                                 $$.dir = $2.dir;
                                 $$.tipo = $2.tipo;
                              }
         | nobool Factor      {  if ($2.tipo != LOGICO) {
                                    errorSemantico(ERR_EXDER_LOG, $1.nlin, $1.ncol, $1.lexema);
                                 }

                                 $$.cod = $2.cod;
                                 $$.dir = nuevaTemp($2.nlin, $2.ncol);
                                 $$.tipo = LOGICO;

                                 // mov Factor1.dir A
                                 $$.cod += "mov " + to_string($2.dir) + " A\n";
                                 
                                 // Factor va a ser 1 o 0
                                 // noti
                                 $$.cod += "noti\n";

                                 // mov A ctemp
                                 $$.cod += "mov A " + to_string(ctemp) + "\n";
                              }
         | cierto             {  $$.tipo = LOGICO;
                                 $$.dir = nuevaTemp($1.nlin, $1.ncol);

                                 // true es 1
                                 $$.cod = "mov #1 " + to_string(ctemp) + "\n";
                              }
         | falso              {  $$.tipo = LOGICO;
                                 $$.dir = nuevaTemp($1.nlin, $1.ncol);

                                 // false es 0
                                 $$.cod = "mov #0 " + to_string(ctemp) + "\n"; 
                              }
         ;

Ref      : id                 {  Simbolo *simbolo = tsActual->searchSymb($1.lexema);
                                 if (simbolo == nullptr) {
                                    errorSemantico(ERR_NODECL, $1.nlin, $1.ncol, $1.lexema);
                                 }

                                 // si no hay espacio para la variable, salta el error 
                                 // (lexema se necesita para el mensaje de error) 
                                 ctemp = nuevaTemp($1.nlin, $1.ncol);    

                                 $$.dir = ctemp;
                                 $$.cod = "mov #0 " + to_string(ctemp) + "\n";
                                 $$.tipo = simbolo->tipo;

                                 // si id no es de tipo array, simbolo->dir es 0
                                 $$.dbase = simbolo->dir;
                              
                                 $$.lexema = $1.lexema;
                                 $$.nlin = $1.nlin;
                                 $$.ncol = $1.ncol;
                              }
         | Ref cori           {  if (!esArray($1.tipo)) {
                                    if(strcmp($1.lexema, "]") == 0) {
                                       errorSemantico(ERR_SOBRAN, $2.nlin, $2.ncol, $2.lexema); 
                                    } else {
                                       errorSemantico(ERR_SOBRAN, $1.nlin, $1.ncol, $1.lexema);
                                    }
                                 }
                              }
           Esimple cord       {  // Indice solo puede ser un numero entero
                                 if ($4.tipo != ENTERO) {
                                    errorSemantico(ERR_INDICE_ENTERO, $4.nlin, $4.ncol, $4.lexema);
                                 }

                                 // desreferenciar
                                 $$.tipo = (ttipos->tipos)[$1.tipo].tipoBase;
                                 $$.dbase = $1.dbase;

                                 // si no hay espacio para la variable, salta el error 
                                 // (lexema se necesita para el mensaje de error) 
                                 ctemp = nuevaTemp($2.nlin, $2.ncol);    

                                 $$.dir = ctemp;

                                 // Ref1.cod + Esimple.cod
                                 $$.cod = $1.cod + $4.cod;

                                 // A = Ref1.dir * Ref1.tam + Esimple.dir
                                 // mov Ref1.dir A
                                 $$.cod += "mov " + to_string($1.dir) + " A\n";
                                 // muli #Ref1.tam
                                 $$.cod += "muli #" + to_string((ttipos->tipos)[$1.tipo].tamanyo) + "\n";
                                 // addi Esimple.dir
                                 $$.cod += "addi " + to_string($4.dir) + "\n";
                                 // mov A ctemp
                                 $$.cod += "mov A " + to_string(ctemp) + "\n";

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

unsigned int nuevaTemp(int nlin, int ncol) {
   if (ctemp == MAX_DIR_TEMP) {
      errorSemantico(ERR_MAXTMP, nlin, ncol, "");
   }
   return ++ctemp;
}

unsigned int nuevaVar(char *lexema, int nlin, int ncol) {
   if (cvar == MAX_DIR_VAR) {
      errorSemantico(ERR_NOCABE, nlin, ncol, lexema);
   }
   return ++cvar;
}

unsigned int nuevaEtiqueta(void) {
   return ++cetiq;
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

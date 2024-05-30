/*##########################################################
#                                                          #
#   Autor: Natallia Tsuranava                              #
#   PL 2022/23                                             #
#   Modificacion: comun.h (ejemploHT)                      #
#                                                          #
##########################################################*/

#ifndef _comun_
#define _comun_

#include <string>

using namespace std;

typedef struct {
   char *lexema;
   int nlin,ncol;
   int tipo;
   int dir;
   int dbase;
   string cod;
} MITIPO;

#define YYSTYPE MITIPO

//==========================================================
// PARA ERRORES SEMANTICOS
//==========================================================
#define ERRLEXICO				1
#define ERRSINT				2
#define ERREOF					3

#define ERR_YADECL			4
#define ERR_NODECL			5
#define ERR_DIM				6
#define ERR_FALTAN			7
#define ERR_SOBRAN			8
#define ERR_INDICE_ENTERO  9
#define ERR_EXP_LOG			10
#define ERR_EXDER_LOG		11
#define ERR_EXDER_ENT		12
#define ERR_EXDER_RE			13
#define ERR_EXIZQ_LOG		14
#define ERR_EXIZQ_RE			15

#define ERR_NOCABE			16
#define ERR_MAXTMP			17

//==========================================================
// DECLARAR FUNCIONES
//==========================================================
void msgError (int nerror, int nlin, int ncol, const char *s);

void errorSemantico (int nerror, int nlin, int ncol, const char *s);

#endif
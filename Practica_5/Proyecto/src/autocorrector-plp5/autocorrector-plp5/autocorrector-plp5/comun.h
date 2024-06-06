/*----------------------- comun.h -----------------------------*/

/* fichero con definciones comunes para los ficheros .l y .y */

typedef struct {
   char *lexema;
   int nlin,ncol;
   int tipo;
   int dir;
   int dbase;
   string cod;
   int tamanyo;
} MITIPO;

#define YYSTYPE MITIPO

#define ERRLEXICO       1
#define ERRSINT         2
#define ERREOF          3
#define ERRLEXEOF       4

#define ERRYADECL       5
#define ERRNODECL       6
#define ERRDIM          7
#define ERRFALTAN       8
#define ERRSOBRAN       9
#define ERR_NOENTERO    10
#define ERR_NOCABE      11
#define ERR_MAXTMP      12

void msgError(int nerror,int nlin,int ncol,const char *s);

void errorSemantico(int nerror,char *lexema,int fila,int columna);
/*----------------------- comun.h -----------------------------*/

/* fichero con definciones comunes para los ficheros .l y .y */

typedef struct {
   char *lexema;
   int nlin,ncol;
   int tipo;
   string cod;
} MITIPO;

#define YYSTYPE MITIPO


#define ERRLEXICO       1
#define ERRSINT         2
#define ERREOF          3
#define ERRLEXEOF       4

#define ERRYADECL       1
#define ERRNOMFUNC      2
#define ERRNOSIMPLE     3
#define ERRNODECL       4
#define ERRTIPOS        5
#define ERRNOENTEROIZQ  6
#define ERRNOENTERODER  7
#define ERRRANGO        8

void msgError(int nerror,int nlin,int ncol,const char *s);

void errorSemantico(int nerror,char *lexema,int fila,int columna);
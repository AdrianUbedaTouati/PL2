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

#define ERRYADECL       5
#define ERRNOMFUNC      6
#define ERRNOSIMPLE     7
#define ERRNODECL       8
#define ERRTIPOS        9
#define ERRNOENTEROIZQ  10
#define ERRNOENTERODER  11
#define ERRRANGO        12

void msgError(int nerror,int nlin,int ncol,const char *s);

void errorSemantico(int nerror,char *lexema,int fila,int columna);
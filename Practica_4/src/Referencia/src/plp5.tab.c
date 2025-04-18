/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.5.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 28 "plp5.y"


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



#line 122 "plp5.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_PLP5_TAB_H_INCLUDED
# define YY_YY_PLP5_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    algoritmo = 258,
    falgoritmo = 259,
    var = 260,
    fvar = 261,
    entero = 262,
    real = 263,
    logico = 264,
    tabla = 265,
    de = 266,
    escribe = 267,
    lee = 268,
    si = 269,
    entonces = 270,
    sino = 271,
    mientras = 272,
    hacer = 273,
    repetir = 274,
    hasta = 275,
    blq = 276,
    fblq = 277,
    cierto = 278,
    falso = 279,
    id = 280,
    nentero = 281,
    nreal = 282,
    coma = 283,
    pyc = 284,
    dospto = 285,
    pari = 286,
    pard = 287,
    oprel = 288,
    opas = 289,
    opmd = 290,
    opasig = 291,
    cori = 292,
    cord = 293,
    ybool = 294,
    obool = 295,
    nobool = 296
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PLP5_TAB_H_INCLUDED  */



#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))

/* Stored state numbers (used for stacks). */
typedef yytype_int8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   93

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  42
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  23
/* YYNRULES -- Number of rules.  */
#define YYNRULES  50
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  96

#define YYUNDEFTOK  2
#define YYMAXUTOK   296


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    83,    83,    95,    96,    99,   103,   103,   136,   137,
     140,   140,   170,   173,   174,   175,   176,   184,   184,   188,
     188,   194,   232,   272,   294,   323,   349,   368,   416,   416,
     422,   445,   451,   474,   480,   548,   554,   609,   613,   641,
     696,   702,   721,   730,   739,   743,   761,   767,   775,   795,
     795
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "algoritmo", "falgoritmo", "var", "fvar",
  "entero", "real", "logico", "tabla", "de", "escribe", "lee", "si",
  "entonces", "sino", "mientras", "hacer", "repetir", "hasta", "blq",
  "fblq", "cierto", "falso", "id", "nentero", "nreal", "coma", "pyc",
  "dospto", "pari", "pard", "oprel", "opas", "opmd", "opasig", "cori",
  "cord", "ybool", "obool", "nobool", "$accept", "S", "SDec", "Dec",
  "DVar", "@1", "MDVar", "LId", "@2", "Tipo", "SInstr", "@3", "@4",
  "Instr", "$@5", "Expr", "Econj", "Ecomp", "Esimple", "Term", "Factor",
  "Ref", "$@6", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296
};
# endif

#define YYPACT_NINF (-43)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int8 yypact[] =
{
       4,   -18,    28,    22,   -43,    50,    59,   -43,   -43,   -43,
     -43,   -43,    36,    59,    33,     0,     2,    60,    59,    64,
      47,   -43,   -43,    15,    48,    15,    15,     2,   -43,   -43,
     -43,    14,    59,   -43,   -43,   -43,     2,   -43,   -43,   -43,
     -43,    15,    34,    34,    37,    39,   -43,     3,    41,   -43,
      42,    42,   -10,    -5,    61,    50,    15,   -43,   -43,    52,
     -43,   -15,    41,   -43,    15,    15,    15,    34,    34,     2,
       2,    15,   -43,    37,    15,    57,    54,   -43,    39,   -43,
      51,    41,   -43,    68,   -43,    37,    23,   -12,   -43,   -43,
       2,   -43,   -43,    52,   -43,   -43
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     1,     4,     0,    19,     3,    13,
      14,    15,     0,     9,     0,     0,     0,     0,     9,     0,
       0,     2,    17,     0,     0,     0,     0,     0,    28,    48,
      20,     0,     0,     8,     5,     6,     0,    46,    47,    42,
      43,     0,     0,     0,    21,    31,    33,    35,    37,    40,
      41,    22,     0,     0,     0,     4,     0,    49,    16,    12,
      18,     0,    38,    45,     0,     0,     0,     0,     0,     0,
       0,     0,    19,    27,     0,     0,     0,    44,    30,    32,
      34,    36,    39,    23,    25,    26,     0,     0,    10,     7,
       0,    29,    50,    12,    24,    11
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -43,   -43,    31,   -43,    81,   -43,    70,    -4,   -43,    58,
      19,   -43,   -43,   -26,   -43,   -23,    29,    27,   -42,   -36,
     -34,   -16,   -43
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     2,     7,     8,    18,    59,    19,    76,    93,    14,
      15,    36,    16,    30,    55,    44,    45,    46,    47,    48,
      49,    50,    74
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      31,    54,    52,    53,    21,    69,    62,     1,    51,    63,
      60,    31,     3,    70,    23,    24,    25,    77,    61,    26,
      31,    27,    67,    28,    80,    64,    92,    29,     4,    22,
      64,    81,    87,    73,    82,    64,    66,    67,    37,    38,
      29,    39,    40,    83,    84,    91,    41,     5,    85,    42,
      56,    57,    22,    31,    31,     6,    43,    37,    38,    29,
      39,    40,    17,    20,    94,    41,     9,    10,    11,    12,
      34,    32,    35,    29,    31,    43,    68,    64,    65,    57,
      75,    71,    88,    89,    90,    67,    72,    13,    33,    95,
      58,    86,    79,    78
};

static const yytype_int8 yycheck[] =
{
      16,    27,    25,    26,     4,    15,    42,     3,    24,    43,
      36,    27,    30,    18,    12,    13,    14,    32,    41,    17,
      36,    19,    34,    21,    66,    40,    38,    25,     0,    29,
      40,    67,    74,    56,    68,    40,    33,    34,    23,    24,
      25,    26,    27,    69,    70,    22,    31,    25,    71,    34,
      36,    37,    29,    69,    70,     5,    41,    23,    24,    25,
      26,    27,    26,    30,    90,    31,     7,     8,     9,    10,
       6,    11,    25,    25,    90,    41,    35,    40,    39,    37,
      28,    20,    25,    29,    16,    34,    55,     6,    18,    93,
      32,    72,    65,    64
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,    43,    30,     0,    25,     5,    44,    45,     7,
       8,     9,    10,    46,    51,    52,    54,    26,    46,    48,
      30,     4,    29,    12,    13,    14,    17,    19,    21,    25,
      55,    63,    11,    48,     6,    25,    53,    23,    24,    26,
      27,    31,    34,    41,    57,    58,    59,    60,    61,    62,
      63,    63,    57,    57,    55,    56,    36,    37,    51,    47,
      55,    57,    61,    62,    40,    39,    33,    34,    35,    15,
      18,    20,    44,    57,    64,    28,    49,    32,    58,    59,
      60,    61,    62,    55,    55,    57,    52,    60,    25,    29,
      16,    22,    38,    50,    55,    49
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    42,    43,    44,    44,    45,    47,    46,    48,    48,
      50,    49,    49,    51,    51,    51,    51,    53,    52,    54,
      52,    55,    55,    55,    55,    55,    55,    55,    56,    55,
      57,    57,    58,    58,    59,    59,    60,    60,    60,    61,
      61,    62,    62,    62,    62,    62,    62,    62,    63,    64,
      63
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     6,     1,     0,     4,     0,     6,     2,     0,
       0,     4,     0,     1,     1,     1,     4,     0,     4,     0,
       2,     2,     2,     4,     6,     4,     4,     3,     0,     5,
       3,     1,     3,     1,     3,     1,     3,     1,     2,     3,
       1,     1,     1,     1,     3,     2,     1,     1,     1,     0,
       5
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[+yyssp[yyi + 1 - yynrhs]],
                       &yyvsp[(yyi + 1) - (yynrhs)]
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
#  else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            else
              goto append;

          append:
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                yy_state_t *yyssp, int yytoken)
{
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Actual size of YYARG. */
  int yycount = 0;
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[+*yyssp];
      YYPTRDIFF_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
      yysize = yysize0;
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYPTRDIFF_T yysize1
                    = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    /* Don't count the "%s"s in the final size, but reserve room for
       the terminator.  */
    YYPTRDIFF_T yysize1 = yysize + (yystrlen (yyformat) - 2 * yycount) + 1;
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss;
    yy_state_t *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYPTRDIFF_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
# undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2:
#line 84 "plp5.y"
                              {  /* comprobar que después del programa no hay ningún token más */
                                 int tk = yylex();
                                 if (tk == 0) {
                                    // SDec.cod | SInstr.cod | halt (detener el programa) 
                                    cout << yyvsp[-2].cod << yyvsp[-1].cod << "halt\n";
                                 } else {
                                    yyerror("");
                                 }
                              }
#line 1460 "plp5.tab.c"
    break;

  case 3:
#line 95 "plp5.y"
                              {  yyval.cod = yyvsp[0].cod;  }
#line 1466 "plp5.tab.c"
    break;

  case 4:
#line 96 "plp5.y"
                              {  yyval.cod = "";   }
#line 1472 "plp5.tab.c"
    break;

  case 5:
#line 100 "plp5.y"
                              {  yyval.cod = yyvsp[-2].cod + yyvsp[-1].cod;  }
#line 1478 "plp5.tab.c"
    break;

  case 6:
#line 103 "plp5.y"
                              {  // Para crear nuevo simbolo necesitamos:
                                 // nombre = id, tipo, dir, tam
                                 Simbolo *simbolo = new Simbolo();
                                 simbolo->nombre = yyvsp[0].lexema;
                                 simbolo->dir = nuevaVar(yyvsp[0].lexema, yyvsp[0].nlin, yyvsp[0].ncol);

                                 // Bucle para obtener el tamanyo
                                 yyval.tipo = yyvsp[-2].tipo;
                                 simbolo->tam = (ttipos->tipos)[yyvsp[-2].tipo].tamanyo;
                                 while ((ttipos->tipos)[yyval.tipo].clase != TIPOBASICO) {
                                    // quitar la dimension
                                    yyval.tipo = (ttipos->tipos)[yyval.tipo].tipoBase;

                                    simbolo->tam *= (ttipos->tipos)[yyval.tipo].tamanyo;
                                 }
                                 simbolo->tipo = yyvsp[-2].tipo;

                                 // Comprobar el espacio para todo el array
                                 if (cvar + simbolo->tam >= MAX_DIR_VAR) {
                                    errorSemantico(ERR_NOCABE, 0, 0, yyvsp[0].lexema);
                                 }
                                 cvar += simbolo->tam;      // actualizar contador
                                 
                                 // comprueba si el simbolo se repite en el ambito
                                 // si no se repite, se anade a tsActual
                                 if (!tsActual->newSymb(*simbolo)) {
                                    errorSemantico(ERR_YADECL, yyvsp[0].nlin, yyvsp[0].ncol, yyvsp[0].lexema);
                                 }

                              }
#line 1513 "plp5.tab.c"
    break;

  case 8:
#line 136 "plp5.y"
                              {  yyval.cod = yyvsp[-1].cod + yyvsp[0].cod;  }
#line 1519 "plp5.tab.c"
    break;

  case 9:
#line 137 "plp5.y"
                              {  yyval.cod = "";   }
#line 1525 "plp5.tab.c"
    break;

  case 10:
#line 140 "plp5.y"
                              {  // Para crear nuevo simbolo necesitamos:
                                 // nombre = id, tipo, dir, tam
                                 Simbolo *simbolo = new Simbolo();
                                 simbolo->nombre = yyvsp[0].lexema;
                                 simbolo->dir = nuevaVar(yyvsp[0].lexema, yyvsp[0].nlin, yyvsp[0].ncol);

                                 // Bucle para obtener el tamanyo
                                 yyval.tipo = yyvsp[-2].tipo;
                                 simbolo->tam = (ttipos->tipos)[yyvsp[-2].tipo].tamanyo;
                                 while ((ttipos->tipos)[yyval.tipo].clase != TIPOBASICO) {
                                    // quitar la dimension
                                    yyval.tipo = (ttipos->tipos)[yyval.tipo].tipoBase;

                                    simbolo->tam *= (ttipos->tipos)[yyval.tipo].tamanyo;
                                 }
                                 simbolo->tipo = yyvsp[-2].tipo;

                                 // Comprobar el espacio para todo el array
                                 if (cvar + simbolo->tam >= MAX_DIR_VAR) {
                                    errorSemantico(ERR_NOCABE, 0, 0, yyvsp[0].lexema);
                                 }
                                 cvar += simbolo->tam;      // actualizar contador

                                 // comprueba si el simbolo se repite en el ambito
                                 // si no se repite, se anade a tsActual
                                 if (!tsActual->newSymb(*simbolo)) {
                                    errorSemantico(ERR_YADECL, yyvsp[0].nlin, yyvsp[0].ncol, yyvsp[0].lexema);
                                 }
                              }
#line 1559 "plp5.tab.c"
    break;

  case 12:
#line 170 "plp5.y"
                              {  yyval.cod = "";   }
#line 1565 "plp5.tab.c"
    break;

  case 13:
#line 173 "plp5.y"
                              {  yyval.tipo = ENTERO; }
#line 1571 "plp5.tab.c"
    break;

  case 14:
#line 174 "plp5.y"
                              {  yyval.tipo = REAL;   }
#line 1577 "plp5.tab.c"
    break;

  case 15:
#line 175 "plp5.y"
                              {  yyval.tipo = LOGICO; }
#line 1583 "plp5.tab.c"
    break;

  case 16:
#line 177 "plp5.y"
                              {  if (stoi(yyvsp[-2].lexema) <= 0) {
                                    errorSemantico(ERR_DIM, yyvsp[-2].nlin, yyvsp[-2].ncol, yyvsp[-2].lexema); 
                                 }
                                 yyval.tipo = ttipos->nuevoTipoArray(stoi(yyvsp[-2].lexema), yyvsp[0].tipo);
                              }
#line 1593 "plp5.tab.c"
    break;

  case 17:
#line 184 "plp5.y"
                              {  yyval.nlin = ctemp;  }
#line 1599 "plp5.tab.c"
    break;

  case 18:
#line 185 "plp5.y"
                              {  yyval.cod = yyvsp[-3].cod + yyvsp[0].cod;  
                                 ctemp = yyvsp[-3].nlin;
                              }
#line 1607 "plp5.tab.c"
    break;

  case 19:
#line 188 "plp5.y"
                              {  yyval.nlin = ctemp;  }
#line 1613 "plp5.tab.c"
    break;

  case 20:
#line 189 "plp5.y"
                              {  yyval.cod = yyvsp[0].cod;
                                 ctemp = yyvsp[-1].nlin;
                              }
#line 1621 "plp5.tab.c"
    break;

  case 21:
#line 194 "plp5.y"
                              {  yyval.cod = yyvsp[0].cod;

                                 if (yyvsp[0].tipo == LOGICO) {
                                    int etq1 = nuevaEtiqueta();   // etiqueta si la expr es falsa
                                    int etq2 = nuevaEtiqueta();   // etiqueta de salida
                                    
                                    // El valor de A debe ser entero
                                    // mov Expr.dir A
                                    yyval.cod += "mov " + to_string(yyvsp[0].dir) + " A\n";

                                    // Salta a la posicion de programa indicada por 
                                    // el valor L1 si en A hay un cero (falso)
                                    // jz L1 
                                    yyval.cod += "jz L" + to_string(etq1) + "\n";

                                    // se escribira una ‘c’ minuscula si el valor es cierto
                                    yyval.cod += "wrc #" + to_string(static_cast<int>('c')) + "\n";
                                    
                                    // saltar a la etiqueta de salida
                                    yyval.cod += "jmp L" + to_string(etq2) + "\n";

                                    // la etiqueta de falso
                                    yyval.cod += "L" + to_string(etq1);

                                    // se escribira una ‘f’ minuscula si el valor es falso
                                    yyval.cod += " wrc #" + to_string(static_cast<int>('f')) + "\n";

                                    // la etiqueta de salida
                                    yyval.cod += "L" + to_string(etq2) + " ";
                                 } else {
                                    // si el tipo es real tenemos wrr, sino wri
                                    string ri = (yyvsp[0].tipo == REAL) ? "r" : "i";
                                    
                                    yyval.cod += "wr" + ri + " " + to_string(yyvsp[0].dir) + "\n";
                                 }

                                 yyval.cod += "wrl\n";
                              }
#line 1664 "plp5.tab.c"
    break;

  case 22:
#line 232 "plp5.y"
                              {  // si el tipo de Ref que nos llega es array, es decir no es un tipo basico,
                                 // entonces se necesitan corchetes
                                 if ((ttipos->tipos)[yyvsp[0].tipo].clase == ARRAY) {
                                    errorSemantico(ERR_FALTAN, yyvsp[0].nlin, yyvsp[0].ncol, yyvsp[0].lexema);
                                 }
                                 
                                 yyval.cod = yyvsp[0].cod;

                                 if (yyvsp[0].tipo == LOGICO) {
                                    //  Al leer del teclado una variable logica, 
                                    // si se lee el caracter ‘c’ se entendera que el valor es cierto, 
                                    // y si se lee cualquier otro caracter se entendera que es falso
                                    
                                    // Lee un caracter de la consola y carga su codigo ASCII en destino
                                    yyval.cod += "rdc A\n";

                                    // si en A esta 'c', A se carga con 1
                                    yyval.cod += "eqli #" + to_string(static_cast<int>('c')) + "\n";

                                    // movemos 1 o 0 a la temporal
                                    yyval.cod += "mov A " + to_string(nuevaTemp(yyvsp[-1].nlin, yyvsp[-1].ncol)) + "\n";
                                    
                                    // calcular la direccion
                                    yyval.cod += "mov " + to_string(yyvsp[0].dir) + " A\n";
                                    yyval.cod += "addi #" + to_string(yyvsp[0].dbase) + "\n";

                                    // guardar ctemp en la direccion calculada en A
                                    yyval.cod += "mov " + to_string(ctemp) + " @A\n";
                                 } else {
                                    // calcular la direccion
                                    yyval.cod += "mov " + to_string(yyvsp[0].dir) + " A\n";
                                    yyval.cod += "addi #" + to_string(yyvsp[0].dbase) + "\n";

                                    // si el tipo es real tenemos rdr, sino rdi
                                    string ri = (yyvsp[0].tipo == REAL) ? "r" : "i";

                                    // Lee un numero de la consola en la direccion calculada en A
                                    yyval.cod += "rd" + ri + " @A\n";
                                 }
                              }
#line 1709 "plp5.tab.c"
    break;

  case 23:
#line 273 "plp5.y"
                              {  if (yyvsp[-2].tipo != LOGICO) {
                                    errorSemantico(ERR_EXP_LOG, yyvsp[-3].nlin, yyvsp[-3].ncol, yyvsp[-3].lexema);
                                 }
                                 
                                 // Expr.cod
                                 yyval.cod = yyvsp[-2].cod;

                                 int etq = nuevaEtiqueta();    // etiqueta si expr es falsa

                                 // mov Expr.dir A (debe ser un valor entero)
                                 yyval.cod += "mov " + to_string(yyvsp[-2].dir) + " A\n";

                                 // jz L1 (saltar si vale 0)
                                 yyval.cod += "jz L" + to_string(etq) +"\n";

                                 // Instr1.cod
                                 yyval.cod += yyvsp[0].cod;

                                 // Etq a la siguiente instruccion
                                 yyval.cod += "L" + to_string(etq) + " ";
                              }
#line 1735 "plp5.tab.c"
    break;

  case 24:
#line 295 "plp5.y"
                              {  if (yyvsp[-4].tipo != LOGICO) {
                                    errorSemantico(ERR_EXP_LOG, yyvsp[-5].nlin, yyvsp[-5].ncol, yyvsp[-5].lexema);
                                 }

                                 // Expr.cod
                                 yyval.cod = yyvsp[-4].cod;

                                 int etq1 = nuevaEtiqueta();   // etiqueta si la expr es falsa
                                 int etq2 = nuevaEtiqueta();   // etiqueta de salida

                                 // mov Expr.dir A
                                 yyval.cod += "mov " + to_string(yyvsp[-4].dir) + " A\n";

                                 // jz L1
                                 yyval.cod += "jz L" + to_string(etq1) + "\n";

                                 // Instr1.cod
                                 yyval.cod += yyvsp[-2].cod;

                                 // jmp L2
                                 yyval.cod += "jmp L" + to_string(etq2) + "\n";

                                 // L1 Instr2.cod
                                 yyval.cod += "L" + to_string(etq1) + " " + yyvsp[0].cod;

                                 // L2 (siguiente instr)
                                 yyval.cod += "L" + to_string(etq2) + " ";
                              }
#line 1768 "plp5.tab.c"
    break;

  case 25:
#line 324 "plp5.y"
                              {  if (yyvsp[-2].tipo != LOGICO) {
                                    errorSemantico(ERR_EXP_LOG, yyvsp[-3].nlin, yyvsp[-3].ncol, yyvsp[-3].lexema);
                                 }

                                 int etq1 = nuevaEtiqueta();
                                 int etq2 = nuevaEtiqueta();

                                 // L1 Expr.cod
                                 yyval.cod = "L" + to_string(etq1) + " " + yyvsp[-2].cod;

                                 // mov Expr.dir A
                                 yyval.cod += "mov " + to_string(yyvsp[-2].dir) + " A\n";

                                 // jz L2
                                 yyval.cod += "jz L" + to_string(etq2) + "\n";

                                 // Instr1.cod
                                 yyval.cod += yyvsp[0].cod;

                                 // jmp L1
                                 yyval.cod += "jmp L" + to_string(etq1) + "\n";

                                 // L2 (siguiente inst)
                                 yyval.cod += "L" + to_string(etq2) + " ";
                              }
#line 1798 "plp5.tab.c"
    break;

  case 26:
#line 350 "plp5.y"
                              {  if (yyvsp[0].tipo != LOGICO) {
                                    errorSemantico(ERR_EXP_LOG, yyvsp[-1].nlin, yyvsp[-1].ncol, yyvsp[-1].lexema);
                                 }

                                 int etq = nuevaEtiqueta();    // etiqueta de bucle

                                 // L1 Instr1.cod
                                 yyval.cod = "L" + to_string(etq) + " " + yyvsp[-2].cod;

                                 // Expr.cod
                                 yyval.cod += yyvsp[0].cod;

                                 // mov Expr.dir A
                                 yyval.cod += "mov " + to_string(yyvsp[0].dir) + " A\n";

                                 // jz L1
                                 yyval.cod += "jz L" + to_string(etq) + "\n";                                 
                              }
#line 1821 "plp5.tab.c"
    break;

  case 27:
#line 368 "plp5.y"
                              {  // si el tipo de Ref que nos llega es array, es decir no es un tipo basico,
                                 // entonces se necesitan corchetes
                                 if ((ttipos->tipos)[yyvsp[-2].tipo].clase == ARRAY) {
                                    errorSemantico(ERR_FALTAN, yyvsp[-2].nlin, yyvsp[-2].ncol, yyvsp[-2].lexema);
                                 }

                                 // no esta permitido asignar un valor real a una variable entera
                                 // no se permite asignar valores logicos a variables enteras
                                 if (yyvsp[-2].tipo == ENTERO && (yyvsp[0].tipo == REAL || yyvsp[0].tipo == LOGICO)) {
                                    errorSemantico(ERR_EXDER_ENT, yyvsp[-1].nlin, yyvsp[-1].ncol, yyvsp[-1].lexema);
                                 }
                                 
                                 // no se permite asignar valores logicos a variables reales
                                 if (yyvsp[-2].tipo == REAL && yyvsp[0].tipo == LOGICO) {
                                    errorSemantico(ERR_EXDER_RE, yyvsp[-1].nlin, yyvsp[-1].ncol, yyvsp[-1].lexema);
                                 }

                                 // no se permite asignar valores reales o enteros a variables logicas
                                 if (yyvsp[-2].tipo == LOGICO && (yyvsp[0].tipo == ENTERO || yyvsp[0].tipo == REAL)) {
                                    errorSemantico(ERR_EXDER_LOG, yyvsp[-1].nlin, yyvsp[-1].ncol, yyvsp[-1].lexema);
                                 }
                                 
                                 // Ref.cod + Expr.cod
                                 yyval.cod = yyvsp[-2].cod + yyvsp[0].cod;

                                 // si es REAL := ENTERO, hay que convertir
                                 if (yyvsp[-2].tipo == REAL && yyvsp[0].tipo == ENTERO) {
                                    // mov Expr.dir A
                                    yyval.cod += "mov " + to_string(yyvsp[0].dir) + " A\n";

                                    // itor
                                    yyval.cod += "itor\n";

                                    // mov A Expr.dir
                                    yyval.cod += "mov A " + to_string(yyvsp[0].dir) + "\n";
                                 }

                                 // calcular la direccion
                                 // mov Ref.dir A
                                 yyval.cod += "mov " + to_string(yyvsp[-2].dir) + " A\n";

                                 // addi #Ref.dbase
                                 yyval.cod += "addi #" + to_string(yyvsp[-2].dbase) + "\n";

                                 // guardar el valor de Expr en la direccion calculada en A
                                 // mov Expr.dir @A
                                 yyval.cod += "mov " + to_string(yyvsp[0].dir) + " @A\n";
                              }
#line 1874 "plp5.tab.c"
    break;

  case 28:
#line 416 "plp5.y"
                              {  tsActual = new TablaSimbolos(tsActual);   }
#line 1880 "plp5.tab.c"
    break;

  case 29:
#line 417 "plp5.y"
                              {  yyval.cod = yyvsp[-2].cod + yyvsp[-1].cod; 
                                 tsActual = tsActual->getAmbitoAnterior();
                              }
#line 1888 "plp5.tab.c"
    break;

  case 30:
#line 422 "plp5.y"
                              {  // los operadores logicos solamente pueden utilizarse con valores logicos,
                                 // nunca con valores reales o enteros
                                 if (yyvsp[-2].tipo != LOGICO) {
                                    errorSemantico(ERR_EXIZQ_LOG, yyvsp[-1].nlin, yyvsp[-1].ncol, yyvsp[-1].lexema);
                                 }
                                 if (yyvsp[0].tipo != LOGICO) {
                                    errorSemantico(ERR_EXDER_LOG, yyvsp[-1].nlin, yyvsp[-1].ncol, yyvsp[-1].lexema);
                                 }

                                 yyval.cod = yyvsp[-2].cod + yyvsp[0].cod;
                                 yyval.dir = nuevaTemp(yyvsp[0].nlin, yyvsp[0].ncol);
                                 yyval.tipo = LOGICO;

                                 // mov Expr1.dir A
                                 yyval.cod += "mov " + to_string(yyvsp[-2].dir) + " A\n";

                                 // las expresiones logicas son 0 o 1
                                 // ori Econj.dir
                                 yyval.cod += "ori " + to_string(yyvsp[0].dir) + "\n";

                                 // mov A ctemp
                                 yyval.cod += "mov A " + to_string(ctemp) + "\n";
                              }
#line 1916 "plp5.tab.c"
    break;

  case 31:
#line 445 "plp5.y"
                              {  yyval.cod = yyvsp[0].cod;
                                 yyval.dir = yyvsp[0].dir;
                                 yyval.tipo = yyvsp[0].tipo;
                              }
#line 1925 "plp5.tab.c"
    break;

  case 32:
#line 451 "plp5.y"
                              {  // los operadores logicos solamente pueden utilizarse con valores logicos,
                                 // nunca con valores reales o enteros
                                 if (yyvsp[-2].tipo != LOGICO) {
                                    errorSemantico(ERR_EXIZQ_LOG, yyvsp[-1].nlin, yyvsp[-1].ncol, yyvsp[-1].lexema);
                                 }
                                 if (yyvsp[0].tipo != LOGICO) {
                                    errorSemantico(ERR_EXDER_LOG, yyvsp[-1].nlin, yyvsp[-1].ncol, yyvsp[-1].lexema);
                                 }

                                 yyval.cod = yyvsp[-2].cod + yyvsp[0].cod;
                                 yyval.dir = nuevaTemp(yyvsp[0].nlin, yyvsp[0].ncol);
                                 yyval.tipo = LOGICO;

                                 // mov Expr1.dir A
                                 yyval.cod += "mov " + to_string(yyvsp[-2].dir) + " A\n";

                                 // las expresiones logicas son 0 o 1
                                 // andi Econj.dir
                                 yyval.cod += "andi " + to_string(yyvsp[0].dir) + "\n";

                                 // mov A ctemp
                                 yyval.cod += "mov A " + to_string(ctemp) + "\n";
                              }
#line 1953 "plp5.tab.c"
    break;

  case 33:
#line 474 "plp5.y"
                              {  yyval.cod = yyvsp[0].cod;
                                 yyval.dir = yyvsp[0].dir;
                                 yyval.tipo = yyvsp[0].tipo;
                              }
#line 1962 "plp5.tab.c"
    break;

  case 34:
#line 481 "plp5.y"
                              {  // los operadores relacionales admiten expresiones reales o enteras
                                 if (yyvsp[-2].tipo != REAL && yyvsp[-2].tipo != ENTERO) {
                                    errorSemantico(ERR_EXIZQ_RE, yyvsp[-1].nlin, yyvsp[-1].ncol, yyvsp[-1].lexema);
                                 }
                                 if (yyvsp[0].tipo != REAL && yyvsp[0].tipo != ENTERO) {
                                    errorSemantico(ERR_EXDER_RE, yyvsp[-1].nlin, yyvsp[-1].ncol, yyvsp[-1].lexema);
                                 }

                                 yyval.cod = yyvsp[-2].cod + yyvsp[0].cod;
                                 yyval.dir = nuevaTemp(yyvsp[0].nlin, yyvsp[0].ncol);
                                 yyval.tipo = LOGICO;
                                 
                                 // operacion
                                 string op = "";
                                 if (strcmp(yyvsp[-1].lexema, "=") == 0) {
                                    op = "eql";
                                 } else if (strcmp(yyvsp[-1].lexema, "<>") == 0) {
                                    op = "neq";
                                 } else if (strcmp(yyvsp[-1].lexema, "<") == 0) {
                                    op = "lss";
                                 } else if (strcmp(yyvsp[-1].lexema, "<=") == 0) {
                                    op = "leq";
                                 } else if (strcmp(yyvsp[-1].lexema, ">") == 0) {
                                    op = "gtr";
                                 } else {    // >=
                                    op = "geq";
                                 }

                                 if (yyvsp[-2].tipo == yyvsp[0].tipo) {  // ENTERO && ENTERO, REAL && REAL
                                    string ri = yyvsp[-2].tipo == ENTERO ? "i" : "r";
                                    
                                    // mov Esimple1.dir A
                                    yyval.cod += "mov " + to_string(yyvsp[-2].dir) + " A\n";

                                    // opri Esimple2.dir
                                    yyval.cod += op + ri + to_string(yyvsp[0].dir) + "\n";

                                 } else if (yyvsp[-2].tipo == REAL && yyvsp[0].tipo == ENTERO) {
                                    // mov Esimple2.dir A
                                    yyval.cod += "mov " + to_string(yyvsp[0].dir) + " A\n";

                                    // itor
                                    yyval.cod += "itor\n";

                                    // mov A ctemp
                                    yyval.cod += "mov A " + to_string(ctemp) + "\n";

                                    // mov Esimple1.dir A
                                    yyval.cod += "mov " + to_string(yyvsp[-2].dir) + " A\n";

                                    // opr ctemp
                                    yyval.cod += op + "r " + to_string(ctemp) + "\n";

                                 } else {    // ENTERO && REAL
                                    // mov Esimple1.dir A
                                    yyval.cod += "mov " + to_string(yyvsp[-2].dir) + " A\n";

                                    // itor
                                    yyval.cod += "itor\n";

                                    // opr Esimple2.dir
                                    yyval.cod += op + "r " + to_string(yyvsp[0].dir) + "\n";
                                 }

                                 // mov A ctemp
                                 yyval.cod += "mov A " + to_string(ctemp) + "\n";
                              }
#line 2034 "plp5.tab.c"
    break;

  case 35:
#line 548 "plp5.y"
                              {  yyval.cod = yyvsp[0].cod;
                                 yyval.dir = yyvsp[0].dir;
                                 yyval.tipo = yyvsp[0].tipo;
                              }
#line 2043 "plp5.tab.c"
    break;

  case 36:
#line 554 "plp5.y"
                              {  // los operadores aritmeticos solamente pueden utilizarse con valores reales o enteros, 
                                 // nunca con valores logicos
                                 if (yyvsp[-2].tipo != REAL && yyvsp[-2].tipo != ENTERO) {
                                    errorSemantico(ERR_EXIZQ_RE, yyvsp[-1].nlin, yyvsp[-1].ncol, yyvsp[-1].lexema);
                                 }
                                 if (yyvsp[0].tipo != REAL && yyvsp[0].tipo != ENTERO) {
                                    errorSemantico(ERR_EXDER_RE, yyvsp[-1].nlin, yyvsp[-1].ncol, yyvsp[-1].lexema);
                                 }
                                 
                                 yyval.cod = yyvsp[-2].cod + yyvsp[0].cod;
                                 yyval.dir = nuevaTemp(yyvsp[0].nlin, yyvsp[0].ncol);
                                 yyval.tipo = (yyvsp[-2].tipo == ENTERO && yyvsp[0].tipo == ENTERO) ? ENTERO : REAL;
                                 
                                 // operacion
                                 string op = (strcmp(yyvsp[-1].lexema, "+") == 0) ? "add" : "sub";
                                 
                                 if (yyvsp[-2].tipo == yyvsp[0].tipo) {  // ENTERO && ENTERO, REAL && REAL
                                    string ri = yyvsp[-2].tipo == ENTERO ? "i" : "r";
                                    
                                    // mov Esimple1.dir A
                                    yyval.cod += "mov " + to_string(yyvsp[-2].dir) + " A\n";

                                    // opri Term.dir
                                    yyval.cod += op + ri + to_string(yyvsp[0].dir) + "\n";

                                 } else if (yyvsp[-2].tipo == REAL && yyvsp[0].tipo == ENTERO) {
                                    // mov Term.dir A
                                    yyval.cod += "mov " + to_string(yyvsp[0].dir) + " A\n";

                                    // itor
                                    yyval.cod += "itor\n";

                                    // mov A ctemp
                                    yyval.cod += "mov A " + to_string(ctemp) + "\n";

                                    // mov Esimple1.dir A
                                    yyval.cod += "mov " + to_string(yyvsp[-2].dir) + " A\n";

                                    // opr ctemp
                                    yyval.cod += op + "r " + to_string(ctemp) + "\n";

                                 } else {    // ENTERO && REAL
                                    // mov Esimple1.dir A
                                    yyval.cod += "mov " + to_string(yyvsp[-2].dir) + " A\n";

                                    // itor
                                    yyval.cod += "itor\n";

                                    // opr Term.dir
                                    yyval.cod += op + "r " + to_string(yyvsp[0].dir) + "\n";
                                 }

                                 // mov A ctemp
                                 yyval.cod += "mov A " + to_string(ctemp) + "\n";
                              }
#line 2103 "plp5.tab.c"
    break;

  case 37:
#line 609 "plp5.y"
                              {  yyval.cod = yyvsp[0].cod;
                                 yyval.dir = yyvsp[0].dir;
                                 yyval.tipo = yyvsp[0].tipo;
                              }
#line 2112 "plp5.tab.c"
    break;

  case 38:
#line 613 "plp5.y"
                              {  // los operadores aritmeticos solamente pueden utilizarse con valores reales o enteros, 
                                 // nunca con valores logicos
                                 if (yyvsp[0].tipo != REAL && yyvsp[0].tipo != ENTERO) {
                                    errorSemantico(ERR_EXDER_RE, yyvsp[-1].nlin, yyvsp[-1].ncol, yyvsp[-1].lexema);
                                 }

                                 yyval.cod = yyvsp[0].cod;
                                 yyval.dir = nuevaTemp(yyvsp[0].nlin, yyvsp[0].ncol);
                                 yyval.tipo = yyvsp[0].tipo;

                                 // si operacion es '-', hay que cambiar el signo
                                 if(strcmp(yyvsp[-1].lexema, "+") == 0) {
                                    // mov Term.dir ctemp
                                    yyval.cod += "mov " + to_string(yyvsp[0].dir) + " " + to_string(ctemp) + "\n";

                                 } else {
                                    // mov Term.dir A
                                    yyval.cod += "mov " + to_string(yyvsp[0].dir) +" A\n";
                                          
                                    // muli #-1
                                    yyval.cod += "muli #-1\n";
                                    
                                    // mov A ctemp
                                    yyval.cod += "mov A " + to_string(ctemp) + "\n";
                                 }
                              }
#line 2143 "plp5.tab.c"
    break;

  case 39:
#line 641 "plp5.y"
                              {  // los operadores aritmeticos solamente pueden utilizarse con valores reales o enteros, 
                                 // nunca con valores logicos
                                 if (yyvsp[-2].tipo != REAL && yyvsp[-2].tipo != ENTERO) {
                                    errorSemantico(ERR_EXIZQ_RE, yyvsp[-1].nlin, yyvsp[-1].ncol, yyvsp[-1].lexema);
                                 }
                                 if (yyvsp[0].tipo != REAL && yyvsp[0].tipo != ENTERO) {
                                    errorSemantico(ERR_EXDER_RE, yyvsp[-1].nlin, yyvsp[-1].ncol, yyvsp[-1].lexema);
                                 }

                                 yyval.cod = yyvsp[-2].cod + yyvsp[0].cod;
                                 yyval.dir = nuevaTemp(yyvsp[0].nlin, yyvsp[0].ncol);
                                 yyval.tipo = (yyvsp[-2].tipo == ENTERO && yyvsp[0].tipo == ENTERO) ? ENTERO : REAL;
                                 
                                 // operacion
                                 string op = (strcmp(yyvsp[-1].lexema, "*") == 0) ? "mul" : "div";
                                 
                                 if (yyvsp[-2].tipo == yyvsp[0].tipo) {  // ENTERO && ENTERO, REAL && REAL
                                    string ri = yyvsp[-2].tipo == ENTERO ? "i" : "r";
                                    
                                    // mov Term1.dir A
                                    yyval.cod += "mov " + to_string(yyvsp[-2].dir) + " A\n";

                                    // opri Factor.dir
                                    yyval.cod += op + ri + to_string(yyvsp[0].dir) + "\n";

                                 } else if (yyvsp[-2].tipo == REAL && yyvsp[0].tipo == ENTERO) {
                                    // mov Factor.dir A
                                    yyval.cod += "mov " + to_string(yyvsp[0].dir) + " A\n";

                                    // itor
                                    yyval.cod += "itor\n";

                                    // mov A ctemp
                                    yyval.cod += "mov A " + to_string(ctemp) + "\n";

                                    // mov Term1.dir A
                                    yyval.cod += "mov " + to_string(yyvsp[-2].dir) + " A\n";

                                    // opr ctemp
                                    yyval.cod += op + "r " + to_string(ctemp) + "\n";

                                 } else {    // ENTERO && REAL
                                    // mov Term1.dir A
                                    yyval.cod += "mov " + to_string(yyvsp[-2].dir) + " A\n";

                                    // itor
                                    yyval.cod += "itor\n";

                                    // opr Factor.dir
                                    yyval.cod += op + "r " + to_string(yyvsp[0].dir) + "\n";
                                 }

                                 // mov A ctemp
                                 yyval.cod += "mov A " + to_string(ctemp) + "\n";
                              }
#line 2203 "plp5.tab.c"
    break;

  case 40:
#line 696 "plp5.y"
                              {  yyval.cod = yyvsp[0].cod;
                                 yyval.dir = yyvsp[0].dir;
                                 yyval.tipo = yyvsp[0].tipo;
                              }
#line 2212 "plp5.tab.c"
    break;

  case 41:
#line 702 "plp5.y"
                              {  // si el tipo de Ref que nos llega es array, es decir no es un tipo basico,
                                 // entonces se necesitan corchetes
                                 if ((ttipos->tipos)[yyvsp[0].tipo].clase == ARRAY) {
                                    errorSemantico(ERR_FALTAN, yyvsp[0].nlin, yyvsp[0].ncol, yyvsp[0].lexema);
                                 }

                                 yyval.cod = yyvsp[0].cod;
                                 yyval.dir = nuevaTemp(yyvsp[0].nlin, yyvsp[0].ncol);
                                 yyval.tipo = yyvsp[0].tipo;

                                 // mov Ref.dir A
                                 yyval.cod += "mov " + to_string(yyvsp[0].dir) + " A\n";

                                 // addi #Ref.dbase
                                 yyval.cod += "addi #" + to_string(yyvsp[0].dbase) + "\n";

                                 // mov @A ctemp
                                 yyval.cod += "mov @A " + to_string(ctemp) + "\n";
                              }
#line 2236 "plp5.tab.c"
    break;

  case 42:
#line 721 "plp5.y"
                              {  yyval.tipo = ENTERO; 

                                 // si no hay espacio para la variable, salta el error 
                                 // (lexema se necesita para el mensaje de error) 
                                 ctemp = nuevaTemp(yyvsp[0].nlin, yyvsp[0].ncol); 
                                 
                                 yyval.dir = ctemp;
                                 yyval.cod = "mov #" + string(yyvsp[0].lexema) + " " + to_string(ctemp) + "\n";
                              }
#line 2250 "plp5.tab.c"
    break;

  case 43:
#line 730 "plp5.y"
                              {  yyval.tipo = REAL; 

                                 // si no hay espacio para la variable, salta el error 
                                 // (lexema se necesita para el mensaje de error) 
                                 ctemp = nuevaTemp(yyvsp[0].nlin, yyvsp[0].ncol); 
                                 
                                 yyval.dir = ctemp;
                                 yyval.cod = "mov $" + string(yyvsp[0].lexema) + " " + to_string(ctemp) + "\n";
                              }
#line 2264 "plp5.tab.c"
    break;

  case 44:
#line 739 "plp5.y"
                              {  yyval.cod = yyvsp[-1].cod;
                                 yyval.dir = yyvsp[-1].dir;
                                 yyval.tipo = yyvsp[-1].tipo;
                              }
#line 2273 "plp5.tab.c"
    break;

  case 45:
#line 743 "plp5.y"
                              {  if (yyvsp[0].tipo != LOGICO) {
                                    errorSemantico(ERR_EXDER_LOG, yyvsp[-1].nlin, yyvsp[-1].ncol, yyvsp[-1].lexema);
                                 }

                                 yyval.cod = yyvsp[0].cod;
                                 yyval.dir = nuevaTemp(yyvsp[0].nlin, yyvsp[0].ncol);
                                 yyval.tipo = LOGICO;

                                 // mov Factor1.dir A
                                 yyval.cod += "mov " + to_string(yyvsp[0].dir) + " A\n";
                                 
                                 // Factor va a ser 1 o 0
                                 // noti
                                 yyval.cod += "noti\n";

                                 // mov A ctemp
                                 yyval.cod += "mov A " + to_string(ctemp) + "\n";
                              }
#line 2296 "plp5.tab.c"
    break;

  case 46:
#line 761 "plp5.y"
                              {  yyval.tipo = LOGICO;
                                 yyval.dir = nuevaTemp(yyvsp[0].nlin, yyvsp[0].ncol);

                                 // true es 1
                                 yyval.cod = "mov #1 " + to_string(ctemp) + "\n";
                              }
#line 2307 "plp5.tab.c"
    break;

  case 47:
#line 767 "plp5.y"
                              {  yyval.tipo = LOGICO;
                                 yyval.dir = nuevaTemp(yyvsp[0].nlin, yyvsp[0].ncol);

                                 // false es 0
                                 yyval.cod = "mov #0 " + to_string(ctemp) + "\n"; 
                              }
#line 2318 "plp5.tab.c"
    break;

  case 48:
#line 775 "plp5.y"
                              {  Simbolo *simbolo = tsActual->searchSymb(yyvsp[0].lexema);
                                 if (simbolo == nullptr) {
                                    errorSemantico(ERR_NODECL, yyvsp[0].nlin, yyvsp[0].ncol, yyvsp[0].lexema);
                                 }

                                 // si no hay espacio para la variable, salta el error 
                                 // (lexema se necesita para el mensaje de error) 
                                 ctemp = nuevaTemp(yyvsp[0].nlin, yyvsp[0].ncol);    

                                 yyval.dir = ctemp;
                                 yyval.cod = "mov #0 " + to_string(ctemp) + "\n";
                                 yyval.tipo = simbolo->tipo;

                                 // si id no es de tipo array, simbolo->dir es 0
                                 yyval.dbase = simbolo->dir;
                              
                                 yyval.lexema = yyvsp[0].lexema;
                                 yyval.nlin = yyvsp[0].nlin;
                                 yyval.ncol = yyvsp[0].ncol;
                              }
#line 2343 "plp5.tab.c"
    break;

  case 49:
#line 795 "plp5.y"
                              {  if (!esArray(yyvsp[-1].tipo)) {
                                    if(strcmp(yyvsp[-1].lexema, "]") == 0) {
                                       errorSemantico(ERR_SOBRAN, yyvsp[0].nlin, yyvsp[0].ncol, yyvsp[0].lexema); 
                                    } else {
                                       errorSemantico(ERR_SOBRAN, yyvsp[-1].nlin, yyvsp[-1].ncol, yyvsp[-1].lexema);
                                    }
                                 }
                              }
#line 2356 "plp5.tab.c"
    break;

  case 50:
#line 803 "plp5.y"
                              {  // Indice solo puede ser un numero entero
                                 if (yyvsp[-1].tipo != ENTERO) {
                                    errorSemantico(ERR_INDICE_ENTERO, yyvsp[-1].nlin, yyvsp[-1].ncol, yyvsp[-1].lexema);
                                 }

                                 // desreferenciar
                                 yyval.tipo = (ttipos->tipos)[yyvsp[-4].tipo].tipoBase;
                                 yyval.dbase = yyvsp[-4].dbase;

                                 // si no hay espacio para la variable, salta el error 
                                 // (lexema se necesita para el mensaje de error) 
                                 ctemp = nuevaTemp(yyvsp[-3].nlin, yyvsp[-3].ncol);    

                                 yyval.dir = ctemp;

                                 // Ref1.cod + Esimple.cod
                                 yyval.cod = yyvsp[-4].cod + yyvsp[-1].cod;

                                 // A = Ref1.dir * Ref1.tam + Esimple.dir
                                 // mov Ref1.dir A
                                 yyval.cod += "mov " + to_string(yyvsp[-4].dir) + " A\n";
                                 // muli #Ref1.tam
                                 yyval.cod += "muli #" + to_string((ttipos->tipos)[yyvsp[-4].tipo].tamanyo) + "\n";
                                 // addi Esimple.dir
                                 yyval.cod += "addi " + to_string(yyvsp[-1].dir) + "\n";
                                 // mov A ctemp
                                 yyval.cod += "mov A " + to_string(ctemp) + "\n";

                                 yyval.lexema = yyvsp[0].lexema;
                                 yyval.nlin = yyvsp[0].nlin;
                                 yyval.ncol = yyvsp[0].ncol;
                              }
#line 2393 "plp5.tab.c"
    break;


#line 2397 "plp5.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *, YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;


#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[+*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 837 "plp5.y"


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

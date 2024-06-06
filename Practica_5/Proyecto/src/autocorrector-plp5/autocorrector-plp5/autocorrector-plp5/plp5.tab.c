/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
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
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 22 "plp5.y"


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


#line 128 "plp5.tab.c"

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

#include "plp5.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_tmain = 3,                      /* tmain  */
  YYSYMBOL_tint = 4,                       /* tint  */
  YYSYMBOL_tfloat = 5,                     /* tfloat  */
  YYSYMBOL_tprintf = 6,                    /* tprintf  */
  YYSYMBOL_tif = 7,                        /* tif  */
  YYSYMBOL_telse = 8,                      /* telse  */
  YYSYMBOL_twhile = 9,                     /* twhile  */
  YYSYMBOL_tfor = 10,                      /* tfor  */
  YYSYMBOL_id = 11,                        /* id  */
  YYSYMBOL_nentero = 12,                   /* nentero  */
  YYSYMBOL_nreal = 13,                     /* nreal  */
  YYSYMBOL_coma = 14,                      /* coma  */
  YYSYMBOL_pyc = 15,                       /* pyc  */
  YYSYMBOL_pari = 16,                      /* pari  */
  YYSYMBOL_pard = 17,                      /* pard  */
  YYSYMBOL_oprel = 18,                     /* oprel  */
  YYSYMBOL_opas = 19,                      /* opas  */
  YYSYMBOL_opmd = 20,                      /* opmd  */
  YYSYMBOL_asig = 21,                      /* asig  */
  YYSYMBOL_referencia = 22,                /* referencia  */
  YYSYMBOL_cori = 23,                      /* cori  */
  YYSYMBOL_cord = 24,                      /* cord  */
  YYSYMBOL_llavei = 25,                    /* llavei  */
  YYSYMBOL_llaved = 26,                    /* llaved  */
  YYSYMBOL_formato = 27,                   /* formato  */
  YYSYMBOL_incrdecr = 28,                  /* incrdecr  */
  YYSYMBOL_tscanf = 29,                    /* tscanf  */
  YYSYMBOL_YYACCEPT = 30,                  /* $accept  */
  YYSYMBOL_S = 31,                         /* S  */
  YYSYMBOL_FVM = 32,                       /* FVM  */
  YYSYMBOL_Tipo = 33,                      /* Tipo  */
  YYSYMBOL_Bloque = 34,                    /* Bloque  */
  YYSYMBOL_35_1 = 35,                      /* $@1  */
  YYSYMBOL_BDecl = 36,                     /* BDecl  */
  YYSYMBOL_DVar = 37,                      /* DVar  */
  YYSYMBOL_38_2 = 38,                      /* @2  */
  YYSYMBOL_LIdent = 39,                    /* LIdent  */
  YYSYMBOL_40_3 = 40,                      /* @3  */
  YYSYMBOL_41_4 = 41,                      /* @4  */
  YYSYMBOL_Variable = 42,                  /* Variable  */
  YYSYMBOL_43_5 = 43,                      /* @5  */
  YYSYMBOL_V = 44,                         /* V  */
  YYSYMBOL_45_6 = 45,                      /* @6  */
  YYSYMBOL_SeqInstr = 46,                  /* SeqInstr  */
  YYSYMBOL_47_7 = 47,                      /* @7  */
  YYSYMBOL_Instr = 48,                     /* Instr  */
  YYSYMBOL_49_8 = 49,                      /* $@8  */
  YYSYMBOL_50_9 = 50,                      /* $@9  */
  YYSYMBOL_Expr = 51,                      /* Expr  */
  YYSYMBOL_Esimple = 52,                   /* Esimple  */
  YYSYMBOL_Term = 53,                      /* Term  */
  YYSYMBOL_Factor = 54,                    /* Factor  */
  YYSYMBOL_Ref = 55,                       /* Ref  */
  YYSYMBOL_56_10 = 56                      /* $@10  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




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

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
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
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
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

#if !defined yyoverflow

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
#endif /* !defined yyoverflow */

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
#define YYFINAL  8
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   97

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  30
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  27
/* YYNRULES -- Number of rules.  */
#define YYNRULES  48
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  105

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   284


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

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
      25,    26,    27,    28,    29
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    81,    81,    93,    97,   102,   105,   110,   110,   117,
     120,   123,   123,   129,   129,   130,   130,   133,   133,   154,
     154,   162,   165,   165,   170,   173,   176,   179,   203,   228,
     265,   275,   289,   301,   314,   301,   372,   424,   432,   475,
     482,   523,   530,   545,   551,   556,   562,   578,   578
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "tmain", "tint",
  "tfloat", "tprintf", "tif", "telse", "twhile", "tfor", "id", "nentero",
  "nreal", "coma", "pyc", "pari", "pard", "oprel", "opas", "opmd", "asig",
  "referencia", "cori", "cord", "llavei", "llaved", "formato", "incrdecr",
  "tscanf", "$accept", "S", "FVM", "Tipo", "Bloque", "$@1", "BDecl",
  "DVar", "@2", "LIdent", "@3", "@4", "Variable", "@5", "V", "@6",
  "SeqInstr", "@7", "Instr", "$@8", "$@9", "Expr", "Esimple", "Term",
  "Factor", "Ref", "$@10", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-69)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int8 yypact[] =
{
      10,    21,   -69,    39,   -69,   -69,    10,    15,   -69,   -69,
     -69,    29,    28,    22,    27,   -69,   -69,   -69,   -69,   -69,
     -69,    22,    34,   -69,   -69,    48,   -69,    40,    38,   -69,
     -69,    35,   -69,   -69,     1,    34,    47,    49,    50,    51,
     -69,   -69,    52,   -69,   -69,   -18,   -69,    43,    16,    16,
      53,    44,    16,   -69,    58,   -69,   -69,    16,    31,    54,
      55,   -69,    56,    33,    57,    60,    19,    16,    16,    37,
       1,    16,    16,    16,     1,    16,    59,   -69,    -1,    41,
     -69,    68,    54,    55,   -69,   -69,    54,    66,   -69,    65,
       1,    67,     2,   -69,   -69,    16,    69,    23,   -69,    72,
     -69,    61,    70,     1,   -69
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     5,     6,     0,     2,    11,     0,     0,     1,    15,
       3,     0,     0,     0,     0,    13,    12,    17,    16,     7,
       4,     0,    21,    10,    14,     0,    18,    24,     0,     5,
       9,    22,    19,     8,     0,    21,     0,     0,     0,     0,
      46,    25,     0,    26,    23,     0,    20,     0,     0,     0,
       0,     0,     0,    47,     0,    43,    44,     0,     0,    37,
      39,    41,    42,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    27,     0,     0,
      45,    30,    36,    38,    40,    32,    33,     0,    48,     0,
       0,     0,     0,    28,    31,     0,     0,     0,    29,     0,
      34,     0,     0,     0,    35
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -69,   -69,    79,   -69,    74,   -69,   -69,    63,   -69,   -69,
     -69,   -69,    71,   -69,    62,   -69,   -69,   -69,   -68,   -69,
     -69,   -48,   -54,    14,    18,   -34,   -69
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     3,     4,     5,    43,    23,    27,     6,     9,    12,
      21,    13,    18,    22,    26,    35,    31,    34,    44,    91,
     101,    58,    59,    60,    61,    62,    67
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      45,    63,    81,    52,    66,    53,    85,    36,    37,    69,
      38,    39,    40,    78,     1,     2,    41,    82,    72,    96,
      79,    86,    94,    88,     7,    53,    19,    40,    55,    56,
      42,    11,    57,    17,    77,   104,    45,    71,    99,     8,
      45,    71,    15,    16,    29,     2,    14,    97,    70,    71,
      74,    71,    19,    92,    80,    71,    45,    25,    89,    71,
      28,    33,    32,    47,    64,    48,    49,    50,    51,    45,
      54,    65,    68,    72,    76,    73,    90,    40,    75,    53,
      93,    87,    95,   100,    98,    10,    83,   103,    20,   102,
      30,    84,    24,     0,     0,     0,     0,    46
};

static const yytype_int8 yycheck[] =
{
      34,    49,    70,    21,    52,    23,    74,     6,     7,    57,
       9,    10,    11,    67,     4,     5,    15,    71,    19,    17,
      68,    75,    90,    24,     3,    23,    25,    11,    12,    13,
      29,    16,    16,    11,    15,   103,    70,    18,    15,     0,
      74,    18,    14,    15,     4,     5,    17,    95,    17,    18,
      17,    18,    25,    87,    17,    18,    90,    23,    17,    18,
      12,    26,    24,    16,    11,    16,    16,    16,    16,   103,
      27,    27,    14,    19,    14,    20,     8,    11,    21,    23,
      15,    22,    15,    11,    15,     6,    72,    17,    14,    28,
      27,    73,    21,    -1,    -1,    -1,    -1,    35
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     4,     5,    31,    32,    33,    37,     3,     0,    38,
      32,    16,    39,    41,    17,    14,    15,    11,    42,    25,
      34,    40,    43,    35,    42,    23,    44,    36,    12,     4,
      37,    46,    24,    26,    47,    45,     6,     7,     9,    10,
      11,    15,    29,    34,    48,    55,    44,    16,    16,    16,
      16,    16,    21,    23,    27,    12,    13,    16,    51,    52,
      53,    54,    55,    51,    11,    27,    51,    56,    14,    51,
      17,    18,    19,    20,    17,    21,    14,    15,    52,    51,
      17,    48,    52,    53,    54,    48,    52,    22,    24,    17,
       8,    49,    55,    15,    48,    15,    17,    51,    15,    15,
      11,    50,    28,    17,    48
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    30,    31,    32,    32,    33,    33,    35,    34,    36,
      36,    38,    37,    40,    39,    41,    39,    43,    42,    45,
      44,    44,    47,    46,    46,    48,    48,    48,    48,    48,
      48,    48,    48,    49,    50,    48,    51,    51,    52,    52,
      53,    53,    54,    54,    54,    54,    55,    56,    55
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     5,     1,     1,     0,     5,     2,
       0,     0,     4,     0,     4,     0,     2,     0,     3,     0,
       5,     0,     0,     3,     0,     1,     1,     4,     7,     8,
       5,     7,     5,     0,     0,    14,     3,     1,     3,     1,
       3,     1,     1,     1,     1,     3,     1,     0,     5
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


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

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


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




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
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
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
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
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
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






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
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
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

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
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
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
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
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

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
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
  case 2: /* S: FVM  */
#line 81 "plp5.y"
                        {
                              int tk = yylex();
                              if(tk == 0){
                                    cout << yyvsp[0].cod << "halt\n";
                              } 
                              else{
                                    yyerror("");
                              }
                        }
#line 1238 "plp5.tab.c"
    break;

  case 3: /* FVM: DVar FVM  */
#line 93 "plp5.y"
                              {
                                    yyval.cod = yyvsp[-1].cod + yyvsp[0].cod;
                              }
#line 1246 "plp5.tab.c"
    break;

  case 4: /* FVM: tint tmain pari pard Bloque  */
#line 97 "plp5.y"
                                            {
                                                yyval.cod = yyvsp[0].cod;
                                          }
#line 1254 "plp5.tab.c"
    break;

  case 5: /* Tipo: tint  */
#line 102 "plp5.y"
                         {
                              yyval.tipo = ENTERO;
                        }
#line 1262 "plp5.tab.c"
    break;

  case 6: /* Tipo: tfloat  */
#line 105 "plp5.y"
                         {
                              yyval.tipo = REAL;
                        }
#line 1270 "plp5.tab.c"
    break;

  case 7: /* $@1: %empty  */
#line 110 "plp5.y"
                     {  tsimbs = new TablaSimbolos(tsimbs);}
#line 1276 "plp5.tab.c"
    break;

  case 8: /* Bloque: llavei $@1 BDecl SeqInstr llaved  */
#line 111 "plp5.y"
                                         {
                                                yyval.cod = yyvsp[-2].cod + yyvsp[-1].cod;
                                                tsimbs = tsimbs->getAmbitoAnterior();
                                          }
#line 1285 "plp5.tab.c"
    break;

  case 9: /* BDecl: BDecl DVar  */
#line 117 "plp5.y"
                              {
                                    yyval.cod = yyvsp[-1].cod + yyvsp[0].cod;
                              }
#line 1293 "plp5.tab.c"
    break;

  case 10: /* BDecl: %empty  */
#line 120 "plp5.y"
                              {     yyval.cod = ""; }
#line 1299 "plp5.tab.c"
    break;

  case 11: /* @2: %empty  */
#line 123 "plp5.y"
                        {
                              yyval.tipo = yyvsp[0].tipo;
                        }
#line 1307 "plp5.tab.c"
    break;

  case 12: /* DVar: Tipo @2 LIdent pyc  */
#line 126 "plp5.y"
                        {yyval.cod = "";}
#line 1313 "plp5.tab.c"
    break;

  case 13: /* @3: %empty  */
#line 129 "plp5.y"
                           {yyval.tipo = yyvsp[-2].tipo;}
#line 1319 "plp5.tab.c"
    break;

  case 14: /* LIdent: LIdent coma @3 Variable  */
#line 129 "plp5.y"
                                                           {yyval.cod = ""; }
#line 1325 "plp5.tab.c"
    break;

  case 15: /* @4: %empty  */
#line 130 "plp5.y"
               {yyval.tipo = yyvsp[0].tipo;}
#line 1331 "plp5.tab.c"
    break;

  case 16: /* LIdent: @4 Variable  */
#line 130 "plp5.y"
                                               {yyval.cod = ""; }
#line 1337 "plp5.tab.c"
    break;

  case 17: /* @5: %empty  */
#line 133 "plp5.y"
                  {     
                        if (tsimbs->buscarAmbito(yyvsp[0].lexema) != nullptr) {
                              errorSemantico(ERRYADECL, yyvsp[0].lexema, yyvsp[0].nlin, yyvsp[0].ncol);
                        }
                        yyval.tipo = yyvsp[-1].tipo;
                  }
#line 1348 "plp5.tab.c"
    break;

  case 18: /* Variable: id @5 V  */
#line 139 "plp5.y"
                        {
                              Simbolo *simb = new Simbolo();
                              simb->nombre = yyvsp[-2].lexema;
                              simb->dir = nuevaVariable(yyvsp[-2].lexema, yyvsp[-2].nlin, yyvsp[-2].ncol);
                              simb->tam = yyvsp[0].tamanyo;
                              simb->tipo = yyvsp[0].tipo;

                              if(cont_pos_vars + simb->tam >= FIN_DIR_VAR) {
                                    errorSemantico(ERR_NOCABE, yyvsp[-2].lexema, yyvsp[-2].nlin, yyvsp[-2].ncol);
                              }
                              cont_pos_vars += simb->tam;  
                              tsimbs->nuevoSimbolo(*simb);
                        }
#line 1366 "plp5.tab.c"
    break;

  case 19: /* @6: %empty  */
#line 154 "plp5.y"
                                {yyval.tipo = yyvsp[-3].tipo; yyval.tamanyo = 1;}
#line 1372 "plp5.tab.c"
    break;

  case 20: /* V: cori nentero cord @6 V  */
#line 155 "plp5.y"
                                        {      
                                          if (stoi(yyvsp[-3].lexema) <= 0) {
                                                errorSemantico(ERRDIM, yyvsp[-3].lexema, yyvsp[-3].nlin, yyvsp[-3].ncol); 
                                          }
                                          yyval.tipo = ttipos->nuevoTipoArray(stoi(yyvsp[-3].lexema), yyvsp[0].tipo);
                                          yyval.tamanyo = yyvsp[0].tamanyo * stoi(yyvsp[-3].lexema);
                                    }
#line 1384 "plp5.tab.c"
    break;

  case 21: /* V: %empty  */
#line 162 "plp5.y"
                              { yyval.tipo = yyvsp[0].tipo; yyval.tamanyo = yyvsp[0].tamanyo;}
#line 1390 "plp5.tab.c"
    break;

  case 22: /* @7: %empty  */
#line 165 "plp5.y"
                       {  yyval.nlin = cont_pos_temps;  }
#line 1396 "plp5.tab.c"
    break;

  case 23: /* SeqInstr: SeqInstr @7 Instr  */
#line 166 "plp5.y"
                              {
                                    yyval.cod = yyvsp[-2].cod + yyvsp[0].cod;
                                    cont_pos_temps = yyvsp[-1].nlin;
                              }
#line 1405 "plp5.tab.c"
    break;

  case 24: /* SeqInstr: %empty  */
#line 170 "plp5.y"
                              { yyval.cod = "";}
#line 1411 "plp5.tab.c"
    break;

  case 25: /* Instr: pyc  */
#line 173 "plp5.y"
                        {
                              yyval.cod = "";
                        }
#line 1419 "plp5.tab.c"
    break;

  case 26: /* Instr: Bloque  */
#line 176 "plp5.y"
                        {
                              yyval.cod = yyvsp[0].cod;
                        }
#line 1427 "plp5.tab.c"
    break;

  case 27: /* Instr: Ref asig Expr pyc  */
#line 179 "plp5.y"
                                    {
                                          if((ttipos->tipos)[yyvsp[-3].tipo].clase == ARRAY){
                                                errorSemantico(ERRFALTAN, yyvsp[-3].lexema, yyvsp[-3].nlin, yyvsp[-3].ncol);
                                          }
                                          
                                          s1 = yyvsp[-3].cod + yyvsp[-1].cod;

                                          if (yyvsp[-3].tipo == REAL && yyvsp[-1].tipo == ENTERO) {
                                                s1 += "mov " + to_string(yyvsp[-1].dir) + " A\n";
                                                s1 += "itor\n";
                                                s1 += "mov A " + to_string(yyvsp[-1].dir) + "\n";
                                          }
                                          if (yyvsp[-3].tipo == ENTERO && yyvsp[-1].tipo == REAL) {
                                                s1 += "mov " + to_string(yyvsp[-1].dir) + " A\n";
                                                s1 += "rtoi\n";
                                                s1 += "mov A " + to_string(yyvsp[-1].dir) + "\n";
                                          }

                                          s1 += "mov " + to_string(yyvsp[-3].dir) + " A\n";
                                          s1 += "addi #" + to_string(yyvsp[-3].dbase) + "\n";

                                          s1 += "mov " + to_string(yyvsp[-1].dir) + " @A\n";
                                          yyval.cod = s1;
                                    }
#line 1456 "plp5.tab.c"
    break;

  case 28: /* Instr: tprintf pari formato coma Expr pard pyc  */
#line 203 "plp5.y"
                                                             {
                                                                  s1 = yyvsp[-2].cod;
                                                                  if(strcmp(yyvsp[-4].lexema, "\"%d\"") ==0){
                                                                        if(yyvsp[-2].tipo == REAL){
                                                                              s1 += "mov " + to_string(yyvsp[-2].dir) + " A\n";
                                                                              s1 += "rtoi\n";
                                                                              s1 += "wri A\n";    
                                                                        }
                                                                        else{
                                                                              s1 += "wri " + to_string(yyvsp[-2].dir) + "\n";
                                                                        }
                                                                  }
                                                                  else{
                                                                        if(yyvsp[-2].tipo == ENTERO){
                                                                              s1 += "mov " + to_string(yyvsp[-2].dir) + " A\n";
                                                                              s1 += "itor\n";
                                                                              s1 += "wrr A\n";    
                                                                        }
                                                                        else{
                                                                              s1 += "wrr " + to_string(yyvsp[-2].dir) + "\n";
                                                                        }
                                                                  }
                                                                  s1 += "wrl\n";
                                                                  yyval.cod = s1;
                                                            }
#line 1486 "plp5.tab.c"
    break;

  case 29: /* Instr: tscanf pari formato coma referencia Ref pard pyc  */
#line 228 "plp5.y"
                                                                   {
                                                                        if ((ttipos->tipos)[yyvsp[-2].tipo].clase == ARRAY) {
                                                                              errorSemantico(ERRFALTAN, yyvsp[-2].lexema, yyvsp[-2].nlin, yyvsp[-2].ncol);
                                                                        }
                                                                              
                                                                        s1 = yyvsp[-2].cod;

                                                                        if(yyvsp[-2].tipo == ENTERO){
                                                                              s1 += "rdi A\n";
                                                                              if(strcmp(yyvsp[-5].lexema, "\"%g\"") ==0){
                                                                                    s1 += "itor\n";
                                                                              }
                                                                              
                                                                              cont_pos_temps = nuevaTemporal(yyvsp[-2].lexema, yyvsp[-2].nlin, yyvsp[-2].ncol);
                                                                              s1 += "mov A " + to_string(cont_pos_temps) + "\n";

                                                                              s1 += "mov " + to_string(yyvsp[-2].dir) + " A\n";
                                                                              s1 += "addi #" + to_string(yyvsp[-2].dbase) + "\n";

                                                                              s1 += "mov " + to_string(cont_pos_temps) + " @A\n";
                                                                        }
                                                                        else{
                                                                              s1 += "rdr A\n";
                                                                              if(strcmp(yyvsp[-5].lexema, "\"%d\"") ==0){
                                                                                    s1 += "rtoi\n";
                                                                              }
                                                                              
                                                                              cont_pos_temps = nuevaTemporal(yyvsp[-2].lexema, yyvsp[-2].nlin, yyvsp[-2].ncol);
                                                                              s1 += "mov A " + to_string(cont_pos_temps) + "\n";

                                                                              s1 += "mov " + to_string(yyvsp[-2].dir) + " A\n";
                                                                              s1 += "addi #" + to_string(yyvsp[-2].dbase) + "\n";

                                                                              s1 += "mov " + to_string(cont_pos_temps) + " @A\n";
                                                                        }
                                                                        yyval.cod = s1;
                                                                  }
#line 1528 "plp5.tab.c"
    break;

  case 30: /* Instr: tif pari Expr pard Instr  */
#line 265 "plp5.y"
                                           {
                                                s1 = yyvsp[-2].cod;
                                                int label = incrementarEtiqueta();

                                                s1 += "mov " + to_string(yyvsp[-2].dir) + " A\n";
                                                s1 += "jz L" + to_string(label) +"\n";
                                                s1 += yyvsp[0].cod;
                                                s1 += "L" + to_string(label) + " ";
                                                yyval.cod = s1;
                                          }
#line 1543 "plp5.tab.c"
    break;

  case 31: /* Instr: tif pari Expr pard Instr telse Instr  */
#line 275 "plp5.y"
                                                        {
                                                            s1 = yyvsp[-4].cod;
                                                            int label1 = incrementarEtiqueta();
                                                            int label2 = incrementarEtiqueta();

                                                            s1 += "mov " + to_string(yyvsp[-4].dir) + " A\n";
                                                            s1 += "jz L" + to_string(label1) +"\n";
                                                            s1 += yyvsp[-2].cod;
                                                            s1 += "jmp L" + to_string(label2) + "\n";
                                                            s1 += "L" + to_string(label1) + " " + yyvsp[0].cod;
                                                            s1 += "L" + to_string(label2) + " ";
                                                            yyval.cod = s1;

                                                      }
#line 1562 "plp5.tab.c"
    break;

  case 32: /* Instr: twhile pari Expr pard Instr  */
#line 289 "plp5.y"
                                                 {
                                                      int label1 = incrementarEtiqueta();
                                                      int label2 = incrementarEtiqueta();
                                                
                                                      s1 = "L" + to_string(label1) + " " + yyvsp[-2].cod;
                                                      s1 += "mov " + to_string(yyvsp[-2].dir) + " A\n";
                                                      s1 += "jz L" + to_string(label2) + "\n";
                                                      s1 += yyvsp[0].cod;
                                                      s1 += "jmp L" + to_string(label1) + "\n";
                                                      s1 += "L" + to_string(label2) + "\n";
                                                      yyval.cod = s1;
                                                }
#line 1579 "plp5.tab.c"
    break;

  case 33: /* $@8: %empty  */
#line 301 "plp5.y"
                                           {
                                                Simbolo *simb = tsimbs->buscar(yyvsp[-2].lexema);
                                                if(simb == nullptr){
                                                      errorSemantico(ERRNODECL, yyvsp[-2].lexema, yyvsp[-2].nlin, yyvsp[-2].ncol);
                                                }
                                                if(simb->tipo != ENTERO){
                                                      errorSemantico(ERR_NOENTERO, yyvsp[-2].lexema, yyvsp[-2].nlin, yyvsp[-2].ncol);
                                                }

                                                if((ttipos->tipos)[yyvsp[-2].tipo].clase == ARRAY){
                                                      errorSemantico(ERRFALTAN, yyvsp[-2].lexema, yyvsp[-2].nlin, yyvsp[-2].ncol);
                                                }
                                          }
#line 1597 "plp5.tab.c"
    break;

  case 34: /* $@9: %empty  */
#line 314 "plp5.y"
                                    {
                                          Simbolo *simb = tsimbs->buscar(yyvsp[0].lexema);
                                          if(simb == nullptr){
                                                errorSemantico(ERRNODECL, yyvsp[0].lexema, yyvsp[0].nlin, yyvsp[0].ncol);
                                          }
                                          if(simb->tipo != ENTERO){
                                                errorSemantico(ERR_NOENTERO, yyvsp[0].lexema, yyvsp[0].nlin, yyvsp[0].ncol);
                                          }

                                          if((ttipos->tipos)[yyvsp[-7].tipo].clase == ARRAY){
                                                errorSemantico(ERRFALTAN, yyvsp[0].lexema, yyvsp[0].nlin, yyvsp[0].ncol);
                                          }  
                                    }
#line 1615 "plp5.tab.c"
    break;

  case 35: /* Instr: tfor pari id asig Esimple $@8 pyc Expr pyc id $@9 incrdecr pard Instr  */
#line 327 "plp5.y"
                                              {                                                                       
                                                      s1 = yyvsp[-9].cod;
                                                                  
                                                      // id = Esimple
                                                      Simbolo *simb = tsimbs->buscar(yyvsp[-11].lexema);
                                                           
                                                      if (yyvsp[-9].tipo == REAL) {
                                                            s1 += "mov " + to_string(yyvsp[-9].dir) + " A\n";
                                                            s1 += "rtoi\n";
                                                            s1 += "mov A " + to_string(yyvsp[-9].dir) + "\n";
                                                      }

                                                      s1 += "mov #0 A\n";
                                                      s1 += "addi #" + to_string(simb->dir) + "\n";
                                                      s1 += "mov " + to_string(yyvsp[-9].dir) + " @A\n";

                                                      // Expr
                                                      int label1 = incrementarEtiqueta();
                                                      int label2 = incrementarEtiqueta(); 
                                                      s1 += "L" + to_string(label1) + " " + yyvsp[-6].cod;
                                                      s1 += "mov " + to_string(yyvsp[-6].dir) + " A\n";
                                                      s1 += "jz L" + to_string(label2) + "\n";
                                                      s1 += yyvsp[0].cod;
                                                      
                                                      // incrdecr
                                                      Simbolo *simb2 = tsimbs->buscar(yyvsp[-4].lexema);
                                                      s1 += "mov " + to_string(simb2->dir) + " A\n";
                                                      if( strcmp(yyvsp[-2].lexema, "++") == 0){
                                                            s1 += "addi #1\n";
                                                      }
                                                      else{
                                                            s1 += "subi #1\n";
                                                      }
                                                
                                                      s1 += "mov A " +  to_string(simb2->dir) + "\n";
                                                      s1 += "jmp L" + to_string(label1) + "\n";

                                                      // salir del for
                                                      s1 += "L" + to_string(label2) + " ";
                                                      yyval.cod = s1;


                                                }
#line 1663 "plp5.tab.c"
    break;

  case 36: /* Expr: Expr oprel Esimple  */
#line 372 "plp5.y"
                                          {
                                                s1 = yyvsp[-2].cod + yyvsp[0].cod;
                                                cont_pos_temps = nuevaTemporal(yyvsp[0].lexema, yyvsp[0].nlin, yyvsp[0].ncol);
                                                yyval.dir = cont_pos_temps;
                                                yyval.tipo = ENTERO;

                                                if(strcmp(yyvsp[-1].lexema, "==") == 0){
                                                      s2 = "eql";
                                                }
                                                else if(strcmp(yyvsp[-1].lexema, "!=") == 0){
                                                      s2 = "neq";
                                                }
                                                else if(strcmp(yyvsp[-1].lexema, ">") == 0){
                                                      s2 = "gtr";
                                                }
                                                else if(strcmp(yyvsp[-1].lexema, ">=") == 0){
                                                      s2 = "geq";
                                                }
                                                else if(strcmp(yyvsp[-1].lexema, "<") == 0){
                                                      s2 = "lss";
                                                }
                                                else{
                                                      s2 = "leq";
                                                }
                                                
                                                if(yyvsp[-2].tipo == yyvsp[0].tipo){
                                                      s1 += "mov " + to_string(yyvsp[-2].dir) + " A\n";
                                                      
                                                      if(yyvsp[-2].tipo == ENTERO){
                                                            s1 += s2 + "i " + to_string(yyvsp[0].dir) + "\n";
                                                      }
                                                      else{
                                                            s1 += s2 + "r " + to_string(yyvsp[0].dir) + "\n";
                                                      }
                                                }
                                                else if(yyvsp[-2].tipo == REAL && yyvsp[0].tipo == ENTERO){
                                                      s1 += "mov " + to_string(yyvsp[0].dir) + " A\n";
                                                      s1 += "itor\n";
                                                      s1 += "mov A " + to_string(cont_pos_temps) + "\n";
                                                      s1 += "mov " + to_string(yyvsp[-2].dir) + " A\n";
                                                      s1 += s2 + "r " + to_string(cont_pos_temps) + "\n";
                                                }
                                                else{
                                                      s1 += "mov " + to_string(yyvsp[-2].dir) + " A\n";
                                                      s1 += "itor\n";
                                                      s1 += s2 + "r " + to_string(yyvsp[0].dir) + "\n";
                                                }

                                                s1 += "mov A " + to_string(cont_pos_temps) + "\n";
                                                yyval.cod = s1;

                                          }
#line 1720 "plp5.tab.c"
    break;

  case 37: /* Expr: Esimple  */
#line 424 "plp5.y"
                              {
                                    yyval.cod = yyvsp[0].cod;
                                    yyval.dir = yyvsp[0].dir;
                                    yyval.tipo = yyvsp[0].tipo;

                              }
#line 1731 "plp5.tab.c"
    break;

  case 38: /* Esimple: Esimple opas Term  */
#line 432 "plp5.y"
                                    {
                                          s1 = yyvsp[-2].cod + yyvsp[0].cod;
                                          cont_pos_temps = nuevaTemporal(yyvsp[0].lexema, yyvsp[0].nlin, yyvsp[0].ncol);
                                          yyval.dir = cont_pos_temps;
                                          
                                          if(strcmp(yyvsp[-1].lexema, "+") == 0){
                                                s2 = "add";
                                          }else{
                                                s2 = "sub";
                                          }
                                          
                                          if(yyvsp[-2].tipo == yyvsp[0].tipo){
                                                yyval.tipo = yyvsp[-2].tipo;

                                                s1 += "mov " + to_string(yyvsp[-2].dir) + " A\n";
                                                
                                                if(yyvsp[-2].tipo == ENTERO){
                                                      s1 += s2 + "i " + to_string(yyvsp[0].dir) + "\n";
                                                }
                                                else{
                                                      s1 += s2 + "r " + to_string(yyvsp[0].dir) + "\n";
                                                }
                                          }
                                          else if(yyvsp[-2].tipo == REAL && yyvsp[0].tipo == ENTERO){
                                                yyval.tipo =  REAL;
                                                s1 += "mov " + to_string(yyvsp[0].dir) + " A\n";
                                                s1 += "itor\n";
                                                s1 += "mov A " + to_string(cont_pos_temps) + "\n";
                                                s1 += "mov " + to_string(yyvsp[-2].dir) + " A\n";
                                                s1 += s2 + "r " + to_string(cont_pos_temps) + "\n";
                                          }
                                          else{    
                                                yyval.tipo = REAL;
                                                s1 += "mov " + to_string(yyvsp[-2].dir) + " A\n";
                                                s1 += "itor\n";
                                                s1 += s2 + "r " + to_string(yyvsp[0].dir) + "\n";
                                          }

                                          s1 += "mov A " + to_string(cont_pos_temps) + "\n";
                                          yyval.cod = s1;


                                    }
#line 1779 "plp5.tab.c"
    break;

  case 39: /* Esimple: Term  */
#line 475 "plp5.y"
                        {     
                              yyval.cod = yyvsp[0].cod;
                              yyval.dir = yyvsp[0].dir;
                              yyval.tipo = yyvsp[0].tipo;
                        }
#line 1789 "plp5.tab.c"
    break;

  case 40: /* Term: Term opmd Factor  */
#line 482 "plp5.y"
                                    {     
                                          s1 = yyvsp[-2].cod + yyvsp[0].cod;
                                          cont_pos_temps = nuevaTemporal(yyvsp[0].lexema, yyvsp[0].nlin, yyvsp[0].ncol);
                                          yyval.dir = cont_pos_temps;
                                          
                                          if(strcmp(yyvsp[-1].lexema, "*") == 0){
                                                s2 = "mul";
                                          }else{
                                                s2 = "div";
                                          }
                                          
                                          if(yyvsp[-2].tipo == yyvsp[0].tipo){
                                                yyval.tipo = yyvsp[-2].tipo;

                                                s1 += "mov " + to_string(yyvsp[-2].dir) + " A\n";
                                                
                                                if(yyvsp[-2].tipo == ENTERO){
                                                      s1 += s2 + "i " + to_string(yyvsp[0].dir) + "\n";
                                                }
                                                else{
                                                      s1 += s2 + "r " + to_string(yyvsp[0].dir) + "\n";
                                                }
                                          }
                                          else if(yyvsp[-2].tipo == REAL && yyvsp[0].tipo == ENTERO){
                                                yyval.tipo =  REAL;
                                                s1 += "mov " + to_string(yyvsp[0].dir) + " A\n";
                                                s1 += "itor\n";
                                                s1 += "mov A " + to_string(cont_pos_temps) + "\n";
                                                s1 += "mov " + to_string(yyvsp[-2].dir) + " A\n";
                                                s1 += s2 + "r " + to_string(cont_pos_temps) + "\n";
                                          }
                                          else{    
                                                yyval.tipo = REAL;
                                                s1 += "mov " + to_string(yyvsp[-2].dir) + " A\n";
                                                s1 += "itor\n";
                                                s1 += s2 + "r " + to_string(yyvsp[0].dir) + "\n";
                                          }

                                          s1 += "mov A " + to_string(cont_pos_temps) + "\n";
                                          yyval.cod = s1;
                                    }
#line 1835 "plp5.tab.c"
    break;

  case 41: /* Term: Factor  */
#line 523 "plp5.y"
                              {     
                                    yyval.cod = yyvsp[0].cod;
                                    yyval.dir = yyvsp[0].dir;
                                    yyval.tipo = yyvsp[0].tipo;
                              }
#line 1845 "plp5.tab.c"
    break;

  case 42: /* Factor: Ref  */
#line 530 "plp5.y"
                        {     
                              if((ttipos->tipos)[yyvsp[0].tipo].clase == ARRAY){
                                    errorSemantico(ERRFALTAN, yyvsp[0].lexema, yyvsp[0].nlin, yyvsp[0].ncol);
                              }

                              s1 = yyvsp[0].cod;
                              cont_pos_temps = nuevaTemporal(yyvsp[0].lexema, yyvsp[0].nlin, yyvsp[0].ncol);
                              yyval.tipo = yyvsp[0].tipo;
                              yyval.dir = cont_pos_temps;

                              s1 += "mov " + to_string(yyvsp[0].dir) + " A\n";
                              s1 += "addi #" + to_string(yyvsp[0].dbase) + "\n";
                              s1 += "mov @A " + to_string(cont_pos_temps) + "\n";
                              yyval.cod = s1;
                        }
#line 1865 "plp5.tab.c"
    break;

  case 43: /* Factor: nentero  */
#line 545 "plp5.y"
                              {     yyval.tipo = ENTERO;
                                    cont_pos_temps = nuevaTemporal(yyvsp[0].lexema, yyvsp[0].nlin, yyvsp[0].ncol);
                                    yyval.dir = cont_pos_temps;
                                    s1 = "mov #" + string(yyvsp[0].lexema) + " " + to_string(cont_pos_temps) + "\n";
                                    yyval.cod = s1;
                              }
#line 1876 "plp5.tab.c"
    break;

  case 44: /* Factor: nreal  */
#line 551 "plp5.y"
                              {     yyval.tipo = REAL;
                                    cont_pos_temps = nuevaTemporal(yyvsp[0].lexema, yyvsp[0].nlin, yyvsp[0].ncol);
                                    yyval.dir = cont_pos_temps;
                                    yyval.cod = "mov $" + string(yyvsp[0].lexema) + " " + to_string(cont_pos_temps) + "\n";
                              }
#line 1886 "plp5.tab.c"
    break;

  case 45: /* Factor: pari Expr pard  */
#line 556 "plp5.y"
                                    {     yyval.cod = yyvsp[-1].cod;
                                          yyval.dir = yyvsp[-1].dir;
                                          yyval.tipo = yyvsp[-1].tipo;
                                    }
#line 1895 "plp5.tab.c"
    break;

  case 46: /* Ref: id  */
#line 562 "plp5.y"
                        {     Simbolo *simb = tsimbs->buscar(yyvsp[0].lexema);
                              if (simb == nullptr){
                                    errorSemantico(ERRNODECL, yyvsp[0].lexema, yyvsp[0].nlin, yyvsp[0].ncol);
                              }

                              cont_pos_temps = nuevaTemporal(yyvsp[0].lexema, yyvsp[0].nlin, yyvsp[0].ncol);
                              yyval.cod = "mov #0 " + to_string(cont_pos_temps) + "\n";
                              yyval.tipo = simb->tipo;
                              yyval.dbase = simb->dir;
                              yyval.dir = cont_pos_temps;

                              yyval.lexema = yyvsp[0].lexema;
                              yyval.nlin = yyvsp[0].nlin;
                              yyval.ncol = yyvsp[0].ncol;
                        }
#line 1915 "plp5.tab.c"
    break;

  case 47: /* $@10: %empty  */
#line 578 "plp5.y"
                        {     if (!esArray(yyvsp[-1].tipo)) {
                                    if(strcmp(yyvsp[-1].lexema, "]") == 0) {
                                       errorSemantico(ERRSOBRAN, yyvsp[0].lexema, yyvsp[0].nlin, yyvsp[0].ncol); 
                                    } else {
                                       errorSemantico(ERRSOBRAN, yyvsp[0].lexema, yyvsp[-1].nlin, yyvsp[-1].ncol);
                                    }
                                 }                   
                        }
#line 1928 "plp5.tab.c"
    break;

  case 48: /* Ref: Ref cori $@10 Esimple cord  */
#line 586 "plp5.y"
                              {     if(yyvsp[-1].tipo != ENTERO){
                                          errorSemantico(ERR_NOENTERO, yyvsp[0].lexema, yyvsp[0].nlin, yyvsp[0].ncol);
                                    }

                                    yyval.tipo = (ttipos->tipos)[yyvsp[-4].tipo].tipoBase;
                                    yyval.dbase = yyvsp[-4].dbase;

                                    cont_pos_temps = nuevaTemporal(yyvsp[-4].lexema, yyvsp[-4].nlin, yyvsp[-4].ncol);
                                    yyval.dir = cont_pos_temps;

                                    s1 = yyvsp[-4].cod + yyvsp[-1].cod;
                                    s1 += "mov " + to_string(yyvsp[-4].dir) + " A\n";
                                    s1 += "muli #" + to_string((ttipos->tipos)[yyvsp[-4].tipo].tamanyo) + "\n";
                                    s1 += "addi " + to_string(yyvsp[-1].dir) + "\n";
                                    s1 += "mov A " + to_string(cont_pos_temps) + "\n";

                                    yyval.cod = s1;

                                    yyval.lexema = yyvsp[0].lexema;
                                    yyval.nlin = yyvsp[0].nlin;
                                    yyval.ncol = yyvsp[0].ncol;

                              }
#line 1956 "plp5.tab.c"
    break;


#line 1960 "plp5.tab.c"

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
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

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
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
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
  ++yynerrs;

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

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
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
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
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
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 614 "plp5.y"


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


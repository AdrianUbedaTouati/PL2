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
#line 20 "plp4.y"


#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>


using namespace std;

#include "comun.h"
#include "TablaSimbolos.h"

// variables y funciones del A. Léxico
extern int ncol,nlin,findefichero;

extern int yylex();
extern char *yytext;
extern FILE *yyin;

int yyerror(char *s);

//varibles
TablaSimbolos *tablaSimbolos = new TablaSimbolos(nullptr);


//funciones
unsigned int nuevaVar(char *lexema, int nlin, int ncol);

string operador, s1, s2;  // string auxiliares


#line 105 "plp4.tab.c"

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

#include "plp4.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_funcion = 3,                    /* funcion  */
  YYSYMBOL_id = 4,                         /* id  */
  YYSYMBOL_pyc = 5,                        /* pyc  */
  YYSYMBOL_var = 6,                        /* var  */
  YYSYMBOL_fvar = 7,                       /* fvar  */
  YYSYMBOL_dosp = 8,                       /* dosp  */
  YYSYMBOL_tabla = 9,                      /* tabla  */
  YYSYMBOL_cori = 10,                      /* cori  */
  YYSYMBOL_cord = 11,                      /* cord  */
  YYSYMBOL_de = 12,                        /* de  */
  YYSYMBOL_coma = 13,                      /* coma  */
  YYSYMBOL_numentero = 14,                 /* numentero  */
  YYSYMBOL_ptopto = 15,                    /* ptopto  */
  YYSYMBOL_puntero = 16,                   /* puntero  */
  YYSYMBOL_entero = 17,                    /* entero  */
  YYSYMBOL_real = 18,                      /* real  */
  YYSYMBOL_blq = 19,                       /* blq  */
  YYSYMBOL_fblq = 20,                      /* fblq  */
  YYSYMBOL_asig = 21,                      /* asig  */
  YYSYMBOL_escribe = 22,                   /* escribe  */
  YYSYMBOL_pari = 23,                      /* pari  */
  YYSYMBOL_pard = 24,                      /* pard  */
  YYSYMBOL_opas = 25,                      /* opas  */
  YYSYMBOL_opmul = 26,                     /* opmul  */
  YYSYMBOL_numreal = 27,                   /* numreal  */
  YYSYMBOL_YYACCEPT = 28,                  /* $accept  */
  YYSYMBOL_X = 29,                         /* X  */
  YYSYMBOL_S = 30,                         /* S  */
  YYSYMBOL_31_1 = 31,                      /* @1  */
  YYSYMBOL_D = 32,                         /* D  */
  YYSYMBOL_33_2 = 33,                      /* @2  */
  YYSYMBOL_L = 34,                         /* L  */
  YYSYMBOL_35_3 = 35,                      /* @3  */
  YYSYMBOL_36_4 = 36,                      /* @4  */
  YYSYMBOL_V = 37,                         /* V  */
  YYSYMBOL_38_5 = 38,                      /* $@5  */
  YYSYMBOL_39_6 = 39,                      /* @6  */
  YYSYMBOL_C = 40,                         /* C  */
  YYSYMBOL_41_7 = 41,                      /* @7  */
  YYSYMBOL_A = 42,                         /* A  */
  YYSYMBOL_R = 43,                         /* R  */
  YYSYMBOL_G = 44,                         /* G  */
  YYSYMBOL_P = 45,                         /* P  */
  YYSYMBOL_Tipo = 46,                      /* Tipo  */
  YYSYMBOL_B = 47,                         /* B  */
  YYSYMBOL_48_8 = 48,                      /* $@8  */
  YYSYMBOL_49_9 = 49,                      /* @9  */
  YYSYMBOL_50_10 = 50,                     /* @10  */
  YYSYMBOL_SI = 51,                        /* SI  */
  YYSYMBOL_52_11 = 52,                     /* @11  */
  YYSYMBOL_53_12 = 53,                     /* @12  */
  YYSYMBOL_I = 54,                         /* I  */
  YYSYMBOL_55_13 = 55,                     /* $@13  */
  YYSYMBOL_56_14 = 56,                     /* @14  */
  YYSYMBOL_E = 57,                         /* E  */
  YYSYMBOL_T = 58,                         /* T  */
  YYSYMBOL_59_15 = 59,                     /* $@15  */
  YYSYMBOL_F = 60                          /* F  */
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
#define YYFINAL  5
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   50

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  28
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  33
/* YYNRULES -- Number of rules.  */
#define YYNRULES  46
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  77

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   282


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
      25,    26,    27
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    56,    56,    64,    64,    67,    71,    71,    75,    75,
      76,    76,    80,    87,    80,   104,   104,   109,   123,   126,
     127,   130,   143,   147,   153,   157,   163,   166,   168,   163,
     176,   176,   181,   181,   188,   188,   226,   235,   235,   240,
     258,   265,   264,   312,   319,   322,   325
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
  "\"end of file\"", "error", "\"invalid token\"", "funcion", "id", "pyc",
  "var", "fvar", "dosp", "tabla", "cori", "cord", "de", "coma",
  "numentero", "ptopto", "puntero", "entero", "real", "blq", "fblq",
  "asig", "escribe", "pari", "pard", "opas", "opmul", "numreal", "$accept",
  "X", "S", "@1", "D", "@2", "L", "@3", "@4", "V", "$@5", "@6", "C", "@7",
  "A", "R", "G", "P", "Tipo", "B", "$@8", "@9", "@10", "SI", "@11", "@12",
  "I", "$@13", "@14", "E", "T", "$@15", "F", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-37)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int8 yypact[] =
{
      -1,    11,    17,   -37,    15,   -37,    -1,   -37,   -37,   -37,
       2,   -37,    16,   -37,   -37,   -37,   -37,    18,    20,    -2,
      -3,   -37,    20,   -37,   -37,   -37,   -37,     5,     4,   -37,
     -37,   -37,    21,    -3,   -37,    -4,   -37,   -37,   -37,    -4,
     -37,   -37,   -37,   -16,     6,   -37,    -5,     8,   -37,    -4,
     -37,    24,    19,   -37,   -37,    23,   -37,   -37,   -37,     6,
      -4,    22,   -11,   -37,    -5,   -37,    25,     3,   -37,   -37,
     -37,    27,    26,    22,   -37,   -37,   -37
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       5,     0,     0,     2,     0,     1,     5,     3,    26,     4,
       0,    27,     0,     6,    28,    10,    32,     8,     0,     0,
      37,     7,     0,    12,    11,    30,    29,     0,     0,    33,
      26,     9,     0,    37,    34,     0,    38,    13,    31,     0,
      46,    44,    45,     0,    40,    43,     0,    35,    36,     0,
      41,     0,     0,    24,    25,     0,    15,    17,    23,    39,
       0,     0,     0,    14,     0,    42,     0,     0,    20,    22,
      16,     0,     0,     0,    21,    18,    19
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -37,   -37,    29,   -37,   -37,   -37,   -37,   -37,   -37,    28,
     -37,   -37,   -34,   -37,   -37,   -37,   -36,   -23,   -37,    12,
     -37,   -37,   -37,   -37,   -37,   -37,    10,   -37,   -37,     7,
       0,   -37,   -15
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     2,     3,     8,    14,    15,    17,    22,    18,    24,
      32,    46,    55,    64,    56,    67,    68,    57,    58,     9,
      10,    12,    16,    19,    33,    20,    29,    39,    30,    43,
      44,    60,    45
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      40,    27,     1,    25,    51,    52,    53,    54,    48,    49,
      41,    52,    53,    54,    72,     4,    73,     5,    26,    28,
       6,    11,    13,    42,    23,    21,    34,    35,    63,    37,
      70,    62,    50,    49,    61,     7,    66,    76,    75,    69,
      71,    74,    36,    38,     0,    65,    47,     0,     0,    59,
      31
};

static const yytype_int8 yycheck[] =
{
       4,     4,     3,     5,     9,    16,    17,    18,    24,    25,
      14,    16,    17,    18,    11,     4,    13,     0,    20,    22,
       5,    19,     6,    27,     4,     7,    21,    23,     5,     8,
      64,    12,    26,    25,    10,     6,    14,    73,    12,    62,
      15,    14,    30,    33,    -1,    60,    39,    -1,    -1,    49,
      22
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,    29,    30,     4,     0,     5,    30,    31,    47,
      48,    19,    49,     6,    32,    33,    50,    34,    36,    51,
      53,     7,    35,     4,    37,     5,    20,     4,    22,    54,
      56,    37,    38,    52,    21,    23,    47,     8,    54,    55,
       4,    14,    27,    57,    58,    60,    39,    57,    24,    25,
      26,     9,    16,    17,    18,    40,    42,    45,    46,    58,
      59,    10,    12,     5,    41,    60,    14,    43,    44,    45,
      40,    15,    11,    13,    14,    12,    44
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    28,    29,    31,    30,    30,    33,    32,    35,    34,
      36,    34,    38,    39,    37,    41,    40,    40,    42,    43,
      43,    44,    45,    45,    46,    46,    48,    49,    50,    47,
      52,    51,    53,    51,    55,    54,    54,    56,    54,    57,
      57,    59,    58,    58,    60,    60,    60
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     0,     6,     0,     0,     4,     0,     3,
       0,     2,     0,     0,     6,     0,     3,     1,     5,     3,
       1,     3,     3,     1,     1,     1,     0,     0,     0,     7,
       0,     4,     0,     2,     0,     4,     4,     0,     2,     3,
       1,     0,     4,     1,     1,     1,     1
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
  case 2: /* X: S  */
#line 56 "plp4.y"
          {/* comprobar que después del programa no hay ningún token más */
                int tk = yylex();
                if (tk != 0) yyerror("");
                else{
                    cout << yyvsp[0].cod.c_str() ;
                }
          }
#line 1201 "plp4.tab.c"
    break;

  case 3: /* @1: %empty  */
#line 64 "plp4.y"
                        {yyval.cod = yyvsp[-2].lexema;}
#line 1207 "plp4.tab.c"
    break;

  case 4: /* S: funcion id pyc S @1 B  */
#line 64 "plp4.y"
                                                 {
                                                    yyval.cod = yyvsp[-2].cod + "\n\nfloat " + yyvsp[-4].lexema + "()" + yyvsp[0].cod;
                                                }
#line 1215 "plp4.tab.c"
    break;

  case 5: /* S: %empty  */
#line 67 "plp4.y"
                         {yyval.cod = "";}
#line 1221 "plp4.tab.c"
    break;

  case 6: /* @2: %empty  */
#line 71 "plp4.y"
        { yyval.cod = yyvsp[-1].cod;}
#line 1227 "plp4.tab.c"
    break;

  case 7: /* D: var @2 L fvar  */
#line 71 "plp4.y"
                                   { yyval.cod = yyvsp[-1].cod; }
#line 1233 "plp4.tab.c"
    break;

  case 8: /* @3: %empty  */
#line 75 "plp4.y"
            { yyval.cod = yyvsp[-1].cod;}
#line 1239 "plp4.tab.c"
    break;

  case 9: /* L: L @3 V  */
#line 75 "plp4.y"
                                      { yyval.cod = yyvsp[-2].cod + yyvsp[0].cod;}
#line 1245 "plp4.tab.c"
    break;

  case 10: /* @4: %empty  */
#line 76 "plp4.y"
          { yyval.cod = yyvsp[0].cod;}
#line 1251 "plp4.tab.c"
    break;

  case 11: /* L: @4 V  */
#line 76 "plp4.y"
                                      { yyval.cod = yyvsp[0].cod; }
#line 1257 "plp4.tab.c"
    break;

  case 12: /* $@5: %empty  */
#line 80 "plp4.y"
       {
                if (strcmp(yyvsp[0].lexema, yyvsp[-1].cod.c_str()) == 0){
                    errorSemantico(ERRNOMFUNC,yyvsp[0].lexema,yyvsp[0].nlin,yyvsp[0].ncol);
                }
                if (tablaSimbolos->buscarAmbito(yyvsp[0].lexema) != nullptr){
                    errorSemantico(ERRYADECL,yyvsp[0].lexema,yyvsp[0].nlin,yyvsp[0].ncol);
                }
      }
#line 1270 "plp4.tab.c"
    break;

  case 13: /* @6: %empty  */
#line 87 "plp4.y"
              {
        yyval.cod = tablaSimbolos->crearVariable(yyvsp[-2].lexema);
      }
#line 1278 "plp4.tab.c"
    break;

  case 14: /* V: id $@5 dosp @6 C pyc  */
#line 90 "plp4.y"
              {
                  string idTrad = tablaSimbolos->crearVariable(yyvsp[-5].lexema);

                  Simbolo *simbolo = new Simbolo();
                  simbolo->nombre = yyvsp[-5].lexema;
                  simbolo->tipo = yyvsp[-1].tipo;
                  simbolo->nomtrad = idTrad;

                  tablaSimbolos->nuevoSimbolo(*simbolo);

                  yyval.cod = yyvsp[-1].cod + ";" + "\n";
              }
#line 1295 "plp4.tab.c"
    break;

  case 15: /* @7: %empty  */
#line 104 "plp4.y"
      {yyval.cod = yyvsp[-1].cod + yyvsp[0].cod;}
#line 1301 "plp4.tab.c"
    break;

  case 16: /* C: A @7 C  */
#line 105 "plp4.y"
                            {
                                yyval.tipo = TABLA;
                                yyval.cod = yyvsp[0].cod;
                            }
#line 1310 "plp4.tab.c"
    break;

  case 17: /* C: P  */
#line 110 "plp4.y"
         {
            if(yyval.tipo == PUNTERO){
                yyval.tipo = PUNTERO;
            }else if(yyval.tipo == ENTERO){
                yyval.tipo = ENTERO;
            }else if(yyval.tipo == REAL){
                yyval.tipo = REAL;
            }

            yyval.cod = yyvsp[0].cod + " " + yyvsp[-1].cod;
         }
#line 1326 "plp4.tab.c"
    break;

  case 18: /* A: tabla cori R cord de  */
#line 123 "plp4.y"
                             { yyval.cod = yyvsp[-2].cod; }
#line 1332 "plp4.tab.c"
    break;

  case 19: /* R: R coma G  */
#line 126 "plp4.y"
                 { yyval.cod = yyvsp[-2].cod + yyvsp[0].cod; }
#line 1338 "plp4.tab.c"
    break;

  case 20: /* R: G  */
#line 127 "plp4.y"
                 { yyval.cod = yyvsp[0].cod; }
#line 1344 "plp4.tab.c"
    break;

  case 21: /* G: numentero ptopto numentero  */
#line 130 "plp4.y"
                                   {
                                        int num1,num2;
                                        num1 = atoi(yyvsp[-2].lexema);
                                        num2 = atoi(yyvsp[0].lexema);

                                        if(num2<num1){
                                            errorSemantico(ERRRANGO,yyvsp[0].lexema,yyvsp[0].nlin,yyvsp[0].ncol);
                                        }

                                        yyval.cod = "["+to_string((num2-num1+1))+"]";
                                    }
#line 1360 "plp4.tab.c"
    break;

  case 22: /* P: puntero de P  */
#line 143 "plp4.y"
                     {
                        yyval.tipo = PUNTERO;
                        yyval.cod = yyvsp[0].cod + "*";
                     }
#line 1369 "plp4.tab.c"
    break;

  case 23: /* P: Tipo  */
#line 147 "plp4.y"
                     {
                        yyval.tipo = yyvsp[0].tipo;
                        yyval.cod = yyvsp[0].cod;
                     }
#line 1378 "plp4.tab.c"
    break;

  case 24: /* Tipo: entero  */
#line 153 "plp4.y"
                 {
                    yyval.cod = "int";
                    yyval.tipo = ENTERO;
                  }
#line 1387 "plp4.tab.c"
    break;

  case 25: /* Tipo: real  */
#line 157 "plp4.y"
                  {
                    yyval.tipo = REAL;
                    yyval.cod = "float";
                   }
#line 1396 "plp4.tab.c"
    break;

  case 26: /* $@8: %empty  */
#line 163 "plp4.y"
        {
            tablaSimbolos = new TablaSimbolos(tablaSimbolos);
        }
#line 1404 "plp4.tab.c"
    break;

  case 27: /* @9: %empty  */
#line 166 "plp4.y"
            {
            yyval.cod = yyvsp[-2].cod;
        }
#line 1412 "plp4.tab.c"
    break;

  case 28: /* @10: %empty  */
#line 168 "plp4.y"
            {
        yyval.cod = yyvsp[-4].cod;
        }
#line 1420 "plp4.tab.c"
    break;

  case 29: /* B: $@8 blq @9 D @10 SI fblq  */
#line 170 "plp4.y"
                  {
            tablaSimbolos = tablaSimbolos->getAmbitoAnterior();
            yyval.cod =  "\n{\n" + yyvsp[-3].cod + yyvsp[-1].cod + "\n}";
        }
#line 1429 "plp4.tab.c"
    break;

  case 30: /* @11: %empty  */
#line 176 "plp4.y"
            {
                yyval.cod = yyvsp[-2].cod;
             }
#line 1437 "plp4.tab.c"
    break;

  case 31: /* SI: SI pyc @11 I  */
#line 178 "plp4.y"
                 {
                    yyval.cod = yyvsp[-3].cod + yyvsp[0].cod;
                 }
#line 1445 "plp4.tab.c"
    break;

  case 32: /* @12: %empty  */
#line 181 "plp4.y"
       {
            yyval.cod = yyvsp[0].cod;
        }
#line 1453 "plp4.tab.c"
    break;

  case 33: /* SI: @12 I  */
#line 183 "plp4.y"
            {
            yyval.cod = yyvsp[0].cod;
        }
#line 1461 "plp4.tab.c"
    break;

  case 34: /* $@13: %empty  */
#line 188 "plp4.y"
            {
                 Simbolo *simbolo = tablaSimbolos->buscar(yyvsp[-1].lexema);
                 if(!(strcmp(yyvsp[-1].lexema, yyvsp[-2].cod.c_str()) == 0))
                 {
                    if(simbolo == nullptr)
                    {
                        errorSemantico(ERRNODECL,yyvsp[-1].lexema,yyvsp[-1].nlin,yyvsp[-1].ncol);
                    } else if(simbolo->tipo != ENTERO && simbolo->tipo != REAL)
                    {
                     errorSemantico(ERRNOSIMPLE,yyvsp[-1].lexema,yyvsp[-1].nlin,yyvsp[-1].ncol);
                    }
                  }
              }
#line 1479 "plp4.tab.c"
    break;

  case 35: /* I: id asig $@13 E  */
#line 200 "plp4.y"
                  {

                if(strcmp(yyvsp[-3].lexema, yyvsp[-4].cod.c_str()) == 0)
                {
                    if(REAL == yyvsp[0].tipo)
                    {
                        yyval.cod = "\n  return " + yyvsp[0].cod + ";";
                    } else
                    {
                        yyval.cod = "\n  return itor(" + yyvsp[0].cod + ");";
                    }
                } else
                {
                    Simbolo *simbolo = tablaSimbolos->buscar(yyvsp[-3].lexema);
                    if(simbolo->tipo == yyvsp[0].tipo)
                    {
                        yyval.cod = "\n  "+simbolo->nomtrad + " = " + yyvsp[0].cod+";";
                    } if(simbolo->tipo == REAL && yyvsp[0].tipo == ENTERO)
                    {
                        yyval.cod = "\n  "+simbolo->nomtrad + " = " + "itor("+yyvsp[0].cod+")"+";";
                    } else if (simbolo->tipo == ENTERO && yyvsp[0].tipo == REAL)
                    {
                       errorSemantico(ERRTIPOS,yyvsp[-2].lexema,yyvsp[-2].nlin,yyvsp[-2].ncol);
                    }
                }
           }
#line 1510 "plp4.tab.c"
    break;

  case 36: /* I: escribe pari E pard  */
#line 226 "plp4.y"
                            {
                                if(REAL == yyvsp[-1].tipo)
                                {
                                    yyval.cod = "\n  printf(\"%f\","+ yyvsp[-1].cod +");";
                                } else
                                {
                                   yyval.cod = "\n  printf(\"%d\","+ yyvsp[-1].cod +");";
                                }
                             }
#line 1524 "plp4.tab.c"
    break;

  case 37: /* @14: %empty  */
#line 235 "plp4.y"
       {yyval.cod = yyvsp[0].cod;}
#line 1530 "plp4.tab.c"
    break;

  case 38: /* I: @14 B  */
#line 235 "plp4.y"
                            {
                              yyval.cod = yyvsp[0].cod;
                           }
#line 1538 "plp4.tab.c"
    break;

  case 39: /* E: E opas T  */
#line 240 "plp4.y"
               {
                    if(yyvsp[-2].tipo == REAL && yyvsp[0].tipo == REAL)
                    {
                        yyval.cod = yyvsp[-2].cod +" " + yyvsp[-1].lexema + "r " + yyvsp[0].cod;
                        yyval.tipo  = REAL;
                    } else if (yyvsp[-2].tipo == REAL && yyvsp[0].tipo == ENTERO)
                    {
                       yyval.cod = yyvsp[-2].cod + " " +yyvsp[-1].lexema + "r " + "itor(" + yyvsp[0].cod +")";
                       yyval.tipo  = REAL;
                    } else if (yyvsp[-2].tipo == ENTERO && yyvsp[0].tipo == REAL)
                    {
                       yyval.cod = "itor(" + yyvsp[-2].cod + ") " + yyvsp[-1].lexema + "r " + yyvsp[0].cod;
                       yyval.tipo  = REAL;
                    } else{
                       yyval.cod = yyvsp[-2].cod +" " + yyvsp[-1].lexema + "i " + yyvsp[0].cod;
                       yyval.tipo  = ENTERO;
                    }
               }
#line 1561 "plp4.tab.c"
    break;

  case 40: /* E: T  */
#line 258 "plp4.y"
          {
             yyval.cod = yyvsp[0].cod;
             yyval.tipo = yyvsp[0].tipo;
          }
#line 1570 "plp4.tab.c"
    break;

  case 41: /* $@15: %empty  */
#line 265 "plp4.y"
            {
                if(strcmp(yyvsp[0].lexema, "//") == 0 || strcmp(yyvsp[0].lexema, "%") == 0)
                {
                    if(yyvsp[-1].tipo == REAL){
                        errorSemantico(ERRNOENTEROIZQ, yyvsp[0].lexema,yyvsp[0].nlin, yyvsp[0].ncol);
                    }
                }
             }
#line 1583 "plp4.tab.c"
    break;

  case 42: /* T: T opmul $@15 F  */
#line 272 "plp4.y"
                 {
                    if(strcmp(yyvsp[-2].lexema, "//") == 0 || strcmp(yyvsp[-2].lexema, "%") == 0)
                    {
                        if(yyvsp[0].tipo == REAL)
                        {
                           errorSemantico(ERRNOENTERODER, yyvsp[-2].lexema, yyvsp[-2].nlin, yyvsp[-2].ncol);
                         }
                    }

                    if(yyvsp[-3].tipo == REAL && yyvsp[0].tipo == REAL){
                        yyval.tipo = REAL;
                        yyval.cod =  yyvsp[-3].cod + " " + yyvsp[-2].lexema + "r " + yyvsp[0].cod;
                    } else if(yyvsp[-3].tipo == REAL && yyvsp[0].tipo == ENTERO)
                    {
                        yyval.cod = yyvsp[-3].cod + " " +yyvsp[-2].lexema + "r " + "itor(" + yyvsp[0].cod + ")";
                        yyval.tipo = REAL;
                    }else if (yyvsp[-3].tipo == ENTERO && yyvsp[0].tipo == REAL) {
                        yyval.cod = "itor(" + yyvsp[-3].cod + ")" +" " + yyvsp[-2].lexema + "r " + yyvsp[0].cod;
                        yyval.tipo = REAL;
                     } else{
                        if(strcmp("%", yyvsp[-2].lexema) == 0)
                        {
                             yyval.cod = yyvsp[-3].cod+" " + yyvsp[-2].lexema +" " + yyvsp[0].cod;
                             yyval.tipo = ENTERO;
                        }else if(strcmp("//", yyvsp[-2].lexema) == 0)
                        {
                             yyval.cod = yyvsp[-3].cod +" " + "/i " + yyvsp[0].cod;
                             yyval.tipo = ENTERO;
                        }
                        else if(strcmp("/", yyvsp[-2].lexema) == 0)
                        {
                             yyval.cod = "itor("+yyvsp[-3].cod+")" +" " + yyvsp[-2].lexema + "r " +"itor("+ yyvsp[0].cod + ")";
                             yyval.tipo = REAL;
                         }
                         else{
                             yyval.cod = yyvsp[-3].cod +" " + yyvsp[-2].lexema + "i " + yyvsp[0].cod;
                             yyval.tipo = ENTERO;
                         }
                      }
                }
#line 1628 "plp4.tab.c"
    break;

  case 43: /* T: F  */
#line 313 "plp4.y"
     {
           yyval.cod = yyvsp[0].cod;
           yyval.tipo = yyvsp[0].tipo;
     }
#line 1637 "plp4.tab.c"
    break;

  case 44: /* F: numentero  */
#line 319 "plp4.y"
                 { yyval.tipo = ENTERO;
                   yyval.cod = yyvsp[0].lexema;
                  }
#line 1645 "plp4.tab.c"
    break;

  case 45: /* F: numreal  */
#line 322 "plp4.y"
                  { yyval.tipo = REAL;
                    yyval.cod = yyvsp[0].lexema;
                  }
#line 1653 "plp4.tab.c"
    break;

  case 46: /* F: id  */
#line 325 "plp4.y"
                  {
                    Simbolo *simbolo = tablaSimbolos->buscar(yyvsp[0].lexema);

                    if (simbolo == nullptr){
                       errorSemantico(ERRNODECL, yyvsp[0].lexema, yyvsp[0].nlin, yyvsp[0].ncol);
                    }else if(simbolo->tipo !=  ENTERO && simbolo->tipo != REAL) {
                       errorSemantico(ERRNOSIMPLE, yyvsp[0].lexema, yyvsp[0].nlin, yyvsp[0].ncol);
                    }

                    yyval.cod = simbolo->nomtrad;
                    yyval.tipo = simbolo->tipo;
                   }
#line 1670 "plp4.tab.c"
    break;


#line 1674 "plp4.tab.c"

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

#line 339 "plp4.y"


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
      case ERRYADECL: fprintf(stderr,"ya existe en este ambito\n");
         break;
      case ERRNOMFUNC: fprintf(stderr,"no puede llamarse igual que la funcion");
         break;
      case ERRNOSIMPLE: fprintf(stderr,"debe ser de tipo entero o real\n");
         break;
      case ERRNODECL: fprintf(stderr,"no ha sido declarado\n");
         break;
      case ERRTIPOS: fprintf(stderr,"tipos incompatibles entero/real\n");
         break;
      case ERRNOENTEROIZQ: fprintf(stderr,"el operando izquierdo debe ser entero\n");
         break;
      case ERRNOENTERODER: fprintf(stderr,"el operando derecho debe ser entero\n");
         break;
      case ERRRANGO: fprintf(stderr,"rango incorrecto\n");
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

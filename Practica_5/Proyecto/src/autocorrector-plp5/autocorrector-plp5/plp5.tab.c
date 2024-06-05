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
#line 23 "plp5.y"


#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>


using namespace std;

#include "comun.h"
#include "TablaSimbolos.h"
#include "TablaTipos.h"

// variables y funciones del A. Léxico
extern int ncol,nlin,findefichero;

extern int yylex();
extern char *yytext;
extern FILE *yyin;

int yyerror(char *s);

//Direciones
int LIM_DIR_TEMP = 16383;
int LIM_DIR_VAR = 15999;


//varibles objeto
TablaTipos *tablaTipos = new TablaTipos();
TablaSimbolos *tablaSimbolos = new TablaSimbolos(nullptr);


//variables
unsigned int numtemp = 16000;
unsigned int numetq = 0;
unsigned int numvar = 0;



//funciones
unsigned int nVar(char *lexema, int nlin, int ncol);
unsigned int nTemp(int nlin, int ncol);
unsigned int nEtiqueta(void);

bool isArray(int tipo);


#line 121 "plp5.tab.c"

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
  YYSYMBOL_35_1 = 35,                      /* @1  */
  YYSYMBOL_36_2 = 36,                      /* $@2  */
  YYSYMBOL_BDecl = 37,                     /* BDecl  */
  YYSYMBOL_DVar = 38,                      /* DVar  */
  YYSYMBOL_39_3 = 39,                      /* @3  */
  YYSYMBOL_LIdent = 40,                    /* LIdent  */
  YYSYMBOL_41_4 = 41,                      /* @4  */
  YYSYMBOL_42_5 = 42,                      /* @5  */
  YYSYMBOL_Variable = 43,                  /* Variable  */
  YYSYMBOL_44_6 = 44,                      /* @6  */
  YYSYMBOL_V = 45,                         /* V  */
  YYSYMBOL_46_7 = 46,                      /* @7  */
  YYSYMBOL_SeqInstr = 47,                  /* SeqInstr  */
  YYSYMBOL_Instr = 48,                     /* Instr  */
  YYSYMBOL_Expr = 49,                      /* Expr  */
  YYSYMBOL_Esimple = 50,                   /* Esimple  */
  YYSYMBOL_Term = 51,                      /* Term  */
  YYSYMBOL_Factor = 52,                    /* Factor  */
  YYSYMBOL_Ref = 53,                       /* Ref  */
  YYSYMBOL_54_8 = 54                       /* $@8  */
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
#define YYLAST   109

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  30
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  25
/* YYNRULES -- Number of rules.  */
#define YYNRULES  46
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  103

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
       0,    75,    75,    84,    87,    90,    91,    94,    95,    94,
     101,   102,   105,   105,   108,   108,   109,   109,   112,   112,
     133,   134,   134,   145,   146,   149,   150,   151,   176,   204,
     231,   246,   268,   287,   293,   363,   368,   431,   436,   497,
     504,   522,   531,   539,   546,   565,   565
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
  "tscanf", "$accept", "S", "FVM", "Tipo", "Bloque", "@1", "$@2", "BDecl",
  "DVar", "@3", "LIdent", "@4", "@5", "Variable", "@6", "V", "@7",
  "SeqInstr", "Instr", "Expr", "Esimple", "Term", "Factor", "Ref", "$@8", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-68)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int8 yypact[] =
{
      37,    18,   -68,    17,   -68,   -68,    37,    13,   -68,   -68,
     -68,    16,    32,    51,    19,   -68,   -68,   -68,   -68,   -68,
     -68,    51,    31,   -68,   -68,    52,   -68,    44,    39,   -68,
     -68,     3,   -68,    49,    50,    53,    55,   -68,   -68,    56,
     -68,    29,   -68,   -17,    31,    41,    14,    14,    62,    47,
     -68,    14,   -68,   -68,    61,   -68,   -68,    14,    33,    48,
      57,   -68,    58,    35,    59,    64,    20,    14,    14,    40,
       3,    14,    14,    14,     3,    14,    54,   -68,    12,    43,
     -68,    71,    48,    57,   -68,   -68,     0,    72,   -68,    67,
       3,    14,   -15,   -68,   -68,    22,    69,    74,   -68,    60,
      70,     3,   -68
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     5,     6,     0,     2,    12,     0,     0,     1,    16,
       3,     0,     0,     0,     0,    14,    13,    18,    17,     7,
       4,     0,    20,    11,    15,     0,    19,    24,     0,     5,
      10,     8,    21,     0,     0,     0,     0,    44,    25,     0,
      26,     0,    23,     0,    20,     0,     0,     0,     0,     0,
       9,     0,    45,    22,     0,    41,    42,     0,     0,    35,
      37,    39,    40,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    27,     0,     0,
      43,    30,    34,    36,    38,    32,     0,     0,    46,     0,
       0,     0,     0,    28,    31,     0,     0,     0,    29,     0,
       0,     0,    33
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -68,   -68,    80,   -68,    75,   -68,   -68,   -68,    63,   -68,
     -68,   -68,   -68,    73,   -68,    65,   -68,   -68,   -67,   -46,
     -51,    21,    23,   -31,   -68
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     3,     4,     5,    40,    23,    41,    27,     6,     9,
      12,    21,    13,    18,    22,    26,    44,    31,    42,    58,
      59,    60,    61,    62,    67
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      43,    63,    96,    81,    51,    66,    52,    85,    52,    33,
      34,    69,    35,    36,    37,    91,    78,     8,    38,    72,
      82,     7,    79,    94,    86,    37,    55,    56,    19,    11,
      57,    72,    39,    14,   102,    77,    88,    97,    71,    43,
      71,     1,     2,    43,    19,    95,    15,    16,    29,     2,
      70,    71,    74,    71,    25,    50,    92,    80,    71,    43,
      89,    71,    17,    32,    28,    45,    46,    72,    54,    47,
      43,    48,    49,    64,    65,    68,    87,    73,    76,    90,
      75,    52,    93,    37,    98,    99,    10,   101,   100,    20,
      30,     0,     0,    83,    24,     0,    84,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    53
};

static const yytype_int8 yycheck[] =
{
      31,    47,    17,    70,    21,    51,    23,    74,    23,     6,
       7,    57,     9,    10,    11,    15,    67,     0,    15,    19,
      71,     3,    68,    90,    75,    11,    12,    13,    25,    16,
      16,    19,    29,    17,   101,    15,    24,    15,    18,    70,
      18,     4,     5,    74,    25,    91,    14,    15,     4,     5,
      17,    18,    17,    18,    23,    26,    87,    17,    18,    90,
      17,    18,    11,    24,    12,    16,    16,    19,    27,    16,
     101,    16,    16,    11,    27,    14,    22,    20,    14,     8,
      21,    23,    15,    11,    15,    11,     6,    17,    28,    14,
      27,    -1,    -1,    72,    21,    -1,    73,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    44
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     4,     5,    31,    32,    33,    38,     3,     0,    39,
      32,    16,    40,    42,    17,    14,    15,    11,    43,    25,
      34,    41,    44,    35,    43,    23,    45,    37,    12,     4,
      38,    47,    24,     6,     7,     9,    10,    11,    15,    29,
      34,    36,    48,    53,    46,    16,    16,    16,    16,    16,
      26,    21,    23,    45,    27,    12,    13,    16,    49,    50,
      51,    52,    53,    49,    11,    27,    49,    54,    14,    49,
      17,    18,    19,    20,    17,    21,    14,    15,    50,    49,
      17,    48,    50,    51,    52,    48,    50,    22,    24,    17,
       8,    15,    53,    15,    48,    49,    17,    15,    15,    11,
      28,    17,    48
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    30,    31,    32,    32,    33,    33,    35,    36,    34,
      37,    37,    39,    38,    41,    40,    42,    40,    44,    43,
      45,    46,    45,    47,    47,    48,    48,    48,    48,    48,
      48,    48,    48,    48,    49,    49,    50,    50,    51,    51,
      52,    52,    52,    52,    53,    54,    53
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     5,     1,     1,     0,     0,     6,
       2,     0,     0,     4,     0,     4,     0,     2,     0,     3,
       0,     0,     5,     2,     0,     1,     1,     4,     7,     8,
       5,     7,     5,    12,     3,     1,     3,     1,     3,     1,
       1,     1,     1,     3,     1,     0,     5
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
#line 75 "plp5.y"
            {/* comprobar que después del programa no hay ningún token más */
                int tk = yylex();
                if (tk != 0) yyerror("");
                else{
                    cout << yyvsp[0].cod.c_str() ;
                }
          }
#line 1228 "plp5.tab.c"
    break;

  case 3: /* FVM: DVar FVM  */
#line 84 "plp5.y"
                  {
                    yyval.cod = yyvsp[-1].cod + yyvsp[0].cod;
                 }
#line 1236 "plp5.tab.c"
    break;

  case 4: /* FVM: tint tmain pari pard Bloque  */
#line 87 "plp5.y"
                                    {yyval.cod = yyvsp[0].cod;}
#line 1242 "plp5.tab.c"
    break;

  case 5: /* Tipo: tint  */
#line 90 "plp5.y"
                {yyval.cod = yyvsp[0].tipo;}
#line 1248 "plp5.tab.c"
    break;

  case 6: /* Tipo: tfloat  */
#line 91 "plp5.y"
                {yyval.cod = yyvsp[0].tipo;}
#line 1254 "plp5.tab.c"
    break;

  case 7: /* @1: %empty  */
#line 94 "plp5.y"
                { tablaSimbolos = new TablaSimbolos(tablaSimbolos); }
#line 1260 "plp5.tab.c"
    break;

  case 8: /* $@2: %empty  */
#line 95 "plp5.y"
                        { tablaSimbolos = tablaSimbolos->getAmbitoAnterior(); }
#line 1266 "plp5.tab.c"
    break;

  case 9: /* Bloque: llavei @1 BDecl SeqInstr $@2 llaved  */
#line 96 "plp5.y"
         {
            yyval.cod = yyvsp[-4].cod + yyvsp[-3].cod;
         }
#line 1274 "plp5.tab.c"
    break;

  case 10: /* BDecl: BDecl DVar  */
#line 101 "plp5.y"
                    {yyval.cod = "";}
#line 1280 "plp5.tab.c"
    break;

  case 11: /* BDecl: %empty  */
#line 102 "plp5.y"
                         {yyval.cod = "";}
#line 1286 "plp5.tab.c"
    break;

  case 12: /* @3: %empty  */
#line 105 "plp5.y"
             {yyval.tipo = yyvsp[-1].tipo;}
#line 1292 "plp5.tab.c"
    break;

  case 13: /* DVar: Tipo @3 LIdent pyc  */
#line 105 "plp5.y"
                                             {yyval.cod = "";}
#line 1298 "plp5.tab.c"
    break;

  case 14: /* @4: %empty  */
#line 108 "plp5.y"
                     {yyval.tipo = yyvsp[-2].tipo;}
#line 1304 "plp5.tab.c"
    break;

  case 15: /* LIdent: LIdent coma @4 Variable  */
#line 108 "plp5.y"
                                                   {yyval.cod = "";}
#line 1310 "plp5.tab.c"
    break;

  case 16: /* @5: %empty  */
#line 109 "plp5.y"
         {yyval.tipo = yyvsp[0].tipo;}
#line 1316 "plp5.tab.c"
    break;

  case 17: /* LIdent: @5 Variable  */
#line 109 "plp5.y"
                                       {yyval.cod = "";}
#line 1322 "plp5.tab.c"
    break;

  case 18: /* @6: %empty  */
#line 112 "plp5.y"
              {
                   if (tablaSimbolos->buscarAmbito(yyvsp[0].lexema)!=nullptr) {
                     errorSemantico(ERRYADECL, yyvsp[0].lexema,yyvsp[0].nlin, yyvsp[0].ncol);
                   }
                   yyval.tipo = yyvsp[-1].tipo;
               }
#line 1333 "plp5.tab.c"
    break;

  case 19: /* Variable: id @6 V  */
#line 118 "plp5.y"
             {
                Simbolo *simbolo = new Simbolo();
                simbolo->dir = nVar(yyvsp[-2].lexema, yyvsp[-2].nlin, yyvsp[-2].ncol);
                simbolo->nombre = yyvsp[-2].lexema;
                simbolo->tam = yyvsp[0].tam;
                simbolo->tipo = yyvsp[0].tipo;

                if (numvar + simbolo->tam >= LIM_DIR_VAR) {
                    errorSemantico(ERR_NOCABE,yyvsp[-2].lexema, yyvsp[-2].nlin, yyvsp[-2].ncol);
                }
                numvar += simbolo->tam;
                tablaSimbolos->nuevoSimbolo(*simbolo);
             }
#line 1351 "plp5.tab.c"
    break;

  case 20: /* V: %empty  */
#line 133 "plp5.y"
     {yyval.tipo = yyvsp[0].tipo; yyval.tam = yyvsp[0].tam;}
#line 1357 "plp5.tab.c"
    break;

  case 21: /* @7: %empty  */
#line 134 "plp5.y"
                      {yyval.tam = 1; yyval.tipo = yyvsp[-3].tipo;}
#line 1363 "plp5.tab.c"
    break;

  case 22: /* V: cori nentero cord @7 V  */
#line 135 "plp5.y"
    {
      if(stoi(yyvsp[-3].lexema) > 0){
        yyval.tipo = tablaTipos->nuevoTipoArray(stoi(yyvsp[-3].lexema),yyvsp[0].tipo);
        yyval.tam = yyvsp[0].tam * stoi(yyvsp[-3].lexema);
      } else {
        errorSemantico(ERRDIM,yyvsp[-3].lexema, yyvsp[-3].nlin, yyvsp[-3].ncol);
      }
  }
#line 1376 "plp5.tab.c"
    break;

  case 23: /* SeqInstr: SeqInstr Instr  */
#line 145 "plp5.y"
                          {yyval.cod = yyvsp[-1].cod + yyvsp[0].cod;}
#line 1382 "plp5.tab.c"
    break;

  case 24: /* SeqInstr: %empty  */
#line 146 "plp5.y"
                           {yyval.cod = "";}
#line 1388 "plp5.tab.c"
    break;

  case 25: /* Instr: pyc  */
#line 149 "plp5.y"
              {yyval.cod = "";}
#line 1394 "plp5.tab.c"
    break;

  case 26: /* Instr: Bloque  */
#line 150 "plp5.y"
                  {yyval.cod = yyvsp[0].cod;}
#line 1400 "plp5.tab.c"
    break;

  case 27: /* Instr: Ref asig Expr pyc  */
#line 151 "plp5.y"
                             {
                                 if ((tablaTipos->tipos)[yyvsp[-3].tipo].clase == ARRAY) {
                                    errorSemantico(ERRFALTAN,yyvsp[-3].lexema, yyvsp[-3].nlin, yyvsp[-3].ncol);
                                 }else{
                                    yyval.cod = yyvsp[-3].cod + yyvsp[-1].cod;
                                 }

                                 if (yyvsp[-1].tipo == ENTERO && yyvsp[-3].tipo == REAL) {
                                    string dir3 = to_string(yyvsp[-1].dir);
                                    yyval.cod += "mov " + dir3 + " A" + "\n";
                                    yyval.cod += "itor\n";

                                    string dir3_2 = to_string(yyvsp[-1].dir);
                                    yyval.cod += "mov A " + dir3_2 + "\n";
                                 }

                                     string dir1 = to_string(yyvsp[-3].dir);
                                     yyval.cod += "mov " + dir1 + " A" + "\n";

                                     string dbase_1 =  to_string(yyvsp[-3].dbase);
                                     yyval.cod += "addi #" + dbase_1 + "\n";

                                     string dir3_3 = to_string(yyvsp[-1].dir);
                                     yyval.cod += "mov " + dir3_3 + " @A\n";
                                }
#line 1430 "plp5.tab.c"
    break;

  case 28: /* Instr: tprintf pari formato coma Expr pard pyc  */
#line 176 "plp5.y"
                                                   {
                                                        yyval.cod = yyvsp[-2].cod;
                                                        if(yyvsp[-4].lexema == "\"%d\""){
                                                            if(yyvsp[-2].tipo != ENTERO){
                                                                string dir5 = to_string(yyvsp[-2].dir);
                                                                yyval.cod += "mov " + dir5 + " A" + "\n";
                                                                yyval.cod += "rtoi\n";
                                                                yyval.cod += "wri A\n";
                                                            } else {
                                                                string dir5 = to_string(yyvsp[-2].dir);
                                                                yyval.cod += "mov " + dir5 + " A" + "\n";
                                                                yyval.cod += "wri A\n";
                                                            }
                                                        } else {
                                                            if(yyvsp[-2].tipo == ENTERO){
                                                                string dir5 = to_string(yyvsp[-2].dir);
                                                                yyval.cod += "mov " + dir5 + " A" + "\n";
                                                                yyval.cod += "itor\n";
                                                                yyval.cod += "wrr A\n";
                                                            } else {
                                                                string dir5 = to_string(yyvsp[-2].dir);
                                                                yyval.cod += "mov " + dir5 + " A" + "\n";
                                                                yyval.cod += "wrr A\n";
                                                            }
                                                        }
                                                        yyval.cod += "wrl \n";
                                                  }
#line 1462 "plp5.tab.c"
    break;

  case 29: /* Instr: tscanf pari formato coma referencia Ref pard pyc  */
#line 204 "plp5.y"
                                                            {
                                                             if ((tablaTipos->tipos)[yyvsp[-2].tipo].clase == ARRAY) {
                                                                errorSemantico(ERRFALTAN, yyvsp[-2].lexema, yyvsp[-2].nlin, yyvsp[-2].ncol);
                                                             } else {
                                                                yyval.cod = yyvsp[-2].cod;

                                                                if(yyvsp[-2].tipo ==  ENTERO) {
                                                                    yyval.cod += "rdi A\n";
                                                                    if(yyvsp[-5].lexema == "\"%g\""){
                                                                        yyval.cod += "itor\n";
                                                                    }
                                                                }else {
                                                                    yyval.cod += "rdr A\n";
                                                                    if(yyvsp[-5].lexema == "\"%d\""){
                                                                        yyval.cod += "rtoi\n";
                                                                    }
                                                                }
                                                                string stemp = to_string(nTemp(yyvsp[-2].nlin,yyvsp[-2].ncol));
                                                                yyval.cod = "mov A" + stemp + "\n";
                                                                string dir6 = to_string(yyvsp[-2].dir);

                                                                yyval.cod = "mov " + dir6 + " A" + "\n";
                                                                string dbase = to_string(yyvsp[-2].dbase);
                                                                yyval.cod = "addi #" + dbase +"\n";
                                                                yyval.cod = "mov " + stemp +" @A\n";
                                                             }
                                                           }
#line 1494 "plp5.tab.c"
    break;

  case 30: /* Instr: tif pari Expr pard Instr  */
#line 231 "plp5.y"
                                    {
                                         yyval.cod = yyvsp[-2].cod;

                                         string dir3 = to_string(yyvsp[-2].dir);
                                         yyval.cod += "mov " + dir3 + " A" + "\n";

                                         int etiqueta = nEtiqueta();
                                         string setiqueta = to_string(etiqueta);

                                         yyval.cod += "jz L" + setiqueta +"\n";

                                         yyval.cod += yyvsp[0].cod;

                                         yyval.cod += "L" + setiqueta + " ";
                                    }
#line 1514 "plp5.tab.c"
    break;

  case 31: /* Instr: tif pari Expr pard Instr telse Instr  */
#line 246 "plp5.y"
                                                {

                                                 yyval.cod = yyvsp[-4].cod;

                                                 string dir2 = to_string(yyvsp[-4].dir);
                                                 yyval.cod += "mov " + dir2 + " A\n";

                                                 int etiqueta_1 = nEtiqueta();
                                                 string setiqueta_1 = to_string(etiqueta_1);

                                                 yyval.cod += "jz L" + setiqueta_1 + "\n";

                                                 yyval.cod += yyvsp[-2].cod;

                                                 int etiqueta_2 = nEtiqueta();
                                                 string setiqueta_2 = to_string(etiqueta_2);

                                                 yyval.cod += "jmp L" + setiqueta_2 + "\n";

                                                 yyval.cod += "L" + setiqueta_1 + " " + yyvsp[0].cod;
                                                 yyval.cod += "L" + setiqueta_2 + " ";
                                              }
#line 1541 "plp5.tab.c"
    break;

  case 32: /* Instr: twhile pari Expr pard Instr  */
#line 268 "plp5.y"
                                       {
                                           int etiqueta_1 = nEtiqueta();
                                           string setiqueta_1 = to_string(etiqueta_1);

                                           yyval.cod = "L" + setiqueta_1 + " " + yyvsp[-2].cod;

                                           string dir2 = to_string(yyvsp[-3].dir);
                                           yyval.cod += "mov " + dir2 + " A" +"\n";

                                           int etiqueta_2 = nEtiqueta();
                                           string setiqueta_2 = to_string(etiqueta_2);
                                           yyval.cod += "jz L" + setiqueta_2 + "\n";

                                           yyval.cod += yyvsp[0].cod;

                                           yyval.cod += "jmp L" + setiqueta_1 + "\n";

                                           yyval.cod += "L" + setiqueta_2 + " ";
                                      }
#line 1565 "plp5.tab.c"
    break;

  case 33: /* Instr: tfor pari id asig Esimple pyc Expr pyc id incrdecr pard Instr  */
#line 288 "plp5.y"
                                       {

                                        }
#line 1573 "plp5.tab.c"
    break;

  case 34: /* Expr: Expr oprel Esimple  */
#line 293 "plp5.y"
                          {
                                    yyval.dir = nTemp(yyvsp[0].nlin, yyvsp[0].ncol);
                                    yyval.cod = yyvsp[-2].cod + yyvsp[0].cod;
                                    yyval.tipo = ENTERO;

                                     string op = "";
                                     if (yyvsp[-1].lexema ==  ">") {
                                        op = "gtr";
                                     } else if (yyvsp[-1].lexema == "<") {
                                        op = "lss";
                                     } else if (yyvsp[-1].lexema ==  "<>") {
                                        op = "neq";
                                     } else if (yyvsp[-1].lexema ==  "=") {
                                        op = "eql";
                                     } else if (yyvsp[-1].lexema ==  "<=") {
                                        op = "leq";
                                     } else {
                                        op = "geq";
                                     }

                                    if (yyvsp[-2].tipo == yyvsp[0].tipo && yyvsp[-2].tipo == ENTERO) {  // ENTERO && ENTERO, REAL && REAL
                                       string tip =  "i";

                                       string dir1 = to_string(yyvsp[-2].dir);
                                       string dir3 = to_string(yyvsp[0].dir);

                                       yyval.cod += "mov " + dir1 + " A" + "\n";
                                       yyval.cod += op + tip + dir3 + "\n";
                                    } else if (yyvsp[-2].tipo == yyvsp[0].tipo && yyvsp[-2].tipo == REAL) {  // ENTERO && ENTERO, REAL && REAL
                                          string tip =  "r";

                                          string dir1 = to_string(yyvsp[-2].dir);
                                          string dir3 = to_string(yyvsp[0].dir);

                                          yyval.cod += "mov " + dir1 + " A" + "\n";
                                          yyval.cod += op + tip + dir3 + "\n";
                                     }else if (yyvsp[-2].tipo == REAL && yyvsp[0].tipo == ENTERO) {
                                       string dir3 = to_string(yyvsp[0].dir);
                                       yyval.cod += "mov " + dir3 + " A" + "\n";

                                       yyval.cod += "itor\n";

                                       string stemp = to_string(numtemp);

                                       yyval.cod += "mov A " + stemp + "\n";

                                       string dir1 = to_string(yyvsp[-2].dir);

                                       yyval.cod += "mov " + dir1 + " A" + "\n";

                                       string stemp_2 = to_string(numtemp);

                                       yyval.cod += op + "r " + stemp_2 + "\n";

                                    } else if (yyvsp[-2].tipo == ENTERO && yyvsp[0].tipo == REAL) {
                                       string dir1 = to_string(yyvsp[-2].dir);

                                       yyval.cod += "mov " + dir1 + " A" + "\n";

                                       yyval.cod += "itor\n";

                                       string dir3 = to_string(yyvsp[0].dir);

                                       yyval.cod += op + "r " + dir3 + "\n";
                                    }
                                    string stemp = to_string(numtemp);

                                    yyval.cod += "mov A " + stemp + "\n";
                                }
#line 1647 "plp5.tab.c"
    break;

  case 35: /* Expr: Esimple  */
#line 363 "plp5.y"
               {yyval.dir = yyvsp[0].dir;
                yyval.tipo = yyvsp[0].tipo;
                yyval.cod = yyvsp[0].cod;}
#line 1655 "plp5.tab.c"
    break;

  case 36: /* Esimple: Esimple opas Term  */
#line 368 "plp5.y"
                            {
                             yyval.dir = nTemp(yyvsp[0].nlin, yyvsp[0].ncol);
                             yyval.cod = yyvsp[-2].cod + yyvsp[0].cod;

                             if (yyvsp[-2].tipo == ENTERO && yyvsp[0].tipo == ENTERO){
                                yyval.tipo = ENTERO;
                             } else {
                                yyval.tipo = REAL;
                             }
                                string op;
                             if ("+" == yyvsp[-1].lexema){
                                op = "add";
                             } else {
                                op = "sub";
                             }

                             if (yyvsp[-2].tipo == yyvsp[0].tipo && yyvsp[-2].tipo == ENTERO) {  // ENTERO && ENTERO, REAL && REAL

                                string dir1 = to_string(yyvsp[-2].dir);
                                string dir3 = to_string(yyvsp[0].dir);

                                yyval.cod += "mov " + dir1 + " A" + "\n";
                                yyval.cod += op + "i" + dir3 + "\n";
                             } else if (yyvsp[-2].tipo == yyvsp[0].tipo && yyvsp[-2].tipo == REAL) {  // ENTERO && ENTERO, REAL && REAL
                                   string dir1 = to_string(yyvsp[-2].dir);
                                   string dir3 = to_string(yyvsp[0].dir);

                                   yyval.cod += "mov " + dir1 + " A" + "\n";
                                   yyval.cod += op + "r" + dir3 + "\n";
                              }else if (yyvsp[-2].tipo == REAL && yyvsp[0].tipo == ENTERO) {
                                string dir3 = to_string(yyvsp[0].dir);
                                yyval.cod += "mov " + dir3 + " A" + "\n";

                                yyval.cod += "itor\n";

                                string stemp_2 = to_string(numtemp);

                                yyval.cod += "mov A " + stemp_2 + "\n";

                                string dir1 = to_string(yyvsp[-2].dir);

                                yyval.cod += "mov " + dir1 + " A" + "\n";

                                string stemp_3 = to_string(numtemp);

                                yyval.cod += op + "r " + stemp_3 + "\n";

                             } else if (yyvsp[-2].tipo == ENTERO && yyvsp[0].tipo == REAL) {
                                string dir1 = to_string(yyvsp[-2].dir);

                                yyval.cod += "mov " + dir1 + " A" + "\n";

                                yyval.cod += "itor\n";

                                string dir3 = to_string(yyvsp[0].dir);

                                yyval.cod += op + "r " + dir3 + "\n";
                             }
                             string stemp = to_string(numtemp);

                             yyval.cod += "mov A " + stemp + "\n";
                         }
#line 1722 "plp5.tab.c"
    break;

  case 37: /* Esimple: Term  */
#line 431 "plp5.y"
            { yyval.dir = yyvsp[0].dir;
              yyval.tipo = yyvsp[0].tipo;
              yyval.cod = yyvsp[0].cod;}
#line 1730 "plp5.tab.c"
    break;

  case 38: /* Term: Term opmd Factor  */
#line 436 "plp5.y"
                        {
                                 yyval.dir = nTemp(yyvsp[0].nlin, yyvsp[0].ncol);
                                 yyval.cod = yyvsp[-2].cod + yyvsp[0].cod;

                                 if (yyvsp[-2].tipo == ENTERO && yyvsp[0].tipo == ENTERO){
                                    yyval.tipo = ENTERO;
                                 } else {
                                    yyval.tipo = REAL;
                                 }
                                    string op;
                                 if ("*" == yyvsp[-1].lexema){
                                     op = "mul";
                                 } else {
                                     op = "div";
                                 }

                                 if (yyvsp[-2].tipo == yyvsp[0].tipo && yyvsp[-2].tipo == ENTERO) {
                                    string dir1 = to_string(yyvsp[-2].dir);
                                    string dir3 = to_string(yyvsp[0].dir);

                                    yyval.cod += "mov " + dir1 + " A" + "\n";
                                    yyval.cod += op + "i" + dir3 + "\n";
                                 } else if (yyvsp[-2].tipo == yyvsp[0].tipo && yyvsp[-2].tipo == REAL) {
                                       string dir1 = to_string(yyvsp[-2].dir);
                                       string dir3 = to_string(yyvsp[0].dir);

                                       yyval.cod += "mov " + dir1 + " A" + "\n";
                                       yyval.cod += op + "r" + dir3 + "\n";
                                  }else if (yyvsp[-2].tipo == REAL && yyvsp[0].tipo == ENTERO) {
                                    string dir3 = to_string(yyvsp[0].dir);
                                    yyval.cod += "mov " + dir3 + " A" + "\n";

                                    yyval.cod += "itor\n";

                                    string stemp = to_string(numtemp);

                                    yyval.cod += "mov A " + stemp + "\n";

                                    string dir1 = to_string(yyvsp[-2].dir);

                                    yyval.cod += "mov " + dir1 + " A" + "\n";

                                    string stemp_2 = to_string(numtemp);

                                    yyval.cod += op + "r " + stemp_2 + "\n";

                                 } else if (yyvsp[-2].tipo == ENTERO && yyvsp[0].tipo == REAL) {
                                    string dir1 = to_string(yyvsp[-2].dir);

                                    yyval.cod += "mov " + dir1 + " A" + "\n";

                                    yyval.cod += "itor\n";

                                    string dir3 = to_string(yyvsp[0].dir);

                                    yyval.cod += op + "r " + dir3 + "\n";
                                 }
                                 string stemp = to_string(numtemp);

                                 yyval.cod += "mov A " + stemp + "\n";
                             }
#line 1796 "plp5.tab.c"
    break;

  case 39: /* Term: Factor  */
#line 497 "plp5.y"
              {
                yyval.dir = yyvsp[0].dir;
                yyval.tipo = yyvsp[0].tipo;
                yyval.cod = yyvsp[0].cod;
              }
#line 1806 "plp5.tab.c"
    break;

  case 40: /* Factor: Ref  */
#line 504 "plp5.y"
             {
                 if ((tablaTipos->tipos)[yyvsp[0].tipo].clase != ARRAY) {
                      yyval.cod = yyvsp[0].cod;
                      yyval.dir = nTemp(yyvsp[0].nlin, yyvsp[0].ncol);
                      yyval.tipo = yyvsp[0].tipo;

                      string dir1 = to_string(yyvsp[0].dir);
                      string sdbase = to_string(yyvsp[0].dbase);
                      string stemp = to_string(numtemp);

                      yyval.cod += "mov " + dir1 + " A\n";
                      yyval.cod += "addi #" + sdbase + "\n";
                      yyval.cod += "mov @A " + stemp + "\n";

                 } else {
                    errorSemantico(ERRFALTAN,yyvsp[0].lexema ,yyvsp[0].nlin, yyvsp[0].ncol);
                 }
             }
#line 1829 "plp5.tab.c"
    break;

  case 41: /* Factor: nentero  */
#line 522 "plp5.y"
               {

                     yyval.dir = nTemp(yyvsp[0].nlin, yyvsp[0].ncol);

                     string stemp = " " + to_string(yyval.dir);
                     yyval.cod = "mov #" + string(yyvsp[0].lexema) + stemp + "\n";

                     yyval.tipo = ENTERO;
               }
#line 1843 "plp5.tab.c"
    break;

  case 42: /* Factor: nreal  */
#line 531 "plp5.y"
             {
                     yyval.dir = nTemp(yyvsp[0].nlin, yyvsp[0].ncol);

                     string stemp = " " + to_string(yyval.dir);
                     yyval.cod = "mov $" + string(yyvsp[0].lexema) + stemp + "\n";

                     yyval.tipo = REAL;
             }
#line 1856 "plp5.tab.c"
    break;

  case 43: /* Factor: pari Expr pard  */
#line 539 "plp5.y"
                      {
                          yyval.dir = yyvsp[-1].dir;
                          yyval.tipo = yyvsp[-1].tipo;
                          yyval.cod = yyvsp[-1].cod;
                      }
#line 1866 "plp5.tab.c"
    break;

  case 44: /* Ref: id  */
#line 546 "plp5.y"
         {
            Simbolo *simb = tablaSimbolos->buscar(yyvsp[0].lexema);
            if (simb != nullptr) {
              string stemp = to_string(nTemp(yyvsp[0].nlin, yyvsp[0].ncol));

              yyval.cod = "mov #0 " + stemp + "\n";
              yyval.tipo = simb->tipo;

              yyval.dir = numtemp;
              yyval.dbase = simb->dir;

              yyval.nlin = yyvsp[0].nlin;
              yyval.ncol = yyvsp[0].ncol;
              yyval.lexema = yyvsp[0].lexema;

             } else {
                errorSemantico(ERRNODECL,yyvsp[0].lexema, yyvsp[0].nlin, yyvsp[0].ncol);
             }
         }
#line 1890 "plp5.tab.c"
    break;

  case 45: /* $@8: %empty  */
#line 565 "plp5.y"
                {
                    if (!isArray(yyvsp[-1].tipo)) {
                        if(yyvsp[-1].lexema != "]") {
                           errorSemantico(ERRSOBRAN,yyvsp[0].lexema, yyvsp[0].nlin, yyvsp[0].ncol);
                        } else {
                           errorSemantico(ERRSOBRAN,yyvsp[-1].lexema, yyvsp[-1].nlin, yyvsp[-1].ncol);
                        }
                     }
                }
#line 1904 "plp5.tab.c"
    break;

  case 46: /* Ref: Ref cori $@8 Esimple cord  */
#line 574 "plp5.y"
                  {
                     if (yyvsp[-1].tipo == ENTERO) {
                         yyval.tipo = (tablaTipos->tipos)[yyvsp[-4].tipo].tipoBase;
                         yyval.dbase = yyvsp[-4].dbase;


                         yyval.dir = nTemp(yyvsp[-3].nlin, yyvsp[-3].ncol);

                         yyval.cod = yyvsp[-4].cod + yyvsp[-1].cod;

                         string dir1 = to_string(yyvsp[-4].dir);
                         string tam1 = to_string((tablaTipos->tipos)[yyvsp[-4].tipo].tamanyo);
                         string dir4 = to_string(yyvsp[-1].dir);
                         string stemp = to_string(numtemp);

                         yyval.cod += "mov " + dir1 + " A" + "\n";
                         yyval.cod += "muli #" + tam1 + "\n";
                         yyval.cod += "addi " + dir4 + "\n";
                         yyval.cod += "mov A " +stemp + "\n";

                         yyval.nlin = yyvsp[0].nlin;
                         yyval.ncol = yyvsp[0].ncol;
                         yyval.lexema = yyvsp[0].lexema;
                    }
                 }
#line 1934 "plp5.tab.c"
    break;


#line 1938 "plp5.tab.c"

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

#line 601 "plp5.y"


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
}

unsigned int nTemp(int nlin, int ncol) {
   if (numtemp == LIM_DIR_TEMP) {
      errorSemantico(ERR_MAXTMP,"", nlin, ncol);
   }
   ++numtemp;
   return numtemp;
}

unsigned int nVar(char *lexema, int nlin, int ncol) {
   if (numvar == LIM_DIR_VAR) {
      errorSemantico(ERR_NOCABE,lexema, nlin, ncol );
   }
   ++numvar;
   return numvar;
}

unsigned int nEtiqueta(void) {
   ++numetq;
   return numetq;
}

bool isArray(int tipo) {
   if(ARRAY == (tablaTipos->tipos)[tipo].clase){
     return true;
   }else{
     return false;
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

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
#line 1 "parser.y"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <libgen.h>
#include "symbol_table.h"
#include "ast.h"
#include "instruccion.h"
#define _GNU_SOURCE

SymbolTable *tabla;
Node *father;

int lines = 1;

ExprType returnType = VOID1;

void addLine(){
    lines++;
}

int temps = 0;
Symbol* registros[3];
struct Symbol *retFunc = NULL;

extern FILE *yyin;
int yylex(void);
void yyerror(const char *s);

#line 101 "parser.tab.c"

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

#include "parser.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_IF = 3,                         /* IF  */
  YYSYMBOL_ELSE = 4,                       /* ELSE  */
  YYSYMBOL_WHILE = 5,                      /* WHILE  */
  YYSYMBOL_INT = 6,                        /* INT  */
  YYSYMBOL_RETURN = 7,                     /* RETURN  */
  YYSYMBOL_BOOLEAN = 8,                    /* BOOLEAN  */
  YYSYMBOL_FLOAT = 9,                      /* FLOAT  */
  YYSYMBOL_EXTERN = 10,                    /* EXTERN  */
  YYSYMBOL_EQUAL = 11,                     /* EQUAL  */
  YYSYMBOL_AND = 12,                       /* AND  */
  YYSYMBOL_OR = 13,                        /* OR  */
  YYSYMBOL_LE = 14,                        /* LE  */
  YYSYMBOL_ID = 15,                        /* ID  */
  YYSYMBOL_LIT_INT = 16,                   /* LIT_INT  */
  YYSYMBOL_TRUE = 17,                      /* TRUE  */
  YYSYMBOL_FALSE = 18,                     /* FALSE  */
  YYSYMBOL_LIT_FLOAT = 19,                 /* LIT_FLOAT  */
  YYSYMBOL_VOID = 20,                      /* VOID  */
  YYSYMBOL_21_ = 21,                       /* '<'  */
  YYSYMBOL_22_ = 22,                       /* '>'  */
  YYSYMBOL_23_ = 23,                       /* '+'  */
  YYSYMBOL_24_ = 24,                       /* '-'  */
  YYSYMBOL_25_ = 25,                       /* '*'  */
  YYSYMBOL_26_ = 26,                       /* '/'  */
  YYSYMBOL_27_ = 27,                       /* '%'  */
  YYSYMBOL_28_ = 28,                       /* '!'  */
  YYSYMBOL_UMINUS = 29,                    /* UMINUS  */
  YYSYMBOL_30_ = 30,                       /* ';'  */
  YYSYMBOL_31_ = 31,                       /* '('  */
  YYSYMBOL_32_ = 32,                       /* ')'  */
  YYSYMBOL_33_ = 33,                       /* '{'  */
  YYSYMBOL_34_ = 34,                       /* '}'  */
  YYSYMBOL_35_ = 35,                       /* ','  */
  YYSYMBOL_36_ = 36,                       /* '='  */
  YYSYMBOL_YYACCEPT = 37,                  /* $accept  */
  YYSYMBOL_preinput = 38,                  /* preinput  */
  YYSYMBOL_input = 39,                     /* input  */
  YYSYMBOL_Extern_decl = 40,               /* Extern_decl  */
  YYSYMBOL_41_1 = 41,                      /* $@1  */
  YYSYMBOL_Method_decl = 42,               /* Method_decl  */
  YYSYMBOL_43_2 = 43,                      /* $@2  */
  YYSYMBOL_44_3 = 44,                      /* $@3  */
  YYSYMBOL_45_4 = 45,                      /* $@4  */
  YYSYMBOL_46_5 = 46,                      /* $@5  */
  YYSYMBOL_47_6 = 47,                      /* $@6  */
  YYSYMBOL_48_7 = 48,                      /* $@7  */
  YYSYMBOL_Type = 49,                      /* Type  */
  YYSYMBOL_Params = 50,                    /* Params  */
  YYSYMBOL_Param = 51,                     /* Param  */
  YYSYMBOL_Linea = 52,                     /* Linea  */
  YYSYMBOL_Sentencia = 53,                 /* Sentencia  */
  YYSYMBOL_Bloque = 54,                    /* Bloque  */
  YYSYMBOL_55_8 = 55,                      /* $@8  */
  YYSYMBOL_Params_pass = 56,               /* Params_pass  */
  YYSYMBOL_Method_call = 57,               /* Method_call  */
  YYSYMBOL_expr = 58,                      /* expr  */
  YYSYMBOL_Ids_decl = 59,                  /* Ids_decl  */
  YYSYMBOL_Var_decl = 60,                  /* Var_decl  */
  YYSYMBOL_Asign = 61                      /* Asign  */
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
typedef yytype_uint8 yy_state_t;

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
#define YYFINAL  15
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   294

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  37
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  25
/* YYNRULES -- Number of rules.  */
#define YYNRULES  71
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  141

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   276


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
       2,     2,     2,    28,     2,     2,     2,    27,     2,     2,
      31,    32,    25,    23,    35,    24,     2,    26,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    30,
      21,    36,    22,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    33,     2,    34,     2,     2,     2,     2,
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
      15,    16,    17,    18,    19,    20,    29
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    61,    61,    69,    73,    77,    80,    83,    86,    92,
     102,   113,   113,   139,   150,   139,   165,   174,   165,   187,
     187,   203,   203,   217,   220,   223,   226,   232,   235,   239,
     251,   252,   256,   257,   258,   264,   271,   277,   287,   293,
     294,   295,   298,   298,   302,   303,   306,   317,   336,   343,
     344,   347,   350,   353,   356,   371,   386,   401,   416,   431,
     445,   458,   471,   476,   484,   492,   502,   514,   517,   527,
     539,   547
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
  "\"end of file\"", "error", "\"invalid token\"", "IF", "ELSE", "WHILE",
  "INT", "RETURN", "BOOLEAN", "FLOAT", "EXTERN", "EQUAL", "AND", "OR",
  "LE", "ID", "LIT_INT", "TRUE", "FALSE", "LIT_FLOAT", "VOID", "'<'",
  "'>'", "'+'", "'-'", "'*'", "'/'", "'%'", "'!'", "UMINUS", "';'", "'('",
  "')'", "'{'", "'}'", "','", "'='", "$accept", "preinput", "input",
  "Extern_decl", "$@1", "Method_decl", "$@2", "$@3", "$@4", "$@5", "$@6",
  "$@7", "Type", "Params", "Param", "Linea", "Sentencia", "Bloque", "$@8",
  "Params_pass", "Method_call", "expr", "Ids_decl", "Var_decl", "Asign", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-113)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  ((Yyn) == YYTABLE_NINF)

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      66,  -113,  -113,  -113,    76,     0,    21,  -113,    66,    66,
      13,     4,  -113,    24,    11,  -113,  -113,  -113,     6,  -113,
      66,   -29,    12,    25,    41,  -113,  -113,    28,  -113,    76,
    -113,    76,     1,  -113,    32,    76,    44,    63,    48,    52,
      50,    57,  -113,    60,     5,  -113,  -113,    76,     5,  -113,
      65,    62,    70,   222,   -27,  -113,  -113,    41,    71,     5,
    -113,    88,    89,    90,    58,  -113,   102,   104,  -113,   263,
     263,    91,  -113,  -113,  -113,  -113,   263,   263,  -113,   263,
    -113,   154,   170,   263,     5,  -113,  -113,  -113,  -113,  -113,
       5,  -113,     5,   103,   120,  -113,  -113,   137,   263,   263,
     263,   263,   263,   263,   263,   263,   263,   263,   263,  -113,
    -113,   106,    86,   192,   105,   119,   121,   107,   107,  -113,
     233,   209,   250,   233,   233,   233,    77,    77,  -113,  -113,
    -113,  -113,   263,  -113,  -113,  -113,   150,  -113,  -113,   107,
    -113
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,    23,    24,    25,     0,     0,     0,     2,     7,     5,
       0,     0,    26,     0,     0,     1,     8,     6,    69,    70,
       4,     0,    16,    13,     0,     3,     9,    11,    21,     0,
      19,     0,    69,    68,     0,     0,     0,     0,     0,    28,
       0,     0,    10,     0,    30,    29,    17,     0,    30,    14,
       0,     0,     0,     0,     0,    39,    42,     0,     0,    30,
      40,     0,     0,     0,     0,    27,     0,     0,    12,     0,
       0,    48,    51,    53,    52,    50,     0,     0,    38,     0,
      49,     0,     0,     0,    30,    22,    31,    41,    32,    33,
      30,    20,    30,     0,     0,    65,    66,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    37,
      46,     0,    45,    71,     0,     0,     0,     0,     0,    67,
      62,    63,    64,    59,    60,    61,    54,    55,    56,    57,
      58,    47,     0,    43,    18,    15,    34,    36,    44,     0,
      35
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -113,  -113,    23,  -113,  -113,  -113,  -113,  -113,  -113,  -113,
    -113,  -113,    59,   -28,  -113,   -19,  -113,  -112,  -113,    -9,
     -26,   -53,   132,    61,  -113
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     6,     7,     8,    35,     9,    31,    67,    29,    64,
      40,    36,    57,    38,    39,    58,    59,    60,    84,   111,
      80,   112,    19,    62,    63
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      81,    26,    27,    41,    82,   136,   137,    43,    51,    83,
      52,     1,    53,     2,     3,    14,    93,    94,    61,    65,
      54,    15,    61,    95,    96,    12,    97,   140,    18,    66,
     113,    16,    17,    61,    20,    55,    24,    23,    56,    21,
      86,    24,    22,    25,    28,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,    32,    30,    61,    10,
      34,    11,    42,    13,    61,   114,    61,    10,    10,    11,
      11,   115,     1,   116,     2,     3,     4,    44,    45,    10,
      46,    11,     1,    48,     2,     3,     5,    47,    37,    49,
      37,    90,    50,    69,    37,    68,    12,    98,    99,   100,
     101,    70,   106,   107,   108,    85,    37,   102,   103,   104,
     105,   106,   107,   108,    98,    99,   100,   101,    87,    88,
      89,   132,    82,   138,   102,   103,   104,   105,   106,   107,
     108,    98,    99,   100,   101,   117,    91,    92,   131,   133,
      56,   102,   103,   104,   105,   106,   107,   108,    98,    99,
     100,   101,   118,   134,   139,   135,    33,     0,   102,   103,
     104,   105,   106,   107,   108,    98,    99,   100,   101,   119,
       0,     0,     0,     0,     0,   102,   103,   104,   105,   106,
     107,   108,     0,     0,   109,    71,    72,    73,    74,    75,
       0,     0,     0,     0,    76,     0,     0,     0,    77,     0,
       0,    79,   110,    98,    99,   100,   101,     0,     0,     0,
       0,     0,     0,   102,   103,   104,   105,   106,   107,   108,
      98,     0,   100,   101,     0,     0,     0,     0,     0,     0,
     102,   103,   104,   105,   106,   107,   108,    71,    72,    73,
      74,    75,     0,     0,    -1,     0,    76,    -1,     0,     0,
      77,     0,    78,    79,    -1,    -1,   104,   105,   106,   107,
     108,    98,     0,     0,   101,     0,     0,     0,     0,     0,
       0,   102,   103,   104,   105,   106,   107,   108,    71,    72,
      73,    74,    75,     0,     0,     0,     0,    76,     0,     0,
       0,    77,     0,     0,    79
};

static const yytype_int16 yycheck[] =
{
      53,    30,    31,    31,    31,   117,   118,    35,     3,    36,
       5,     6,     7,     8,     9,    15,    69,    70,    44,    47,
      15,     0,    48,    76,    77,    20,    79,   139,    15,    48,
      83,     8,     9,    59,    30,    30,    35,    31,    33,    15,
      59,    35,    31,    20,    32,    98,    99,   100,   101,   102,
     103,   104,   105,   106,   107,   108,    15,    32,    84,     0,
      32,     0,    30,     4,    90,    84,    92,     8,     9,     8,
       9,    90,     6,    92,     8,     9,    10,    33,    15,    20,
      32,    20,     6,    33,     8,     9,    20,    35,    29,    32,
      31,    33,    32,    31,    35,    30,    20,    11,    12,    13,
      14,    31,    25,    26,    27,    34,    47,    21,    22,    23,
      24,    25,    26,    27,    11,    12,    13,    14,    30,    30,
      30,    35,    31,   132,    21,    22,    23,    24,    25,    26,
      27,    11,    12,    13,    14,    32,    34,    33,    32,    34,
      33,    21,    22,    23,    24,    25,    26,    27,    11,    12,
      13,    14,    32,    34,     4,    34,    24,    -1,    21,    22,
      23,    24,    25,    26,    27,    11,    12,    13,    14,    32,
      -1,    -1,    -1,    -1,    -1,    21,    22,    23,    24,    25,
      26,    27,    -1,    -1,    30,    15,    16,    17,    18,    19,
      -1,    -1,    -1,    -1,    24,    -1,    -1,    -1,    28,    -1,
      -1,    31,    32,    11,    12,    13,    14,    -1,    -1,    -1,
      -1,    -1,    -1,    21,    22,    23,    24,    25,    26,    27,
      11,    -1,    13,    14,    -1,    -1,    -1,    -1,    -1,    -1,
      21,    22,    23,    24,    25,    26,    27,    15,    16,    17,
      18,    19,    -1,    -1,    11,    -1,    24,    14,    -1,    -1,
      28,    -1,    30,    31,    21,    22,    23,    24,    25,    26,
      27,    11,    -1,    -1,    14,    -1,    -1,    -1,    -1,    -1,
      -1,    21,    22,    23,    24,    25,    26,    27,    15,    16,
      17,    18,    19,    -1,    -1,    -1,    -1,    24,    -1,    -1,
      -1,    28,    -1,    -1,    31
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     6,     8,     9,    10,    20,    38,    39,    40,    42,
      49,    60,    20,    49,    15,     0,    39,    39,    15,    59,
      30,    15,    31,    31,    35,    39,    30,    31,    32,    45,
      32,    43,    15,    59,    32,    41,    48,    49,    50,    51,
      47,    50,    30,    50,    33,    15,    32,    35,    33,    32,
      32,     3,     5,     7,    15,    30,    33,    49,    52,    53,
      54,    57,    60,    61,    46,    50,    52,    44,    30,    31,
      31,    15,    16,    17,    18,    19,    24,    28,    30,    31,
      57,    58,    31,    36,    55,    34,    52,    30,    30,    30,
      33,    34,    33,    58,    58,    58,    58,    58,    11,    12,
      13,    14,    21,    22,    23,    24,    25,    26,    27,    30,
      32,    56,    58,    58,    52,    52,    52,    32,    32,    32,
      58,    58,    58,    58,    58,    58,    58,    58,    58,    58,
      58,    32,    35,    34,    34,    34,    54,    54,    56,     4,
      54
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    37,    38,    39,    39,    39,    39,    39,    39,    40,
      40,    41,    40,    43,    44,    42,    45,    46,    42,    47,
      42,    48,    42,    49,    49,    49,    49,    50,    50,    51,
      52,    52,    53,    53,    53,    53,    53,    53,    53,    53,
      53,    53,    55,    54,    56,    56,    57,    57,    58,    58,
      58,    58,    58,    58,    58,    58,    58,    58,    58,    58,
      58,    58,    58,    58,    58,    58,    58,    58,    59,    59,
      60,    61
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     3,     2,     1,     2,     1,     2,     4,
       6,     0,     8,     0,     0,    10,     0,     0,    10,     0,
       8,     0,     8,     1,     1,     1,     1,     3,     1,     2,
       0,     2,     2,     2,     5,     7,     5,     3,     2,     1,
       1,     2,     0,     4,     3,     1,     3,     4,     1,     1,
       1,     1,     1,     1,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     2,     2,     3,     3,     1,
       2,     3
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
  case 2: /* preinput: input  */
#line 61 "parser.y"
                  {
    Symbol *simb = create_symb(NOT_TYPE, 0, NULL);
    (yyval.node) = create_node(NODE_OP_FUNC, simb, (yyvsp[0].node), NULL, NULL);
    father = (yyval.node);
}
#line 1272 "parser.tab.c"
    break;

  case 3: /* input: Var_decl ';' input  */
#line 69 "parser.y"
                       {
                        (yyval.node) = create_node(NODE_OP_NEWLINE, NULL, (yyvsp[-2].node), (yyvsp[0].node), NULL);
                        (yyvsp[-2].node)->third->info->isFuction = 2;
                    }
#line 1281 "parser.tab.c"
    break;

  case 4: /* input: Var_decl ';'  */
#line 73 "parser.y"
                   {
                        (yyval.node) = create_node(NODE_OP_NEWLINE, NULL, (yyvsp[-1].node), NULL, NULL);
                        (yyvsp[-1].node)->third->info->isFuction = 2;
                    }
#line 1290 "parser.tab.c"
    break;

  case 5: /* input: Method_decl  */
#line 77 "parser.y"
                  {
                        (yyval.node) = create_node(NODE_OP_NEWLINE, NULL, (yyvsp[0].node), NULL, NULL);
                    }
#line 1298 "parser.tab.c"
    break;

  case 6: /* input: Method_decl input  */
#line 80 "parser.y"
                        {
                        (yyval.node) = create_node(NODE_OP_NEWLINE, NULL, (yyvsp[-1].node), (yyvsp[0].node), NULL);
                    }
#line 1306 "parser.tab.c"
    break;

  case 7: /* input: Extern_decl  */
#line 83 "parser.y"
                  {
                        (yyval.node) = create_node(NODE_OP_NEWLINE, NULL, (yyvsp[0].node), NULL, NULL);
                    }
#line 1314 "parser.tab.c"
    break;

  case 8: /* input: Extern_decl input  */
#line 86 "parser.y"
                        {
                        (yyval.node) = create_node(NODE_OP_NEWLINE, NULL, (yyvsp[-1].node), (yyvsp[0].node), NULL);
                    }
#line 1322 "parser.tab.c"
    break;

  case 9: /* Extern_decl: EXTERN Type ID ';'  */
#line 92 "parser.y"
                       {
            if (find_in_level(tabla, (yyvsp[-1].str))) {
                yyerror("Error de sintaxis: Variable declarada mas de una vez\n");
                YYABORT;
            }
            returnType = (yyvsp[-2].node)->info->exprType;
            Symbol *simb = create_symb((yyvsp[-2].node)->info->exprType, 0, (yyvsp[-1].str));
            insert_symbolo(tabla, simb);
            (yyval.node) = create_node(NODE_EXT_DECLARATION, simb, NULL, NULL, NULL);
    }
#line 1337 "parser.tab.c"
    break;

  case 10: /* Extern_decl: EXTERN Type ID '(' ')' ';'  */
#line 102 "parser.y"
                                 {
            if (find_in_level(tabla, (yyvsp[-3].str))) {
                yyerror("Error de sintaxis: Metodo declarado mas de una vez\n");
                YYABORT;
            }
            returnType = (yyvsp[-4].node)->info->exprType;
            Symbol *simb = create_symb((yyvsp[-4].node)->info->exprType, 0, (yyvsp[-3].str));
            simb->isFuction = 1;
            insert_symbolo(tabla, simb);
            (yyval.node) = create_node(NODE_EXT_MET_DECLARATION, simb, NULL, NULL, NULL);
    }
#line 1353 "parser.tab.c"
    break;

  case 11: /* $@1: %empty  */
#line 113 "parser.y"
                         {
            if (find_in_level(tabla, (yyvsp[-1].str))) {
                yyerror("Error de sintaxis: Metodo declarado mas de una vez\n");
                YYABORT;
            }

            returnType = (yyvsp[-2].node)->info->exprType;
            Symbol *simb = create_symb((yyvsp[-2].node)->info->exprType, 0, (yyvsp[-1].str));
            simb->isFuction = 1;
            insert_symbolo(tabla, simb);
            new_level(tabla);
            }
#line 1370 "parser.tab.c"
    break;

  case 12: /* Extern_decl: EXTERN Type ID '(' $@1 Params ')' ';'  */
#line 125 "parser.y"
                       {
            Symbol *simb = find_symbol(tabla, (yyvsp[-5].str));
            if(!(yyvsp[-2].node)->left){
                simb->init=(yyvsp[-2].node)->info;
                simb->end=(yyvsp[-2].node)->info;
            }else{
                simb->init=(yyvsp[-2].node)->left->info;
                simb->end = search_last_Symbol((yyvsp[-2].node));
            }
            (yyval.node) = create_node(NODE_EXT_DECLARATION, simb, NULL, NULL, NULL);
            close_level(tabla);
        }
#line 1387 "parser.tab.c"
    break;

  case 13: /* $@2: %empty  */
#line 139 "parser.y"
                {
            if (find_in_level(tabla, (yyvsp[-1].str))) {
                yyerror("Error de sintaxis: Metodo declarado mas de una vez\n");
                YYABORT;
            }

            returnType = (yyvsp[-2].node)->info->exprType;
            Symbol *simb = create_symb((yyvsp[-2].node)->info->exprType, 0, (yyvsp[-1].str));
            simb->isFuction = 1;
            insert_symbolo(tabla, simb);
            new_level(tabla);
        }
#line 1404 "parser.tab.c"
    break;

  case 14: /* $@3: %empty  */
#line 150 "parser.y"
                     {
            Symbol *simb = find_symbol(tabla, (yyvsp[-4].str));
            if(!(yyvsp[-1].node)->left){
                simb->init=(yyvsp[-1].node)->info;
                simb->end=(yyvsp[-1].node)->info;
            }else{
                simb->init=(yyvsp[-1].node)->left->info;
                simb->end = search_last_Symbol((yyvsp[-1].node));
            }
        }
#line 1419 "parser.tab.c"
    break;

  case 15: /* Method_decl: Type ID '(' $@2 Params ')' $@3 '{' Linea '}'  */
#line 159 "parser.y"
                        {
            close_level(tabla);
            print_from_to(find_symbol(tabla, (yyvsp[-8].str))->end, find_symbol(tabla, (yyvsp[-8].str))->init);
            (yyval.node) = create_node(NODE_MET_DECLARATION, find_symbol(tabla, (yyvsp[-8].str)), (yyvsp[-5].node), (yyvsp[-1].node), NULL);
            returnType = VOID1;
        }
#line 1430 "parser.tab.c"
    break;

  case 16: /* $@4: %empty  */
#line 165 "parser.y"
                  {
            if (find_in_level(tabla, (yyvsp[-1].str))) {
                yyerror("Error de sintaxis: Metodo declarado mas de una vez\n");
                YYABORT;
            }
            Symbol *simb = create_symb(VOID1, 0, (yyvsp[-1].str));
            simb->isFuction = 1;
            insert_symbolo(tabla, simb);
            new_level(tabla);
        }
#line 1445 "parser.tab.c"
    break;

  case 17: /* $@5: %empty  */
#line 174 "parser.y"
                     {
            Symbol *simb = find_symbol(tabla, (yyvsp[-4].str));
            if(!(yyvsp[-1].node)->left){
                simb->init=(yyvsp[-1].node)->info;
                simb->end=(yyvsp[-1].node)->info;
            }else{
                simb->init=(yyvsp[-1].node)->left->info;
                simb->end = search_last_Symbol((yyvsp[-1].node));
            }
        }
#line 1460 "parser.tab.c"
    break;

  case 18: /* Method_decl: VOID ID '(' $@4 Params ')' $@5 '{' Linea '}'  */
#line 183 "parser.y"
                        {
            close_level(tabla);
            (yyval.node) = create_node(NODE_MET_DECLARATION, find_symbol(tabla, (yyvsp[-8].str)), (yyvsp[-5].node), (yyvsp[-1].node), NULL);
        }
#line 1469 "parser.tab.c"
    break;

  case 19: /* $@6: %empty  */
#line 187 "parser.y"
                      {
            if (find_in_level(tabla, (yyvsp[-2].str))) {
                yyerror("Error de sintaxis: Metodo declarado mas de una vez\n");
                YYABORT;
            }
            returnType = (yyvsp[-3].node)->info->exprType;
            Symbol *simb = create_symb((yyvsp[-3].node)->info->exprType, 0, (yyvsp[-2].str));
            simb->isFuction = 1;
            insert_symbolo(tabla, simb);
            new_level(tabla);
        }
#line 1485 "parser.tab.c"
    break;

  case 20: /* Method_decl: Type ID '(' ')' $@6 '{' Linea '}'  */
#line 197 "parser.y"
                        {
            close_level(tabla);
            returnType = VOID1;
            (yyval.node) = create_node(NODE_MET_DECLARATION, find_symbol(tabla, (yyvsp[-6].str)), NULL, (yyvsp[-1].node), NULL);

        }
#line 1496 "parser.tab.c"
    break;

  case 21: /* $@7: %empty  */
#line 203 "parser.y"
                      {
            if (find_in_level(tabla, (yyvsp[-2].str))) {
                yyerror("Error de sintaxis: Metodo declarado mas de una vez\n");
                YYABORT;
            }
            Symbol *simb = create_symb(VOID1, 0, (yyvsp[-2].str));
            simb->isFuction = 1;
            insert_symbolo(tabla, simb);
            new_level(tabla);
        }
#line 1511 "parser.tab.c"
    break;

  case 22: /* Method_decl: VOID ID '(' ')' $@7 '{' Linea '}'  */
#line 212 "parser.y"
                        {
            close_level(tabla);
            (yyval.node) = create_node(NODE_MET_DECLARATION, find_symbol(tabla, (yyvsp[-6].str)), NULL, (yyvsp[-1].node), NULL);
        }
#line 1520 "parser.tab.c"
    break;

  case 23: /* Type: INT  */
#line 217 "parser.y"
            { Symbol *simb = create_symb(INT1, 0, NULL);
            (yyval.node) = create_node(NODE_AUX, simb, NULL, NULL, NULL);
            }
#line 1528 "parser.tab.c"
    break;

  case 24: /* Type: BOOLEAN  */
#line 220 "parser.y"
                { Symbol *simb = create_symb(BOOL1, 0, NULL);
            (yyval.node) = create_node(NODE_AUX, simb, NULL, NULL, NULL);
            }
#line 1536 "parser.tab.c"
    break;

  case 25: /* Type: FLOAT  */
#line 223 "parser.y"
            { Symbol *simb = create_symb(FLOAT1, 0, NULL);
            (yyval.node) = create_node(NODE_AUX, simb, NULL, NULL, NULL);
            }
#line 1544 "parser.tab.c"
    break;

  case 26: /* Type: VOID  */
#line 226 "parser.y"
           { Symbol *simb = create_symb(VOID1, 0, NULL);
            (yyval.node) = create_node(NODE_AUX, simb, NULL, NULL, NULL);
            }
#line 1552 "parser.tab.c"
    break;

  case 27: /* Params: Param ',' Params  */
#line 232 "parser.y"
                        {
            (yyval.node) = create_node(NODE_PARAM_DECLARATION, NULL, (yyvsp[-2].node), (yyvsp[0].node), NULL);
            }
#line 1560 "parser.tab.c"
    break;

  case 28: /* Params: Param  */
#line 235 "parser.y"
            {(yyval.node) = (yyvsp[0].node);
        }
#line 1567 "parser.tab.c"
    break;

  case 29: /* Param: Type ID  */
#line 239 "parser.y"
               {
            if (find_in_level(tabla, (yyvsp[0].str))) {
                yyerror("Error de sintaxis: Parametro declarado mas de una vez\n");
                YYABORT;
            }
            Symbol *simb = create_symb((yyvsp[-1].node)->info->exprType, 0, (yyvsp[0].str));
            insert_symbolo(tabla, simb);
            (yyval.node) = create_node(NODE_PARAM_DECLARATION_PURE, simb, NULL, NULL, NULL);
        }
#line 1581 "parser.tab.c"
    break;

  case 30: /* Linea: %empty  */
#line 251 "parser.y"
                    {(yyval.node) = NULL;}
#line 1587 "parser.tab.c"
    break;

  case 31: /* Linea: Sentencia Linea  */
#line 252 "parser.y"
                        {(yyval.node) = create_node(NODE_OP_NEWLINE, NULL, (yyvsp[-1].node), (yyvsp[0].node), NULL);}
#line 1593 "parser.tab.c"
    break;

  case 32: /* Sentencia: Var_decl ';'  */
#line 256 "parser.y"
                    {(yyval.node) = (yyvsp[-1].node);}
#line 1599 "parser.tab.c"
    break;

  case 33: /* Sentencia: Asign ';'  */
#line 257 "parser.y"
                {(yyval.node) = (yyvsp[-1].node);}
#line 1605 "parser.tab.c"
    break;

  case 34: /* Sentencia: IF '(' expr ')' Bloque  */
#line 258 "parser.y"
                             {
                    if((yyvsp[-2].node)->info->exprType != BOOL1){
                        yyerror("Error de sintaxis: expresion no booleana");
                    }
                    (yyval.node) = create_node(NODE_IF, create_symb(NOT_TYPE,0,NULL), (yyvsp[-2].node), (yyvsp[0].node), NULL);
                    }
#line 1616 "parser.tab.c"
    break;

  case 35: /* Sentencia: IF '(' expr ')' Bloque ELSE Bloque  */
#line 265 "parser.y"
                   {
                    if((yyvsp[-4].node)->info->exprType != BOOL1){
                        yyerror("Error de sintaxis: expresion no booleana");
                    }
                    (yyval.node) = create_node(NODE_IF_ELSE, create_symb(NOT_TYPE,0,NULL), (yyvsp[-4].node), (yyvsp[-2].node), (yyvsp[0].node));
                    }
#line 1627 "parser.tab.c"
    break;

  case 36: /* Sentencia: WHILE '(' expr ')' Bloque  */
#line 271 "parser.y"
                                 {
                    if((yyvsp[-2].node)->info->exprType != BOOL1){
                        yyerror("Error de sintaxis: expresion no booleana");
                    }
                    (yyval.node) = create_node(NODE_WHILE, create_symb(NOT_TYPE,0,NULL), (yyvsp[-2].node), (yyvsp[0].node), NULL);
                    }
#line 1638 "parser.tab.c"
    break;

  case 37: /* Sentencia: RETURN expr ';'  */
#line 277 "parser.y"
                      {Symbol *simb = create_symb((yyvsp[-1].node)->info->exprType, 0, NULL);
                    if(returnType!=simb->exprType){
                        if((returnType==INT1 ||returnType==FLOAT1) && (simb->exprType==INT1 || simb->exprType==FLOAT1)){
                            yyerror("Warning: Tipos no coinciden");
                        } else {
                            yyerror("Error de sintaxis: tipo de retorno incompatible");
                        }
                    }
                    (yyval.node) = create_node(NODE_OP_RETURN, simb, (yyvsp[-1].node), NULL, NULL);
                    }
#line 1653 "parser.tab.c"
    break;

  case 38: /* Sentencia: RETURN ';'  */
#line 287 "parser.y"
                 {Symbol *simb = create_symb(VOID1, 0, NULL);
                    if(returnType!=VOID1){
                        yyerror("Error de sintaxis: tipo de retorno incompatible");
                    }
                    (yyval.node) = create_node(NODE_OP_RETURN, simb, NULL, NULL, NULL);
                }
#line 1664 "parser.tab.c"
    break;

  case 39: /* Sentencia: ';'  */
#line 293 "parser.y"
          {(yyval.node)=NULL;}
#line 1670 "parser.tab.c"
    break;

  case 40: /* Sentencia: Bloque  */
#line 294 "parser.y"
             {(yyval.node) = (yyvsp[0].node);}
#line 1676 "parser.tab.c"
    break;

  case 41: /* Sentencia: Method_call ';'  */
#line 295 "parser.y"
                      {(yyval.node)=(yyvsp[-1].node);}
#line 1682 "parser.tab.c"
    break;

  case 42: /* $@8: %empty  */
#line 298 "parser.y"
            {new_level(tabla);}
#line 1688 "parser.tab.c"
    break;

  case 43: /* Bloque: '{' $@8 Linea '}'  */
#line 298 "parser.y"
                                          {close_level(tabla);
        (yyval.node) = (yyvsp[-1].node);
        }
#line 1696 "parser.tab.c"
    break;

  case 44: /* Params_pass: expr ',' Params_pass  */
#line 302 "parser.y"
                                  {(yyval.node) = create_node(NODE_PARAM_PASS, NULL, (yyvsp[-2].node), (yyvsp[0].node), NULL);}
#line 1702 "parser.tab.c"
    break;

  case 45: /* Params_pass: expr  */
#line 303 "parser.y"
           {(yyval.node) = (yyvsp[0].node);}
#line 1708 "parser.tab.c"
    break;

  case 46: /* Method_call: ID '(' ')'  */
#line 306 "parser.y"
                        {
                Symbol *simb = find_symbol(tabla, (yyvsp[-2].str));
                if (!simb || !simb->isFuction) {
                    yyerror("Error de sintaxis: Metodo no declarado");
                    YYABORT;
                }
                if (simb->init) {
                    yyerror("Error de sintaxis: Parametros Incorrectos");
                }
                (yyval.node) = create_node(NODE_MET_CALL, simb, NULL, NULL, NULL);
            }
#line 1724 "parser.tab.c"
    break;

  case 47: /* Method_call: ID '(' Params_pass ')'  */
#line 317 "parser.y"
                             {
                Symbol *simb = find_symbol(tabla, (yyvsp[-3].str));
                if (!simb || !simb->isFuction) {
                    yyerror("Error de sintaxis: Metodo no declarado");
                    YYABORT;
                }
                if (!simb->init) {
                    yyerror("Error de sintaxis: Parametros Incorrectos");
                } else {
                    Symbol *aux = verify_params(simb->end, (yyvsp[-1].node));
                    if(!aux || aux !=simb->init->next){
                        yyerror("Error de sintaxis: Parametros Incorrectos");
                    }
                }
                (yyval.node) = create_node(NODE_MET_CALL, simb, (yyvsp[-1].node), NULL, NULL);
            }
#line 1745 "parser.tab.c"
    break;

  case 48: /* expr: ID  */
#line 336 "parser.y"
            {   Symbol *sim = find_symbol(tabla, (yyvsp[0].str));
                if(!sim){
                yyerror("Error de sintaxis: Variable no declarado");
                YYABORT;
                }
                (yyval.node) = create_node(NODE_ID, sim, NULL, NULL, NULL);
            }
#line 1757 "parser.tab.c"
    break;

  case 49: /* expr: Method_call  */
#line 343 "parser.y"
                  {(yyval.node) = (yyvsp[0].node);}
#line 1763 "parser.tab.c"
    break;

  case 50: /* expr: LIT_FLOAT  */
#line 344 "parser.y"
                    {Symbol *simb = create_symb(FLOAT1, (yyvsp[0].num), NULL);
        (yyval.node) = create_node(NODE_VAL_NUM, simb, NULL, NULL, NULL);
        }
#line 1771 "parser.tab.c"
    break;

  case 51: /* expr: LIT_INT  */
#line 347 "parser.y"
                {Symbol *simb = create_symb(INT1, (yyvsp[0].num), NULL);
        (yyval.node) = create_node(NODE_VAL_NUM, simb, NULL, NULL, NULL);
        }
#line 1779 "parser.tab.c"
    break;

  case 52: /* expr: FALSE  */
#line 350 "parser.y"
            {Symbol *simb = create_symb(BOOL1, 0, NULL);
        (yyval.node) = create_node(NODE_VAL_FALSE, simb, NULL, NULL, NULL);
        }
#line 1787 "parser.tab.c"
    break;

  case 53: /* expr: TRUE  */
#line 353 "parser.y"
           {Symbol *simb = create_symb(BOOL1, 1, NULL);
        (yyval.node) = create_node(NODE_VAL_TRUE, simb, NULL, NULL, NULL);
        }
#line 1795 "parser.tab.c"
    break;

  case 54: /* expr: expr '+' expr  */
#line 356 "parser.y"
                      {Symbol *simb = NULL;
            if((yyvsp[0].node)->info->exprType != (yyvsp[-2].node)->info->exprType){
                if(((yyvsp[-2].node)->info->exprType != INT1 && (yyvsp[-2].node)->info->exprType != FLOAT1)||
                ((yyvsp[0].node)->info->exprType != INT1 && (yyvsp[0].node)->info->exprType != FLOAT1)){
                    yyerror("Error de tipo");
                    YYABORT;
                }else{
                    yyerror("Warning: tipos no coinciden");
                    simb = create_symb(FLOAT1, 0, NULL);
                }
            }else{
                simb = create_symb((yyvsp[0].node)->info->exprType, 0, NULL);
            }
            (yyval.node) = create_node(NODE_OP_ADD, simb, (yyvsp[-2].node), (yyvsp[0].node), NULL);
        }
#line 1815 "parser.tab.c"
    break;

  case 55: /* expr: expr '-' expr  */
#line 371 "parser.y"
                       {Symbol *simb = NULL;
            if((yyvsp[0].node)->info->exprType != (yyvsp[-2].node)->info->exprType){
                if(((yyvsp[-2].node)->info->exprType != INT1 && (yyvsp[-2].node)->info->exprType != FLOAT1)||
                ((yyvsp[0].node)->info->exprType != INT1 && (yyvsp[0].node)->info->exprType != FLOAT1)){
                    yyerror("Error de tipo");
                    YYABORT;
                }else{
                    yyerror("Warning: tipos no coinciden");
                    simb = create_symb(FLOAT1, 0, NULL);
                }
            }else{
                simb = create_symb((yyvsp[0].node)->info->exprType, 0, NULL);
            }
            (yyval.node) = create_node(NODE_OP_SUB, simb, (yyvsp[-2].node), (yyvsp[0].node), NULL);
        }
#line 1835 "parser.tab.c"
    break;

  case 56: /* expr: expr '*' expr  */
#line 386 "parser.y"
                        {Symbol *simb = NULL;
            if((yyvsp[0].node)->info->exprType != (yyvsp[-2].node)->info->exprType){
                if(((yyvsp[-2].node)->info->exprType != INT1 && (yyvsp[-2].node)->info->exprType != FLOAT1)||
                ((yyvsp[0].node)->info->exprType != INT1 && (yyvsp[0].node)->info->exprType != FLOAT1)){
                    yyerror("Error de tipo");
                    YYABORT;
                }else{
                    yyerror("Warning: tipos no coinciden");
                    simb = create_symb(FLOAT1, 0, NULL);
                }
            }else{
                simb = create_symb((yyvsp[0].node)->info->exprType, 0, NULL);
            }
            (yyval.node) = create_node(NODE_OP_MUL, simb, (yyvsp[-2].node), (yyvsp[0].node), NULL);
        }
#line 1855 "parser.tab.c"
    break;

  case 57: /* expr: expr '/' expr  */
#line 401 "parser.y"
                    {Symbol *simb = NULL;
            if((yyvsp[0].node)->info->exprType != (yyvsp[-2].node)->info->exprType){
                if(((yyvsp[-2].node)->info->exprType != INT1 && (yyvsp[-2].node)->info->exprType != FLOAT1)||
                ((yyvsp[0].node)->info->exprType != INT1 && (yyvsp[0].node)->info->exprType != FLOAT1)){
                    yyerror("Error de tipo");
                    YYABORT;
                }else{
                    yyerror("Warning: tipos no coinciden");
                    simb = create_symb(FLOAT1, 0, NULL);
                }
            }else{
                simb = create_symb((yyvsp[0].node)->info->exprType, 0, NULL);
            }
            (yyval.node) = create_node(NODE_OP_DIV, simb, (yyvsp[-2].node), (yyvsp[0].node), NULL);
        }
#line 1875 "parser.tab.c"
    break;

  case 58: /* expr: expr '%' expr  */
#line 416 "parser.y"
                    {Symbol *simb = NULL;
            if((yyvsp[0].node)->info->exprType != (yyvsp[-2].node)->info->exprType){
                if(((yyvsp[-2].node)->info->exprType != INT1 && (yyvsp[-2].node)->info->exprType != FLOAT1)||
                ((yyvsp[0].node)->info->exprType != INT1 && (yyvsp[0].node)->info->exprType != FLOAT1)){
                    yyerror("Error de tipo");
                    YYABORT;
                }else{
                    yyerror("Warning: tipos no coinciden");
                    simb = create_symb(FLOAT1, 0, NULL);
                }
            }else{
                simb = create_symb((yyvsp[0].node)->info->exprType, 0, NULL);
            }
            (yyval.node) = create_node(NODE_OP_MOD, simb, (yyvsp[-2].node), (yyvsp[0].node), NULL);
        }
#line 1895 "parser.tab.c"
    break;

  case 59: /* expr: expr LE expr  */
#line 431 "parser.y"
                   {
            Symbol *simb = NULL;
            if((yyvsp[0].node)->info->exprType != (yyvsp[-2].node)->info->exprType){
                if(((yyvsp[-2].node)->info->exprType != INT1 && (yyvsp[-2].node)->info->exprType != FLOAT1)||
                ((yyvsp[0].node)->info->exprType != INT1 && (yyvsp[0].node)->info->exprType != FLOAT1)){
                    yyerror("Error de tipo");
                    YYABORT;
                }else{
                    yyerror("Warning: tipos no coinciden");
                }
            }
            simb = create_symb((yyvsp[0].node)->info->exprType, 0, NULL);
            (yyval.node) = create_node(NODE_OP_OR, simb, create_node(NODE_OP_LESS, simb, (yyvsp[-2].node), (yyvsp[0].node), NULL), create_node(NODE_OP_EQUAL, simb, (yyvsp[-2].node), (yyvsp[0].node), NULL), NULL);
    }
#line 1914 "parser.tab.c"
    break;

  case 60: /* expr: expr '<' expr  */
#line 445 "parser.y"
                    {Symbol *simb = NULL;
            if((yyvsp[0].node)->info->exprType != (yyvsp[-2].node)->info->exprType){
                if(((yyvsp[-2].node)->info->exprType != INT1 && (yyvsp[-2].node)->info->exprType != FLOAT1)||
                ((yyvsp[0].node)->info->exprType != INT1 && (yyvsp[0].node)->info->exprType != FLOAT1)){
                    yyerror("Error de tipo");
                    YYABORT;
                }else{
                    yyerror("Warning: tipos no coinciden");
                }
            }
            simb = create_symb(BOOL1, 0, NULL);
            (yyval.node) = create_node(NODE_OP_LESS, simb, (yyvsp[-2].node), (yyvsp[0].node), NULL);
        }
#line 1932 "parser.tab.c"
    break;

  case 61: /* expr: expr '>' expr  */
#line 458 "parser.y"
                    {Symbol *simb = NULL;
            if((yyvsp[0].node)->info->exprType != (yyvsp[-2].node)->info->exprType){
                if(((yyvsp[-2].node)->info->exprType != INT1 && (yyvsp[-2].node)->info->exprType != FLOAT1)||
                ((yyvsp[0].node)->info->exprType != INT1 && (yyvsp[0].node)->info->exprType != FLOAT1)){
                    yyerror("Error de tipo");
                    YYABORT;
                }else{
                    yyerror("Warning: tipos no coinciden");
                }
            }
            simb = create_symb(BOOL1, 0, NULL);
            (yyval.node) = create_node(NODE_OP_GREAT, simb, (yyvsp[-2].node), (yyvsp[0].node), NULL);
        }
#line 1950 "parser.tab.c"
    break;

  case 62: /* expr: expr EQUAL expr  */
#line 471 "parser.y"
                      {Symbol *simb = NULL;
            simb = create_symb(BOOL1, 0, NULL);
            (yyval.node) = create_node(NODE_OP_EQUAL, simb, (yyvsp[-2].node), (yyvsp[0].node), NULL);

        }
#line 1960 "parser.tab.c"
    break;

  case 63: /* expr: expr AND expr  */
#line 476 "parser.y"
                    {Symbol *simb = NULL;
            if((yyvsp[0].node)->info->exprType != (yyvsp[-2].node)->info->exprType || (yyvsp[-2].node)->info->exprType != BOOL1){
                yyerror("Error de tipo");
                YYABORT;
            }
            simb = create_symb((yyvsp[0].node)->info->exprType, 0, NULL);
            (yyval.node) = create_node(NODE_OP_AND, simb, (yyvsp[-2].node), (yyvsp[0].node), NULL);
        }
#line 1973 "parser.tab.c"
    break;

  case 64: /* expr: expr OR expr  */
#line 484 "parser.y"
                    {Symbol *simb = NULL;
            if((yyvsp[0].node)->info->exprType != (yyvsp[-2].node)->info->exprType || (yyvsp[-2].node)->info->exprType != BOOL1){
                yyerror("Error de tipo");
                YYABORT;
            }
            simb = create_symb((yyvsp[0].node)->info->exprType, 0, NULL);
            (yyval.node) = create_node(NODE_OP_OR, simb, (yyvsp[-2].node), (yyvsp[0].node), NULL);
        }
#line 1986 "parser.tab.c"
    break;

  case 65: /* expr: '-' expr  */
#line 492 "parser.y"
                            {
            if((yyvsp[0].node)->info->exprType != INT1 && (yyvsp[0].node)->info->exprType != FLOAT1){
                yyerror("Error de tipo");
                YYABORT;
            }
            Symbol *simb = create_symb((yyvsp[0].node)->info->exprType, (yyvsp[0].node)->info->value, NULL);
            Symbol *zero = create_symb((yyvsp[0].node)->info->exprType, 0, NULL);
            Node *zero_node = create_node(NODE_VAL_NUM, zero, NULL, NULL, NULL);
            (yyval.node) = create_node(NODE_OP_SUB, simb, zero_node, (yyvsp[0].node), NULL);
            }
#line 2001 "parser.tab.c"
    break;

  case 66: /* expr: '!' expr  */
#line 502 "parser.y"
                {
            if((yyvsp[0].node)->info->exprType != BOOL1){
                yyerror("Error de tipo");
                YYABORT;
            }
            Symbol *simb = create_symb((yyvsp[0].node)->info->exprType, (yyvsp[0].node)->info->value, NULL);
            if((yyvsp[0].node)->info->exprType != BOOL1){
                yyerror("Error de tipo");
                YYABORT;
            }
            (yyval.node) = create_node(NODE_OP_NOT, simb, (yyvsp[0].node), NULL, NULL);
            }
#line 2018 "parser.tab.c"
    break;

  case 67: /* expr: '(' expr ')'  */
#line 514 "parser.y"
                   {(yyval.node) = (yyvsp[-1].node);}
#line 2024 "parser.tab.c"
    break;

  case 68: /* Ids_decl: ID ',' Ids_decl  */
#line 517 "parser.y"
                             {
            if(!find_in_level(tabla, (yyvsp[-2].str))){
                Symbol *simb = create_symb(NOT_TYPE, 0, (yyvsp[-2].str));
                insert_symbolo(tabla, simb);
                (yyval.node) = create_node(NODE_AUX_DEC, simb, (yyvsp[0].node), NULL, NULL);
            } else {
                yyerror("Error de sintaxis: Variable declarada mas de una vez\n");
                YYABORT;
            }
        }
#line 2039 "parser.tab.c"
    break;

  case 69: /* Ids_decl: ID  */
#line 527 "parser.y"
            {
            if(!find_in_level(tabla, (yyvsp[0].str))){
                Symbol *simb = create_symb(NOT_TYPE, 0, (yyvsp[0].str));
                insert_symbolo(tabla, simb);
                (yyval.node) = create_node(NODE_AUX_DEC, simb, NULL, NULL, NULL);
            }else {
                yyerror("Error de sintaxis: Variable declarada mas de una vez\n");
                YYABORT;
            }
        }
#line 2054 "parser.tab.c"
    break;

  case 70: /* Var_decl: Type Ids_decl  */
#line 539 "parser.y"
                        {
        (yyval.node) = create_node(NODE_DECLARATION, NULL, (yyvsp[-1].node), (yyvsp[0].node), NULL);
        (yyvsp[0].node)->info->exprType = (yyvsp[-1].node)->info->exprType;
        push_type((yyvsp[0].node));

        }
#line 2065 "parser.tab.c"
    break;

  case 71: /* Asign: ID '=' expr  */
#line 547 "parser.y"
                   { Symbol *simb = find_symbol(tabla, (yyvsp[-2].str));
            if(!simb){
                yyerror("Error de sintaxis: Variable no declarada");
                YYABORT;
            } else {
            if((yyvsp[0].node)->info->exprType != simb->exprType){
                if((simb->exprType != INT1 && simb->exprType != FLOAT1)||
                ((yyvsp[0].node)->info->exprType != INT1 && (yyvsp[0].node)->info->exprType != FLOAT1)){
                    yyerror("Error de tipo");
                    YYABORT;
                }else{
                        yyerror("Warning: tipos no coinciden");
                }
            }
            (yyval.node) = create_node(NODE_ASSIGN, simb, (yyvsp[0].node), NULL, NULL);
            }
        }
#line 2087 "parser.tab.c"
    break;


#line 2091 "parser.tab.c"

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

#line 566 "parser.y"


void yyerror(const char *s) {
    fprintf(stderr, "%s en la linea %d\n", s, lines);
}

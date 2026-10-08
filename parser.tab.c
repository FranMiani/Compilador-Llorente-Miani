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
#define _GNU_SOURCE

SymbolTable *tabla;
Node *father;

int lines = 1;
ExprType returnType = VOID1;

void addLine(){
    lines++;
}

extern FILE *yyin;
int yylex(void);
void yyerror(const char *s);

#line 95 "parser.tab.c"

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
  YYSYMBOL_EQUAL = 10,                     /* EQUAL  */
  YYSYMBOL_AND = 11,                       /* AND  */
  YYSYMBOL_OR = 12,                        /* OR  */
  YYSYMBOL_ID = 13,                        /* ID  */
  YYSYMBOL_LIT_INT = 14,                   /* LIT_INT  */
  YYSYMBOL_TRUE = 15,                      /* TRUE  */
  YYSYMBOL_FALSE = 16,                     /* FALSE  */
  YYSYMBOL_LIT_FLOAT = 17,                 /* LIT_FLOAT  */
  YYSYMBOL_VOID = 18,                      /* VOID  */
  YYSYMBOL_19_ = 19,                       /* '<'  */
  YYSYMBOL_20_ = 20,                       /* '>'  */
  YYSYMBOL_21_ = 21,                       /* '+'  */
  YYSYMBOL_22_ = 22,                       /* '-'  */
  YYSYMBOL_23_ = 23,                       /* '*'  */
  YYSYMBOL_24_ = 24,                       /* '/'  */
  YYSYMBOL_25_ = 25,                       /* '%'  */
  YYSYMBOL_26_ = 26,                       /* '!'  */
  YYSYMBOL_UMINUS = 27,                    /* UMINUS  */
  YYSYMBOL_28_ = 28,                       /* ';'  */
  YYSYMBOL_29_ = 29,                       /* '('  */
  YYSYMBOL_30_ = 30,                       /* ')'  */
  YYSYMBOL_31_ = 31,                       /* '{'  */
  YYSYMBOL_32_ = 32,                       /* '}'  */
  YYSYMBOL_33_ = 33,                       /* ','  */
  YYSYMBOL_34_ = 34,                       /* '='  */
  YYSYMBOL_YYACCEPT = 35,                  /* $accept  */
  YYSYMBOL_preinput = 36,                  /* preinput  */
  YYSYMBOL_input = 37,                     /* input  */
  YYSYMBOL_Method_decl = 38,               /* Method_decl  */
  YYSYMBOL_39_1 = 39,                      /* $@1  */
  YYSYMBOL_40_2 = 40,                      /* $@2  */
  YYSYMBOL_41_3 = 41,                      /* $@3  */
  YYSYMBOL_42_4 = 42,                      /* $@4  */
  YYSYMBOL_43_5 = 43,                      /* $@5  */
  YYSYMBOL_44_6 = 44,                      /* $@6  */
  YYSYMBOL_Type = 45,                      /* Type  */
  YYSYMBOL_Params = 46,                    /* Params  */
  YYSYMBOL_Param = 47,                     /* Param  */
  YYSYMBOL_Linea = 48,                     /* Linea  */
  YYSYMBOL_Sentencia = 49,                 /* Sentencia  */
  YYSYMBOL_Bloque = 50,                    /* Bloque  */
  YYSYMBOL_51_7 = 51,                      /* $@7  */
  YYSYMBOL_Params_pass = 52,               /* Params_pass  */
  YYSYMBOL_Method_call = 53,               /* Method_call  */
  YYSYMBOL_expr = 54,                      /* expr  */
  YYSYMBOL_Ids_decl = 55,                  /* Ids_decl  */
  YYSYMBOL_Var_decl = 56,                  /* Var_decl  */
  YYSYMBOL_Asign = 57                      /* Asign  */
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
#define YYFINAL  11
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   238

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  35
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  23
/* YYNRULES -- Number of rules.  */
#define YYNRULES  63
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  125

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   274


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
       2,     2,     2,    26,     2,     2,     2,    25,     2,     2,
      29,    30,    23,    21,    33,    22,     2,    24,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    28,
      19,    34,    20,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    31,     2,    32,     2,     2,     2,     2,
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
      15,    16,    17,    18,    27
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    55,    55,    63,    66,    69,    72,    78,    88,    78,
     103,   112,   103,   126,   126,   141,   141,   156,   159,   162,
     168,   171,   174,   186,   187,   191,   192,   193,   199,   205,
     211,   221,   227,   228,   229,   232,   232,   236,   237,   240,
     251,   270,   277,   278,   280,   282,   284,   286,   301,   316,
     331,   346,   361,   374,   387,   391,   399,   407,   415,   427,
     430,   440,   452,   459
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
  "INT", "RETURN", "BOOLEAN", "FLOAT", "EQUAL", "AND", "OR", "ID",
  "LIT_INT", "TRUE", "FALSE", "LIT_FLOAT", "VOID", "'<'", "'>'", "'+'",
  "'-'", "'*'", "'/'", "'%'", "'!'", "UMINUS", "';'", "'('", "')'", "'{'",
  "'}'", "','", "'='", "$accept", "preinput", "input", "Method_decl",
  "$@1", "$@2", "$@3", "$@4", "$@5", "$@6", "Type", "Params", "Param",
  "Linea", "Sentencia", "Bloque", "$@7", "Params_pass", "Method_call",
  "expr", "Ids_decl", "Var_decl", "Asign", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-90)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  ((Yyn) == YYTABLE_NINF)

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     119,   -90,   -90,   -90,    -4,    19,   -90,   119,    20,    11,
      25,   -90,   -90,    31,   -90,   119,    10,    29,    49,   -90,
     -90,    69,   -90,    69,    43,   -90,    60,    67,    66,    74,
      79,    81,    -1,   -90,   -90,    69,    -1,   -90,    80,    83,
     144,     8,   -90,   -90,    49,    91,    -1,   -90,    98,   108,
     116,   114,   -90,   117,   115,   161,   161,   121,   -90,   -90,
     -90,   -90,   161,   161,   -90,   161,   -90,   110,   126,   161,
      -1,   -90,   -90,   -90,   -90,   -90,    -1,   -90,    -1,    62,
      78,   -90,   -90,    94,   161,   161,   161,   161,   161,   161,
     161,   161,   161,   161,   -90,   -90,   123,    46,   174,   131,
     132,   133,   120,   120,   -90,   197,   190,   213,   197,   197,
      70,    70,   -90,   -90,   -90,   -90,   161,   -90,   -90,   -90,
     163,   -90,   -90,   120,   -90
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,    17,    18,    19,     0,     0,     2,     5,     0,     0,
       0,     1,     6,    61,    62,     4,    10,     7,     0,     3,
      15,     0,    13,     0,    61,    60,     0,     0,     0,    21,
       0,     0,    23,    22,    11,     0,    23,     8,     0,     0,
       0,     0,    32,    35,     0,     0,    23,    33,     0,     0,
       0,     0,    20,     0,     0,     0,     0,    41,    44,    46,
      45,    43,     0,     0,    31,     0,    42,     0,     0,     0,
      23,    16,    24,    34,    25,    26,    23,    14,    23,     0,
       0,    57,    58,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    30,    39,     0,    38,    63,     0,
       0,     0,     0,     0,    59,    54,    55,    56,    52,    53,
      47,    48,    49,    50,    51,    40,     0,    36,    12,     9,
      27,    29,    37,     0,    28
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -90,   -90,    21,   -90,   -90,   -90,   -90,   -90,   -90,   -90,
       3,    -3,   -90,   -35,   -90,   -89,   -90,    52,   -15,   -40,
     151,   147,   -90
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     5,     6,     7,    23,    54,    21,    51,    30,    26,
      44,    28,    29,    45,    46,    47,    70,    96,    66,    97,
      14,    49,    50
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      67,    53,    38,     8,    39,     1,    40,     2,     3,    10,
       8,    72,    41,   120,   121,    79,    80,    48,     8,    11,
      31,    48,    81,    82,    27,    83,    27,    42,    12,    98,
      43,    48,    52,    13,   124,    99,    19,    68,    27,    15,
      20,   100,    69,   101,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,    16,    48,    84,    85,    86,    22,
      17,    48,    24,    48,    18,    87,    88,    89,    90,    91,
      92,    93,    84,    85,    86,     1,    18,     2,     3,   116,
      33,    87,    88,    89,    90,    91,    92,    93,    84,    85,
      86,    32,   102,    91,    92,    93,    34,    87,    88,    89,
      90,    91,    92,    93,    84,    85,    86,    35,   103,    55,
      36,    37,    56,    87,    88,    89,    90,    91,    92,    93,
      84,    85,    86,    71,   104,     1,    73,     2,     3,    87,
      88,    89,    90,    91,    92,    93,    74,     4,    94,    57,
      58,    59,    60,    61,    75,    76,    78,     9,    62,    77,
      68,    43,    63,   115,     9,    65,    95,    57,    58,    59,
      60,    61,     9,   117,   118,   119,    62,   123,   122,    25,
      63,     0,    64,    65,    57,    58,    59,    60,    61,     0,
       0,     0,     0,    62,    84,    85,    86,    63,     0,     0,
      65,     0,     0,    87,    88,    89,    90,    91,    92,    93,
      84,     0,    86,     0,     0,     0,     0,    -1,     0,    87,
      88,    89,    90,    91,    92,    93,    -1,    -1,    89,    90,
      91,    92,    93,    84,     0,     0,     0,     0,     0,     0,
       0,     0,    87,    88,    89,    90,    91,    92,    93
};

static const yytype_int8 yycheck[] =
{
      40,    36,     3,     0,     5,     6,     7,     8,     9,    13,
       7,    46,    13,   102,   103,    55,    56,    32,    15,     0,
      23,    36,    62,    63,    21,    65,    23,    28,     7,    69,
      31,    46,    35,    13,   123,    70,    15,    29,    35,    28,
      30,    76,    34,    78,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    29,    70,    10,    11,    12,    30,
      29,    76,    13,    78,    33,    19,    20,    21,    22,    23,
      24,    25,    10,    11,    12,     6,    33,     8,     9,    33,
      13,    19,    20,    21,    22,    23,    24,    25,    10,    11,
      12,    31,    30,    23,    24,    25,    30,    19,    20,    21,
      22,    23,    24,    25,    10,    11,    12,    33,    30,    29,
      31,    30,    29,    19,    20,    21,    22,    23,    24,    25,
      10,    11,    12,    32,    30,     6,    28,     8,     9,    19,
      20,    21,    22,    23,    24,    25,    28,    18,    28,    13,
      14,    15,    16,    17,    28,    31,    31,     0,    22,    32,
      29,    31,    26,    30,     7,    29,    30,    13,    14,    15,
      16,    17,    15,    32,    32,    32,    22,     4,   116,    18,
      26,    -1,    28,    29,    13,    14,    15,    16,    17,    -1,
      -1,    -1,    -1,    22,    10,    11,    12,    26,    -1,    -1,
      29,    -1,    -1,    19,    20,    21,    22,    23,    24,    25,
      10,    -1,    12,    -1,    -1,    -1,    -1,    10,    -1,    19,
      20,    21,    22,    23,    24,    25,    19,    20,    21,    22,
      23,    24,    25,    10,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    19,    20,    21,    22,    23,    24,    25
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     6,     8,     9,    18,    36,    37,    38,    45,    56,
      13,     0,    37,    13,    55,    28,    29,    29,    33,    37,
      30,    41,    30,    39,    13,    55,    44,    45,    46,    47,
      43,    46,    31,    13,    30,    33,    31,    30,     3,     5,
       7,    13,    28,    31,    45,    48,    49,    50,    53,    56,
      57,    42,    46,    48,    40,    29,    29,    13,    14,    15,
      16,    17,    22,    26,    28,    29,    53,    54,    29,    34,
      51,    32,    48,    28,    28,    28,    31,    32,    31,    54,
      54,    54,    54,    54,    10,    11,    12,    19,    20,    21,
      22,    23,    24,    25,    28,    30,    52,    54,    54,    48,
      48,    48,    30,    30,    30,    54,    54,    54,    54,    54,
      54,    54,    54,    54,    54,    30,    33,    32,    32,    32,
      50,    50,    52,     4,    50
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    35,    36,    37,    37,    37,    37,    39,    40,    38,
      41,    42,    38,    43,    38,    44,    38,    45,    45,    45,
      46,    46,    47,    48,    48,    49,    49,    49,    49,    49,
      49,    49,    49,    49,    49,    51,    50,    52,    52,    53,
      53,    54,    54,    54,    54,    54,    54,    54,    54,    54,
      54,    54,    54,    54,    54,    54,    54,    54,    54,    54,
      55,    55,    56,    57
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     3,     2,     1,     2,     0,     0,    10,
       0,     0,    10,     0,     8,     0,     8,     1,     1,     1,
       3,     1,     2,     0,     2,     2,     2,     5,     7,     5,
       3,     2,     1,     1,     2,     0,     4,     3,     1,     3,
       4,     1,     1,     1,     1,     1,     1,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     2,     2,     3,
       3,     1,     2,     3
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
#line 55 "parser.y"
                  {
    Symbol *simb = create_symb(NOT_TYPE, 0, NULL);
    (yyval.node) = create_node(NODE_OP_FUNC, simb, (yyvsp[0].node), NULL, NULL);
    father = (yyval.node);
}
#line 1241 "parser.tab.c"
    break;

  case 3: /* input: Var_decl ';' input  */
#line 63 "parser.y"
                       {
                        (yyval.node) = create_node(NODE_OP_NEWLINE, NULL, (yyvsp[-2].node), (yyvsp[0].node), NULL);
                    }
#line 1249 "parser.tab.c"
    break;

  case 4: /* input: Var_decl ';'  */
#line 66 "parser.y"
                   {
                        (yyval.node) = create_node(NODE_OP_NEWLINE, NULL, (yyvsp[-1].node), NULL, NULL);
                    }
#line 1257 "parser.tab.c"
    break;

  case 5: /* input: Method_decl  */
#line 69 "parser.y"
                  {
                        (yyval.node) = create_node(NODE_OP_NEWLINE, NULL, (yyvsp[0].node), NULL, NULL);
                    }
#line 1265 "parser.tab.c"
    break;

  case 6: /* input: Method_decl input  */
#line 72 "parser.y"
                        {
                        (yyval.node) = create_node(NODE_OP_NEWLINE, NULL, (yyvsp[-1].node), (yyvsp[0].node), NULL);
                    }
#line 1273 "parser.tab.c"
    break;

  case 7: /* $@1: %empty  */
#line 78 "parser.y"
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
#line 1289 "parser.tab.c"
    break;

  case 8: /* $@2: %empty  */
#line 88 "parser.y"
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
#line 1304 "parser.tab.c"
    break;

  case 9: /* Method_decl: Type ID '(' $@1 Params ')' $@2 '{' Linea '}'  */
#line 97 "parser.y"
                        {
            close_level(tabla);
            print_from_to(find_symbol(tabla, (yyvsp[-8].str))->end, find_symbol(tabla, (yyvsp[-8].str))->init);
            (yyval.node) = create_node(NODE_MET_DECLARATION, find_symbol(tabla, (yyvsp[-8].str)), (yyvsp[-5].node), (yyvsp[-1].node), NULL);
            returnType = VOID1;
        }
#line 1315 "parser.tab.c"
    break;

  case 10: /* $@3: %empty  */
#line 103 "parser.y"
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
#line 1330 "parser.tab.c"
    break;

  case 11: /* $@4: %empty  */
#line 112 "parser.y"
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
#line 1345 "parser.tab.c"
    break;

  case 12: /* Method_decl: VOID ID '(' $@3 Params ')' $@4 '{' Linea '}'  */
#line 121 "parser.y"
                        {
            close_level(tabla);

            (yyval.node) = create_node(NODE_MET_DECLARATION, find_symbol(tabla, (yyvsp[-8].str)), (yyvsp[-5].node), (yyvsp[-1].node), NULL);
        }
#line 1355 "parser.tab.c"
    break;

  case 13: /* $@5: %empty  */
#line 126 "parser.y"
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
#line 1371 "parser.tab.c"
    break;

  case 14: /* Method_decl: Type ID '(' ')' $@5 '{' Linea '}'  */
#line 136 "parser.y"
                        {
            close_level(tabla);
            returnType = VOID1;
            (yyval.node) = create_node(NODE_MET_DECLARATION, find_symbol(tabla, (yyvsp[-6].str)), NULL, (yyvsp[-1].node), NULL);
        }
#line 1381 "parser.tab.c"
    break;

  case 15: /* $@6: %empty  */
#line 141 "parser.y"
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
#line 1396 "parser.tab.c"
    break;

  case 16: /* Method_decl: VOID ID '(' ')' $@6 '{' Linea '}'  */
#line 150 "parser.y"
                        {
            close_level(tabla);

            (yyval.node) = create_node(NODE_MET_DECLARATION, find_symbol(tabla, (yyvsp[-6].str)), NULL, (yyvsp[-1].node), NULL);
        }
#line 1406 "parser.tab.c"
    break;

  case 17: /* Type: INT  */
#line 156 "parser.y"
            { Symbol *simb = create_symb(INT1, 0, NULL);
            (yyval.node) = create_node(NODE_AUX, simb, NULL, NULL, NULL);
            }
#line 1414 "parser.tab.c"
    break;

  case 18: /* Type: BOOLEAN  */
#line 159 "parser.y"
                { Symbol *simb = create_symb(BOOL1, 0, NULL);
            (yyval.node) = create_node(NODE_AUX, simb, NULL, NULL, NULL);
            }
#line 1422 "parser.tab.c"
    break;

  case 19: /* Type: FLOAT  */
#line 162 "parser.y"
            { Symbol *simb = create_symb(FLOAT1, 0, NULL);
            (yyval.node) = create_node(NODE_AUX, simb, NULL, NULL, NULL);
            }
#line 1430 "parser.tab.c"
    break;

  case 20: /* Params: Param ',' Params  */
#line 168 "parser.y"
                        {
            (yyval.node) = create_node(NODE_PARAM_DECLARATION, NULL, (yyvsp[-2].node), (yyvsp[0].node), NULL);
            }
#line 1438 "parser.tab.c"
    break;

  case 21: /* Params: Param  */
#line 171 "parser.y"
            {(yyval.node) = (yyvsp[0].node);}
#line 1444 "parser.tab.c"
    break;

  case 22: /* Param: Type ID  */
#line 174 "parser.y"
               {
            if (find_in_level(tabla, (yyvsp[0].str))) {
                yyerror("Error de sintaxis: Parametro declarado mas de una vez\n");
                YYABORT;
            }
            Symbol *simb = create_symb((yyvsp[-1].node)->info->exprType, 0, (yyvsp[0].str));
            insert_symbolo(tabla, simb);
            (yyval.node) = create_node(NODE_PARAM_DECLARATION, simb, NULL, NULL, NULL);
        }
#line 1458 "parser.tab.c"
    break;

  case 23: /* Linea: %empty  */
#line 186 "parser.y"
                    {(yyval.node) = NULL;}
#line 1464 "parser.tab.c"
    break;

  case 24: /* Linea: Sentencia Linea  */
#line 187 "parser.y"
                        {(yyval.node) = create_node(NODE_OP_NEWLINE, NULL, (yyvsp[-1].node), (yyvsp[0].node), NULL);}
#line 1470 "parser.tab.c"
    break;

  case 25: /* Sentencia: Var_decl ';'  */
#line 191 "parser.y"
                    {(yyval.node) = (yyvsp[-1].node);}
#line 1476 "parser.tab.c"
    break;

  case 26: /* Sentencia: Asign ';'  */
#line 192 "parser.y"
                {(yyval.node) = (yyvsp[-1].node);}
#line 1482 "parser.tab.c"
    break;

  case 27: /* Sentencia: IF '(' expr ')' Bloque  */
#line 193 "parser.y"
                             {
                    if((yyvsp[-2].node)->info->exprType != BOOL1){
                        yyerror("Error de sintaxis: expresion no booleana");
                    }
                    (yyval.node) = create_node(NODE_IF, NULL, (yyvsp[-2].node), (yyvsp[0].node), NULL);
                    }
#line 1493 "parser.tab.c"
    break;

  case 28: /* Sentencia: IF '(' expr ')' Bloque ELSE Bloque  */
#line 199 "parser.y"
                                            {
                    if((yyvsp[-4].node)->info->exprType != BOOL1){
                        yyerror("Error de sintaxis: expresion no booleana");
                    }
                    (yyval.node) = create_node(NODE_IF_ELSE, NULL, (yyvsp[-4].node), (yyvsp[-2].node), (yyvsp[0].node));
                    }
#line 1504 "parser.tab.c"
    break;

  case 29: /* Sentencia: WHILE '(' expr ')' Bloque  */
#line 205 "parser.y"
                                {
                    if((yyvsp[-2].node)->info->exprType != BOOL1){
                        yyerror("Error de sintaxis: expresion no booleana");
                    }
                    (yyval.node) = create_node(NODE_WHILE, NULL, (yyvsp[-2].node), (yyvsp[0].node), NULL);
                    }
#line 1515 "parser.tab.c"
    break;

  case 30: /* Sentencia: RETURN expr ';'  */
#line 211 "parser.y"
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
#line 1530 "parser.tab.c"
    break;

  case 31: /* Sentencia: RETURN ';'  */
#line 221 "parser.y"
                 {Symbol *simb = create_symb(VOID1, 0, NULL);
                    if(returnType!=VOID1){
                        yyerror("Error de sintaxis: tipo de retorno incompatible");
                    }
                    (yyval.node) = create_node(NODE_OP_RETURN, simb, NULL, NULL, NULL);
                    }
#line 1541 "parser.tab.c"
    break;

  case 32: /* Sentencia: ';'  */
#line 227 "parser.y"
          {(yyval.node)=NULL;}
#line 1547 "parser.tab.c"
    break;

  case 33: /* Sentencia: Bloque  */
#line 228 "parser.y"
             {(yyval.node) = (yyvsp[0].node);}
#line 1553 "parser.tab.c"
    break;

  case 34: /* Sentencia: Method_call ';'  */
#line 229 "parser.y"
                      {(yyval.node)=(yyvsp[-1].node);}
#line 1559 "parser.tab.c"
    break;

  case 35: /* $@7: %empty  */
#line 232 "parser.y"
            {new_level(tabla);}
#line 1565 "parser.tab.c"
    break;

  case 36: /* Bloque: '{' $@7 Linea '}'  */
#line 232 "parser.y"
                                          {close_level(tabla);
        (yyval.node) = (yyvsp[-1].node);
        }
#line 1573 "parser.tab.c"
    break;

  case 37: /* Params_pass: expr ',' Params_pass  */
#line 236 "parser.y"
                                  {(yyval.node) = create_node(NODE_PARAM_PASS, NULL, (yyvsp[-2].node), (yyvsp[0].node), NULL);}
#line 1579 "parser.tab.c"
    break;

  case 38: /* Params_pass: expr  */
#line 237 "parser.y"
           {(yyval.node) = (yyvsp[0].node);}
#line 1585 "parser.tab.c"
    break;

  case 39: /* Method_call: ID '(' ')'  */
#line 240 "parser.y"
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
#line 1601 "parser.tab.c"
    break;

  case 40: /* Method_call: ID '(' Params_pass ')'  */
#line 251 "parser.y"
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
#line 1622 "parser.tab.c"
    break;

  case 41: /* expr: ID  */
#line 270 "parser.y"
            {   Symbol *sim = find_symbol(tabla, (yyvsp[0].str));
                if(!sim){
                yyerror("Error de sintaxis: Variable no declarado");
                YYABORT;
                }
                (yyval.node) = create_node(NODE_ID, sim, NULL, NULL, NULL);
            }
#line 1634 "parser.tab.c"
    break;

  case 42: /* expr: Method_call  */
#line 277 "parser.y"
                  {(yyval.node) = (yyvsp[0].node);}
#line 1640 "parser.tab.c"
    break;

  case 43: /* expr: LIT_FLOAT  */
#line 278 "parser.y"
                    {Symbol *simb = create_symb(FLOAT1, (yyvsp[0].num), NULL);
        (yyval.node) = create_node(NODE_VAL_NUM, simb, NULL, NULL, NULL);}
#line 1647 "parser.tab.c"
    break;

  case 44: /* expr: LIT_INT  */
#line 280 "parser.y"
                {Symbol *simb = create_symb(INT1, (yyvsp[0].num), NULL);
        (yyval.node) = create_node(NODE_VAL_NUM, simb, NULL, NULL, NULL);}
#line 1654 "parser.tab.c"
    break;

  case 45: /* expr: FALSE  */
#line 282 "parser.y"
            {Symbol *simb = create_symb(BOOL1, 0, NULL);
        (yyval.node) = create_node(NODE_VAL_FALSE, simb, NULL, NULL, NULL);}
#line 1661 "parser.tab.c"
    break;

  case 46: /* expr: TRUE  */
#line 284 "parser.y"
           {Symbol *simb = create_symb(BOOL1, 1, NULL);
        (yyval.node) = create_node(NODE_VAL_TRUE, simb, NULL, NULL, NULL);}
#line 1668 "parser.tab.c"
    break;

  case 47: /* expr: expr '+' expr  */
#line 286 "parser.y"
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
#line 1688 "parser.tab.c"
    break;

  case 48: /* expr: expr '-' expr  */
#line 301 "parser.y"
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
#line 1708 "parser.tab.c"
    break;

  case 49: /* expr: expr '*' expr  */
#line 316 "parser.y"
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
#line 1728 "parser.tab.c"
    break;

  case 50: /* expr: expr '/' expr  */
#line 331 "parser.y"
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
#line 1748 "parser.tab.c"
    break;

  case 51: /* expr: expr '%' expr  */
#line 346 "parser.y"
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
#line 1768 "parser.tab.c"
    break;

  case 52: /* expr: expr '<' expr  */
#line 361 "parser.y"
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
#line 1786 "parser.tab.c"
    break;

  case 53: /* expr: expr '>' expr  */
#line 374 "parser.y"
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
#line 1804 "parser.tab.c"
    break;

  case 54: /* expr: expr EQUAL expr  */
#line 387 "parser.y"
                      {Symbol *simb = NULL;
            simb = create_symb(BOOL1, 0, NULL);
            (yyval.node) = create_node(NODE_OP_EQUAL, simb, (yyvsp[-2].node), (yyvsp[0].node), NULL);
        }
#line 1813 "parser.tab.c"
    break;

  case 55: /* expr: expr AND expr  */
#line 391 "parser.y"
                    {Symbol *simb = NULL;
            if((yyvsp[0].node)->info->exprType != (yyvsp[-2].node)->info->exprType || (yyvsp[-2].node)->info->exprType != BOOL1){
                yyerror("Error de tipo");
                YYABORT;
            }
            simb = create_symb((yyvsp[0].node)->info->exprType, 0, NULL);
            (yyval.node) = create_node(NODE_OP_AND, simb, (yyvsp[-2].node), (yyvsp[0].node), NULL);
        }
#line 1826 "parser.tab.c"
    break;

  case 56: /* expr: expr OR expr  */
#line 399 "parser.y"
                    {Symbol *simb = NULL;
            if((yyvsp[0].node)->info->exprType != (yyvsp[-2].node)->info->exprType || (yyvsp[-2].node)->info->exprType != BOOL1){
                yyerror("Error de tipo");
                YYABORT;
            }
            simb = create_symb((yyvsp[0].node)->info->exprType, 0, NULL);
            (yyval.node) = create_node(NODE_OP_OR, simb, (yyvsp[-2].node), (yyvsp[0].node), NULL);
        }
#line 1839 "parser.tab.c"
    break;

  case 57: /* expr: '-' expr  */
#line 407 "parser.y"
                            {
            if((yyvsp[0].node)->info->exprType != INT1 && (yyvsp[0].node)->info->exprType != FLOAT1){
                yyerror("Error de tipo");
                YYABORT;
            }
            Symbol *simb = create_symb((yyvsp[0].node)->info->exprType, -(yyvsp[0].node)->info->value, NULL);
            (yyval.node) = create_node(NODE_AUX, simb, (yyvsp[0].node), NULL, NULL);
            }
#line 1852 "parser.tab.c"
    break;

  case 58: /* expr: '!' expr  */
#line 415 "parser.y"
                {
            if((yyvsp[0].node)->info->exprType != BOOL1){
                yyerror("Error de tipo");
                YYABORT;
            }
            Symbol *simb = create_symb((yyvsp[0].node)->info->exprType, -(yyvsp[0].node)->info->value, NULL);
            if((yyvsp[0].node)->info->exprType != BOOL1){
                yyerror("Error de tipo");
                YYABORT;
            }
            (yyval.node) = create_node(NODE_AUX, simb, (yyvsp[0].node), NULL, NULL);
            }
#line 1869 "parser.tab.c"
    break;

  case 59: /* expr: '(' expr ')'  */
#line 427 "parser.y"
                   {(yyval.node) = (yyvsp[-1].node);}
#line 1875 "parser.tab.c"
    break;

  case 60: /* Ids_decl: ID ',' Ids_decl  */
#line 430 "parser.y"
                             {
            if(!find_in_level(tabla, (yyvsp[-2].str))){
                Symbol *simb = create_symb(NOT_TYPE, 0, (yyvsp[-2].str));
                insert_symbolo(tabla, simb);
                (yyval.node) = create_node(NODE_AUX, simb, (yyvsp[0].node), NULL, NULL);
            }else {
                yyerror("Error de sintaxis: Variable declarada mas de una vez\n");
                YYABORT;
            }
            }
#line 1890 "parser.tab.c"
    break;

  case 61: /* Ids_decl: ID  */
#line 440 "parser.y"
            {
            if(!find_in_level(tabla, (yyvsp[0].str))){
                Symbol *simb = create_symb(NOT_TYPE, 0, (yyvsp[0].str));
                insert_symbolo(tabla, simb);
                (yyval.node) = create_node(NODE_AUX, simb, NULL, NULL, NULL);
            }else {
                yyerror("Error de sintaxis: Variable declarada mas de una vez\n");
                YYABORT;
            }
            }
#line 1905 "parser.tab.c"
    break;

  case 62: /* Var_decl: Type Ids_decl  */
#line 452 "parser.y"
                        {
        (yyval.node) = create_node(NODE_DECLARATION, NULL, (yyvsp[-1].node), (yyvsp[0].node), NULL);
        (yyvsp[0].node)->info->exprType = (yyvsp[-1].node)->info->exprType;
        push_type((yyvsp[0].node));
        }
#line 1915 "parser.tab.c"
    break;

  case 63: /* Asign: ID '=' expr  */
#line 459 "parser.y"
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
#line 1937 "parser.tab.c"
    break;


#line 1941 "parser.tab.c"

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

#line 478 "parser.y"


void yyerror(const char *s) {
    fprintf(stderr, "%s en la linea %d\n", s, lines);
}

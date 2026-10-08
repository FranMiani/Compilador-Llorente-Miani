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

int params_cant = 0;
int param_extract = 1;
int temps = 0;
Symbol* registros[3];
Pila *pila;
struct Symbol *retFunc = NULL;
Symbol *pilaTop; 

Symbol* registro_correspondiente() {
    temps = temps % 3;
    return registros[temps++];
}

extern FILE *yyin;
int yylex(void);
void yyerror(const char *s);

#line 109 "parser.tab.c"

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
  YYSYMBOL_37_1 = 37,                      /* $@1  */
  YYSYMBOL_input = 38,                     /* input  */
  YYSYMBOL_Method_decl = 39,               /* Method_decl  */
  YYSYMBOL_40_2 = 40,                      /* $@2  */
  YYSYMBOL_41_3 = 41,                      /* $@3  */
  YYSYMBOL_42_4 = 42,                      /* $@4  */
  YYSYMBOL_43_5 = 43,                      /* $@5  */
  YYSYMBOL_Type = 44,                      /* Type  */
  YYSYMBOL_Params = 45,                    /* Params  */
  YYSYMBOL_Param = 46,                     /* Param  */
  YYSYMBOL_Linea = 47,                     /* Linea  */
  YYSYMBOL_Sentencia = 48,                 /* Sentencia  */
  YYSYMBOL_49_6 = 49,                      /* $@6  */
  YYSYMBOL_50_7 = 50,                      /* $@7  */
  YYSYMBOL_51_8 = 51,                      /* $@8  */
  YYSYMBOL_52_9 = 52,                      /* $@9  */
  YYSYMBOL_53_10 = 53,                     /* $@10  */
  YYSYMBOL_54_11 = 54,                     /* $@11  */
  YYSYMBOL_Bloque = 55,                    /* Bloque  */
  YYSYMBOL_56_12 = 56,                     /* $@12  */
  YYSYMBOL_Params_pass = 57,               /* Params_pass  */
  YYSYMBOL_Method_call = 58,               /* Method_call  */
  YYSYMBOL_expr = 59,                      /* expr  */
  YYSYMBOL_Ids_decl = 60,                  /* Ids_decl  */
  YYSYMBOL_Var_decl = 61,                  /* Var_decl  */
  YYSYMBOL_Asign = 62                      /* Asign  */
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
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   239

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  35
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  28
/* YYNRULES -- Number of rules.  */
#define YYNRULES  68
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  132

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
       0,    69,    69,    69,    85,    88,    91,    94,   100,   100,
     126,   126,   142,   142,   159,   159,   176,   179,   182,   188,
     192,   198,   210,   211,   215,   216,   217,   217,   224,   224,
     224,   224,   232,   232,   232,   240,   251,   258,   259,   260,
     263,   263,   267,   271,   277,   287,   308,   316,   317,   321,
     325,   329,   333,   350,   367,   384,   401,   418,   435,   452,
     461,   471,   481,   491,   505,   508,   519,   532,   540
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
  "'}'", "','", "'='", "$accept", "preinput", "$@1", "input",
  "Method_decl", "$@2", "$@3", "$@4", "$@5", "Type", "Params", "Param",
  "Linea", "Sentencia", "$@6", "$@7", "$@8", "$@9", "$@10", "$@11",
  "Bloque", "$@12", "Params_pass", "Method_call", "expr", "Ids_decl",
  "Var_decl", "Asign", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-65)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  ((Yyn) == YYTABLE_NINF)

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -65,    14,    24,   -65,   -65,   -65,   -65,    13,   -65,    24,
      15,     3,     6,   -65,     5,   -65,    24,     7,     9,    28,
     -65,   -65,    72,   -65,    72,    22,   -65,    27,    46,    30,
      31,    32,    35,    64,   -65,    44,    72,    64,    48,    53,
     -65,   145,   -13,   -65,   -65,    28,    51,    64,   -65,    56,
      57,    58,    64,   -65,    55,    64,   162,    65,    67,   -65,
     -65,   -65,   -65,   162,   162,   -65,   162,   -65,   111,   127,
     162,    64,   -65,   -65,   -65,   -65,   -65,    61,   -65,    76,
     175,   162,   -65,   -65,    95,   162,   162,   162,   162,   162,
     162,   162,   162,   162,   162,   -65,   -65,    80,    79,   175,
      77,   -65,   -65,    81,    83,   175,   -65,   198,   191,   214,
     198,   198,   -17,   -17,   -65,   -65,   -65,   -65,   162,   -65,
      66,    66,    94,   -65,   -65,   -65,    66,   122,   -65,   -65,
      66,   -65
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       2,     0,     0,     1,    16,    17,    18,     0,     3,     6,
       0,     0,     0,     7,    66,    67,     5,    10,     8,     0,
       4,    14,     0,    12,     0,    66,    65,     0,     0,     0,
      20,     0,     0,    22,    21,     0,     0,    22,     0,     0,
      32,     0,     0,    37,    40,     0,     0,    22,    38,     0,
       0,     0,    22,    19,     0,    22,     0,     0,    46,    49,
      51,    50,    48,     0,     0,    36,     0,    47,     0,     0,
       0,    22,    15,    23,    39,    24,    25,     0,    13,     0,
      26,     0,    62,    63,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    35,    44,     0,    43,    68,
       0,    11,     9,     0,     0,    33,    64,    59,    60,    61,
      57,    58,    52,    53,    54,    55,    56,    45,     0,    41,
       0,     0,     0,    42,    27,    29,     0,     0,    34,    30,
       0,    31
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -65,   -65,   -65,    -6,   -65,   -65,   -65,   -65,   -65,    52,
     -23,   -65,   -35,   -65,   -65,   -65,   -65,   -65,   -65,   -65,
     -64,   -65,    10,   -28,   -41,   108,     2,   -65
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     1,     2,     8,     9,    24,    22,    31,    27,    45,
      29,    30,    46,    47,   103,   104,   127,   130,    57,   122,
      48,    71,    97,    67,    98,    15,    50,    51
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      68,    32,    54,    13,    11,    49,    92,    93,    94,    49,
      20,    11,    73,    53,     3,    80,    69,    77,    11,    49,
      79,    70,    82,    83,    49,    84,    12,    49,    14,    99,
       4,    16,     5,     6,    18,    17,   100,    21,    19,    23,
     105,    25,     7,    49,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,    10,    19,   124,   125,    33,    34,
      35,    10,   128,    37,    36,    38,   131,    39,    10,    40,
       4,    41,     5,     6,    28,    52,    28,    42,     4,    55,
       5,     6,    56,    72,    74,    75,    76,    78,    28,    85,
      86,    87,    43,   101,    81,    44,    69,    44,    88,    89,
      90,    91,    92,    93,    94,    85,    86,    87,   102,   119,
     117,   120,   118,   121,    88,    89,    90,    91,    92,    93,
      94,    85,    86,    87,   126,   106,   129,    26,   123,     0,
      88,    89,    90,    91,    92,    93,    94,     0,     0,    95,
      58,    59,    60,    61,    62,     0,     0,     0,     0,    63,
       0,     0,     0,    64,     0,     0,    66,    96,    58,    59,
      60,    61,    62,     0,     0,     0,     0,    63,     0,     0,
       0,    64,     0,    65,    66,    58,    59,    60,    61,    62,
       0,     0,     0,     0,    63,    85,    86,    87,    64,     0,
       0,    66,     0,     0,    88,    89,    90,    91,    92,    93,
      94,    85,     0,    87,     0,     0,     0,     0,    -1,     0,
      88,    89,    90,    91,    92,    93,    94,    -1,    -1,    90,
      91,    92,    93,    94,    85,     0,     0,     0,     0,     0,
       0,     0,     0,    88,    89,    90,    91,    92,    93,    94
};

static const yytype_int16 yycheck[] =
{
      41,    24,    37,     9,     2,    33,    23,    24,    25,    37,
      16,     9,    47,    36,     0,    56,    29,    52,    16,    47,
      55,    34,    63,    64,    52,    66,    13,    55,    13,    70,
       6,    28,     8,     9,    29,    29,    71,    30,    33,    30,
      81,    13,    18,    71,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,     2,    33,   120,   121,    31,    13,
      30,     9,   126,    31,    33,    30,   130,     3,    16,     5,
       6,     7,     8,     9,    22,    31,    24,    13,     6,    31,
       8,     9,    29,    32,    28,    28,    28,    32,    36,    10,
      11,    12,    28,    32,    29,    31,    29,    31,    19,    20,
      21,    22,    23,    24,    25,    10,    11,    12,    32,    32,
      30,    30,    33,    30,    19,    20,    21,    22,    23,    24,
      25,    10,    11,    12,    30,    30,     4,    19,   118,    -1,
      19,    20,    21,    22,    23,    24,    25,    -1,    -1,    28,
      13,    14,    15,    16,    17,    -1,    -1,    -1,    -1,    22,
      -1,    -1,    -1,    26,    -1,    -1,    29,    30,    13,    14,
      15,    16,    17,    -1,    -1,    -1,    -1,    22,    -1,    -1,
      -1,    26,    -1,    28,    29,    13,    14,    15,    16,    17,
      -1,    -1,    -1,    -1,    22,    10,    11,    12,    26,    -1,
      -1,    29,    -1,    -1,    19,    20,    21,    22,    23,    24,
      25,    10,    -1,    12,    -1,    -1,    -1,    -1,    10,    -1,
      19,    20,    21,    22,    23,    24,    25,    19,    20,    21,
      22,    23,    24,    25,    10,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    19,    20,    21,    22,    23,    24,    25
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    36,    37,     0,     6,     8,     9,    18,    38,    39,
      44,    61,    13,    38,    13,    60,    28,    29,    29,    33,
      38,    30,    41,    30,    40,    13,    60,    43,    44,    45,
      46,    42,    45,    31,    13,    30,    33,    31,    30,     3,
       5,     7,    13,    28,    31,    44,    47,    48,    55,    58,
      61,    62,    31,    45,    47,    31,    29,    53,    13,    14,
      15,    16,    17,    22,    26,    28,    29,    58,    59,    29,
      34,    56,    32,    47,    28,    28,    28,    47,    32,    47,
      59,    29,    59,    59,    59,    10,    11,    12,    19,    20,
      21,    22,    23,    24,    25,    28,    30,    57,    59,    59,
      47,    32,    32,    49,    50,    59,    30,    59,    59,    59,
      59,    59,    59,    59,    59,    59,    59,    30,    33,    32,
      30,    30,    54,    57,    55,    55,    30,    51,    55,     4,
      52,    55
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    35,    37,    36,    38,    38,    38,    38,    40,    39,
      41,    39,    42,    39,    43,    39,    44,    44,    44,    45,
      45,    46,    47,    47,    48,    48,    49,    48,    50,    51,
      52,    48,    53,    54,    48,    48,    48,    48,    48,    48,
      56,    55,    57,    57,    58,    58,    59,    59,    59,    59,
      59,    59,    59,    59,    59,    59,    59,    59,    59,    59,
      59,    59,    59,    59,    59,    60,    60,    61,    62
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     2,     3,     2,     1,     2,     0,     9,
       0,     9,     0,     8,     0,     8,     1,     1,     1,     3,
       1,     2,     0,     2,     2,     2,     0,     6,     0,     0,
       0,    10,     0,     0,     7,     3,     2,     1,     1,     2,
       0,     4,     3,     1,     3,     4,     1,     1,     1,     1,
       1,     1,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     2,     2,     3,     3,     1,     2,     3
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
  case 2: /* $@1: %empty  */
#line 69 "parser.y"
           { retFunc = create_symb(NOT_TYPE, 0, "D");
            registros[0] =
            create_symb(NOT_TYPE, NULL, "A");
            registros[1] =
            create_symb(NOT_TYPE, NULL, "B");
            registros[2] =
            create_symb(NOT_TYPE, NULL, "C");
            pilaTop = create_symb(NOT_TYPE, NULL, "TOP"); 
}
#line 1268 "parser.tab.c"
    break;

  case 3: /* preinput: $@1 input  */
#line 77 "parser.y"
        {
    Symbol *simb = create_symb(NOT_TYPE, 0, NULL);
    (yyval.node) = create_node(NODE_OP_FUNC, simb, (yyvsp[0].node), NULL, NULL);
    father = (yyval.node);
}
#line 1278 "parser.tab.c"
    break;

  case 4: /* input: Var_decl ';' input  */
#line 85 "parser.y"
                       {
                        (yyval.node) = create_node(NODE_OP_NEWLINE, NULL, (yyvsp[-2].node), (yyvsp[0].node), NULL);
                    }
#line 1286 "parser.tab.c"
    break;

  case 5: /* input: Var_decl ';'  */
#line 88 "parser.y"
                   {
                        (yyval.node) = create_node(NODE_OP_NEWLINE, NULL, (yyvsp[-1].node), NULL, NULL);
                    }
#line 1294 "parser.tab.c"
    break;

  case 6: /* input: Method_decl  */
#line 91 "parser.y"
                  {
                        (yyval.node) = create_node(NODE_OP_NEWLINE, NULL, (yyvsp[0].node), NULL, NULL);
                    }
#line 1302 "parser.tab.c"
    break;

  case 7: /* input: Method_decl input  */
#line 94 "parser.y"
                        {
                        (yyval.node) = create_node(NODE_OP_NEWLINE, NULL, (yyvsp[-1].node), (yyvsp[0].node), NULL);
                    }
#line 1310 "parser.tab.c"
    break;

  case 8: /* $@2: %empty  */
#line 100 "parser.y"
                {
            if (find_in_level(tabla, (yyvsp[-1].str))) {
                yyerror("Error de sintaxis: Metodo declarado mas de una vez\n");
                YYABORT;
            }
            
            returnType = (yyvsp[-2].node)->info->exprType;
            Symbol *simb = create_symb((yyvsp[-2].node)->info->exprType, 0, (yyvsp[-1].str));
            simb->isFuction = 1;
            insert_symbolo(tabla, simb);
            add_inst(pila,create_inst(LBL,simb, NULL, NULL));
            new_level(tabla);
        }
#line 1328 "parser.tab.c"
    break;

  case 9: /* Method_decl: Type ID '(' $@2 Params ')' '{' Linea '}'  */
#line 112 "parser.y"
                                   {
            close_level(tabla);
            Symbol *simb = find_symbol(tabla, (yyvsp[-7].str));
            if(!(yyvsp[-4].node)->left){
                simb->init=(yyvsp[-4].node)->info;
                simb->end=(yyvsp[-4].node)->info;
            }else{
                simb->init=(yyvsp[-4].node)->left->info;
                simb->end = search_last_Symbol((yyvsp[-4].node));
            }
            print_from_to(simb->end,simb->init);
            (yyval.node) = create_node(NODE_MET_DECLARATION, find_symbol(tabla, (yyvsp[-7].str)), (yyvsp[-4].node), (yyvsp[-1].node), NULL);
            returnType = VOID1;
        }
#line 1347 "parser.tab.c"
    break;

  case 10: /* $@3: %empty  */
#line 126 "parser.y"
                  {
            if (find_in_level(tabla, (yyvsp[-1].str))) {
                yyerror("Error de sintaxis: Metodo declarado mas de una vez\n");
                YYABORT;
            }
            Symbol *simb = create_symb(VOID1, 0, (yyvsp[-1].str));
            simb->isFuction = 1;
            insert_symbolo(tabla, simb);
            add_inst(pila,create_inst(LBL,simb, NULL, NULL));
            new_level(tabla);
        }
#line 1363 "parser.tab.c"
    break;

  case 11: /* Method_decl: VOID ID '(' $@3 Params ')' '{' Linea '}'  */
#line 136 "parser.y"
                                   {
            close_level(tabla);

            (yyval.node) = create_node(NODE_MET_DECLARATION, find_symbol(tabla, (yyvsp[-7].str)), (yyvsp[-4].node), (yyvsp[-1].node), NULL);
            
        }
#line 1374 "parser.tab.c"
    break;

  case 12: /* $@4: %empty  */
#line 142 "parser.y"
                      {
            if (find_in_level(tabla, (yyvsp[-2].str))) {
                yyerror("Error de sintaxis: Metodo declarado mas de una vez\n");
                YYABORT;
            }
            returnType = (yyvsp[-3].node)->info->exprType;
            Symbol *simb = create_symb((yyvsp[-3].node)->info->exprType, 0, (yyvsp[-2].str));
            simb->isFuction = 1;
            insert_symbolo(tabla, simb);
            add_inst(pila,create_inst(LBL,simb, NULL, NULL));
            new_level(tabla);
        }
#line 1391 "parser.tab.c"
    break;

  case 13: /* Method_decl: Type ID '(' ')' $@4 '{' Linea '}'  */
#line 153 "parser.y"
                        {
            close_level(tabla);
            returnType = VOID1;
            (yyval.node) = create_node(NODE_MET_DECLARATION, find_symbol(tabla, (yyvsp[-6].str)), NULL, (yyvsp[-1].node), NULL);
            
        }
#line 1402 "parser.tab.c"
    break;

  case 14: /* $@5: %empty  */
#line 159 "parser.y"
                      {
            if (find_in_level(tabla, (yyvsp[-2].str))) {
                yyerror("Error de sintaxis: Metodo declarado mas de una vez\n");
                YYABORT;
            }
            Symbol *simb = create_symb(VOID1, 0, (yyvsp[-2].str));
            simb->isFuction = 1;
            insert_symbolo(tabla, simb);
            add_inst(pila,create_inst(LBL,simb, NULL, NULL));
            new_level(tabla);
        }
#line 1418 "parser.tab.c"
    break;

  case 15: /* Method_decl: VOID ID '(' ')' $@5 '{' Linea '}'  */
#line 169 "parser.y"
                        {
            close_level(tabla);

            (yyval.node) = create_node(NODE_MET_DECLARATION, find_symbol(tabla, (yyvsp[-6].str)), NULL, (yyvsp[-1].node), NULL);
            add_inst(pila,create_inst(LBL,find_symbol(tabla, (yyvsp[-6].str)), NULL, NULL));
        }
#line 1429 "parser.tab.c"
    break;

  case 16: /* Type: INT  */
#line 176 "parser.y"
            { Symbol *simb = create_symb(INT1, 0, NULL);
            (yyval.node) = create_node(NODE_AUX, simb, NULL, NULL, NULL);
            }
#line 1437 "parser.tab.c"
    break;

  case 17: /* Type: BOOLEAN  */
#line 179 "parser.y"
                { Symbol *simb = create_symb(BOOL1, 0, NULL);
            (yyval.node) = create_node(NODE_AUX, simb, NULL, NULL, NULL);
            }
#line 1445 "parser.tab.c"
    break;

  case 18: /* Type: FLOAT  */
#line 182 "parser.y"
            { Symbol *simb = create_symb(FLOAT1, 0, NULL);
            (yyval.node) = create_node(NODE_AUX, simb, NULL, NULL, NULL);
            }
#line 1453 "parser.tab.c"
    break;

  case 19: /* Params: Param ',' Params  */
#line 188 "parser.y"
                        {
            (yyval.node) = create_node(NODE_PARAM_DECLARATION, NULL, (yyvsp[-2].node), (yyvsp[0].node), NULL);
            add_inst(pila,create_inst(MOV,(yyvsp[-2].node)->info, pilaTop, create_symb(INT1, param_extract++, NULL)));
            }
#line 1462 "parser.tab.c"
    break;

  case 20: /* Params: Param  */
#line 192 "parser.y"
            {(yyval.node) = (yyvsp[0].node);
        add_inst(pila,create_inst(MOV,(yyvsp[0].node)->info, pilaTop, create_symb(INT1, param_extract, NULL)));
        param_extract=0;
        }
#line 1471 "parser.tab.c"
    break;

  case 21: /* Param: Type ID  */
#line 198 "parser.y"
               {
            if (find_in_level(tabla, (yyvsp[0].str))) {
                yyerror("Error de sintaxis: Parametro declarado mas de una vez\n");
                YYABORT;
            }
            Symbol *simb = create_symb((yyvsp[-1].node)->info->exprType, 0, (yyvsp[0].str));
            insert_symbolo(tabla, simb);
            (yyval.node) = create_node(NODE_PARAM_DECLARATION, simb, NULL, NULL, NULL);
        }
#line 1485 "parser.tab.c"
    break;

  case 22: /* Linea: %empty  */
#line 210 "parser.y"
                    {(yyval.node) = NULL;}
#line 1491 "parser.tab.c"
    break;

  case 23: /* Linea: Sentencia Linea  */
#line 211 "parser.y"
                        {(yyval.node) = create_node(NODE_OP_NEWLINE, NULL, (yyvsp[-1].node), (yyvsp[0].node), NULL);}
#line 1497 "parser.tab.c"
    break;

  case 24: /* Sentencia: Var_decl ';'  */
#line 215 "parser.y"
                    {(yyval.node) = (yyvsp[-1].node);}
#line 1503 "parser.tab.c"
    break;

  case 25: /* Sentencia: Asign ';'  */
#line 216 "parser.y"
                {(yyval.node) = (yyvsp[-1].node);}
#line 1509 "parser.tab.c"
    break;

  case 26: /* $@6: %empty  */
#line 217 "parser.y"
                  {add_inst(pila,create_inst(JUMPF,(yyvsp[0].node)->dirRet,create_symb(VOID1, NULL, "endIF"),NULL));}
#line 1515 "parser.tab.c"
    break;

  case 27: /* Sentencia: IF '(' expr $@6 ')' Bloque  */
#line 217 "parser.y"
                                                                                                                   {
                    if((yyvsp[-3].node)->info->exprType != BOOL1){
                        yyerror("Error de sintaxis: expresion no booleana");
                    }
                    (yyval.node) = create_node(NODE_IF, NULL, (yyvsp[-3].node), (yyvsp[0].node), NULL);
                    add_inst(pila,create_inst(LBL, create_symb(VOID1, NULL, "endIF"), NULL, NULL));
                    }
#line 1527 "parser.tab.c"
    break;

  case 28: /* $@7: %empty  */
#line 224 "parser.y"
                  {add_inst(pila,create_inst(JUMPF,(yyvsp[0].node)->dirRet,create_symb(VOID1, NULL, "Else"),NULL));}
#line 1533 "parser.tab.c"
    break;

  case 29: /* $@8: %empty  */
#line 224 "parser.y"
                                                                                                                  {add_inst(pila,create_inst(JUMPF,(yyvsp[-3].node)->dirRet,create_symb(VOID1, NULL, "endIF"),NULL));}
#line 1539 "parser.tab.c"
    break;

  case 30: /* $@9: %empty  */
#line 224 "parser.y"
                                                                                                                                                                                                              { add_inst(pila,create_inst(LBL, create_symb(VOID1, NULL, "Else"), NULL, NULL));}
#line 1545 "parser.tab.c"
    break;

  case 31: /* Sentencia: IF '(' expr $@7 ')' Bloque $@8 ELSE $@9 Bloque  */
#line 225 "parser.y"
              {
                    if((yyvsp[-7].node)->info->exprType != BOOL1){
                        yyerror("Error de sintaxis: expresion no booleana");
                    }
                    (yyval.node) = create_node(NODE_IF_ELSE, NULL, (yyvsp[-7].node), (yyvsp[-4].node), (yyvsp[0].node));
                    add_inst(pila,create_inst(LBL, create_symb(VOID1, NULL, "endIF"), NULL, NULL));
                    }
#line 1557 "parser.tab.c"
    break;

  case 32: /* $@10: %empty  */
#line 232 "parser.y"
            {add_inst(pila,create_inst(LBL, create_symb(VOID1, NULL, "While"), NULL, NULL));}
#line 1563 "parser.tab.c"
    break;

  case 33: /* $@11: %empty  */
#line 232 "parser.y"
                                                                                                       {add_inst(pila,create_inst(JUMPF,(yyvsp[0].node)->dirRet,create_symb(VOID1, NULL, "endWhile"),NULL));}
#line 1569 "parser.tab.c"
    break;

  case 34: /* Sentencia: WHILE $@10 '(' expr $@11 ')' Bloque  */
#line 232 "parser.y"
                                                                                                                                                                                                           {
                    if((yyvsp[-3].node)->info->exprType != BOOL1){
                        yyerror("Error de sintaxis: expresion no booleana");
                    }
                    (yyval.node) = create_node(NODE_WHILE, NULL, (yyvsp[-3].node), (yyvsp[0].node), NULL);
                    add_inst(pila,create_inst(JUMP, create_symb(VOID1, NULL, "While"), NULL, NULL));
                    add_inst(pila,create_inst(LBL, create_symb(VOID1, NULL, "endWhile"), NULL, NULL));
                    }
#line 1582 "parser.tab.c"
    break;

  case 35: /* Sentencia: RETURN expr ';'  */
#line 240 "parser.y"
                      {Symbol *simb = create_symb((yyvsp[-1].node)->info->exprType, 0, NULL);
                    if(returnType!=simb->exprType){
                        if((returnType==INT1 ||returnType==FLOAT1) && (simb->exprType==INT1 || simb->exprType==FLOAT1)){
                            yyerror("Warning: Tipos no coinciden");
                        } else {
                            yyerror("Error de sintaxis: tipo de retorno incompatible");
                        }
                    }
                    add_inst(pila,create_inst(RET, simb, NULL, NULL));
                    (yyval.node) = create_node(NODE_OP_RETURN, simb, (yyvsp[-1].node), NULL, NULL);
                    }
#line 1598 "parser.tab.c"
    break;

  case 36: /* Sentencia: RETURN ';'  */
#line 251 "parser.y"
                 {Symbol *simb = create_symb(VOID1, 0, NULL);
                    if(returnType!=VOID1){
                        yyerror("Error de sintaxis: tipo de retorno incompatible");
                    }
                    add_inst(pila,create_inst(RET, NULL, NULL, NULL));
                    (yyval.node) = create_node(NODE_OP_RETURN, simb, NULL, NULL, NULL);
                }
#line 1610 "parser.tab.c"
    break;

  case 37: /* Sentencia: ';'  */
#line 258 "parser.y"
          {(yyval.node)=NULL;}
#line 1616 "parser.tab.c"
    break;

  case 38: /* Sentencia: Bloque  */
#line 259 "parser.y"
             {(yyval.node) = (yyvsp[0].node);}
#line 1622 "parser.tab.c"
    break;

  case 39: /* Sentencia: Method_call ';'  */
#line 260 "parser.y"
                      {(yyval.node)=(yyvsp[-1].node);}
#line 1628 "parser.tab.c"
    break;

  case 40: /* $@12: %empty  */
#line 263 "parser.y"
            {new_level(tabla);}
#line 1634 "parser.tab.c"
    break;

  case 41: /* Bloque: '{' $@12 Linea '}'  */
#line 263 "parser.y"
                                          {close_level(tabla);
        (yyval.node) = (yyvsp[-1].node);
        }
#line 1642 "parser.tab.c"
    break;

  case 42: /* Params_pass: expr ',' Params_pass  */
#line 267 "parser.y"
                                  {(yyval.node) = create_node(NODE_PARAM_PASS, NULL, (yyvsp[-2].node), (yyvsp[0].node), NULL);
        add_inst(pila,create_inst(PUSH,(yyvsp[-2].node)->dirRet, NULL, NULL));
        params_cant++;
    }
#line 1651 "parser.tab.c"
    break;

  case 43: /* Params_pass: expr  */
#line 271 "parser.y"
           {(yyval.node) = (yyvsp[0].node);
        add_inst(pila,create_inst(PUSH,(yyvsp[0].node)->dirRet, NULL, NULL));
        params_cant++;
        }
#line 1660 "parser.tab.c"
    break;

  case 44: /* Method_call: ID '(' ')'  */
#line 277 "parser.y"
                        {
                Symbol *simb = find_symbol(tabla, (yyvsp[-2].str));
                if (!simb || !simb->isFuction) {
                    yyerror("Error de sintaxis: Metodo no declarado");
                    YYABORT;
                }
                (yyval.node) = create_node(NODE_MET_CALL, simb, NULL, NULL, NULL);
                addDirRet((yyval.node), retFunc);
                add_inst(pila,create_inst(JUMP,simb, NULL, NULL));
            }
#line 1675 "parser.tab.c"
    break;

  case 45: /* Method_call: ID '(' Params_pass ')'  */
#line 287 "parser.y"
                             {
                Symbol *simb = find_symbol(tabla, (yyvsp[-3].str));
                if (!simb || !simb->isFuction) {
                    yyerror("Error de sintaxis: Metodo no declarado");
                    YYABORT;
                }
                Symbol *aux = verify_params(simb->end, (yyvsp[-1].node));
                if(!aux || aux !=simb->init->next){
                    yyerror("Error de sintaxis: Parametros Incorrectos");
                }
                (yyval.node) = create_node(NODE_MET_CALL, simb, (yyvsp[-1].node), NULL, NULL);
                addDirRet((yyval.node), retFunc);
                add_inst(pila,create_inst(JUMP,simb, NULL, NULL));
                while(params_cant>0){
                    add_inst(pila,create_inst(POP,NULL, NULL, NULL));
                    params_cant--;
                }
            }
#line 1698 "parser.tab.c"
    break;

  case 46: /* expr: ID  */
#line 308 "parser.y"
            {   Symbol *sim = find_symbol(tabla, (yyvsp[0].str));
                if(!sim){
                yyerror("Error de sintaxis: Variable no declarado");
                YYABORT;
                }
                (yyval.node) = create_node(NODE_ID, sim, NULL, NULL, NULL);
                addDirRet((yyval.node), sim);
            }
#line 1711 "parser.tab.c"
    break;

  case 47: /* expr: Method_call  */
#line 316 "parser.y"
                  {(yyval.node) = (yyvsp[0].node);}
#line 1717 "parser.tab.c"
    break;

  case 48: /* expr: LIT_FLOAT  */
#line 317 "parser.y"
                    {Symbol *simb = create_symb(FLOAT1, (yyvsp[0].num), NULL);
        (yyval.node) = create_node(NODE_VAL_NUM, simb, NULL, NULL, NULL);
        addDirRet((yyval.node), simb);
        }
#line 1726 "parser.tab.c"
    break;

  case 49: /* expr: LIT_INT  */
#line 321 "parser.y"
                {Symbol *simb = create_symb(INT1, (yyvsp[0].num), NULL);
        (yyval.node) = create_node(NODE_VAL_NUM, simb, NULL, NULL, NULL);
        addDirRet((yyval.node), simb);
        }
#line 1735 "parser.tab.c"
    break;

  case 50: /* expr: FALSE  */
#line 325 "parser.y"
            {Symbol *simb = create_symb(BOOL1, 0, NULL);
        (yyval.node) = create_node(NODE_VAL_FALSE, simb, NULL, NULL, NULL);
        addDirRet((yyval.node), simb);
        }
#line 1744 "parser.tab.c"
    break;

  case 51: /* expr: TRUE  */
#line 329 "parser.y"
           {Symbol *simb = create_symb(BOOL1, 1, NULL);
        (yyval.node) = create_node(NODE_VAL_TRUE, simb, NULL, NULL, NULL);
        addDirRet((yyval.node), simb);
        }
#line 1753 "parser.tab.c"
    break;

  case 52: /* expr: expr '+' expr  */
#line 333 "parser.y"
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
            addDirRet((yyval.node), registro_correspondiente());
            add_inst(pila,create_inst(ADD,(yyvsp[-2].node)->dirRet, (yyvsp[0].node)->dirRet, (yyval.node)->dirRet));
        }
#line 1775 "parser.tab.c"
    break;

  case 53: /* expr: expr '-' expr  */
#line 350 "parser.y"
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
            addDirRet((yyval.node), registro_correspondiente());
            add_inst(pila,create_inst(SUB,(yyvsp[-2].node)->dirRet, (yyvsp[0].node)->dirRet, (yyval.node)->dirRet));
        }
#line 1797 "parser.tab.c"
    break;

  case 54: /* expr: expr '*' expr  */
#line 367 "parser.y"
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
            addDirRet((yyval.node), registro_correspondiente());
            add_inst(pila,create_inst(MUL,(yyvsp[-2].node)->dirRet, (yyvsp[0].node)->dirRet, (yyval.node)->dirRet));
        }
#line 1819 "parser.tab.c"
    break;

  case 55: /* expr: expr '/' expr  */
#line 384 "parser.y"
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
            addDirRet((yyval.node), registro_correspondiente());
            add_inst(pila,create_inst(DIV,(yyvsp[-2].node)->dirRet, (yyvsp[0].node)->dirRet, (yyval.node)->dirRet));
        }
#line 1841 "parser.tab.c"
    break;

  case 56: /* expr: expr '%' expr  */
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
            (yyval.node) = create_node(NODE_OP_MOD, simb, (yyvsp[-2].node), (yyvsp[0].node), NULL);
            addDirRet((yyval.node), registro_correspondiente());
            add_inst(pila,create_inst(MOD,(yyvsp[-2].node)->dirRet, (yyvsp[0].node)->dirRet, (yyval.node)->dirRet));
        }
#line 1863 "parser.tab.c"
    break;

  case 57: /* expr: expr '<' expr  */
#line 418 "parser.y"
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
            Symbol *aux = registro_correspondiente();
            add_inst(pila,create_inst(CMP,(yyvsp[-2].node)->dirRet, (yyvsp[0].node)->dirRet, aux));
            addDirRet((yyval.node), registro_correspondiente());
            add_inst(pila,create_inst(LESS, aux, NULL, (yyval.node)->dirRet));
        }
#line 1885 "parser.tab.c"
    break;

  case 58: /* expr: expr '>' expr  */
#line 435 "parser.y"
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
            Symbol *aux = registro_correspondiente();
            add_inst(pila,create_inst(CMP,(yyvsp[-2].node)->dirRet, (yyvsp[0].node)->dirRet, aux));
            addDirRet((yyval.node), registro_correspondiente());
            add_inst(pila,create_inst(GREAT, aux, NULL, (yyval.node)->dirRet));
        }
#line 1907 "parser.tab.c"
    break;

  case 59: /* expr: expr EQUAL expr  */
#line 452 "parser.y"
                      {Symbol *simb = NULL;
            simb = create_symb(BOOL1, 0, NULL);
            (yyval.node) = create_node(NODE_OP_EQUAL, simb, (yyvsp[-2].node), (yyvsp[0].node), NULL);
            Symbol *aux = registro_correspondiente();
            add_inst(pila,create_inst(CMP,(yyvsp[-2].node)->dirRet, (yyvsp[0].node)->dirRet, aux));
            addDirRet((yyval.node), registro_correspondiente());
            add_inst(pila,create_inst(EQUAL, aux, NULL, (yyval.node)->dirRet));
            
        }
#line 1921 "parser.tab.c"
    break;

  case 60: /* expr: expr AND expr  */
#line 461 "parser.y"
                    {Symbol *simb = NULL;
            if((yyvsp[0].node)->info->exprType != (yyvsp[-2].node)->info->exprType || (yyvsp[-2].node)->info->exprType != BOOL1){
                yyerror("Error de tipo");
                YYABORT;
            }
            simb = create_symb((yyvsp[0].node)->info->exprType, 0, NULL);
            (yyval.node) = create_node(NODE_OP_AND, simb, (yyvsp[-2].node), (yyvsp[0].node), NULL);
            addDirRet((yyval.node), registro_correspondiente());
            add_inst(pila,create_inst(ANDD,(yyvsp[-2].node)->dirRet, (yyvsp[0].node)->dirRet, (yyval.node)->dirRet));
        }
#line 1936 "parser.tab.c"
    break;

  case 61: /* expr: expr OR expr  */
#line 471 "parser.y"
                    {Symbol *simb = NULL;
            if((yyvsp[0].node)->info->exprType != (yyvsp[-2].node)->info->exprType || (yyvsp[-2].node)->info->exprType != BOOL1){
                yyerror("Error de tipo");
                YYABORT;
            }
            simb = create_symb((yyvsp[0].node)->info->exprType, 0, NULL);
            (yyval.node) = create_node(NODE_OP_OR, simb, (yyvsp[-2].node), (yyvsp[0].node), NULL);
            addDirRet((yyval.node), registro_correspondiente());
            add_inst(pila,create_inst(ORR,(yyvsp[-2].node)->dirRet, (yyvsp[0].node)->dirRet, (yyval.node)->dirRet));
        }
#line 1951 "parser.tab.c"
    break;

  case 62: /* expr: '-' expr  */
#line 481 "parser.y"
                            {
            if((yyvsp[0].node)->info->exprType != INT1 && (yyvsp[0].node)->info->exprType != FLOAT1){
                yyerror("Error de tipo");
                YYABORT;
            }
            Symbol *simb = create_symb((yyvsp[0].node)->info->exprType, -(yyvsp[0].node)->info->value, NULL);
            (yyval.node) = create_node(NODE_AUX, simb, (yyvsp[0].node), NULL, NULL);
            addDirRet((yyval.node), registro_correspondiente());
            add_inst(pila,create_inst(MUL,(yyvsp[0].node)->dirRet, create_symb(INT1, NULL, -1), (yyval.node)->dirRet));
            }
#line 1966 "parser.tab.c"
    break;

  case 63: /* expr: '!' expr  */
#line 491 "parser.y"
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
            addDirRet((yyval.node), registro_correspondiente());
            add_inst(pila,create_inst(XOR,(yyvsp[0].node)->dirRet, create_symb(BOOL1, NULL, 1), (yyval.node)->dirRet));
            }
#line 1985 "parser.tab.c"
    break;

  case 64: /* expr: '(' expr ')'  */
#line 505 "parser.y"
                   {(yyval.node) = (yyvsp[-1].node);}
#line 1991 "parser.tab.c"
    break;

  case 65: /* Ids_decl: ID ',' Ids_decl  */
#line 508 "parser.y"
                             {
            if(!find_in_level(tabla, (yyvsp[-2].str))){
                Symbol *simb = create_symb(NOT_TYPE, 0, (yyvsp[-2].str));
                insert_symbolo(tabla, simb);
                (yyval.node) = create_node(NODE_AUX, simb, (yyvsp[0].node), NULL, NULL);
            }else {
                yyerror("Error de sintaxis: Variable declarada mas de una vez\n");
                YYABORT;
            }
            add_inst(pila,create_inst(DEC,find_in_level(tabla, (yyvsp[-2].str)), NULL, NULL));
            }
#line 2007 "parser.tab.c"
    break;

  case 66: /* Ids_decl: ID  */
#line 519 "parser.y"
            {
            if(!find_in_level(tabla, (yyvsp[0].str))){
                Symbol *simb = create_symb(NOT_TYPE, 0, (yyvsp[0].str));
                insert_symbolo(tabla, simb);
                (yyval.node) = create_node(NODE_AUX, simb, NULL, NULL, NULL);
            }else {
                yyerror("Error de sintaxis: Variable declarada mas de una vez\n");
                YYABORT;
            }
            add_inst(pila,create_inst(DEC,find_in_level(tabla, (yyvsp[0].str)), NULL, NULL));
            }
#line 2023 "parser.tab.c"
    break;

  case 67: /* Var_decl: Type Ids_decl  */
#line 532 "parser.y"
                        {
        (yyval.node) = create_node(NODE_DECLARATION, NULL, (yyvsp[-1].node), (yyvsp[0].node), NULL);
        (yyvsp[0].node)->info->exprType = (yyvsp[-1].node)->info->exprType;
        push_type((yyvsp[0].node));
        
        }
#line 2034 "parser.tab.c"
    break;

  case 68: /* Asign: ID '=' expr  */
#line 540 "parser.y"
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
            add_inst(pila,create_inst(MOV,simb, (yyvsp[0].node)->dirRet, NULL));
            
            }
        }
#line 2058 "parser.tab.c"
    break;


#line 2062 "parser.tab.c"

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

#line 561 "parser.y"


void yyerror(const char *s) {
    fprintf(stderr, "%s en la linea %d\n", s, lines);
}

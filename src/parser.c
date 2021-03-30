/* A Bison parser, made by GNU Bison 3.7.3.  */

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.7.3"

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
    #include <string.h>
    #include <stdlib.h>

    int yyerror(char* message);
    int yylex();
    int scope = 0;
    int funcdef_counter = 0;
    int anonymous_functions = 0;
    int loop_counter = 0;

    extern int yylineno;
    extern char* yytext;
    extern FILE* yyin;
    extern FILE* yyout;

    #define MAX 509
    #define HASH_MULTIPLIER 65599
    #define null NULL

    #define LIBFUNC_COLLISION 2
    #define COLLISION 3
    #define NOT_ACCESSIBLE 4

    char* libfuncs[] = { "print", "input", "objectmemberkeys", "objecttotalmembers",
    "objectcopy", "totalarguments", "argument", "typeof", "strtonum", "sqrt",
    "cos", "sin"};

    typedef struct Variable {
        char* name;
        unsigned int scope;
        unsigned int line;
    }Variable;

    typedef struct Function {
        char* name;
        char* args;
        unsigned int scope;
        unsigned int line;
    }Function;

    enum SymbolType {
        GLOBAL, LOCALVAR, VAR, FORMAL,
        USERFUNC, LIBFUNC
    };

    typedef struct SymbolTableEntry {
        short int isActive;
        Variable* varVal;
        Function* funcVal;
        enum SymbolType type;
        struct SymbolTableEntry* next;
        struct SymbolTableEntry* next_in_scope;
    }SymbolTableEntry;

    Function* last_function;
    SymbolTableEntry* symtable[MAX];
    SymbolTableEntry* scope_link[MAX];

    char* itoa(int val);
    unsigned int symtable_hash(const char *pcKey);
    int symtable_insert(Variable* var, Function* func, enum SymbolType type);
    int check_for_libfunc(const char* name);
    int hide_scope(const unsigned int scope);
    int symtable_contains(const Variable* var, const Function* func, enum SymbolType type);
    int scope_contains(const char* name, const unsigned int scope);
    int symtable_lookup(const char* name, enum SymbolType type);
    SymbolTableEntry* scope_lookup(const Variable* var, const Function* func, enum SymbolType type);
    char* get_type(enum SymbolType type);
    void print_scopes();


#line 146 "./src/parser.c"

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

#include "parser.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_ID = 3,                         /* ID  */
  YYSYMBOL_TRUE = 4,                       /* TRUE  */
  YYSYMBOL_FALSE = 5,                      /* FALSE  */
  YYSYMBOL_NIL = 6,                        /* NIL  */
  YYSYMBOL_IF = 7,                         /* IF  */
  YYSYMBOL_ELSE = 8,                       /* ELSE  */
  YYSYMBOL_WHILE = 9,                      /* WHILE  */
  YYSYMBOL_FOR = 10,                       /* FOR  */
  YYSYMBOL_FUNCTION = 11,                  /* FUNCTION  */
  YYSYMBOL_RETURN = 12,                    /* RETURN  */
  YYSYMBOL_BREAK = 13,                     /* BREAK  */
  YYSYMBOL_CONTINUE = 14,                  /* CONTINUE  */
  YYSYMBOL_LOCAL = 15,                     /* LOCAL  */
  YYSYMBOL_AND = 16,                       /* AND  */
  YYSYMBOL_OR = 17,                        /* OR  */
  YYSYMBOL_NOT = 18,                       /* NOT  */
  YYSYMBOL_NUMBER = 19,                    /* NUMBER  */
  YYSYMBOL_STRING = 20,                    /* STRING  */
  YYSYMBOL_REAL = 21,                      /* REAL  */
  YYSYMBOL_ASSIGN = 22,                    /* ASSIGN  */
  YYSYMBOL_COMMENT = 23,                   /* COMMENT  */
  YYSYMBOL_ADD = 24,                       /* ADD  */
  YYSYMBOL_INC = 25,                       /* INC  */
  YYSYMBOL_SUB = 26,                       /* SUB  */
  YYSYMBOL_DEC = 27,                       /* DEC  */
  YYSYMBOL_MUL = 28,                       /* MUL  */
  YYSYMBOL_DIV = 29,                       /* DIV  */
  YYSYMBOL_MOD = 30,                       /* MOD  */
  YYSYMBOL_EQUAL = 31,                     /* EQUAL  */
  YYSYMBOL_NEQ = 32,                       /* NEQ  */
  YYSYMBOL_GT = 33,                        /* GT  */
  YYSYMBOL_LT = 34,                        /* LT  */
  YYSYMBOL_GE = 35,                        /* GE  */
  YYSYMBOL_LE = 36,                        /* LE  */
  YYSYMBOL_LCURLY = 37,                    /* LCURLY  */
  YYSYMBOL_RCURLY = 38,                    /* RCURLY  */
  YYSYMBOL_LBRACKET = 39,                  /* LBRACKET  */
  YYSYMBOL_RBRACKET = 40,                  /* RBRACKET  */
  YYSYMBOL_LPAREN = 41,                    /* LPAREN  */
  YYSYMBOL_RPAREN = 42,                    /* RPAREN  */
  YYSYMBOL_SEMICOLON = 43,                 /* SEMICOLON  */
  YYSYMBOL_COMMA = 44,                     /* COMMA  */
  YYSYMBOL_COLON = 45,                     /* COLON  */
  YYSYMBOL_SCOPE = 46,                     /* SCOPE  */
  YYSYMBOL_POINT = 47,                     /* POINT  */
  YYSYMBOL_RANGE = 48,                     /* RANGE  */
  YYSYMBOL_MUL_COMMENT = 49,               /* MUL_COMMENT  */
  YYSYMBOL_UMINUS = 50,                    /* UMINUS  */
  YYSYMBOL_YYACCEPT = 51,                  /* $accept  */
  YYSYMBOL_program = 52,                   /* program  */
  YYSYMBOL_stmt = 53,                      /* stmt  */
  YYSYMBOL_stmt_list = 54,                 /* stmt_list  */
  YYSYMBOL_expr = 55,                      /* expr  */
  YYSYMBOL_term = 56,                      /* term  */
  YYSYMBOL_assignexpr = 57,                /* assignexpr  */
  YYSYMBOL_primary = 58,                   /* primary  */
  YYSYMBOL_lvalue = 59,                    /* lvalue  */
  YYSYMBOL_member = 60,                    /* member  */
  YYSYMBOL_call = 61,                      /* call  */
  YYSYMBOL_callsuffix = 62,                /* callsuffix  */
  YYSYMBOL_normcall = 63,                  /* normcall  */
  YYSYMBOL_methodcall = 64,                /* methodcall  */
  YYSYMBOL_elist = 65,                     /* elist  */
  YYSYMBOL_commaexpr = 66,                 /* commaexpr  */
  YYSYMBOL_objectdef = 67,                 /* objectdef  */
  YYSYMBOL_indexed = 68,                   /* indexed  */
  YYSYMBOL_indexelemlist = 69,             /* indexelemlist  */
  YYSYMBOL_indexelem = 70,                 /* indexelem  */
  YYSYMBOL_funcdef = 71,                   /* funcdef  */
  YYSYMBOL_72_1 = 72,                      /* $@1  */
  YYSYMBOL_73_2 = 73,                      /* $@2  */
  YYSYMBOL_block = 74,                     /* block  */
  YYSYMBOL_75_3 = 75,                      /* $@3  */
  YYSYMBOL_const = 76,                     /* const  */
  YYSYMBOL_idlist = 77,                    /* idlist  */
  YYSYMBOL_78_4 = 78,                      /* $@4  */
  YYSYMBOL_commaidlist = 79,               /* commaidlist  */
  YYSYMBOL_80_5 = 80,                      /* $@5  */
  YYSYMBOL_ifstmt = 81,                    /* ifstmt  */
  YYSYMBOL_whilestmt = 82,                 /* whilestmt  */
  YYSYMBOL_83_6 = 83,                      /* $@6  */
  YYSYMBOL_forstmt = 84,                   /* forstmt  */
  YYSYMBOL_85_7 = 85,                      /* $@7  */
  YYSYMBOL_returnstmt = 86,                /* returnstmt  */
  YYSYMBOL_comment = 87                    /* comment  */
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
#define YYFINAL  73
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   759

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  51
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  37
/* YYNRULES -- Number of rules.  */
#define YYNRULES  99
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  187

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   305


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
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   156,   156,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   172,   173,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,   196,   197,   198,   199,   200,   201,   202,   203,
     207,   210,   211,   212,   213,   214,   218,   227,   243,   246,
     250,   251,   252,   253,   257,   258,   259,   263,   264,   268,
     271,   274,   275,   279,   280,   284,   285,   289,   293,   294,
     298,   301,   301,   317,   317,   333,   333,   334,   338,   338,
     338,   338,   338,   338,   341,   341,   357,   361,   361,   378,
     382,   383,   387,   387,   390,   390,   393,   394,   397,   398
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
  "\"end of file\"", "error", "\"invalid token\"", "ID", "TRUE", "FALSE",
  "NIL", "IF", "ELSE", "WHILE", "FOR", "FUNCTION", "RETURN", "BREAK",
  "CONTINUE", "LOCAL", "AND", "OR", "NOT", "NUMBER", "STRING", "REAL",
  "ASSIGN", "COMMENT", "ADD", "INC", "SUB", "DEC", "MUL", "DIV", "MOD",
  "EQUAL", "NEQ", "GT", "LT", "GE", "LE", "LCURLY", "RCURLY", "LBRACKET",
  "RBRACKET", "LPAREN", "RPAREN", "SEMICOLON", "COMMA", "COLON", "SCOPE",
  "POINT", "RANGE", "MUL_COMMENT", "UMINUS", "$accept", "program", "stmt",
  "stmt_list", "expr", "term", "assignexpr", "primary", "lvalue", "member",
  "call", "callsuffix", "normcall", "methodcall", "elist", "commaexpr",
  "objectdef", "indexed", "indexelemlist", "indexelem", "funcdef", "$@1",
  "$@2", "block", "$@3", "const", "idlist", "$@4", "commaidlist", "$@5",
  "ifstmt", "whilestmt", "$@6", "forstmt", "$@7", "returnstmt", "comment", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305
};
#endif

#define YYPACT_NINF (-161)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-63)

#define yytable_value_is_error(Yyn) \
  ((Yyn) == YYTABLE_NINF)

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     199,  -161,  -161,  -161,  -161,  -161,   -38,   -34,   -26,    44,
      15,     7,    16,    50,   427,  -161,  -161,  -161,  -161,     2,
     427,     2,    24,    90,   340,  -161,    60,  -161,    64,   152,
    -161,   489,  -161,  -161,  -161,    98,  -161,    10,  -161,  -161,
    -161,  -161,  -161,  -161,  -161,  -161,  -161,   427,   427,   369,
    -161,    39,  -161,   510,  -161,  -161,  -161,   680,    70,   -16,
      10,   723,   -16,  -161,   246,   427,   468,    45,    46,    40,
     552,    55,  -161,  -161,  -161,   427,   427,   427,   427,   427,
     427,   427,   427,   427,   427,   427,   427,   427,  -161,   427,
    -161,  -161,   427,   398,    84,    89,  -161,  -161,  -161,   427,
     398,    95,   573,   594,    56,    59,    99,  -161,    65,    74,
     446,   427,  -161,  -161,  -161,    76,  -161,  -161,    73,   714,
     701,   723,   723,   149,   149,   149,   196,   196,    -7,    -7,
      -7,    -7,   680,   615,    77,  -161,    80,   636,    82,  -161,
     293,  -161,   427,    99,  -161,    86,    73,  -161,   427,   468,
      40,   398,  -161,  -161,   398,  -161,  -161,   110,   293,   531,
      91,    96,    97,   657,  -161,  -161,    93,   100,   293,  -161,
     398,    97,   123,  -161,  -161,  -161,  -161,  -161,  -161,   101,
    -161,  -161,  -161,    96,   293,  -161,  -161
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,    31,    46,    81,    82,    80,     0,     0,     0,    73,
       0,     0,     0,     0,     0,    78,    79,    83,    98,     0,
       0,     0,    75,     0,     0,    12,     0,    99,     0,     0,
       2,     0,    30,    16,    33,    41,    49,    42,    43,    11,
      10,    45,     4,     5,     6,     7,    13,     0,     0,     0,
      71,     0,    97,     0,     8,     9,    47,    35,     0,    36,
       0,    34,    38,    77,     0,     0,    64,     0,     0,    69,
       0,     0,    48,     1,    14,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     3,     0,
      37,    39,     0,     0,     0,     0,    55,    57,    58,     0,
       0,     0,     0,     0,     0,     0,    86,    96,     0,     0,
       0,     0,    61,    65,    66,     0,    67,    32,    44,    28,
      29,    17,    18,    19,    20,    21,    26,    27,    22,    24,
      23,    25,    40,     0,     0,    50,     0,     0,     0,    52,
       0,    92,     0,    86,    84,     0,     0,    76,     0,    64,
      69,     0,    51,    59,     0,    53,    54,    90,     0,     0,
       0,    89,     0,     0,    63,    68,     0,     0,     0,    93,
       0,     0,     0,    85,    74,    70,    56,    60,    91,     0,
      72,    87,    94,    89,     0,    88,    95
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -161,  -161,   -80,   -20,   -10,  -161,  -161,  -161,   -13,  -161,
       3,  -161,  -161,  -161,   -48,    -2,  -161,  -161,    -1,    33,
     -12,  -161,  -161,  -160,  -161,  -161,     8,  -161,   -33,  -161,
    -161,  -161,  -161,  -161,  -161,  -161,  -161
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    96,    97,    98,    67,   112,    38,    68,   116,    69,
      39,   105,    51,    40,    64,    41,   145,   161,   173,   183,
      42,    43,   158,    44,   184,    45,    46
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      53,   104,   174,    47,    57,     2,    59,    48,    62,    74,
      61,   180,    71,    66,    70,    49,     1,    13,     2,     3,
       4,     5,    60,    92,    60,    93,   -63,   -63,   -63,   -63,
      13,    94,    95,    14,    15,    16,    17,   102,   103,    66,
      19,    20,    21,    58,   109,   134,   108,    50,    26,    99,
      54,   100,   138,    56,    23,   110,    24,   101,    52,    55,
     157,    26,    63,    72,    73,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   169,   132,
     106,     9,   133,    66,   115,   113,   114,   135,   178,   137,
      66,     1,   136,     2,     3,     4,     5,   118,   139,   142,
     143,   149,   144,   166,   186,    13,   167,   146,    14,    15,
      16,    17,   147,    65,   151,    19,    20,    21,   168,   153,
      89,   154,   179,    90,   156,    91,   181,    65,   162,    23,
     -62,    24,   159,   171,    22,   176,    26,    92,   163,    93,
     172,    66,   177,   182,    66,    94,    95,   164,   150,   165,
     185,   160,   -15,     1,     0,     2,     3,     4,     5,     6,
      66,     7,     8,     9,    10,    11,    12,    13,     0,     0,
      14,    15,    16,    17,     0,    18,     0,    19,    20,    21,
      82,    83,    84,    85,    86,    87,     0,     0,     0,    22,
     -15,    23,     0,    24,     0,    25,     0,     0,    26,   -15,
       1,    27,     2,     3,     4,     5,     6,     0,     7,     8,
       9,    10,    11,    12,    13,     0,     0,    14,    15,    16,
      17,     0,    18,     0,    19,    20,    21,   -63,   -63,    84,
      85,    86,    87,     0,     0,     0,    22,     0,    23,     0,
      24,     0,    25,     0,     0,    26,     0,     1,    27,     2,
       3,     4,     5,     6,     0,     7,     8,     9,    10,    11,
      12,    13,     0,     0,    14,    15,    16,    17,     0,    18,
       0,    19,    20,    21,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    22,   -15,    23,     0,    24,     0,    25,
       0,     0,    26,     0,     1,    27,     2,     3,     4,     5,
       6,     0,     7,     8,     9,    10,    11,    12,    13,     0,
       0,    14,    15,    16,    17,     0,    18,     0,    19,    20,
      21,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      22,     0,    23,     0,    24,     0,    25,     0,     0,    26,
       0,     1,    27,     2,     3,     4,     5,     0,     0,     0,
       0,     9,     0,     0,     0,    13,     0,     0,    14,    15,
      16,    17,     0,     0,     0,    19,    20,    21,     0,     0,
       1,     0,     2,     3,     4,     5,     0,     0,     0,    23,
       0,    24,     0,     0,    13,     0,    26,    14,    15,    16,
      17,     0,     0,     0,    19,    20,    21,     0,     0,     1,
       0,     2,     3,     4,     5,     0,     0,     0,    23,     0,
      24,     0,   -62,    13,     0,    26,    14,    15,    16,    17,
       0,     0,     0,    19,    20,    21,     0,     0,     1,     0,
       2,     3,     4,     5,     0,     0,     0,    23,     0,    24,
     -62,     0,    13,     0,    26,    14,    15,    16,    17,     0,
       0,     0,    19,    20,    21,     0,     0,     0,     0,     0,
       0,     0,    75,    76,     0,     0,    23,     0,    24,     0,
      77,     0,    78,    26,    79,    80,    81,    82,    83,    84,
      85,    86,    87,     0,    75,    76,     0,     0,     0,     0,
       0,   148,    77,     0,    78,     0,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    75,    76,     0,     0,     0,
       0,     0,   111,    77,     0,    78,     0,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    75,    76,     0,     0,
       0,     0,    88,     0,    77,     0,    78,     0,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    75,    76,     0,
       0,     0,     0,   107,     0,    77,     0,    78,     0,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    75,    76,
       0,     0,     0,     0,   170,     0,    77,     0,    78,     0,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    75,
      76,     0,     0,     0,   117,     0,     0,    77,     0,    78,
       0,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      75,    76,     0,     0,     0,   140,     0,     0,    77,     0,
      78,     0,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    75,    76,     0,     0,     0,   141,     0,     0,    77,
       0,    78,     0,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    75,    76,     0,   152,     0,     0,     0,     0,
      77,     0,    78,     0,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    75,    76,     0,   155,     0,     0,     0,
       0,    77,     0,    78,     0,    79,    80,    81,    82,    83,
      84,    85,    86,    87,     0,   175,    75,    76,     0,     0,
       0,     0,     0,     0,    77,     0,    78,     0,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    75,     0,     0,
       0,     0,     0,     0,     0,    77,     0,    78,     0,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    77,     0,
      78,     0,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    79,    80,    81,    82,    83,    84,    85,    86,    87
};

static const yytype_int16 yycheck[] =
{
      10,    49,   162,    41,    14,     3,    19,    41,    21,    29,
      20,   171,    24,    23,    24,    41,     1,    15,     3,     4,
       5,     6,    19,    39,    21,    41,    33,    34,    35,    36,
      15,    47,    48,    18,    19,    20,    21,    47,    48,    49,
      25,    26,    27,    41,    64,    93,    58,     3,    46,    39,
      43,    41,   100,     3,    39,    65,    41,    47,    43,    43,
     140,    46,    38,     3,     0,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,   158,    89,
      41,    11,    92,    93,    44,    40,    40,     3,   168,    99,
     100,     1,     3,     3,     4,     5,     6,    42,     3,    43,
      41,   111,     3,   151,   184,    15,   154,    42,    18,    19,
      20,    21,    38,    37,    41,    25,    26,    27,     8,    42,
      22,    41,   170,    25,    42,    27,     3,    37,    42,    39,
      40,    41,   142,    42,    37,    42,    46,    39,   148,    41,
      44,   151,    42,    42,   154,    47,    48,   149,   115,   150,
     183,   143,     0,     1,    -1,     3,     4,     5,     6,     7,
     170,     9,    10,    11,    12,    13,    14,    15,    -1,    -1,
      18,    19,    20,    21,    -1,    23,    -1,    25,    26,    27,
      31,    32,    33,    34,    35,    36,    -1,    -1,    -1,    37,
      38,    39,    -1,    41,    -1,    43,    -1,    -1,    46,     0,
       1,    49,     3,     4,     5,     6,     7,    -1,     9,    10,
      11,    12,    13,    14,    15,    -1,    -1,    18,    19,    20,
      21,    -1,    23,    -1,    25,    26,    27,    31,    32,    33,
      34,    35,    36,    -1,    -1,    -1,    37,    -1,    39,    -1,
      41,    -1,    43,    -1,    -1,    46,    -1,     1,    49,     3,
       4,     5,     6,     7,    -1,     9,    10,    11,    12,    13,
      14,    15,    -1,    -1,    18,    19,    20,    21,    -1,    23,
      -1,    25,    26,    27,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    37,    38,    39,    -1,    41,    -1,    43,
      -1,    -1,    46,    -1,     1,    49,     3,     4,     5,     6,
       7,    -1,     9,    10,    11,    12,    13,    14,    15,    -1,
      -1,    18,    19,    20,    21,    -1,    23,    -1,    25,    26,
      27,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      37,    -1,    39,    -1,    41,    -1,    43,    -1,    -1,    46,
      -1,     1,    49,     3,     4,     5,     6,    -1,    -1,    -1,
      -1,    11,    -1,    -1,    -1,    15,    -1,    -1,    18,    19,
      20,    21,    -1,    -1,    -1,    25,    26,    27,    -1,    -1,
       1,    -1,     3,     4,     5,     6,    -1,    -1,    -1,    39,
      -1,    41,    -1,    -1,    15,    -1,    46,    18,    19,    20,
      21,    -1,    -1,    -1,    25,    26,    27,    -1,    -1,     1,
      -1,     3,     4,     5,     6,    -1,    -1,    -1,    39,    -1,
      41,    -1,    43,    15,    -1,    46,    18,    19,    20,    21,
      -1,    -1,    -1,    25,    26,    27,    -1,    -1,     1,    -1,
       3,     4,     5,     6,    -1,    -1,    -1,    39,    -1,    41,
      42,    -1,    15,    -1,    46,    18,    19,    20,    21,    -1,
      -1,    -1,    25,    26,    27,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    16,    17,    -1,    -1,    39,    -1,    41,    -1,
      24,    -1,    26,    46,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    -1,    16,    17,    -1,    -1,    -1,    -1,
      -1,    45,    24,    -1,    26,    -1,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    16,    17,    -1,    -1,    -1,
      -1,    -1,    44,    24,    -1,    26,    -1,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    16,    17,    -1,    -1,
      -1,    -1,    43,    -1,    24,    -1,    26,    -1,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    16,    17,    -1,
      -1,    -1,    -1,    43,    -1,    24,    -1,    26,    -1,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    16,    17,
      -1,    -1,    -1,    -1,    43,    -1,    24,    -1,    26,    -1,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    16,
      17,    -1,    -1,    -1,    42,    -1,    -1,    24,    -1,    26,
      -1,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      16,    17,    -1,    -1,    -1,    42,    -1,    -1,    24,    -1,
      26,    -1,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    16,    17,    -1,    -1,    -1,    42,    -1,    -1,    24,
      -1,    26,    -1,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    16,    17,    -1,    40,    -1,    -1,    -1,    -1,
      24,    -1,    26,    -1,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    16,    17,    -1,    40,    -1,    -1,    -1,
      -1,    24,    -1,    26,    -1,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    -1,    38,    16,    17,    -1,    -1,
      -1,    -1,    -1,    -1,    24,    -1,    26,    -1,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    16,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    24,    -1,    26,    -1,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    24,    -1,
      26,    -1,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    28,    29,    30,    31,    32,    33,    34,    35,    36
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     1,     3,     4,     5,     6,     7,     9,    10,    11,
      12,    13,    14,    15,    18,    19,    20,    21,    23,    25,
      26,    27,    37,    39,    41,    43,    46,    49,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    67,    71,
      74,    76,    81,    82,    84,    86,    87,    41,    41,    41,
       3,    73,    43,    55,    43,    43,     3,    55,    41,    59,
      61,    55,    59,    38,    75,    37,    55,    65,    68,    70,
      55,    71,     3,     0,    54,    16,    17,    24,    26,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    43,    22,
      25,    27,    39,    41,    47,    48,    62,    63,    64,    39,
      41,    47,    55,    55,    65,    72,    41,    43,    71,    54,
      55,    44,    66,    40,    40,    44,    69,    42,    42,    55,
      55,    55,    55,    55,    55,    55,    55,    55,    55,    55,
      55,    55,    55,    55,    65,     3,     3,    55,    65,     3,
      42,    42,    43,    41,     3,    77,    42,    38,    45,    55,
      70,    41,    40,    42,    41,    40,    42,    53,    83,    55,
      77,    78,    42,    55,    66,    69,    65,    65,     8,    53,
      43,    42,    44,    79,    74,    38,    42,    42,    53,    65,
      74,     3,    42,    80,    85,    79,    53
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    51,    52,    53,    53,    53,    53,    53,    53,    53,
      53,    53,    53,    53,    54,    54,    55,    55,    55,    55,
      55,    55,    55,    55,    55,    55,    55,    55,    55,    55,
      55,    55,    56,    56,    56,    56,    56,    56,    56,    56,
      57,    58,    58,    58,    58,    58,    59,    59,    59,    59,
      60,    60,    60,    60,    61,    61,    61,    62,    62,    63,
      64,    65,    65,    66,    66,    67,    67,    68,    69,    69,
      70,    72,    71,    73,    71,    75,    74,    74,    76,    76,
      76,    76,    76,    76,    78,    77,    77,    80,    79,    79,
      81,    81,    83,    82,    85,    84,    86,    86,    87,    87
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     1,     2,     2,
       1,     1,     1,     1,     2,     0,     1,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       1,     1,     3,     1,     2,     2,     2,     2,     2,     2,
       3,     1,     1,     1,     3,     1,     1,     2,     2,     1,
       3,     4,     3,     4,     4,     2,     6,     1,     1,     3,
       5,     2,     0,     3,     0,     3,     3,     2,     3,     0,
       5,     0,     7,     0,     6,     0,     4,     2,     1,     1,
       1,     1,     1,     1,     0,     3,     0,     0,     4,     0,
       5,     7,     0,     6,     0,    10,     3,     2,     1,     1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

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

/* This macro is provided for backward compatibility. */
# ifndef YY_LOCATION_PRINT
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif


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
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yykind < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yykind], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yykind);
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
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yykind);
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
  case 8: /* stmt: BREAK SEMICOLON  */
#line 163 "parser.y"
                              {if (loop_counter == 0) yyerror("Error: Usage of break outside of loop");}
#line 1458 "./src/parser.c"
    break;

  case 9: /* stmt: CONTINUE SEMICOLON  */
#line 164 "parser.y"
                                 {if (loop_counter == 0) yyerror("Error: Usage of continue outside of loop");}
#line 1464 "./src/parser.c"
    break;

  case 31: /* expr: error  */
#line 192 "parser.y"
                    {yyclearin;}
#line 1470 "./src/parser.c"
    break;

  case 46: /* lvalue: ID  */
#line 218 "parser.y"
                {
                    Variable* var = malloc(sizeof(struct Variable));
                    var->name = (yyvsp[0].strVal);
                    var->line = yylineno;
                    var->scope = scope;
                    if (symtable_insert(var, null, 2) == NOT_ACCESSIBLE) {
                        yyerror("Error: Symbol not accessible");
                    }
                }
#line 1484 "./src/parser.c"
    break;

  case 47: /* lvalue: LOCAL ID  */
#line 227 "parser.y"
                                {
                                    Variable* var = malloc(sizeof(struct Variable));
                                    var->name = (yyvsp[0].strVal);
                                    var->line = yylineno;
                                    var->scope = scope;
                                    if(scope > 0) {
                                        if (symtable_insert(var, null, 1) == LIBFUNC_COLLISION) {
                                            yyerror("Error: Trying to shadow library function");
                                        }
                                    }
                                    else {
                                        if (symtable_insert(var, null, 0) == LIBFUNC_COLLISION) {
                                            yyerror("Error: Trying to shadow library function");
                                        }
                                    }
                                }
#line 1505 "./src/parser.c"
    break;

  case 48: /* lvalue: SCOPE ID  */
#line 243 "parser.y"
                       {
                            if (!scope_contains((yyvsp[0].strVal), 0)) yyerror("Error: Global symbol not found");
                       }
#line 1513 "./src/parser.c"
    break;

  case 71: /* $@1: %empty  */
#line 301 "parser.y"
                        {
       Function* func = malloc(sizeof(struct Function));
       func->name = (yyvsp[0].strVal);
       func->scope = scope;
       func->line = yylineno;
       func->args = null;
       funcdef_counter++;
       last_function = func;
       int code = symtable_insert(null, func, 4);
       if (code == LIBFUNC_COLLISION) {
           yyerror("Error: Trying to shadow libfunc");
       }
       else if (code == COLLISION) {
           yyerror("Error: Symbol redefinition");
       }
       }
#line 1534 "./src/parser.c"
    break;

  case 72: /* funcdef: FUNCTION ID $@1 LPAREN idlist RPAREN block  */
#line 316 "parser.y"
                                    {funcdef_counter--;}
#line 1540 "./src/parser.c"
    break;

  case 73: /* $@2: %empty  */
#line 317 "parser.y"
                       {
                   anonymous_functions++;
                   Function* func = malloc(sizeof(struct Function));
                   func->name = malloc(1 + strlen(itoa(anonymous_functions)));
                   strcat(func->name, "$");
                   strcat(func->name, itoa(anonymous_functions));
                   func->scope = scope;
                   func->line = yylineno;
                   func->args = null;
                   funcdef_counter++;
                   last_function = func;
                   symtable_insert(null, func, 4);
            }
#line 1558 "./src/parser.c"
    break;

  case 74: /* funcdef: FUNCTION $@2 LPAREN idlist RPAREN block  */
#line 329 "parser.y"
                                         {funcdef_counter--;}
#line 1564 "./src/parser.c"
    break;

  case 75: /* $@3: %empty  */
#line 333 "parser.y"
                   {scope++;}
#line 1570 "./src/parser.c"
    break;

  case 76: /* block: LCURLY $@3 stmt_list RCURLY  */
#line 333 "parser.y"
                                               {hide_scope(scope--);}
#line 1576 "./src/parser.c"
    break;

  case 84: /* $@4: %empty  */
#line 341 "parser.y"
               {
                    Variable* var = malloc(sizeof(struct Variable));
                    var->name = (yyvsp[0].strVal);
                    var->scope = scope + 1;
                    var->line = yylineno;
                    last_function->args = malloc(strlen((yyvsp[0].strVal)) + 1);
                    strcat(last_function->args, (yyvsp[0].strVal));
                    strcat(last_function->args, " ");
                    int code = symtable_insert(var, null, 3);
                    if (code == COLLISION) {
                        yyerror("Error: Symbol redefinition");
                    }
                    else if (code == LIBFUNC_COLLISION) {
                        yyerror("Error: Trying to shadow library function");
                    }
               }
#line 1597 "./src/parser.c"
    break;

  case 87: /* $@5: %empty  */
#line 361 "parser.y"
                      {
                        Variable* var = malloc(sizeof(struct Variable));
                        var->name = (yyvsp[0].strVal);
                        var->scope = scope + 1;
                        var->line = yylineno;
                        int prev_args = strlen(last_function->args);
                        last_function->args = realloc(last_function->args, prev_args + strlen((yyvsp[0].strVal)) + 1);
                        strcat(last_function->args, (yyvsp[0].strVal));
                        strcat(last_function->args, " ");
                        int code = symtable_insert(var, null, 3);
                        if (code == COLLISION) {
                            yyerror("Error: Symbol redefinition");
                        }
                        else if (code == LIBFUNC_COLLISION) {
                            yyerror("Error: Trying to shadow library function");
                        }
                      }
#line 1619 "./src/parser.c"
    break;

  case 92: /* $@6: %empty  */
#line 387 "parser.y"
                                     {loop_counter++;}
#line 1625 "./src/parser.c"
    break;

  case 93: /* whilestmt: WHILE LPAREN expr RPAREN $@6 stmt  */
#line 387 "parser.y"
                                                            {loop_counter--;}
#line 1631 "./src/parser.c"
    break;

  case 94: /* $@7: %empty  */
#line 390 "parser.y"
                                                                   {loop_counter++;}
#line 1637 "./src/parser.c"
    break;

  case 95: /* forstmt: FOR LPAREN elist SEMICOLON expr SEMICOLON elist RPAREN $@7 stmt  */
#line 390 "parser.y"
                                                                                          {loop_counter--;}
#line 1643 "./src/parser.c"
    break;

  case 96: /* returnstmt: RETURN expr SEMICOLON  */
#line 393 "parser.y"
                                  {if (funcdef_counter == 0) yyerror("Error: Usage of return outside of function");}
#line 1649 "./src/parser.c"
    break;

  case 97: /* returnstmt: RETURN SEMICOLON  */
#line 394 "parser.y"
                             {if (funcdef_counter == 0) yyerror("Error: Usage of return outside of function");}
#line 1655 "./src/parser.c"
    break;


#line 1659 "./src/parser.c"

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
  goto yyreturn;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;


#if !defined yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturn;
#endif


/*-------------------------------------------------------.
| yyreturn -- parsing is finished, clean up and return.  |
`-------------------------------------------------------*/
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
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 402 "parser.y"


int yyerror(char* message) {
    fprintf(yyout, "%s at token %s line %d\n", message, yytext, yylineno);
    return 1;
}

// Int to String implementation because C
// IT MAY BE USELESS WE'LL SEE
char* itoa(int val){

	static char buf[32] = {0};
	int i = 30;

	for(; val && i; --i, val /= 10)
		buf[i] = "0123456789abcdef"[val % 10];

	return &buf[i+1];
}

// Hash Function
unsigned int symtable_hash(const char *pcKey) {

  	size_t ui;
  	unsigned int uiHash = 0U;

  	for (ui = 0U; pcKey[ui] != '\0'; ui++)
    	uiHash = uiHash * HASH_MULTIPLIER + pcKey[ui];

  	return uiHash%MAX;
}


// Insert an entry to the Symbol Table AND the Scope Link
// !!! Anything can be added except if every field (name, scope, type) is the same, then return error !!!
// ^^^^ That must be fixed once we understand the rules for definitions and redeclarations
int symtable_insert(Variable* var, Function* func, enum SymbolType type) {

    const char* name = var ? var->name : func->name;
    unsigned int hash = symtable_hash(name);


	SymbolTableEntry* table_entry = symtable[hash];
	SymbolTableEntry* scope_entry = scope_link[var ? var->scope : func->scope];
	SymbolTableEntry* table_prev = null;
	SymbolTableEntry* scope_prev = null;
	SymbolTableEntry* new;

	while(table_entry) {

        unsigned int scope = var ? var->scope : func->scope;
        if(type == 0){
            if(scope_contains(name, 0))
                return 0;
        }
        else if(type == 1){
            if (scope_contains(name, scope))
                return 1;
            if (check_for_libfunc(name) && scope != 0)
                return LIBFUNC_COLLISION;
        }
        else if (type == 2) {
            if (symtable_lookup(name, 3)) return 1;
            for (int i = scope; i > 0; i--) {
                if (scope_contains(name, i)) {
                    if (symtable_lookup(name, 4)) return 1;
                    if (symtable_lookup(name, 5)) return 1;
                    if (funcdef_counter == 0) return 1;
                    else return NOT_ACCESSIBLE;
                }
            }
            if (scope_contains(name, 0)) return 1;
        }
        else if (type == 3) {
            if (scope_contains(name, scope - 1)) return COLLISION;
            if (symtable_lookup(name, 5)) return LIBFUNC_COLLISION;
        }
        else if (type == 4) {
            if (scope_contains(name, scope))
                return COLLISION;
            if (check_for_libfunc(name))
                return LIBFUNC_COLLISION;
        }


		table_prev = table_entry;
		table_entry = table_entry->next;
	}

	while(scope_entry) {
		scope_prev = scope_entry;
		scope_entry = scope_entry->next_in_scope;
	}

	new = malloc(sizeof(struct SymbolTableEntry));
    new->isActive = 1;
    new->varVal = var;
    new->funcVal = func;
    new->type = type;
	new->next = null;
    new->next_in_scope = null;

	if   (table_prev) table_prev->next = new;
	else symtable[hash] = new;

	if   (scope_prev) scope_prev->next_in_scope = new;
	else scope_link[var ? var->scope : func->scope] = new;

	return 1;
}


int check_for_libfunc(const char* name){
    for(int i = 0; i < 12; i++)
        if(strcmp(name, libfuncs[i]) == 0)
            return 1;
    return 0;
}


// Hide all entries in a scope
int hide_scope(const unsigned int scope) {

	SymbolTableEntry* scope_entry = scope_link[scope];

	while(scope_entry) {
        scope_entry->isActive = 0;
        scope_entry = scope_entry->next_in_scope;
	}

	return 1;
}


// Return true if a bucket contains an entry
int symtable_contains(const Variable* var, const Function* func, enum SymbolType type){

	unsigned int hash = symtable_hash(var ? var->name : func->name);
	SymbolTableEntry* table_entry = symtable[hash];

	while(table_entry) {
        if(var && table_entry->varVal){
            if(strcmp(var->name, table_entry->varVal->name) == 0 && type == table_entry->type)
			    return 1;
        }
        else if(func && table_entry->funcVal){
            if(strcmp(func->name, table_entry->funcVal->name) == 0 && type == table_entry->type)
			    return 1;
        }

		table_entry = table_entry->next;
	}

	return 0;
}


// Return true if a scope contains an entry
int scope_contains(const char* name, const unsigned int scope){

	SymbolTableEntry* scope_entry = scope_link[scope];

	while(scope_entry) {
        const char* e_name = scope_entry->varVal ? scope_entry->varVal->name : scope_entry->funcVal->name;

        if(strcmp(name, e_name) == 0 && scope_entry->isActive)
			    return 1;

		scope_entry = scope_entry->next_in_scope;
	}

	return 0;
}


// Return an entry from a bucket
int symtable_lookup(const char* name, enum SymbolType type){

	unsigned int hash = symtable_hash(name);
	SymbolTableEntry* table_entry = symtable[hash];

	while(table_entry) {
        if (table_entry->varVal) {
            if(strcmp(name, table_entry->varVal->name) == 0 && type == table_entry->type && table_entry->isActive)
                return 1;
        }
        else if (table_entry->funcVal) {
            if(strcmp(name, table_entry->funcVal->name) == 0 && type == table_entry->type && table_entry->isActive)
                return 1;
        }


		table_entry = table_entry->next;
	}

	return 0;
}


// Return an entry from a scope
SymbolTableEntry* scope_lookup(const Variable* var, const Function* func, enum SymbolType type){

	SymbolTableEntry* scope_entry = scope_link[var ? var->scope : func->scope];

	while(scope_entry) {
        if(var && scope_entry->varVal){
            if(strcmp(var->name, scope_entry->varVal->name) == 0 && type == scope_entry->type)
			    return scope_entry;
        }
        else if(func && scope_entry->funcVal){
            if(strcmp(func->name, scope_entry->funcVal->name) == 0 && type == scope_entry->type)
			    return scope_entry;
        }

		scope_entry = scope_entry->next_in_scope;
	}

	return null;
}

void initialize_libfuncs() {
    for (int i = 0; i < 12; i++) {
        Function* func = malloc(sizeof(Function));
        func->name = libfuncs[i];
        func->scope = 0;
        func->line = 0;
        func->args = null;
        symtable_insert(null, func, 5);
    }
}


void print_scopes(){
    for(int i = 0; i < MAX; i++){
        SymbolTableEntry* curr = scope_link[i];
        if (!curr) break;
        fprintf(yyout, "\n--------------- Scope #%d ---------------\n", i);
        while(curr){
            char* type = get_type(curr->type);
            if(curr->varVal) {
                fprintf(yyout, "\"%s\" [%s] (line %d) (scope %d)\n", curr->varVal->name, type, curr->varVal->line, curr->varVal->scope);
            }
            else {
                if (curr->funcVal->args)
                    fprintf(yyout, "\"%s\" { args: %s} [%s] (line %d) (scope %d)\n", curr->funcVal->name, curr->funcVal->args, type, curr->funcVal->line, curr->funcVal->scope);
                else
                    fprintf(yyout, "\"%s\" [%s] (line %d) (scope %d)\n", curr->funcVal->name, type, curr->funcVal->line, curr->funcVal->scope);
            }
            curr = curr->next_in_scope;
        }
    }
}

char* get_type(enum SymbolType type) {
    switch (type) {
        case 0:
            return "global variable";
        case 1:
            return "local variable";
        case 2:
            return "local variable";
        case 3:
            return "formal argument";
        case 4:
            return "user function";
        case 5:
            return "library function";
    }
    return null;
}

int main(int argc, char** argv) {
    if(argc > 1) {
        if(!(yyin = fopen(argv[1], "r"))) {
            fprintf(stderr, "Cannot read file: %s\n", argv[1]);
            return 1;
        }
    }
    else yyin = stdin;

    if (argc > 2) {
        yyout = fopen(argv[2], "w");
    }
    else yyout = stdout;

    initialize_libfuncs();
    yyparse();
    print_scopes();

    return 0;
}

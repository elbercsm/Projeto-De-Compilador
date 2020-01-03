/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

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

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "parser.y" /* yacc.c:339  */

#include <stdio.h>
#include "hash.h"

Lista *lista_var, *lista_func, *var, *func, *doge;
Lista **tabela_hash_var, **tabela_hash_func;
Pilha *pilha_termo, *pilha_op; //TERMO: 0 = int, 1 = real, 2 = logico, 3 = ident; OP: + = 0, - = 1, * = 2, / = 3, ^ = 4, and = 5, or = 6.
int qtd_param = 0;
char nome_func[100];
char nome_func2[100];
char nome_var[100];
int tipo_parametros[10];

int ARIDADE_FUNC = 0;

extern int nlinhas;
extern char vlr_int[100];
extern char * yytext;
extern char ident[100];

int tipo_termos, tipo_operadores;
int TIPO_VAR = 0;
int TIPO_ATRIB = 0;
int TIPO_TERMO;
int TIPO_OP;
int ESCOPO_VAR = 0;
int flag_valorEhFuncao = 0; // VALOR era uma Chamada de Funcao 1
int flag_cmdChamada = 0; // Quando funcao eh chamada sozinha
int flag_ehMatriz = 0;
int flag_eh_arg = 0;
int DIM_M, DIM_N = 1;

//Busca a variavel na tabela e 'seta' se eh usada ou se nao encontrar a variavel, erro.
void doge_var(Lista** tab, Lista* v, char* nom, int esc)
{ 
	v = busca(tab, nom, esc);
	if(v == NULL){
		printf(" Erro semantico: Variavel %s nao declarada. Escopo: %d, Linha: %d \n", nom, esc, nlinhas);
		exit(0);
		
	}else{
		set_usada(v);
	}
	v = inicializa(); 
}


#line 114 "parser.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif


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
    token_var_fim = 258,
    token_var = 259,
    token_char = 260,
    token_algoritmo = 261,
    token_if = 262,
    token_do = 263,
    token_do_end = 264,
    token_strings = 265,
    token_string = 266,
    token_fim = 267,
    token_else = 268,
    token_while_end = 269,
    token_matriz = 270,
    token_booleans = 271,
    token_boolean = 272,
    token_or = 273,
    token_then = 274,
    token_for = 275,
    token_for_end = 276,
    token_ints = 277,
    token_func = 278,
    token_func_fim = 279,
    token_proc = 280,
    token_proc_fim = 281,
    token_switch = 282,
    token_switch_end = 283,
    token_case = 284,
    token_default = 285,
    token_int = 286,
    token_inicio = 287,
    token_and = 288,
    token_if_end = 289,
    token_then_end = 290,
    token_else_end = 291,
    token_de = 292,
    token_ate = 293,
    token_repeat = 294,
    token_reals = 295,
    token_return = 296,
    token_real = 297,
    token_not = 298,
    token_while = 299,
    token_chars = 300,
    token_passo = 301,
    token_print = 302,
    token_read = 303,
    token_central = 304,
    token_minimo = 305,
    token_maximo = 306,
    token_aspas = 307,
    token_atrib = 308,
    token_maior = 309,
    token_maior_igual = 310,
    token_menor = 311,
    token_menor_igual = 312,
    token_igual = 313,
    token_diferente = 314,
    token_mais = 315,
    token_menos = 316,
    token_div = 317,
    token_mult = 318,
    token_pot = 319,
    token_mod = 320,
    token_increment = 321,
    token_decrement = 322,
    token_colchete_abre = 323,
    token_colchete_fecha = 324,
    token_abreParen = 325,
    token_fechaParen = 326,
    token_pt = 327,
    token_virg = 328,
    token_pt_virg = 329,
    token_dois_pt = 330,
    token_hashtag = 331,
    token_chaves_abre = 332,
    token_chaves_fecha = 333,
    token_apost = 334,
    token_cbarra = 335,
    token_vlr_inteiro = 336,
    token_vlr_real = 337,
    token_vlr_char = 338,
    token_true = 339,
    token_false = 340,
    token_ident = 341,
    token_vlr_string = 342
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



/* Copy the second part of user declarations.  */

#line 250 "parser.tab.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

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

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
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
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
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
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
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
#define YYLAST   581

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  88
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  83
/* YYNRULES -- Number of rules.  */
#define YYNRULES  166
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  303

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   342

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
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
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   144,   144,   145,   147,   197,   197,   198,   199,   200,
     200,   203,   204,   207,   208,   211,   212,   213,   214,   217,
     218,   220,   237,   238,   241,   242,   245,   246,   247,   248,
     250,   252,   264,   277,   278,   281,   282,   284,   290,   301,
     302,   305,   306,   307,   308,   309,   310,   313,   314,   316,
     318,   321,   322,   325,   326,   327,   328,   331,   332,   333,
     336,   337,   343,   344,   345,   346,   347,   348,   349,   352,
     352,   363,   364,   366,   366,   369,   369,   370,   370,   372,
     383,   384,   386,   388,   389,   390,   392,   393,   395,   397,
     400,   400,   418,   434,   435,   437,   440,   440,   441,   443,
     446,   447,   448,   449,   450,   453,   475,   478,   479,   481,
     484,   485,   488,   488,   489,   489,   490,   490,   491,   491,
     492,   494,   503,   503,   504,   504,   505,   505,   506,   509,
     510,   511,   512,   522,   523,   524,   527,   538,   539,   541,
     564,   577,   577,   578,   581,   582,   585,   586,   587,   588,
     592,   593,   596,   597,   598,   599,   600,   602,   602,   603,
     603,   606,   607,   608,   609,   610,   611
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "token_var_fim", "token_var",
  "token_char", "token_algoritmo", "token_if", "token_do", "token_do_end",
  "token_strings", "token_string", "token_fim", "token_else",
  "token_while_end", "token_matriz", "token_booleans", "token_boolean",
  "token_or", "token_then", "token_for", "token_for_end", "token_ints",
  "token_func", "token_func_fim", "token_proc", "token_proc_fim",
  "token_switch", "token_switch_end", "token_case", "token_default",
  "token_int", "token_inicio", "token_and", "token_if_end",
  "token_then_end", "token_else_end", "token_de", "token_ate",
  "token_repeat", "token_reals", "token_return", "token_real", "token_not",
  "token_while", "token_chars", "token_passo", "token_print", "token_read",
  "token_central", "token_minimo", "token_maximo", "token_aspas",
  "token_atrib", "token_maior", "token_maior_igual", "token_menor",
  "token_menor_igual", "token_igual", "token_diferente", "token_mais",
  "token_menos", "token_div", "token_mult", "token_pot", "token_mod",
  "token_increment", "token_decrement", "token_colchete_abre",
  "token_colchete_fecha", "token_abreParen", "token_fechaParen",
  "token_pt", "token_virg", "token_pt_virg", "token_dois_pt",
  "token_hashtag", "token_chaves_abre", "token_chaves_fecha",
  "token_apost", "token_cbarra", "token_vlr_inteiro", "token_vlr_real",
  "token_vlr_char", "token_true", "token_false", "token_ident",
  "token_vlr_string", "$accept", "PROG", "INSERE_INIT", "BLOCO", "$@1",
  "$@2", "BLOCO_MAIN", "DECL_VAR", "MAIS_FUNCOES", "LISTA_VAR", "COD1",
  "REC_IDENT", "BLOCO_FUNC", "DECL_FUNC", "STRCPY_FUNC", "INSERE_FUNC_TAB",
  "INSERE_PROC_TAB", "PARAMETROS", "LISTA_PARAM", "INSERE_VAR_LISTAPARAM",
  "INSERE_LISTAPARAM_HASH", "LISTA_CMD", "CMD", "CMD_IF", "CMD_DO_WHILE",
  "CMD_REPEAT", "CMD_WHILE", "CMD_FOR", "IDENT_OU_INT", "CMD_SIMPLES",
  "ATRIB", "$@3", "IDENTS", "CMD_IMPRIMA", "$@4", "ARG", "$@5", "$@6",
  "VERIFICA_VAR_DECLARADA", "CMD_LEIA", "CMD_CENTRAL", "IDENT_OU_NUM",
  "CMD_MINIMO", "CMD_MAXIMO", "RETURN", "STRCPY_IDENT", "CHAMADA_FUNCAO",
  "$@7", "TIPO", "MATRIZ", "T_MAT", "$@8", "SALVAR_M", "TIPO_PRIM",
  "VALOR", "EXPRESSAO", "RESETA_PILHAS", "EXPRESSAO_ARIT", "EXPR", "$@9",
  "$@10", "$@11", "$@12", "VERIFICACAO_OP", "FATOR", "$@13", "$@14",
  "$@15", "TERMO", "VERIFICACAO_TERMOS", "TK_IDENT", "VERIFICA_LIM_MAT",
  "PILHA_IDENT", "TAM_MATRIZ", "$@16", "TK_VLR_LITERAL", "TK_VLR_NUM",
  "MULTIPLOS_NOT", "TK_VLR_BOOL", "OP_INCR", "$@17", "$@18",
  "OP_COMPARATIVO", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   337,   338,   339,   340,   341,   342
};
# endif

#define YYPACT_NINF -178

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-178)))

#define YYTABLE_NINF -160

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      35,   -38,    53,  -178,  -178,    14,    19,     6,    -1,    10,
      50,  -178,  -178,     2,    15,    11,  -178,  -178,     7,    52,
    -178,  -178,  -178,   495,  -178,    17,   495,  -178,  -178,    43,
      48,    62,    64,    70,    75,   100,  -178,  -178,  -178,  -178,
    -178,  -178,    16,  -178,    49,  -178,  -178,  -178,  -178,  -178,
    -178,    83,  -178,    71,  -178,  -178,    15,   130,    47,  -178,
    -178,  -178,    58,    77,   150,    94,    94,   149,   229,   171,
    -178,   129,   238,  -178,   161,  -178,   -55,    -7,    -7,    -7,
     102,  -178,  -178,  -178,    17,   118,   103,   107,   108,   130,
    -178,  -178,  -178,   150,  -178,  -178,  -178,   109,  -178,  -178,
    -178,  -178,  -178,  -178,   -43,   110,  -178,   495,  -178,    61,
    -178,  -178,  -178,  -178,  -178,  -178,   172,   -16,     3,  -178,
      71,  -178,   -25,  -178,  -178,   138,    25,  -178,   253,   111,
     -54,  -178,   112,    78,  -178,  -178,  -178,   120,  -178,   121,
     140,   133,  -178,  -178,   -54,  -178,   111,  -178,  -178,  -178,
    -178,   135,   174,   158,  -178,  -178,   -41,   150,   159,   299,
    -178,  -178,   152,  -178,  -178,  -178,  -178,  -178,  -178,   229,
     229,  -178,  -178,  -178,  -178,  -178,  -178,  -178,  -178,  -178,
    -178,  -178,  -178,  -178,  -178,   143,   196,  -178,  -178,   313,
    -178,   177,  -178,  -178,  -178,  -178,  -178,  -178,  -178,  -178,
      -7,    -7,    -7,  -178,  -178,  -178,   178,   176,  -178,   104,
    -178,   180,  -178,   165,  -178,    20,   239,  -178,   -16,   192,
    -178,  -178,  -178,  -178,  -178,  -178,  -178,   188,  -178,    25,
    -178,   -54,  -178,  -178,   189,   193,   197,   194,  -178,  -178,
     200,  -178,   150,  -178,   201,  -178,   130,  -178,   495,   229,
     229,   229,   229,   229,   229,   229,  -178,     4,  -178,    -7,
    -178,  -178,   202,   206,  -178,   203,    20,  -178,   359,     3,
       3,     3,     3,  -178,  -178,  -178,   373,    25,  -178,   209,
     210,   212,  -178,   150,  -178,  -178,  -178,   419,   273,  -178,
    -178,  -178,  -178,  -178,   434,   214,   215,  -178,  -178,   480,
    -178,  -178,  -178
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     4,     1,     0,     3,     0,     0,     0,
       0,     2,     7,     0,     9,     0,    14,    23,     0,     0,
      30,    30,   109,     0,    12,     0,     0,   109,   109,     0,
       0,     0,     0,     0,   140,     0,    40,    46,    42,    45,
      41,    43,     0,    60,    69,    62,    63,    66,    64,    65,
      67,     0,    61,    72,    68,     8,     5,     0,     0,    16,
      18,    13,     0,     0,     0,     0,     0,     0,     0,     0,
     140,     0,     0,    88,     0,    77,     0,     0,     0,     0,
     137,    11,    39,    44,     0,     0,    77,     0,     0,     0,
      10,    15,    17,     0,    22,   101,   102,     0,   104,   100,
     103,    21,    94,    93,     0,     0,    32,     0,   151,     0,
     109,   146,   148,   154,   155,   132,   108,   111,   120,   136,
     133,   130,     0,   134,   129,     0,     0,   109,     0,    73,
     109,    80,     0,     0,    58,    84,    83,     0,    57,     0,
       0,     0,   139,    71,   109,    92,    90,   158,   160,     6,
      21,     0,     0,     0,    34,    37,     0,     0,     0,     0,
     147,   149,     0,   161,   162,   163,   164,   165,   166,     0,
       0,   118,   114,   112,   116,   126,   122,   124,   128,   150,
     109,   152,   153,   156,   109,     0,     0,    50,    52,     0,
      75,     0,   144,   145,    79,   105,   106,    81,    59,    85,
       0,     0,     0,    99,   138,    70,     0,     0,    99,     0,
      20,     0,    33,     0,    31,    29,    47,   131,   110,   107,
     121,   121,   121,   121,   121,   121,   121,     0,    49,     0,
      51,   109,    74,    78,     0,     0,     0,     0,    91,    19,
       0,    95,     0,    37,     0,    25,     0,    27,     0,     0,
       0,     0,     0,     0,     0,     0,   135,     0,    79,     0,
      86,    87,   143,    98,    38,     0,    28,    24,     0,   119,
     115,   113,   117,   127,   123,   125,     0,     0,    76,     0,
       0,     0,    36,     0,    26,    48,    55,     0,     0,    82,
     141,    96,    38,    53,     0,     0,     0,    35,    56,     0,
     142,    97,    54
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -178,  -178,  -178,  -178,  -178,  -178,    -2,   289,   283,  -178,
     148,   287,    42,    12,   288,  -178,  -178,   246,  -178,    73,
      26,   -23,   -33,  -178,  -178,  -178,  -178,  -178,  -125,  -178,
    -178,  -178,  -178,  -178,  -178,   231,  -178,  -178,    65,  -178,
    -178,   -72,  -178,  -178,  -178,  -178,   -53,  -178,   -88,  -178,
    -178,  -178,   114,   116,  -136,    -8,  -178,   156,   160,  -178,
    -178,  -178,  -178,   147,  -169,  -178,  -178,  -178,  -177,  -178,
     -12,  -178,  -178,  -178,  -178,  -178,  -178,  -178,  -178,   -46,
    -178,  -178,  -178
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     5,    11,    89,    57,   245,   246,    14,    18,
     153,    19,   247,    15,    65,   244,   158,   105,   156,   211,
     282,    35,    36,    37,    38,    39,    40,    41,   136,    42,
      43,    85,    44,    45,   191,   129,   231,   130,   233,    46,
      47,   137,    48,    49,    50,    51,    52,   206,   101,   102,
     152,   296,   237,   103,   194,   195,    68,   116,   117,   222,
     221,   223,   220,   249,   118,   225,   226,   224,   119,   178,
      53,   204,    80,   142,   295,   196,   121,   122,   123,    54,
      87,    88,   170
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      69,   186,    82,    72,    12,   150,   139,   140,   205,    16,
      61,    55,   276,    71,    67,   115,   131,   171,   179,    73,
      74,   175,   124,     7,     7,     8,    58,     9,   154,   192,
     212,   132,   213,   193,    10,    59,    82,    60,     8,    82,
       9,     1,     8,   155,     9,   180,   172,   173,     3,   174,
     277,    10,    10,     4,   133,    90,   120,    22,    23,   181,
     182,    70,    24,   176,   177,   138,   138,   138,    58,   214,
      25,    91,   143,    92,   134,   135,   273,   274,   275,    70,
     269,   270,   271,   272,   159,    20,   185,   149,     6,    26,
      83,    27,    17,    17,    28,   258,    21,    29,    30,    31,
      32,    33,   162,    70,   257,   189,   134,    22,    23,    95,
     183,    70,    81,    75,   138,    96,   115,   115,    76,   187,
      25,    98,    84,   124,   124,    63,    82,    64,   234,   235,
     236,    63,    77,    93,    78,    99,    34,  -157,  -159,    26,
      79,    27,   160,   161,    28,   -89,   100,    29,    30,    31,
      32,    33,   288,    86,   264,    95,    82,   120,   120,   198,
     199,    96,    10,    94,   104,    97,   126,    98,   107,   128,
     141,   144,   227,   147,   145,   148,   228,   151,    22,    23,
     125,    99,   184,   197,   190,   157,    34,   279,   138,   138,
     138,    25,   100,   200,   201,   292,   115,   115,   115,   115,
     115,   115,   115,   124,   124,   124,   124,   124,   124,   124,
      26,   209,    27,   202,   203,    28,   208,   138,    29,    30,
      31,    32,    33,   217,   198,   268,   163,   164,   165,   166,
     167,   168,   210,   215,   229,    82,   169,   120,   120,   120,
     120,   120,   120,   120,   267,    22,    23,   138,   232,   238,
     239,   243,   248,   287,    82,   242,   169,    34,    25,   256,
      22,    23,   259,   262,   260,   138,    82,   188,   261,   263,
     280,   299,   108,    25,   281,   266,   127,    26,   283,    27,
     289,   294,    28,   300,   301,    29,    30,    31,    32,    33,
     109,   290,    26,   291,    27,    13,    56,    28,   207,   110,
      29,    30,    31,    32,    33,    62,    22,    23,   284,    66,
     111,   112,   106,   113,   114,    34,   265,   146,   297,    25,
      22,    23,   240,   278,    34,   241,   219,   230,     0,   218,
       0,     0,     0,    25,   216,     0,     0,     0,    26,    34,
      27,     0,     0,    28,     0,     0,    29,    30,    31,    32,
      33,     0,    26,     0,    27,     0,     0,    28,     0,     0,
      29,    30,    31,    32,    33,     0,    22,    23,   250,   251,
     252,   253,   254,   255,     0,     0,     0,     0,     0,    25,
      22,    23,     0,     0,     0,    34,     0,     0,     0,     0,
       0,     0,     0,    25,   286,   285,     0,     0,    26,    34,
      27,     0,     0,    28,     0,     0,    29,    30,    31,    32,
      33,     0,    26,     0,    27,     0,     0,    28,     0,     0,
      29,    30,    31,    32,    33,     0,    22,    23,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    25,
     293,    22,    23,     0,     0,    34,     0,     0,     0,     0,
       0,     0,     0,     0,    25,   298,     0,     0,    26,    34,
      27,     0,     0,    28,     0,     0,    29,    30,    31,    32,
      33,     0,     0,    26,     0,    27,     0,     0,    28,     0,
       0,    29,    30,    31,    32,    33,     0,    22,    23,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      25,   302,    22,    23,     0,    34,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    25,     0,     0,     0,    26,
      34,    27,     0,     0,    28,     0,     0,    29,    30,    31,
      32,    33,     0,     0,    26,     0,    27,     0,     0,    28,
       0,     0,    29,    30,    31,    32,    33,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    34,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    34
};

static const yytype_int16 yycheck[] =
{
      23,   126,    35,    26,     6,    93,    78,    79,   144,     3,
       3,    13,     8,    25,    22,    68,    71,    33,    43,    27,
      28,    18,    68,     4,     4,    23,    14,    25,    71,    83,
      71,    86,    73,    87,    32,    24,    69,    26,    23,    72,
      25,     6,    23,    86,    25,    70,    62,    63,    86,    65,
      46,    32,    32,     0,    61,    57,    68,     7,     8,    84,
      85,    86,    12,    60,    61,    77,    78,    79,    56,   157,
      20,    24,    84,    26,    81,    82,   253,   254,   255,    86,
     249,   250,   251,   252,   107,    86,    61,    89,    74,    39,
      74,    41,    86,    86,    44,   231,    86,    47,    48,    49,
      50,    51,   110,    86,   229,   128,    81,     7,     8,     5,
     122,    86,    12,    70,   126,    11,   169,   170,    70,   127,
      20,    17,    73,   169,   170,    73,   159,    75,   200,   201,
     202,    73,    70,    75,    70,    31,    86,    66,    67,    39,
      70,    41,    81,    82,    44,    70,    42,    47,    48,    49,
      50,    51,   277,    70,   242,     5,   189,   169,   170,    81,
      82,    11,    32,    86,    70,    15,    37,    17,    19,     8,
      68,    53,   180,    66,    71,    67,   184,    68,     7,     8,
       9,    31,    44,    71,    73,    75,    86,   259,   200,   201,
     202,    20,    42,    73,    73,   283,   249,   250,   251,   252,
     253,   254,   255,   249,   250,   251,   252,   253,   254,   255,
      39,    37,    41,    73,    81,    44,    81,   229,    47,    48,
      49,    50,    51,    71,    81,   248,    54,    55,    56,    57,
      58,    59,    74,    74,    38,   268,    64,   249,   250,   251,
     252,   253,   254,   255,   246,     7,     8,   259,    71,    71,
      74,    86,    13,   276,   287,    75,    64,    86,    20,    71,
       7,     8,    73,    69,    71,   277,   299,    14,    71,    69,
      68,   294,    43,    20,    68,    74,    38,    39,    75,    41,
      71,     8,    44,    69,    69,    47,    48,    49,    50,    51,
      61,    81,    39,    81,    41,     6,    13,    44,   150,    70,
      47,    48,    49,    50,    51,    18,     7,     8,   266,    21,
      81,    82,    66,    84,    85,    86,   243,    86,   292,    20,
       7,     8,   208,   258,    86,   209,   170,    14,    -1,   169,
      -1,    -1,    -1,    20,    35,    -1,    -1,    -1,    39,    86,
      41,    -1,    -1,    44,    -1,    -1,    47,    48,    49,    50,
      51,    -1,    39,    -1,    41,    -1,    -1,    44,    -1,    -1,
      47,    48,    49,    50,    51,    -1,     7,     8,   221,   222,
     223,   224,   225,   226,    -1,    -1,    -1,    -1,    -1,    20,
       7,     8,    -1,    -1,    -1,    86,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    20,    21,    36,    -1,    -1,    39,    86,
      41,    -1,    -1,    44,    -1,    -1,    47,    48,    49,    50,
      51,    -1,    39,    -1,    41,    -1,    -1,    44,    -1,    -1,
      47,    48,    49,    50,    51,    -1,     7,     8,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    20,
      21,     7,     8,    -1,    -1,    86,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    20,    21,    -1,    -1,    39,    86,
      41,    -1,    -1,    44,    -1,    -1,    47,    48,    49,    50,
      51,    -1,    -1,    39,    -1,    41,    -1,    -1,    44,    -1,
      -1,    47,    48,    49,    50,    51,    -1,     7,     8,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      20,    21,     7,     8,    -1,    86,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    20,    -1,    -1,    -1,    39,
      86,    41,    -1,    -1,    44,    -1,    -1,    47,    48,    49,
      50,    51,    -1,    -1,    39,    -1,    41,    -1,    -1,    44,
      -1,    -1,    47,    48,    49,    50,    51,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    86,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    86
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     6,    89,    86,     0,    90,    74,     4,    23,    25,
      32,    91,    94,    95,    96,   101,     3,    86,    97,    99,
      86,    86,     7,     8,    12,    20,    39,    41,    44,    47,
      48,    49,    50,    51,    86,   109,   110,   111,   112,   113,
     114,   115,   117,   118,   120,   121,   127,   128,   130,   131,
     132,   133,   134,   158,   167,    94,    96,    93,   101,    24,
      26,     3,    99,    73,    75,   102,   102,   143,   144,   109,
      86,   158,   109,   143,   143,    70,    70,    70,    70,    70,
     160,    12,   110,    74,    73,   119,    70,   168,   169,    92,
      94,    24,    26,    75,    86,     5,    11,    15,    17,    31,
      42,   136,   137,   141,    70,   105,   105,    19,    43,    61,
      70,    81,    82,    84,    85,   134,   145,   146,   152,   156,
     158,   164,   165,   166,   167,     9,    37,    38,     8,   123,
     125,    71,    86,    61,    81,    82,   116,   129,   158,   129,
     129,    68,   161,   158,    53,    71,   123,    66,    67,    94,
     136,    68,   138,    98,    71,    86,   106,    75,   104,   109,
      81,    82,   143,    54,    55,    56,    57,    58,    59,    64,
     170,    33,    62,    63,    65,    18,    60,    61,   157,    43,
      70,    84,    85,   158,    44,    61,   116,   143,    14,   109,
      73,   122,    83,    87,   142,   143,   163,    71,    81,    82,
      73,    73,    73,    81,   159,   142,   135,    98,    81,    37,
      74,   107,    71,    73,   136,    74,    35,    71,   146,   145,
     150,   148,   147,   149,   155,   153,   154,   143,   143,    38,
      14,   124,    71,   126,   129,   129,   129,   140,    71,    74,
     140,   141,    75,    86,   103,    94,    95,   100,    13,   151,
     151,   151,   151,   151,   151,   151,    71,   116,   142,    73,
      71,    71,    69,    69,   136,   107,    74,    94,   109,   152,
     152,   152,   152,   156,   156,   156,     8,    46,   126,   129,
      68,    68,   108,    75,   100,    36,    21,   109,   116,    71,
      81,    81,   136,    21,     8,   162,   139,   108,    21,   109,
      69,    69,    21
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    88,    89,    89,    90,    92,    91,    91,    91,    93,
      91,    94,    94,    95,    95,    96,    96,    96,    96,    97,
      97,    98,    99,    99,   100,   100,   101,   101,   101,   101,
     102,   103,   104,   105,   105,   106,   106,   107,   108,   109,
     109,   110,   110,   110,   110,   110,   110,   111,   111,   112,
     113,   114,   114,   115,   115,   115,   115,   116,   116,   116,
     117,   117,   117,   117,   117,   117,   117,   117,   117,   119,
     118,   120,   120,   122,   121,   124,   123,   125,   123,   126,
     127,   127,   128,   129,   129,   129,   130,   131,   132,   133,
     135,   134,   134,   136,   136,   137,   139,   138,   138,   140,
     141,   141,   141,   141,   141,   142,   142,   143,   143,   144,
     145,   145,   147,   146,   148,   146,   149,   146,   150,   146,
     146,   151,   153,   152,   154,   152,   155,   152,   152,   156,
     156,   156,   156,   156,   156,   156,   157,   158,   158,   159,
     160,   162,   161,   161,   163,   163,   164,   164,   164,   164,
     165,   165,   166,   166,   166,   166,   166,   168,   167,   169,
     167,   170,   170,   170,   170,   170,   170
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     5,     4,     0,     0,     4,     1,     2,     0,
       3,     3,     2,     3,     2,     3,     2,     3,     2,     6,
       5,     0,     3,     1,     2,     1,     9,     7,     8,     6,
       0,     0,     0,     3,     2,     7,     5,     0,     0,     2,
       1,     1,     1,     1,     2,     1,     1,     5,     8,     5,
       4,     5,     4,     9,    11,     8,    10,     1,     1,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     0,
       4,     3,     1,     0,     5,     0,     5,     0,     3,     0,
       3,     4,     8,     1,     1,     2,     6,     6,     2,     1,
       0,     5,     3,     1,     1,     4,     0,     8,     4,     0,
       1,     1,     1,     1,     1,     1,     1,     4,     2,     0,
       3,     1,     0,     5,     0,     5,     0,     5,     0,     5,
       1,     0,     0,     5,     0,     5,     0,     5,     2,     1,
       1,     3,     1,     1,     1,     4,     0,     2,     4,     0,
       0,     0,     8,     4,     1,     1,     1,     2,     1,     2,
       2,     1,     2,     2,     1,     1,     2,     0,     3,     0,
       3,     1,     1,     1,     1,     1,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
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


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
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
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
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
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
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
            /* Fall through.  */
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

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
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
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

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
      int yyn = yypact[*yyssp];
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
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
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
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
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
          yyp++;
          yyformat++;
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
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

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
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
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
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

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

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
| yyreduce -- Do a reduction.  |
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
        case 4:
#line 147 "parser.y" /* yacc.c:1646  */
    { 
	// inserindo o nome da main na tabela de variaveis

	lista_var = insere_variavel_lista(lista_var, ident, 1); // 1 = usado
	insere_variavel_hash(tabela_hash_var, lista_var, -1, 0);
	libera(lista_var);
	lista_var = inicializa();

	//inserindo as funcoes primitivas da linguagem na tabela de funcoes

	tabela_hash_func = insere_funcao(tabela_hash_func, "leia", -1, 0);
	tipo_parametros[0] = -1;
	insere_parametro_funcao(tabela_hash_func,"leia",tipo_parametros);

	tipo_parametros[0]=0;
	tipo_parametros[1]=-1;

	tabela_hash_func = insere_funcao(tabela_hash_func, "escreva", -1, 1);
	insere_parametro_funcao(tabela_hash_func,"escreva",tipo_parametros);

	tipo_parametros[0]=0;
	tipo_parametros[1]=0;
	tipo_parametros[2]=-1;

	tabela_hash_func = insere_funcao(tabela_hash_func, "maximo", 0, 2);
	insere_parametro_funcao(tabela_hash_func,"maximo",tipo_parametros);
	tabela_hash_func = insere_funcao(tabela_hash_func, "minimo", 0, 2);
	insere_parametro_funcao(tabela_hash_func,"minimo",tipo_parametros);
	tabela_hash_func = insere_funcao(tabela_hash_func, "%", 0, 2);
	insere_parametro_funcao(tabela_hash_func,"%",tipo_parametros);
	tabela_hash_func = insere_funcao(tabela_hash_func, "^", 0, 2);
	insere_parametro_funcao(tabela_hash_func,"^",tipo_parametros);
	tabela_hash_func = insere_funcao(tabela_hash_func, "+", 0, 2);
	insere_parametro_funcao(tabela_hash_func,"+",tipo_parametros);
	tabela_hash_func = insere_funcao(tabela_hash_func, "-", 0, 2);
	insere_parametro_funcao(tabela_hash_func,"-",tipo_parametros);
	tabela_hash_func = insere_funcao(tabela_hash_func, "*", 0, 2);
	insere_parametro_funcao(tabela_hash_func,"*",tipo_parametros);
	tabela_hash_func = insere_funcao(tabela_hash_func, "/", 0, 2);
	insere_parametro_funcao(tabela_hash_func,"/",tipo_parametros);

	tipo_parametros[2]=0;
	tipo_parametros[3]=-1;

	tabela_hash_func = insere_funcao(tabela_hash_func, "central", 0, 3);
	insere_parametro_funcao(tabela_hash_func,"central",tipo_parametros);
	
}
#line 1684 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 197 "parser.y" /* yacc.c:1646  */
    { ESCOPO_VAR = 0; }
#line 1690 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 200 "parser.y" /* yacc.c:1646  */
    { ESCOPO_VAR = 0; }
#line 1696 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 220 "parser.y" /* yacc.c:1646  */
    {
	if (flag_ehMatriz == 0) {
		DIM_M = 1;
		DIM_N = 1;
		insere_variavel_hash(tabela_hash_var, lista_var, TIPO_VAR, ESCOPO_VAR); 
	}
	else {
		edita_para_matriz(lista_var, DIM_M, DIM_N);
		insere_variavel_hash(tabela_hash_var, lista_var, TIPO_VAR, ESCOPO_VAR);
		DIM_M = 1;
		DIM_N = 1;
	}
	libera(lista_var);
	lista_var = inicializa();
}
#line 1716 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 237 "parser.y" /* yacc.c:1646  */
    { lista_var = insere_variavel_lista(lista_var, ident,0); }
#line 1722 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 238 "parser.y" /* yacc.c:1646  */
    { lista_var = insere_variavel_lista(lista_var, ident,0); }
#line 1728 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 250 "parser.y" /* yacc.c:1646  */
    { strcpy(nome_func, ident); strcpy(nome_func2, nome_func); ESCOPO_VAR++;}
#line 1734 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 252 "parser.y" /* yacc.c:1646  */
    {
	func = busca(tabela_hash_func, nome_func, ESCOPO_VAR);
	if(func) {
		printf(" Erro semantico: Funcao %s redeclarada. Escopo: %d, Linha: %d \n", nome_func, ESCOPO_VAR, nlinhas);
		exit(0);
	}
	tabela_hash_func = insere_funcao(tabela_hash_func, nome_func, TIPO_VAR, qtd_param); // TIPO_VAR eh o tipo de retorno da funcao
	tipo_parametros[qtd_param] = -1;
	tabela_hash_func = insere_parametro_funcao(tabela_hash_func, nome_func, tipo_parametros);
	qtd_param = 0;
}
#line 1750 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 264 "parser.y" /* yacc.c:1646  */
    {
	func = busca(tabela_hash_func, nome_func, ESCOPO_VAR);
	if(func) {
		printf(" Erro semantico: Funcao %s redeclarada. Escopo: %d, Linha: %d \n", nome_func, ESCOPO_VAR, nlinhas);
		exit(0);
	}
	tabela_hash_func = insere_funcao(tabela_hash_func, nome_func, -1, qtd_param); // -1 eh o TIPO_VAR para funcoes que nao tem retorno, ou seja, para procedimentos
	tipo_parametros[qtd_param] = -1;
	tabela_hash_func = insere_parametro_funcao(tabela_hash_func, nome_func, tipo_parametros);
	qtd_param = 0;
}
#line 1766 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 284 "parser.y" /* yacc.c:1646  */
    { 
	strcpy(nome_var, yytext); 
	lista_var = insere_variavel_lista(lista_var, yytext, 0); 
	qtd_param++; 
}
#line 1776 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 290 "parser.y" /* yacc.c:1646  */
    { 
	insere_variavel_hash(tabela_hash_var, lista_var, TIPO_VAR, ESCOPO_VAR); 
	doge_var(tabela_hash_var, var, nome_var, 0); 
	libera(lista_var); 
	lista_var = inicializa(); 
	tipo_parametros[qtd_param -1] = TIPO_VAR;
}
#line 1788 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 337 "parser.y" /* yacc.c:1646  */
    {
		  if (get_retorno(busca(tabela_hash_func, nome_func, ESCOPO_VAR)) != -1){
			 printf(" Erro semantico: Funcao com retorno porem sem atribuicao. Funcao: %s, Linha: %d\n", nome_func, nlinhas); 
			exit(0);	
		}
	}
#line 1799 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 352 "parser.y" /* yacc.c:1646  */
    { TIPO_ATRIB = get_tipo(busca(tabela_hash_var,nome_var,ESCOPO_VAR)); }
#line 1805 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 352 "parser.y" /* yacc.c:1646  */
    { 
	if (flag_valorEhFuncao == 1){
		if(TIPO_ATRIB != get_retorno(busca(tabela_hash_func, nome_func, ESCOPO_VAR))){
			printf(" Erro semantico: Funcao com tipo de retorno incompativel. Funcao: %s, Linha: %d \n", nome_func, nlinhas);
			exit(0);
		}
		flag_valorEhFuncao = 0;
	}
}
#line 1819 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 363 "parser.y" /* yacc.c:1646  */
    {doge_var(tabela_hash_var, var, nome_var, ESCOPO_VAR);}
#line 1825 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 364 "parser.y" /* yacc.c:1646  */
    {doge_var(tabela_hash_var, var, nome_var, ESCOPO_VAR);}
#line 1831 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 366 "parser.y" /* yacc.c:1646  */
    {flag_eh_arg = 0;}
#line 1837 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 369 "parser.y" /* yacc.c:1646  */
    {flag_eh_arg = 1;}
#line 1843 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 370 "parser.y" /* yacc.c:1646  */
    {flag_eh_arg = 1;}
#line 1849 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 372 "parser.y" /* yacc.c:1646  */
    {
	var = busca(tabela_hash_var,ident,ESCOPO_VAR);
	if (var == NULL)
		{
			printf(" Erro semantico: Variavel %s nao declarada. Linha: %d.\n", ident, nlinhas);
			exit(0);
		}
	doge = insere_variavel_lista1(doge,ident,get_tipo(var),get_escopo(var),get_usada(var));
	qtd_param++;
}
#line 1864 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 395 "parser.y" /* yacc.c:1646  */
    {flag_valorEhFuncao = 0;}
#line 1870 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 397 "parser.y" /* yacc.c:1646  */
    { strcpy(nome_func, ident); }
#line 1876 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 400 "parser.y" /* yacc.c:1646  */
    { flag_eh_arg = 0; }
#line 1882 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 401 "parser.y" /* yacc.c:1646  */
    {	
		func = busca(tabela_hash_func, nome_func, ESCOPO_VAR);
		if (func == NULL){
				printf(" Erro semantico: Funcao nao declarada. Funcao: %s, Linha: %d.\n", nome_func, nlinhas);
				exit(0);
		}
		if (get_aridade(func) != qtd_param){
				printf(" Erro semantico: Quantidade de parametros errada. Funcao %s, Linha: %d.\n", nome_func, nlinhas);
				exit(0);
		}
		if (verifica_tipo_parametros_funcao(tabela_hash_func, nome_func, doge) == 0){
				printf(" Erro semantico: Tipo de parametros errado. Funcao: %s, Linha: %d.\n", nome_func, nlinhas);			
				exit(0);
		}
		qtd_param = 0;
		doge = inicializa();	
	}
#line 1904 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 418 "parser.y" /* yacc.c:1646  */
    { 
		strcpy(nome_func, ident);
		func = busca(tabela_hash_func, nome_func, ESCOPO_VAR);
		if (func == NULL){
				printf(" Erro semantico: Funcao nao declarada. Funcao: %s, Linha: %d.\n", nome_func, nlinhas);
				exit(0);
		}
		if (get_aridade(func) > 0){
				printf(" Erro semantico: Quantidade de parametros errada. Funcao: %s, Linha: %d.\n", nome_func, nlinhas);
				exit(0);
		}
	}
#line 1921 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 434 "parser.y" /* yacc.c:1646  */
    {flag_ehMatriz = 0;}
#line 1927 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 437 "parser.y" /* yacc.c:1646  */
    {flag_ehMatriz = 1;}
#line 1933 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 440 "parser.y" /* yacc.c:1646  */
    {DIM_N = atoi(vlr_int);}
#line 1939 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 443 "parser.y" /* yacc.c:1646  */
    {DIM_M = atoi(vlr_int);}
#line 1945 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 446 "parser.y" /* yacc.c:1646  */
    {TIPO_VAR = 0; }
#line 1951 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 447 "parser.y" /* yacc.c:1646  */
    {TIPO_VAR = 3; }
#line 1957 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 448 "parser.y" /* yacc.c:1646  */
    {TIPO_VAR = 4; }
#line 1963 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 103:
#line 449 "parser.y" /* yacc.c:1646  */
    {TIPO_VAR = 1; }
#line 1969 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 104:
#line 450 "parser.y" /* yacc.c:1646  */
    {TIPO_VAR = 2; }
#line 1975 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 105:
#line 453 "parser.y" /* yacc.c:1646  */
    { 
		tipo_operadores =  pilha_remove(pilha_op);
		tipo_termos = pilha_remove(pilha_termo);
		if (tipo_operadores == 0){
			if (!(tipo_termos == 0 || tipo_termos == 1)){
				printf(" Erro semantico: Incompatibilidade na expressao. Linha: %d.\n", nlinhas ); 
				exit(0);
			}
		}
		if (tipo_operadores == 1){
			if (tipo_termos != 2){
				printf(" Erro semantico: Incompatibilidade na expressao. Linha: %d.\n", nlinhas ); 
				exit(0);
			}
		}
		if(flag_eh_arg == 0){
			if(TIPO_ATRIB != tipo_termos){ 
				printf(" Erro semantico: Incompatibilidade de tipos na atribuicao. Linha: %d.\n", nlinhas);
				exit(0);
			}
		}
 	}
#line 2002 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 109:
#line 481 "parser.y" /* yacc.c:1646  */
    {/*verificar com as 2 pilhas*/ pilha_destroi(pilha_termo); pilha_constroi(pilha_termo); pilha_destroi(pilha_op); pilha_constroi(pilha_op);}
#line 2008 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 112:
#line 488 "parser.y" /* yacc.c:1646  */
    {TIPO_OP = 0;}
#line 2014 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 114:
#line 489 "parser.y" /* yacc.c:1646  */
    {TIPO_OP = 0;}
#line 2020 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 116:
#line 490 "parser.y" /* yacc.c:1646  */
    {TIPO_OP = 0;}
#line 2026 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 118:
#line 491 "parser.y" /* yacc.c:1646  */
    {TIPO_OP = 1;}
#line 2032 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 121:
#line 494 "parser.y" /* yacc.c:1646  */
    {
	pilha_insere(pilha_op, TIPO_OP);
	if (!pilha_verifica_compatibilidade(pilha_op)) {
		printf(" Erro semantico na linha %d. Incompatibilidade de operadores na expressao.\n", nlinhas);
		exit(0);
	}
}
#line 2044 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 122:
#line 503 "parser.y" /* yacc.c:1646  */
    {TIPO_OP = 0;}
#line 2050 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 124:
#line 504 "parser.y" /* yacc.c:1646  */
    {TIPO_OP = 0;}
#line 2056 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 126:
#line 505 "parser.y" /* yacc.c:1646  */
    {TIPO_OP = 1;}
#line 2062 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 132:
#line 513 "parser.y" /* yacc.c:1646  */
    {
		flag_valorEhFuncao = 1; 
		if (busca(tabela_hash_func, nome_func, ESCOPO_VAR) != NULL)
			TIPO_TERMO = get_retorno(busca(tabela_hash_func, nome_func, ESCOPO_VAR));
		else {
			printf(" Erro semantico: Funcao %s nao declarada. Linha: %d\n", nome_func, nlinhas);
			exit(0);
		}
     }
#line 2076 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 133:
#line 522 "parser.y" /* yacc.c:1646  */
    { doge_var(tabela_hash_var, var, ident, ESCOPO_VAR); }
#line 2082 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 136:
#line 527 "parser.y" /* yacc.c:1646  */
    {
	pilha_insere(pilha_termo, TIPO_TERMO);
	if (flag_eh_arg == 0){ //Se nao for argumento, insere na pilha para comparar com a atribuicao
		if(!pilha_verifica_compatibilidade(pilha_termo)) {
				printf(" Erro semantico: Incompatibilidade de tipos na expressao. Linha: %d\n", nlinhas);
				exit(0);
		}
	}
}
#line 2096 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 139:
#line 541 "parser.y" /* yacc.c:1646  */
    {
	var = busca(tabela_hash_var, nome_var, ESCOPO_VAR);
	if (var == NULL){
		printf(" Erro semantico: Variavel %s nao declarada. Linha: %d.\n", nome_var, nlinhas);
		exit(0);
	}
	else {
		if (DIM_M >= 1){
			if (DIM_N >= 1){
				if (DIM_M > get_m(var) || DIM_N > get_n(var)){
					printf(" Erro semantico: Acessando posicao inexistente em matriz. Linha: %d.\n", nlinhas);
					exit(0);
				}
			}
			else
				if (DIM_M > get_m(var)){
					printf(" Erro semantico: Acessando posicao inexistente em vetor. Linha: %d.\n", nlinhas);
					exit(0);
				}
		}
	}
}
#line 2123 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 140:
#line 564 "parser.y" /* yacc.c:1646  */
    { 
	strcpy(nome_var, ident);
	if (busca(tabela_hash_var,nome_var,ESCOPO_VAR) != NULL){
		TIPO_VAR = get_tipo(busca(tabela_hash_var,nome_var,ESCOPO_VAR));
		TIPO_TERMO = TIPO_VAR;
	}
	else {
		printf(" Erro semantico: Variavel %s nao declarada. Linha: %d.\n", nome_var, nlinhas);
		exit(0);
	}
}
#line 2139 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 141:
#line 577 "parser.y" /* yacc.c:1646  */
    {DIM_N = atoi(vlr_int);}
#line 2145 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 146:
#line 585 "parser.y" /* yacc.c:1646  */
    { TIPO_TERMO = 0;}
#line 2151 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 147:
#line 586 "parser.y" /* yacc.c:1646  */
    { TIPO_TERMO = 0;}
#line 2157 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 148:
#line 587 "parser.y" /* yacc.c:1646  */
    { TIPO_TERMO = 1; }
#line 2163 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 149:
#line 588 "parser.y" /* yacc.c:1646  */
    { TIPO_TERMO = 1; }
#line 2169 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 152:
#line 596 "parser.y" /* yacc.c:1646  */
    { TIPO_TERMO = 2; }
#line 2175 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 153:
#line 597 "parser.y" /* yacc.c:1646  */
    { TIPO_TERMO = 2; }
#line 2181 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 154:
#line 598 "parser.y" /* yacc.c:1646  */
    {TIPO_TERMO = 2;}
#line 2187 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 155:
#line 599 "parser.y" /* yacc.c:1646  */
    {TIPO_TERMO = 2;}
#line 2193 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 156:
#line 600 "parser.y" /* yacc.c:1646  */
    { doge_var(tabela_hash_var, var, ident, ESCOPO_VAR); }
#line 2199 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 157:
#line 602 "parser.y" /* yacc.c:1646  */
    { doge_var(tabela_hash_var, var, ident, ESCOPO_VAR); }
#line 2205 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 159:
#line 603 "parser.y" /* yacc.c:1646  */
    { doge_var(tabela_hash_var, var, ident, ESCOPO_VAR); }
#line 2211 "parser.tab.c" /* yacc.c:1646  */
    break;


#line 2215 "parser.tab.c" /* yacc.c:1646  */
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

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

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
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
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

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

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
                  yystos[*yyssp], yyvsp);
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
#line 613 "parser.y" /* yacc.c:1906  */


#include "lex.yy.c"

int main(void){

	lista_var = inicializa();
	var = inicializa();
	lista_func = inicializa();
	func = inicializa();
	tabela_hash_var = inicializa_hash();
	tabela_hash_func = inicializa_hash();
	pilha_termo = pilha_constroi(pilha_termo);
	pilha_op = pilha_constroi(pilha_op);
	yyparse();
	verifica_variavel_usada(tabela_hash_var);
	printf("Algoritmo Reconhecido com sucesso \n");
	return 0;
}

yyerror(void){
  printf(" Erro sintatico. Linha: %d\n", nlinhas);
  exit(1);
}

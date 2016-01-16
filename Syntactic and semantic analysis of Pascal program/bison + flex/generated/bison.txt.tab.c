
/*  A Bison parser, made from bison.txt
    by GNU Bison version 1.28  */

#define YYBISON 1  /* Identify Bison output.  */

#define	G_VAR	257
#define	G_STR	258
#define	G_INT	259
#define	G_BEGIN	260
#define	G_END	261
#define	G_IF	262
#define	G_THEN	263
#define	G_ELSE	264
#define	G_IDENT	265
#define	G_NUMBER	266
#define	G_STRING	267
#define	G_ASSIGN	268
#define	G_NXTL	269
#define	G_ENDL	270
#define	G_COMMA	271
#define	G_PLUS	272
#define	G_MINUS	273
#define	G_MULT	274
#define	G_DIV	275
#define	G_LPAR	276
#define	G_RPAR	277
#define	G_CMP	278
#define	G_MORE	279
#define	G_LESS	280
#define	G_CMORE	281
#define	G_CLESS	282
#define	G_AND	283
#define	G_OR	284
#define	G_SPACE	285

#line 1 "bison.txt"

//#define DEBUG_PT
#define DEBUG_T

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "Property_table.h"
#include "Table.h"
extern int line_counter;
void yyerror(char const* msg) { printf("\n[ERROR] Syntax error. Line: %i\n", line_counter); }
#define YYPRINT(file, type, value) fprintf(file, "%d", value);

extern FILE *yyin;
const char FILENAME[] = "input.txt";
char PROP_TABLE_FILE[] = "property_table.db";
int yylex();
int yyparse();
extern int SEM_ERROR;
extern table* DEC_LIST;
extern char* ERROR_MSG;
extern int PROP_TAB_FAIL;
const int MSG_SIZE = 2048;
/* =========== table ============ */
#ifndef _tab
#define _tab
typedef struct Table
{
	char* ident;
	int prop;
	struct Table* next;
} table;/**/
#endif
/* ====== init prop_table ======= */
int count = 0;
prop_table* p_table = NULL;
/* ============================== */
#ifdef DEBUG_T
void debug_table(table *list) { printf("\n\n---> Result from AXIOM:");view_table(list); printf("\n\n"); }
#else
void debug_table(table *list) { /*empty*/ }
#endif
#ifdef DEBUG_PT
void debug_prop_table() { view_prop_table(p_table, count); printf("\n\n"); }
#else
void debug_prop_table() { /*empty*/ }
#endif

typedef union { table* t; } YYSTYPE;
#ifndef YYDEBUG
#define YYDEBUG 1
#endif

#include <stdio.h>

#ifndef __cplusplus
#ifndef __STDC__
#define const
#endif
#endif



#define	YYFINAL		77
#define	YYFLAG		-32768
#define	YYNTBASE	32

#define YYTRANSLATE(x) ((unsigned)(x) <= 285 ? yytranslate[x] : 51)

static const char yytranslate[] = {     0,
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
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     1,     3,     4,     5,     6,
     7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
    17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
    27,    28,    29,    30,    31
};

#if YYDEBUG != 0
static const short yyprhs[] = {     0,
     0,     4,     8,    13,    18,    19,    23,    26,    27,    30,
    35,    40,    42,    46,    48,    52,    54,    58,    60,    62,
    72,    76,    77,    81,    83,    87,    89,    93,    95,    97,
    99,   101,   103,   105,   107,   109,   111,   113,   115,   117,
   119,   122
};

static const short yyrhs[] = {    33,
    35,    16,     0,     3,    50,    34,     0,    11,     4,    15,
    34,     0,    11,     5,    15,    34,     0,     0,     6,    36,
     7,     0,    37,    36,     0,     0,    35,    15,     0,    11,
    14,    13,    15,     0,    11,    14,    38,    15,     0,    41,
     0,    38,    49,    39,     0,    39,     0,    39,    48,    40,
     0,    40,     0,    22,    38,    23,     0,    11,     0,    12,
     0,     8,    31,    43,    31,     9,    50,    37,    50,    42,
     0,    10,    50,    37,     0,     0,    43,    47,    44,     0,
    44,     0,    44,    46,    45,     0,    45,     0,    22,    43,
    23,     0,    11,     0,    12,     0,    29,     0,    30,     0,
    24,     0,    25,     0,    26,     0,    27,     0,    28,     0,
    21,     0,    20,     0,    18,     0,    19,     0,    31,    50,
     0,     0
};

#endif

#if YYDEBUG != 0
static const short yyrline[] = { 0,
   104,   121,   122,   123,   124,   125,   126,   127,   128,   129,
   130,   131,   133,   134,   135,   136,   137,   138,   139,   141,
   147,   148,   150,   151,   152,   153,   154,   155,   156,   158,
   159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
   169,   170
};
#endif


#if YYDEBUG != 0 || defined (YYERROR_VERBOSE)

static const char * const yytname[] = {   "$","error","$undefined.","G_VAR",
"G_STR","G_INT","G_BEGIN","G_END","G_IF","G_THEN","G_ELSE","G_IDENT","G_NUMBER",
"G_STRING","G_ASSIGN","G_NXTL","G_ENDL","G_COMMA","G_PLUS","G_MINUS","G_MULT",
"G_DIV","G_LPAR","G_RPAR","G_CMP","G_MORE","G_LESS","G_CMORE","G_CLESS","G_AND",
"G_OR","G_SPACE","AXIOM","L_DECL","L_IDENT","BLOCK","ACTIONS","OPER","E","T",
"F","IFRule","ELSERule","LOG_EXPR","T_LOG","F_LOG","LOG_OP","SIGN","N_Div_Mult",
"N_Plus_Minus","N_SPACE", NULL
};
#endif

static const short yyr1[] = {     0,
    32,    33,    34,    34,    34,    35,    36,    36,    37,    37,
    37,    37,    38,    38,    39,    39,    40,    40,    40,    41,
    42,    42,    43,    43,    44,    44,    45,    45,    45,    46,
    46,    47,    47,    47,    47,    47,    48,    48,    49,    49,
    50,    50
};

static const short yyr2[] = {     0,
     3,     3,     4,     4,     0,     3,     2,     0,     2,     4,
     4,     1,     3,     1,     3,     1,     3,     1,     1,     9,
     3,     0,     3,     1,     3,     1,     3,     1,     1,     1,
     1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
     2,     0
};

static const short yydefact[] = {     0,
    42,     0,    42,     5,     8,     0,    41,     0,     2,     0,
     0,     0,     0,     8,    12,     1,     0,     0,     0,     0,
     9,     6,     7,     5,     5,    28,    29,     0,     0,    24,
    26,    18,    19,     0,     0,     0,    14,    16,     3,     4,
     0,    32,    33,    34,    35,    36,     0,     0,    30,    31,
     0,    10,     0,    11,    39,    40,     0,    38,    37,     0,
    27,    42,    23,    25,    17,    13,    15,     0,    42,    22,
    42,    20,     0,    21,     0,     0,     0
};

static const short yydefgoto[] = {    75,
     2,     9,    12,    13,    14,    36,    37,    38,    15,    72,
    29,    30,    31,    51,    48,    60,    57,     4
};

static const short yypact[] = {     8,
   -15,    28,   -15,    25,     2,    31,-32768,    19,-32768,    13,
    34,    35,    42,     2,-32768,-32768,    36,    37,    -7,   -10,
-32768,-32768,-32768,    25,    25,-32768,-32768,    -7,    -6,    11,
-32768,-32768,-32768,    38,    -5,    20,    22,-32768,-32768,-32768,
     3,-32768,-32768,-32768,-32768,-32768,    45,    -7,-32768,-32768,
    -7,-32768,    14,-32768,-32768,-32768,    -5,-32768,-32768,    -5,
-32768,   -15,    11,-32768,-32768,    22,-32768,     2,   -15,    46,
   -15,-32768,     2,-32768,    55,    57,-32768
};

static const short yypgoto[] = {-32768,
-32768,    21,    56,    47,   -59,    27,     6,     0,-32768,-32768,
    39,    16,    18,-32768,-32768,-32768,-32768,    -3
};


#define	YYLAST		69


static const short yytable[] = {     7,
    32,    33,    34,    26,    27,    32,    33,     5,    69,    10,
     1,    35,    11,    74,    28,     3,    35,    42,    43,    44,
    45,    46,    17,    18,    47,    61,    42,    43,    44,    45,
    46,    55,    56,     5,    54,     8,    65,    55,    56,    49,
    50,    58,    59,    19,    39,    40,    16,    20,    22,    21,
    24,    25,    52,    62,    76,    71,    77,     6,    68,    67,
    23,    53,    66,    63,     0,    70,    41,    73,    64
};

static const short yycheck[] = {     3,
    11,    12,    13,    11,    12,    11,    12,     6,    68,     8,
     3,    22,    11,    73,    22,    31,    22,    24,    25,    26,
    27,    28,     4,     5,    31,    23,    24,    25,    26,    27,
    28,    18,    19,     6,    15,    11,    23,    18,    19,    29,
    30,    20,    21,    31,    24,    25,    16,    14,     7,    15,
    15,    15,    15,     9,     0,    10,     0,     2,    62,    60,
    14,    35,    57,    48,    -1,    69,    28,    71,    51
};
/* -*-C-*-  Note some compilers choke on comments on `#line' lines.  */

/* This file comes from bison-1.28.  */

/* Skeleton output parser for bison,
   Copyright (C) 1984, 1989, 1990 Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 59 Temple Place - Suite 330,
   Boston, MA 02111-1307, USA.  */

/* As a special exception, when this file is copied by Bison into a
   Bison output file, you may use that output file without restriction.
   This special exception was added by the Free Software Foundation
   in version 1.24 of Bison.  */

/* This is the parser code that is written into each bison parser
  when the %semantic_parser declaration is not specified in the grammar.
  It was written by Richard Stallman by simplifying the hairy parser
  used when %semantic_parser is specified.  */

#ifndef YYSTACK_USE_ALLOCA
#ifdef alloca
#define YYSTACK_USE_ALLOCA
#else /* alloca not defined */
#ifdef __GNUC__
#define YYSTACK_USE_ALLOCA
#define alloca __builtin_alloca
#else /* not GNU C.  */
#if (!defined (__STDC__) && defined (sparc)) || defined (__sparc__) || defined (__sparc) || defined (__sgi) || (defined (__sun) && defined (__i386))
#define YYSTACK_USE_ALLOCA
#include <alloca.h>
#else /* not sparc */
/* We think this test detects Watcom and Microsoft C.  */
/* This used to test MSDOS, but that is a bad idea
   since that symbol is in the user namespace.  */
#if (defined (_MSDOS) || defined (_MSDOS_)) && !defined (__TURBOC__)
#if 0 /* No need for malloc.h, which pollutes the namespace;
	 instead, just don't use alloca.  */
#include <malloc.h>
#endif
#else /* not MSDOS, or __TURBOC__ */
#if defined(_AIX)
/* I don't know what this was needed for, but it pollutes the namespace.
   So I turned it off.   rms, 2 May 1997.  */
/* #include <malloc.h>  */
 #pragma alloca
#define YYSTACK_USE_ALLOCA
#else /* not MSDOS, or __TURBOC__, or _AIX */
#if 0
#ifdef __hpux /* haible@ilog.fr says this works for HPUX 9.05 and up,
		 and on HPUX 10.  Eventually we can turn this on.  */
#define YYSTACK_USE_ALLOCA
#define alloca __builtin_alloca
#endif /* __hpux */
#endif
#endif /* not _AIX */
#endif /* not MSDOS, or __TURBOC__ */
#endif /* not sparc */
#endif /* not GNU C */
#endif /* alloca not defined */
#endif /* YYSTACK_USE_ALLOCA not defined */

#ifdef YYSTACK_USE_ALLOCA
#define YYSTACK_ALLOC alloca
#else
#define YYSTACK_ALLOC malloc
#endif

/* Note: there must be only one dollar sign in this file.
   It is replaced by the list of actions, each action
   as one case of the switch.  */

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		-2
#define YYEOF		0
#define YYACCEPT	goto yyacceptlab
#define YYABORT 	goto yyabortlab
#define YYERROR		goto yyerrlab1
/* Like YYERROR except do call yyerror.
   This remains here temporarily to ease the
   transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */
#define YYFAIL		goto yyerrlab
#define YYRECOVERING()  (!!yyerrstatus)
#define YYBACKUP(token, value) \
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    { yychar = (token), yylval = (value);			\
      yychar1 = YYTRANSLATE (yychar);				\
      YYPOPSTACK;						\
      goto yybackup;						\
    }								\
  else								\
    { yyerror ("syntax error: cannot back up"); YYERROR; }	\
while (0)

#define YYTERROR	1
#define YYERRCODE	256

#ifndef YYPURE
#define YYLEX		yylex()
#endif

#ifdef YYPURE
#ifdef YYLSP_NEEDED
#ifdef YYLEX_PARAM
#define YYLEX		yylex(&yylval, &yylloc, YYLEX_PARAM)
#else
#define YYLEX		yylex(&yylval, &yylloc)
#endif
#else /* not YYLSP_NEEDED */
#ifdef YYLEX_PARAM
#define YYLEX		yylex(&yylval, YYLEX_PARAM)
#else
#define YYLEX		yylex(&yylval)
#endif
#endif /* not YYLSP_NEEDED */
#endif

/* If nonreentrant, generate the variables here */

#ifndef YYPURE

int	yychar;			/*  the lookahead symbol		*/
YYSTYPE	yylval;			/*  the semantic value of the		*/
				/*  lookahead symbol			*/

#ifdef YYLSP_NEEDED
YYLTYPE yylloc;			/*  location data for the lookahead	*/
				/*  symbol				*/
#endif

int yynerrs;			/*  number of parse errors so far       */
#endif  /* not YYPURE */

#if YYDEBUG != 0
int yydebug;			/*  nonzero means print parse trace	*/
/* Since this is uninitialized, it does not stop multiple parsers
   from coexisting.  */
#endif

/*  YYINITDEPTH indicates the initial size of the parser's stacks	*/

#ifndef	YYINITDEPTH
#define YYINITDEPTH 200
#endif

/*  YYMAXDEPTH is the maximum size the stacks can grow to
    (effective only if the built-in stack extension method is used).  */

#if YYMAXDEPTH == 0
#undef YYMAXDEPTH
#endif

#ifndef YYMAXDEPTH
#define YYMAXDEPTH 10000
#endif

/* Define __yy_memcpy.  Note that the size argument
   should be passed with type unsigned int, because that is what the non-GCC
   definitions require.  With GCC, __builtin_memcpy takes an arg
   of type size_t, but it can handle unsigned int.  */

#if __GNUC__ > 1		/* GNU C and GNU C++ define this.  */
#define __yy_memcpy(TO,FROM,COUNT)	__builtin_memcpy(TO,FROM,COUNT)
#else				/* not GNU C or C++ */
#ifndef __cplusplus

/* This is the most reliable way to avoid incompatibilities
   in available built-in functions on various systems.  */
static void
__yy_memcpy (to, from, count)
     char *to;
     char *from;
     unsigned int count;
{
  register char *f = from;
  register char *t = to;
  register int i = count;

  while (i-- > 0)
    *t++ = *f++;
}

#else /* __cplusplus */

/* This is the most reliable way to avoid incompatibilities
   in available built-in functions on various systems.  */
static void
__yy_memcpy (char *to, char *from, unsigned int count)
{
  register char *t = to;
  register char *f = from;
  register int i = count;

  while (i-- > 0)
    *t++ = *f++;
}

#endif
#endif



/* The user can define YYPARSE_PARAM as the name of an argument to be passed
   into yyparse.  The argument should have type void *.
   It should actually point to an object.
   Grammar actions can access the variable by casting it
   to the proper pointer type.  */

#ifdef YYPARSE_PARAM
#ifdef __cplusplus
#define YYPARSE_PARAM_ARG void *YYPARSE_PARAM
#define YYPARSE_PARAM_DECL
#else /* not __cplusplus */
#define YYPARSE_PARAM_ARG YYPARSE_PARAM
#define YYPARSE_PARAM_DECL void *YYPARSE_PARAM;
#endif /* not __cplusplus */
#else /* not YYPARSE_PARAM */
#define YYPARSE_PARAM_ARG
#define YYPARSE_PARAM_DECL
#endif /* not YYPARSE_PARAM */

/* Prevent warning if -Wstrict-prototypes.  */
#ifdef __GNUC__
#ifdef YYPARSE_PARAM
int yyparse (void *);
#else
int yyparse (void);
#endif
#endif

int
yyparse(YYPARSE_PARAM_ARG)
     YYPARSE_PARAM_DECL
{
  register int yystate;
  register int yyn;
  register short *yyssp;
  register YYSTYPE *yyvsp;
  int yyerrstatus;	/*  number of tokens to shift before error messages enabled */
  int yychar1 = 0;		/*  lookahead token as an internal (translated) token number */

  short	yyssa[YYINITDEPTH];	/*  the state stack			*/
  YYSTYPE yyvsa[YYINITDEPTH];	/*  the semantic value stack		*/

  short *yyss = yyssa;		/*  refer to the stacks thru separate pointers */
  YYSTYPE *yyvs = yyvsa;	/*  to allow yyoverflow to reallocate them elsewhere */

#ifdef YYLSP_NEEDED
  YYLTYPE yylsa[YYINITDEPTH];	/*  the location stack			*/
  YYLTYPE *yyls = yylsa;
  YYLTYPE *yylsp;

#define YYPOPSTACK   (yyvsp--, yyssp--, yylsp--)
#else
#define YYPOPSTACK   (yyvsp--, yyssp--)
#endif

  int yystacksize = YYINITDEPTH;
  int yyfree_stacks = 0;

#ifdef YYPURE
  int yychar;
  YYSTYPE yylval;
  int yynerrs;
#ifdef YYLSP_NEEDED
  YYLTYPE yylloc;
#endif
#endif

  YYSTYPE yyval;		/*  the variable used to return		*/
				/*  semantic values from the action	*/
				/*  routines				*/

  int yylen;

#if YYDEBUG != 0
  if (yydebug)
    fprintf(stderr, "Starting parse\n");
#endif

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss - 1;
  yyvsp = yyvs;
#ifdef YYLSP_NEEDED
  yylsp = yyls;
#endif

/* Push a new state, which is found in  yystate  .  */
/* In all cases, when you get here, the value and location stacks
   have just been pushed. so pushing a state here evens the stacks.  */
yynewstate:

  *++yyssp = yystate;

  if (yyssp >= yyss + yystacksize - 1)
    {
      /* Give user a chance to reallocate the stack */
      /* Use copies of these so that the &'s don't force the real ones into memory. */
      YYSTYPE *yyvs1 = yyvs;
      short *yyss1 = yyss;
#ifdef YYLSP_NEEDED
      YYLTYPE *yyls1 = yyls;
#endif

      /* Get the current used size of the three stacks, in elements.  */
      int size = yyssp - yyss + 1;

#ifdef yyoverflow
      /* Each stack pointer address is followed by the size of
	 the data in use in that stack, in bytes.  */
#ifdef YYLSP_NEEDED
      /* This used to be a conditional around just the two extra args,
	 but that might be undefined if yyoverflow is a macro.  */
      yyoverflow("parser stack overflow",
		 &yyss1, size * sizeof (*yyssp),
		 &yyvs1, size * sizeof (*yyvsp),
		 &yyls1, size * sizeof (*yylsp),
		 &yystacksize);
#else
      yyoverflow("parser stack overflow",
		 &yyss1, size * sizeof (*yyssp),
		 &yyvs1, size * sizeof (*yyvsp),
		 &yystacksize);
#endif

      yyss = yyss1; yyvs = yyvs1;
#ifdef YYLSP_NEEDED
      yyls = yyls1;
#endif
#else /* no yyoverflow */
      /* Extend the stack our own way.  */
      if (yystacksize >= YYMAXDEPTH)
	{
	  yyerror("parser stack overflow");
	  if (yyfree_stacks)
	    {
	      free (yyss);
	      free (yyvs);
#ifdef YYLSP_NEEDED
	      free (yyls);
#endif
	    }
	  return 2;
	}
      yystacksize *= 2;
      if (yystacksize > YYMAXDEPTH)
	yystacksize = YYMAXDEPTH;
#ifndef YYSTACK_USE_ALLOCA
      yyfree_stacks = 1;
#endif
      yyss = (short *) YYSTACK_ALLOC (yystacksize * sizeof (*yyssp));
      __yy_memcpy ((char *)yyss, (char *)yyss1,
		   size * (unsigned int) sizeof (*yyssp));
      yyvs = (YYSTYPE *) YYSTACK_ALLOC (yystacksize * sizeof (*yyvsp));
      __yy_memcpy ((char *)yyvs, (char *)yyvs1,
		   size * (unsigned int) sizeof (*yyvsp));
#ifdef YYLSP_NEEDED
      yyls = (YYLTYPE *) YYSTACK_ALLOC (yystacksize * sizeof (*yylsp));
      __yy_memcpy ((char *)yyls, (char *)yyls1,
		   size * (unsigned int) sizeof (*yylsp));
#endif
#endif /* no yyoverflow */

      yyssp = yyss + size - 1;
      yyvsp = yyvs + size - 1;
#ifdef YYLSP_NEEDED
      yylsp = yyls + size - 1;
#endif

#if YYDEBUG != 0
      if (yydebug)
	fprintf(stderr, "Stack size increased to %d\n", yystacksize);
#endif

      if (yyssp >= yyss + yystacksize - 1)
	YYABORT;
    }

#if YYDEBUG != 0
  if (yydebug)
    fprintf(stderr, "Entering state %d\n", yystate);
#endif

  goto yybackup;
 yybackup:

/* Do appropriate processing given the current state.  */
/* Read a lookahead token if we need one and don't already have one.  */
/* yyresume: */

  /* First try to decide what to do without reference to lookahead token.  */

  yyn = yypact[yystate];
  if (yyn == YYFLAG)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* yychar is either YYEMPTY or YYEOF
     or a valid token in external form.  */

  if (yychar == YYEMPTY)
    {
#if YYDEBUG != 0
      if (yydebug)
	fprintf(stderr, "Reading a token: ");
#endif
      yychar = YYLEX;
    }

  /* Convert token to internal form (in yychar1) for indexing tables with */

  if (yychar <= 0)		/* This means end of input. */
    {
      yychar1 = 0;
      yychar = YYEOF;		/* Don't call YYLEX any more */

#if YYDEBUG != 0
      if (yydebug)
	fprintf(stderr, "Now at end of input.\n");
#endif
    }
  else
    {
      yychar1 = YYTRANSLATE(yychar);

#if YYDEBUG != 0
      if (yydebug)
	{
	  fprintf (stderr, "Next token is %d (%s", yychar, yytname[yychar1]);
	  /* Give the individual parser a way to print the precise meaning
	     of a token, for further debugging info.  */
#ifdef YYPRINT
	  YYPRINT (stderr, yychar, yylval);
#endif
	  fprintf (stderr, ")\n");
	}
#endif
    }

  yyn += yychar1;
  if (yyn < 0 || yyn > YYLAST || yycheck[yyn] != yychar1)
    goto yydefault;

  yyn = yytable[yyn];

  /* yyn is what to do for this token type in this state.
     Negative => reduce, -yyn is rule number.
     Positive => shift, yyn is new state.
       New state is final state => don't bother to shift,
       just return success.
     0, or most negative number => error.  */

  if (yyn < 0)
    {
      if (yyn == YYFLAG)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }
  else if (yyn == 0)
    goto yyerrlab;

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Shift the lookahead token.  */

#if YYDEBUG != 0
  if (yydebug)
    fprintf(stderr, "Shifting token %d (%s), ", yychar, yytname[yychar1]);
#endif

  /* Discard the token being shifted unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  *++yyvsp = yylval;
#ifdef YYLSP_NEEDED
  *++yylsp = yylloc;
#endif

  /* count tokens shifted since error; after three, turn off error status.  */
  if (yyerrstatus) yyerrstatus--;

  yystate = yyn;
  goto yynewstate;

/* Do the default action for the current state.  */
yydefault:

  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;

/* Do a reduction.  yyn is the number of a rule to reduce with.  */
yyreduce:
  yylen = yyr2[yyn];
  if (yylen > 0)
    yyval = yyvsp[1-yylen]; /* implement default value of the action */

#if YYDEBUG != 0
  if (yydebug)
    {
      int i;

      fprintf (stderr, "Reducing via rule %d (line %d), ",
	       yyn, yyrline[yyn]);

      /* Print the symbols being reduced, and their result.  */
      for (i = yyprhs[yyn]; yyrhs[i] > 0; i++)
	fprintf (stderr, "%s ", yytname[yyrhs[i]]);
      fprintf (stderr, " -> %s\n", yytname[yyr1[yyn]]);
    }
#endif


  switch (yyn) {

case 1:
{ 
	#ifdef DEBUG_T
	printf("\n---> From L_DECL:");
	view_table(yyvsp[-2].t);
	printf("\n---> From BLOCK:");
	view_table(yyvsp[-1].t);
	#endif
	int l[] = { 0, 0, 0 };
	yyval.t = test(l, yyvsp[-2].t, yyvsp[-1].t, p_table, 1);
	
	debug_table(yyval.t);
	
	table* p = yyval.t;
	free_table(&p);
	yyval.t = NULL;
;
    break;}
case 2:
{ yyval.t = yyvsp[0].t; DEC_LIST = yyvsp[0].t; ;
    break;}
case 3:
{ yyval.t = yyvsp[0].t; add_table(yyvsp[-3].t->ident, 2, &yyval.t); ;
    break;}
case 4:
{ yyval.t = yyvsp[0].t; add_table(yyvsp[-3].t->ident, 1, &yyval.t); ;
    break;}
case 5:
{ yyval.t = NULL;;
    break;}
case 6:
{ yyval.t = yyvsp[-1].t; ;
    break;}
case 7:
{ int l[] = { 0, 0 }; yyval.t = test(l, yyvsp[-1].t, yyvsp[0].t, p_table, 2); ;
    break;}
case 8:
{ yyval.t = NULL;;
    break;}
case 9:
{ yyval.t = yyvsp[-1].t; ;
    break;}
case 10:
{ yyval.t = yyvsp[-3].t; add_table(yyvsp[-3].t->ident, 4, &yyval.t); ;
    break;}
case 11:
{ yyval.t = yyvsp[-1].t; add_table(yyvsp[-3].t->ident, 3, &yyval.t); ;
    break;}
case 12:
{ yyval.t = yyvsp[0].t; ;
    break;}
case 13:
{ int l[] = { 0, 0 }; yyval.t = test(l, yyvsp[-2].t, yyvsp[0].t, p_table, 2); ;
    break;}
case 14:
{ yyval.t = yyvsp[0].t; ;
    break;}
case 15:
{ int l[] = { 0, 0 }; yyval.t = test(l, yyvsp[-2].t, yyvsp[0].t, p_table, 2); ;
    break;}
case 16:
{ yyval.t = yyvsp[0].t; ;
    break;}
case 17:
{ yyval.t = yyvsp[-1].t; ;
    break;}
case 18:
{ yyval.t = yyvsp[0].t; yyval.t->prop = 3; ;
    break;}
case 19:
{ yyval.t = NULL; ;
    break;}
case 20:
{
	int l[] = { 0, 0, 0 };
	table* first = test(l, yyvsp[-2].t, yyvsp[0].t, p_table, 2);
	yyval.t = test(l, yyvsp[-6].t, first, p_table, 2);
;
    break;}
case 21:
{ yyval.t = yyvsp[0].t; ;
    break;}
case 22:
{ yyval.t = NULL; ;
    break;}
case 23:
{ int l[] = { 0, 0 }; yyval.t = test(l, yyvsp[-2].t, yyvsp[0].t, p_table, 2); ;
    break;}
case 24:
{ yyval.t = yyvsp[0].t; ;
    break;}
case 25:
{ int l[] = { 0, 0 }; yyval.t = test(l, yyvsp[-2].t, yyvsp[0].t, p_table, 2); ;
    break;}
case 26:
{ yyval.t = yyvsp[0].t; ;
    break;}
case 27:
{ yyval.t = yyvsp[-1].t; ;
    break;}
case 28:
{ yyval.t = yyvsp[0].t; yyval.t->prop = 3; ;
    break;}
case 29:
{ yyval.t = NULL; ;
    break;}
case 30:
{ yyval.t = NULL; ;
    break;}
case 31:
{ yyval.t = NULL; ;
    break;}
case 32:
{ yyval.t = NULL; ;
    break;}
case 33:
{ yyval.t = NULL; ;
    break;}
case 34:
{ yyval.t = NULL; ;
    break;}
case 35:
{ yyval.t = NULL; ;
    break;}
case 36:
{ yyval.t = NULL; ;
    break;}
case 37:
{ yyval.t = NULL; ;
    break;}
case 38:
{ yyval.t = NULL; ;
    break;}
case 39:
{ yyval.t = NULL; ;
    break;}
case 40:
{ yyval.t = NULL; ;
    break;}
case 41:
{ yyval.t = NULL; ;
    break;}
case 42:
{ yyval.t = NULL; ;
    break;}
}
   /* the action file gets copied in in place of this dollarsign */


  yyvsp -= yylen;
  yyssp -= yylen;
#ifdef YYLSP_NEEDED
  yylsp -= yylen;
#endif

#if YYDEBUG != 0
  if (yydebug)
    {
      short *ssp1 = yyss - 1;
      fprintf (stderr, "state stack now");
      while (ssp1 != yyssp)
	fprintf (stderr, " %d", *++ssp1);
      fprintf (stderr, "\n");
    }
#endif

  *++yyvsp = yyval;

#ifdef YYLSP_NEEDED
  yylsp++;
  if (yylen == 0)
    {
      yylsp->first_line = yylloc.first_line;
      yylsp->first_column = yylloc.first_column;
      yylsp->last_line = (yylsp-1)->last_line;
      yylsp->last_column = (yylsp-1)->last_column;
      yylsp->text = 0;
    }
  else
    {
      yylsp->last_line = (yylsp+yylen-1)->last_line;
      yylsp->last_column = (yylsp+yylen-1)->last_column;
    }
#endif

  /* Now "shift" the result of the reduction.
     Determine what state that goes to,
     based on the state we popped back to
     and the rule number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTBASE] + *yyssp;
  if (yystate >= 0 && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTBASE];

  goto yynewstate;

yyerrlab:   /* here on detecting error */

  if (! yyerrstatus)
    /* If not already recovering from an error, report this error.  */
    {
      ++yynerrs;

#ifdef YYERROR_VERBOSE
      yyn = yypact[yystate];

      if (yyn > YYFLAG && yyn < YYLAST)
	{
	  int size = 0;
	  char *msg;
	  int x, count;

	  count = 0;
	  /* Start X at -yyn if nec to avoid negative indexes in yycheck.  */
	  for (x = (yyn < 0 ? -yyn : 0);
	       x < (sizeof(yytname) / sizeof(char *)); x++)
	    if (yycheck[x + yyn] == x)
	      size += strlen(yytname[x]) + 15, count++;
	  msg = (char *) malloc(size + 15);
	  if (msg != 0)
	    {
	      strcpy(msg, "parse error");

	      if (count < 5)
		{
		  count = 0;
		  for (x = (yyn < 0 ? -yyn : 0);
		       x < (sizeof(yytname) / sizeof(char *)); x++)
		    if (yycheck[x + yyn] == x)
		      {
			strcat(msg, count == 0 ? ", expecting `" : " or `");
			strcat(msg, yytname[x]);
			strcat(msg, "'");
			count++;
		      }
		}
	      yyerror(msg);
	      free(msg);
	    }
	  else
	    yyerror ("parse error; also virtual memory exceeded");
	}
      else
#endif /* YYERROR_VERBOSE */
	yyerror("parse error");
    }

  goto yyerrlab1;
yyerrlab1:   /* here on error raised explicitly by an action */

  if (yyerrstatus == 3)
    {
      /* if just tried and failed to reuse lookahead token after an error, discard it.  */

      /* return failure if at end of input */
      if (yychar == YYEOF)
	YYABORT;

#if YYDEBUG != 0
      if (yydebug)
	fprintf(stderr, "Discarding token %d (%s).\n", yychar, yytname[yychar1]);
#endif

      yychar = YYEMPTY;
    }

  /* Else will try to reuse lookahead token
     after shifting the error token.  */

  yyerrstatus = 3;		/* Each real token shifted decrements this */

  goto yyerrhandle;

yyerrdefault:  /* current state does not do anything special for the error token. */

#if 0
  /* This is wrong; only states that explicitly want error tokens
     should shift them.  */
  yyn = yydefact[yystate];  /* If its default is to accept any token, ok.  Otherwise pop it.*/
  if (yyn) goto yydefault;
#endif

yyerrpop:   /* pop the current state because it cannot handle the error token */

  if (yyssp == yyss) YYABORT;
  yyvsp--;
  yystate = *--yyssp;
#ifdef YYLSP_NEEDED
  yylsp--;
#endif

#if YYDEBUG != 0
  if (yydebug)
    {
      short *ssp1 = yyss - 1;
      fprintf (stderr, "Error: state stack now");
      while (ssp1 != yyssp)
	fprintf (stderr, " %d", *++ssp1);
      fprintf (stderr, "\n");
    }
#endif

yyerrhandle:

  yyn = yypact[yystate];
  if (yyn == YYFLAG)
    goto yyerrdefault;

  yyn += YYTERROR;
  if (yyn < 0 || yyn > YYLAST || yycheck[yyn] != YYTERROR)
    goto yyerrdefault;

  yyn = yytable[yyn];
  if (yyn < 0)
    {
      if (yyn == YYFLAG)
	goto yyerrpop;
      yyn = -yyn;
      goto yyreduce;
    }
  else if (yyn == 0)
    goto yyerrpop;

  if (yyn == YYFINAL)
    YYACCEPT;

#if YYDEBUG != 0
  if (yydebug)
    fprintf(stderr, "Shifting error token, ");
#endif

  *++yyvsp = yylval;
#ifdef YYLSP_NEEDED
  *++yylsp = yylloc;
#endif

  yystate = yyn;
  goto yynewstate;

 yyacceptlab:
  /* YYACCEPT comes here.  */
  if (yyfree_stacks)
    {
      free (yyss);
      free (yyvs);
#ifdef YYLSP_NEEDED
      free (yyls);
#endif
    }
  return 0;

 yyabortlab:
  /* YYABORT comes here.  */
  if (yyfree_stacks)
    {
      free (yyss);
      free (yyvs);
#ifdef YYLSP_NEEDED
      free (yyls);
#endif
    }
  return 1;
}


int main(int argc, char * argv[])
{
	system("title Syntactic and semantic analysis of Pascal program.");
	#if defined(DEBUG_PT) || defined(DEBUG_T)
	system("mode con: lines=100 cols=100");
	#else
	system("mode con: lines=15 cols=100"); 
	#endif
	line_counter = 1;
	PROP_TAB_FAIL = NULL;
	SEM_ERROR = NULL;
	DEC_LIST = NULL;
	ERROR_MSG = (char*)malloc(sizeof(char*)*MSG_SIZE);
	strcpy(ERROR_MSG, "");
	
	get_prop_table(PROP_TABLE_FILE, &p_table, &count);
	if (!PROP_TAB_FAIL)
	{
		printf("Start program...\n\n \tAnalyze \"%s\"", FILENAME);
		
		yydebug = 0;
		yyin = fopen(FILENAME,"r");
		if (!yyin)
		{
			printf("\n[ERROR] Couldn't open file with table of property grammar.\n");
			system("pause");
		}
		else
		{
			debug_prop_table();

			if (yyparse() == 0) 
			{
				printf("\n\tSyntax parse success.");
				if (!SEM_ERROR) printf("\n\tSemantics parse success.\n");
				else printf(ERROR_MSG);
			}
	
			fclose(yyin);
			printf("\nFinish program...\n");
			free_prop_table(&p_table, count);
			system("pause");
		}
	}
    return 0;
}
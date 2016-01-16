#ifndef _tab
#define _tab
typedef struct Table
{
	char* ident;
	int prop;
	struct Table* next;
} table;
typedef union { table* t; } YYSTYPE;
#endif

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


extern YYSTYPE yylval;

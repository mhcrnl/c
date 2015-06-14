
/* AST Node types */
enum {
	NDOWHILE,
	NFOR,
	NNUMBER
};

/* Token types */
enum {
	TOKNUMBER = 256,
	TOKIDENT,
	TOKIF,
	TOKDO,
	TOKFOR,
	TOKWHILE,
	TOKRETURN,
	TOKEOF,
	TOKINC,
	TOKADDASS,
	TOKDEC,
	TOKSUBASS,
	TOKMULASS,
	TOKDIVASS,
	TOKMODASS,
	TOKGTEQL,
	TOKLTEQL,
	TOKNEQL,
	TOKEQL,
	TOKVOID,
	TOKCHAR,
	TOKINT,
	TOKELSE,
	TOKVOLATILE,
	TOKCONST
};

typedef struct {
	char *file;
	int   line;
	int   col;
} SrcPos;

typedef struct Node Node;

struct Node {
	/* type tag */
	int t;
	SrcPos pos;
	union {
		struct {

		} If;
		struct {
			Node *stmt;
			Node *expr;
		} DoWhile;
		struct {

		} For;
		struct {

		} While;
		struct {

		} Return;
		struct {

		} Block;
		struct {

		} Decl;
		struct {

		} Func;
		struct {

		} Binop;
		struct {

		} Unop;
		struct {
			/* TODO: parse to int */
			char *v;
		} Number;
	};
};

typedef struct {
	/* type tag */
	int t;
	int sclass;
	union {
		struct {

		} Ptr;
		int prim;
	};
} CTy;

typedef struct {
	int   k;
	char *v;
	/* Set if the tok was preceeded by an unescaped newline */
	int newline;
	SrcPos pos;
} Tok;

/* 	Singly linked list.
	A null pointer is the empty list. */
typedef struct List {
	struct List *rest;
	void *v;
} List;

/* helper functions */
void  error(char*, ...);
void  errorpos(SrcPos *, char *, ...);
void *ccmalloc(int);
char *ccstrdup(char*);
/* cpp functions */
char *tokktostr(int);
Tok  *lex(void);
void  cppinit(char *);
/* parser functions */
void  parse(void);
/* backend functions */
void  emit(void);



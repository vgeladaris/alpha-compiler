#ifndef ICODE_H
#define ICODE_H
#include "utilities.h"

#define EXPAND_SIZE 1024
#define CURR_SIZE   (total * sizeof(quad))
#define NEW_SIZE    (EXPAND_SIZE * sizeof(quad) + CURR_SIZE)

typedef enum iopcode {
    assign, add, sub, mul, div_i, mod, uminus, and_i, or_i, not_i,
    if_eq, if_noteq, if_lesseq, if_greatereq, if_less, if_greater,
    jump, call, param, ret, getretval, funcstart, funcend,
    tablecreate, tablegetelem, tablesetelem
}iopcode;

typedef enum expr_t {
    var_e,
    tableitem_e,

    programfunc_e,
    libraryfunc_e,

    arithexpr_e,
    boolexpr_e,
    assignexpr_e,
    newtable_e,
    constnum_e,
    constbool_e,
    conststring_e,

    nil_e,
}expr_t;

typedef struct expr {
    expr_t type;
    symbol* sym;
    int falselist;
    int truelist;
    int returnlist;
    struct expr* index;
    double num_const;
    char* str_const;
    unsigned char bool_const;
    struct expr* next;
}expr;

typedef struct quad {
    iopcode op;
    expr* result;
    expr* arg1;
    expr* arg2;
    unsigned int label;
    unsigned int line;
    unsigned taddress;
}quad;

typedef struct for_stmt {
    int test;
    int enter;
}for_stmt;

struct call {
    expr* elist;
    unsigned method;
    char* name;
};

typedef struct index_elem {
    expr* key;
    expr* value;
    struct index_elem* next;
}index_elem;

typedef struct stmt_t {
    int breaklist;
    int contlist;
}stmt_t;

void expand();

void emit(iopcode op,
          expr* arg1,
          expr* arg2,
          expr* result,
          unsigned int label,
          unsigned int line
        );

int newlist(int i);
int mergelist(int l1, int l2);
void patchlabel(unsigned quadNo, unsigned label);
void patchlist(int list, int label);
expr* lvalue_expr(symbol* sym);
expr* newexpr(expr_t type);
unsigned int istempname(char* s);
unsigned int istempexpr(expr* e);
expr* emit_iftableitem(expr* e);
void check_arith(expr* e, const char* msg);
int is_func(expr* e);
symbol* new_temp();
char* new_temp_name();
void reset_temp();
expr* insert_last(expr* list, expr* node);

#endif /* ICODE_H */

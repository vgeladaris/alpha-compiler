#ifndef MANAGER_H
#define MANAGER_H

#include "utilities.h"
#include "parser.h"
#include "icode.h"

extern unsigned int curr_quad;

typedef struct stack_node {
    int label;
    struct stack_node* prev;
}stack_node;

int yy_alphaerror(const char* message);
expr* manage_lvalue(expr* ex);
expr* manage_global_var(char* id);
expr* manage_var(char *id);
expr* manage_local_var(char *id);
expr* manage_function(char *id);
expr* manage_function_exit();
expr* manage_add(expr* arg1, expr* arg2);
expr* manage_sub(expr* arg1, expr* arg2);
expr* manage_mul(expr* arg1, expr* arg2);
expr* manage_div(expr* arg1, expr* arg2);
expr* manage_mod(expr* arg1, expr* arg2);
expr* manage_uminus(expr* ex);
expr* manage_not(expr* ex);
expr* manage_pre_inc(expr* ex);
expr* manage_post_inc(expr* ex);
expr* manage_pre_dec(expr* ex);
expr* manage_post_dec(expr* ex);
expr* manage_args(char *id);
expr* manage_real(double val);
expr* manage_bool(unsigned char val);
expr* manage_nil();
expr* manage_string(char *val);
expr* manage_number(int val);
expr* manage_assignexpr(expr* lvalue, expr* ex);
unsigned int manage_ifprefix(expr* ex);
void manage_ifstmt(unsigned int qq);
unsigned int manage_elseprefix();
stmt_t* manage_ifelse(unsigned int ifp_quad, unsigned int elsep_quad, stmt_t* if_stmt, stmt_t* else_stmt);
unsigned int manage_whilestart();
unsigned int manage_whilecond(expr* ex);
void manage_whilestmt(unsigned int whilestart_quad, unsigned int whilecond_quad, stmt_t* stmt);
expr* manage_relop(iopcode relop, expr* arg1, expr* arg2);
expr* manage_or(expr* arg1, expr* arg2, int M);
expr* manage_and(expr* arg1, expr* arg2, int M);
void manage_short_circuit(expr* ex);
expr* create_short_circuit_assigns(expr* ex);
expr* manage_member_item(expr* lv, char* name);
expr* manage_array_item(expr* lv, expr* ex);
expr* make_call(expr* lv, expr* reversed_elist);
expr* manage_call_funcdef(expr* funcdef, expr* elist);
struct call* manage_methodcall(char* id, expr* elist);
struct call* manage_normcall(expr* elist);
expr* manage_elist(expr* expr, struct expr* curr_list);
expr* manage_call_lvalue(expr* lvalue, struct call* callsuffix);
expr* manage_tablemake(expr* elist);
index_elem* manage_indexelem(expr* key, expr* value);
index_elem* manage_indexelemlist(index_elem* node, index_elem* list);
expr* manage_mapmake(index_elem* list);
int manage_N();
int manage_M();
for_stmt* manage_forprefix(int M, expr* ex);
void manage_forstmt(for_stmt* prefix, int N1, int N2, stmt_t* st, int N3);
void manage_return(expr* expr);
stmt_t* manage_break();
stmt_t* manage_continue();
stmt_t* manage_stmtlist(stmt_t* stmt_list, stmt_t* stmt);
void print_quads();
char* new_anonymous_function();
#endif /* MANAGER_H */

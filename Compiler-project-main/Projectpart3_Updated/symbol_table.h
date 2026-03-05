#ifndef SYMBOL_TABLE_H
#define SYMBOL_TABLE_H

#include "ast.h"

#define MAX_PARAMS 20 // מספר מקסימלי של פרמטרים
#define MAX_SCOPE_DEPTH 100 // עומק מקסימלי של סקופים

// הגדרת טיפוסי נתונים
typedef enum {
    DT_INT, DT_REAL, DT_CHAR, DT_BOOL,
    DT_STRING, DT_VOID, DT_PTR_INT, DT_PTR_CHAR, DT_PTR_REAL
} DataType;

typedef enum { VAR_SYM, FUNC_SYM } SymbolKind;

// מבנה של סמל
typedef struct Symbol {
    char* name;
    SymbolKind kind;
    DataType type;
    int param_count;
    DataType param_types[MAX_PARAMS]; // מערך של טיפוסי הפרמטרים
    struct Symbol* next;
} Symbol;

// מבנה של טבלת סמלים
typedef struct SymbolTable {
    Symbol* head;
} SymbolTable;

extern SymbolTable* symbol_stack[MAX_SCOPE_DEPTH];
extern int current_scope;
extern int max_scope;
extern int preserve_symbol_tables;

void enter_scope();
void exit_scope();
int count_actual_params_recursive(AST* par_node);
void insert_symbol(char* name, SymbolKind kind, DataType type);
Symbol* lookup_symbol(const char* name);
int symbol_exists_in_current_scope(const char* name);
Symbol* lookup_any_scope(const char* name);
DataType get_type_from_name(const char* type_str);
const char* get_name_from_type(DataType type);
void print_scope_hierarchy();
void print_symbol_tables();
void insert_checked_variable(const char* name, DataType type);
void insert_function_symbol(char* name, DataType type, int param_count);
void insert_function_with_param_types(char* name, DataType type, int param_count, DataType* param_types);
int count_params(AST* args_node);
int count_actual_params(AST* args_node);
void collect_param_types(AST* par_list, DataType* param_types);
void collect_param_types_recursive(AST* node, DataType* param_types, int depth);
DataType get_expr_type(AST* expr);
void check_param_types(char* func_name, AST* args_node);
void get_call_param_types(AST* args_node, DataType* types);
void get_call_param_types_recursive(AST* node, DataType* types, int* index);
void check_return_type(AST* expr, const char* func_name);
void check_boolean_condition(AST* expr, const char* construct_name);
void check_string_index(AST* index_expr);
int is_type_compatible(DataType lhs, DataType rhs);
int is_pointer_type(DataType type);
int can_take_address(DataType type);
DataType get_base_type(DataType ptr_type);
int get_expected_param_number(const char* param_name);
void check_param_order(const char* param_name, int expected_number);
void add_multiple_variables(AST* id_list, DataType type);
int count_params_helper(AST* node);
void add_multiple_variables_with_values(AST* list, DataType type);
void insert_checked_variable_with_value(const char* name, DataType type, const char* value);
void debug_param_ast(AST* node, int depth);  // <-- ADD THIS LINE
void add_multiple_string_arrays(AST* string_list);
void add_multiple_variables_mixed(AST* list, DataType type);




#endif // SYMBOL_TABLE_H
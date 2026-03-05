#ifndef THREE_ADDRESS_CODE_H
#define THREE_ADDRESS_CODE_H

#include "ast.h"
#include "symbol_table.h"

// סוגי הוראות 3AC
typedef enum {
    TAC_ASSIGN,      // x = y
    TAC_BINARY_OP,   // x = y op z
    TAC_UNARY_OP,    // x = op y
    TAC_COPY,        // x = y
    TAC_GOTO,        // goto L
    TAC_IF_GOTO,     // if x relop y goto L
    TAC_LABEL,       // L:
    TAC_PARAM,       // param x
    TAC_CALL,        // x = call f
    TAC_RETURN,      // return x
    TAC_BEGIN_FUNC,  // BeginFunc size
    TAC_END_FUNC,    // EndFunc
    TAC_PUSH_PARAM,  // PushParam x
    TAC_POP_PARAMS,  // PopParams size
    TAC_LCALL        // x = LCall f
} TACType;

// מבנה הוראת 3AC
typedef struct TACInstruction {
    TACType type;
    char* result;    // משתנה יעד
    char* arg1;      // ארגומנט ראשון
    char* arg2;      // ארגומנט שני
    char* op;        // אופרטור
    int label_num;   // מספר תווית
    struct TACInstruction* next;
} TACInstruction;

// רשימת הוראות
typedef struct {
    TACInstruction* head;
    TACInstruction* tail;
} TACList;

// משתנים גלובליים
extern TACList* tac_list;
extern int temp_counter;
extern int label_counter;

// פונקציות
void init_tac();
TACInstruction* create_tac_instruction(TACType type, char* result, char* arg1, char* arg2, char* op);
void add_tac_instruction(TACInstruction* instr);
void generate_tac_from_ast(AST* root);
char* new_temp();
char* new_label();
void print_tac();
void generate_function_tac(AST* func_node);
void generate_statement_tac(AST* stmt);
void generate_expression_tac(AST* expr, char* result);
void generate_if_tac(AST* if_node);
void generate_while_tac(AST* while_node);
void generate_for_tac(AST* for_node);
void generate_assignment_tac(AST* assign_node);
void generate_call_tac(AST* call_node, char* result);
void generate_logical_expression_tac(AST* expr, char* true_label, char* false_label);
void generate_params_tac(AST* param_node);
// הוסף בסוף רשימת הפונקציות:
int calculate_local_var_size(AST* func_node);
int count_local_variables(AST* node);
int count_variables_in_list(AST* var_list);
void find_and_generate_functions(AST* node);

#endif // THREE_ADDRESS_CODE_H

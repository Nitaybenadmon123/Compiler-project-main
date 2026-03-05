#include "three_address_code.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

TACList* tac_list = NULL;
int temp_counter = 0;
int label_counter = 0;

void init_tac() {
    tac_list = malloc(sizeof(TACList));
    tac_list->head = NULL;
    tac_list->tail = NULL;
    temp_counter = 0;
    // אל תאתחל את label_counter כאן!
}

TACInstruction* create_tac_instruction(TACType type, char* result, char* arg1, char* arg2, char* op) {
    TACInstruction* instr = malloc(sizeof(TACInstruction));
    instr->type = type;
    instr->result = result ? strdup(result) : NULL;
    instr->arg1 = arg1 ? strdup(arg1) : NULL;
    instr->arg2 = arg2 ? strdup(arg2) : NULL;
    instr->op = op ? strdup(op) : NULL;
    instr->label_num = -1;
    instr->next = NULL;
    return instr;
}

void add_tac_instruction(TACInstruction* instr) {
    if (!tac_list->head) {
        tac_list->head = tac_list->tail = instr;
    } else {
        tac_list->tail->next = instr;
        tac_list->tail = instr;
    }
}

char* new_temp() {
    char* temp = malloc(10);
    sprintf(temp, "t%d", temp_counter++);
    return temp;
}

char* new_label() {
    char* label = malloc(10);
    sprintf(label, "L%d", label_counter++);
    return label;
}
void generate_tac_from_ast(AST* root) {
    if (!root) return;
    
    init_tac();
    
    // חפש את כל הפונקציות ברקורסיה
    find_and_generate_functions(root);
    
}
// פונקציה עזר חדשה
void find_and_generate_functions(AST* node) {
    if (!node) return;
    
   // printf("DEBUG: Searching in node: '%s' with %d children\n",  node->name ? node->name : "NULL", node->child_count);
    
    if (strcmp(node->name, "FUNCTION") == 0) {
        //printf("DEBUG: Found FUNCTION, generating code\n");
        generate_function_tac(node);
        return;
    }
    
    // חפש בכל הילדים
    for (int i = 0; i < node->child_count; i++) {
        find_and_generate_functions(node->children[i]);
    }
}
void generate_function_tac(AST* func_node) {
    if (!func_node || strcmp(func_node->name, "FUNCTION") != 0) {
        return;
    }
    
    // קבל שם הפונקציה
    char* func_name = func_node->children[0]->name;
    
    // שנה _main_ ל main
    if (strcmp(func_name, "_main_") == 0) {
        func_name = "main";
    }
    
    // הדפס את שם הפונקציה
    printf("%s:\n", func_name);
    
    // יצירת TAC list זמנית לפונקציה הזו
    TACList* temp_list = tac_list;
    tac_list = malloc(sizeof(TACList));
    tac_list->head = NULL;
    tac_list->tail = NULL;
    
    // חשב גודל משתנים מקומיים
    int local_var_size = calculate_local_var_size(func_node);
    
    TACInstruction* begin_func = create_tac_instruction(TAC_BEGIN_FUNC, NULL, NULL, NULL, NULL);
    begin_func->label_num = local_var_size;
    add_tac_instruction(begin_func);
    
    // גנרט קוד לגוף הפונקציה
    AST* body = func_node->children[3]; // BODY
    if (body && body->child_count > 0) {
        generate_statement_tac(body->children[0]);
    }
    
    // EndFunc
    TACInstruction* end_func = create_tac_instruction(TAC_END_FUNC, NULL, NULL, NULL, NULL);
    add_tac_instruction(end_func);
    
    // הדפס את הקוד של הפונקציה הזו מיד
    print_tac();
    
    // שחרר את ה-TAC list הזמנית
    // (אם אתה רוצה לשמור הכל, צרף ל-temp_list)
    free(tac_list);
    tac_list = temp_list;
}

void generate_statement_tac(AST* stmt) {
    if (!stmt) return;
    
    // רקורסיה על ילדים אם זה רשימת statements
    if (strcmp(stmt->name, "") == 0 && stmt->child_count > 1) {
        for (int i = 0; i < stmt->child_count; i++) {
            generate_statement_tac(stmt->children[i]);
        }
        return;
    }
    
    if (strcmp(stmt->name, "=") == 0) {
        generate_assignment_tac(stmt);
    }
    else if (strcmp(stmt->name, "IF") == 0 || strcmp(stmt->name, "IF-ELSE") == 0) {
        generate_if_tac(stmt);
    }
    else if (strcmp(stmt->name, "while2") == 0) {
        generate_while_tac(stmt);
    }
    else if (strcmp(stmt->name, "for") == 0) {
        generate_for_tac(stmt);
    }
    else if (strcmp(stmt->name, "RETURN") == 0) {
        char* return_val = NULL;
        if (stmt->child_count > 0 && strcmp(stmt->children[0]->name, "NONE") != 0) {
            return_val = new_temp();
            generate_expression_tac(stmt->children[0], return_val);
        }
        TACInstruction* ret = create_tac_instruction(TAC_RETURN, NULL, return_val, NULL, NULL);
        add_tac_instruction(ret);
    }
    else if (strcmp(stmt->name, "CALL") == 0) {
        generate_call_tac(stmt, NULL);
    }
    else if (strcmp(stmt->name, "ASSIGN-CALL") == 0) {
        // assignment + call
        char* var_name = stmt->children[0]->name;
        char* temp_result = new_temp();
        generate_call_tac(stmt->children[1], temp_result);
        TACInstruction* assign = create_tac_instruction(TAC_COPY, var_name, temp_result, NULL, NULL);
        add_tac_instruction(assign);
    }
    else if (strcmp(stmt->name, "BLOCK") == 0) {
        if (stmt->child_count > 0) {
            generate_statement_tac(stmt->children[0]);
        }
    }
    else if (strcmp(stmt->name, "VAR") == 0 || strcmp(stmt->name, "VAR_BLOCK") == 0) {
        // טיפול בהצהרות משתנים - דלג על ההצהרות, עבד רק את הקוד
        if (stmt->child_count > 1) {
            generate_statement_tac(stmt->children[1]);
        }
    }
    else if (strcmp(stmt->name, "TYPE") == 0 || strcmp(stmt->name, "TYPE_MULTI") == 0 || strcmp(stmt->name, "DECLS") == 0) {
        // דילוג על הצהרות טיפוסים
        return;
    }
    else {
        // statement אחר - רקורסיה על ילדים
        for (int i = 0; i < stmt->child_count; i++) {
            generate_statement_tac(stmt->children[i]);
        }
    }
}
void generate_assignment_tac(AST* assign_node) {
    if (strcmp(assign_node->name, "=") != 0) return;
    
    char* lhs = assign_node->children[0]->name;
    char* temp_result = new_temp();
    
    generate_expression_tac(assign_node->children[1], temp_result);
    
    TACInstruction* assign = create_tac_instruction(TAC_COPY, lhs, temp_result, NULL, NULL);
    add_tac_instruction(assign);
}

void generate_expression_tac(AST* expr, char* result) {
    if (!expr || !result) return;
    
    if (strcmp(expr->name, "+") == 0 || strcmp(expr->name, "-") == 0 || 
        strcmp(expr->name, "*") == 0 || strcmp(expr->name, "/") == 0) {
        
        char* temp1 = new_temp();
        char* temp2 = new_temp();
        
        generate_expression_tac(expr->children[0], temp1);
        generate_expression_tac(expr->children[1], temp2);
        
        TACInstruction* binop = create_tac_instruction(TAC_BINARY_OP, result, temp1, temp2, expr->name);
        add_tac_instruction(binop);
    }
    else if (strcmp(expr->name, "call") == 0) {
        generate_call_tac(expr, result);
    }
    else {
        // משתנה או קבוע
        TACInstruction* copy = create_tac_instruction(TAC_COPY, result, expr->name, NULL, NULL);
        add_tac_instruction(copy);
    }
}

void generate_if_tac(AST* if_node) {
    char* true_label = new_label();   // L1 - אם התנאי נכון
    char* false_label = new_label();  // L2 - אם התנאי לא נכון  
    char* end_label = NULL;
    
    if (strcmp(if_node->name, "IF-ELSE") == 0) {
        end_label = new_label();      // L3 - סוף הבלוק
    }
    
    AST* condition = if_node->children[0];
    
    // במקום לקרוא לפונקציה עם true_label, נעשה את זה בצורה פשוטה יותר:
    if (strcmp(condition->name, "==") == 0 || strcmp(condition->name, "!=") == 0 ||
        strcmp(condition->name, "<") == 0 || strcmp(condition->name, ">") == 0 ||
        strcmp(condition->name, "<=") == 0 || strcmp(condition->name, ">=") == 0) {
        
        char* temp1 = new_temp();
        char* temp2 = new_temp();
        
        generate_expression_tac(condition->children[0], temp1);
        generate_expression_tac(condition->children[1], temp2);
        
        // יצירת התנאי: אם התנאי נכון, קפוץ ל-true_label
        TACInstruction* if_stmt = create_tac_instruction(TAC_IF_GOTO, NULL, temp1, temp2, condition->name);
        if_stmt->label_num = atoi(true_label + 1); // חלץ מספר מ-"L1"
        add_tac_instruction(if_stmt);
    } else {
        // תנאי פשוט (משתנה או קבוע)
        char* temp = new_temp();
        generate_expression_tac(condition, temp);
        
        TACInstruction* if_stmt = create_tac_instruction(TAC_IF_GOTO, NULL, temp, "0", "!=");
        if_stmt->label_num = atoi(true_label + 1);
        add_tac_instruction(if_stmt);
    }
    
    // אם התנאי לא נכון, קפוץ ל-false_label
    TACInstruction* goto_false = create_tac_instruction(TAC_GOTO, NULL, false_label, NULL, NULL);
    add_tac_instruction(goto_false);
    
    // תווית true_label - כאן מתחיל הבלוק של if
    TACInstruction* true_lbl = create_tac_instruction(TAC_LABEL, NULL, true_label, NULL, NULL);
    add_tac_instruction(true_lbl);
    
    // גוף הבלוק של if
    generate_statement_tac(if_node->children[1]);
    
    if (strcmp(if_node->name, "IF-ELSE") == 0) {
        // יש else - קפוץ לסוף
        TACInstruction* goto_end = create_tac_instruction(TAC_GOTO, NULL, end_label, NULL, NULL);
        add_tac_instruction(goto_end);
        
        // תווית false_label - כאן מתחיל הבלוק של else
        TACInstruction* false_lbl = create_tac_instruction(TAC_LABEL, NULL, false_label, NULL, NULL);
        add_tac_instruction(false_lbl);
        
        // גוף הבלוק של else
        generate_statement_tac(if_node->children[2]);
        
        // תווית סוף
        TACInstruction* end_lbl = create_tac_instruction(TAC_LABEL, NULL, end_label, NULL, NULL);
        add_tac_instruction(end_lbl);
    } else {
        // אין else - false_label הוא הסוף
        TACInstruction* false_lbl = create_tac_instruction(TAC_LABEL, NULL, false_label, NULL, NULL);
        add_tac_instruction(false_lbl);
    }
}

void generate_while_tac(AST* while_node) {
    char* loop_label = new_label();    // L4
    char* true_label = new_label();    // L5  
    char* end_label = new_label();     // L6
    
    // תווית התחלת לולאה
    TACInstruction* loop_lbl = create_tac_instruction(TAC_LABEL, NULL, loop_label, NULL, NULL);
    add_tac_instruction(loop_lbl);
    
    // תנאי
    AST* condition = while_node->children[0];
    
    if (strcmp(condition->name, "==") == 0 || strcmp(condition->name, "!=") == 0 ||
        strcmp(condition->name, "<") == 0 || strcmp(condition->name, ">") == 0 ||
        strcmp(condition->name, "<=") == 0 || strcmp(condition->name, ">=") == 0) {
        
        char* temp1 = new_temp();
        char* temp2 = new_temp();
        
        generate_expression_tac(condition->children[0], temp1);
        generate_expression_tac(condition->children[1], temp2);
        
        // אם התנאי נכון, קפוץ לגוף הלולאה
        TACInstruction* if_stmt = create_tac_instruction(TAC_IF_GOTO, NULL, temp1, temp2, condition->name);
        if_stmt->label_num = atoi(true_label + 1);
        add_tac_instruction(if_stmt);
    }
    
    // אם התנאי לא נכון, קפוץ לסוף
    TACInstruction* goto_end = create_tac_instruction(TAC_GOTO, NULL, end_label, NULL, NULL);
    add_tac_instruction(goto_end);
    
    // תווית גוף הלולאה
    TACInstruction* true_lbl = create_tac_instruction(TAC_LABEL, NULL, true_label, NULL, NULL);
    add_tac_instruction(true_lbl);
    
    // גוף הלולאה
    generate_statement_tac(while_node->children[1]);
    
    // חזרה להתחלה
    TACInstruction* goto_loop = create_tac_instruction(TAC_GOTO, NULL, loop_label, NULL, NULL);
    add_tac_instruction(goto_loop);
    
    // תווית סוף
    TACInstruction* end_lbl = create_tac_instruction(TAC_LABEL, NULL, end_label, NULL, NULL);
    add_tac_instruction(end_lbl);
}
void generate_for_tac(AST* for_node) {
    char* loop_label = new_label();
    char* end_label = new_label();
    
    // initialization
    generate_statement_tac(for_node->children[0]);
    
    // תווית התחלת לולאה
    TACInstruction* loop_lbl = create_tac_instruction(TAC_LABEL, NULL, loop_label, NULL, NULL);
    add_tac_instruction(loop_lbl);
    
    // תנאי
    generate_logical_expression_tac(for_node->children[1], NULL, end_label);
    
    // גוף הלולאה
    generate_statement_tac(for_node->children[3]);
    
    // update
    generate_statement_tac(for_node->children[2]);
    
    // חזרה להתחלה
    TACInstruction* goto_loop = create_tac_instruction(TAC_GOTO, NULL, loop_label, NULL, NULL);
    add_tac_instruction(goto_loop);
    
    // תווית סוף
    TACInstruction* end_lbl = create_tac_instruction(TAC_LABEL, NULL, end_label, NULL, NULL);
    add_tac_instruction(end_lbl);
}
void generate_params_tac(AST* param_node) {
    if (!param_node) return;
    
    if (strcmp(param_node->name, "par") == 0) {
        if (param_node->child_count == 2) {
            // רקורסיה על פרמטרים נוספים
            generate_params_tac(param_node->children[0]);
            
            // עבד את הפרמטר הנוכחי
            char* temp_param = new_temp();
            generate_expression_tac(param_node->children[1], temp_param);
            TACInstruction* push = create_tac_instruction(TAC_PUSH_PARAM, NULL, temp_param, NULL, NULL);
            add_tac_instruction(push);
        } else if (param_node->child_count == 1) {
            // פרמטר יחיד
            char* temp_param = new_temp();
            generate_expression_tac(param_node->children[0], temp_param);
            TACInstruction* push = create_tac_instruction(TAC_PUSH_PARAM, NULL, temp_param, NULL, NULL);
            add_tac_instruction(push);
        }
    } else {
        // ביטוי פשוט
        char* temp_param = new_temp();
        generate_expression_tac(param_node, temp_param);
        TACInstruction* push = create_tac_instruction(TAC_PUSH_PARAM, NULL, temp_param, NULL, NULL);
        add_tac_instruction(push);
    }
}

void generate_call_tac(AST* call_node, char* result) {
    char* func_name = call_node->children[0]->name;
    
    // טיפול בפרמטרים
    if (call_node->child_count > 1) {
        AST* args = call_node->children[1];
        
        if (strcmp(args->name, "args") == 0 && args->child_count > 0) {
            AST* param_list = args->children[0];
            if (strcmp(param_list->name, "none") != 0) {
                // עבור על כל הפרמטרים
                generate_params_tac(param_list);
            }
        }
    }
    
    // Call
    if (result) {
        TACInstruction* call = create_tac_instruction(TAC_LCALL, result, func_name, NULL, NULL);
        add_tac_instruction(call);
    } else {
        TACInstruction* call = create_tac_instruction(TAC_LCALL, NULL, func_name, NULL, NULL);
        add_tac_instruction(call);
    }
    
    // Pop parameters - חשב גודל (4 bytes לכל פרמטר)
    TACInstruction* pop = create_tac_instruction(TAC_POP_PARAMS, NULL, NULL, NULL, NULL);
    pop->label_num = 8; // 8 bytes לפרמטר real אחד
    add_tac_instruction(pop);
}
void generate_logical_expression_tac(AST* expr, char* true_label, char* false_label) {
    if (!expr) return;
    
    if (strcmp(expr->name, "==") == 0 || strcmp(expr->name, "!=") == 0 ||
        strcmp(expr->name, "<") == 0 || strcmp(expr->name, ">") == 0 ||
        strcmp(expr->name, "<=") == 0 || strcmp(expr->name, ">=") == 0) {
        
        char* temp1 = new_temp();
        char* temp2 = new_temp();
        
        generate_expression_tac(expr->children[0], temp1);
        generate_expression_tac(expr->children[1], temp2);
        
        char* target_label = false_label ? false_label : new_label();
        
        TACInstruction* if_stmt = create_tac_instruction(TAC_IF_GOTO, NULL, temp1, temp2, expr->name);
        if_stmt->label_num = label_counter - 1; // השתמש בתווית שזה עתה נוצרה
        add_tac_instruction(if_stmt);
        
        if (!false_label) {
            TACInstruction* goto_stmt = create_tac_instruction(TAC_GOTO, NULL, target_label, NULL, NULL);
            add_tac_instruction(goto_stmt);
        }
    }
    else if (strcmp(expr->name, "and") == 0) {
        // Short circuit evaluation
        char* mid_label = new_label();
        generate_logical_expression_tac(expr->children[0], mid_label, false_label);
        TACInstruction* mid_lbl = create_tac_instruction(TAC_LABEL, NULL, mid_label, NULL, NULL);
        add_tac_instruction(mid_lbl);
        generate_logical_expression_tac(expr->children[1], true_label, false_label);
    }
    else if (strcmp(expr->name, "or") == 0) {
        // Short circuit evaluation
        char* mid_label = new_label();
        generate_logical_expression_tac(expr->children[0], true_label, mid_label);
        TACInstruction* mid_lbl = create_tac_instruction(TAC_LABEL, NULL, mid_label, NULL, NULL);
        add_tac_instruction(mid_lbl);
        generate_logical_expression_tac(expr->children[1], true_label, false_label);
    }
    else {
        // ביטוי פשוט
        char* temp = new_temp();
        generate_expression_tac(expr, temp);
        
        char* target_label = false_label ? false_label : new_label();
        TACInstruction* if_stmt = create_tac_instruction(TAC_IF_GOTO, NULL, temp, "0", "==");
        if_stmt->label_num = label_counter - 1;
        add_tac_instruction(if_stmt);
    }
}
void print_tac() {
    TACInstruction* current = tac_list->head;
    
    while (current) {
        switch (current->type) {
            case TAC_BEGIN_FUNC:
                printf("BeginFunc %d\n", current->label_num);
                break;
            case TAC_END_FUNC:
                printf("EndFunc\n");
                break;
            case TAC_COPY:
                printf("%s = %s\n", current->result, current->arg1);
                break;
            case TAC_BINARY_OP:
                printf("%s = %s %s %s\n", current->result, current->arg1, current->op, current->arg2);
                break;
            case TAC_IF_GOTO:
                printf("if %s %s %s Goto L%d\n", current->arg1, current->op, current->arg2, current->label_num);
                break;
            case TAC_GOTO:
                printf("goto %s\n", current->arg1);
                break;
            case TAC_LABEL:
                printf("%s: ", current->arg1);  // רק התווית, בלי Return
                break;
            case TAC_RETURN:
                if (current->arg1) {
                    printf("Return %s\n", current->arg1);
                } else {
                    printf("Return\n");
                }
                break;
            case TAC_PUSH_PARAM:
                printf("PushParam %s\n", current->arg1);
                break;
            case TAC_LCALL:
                if (current->result) {
                    printf("%s = LCall %s\n", current->result, current->arg1);
                } else {
                    printf("LCall %s\n", current->arg1);
                }
                break;
            case TAC_POP_PARAMS:
                printf("PopParams %d\n", current->label_num);
                break;
            default:
                break;
        }
        current = current->next;
    }
}
int count_variables_in_list(AST* var_list) {
    if (!var_list) return 0;
    
    int count = 0;
    
    
    // אם זה רשימה עם פסיק (a,b,c)
    if (strcmp(var_list->name, "") == 0 && var_list->child_count == 2) {
        count += count_variables_in_list(var_list->children[0]);
        count += 1; // המשתנה הנוכחי
    } else {
        count = 1; // משתנה יחיד
    }
    
    return count;
}

int count_local_variables(AST* node) {
    if (!node) return 0;
    
    int count = 0;
    
    
    // אם זה הצהרת משתנה
    if (strcmp(node->name, "TYPE_MULTI") == 0) {
        // ספור כמה משתנים בהצהרה (a,b = 2 משתנים)
        AST* var_list = node->children[1];
        int vars_in_decl = count_variables_in_list(var_list);
        count += vars_in_decl;
    } 
    else if (strcmp(node->name, "TYPE") == 0) {
        count = 1;
    }
    
    // רקורסיה על ילדים
    for (int i = 0; i < node->child_count; i++) {
        count += count_local_variables(node->children[i]);
    }
    
    return count;
}

int calculate_local_var_size(AST* func_node) {
    int var_count = 0;
    
    // ספור פרמטרים
    AST* params = func_node->children[1]; // ARGS
    if (params && params->child_count > 0 && strcmp(params->children[0]->name, "NONE") != 0) {
        var_count += count_params(params);
    }
    
    // ספור משתנים מקומיים בגוף הפונקציה
    AST* body = func_node->children[3]; // BODY
    if (body) {
        int local_vars = count_local_variables(body);
        var_count += local_vars;
    }
    
    
    int base_size = (strcmp(func_node->children[0]->name, "_main_") == 0) ? 20 : 12;
    int total_size = base_size + (var_count * 4);
    
    return total_size;
}
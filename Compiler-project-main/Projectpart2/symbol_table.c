#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "symbol_table.h"
#include "ast.h"

SymbolTable* symbol_stack[MAX_SCOPE_DEPTH];
int current_scope = -1;
int max_scope = -1;
int preserve_symbol_tables = 0;  

void yyerror(const char* s);

void enter_scope() {
    current_scope++;
    if (current_scope > max_scope)
        max_scope = current_scope;

    symbol_stack[current_scope] = malloc(sizeof(SymbolTable));
    symbol_stack[current_scope]->head = NULL;
    printf("DEBUG: ENTERED scope %d (from scope %d)\n", current_scope, current_scope - 1);
}

void exit_scope() {
    printf("DEBUG: EXITING scope %d (back to scope %d)\n", current_scope, current_scope - 1);
    current_scope--;
}
void insert_symbol(char* name, SymbolKind kind, DataType type) {
    Symbol* new_sym = malloc(sizeof(Symbol));
    new_sym->name = strdup(name);
    new_sym->kind = kind;
    new_sym->type = type;
    new_sym->param_count = 0; 
    new_sym->next = symbol_stack[current_scope]->head;
    symbol_stack[current_scope]->head = new_sym;
}

int symbol_exists_in_current_scope(const char* name) {
    Symbol* s = symbol_stack[current_scope]->head;
    while (s) {
        if (strcmp(s->name, name) == 0)
            return 1;
        s = s->next;
    }
    return 0;
}

Symbol* lookup_symbol(const char* name) {
    for (int i = current_scope; i >= 0; i--) {
        Symbol* s = symbol_stack[i]->head;
        while (s) {
            if (strcmp(s->name, name) == 0)
                return s;
            s = s->next;
        }
    }
    return NULL;
}
void add_multiple_string_arrays(AST* string_list) {
    if (!string_list) return;

    // אם זה רשימה עם שני ילדים (רקורסיה)
    if (string_list->name && strcmp(string_list->name, "") == 0 && string_list->child_count == 2) {
        // עבד על הרשימה הקודמת
        add_multiple_string_arrays(string_list->children[0]);
        
        // עבד על האלמנט הנוכחי
        AST* current = string_list->children[1];
        if (current && current->name && current->child_count == 1) {
            int size = atoi(current->children[0]->name);
            if (size <= 0) {
                char error_msg[100];
                sprintf(error_msg, "Semantic Error: String size must be positive for '%s'", current->name);
                yyerror(error_msg);
            }
            insert_checked_variable(current->name, DT_STRING);
        }
    }
    // אלמנט יחיד
    else if (string_list->name && string_list->child_count == 1) {
        int size = atoi(string_list->children[0]->name);
        if (size <= 0) {
            char error_msg[100];
            sprintf(error_msg, "Semantic Error: String size must be positive for '%s'", string_list->name);
            yyerror(error_msg);
        }
        insert_checked_variable(string_list->name, DT_STRING);
    }
}
void add_multiple_variables_mixed(AST* list, DataType type) {
    if (!list) return;

    // אם זה רשימה עם שני ילדים (רקורסיה)
    if (list->name && strcmp(list->name, "") == 0 && list->child_count == 2) {
        // עבד על הרשימה הקודמת
        add_multiple_variables_mixed(list->children[0], type);
        
        // עבד על האלמנט הנוכחי
        AST* current = list->children[1];
        if (current && current->name) {
            // בדוק אם יש ערך התחלה
            if (current->child_count == 1) {
                // משתנה עם ערך התחלה
                const char* name = current->name;
                const char* value = current->children[0]->name;
                insert_checked_variable_with_value(name, type, value);
            } else {
                // משתנה ללא ערך התחלה
                insert_checked_variable(current->name, type);
            }
        }
    }
    // אלמנט יחיד
    else if (list->name) {
        if (list->child_count == 1) {
            // משתנה עם ערך התחלה
            const char* name = list->name;
            const char* value = list->children[0]->name;
            insert_checked_variable_with_value(name, type, value);
        } else {
            // משתנה ללא ערך התחלה
            insert_checked_variable(list->name, type);
        }
    }
}
DataType get_type_from_name(const char* type_str) {
    if (strcmp(type_str, "int") == 0) return DT_INT;
    if (strcmp(type_str, "real") == 0) return DT_REAL;
    if (strcmp(type_str, "char") == 0) return DT_CHAR;
    if (strcmp(type_str, "bool") == 0) return DT_BOOL;
    if (strcmp(type_str, "string") == 0) return DT_STRING;
    if (strcmp(type_str, "void") == 0) return DT_VOID;
    if (strcmp(type_str, "int*") == 0) return DT_PTR_INT;
    if (strcmp(type_str, "char*") == 0) return DT_PTR_CHAR;
    if (strcmp(type_str, "real*") == 0) return DT_PTR_REAL;
    return DT_INT; 
}

const char* get_name_from_type(DataType type) {
    switch (type) {
        case DT_INT: return "int";
        case DT_REAL: return "real";
        case DT_CHAR: return "char";
        case DT_BOOL: return "bool";
        case DT_STRING: return "string";
        case DT_VOID: return "void";
        case DT_PTR_INT: return "int*";
        case DT_PTR_CHAR: return "char*";
        case DT_PTR_REAL: return "real*";
        default: return "unknown";
    }
}

Symbol* lookup_any_scope(const char* name) {
    for (int i = current_scope; i >= 0; i--) {
        Symbol* s = symbol_stack[i]->head;
        while (s) {
            if (strcmp(s->name, name) == 0)
                return s;
            s = s->next;
        }
    }
    return NULL;
}

void print_scope_hierarchy() {
    printf("\n--- Scope Stack (top-down) ---\n");
    for (int i = current_scope; i >= 0; i--) {
        printf("Scope %d\n", i);
    }
    printf("------------------------------\n");
}

void print_symbol_tables() {
    printf("\n===== SYMBOL TABLES (with empty scopes) =====\n");
    for (int i = 0; i <= max_scope; i++) {
        printf("Scope %d:\n", i);
        Symbol* s = symbol_stack[i] ? symbol_stack[i]->head : NULL;
        if (!s) {
            printf("  (empty)\n");
            continue;
        }
        while (s) {
            const char* kind_str = (s->kind == FUNC_SYM) ? "Function" : "Variable";
            const char* type_str = get_name_from_type(s->type);
            printf("  Name: %-10s | Kind: %-8s | Type: %s\n", s->name, kind_str, type_str);
            s = s->next;
        }
    }
    printf("=======================================\n");
}

void insert_checked_variable(const char* name, DataType type) {
    printf("DEBUG: Trying to insert variable '%s' in scope %d\n", name, current_scope);
    
    // Let's also see what's currently in this scope
    printf("DEBUG: Current scope %d contents:\n", current_scope);
    if (symbol_stack[current_scope] && symbol_stack[current_scope]->head) {
        Symbol* s = symbol_stack[current_scope]->head;
        while (s) {
            printf("  - %s (%s)\n", s->name, s->kind == VAR_SYM ? "variable" : "function");
            s = s->next;
        }
    } else {
        printf("  (empty)\n");
    }
    
    if (symbol_exists_in_current_scope(name)) {
        printf("DEBUG: Variable '%s' already exists in scope %d\n", name, current_scope);
        char error_msg[100];
        sprintf(error_msg, "Semantic Error: Var '%s' already defined in this block", name);
        yyerror(error_msg);
    } else {
        insert_symbol((char*)name, VAR_SYM, type);
        printf("DEBUG: Successfully inserted '%s' as var in scope %d\n", name, current_scope);
    }
}

// גרסה דומה ל־insert_checked_variable עבור פונקציות
void insert_function_symbol(char* name, DataType type, int param_count) {
        // קודם בודקים כפילות באותו סקופ בלבד
       if (symbol_exists_in_current_scope(name)) {
            char err[128];
            sprintf(err, "Semantic Error: Function '%s' already defined in this block", name);
           yyerror(err);
            return;
        }
       // אם אין כפילות, מוסיפים
        Symbol* new_sym = malloc(sizeof(Symbol));
        new_sym->name = strdup(name);
        new_sym->kind = FUNC_SYM;
        new_sym->type = type;
        new_sym->param_count = param_count;
        new_sym->next = symbol_stack[current_scope]->head;
        symbol_stack[current_scope]->head = new_sym;
        printf("  Inserted function '%s' with %d parameters in scope %d\n",
               name, param_count, current_scope);
    }

int count_params(AST* args_node) {
    if (!args_node || args_node->child_count == 0)
        return 0;

    AST* list = args_node->children[0];
    if (!list || strcmp(list->name, "NONE") == 0)
        return 0;
    
    //printf("DEBUG: Parameter list node name: '%s', child_count: %d\n", list->name ? list->name : "(null)", list->child_count);
    

    if (list->name && strncmp(list->name, "par", 3) == 0) {
        //printf("DEBUG: Single parameter case detected: %s\n", list->name);
        return 1;
    }


    if (strcmp(list->name, "") == 0 && list->child_count == 1) {
        printf("DEBUG: Empty node with one child - likely single parameter\n");
        return 1;
    }

 
    if (strcmp(list->name, "") == 0) {
       
        if (list->child_count == 2) {
            
            int count = 0;
            AST* current = list;
            
            while (current && strcmp(current->name, "") == 0 && current->child_count == 2) {
                count++;  
                current = current->children[0];  
            }
            
            
            if (current && current->child_count > 0) {
                count++;
            }
            
            
            return count;
        }
   
        else {
            int count = 0;
            for (int i = 0; i < list->child_count; i++) {
                if (list->children[i]) {
                    count++;
                    printf("DEBUG: Counted child %d\n", i);
                }
            }
            printf("DEBUG: Flat list structure detected with %d parameters\n", count);
            return count;
        }
    }
    
   
    printf("DEBUG: Defaulting to 1 parameter\n");
    return 1;
}


int count_params_helper(AST* node) {
    if (!node) return 0;
    
  
    if (strcmp(node->name, "") != 0) {
        return 1;
    }
    
  
    if (node->child_count == 2) {
        return 1 + count_params_helper(node->children[0]);
    }
    
    
    if (node->child_count == 3) {
        return 1;
    }
    
    return 0;
}

int count_actual_params(AST* args_node) {
    if (!args_node || strcmp(args_node->name, "args") != 0)
        return 0;

    AST* par_node = args_node->children[0];
    if (!par_node || strcmp(par_node->name, "none") == 0)
        return 0;


    return count_actual_params_recursive(par_node);
}


int count_actual_params_recursive(AST* node) {
    if (!node) return 0;
    

    if (strcmp(node->name, "par") == 0 && node->child_count == 2) {
        return 1 + count_actual_params_recursive(node->children[0]);
    }
    

    if (strcmp(node->name, "par") == 0 && node->child_count == 1) {
        return 1;
    }
    

    return 1;
}
void insert_function_with_param_types(char* name, DataType type, int param_count, DataType* param_types) {

    if (symbol_exists_in_current_scope(name)) {
        char err[128];
        sprintf(err, "Semantic Error: Function '%s' already defined in this block", name);
        yyerror(err);
        return;
    }

    Symbol* new_sym = malloc(sizeof(Symbol));
    new_sym->name = strdup(name);
    new_sym->kind = FUNC_SYM;
    new_sym->type = type;
    new_sym->param_count = param_count;
    
    for (int i = 0; i < param_count && i < MAX_PARAMS; i++) {
        new_sym->param_types[i] = param_types[i];
    }
    
    new_sym->next = symbol_stack[current_scope]->head;
    symbol_stack[current_scope]->head = new_sym;
    
    printf("  Inserted function '%s' with %d parameters in scope %d\n", 
           name, param_count, current_scope);
    
    if (param_count > 0) {
        printf("  Parameter types: ");
        for (int i = 0; i < param_count; i++) {
            printf("%s", get_name_from_type(param_types[i]));
            if (i < param_count - 1) printf(", ");
        }
        printf("\n");
    }
}
void collect_param_types(AST* par_list, DataType* param_types) {
    if (!par_list || strcmp(par_list->name, "ARGS") != 0 || par_list->child_count == 0)
        return;
    
    AST* list = par_list->children[0];
    if (!list || strcmp(list->name, "NONE") == 0)
        return;
    
    printf("DEBUG: ===== DEBUGGING PARAMETER AST STRUCTURE =====\n");
    debug_param_ast(par_list, 0);
    printf("DEBUG: ===============================================\n");
    
    printf("DEBUG: Collecting param types, list node: '%s', child_count: %d\n", 
           list->name ? list->name : "(null)", list->child_count);
    
    // Handle single parameter case
    if (list->name && strncmp(list->name, "par", 3) == 0) {
        if (list->child_count >= 2 && list->children[0]) {
            param_types[0] = get_type_from_name(list->children[0]->name);
            printf("DEBUG: Collected single parameter type: %s\n", 
                   get_name_from_type(param_types[0]));
        }
        return;
    }
    
    // Handle multiple parameters
    if (strcmp(list->name, "") == 0) {
        printf("DEBUG: Multiple parameters detected\n");
        
        collect_param_types_recursive(list, param_types, 0);  // Pass param_types directly
        return;
    }
    
    printf("DEBUG: Using fallback approach\n");
    collect_param_types_recursive(list, param_types, 0);
}

// Update the recursive function to use correct indexing:
void collect_param_types_recursive(AST* node, DataType* param_types, int depth) {
    if (!node) return;
    
    printf("DEBUG: Recursive type extraction from node '%s' with %d children (depth=%d)\n", 
           node->name ? node->name : "(null)", node->child_count, depth);
    
    // Check if this is a parameter node like 'par1' or 'par2'
    if (node->name && strncmp(node->name, "par", 3) == 0 && node->child_count >= 2) {
        // Extract parameter number from name (par1 -> 1, par2 -> 2)
        int param_num = atoi(node->name + 3) - 1;  // Convert to 0-based index
        
        char* type_name = node->children[0]->name;
        printf("DEBUG: Found parameter node '%s' (index %d) with type '%s'\n", 
               node->name, param_num, type_name);
        
        if (param_num >= 0 && param_num < MAX_PARAMS) {
            param_types[param_num] = get_type_from_name(type_name);
            printf("DEBUG: Set param_types[%d] = %s\n", 
                   param_num, get_name_from_type(param_types[param_num]));
        }
        return;
    }
    
    // Handle recursive parameter lists (empty node with 2 children)
    if (strcmp(node->name, "") == 0 && node->child_count == 2) {
        // Process both children
        collect_param_types_recursive(node->children[0], param_types, depth + 1);
        collect_param_types_recursive(node->children[1], param_types, depth + 1);
        return;
    }
    
    // Handle other structures by recursively processing children
    for (int i = 0; i < node->child_count; i++) {
        collect_param_types_recursive(node->children[i], param_types, depth + 1);
    }
}
DataType get_expr_type(AST* expr) {
    if (!expr)
        return DT_VOID;

    // כתובת של משתנה
    if (expr->name && strcmp(expr->name, "&") == 0 && expr->child_count == 1) {
        DataType operand_type = get_expr_type(expr->children[0]);
        switch (operand_type) {
            case DT_INT: return DT_PTR_INT;
            case DT_CHAR: return DT_PTR_CHAR;
            case DT_REAL: return DT_PTR_REAL;
            default: return DT_VOID;
        }
    }

    // dereference של מצביע
    if (expr->name && strcmp(expr->name, "*") == 0 && expr->child_count == 1) {
        DataType operand_type = get_expr_type(expr->children[0]);
        switch (operand_type) {
            case DT_PTR_INT: return DT_INT;
            case DT_PTR_CHAR: return DT_CHAR;
            case DT_PTR_REAL: return DT_REAL;
            default: return DT_VOID;
        }
    }

    // גישה לתא במחרוזת
    if (expr->name && strcmp(expr->name, "array_access") == 0) {
        return DT_CHAR;
    }
    if (expr->name && strcmp(expr->name, "string_length") == 0) {
        return DT_INT;  // אורך מחרוזת תמיד מחזיר int
    }
    // ליטרלים
    if (expr->name && expr->name[0] == '\'') return DT_CHAR;
    if (expr->name && expr->name[0] == '"') return DT_STRING;

    // ערכים בוליאניים
    if (expr->name && (
        strcmp(expr->name, "true") == 0 || strcmp(expr->name, "false") == 0 ||
        strcmp(expr->name, "TRUE") == 0 || strcmp(expr->name, "FALSE") == 0))
        return DT_BOOL;

    // nullptr
    if (expr->name && strcmp(expr->name, "nullptr") == 0)
        return DT_PTR_INT;

    // ביטויים בוליאניים
    if (expr->name && (
        strcmp(expr->name, "and") == 0 || strcmp(expr->name, "or") == 0 || strcmp(expr->name, "not") == 0 ||
        strcmp(expr->name, "==") == 0 || strcmp(expr->name, "!=") == 0 ||
        strcmp(expr->name, "<") == 0 || strcmp(expr->name, ">") == 0 ||
        strcmp(expr->name, "<=") == 0 || strcmp(expr->name, ">=") == 0))
        return DT_BOOL;

    // קריאה לפונקציה
    if (expr->name && strcmp(expr->name, "call") == 0 && expr->child_count >= 1) {
        AST* func_node = expr->children[0];  // שם הפונקציה
        if (func_node && func_node->name) {
            Symbol* sym = lookup_symbol(func_node->name);
            if (sym) return sym->type;
            yyerror("Semantic Error: Function in call not found in symbol table");
            return DT_VOID;
        }
    }

    // אם זה מזהה (שם של משתנה או קבוע)
    if (expr->name) {
        Symbol* sym = lookup_any_scope(expr->name);
        if (sym)
            return sym->type;
    }

    // ביטויים אריתמטיים
    if (expr->child_count > 0 && expr->name) {
        if (strcmp(expr->name, "+") == 0 || strcmp(expr->name, "-") == 0 ||
            strcmp(expr->name, "*") == 0 || strcmp(expr->name, "/") == 0) {

            DataType left = get_expr_type(expr->children[0]);
            DataType right = expr->child_count > 1 ? get_expr_type(expr->children[1]) : DT_VOID;

            if (left == DT_REAL || right == DT_REAL)
                return DT_REAL;

            if (left == DT_INT && right == DT_INT)
                return DT_INT;
        }
    }

    // ליטרלים מספריים
    if (expr->name && (isdigit(expr->name[0]) || (expr->name[0] == '-' && isdigit(expr->name[1])))) {
        for (int i = 0; expr->name[i]; i++) {
            if (expr->name[i] == '.')
                return DT_REAL;
        }
        return DT_INT;
    }

    // כתובת של תא במחרוזת
    if (expr->name && strcmp(expr->name, "&array_access") == 0 && expr->child_count == 2) {
        Symbol* sym = lookup_any_scope(expr->children[0]->name);
        if (sym && sym->type == DT_STRING)
            return DT_PTR_CHAR;
        return DT_VOID;
    }

    // ברירת מחדל סופית – לא אידאלית, אך בטוחה
    return DT_INT;
}



void check_param_types(char* func_name, AST* args_node) {
    Symbol* func = lookup_any_scope(func_name);
    if (!func || func->kind != FUNC_SYM)
        return;
    
    int param_count = func->param_count;
    if (param_count == 0)
        return;
    
    DataType actual_types[MAX_PARAMS];
    memset(actual_types, 0, sizeof(actual_types));
    
    printf("DEBUG: ===== CHECKING PARAMETER TYPES =====\n");
    printf("DEBUG: Expected types for function '%s':\n", func_name);
    for (int i = 0; i < param_count; i++) {
        printf("DEBUG:   Formal param %d: %s\n", i+1, get_name_from_type(func->param_types[i]));
    }
    
    get_call_param_types(args_node, actual_types);
    
    printf("DEBUG: Actual types from function call:\n");
    for (int i = 0; i < param_count; i++) {
        printf("DEBUG:   Actual param %d: %s\n", i+1, get_name_from_type(actual_types[i]));
    }
    printf("DEBUG: =====================================\n");
        
    for (int i = 0; i < param_count; i++) {
        if (actual_types[i] != func->param_types[i]) {
            if (!(func->param_types[i] == DT_REAL && actual_types[i] == DT_INT)) {
                char msg[200];
                sprintf(msg, "Semantic Error: Parameter %d of function '%s' expects type %s, got %s",
                        i+1, func_name, get_name_from_type(func->param_types[i]), 
                        get_name_from_type(actual_types[i]));
                yyerror(msg);
            }
        }
    }
}
void get_call_param_types(AST* args_node, DataType* types) {
    if (!args_node || strcmp(args_node->name, "args") != 0 || args_node->child_count == 0)
        return;
    
    AST* param_node = args_node->children[0];
    if (!param_node || strcmp(param_node->name, "none") == 0)
        return;
    
    int index = 0;
    
    printf("DEBUG: Analyzing call args structure: %s with %d children\n", 
           param_node->name, param_node->child_count);
           
    get_call_param_types_recursive(param_node, types, &index);
}
void get_call_param_types_recursive(AST* node, DataType* types, int* index) {
    if (!node) return;
    
    printf("DEBUG: Processing node '%s' with %d children for parameter type extraction\n", 
           node->name, node->child_count);
    
    if (strcmp(node->name, "par") == 0) {
        if (node->child_count == 1) {

            types[(*index)++] = get_expr_type(node->children[0]);
            printf("DEBUG: Extracted single parameter of type %s\n", 
                   get_name_from_type(types[(*index)-1]));
        } 
        else if (node->child_count == 2) {


            get_call_param_types_recursive(node->children[0], types, index);
            

            types[(*index)++] = get_expr_type(node->children[1]);
            printf("DEBUG: Extracted parameter of type %s\n", 
                   get_name_from_type(types[(*index)-1]));
        }
    } 
    else {

        types[(*index)++] = get_expr_type(node);
        printf("DEBUG: Extracted direct parameter of type %s\n", 
               get_name_from_type(types[(*index)-1]));
    }
}
void check_boolean_condition(AST* expr, const char* construct_name) {
    if (expr) {
        DataType type = get_expr_type(expr);
        if (type != DT_BOOL) {
            char error_msg[100];
            sprintf(error_msg, "Semantic Error: Condition in '%s' statement must be of boolean type, got %s", 
                    construct_name, get_name_from_type(type));
            yyerror(error_msg);
        }
    }
}
void check_return_type(AST* expr, const char* func_name) {
    Symbol* func = lookup_any_scope(func_name);
    if (!func || func->kind != FUNC_SYM) {
        printf("DEBUG: Could not find function '%s' for return type check\n", func_name);
        return;
    }
    

    printf("DEBUG: Return expression details - name: '%s', child_count: %d\n", 
           expr ? expr->name : "NULL", expr ? expr->child_count : 0);
    

    if (expr && strcmp(expr->name, "NONE") == 0) {
        if (func->type != DT_VOID) {
            char msg[200];
            sprintf(msg, "Semantic Error: Function '%s' must return a value of type %s", 
                    func_name, get_name_from_type(func->type));
            yyerror(msg);
        }
        return;
    }
    

    if (func->type == DT_VOID && expr && strcmp(expr->name, "NONE") != 0) {
        char msg[200];
        sprintf(msg, "Semantic Error: Function '%s' has void return type but returns a value", 
                func_name);
        yyerror(msg);
        return;
    }
    
    DataType expr_type = get_expr_type(expr);
    printf("DEBUG: Function '%s' returns type %s, expression has type %s, expression name: '%s'\n", 
            func_name, get_name_from_type(func->type), get_name_from_type(expr_type), 
            expr ? expr->name : "NULL");
    

    if (func->type == DT_BOOL && expr && (strcmp(expr->name, "TRUE") == 0 || strcmp(expr->name, "FALSE") == 0)) {
        return;  
    }
    

    if ((func->type == DT_REAL && expr_type == DT_INT) ||
        (func->type == DT_BOOL && expr_type == DT_INT)) {
        return;
    }


    if (expr_type != func->type) {
        char msg[200];
        sprintf(msg,
            "Semantic Error: Function '%s' returns type %s but return statement has type %s", 
            func_name,
            get_name_from_type(func->type),
            get_name_from_type(expr_type));
        yyerror(msg);
    }
}
void check_string_index(AST* index_expr) {
    if (index_expr) {
        DataType type = get_expr_type(index_expr);
        if (type != DT_INT) {
            char error_msg[100];
            sprintf(error_msg, "Semantic Error: String index must be of integer type, got %s", 
                    get_name_from_type(type));
            yyerror(error_msg);
        }
    }
}
int is_type_compatible(DataType lhs, DataType rhs) {
    if (lhs == rhs)
        return 1;
    
    if (lhs == DT_REAL && rhs == DT_INT)
        return 1;
    
    
    return 0;
}
int is_pointer_type(DataType type) {
    return (type == DT_PTR_INT || type == DT_PTR_CHAR || type == DT_PTR_REAL);
}

DataType get_base_type(DataType ptr_type) {
    if (ptr_type == DT_PTR_INT) return DT_INT;
    if (ptr_type == DT_PTR_CHAR) return DT_CHAR;
    if (ptr_type == DT_PTR_REAL) return DT_REAL;
    return DT_VOID; 
}

int get_expected_param_number(const char* param_name) {
    
    if (strncmp(param_name, "par", 3) != 0)
        return -1; 
    
    return atoi(param_name + 3); 
}

void check_param_order(const char* param_name, int expected_number) {
    int param_number = get_expected_param_number(param_name);
    
    if (param_number != expected_number) {
        char error_msg[200];
        sprintf(error_msg, "Semantic Error: Parameter order incorrect - expected 'par%d', got '%s'", 
                expected_number, param_name);
        yyerror(error_msg);
    }
}
void add_multiple_variables(AST* id_list, DataType type) {
    if (!id_list) return;

    if (strcmp(id_list->name, "") == 0 && id_list->child_count == 2) {
        add_multiple_variables(id_list->children[0], type);
        if (id_list->children[1] && id_list->children[1]->name) {
            insert_checked_variable(id_list->children[1]->name, type);
        }
    } else {
        insert_checked_variable(id_list->name, type);
    }
}
void add_multiple_variables_with_values(AST* list, DataType type) {
    if (!list) return;

    if (strcmp(list->name, "") == 0 && list->child_count == 2) {
        add_multiple_variables_with_values(list->children[0], type);

        AST* id_with_value = list->children[1];
        if (id_with_value && id_with_value->name && id_with_value->child_count == 1) {
            const char* name = id_with_value->name;
            const char* value = id_with_value->children[0]->name;
            insert_checked_variable_with_value(name, type, value);
        }
    } else if (list->name && list->child_count == 1) {
        const char* name = list->name;
        const char* value = list->children[0]->name;
        insert_checked_variable_with_value(name, type, value);
    }
}
void insert_checked_variable_with_value(const char* name, DataType type, const char* value) {
    if (symbol_exists_in_current_scope(name)) {
        char error_msg[100];
        sprintf(error_msg, "Semantic Error: Var '%s' already defined in this block", name);
        yyerror(error_msg);
    } else {
        Symbol* new_sym = malloc(sizeof(Symbol));
        new_sym->name = strdup(name);
        new_sym->kind = VAR_SYM;
        new_sym->type = type;
        new_sym->param_count = 0;
        // אם תרצה – אפשר לשמור גם את הערך ב־Symbol struct, לפי הצורך
        new_sym->next = symbol_stack[current_scope]->head;
        symbol_stack[current_scope]->head = new_sym;
        printf("  Inserted '%s' with value '%s' as var in scope %d\n", name, value, current_scope);
    }
}
void debug_param_ast(AST* node, int depth) {
    if (!node) {
        printf("DEBUG: %*s(null)\n", depth*2, "");
        return;
    }
    
    printf("DEBUG: %*sNode: '%s', children: %d\n", depth*2, "", 
           node->name ? node->name : "(null)", node->child_count);
    
    for (int i = 0; i < node->child_count; i++) {
        printf("DEBUG: %*s  Child %d:\n", depth*2, "", i);
        debug_param_ast(node->children[i], depth + 1);
    }
}


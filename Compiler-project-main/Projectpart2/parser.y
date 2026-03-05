%{
    #include "ast.h"
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include "symbol_table.h"
#include "three_address_code.h"
    AST* make_node(char* name, int count, ...);
    void print_ast(AST* node, int indent);
    void yyerror(const char* s);
    void print_symbol_tables();
    int yylex();
    int yydebug = 1;
    int inside_main = 0;
    int scope_parent[100] = {-1};  
    int function_scopes[100] = {0}; 
    int current_function = 0; 
    int main_defined = 0;  
    extern int preserve_symbol_tables;
    char current_function_name[256] = "";
    int current_param_index = 0;
    AST* program_ast = NULL;
%}

%union {
    struct ast_node* ast ;
    char* sval;
}

%start program
%left OR
%left AND
%left PLUS MINUS

%left EQ NE GT GE LT LE
%left MULT DIV
%right NOT

%token <sval> ID CHAR_LITERAL STRING_LITERAL NUM TRUE FALSE
%token <sval> TYPE_INT TYPE_CHAR TYPE_REAL TYPE_BOOL TYPE_STRING TYPE_INT_PTR TYPE_CHAR_PTR TYPE_REAL_PTR

%token DEF T_BEGIN T_END IF ELSE ELIF WHILE FOR DO CALL RETURN RETURNS VAR NULLPTR ASSIGN ADDRESS
//%token AND OR NOT

//%token EQ NE GT GE LT LE ASSIGN
//%token PLUS MINUS MULT DIV ADDRESS

%token COLON SEMICOLON COMMA LPAREN RPAREN LBRACK RBRACK BAR TYPE

%type <ast> program function func_list par_list par_list_item param_list_item_list elif_list call_list type_decls type_decl update_expr id_list id_value_list 
%type <ast> type stmt_list stmt assignment expr if_stmt block return_stmt while_stmt for_stmt   do_while_stmt var_stmt call_args void_call assignment_call block_content
%type <ast> literal nested_block function_body nested_func_list string_id_list mixed_id_list

%%

program:
    func_list {
         program_ast = $1;
        print_ast($1, 0);
    }
  | error {
        yyerror("Could not parse input");
    }
;

func_list:
    func_list function { $$ = make_node("CODE", 2, $1, $2); }
  | function { $$ = make_node("CODE", 1, $1); }
;
function_body:
    T_BEGIN stmt_list T_END { $$ = make_node("BLOCK", 1, $2); }
  | T_BEGIN nested_func_list stmt_list T_END { $$ = make_node("BLOCK", 2, $2, $3); }
  | T_BEGIN T_END { $$ = make_node("BLOCK", 0); }
   | VAR type_decls T_BEGIN stmt_list T_END { 
        $$ = make_node("VAR_BLOCK", 2, $2, make_node("BLOCK", 1, $4)); 
    }
  | VAR type_decls T_BEGIN T_END { 
        $$ = make_node("VAR_BLOCK", 2, $2, make_node("BLOCK", 0)); 
    }
;
nested_func_list:
    nested_func_list function { $$ = make_node("", 2, $1, $2); }
  | function { $$ = $1; }
;
function:
    DEF ID LPAREN par_list RPAREN COLON RETURNS type {
        current_param_index = 0;
        if (symbol_exists_in_current_scope($2)) {
            char error_msg[100];
            sprintf(error_msg, "Semantic Error: Function '%s' already defined in this block", $2);
            yyerror(error_msg);
        } else {
            DataType param_types[MAX_PARAMS];
            int param_count = count_params($4);
            collect_param_types($4, param_types);
            insert_function_with_param_types($2, get_type_from_name($8->name), param_count, param_types);
            printf("Pre-registered function '%s' in scope %d with %d params\n", $2, current_scope, param_count);
        }
        strcpy(current_function_name, $2);

        if (strcmp($2, "_main_") == 0) {
            if (main_defined)
                yyerror("Semantic Error: Multiple definitions of _main_ function");
            main_defined = 1;
            inside_main = 1;

            if ($4->child_count > 0 && strcmp($4->children[0]->name, "NONE") != 0)
                yyerror("Semantic Error: _main_ function cannot take arguments");

            if (get_type_from_name($8->name) != DT_VOID)
                yyerror("Semantic Error: _main_ function cannot return a value");
        }
        if (get_type_from_name($8->name) == DT_STRING) {
            yyerror("Semantic Error: Function cannot return string type");
        }
          enter_scope();
        printf("DEBUG: Entered function scope %d for function %s\n", current_scope, $2);
        //enter_scope();
    } function_body {
         //exit_scope();
        inside_main = 0;
        current_function_name[0] = '\0';  

        $$ = make_node("FUNCTION", 4,
             make_node($2, 0),
             $4,
             make_node("RET", 1, $8),
             make_node("BODY", 1, $10));
              exit_scope();
        printf("DEBUG: Exited function scope for function %s, back to scope %d\n", $2, current_scope);
    }

  | DEF ID LPAREN RPAREN COLON RETURNS type {
        if (symbol_exists_in_current_scope($2)) {
            char error_msg[100];
            sprintf(error_msg, "Semantic Error: Function '%s' already defined in this block", $2);
            yyerror(error_msg);
        } else {
            DataType param_types[MAX_PARAMS];  
            insert_function_with_param_types($2, get_type_from_name($7->name), 0, param_types);
            printf("Pre-registered function '%s' in scope %d with 0 params\n", $2, current_scope);
        }
        strcpy(current_function_name, $2);

        if (strcmp($2, "_main_") == 0) {
            if (main_defined)
                yyerror("Semantic Error: Multiple definitions of _main_ function");
            main_defined = 1;
            inside_main = 1;

            if (get_type_from_name($7->name) != DT_VOID)
                yyerror("Semantic Error: _main_ function cannot return a value");
        }
        if (get_type_from_name($7->name) == DT_STRING) {
            yyerror("Semantic Error: Function cannot return string type");
        }
          enter_scope();
        printf("DEBUG: Entered function scope %d for function %s\n", current_scope, $2);
        //enter_scope();
    } function_body {
         //exit_scope();
        inside_main = 0;
        current_function_name[0] = '\0';  

        $$ = make_node("FUNCTION", 4,
             make_node($2, 0),
             make_node("ARGS", 1, make_node("NONE", 0)),
             make_node("RET", 1, $7),
             make_node("BODY", 1, $9));
                   exit_scope();
        printf("DEBUG: Exited function scope for function %s, back to scope %d\n", $2, current_scope);
    }

  | DEF ID LPAREN par_list RPAREN COLON {
    current_param_index = 0;
        if (symbol_exists_in_current_scope($2)) {
            char error_msg[100];
            sprintf(error_msg, "Semantic Error: Function '%s' already defined in this block", $2);
            yyerror(error_msg);
        } else {
            DataType param_types[MAX_PARAMS];
            int param_count = count_params($4);
            collect_param_types($4, param_types);
            insert_function_with_param_types($2, DT_VOID, param_count, param_types);
            printf("Pre-registered function '%s' in scope %d with %d params\n", $2, current_scope, param_count);
        }
        strcpy(current_function_name, $2);

        if (strcmp($2, "_main_") == 0) {
            if (main_defined)
                yyerror("Semantic Error: Multiple definitions of _main_ function");
            main_defined = 1;
            inside_main = 1;

            if ($4->child_count > 0 && strcmp($4->children[0]->name, "NONE") != 0)
                yyerror("Semantic Error: _main_ function cannot take arguments");
        }
          enter_scope();
        printf("DEBUG: Entered function scope %d for function %s\n", current_scope, $2);
        //enter_scope();
    } function_body {
         //exit_scope();
        inside_main = 0;
        current_function_name[0] = '\0';  

        $$ = make_node("FUNCTION", 4,
             make_node($2, 0),
             $4,
             make_node("RET", 1, make_node("NONE", 0)),
             make_node("BODY", 1, $8));
                   exit_scope();
        printf("DEBUG: Exited function scope for function %s, back to scope %d\n", $2, current_scope);
    }

  | DEF ID LPAREN RPAREN COLON {
        if (symbol_exists_in_current_scope($2)) {
            char error_msg[100];
            sprintf(error_msg, "Semantic Error: Function '%s' already defined in this block", $2);
            yyerror(error_msg);
        } else {
            DataType param_types[MAX_PARAMS];  
            insert_function_with_param_types($2, DT_VOID, 0, param_types);
            printf("Pre-registered function '%s' in scope %d with 0 params\n", $2, current_scope);
        }
    strcpy(current_function_name, $2);

        if (strcmp($2, "_main_") == 0) {
            if (main_defined)
                yyerror("Semantic Error: Multiple definitions of _main_ function");
            main_defined = 1;
            inside_main = 1;
        }
          enter_scope();
        printf("DEBUG: Entered function scope %d for function %s\n", current_scope, $2);
       // enter_scope();
    } function_body {
        // exit_scope();
        inside_main = 0;
         current_function_name[0] = '\0';  

        $$ = make_node("FUNCTION", 4,
             make_node($2, 0),
             make_node("ARGS", 1, make_node("NONE", 0)),
             make_node("RET", 1, make_node("NONE", 0)),
             make_node("BODY", 1, $7));
                    exit_scope();
        printf("DEBUG: Exited function scope for function %s, back to scope %d\n", $2, current_scope);

    }
;

par_list:
    param_list_item_list { $$ = make_node("ARGS", 1, $1); }
  | /* empty */ { $$ = make_node("ARGS", 1, make_node("NONE", 0)); }
;

param_list_item_list:
    param_list_item_list SEMICOLON par_list_item {
        $$ = make_node("", 2, $1, $3);
    }
  | par_list_item {
        $$ = $1;
    }
;


par_list_item:
    ID type COLON ID {
        current_param_index++;
        
        check_param_order($1, current_param_index);
        
        insert_symbol($4, VAR_SYM, get_type_from_name($2->name));
        printf("  Inserted parameter '%s' as variable in scope %d\n", $4, current_scope);
        
    
              $$ = make_node($1, 2,
          make_node($2->name, 0),
            make_node($4,      0));
    }
;
type:
    TYPE_INT   { $$ = make_node($1, 0); }
  | TYPE_CHAR  { $$ = make_node($1, 0); }
  | TYPE_REAL  { $$ = make_node($1, 0); }
  | TYPE_BOOL  { $$ = make_node($1, 0); }
  | TYPE_STRING { $$ = make_node($1, 0); }
  | TYPE_INT_PTR { $$ = make_node($1, 0); }
  | TYPE_CHAR_PTR { $$ = make_node($1, 0); }
  | TYPE_REAL_PTR { $$ = make_node($1, 0); }
;

stmt_list:
    stmt_list stmt { 
        printf("DEBUG: Processing stmt_list + stmt, current_scope = %d\n", current_scope);
        $$ = make_node("", 2, $1, $2); 
    }
    | stmt { 
        printf("DEBUG: Processing solo stmt, current_scope = %d\n", current_scope);
        $$ = $1; 
    }
;

stmt:
    assignment
  | if_stmt
  | return_stmt
|block
  | while_stmt 
  | for_stmt 
  | call_args 
  |do_while_stmt
  |var_stmt 
  |void_call
|assignment_call
|function
;

assignment:
   ID ASSIGN expr SEMICOLON {
        Symbol* sym = lookup_any_scope($1);
        if (!sym) {
            char error_msg[100];
            sprintf(error_msg, "Semantic Error: Variable '%s' used before declaration", $1);
            yyerror(error_msg);
        } else {
            DataType lhs_type = sym->type;
            DataType rhs_type = get_expr_type($3);
            
            if (rhs_type == DT_PTR_INT && $3->name && strcmp($3->name, "nullptr") == 0) {
                if (lhs_type != DT_PTR_INT && lhs_type != DT_PTR_CHAR && lhs_type != DT_PTR_REAL) {
                    char error_msg[100];
                    sprintf(error_msg, "Semantic Error: Cannot assign null to non-pointer type %s", 
                            get_name_from_type(lhs_type));
                    yyerror(error_msg);
                }
            }
            else if (!is_type_compatible(lhs_type, rhs_type)) {
                char error_msg[100];
                sprintf(error_msg, "Semantic Error: Type mismatch in assignment, cannot assign %s to %s", 
                        get_name_from_type(rhs_type), get_name_from_type(lhs_type));
                yyerror(error_msg);
            }
        }
        $$ = make_node("=", 2, make_node($1, 0), $3);
    }
    | ID LBRACK expr RBRACK ASSIGN expr SEMICOLON {
        Symbol* sym = lookup_any_scope($1);
        if (!sym) {
            char error_msg[100];
            sprintf(error_msg, "Semantic Error: Variable '%s' used before declaration", $1);
            yyerror(error_msg);
        } else if (sym->type != DT_STRING) {
            char error_msg[100];
            sprintf(error_msg, "Semantic Error: [] operator can only be used with string type, '%s' is of type %s", 
                    $1, get_name_from_type(sym->type));
            yyerror(error_msg);
        } else {
            check_string_index($3);
            
            DataType rhs_type = get_expr_type($6);
            if (rhs_type != DT_CHAR) {
                char error_msg[100];
                sprintf(error_msg, "Semantic Error: String element can only be assigned a char value, got %s", 
                        get_name_from_type(rhs_type));
                yyerror(error_msg);
            }
        }
        $$ = make_node("=", 2, make_node("array_access", 2, make_node($1, 0), $3), $6);
    }
  | MULT ID ASSIGN expr SEMICOLON {
        Symbol* sym = lookup_any_scope($2);
        if (!sym) {
            char error_msg[100];
            sprintf(error_msg, "Semantic Error: Variable '%s' used before declaration", $2);
            yyerror(error_msg);
        }
        
        DataType type = sym->type;
        if (!is_pointer_type(type)) {
            char error_msg[100];
            sprintf(error_msg, "Semantic Error: Cannot dereference non-pointer variable '%s'", $2);
            yyerror(error_msg);
        }
        
        DataType target_type = get_base_type(type);
        
        DataType expr_type = get_expr_type($4);
        if (target_type != expr_type) {
            if (!(target_type == DT_REAL && expr_type == DT_INT)) {
                char error_msg[100];
                sprintf(error_msg, "Semantic Error: Type mismatch in assignment to dereferenced pointer: expected %s, got %s",
                        get_name_from_type(target_type), get_name_from_type(expr_type));
                yyerror(error_msg);
            }
        }
        
        $$ = make_node("=", 2, make_node("*", 1, make_node($2, 0)), $4);
    }
    | ADDRESS ID ASSIGN expr SEMICOLON {
        yyerror("Semantic Error: Cannot use address operator on left side of assignment");
        $$ = make_node("error", 2, make_node("&", 1, make_node($2, 0)), $4);
   }
;
mixed_id_list:
    ID {
        $$ = make_node($1, 0);  /* משתנה ללא ערך התחלה */
    }
    | ID COLON literal {
        $$ = make_node($1, 1, $3);  /* משתנה עם ערך התחלה */
    }
    | mixed_id_list COMMA ID {
        $$ = make_node("", 2, $1, make_node($3, 0));  /* הוספת משתנה ללא ערך */
    }
    | mixed_id_list COMMA ID COLON literal {
        $$ = make_node("", 2, $1, make_node($3, 1, $5));  /* הוספת משתנה עם ערך */
    }
;
id_list:
      ID                        { $$ = make_node($1, 0); }
    | id_list COMMA ID         { $$ = make_node("", 2, $1, make_node($3, 0)); }
;


var_stmt:
    VAR {
        enter_scope();
        printf("DEBUG: Entered VAR scope %d\n", current_scope);
    } type_decls block_content {
        $$ = make_node("VAR", 2, $3, $4);
    }
  | VAR {
        enter_scope();
        printf("DEBUG: Entered VAR scope %d\n", current_scope);
    } type_decls stmt {
        $$ = make_node("VAR", 2, $3, $4);
        exit_scope();
        printf("DEBUG: Exited VAR scope\n");
    }
;
block_content:
    T_BEGIN stmt_list T_END {
        $$ = make_node("BLOCK", 1, $2); 
        exit_scope();
        printf("DEBUG: Exited VAR scope from block_content\n");
    }
    | T_BEGIN T_END {
        $$ = make_node("BLOCK", 0); 
        exit_scope();
        printf("DEBUG: Exited VAR scope from empty block_content\n");
    }
;
type_decls:
    type_decls type_decl {
        $$ = make_node("DECLS", 2, $1, $2);
    }
  | type_decl {
        $$ = $1;
    }
;
string_id_list:
    ID LBRACK NUM RBRACK {
        $$ = make_node($1, 1, make_node($3, 0));
    }
    | string_id_list COMMA ID LBRACK NUM RBRACK {
        $$ = make_node("", 2, $1, make_node($3, 1, make_node($5, 0)));
    }
;
type_decl:
    TYPE TYPE_INT COLON ID SEMICOLON {
        insert_checked_variable($4, DT_INT);
        $$ = make_node("TYPE", 2, make_node("int", 0), make_node($4, 0));
    }
  | TYPE TYPE_BOOL COLON ID SEMICOLON {
        insert_checked_variable($4, DT_BOOL);
        $$ = make_node("TYPE", 2, make_node("bool", 0), make_node($4, 0));
    }
  | TYPE TYPE_CHAR COLON ID SEMICOLON {
        insert_checked_variable($4, DT_CHAR);
        $$ = make_node("TYPE", 2, make_node("char", 0), make_node($4, 0));
    }
  | TYPE TYPE_STRING COLON ID SEMICOLON {
        insert_checked_variable($4, DT_STRING);
        $$ = make_node("TYPE", 2, make_node("string", 0), make_node($4, 0));
    }
  | TYPE TYPE_REAL COLON ID SEMICOLON {
        insert_checked_variable($4, DT_REAL);
        $$ = make_node("TYPE", 2, make_node("real", 0), make_node($4, 0));
    }
    | TYPE TYPE_REAL COLON ID COLON NUM SEMICOLON {
        insert_checked_variable($4, DT_REAL);
        $$ = make_node("TYPE", 2, make_node("real", 0), make_node($4, 1,make_node($6,0)));
    }
  | TYPE TYPE_INT COLON ID COLON NUM SEMICOLON {
        insert_checked_variable($4, DT_INT);
        $$ = make_node("TYPE", 2, make_node("int", 0), make_node($4, 1, make_node($6, 0)));
    }
  | TYPE TYPE_CHAR COLON ID COLON CHAR_LITERAL SEMICOLON {
        insert_checked_variable($4, DT_CHAR);
        $$ = make_node("TYPE", 2, make_node("char", 0), make_node($4, 1, make_node($6, 0)));
    }
  | TYPE TYPE_STRING COLON ID COLON STRING_LITERAL SEMICOLON {
        insert_checked_variable($4, DT_STRING);
        $$ = make_node("TYPE", 2, make_node("string", 0), make_node($4, 1, make_node($6, 0)));
    }
  | TYPE TYPE_BOOL COLON ID COLON TRUE SEMICOLON {
        insert_checked_variable($4, DT_BOOL);
        $$ = make_node("TYPE", 2, make_node("bool", 0), make_node($4, 1, make_node("true", 0)));
    }
  | TYPE TYPE_BOOL COLON ID COLON FALSE SEMICOLON {
        insert_checked_variable($4, DT_BOOL);
        $$ = make_node("TYPE", 2, make_node("bool", 0), make_node($4, 1, make_node("false", 0)));
    }
   | TYPE TYPE_STRING COLON ID LBRACK NUM RBRACK SEMICOLON {
        int size = atoi($6);
        if (size <= 0) {
            char error_msg[100];
            sprintf(error_msg, "Semantic Error: String size must be a positive integer");
            yyerror(error_msg);
        }
        insert_checked_variable($4, DT_STRING);
        $$ = make_node("TYPE", 3, make_node("string", 0), make_node($4, 0), make_node($6, 0));
    }
    | TYPE TYPE_INT_PTR COLON ID SEMICOLON {
        insert_checked_variable($4, DT_PTR_INT);
        $$ = make_node("TYPE", 2, make_node("int*", 0), make_node($4, 0));
    }
  | TYPE TYPE_CHAR_PTR COLON ID SEMICOLON {
        insert_checked_variable($4, DT_PTR_CHAR);
        $$ = make_node("TYPE", 2, make_node("char*", 0), make_node($4, 0));
    }
  | TYPE TYPE_REAL_PTR COLON ID SEMICOLON {
        insert_checked_variable($4, DT_PTR_REAL);
        $$ = make_node("TYPE", 2, make_node("real*", 0), make_node($4, 0));
    }

    |TYPE TYPE_INT COLON id_list SEMICOLON {
        add_multiple_variables($4, DT_INT);
        $$ = make_node("TYPE_MULTI", 2, make_node("int", 0), $4);
    }
  | TYPE TYPE_BOOL COLON id_list SEMICOLON {
        add_multiple_variables($4, DT_BOOL);
        $$ = make_node("TYPE_MULTI", 2, make_node("bool", 0), $4);
    }
  | TYPE TYPE_CHAR COLON id_list SEMICOLON {
        add_multiple_variables($4, DT_CHAR);
        $$ = make_node("TYPE_MULTI", 2, make_node("char", 0), $4);
    }
  | TYPE TYPE_REAL COLON id_list SEMICOLON {
        add_multiple_variables($4, DT_REAL);
        $$ = make_node("TYPE_MULTI", 2, make_node("real", 0), $4);
    }
  | TYPE TYPE_INT_PTR COLON id_list SEMICOLON {
        add_multiple_variables($4, DT_PTR_INT);
        $$ = make_node("TYPE_MULTI", 2, make_node("int*", 0), $4);
    }
  | TYPE TYPE_CHAR_PTR COLON id_list SEMICOLON {
        add_multiple_variables($4, DT_PTR_CHAR);
        $$ = make_node("TYPE_MULTI", 2, make_node("char*", 0), $4);
    }
  | TYPE TYPE_REAL_PTR COLON id_list SEMICOLON {
        add_multiple_variables($4, DT_PTR_REAL);
        $$ = make_node("TYPE_MULTI", 2, make_node("real*", 0), $4);
    }
| TYPE TYPE_STRING COLON string_id_list SEMICOLON {
        add_multiple_string_arrays($4);
        $$ = make_node("TYPE_STRING_MULTI", 2, make_node("string", 0), $4);
    }
| TYPE TYPE_BOOL COLON id_value_list SEMICOLON {
    add_multiple_variables_with_values($4, DT_BOOL);
    $$ = make_node("TYPE_MULTI_INIT", 2, make_node("bool", 0), $4);
}
| TYPE TYPE_INT COLON id_value_list SEMICOLON {
    add_multiple_variables_with_values($4, DT_INT);
    $$ = make_node("TYPE_MULTI_INIT", 2, make_node("int", 0), $4);
}
| TYPE TYPE_CHAR COLON id_value_list SEMICOLON {
    add_multiple_variables_with_values($4, DT_CHAR);
    $$ = make_node("TYPE_MULTI_INIT", 2, make_node("char", 0), $4);
}
| TYPE TYPE_STRING COLON id_value_list SEMICOLON {
    add_multiple_variables_with_values($4, DT_STRING);
    $$ = make_node("TYPE_MULTI_INIT", 2, make_node("string", 0), $4);
}
| TYPE TYPE_REAL COLON id_value_list SEMICOLON {
    add_multiple_variables_with_values($4, DT_REAL);
    $$ = make_node("TYPE_MULTI_INIT", 2, make_node("real", 0), $4);
}| TYPE TYPE_BOOL COLON mixed_id_list SEMICOLON {
        add_multiple_variables_mixed($4, DT_BOOL);
        $$ = make_node("TYPE_MIXED", 2, make_node("bool", 0), $4);
    }
  | TYPE TYPE_INT COLON mixed_id_list SEMICOLON {
        add_multiple_variables_mixed($4, DT_INT);
        $$ = make_node("TYPE_MIXED", 2, make_node("int", 0), $4);
    }
  | TYPE TYPE_CHAR COLON mixed_id_list SEMICOLON {
        add_multiple_variables_mixed($4, DT_CHAR);
        $$ = make_node("TYPE_MIXED", 2, make_node("char", 0), $4);
    }
  | TYPE TYPE_STRING COLON mixed_id_list SEMICOLON {
        add_multiple_variables_mixed($4, DT_STRING);
        $$ = make_node("TYPE_MIXED", 2, make_node("string", 0), $4);
    }
  | TYPE TYPE_REAL COLON mixed_id_list SEMICOLON {
        add_multiple_variables_mixed($4, DT_REAL);
        $$ = make_node("TYPE_MIXED", 2, make_node("real", 0), $4);
    }

;
id_value_list:
      ID COLON literal {
          $$ = make_node($1, 1, $3);  // $3 כבר AST
      }
    | id_value_list COMMA ID COLON literal {
          $$ = make_node("", 2, $1, make_node($3, 1, $5));
      }
;


literal:
   NUM            { $$ = make_node($1, 0); }
|TRUE           { $$ = make_node("true", 0); }
|FALSE          { $$ = make_node("false", 0); }
|CHAR_LITERAL   { $$ = make_node($1, 0); }
|STRING_LITERAL { $$ = make_node($1, 0); }

;

return_stmt:
    RETURN expr SEMICOLON {
        printf("DEBUG: Processing return with value in function '%s'\n", current_function_name);

        
        check_return_type($2, current_function_name);
        
        $$ = make_node("RETURN", 1, $2);
    }
  | RETURN SEMICOLON {
        printf("DEBUG: Processing empty return in function '%s'\n", current_function_name);
        
        check_return_type(make_node("NONE", 0), current_function_name);
        
        $$ = make_node("RETURN", 1, make_node("NONE", 0));
    }
;

if_stmt:
    IF expr COLON nested_block ELSE COLON nested_block
    {
        check_boolean_condition($2, "if");
        $$ = make_node("IF-ELSE", 3, $2, $4, $7);
    }
  | IF expr COLON nested_block
    {
        check_boolean_condition($2, "if");
        $$ = make_node("IF", 2, $2, $4);
    }
  | IF expr COLON stmt
    {
        check_boolean_condition($2, "if");
        $$ = make_node("IF", 2, $2, $4);
    }
  | IF expr COLON stmt ELSE COLON stmt
    {
        check_boolean_condition($2, "if");
        $$ = make_node("IF-ELSE", 3, $2, $4, $7);
    }
  | IF expr COLON nested_block elif_list ELSE COLON nested_block
    {
        check_boolean_condition($2, "if");
        $$ = make_node("IF-ELIF-ELSE", 4, $2, $4, $5, $8);
    }
;

elif_list: 
    ELIF expr COLON block
    {
        check_boolean_condition($2, "elif");
        $$ = make_node("ELIF", 2, $2, $4);
    }
    | elif_list ELIF expr COLON block
    {
        check_boolean_condition($3, "elif");
        $$ = make_node("ELIF - ...", 3, $1, make_node("elif", 2, $3, $5));
    }
;
while_stmt:
    WHILE COLON expr SEMICOLON
    {
        check_boolean_condition($3, "while");
        $$ = make_node("while", 1, $3);
    }
    | WHILE expr COLON block
    {
        check_boolean_condition($2, "while");
        $$ = make_node("while2", 2, $2, $4);
    }
    | WHILE expr COLON stmt
    {
        check_boolean_condition($2, "while");
        $$ = make_node("while2", 2, $2, $4);
    }
;
do_while_stmt:
    DO COLON stmt_list WHILE expr SEMICOLON {
        check_boolean_condition($5, "do-while");
        $$ = make_node("do-while", 2, $3, $5);
    }
    |
    DO COLON stmt WHILE expr SEMICOLON {
        check_boolean_condition($5, "do-while");
        $$ = make_node("do-while", 2, $3, $5);
    }
    |
    DO COLON block WHILE expr SEMICOLON {
        check_boolean_condition($5, "do-while");
        $$ = make_node("do-while", 2, $3, $5);
    }
;

for_stmt:
    FOR LPAREN assignment expr SEMICOLON update_expr RPAREN COLON block {
        check_boolean_condition($4, "for"); 
        $$ = make_node("for", 4, $3, $4, $6, $9);
    }
    |
    FOR LPAREN assignment expr SEMICOLON update_expr RPAREN COLON stmt {
        check_boolean_condition($4, "for"); 
        $$ = make_node("for", 4, $3, $4, $6, $9);
    }
;

update_expr:
    ID ASSIGN expr {
        $$ = make_node("=", 2, make_node($1, 0), $3);
    }
    | expr {
        $$ = $1;
    }
;
call_args:
    call_list { $$ = make_node("args", 1, $1); }
  | /* empty */ { $$ = make_node("args", 1, make_node("none", 0)); }
;

call_list:
    call_list COMMA expr
    {
        $$= make_node ("par",2,$1,$3);
    }
    | expr
    {
          $$= make_node ("par",1,$1);
    }

;

assignment_call:
    ID ASSIGN CALL ID LPAREN call_args RPAREN SEMICOLON {
        Symbol* func = lookup_any_scope($4);
        if (!func) {
            char msg[100];
            sprintf(msg, "Semantic Error: Function '%s' called before declaration", $4);
            yyerror(msg);
        } else if (func->kind != FUNC_SYM) {
            char msg[100];
            sprintf(msg, "Semantic Error: '%s' is not a function", $4);
            yyerror(msg);
        } else {
            int expected = func->param_count;
            int actual = count_actual_params($6);
            if (expected != actual) {
                char msg[150];
                sprintf(msg, "Semantic Error: Function '%s' expects %d arguments, got %d", $4, expected, actual);
                yyerror(msg);
            } else {
                check_param_types($4, $6);
            }
        }

        $$ = make_node("ASSIGN-CALL", 2,
                       make_node($1, 0),
                       make_node("CALL", 2, make_node($4, 0), $6));
    }
;

void_call:
    CALL ID LPAREN call_args RPAREN SEMICOLON {
        Symbol* func = lookup_any_scope($2);
        if (!func) {
            char msg[100];
            sprintf(msg, "Semantic Error: Function '%s' called before declaration", $2);
            yyerror(msg);
        } else if (func->kind != FUNC_SYM) {
            char msg[100];
            sprintf(msg, "Semantic Error: '%s' is not a function", $2);
            yyerror(msg);
        } else {
            int expected = func->param_count;
            int actual = count_actual_params($4);
            if (expected != actual) {
                char msg[150];
                sprintf(msg, "Semantic Error: Function '%s' expects %d arguments, got %d", $2, expected, actual);
                yyerror(msg);
            } else {
                check_param_types($2, $4);
            }
        }

        $$ = make_node("CALL", 2, make_node($2, 0), $4);
    }
;

block:
    T_BEGIN stmt_list T_END {
        $$ = make_node("BLOCK", 1, $2); 
    }
    | T_BEGIN T_END {
        $$ = make_node("BLOCK", 0); 
    }
;
nested_block:
    T_BEGIN {
        enter_scope();
        printf("DEBUG: Entered nested block scope %d\n", current_scope);
    } stmt_list T_END {
        $$ = make_node("BLOCK", 1, $3); 
        exit_scope();
        printf("DEBUG: Exited nested block scope\n");
    }
    | T_BEGIN {
        enter_scope();
        printf("DEBUG: Entered nested block scope %d\n", current_scope);
    } T_END {
        $$ = make_node("BLOCK", 0); 
        exit_scope();
        printf("DEBUG: Exited nested block scope\n");
    }
;

expr:
| BAR ID BAR {
        Symbol* sym = lookup_any_scope($2);
        if (!sym) {
            char error_msg[100];
            sprintf(error_msg, "Semantic Error: Variable '%s' used before declaration", $2);
            yyerror(error_msg);
        } else if (sym->type != DT_STRING) {
            char error_msg[100];
            sprintf(error_msg, "Semantic Error: Length operator |...| can only be used with string type, '%s' is of type %s", 
                    $2, get_name_from_type(sym->type));
            yyerror(error_msg);
        }
        $$ = make_node("string_length", 1, make_node($2, 0));
    }|
    expr PLUS expr {
    DataType left = get_expr_type($1);
    DataType right = get_expr_type($3);
    if (!((left == DT_INT || left == DT_REAL) && (right == DT_INT || right == DT_REAL))) {
        char msg[200];
        sprintf(msg, "Semantic Error: '+' operator requires numeric types, got '%s' and '%s'",
                get_name_from_type(left), get_name_from_type(right));
        yyerror(msg);
    }
    $$ = make_node("+", 2, $1, $3);
	}
    | expr MINUS expr {
    DataType left = get_expr_type($1);
    DataType right = get_expr_type($3);
    if (!((left == DT_INT || left == DT_REAL) && (right == DT_INT || right == DT_REAL))) {
        char msg[200];
        sprintf(msg, "Semantic Error: '-' operator requires numeric types, got '%s' and '%s'",
                get_name_from_type(left), get_name_from_type(right));
        yyerror(msg);
    }
    $$ = make_node("-", 2, $1, $3);
	}
    | expr MULT expr {
    DataType left = get_expr_type($1);
    DataType right = get_expr_type($3);
    if (!((left == DT_INT || left == DT_REAL) && (right == DT_INT || right == DT_REAL))) {
        char msg[200];
        sprintf(msg, "Semantic Error: '*' operator requires numeric types, got '%s' and '%s'",
                get_name_from_type(left), get_name_from_type(right));
        yyerror(msg);
    }
    $$ = make_node("*", 2, $1, $3);
	}
    |  expr DIV expr {
    DataType left = get_expr_type($1);
    DataType right = get_expr_type($3);
    if (!((left == DT_INT || left == DT_REAL) && (right == DT_INT || right == DT_REAL))) {
        char msg[200];
        sprintf(msg, "Semantic Error: '/' operator requires numeric types, got '%s' and '%s'",
                get_name_from_type(left), get_name_from_type(right));
        yyerror(msg);
    }
    $$ = make_node("/", 2, $1, $3);
	}
    | expr EQ expr {
    DataType left = get_expr_type($1);
    DataType right = get_expr_type($3);
    if (left != right) {
        char msg[200];
        sprintf(msg, "Semantic Error: '==' requires operands of same type, got '%s' and '%s'",
                get_name_from_type(left), get_name_from_type(right));
        yyerror(msg);
    }
    $$ = make_node("==", 2, $1, $3);
	}
    | expr NE expr {
    DataType left = get_expr_type($1);
    DataType right = get_expr_type($3);
    if (left != right) {
        char msg[200];
        sprintf(msg, "Semantic Error: '!=' requires operands of same type, got '%s' and '%s'",
                get_name_from_type(left), get_name_from_type(right));
        yyerror(msg);
    }
    $$ = make_node("!=", 2, $1, $3);
	}
    | expr LT expr {
    DataType left = get_expr_type($1);
    DataType right = get_expr_type($3);
    if (!((left == DT_INT || left == DT_REAL) && (right == DT_INT || right == DT_REAL))) {
        char msg[200];
        sprintf(msg, "Semantic Error: '<' requires numeric types, got '%s' and '%s'",
                get_name_from_type(left), get_name_from_type(right));
        yyerror(msg);
    }
    $$ = make_node("<", 2, $1, $3);
	}
    | expr GT expr {
    DataType left = get_expr_type($1);
    DataType right = get_expr_type($3);
    if (!((left == DT_INT || left == DT_REAL) && (right == DT_INT || right == DT_REAL))) {
        char msg[200];
        sprintf(msg, "Semantic Error: '>' requires numeric types, got '%s' and '%s'",
                get_name_from_type(left), get_name_from_type(right));
        yyerror(msg);
    }
    $$ = make_node(">", 2, $1, $3);
	}
    | expr LE expr {
    DataType left = get_expr_type($1);
    DataType right = get_expr_type($3);
    if (!((left == DT_INT || left == DT_REAL) && (right == DT_INT || right == DT_REAL))) {
        char msg[200];
        sprintf(msg, "Semantic Error: '<=' requires numeric types, got '%s' and '%s'",
                get_name_from_type(left), get_name_from_type(right));
        yyerror(msg);
    }
    $$ = make_node("<=", 2, $1, $3);
	}
    | expr GE expr {
    DataType left = get_expr_type($1);
    DataType right = get_expr_type($3);
    if (!((left == DT_INT || left == DT_REAL) && (right == DT_INT || right == DT_REAL))) {
        char msg[200];
        sprintf(msg, "Semantic Error: '>=' requires numeric types, got '%s' and '%s'",
                get_name_from_type(left), get_name_from_type(right));
        yyerror(msg);
    }
    $$ = make_node(">=", 2, $1, $3);
	}
    | LPAREN expr RPAREN { $$ = $2; }
    
    | ID LBRACK expr RBRACK {
        Symbol* sym = lookup_any_scope($1);
        if (!sym) {
            char error_msg[100];
            sprintf(error_msg, "Semantic Error: Variable '%s' used before declaration", $1);
            yyerror(error_msg);
        } else if (sym->type != DT_STRING) {
            char error_msg[100];
            sprintf(error_msg, "Semantic Error: [] operator can only be used with string type, '%s' is of type %s", 
                    $1, get_name_from_type(sym->type));
            yyerror(error_msg);
        } else {
            check_string_index($3);
        }
        $$ = make_node("array_access", 2, make_node($1, 0), $3);
    }

    | LBRACK expr RBRACK {
        char error_msg[100];
        sprintf(error_msg, "Semantic Error: Invalid use of [] operator");
        yyerror(error_msg);
        $$ = $2; 
    }
    
    | NUM { $$ = make_node($1, 0); }
    | ID {
        Symbol* sym = lookup_any_scope($1);
        if (!sym) {
            char error_msg[100];
            sprintf(error_msg, "Semantic Error: Variable '%s' used before declaration", $1);
            yyerror(error_msg);
        }
        $$ = make_node($1, 0);
    }
    | CHAR_LITERAL { $$ = make_node($1, 0); }
    | STRING_LITERAL { $$ = make_node($1, 0); }
    | NULLPTR { $$ = make_node("nullptr", 0); }
    | TRUE { $$ = make_node("true", 0); }
    | FALSE { $$ = make_node("false", 0); }
    | AND { $$ = make_node("and", 0); }
    | OR { $$ = make_node("or", 0); }
    | NOT { $$ = make_node("not", 0); }
    | CALL ID LPAREN call_args RPAREN {
        Symbol* func = lookup_any_scope($2);
        if (func && func->kind == FUNC_SYM) {
            int expected = func->param_count;
            int actual = count_actual_params($4);
            if (expected == actual) {
                check_param_types($2, $4);
            }
        }
        $$ = make_node("call", 2, make_node($2, 0), $4);
    }
    | ID LPAREN call_args RPAREN {
        
        Symbol* sym = lookup_any_scope($1);
        if (!sym) {
            char msg[128];
            sprintf(msg, "Semantic Error: Function '%s' called before declaration/definition", $1);
            yyerror(msg);
        }
        else if (sym->kind != FUNC_SYM) {
            char msg[128];
            sprintf(msg, "Semantic Error: '%s' is not a function", $1);
            yyerror(msg);
        }
        else {
         
            int expected = sym->param_count;
            int actual   = count_actual_params($3);
          if (expected != actual) {
                char msg[150];
                sprintf(msg, "Semantic Error: Function '%s' expects %d args, got %d",
                        $1, expected, actual);
                yyerror(msg);
            } else {
                check_param_types($1, $3);
            }
        }
        $$ = make_node("call", 2, make_node($1, 0), $3);
    }
    | expr AND expr { $$ = make_node("and", 2, $1, $3); }
    | expr OR expr { $$ = make_node("or", 2, $1, $3); }
    | NOT expr { $$ = make_node("not", 1, $2); }

  | MULT expr {
  
    if (!$2) {
        yyerror("Semantic Error: Invalid dereference expression");
        $$ = make_node("error", 0);
    }
   
    else if ($2->name && strcmp($2->name, "*") == 0) {
        yyerror("Semantic Error: Double dereference is not allowed (cannot use **ptr)");
        $$ = make_node("error", 1, $2);
    }
    
    else if ($2->name && $2->child_count == 0) {
        Symbol* sym = lookup_any_scope($2->name);
        if (!sym) {
            char error_msg[100];
            sprintf(error_msg, "Semantic Error: Variable '%s' used before declaration", $2->name);
            yyerror(error_msg);
        }
        else if (!is_pointer_type(sym->type)) {
            char error_msg[100];
            sprintf(error_msg, "Semantic Error: Cannot dereference non-pointer variable '%s'", $2->name);
            yyerror(error_msg);
        }
        $$ = make_node("*", 1, $2);
    }
   
    else {
        yyerror("Semantic Error: Cannot dereference non-pointer expression");
        $$ = make_node("error", 1, $2);
    }
}
  | ADDRESS ID {
    Symbol* sym = lookup_any_scope($2);
    if (!sym) {
        char error_msg[100];
        sprintf(error_msg, "Semantic Error: Variable '%s' used before declaration", $2);
        yyerror(error_msg);
    } else {
        DataType type = sym->type;
        if (type == DT_PTR_INT || type == DT_PTR_CHAR || type == DT_PTR_REAL) {
            char error_msg[100];
            sprintf(error_msg, "Semantic Error: Cannot take address of pointer variable '%s'", $2);
            yyerror(error_msg);
        } else if (type != DT_INT && type != DT_REAL && type != DT_CHAR && type != DT_STRING) {
            char error_msg[100];
            sprintf(error_msg, "Semantic Error: Cannot take address of '%s' with type '%s'",
                    $2, get_name_from_type(type));
            yyerror(error_msg);
        }
    }

    $$ = make_node("&", 1, make_node($2, 0));
}

| ADDRESS ID LBRACK expr RBRACK {
    Symbol* sym = lookup_any_scope($2);
    if (!sym) {
        char error_msg[100];
        sprintf(error_msg, "Semantic Error: Variable '%s' used before declaration", $2);
        yyerror(error_msg);
    } else if (sym->type != DT_STRING) {
        char error_msg[100];
        sprintf(error_msg, "Semantic Error: [] operator can only be used with string type, '%s' is of type %s", 
                $2, get_name_from_type(sym->type));
        yyerror(error_msg);
    } else {
        check_string_index($4);
    }
    
    
    $$ = make_node("&array_access", 2, make_node($2, 0), $4);
}

       

%%

void yyerror(const char* s) {
    extern char* yytext;
    fprintf(stderr, "Syntax Error: %s (current token: %s)\n", s, yytext);
}

int main(int argc, char* argv[]) {
    printf("DEBUG: Starting compiler\n");

    enter_scope();
    int result = yyparse();

    printf("\nDEBUG: Final symbol tables:\n");
    print_symbol_tables();
    preserve_symbol_tables = 1;
    exit_scope();

    // בדוק אם יש _main_ רק אם הפרסינג הצליח
    if (result == 0 && !main_defined) {
        yyerror("Semantic Error: No _main_ function defined");
    }

    // גנרט קוד 3AC תמיד אם הפרסינג הצליח (ללא תלות ב-main)
    if (result == 0 && program_ast) {
        printf("\n=== THREE ADDRESS CODE ===\n");
        generate_tac_from_ast(program_ast);
    } else if (result != 0) {
        printf("Parsing failed, cannot generate 3AC\n");
    } else if (!program_ast) {
        printf("No AST available for 3AC generation\n");
    }

    return result;
}
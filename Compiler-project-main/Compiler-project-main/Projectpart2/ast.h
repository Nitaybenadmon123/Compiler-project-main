#ifndef AST_H
#define AST_H

typedef struct ast_node {
    char* name;
    struct ast_node** children;
    int child_count;
} AST;

// הצהרות פונקציות
AST* make_node(char* name, int count, ...);
void print_ast(AST* node, int indent);
void print_ast_debug(AST* node, int depth);

#endif // AST_H
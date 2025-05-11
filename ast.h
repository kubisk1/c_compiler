#ifndef AST_H
#define AST_H

typedef enum {
    AST_DUMMY
} ASTType;

typedef struct ASTNode {
    ASTType type;
    // Add child nodes later
} ASTNode;

ASTNode* create_dummy_ast();

#endif

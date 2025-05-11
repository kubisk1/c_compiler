#ifndef LEXER_H
#define LEXER_H

typedef enum {
    TOKEN_EOF,
    TOKEN_INT,
    TOKEN_RETURN,
    TOKEN_IDENTIFIER
} TokenType;

typedef struct {
    TokenType type;
    const char* lexeme;
    int line;
} Token;

Token get_next_token();

#endif

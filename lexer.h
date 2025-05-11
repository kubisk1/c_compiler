#ifndef LEXER_H
#define LEXER_H

typedef enum {
    TOKEN_EOF,
    TOKEN_INT,
    TOKEN_MAIN,
    TOKEN_RETURN,
    TOKEN_NUMBER,
    TOKEN_LPAREN,  // (
    TOKEN_RPAREN,  // )
    TOKEN_LBRACE,  // {
    TOKEN_RBRACE,  // }
    TOKEN_SEMI     // ;
} TokenType;

typedef struct {
    TokenType type;
    int value; // for numbers
} Token;

void init_lexer(const char* src);
Token get_next_token();

#endif

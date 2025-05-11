#ifndef LEXER_H
#define LEXER_H

typedef enum {
    TOKEN_EOF,
    TOKEN_INT,
    TOKEN_MAIN,
    TOKEN_RETURN,
    TOKEN_NUMBER,
    TOKEN_PUTS,
    TOKEN_STRING,      // ← NEW
    TOKEN_LPAREN,
    TOKEN_RPAREN,
    TOKEN_LBRACE,
    TOKEN_RBRACE,
    TOKEN_SEMI
} TokenType;

typedef struct {
    TokenType type;
    const char* lexeme;  // ← użyj lexeme do stringów
    int value;
} Token;

void init_lexer(const char* src);
Token get_next_token(void);


#endif

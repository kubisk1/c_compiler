#include "parser.h"
#include "lexer.h"
#include "codegen.h"
#include <stdio.h>
#include <stdlib.h>

static Token current;

static void advance() {
    current = get_next_token();
}

static void expect(TokenType type) {
    if (current.type != type) {
        printf("Unexpected token: %s\n", current.lexeme);
        exit(1);
    }
    advance();
}

void parse_and_generate() {
    advance(); expect(TOKEN_INT);
    expect(TOKEN_MAIN);
    expect(TOKEN_LPAREN);
    expect(TOKEN_RPAREN);
    expect(TOKEN_LBRACE);

    if (current.type == TOKEN_PUTS) {
        advance();
        expect(TOKEN_LPAREN);
        if (current.type != TOKEN_STRING) {
            printf("Expected string in puts()\n");
            exit(1);
        }
        const char* text = current.lexeme;
        advance();
        expect(TOKEN_RPAREN);
        expect(TOKEN_SEMI);

        generate_puts_program(text);
    }

    expect(TOKEN_RETURN);
    expect(TOKEN_NUMBER);
    expect(TOKEN_SEMI);
    expect(TOKEN_RBRACE);
}

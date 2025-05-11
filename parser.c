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
        printf("Unexpected token. Exiting.\n");
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
    expect(TOKEN_RETURN);

    int value = 0;
    if (current.type == TOKEN_NUMBER) {
        value = current.value;
        advance();
    }

    expect(TOKEN_SEMI);
    expect(TOKEN_RBRACE);

    generate_return_assembly(value);
}

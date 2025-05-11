#include "lexer.h"
#include <string.h>
#include <ctype.h>

static const char* input;
static size_t pos;

void init_lexer(const char* src) {
    input = src;
    pos = 0;
}

static void skip_whitespace() {
    while (isspace(input[pos])) pos++;
}

static int match(const char* kw) {
    size_t len = strlen(kw);
    return strncmp(&input[pos], kw, len) == 0 && !isalnum(input[pos + len]);
}

Token get_next_token() {
    skip_whitespace();

    if (input[pos] == '\0') return (Token){TOKEN_EOF, 0};

    if (match("int"))    { pos += 3; return (Token){TOKEN_INT, 0}; }
    if (match("main"))   { pos += 4; return (Token){TOKEN_MAIN, 0}; }
    if (match("return")) { pos += 6; return (Token){TOKEN_RETURN, 0}; }

    char c = input[pos];
    if (isdigit(c)) {
        int val = 0;
        while (isdigit(input[pos])) {
            val = val * 10 + (input[pos++] - '0');
        }
        return (Token){TOKEN_NUMBER, val};
    }

    pos++;
    switch (c) {
        case '(': return (Token){TOKEN_LPAREN, 0};
        case ')': return (Token){TOKEN_RPAREN, 0};
        case '{': return (Token){TOKEN_LBRACE, 0};
        case '}': return (Token){TOKEN_RBRACE, 0};
        case ';': return (Token){TOKEN_SEMI, 0};
        default:  return (Token){TOKEN_EOF, 0}; // Unknown chars treated as EOF for now
    }
}

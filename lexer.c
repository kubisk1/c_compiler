#include "lexer.h"
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

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

    if (input[pos] == '\0') return (Token){TOKEN_EOF, "", 0};

    if (match("int"))   { pos += 3; return (Token){TOKEN_INT, "int", 0}; }
    if (match("main"))  { pos += 4; return (Token){TOKEN_MAIN, "main", 0}; }
    if (match("return")){ pos += 6; return (Token){TOKEN_RETURN, "return", 0}; }
    if (match("puts"))  { pos += 4; return (Token){TOKEN_PUTS, "puts", 0}; }

    if (isdigit(input[pos])) {
        int val = 0;
        while (isdigit(input[pos])) {
            val = val * 10 + (input[pos++] - '0');
        }
        return (Token){TOKEN_NUMBER, "", val};
    }

    if (input[pos] == '"') {
        pos++; // skip opening "
        size_t start = pos;
        while (input[pos] != '"' && input[pos] != '\0') pos++;
        size_t len = pos - start;

        char* str = malloc(len + 1);
        strncpy(str, &input[start], len);
        str[len] = '\0';
        pos++; // skip closing "
        return (Token){TOKEN_STRING, str, 0};
    }

    char c = input[pos++];
    switch (c) {
        case '(': return (Token){TOKEN_LPAREN, "(", 0};
        case ')': return (Token){TOKEN_RPAREN, ")", 0};
        case '{': return (Token){TOKEN_LBRACE, "{", 0};
        case '}': return (Token){TOKEN_RBRACE, "}", 0};
        case ';': return (Token){TOKEN_SEMI, ";", 0};
        default:  return (Token){TOKEN_EOF, "", 0};
    }
}

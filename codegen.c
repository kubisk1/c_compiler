#include "codegen.h"
#include <stdio.h>

void generate_puts_program(const char* str) {
    FILE* out = fopen("output.c", "w");
    if (!out) {
        perror("fopen");
        return;
    }

    fprintf(out,
        "#include <stdio.h>\n"
        "int main() {\n"
        "    puts(\"%s\");\n"
        "    return 0;\n"
        "}\n", str);

    fclose(out);
}

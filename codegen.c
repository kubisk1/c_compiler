#include "codegen.h"
#include <stdio.h>

void generate_return_assembly(int value) {
    FILE* out = fopen("output.s", "w");
    if (!out) return;

    fprintf(out, ".global main\n");
    fprintf(out, "main:\n");
    fprintf(out, "    mov $%d, %%eax\n", value);
    fprintf(out, "    ret\n");

    fclose(out);
}

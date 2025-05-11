# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -std=c11 -Iinclude -g

# Output binary name
TARGET = mycc

# Source files
SRCS = main.c lexer.c parser.c ast.c sema.c codegen.c symbol_table.c utils.c

# Object files (replace .c with .o)
OBJS = $(SRCS:.c=.o)

# Default rule
all: $(TARGET)

# Link the final binary
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

# Compile .c to .o
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean build files
clean:
	rm -f $(OBJS) $(TARGET)

# Optional: run the compiler with a test file
run: $(TARGET)
	./$(TARGET) test.c

.PHONY: all clean run

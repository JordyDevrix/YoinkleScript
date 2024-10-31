#ifndef YOIKNLE_RUNTIME_H
#define YOINKLE_RUNTIME_H

#include "path_variable_scanner.h"
#include "file_reader.h"
#include "tokenizer.h"
#include "my_parser.h"

// Enum for the variable types
typedef enum {
    VAR_INT,
    VAR_FLOAT,
    VAR_STRING,
    VAR_BOOLEAN,
    VAR_NULL
} VarType;

// Variable stack
typedef struct {
    char *name;
    VarType type;
    union {
        long long int_value;
        float float_value;
        char *string_value;
        int boolean_value;
    } value;
} Variable;

// Functions stack with node and name
typedef struct {
    char *name;
    Node *node;
} Function;

void run_runtime(Node *AST, Token *p_tokens);

#endif

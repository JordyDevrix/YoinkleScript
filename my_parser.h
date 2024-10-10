#ifndef MY_PARSER_H
#define MY_PARSER_H

#include "path_variable_scanner.h"
#include "file_reader.h"
#include "tokenizer.h"

typedef enum {
    NODE_VAR_DECL,
    NODE_FUNC_DECL,
    NODE_IF_STMT,
    NODE_ELSE_STMT,
    NODE_RETURN_STMT,
    NODE_FOR_LOOP,
    NODE_WHILE_LOOP,
    NODE_ASSIGN,
    NODE_BIN_EXPR,
} NodeType;

typedef struct Node Node;

struct Node {
    int start_t;
    int end_t;
    NodeType type;
    int num_childs;
    struct Node *childs;
};

Node *parse_tokens(Token *p_tokens);

#endif

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
    NODE_FUNC_CALL,
    NODE_STR_LITERAL,
    NODE_INT_LITERAL,
    NODE_FLT_LITERAL,
    NODE_BOOL_LITERAL,
    NODE_OPERATOR,
    NODE_COMPARE,
    NODE_PAREN_OPEN,
    NODE_PAREN_CLOSE,
    NODE_END,
    NODE_IDENTIFIER,
    NODE_ARGS,
    NODE_ARRAY,
    NODE_ARRAY_CLOSE,
    NODE_CONDITION,
    NODE_STMT_BODY,
    NODE_BRACK_CLOSE,
    NODE_AST
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

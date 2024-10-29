#include "common.h"
#include "my_parser.h"

int depth = 0;
int i = 0;

void print_ast_recursive(Node *AST, Token *p_tokens) {
    for (int j = 0; j < depth; j++) {
        printf("   ");
    }

    switch (AST->type) {
        case NODE_VAR_DECL:
            printf("NODE_VAR_DECL - ST:%d ET:%d CHILD:%d\n", AST->start_t, AST->end_t, AST->num_childs);
            break;
        case NODE_FUNC_DECL:
            printf("NODE_FUNC_DECL - ST:%d ET:%d CHILD:%d\n", AST->start_t, AST->end_t, AST->num_childs);
            break;
        case NODE_IF_STMT:
            printf("NODE_IF_STMT - ST:%d ET:%d CHILD:%d\n", AST->start_t, AST->end_t, AST->num_childs);
            break;
        case NODE_ELSE_STMT:
            printf("NODE_ELSE_STMT - ST:%d ET:%d CHILD:%d\n", AST->start_t, AST->end_t, AST->num_childs);
            break;
        case NODE_RETURN_STMT:
            printf("NODE_RETURN_STMT - ST:%d ET:%d CHILD:%d\n", AST->start_t, AST->end_t, AST->num_childs);
            break;
        case NODE_FOR_LOOP:
            printf("NODE_FOR_LOOP - ST:%d ET:%d CHILD:%d\n", AST->start_t, AST->end_t, AST->num_childs);
            break;
        case NODE_WHILE_LOOP:
            printf("NODE_WHILE_LOOP - ST:%d ET:%d CHILD:%d\n", AST->start_t, AST->end_t, AST->num_childs);
            break;
        case NODE_ASSIGN:
            printf("NODE_ASSIGN - ST:%d ET:%d CHILD:%d\n", AST->start_t, AST->end_t, AST->num_childs);
            break;
        case NODE_BIN_EXPR:
            printf("NODE_BIN_EXPR - ST:%d ET:%d CHILD:%d\n", AST->start_t, AST->end_t, AST->num_childs);
            break;
        case NODE_FUNC_CALL:
            printf("NODE_FUNC_CALL - ST:%d ET:%d CHILD:%d\n", AST->start_t, AST->end_t, AST->num_childs);
            break;
        case NODE_LITERAL:
            printf("NODE_LITERAL - ST:%d ET:%d CHILD:%d\n", AST->start_t, AST->end_t, AST->num_childs);
            break;
        case NODE_OPERATOR:
            printf("NODE_OPERATOR - ST:%d ET:%d CHILD:%d\n", AST->start_t, AST->end_t, AST->num_childs);
            break;
        case NODE_ARGS:
            printf("NODE_ARGS - ST:%d ET:%d CHILD:%d\n", AST->start_t, AST->end_t, AST->num_childs);
            break;
        case NODE_ARGS_END:
            printf("NODE_ARGS_END - ST:%d ET:%d CHILD:%d\n", AST->start_t, AST->end_t, AST->num_childs);
            break;
        case NODE_END:
            printf("NODE_END - ST:%d ET:%d CHILD:%d\n", AST->start_t, AST->end_t, AST->num_childs);
            break;
        case NODE_IDENTIFIER:
            printf("NODE_IDENTIFIER - ST:%d ET:%d CHILD:%d\n", AST->start_t, AST->end_t, AST->num_childs);
            break;
        case NODE_AST:
            printf("NODE_AST - ST:%d ET:%d CHILD:%d\n", AST->start_t, AST->end_t, AST->num_childs);
            break;
        default:
            printf("NODE_UNKNOWN\n");
            break;
    }

    if (AST->num_childs > 0) {
        depth += 1;
        for (int j = 0; j < AST->num_childs; j++) {
            print_ast_recursive(&AST->childs[j], p_tokens);
        }
        depth -= 1;
    }

}


Node *parser(Token *p_tokens) {
    while (p_tokens[i].type != TOKEN_NULL) {
        Node *p_node = NULL;  
        // printf("Index: %d\n", i);
        // printf("Depth: %d\n", depth);

        switch (p_tokens[i].type) {
            case TOKEN_IDENTIFIER:
                // Allocate memory for the parent node
                // printf("identifier %s\n", p_tokens[i].value);
                ;
                p_node = malloc(sizeof(Node));

                // Define the parent node (which could be a variable)
                p_node->start_t = i;
                // This will be updated later (need to find the end token which is the semicolon)

                // Increase index by one to get the next token
                i += 1;
                Node *p_next = malloc(sizeof(Node));
                p_next = parser(p_tokens);
                if ((p_next->type == NODE_ASSIGN)) {
                    p_node->type = NODE_VAR_DECL;
                    p_node->num_childs = 2;
                    p_node->childs = malloc(p_node->num_childs * sizeof(Node));

                    // identifier
                    p_node->childs[0].type = NODE_IDENTIFIER;
                    p_node->childs[0].start_t = p_node->start_t;
                    p_node->childs[0].end_t = p_node->start_t;
                    p_node->childs[0].num_childs = 0;
                    p_node->childs[0].childs = NULL;

                    Node *p_child_value = parser(p_tokens);
                    p_node->childs[1] = *p_child_value;
                }

                if ((p_next->type == NODE_ARGS)) {
                    p_node->type = NODE_FUNC_CALL;
                    p_node->num_childs = 0;
                    p_node->childs = malloc(p_node->num_childs * sizeof(Node));
                    
                    // Inserting a list of args in the parent node while the next node is not NODE_ARGS_END
                    for (int j = 0; p_next->type != NODE_ARGS_END; j++) {
                        p_next = parser(p_tokens);
                        if (p_next->type == NODE_ARGS_END) {
                            break;
                        } else {
                            p_node->num_childs += 1;
                            p_node->childs = realloc(p_node->childs, p_node->num_childs * sizeof(Node));
                            p_node->childs[j] = *p_next;
                        }
                    }
                }

                if ((p_next->type == NODE_END)) {
                    p_node->type = NODE_IDENTIFIER;
                    p_node->num_childs = 0;
                    p_node->childs = NULL;
                    p_node->end_t = i-1;
                    return p_node;
                }

                p_node->end_t = i;

                i += 1;
                return p_node;
            case TOKEN_OPERATOR:
                // printf("Operator: %s\n", p_tokens[i].value);
                p_node = malloc(sizeof(Node));

                p_node->type = NODE_ASSIGN;
                p_node->start_t = i;
                p_node->end_t = i;
                p_node->num_childs = 0;
                p_node->childs = NULL;

                i += 1;
                return p_node;
            case TOKEN_COMPARATOR:
                i += 1;
                break;
            case TOKEN_KEYWORD:
                i += 1;
                break;
            case TOKEN_SYMBOL:
                // printf("Symbol: %s\n", p_tokens[i].value);
                if (strcmp(p_tokens[i].value, "(") == 0) {
                    p_node = malloc(sizeof(Node));

                    p_node->type = NODE_ARGS;
                    p_node->start_t = i;
                    p_node->end_t = i;
                    p_node->num_childs = 0;
                    p_node->childs = NULL;

                    i += 1;
                    return p_node;
                }

                if (strcmp(p_tokens[i].value, ")") == 0) {
                    p_node = malloc(sizeof(Node));

                    p_node->type = NODE_ARGS_END;
                    p_node->start_t = i;
                    p_node->end_t = i;
                    p_node->num_childs = 0;
                    p_node->childs = NULL;

                    return p_node;
                }

                if (strcmp(p_tokens[i].value, ";") == 0) {
                    p_node = malloc(sizeof(Node));

                    p_node->type = NODE_END;
                    p_node->start_t = i;
                    p_node->end_t = i;
                    p_node->num_childs = 0;
                    p_node->childs = NULL;

                    return p_node;
                }
            case TOKEN_STRING:
                // printf("String: %s\n", p_tokens[i].value);
                p_node = malloc(sizeof(Node));

                p_node->type = NODE_LITERAL;
                p_node->start_t = i;
                p_node->end_t = i;
                p_node->num_childs = 0;
                p_node->childs = NULL;

                i += 1;
                return p_node;
            case TOKEN_INTEGER:
                i += 1;
                break;
            case TOKEN_FLOAT:
                i += 1;
                break;
            case TOKEN_BOOLEAN:
                i += 1;
                break;
            default:
                printf("Unkown token: %s\n", p_tokens[i].value);
                exit(1);
                i += 1;
                break;
        }
    }
}

Node *parse_tokens(Token *p_tokens) {
    Node *node_list = NULL;

    int node_num = 0;
    while (p_tokens[i].type != TOKEN_NULL) {
        Node *p_node = parser(p_tokens);
        node_num += 1;
        // Imsert the node into the list of nodes
        node_list = realloc(node_list, node_num * sizeof(Node));
        node_list[node_num - 1] = *p_node;
    }

    // Printing the number of nodes
    // printf("Number of nodes: %d\n", node_num);

    // Inserting the nodes into the abstract syntax tree
    Node *AST = malloc(sizeof(Node));
    AST->type = NODE_AST;
    AST->start_t = 0;
    AST->end_t = node_num - 1;
    AST->num_childs = node_num;
    AST->childs = malloc(AST->num_childs * sizeof(Node));
    for (int j = 0; j < node_num; j++) {
        AST->childs[j] = node_list[j];
    }

    print_ast_recursive(AST, p_tokens);
}

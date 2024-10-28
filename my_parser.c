#include "common.h"
#include "my_parser.h"

int depth = 0;
int i = 0;
Node *parser(Token *p_tokens) {
    while (p_tokens[i].type != TOKEN_NULL) {
        Node *p_node = NULL;  
        // printf("Index: %d\n", i);
        // printf("Depth: %d\n", depth);

        switch (p_tokens[i].type) {
            case TOKEN_IDENTIFIER:
                // Allocate memory for the parent node
                printf("identifier %s\n", p_tokens[i].value);
                ;
                p_node = malloc(sizeof(Node));
                Node *p_identifier = malloc(sizeof(Node));

                // Define the parent node (which could be a variable)
                p_node->start_t = i;
                p_node->end_t = i; // This will be updated later (need to find the end token which is the semicolon)

                // Increase index by one to get the next token
                i += 1;
                Node *p_next = malloc(sizeof(Node));
                p_next = parser(p_tokens);
                if ((p_next->type == NODE_OPERATOR) && (strcmp(p_tokens[p_next->start_t].value, "=") == 0)) {
                    printf("Assignment\n");
                    p_node->type = NODE_VAR_DECL;
                    p_node->num_childs = 2;
                    p_node->childs = malloc(p_node->num_childs * sizeof(Node));
                    p_node->childs[0] = *p_identifier;
                    printf("Parent node type\n");
                    Node *p_child = parser(p_tokens);
                    p_node->childs[1] = *p_child;
                }

                i += 1;
                return p_node;
            case TOKEN_OPERATOR:
                printf("Operator: %s\n", p_tokens[i].value);
                p_node = malloc(sizeof(Node));

                p_node->type = NODE_OPERATOR;
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
                printf("Symbol: %s\n", p_tokens[i].value);
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
                break;
            case TOKEN_STRING:
                printf("String: %s\n", p_tokens[i].value);
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

    printf("Number of nodes: %d\n", node_list->num_childs);

    // Printing the number of child nodes
    printf("Number of child nodes: %d\n", node_list[0].childs[1].num_childs);
}


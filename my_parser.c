#include "common.h"
#include "my_parser.h"

Node node_list;

int depth = 0;
int i = 0;
Node *parse_tokens(Token *p_tokens) {
    while (p_tokens[i].type != TOKEN_NULL) {
        // printf("Index: %d\n", i);
        // printf("Depth: %d\n", depth);

        switch (p_tokens[i].type) {
            case TOKEN_IDENTIFIER:
                // // Allocate memory for the parent node
                // Node *p_node = malloc(sizeof(Node));

                // // Define the parent node (which could be a variable)
                // p_node->start_t = i;
                // p_node->end_t = i; // This will be updated later (need to find the end token which is the semicolon)

                // // Increase index by one to get the next token
                // i += 1;
                
                // // Define the child node(s)
                // Node *child_nodes = parse_tokens(p_tokens);
                
                // if (child_nodes->type == NODE_ASSIGN) {
                //     p_node->type = NODE_VAR_DECL;
                //     p_node->num_childs = 1;
                //     p_node->childs = malloc(2 * sizeof(Node));
                //     // Assign the child node(s) to the parent node
                //     p_node->childs[0] = child_nodes[0];
                // }

                i += 1;
                break;
            case TOKEN_OPERATOR:

                i += 1;
                break;
            case TOKEN_COMPARATOR:
                i += 1;
                break;
            case TOKEN_KEYWORD:
                i += 1;
                break;
            case TOKEN_SYMBOL:
                i += 1;
                break;
            case TOKEN_STRING:
                i += 1;
                // Node *p_node = malloc(sizeof(Node));
                // p_node->start_t = i;
                // p_node->end_t = i;
                // p_node->num_childs = 0;
                // p_node->childs = NULL;
                // return p_node;
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

    // Loop through all the nodes and child nodes
    printf("############################################\n");
    for (int j = 0; j < node_list.num_childs; j++) {
        printf("Node %d\n", j);
        printf("Start: %d\n", node_list.childs[j].start_t);
        printf("End: %d\n", node_list.childs[j].end_t);
        printf("Type: %d\n", node_list.childs[j].type);
        printf("Num childs: %d\n", node_list.childs[j].num_childs);
    }
}
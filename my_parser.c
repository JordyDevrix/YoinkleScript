#include "common.h"
#include "my_parser.h"

typedef struct Node Node;

struct Node {
    char *value;
    TokenType type;
    Node *next;
};


int depth = 0;
int parse_tokens(Token *p_tokens, int i) {
    while (p_tokens[i].type != TOKEN_NULL) {
        printf("Index: %d\n", i);
        printf("Depth: %d\n", depth);

        Node node1;
        node1.value = "example";
        node1.type = TOKEN_STRING;
        node1.next = NULL; // Next node is initially NULL

        // Create another Node and link it to the first
        Node node2;
        node2.value = "another example";
        node2.type = TOKEN_INTEGER;
        node1.next = &node2; // node1 now points to node2

        // Create another Node and link it to the second
        Node node3;
        node3.value = "yet another example";
        node3.type = TOKEN_FLOAT;
        node2.next = &node3; // node2 now points to node3

        // Print the values of the nodes
        printf("Node 1: %s\n", node3.value);
        printf("Node 3: %s\n", node1.next->next->value);


        switch (p_tokens[i].type) {
            case TOKEN_IDENTIFIER:
                printf("Identifier: %s\n", p_tokens[i].value);
                i += 1;
                switch (p_tokens[i].type) {
                    case TOKEN_OPERATOR:
                        if (strcmp(p_tokens[i].value, "=") == 0)
                            printf("Assignment: %s\n", p_tokens[i].value);
                        else
                            printf("Operator: %s\n", p_tokens[i].value);
                        break;
                    case TOKEN_COMPARATOR:
                        printf("Comparator: %s\n", p_tokens[i].value);
                        break;
                    case TOKEN_SYMBOL:
                        if (strcmp(p_tokens[i].value, "(") == 0) {
                            printf("Function call: %s\n", p_tokens[i].value);
                            depth += 1;
                        }
                        else if (strcmp(p_tokens[i].value, ")") == 0) {
                            printf("End of function call: %s\n", p_tokens[i].value);
                            depth -= 1;
                        }
                        else
                            printf("Symbol: %s\n", p_tokens[i].value);
                    default:
                        break;
                }
                break;
            case TOKEN_OPERATOR:
                printf("Operator: %s\n", p_tokens[i].value);
                i += 1;
                break;
            case TOKEN_COMPARATOR:
                printf("Comparator: %s\n", p_tokens[i].value);
                i += 1;
                break;
            case TOKEN_KEYWORD:
                printf("Keyword: %s\n", p_tokens[i].value);
                i += 1;
                break;
            case TOKEN_SYMBOL:
                printf("Symbol: %s\n", p_tokens[i].value);
                i += 1;
                break;
            case TOKEN_STRING:
                printf("String: %s\n", p_tokens[i].value);
                i += 1;
                break;
            case TOKEN_INTEGER:
                printf("Integer: %s\n", p_tokens[i].value);
                i += 1;
                break;
            case TOKEN_FLOAT:
                printf("Float: %s\n", p_tokens[i].value);
                i += 1;
                break;
            case TOKEN_BOOLEAN:
                printf("Boolean: %s\n", p_tokens[i].value);
                i += 1;
                break;
            default:
                printf("Unkown token: %s\n", p_tokens[i].value);
                exit(1);
                i += 1;
                break;
        }
    }

    return 0;
}
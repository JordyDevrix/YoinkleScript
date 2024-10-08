#include "common.h"
#include "my_parser.h"

typedef struct Node Node;

struct Node {
    char *value;
    TokenType type;
    int num_childs;
    struct Node *childs;
};



int depth = 0;
int parse_tokens(Token *p_tokens, int i) {
    while (p_tokens[i].type != TOKEN_NULL) {
        printf("Index: %d\n", i);
        printf("Depth: %d\n", depth);

        Node *nodep1 = malloc(sizeof(Node));
        nodep1->value = "I am the parent node";
        nodep1->type = TOKEN_STRING;
        nodep1->num_childs = 0;
        nodep1->childs = NULL;

        Node *nodec1 = malloc(sizeof(Node));
        nodec1->value = "I am a child node";
        nodec1->type = TOKEN_STRING;
        nodec1->num_childs = 0;
        nodec1->childs = NULL;

        Node *nodec2 = malloc(sizeof(Node));
        nodec2->value = "I am also a child node";
        nodec2->type = TOKEN_STRING;
        nodec2->num_childs = 0;
        nodec2->childs = NULL;

        nodep1->num_childs = 2;
        nodep1->childs = malloc(sizeof(Node) * 2);
        nodep1->childs[0] = *nodec1;
        nodep1->childs[1] = *nodec2;

        printf("Parent node value: %s\n", nodep1->value);
        printf("Child node value: %s\n", nodep1->childs[0].value);
        printf("Child node value: %s\n", nodep1->childs[1].value);

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
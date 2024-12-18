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
        case NODE_UNARY_EXPR:
            printf("NODE_UNARY_EXPR - ST:%d ET:%d CHILD:%d\n", AST->start_t, AST->end_t, AST->num_childs);
            break;
        case NODE_EXPR:
            printf("NODE_EXPR - ST:%d ET:%d CHILD:%d\n", AST->start_t, AST->end_t, AST->num_childs);
            break;
        case NODE_FUNC_CALL:
            printf("NODE_FUNC_CALL - ST:%d ET:%d CHILD:%d\n", AST->start_t, AST->end_t, AST->num_childs);
            break;
        case NODE_STR_LITERAL:
            printf("NODE_STR_LITERAL - ST:%d ET:%d CHILD:%d\n", AST->start_t, AST->end_t, AST->num_childs);
            break;
        case NODE_INT_LITERAL:
            printf("NODE_INT_LITERAL - ST:%d ET:%d CHILD:%d\n", AST->start_t, AST->end_t, AST->num_childs);
            break;
        case NODE_FLT_LITERAL:
            printf("NODE_FLT_LITERAL - ST:%d ET:%d CHILD:%d\n", AST->start_t, AST->end_t, AST->num_childs);
            break;
        case NODE_BOOL_LITERAL:
            printf("NODE_BOOL_LITERAL - ST:%d ET:%d CHILD:%d\n", AST->start_t, AST->end_t, AST->num_childs);
            break;
        case NODE_OPERATOR:
            printf("NODE_OPERATOR - ST:%d ET:%d CHILD:%d\n", AST->start_t, AST->end_t, AST->num_childs);
            break;
        case NODE_COMPARE:
            printf("NODE_COMPARE - ST:%d ET:%d CHILD:%d\n", AST->start_t, AST->end_t, AST->num_childs);
            break;
        case NODE_PAREN_OPEN:
            printf("NODE_PAREN_OPEN - ST:%d ET:%d CHILD:%d\n", AST->start_t, AST->end_t, AST->num_childs);
            break;
        case NODE_PAREN_CLOSE:
            printf("NODE_PAREN_CLOSE - ST:%d ET:%d CHILD:%d\n", AST->start_t, AST->end_t, AST->num_childs);
            break;
        case NODE_END:
            printf("NODE_END - ST:%d ET:%d CHILD:%d\n", AST->start_t, AST->end_t, AST->num_childs);
            break;
        case NODE_IDENTIFIER:
            printf("NODE_IDENTIFIER - ST:%d ET:%d CHILD:%d\n", AST->start_t, AST->end_t, AST->num_childs);
            break;
        case NODE_ARGS:
            printf("NODE_ARGS - ST:%d ET:%d CHILD:%d\n", AST->start_t, AST->end_t, AST->num_childs);
            break;
        case NODE_ARG:
            printf("NODE_ARG - ST:%d ET:%d CHILD:%d\n", AST->start_t, AST->end_t, AST->num_childs);
            break;
        case NODE_ARRAY:
            printf("NODE_ARRAY - ST:%d ET:%d CHILD:%d\n", AST->start_t, AST->end_t, AST->num_childs);
            break;
        case NODE_ARRAY_CLOSE:
            printf("NODE_ARRAY_CLOSE - ST:%d ET:%d CHILD:%d\n", AST->start_t, AST->end_t, AST->num_childs);
            break;
        case NODE_CONDITION:
            printf("NODE_CONDITION - ST:%d ET:%d CHILD:%d\n", AST->start_t, AST->end_t, AST->num_childs);
            break;
        case NODE_STMT_BODY:
            printf("NODE_STMT_BODY - ST:%d ET:%d CHILD:%d\n", AST->start_t, AST->end_t, AST->num_childs);
            break;
        case NODE_BRACK_CLOSE:
            printf("NODE_BRACK_CLOSE - ST:%d ET:%d CHILD:%d\n", AST->start_t, AST->end_t, AST->num_childs);
            break;
        case NODE_BREAK_STMT:
            printf("NODE_BREAK_STMT - ST:%d ET:%d CHILD:%d\n", AST->start_t, AST->end_t, AST->num_childs);
            break;
        case NODE_SKIP_STMT:
            printf("NODE_SKIP_STMT - ST:%d ET:%d CHILD:%d\n", AST->start_t, AST->end_t, AST->num_childs);
            break;
        case NODE_LIST_COMMA:
            printf("NODE_LIST_COMMA - ST:%d ET:%d CHILD:%d\n", AST->start_t, AST->end_t, AST->num_childs);
            break;
        case NODE_SHORT_CALC:
            printf("NODE_SHORT_CALC - ST:%d ET:%d CHILD:%d\n", AST->start_t, AST->end_t, AST->num_childs);
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
    // Lets see which tokens we have
    while (p_tokens[i].type != TOKEN_NULL) {
        Node *p_node = NULL;  

        switch (p_tokens[i].type) {
            case TOKEN_IDENTIFIER:
                // Making a NODE_FUNC_CALL node if the next token is a symbol and the token after that is a parenthesis
                if (p_tokens[i+1].type == TOKEN_SYMBOL && strcmp(p_tokens[i+1].value, "(") == 0) {
                    p_node = malloc(sizeof(Node));
                    p_node->type = NODE_FUNC_CALL;
                    p_node->start_t = i;
                    p_node->num_childs = 2;
                    p_node->childs = malloc(p_node->num_childs * sizeof(Node));

                    p_node->childs[0].type = NODE_IDENTIFIER;
                    p_node->childs[0].start_t = i;
                    p_node->childs[0].end_t = i;
                    p_node->childs[0].num_childs = 0;
                    p_node->childs[0].childs = NULL;

                    p_node->childs[1].type = NODE_ARGS;
                    p_node->childs[1].start_t = i;
                    p_node->childs[1].end_t = i;
                    p_node->childs[1].num_childs = 0;
                    p_node->childs[1].childs = NULL;

                    i += 2;
                    
                } 
                
                p_node = malloc(sizeof(Node));
                p_node->start_t = i;
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

                    p_node->end_t = i;
                    return p_node;
                } else {
                    // Checking if next token is an operator and the token after that is also an operator if so then its a increment operator
                    i -= 1;
                    p_node->start_t = i-1;

                    if (p_tokens[i].type == TOKEN_OPERATOR && p_tokens[i+1].type == TOKEN_OPERATOR) {
                        p_node->type = NODE_SHORT_CALC;
                        p_node->num_childs = 3;

                        p_node->childs = malloc(p_node->num_childs * sizeof(Node));

                        p_node->childs[0].type = NODE_IDENTIFIER;
                        p_node->childs[0].start_t = i-1;
                        p_node->childs[0].end_t = i-1;
                        p_node->childs[0].num_childs = 0;
                        p_node->childs[0].childs = NULL;

                        p_node->childs[1].type = NODE_OPERATOR;
                        p_node->childs[1].start_t = i;
                        p_node->childs[1].end_t = i;
                        p_node->childs[1].num_childs = 0;
                        p_node->childs[1].childs = NULL;

                        i += 2;
                        Node *p_value = parser(p_tokens);
                        p_node->childs[2] = *p_value;

                        p_node->end_t = i+1;
                        return p_node;
                    }

                    // Check if the next token is an operator
                    if (p_tokens[i].type == TOKEN_OPERATOR || p_tokens[i].type == TOKEN_COMPARATOR) {
                        if (p_tokens[i].type == TOKEN_OPERATOR) {
                            p_node->type = NODE_BIN_EXPR;
                        } else {
                            p_node->type = NODE_CONDITION;
                        }
                        p_node->num_childs = 3;

                        p_node->childs = malloc(p_node->num_childs * sizeof(Node));

                        p_node->childs[0].type = NODE_IDENTIFIER;
                        p_node->childs[0].start_t = i-1;
                        p_node->childs[0].end_t = i-1;
                        p_node->childs[0].num_childs = 0;
                        p_node->childs[0].childs = NULL;

                        if (p_tokens[i].type == TOKEN_OPERATOR) {
                            p_node->childs[1].type = NODE_OPERATOR;
                        } else {
                            p_node->childs[1].type = NODE_COMPARE;
                        }
                        p_node->childs[1].start_t = i;
                        p_node->childs[1].end_t = i;
                        p_node->childs[1].num_childs = 0;
                        p_node->childs[1].childs = NULL;

                        i += 1;
                        Node *p_value = parser(p_tokens);
                        p_node->childs[2] = *p_value;

                        p_node->end_t = i;
                        return p_node;
                    } 

                    p_node->type = NODE_IDENTIFIER;
                    p_node->end_t = i-1;
                    p_node->num_childs = 0;
                    p_node->childs = NULL;

                    return p_node;
                }

                p_node->end_t = i;

                i += 1;
                return p_node;
            case TOKEN_OPERATOR:
                if (strcmp(p_tokens[i].value, "=") == 0) {
                    p_node = malloc(sizeof(Node));

                    p_node->type = NODE_ASSIGN;
                    p_node->start_t = i;
                    p_node->end_t = i;
                    p_node->num_childs = 0;
                    p_node->childs = NULL;

                    i += 1;
                    return p_node;
                } else {
                    p_node = malloc(sizeof(Node));

                    p_node->type = NODE_OPERATOR;
                    p_node->start_t = i;
                    p_node->end_t = i;
                    p_node->num_childs = 0;
                    p_node->childs = NULL;

                    i += 1;
                    return p_node;
                }
            case TOKEN_COMPARATOR:
                p_node = malloc(sizeof(Node));

                    p_node->type = NODE_COMPARE;
                    p_node->start_t = i;
                    p_node->end_t = i;
                    p_node->num_childs = 0;
                    p_node->childs = NULL;

                    i += 1;
                    return p_node;
                break;
            case TOKEN_KEYWORD:
                if (strcmp(p_tokens[i].value, "if") == 0) {
                    p_node = malloc(sizeof(Node));

                    p_node->type = NODE_IF_STMT;
                    p_node->start_t = i;
                    p_node->num_childs = 0;
                    
                    i += 1;
                    // Parsing the condition
                    Node *p_child = parser(p_tokens);
                    p_child->type = NODE_CONDITION;
                    p_node->num_childs += 1;
                    p_node->childs = malloc(p_node->num_childs * sizeof(Node));
                    p_node->childs[0] = *p_child;
                    
                    // Parsing the body
                    Node *p_body = parser(p_tokens);
                    p_node->num_childs += 1;
                    p_node->childs = realloc(p_node->childs, p_node->num_childs * sizeof(Node));
                    p_node->childs[1] = *p_body;

                    // Parsing the else statement if it exists
                    if (p_tokens[i].type == TOKEN_KEYWORD && strcmp(p_tokens[i].value, "else") == 0) {
                        i += 1;
                        Node *p_else = parser(p_tokens);
                        p_else->type = NODE_ELSE_STMT;
                        p_node->num_childs += 1;
                        p_node->childs = realloc(p_node->childs, p_node->num_childs * sizeof(Node));
                        p_node->childs[2] = *p_else;
                    }

                    p_node->end_t = i;
                    i += 1;
                    return p_node;
                }

                // Checking for functions
                if (strcmp(p_tokens[i].value, "task") == 0) {
                    p_node = malloc(sizeof(Node));

                    p_node->type = NODE_FUNC_DECL;
                    p_node->start_t = i;
                    p_node->num_childs = 0;

                    i += 1;
                    // Parsing the function name
                    Node *p_child = parser(p_tokens);
                    p_child->type = NODE_IDENTIFIER;
                    p_node->num_childs += 1;
                    p_node->childs = malloc(p_node->num_childs * sizeof(Node));
                    p_node->childs[0] = *p_child;

                    // Parsing the body
                    Node *p_body = parser(p_tokens);

                    p_node->num_childs += 1;
                    p_node->childs = realloc(p_node->childs, p_node->num_childs * sizeof(Node));
                    p_node->childs[1] = *p_body;

                    p_node->end_t = i;
                    i += 1;
                    return p_node;
                }

                // Checking for return statement
                if (strcmp(p_tokens[i].value, "return") == 0) {
                    p_node = malloc(sizeof(Node));
                    int line = p_tokens[i].start;
                    p_node->type = NODE_RETURN_STMT;
                    p_node->start_t = i;
                    p_node->num_childs = 0;

                    i += 1;
                    // Parsing the return value
                    Node *p_child = parser(p_tokens);
                    if (strcmp(p_tokens[i].value, ";") != 0) {
                        printf("\033[1;31m\nError at line %d:\n\tExpected a semicolon after return statement\033[0m\n", line);
                        exit(1);
                    }
                    p_node->num_childs += 1;
                    p_node->childs = malloc(p_node->num_childs * sizeof(Node));
                    p_node->childs[0] = *p_child;

                    p_node->end_t = i;
                    i += 1;
                    return p_node;
                }

                // Checking for break statement
                if (strcmp(p_tokens[i].value, "break") == 0) {
                    p_node = malloc(sizeof(Node));

                    p_node->type = NODE_BREAK_STMT;
                    p_node->start_t = i;
                    p_node->end_t = i;
                    p_node->num_childs = 0;
                    p_node->childs = NULL;

                    i += 1;
                    return p_node;
                }

                // Checking for skip statement
                if (strcmp(p_tokens[i].value, "skip") == 0) {
                    p_node = malloc(sizeof(Node));

                    p_node->type = NODE_SKIP_STMT;
                    p_node->start_t = i;
                    p_node->end_t = i;
                    p_node->num_childs = 0;
                    p_node->childs = NULL;

                    i += 1;
                    return p_node;
                }

                // Checking for the while loop
                if (strcmp(p_tokens[i].value, "while") == 0) {
                    p_node = malloc(sizeof(Node));

                    p_node->type = NODE_WHILE_LOOP;
                    p_node->start_t = i;
                    p_node->num_childs = 0;

                    i += 1;
                    // Parsing the condition
                    Node *p_child = parser(p_tokens);
                    p_child->type = NODE_CONDITION;
                    p_node->num_childs += 1;
                    p_node->childs = malloc(p_node->num_childs * sizeof(Node));
                    p_node->childs[0] = *p_child;
                    
                    // Parsing the body
                    Node *p_body = parser(p_tokens);
                    p_node->num_childs += 1;
                    p_node->childs = realloc(p_node->childs, p_node->num_childs * sizeof(Node));
                    p_node->childs[1] = *p_body;

                    p_node->end_t = i;
                    i += 1;
                    return p_node;
                }

                break;
            case TOKEN_SYMBOL:
                if (strcmp(p_tokens[i].value, ",") == 0) {
                    p_node = malloc(sizeof(Node));
                    p_node->type = NODE_LIST_COMMA;
                    p_node->start_t = i;
                    p_node->end_t = i;
                    p_node->num_childs = 0;
                    p_node->childs = NULL;
                    i += 1;
                    return p_node;
                }
                if (strcmp(p_tokens[i].value, "[") == 0) {
                    p_node = malloc(sizeof(Node));

                    p_node->type = NODE_ARRAY;
                    p_node->start_t = i;
                    p_node->end_t = i;
                    p_node->num_childs = 0;
                    p_node->childs = NULL;

                    i += 1;
                    for (int j = 0; p_tokens[i].type != TOKEN_NULL; j++) {
                        Node *p_child = parser(p_tokens);
                        if (p_child->type == NODE_ARRAY_CLOSE) {
                            break;
                        } else {
                            p_node->num_childs += 1;

                            p_node->childs = realloc(p_node->childs, p_node->num_childs * sizeof(Node));
                            p_node->childs[j] = *p_child;
                        }
                    }
                    return p_node;
                }

                if (strcmp(p_tokens[i].value, "]") == 0) {
                    p_node = malloc(sizeof(Node));

                    p_node->type = NODE_ARRAY_CLOSE;
                    p_node->start_t = i;
                    p_node->end_t = i;
                    p_node->num_childs = 0;
                    p_node->childs = NULL;

                    i += 1;
                    return p_node;
                }

                if (strcmp(p_tokens[i].value, "(") == 0) {
                    Node *p_first = malloc(sizeof(Node));

                    p_first->type = NODE_BIN_EXPR;
                    p_first->start_t = i;
                    p_first->end_t = i;
                    p_first->num_childs = 0;
                    p_first->childs = NULL;

                    i += 1;
                    int childs_pos = 0;
                    for (int j = 0; p_tokens[i].type != TOKEN_NULL; j++) {
                        Node *p_child = parser(p_tokens);
                        if (p_child->type == NODE_PAREN_CLOSE) {
                            break;
                        } else if (p_child->type == NODE_LIST_COMMA) {
                            continue;
                        } else {
                            p_first->num_childs += 1;

                            p_first->childs = realloc(p_first->childs, p_first->num_childs * sizeof(Node));
                            if (p_first->childs == NULL) {
                                printf("Error: Could not allocate memory for bin expr\n");
                                exit(1);
                            }
                            p_first->childs[childs_pos] = *p_child;
                            childs_pos += 1;
                        }
                    }

                    // Check if the next token is an operator
                    if (p_tokens[i].type == TOKEN_OPERATOR) {
                        Node *p_operator = malloc(sizeof(Node));
                        p_operator->type = NODE_OPERATOR;
                        p_operator->start_t = i;
                        p_operator->end_t = i;
                        p_operator->num_childs = 0;
                        p_operator->childs = NULL;

                        i += 1;
                        Node *p_child_value = parser(p_tokens);
                        p_first->num_childs += 1;
                        p_first->childs = realloc(p_first->childs, p_first->num_childs * sizeof(Node));
                        p_first->childs[childs_pos] = *p_operator;
                        p_first->num_childs += 1;
                        p_first->childs = realloc(p_first->childs, p_first->num_childs * sizeof(Node));
                        p_first->childs[childs_pos+1] = *p_child_value;
                        return p_first;
                    } else {
                        if (p_first->childs[1].type == NODE_COMPARE) {
                            p_first->type = NODE_CONDITION;
                            return p_first;
                        } else {
                            return p_first;
                        }
                    }
                }

                if (strcmp(p_tokens[i].value, ")") == 0) {
                    p_node = malloc(sizeof(Node));

                    p_node->type = NODE_PAREN_CLOSE;
                    p_node->start_t = i;
                    p_node->end_t = i;
                    p_node->num_childs = 0;
                    p_node->childs = NULL;

                    i += 1;
                    return p_node;
                }
                if (strcmp(p_tokens[i].value, "{") == 0) {
                    p_node = malloc(sizeof(Node));

                    p_node->type = NODE_STMT_BODY;
                    p_node->start_t = i;
                    p_node->num_childs = 0;
                    p_node->childs = NULL;

                    i += 1;
                    int childs_pos = 0;
                    for (int j = 0; p_tokens[i].type != TOKEN_NULL; j++) {
                        Node *p_child = parser(p_tokens);
                        if (p_child->type == NODE_BRACK_CLOSE) {
                            break;
                        } else if (p_child->type == NODE_END) {
                            continue;
                        } else {
                            p_node->num_childs += 1;

                            p_node->childs = realloc(p_node->childs, p_node->num_childs * sizeof(Node));
                            p_node->childs[childs_pos] = *p_child;
                            childs_pos += 1;
                        }
                    }
                    p_node->end_t = i;
                    return p_node;
                }

                if (strcmp(p_tokens[i].value, "}") == 0) {
                    p_node = malloc(sizeof(Node));

                    p_node->type = NODE_BRACK_CLOSE;
                    p_node->start_t = i;
                    p_node->end_t = i;
                    p_node->num_childs = 0;
                    p_node->childs = NULL;

                    i += 1;
                    return p_node;
                }

                if (strcmp(p_tokens[i].value, ";") == 0) {
                    p_node = malloc(sizeof(Node));

                    p_node->type = NODE_END;
                    p_node->start_t = i;
                    p_node->end_t = i;
                    p_node->num_childs = 0;
                    p_node->childs = NULL;

                    i += 1;
                    return p_node;
                }
            case TOKEN_STRING:
                p_node = malloc(sizeof(Node));
                p_node->start_t = i;
                p_node->type = NODE_STR_LITERAL;
                p_node->end_t = i;
                p_node->num_childs = 0;
                p_node->childs = NULL;
                i += 1;
                return p_node;

            case TOKEN_INTEGER:
                p_node = malloc(sizeof(Node));
                p_node->start_t = i;
                p_node->type = NODE_INT_LITERAL;
                p_node->end_t = i;
                p_node->num_childs = 0;
                p_node->childs = NULL;
                i += 1;
                return p_node;

            case TOKEN_FLOAT:
                p_node = malloc(sizeof(Node));
                p_node->start_t = i;
                p_node->type = NODE_FLT_LITERAL;
                p_node->end_t = i;
                p_node->num_childs = 0;
                p_node->childs = NULL;
                i += 1;
                return p_node;

            case TOKEN_BOOLEAN:
                p_node = malloc(sizeof(Node));
                p_node->start_t = i;
                p_node->type = NODE_BOOL_LITERAL;
                p_node->end_t = i;
                p_node->num_childs = 0;
                p_node->childs = NULL;
                i += 1;
                return p_node;

            default:
                printf("Unkown token: %s\n", p_tokens[i].value);
                exit(1);
                i += 1;
                break;
        }
    }
}

Node *parse_tokens(Token *p_tokens, int ast_flag) {
    Node *node_list = NULL;

    int node_num = 0;
    while (p_tokens[i].type != TOKEN_NULL) {
        Node *p_node = parser(p_tokens);
        if (p_node->type == NODE_END) {
            continue;
        }
        node_num += 1;
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
    
    if (ast_flag) {
        printf("v v v ABSTRACT SYNTAX TREE v v v\n");
        print_ast_recursive(AST, p_tokens);
    }

    return AST;    
}

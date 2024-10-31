#include "common.h"
// #include "yoinkle_runtime.h"
#include "standard_library.h"
#include <errno.h>
#include <limits.h>

int run_depth = 0;

Variable *var_stack;
Function *function_stack;

int var_num = 0;
int function_num = 0;

int in_function = 0;

Variable *runtime(Node *NODE, Token *p_tokens, Node *AST) {
    switch (NODE->type) {
        Variable *new_var;
        case NODE_VAR_DECL:
            ;
            char *var_name = p_tokens[NODE->childs[0].start_t].value;

            // Getting the second child of the node
            new_var = runtime(&NODE->childs[1], p_tokens, AST);
            
            // Checking if the variable already exists
            int variable_exists = 0;
            for (int i = 0; i < var_num; i++) {
                if (strcmp(var_stack[i].name, var_name) == 0) {
                    // Changing the value of the variable
                    new_var->name = var_name;
                    var_stack[i] = *new_var;
                    variable_exists = 1;
                }
            }
            if (variable_exists) {
                break;
            }
            
            var_stack = realloc(var_stack, sizeof(Variable) * (var_num + 1));
            var_stack[var_num] = *new_var;
            var_stack[var_num].name = var_name;
            var_num++;
            break;
        case NODE_STR_LITERAL:
            ;
            char *string_value = p_tokens[NODE->start_t].value;
            new_var = malloc(sizeof(Variable));
            new_var->name = NULL;
            new_var->type = VAR_STRING;
            new_var->value.string_value = string_value;
            return new_var;
        case NODE_INT_LITERAL:
            ;
            errno = 0; // Clear errno before conversion
            char *end;

            long long int_value = strtoll(p_tokens[NODE->start_t].value, &end, 10);

            if (errno == ERANGE) {
                printf("Number out of range for long long.\n");
                exit(1);
            } else if (*end != '\0') {
                printf("Conversion stopped at unexpected character: %c\n", *end);
                exit(1);
            }
            new_var = malloc(sizeof(Variable));
            new_var->name = NULL;
            new_var->type = VAR_INT;
            new_var->value.int_value = int_value;
            return new_var;
        case NODE_FLT_LITERAL:
            ;
            float float_value = atof(p_tokens[NODE->start_t].value);
            new_var = malloc(sizeof(Variable));
            new_var->name = NULL;
            new_var->type = VAR_FLOAT;
            new_var->value.float_value = float_value;
            return new_var;
        case NODE_BOOL_LITERAL:
            ;
            int bool_value = strcmp(p_tokens[NODE->start_t].value, "True") == 0 ? 1 : 0;
            new_var = malloc(sizeof(Variable));
            new_var->name = NULL;
            new_var->type = VAR_BOOLEAN;
            new_var->value.boolean_value = bool_value;
            return new_var;
        case NODE_IDENTIFIER:
            ;
            char *identifier = p_tokens[NODE->start_t].value;
            int var_found = 0;
            for (int i = 0; i < var_num; i++) {
                if (strcmp(var_stack[i].name, identifier) == 0) {
                    return &var_stack[i];
                    var_found = 1;
                }
            }
            if (!var_found) {
                printf("Error: Variable '%s' not found\n", identifier);
                exit(1);
            }
            break;
        case NODE_BIN_EXPR:
            ;
            Variable *left = runtime(&NODE->childs[0], p_tokens, AST);
            Variable *right = runtime(&NODE->childs[2], p_tokens, AST);
            Variable *result = malloc(sizeof(Variable));
            result->name = NULL;
            if ((left->type == VAR_INT && right->type == VAR_INT)) {
                result->type = VAR_INT;
                if (strcmp(p_tokens[NODE->childs[1].start_t].value, "+") == 0) {
                    result->value.int_value = left->value.int_value + right->value.int_value;
                } else if (strcmp(p_tokens[NODE->childs[1].start_t].value, "-") == 0) {
                    result->value.int_value = left->value.int_value - right->value.int_value;
                } else if (strcmp(p_tokens[NODE->childs[1].start_t].value, "*") == 0) {
                    result->value.int_value = left->value.int_value * right->value.int_value;
                } else if (strcmp(p_tokens[NODE->childs[1].start_t].value, "/") == 0) {
                    result->value.int_value = left->value.int_value / right->value.int_value;
                }
            } else if (left->type == VAR_FLOAT && right->type == VAR_FLOAT) {
                result->type = VAR_FLOAT;
                if (strcmp(p_tokens[NODE->childs[1].start_t].value, "+") == 0) {
                    result->value.float_value = left->value.float_value + right->value.float_value;
                } else if (strcmp(p_tokens[NODE->childs[1].start_t].value, "-") == 0) {
                    result->value.float_value = left->value.float_value - right->value.float_value;
                } else if (strcmp(p_tokens[NODE->childs[1].start_t].value, "*") == 0) {
                    result->value.float_value = left->value.float_value * right->value.float_value;
                } else if (strcmp(p_tokens[NODE->childs[1].start_t].value, "/") == 0) {
                    result->value.float_value = left->value.float_value / right->value.float_value;
                }
            } else if (left->type == VAR_INT && right->type == VAR_FLOAT) {
                result->type = VAR_FLOAT;
                if (strcmp(p_tokens[NODE->childs[1].start_t].value, "+") == 0) {
                    result->value.float_value = left->value.int_value + right->value.float_value;
                } else if (strcmp(p_tokens[NODE->childs[1].start_t].value, "-") == 0) {
                    result->value.float_value = left->value.int_value - right->value.float_value;
                } else if (strcmp(p_tokens[NODE->childs[1].start_t].value, "*") == 0) {
                    result->value.float_value = left->value.int_value * right->value.float_value;
                } else if (strcmp(p_tokens[NODE->childs[1].start_t].value, "/") == 0) {
                    result->value.float_value = left->value.int_value / right->value.float_value;
                }
            } else if (left->type == VAR_FLOAT && right->type == VAR_INT) {
                result->type = VAR_FLOAT;
                if (strcmp(p_tokens[NODE->childs[1].start_t].value, "+") == 0) {
                    result->value.float_value = left->value.float_value + right->value.int_value;
                } else if (strcmp(p_tokens[NODE->childs[1].start_t].value, "-") == 0) {
                    result->value.float_value = left->value.float_value - right->value.int_value;
                } else if (strcmp(p_tokens[NODE->childs[1].start_t].value, "*") == 0) {
                    result->value.float_value = left->value.float_value * right->value.int_value;
                } else if (strcmp(p_tokens[NODE->childs[1].start_t].value, "/") == 0) {
                    result->value.float_value = left->value.float_value / right->value.int_value;
                }
            } else if (left->type == VAR_STRING && right->type == VAR_STRING) {
                result->type = VAR_STRING;
                char *new_string = malloc(strlen(left->value.string_value) + strlen(right->value.string_value) + 1);
                strcpy(new_string, left->value.string_value);
                strcat(new_string, right->value.string_value);
                result->value.string_value = new_string;
            } else if ((left->type == VAR_STRING && (right->type == VAR_INT || right->type == VAR_FLOAT || right->type == VAR_BOOLEAN)) && strcmp(p_tokens[NODE->childs[1].start_t].value, "+") == 0) {
                result->type = VAR_STRING;
                char *new_string = malloc(strlen(left->value.string_value) + 20);
                if (right->type == VAR_INT) {
                    sprintf(new_string, "%s%d", left->value.string_value, right->value.int_value);
                } else if (right->type == VAR_FLOAT) {
                    sprintf(new_string, "%s%f", left->value.string_value, right->value.float_value);
                } else if (right->type == VAR_BOOLEAN) {
                    sprintf(new_string, "%s%s", left->value.string_value, right->value.boolean_value ? "True" : "False");
                }
                result->value.string_value = new_string;
            } else if (((left->type == VAR_INT || left->type == VAR_FLOAT || left->type == VAR_BOOLEAN) && right->type == VAR_STRING) && strcmp(p_tokens[NODE->childs[1].start_t].value, "+") == 0) {
                result->type = VAR_STRING;
                char *new_string = malloc(strlen(right->value.string_value) + 20);
                if (left->type == VAR_INT) {
                    sprintf(new_string, "%d%s", left->value.int_value, right->value.string_value);
                } else if (left->type == VAR_FLOAT) {
                    sprintf(new_string, "%f%s", left->value.float_value, right->value.string_value);
                } else if (left->type == VAR_BOOLEAN) {
                    sprintf(new_string, "%s%s", left->value.boolean_value ? "True" : "False", right->value.string_value);
                }
                result->value.string_value = new_string;
            } else {
                printf("Error: Unsupported operation\n");
                printf("Cannot perform operation of type %s and %s\n", 
                left->type == VAR_INT ? "int" : left->type == VAR_FLOAT ? "float" : left->type == VAR_STRING ? "string" : left->type == VAR_BOOLEAN ? "boolean" : "null", right->type == VAR_INT ? "int" : right->type == VAR_FLOAT ? "float" : right->type == VAR_STRING ? "string" : right->type == VAR_BOOLEAN ? "boolean" : "null");
                exit(1);
            }
            return result;

        case NODE_FUNC_CALL:
            ;
            // Getting arguments
            int num_args = NODE->childs[0].num_childs;
            Variable *args;
            if (num_args > 0) {
                args = malloc(sizeof(Variable) * num_args);
                if (args == NULL) {
                    printf("Error: Could not allocate memory for function arguments\n");
                    exit(1);
                }
                for (int i = 0; i < num_args; i++) {
                    args[i] = *runtime(&NODE->childs[0].childs[i], p_tokens, AST);
                }
            }
            
            // Getting function name
            char *func_name = p_tokens[NODE->start_t].value;

            // Checking if the function is a standard function
            if (strcmp(func_name, "print") == 0) {
                yoinkle_std_print(args, num_args);
            } else if (strcmp(func_name, "println") == 0) {
                yoinkle_std_println(args, num_args);
            } else if (strcmp(func_name, "exit") == 0) {
                int exit_code = 0;
                if (num_args > 0) {
                    exit_code = args[0].value.int_value;
                }
                yoinkle_std_exit(AST, p_tokens, var_stack, exit_code);
            } else if (strcmp(func_name, "read") == 0) {
                char *prompt = NULL;
                if (num_args > 0) {
                    prompt = args[0].value.string_value;
                }
                char *input = yoinkle_std_read(prompt);

                new_var = malloc(sizeof(Variable));
                new_var->name = NULL;

                // Checking if the input is an integer
                char *end;
                errno = 0;
                long long int_value = strtoll(input, &end, 10);
                if (errno == 0 && *end == '\0') {
                    new_var->type = VAR_INT;
                    new_var->value.int_value = int_value;
                    return new_var;
                }
                // Checking if the input is a float
                float float_value = strtof(input, &end);
                if (errno == 0 && *end == '\0') {
                    new_var->type = VAR_FLOAT;
                    new_var->value.float_value = float_value;
                    return new_var;
                }
                // Checking if the input is a boolean
                if (strcmp(input, "True") == 0 || strcmp(input, "False") == 0) {
                    new_var->type = VAR_BOOLEAN;
                    new_var->value.boolean_value = strcmp(input, "True") == 0 ? 1 : 0;
                    return new_var;
                }
                // If the input is not a one of the above, then it is a string
                new_var->type = VAR_STRING;
                new_var->value.string_value = input;
                return new_var;
            } else if (strcmp(func_name, "to_int") == 0) {
                new_var = yoinkle_std_value_to_int(&args[0]);
                return new_var;
            } else if (strcmp(func_name, "to_float") == 0) {
                new_var = yoinkle_std_value_to_float(&args[0]);
                return new_var;
            } else if (strcmp(func_name, "to_string") == 0) {
                new_var = yoinkle_std_value_to_string(&args[0]);
                return new_var;
            } else {
                // Checking if the function is a user defined function
                for (int i = 0; i < function_num; i++) {
                    if (strcmp(func_name, function_stack[i].name) == 0) {
                        Node *function_args = function_stack[i].node->childs[0].childs[0].childs;
                        Node *function_body = function_stack[i].node->childs;
                        // saving the current global variable stack
                        Variable *old_var_stack = var_stack;
                        int old_var_num = var_num;

                        // Creating a new variable stack for the function
                        var_stack = malloc(sizeof(Variable) * num_args);

                        // Adding the arguments to the variable stack
                        var_num = 0;
                        for (int j = 0; j < num_args; j++) {
                            var_stack = realloc(var_stack, sizeof(Variable) * (var_num + 1));
                            var_stack[j] = args[j];
                            var_stack[j].name = p_tokens[function_args[j].start_t].value;

                            var_num++;
                        }

                        // Running the function
                        Variable *result;
                        result = NULL;
                        for (int j = 0; j < function_body[1].num_childs; j++) {
                            if (function_body[1].childs[j].type == NODE_RETURN_STMT) {
                                result = runtime(&function_body[1].childs[j].childs[0], p_tokens, AST);
                                break;
                            }
                            runtime(&function_body[1].childs[j], p_tokens, AST);
                        }

                        // Freeing the variable stack
                        free(var_stack);

                        // Restoring the global variable stack
                        var_stack = old_var_stack;
                        var_num = old_var_num;
                        
                        // Freeing the arguments
                        free(args);

                        return result;
                    }
                }

            } 
            break;
        case NODE_IF_STMT:
            ;
            Variable *condition = runtime(&NODE->childs[0], p_tokens, AST);

            if (condition->value.boolean_value) {
                runtime(&NODE->childs[1].childs[0], p_tokens, AST);
            } else if (NODE->num_childs == 3 && NODE->childs[2].type == NODE_ELSE_STMT) {
                runtime(&NODE->childs[2].childs[0], p_tokens, AST);
            }
            break;

        case NODE_CONDITION:
            ;
            Variable *left_cond = runtime(&NODE->childs[0], p_tokens, AST);
            Variable *right_cond = runtime(&NODE->childs[2], p_tokens, AST);
            Variable *result_cond = malloc(sizeof(Variable));
            result_cond->name = NULL;
            if (left_cond->type == VAR_INT && right_cond->type == VAR_INT) {
                result_cond->type = VAR_BOOLEAN;
                if (strcmp(p_tokens[NODE->childs[1].start_t].value, "==") == 0) {
                    result_cond->value.boolean_value = left_cond->value.int_value == right_cond->value.int_value;
                } else if (strcmp(p_tokens[NODE->childs[1].start_t].value, "!=") == 0) {
                    result_cond->value.boolean_value = left_cond->value.int_value != right_cond->value.int_value;
                } else if (strcmp(p_tokens[NODE->childs[1].start_t].value, ">") == 0) {
                    result_cond->value.boolean_value = left_cond->value.int_value > right_cond->value.int_value;
                } else if (strcmp(p_tokens[NODE->childs[1].start_t].value, "<") == 0) {
                    result_cond->value.boolean_value = left_cond->value.int_value < right_cond->value.int_value;
                } else if (strcmp(p_tokens[NODE->childs[1].start_t].value, ">=") == 0) {
                    result_cond->value.boolean_value = left_cond->value.int_value >= right_cond->value.int_value;
                } else if (strcmp(p_tokens[NODE->childs[1].start_t].value, "<=") == 0) {
                    result_cond->value.boolean_value = left_cond->value.int_value <= right_cond->value.int_value;
                }
            } else if (left_cond->type == VAR_FLOAT && right_cond->type == VAR_FLOAT) {
                result_cond->type = VAR_BOOLEAN;
                if (strcmp(p_tokens[NODE->childs[1].start_t].value, "==") == 0) {
                    result_cond->value.boolean_value = left_cond->value.float_value == right_cond->value.float_value;
                } else if (strcmp(p_tokens[NODE->childs[1].start_t].value, "!=") == 0) {
                    result_cond->value.boolean_value = left_cond->value.float_value != right_cond->value.float_value;
                } else if (strcmp(p_tokens[NODE->childs[1].start_t].value, ">") == 0) {
                    result_cond->value.boolean_value = left_cond->value.float_value > right_cond->value.float_value;
                } else if (strcmp(p_tokens[NODE->childs[1].start_t].value, "<") == 0) {
                    result_cond->value.boolean_value = left_cond->value.float_value < right_cond->value.float_value;
                } else if (strcmp(p_tokens[NODE->childs[1].start_t].value, ">=") == 0) {
                    result_cond->value.boolean_value = left_cond->value.float_value >= right_cond->value.float_value;
                } else if (strcmp(p_tokens[NODE->childs[1].start_t].value, "<=") == 0) {
                    result_cond->value.boolean_value = left_cond->value.float_value <= right_cond->value.float_value;
                }
            } else if (left_cond->type == VAR_BOOLEAN && right_cond->type == VAR_BOOLEAN) {
                result_cond->type = VAR_BOOLEAN;
                if (strcmp(p_tokens[NODE->childs[1].start_t].value, "==") == 0) {
                    result_cond->value.boolean_value = left_cond->value.boolean_value == right_cond->value.boolean_value;
                } else if (strcmp(p_tokens[NODE->childs[1].start_t].value, "!=") == 0) {
                    result_cond->value.boolean_value = left_cond->value.boolean_value != right_cond->value.boolean_value;
                }
            } else if (left_cond->type == VAR_STRING && right_cond->type == VAR_STRING) {
                result_cond->type = VAR_BOOLEAN;
                if (strcmp(p_tokens[NODE->childs[1].start_t].value, "==") == 0) {
                    result_cond->value.boolean_value = strcmp(left_cond->value.string_value, right_cond->value.string_value) == 0;
                } else if (strcmp(p_tokens[NODE->childs[1].start_t].value, "!=") == 0) {
                    result_cond->value.boolean_value = strcmp(left_cond->value.string_value, right_cond->value.string_value) != 0;
                }
            } else {
                printf("Error: Unsupported operation\n");
                printf("Cannot perform operation of type %s and %s\n", 
                left_cond->type == VAR_INT ? "int" : left_cond->type == VAR_FLOAT ? "float" : left_cond->type == VAR_STRING ? "string" : left_cond->type == VAR_BOOLEAN ? "boolean" : "null", right_cond->type == VAR_INT ? "int" : right_cond->type == VAR_FLOAT ? "float" : right_cond->type == VAR_STRING ? "string" : right_cond->type == VAR_BOOLEAN ? "boolean" : "null");
                exit(1);
            }
            return result_cond;
        case NODE_FUNC_DECL:
            ;
            // Getting the function name
            char *func_decl_name = p_tokens[NODE->childs[0].start_t].value;

            // Adding the function to the function stack
            function_stack = realloc(function_stack, sizeof(Function) * (function_num + 1));
            function_stack[function_num].name = func_decl_name;
            function_stack[function_num].node = NODE;
            function_num++;
            break;
    }
}


void run_runtime(Node *AST, Token *p_tokens) {
    int ast_length = AST->num_childs;
    // printf("AST length: %d\n", ast_length);

    // Running AST per node
    for (int i = 0; i < ast_length; i++) {
        Node *current_node = &AST->childs[i];
        // printf("Running node %d\n", i);
        runtime(current_node, p_tokens, AST);
        // printf("  Variable stack length: %d\n", var_num);
        // for (int j = 0; j < var_num; j++) {
        //     if (var_stack[j].type == VAR_INT) {
        //         printf("  Variable %d: %s - %lld\n", j, var_stack[j].name, var_stack[j].value.int_value);
        //     } else if (var_stack[j].type == VAR_FLOAT) {
        //         printf("  Variable %d: %s - %f\n", j, var_stack[j].name, var_stack[j].value.float_value);
        //     } else if (var_stack[j].type == VAR_STRING) {
        //         printf("  Variable %d: %s - %s\n", j, var_stack[j].name, var_stack[j].value.string_value);
        //     } else if (var_stack[j].type == VAR_BOOLEAN) {
        //         printf("  Variable %d: %s - %s\n", j, var_stack[j].name, var_stack[j].value.boolean_value ? "True" : "False");
        //     } else {
        //         printf("  Variable %d: %s - NULL\n", j, var_stack[j].name);
        //     }
        // }
    }

}

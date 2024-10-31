#include "common.h"
#include "standard_library.h"

void yoinkle_std_print(Variable *args, int num_args) {
    // Printing the arguments
    // printf("Arg 2: %d\n", args[2].value.int_value);

    // If there are multiple arguments, then the first argument is a string
    // Getting the format string and replacing all the %V with the arguments
    char *format_string = args[0].value.string_value;
    int format_string_len = strlen(format_string);
    int format_string_index = 0;
    int arg_index = 1;
    if (num_args > 1) {
        for (int pos = 0; pos < format_string_len; pos++) {
            if (format_string[pos] == '%' && format_string[pos + 1] == 'V') {
                // Getting the argument
                Variable arg = args[arg_index];
                switch (arg.type) {
                    char *dest;
                    char *argument;
                    char *rest;
                    int arg_length;

                    case VAR_INT:
                        ;
                        // Copy the first part of the format string
                        dest = malloc(pos + 1);
                        strncpy(dest, format_string, pos);
                        dest[pos] = '\0';

                        // Insert the argument
                        arg_length = snprintf(NULL, 0, "%lld", arg.value.int_value);
                        argument = malloc(arg_length + 1); // Allocate space for string + null terminator
                        snprintf(argument, arg_length + 1, "%lld", arg.value.int_value); // Convert integer to string

                        // Copy the rest of the format string
                        rest = malloc(format_string_len - pos - 2);
                        strncpy(rest, format_string + pos + 2, format_string_len - pos - 2);
                        rest[format_string_len - pos - 2] = '\0';

                        // Concatenate the strings
                        format_string = malloc(strlen(dest) + strlen(argument) + strlen(rest) + 1);
                        strcpy(format_string, dest);
                        strcat(format_string, argument);
                        strcat(format_string, rest);
                        format_string_len = strlen(format_string);
                        free(dest);
                        free(argument);
                        free(rest);
                        arg_index++;
                        break;
                    case VAR_FLOAT:
                        ;
                        // Copy the first part of the format string
                        dest = malloc(pos + 1);
                        strncpy(dest, format_string, pos);
                        dest[pos] = '\0';

                        // Insert the argument
                        arg_length = snprintf(NULL, 0, "%f", arg.value.float_value);
                        argument = malloc(arg_length + 1); // Allocate space for string + null terminator
                        snprintf(argument, arg_length + 1, "%f", arg.value.float_value); // Convert float to string

                        // Copy the rest of the format string
                        rest = malloc(format_string_len - pos - 2);
                        strncpy(rest, format_string + pos + 2, format_string_len - pos - 2);
                        rest[format_string_len - pos - 2] = '\0';

                        // Concatenate the strings
                        format_string = malloc(strlen(dest) + strlen(argument) + strlen(rest) + 1);
                        strcpy(format_string, dest);
                        strcat(format_string, argument);
                        strcat(format_string, rest);
                        format_string_len = strlen(format_string);
                        free(dest);
                        free(argument);
                        free(rest);
                        arg_index++;
                        break;

                    case VAR_BOOLEAN:
                        ;
                        // Copy the first part of the format string
                        dest = malloc(pos + 1);
                        strncpy(dest, format_string, pos);
                        dest[pos] = '\0';

                        // Insert the argument
                        arg_length = snprintf(NULL, 0, "%s", arg.value.boolean_value ? "True" : "False");
                        argument = malloc(arg_length + 1); // Allocate space for string + null terminator
                        snprintf(argument, arg_length + 1, "%s", arg.value.boolean_value ? "True" : "False"); // Convert boolean to string

                        // Copy the rest of the format string
                        rest = malloc(format_string_len - pos - 2);
                        strncpy(rest, format_string + pos + 2, format_string_len - pos - 2);
                        rest[format_string_len - pos - 2] = '\0';

                        // Concatenate the strings
                        format_string = malloc(strlen(dest) + strlen(argument) + strlen(rest) + 1);
                        strcpy(format_string, dest);
                        strcat(format_string, argument);
                        strcat(format_string, rest);
                        format_string_len = strlen(format_string);
                        free(dest);
                        free(argument);
                        free(rest);
                        arg_index++;
                        break;

                    case VAR_STRING:
                        ;
                        // Copy the first part of the format string
                        dest = malloc(pos + 1);
                        strncpy(dest, format_string, pos);
                        dest[pos] = '\0';

                        // Insert the argument
                        arg_length = strlen(arg.value.string_value);
                        argument = malloc(arg_length + 1); // Allocate space for string + null terminator
                        strcpy(argument, arg.value.string_value); // Copy the string

                        // Copy the rest of the format string
                        rest = malloc(format_string_len - pos - 2);
                        strncpy(rest, format_string + pos + 2, format_string_len - pos - 2);
                        rest[format_string_len - pos - 2] = '\0';

                        // Concatenate the strings
                        format_string = malloc(strlen(dest) + strlen(argument) + strlen(rest) + 1);
                        strcpy(format_string, dest);
                        strcat(format_string, argument);
                        strcat(format_string, rest);
                        format_string_len = strlen(format_string);
                        free(dest);
                        free(argument);
                        free(rest);
                        arg_index++;
                        break;
                }
            }
        }
    }
    while (*format_string) 
    {
        if (*format_string == '\\') {
            format_string++; // Move to the next character after the backslash
            switch (*format_string) {
                case 't':
                    putchar('\t'); // Print a tab character
                    break;
                case 'n':
                    putchar('\n'); // Print a new line character
                    break;
                case 'r':
                    putchar('\r'); // Carriage return
                    break;
                case 'b':
                    putchar('\b'); // Backspace (may not show effect)
                    break;
                case '\\':
                    putchar('\\'); // Backslash
                    break;
                default:
                    putchar('\\'); // Print the backslash if it's not followed by t or n
                    putchar(*format_string);  // Print the next character
            }
        } else {
            putchar(*format_string); // Print the regular character
        }
        format_string++; // Move to the next character in the string
    }
}

void yoinkle_std_println(Variable *args, int num_args) {
    // Printing the arguments

    // If there are multiple arguments, then the first argument is a string
    // Getting the format string and replacing all the %V with the arguments
    char *format_string = args[0].value.string_value;
    int format_string_len = strlen(format_string);
    int format_string_index = 0;
    int arg_index = 1;
    if (num_args > 1) {
        for (int pos = 0; pos < format_string_len; pos++) {
            if (format_string[pos] == '%' && format_string[pos + 1] == 'V') {
                // Getting the argument
                Variable arg = args[arg_index];
                switch (arg.type) {
                    char *dest;
                    char *argument;
                    char *rest;
                    int arg_length;

                    case VAR_INT:
                        ;
                        // Copy the first part of the format string
                        dest = malloc(pos + 1);
                        strncpy(dest, format_string, pos);
                        dest[pos] = '\0';

                        // Insert the argument
                        arg_length = snprintf(NULL, 0, "%lld", arg.value.int_value);
                        argument = malloc(arg_length + 1); // Allocate space for string + null terminator
                        snprintf(argument, arg_length + 1, "%lld", arg.value.int_value); // Convert integer to string

                        // Copy the rest of the format string
                        rest = malloc(format_string_len - pos - 2);
                        strncpy(rest, format_string + pos + 2, format_string_len - pos - 2);
                        rest[format_string_len - pos - 2] = '\0';

                        // Concatenate the strings
                        format_string = malloc(strlen(dest) + strlen(argument) + strlen(rest) + 1);
                        strcpy(format_string, dest);
                        strcat(format_string, argument);
                        strcat(format_string, rest);
                        format_string_len = strlen(format_string);
                        free(dest);
                        free(argument);
                        free(rest);
                        arg_index++;
                        break;
                    case VAR_FLOAT:
                        ;
                        // Copy the first part of the format string
                        dest = malloc(pos + 1);
                        strncpy(dest, format_string, pos);
                        dest[pos] = '\0';

                        // Insert the argument
                        arg_length = snprintf(NULL, 0, "%f", arg.value.float_value);
                        argument = malloc(arg_length + 1); // Allocate space for string + null terminator
                        snprintf(argument, arg_length + 1, "%f", arg.value.float_value); // Convert float to string

                        // Copy the rest of the format string
                        rest = malloc(format_string_len - pos - 2);
                        strncpy(rest, format_string + pos + 2, format_string_len - pos - 2);
                        rest[format_string_len - pos - 2] = '\0';

                        // Concatenate the strings
                        format_string = malloc(strlen(dest) + strlen(argument) + strlen(rest) + 1);
                        strcpy(format_string, dest);
                        strcat(format_string, argument);
                        strcat(format_string, rest);
                        format_string_len = strlen(format_string);
                        free(dest);
                        free(argument);
                        free(rest);
                        arg_index++;
                        break;

                    case VAR_BOOLEAN:
                        ;
                        // Copy the first part of the format string
                        dest = malloc(pos + 1);
                        strncpy(dest, format_string, pos);
                        dest[pos] = '\0';

                        // Insert the argument
                        arg_length = snprintf(NULL, 0, "%s", arg.value.boolean_value ? "True" : "False");
                        argument = malloc(arg_length + 1); // Allocate space for string + null terminator
                        snprintf(argument, arg_length + 1, "%s", arg.value.boolean_value ? "True" : "False"); // Convert boolean to string

                        // Copy the rest of the format string
                        rest = malloc(format_string_len - pos - 2);
                        strncpy(rest, format_string + pos + 2, format_string_len - pos - 2);
                        rest[format_string_len - pos - 2] = '\0';

                        // Concatenate the strings
                        format_string = malloc(strlen(dest) + strlen(argument) + strlen(rest) + 1);
                        strcpy(format_string, dest);
                        strcat(format_string, argument);
                        strcat(format_string, rest);
                        format_string_len = strlen(format_string);
                        free(dest);
                        free(argument);
                        free(rest);
                        arg_index++;
                        break;

                    case VAR_STRING:
                        ;
                        // Copy the first part of the format string
                        dest = malloc(pos + 1);
                        strncpy(dest, format_string, pos);
                        dest[pos] = '\0';

                        // Insert the argument
                        arg_length = strlen(arg.value.string_value);
                        argument = malloc(arg_length + 1); // Allocate space for string + null terminator
                        strcpy(argument, arg.value.string_value); // Copy the string

                        // Copy the rest of the format string
                        rest = malloc(format_string_len - pos - 2);
                        strncpy(rest, format_string + pos + 2, format_string_len - pos - 2);
                        rest[format_string_len - pos - 2] = '\0';

                        // Concatenate the strings
                        format_string = malloc(strlen(dest) + strlen(argument) + strlen(rest) + 1);
                        strcpy(format_string, dest);
                        strcat(format_string, argument);
                        strcat(format_string, rest);
                        format_string_len = strlen(format_string);
                        free(dest);
                        free(argument);
                        free(rest);
                        arg_index++;
                        break;
                }
            }
        }
    }
    while (*format_string) 
    {
        if (*format_string == '\\') {
            format_string++; // Move to the next character after the backslash
            switch (*format_string) {
                case 't':
                    putchar('\t'); // Print a tab character
                    break;
                case 'n':
                    putchar('\n'); // Print a new line character
                    break;
                case 'r':
                    putchar('\r'); // Carriage return
                    break;
                case 'b':
                    putchar('\b'); // Backspace (may not show effect)
                    break;
                case '\\':
                    putchar('\\'); // Backslash
                    break;
                default:
                    putchar('\\'); // Print the backslash if it's not followed by t or n
                    putchar(*format_string);  // Print the next character
            }
        } else {
            putchar(*format_string); // Print the regular character
        }
        format_string++; // Move to the next character in the string
    }
    putchar('\n');
}

void yoinkle_std_exit(Node *AST, Token *p_tokens, Variable *var_stack, int exit_code) {
    free(AST);
    free(p_tokens);
    free(var_stack);

    AST = NULL;
    p_tokens = NULL;
    var_stack = NULL;

    printf("\nExiting with code %d\n", exit_code);
    exit(exit_code);
}

char *yoinkle_std_read(char *prompt) {
    if (prompt != NULL) {
        char *format_string = prompt;
        while (*format_string) 
        {
            if (*format_string == '\\') {
                format_string++; // Move to the next character after the backslash
                switch (*format_string) {
                    case 't':
                        putchar('\t'); // Print a tab character
                        break;
                    case 'n':
                        putchar('\n'); // Print a new line character
                        break;
                    case 'r':
                        putchar('\r'); // Carriage return
                        break;
                    case 'b':
                        putchar('\b'); // Backspace (may not show effect)
                        break;
                    case '\\':
                        putchar('\\'); // Backslash
                        break;
                    default:
                        putchar('\\'); // Print the backslash if it's not followed by t or n
                        putchar(*format_string);  // Print the next character
                }
            } else {
                putchar(*format_string); // Print the regular character
            }
            format_string++; // Move to the next character in the string
        }
    }
    char *input = malloc(1000);
    fgets(input, 1000, stdin);

    // Remove the newline character from the input
    input[strcspn(input, "\n")] = 0;
    return input;
}

Variable *yoinkle_std_value_to_int(Variable *var) {
    Variable *new_var = malloc(sizeof(Variable));
    new_var->name = NULL;
    new_var->type = VAR_INT;
    if (var->type == VAR_INT) {
        new_var->value.int_value = var->value.int_value;
    } else if (var->type == VAR_FLOAT) {
        new_var->value.int_value = (long long)var->value.float_value;
    } else if (var->type == VAR_STRING) {
        char *end;
        new_var->value.int_value = strtoll(var->value.string_value, &end, 10);
    } else if (var->type == VAR_BOOLEAN) {
        new_var->value.int_value = var->value.boolean_value;
    }
    return new_var;
}

Variable *yoinkle_std_value_to_float(Variable *var) {
    Variable *new_var = malloc(sizeof(Variable));
    new_var->name = NULL;
    new_var->type = VAR_FLOAT;
    if (var->type == VAR_INT) {
        new_var->value.float_value = (float)var->value.int_value;
    } else if (var->type == VAR_FLOAT) {
        new_var->value.float_value = var->value.float_value;
    } else if (var->type == VAR_STRING) {
        char *end;
        new_var->value.float_value = strtof(var->value.string_value, &end);
    } else if (var->type == VAR_BOOLEAN) {
        new_var->value.float_value = var->value.boolean_value;
    }
    return new_var;
}

Variable *yoinkle_std_value_to_string(Variable *var) {
    Variable *new_var = malloc(sizeof(Variable));
    new_var->name = NULL;
    new_var->type = VAR_STRING;
    if (var->type == VAR_INT) {
        char *string_value = malloc(20);
        sprintf(string_value, "%lld", var->value.int_value);
        new_var->value.string_value = string_value;
    } else if (var->type == VAR_FLOAT) {
        char *string_value = malloc(20);
        sprintf(string_value, "%f", var->value.float_value);
        new_var->value.string_value = string_value;
    } else if (var->type == VAR_STRING) {
        char *string_value = malloc(strlen(var->value.string_value) + 1);
        strcpy(string_value, var->value.string_value);
        new_var->value.string_value = string_value;
    } else if (var->type == VAR_BOOLEAN) {
        char *string_value = malloc(6);
        strcpy(string_value, var->value.boolean_value ? "True" : "False");
        new_var->value.string_value = string_value;
    }
    return new_var;
}

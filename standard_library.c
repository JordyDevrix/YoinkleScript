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

Variable *yoinkle_std_value_to_bool(Variable *var) {
    Variable *new_var = malloc(sizeof(Variable));
    new_var->name = NULL;
    new_var->type = VAR_BOOLEAN;
    if (var->type == VAR_INT) {
        new_var->value.boolean_value = var->value.int_value != 0 ? 1 : 0;
    } else if (var->type == VAR_FLOAT) {
        new_var->value.boolean_value = var->value.float_value != 0.0 ? 1 : 0;
    } else if (var->type == VAR_STRING) {
        new_var->value.boolean_value = strcmp(var->value.string_value, "") != 0 ? 1 : 0;
    } else if (var->type == VAR_BOOLEAN) {
        new_var->value.boolean_value = var->value.boolean_value;
    }
    return new_var;
}

Variable *yoinkle_std_get_system_time(char *format_string) {
    if (format_string == NULL) {
        time_t t = time(NULL);
        struct tm tm = *localtime(&t);
        Variable *new_var = malloc(sizeof(Variable));
        new_var->name = NULL;
        new_var->type = VAR_STRING;
        char *string_value = malloc(20);
        sprintf(string_value, "%d-%02d-%02d %02d:%02d:%02d", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);
        new_var->value.string_value = string_value;
        return new_var;
    } else {
        // Getting the format string and replacing all %d, %m, %Y, %H, %M, %S with the system time
        char *new_format_string = format_string;
        int format_string_len = strlen(format_string);

        for (int pos = 0; pos < format_string_len; pos++) {
            if (format_string[pos] == '%' && pos + 1 < format_string_len) {
                switch (format_string[pos + 1]) {
                    // %d - day of the month as a decimal number (01-31)
                    case 'd':
                        ;
                        time_t t = time(NULL);
                        struct tm tm = *localtime(&t);
                        char *dest = malloc(pos + 1);
                        strncpy(dest, new_format_string, pos);
                        dest[pos] = '\0';
                        char *day = malloc(3);
                        sprintf(day, "%02d", tm.tm_mday);
                        char *rest = malloc(format_string_len - pos - 2);
                        strncpy(rest, new_format_string + pos + 2, format_string_len - pos - 2);
                        rest[format_string_len - pos - 2] = '\0';
                        new_format_string = malloc(strlen(dest) + 3 + strlen(rest) + 1);
                        strcpy(new_format_string, dest);
                        strcat(new_format_string, day);
                        strcat(new_format_string, rest);
                        format_string_len = strlen(new_format_string);
                        free(dest);
                        free(day);
                        free(rest);
                        break;
                    // %m - month as a decimal number (01-12)
                    case 'm':
                        ;
                        time_t t2 = time(NULL);
                        struct tm tm2 = *localtime(&t2);
                        char *dest2 = malloc(pos + 1);
                        strncpy(dest2, new_format_string, pos);
                        dest2[pos] = '\0';
                        char *month = malloc(3);
                        sprintf(month, "%02d", tm2.tm_mon + 1);
                        char *rest2 = malloc(format_string_len - pos - 2);
                        strncpy(rest2, new_format_string + pos + 2, format_string_len - pos - 2);
                        rest2[format_string_len - pos - 2] = '\0';
                        new_format_string = malloc(strlen(dest2) + 3 + strlen(rest2) + 1);
                        strcpy(new_format_string, dest2);
                        strcat(new_format_string, month);
                        strcat(new_format_string, rest2);
                        format_string_len = strlen(new_format_string);
                        free(dest2);
                        free(month);
                        free(rest2);
                        break;
                    // %Y - year as a decimal number
                    case 'Y':
                        ;
                        time_t t3 = time(NULL);
                        struct tm tm3 = *localtime(&t3);
                        char *dest3 = malloc(pos + 1);
                        strncpy(dest3, new_format_string, pos);
                        dest3[pos] = '\0';
                        char *year = malloc(5);
                        sprintf(year, "%d", tm3.tm_year + 1900);
                        char *rest3 = malloc(format_string_len - pos - 2);
                        strncpy(rest3, new_format_string + pos + 2, format_string_len - pos - 2);
                        rest3[format_string_len - pos - 2] = '\0';
                        new_format_string = malloc(strlen(dest3) + 5 + strlen(rest3) + 1);
                        strcpy(new_format_string, dest3);
                        strcat(new_format_string, year);
                        strcat(new_format_string, rest3);
                        format_string_len = strlen(new_format_string);
                        free(dest3);
                        free(year);
                        free(rest3);
                        break;
                    // %H - hour as a decimal number (00-23)
                    case 'H':
                        ;
                        time_t t4 = time(NULL);
                        struct tm tm4 = *localtime(&t4);
                        char *dest4 = malloc(pos + 1);
                        strncpy(dest4, new_format_string, pos);
                        dest4[pos] = '\0';
                        char *hour = malloc(3);
                        sprintf(hour, "%02d", tm4.tm_hour);
                        char *rest4 = malloc(format_string_len - pos - 2);
                        strncpy(rest4, new_format_string + pos + 2, format_string_len - pos - 2);
                        rest4[format_string_len - pos - 2] = '\0';
                        new_format_string = malloc(strlen(dest4) + 3 + strlen(rest4) + 1);
                        strcpy(new_format_string, dest4);
                        strcat(new_format_string, hour);
                        strcat(new_format_string, rest4);
                        format_string_len = strlen(new_format_string);
                        free(dest4);
                        free(hour);
                        free(rest4);
                        break;
                    // %M - minute as a decimal number (00-59)
                    case 'M':
                        ;
                        time_t t5 = time(NULL);
                        struct tm tm5 = *localtime(&t5);
                        char *dest5 = malloc(pos + 1);
                        strncpy(dest5, new_format_string, pos);
                        dest5[pos] = '\0';
                        char *minute = malloc(3);
                        sprintf(minute, "%02d", tm5.tm_min);
                        char *rest5 = malloc(format_string_len - pos - 2);
                        strncpy(rest5, new_format_string + pos + 2, format_string_len - pos - 2);
                        rest5[format_string_len - pos - 2] = '\0';
                        new_format_string = malloc(strlen(dest5) + 3 + strlen(rest5) + 1);
                        strcpy(new_format_string, dest5);
                        strcat(new_format_string, minute);
                        strcat(new_format_string, rest5);
                        format_string_len = strlen(new_format_string);
                        free(dest5);
                        free(minute);
                        free(rest5);
                        break;
                    // %S - second as a decimal number (00-59)
                    case 'S':
                        ;
                        time_t t6 = time(NULL);
                        struct tm tm6 = *localtime(&t6);
                        char *dest6 = malloc(pos + 1);
                        strncpy(dest6, new_format_string, pos);
                        dest6[pos] = '\0';
                        char *second = malloc(3);
                        sprintf(second, "%02d", tm6.tm_sec);
                        char *rest6 = malloc(format_string_len - pos - 2);
                        strncpy(rest6, new_format_string + pos + 2, format_string_len - pos - 2);
                        rest6[format_string_len - pos - 2] = '\0';
                        new_format_string = malloc(strlen(dest6) + 3 + strlen(rest6) + 1);
                        strcpy(new_format_string, dest6);
                        strcat(new_format_string, second);
                        strcat(new_format_string, rest6);
                        format_string_len = strlen(new_format_string);
                        free(dest6);
                        free(second);
                        free(rest6);
                        break;
                        // Millisecond as a decimal number (000-999)
                    case 's':
                        ;
                        time_t t7 = time(NULL);
                        struct tm tm7 = *localtime(&t7);
                        struct timeval tv;
                        mingw_gettimeofday(&tv, NULL);
                        char *dest7 = malloc(pos + 1);
                        strncpy(dest7, new_format_string, pos);
                        dest7[pos] = '\0';
                        char *millisecond = malloc(4);
                        sprintf(millisecond, "%03d", (int)tv.tv_usec / 1000);
                        char *rest7 = malloc(format_string_len - pos - 2);
                        strncpy(rest7, new_format_string + pos + 2, format_string_len - pos - 2);
                        rest7[format_string_len - pos - 2] = '\0';
                        new_format_string = malloc(strlen(dest7) + 4 + strlen(rest7) + 1);
                        strcpy(new_format_string, dest7);
                        strcat(new_format_string, millisecond);
                        strcat(new_format_string, rest7);
                        format_string_len = strlen(new_format_string);
                        free(dest7);
                        free(millisecond);
                        free(rest7);
                        break;
                }
            }   
        }
        Variable *new_var = malloc(sizeof(Variable));
        new_var->name = NULL;
        new_var->type = VAR_STRING;
        new_var->value.string_value = new_format_string;
        return new_var;
    }
}

void *yoinkle_std_delay(Variable *time_in_milliseconds) {
    // Storing start time
    clock_t start_time = clock();

    // looping till required time is not achieved
    while (clock() < start_time + time_in_milliseconds->value.int_value);
}
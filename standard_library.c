#include "common.h"
#include "standard_library.h"

void yoinkle_std_print(Variable *args, int num_args) {
    // Printing the arguments
    // printf("Arg 2: %lld\n", args[1].value.int_value);

    // If there are multiple arguments, then the first argument is a string
    if (num_args <= 1) {
        printf("%s", args[0].value.string_value);
    } else {
        // Getting the format string and replacing all the %V with the arguments
        char *format_string = args[0].value.string_value;
        int format_string_len = strlen(format_string);
        int format_string_index = 0;
        for (int i = 1; i < num_args; i++) {
            // Getting the argument
            Variable arg = args[i];
            switch (arg.type) {
                case VAR_INT:
                    ;
                    for (int pos = 0; pos < format_string_len; pos++) {
                        if (format_string[pos] == '%' && format_string[pos + 1] == 'V') {
                            // Copy the first part of the format string
                            char *dest;
                            dest = malloc(pos + 1);
                            strncpy(dest, format_string, pos);
                            dest[pos] = '\0';

                            // Insert the argument
                            int arg_length = snprintf(NULL, 0, "%lld", arg.value.int_value);
                            char *argument = malloc(arg_length + 1); // Allocate space for string + null terminator
                            snprintf(argument, arg_length + 1, "%lld", arg.value.int_value); // Convert integer to string

                            // Copy the rest of the format string
                            char *rest = malloc(format_string_len - pos - 2);
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
                        }
                    }
            }
        }
        printf("%s\n", format_string);
    }
}
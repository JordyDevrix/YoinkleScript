#include "common.h"

typedef struct {
    int help;
    int version;
    int debug;
    int tokens;
    int ast;
    char *file_path;
} flags;

flags *path_variable_scanner(int argc, char *argv[]) {

    flags *ptr_program_flags = malloc(sizeof(flags));
    if (ptr_program_flags == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }

    *ptr_program_flags = (flags) { 0, 0, 0, 0, 0, NULL };

    for (int i = 0; i < argc; i++) {
        char *argument = argv[i];

        if (i == 0) {
            // Skip the first argument, which is the program name
            continue;
        } 

        if (argument[0] == '-') {
            if (strcmp(argument, "-h") == 0 || strcmp(argument, "--help") == 0) {
                ptr_program_flags->help = 1;
                return ptr_program_flags;
            }
            else if (strcmp(argument, "-v") == 0) {
                ptr_program_flags->version = 1;
                return ptr_program_flags;
            }
            else if (strcmp(argument, "-d") == 0) {
                ptr_program_flags->debug = 1;
            }
            else if (strcmp(argument, "-t") == 0) {
                ptr_program_flags->tokens = 1;
            }
            else if (strcmp(argument, "-a") == 0) {
                ptr_program_flags->ast = 1;
            } else {
                printf("");

                int space_length = 13;
                int argument_length = strlen(argument);
                char *error_line = malloc(sizeof(char) * (space_length + argument_length + 1));

                for (int i = 0; i < space_length; i++) {
                    error_line[i] = ' ';
                }
                for (int i = 0; i < argument_length; i++) {
                    error_line[space_length + i] = '^';
                }
                error_line[space_length + argument_length] = '\0';
                
                printf("Unkown flag: %s\n%s\n", argument, error_line);
                exit(1);
                break;
            }
        } else {
            ptr_program_flags->file_path = argument;
        }
    }
    // printf("Help: %d\n", program_flags.help);
    // printf("Version: %d\n", program_flags.version);
    // printf("Debug: %d\n", program_flags.debug);
    // printf("Tokens: %d\n", program_flags.tokens);
    // printf("AST: %d\n", program_flags.ast);
    // printf("File Path: %s\n", program_flags.file_path);


    
    return ptr_program_flags;
}
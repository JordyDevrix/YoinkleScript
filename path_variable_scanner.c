#include "common.h"
#include "path_variable_scanner.h"

flags *path_variable_scanner(int argc, char *argv[]) {

    flags *ptr_program_flags = malloc(sizeof(flags));
    if (ptr_program_flags == NULL) {
        printf("Memory allocation failed\n");
        printf("\nExited with code 1\n");
        exit(1);
    }

    *ptr_program_flags = (flags) { 0, 0, 0, 0, 0, 0, NULL };

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
            else if (strcmp(argument, "-v") == 0 || strcmp(argument, "--version") == 0) {
                ptr_program_flags->version = 1;
                return ptr_program_flags;
            }
            else if (strcmp(argument, "-t") == 0) {
                ptr_program_flags->tokens = 1;
            }
            else if (strcmp(argument, "-a") == 0) {
                ptr_program_flags->ast = 1;
            }
            else if (strcmp(argument, "-f") == 0) {
                ptr_program_flags->file = 1;
            }
            else if (strcmp(argument, "-c") == 0) {
                ptr_program_flags->code = 1;
            }
            else if ((strcmp(argument, "-d") == 0) || (strcmp(argument, "--debug") == 0)) {
                ptr_program_flags->ast = 1;
                ptr_program_flags->tokens = 1;
                ptr_program_flags->file = 1;    
                ptr_program_flags->code = 1;            
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
                printf("Use -h or --help to view the help message\n");
                exit(1);
                printf("\nExited with code 1\n");
                break;
            }
        } else {
            if (ptr_program_flags->file_path != NULL) {
                printf("");
                int space_length = 35;
                int argument_length = strlen(argument);
                char *error_line = malloc(sizeof(char) * (space_length + argument_length + 1));
                if (error_line == NULL) {
                    printf("Memory allocation failed\n");
                    printf("\nExited with code 1\n");
                    exit(1);
                }

                for (int i = 0; i < space_length; i++) {
                    error_line[i] = ' ';
                }
                for (int i = 0; i < argument_length; i++) {
                    error_line[space_length + i] = '^';
                }
                error_line[space_length + argument_length] = '\0';
                printf("One or multiple unknown arguments: %s\n%s\n", argument, error_line);
                printf("Use -h or --help to view the help message\n");
                free(ptr_program_flags);
                printf("\nExited with code 1\n");
                exit(1);
            }
            char *file_extension = strrchr(argument, '.');
            if (strcmp(file_extension, ".ys") != 0) {
                printf("");
                int space_length = 21;
                int argument_length = strlen(argument);
                char *error_line = malloc(sizeof(char) * (space_length + argument_length + 1));

                for (int i = 0; i < space_length; i++) {
                    error_line[i] = ' ';
                }
                for (int i = 0; i < argument_length; i++) {
                    error_line[space_length + i] = '^';
                }
                error_line[space_length + argument_length] = '\0';
                
                printf("File cannot be read: %s (File might not be a YoinkleScript file)\n%s\n", argument, error_line);
                printf("Use -h or --help to view the help message\n");
                free(ptr_program_flags);
                printf("\nExited with code 1\n");
                exit(1);
            }
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
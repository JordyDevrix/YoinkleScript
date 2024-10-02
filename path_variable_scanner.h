#include "common.h"

void path_variable_scanner(int argc, char *argv[]) {
    typedef struct {
        int help;
        int version;
        int debug;
        int tokens;
        int ast;
        char *file_path;
    } flags;

    flags program_flags;
    program_flags = (flags) {0, 0, 0, 0, 0, NULL};

    for (int i = 0; i < argc; i++) {
        char *argument = argv[i];

        if (i == 0) {
            // Skip the first argument, which is the program name
            continue;
        } 

        if (argument[0] == '-') {
            if (strcmp(argument, "-h") == 0 || strcmp(argument, "--help") == 0) {
                // printf(
                //     "Help\n"
                //     "  -h: Display this help message\n"
                //     "  -v: Display the version\n"
                //     "  -d: Add behind your script to run in debug\n"
                //     "  -t: Add behind your script to view the tokens\n"
                //     "  -a: Add behind your script to view abstract syntax tree\n"
                // );
                program_flags.help = 1;
            }
            else if (strcmp(argument, "-v") == 0) {
                // printf("Version: 02/10/2024 v0.0.1 pre-alpha\n");
                program_flags.version = 1;
            }
            else if (strcmp(argument, "-d") == 0) {
                // printf("Debug\n");
                program_flags.debug = 1;
            }
            else if (strcmp(argument, "-t") == 0) {
                // printf("Tokens\n");
                program_flags.tokens = 1;
            }
            else if (strcmp(argument, "-a") == 0) {
                // printf("Abstract Syntax Tree\n");
                program_flags.ast = 1;
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
            program_flags.file_path = argument;
        }

    }
    printf("Help: %d\n", program_flags.help);
    printf("Version: %d\n", program_flags.version);
    printf("Debug: %d\n", program_flags.debug);
    printf("Tokens: %d\n", program_flags.tokens);
    printf("AST: %d\n", program_flags.ast);
    printf("File Path: %s\n", program_flags.file_path);

}
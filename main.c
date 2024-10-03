#include "common.h"
#include "path_variable_scanner.h"

int main(int argc, char *argv[]) {
    
    flags *my_flags = path_variable_scanner(argc, argv);

    if (my_flags->help) {
        printf(
            "Help\n"
            "  -h: Display this help message\n"
            "  -v: Display the version\n"
            "  -d: Add behind your script to run in debug\n"
            "  -t: Add behind your script to view the tokens\n"
            "  -a: Add behind your script to view abstract syntax tree\n"
        );
    }

    if (my_flags->version) {
        printf("Version: 02/10/2024 v0.0.1 pre-alpha\n");
    }

    

    if (my_flags->tokens) {
        printf("Tokens\n");
    }

    if (my_flags->ast) {
        printf("Abstract Syntax Tree\n");
    }

    free(my_flags);

    return 0;
} 
#include "common.h"

#include "path_variable_scanner.h"
#include "file_reader.h"
#include "tokenizer.h"
#include "my_parser.h"


int main(int argc, char *argv[]) {
    
    // Getting the execution arguments and checking for flags and a file path
    flags *my_flags = path_variable_scanner(argc, argv);

    // Printing the help message and exiting
    if (my_flags->help) {
        printf(
            "Help\n"
            "  -h | --help: Display this help message\n"
            "  -v | --version: Display the version\n"
            "  -d | --debug: Add behind your script to run in debug\n"
            "  -t: Add behind your script to view the tokens\n"
            "  -a: Add behind your script to view abstract syntax tree\n"
            "  -f: Add behind your script to view the file path\n"
            "  -c: Add behind your script to view the code\n"
        );
        free(my_flags);
        exit(0);
    }

    // Printing the version number and exiting
    if (my_flags->version) {
        printf("Version: 02/10/2024 v0.0.1 pre-alpha\n");
        free(my_flags);
        exit(0);
    }

    // Reading the file_path argument and getting the file contents
    if (my_flags->file_path) {
        // Printing the file path when the -f flag is set
        if (my_flags->file) {
            printf("v v v FILE v v v\n");
            printf("%s\n", my_flags->file_path);
        }

        // Reading the file contents and checking if the file exists
        char *p_code = file_reader(my_flags->file_path);
        if (p_code == NULL) {
            free(my_flags);
            exit(1);
        }

        // Printing the code when the -c flag is set
        if (my_flags->code) {
            printf("v v v CODE v v v\n");
            printf("%s\n", p_code);
        }

        // Tokenizing the code and optionally printing the tokens when the -t flag is set
        Token *p_tokens = tokenize_code(p_code);
        if (p_tokens == NULL) {
            free(my_flags);
            free(p_code);
            exit(1);
        }

        // Checking if the tokens flag has been set to 1 and printing the tokens
        int print_tokens = my_flags->tokens;
        if (print_tokens) {
            printf("v v v TOKENS v v v\n");
        }
        int token_list_length = 0;
        for (int i = 0; p_tokens[i].type != TOKEN_NULL; i++) {
            if (print_tokens) {
                switch (p_tokens[i].type)
                {
                    case TOKEN_STRING:
                        printf("(%d)\tType %d\t(STRING)\t%s\n", i, p_tokens[i].type, p_tokens[i].value);
                        break;
                    case TOKEN_INTEGER:
                        printf("(%d)\tType %d\t(INTEGER)\t%s\n", i, p_tokens[i].type, p_tokens[i].value);
                        break;
                    case TOKEN_FLOAT:
                        printf("(%d)\tType %d\t(FLOAT)\t\t%s\n", i, p_tokens[i].type, p_tokens[i].value);
                        break;
                    case TOKEN_BOOLEAN:
                        printf("(%d)\tType %d\t(BOOLEAN)\t%s\n", i, p_tokens[i].type, p_tokens[i].value);
                        break;
                    case TOKEN_IDENTIFIER:
                        printf("(%d)\tType %d\t(IDENTIFIER)\t%s\n", i, p_tokens[i].type, p_tokens[i].value);
                        break;
                    case TOKEN_KEYWORD:
                        printf("(%d)\tType %d\t(KEYWORD)\t%s\n", i, p_tokens[i].type, p_tokens[i].value);
                        break;
                    case TOKEN_OPERATOR:
                        printf("(%d)\tType %d\t(OPERATOR)\t%s\n", i, p_tokens[i].type, p_tokens[i].value);
                        break;
                    case TOKEN_SYMBOL:
                        printf("(%d)\tType %d\t(SYMBOL)\t%s\n", i, p_tokens[i].type, p_tokens[i].value);
                        break;
                    case TOKEN_COMPARATOR:
                        printf("(%d)\tType %d\t(COMPARATOR)\t%s\n", i, p_tokens[i].type, p_tokens[i].value);
                        break;
                    default:
                        break;
                }
            }
        
            
        }

        if (my_flags->ast) {
            printf("v v v ABSTRACT SYNTAX TREE v v v\n");
            parse_tokens(p_tokens);
        }
    }


    free(my_flags);

    return 0;
} 
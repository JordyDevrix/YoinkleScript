#include "common.h"
#include "tokenizer.h"

#define SYMBOLS ";,(){}[]"
#define OPERATORS "+-*/%="
#define COMPARATORS { "==", "!=", ">", "<", ">=", "<=" }
#define KEYWORDS {"if", "else", "return", "task", "for", "while", "break", "skip"}

Token *tokenize_code(char *p_code) {
    Token *token_list = (Token *) malloc(sizeof(Token));
    if (token_list == NULL) {
        printf("Memory allocation failed\n");
        printf("\nExited with code 1\n");
        exit(1);
    }

    int token_count = 0;

    int code_length = strlen(p_code);
    int i = 0;

    const char *comparators[] = COMPARATORS;
    const char *keywords[] = KEYWORDS;
    int n_comparators = sizeof(comparators) / sizeof(comparators[0]);
    int n_keywords = sizeof(keywords) / sizeof(keywords[0]);

    int line_number = 1;

    while (i < code_length)
    {   
        // printf("The value of p_code[%d] is: %c (%d)\n", i, p_code[i], p_code[i]);

        // Removing spaces
        if (p_code[i] == ' ')
        {
            i++;
            continue;
        }

        // Removing newlines
        if (p_code[i] == '\n')
        {
            line_number++;
            i++;
            continue;
        }

        // Removing singleline comments
        if (p_code[i] == '#' && p_code[i + 1] == '#')
        {
            while (p_code[i] != '\n')
            {
                i++;
            }
            continue;
        }

        // Removing multiline comments
        if (p_code[i] == '#')
        {
            i++;
            while (p_code[i] != '#')
            {
                i++;
            }
            i += 2;
            continue;
        }

        // Checking for doublecharacter comparators in COMPARATORS list
        for (int j = 0; j < n_comparators; j++)
        {
            // printf("Comparing %c%c with %s\n", p_code[i], p_code[i + 1], comparators[j]);

            char current_double_string[3] = { p_code[i], p_code[i + 1], '\0' };

            if (strcmp(current_double_string, comparators[j]) == 0)
            {
                TokenType token_type = TOKEN_COMPARATOR;
                char *token_value = (char *) malloc(3 * sizeof(char));
                if (token_value == NULL) {
                    free(token_list);
                    fprintf(stderr, "Memory allocation failed\n");
                    exit(1);
                }

                token_value[0] = p_code[i];
                token_value[1] = p_code[i + 1];
                token_value[2] = '\0';

                token_list = (Token *) realloc(token_list, (token_count + 1) * sizeof(Token));
                if (token_list == NULL) {
                    free(token_list);
                    fprintf(stderr, "Memory allocation failed\n");
                    exit(1);
                }

                token_list[token_count] = (Token) { token_type, token_value };
                token_count++;

                i += 2;
                continue;
            } 
        }

        // Checking for single character comparators in COMPARATORS list
        for (int j = 0; j < n_comparators; j++)
        {
            // printf("Comparing %c%c with %s\n", p_code[i], p_code[i + 1], comparators[j]);

            char current_single_string[2] = { p_code[i], '\0' };

            if (strcmp(current_single_string, comparators[j]) == 0)
            {
                TokenType token_type = TOKEN_COMPARATOR;
                char *token_value = (char *) malloc(3 * sizeof(char));
                if (token_value == NULL) {
                    free(token_list);
                    fprintf(stderr, "Memory allocation failed\n");
                    exit(1);
                }

                token_value[0] = p_code[i];
                token_value[1] = '\0';

                token_list = (Token *) realloc(token_list, (token_count + 1) * sizeof(Token));
                if (token_list == NULL) {
                    free(token_list);
                    fprintf(stderr, "Memory allocation failed\n");
                    exit(1);
                }

                token_list[token_count] = (Token) { token_type, token_value };
                token_count++;

                i += 1;
                continue;
            } 
        }

        // Checking for symbols
        if (strchr(SYMBOLS, p_code[i]) != NULL)
        {
            TokenType token_type = TOKEN_SYMBOL;
            char *token_value = (char *) malloc(2 * sizeof(char));
            if (token_value == NULL) {
                free(token_list);
                fprintf(stderr, "Memory allocation failed\n");
                exit(1);
            }

            token_value[0] = p_code[i];
            token_value[1] = '\0';

            token_list = (Token *) realloc(token_list, (token_count + 1) * sizeof(Token));
            if (token_list == NULL) {
                free(token_list);
                fprintf(stderr, "Memory allocation failed\n");
                exit(1);
            }

            token_list[token_count] = (Token) { token_type, token_value };
            token_count++;

            i++;
            continue;
        }

        // Checking for operators
        if (strchr(OPERATORS, p_code[i]) != NULL)
        {
            TokenType token_type = TOKEN_OPERATOR;
            char *token_value = (char *) malloc(2 * sizeof(char));
            if (token_value == NULL) {
                free(token_list);
                fprintf(stderr, "Memory allocation failed\n");
                exit(1);
            }

            token_value[0] = p_code[i];
            token_value[1] = '\0';

            token_list = (Token *) realloc(token_list, (token_count + 1) * sizeof(Token));
            if (token_list == NULL) {
                free(token_list);
                fprintf(stderr, "Memory allocation failed\n");
                exit(1);
            }
            token_list[token_count] = (Token) { token_type, token_value };
            token_count++;

            i++;
            continue;
        }

        // Adding DOUBLE QUOTED strings to the token list
        if (p_code[i] == '"') 
        {
            i++;
            TokenType token_type = TOKEN_STRING;
            char *token_value = (char *) malloc(1 * sizeof(char));
            if (token_value == NULL) {
                free(token_list);
                fprintf(stderr, "Memory allocation failed\n");
                exit(1);
            }

            int j = 0; // Initialize character index
            while (p_code[i] != '"' && p_code[i] != '\0') // Ensure you don't go out of bounds
            {
                token_value = (char *) realloc(token_value, (j + 2) * sizeof(char)); // +2 for new char and null terminator
                if (token_value == NULL) {
                    free(token_list);
                    fprintf(stderr, "Memory allocation failed\n");
                    exit(1);
                }
                token_value[j] = p_code[i]; // Add the current character
                i++;
                j++;
            }

            // Check if we exited the loop due to closing quote or end of string
            if (p_code[i] == '"') {
                token_value[j] = '\0'; // Properly null-terminate
            } else {
                // Handle the case where the string is not properly closed (optional)
                fprintf(stderr, "String not properly closed\n");
                free(token_value);
                free(token_list);
                exit(1);
            }

            token_list = (Token *) realloc(token_list, (token_count + 1) * sizeof(Token));
            if (token_list == NULL) {
                free(token_list);
                fprintf(stderr, "Memory allocation failed\n");
                exit(1);
            }
            token_list[token_count] = (Token) { token_type, token_value, line_number };
            token_count++;

            i++;
            continue;
        }

        // Adding SINGLE QUOTED strings to the token list
        if (p_code[i] == '\'') 
        {
            i++;
            TokenType token_type = TOKEN_STRING;
            char *token_value = (char *) malloc(1 * sizeof(char));
            if (token_value == NULL) {
                free(token_list);
                fprintf(stderr, "Memory allocation failed\n");
                exit(1);
            }

            int j = 0; // Initialize character index
            while (p_code[i] != '\'' && p_code[i] != '\0') // Ensure you don't go out of bounds
            {
                token_value = (char *) realloc(token_value, (j + 2) * sizeof(char)); // +2 for new char and null terminator
                if (token_value == NULL) {
                    free(token_list);
                    fprintf(stderr, "Memory allocation failed\n");
                    exit(1);
                }
                token_value[j] = p_code[i]; // Add the current character
                i++;
                j++;
            }

            // Check if we exited the loop due to closing quote or end of string
            if (p_code[i] == '\'') {
                token_value[j] = '\0'; // Properly null-terminate
            } else {
                // Handle the case where the string is not properly closed (optional)
                fprintf(stderr, "String not properly closed\n");
                free(token_value);
                free(token_list);
                exit(1);
            }

            token_list = (Token *) realloc(token_list, (token_count + 1) * sizeof(Token));
            if (token_list == NULL) {
                free(token_list);
                fprintf(stderr, "Memory allocation failed\n");
                exit(1);
            }
            token_list[token_count] = (Token) { token_type, token_value, line_number };
            token_count++;

            i++;
            continue;
        }

        // Adding INTEGERS or FLOATS to the token list
        if ((isdigit(p_code[i]) == 1) || (p_code[i] == '.' && isdigit(p_code[i + 1]) == 1))
        {
            TokenType token_type;
            char *token_value = (char *) malloc(1 * sizeof(char));
            if (token_value == NULL) {
                free(token_list);
                fprintf(stderr, "Memory allocation failed\n");
                exit(1);
            }

            int last_j = 0;
            for (int j = 0; isdigit(p_code[i]) == 1 || p_code[i] == '.'; j++)
            {
                token_value = (char *) realloc(token_value, (j + 1) * sizeof(char));
                if (token_value == NULL) {
                    free(token_list);
                    fprintf(stderr, "Memory allocation failed\n");
                    exit(1);
                }

                token_value[j] = p_code[i];
                i++;
                last_j = j;
            }
            token_value[last_j + 1] = '\0';

            if (strchr(token_value, '.') != NULL)
            {
                token_type = TOKEN_FLOAT;
            } else {
                token_type = TOKEN_INTEGER;
            }

            token_list = (Token *) realloc(token_list, (token_count + 1) * sizeof(Token));
            if (token_list == NULL) {
                free(token_list);
                fprintf(stderr, "Memory allocation failed\n");
                exit(1);
            }
            token_list[token_count] = (Token) { token_type, token_value, line_number };
            token_count++;

            continue;
        }

        // Adding BOOLEAN values to the token list
        if (strncmp(&p_code[i], "True", 4) == 0 || strncmp(&p_code[i], "False", 5) == 0)
        {
            TokenType token_type = TOKEN_BOOLEAN;
            char *token_value = (char *) malloc(1 * sizeof(char));
            if (token_value == NULL) {
                free(token_list);
                fprintf(stderr, "Memory allocation failed\n");
                exit(1);
            }

            if (strncmp(&p_code[i], "True", 4) == 0)
            {
                token_value = (char *) realloc(token_value, 5 * sizeof(char));
                if (token_value == NULL) {
                    free(token_list);
                    fprintf(stderr, "Memory allocation failed\n");
                    exit(1);
                }
                strcpy(token_value, "True");
                i += 4;
            } else {
                token_value = (char *) realloc(token_value, 6 * sizeof(char));
                if (token_value == NULL) {
                    free(token_list);
                    fprintf(stderr, "Memory allocation failed\n");
                    exit(1);
                }
                strcpy(token_value, "False");
                i += 5;
            }

            token_list = (Token *) realloc(token_list, (token_count + 1) * sizeof(Token));
            if (token_list == NULL) {
                free(token_list);
                fprintf(stderr, "Memory allocation failed\n");
                exit(1);
            }
            token_list[token_count] = (Token) { token_type, token_value, line_number };
            token_count++;

            continue;
        }

        // Adding KEYWORDS to the token list
        for (int j = 0; j < n_keywords; j++)
        {
            int start_i = i;
            if (strncmp(&p_code[i], keywords[j], strlen(keywords[j])) == 0)
            {
                TokenType token_type = TOKEN_KEYWORD;
                char *token_value = (char *) malloc(strlen(keywords[j]) * sizeof(char));
                if (token_value == NULL) {
                    fprintf(stderr, "Memory allocation failed\n");
                    exit(1);
                }

                strcpy(token_value, keywords[j]);
                i += strlen(keywords[j]);

                token_list = (Token *) realloc(token_list, (token_count + 1) * sizeof(Token));
                if (token_list == NULL) {
                    free(token_list);
                    fprintf(stderr, "Memory allocation failed\n");
                    exit(1);
                }
                token_list[token_count] = (Token) { token_type, token_value, line_number };
                token_count++;

                continue;
            }
        }

        // Adding IDENTIFIERS to the token list
        if (isalpha(p_code[i]) != 0)
        {
            TokenType token_type = TOKEN_IDENTIFIER;
            int start_i = i;
            char *token_value = (char *) malloc(256 * sizeof(char));
            if (token_value == NULL) {
                fprintf(stderr, "Memory allocation failed\n");
                exit(1);
            }

            int last_j = 0;
            for (int j = 0; (isalnum(p_code[i]) != 0)  || (strncmp(&p_code[i], "_", 1)) == 0; j++)
            {
                // Allocating more memory for the token value if the current memory is not enough
                if (j % 256 == 0)
                {
                    token_value = (char *) realloc(token_value, (j + 256) * sizeof(char));
                    if (token_value == NULL) {
                        fprintf(stderr, "Memory allocation failed\n");
                        exit(1);
                    }
                }
                if (token_value == NULL) {
                    free(token_list);
                    fprintf(stderr, "Memory allocation failed\n");
                    exit(1);
                }
                token_value[j] = p_code[i];
                i++;
                last_j = j;
            }
            token_value[last_j + 1] = '\0';

            token_list = (Token *) realloc(token_list, (token_count + 1) * sizeof(Token));
            if (token_list == NULL) {
                free(token_list);
                fprintf(stderr, "Memory allocation failed\n");
                exit(1);
            }
            token_list[token_count] = (Token) { token_type, token_value, line_number };
            token_count++;

            continue;
        }
        i++;


    }
    token_list = (Token *) realloc(token_list, (token_count + 1) * sizeof(Token));
    if (token_list == NULL) {
        free(token_list);
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
    token_list[token_count] = (Token) { TOKEN_NULL, NULL };
    token_count++;

    return token_list;
}
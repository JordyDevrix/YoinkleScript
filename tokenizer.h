#include "common.h"

#define SYMBOLS ";,(){}[]"
#define OPERATORS "+-*/%="
#define COMPARATORS { "==", "!=", ">", "<", ">=", "<=" }
#define KEYWORDS {"if", "else"}

typedef enum {
    TOKEN_STRING,
    TOKEN_INTEGER,
    TOKEN_FLOAT,
    TOKEN_BOOLEAN,
    TOKEN_NULL,
    TOKEN_IDENTIFIER,
    TOKEN_KEYWORD,
    TOKEN_OPERATOR,
    TOKEN_SYMBOL,
    TOKEN_COMPARATOR
} TokenType;

typedef struct {
    TokenType type;
    char *value;
} Token;

int *tokenize_code(char *p_code) {
    Token *token_list = (Token *) malloc(sizeof(Token));
    if (token_list == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }

    int token_count = 0;

    int code_length = strlen(p_code);
    int i = 0;

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
            i++;
            continue;
        }

        // Removing comments
        if (p_code[i] == '#')
        {
            while (p_code[i] != '\n')
            {
                i++;
            }
            continue;
        }

        // Checking for comparators
        if (p_code[i] == '=' && p_code[i + 1] == '=')
        {
            TokenType token_type = TOKEN_COMPARATOR;
            char *token_value = "==";

            token_list = (Token *) realloc(token_list, (token_count + 1) * sizeof(Token));
            token_list[token_count] = (Token) { token_type, token_value };
            token_count++;

            i += 2;
            continue;
        }

        // Checking for symbols
        if (strchr(SYMBOLS, p_code[i]) != NULL)
        {
            TokenType token_type = TOKEN_SYMBOL;
            char *token_value = (char *) malloc(2 * sizeof(char));
            token_value[0] = p_code[i];
            token_value[1] = '\0';

            token_list = (Token *) realloc(token_list, (token_count + 1) * sizeof(Token));
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
            token_value[0] = p_code[i];
            token_value[1] = '\0';

            token_list = (Token *) realloc(token_list, (token_count + 1) * sizeof(Token));
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

            int last_j = 0;
            for (int j = 0; p_code[i] != '"'; j++)
            {
                token_value = (char *) realloc(token_value, (j + 1) * sizeof(char));
                token_value[j] = p_code[i];
                i++;
                last_j = j;
            }
            token_value[last_j + 1] = '\0';

            token_list = (Token *) realloc(token_list, (token_count + 1) * sizeof(Token));
            token_list[token_count] = (Token) { token_type, token_value };
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

            int last_j = 0;
            for (int j = 0; p_code[i] != '\''; j++)
            {
                token_value = (char *) realloc(token_value, (j + 1) * sizeof(char));
                token_value[j] = p_code[i];
                i++;
                last_j = j;
            }
            token_value[last_j + 1] = '\0';

            token_list = (Token *) realloc(token_list, (token_count + 1) * sizeof(Token));
            token_list[token_count] = (Token) { token_type, token_value };
            token_count++;

            i++;
            continue;
        }
        

        i++;

    }

    for (int i = 0; i < token_count; i++) {
        printf("Token type %d\t token value %s\n", token_list[i].type, token_list[i].value);
    }

}
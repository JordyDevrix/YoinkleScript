#include "common.h"
#include "my_parser.h"

// Function to parse the tokens into an abstract syntax tree
int parse_tokens(Token *p_tokens) {
    int i = 0;
    while (p_tokens[i].type != NULL) {
        Token token = p_tokens[i];
        printf("%i\t%i\t%s\n", i, token.type, token.value);
        i++;
    }
}
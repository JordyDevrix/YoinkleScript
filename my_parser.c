#include "common.h"
#include "my_parser.h"
#include "tokenizer.h"

void parse_tokens(Token *p_tokens) {
    printf("Parsing tokens\n");
    Token *p_current_token = p_tokens;
    while (p_current_token != NULL) {
        printf("Token: %s\n", p_current_token->type);
    }
}
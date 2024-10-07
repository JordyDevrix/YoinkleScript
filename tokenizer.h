#ifndef TOKENIZER_H
#define TOKENIZER_H

typedef enum {
    TOKEN_NULL,
    TOKEN_STRING,
    TOKEN_INTEGER,
    TOKEN_FLOAT,
    TOKEN_BOOLEAN,
    TOKEN_IDENTIFIER,
    TOKEN_KEYWORD,
    TOKEN_OPERATOR,
    TOKEN_SYMBOL,
    TOKEN_COMPARATOR,
    TOKEN_NAN
} TokenType;

typedef struct {
    TokenType type;
    char *value;
} Token;

Token *tokenize_code(char *p_code);

#endif
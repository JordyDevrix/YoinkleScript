#include "common.h"

int *tokenize_code(char *p_code) {
    int *token_list = NULL;
    int *tokens = NULL;
    int code_length = strlen(p_code);
    int i = 0;

    while (i < code_length)
    {   
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
        
        

        i++;

    }
        
}
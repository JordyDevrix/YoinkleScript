#include "common.h"

char *file_reader(char *file_path) {
    FILE *p_file = fopen(file_path, "r");
    char c;
    char *file_content = NULL;

    if (p_file == NULL) {
        printf("File not found\n");
        printf("\nExited with code 1\n");
        exit(1);
    }

    int i = 0;
    file_content = (char *) malloc(0 * sizeof(char));
    while ((c = fgetc(p_file)) != EOF)
    {
        file_content = realloc(file_content, (i + 1) * sizeof(char));
        if (file_content == NULL) {
            printf("Memory allocation failed\n");
            file_content = NULL;
            return file_content;
        }
        file_content[i] = c;
        i++;    
    }
    file_content[i] = '\0';

    fclose(p_file);
    return file_content;

}
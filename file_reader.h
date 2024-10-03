#include "common.h"

char *file_reader(char *file_path) {
    FILE *p_file = fopen(file_path, "r");
    char c;
    if (p_file == NULL) {
        printf("File not found\n");
        exit(1);
    }
    int i = 0;
    while ((c = fgetc(p_file)) != EOF)
    {
        printf("%c", c);
        i++;
    }
    

    fclose(p_file);

}
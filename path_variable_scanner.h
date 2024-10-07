#ifndef PATH_VARIABLE_SCANNER_H
#define PATH_VARIABLE_SCANNER_H

typedef struct {
    int help;
    int version;
    int tokens;
    int ast;
    int file;
    int code;
    char *file_path;
} flags;

flags *path_variable_scanner(int argc, char **argv);

#endif
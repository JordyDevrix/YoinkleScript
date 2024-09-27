void path_variable_scanner() {
    char *path = getenv("PATH");
    if (path == NULL) {
        printf("PATH is not set\n");
    } else {
        printf("PATH is %s\n", path);
    }
}
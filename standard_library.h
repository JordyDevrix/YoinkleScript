#ifndef STANDARD_LIBRARY_H
#define STANDARD_LIBRARY_H

#include "yoinkle_runtime.h"

void yoinkle_std_print(Variable *args, int num_args);
void yoinkle_std_println(Variable *args, int num_args);
void yoinkle_std_exit(Node *AST, Token *p_tokens, Variable *var_stack, int exit_code);
char *yoinkle_std_read(char *prompt);

Variable *yoinkle_std_value_to_int(Variable *var);
Variable *yoinkle_std_value_to_float(Variable *var);
Variable *yoinkle_std_value_to_string(Variable *var);
Variable *yoinkle_std_value_to_bool(Variable *var);

Variable *yoinkle_std_get_system_time(char *format_string);

#endif
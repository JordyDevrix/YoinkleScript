#ifndef YOIKNLE_RUNTIME_H
#define YOINKLE_RUNTIME_H

#include "path_variable_scanner.h"
#include "file_reader.h"
#include "tokenizer.h"
#include "my_parser.h"

void run_runtime(Node *AST, Token *p_tokens);

#endif

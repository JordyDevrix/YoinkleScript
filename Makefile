main: main.c my_parser.c path_variable_scanner.c tokenizer.c file_reader.c
	gcc -o yoinkle main.c my_parser.c path_variable_scanner.c tokenizer.c file_reader.c
	
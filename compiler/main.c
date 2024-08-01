#include <stdio.h>
#include "file.h"
#include "lexer.h"

int compile(char* filepath) {
    printf("Compiling %s...\n", filepath);
    char* file = file_read_whole(filepath);
    if (!file) {
        printf("toylang: the file %s does not exists.", filepath);
        return 1;
    }
    printf("Compiling the following code\n");
    printf("```\n");
    printf("%s", file);
    printf("```\n");
   
    Lexer* lexer = lexer_init(file);
    Token* token = 0;
    while ((token = lexer_next_token(lexer)) != 0) {
        printf("TOKEN(%d, %s)\n", token->type, token->value);
    }

    file_free_buffer(file);
    return 0;
}

int main(int argc, char *argv[]) {
    if (argc == 1) {
        printf("toylang: fatal error, no input files.\n");
        return 1;
    }
    // for now compile just one file
    return compile(argv[1]);
}

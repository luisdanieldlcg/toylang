#include "lexer.h"
#include <stdio.h>

int main() {

    printf("Compiling your code...\n");
    Lexer* lexer = lexer_init(
    "let f = \"hello world\";\n"
          "println(f);\n"
    );

    Token* token = 0;

    while ((token = lexer_next_token(lexer)) != 0) {
        printf("TOKEN(%d, %s)\n", token->type, token->value);
    }

    return 0;
}


#include "lexer.h"
#include "token.h"
#include <string.h>
#include <stdlib.h>
#include <ctype.h>


Lexer* lexer_init(char *code)  {
    Lexer* lexer = malloc(sizeof(Lexer));
    lexer->code = code;
    lexer->index = 0;
    lexer->character = lexer->code[lexer->index];
    return lexer;
}

void lexer_step(Lexer* lexer) {
    if (lexer_at_eof(lexer)) return;
    lexer->index++;
    lexer->character = lexer->code[lexer->index];
}

void lexer_skip_whitespace(Lexer* lexer) {
    // 10 is code for end of line
    while(lexer->character == ' ' || lexer->character == 10) {
        lexer_step(lexer);
    }
}

Token* lexer_make_token(Lexer* lexer, TokenType type) {
    lexer_step(lexer);
    return token_create(type, lexer_char_as_str(lexer));
}

Token* lexer_make_id_token(Lexer* lexer) {
    lexer_step(lexer);
    char value = 0;
    return 0;
}

Token* lexer_make_str_token(Lexer* lexer) {
    lexer_step(lexer);

    char* value = malloc(sizeof(char));
    value[0] = '\0';

    while (lexer->character != '"') {
        // iterate all the characters until there is another "
        char* str = lexer_char_as_str(lexer);
        value = realloc(value, (strlen(value) + strlen(str) + 1) * sizeof(char));
        strcat(value, str);
        lexer_step(lexer);
    }
    lexer_step(lexer);
    return token_create(TOKEN_STR, value);
}

Token* lexer_next_token(Lexer* lexer) {
    // Iterate as long as we still have characters to parse 
    while (!lexer_at_eof(lexer)) {
        lexer_skip_whitespace(lexer);
        
        if (lexer->character == '"') {
            return lexer_make_str_token(lexer);
        }
        if (isalnum(lexer->character)) {
            // TODO: make id token
            lexer_step(lexer);
        }
        switch (lexer->character) {
            case '=': return lexer_make_token(lexer, TOKEN_EQ);
            case ';': return lexer_make_token(lexer, TOKEN_SEMI);
            case '(': return lexer_make_token(lexer, TOKEN_LPAREN);
            case ')': return lexer_make_token(lexer, TOKEN_RPAREN);
        }
    }
    return 0;
}

bool lexer_at_eof(Lexer* lexer) {
    return lexer->character == '\0' || lexer->index >= strlen(lexer->code); 
}

char* lexer_char_as_str(Lexer* lexer) {
    char* str = malloc(sizeof(char) * 2);
    str[0] = lexer->character;
    str[1] = '\0';
    return str;
}

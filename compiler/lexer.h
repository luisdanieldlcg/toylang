#ifndef LEXER_H
#define LEXER_H

#include "types.h"
#include "token.h"

typedef struct Lexer {
    u32 index;
    char character;
    char* code;
} Lexer;

Lexer* lexer_init(char* code);
void lexer_step(Lexer* lexer);
void lexer_skip_whitespace(Lexer* lexer);

Token* lexer_next_token(Lexer* lexer);
Token* lexer_make_token(Lexer* lexer, TokenType type);
Token* lexer_make_id_token(Lexer* lexer);
Token* lexer_make_str_token(Lexer* lexer);

bool lexer_at_eof(Lexer* lexer);
char* lexer_char_as_str(Lexer* lexer);

#endif

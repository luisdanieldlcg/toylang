#ifndef TOKEN_H
#define TOKEN_H

typedef enum TokenType {
    TOKEN_ID,
    TOKEN_EQ,
    TOKEN_STR,
    TOKEN_LPAREN,
    TOKEN_RPAREN,
    TOKEN_SEMI
} TokenType;

typedef struct Token {
    TokenType type;
    char* value;
}Token;

Token* token_create(TokenType type, char* value);

#endif


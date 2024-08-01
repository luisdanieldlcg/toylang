#include "token.h"
#include <stdlib.h>

Token* token_create(TokenType type, char* value) {
    Token* token = malloc(sizeof(Token));
    token->type = type;
    token->value = value;
    return token;
}

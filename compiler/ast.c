#include "ast.h"
#include <stdlib.h>

struct ASTNode* ast_create(int type) {
  AST* ast = malloc(sizeof(AST));
  ast->type = type;
  return ast;
}


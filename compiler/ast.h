#ifndef AST_H
#define AST_H

typedef enum ASTNodeType {
  AST_VAR_DEF,
  AST_VAR,
  AST_FUNC_CALL,
  AST_STR,
} ASTNodeType ;


typedef struct ASTNode {

  ASTNodeType type;

  char var_def_name;
  struct ASTNode* var_def_value;

  char* var_name;
  struct ASTNode** func_call_args;
  // AST_STR
  char* str_value; 
} AST;

struct ASTNode* ast_create(int type);


#endif



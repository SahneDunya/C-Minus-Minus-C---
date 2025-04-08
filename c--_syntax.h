#ifndef C_MINUS_MINUS_SYNTAX_H
#define C_MINUS_MINUS_SYNTAX_H

#include "c--_lexer.h" // Assuming lexer is implemented
#include "c--_data_types.h"
#include "c--_operators.h"

// Soyut Sözdizimi Ağacı (AST) Düğüm Tipleri
typedef enum {
    AST_PROGRAM,
    AST_DECLARATION,
    AST_ASSIGNMENT,
    AST_IDENTIFIER,
    AST_INTEGER_LITERAL,
    AST_CHARACTER_LITERAL,
    AST_BOOLEAN_LITERAL,
    AST_BINARY_EXPRESSION,
    AST_UNARY_EXPRESSION,
    AST_IF_STATEMENT,
    AST_ELSE_STATEMENT,
    AST_BLOCK_STATEMENT,
    AST_FUNCTION_DEFINITION,
    AST_FUNCTION_CALL,
    AST_RETURN_STATEMENT,
    AST_EXPRESSION_STATEMENT,
    AST_UNKNOWN
} cmm_ast_node_type;

// Soyut Sözdizimi Ağacı (AST) Düğüm Yapısı
typedef struct cmm_ast_node_t {
    cmm_ast_node_type type;
    int line;
    int column;
    // Düğüm tipine özel veriler
    union {
         AST_IDENTIFIER
        char* identifier;
         AST_INTEGER_LITERAL
        cmm_int int_value;
         AST_CHARACTER_LITERAL
        cmm_char char_value;
         AST_BOOLEAN_LITERAL
        cmm_bool bool_value;
         AST_BINARY_EXPRESSION
        struct {
            cmm_operator op;
            struct cmm_ast_node_t* left;
            struct cmm_ast_node_t* right;
        } binary;
         AST_UNARY_EXPRESSION
        struct {
            cmm_operator op;
            struct cmm_ast_node_t* operand;
        } unary;
         AST_DECLARATION
        struct {
            int data_type; // cmm_data_types.h'daki tiplerden
            char* name;
            struct cmm_ast_node_t* initializer;
        } declaration;
         AST_ASSIGNMENT
        struct {
            char* name;
            struct cmm_ast_node_t* value;
        } assignment;
         AST_IF_STATEMENT
        struct {
            struct cmm_ast_node_t* condition;
            struct cmm_ast_node_t* then_branch;
            struct cmm_ast_node_t* else_branch;
        } if_stmt;
         AST_FUNCTION_DEFINITION
        struct {
            int return_type;
            char* name;
            // Parametre listesi (ileride eklenebilir)
            struct cmm_ast_node_t* body; // AST_BLOCK_STATEMENT olmalı
        } function_def;
         AST_FUNCTION_CALL
        struct {
            char* name;
            // Argüman listesi (ileride eklenebilir)
        } function_call;
         AST_RETURN_STATEMENT
        struct cmm_ast_node_t* return_value;
         AST_BLOCK_STATEMENT
        struct cmm_ast_node_t* first_statement; // Bağlı liste olarak deyimler
    } data;
    struct cmm_ast_node_t* next; // Blok içindeki deyimler veya parametreler/argümanlar için
} cmm_ast_node_t;

// Parser fonksiyonlarının bildirimi
cmm_ast_node_t* cmm_parse(FILE* file); // Giriş dosyasını alacak
cmm_ast_node_t* cmm_parse_program(FILE* file);
cmm_ast_node_t* cmm_parse_statement(FILE* file);
cmm_ast_node_t* cmm_parse_expression(FILE* file);
// ... diğer parser fonksiyonları

#endif // C_MINUS_MINUS_SYNTAX_H
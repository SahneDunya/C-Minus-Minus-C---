#ifndef C_MINUS_MINUS_FUNCTIONS_H
#define C_MINUS_MINUS_FUNCTIONS_H

#include "c--_data_types.h"
#include "c--_syntax.h" // Assuming AST node structure is defined here

// Temsili bir fonksiyon parametre yapısı
typedef struct cmm_parameter_t {
    char* name;
    int type; // cmm_data_types.h'daki tiplerden
    struct cmm_parameter_t* next;
} cmm_parameter_t;

// Temsili bir fonksiyon yapısı
typedef struct cmm_function_t {
    char* name;
    int return_type; // cmm_data_types.h'daki tiplerden
    cmm_parameter_t* parameters;
    cmm_ast_node_t* body; // Fonksiyonun gövdesini temsil eden AST düğümü
    struct cmm_function_t* next; // Fonksiyon tablosu için
} cmm_function_t;

// Fonksiyon yönetimi fonksiyonları
cmm_function_t* cmm_create_function(const char* name, int return_type, cmm_parameter_t* parameters, cmm_ast_node_t* body);
cmm_parameter_t* cmm_create_parameter(const char* name, int type);
void cmm_add_parameter(cmm_parameter_t** param_list, cmm_parameter_t* param);
void cmm_call_function(cmm_function_t* func, /* arguments */ ...); // Henüz tam olarak tanımlanmadı
cmm_function_t* cmm_find_function(const char* name, cmm_function_t* function_list);
void cmm_add_function(cmm_function_t** function_list, cmm_function_t* func);

#endif // C_MINUS_MINUS_FUNCTIONS_H
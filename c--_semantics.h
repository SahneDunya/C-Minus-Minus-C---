#ifndef C_MINUS_MINUS_SEMANTICS_H
#define C_MINUS_MINUS_SEMANTICS_H

#include "c--_syntax.h" // Assuming AST node definition is here
#include "c--_data_types.h"
#include "c--_functions.h" // For function structure

// Sembol Tablosu Girdisi Yapısı
typedef struct cmm_symbol_t {
    char* name;
    int type; // cmm_data_types.h'daki tiplerden
    cmm_symbol_type symbol_kind; // VARIABLE, FUNCTION, ...
    // Ek bilgiler (fonksiyonlar için parametreler, dönüş tipi vb.)
    cmm_function_t* function_data; // Eğer sembol bir fonksiyonsa
    // Kapsam bilgisi (global, yerel) eklenebilir
    struct cmm_symbol_t* next;
} cmm_symbol_t;

// Sembol Tipleri
typedef enum {
    SYMBOL_VARIABLE,
    SYMBOL_FUNCTION
} cmm_symbol_type;

// Sembol Tablosu Yönetimi Fonksiyonları
cmm_symbol_t* cmm_create_symbol(const char* name, int type, cmm_symbol_type kind);
void cmm_add_symbol(cmm_symbol_t** table, cmm_symbol_t* symbol);
cmm_symbol_t* cmm_find_symbol(cmm_symbol_t* table, const char* name);

// Semantik Analiz Fonksiyonu
void cmm_analyze(cmm_ast_node_t* root); // AST'nin kök düğümünü alacak

// Yardımcı Semantik Kontrol Fonksiyonları (örnekler)
 bool cmm_check_type_compatibility(int type1, int type2);
 void cmm_check_variable_declaration(cmm_ast_node_t* variable_node, cmm_symbol_t** symbol_table);
 void cmm_check_function_call(cmm_ast_node_t* call_node, cmm_symbol_t* symbol_table);

#endif // C_MINUS_MINUS_SEMANTICS_H
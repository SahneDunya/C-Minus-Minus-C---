#ifndef C_MINUS_MINUS_VARIABLES_H
#define C_MINUS_MINUS_VARIABLES_H

#include "c--_data_types.h"
#include "c--_semantics.h" // For symbol table interaction

// Değişken Bilgisi Yapısı
typedef struct cmm_variable_t {
    char* name;
    int type; // cmm_data_types.h'daki tiplerden
    // Değişkenin değerini saklamak için bir union kullanılabilir
    union {
        cmm_int int_value;
        cmm_char char_value;
        cmm_bool bool_value;
        cmm_ptr ptr_value;
        // Diğer veri tipleri için eklenebilir
    } value;
    // Kapsam bilgisi (global, yerel) eklenebilir
    cmm_symbol_t* symbol_entry; // Sembol tablosu girdisine işaretçi
    struct cmm_variable_t* next; // (Gerekirse, örneğin bir blok içindeki değişkenler için)
} cmm_variable_t;

// Değişken Yönetimi Fonksiyonları
cmm_variable_t* cmm_create_variable(const char* name, int type);
void cmm_set_variable_value(cmm_variable_t* var, ...); // Variadic fonksiyon ile değer atama
cmm_variable_t* cmm_get_variable(const char* name, cmm_symbol_t* current_scope); // Sembol tablosundan değişkeni al
void cmm_initialize_variable(cmm_variable_t* var);

#endif // C_MINUS_MINUS_VARIABLES_H
#include "c--_variables.h"
#include "c--_error_handling.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h> // Variadic arguments for setting values

// Yeni bir değişken oluşturma fonksiyonu
cmm_variable_t* cmm_create_variable(const char* name, int type) {
    cmm_variable_t* var = (cmm_variable_t*)malloc(sizeof(cmm_variable_t));
    if (!var) {
        cmm_report_error(ERROR_MEMORY_ALLOCATION_FAILED, 0, 0, "Değişken için bellek ayrılamadı.");
        exit(EXIT_FAILURE);
    }
    var->name = strdup(name);
    if (!var->name) {
        cmm_report_error(ERROR_MEMORY_ALLOCATION_FAILED, 0, 0, "Değişken adı için bellek ayrılamadı.");
        free(var);
        exit(EXIT_FAILURE);
    }
    var->type = type;
    var->symbol_entry = NULL; // Sembol tablosu girdisi henüz ayarlanmadı
    var->next = NULL;
    cmm_initialize_variable(var);
    return var;
}

// Değişkenin değerini ayarlama fonksiyonu (variadic)
void cmm_set_variable_value(cmm_variable_t* var, ...) {
    if (!var) {
        fprintf(stderr, "Hata: Geçersiz değişken işaretçisi.\n");
        return;
    }

    va_list args;
    va_start(args, var);

    switch (var->type) {
        case CMM_TYPE_INT: // Assuming CMM_TYPE_INT is defined in c--_data_types.h
            var->value.int_value = va_arg(args, cmm_int);
            break;
        case CMM_TYPE_CHAR: // Assuming CMM_TYPE_CHAR is defined
            var->value.char_value = (cmm_char)va_arg(args, int); // char, int olarak promote edilir
            break;
        case CMM_TYPE_BOOL: // Assuming CMM_TYPE_BOOL is defined
            var->value.bool_value = (cmm_bool)va_arg(args, int); // bool da int olarak promote edilir
            break;
        case CMM_TYPE_PTR: // Assuming CMM_TYPE_PTR is defined
            var->value.ptr_value = va_arg(args, cmm_ptr);
            break;
        default:
            fprintf(stderr, "Hata: Bilinmeyen veri tipi (%d) için değer ayarlanamıyor.\n", var->type);
            break;
    }

    va_end(args);
}

// Sembol tablosundan değişkeni alma fonksiyonu
cmm_variable_t* cmm_get_variable(const char* name, cmm_symbol_t* current_scope) {
    cmm_symbol_t* symbol = cmm_find_symbol(current_scope, name);
    if (symbol && symbol->symbol_kind == SYMBOL_VARIABLE) {
        // Burada sembol tablosu girdisinden değişkenle ilgili bilgileri (tip vb.) alabiliriz.
        // Gerçek değişken değerleri genellikle bir ortamda (environment) saklanır.
        // Bu örnekte, sadece sembolü buluyoruz. Değer yönetimi daha karmaşık olabilir.
        // Belki bir değişken "store" veya "environment" yapısı tutulmalı.
        fprintf(stderr, "UYARI: Değişken değerleri henüz tam olarak yönetilmiyor. Sadece sembol bulundu.\n");
        return NULL; // Geçici olarak NULL döndürülüyor. Gerçek implementasyon farklı olacaktır.
    }
    return NULL;
}

// Değişkeni varsayılan bir değere başlatma fonksiyonu
void cmm_initialize_variable(cmm_variable_t* var) {
    if (!var) return;
    switch (var->type) {
        case CMM_TYPE_INT:
            var->value.int_value = 0;
            break;
        case CMM_TYPE_CHAR:
            var->value.char_value = '\0';
            break;
        case CMM_TYPE_BOOL:
            var->value.bool_value = CMM_FALSE;
            break;
        case CMM_TYPE_PTR:
            var->value.ptr_value = NULL;
            break;
        default:
            fprintf(stderr, "Uyarı: Bilinmeyen veri tipi (%d) için varsayılan değer ayarlanamadı.\n", var->type);
            break;
    }
}
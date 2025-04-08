#include "c--_semantics.h"
#include "c--_error_handling.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Sembol Tablosu Oluşturma Fonksiyonu
cmm_symbol_t* cmm_create_symbol(const char* name, int type, cmm_symbol_type kind) {
    cmm_symbol_t* symbol = (cmm_symbol_t*)malloc(sizeof(cmm_symbol_t));
    if (!symbol) {
        cmm_report_error(ERROR_MEMORY_ALLOCATION_FAILED, 0, 0, "Sembol tablosu girdisi için bellek ayrılamadı.");
        exit(EXIT_FAILURE);
    }
    symbol->name = strdup(name);
    if (!symbol->name) {
        cmm_report_error(ERROR_MEMORY_ALLOCATION_FAILED, 0, 0, "Sembol adı için bellek ayrılamadı.");
        free(symbol);
        exit(EXIT_FAILURE);
    }
    symbol->type = type;
    symbol->symbol_kind = kind;
    symbol->function_data = NULL; // Başlangıçta fonksiyon verisi yok
    symbol->next = NULL;
    return symbol;
}

// Sembolü Sembol Tablosuna Ekleme Fonksiyonu
void cmm_add_symbol(cmm_symbol_t** table, cmm_symbol_t* symbol) {
    symbol->next = *table;
    *table = symbol;
}

// Sembol Tablosunda Bir Sembol Bulma Fonksiyonu
cmm_symbol_t* cmm_find_symbol(cmm_symbol_t* table, const char* name) {
    cmm_symbol_t* current = table;
    while (current) {
        if (strcmp(current->name, name) == 0) {
            return current;
        }
        current = current->next;
    }
    return NULL; // Sembol bulunamadı
}

// Semantik Analiz Fonksiyonu (AST üzerinde gezinerek)
void cmm_analyze(cmm_ast_node_t* root) {
    cmm_symbol_t* global_symbol_table = NULL; // Global sembol tablosu

    printf("Semantik analiz başlatılıyor...\n");

    // Burada AST üzerinde gezinerek semantik kontroller yapılacak.
    // Bu, düğümün tipine göre farklı işlemleri içerecektir.
    // Örnek bir taslak (gerçek implementasyon AST yapınıza bağlı olacaktır):
     if (root != NULL) {
         switch (root->type) {
             case AST_DECLARATION:
                 // Değişken veya fonksiyon deklarasyonunu işle
                 break;
             case AST_ASSIGNMENT:
                 // Atama ifadesini işle ve tip uyumluluğunu kontrol et
                 break;
             case AST_IDENTIFIER:
                 // Tanımlayıcının sembol tablosunda tanımlı olup olmadığını kontrol et
                 break;
             case AST_FUNCTION_CALL:
                 // Fonksiyon çağrısını işle ve argümanları kontrol et
                 break;
             case AST_IF_STATEMENT:
                 // if ifadesinin koşulunu ve gövdelerini işle
                 break;
             // ... diğer AST düğüm tipleri
        }
         // Alt düğümleri yinelemeli olarak işle
         if (root->left) cmm_analyze(root->left);
         if (root->right) cmm_analyze(root->right);
         // ... diğer alt düğümler
     }

    printf("Semantik analiz tamamlandı.\n");

    // Sembol tablosunu temizleme (manuel bellek yönetimi)
    cmm_symbol_t* current = global_symbol_table;
    while (current) {
        cmm_symbol_t* next = current->next;
        free(current->name);
        // Fonksiyon verisi de serbest bırakılabilir eğer ayrıldıysa
        free(current);
        current = next;
    }
}

// Örnek bir yardımcı semantik kontrol fonksiyonu (taslak):
 bool cmm_check_type_compatibility(int type1, int type2) {
     return type1 == type2; // Basit bir örnek
 }

// Örnek bir yardımcı semantik kontrol fonksiyonu (taslak):
 void cmm_check_variable_declaration(cmm_ast_node_t* variable_node, cmm_symbol_t** symbol_table) {
     char* var_name = variable_node->identifier; // AST düğümünden tanımlayıcıyı al
     int var_type = variable_node->data_type; // AST düğümünden veri tipini al
     if (cmm_find_symbol(*symbol_table, var_name)) {
         cmm_report_error(ERROR_SEMANTIC_REDECLARED_VARIABLE, variable_node->line, variable_node->column, "Değişken '%s' zaten tanımlanmış.", var_name);
     } else {
         cmm_symbol_t* new_symbol = cmm_create_symbol(var_name, var_type, SYMBOL_VARIABLE);
         cmm_add_symbol(symbol_table, new_symbol);
         printf("Sembol Tablosuna Eklendi (Değişken): '%s' (Tip: %d)\n", var_name, var_type);
     }
 }

// Örnek bir yardımcı semantik kontrol fonksiyonu (taslak):
 void cmm_check_function_call(cmm_ast_node_t* call_node, cmm_symbol_t* symbol_table) {
     char* func_name = call_node->function_name; // AST düğümünden fonksiyon adını al
     cmm_symbol_t* function_symbol = cmm_find_symbol(symbol_table, func_name);
     if (!function_symbol || function_symbol->symbol_kind != SYMBOL_FUNCTION) {
         cmm_report_error(ERROR_SEMANTIC_UNDECLARED_FUNCTION, call_node->line, call_node->column, "Tanımsız fonksiyon '%s'.", func_name);
     } else {
         // Argüman sayısını ve tiplerini kontrol et (ileride implement edilecek)
         printf("Fonksiyon çağrısı kontrol edildi: '%s'\n", func_name);
     }
 }
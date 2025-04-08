#include "c--_functions.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdarg.h> // Variadic arguments for function calls (future)

// Basit bir fonksiyon oluşturma fonksiyonu
cmm_function_t* cmm_create_function(const char* name, int return_type, cmm_parameter_t* parameters, cmm_ast_node_t* body) {
    cmm_function_t* new_func = (cmm_function_t*)malloc(sizeof(cmm_function_t));
    if (new_func == NULL) {
        perror("Bellek ayırma hatası");
        return NULL;
    }
    new_func->name = strdup(name);
    if (new_func->name == NULL) {
        perror("Bellek ayırma hatası");
        free(new_func);
        return NULL;
    }
    new_func->return_type = return_type;
    new_func->parameters = parameters;
    new_func->body = body;
    new_func->next = NULL;
    return new_func;
}

// Fonksiyon parametresi oluşturma fonksiyonu
cmm_parameter_t* cmm_create_parameter(const char* name, int type) {
    cmm_parameter_t* new_param = (cmm_parameter_t*)malloc(sizeof(cmm_parameter_t));
    if (new_param == NULL) {
        perror("Bellek ayırma hatası");
        return NULL;
    }
    new_param->name = strdup(name);
    if (new_param->name == NULL) {
        perror("Bellek ayırma hatası");
        free(new_param);
        return NULL;
    }
    new_param->type = type;
    new_param->next = NULL;
    return new_param;
}

// Parametre listesine parametre ekleme fonksiyonu
void cmm_add_parameter(cmm_parameter_t** param_list, cmm_parameter_t* param) {
    if (*param_list == NULL) {
        *param_list = param;
    } else {
        cmm_parameter_t* current = *param_list;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = param;
    }
}

// Bir fonksiyonu çağırma fonksiyonu (henüz temel düzeyde)
void cmm_call_function(cmm_function_t* func, /* arguments */ ...) {
    if (func != NULL && func->body != NULL) {
        printf("Fonksiyon '%s' çağrılıyor...\n", func->name);
        // Burada argümanları işlemeniz ve fonksiyonun gövdesini yürütmeniz gerekecek.
        // Bu, yürütme motorunun bir parçası olacaktır.
        printf("Fonksiyon '%s' tamamlandı.\n", func->name);
    } else {
        fprintf(stderr, "Hata: Geçersiz fonksiyon veya fonksiyon gövdesi.\n");
    }
}

// Fonksiyon listesinde bir fonksiyon bulma fonksiyonu
cmm_function_t* cmm_find_function(const char* name, cmm_function_t* function_list) {
    cmm_function_t* current = function_list;
    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            return current;
        }
        current = current->next;
    }
    return NULL; // Fonksiyon bulunamadı
}

// Fonksiyon listesine bir fonksiyon ekleme fonksiyonu
void cmm_add_function(cmm_function_t** function_list, cmm_function_t* func) {
    if (*function_list == NULL) {
        *function_list = func;
    } else {
        cmm_function_t* current = *function_list;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = func;
    }
}
#include <stdio.h>
#include <stdlib.h>
#include "c--_syntax.h"
#include "c--_semantics.h"
#include "c--_error_handling.h"

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Kullanım: %s <kaynak_dosya>\n", argv[0]);
        return 1;
    }

    const char *source_file_path = argv[1];
    FILE *source_file = fopen(source_file_path, "r");
    if (!source_file) {
        perror("Kaynak dosya açılamadı");
        return 1;
    }

    printf("C-- Derleyicisi Başlatılıyor...\n");

    // Sözdizimi Analizi (Parsing)
    printf("Sözdizimi analizi yapılıyor...\n");
    cmm_ast_node_t *ast_root = cmm_parse(source_file);
    fclose(source_file);

    if (!ast_root) {
        fprintf(stderr, "Sözdizimi analizinde hatalar bulundu. Derleme durduruluyor.\n");
        // AST'yi serbest bırakmak gerekebilir
        return 1;
    }

    // Semantik Analiz
    printf("Semantik analiz yapılıyor...\n");
    cmm_analyze(ast_root);

    // Kod Üretimi veya Yorumlama (Şimdilik sadece bir mesaj)
    printf("Kod üretimi veya yorumlama aşaması (henüz implemente edilmedi).\n");

    // Belleği Temizleme (AST'yi serbest bırakma) - Basit bir örnek
    // Gerçek bir derleyicide bu çok daha karmaşık olabilir
    void cmm_free_ast(cmm_ast_node_t* node) {
        if (node == NULL) return;
        switch (node->type) {
            case AST_IDENTIFIER:
                free(node->data.identifier);
                break;
            case AST_BINARY_EXPRESSION:
                cmm_free_ast(node->data.binary.left);
                cmm_free_ast(node->data.binary.right);
                break;
            case AST_UNARY_EXPRESSION:
                cmm_free_ast(node->data.unary.operand);
                break;
            case AST_DECLARATION:
                free(node->data.declaration.name);
                cmm_free_ast(node->data.declaration.initializer);
                break;
            case AST_ASSIGNMENT:
                free(node->data.assignment.name);
                cmm_free_ast(node->data.assignment.value);
                break;
            case AST_IF_STATEMENT:
                cmm_free_ast(node->data.if_stmt.condition);
                cmm_free_ast(node->data.if_stmt.then_branch);
                cmm_free_ast(node->data.if_stmt.else_branch);
                break;
            case AST_FUNCTION_DEFINITION:
                free(node->data.function_def.name);
                cmm_free_ast(node->data.function_def.body);
                break;
            case AST_FUNCTION_CALL:
                free(node->data.function_call.name);
                // Argümanları da serbest bırakmak gerekebilir
                break;
            case AST_BLOCK_STATEMENT: {
                cmm_ast_node_t* current = node->data.first_statement;
                while (current) {
                    cmm_ast_node_t* next = current->next;
                    cmm_free_ast(current);
                    current = next;
                }
                break;
            }
            // Diğer düğüm türleri için de serbest bırakma işlemleri eklenebilir
            default:
                break;
        }
        free(node);
    }

    if (ast_root) {
        printf("AST serbest bırakılıyor...\n");
        cmm_free_ast(ast_root);
    }

    printf("C-- Derleyici Tamamlandı.\n");

    return 0;
}
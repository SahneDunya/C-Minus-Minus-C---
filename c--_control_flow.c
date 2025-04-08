#include "c--_control_flow.h"
#include <stdio.h>

// NOT: Bu dosya, C-- dilinin kontrol akışı yapılarının (sadece if-else) yürütülmesini ele alır.
// Bu fonksiyonlar, genellikle bir yürütme motoru (interpreter veya kod üreteci) tarafından,
// sözdizimi analizi sonucunda oluşturulan Soyut Sözdizimi Ağacı (AST) üzerinde çağrılır.

// Bir AST düğümünü (ifade) boolean bir değere değerlendiren bir fonksiyonun varlığını varsayıyoruz.
// Bu fonksiyon, dilinizin yürütme motorunun bir parçası olacaktır.
extern int cmm_evaluate_expression(cmm_ast_node_t* node);

// Bir AST düğümünü (deyim veya ifade) yürüten bir fonksiyonun varlığını varsayıyoruz.
// Bu da dilinizin yürütme motorunun bir parçası olacaktır.
extern void cmm_execute_statement(cmm_ast_node_t* node);

// 'if' ifadesini yürütme fonksiyonu
void cmm_execute_if_statement(cmm_ast_node_t* condition, cmm_ast_node_t* if_body) {
    if (condition != NULL && if_body != NULL) {
        // 1. 'if' ifadesinin koşulunu temsil eden AST düğümünü değerlendir.
        // Bu değerlendirme sonucunda bir boolean değer (C'de 0 veya 0 olmayan bir tamsayı) elde edilir.
        int condition_value = cmm_evaluate_expression(condition);

        // 2. Eğer koşul doğruysa (0 olmayan bir değer), 'if' bloğunu temsil eden AST düğümünü yürüt.
        if (condition_value) {
            cmm_execute_statement(if_body);
        }
        // C-- sadece if-else desteklediği için burada başka bir kontrol yapısı (örn: else if) yoktur.
    } else {
        fprintf(stderr, "Hata: Geçersiz 'if' ifadesi yapısı (koşul veya gövde NULL).\n");
    }
}

// 'if-else' ifadesini yürütme fonksiyonu
void cmm_execute_if_else_statement(cmm_ast_node_t* condition, cmm_ast_node_t* if_body, cmm_ast_node_t* else_body) {
    if (condition != NULL && if_body != NULL) {
        // 1. 'if' ifadesinin koşulunu temsil eden AST düğümünü değerlendir.
        int condition_value = cmm_evaluate_expression(condition);

        // 2. Eğer koşul doğruysa, 'if' bloğunu yürüt.
        if (condition_value) {
            cmm_execute_statement(if_body);
        } else if (else_body != NULL) {
            // 3. Aksi takdirde (koşul yanlış) ve bir 'else' bloğu varsa, 'else' bloğunu yürüt.
            cmm_execute_statement(else_body);
        }
        // C-- sadece if-else desteklediği için burada başka bir kontrol yapısı yoktur.
    } else {
        fprintf(stderr, "Hata: Geçersiz 'if-else' ifadesi yapısı (koşul veya if gövdesi NULL).\n");
    }
}
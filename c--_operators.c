#include "c--_operators.h"
#include "c--_data_types.h"
#include "c--_error_handling.h" // Hata raporlama için (örneğin, tanımsız operatör)
#include <stdio.h> // Gerekirse hata mesajları için

// NOT: Bu dosya, C-- dilinde desteklenen operatörlerin tanımlarını ve
// bu operatörlerin nasıl işleneceğine dair temel bir çerçeveyi içerir.
// Gerçek implementasyon, dilin semantik analiz ve kod üretimi/yorumlaması aşamalarında yapılacaktır.

// İleride operatörlerin semantik analiz veya kod üretimi sırasında nasıl işleneceğine dair örnek bir fonksiyon (taslak):
 cmm_int cmm_evaluate_binary_expression(cmm_operator op, cmm_int left_operand, cmm_int right_operand) {
     switch (op) {
         case CMM_OPERATOR_ADD: return left_operand + right_operand;
         case CMM_OPERATOR_SUBTRACT: return left_operand - right_operand;
         case CMM_OPERATOR_MULTIPLY: return left_operand * right_operand;
         case CMM_OPERATOR_DIVIDE:
             if (right_operand == 0) {
                 cmm_report_error(ERROR_RUNTIME_DIVISION_BY_ZERO, 0, 0, "Sıfıra bölme hatası.");
                 return 0; // Hata durumunda bir değer döndürülmeli (nasıl ele alınacağı dil tasarımına bağlı)
             }
             return left_operand / right_operand;
        default:
            cmm_report_error(ERROR_SEMANTIC_INVALID_OPERATOR, 0, 0, "Geçersiz ikili operatör.");
             return 0;
     }
 }

// Benzer fonksiyonlar diğer operatörler için de yazılabilir (ilişkisel, mantıksal vb.).

// Operatörlerin önceliği (parser için gerekli olabilir)
// Örneğin:
 int cmm_get_operator_precedence(cmm_operator op) {
     switch (op) {
         case CMM_OPERATOR_MULTIPLY:
         case CMM_OPERATOR_DIVIDE:
             return 2;
         case CMM_OPERATOR_ADD:
         case CMM_OPERATOR_SUBTRACT:
             return 1;
         case CMM_OPERATOR_EQUAL_EQUAL:
         case CMM_OPERATOR_NOT_EQUAL_TO:
         case CMM_OPERATOR_GREATER_THAN:
         case CMM_OPERATOR_LESS_THAN:
         case CMM_OPERATOR_GREATER_THAN_OR_EQUAL_TO:
         case CMM_OPERATOR_LESS_THAN_OR_EQUAL_TO:
             return 0; // Daha düşük öncelik
         default:
             return -1; // Tanımsız operatör
     }
 }

// Operatörlerin birleşme yönü (parser için gerekli olabilir)
// Örneğin:
 typedef enum {
     CMM_ASSOCIATIVITY_LEFT,
     CMM_ASSOCIATIVITY_RIGHT
 } cmm_associativity;

 cmm_associativity cmm_get_operator_associativity(cmm_operator op) {
     switch (op) {
         case CMM_OPERATOR_ASSIGNMENT:
             return CMM_ASSOCIATIVITY_RIGHT;
         default:
             return CMM_ASSOCIATIVITY_LEFT;
     }
 }

// ... diğer operatörlerle ilgili fonksiyonlar eklenebilir.
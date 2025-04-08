#ifndef C_MINUS_MINUS_CONTROL_FLOW_H
#define C_MINUS_MINUS_CONTROL_FLOW_H

// C-- Dilinin Kontrol Akışı Yapıları (Sadece if-else desteklenir)

// Soyut Sözdizimi Ağacı (AST) düğüm yapısının tanımının başka bir yerde olduğunu varsayıyoruz.
// Kontrol akışı ifadeleri (if, else) bu ağacın düğümleri olarak temsil edilecektir.
typedef struct cmm_ast_node_t cmm_ast_node_t;

// 'if' ifadesini AST üzerinde yürüten fonksiyon.
// Parametreler:
//   - condition: 'if' koşulunu temsil eden AST düğümü.
//   - if_body: Koşul doğru olduğunda yürütülecek olan kod bloğunu temsil eden AST düğümü.
void cmm_execute_if_statement(cmm_ast_node_t* condition, cmm_ast_node_t* if_body);

// 'if-else' ifadesini AST üzerinde yürüten fonksiyon.
// Parametreler:
//   - condition: 'if' koşulunu temsil eden AST düğümü.
//   - if_body: Koşul doğru olduğunda yürütülecek olan kod bloğunu temsil eden AST düğümü.
//   - else_body: Koşul yanlış olduğunda yürütülecek olan kod bloğunu temsil eden AST düğümü (isteğe bağlı, NULL olabilir).
void cmm_execute_if_else_statement(cmm_ast_node_t* condition, cmm_ast_node_t* if_body, cmm_ast_node_t* else_body);

#endif // C_MINUS_MINUS_CONTROL_FLOW_H
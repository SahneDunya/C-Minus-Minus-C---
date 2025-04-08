#include "c--_syntax.h"
#include "c--_lexer.h"
#include "c--_error_handling.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Yardımcı fonksiyon: Yeni bir AST düğümü oluşturur
cmm_ast_node_t* cmm_create_ast_node(cmm_ast_node_type type, int line, int column) {
    cmm_ast_node_t* node = (cmm_ast_node_t*)malloc(sizeof(cmm_ast_node_t));
    if (!node) {
        cmm_report_error(ERROR_MEMORY_ALLOCATION_FAILED, line, column, "AST düğümü için bellek ayrılamadı.");
        exit(EXIT_FAILURE);
    }
    node->type = type;
    node->line = line;
    node->column = column;
    node->next = NULL;
    // Birliğin (union) içeriğini sıfırla (isteğe bağlı)
    memset(&node->data, 0, sizeof(node->data));
    return node;
}

// Ana parser fonksiyonu
cmm_ast_node_t* cmm_parse(FILE* file) {
    // Burada lexer'ı başlatma ve programı parse etme mantığı olacak
    cmm_ast_node_t* program_node = cmm_parse_program(file);
    return program_node;
}

// Programı parse etme fonksiyonu (en üst seviye)
cmm_ast_node_t* cmm_parse_program(FILE* file) {
    cmm_ast_node_t* program_node = cmm_create_ast_node(AST_PROGRAM, 0, 0); // Satır/sütun bilgisi başlangıçta 0 olabilir
    cmm_ast_node_t* current_statement = NULL;
    cmm_token* token;

    printf("Parsing program...\n");

    while ((token = cmm_get_next_token(file))->type != TOKEN_EOF) {
        // Şu an sadece temel bir deyim parse etme varsayımı
        cmm_ast_node_t* statement_node = cmm_parse_statement(file);
        if (statement_node) {
            if (program_node->data.first_statement == NULL) {
                program_node->data.first_statement = statement_node;
                current_statement = statement_node;
            } else {
                current_statement->next = statement_node;
                current_statement = statement_node;
            }
        }
        if (token->value) free(token->value);
        free(token);
    }
    if (token) free(token);

    printf("Parsing complete.\n");
    return program_node;
}

// Bir deyimi parse etme fonksiyonu (çok temel bir örnek)
cmm_ast_node_t* cmm_parse_statement(FILE* file) {
    cmm_token* token = cmm_peek_next_token(file);
    if (!token) return NULL;

    cmm_ast_node_t* statement_node = NULL;

    switch (token->type) {
        case TOKEN_KEYWORD_IF:
            statement_node = cmm_parse_if_statement(file);
            break;
        // ... diğer deyim türleri (değişken tanımlama, atama, fonksiyon çağrısı vb.)
        default:
            // Basit bir ifade deyimi olarak kabul etmeye çalış
            statement_node = cmm_parse_expression_statement(file);
            break;
    }

    return statement_node;
}

// Bir ifade deyimini parse etme fonksiyonu (çok temel bir örnek)
cmm_ast_node_t* cmm_parse_expression_statement(FILE* file) {
    cmm_ast_node_t* expression_node = cmm_parse_expression(file);
    if (expression_node) {
        // İfade deyimleri genellikle bir noktalı virgülle biter
        cmm_token* semicolon_token = cmm_get_next_token(file);
        if (!semicolon_token || semicolon_token->type != TOKEN_SEMICOLON) {
            if (semicolon_token) {
                cmm_report_error(ERROR_SYNTAX_MISSING_TOKEN, semicolon_token->line, semicolon_token->column, "Noktalı virgül bekleniyordu.");
                if (semicolon_token->value) free(semicolon_token->value);
                free(semicolon_token);
            } else {
                cmm_report_error(ERROR_SYNTAX_MISSING_TOKEN, expression_node->line, expression_node->column, "Noktalı virgül bekleniyordu (dosya sonu).");
            }
            // Hata durumunda AST'yi serbest bırakmak gerekebilir
        } else {
            if (semicolon_token->value) free(semicolon_token->value);
            free(semicolon_token);
        }
        return expression_node;
    }
    return NULL;
}

// Bir ifadeyi parse etme fonksiyonu (çok temel bir örnek)
cmm_ast_node_t* cmm_parse_expression(FILE* file) {
    cmm_token* token = cmm_get_next_token(file);
    if (!token) return NULL;

    cmm_ast_node_t* expression_node = NULL;

    switch (token->type) {
        case TOKEN_IDENTIFIER:
            expression_node = cmm_create_ast_node(AST_IDENTIFIER, token->line, token->column);
            expression_node->data.identifier = strdup(token->value);
            break;
        case TOKEN_LITERAL_INTEGER:
            expression_node = cmm_create_ast_node(AST_INTEGER_LITERAL, token->line, token->column);
            expression_node->data.int_value = atoi(token->value);
            break;
        // ... diğer ifade türleri (operatörler, parantezler, fonksiyon çağrıları vb.)
        default:
            cmm_report_error(ERROR_SYNTAX_UNEXPECTED_TOKEN, token->line, token->column, "Beklenmeyen token: '%s'", token->value);
            break;
    }

    if (token->value) free(token->value);
    free(token);
    return expression_node;
}

// if ifadesini parse etme fonksiyonu (temel örnek)
cmm_ast_node_t* cmm_parse_if_statement(FILE* file) {
    cmm_token* if_token = cmm_get_next_token(file);
    if (!if_token || if_token->type != TOKEN_KEYWORD_IF) {
        // Hata işleme
        return NULL;
    }
    int line = if_token->line;
    int column = if_token->column;
    if (if_token->value) free(if_token->value);
    free(if_token);

    // Parantez içinde koşul bekleniyor
    cmm_token* open_paren_token = cmm_get_next_token(file);
    if (!open_paren_token || open_paren_token->type != TOKEN_OPEN_PAREN) {
        cmm_report_error(ERROR_SYNTAX_MISSING_TOKEN, line, column, "'(' bekleniyordu.");
        if (open_paren_token) {
            if (open_paren_token->value) free(open_paren_token->value);
            free(open_paren_token);
        }
        return NULL;
    }
    if (open_paren_token->value) free(open_paren_token->value);
    free(open_paren_token);

    cmm_ast_node_t* condition_node = cmm_parse_expression(file);
    if (!condition_node) {
        return NULL;
    }

    cmm_token* close_paren_token = cmm_get_next_token(file);
    if (!close_paren_token || close_paren_token->type != TOKEN_CLOSE_PAREN) {
        cmm_report_error(ERROR_SYNTAX_MISSING_TOKEN, condition_node->line, condition_node->column, "')' bekleniyordu.");
        if (close_paren_token) {
            if (close_paren_token->value) free(close_paren_token->value);
            free(close_paren_token);
        }
        // Koşul düğümünü serbest bırakmak gerekebilir
        return NULL;
    }
    if (close_paren_token->value) free(close_paren_token->value);
    free(close_paren_token);

    cmm_ast_node_t* then_branch_node = cmm_parse_statement(file);
    if (!then_branch_node) {
        return NULL;
    }

    // Else kısmı kontrolü
    cmm_token* else_peek_token = cmm_peek_next_token(file);
    cmm_ast_node_t* else_branch_node = NULL;
    if (else_peek_token && else_peek_token->type == TOKEN_KEYWORD_ELSE) {
        cmm_token* else_token = cmm_get_next_token(file);
        if (else_token->value) free(else_token->value);
        free(else_token);
        else_branch_node = cmm_parse_statement(file);
    }

    cmm_ast_node_t* if_node = cmm_create_ast_node(AST_IF_STATEMENT, line, column);
    if_node->data.if_stmt.condition = condition_node;
    if_node->data.if_stmt.then_branch = then_branch_node;
    if_node->data.if_stmt.else_branch = else_branch_node;

    return if_node;
}

// ... diğer parser fonksiyonları (blok, deklarasyon, atama vb.)
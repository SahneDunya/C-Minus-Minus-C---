#ifndef C_MINUS_MINUS_ERROR_HANDLING_H
#define C_MINUS_MINUS_ERROR_HANDLING_H

// C-- Dilinin Hata Tipleri
typedef enum {
    ERROR_NONE,
    ERROR_LEXICAL_UNEXPECTED_CHARACTER,
    ERROR_LEXICAL_INVALID_TOKEN,

    ERROR_SYNTAX_UNEXPECTED_TOKEN,
    ERROR_SYNTAX_MISSING_TOKEN,
    ERROR_SYNTAX_INVALID_EXPRESSION,
    ERROR_SYNTAX_INVALID_STATEMENT,

    ERROR_SEMANTIC_UNDECLARED_VARIABLE,
    ERROR_SEMANTIC_REDECLARED_VARIABLE,
    ERROR_SEMANTIC_UNDECLARED_FUNCTION,
    ERROR_SEMANTIC_INCORRECT_ARGUMENT_COUNT,
    ERROR_SEMANTIC_INCORRECT_ARGUMENT_TYPE,
    ERROR_SEMANTIC_TYPE_MISMATCH,
    ERROR_SEMANTIC_INVALID_OPERAND,
    ERROR_SEMANTIC_INVALID_RETURN_TYPE,

    ERROR_RUNTIME_DIVISION_BY_ZERO,
    ERROR_RUNTIME_MEMORY_ACCESS_VIOLATION,
    ERROR_RUNTIME_STACK_OVERFLOW,

    ERROR_MEMORY_ALLOCATION_FAILED,
    ERROR_MEMORY_DEALLOCATION_FAILED,

    ERROR_INTERNAL_COMPILER_ERROR,
    ERROR_UNKNOWN
} cmm_error_type;

// Hata Bilgisi Yapısı
typedef struct cmm_error_info_t {
    cmm_error_type type;
    int line;
    int column;
    const char* message;
    // İsteğe bağlı olarak ek bilgiler eklenebilir (örn: hatalı token, beklenen token vb.)
} cmm_error_info_t;

// Hata Raporlama Fonksiyonu
void cmm_report_error(cmm_error_type type, int line, int column, const char* message, ...); // Variadic fonksiyon ile daha esnek mesaj

// Hata Bilgisi Alma Fonksiyonu (isteğe bağlı)
cmm_error_info_t cmm_get_last_error();

#endif // C_MINUS_MINUS_ERROR_HANDLING_H
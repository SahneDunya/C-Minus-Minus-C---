#include "c--_error_handling.h"
#include <stdio.h>
#include <stdarg.h> // Variadic fonksiyonlar için
#include <stdlib.h> // malloc için

// Son oluşan hatayı saklamak için (isteğe bağlı)
static cmm_error_info_t last_error = {ERROR_NONE, 0, 0, NULL};

// Hata Raporlama Fonksiyonu (variadic)
void cmm_report_error(cmm_error_type type, int line, int column, const char* message, ...) {
    const char* type_str;
    switch (type) {
        case ERROR_LEXICAL_UNEXPECTED_CHARACTER: type_str = "Leksikal Hata: Beklenmeyen Karakter"; break;
        case ERROR_LEXICAL_INVALID_TOKEN: type_str = "Leksikal Hata: Geçersiz Token"; break;
        case ERROR_SYNTAX_UNEXPECTED_TOKEN: type_str = "Sözdizimi Hatası: Beklenmeyen Token"; break;
        case ERROR_SYNTAX_MISSING_TOKEN: type_str = "Sözdizimi Hatası: Eksik Token"; break;
        case ERROR_SYNTAX_INVALID_EXPRESSION: type_str = "Sözdizimi Hatası: Geçersiz İfade"; break;
        case ERROR_SYNTAX_INVALID_STATEMENT: type_str = "Sözdizimi Hatası: Geçersiz Deyim"; break;
        case ERROR_SEMANTIC_UNDECLARED_VARIABLE: type_str = "Semantik Hata: Tanımsız Değişken"; break;
        case ERROR_SEMANTIC_REDECLARED_VARIABLE: type_str = "Semantik Hata: Tekrar Tanımlanan Değişken"; break;
        case ERROR_SEMANTIC_UNDECLARED_FUNCTION: type_str = "Semantik Hata: Tanımsız Fonksiyon"; break;
        case ERROR_SEMANTIC_INCORRECT_ARGUMENT_COUNT: type_str = "Semantik Hata: Yanlış Argüman Sayısı"; break;
        case ERROR_SEMANTIC_INCORRECT_ARGUMENT_TYPE: type_str = "Semantik Hata: Yanlış Argüman Tipi"; break;
        case ERROR_SEMANTIC_TYPE_MISMATCH: type_str = "Semantik Hata: Tip Uyuşmazlığı"; break;
        case ERROR_SEMANTIC_INVALID_OPERAND: type_str = "Semantik Hata: Geçersiz Operand"; break;
        case ERROR_SEMANTIC_INVALID_RETURN_TYPE: type_str = "Semantik Hata: Geçersiz Dönüş Tipi"; break;
        case ERROR_RUNTIME_DIVISION_BY_ZERO: type_str = "Çalışma Zamanı Hatası: Sıfıra Bölme"; break;
        case ERROR_RUNTIME_MEMORY_ACCESS_VIOLATION: type_str = "Çalışma Zamanı Hatası: Bellek Erişim İhlali"; break;
        case ERROR_RUNTIME_STACK_OVERFLOW: type_str = "Çalışma Zamanı Hatası: Yığın Taşması"; break;
        case ERROR_MEMORY_ALLOCATION_FAILED: type_str = "Bellek Hatası: Bellek Ayırma Başarısız"; break;
        case ERROR_MEMORY_DEALLOCATION_FAILED: type_str = "Bellek Hatası: Bellek Serbest Bırakma Başarısız"; break;
        case ERROR_INTERNAL_COMPILER_ERROR: type_str = "Dahili Derleyici Hatası"; break;
        default: type_str = "Bilinmeyen Hata"; break;
    }

    fprintf(stderr, "%s (%d:%d): ", type_str, line, column);

    va_list args;
    va_start(args, message);
    vfprintf(stderr, message, args);
    va_end(args);

    fprintf(stderr, "\n");

    // Son hatayı kaydet (isteğe bağlı)
    last_error.type = type;
    last_error.line = line;
    last_error.column = column;
    // Mesajı kopyalamak isteyebilirsiniz, ancak bu örnekte sadece işaretçiyi atıyoruz
    last_error.message = message;
}

// Son Hata Bilgisini Alma Fonksiyonu (isteğe bağlı)
cmm_error_info_t cmm_get_last_error() {
    return last_error;
}
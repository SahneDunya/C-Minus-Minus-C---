#ifndef C_MINUS_MINUS_IO_H
#define C_MINUS_MINUS_IO_H

#include "c--_data_types.h"

// Temel çıktı fonksiyonları
void cmm_print_int(cmm_int value);
void cmm_print_char(cmm_char value);
void cmm_print_bool(cmm_bool value);
void cmm_print_string(const char* str); // Basit string yazdırma (C stili)

// Temel girdi fonksiyonları (ileride implement edilebilir)
 cmm_int cmm_read_int();
 cmm_char cmm_read_char();

#endif // C_MINUS_MINUS_IO_H
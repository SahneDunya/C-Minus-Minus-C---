#ifndef C_MINUS_MINUS_DATA_TYPES_H
#define C_MINUS_MINUS_DATA_TYPES_H

#include <stddef.h> // size_t gibi standart tipler için
#include <stdint.h> // int32_t gibi kesin boyutlu tipler için (isteğe bağlı)

// C-- Dilinin Temel Veri Tipleri

// Tam Sayı Tipleri:
// C'deki 'int' tipine karşılık gelen, platforma bağımlı boyutta işaretli tam sayı.
typedef int cmm_int;

typedef int64_t cmm_int64;  // 64-bit işaretli tam sayı
 typedef int32_t cmm_int32;  // 32-bit işaretli tam sayı
 typedef int16_t cmm_int16;  // 16-bit işaretli tam sayı
 typedef int8_t cmm_int8;   // 8-bit işaretli tam sayı
 typedef uint64_t cmm_uint64; // 64-bit işaretsiz tam sayı
 typedef uint32_t cmm_uint32; // 32-bit işaretsiz tam sayı
 typedef uint16_t cmm_uint16; // 16-bit işaretsiz tam sayı
 typedef uint8_t cmm_uint8;  // 8-bit işaretsiz tam sayı

// Karakter Tipi:
// Tek bir karakteri temsil eden tip. Genellikle 8-bitlik bir boyuta sahiptir.
typedef char cmm_char;

// Boolean Tipi:
// Doğru (true) veya yanlış (false) değerlerini temsil eden tip.
// C'de doğrudan bir boolean tipi olmamasına rağmen, genellikle bu amaçla bir tamsayı tipi kullanılır.
typedef unsigned char cmm_bool; // 0: false, diğer değerler: true

// İşaretçi Tipi:
// Bellekteki bir adresi tutan tip. 'void*' genel bir işaretçidir.
typedef void* cmm_ptr;

// Boolean Değerler İçin Sabitler:
#define CMM_TRUE 1
#define CMM_FALSE 0

 typedef float cmm_float;
 typedef double cmm_double;
 typedef char* cmm_string;

#endif // C_MINUS_MINUS_DATA_TYPES_H
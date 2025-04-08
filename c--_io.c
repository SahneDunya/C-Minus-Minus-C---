#include "c--_io.h"
#include <stdio.h> // putchar ve printf (dikkatli kullanım!)

// NOT: C-- dilinde standart bir kütüphane olmayacağı için, buradaki implementasyonlar
// çok temel seviyededir ve işletim sistemi çağrılarını doğrudan kullanmayı gerektirebilir.
// Şu anki örnek, basitlik adına standart C fonksiyonlarını (putchar, printf, scanf) kullanmaktadır.

// Temel çıktı fonksiyonu: bir tam sayıyı yazdırır
void cmm_print_int(cmm_int value) {
    char buffer[12];
    int i = 0;
    int is_negative = 0;

    if (value < 0) {
        is_negative = 1;
        value = -value;
    }

    do {
        buffer[i++] = '0' + (value % 10);
        value /= 10;
    } while (value > 0);

    if (is_negative) {
        putchar('-');
    }

    while (i > 0) {
        putchar(buffer[--i]);
    }
}

// Temel çıktı fonksiyonu: bir karakteri yazdırır
void cmm_print_char(cmm_char value) {
    putchar(value);
}

// Temel çıktı fonksiyonu: bir boolean değeri yazdırır
void cmm_print_bool(cmm_bool value) {
    if (value == CMM_TRUE) {
        printf("true"); // Dikkat: printf kullanılıyor
    } else {
        printf("false"); // Dikkat: printf kullanılıyor
    }
}

// Temel çıktı fonksiyonu: bir C stili stringi yazdırır
void cmm_print_string(const char* str) {
    if (str != NULL) {
        printf("%s", str); // Dikkat: printf kullanılıyor
    }
}

// Temel girdi fonksiyonları (ileride implement edilebilir)
 cmm_int cmm_read_int() {
     int value;
     scanf("%d", &value); // Dikkat: scanf kullanılıyor
     return value;
 }

 cmm_char cmm_read_char() {
     char value;
     scanf(" %c", &value); // Dikkat: scanf kullanılıyor
     return value;
 }
#ifndef C_MINUS_MINUS_OPERATORS_H
#define C_MINUS_MINUS_OPERATORS_H

// C-- Dilinin Desteklediği Operatörler

// Aritmetik Operatörler
typedef enum {
    CMM_OPERATOR_ADD,       // +
    CMM_OPERATOR_SUBTRACT,  // -
    CMM_OPERATOR_MULTIPLY,  // *
    CMM_OPERATOR_DIVIDE,    // /
    // CMM_OPERATOR_MODULO,    // % (Belki sonra eklenebilir)
} cmm_arithmetic_operator;

// İlişkisel Operatörler
typedef enum {
    CMM_OPERATOR_EQUAL_TO, ==
    CMM_OPERATOR_NOT_EQUAL_TO, !=
    CMM_OPERATOR_GREATER_THAN, >
    CMM_OPERATOR_LESS_THAN, <
    CMM_OPERATOR_GREATER_THAN_OR_EQUAL_TO, >=
    CMM_OPERATOR_LESS_THAN_OR_EQUAL_TO, <=
} cmm_relational_operator;

// Mantıksal Operatörler
typedef enum {
    CMM_OPERATOR_LOGICAL_AND, &&
    CMM_OPERATOR_LOGICAL_OR, ||
    CMM_OPERATOR_LOGICAL_NOT, !
} cmm_logical_operator;

// Atama Operatörleri
typedef enum {
    CMM_OPERATOR_ASSIGNMENT, =
    CMM_OPERATOR_ADD_ASSIGNMENT, += 
    CMM_OPERATOR_SUBTRACT_ASSIGNMENT, -= 
    // ... diğerleri
} cmm_assignment_operator;

// İşaretçi Operatörleri
typedef enum {
    CMM_OPERATOR_DEREFERENCE, * 
    CMM_OPERATOR_ADDRESS_OF, & 
    CMM_OPERATOR_ARROW, -> 
} cmm_pointer_operator;

// Tüm operatörleri kapsayan genel bir enum (isteğe bağlı)
typedef enum {
    CMM_OPERATOR_UNKNOWN,
    CMM_OPERATOR_PLUS = CMM_OPERATOR_ADD,
    CMM_OPERATOR_MINUS = CMM_OPERATOR_SUBTRACT,
    CMM_OPERATOR_STAR = CMM_OPERATOR_MULTIPLY,
    CMM_OPERATOR_SLASH = CMM_OPERATOR_DIVIDE,
    // CMM_OPERATOR_PERCENT = CMM_OPERATOR_MODULO,
    CMM_OPERATOR_EQUAL_EQUAL = CMM_OPERATOR_EQUAL_TO,
    CMM_OPERATOR_BANG_EQUAL = CMM_OPERATOR_NOT_EQUAL_TO,
    CMM_OPERATOR_GREATER = CMM_OPERATOR_GREATER_THAN,
    CMM_OPERATOR_LESS = CMM_OPERATOR_LESS_THAN,
    CMM_OPERATOR_GREATER_EQUAL = CMM_OPERATOR_GREATER_THAN_OR_EQUAL_TO,
    CMM_OPERATOR_LESS_EQUAL = CMM_OPERATOR_LESS_THAN_OR_EQUAL_TO,
    CMM_OPERATOR_AMPERSAND_AMPERSAND = CMM_OPERATOR_LOGICAL_AND,
    CMM_OPERATOR_PIPE_PIPE = CMM_OPERATOR_LOGICAL_OR,
    CMM_OPERATOR_BANG = CMM_OPERATOR_LOGICAL_NOT,
    CMM_OPERATOR_EQUAL = CMM_OPERATOR_ASSIGNMENT,
    CMM_OPERATOR_ASTERISK = CMM_OPERATOR_DEREFERENCE,
    CMM_OPERATOR_AMPERSAND = CMM_OPERATOR_ADDRESS_OF,
     CMM_OPERATOR_ARROW_OP = CMM_OPERATOR_ARROW,
} cmm_operator;

#endif // C_MINUS_MINUS_OPERATORS_H
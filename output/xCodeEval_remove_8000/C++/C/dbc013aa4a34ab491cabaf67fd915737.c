#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char* str;
    size_t length;
} String;

typedef struct {
    String* arr;
    size_t size;
} StringArray;

typedef struct {
    StringArray* arr;
    size_t length;
} StringArrayArray;

typedef struct {
    long long int64;
    unsigned long long uint64;
} Typedefs;

typedef struct {
    int64 first;
    int64 second;
} PairInt64;

typedef struct {
    String first;
    String second;
} PairString;

typedef struct {
    PairString* arr;
    size_t size;
} PairStringArray;

typedef struct {
    String str;
    PairInt64* arr;
    size_t size;
} StringPairInt64Array;

typedef struct {
    String str;
    StringArray* arr;
    size_t size;
} StringStringArrayArray;

typedef struct {
    String str;
    StringArrayArray* arr;
    size_t size;
} StringStringArrayArrayArray;

typedef struct {
    String str;
    StringArrayArrayArray* arr;
    size_t size;
} StringStringArrayArrayArrayArray;

typedef struct {
    String str;
    StringStringArrayArrayArray* arr;
    size_t size;
} StringStringArrayArrayArrayArrayArray;

typedef struct {
    String str;
    StringStringArrayArrayArrayArray* arr;
    size_t size;
} StringStringArrayArrayArrayArrayArrayArray;

typedef struct {
    String str;
    StringStringArrayArrayArrayArrayArray* arr;
    size_t size;
} StringStringArrayArrayArrayArrayArrayArrayArray;

typedef struct {
    String str;
    StringStringArrayArrayArrayArrayArrayArray* arr;
    size_t size;
} StringStringArrayArrayArrayArrayArrayArrayArrayArray;

typedef struct {
    String str;
    StringStringArrayArrayArrayArrayArrayArrayArray* arr;
    size_t size;
} StringStringArrayArrayArrayArrayArrayArrayArrayArrayArray;

typedef struct {
    String str;
    StringStringArrayArrayArrayArrayArrayArrayArrayArray* arr;
    size_t size;
} StringStringArrayArrayArrayArrayArrayArrayArrayArrayArrayArray;

typedef struct {
    String str;
    StringStringArrayArrayArrayArrayArrayArrayArrayArrayArray* arr;
    size_t size;
} StringStringArrayArrayArrayArrayArrayArrayArrayArrayArrayArrayArray;

typedef struct {
    String str;

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define BUF_SIZE 1<<13
#define mod 998244353
#define G 3

typedef struct {
    int* upper;
} DJSet;

typedef struct {
    int** data;
    int size;
} IntMatrix;

typedef struct {
    long* data;
    int size;
} LongArray;

typedef struct {
    int* data;
    int size;
} IntArray;

typedef struct {
    char* data;
    int size;
} CharArray;

typedef struct {
    int** data;
    int rows;
    int cols;
} CharMatrix;

typedef struct {
    int** data;
    int rows;
    int cols;
} IntMatrix;

typedef struct {
    long** data;
    int rows;
    int cols;
} LongMatrix;

typedef struct {
    int* data;
    int size;
} IntArray;

typedef struct {
    long* data;
    int size;
} LongArray;

typedef struct {
    char* data;
    int size;
} CharArray;

typedef struct {
    char** data;
    int size;
} CharArray2D;

typedef struct {
    int** data;
    int size;
} IntArray2D;

typedef struct {
    long** data;
    int size;
} LongArray2D;

typedef struct {
    double** data;
    int size;
} DoubleArray2D;

typedef struct {
    double* data;
    int size;
} DoubleArray;

typedef struct {
    bool* data;
    int size;
} BoolArray;

typedef struct {
    bool** data;
    int size;
} BoolArray2D;

typedef struct {
    int* data;
    int size;
} IntArray;

typedef struct {
    long* data;
    int size;
} LongArray;

typedef struct {
    char* data;
    int size;
} CharArray;

typedef struct {
    char** data;
    int size;
} CharArray2D;

typedef struct {
    int** data;
    int size;
} IntArray2D;

typedef struct {
    long** data;
    int size;
} LongArray2D;

typedef struct {
    double** data;
    int size;
} DoubleArray2D;

typedef struct {
    double* data;
    int size;
} DoubleArray;

typedef struct {
    bool* data;
    int size;
} BoolArray;

typedef struct {
    bool** data;
    int size;
} BoolArray2D;

typedef struct {
    int* data;
    int size;
} IntArray;

typedef struct {
    long* data;
    int size;
} LongArray;

typedef struct {
    char* data;
    int size;
} CharArray;

typedef struct {
    char** data;
    int size;
} CharArray2D;

typedef struct {
    int** data;
    int size;
} IntArray2D;

typedef struct {
    long** data;
    int size;
} LongArray2D;

typedef struct {
    double** data;
    int size;
} DoubleArray2D;

typedef struct {
    double* data;
    int size;
} DoubleArray;

typedef struct {
    bool* data;
    int size;
} BoolArray;

typedef struct {
    bool** data;
    int size;
} BoolArray2D;

typedef struct {
    int* data;
    int size;
} IntArray;

typedef struct {
    long* data;
    int size;
} LongArray;

typedef struct {
    char* data;
    int size;
} CharArray;

typedef struct {
    char** data;
    int size;
} CharArray2D;

typedef struct {
    int** data;
    int size;
} IntArray2D;

typedef struct {
    long** data;
    int size;
} LongArray2D;

typedef struct {
    double** data;
    int size;
} DoubleArray2D;

typedef struct {
    double* data;
    int size;
} DoubleArray;

typedef struct {
    bool* data;
    int size;
} BoolArray;

typedef struct {
    bool** data;
    int size;
} BoolArray2D;

typedef struct {
    int* data;
    int size;
} IntArray;

typedef struct {
    long* data;
    int size;
} LongArray;

typedef struct {
    char* data;
    int size;
} CharArray;

typedef struct {
    char** data;
    int size;
} CharArray2D;

typedef struct {
    int** data;
    int size;
} IntArray2D;

typedef struct {
    long** data;
    int size;
} LongArray2D;

typedef struct {
    double** data;
    int size;
} DoubleArray2D;

typedef struct {
    double* data;
    int size;
} DoubleArray;

typedef struct {
    bool* data;
    int size;
} BoolArray;

typedef struct {
    bool** data;
    int size;
} BoolArray2D;

typedef struct {
    int* data;
    int size;
} IntArray;

typedef struct {
    long* data;
    int size;
} LongArray;

typedef struct {
    char* data;
    int size;
} CharArray;

typedef struct {
    char** data;
    int size;
} CharArray2D;

typedef struct {
    int** data;
    int size;
} IntArray2D;

typedef struct {
    long** data;
    int size;
} LongArray2D;

typedef struct {
    double** data;
    int size;
} DoubleArray2D;

typedef struct {
    double* data;
    int size;
} DoubleArray;

typedef struct {
    bool* data;
    int size;
} BoolArray;

typedef struct {
    bool** data;
    int size;
} BoolArray2D;

typedef struct {
    int* data;
    int size;
} IntArray;

typedef struct {
    long* data;
    int size;
} LongArray;

typedef struct {
    char* data;
    int size;
} CharArray;

typedef struct {
    char** data;
    int size;
} CharArray2D;

typedef struct {
    int** data;
    int size;
} IntArray2D;

typedef struct {
    long** data;
    int size;
} LongArray2D;

typedef struct {
    double** data;
    int size;
} DoubleArray2D;

typedef struct {
    double* data;
    int size;
} DoubleArray;

typedef struct {
    bool* data;
    int size;
} BoolArray;

typedef struct {
    bool** data;
    int size;
} BoolArray2D;

typedef struct {
    int* data;
    int size;
} IntArray;

typedef struct {
    long* data;
    int size;
} LongArray;

typedef struct {
    char* data;
    int size;
} CharArray;

typedef struct {
    char** data;
    int size;
} CharArray2D;

typedef struct {
    int** data;
    int size;
} IntArray2D;

typedef struct {
    long** data;
    int size;
} LongArray2D;

typedef struct {
    double** data;
    int size;
} DoubleArray2D;

typedef struct {
    double* data;
    int size;
} DoubleArray;

typedef struct {
    bool* data;
    int size;
} BoolArray;

typedef struct {
    bool** data;
    int size;
} BoolArray2D;

typedef struct {
    int* data;
    int size;
} IntArray;

typedef struct {
    long* data;
    int size;
} LongArray;

typedef struct {
    char* data;
    int size;
} CharArray;

typedef struct {
    char** data;
    int size;
} CharArray2D;

typedef struct {
    int** data;
    int size;
} IntArray2D;

typedef struct {
    long** data;
    int size;
} LongArray2D;

typedef struct {
    double** data;
    int size;
} DoubleArray2D;

typedef struct {
    double* data;
    int size;
} DoubleArray;

typedef struct {
    bool* data;
    int size;
} BoolArray;

typedef struct {
    bool** data;
    int size;
} BoolArray2D;

typedef struct {
    int* data;
    int size;
} IntArray;

typedef struct {
    long* data;
    int size;
} LongArray;

typedef struct {
    char* data;
    int size;
} CharArray;

typedef struct {
    char** data;
    int size;
} CharArray2D;

typedef struct {
    int** data;
    int size;
} IntArray2D;

typedef struct {
    long** data;
    int size;
} LongArray2D;

typedef struct {
    double** data;
    int size;
} DoubleArray2D;

typedef struct {
    double* data;
    int size;
} DoubleArray;

typedef struct {
    bool* data;
    int size;
} BoolArray;

typedef struct {
    bool** data;
    int size;
} BoolArray2D;

typedef struct {
    int* data;
    int size;
} IntArray;

typedef struct {
    long* data;
    int size;
} LongArray;

typedef struct {
    char* data;
    int size;
} CharArray;

typedef struct {
    char** data;
    int size;
} CharArray2D;

typedef struct {
    int** data;
    int size;
} IntArray2D;

typedef struct {
    long** data;
    int size;
} LongArray2D;

typedef struct {
    double** data;
    int size;
} DoubleArray2D;

typedef struct {
    double* data;
    int size;
} DoubleArray;

typedef struct {
    bool* data;
    int size;
} BoolArray;

typedef struct {
    bool** data;
    int size;
} BoolArray2D;

typedef struct {
    int* data;
    int size;
} IntArray;

typedef struct {
    long* data;
    int size;
} LongArray;

typedef struct {
    char* data;
    int size;
} CharArray;

typedef struct {
    char** data;
    int size;
} CharArray2D;

typedef struct {
    int** data;
    int size;
} IntArray2D;

typedef struct {
    long** data;
    int size;
} LongArray2D;

typedef struct {
    double** data;
    int size;
} DoubleArray2D;

typedef struct {
    double* data;
    int size;
} DoubleArray;

typedef struct {
    bool* data;
    int size;
} BoolArray;

typedef struct {
    bool** data;
    int size;
} BoolArray2D;

typedef struct {
    int* data;
    int size;
} IntArray;

typedef struct {
    long* data;
    int size;
} LongArray;

typedef struct {
    char* data;
    int size;
} CharArray;

typedef struct {
    char** data;
    int size;
} CharArray2D;

typedef struct {
    int** data;
    int size;
} IntArray2D;

typedef struct {
    long** data;
    int size;
} LongArray2D;

typedef struct {
    double** data;
    int size;
} DoubleArray2D;

typedef struct {
    double* data;
    int size;
} DoubleArray;

typedef struct {
    bool* data;
    int size;
} BoolArray;

typedef struct {
    bool** data;
    int size;
} BoolArray2D;

typedef struct {
    int* data;
    int size;
} IntArray;

typedef struct {
    long* data;
    int size;
} LongArray;

typedef struct {
    char* data;
    int size;
} CharArray;

typedef struct {
    char** data;
    int size;
} CharArray2D;

typedef struct {
    int** data;
    int size;
} IntArray2D;

typedef struct {
    long** data;
    int size;
} LongArray2D;

typedef struct {
    double** data;
    int size;
} DoubleArray2D;

typedef struct {
    double* data;
    int size;
} DoubleArray;

typedef struct {
    bool* data;
    int size;
} BoolArray;

typedef struct {
    bool** data;
    int size;
} BoolArray2D;

typedef struct {
    int* data;
    int size;
} IntArray;

typedef struct {
    long* data;
    int size;
} LongArray;

typedef struct {
    char* data;
    int size;
} CharArray;

typedef struct {
    char** data;
    int size;
} CharArray2D;

typedef struct {
    int** data;
    int size;
} IntArray2D;

typedef struct {
    long** data;
    int size;
} LongArray2D;

typedef struct {
    double** data;
    int size;
} DoubleArray2D;

typedef struct {
    double* data;
    int size;
} DoubleArray;

typedef struct {
    bool* data;
    int size;
} BoolArray;

typedef struct {
    bool** data;
    int size;
} BoolArray2D;

typedef struct {
    int* data;
    int size;
} IntArray;

typedef struct {
    long* data;
    int size;
} LongArray;

typedef struct {
    char* data;
    int size;
} CharArray;

typedef struct {
    char** data;
    int size;
} CharArray2D;

typedef struct {
    int** data;
    int size;
} IntArray2D;

typedef struct {
    long** data;
    int size;
} LongArray2D;

typedef struct {
    double** data;
    int size;
} DoubleArray2D;

typedef struct {
    double* data;
    int size;
} DoubleArray;

typedef struct {
    bool* data;
    int size;
} BoolArray;

typedef struct {
    bool** data;
    int size;
} BoolArray2D;

typedef struct {
    int* data;
    int size;
} IntArray;

typedef struct {
    long* data;
    int size;
} LongArray;

typedef struct {
    char* data;
    int size;
} CharArray;

typedef struct {
    char** data;
    int size;
} CharArray2D;

typedef struct {
    int** data;
    int size;
} IntArray2D;

typedef struct {
    long** data;
    int size;
} LongArray2D;

typedef struct {
    double** data;
    int size;
} DoubleArray2D;

typedef struct {
    double* data;
    int size;
} DoubleArray;

typedef struct {
    bool* data;
    int size;
} BoolArray;

typedef struct {
    bool** data;
    int size;
} BoolArray2D;

typedef struct {
    int* data;
    int size;
} IntArray;

typedef struct {
    long* data;
    int size;
} LongArray;

typedef struct {
    char* data;
    int size;
} CharArray;

typedef struct {
    char** data;
    int size;
} CharArray2D;

typedef struct {
    int** data;
    int size;
} IntArray2D;

typedef struct {
    long** data;
    int size;
} LongArray2D;

typedef struct {
    double** data;
    int size;
} DoubleArray2D;

typedef struct {
    double* data;
    int size;
} DoubleArray;

typedef struct {
    bool* data;
    int size;
} BoolArray;

typedef struct {
    bool** data;
    int size;
} BoolArray2D;

typedef struct {
    int* data;
    int size;
} IntArray;

typedef struct {
    long* data;
    int size;
} LongArray;

typedef struct {
    char* data;
    int size;
} CharArray;

typedef struct {
    char** data;
    int size;
} CharArray2D;

typedef struct {
    int** data;
    int size;
} IntArray2D;

typedef struct {
    long** data;
    int size;
} LongArray2D;

typedef struct {
    double** data;
    int size;
} DoubleArray2D;

typedef struct {
    double* data;
    int size;
} DoubleArray;

typedef struct {
    bool* data;
    int size;
} BoolArray;

typedef struct {
    bool** data;
    int size;
} BoolArray2D;

typedef struct {
    int* data;
    int size;
} IntArray;

typedef struct {
    long* data;
    int size;
} LongArray;

typedef struct {
    char* data;
    int size;
} CharArray;

typedef struct {
    char** data;
    int size;
} CharArray2D;

typedef struct {
    int** data;
    int size;
} IntArray2D;

typedef struct {
    long** data;
    int size;
} LongArray2D;

typedef struct {
    double** data;
    int size;
} DoubleArray2D;

typedef struct {
    double* data;
    int size;
} DoubleArray;

typedef struct {
    bool* data;
    int size;
} BoolArray;

typedef struct {
    bool** data;
    int size;
} BoolArray2D;

typedef struct {
    int* data;
    int size;
} IntArray;

typedef struct {
    long* data;
    int size;
} LongArray;

typedef struct {
    char* data;
    int size;
} CharArray;

typedef struct {
    char** data;
    int size;
} CharArray2D;

typedef struct {
    int** data;
    int size;
} IntArray2D;

typedef struct {
    long** data;
    int size;
} LongArray2D;

typedef struct {
    double** data;
    int size;
} DoubleArray2D;

typedef struct {
    double* data;
    int size;
} DoubleArray;

typedef struct {
    bool* data;
    int size;
} BoolArray;

typedef struct {
    bool** data;
    int size;
} BoolArray2D;

typedef struct {
    int* data;
    int size;
} IntArray;

typedef struct {
    long* data;
    int size;
} LongArray;

typedef struct {
    char* data;
    int size;
} CharArray;

typedef struct {
    char** data;
    int size;
} CharArray2D;

typedef struct {
    int** data;
    int size;
} IntArray2D;

typedef struct {
    long** data;
    int size;
} LongArray2D;

typedef struct {
    double** data;
    int size;
} DoubleArray2D;

typedef struct {
    double* data;
    int size;
} DoubleArray;

typedef struct {
    bool* data;
    int size;
} BoolArray;

typedef struct {
    bool** data;
    int size;
} BoolArray2D;

typedef struct {
    int* data;
    int size;
} IntArray;

typedef struct {
    long* data;
    int size;
} LongArray;

typedef struct {
    char* data;
    int size;
} CharArray;

typedef struct {
    char** data;
    int size;
} CharArray2D;

typedef struct {
    int** data;
    int size;
} IntArray2D;

typedef struct {
    long** data;
    int size;
} LongArray2D;

typedef struct {
    double** data;
    int size;
} DoubleArray2D;

typedef struct {
    double* data;
    int size;
} DoubleArray;

typedef struct {
    bool* data;
    int size;
} BoolArray;

typedef struct {
    bool** data;
    int size;
} BoolArray2D;

typedef struct {
    int* data;
    int size;
} IntArray;

typedef struct {
    long* data;
    int size;
} LongArray;

typedef struct {
    char* data;
    int size;
} CharArray;

typedef struct {
    char** data;
    int size;
} CharArray2D;

typedef struct {
    int** data;
    int size;
} IntArray2D;

typedef struct {
    long** data;
    int size;
} LongArray2D;

typedef struct {
    double** data;
    int size;
} DoubleArray2D;

typedef struct {
    double* data;
    int size;
} DoubleArray;

typedef struct {
    bool* data;
    int size;
} BoolArray;

typedef struct {
    bool** data;
    int size;
} BoolArray2D;

typedef struct {
    int* data;
    int size;
} IntArray;

typedef struct {
    long* data;
    int size;
} LongArray;

typedef struct {
    char* data;
    int size;
} CharArray;

typedef struct {
    char** data;
    int size;
} CharArray2D;

typedef struct {
    int** data;
    int size;
} IntArray2D;

typedef struct {
    long** data;
    int size;
} LongArray2D;

typedef struct {
    double** data;
    int size;
} DoubleArray2D;

typedef struct {
    double* data;
    int size;
} DoubleArray;

typedef struct {
    bool* data;
    int size;
} BoolArray;

typedef struct {
    bool** data;
    int size;
} BoolArray2D;

IntArray* newIntArray(int size) {
    IntArray* array = (IntArray*)malloc(sizeof(IntArray));
    array->data = (int*)malloc(sizeof(int) * size);
    array->size = size;
    return array;
}

LongArray* newLongArray(int size) {
    LongArray* array = (LongArray*)malloc(sizeof(LongArray));
    array->data = (long*)malloc(sizeof(long) * size);
    array->size = size;
    return array;
}

CharArray* newCharArray(int size) {
    CharArray* array = (CharArray*)malloc(sizeof(CharArray));
    array->data = (char*)malloc(sizeof(char) * size);
    array->size = size;
    return array;
}

CharArray2D* newCharArray2D(int size) {
    CharArray2D* array = (CharArray2D*)malloc(sizeof(CharArray2D));
    array->data = (char**)malloc(sizeof(char*) * size);
    array->size = size;
    return array;
}

IntArray2D* newIntArray2D(int size) {
    IntArray2D* array = (IntArray2D*)malloc(sizeof(IntArray2D));
    array->data = (int**)malloc(sizeof(int*) * size);
    array->size = size;
    return array;
}

LongArray2D* newLongArray2D(int size) {
    LongArray2D* array = (LongArray2D*)malloc(sizeof(LongArray2D));
    array->data = (long**)malloc(sizeof(long*) * size);
    array->size = size;
    return array;
}

DoubleArray2D* newDoubleArray2D(int size) {
    DoubleArray2D* array = (DoubleArray2D*)malloc(sizeof(DoubleArray2D));
    array->data = (double**)malloc(sizeof(double*) * size);
    array->size = size;
    return array;
}

DoubleArray* newDoubleArray(int size) {
    DoubleArray* array = (DoubleArray*)malloc(sizeof(DoubleArray));
    array->data = (double*)malloc(sizeof(double) * size);
    array->size = size;
    return array;
}

BoolArray* newBoolArray(int size) {
    BoolArray* array = (BoolArray*)malloc(sizeof(BoolArray));
    array->data = (bool*)malloc(sizeof(bool) * size);
    array->size = size;
    return array;
}

BoolArray2D* newBoolArray2D(int size) {
    BoolArray2D* array = (BoolArray2D*)malloc(sizeof(BoolArray2D));
    array->data = (bool**)malloc(sizeof(bool*) * size);
    array->size = size;
    return array;
}

IntArray* newArray(int* data, int size) {
    IntArray* array = (IntArray*)malloc(sizeof(IntArray));
    array->data = data;
    array->size = size;
    return array;
}

LongArray* newArray(long* data, int size) {
    LongArray* array = (LongArray*)malloc(sizeof(LongArray));
    array->data = data;
    array->size = size;
    return array;
}

CharArray* newArray(char* data, int size) {
    CharArray* array = (CharArray*)malloc(sizeof(CharArray));
    array->data = data;
    array->size = size;
    return array;
}

CharArray2D* newArray(char** data, int size) {
    CharArray2D* array = (CharArray2D*)malloc(sizeof(CharArray2D));
    array->data = data;
    array->size = size;
    return array;
}

IntArray2D* newArray(int** data, int size) {
    IntArray2D* array = (IntArray2D*)malloc(sizeof(IntArray2D));
    array->data = data;
    array->size = size;
    return array;
}

LongArray2D* newArray(long** data, int size) {
    LongArray2D* array = (LongArray2D*)malloc(sizeof(LongArray2D));
    array->data = data;
    array->size = size;
    return array;
}

DoubleArray2D* newArray(double** data, int size) {
    DoubleArray2D* array = (DoubleArray2D*)malloc(sizeof(DoubleArray2D));
    array->data = data;
    array->size = size;
    return array;
}

DoubleArray* newArray(double* data, int size) {
    DoubleArray* array = (DoubleArray*)malloc(sizeof(DoubleArray));
    array->data = data;
    array->size = size;
    return array;
}

BoolArray* newArray(bool* data, int size) {
    BoolArray* array = (BoolArray*)malloc(sizeof(BoolArray));
    array->data = data;
    array->size = size;
    return array;
}

BoolArray2D* newArray(bool** data, int size) {
    BoolArray2D* array = (BoolArray2D*)malloc(sizeof(BoolArray2D));
    array->data = data;
    array->size = size;
    return array;
}

IntArray* newIntArrayFromValues(int* values, int size) {
    IntArray* array = (IntArray*)malloc(sizeof(IntArray));
    array->data = (int*)malloc(sizeof(int) * size);
    array->size = size;
    for (int i = 0; i < size; i++) {
        array->data[i] = values[i];
    }
    return array;
}

LongArray* newLongArrayFromValues(long* values, int size) {
    LongArray* array = (LongArray*)malloc(sizeof(LongArray));
    array->data = (long*)malloc(sizeof(long) * size);
    array->size = size;
    for (int i = 0; i < size; i++) {
        array->data[i] = values[i];
    }
    return array;
}

CharArray* newCharArrayFromValues(char* values, int size) {
    CharArray* array = (CharArray*)malloc(sizeof(CharArray));
    array->data = (char*)malloc(sizeof(char) * size);
    array->size = size;
    for (int i = 0; i < size; i++) {
        array->data[i] = values[i];
    }
    return array;
}

CharArray2D* newCharArray2DFromValues(char** values, int size) {
    CharArray2D* array = (CharArray2D*)malloc(sizeof(CharArray2D));
    array->data = (char**)malloc(sizeof(char*) * size);
    array->size = size;
    for (int i = 0; i < size; i++) {
        array->data[i] = values[i];
    }
    return array;
}

IntArray2D* newIntArray2DFromValues(int** values, int size) {
    IntArray2D* array = (IntArray2D*)malloc(sizeof(IntArray2D));
    array->data = (int**)malloc(sizeof(int*) * size);
    array->size = size;
    for (int i = 0; i < size; i++) {
        array->data[i] = values[i];
    }
    return array;
}

LongArray2D* newLongArray2DFromValues(long** values, int size) {
    LongArray2D* array = (LongArray2D*)malloc(sizeof(LongArray2D));
    array->data = (long**)malloc(sizeof(long*) * size);
    array->size = size;
    for (int i = 0; i < size; i++) {
        array->data[i] = values[i];
    }
    return array;
}

DoubleArray2D* newDoubleArray2DFromValues(double** values, int size) {
    DoubleArray2D* array = (DoubleArray2D*)malloc(sizeof(DoubleArray2D));
    array->data = (double**)malloc(sizeof(double*) * size);
    array->size = size;
    for (int i = 0; i < size; i++) {
        array->data[i] = values[i];
    }
    return array;
}

DoubleArray* newDoubleArrayFromValues(double* values, int size) {
    DoubleArray* array = (DoubleArray*)malloc(sizeof(DoubleArray));
    array->data = (double*)malloc(sizeof(double) * size);
    array->size = size;
    for (int i = 0; i < size; i++) {
        array->data[i] = values[i];
    }
    return array;
}

BoolArray* newBoolArrayFromValues(bool* values, int size) {
    BoolArray* array = (BoolArray*)malloc(sizeof(BoolArray));
    array->data = (bool*)malloc(sizeof(bool) * size);
    array->size = size;
    for (int i = 0; i < size; i++) {
        array->data[i] = values[i];
    }
    return array;
}

BoolArray2D* newBoolArray2DFromValues(bool** values, int size) {
    BoolArray2D* array = (BoolArray2D*)malloc(sizeof(BoolArray2D));
    array->data = (bool**)malloc(sizeof(bool*) * size);
    array->size = size;
    for (int i = 0; i < size; i++) {
        array->data[i] = values[i];
    }
    return array;
}

IntArray* range(int start, int end, int step) {
    int size = (end - start) / step;
    IntArray* array = (IntArray*)malloc(sizeof(IntArray));
    array->data = (int*)malloc(sizeof(int) * size);
    array->size = size;
    for (int i = 0; i < size; i++) {
        array->data[i] = start + (i * step);
    }
    return array;
}

IntArray* range(int start, int end) {
    return range(start, end, 1);
}

IntArray* range(int end) {
    return range(0, end, 1);
}

IntArray* zeros(int size) {
    IntArray* array = (IntArray*)malloc(sizeof(IntArray));
    array->data = (int*)calloc(size, sizeof(int));
    array->size = size;
    return array;
}

LongArray* zerosLong(int size) {
    LongArray* array = (LongArray*)malloc(sizeof(LongArray));
    array->data = (long*)calloc(size, sizeof(long));
    array->size = size;
    return array;
}

CharArray* zerosChar(int size) {
    CharArray* array = (CharArray*)malloc(sizeof(CharArray));
    array->data = (char*)calloc(size, sizeof(char));
    array->size = size;
    return array;
}

IntArray* ones(int size) {
    IntArray* array = (IntArray*)malloc(sizeof(IntArray));
    array->data = (int*)malloc(sizeof(int) * size);
    array->size = size;
    for (int i = 0; i < size; i++) {
        array->data[i] = 1;
    }
    return array;
}

LongArray* onesLong(int size) {
    LongArray* array = (LongArray*)malloc(sizeof(LongArray));
    array->data = (long*)malloc(sizeof(long) * size);
    array->size = size;
    for (int i = 0; i < size; i++) {
        array->data[i] = 1;
    }
    return array;
}

CharArray* onesChar(int size) {
    CharArray* array = (CharArray*)malloc(sizeof(CharArray));
    array->data = (char*)malloc(sizeof(char) * size);
    array->size = size;
    for (int i = 0; i < size; i++) {
        array->data[i] = 1;
    }
    return array;
}

IntArray* copyIntArray(IntArray* array) {
    IntArray* newArray = (IntArray*)malloc(sizeof(IntArray));
    newArray->data = (int*)malloc(sizeof(int) * array->size);
    newArray->size = array->size;
    for (int i = 0; i < array->size; i++) {
        newArray->data[i] = array->data[i];
    }
    return newArray;
}

LongArray* copyLongArray(LongArray* array) {
    LongArray* newArray = (LongArray*)malloc(sizeof(LongArray));
    newArray->data = (long*)malloc(sizeof(long) * array->size);
    newArray->size = array->size;
    for (int i = 0; i < array->size; i++) {
        newArray->data[i] = array->data[i];
    }
    return newArray;
}

CharArray* copyCharArray(CharArray* array) {
    CharArray* newArray = (CharArray*)malloc(sizeof(CharArray));
    newArray->data = (char*)malloc(sizeof(char) * array->size);
    newArray->size = array->size;
    for (int i = 0; i < array->size; i++) {
        newArray->data[i] = array->data[i];
    }
    return newArray;
}

CharArray2D* copyCharArray2D(CharArray2D* array) {
    CharArray2D* newArray = (CharArray2D*)malloc(sizeof(CharArray2D));
    newArray->data = (char**)malloc(sizeof(char*) * array->size);
    newArray->size = array->size;
    for (int i = 0; i < array->size; i++) {
        newArray->data[i] = array->data[i];
    }
    return newArray;
}

IntArray2D* copyIntArray2D(IntArray2D* array) {
    IntArray2D* newArray = (IntArray2D*)malloc(sizeof(IntArray2D));
    newArray->data = (int**)malloc(sizeof(int*) * array->size);
    newArray->size = array->size;
    for (int i = 0; i < array->size; i++) {
        newArray->data[i] = array->data[i];
    }
    return newArray;
}

LongArray2D* copyLongArray2D(LongArray2D* array) {
    LongArray2D* newArray = (LongArray2D*)malloc(sizeof(LongArray2D));
    newArray->data = (long**)malloc(sizeof(long*) * array->size);
    newArray->size = array->size;
    for (int i = 0; i < array->size; i++) {
        newArray->data[i] = array->data[i];
    }
    return newArray;
}

DoubleArray2D* copyDoubleArray2D(DoubleArray2D* array) {
    DoubleArray2D* newArray = (DoubleArray2D*)malloc(sizeof(DoubleArray2D));
    newArray->data = (double**)malloc(sizeof(double*) * array->size);
    newArray->size = array->size;
    for (int i = 0; i < array->size; i++) {
        newArray->data[i] = array->data[i];
    }
    return newArray;
}

DoubleArray* copyDoubleArray(DoubleArray* array) {
    DoubleArray* newArray = (DoubleArray*)malloc(sizeof(DoubleArray));
    newArray->data = (double*)malloc(sizeof(double) * array->size);
    newArray->size = array->size;
    for (int i = 0; i < array->size; i++) {
        newArray->data[i] = array->data[i];
    }
    return newArray;
}

BoolArray* copyBoolArray(BoolArray* array) {
    BoolArray* newArray = (BoolArray*)malloc(sizeof(BoolArray));
    newArray->data = (bool*)malloc(sizeof(bool) * array->size);
    newArray->size = array->size;
    for (int i = 0; i < array->size; i++) {
        newArray->data[i] = array->data[i];
    }
    return newArray;
}

BoolArray2D* copyBoolArray2D(BoolArray2D* array) {
    BoolArray2D* newArray = (BoolArray2D*)malloc(sizeof(BoolArray2D));
    newArray->data = (bool**)malloc(sizeof(bool*) * array->size);
    newArray->size = array->size;
    for (int i = 0; i < array->size; i++) {
        newArray->data[i] = array->data[i];
    }
    return newArray;
}

IntArray* sliceIntArray(IntArray* array, int start, int end, int step) {
    int size = (end - start) / step;
    IntArray* newArray = (IntArray*)malloc(sizeof(IntArray));
    newArray->data = (int*)malloc(sizeof(int) * size);
    newArray->size = size;
    int j = 0;
    for (int i = start; i < end; i += step) {
        newArray->data[j] = array->data[i];
        j++;
    }
    return newArray;
}

LongArray* sliceLongArray(LongArray* array, int start, int end, int step) {
    int size = (end - start) / step;
    LongArray* newArray = (LongArray*)malloc(sizeof(LongArray));
    newArray->data = (long*)malloc(sizeof(long) * size);
    newArray->size = size;
    int j = 0;
    for (int i = start; i < end; i += step) {
        newArray->data[j] = array->data[i];
        j++;
    }
    return newArray;
}

CharArray* sliceCharArray(CharArray* array, int start, int end, int step) {
    int size = (end - start) / step;
    CharArray* newArray = (CharArray*)malloc(sizeof(CharArray));
    newArray->data = (char*)malloc(sizeof(char) * size);
    newArray->size = size;
    int j = 0;
    for (int i = start; i < end; i += step) {
        newArray->data[j] = array->data[i];
        j++;
    }
    return newArray;
}

CharArray2D* sliceCharArray2D(CharArray2D* array, int start, int end, int step) {
    int size = (end - start) / step;
    CharArray2D* newArray = (CharArray2D*)malloc(sizeof(CharArray2D));
    newArray->data = (char**)malloc(sizeof(char*) * size);
    newArray->size = size;
    int j = 0;
    for (int i = start; i < end; i += step) {
        newArray->data[j] = array->data[i];
        j++;
    }
    return newArray;
}

IntArray2D* sliceIntArray2D(IntArray2D* array, int start, int end, int step) {
    int size = (end - start) / step;
    IntArray2D* newArray = (IntArray2D*)malloc(sizeof(IntArray2D));
    newArray->data = (int**)malloc(sizeof(int*) * size);
    newArray->size = size;
    int j = 0;
    for (int i = start; i < end; i += step) {
        newArray->data[j] = array->data[i];
        j++;
    }
    return newArray;
}

LongArray2D* sliceLongArray2D(LongArray2D* array, int start, int end, int step) {
    int size = (end - start) / step;
    LongArray2D* newArray = (LongArray2D*)malloc(sizeof(LongArray2D));
    newArray->data = (long**)malloc(sizeof(long*) * size);
    newArray->size = size;
    int j = 0;
    for (int i = start; i < end; i += step) {
        newArray->data[j] = array->data[i];
        j++;
    }
    return newArray;
}

DoubleArray2D* sliceDoubleArray2D(DoubleArray2D* array, int start, int end, int step) {
    int size = (end - start) / step;
    DoubleArray2D* newArray = (DoubleArray2D*)malloc(sizeof(DoubleArray2D));
    newArray->data = (double**)malloc(sizeof(double*) * size);
    newArray->size = size;
    int j = 0;
    for (int i = start; i < end; i += step) {
        newArray->data[j] = array->data[i];
        j++;
    }
    return newArray;
}

DoubleArray* sliceDoubleArray(DoubleArray* array, int start, int end, int step) {
    int size = (end - start) / step;
    DoubleArray* newArray = (DoubleArray*)malloc(sizeof(DoubleArray));
    newArray->data = (double*)malloc(sizeof(double) * size);
    newArray->size = size;
    int j = 0;
    for (int i = start; i < end; i += step) {
        newArray->data[j] = array->data[i];
        j++;
    }
    return newArray;
}

BoolArray* sliceBoolArray(BoolArray* array, int start, int end, int step) {
    int size = (end - start) / step;
    BoolArray* newArray = (BoolArray*)malloc(sizeof(BoolArray));
    newArray->data = (bool*)malloc(sizeof(bool) * size);
    newArray->size = size;
    int j = 0;
    for (int i = start; i < end; i += step) {
        newArray->data[j] = array->data[i];
        j++;
    }
    return newArray;
}

BoolArray2D* sliceBoolArray2D(BoolArray2D* array, int start, int end, int step) {
    int size = (end - start) / step;
    BoolArray2D* newArray = (BoolArray2D*)malloc(sizeof(BoolArray2D));
    newArray->data = (bool**)malloc(sizeof(bool*) * size);
    newArray->size = size;
    int j = 0;
    for (int i = start; i < end; i += step) {
        newArray->data[j] = array->data[i];
        j++;
    }
    return newArray;
}

IntArray* appendIntArray(IntArray* array, int value) {
    IntArray* newArray = (IntArray*)malloc(sizeof(IntArray));
    newArray->data = (int*)malloc(sizeof(int) * (array->size + 1));
    newArray->size = array->size + 1;
    for (int i = 0; i < array->size; i++) {
        newArray->data[i] = array->data[i];
    }
    newArray->data[array->size] = value;
    return newArray;
}

LongArray* appendLongArray(LongArray* array, long value) {
    LongArray* newArray = (LongArray*)malloc(sizeof(LongArray));
    newArray->data = (long*)malloc(sizeof(long) * (array->size + 1));
    newArray->size = array->size + 1;
    for (int i = 0; i < array->size; i++) {
        newArray->data[i] = array->data[i];
    }
    newArray->data[array->size] = value;
    return newArray;
}

CharArray* appendCharArray(CharArray* array, char value) {
    CharArray* newArray = (CharArray*)malloc(sizeof(CharArray));
    newArray->data = (char*)malloc(sizeof(char) * (array->size + 1));
    newArray->size = array->size + 1;
    for (int i = 0; i < array->size; i++) {
        newArray->data[i] = array->data[i];
    }
    newArray->data[array->size] = value;
    return newArray;
}

CharArray2D* appendCharArray2D(CharArray2D* array, char* value) {
    CharArray2D* newArray = (CharArray2D*)malloc(sizeof(CharArray2D));
    newArray->data = (char**)malloc(sizeof(char*) * (array->size + 1));
    newArray->size = array->size + 1;
    for (int i = 0; i < array->size; i++) {
        newArray->data[i] = array->data[i];
    }
    newArray->data[array->size] = value;
    return newArray;
}

IntArray2D* appendIntArray2D(IntArray2D* array, int* value) {
    IntArray2D* newArray = (IntArray2D*)malloc(sizeof(IntArray2D));
    newArray->data = (int**)malloc(sizeof(int*) * (array->size + 1));
    newArray->size = array->size + 1;
    for (int i = 0; i < array->size; i++) {
        newArray->data[i] = array->data[i];
    }
    newArray->data[array->size] = value;
    return newArray;
}

LongArray2D* appendLongArray2D(LongArray2D* array, long* value) {
    LongArray2D* newArray = (LongArray2D*)malloc(sizeof(LongArray2D));
    newArray->data = (long**)malloc(sizeof(long*) * (array->size + 1));
    newArray->size = array->size + 1;
    for (int i = 0; i < array->size; i++) {
        newArray->data[i] = array->data[i];
    }
    newArray->data[array->size] = value;
    return newArray;
}

DoubleArray2D* appendDoubleArray2D(DoubleArray2D* array, double* value) {
    DoubleArray2D* newArray = (DoubleArray2D*)malloc(sizeof(DoubleArray2D));
    newArray->data = (double**)malloc(sizeof(double*) * (array->size + 1));
    newArray->size = array->size + 1;
    for (int i = 0; i < array->size; i++) {
        newArray->data[i] = array->data[i];
    }
    newArray->data[array->size] = value;
    return newArray;
}

DoubleArray* appendDoubleArray(DoubleArray* array, double value) {
    DoubleArray* newArray = (DoubleArray*)malloc(sizeof(DoubleArray));
    newArray->data = (double*)malloc(sizeof(double) * (array->size + 1));
    newArray->size = array->size + 1;
    for (int i = 0; i < array->size; i++) {
        newArray->data[i] = array->data[i];
    }
    newArray->data[array->size] = value;
    return newArray;
}

BoolArray* appendBoolArray(BoolArray* array, bool value) {
    BoolArray* newArray = (BoolArray*)malloc(sizeof(BoolArray));
    newArray->data = (bool*)malloc(sizeof(bool) * (array->size + 1));
    newArray->size = array->size + 1;
    for (int i = 0; i < array->size; i++) {
        newArray->data[i] = array->data[i];
    }
    newArray->data[array->size] = value;
    return newArray;
}

BoolArray2D* appendBoolArray2D(BoolArray2D* array, bool* value) {
    BoolArray2D* newArray = (BoolArray2D*)malloc(sizeof(BoolArray2D));
    newArray->data = (bool**)malloc(sizeof(bool*) * (array->size + 1));
    newArray->size = array->size + 1;
    for (int i = 0; i < array->size; i++) {
        newArray->data[i] = array->data[i];
    }
    newArray->data[array->size] = value;
    return newArray;
}

IntArray* insertIntArray(IntArray* array, int index, int value) {
    IntArray* newArray = (IntArray*)malloc(sizeof(IntArray));
    newArray->data = (int*)malloc(sizeof(int) * (array->size + 1));
    newArray->size = array->size + 1;
    for (int i = 0; i < index; i++) {
        newArray->data[i] = array->data[i];
    }
    newArray->data[index] = value;
    for (int i = index + 1; i < newArray->size; i++) {
        newArray->data[i] = array->data[i - 1];
    }
    return newArray;
}

LongArray* insertLongArray(LongArray* array, int index, long value) {
    LongArray* newArray = (LongArray*)malloc(sizeof(LongArray));
    newArray->data = (long*)malloc(sizeof(long) * (array->size + 1));
    newArray->size = array->size + 1;
    for (int i = 0; i < index; i++) {
        newArray->data[i] = array->data[i];
    }
    newArray->data[index] = value;
    for (int i = index + 1; i < newArray->size; i++) {
        newArray->data[i] = array->data[i - 1];
    }
    return newArray;
}

CharArray* insertCharArray(CharArray* array, int index, char value) {
    CharArray* newArray = (CharArray*)malloc(sizeof(CharArray));
    newArray->data = (char*)malloc(sizeof(char) * (array->size + 1));
    newArray->size = array->size + 1;

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    double x;
    double y;
} Point;

typedef struct {
    Point a;
    Point b;
} Segment;

typedef struct {
    double a;
    double b;
    double c;
} Line;

typedef struct {
    double x;
    double y;
    Point point;
} Vector;

typedef struct {
    int rowCount;
    int columnCount;
    bool** data;
} BooleanMatrix;

typedef struct {
    int* elements;
    int* at;
    int size;
    IntComparator comparator;
} Heap;

typedef struct {
    double* a;
    double* b;
} Complex;

typedef struct {
    double* real;
    double* imaginary;
} ComplexArray;

typedef struct {
    double* a;
    double* b;
    bool invert;
} FFTParams;

typedef struct {
    double* a;
    double* b;
    bool invert;
} FFTParams;

typedef struct {
    double* a;
    double* b;
    bool invert;
} FFTParams;

typedef struct {
    double* a;
    double* b;
    bool invert;
} FFTParams;

typedef struct {
    double* a;
    double* b;
    bool invert;
} FFTParams;

typedef struct {
    double* a;
    double* b;
    bool invert;
} FFTParams;

typedef struct {
    double* a;
    double* b;
    bool invert;
} FFTParams;

typedef struct {
    double* a;
    double* b;
    bool invert;
} FFTParams;

typedef struct {
    double* a;
    double* b;
    bool invert;
} FFTParams;

typedef struct {
    double* a;
    double* b;
    bool invert;
} FFTParams;

typedef struct {
    double* a;
    double* b;
    bool invert;
} FFTParams;

typedef struct {
    double* a;
    double* b;
    bool invert;
} FFTParams;

typedef struct {
    double* a;
    double* b;
    bool invert;
} FFTParams;

typedef struct {
    double* a;
    double* b;
    bool invert;
} FFTParams;

typedef struct {
    double* a;
    double* b;
    bool invert;
} FFTParams;

typedef struct {
    double* a;
    double* b;
    bool invert;
} FFTParams;

typedef struct {
    double* a;
    double* b;
    bool invert;
} FFTParams;

typedef struct {
    double* a;
    double* b;
    bool invert;
} FFTParams;

typedef struct {
    double* a;
    double* b;
    bool invert;
} FFTParams;

typedef struct {
    double* a;
    double* b;
    bool invert;
} FFTParams;

typedef struct {
    double* a;
    double* b;
    bool invert;
} FFTParams;

typedef struct {
    double* a;
    double* b;
    bool invert;
} FFTParams;

typedef struct {
    double* a;
    double* b;
    bool invert;
} FFTParams;

typedef struct {
    double* a;
    double* b;
    bool invert;
} FFTParams;

typedef struct {
    double* a;
    double* b;
    bool invert;
} FFTParams;

typedef struct {
    double* a;
    double* b;
    bool invert;
} FFTParams;

typedef struct {
    double* a;
    double* b;
    bool invert;
} FFTParams;

typedef struct {
    double* a;
    double* b;
    bool invert;
} FFTParams;

typedef struct {
    double* a;
    double* b;
    bool invert;
} FFTParams;

typedef struct {
    double* a;
    double* b;
    bool invert;
} FFTParams;

typedef struct {
    double* a;
    double* b;
    bool invert;
} FFTParams;

typedef struct {
    double* a;
    double* b;
    bool invert;
} FFTParams;

typedef struct {
    double* a;
    double* b;
    bool invert;
} FFTParams;

typedef struct {
    double* a;
    double* b;
    bool invert;
} FFTParams;

typedef struct {
    double* a;
    double* b;
    bool invert;
} FFTParams;

typedef struct {
    double* a;
    double* b;
    bool invert;
} FFTParams;

typedef struct {
    double* a;
    double* b;
    bool invert;
} FFTParams;

typedef struct {
    double* a;
    double* b;
    bool invert;
} FFTParams;

typedef struct {
    double* a;
    double* b;
    bool invert;
} FFTParams;

typedef struct {
    double* a;
    double* b;
    bool invert;
} FFTParams;

typedef struct {
    double* a;
    double* b;
    bool invert;
} FFTParams;

typedef struct {
    double* a;
    double* b;
    bool invert;
} FFTParams;

typedef struct {
    double* a;
    double* b;
    bool invert;
} FFTParams;

typedef struct {
    double* a;
    double* b;
    bool invert;
} FFTParams;

typedef struct {
    double* a;
    double* b;
    bool invert;
} FFTParams;

typedef struct {
    double* a;
    double* b;
    bool invert;
} FFTParams;

typedef struct {
    double* a;
    double* b;
    bool invert;
} FFTParams;

typedef struct {
    double* a;
    double* b;
    bool invert;
} FFTParams;

typedef struct {
    double* a;
    double* b;
    bool invert;
} FFTParams;

typedef struct {
    double* a;
    double* b;
    bool invert;
} FFTParams;

typedef struct {
    double* a;
    double* b;
    bool invert;
} FFTParams;

typedef struct {
    double* a;
    double* b;
    bool invert;
} FFTParams;

typedef struct {
    double* a;
    double* b;
    bool invert;
} FFTParams;

typedef struct {
    double* a;
    double* b;
    bool invert;
} FFTParams;

typedef struct {
    double* a;
    double* b;
    bool invert;
} FFTParams;

typedef struct {
    double* a;
    double* b;
    bool invert;
} FFTParams;

typedef struct {
    double* a;
    double* b;
    bool invert;
} FFTParams;

typedef struct {
    double* a;
    double* b;
    bool invert;
} FFTParams;

typedef struct {
    double* a;
    double* b;
    bool invert;
} FFTParams;

typedef struct {
    double* a;
    double* b;
    bool invert;
} FFTParams;

typedef struct {
    double* a;
    double* b;
    bool invert;
} FFTParams;

typedef struct {
    double* a;
    double* b;
    bool invert;
} FFTParams;

typedef struct {
    double* a;
    double* b;
    bool invert;
} FFTParams;

typedef struct {
    double* a;
    double* b;
    bool invert;
} FFTParams;

typedef struct {
    double* a;
    double* b;
    bool invert;
} FFTParams;

typedef struct {
    double* a;
    double* b;
    bool invert;
} FFTParams;

typedef struct {
    double* a;
    double* b;
    bool invert;
} FFTParams;

typedef struct {
    double* a;
    double* b;
    bool invert;
} FFTParams;

typedef struct {
    double* a;
    double* b;
    bool invert;
} FFTParams;

typedef struct {
    double* a;
    double* b;
    bool invert;
} FFTParams;

typedef struct {
    double* a;
    double* b;
    bool invert;
} FFTParams;

typedef struct {
    double* a;
    double* b;
    bool invert;
} FFTParams;

typedef struct {
    double* a;
    double* b;
    bool invert;
} FFTParams;

typedef struct {
    double* a;
    double* b;
    bool invert;
} FFTParams;

typedef struct {
    double* a;
    double* b;
    bool invert;
} FFTParams;

typedef struct {
    double* a;
    double* b;
    bool invert;
} FFTParams;

typedef struct {
    double* a;
    double* b;
    bool invert;
} FFTParams;

typedef struct {
    double* a;
    double* b;
    bool invert;
} FFTParams;

typedef struct {
    double* a;
    double* b;
    bool invert;
} FFTParams;

typedef struct {
    double* a;
    double* b;
    bool invert;
} FFTParams;

typedef struct {
    double* a;
    double* b;
    bool invert;
} FFTParams;

typedef struct {
    double* a;
    double* b;
    bool invert;
} FFTParams;

typedef struct {
    double* a;
    double* b;
    bool invert;
} FFTParams;

typedef struct {
    double* a;
    double* b;
    bool invert;
} FFTParams;

typedef struct {
    double* a;
    double* b;
    bool invert;
} FFTParams;

typedef struct {
    double* a;
    double* b;
    bool invert;
} FFTParams;

typedef struct {
    double* a;
    double* b;
    bool invert;
} FFTParams;

typedef struct {
    double* a;
    double* b;
    bool invert;
} FFTParams;

typedef struct {
    double* a;
    double* b;
    bool invert;
} FFTParams;

typedef struct {
    double* a;
    double* b;
    bool invert;
} FFTParams;

typedef struct {
    double* a;
    double* b;
    bool invert;
} FFTParams;

typedef struct {
    double* a;
    double* b;
    bool invert;
} FFTParams;

typedef struct {
    double* a;
    double* b;
    bool invert;
} FFTParams;

typedef struct {
    double* a;
    double* b;
    bool invert;
} FFTParams;

typedef struct {
    double* a;
    double* b;
    bool invert;
} FFTParams;

typedef struct {
    double* a;
    double* b;
    bool invert;
} FFTParams;

typedef struct {
    double* a;
    double* b;
    bool invert;
} FFTParams;

typedef struct {
    double* a;
    double* b;
    bool invert;
} FFTParams;

typedef struct {
    double* a;
    double* b;
    bool invert;
} FFTParams;

typedef struct {
    double* a;
    double* b;
    bool invert;
} FFTParams;

typedef struct {
    double* a;
    double* b;
    bool invert;
} FFTParams;

typedef struct {
    double* a;
    double* b;
    bool invert;
} FFTParams;

typedef struct {
    double* a;
    double* b;
    bool invert;
} FFTParams;

typedef struct {
    double* a;
    double* b;
    bool invert;
} FFTParams;

typedef struct {
    double* a;
    double* b;
    bool invert;
} FFTParams;

typedef struct {
    double* a;
    double* b;
    bool invert;
} FFTParams;

typedef struct {
    double* a;
    double* b;
    bool invert;
} FFTParams;

typedef struct {
    double* a;
    double* b;
    bool invert;
} FFTParams;

typedef struct {
    double* a;
    double* b;
    bool invert;
} FFTParams;

typedef struct {
    double* a;
    double* b;
    bool invert;
} FFTParams;

typedef struct {
    double* a;
    double* b;
    bool invert;
} FFTParams;

typedef struct {
    double* a;
    double* b;
    bool invert;
} FFTParams;

typedef struct {
    double* a;
    double* b;
    bool invert;
} FFTParams;

typedef struct {
    double* a;
    double* b;
    bool invert;
} FFTParams;

typedef struct {
    double* a;
    double* b;
    bool invert;
} FFTParams;

typedef struct {
    double* a;
    double* b;
    bool invert;
} FFTParams;

typedef struct {
    double* a;
    double* b;
    bool invert;
} FFTParams;

typedef struct {
    double* a;
    double* b;
    bool invert;
} FFTParams;

typedef struct {
    double* a;
    double* b;
    bool invert;
} FFTParams;

typedef struct {
    double* a;
    double* b;
    bool invert;
} FFTParams;

typedef struct {
    double* a;
    double* b;
    bool invert;
} FFTParams;

typedef struct {
    double* a;
    double* b;
    bool invert;
} FFTParams;

typedef struct {
    double* a;
    double* b;
    bool invert;
} FFTParams;

typedef struct {
    double* a;
    double* b;
    bool invert;
} FFTParams;

typedef struct {
    double* a;
    double* b;
    bool invert;
} FFTParams;

typedef struct {
    double* a;
    double* b;
    bool invert;
} FFTParams;

typedef struct {
    double* a;
    double* b;
    bool invert;
} FFTParams;

typedef struct {
    double* a;
    double* b;
    bool invert;
} FFTParams;

typedef struct {
    double* a;
    double* b;
    bool invert;
} FFTParams;

typedef struct {
    double* a;
    double* b;
    bool invert;
} FFTParams;

typedef struct {
    double* a;
    double* b;
    bool invert;
} FFTParams;

typedef struct {
    double* a;
    double* b;
    bool invert;
} FFTParams;

typedef struct {
    double* a;
    double* b;
    bool invert;
} FFTParams;

typedef struct {
    double* a;
    double* b;
    bool invert;
} FFTParams;

typedef struct {
    double* a;
    double* b;
    bool invert;
} FFTParams;

typedef struct {
    double* a;
    double* b;
    bool invert;
} FFTParams;

typedef struct {
    double* a;
    double* b;
    bool invert;
} FFTParams;

typedef struct {
    double* a;
    double* b;
    bool invert;
} FFTParams;

typedef struct {
    double* a;
    double* b;
    bool invert;
} FFTParams;

typedef struct {
    double* a;
    double* b;
    bool invert;
} FFTParams;

typedef struct {
    double* a;
    double* b;
    bool invert;
} FFTParams;

typedef struct {
    double* a;
    double* b;
    bool invert;
} FFTParams;

typedef struct {
    double* a;
    double* b;
    bool invert;
} FFTParams;

typedef struct {
    double* a;
    double* b;
    bool invert;
} FFTParams;

typedef struct {
    double* a;
    double* b;
    bool invert;
} FFTParams;

typedef struct {
    double* a;
    double* b;
    bool invert;
} FFTParams;

typedef struct {
    double* a;
    double* b;
    bool invert;
} FFTParams;

typedef struct {
    double* a;
    double* b;
    bool invert;
} FFTParams;

typedef struct {
    double* a;
    double* b;
    bool invert;
} FFTParams;

typedef struct {
    double* a;
    double* b;
    bool invert;
} FFTParams;

typedef struct {
    double* a;
    double* b;
    bool invert;
} FFTParams;

typedef struct {
    double* a;
    double* b;
    bool invert;
} FFTParams;

typedef struct {
    double* a;
    double* b;
    bool invert;
} FFTParams;

typedef struct {
    double* a;
    double* b;
    bool invert;
} FFTParams;

typedef struct {
    double* a;
    double* b;
    bool invert;
} FFTParams;

typedef struct {
    double* a;
    double* b;
    bool invert;
} FFTParams;

typedef struct {
    double* a;
    double* b;
    bool invert;
} FFTParams;

typedef struct {
    double* a;
    double* b;
    bool invert;
} FFTParams;

typedef struct {
    double* a;
    double* b;
    bool invert;
} FFTParams;

typedef struct {
    double* a;
    double* b;
    bool invert;
} FFTParams;

typedef struct {
    double* a;
    double* b;
    bool invert;
} FFTParams;

typedef struct {
    double* a;
    double* b;
    bool invert;
} FFTParams;

typedef struct {
    double* a;
    double* b;
    bool invert;
} FFTParams;

typedef struct {
    double* a;
    double* b;
    bool invert;
} FFTParams;

typedef struct {
    double* a;
    double* b;
    bool invert;
} FFTParams;

typedef struct {
    double* a;
    double* b;
    bool invert;
} FFTParams;

typedef struct {
    double* a;
    double* b;
    bool invert;
} FFTParams;

typedef struct {
    double* a;
    double* b;
    bool invert;
} FFTParams;

typedef struct {
    double* a;
    double* b;
    bool invert;
} FFTParams;

typedef struct {
    double* a;
    double* b;
    bool invert;
} FFTParams;

typedef struct {
    double* a;
    double* b;
    bool invert;
} FFTParams;

typedef struct {
    double* a;
    double* b;
    bool invert;
} FFTParams;

typedef struct {
    double* a;
    double* b;
    bool invert;
} FFTParams;

typedef struct {
    double* a;
    double* b;
    bool invert;
} FFTParams;

typedef struct {
    double* a;
    double* b;
    bool invert;
} FFTParams;

typedef struct {
    double* a;
    double* b;
    bool invert;
} FFTParams;

typedef struct {
    double* a;
    double* b;
    bool invert;
} FFTParams;

typedef struct {
    double* a;
    double* b;
    bool invert;
} FFTParams;

typedef struct {
    double* a;
    double* b;
    bool invert;
} FFTParams;

typedef struct {
    double* a;
    double* b;
    bool invert;
} FFTParams;

typedef struct {
    double* a;
    double* b;
    bool invert;
} FFTParams;

typedef struct {
    double* a;
    double* b;
    bool invert;
} FFTParams;

typedef struct {
    double* a;
    double* b;
    bool invert;
} FFTParams;

typedef struct {
    double* a;
    double* b;
    bool invert;
} FFTParams;

typedef struct {
    double* a;
    double* b;
    bool invert;
} FFTParams;

typedef struct {
    double* a;
    double* b;
    bool invert;
} FFTParams;

typedef struct {
    double* a;
    double* b;
    bool invert;
} FFTParams;

typedef struct {
    double* a;
    double* b;
    bool invert;
} FFTParams;

typedef struct {
    double* a;
    double* b;
    bool invert;
} FFTParams;

typedef struct {
    double* a;
    double* b;
    bool invert;
} FFTParams;

typedef struct {
    double* a;
    double* b;
    bool invert;
} FFTParams;

typedef struct {
    double* a;
    double* b;
    bool invert;
} FFTParams;

typedef struct {
    double* a;
    double* b;
    bool invert;
} FFTParams;

typedef struct {
    double* a;
    double* b;
    bool invert;
} FFTParams;

typedef struct {
    double* a;
    double* b;
    bool invert;
} FFTParams;

typedef struct {
    double* a;
    double* b;
    bool invert;
} FFTParams;

typedef struct {
    double* a;
    double* b;
    bool invert;
} FFTParams;

typedef struct {
    double* a;
    double* b;
    bool invert;
} FFTParams;

typedef struct {
    double* a;
    double* b;
    bool invert;
} FFTParams;

typedef struct {
    double* a;
    double* b;
    bool invert;
} FFTParams;

typedef struct {
    double* a;
    double* b;
    bool invert;
} FFTParams;

typedef struct {
    double* a;
    double* b;
    bool invert;
} FFTParams;

typedef struct {
    double* a;
    double* b;
    bool invert;
} FFTParams;

typedef struct {
    double* a;
    double* b;
    bool invert;
} FFTParams;

typedef struct {
    double* a;
    double* b;
    bool invert;
} FFTParams;

typedef struct {
    double* a;
    double* b;
    bool invert;
} FFTParams;

typedef struct {
    double* a;
    double* b;
    bool invert;
} FFTParams;

typedef struct {
    double* a;
    double* b;
    bool invert;
} FFTParams;

typedef struct {
    double* a;
    double* b;
    bool invert;
} FFTParams;

typedef struct {
    double* a;
    double* b;
    bool invert;
} FFTParams;

typedef struct {
    double* a;
    double* b;
    bool invert;
} FFTParams;

typedef struct {
    double* a;
    double* b;
    bool invert;
} FFTParams;

typedef struct {
    double* a;
    double* b;
    bool invert;
} FFTParams;

typedef struct {
    double* a;
    double* b;
    bool invert;
} FFTParams;

typedef struct {
    double* a;
    double* b;
    bool invert;
} FFTParams;

typedef struct {
    double* a;
    double* b;
    bool invert;
} FFTParams;

typedef struct {
    double* a;
    double* b;
    bool invert;
} FFTParams;

typedef struct {
    double* a;
    double* b;
    bool invert;
} FFTParams;

typedef struct {
    double* a;
    double* b;
    bool invert;
} FFTParams;

typedef struct {
    double* a;
    double* b;
    bool invert;
} FFTParams;

typedef struct {
    double* a;
    double* b;
    bool invert;
} FFTParams;

typedef struct {
    double* a;
    double* b;
    bool invert;
} FFTParams;

typedef struct {
    double* a;
    double* b;
    bool invert;
} FFTParams;

typedef struct {
    double* a;
    double* b;
    bool invert;
} FFTParams;

typedef struct {
    double* a;
    double* b;
    bool invert;
} FFTParams;

typedef struct {
    double* a;
    double* b;
    bool invert;
} FFTParams;

typedef struct {
    double* a;
    double* b;
    bool invert;
} FFTParams;

typedef struct {
    double* a;
    double* b;
    bool invert;
} FFTParams;

typedef struct {
    double* a;
    double* b;
    bool invert;
} FFTParams;

typedef struct {
    double* a;
    double* b;
    bool invert;
} FFTParams;

typedef struct {
    double* a;
    double* b;
    bool invert;
} FFTParams;

typedef struct {
    double* a;
    double* b;
    bool invert;

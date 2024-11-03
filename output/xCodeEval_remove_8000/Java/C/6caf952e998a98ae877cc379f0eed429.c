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
    int capacity;
    IntComparator comparator;
} Heap;

typedef struct {
    double* a;
    double* b;
} Complex;

typedef struct {
    Complex* data;
    int size;
} ComplexArray;

typedef struct {
    double* data;
    int size;
} DoubleArray;

typedef struct {
    int* data;
    int size;
} IntArray;

typedef struct {
    long long* data;
    int size;
} LongArray;

typedef struct {
    Point* data;
    int size;
} PointArray;

typedef struct {
    Segment* data;
    int size;
} SegmentArray;

typedef struct {
    double* data;
    int size;
} DoubleArray;

typedef struct {
    int* data;
    int size;
} IntArray;

typedef struct {
    long long* data;
    int size;
} LongArray;

typedef struct {
    Point* data;
    int size;
} PointArray;

typedef struct {
    Segment* data;
    int size;
} SegmentArray;

typedef struct {
    double* data;
    int size;
} DoubleArray;

typedef struct {
    int* data;
    int size;
} IntArray;

typedef struct {
    long long* data;
    int size;
} LongArray;

typedef struct {
    Point* data;
    int size;
} PointArray;

typedef struct {
    Segment* data;
    int size;
} SegmentArray;

typedef struct {
    double* data;
    int size;
} DoubleArray;

typedef struct {
    int* data;
    int size;
} IntArray;

typedef struct {
    long long* data;
    int size;
} LongArray;

typedef struct {
    Point* data;
    int size;
} PointArray;

typedef struct {
    Segment* data;
    int size;
} SegmentArray;

typedef struct {
    double* data;
    int size;
} DoubleArray;

typedef struct {
    int* data;
    int size;
} IntArray;

typedef struct {
    long long* data;
    int size;
} LongArray;

typedef struct {
    Point* data;
    int size;
} PointArray;

typedef struct {
    Segment* data;
    int size;
} SegmentArray;

typedef struct {
    double* data;
    int size;
} DoubleArray;

typedef struct {
    int* data;
    int size;
} IntArray;

typedef struct {
    long long* data;
    int size;
} LongArray;

typedef struct {
    Point* data;
    int size;
} PointArray;

typedef struct {
    Segment* data;
    int size;
} SegmentArray;

typedef struct {
    double* data;
    int size;
} DoubleArray;

typedef struct {
    int* data;
    int size;
} IntArray;

typedef struct {
    long long* data;
    int size;
} LongArray;

typedef struct {
    Point* data;
    int size;
} PointArray;

typedef struct {
    Segment* data;
    int size;
} SegmentArray;

typedef struct {
    double* data;
    int size;
} DoubleArray;

typedef struct {
    int* data;
    int size;
} IntArray;

typedef struct {
    long long* data;
    int size;
} LongArray;

typedef struct {
    Point* data;
    int size;
} PointArray;

typedef struct {
    Segment* data;
    int size;
} SegmentArray;

typedef struct {
    double* data;
    int size;
} DoubleArray;

typedef struct {
    int* data;
    int size;
} IntArray;

typedef struct {
    long long* data;
    int size;
} LongArray;

typedef struct {
    Point* data;
    int size;
} PointArray;

typedef struct {
    Segment* data;
    int size;
} SegmentArray;

typedef struct {
    double* data;
    int size;
} DoubleArray;

typedef struct {
    int* data;
    int size;
} IntArray;

typedef struct {
    long long* data;
    int size;
} LongArray;

typedef struct {
    Point* data;
    int size;
} PointArray;

typedef struct {
    Segment* data;
    int size;
} SegmentArray;

typedef struct {
    double* data;
    int size;
} DoubleArray;

typedef struct {
    int* data;
    int size;
} IntArray;

typedef struct {
    long long* data;
    int size;
} LongArray;

typedef struct {
    Point* data;
    int size;
} PointArray;

typedef struct {
    Segment* data;
    int size;
} SegmentArray;

typedef struct {
    double* data;
    int size;
} DoubleArray;

typedef struct {
    int* data;
    int size;
} IntArray;

typedef struct {
    long long* data;
    int size;
} LongArray;

typedef struct {
    Point* data;
    int size;
} PointArray;

typedef struct {
    Segment* data;
    int size;
} SegmentArray;

typedef struct {
    double* data;
    int size;
} DoubleArray;

typedef struct {
    int* data;
    int size;
} IntArray;

typedef struct {
    long long* data;
    int size;
} LongArray;

typedef struct {
    Point* data;
    int size;
} PointArray;

typedef struct {
    Segment* data;
    int size;
} SegmentArray;

typedef struct {
    double* data;
    int size;
} DoubleArray;

typedef struct {
    int* data;
    int size;
} IntArray;

typedef struct {
    long long* data;
    int size;
} LongArray;

typedef struct {
    Point* data;
    int size;
} PointArray;

typedef struct {
    Segment* data;
    int size;
} SegmentArray;

typedef struct {
    double* data;
    int size;
} DoubleArray;

typedef struct {
    int* data;
    int size;
} IntArray;

typedef struct {
    long long* data;
    int size;
} LongArray;

typedef struct {
    Point* data;
    int size;
} PointArray;

typedef struct {
    Segment* data;
    int size;
} SegmentArray;

typedef struct {
    double* data;
    int size;
} DoubleArray;

typedef struct {
    int* data;
    int size;
} IntArray;

typedef struct {
    long long* data;
    int size;
} LongArray;

typedef struct {
    Point* data;
    int size;
} PointArray;

typedef struct {
    Segment* data;
    int size;
} SegmentArray;

typedef struct {
    double* data;
    int size;
} DoubleArray;

typedef struct {
    int* data;
    int size;
} IntArray;

typedef struct {
    long long* data;
    int size;
} LongArray;

typedef struct {
    Point* data;
    int size;
} PointArray;

typedef struct {
    Segment* data;
    int size;
} SegmentArray;

typedef struct {
    double* data;
    int size;
} DoubleArray;

typedef struct {
    int* data;
    int size;
} IntArray;

typedef struct {
    long long* data;
    int size;
} LongArray;

typedef struct {
    Point* data;
    int size;
} PointArray;

typedef struct {
    Segment* data;
    int size;
} SegmentArray;

typedef struct {
    double* data;
    int size;
} DoubleArray;

typedef struct {
    int* data;
    int size;
} IntArray;

typedef struct {
    long long* data;
    int size;
} LongArray;

typedef struct {
    Point* data;
    int size;
} PointArray;

typedef struct {
    Segment* data;
    int size;
} SegmentArray;

typedef struct {
    double* data;
    int size;
} DoubleArray;

typedef struct {
    int* data;
    int size;
} IntArray;

typedef struct {
    long long* data;
    int size;
} LongArray;

typedef struct {
    Point* data;
    int size;
} PointArray;

typedef struct {
    Segment* data;
    int size;
} SegmentArray;

typedef struct {
    double* data;
    int size;
} DoubleArray;

typedef struct {
    int* data;
    int size;
} IntArray;

typedef struct {
    long long* data;
    int size;
} LongArray;

typedef struct {
    Point* data;
    int size;
} PointArray;

typedef struct {
    Segment* data;
    int size;
} SegmentArray;

typedef struct {
    double* data;
    int size;
} DoubleArray;

typedef struct {
    int* data;
    int size;
} IntArray;

typedef struct {
    long long* data;
    int size;
} LongArray;

typedef struct {
    Point* data;
    int size;
} PointArray;

typedef struct {
    Segment* data;
    int size;
} SegmentArray;

typedef struct {
    double* data;
    int size;
} DoubleArray;

typedef struct {
    int* data;
    int size;
} IntArray;

typedef struct {
    long long* data;
    int size;
} LongArray;

typedef struct {
    Point* data;
    int size;
} PointArray;

typedef struct {
    Segment* data;
    int size;
} SegmentArray;

typedef struct {
    double* data;
    int size;
} DoubleArray;

typedef struct {
    int* data;
    int size;
} IntArray;

typedef struct {
    long long* data;
    int size;
} LongArray;

typedef struct {
    Point* data;
    int size;
} PointArray;

typedef struct {
    Segment* data;
    int size;
} SegmentArray;

typedef struct {
    double* data;
    int size;
} DoubleArray;

typedef struct {
    int* data;
    int size;
} IntArray;

typedef struct {
    long long* data;
    int size;
} LongArray;

typedef struct {
    Point* data;
    int size;
} PointArray;

typedef struct {
    Segment* data;
    int size;
} SegmentArray;

typedef struct {
    double* data;
    int size;
} DoubleArray;

typedef struct {
    int* data;
    int size;
} IntArray;

typedef struct {
    long long* data;
    int size;
} LongArray;

typedef struct {
    Point* data;
    int size;
} PointArray;

typedef struct {
    Segment* data;
    int size;
} SegmentArray;

typedef struct {
    double* data;
    int size;
} DoubleArray;

typedef struct {
    int* data;
    int size;
} IntArray;

typedef struct {
    long long* data;
    int size;
} LongArray;

typedef struct {
    Point* data;
    int size;
} PointArray;

typedef struct {
    Segment* data;
    int size;
} SegmentArray;

typedef struct {
    double* data;
    int size;
} DoubleArray;

typedef struct {
    int* data;
    int size;
} IntArray;

typedef struct {
    long long* data;
    int size;
} LongArray;

typedef struct {
    Point* data;
    int size;
} PointArray;

typedef struct {
    Segment* data;
    int size;
} SegmentArray;

typedef struct {
    double* data;
    int size;
} DoubleArray;

typedef struct {
    int* data;
    int size;
} IntArray;

typedef struct {
    long long* data;
    int size;
} LongArray;

typedef struct {
    Point* data;
    int size;
} PointArray;

typedef struct {
    Segment* data;
    int size;
} SegmentArray;

typedef struct {
    double* data;
    int size;
} DoubleArray;

typedef struct {
    int* data;
    int size;
} IntArray;

typedef struct {
    long long* data;
    int size;
} LongArray;

typedef struct {
    Point* data;
    int size;
} PointArray;

typedef struct {
    Segment* data;
    int size;
} SegmentArray;

typedef struct {
    double* data;
    int size;
} DoubleArray;

typedef struct {
    int* data;
    int size;
} IntArray;

typedef struct {
    long long* data;
    int size;
} LongArray;

typedef struct {
    Point* data;
    int size;
} PointArray;

typedef struct {
    Segment* data;
    int size;
} SegmentArray;

typedef struct {
    double* data;
    int size;
} DoubleArray;

typedef struct {
    int* data;
    int size;
} IntArray;

typedef struct {
    long long* data;
    int size;
} LongArray;

typedef struct {
    Point* data;
    int size;
} PointArray;

typedef struct {
    Segment* data;
    int size;
} SegmentArray;

typedef struct {
    double* data;
    int size;
} DoubleArray;

typedef struct {
    int* data;
    int size;
} IntArray;

typedef struct {
    long long* data;
    int size;
} LongArray;

typedef struct {
    Point* data;
    int size;
} PointArray;

typedef struct {
    Segment* data;
    int size;
} SegmentArray;

typedef struct {
    double* data;
    int size;
} DoubleArray;

typedef struct {
    int* data;
    int size;
} IntArray;

typedef struct {
    long long* data;
    int size;
} LongArray;

typedef struct {
    Point* data;
    int size;
} PointArray;

typedef struct {
    Segment* data;
    int size;
} SegmentArray;

typedef struct {
    double* data;
    int size;
} DoubleArray;

typedef struct {
    int* data;
    int size;
} IntArray;

typedef struct {
    long long* data;
    int size;
} LongArray;

typedef struct {
    Point* data;
    int size;
} PointArray;

typedef struct {
    Segment* data;
    int size;
} SegmentArray;

typedef struct {
    double* data;
    int size;
} DoubleArray;

typedef struct {
    int* data;
    int size;
} IntArray;

typedef struct {
    long long* data;
    int size;
} LongArray;

typedef struct {
    Point* data;
    int size;
} PointArray;

typedef struct {
    Segment* data;
    int size;
} SegmentArray;

typedef struct {
    double* data;
    int size;
} DoubleArray;

typedef struct {
    int* data;
    int size;
} IntArray;

typedef struct {
    long long* data;
    int size;
} LongArray;

typedef struct {
    Point* data;
    int size;
} PointArray;

typedef struct {
    Segment* data;
    int size;
} SegmentArray;

typedef struct {
    double* data;
    int size;
} DoubleArray;

typedef struct {
    int* data;
    int size;
} IntArray;

typedef struct {
    long long* data;
    int size;
} LongArray;

typedef struct {
    Point* data;
    int size;
} PointArray;

typedef struct {
    Segment* data;
    int size;
} SegmentArray;

typedef struct {
    double* data;
    int size;
} DoubleArray;

typedef struct {
    int* data;
    int size;
} IntArray;

typedef struct {
    long long* data;
    int size;
} LongArray;

typedef struct {
    Point* data;
    int size;
} PointArray;

typedef struct {
    Segment* data;
    int size;
} SegmentArray;

typedef struct {
    double* data;
    int size;
} DoubleArray;

typedef struct {
    int* data;
    int size;
} IntArray;

typedef struct {
    long long* data;
    int size;
} LongArray;

typedef struct {
    Point* data;
    int size;
} PointArray;

typedef struct {
    Segment* data;
    int size;
} SegmentArray;

typedef struct {
    double* data;
    int size;
} DoubleArray;

typedef struct {
    int* data;
    int size;
} IntArray;

typedef struct {
    long long* data;
    int size;
} LongArray;

typedef struct {
    Point* data;
    int size;
} PointArray;

typedef struct {
    Segment* data;
    int size;
} SegmentArray;

typedef struct {
    double* data;
    int size;
} DoubleArray;

typedef struct {
    int* data;
    int size;
} IntArray;

typedef struct {
    long long* data;
    int size;
} LongArray;

typedef struct {
    Point* data;
    int size;
} PointArray;

typedef struct {
    Segment* data;
    int size;
} SegmentArray;

typedef struct {
    double* data;
    int size;
} DoubleArray;

typedef struct {
    int* data;
    int size;
} IntArray;

typedef struct {
    long long* data;
    int size;
} LongArray;

typedef struct {
    Point* data;
    int size;
} PointArray;

typedef struct {
    Segment* data;
    int size;
} SegmentArray;

typedef struct {
    double* data;
    int size;
} DoubleArray;

typedef struct {
    int* data;
    int size;
} IntArray;

typedef struct {
    long long* data;
    int size;
} LongArray;

typedef struct {
    Point* data;
    int size;
} PointArray;

typedef struct {
    Segment* data;
    int size;
} SegmentArray;

typedef struct {
    double* data;
    int size;
} DoubleArray;

typedef struct {
    int* data;
    int size;
} IntArray;

typedef struct {
    long long* data;
    int size;
} LongArray;

typedef struct {
    Point* data;
    int size;
} PointArray;

typedef struct {
    Segment* data;
    int size;
} SegmentArray;

typedef struct {
    double* data;
    int size;
} DoubleArray;

typedef struct {
    int* data;
    int size;
} IntArray;

typedef struct {
    long long* data;
    int size;
} LongArray;

typedef struct {
    Point* data;
    int size;
} PointArray;

typedef struct {
    Segment* data;
    int size;
} SegmentArray;

typedef struct {
    double* data;
    int size;
} DoubleArray;

typedef struct {
    int* data;
    int size;
} IntArray;

typedef struct {
    long long* data;
    int size;
} LongArray;

typedef struct {
    Point* data;
    int size;
} PointArray;

typedef struct {
    Segment* data;
    int size;
} SegmentArray;

typedef struct {
    double* data;
    int size;
} DoubleArray;

typedef struct {
    int* data;
    int size;
} IntArray;

typedef struct {
    long long* data;
    int size;
} LongArray;

typedef struct {
    Point* data;
    int size;
} PointArray;

typedef struct {
    Segment* data;
    int size;
} SegmentArray;

typedef struct {
    double* data;
    int size;
} DoubleArray;

typedef struct {
    int* data;
    int size;
} IntArray;

typedef struct {
    long long* data;
    int size;
} LongArray;

typedef struct {
    Point* data;
    int size;
} PointArray;

typedef struct {
    Segment* data;
    int size;
} SegmentArray;

typedef struct {
    double* data;
    int size;
} DoubleArray;

typedef struct {
    int* data;
    int size;
} IntArray;

typedef struct {
    long long* data;
    int size;
} LongArray;

typedef struct {
    Point* data;
    int size;
} PointArray;

typedef struct {
    Segment* data;
    int size;
} SegmentArray;

typedef struct {
    double* data;
    int size;
} DoubleArray;

typedef struct {
    int* data;
    int size;
} IntArray;

typedef struct {
    long long* data;
    int size;
} LongArray;

typedef struct {
    Point* data;
    int size;
} PointArray;

typedef struct {
    Segment* data;
    int size;
} SegmentArray;

typedef struct {
    double* data;
    int size;
} DoubleArray;

typedef struct {
    int* data;
    int size;
} IntArray;

typedef struct {
    long long* data;
    int size;
} LongArray;

typedef struct {
    Point* data;
    int size;
} PointArray;

typedef struct {
    Segment* data;
    int size;
} SegmentArray;

typedef struct {
    double* data;
    int size;
} DoubleArray;

typedef struct {
    int* data;
    int size;
} IntArray;

typedef struct {
    long long* data;
    int size;
} LongArray;

typedef struct {
    Point* data;
    int size;
} PointArray;

typedef struct {
    Segment* data;
    int size;
} SegmentArray;

typedef struct {
    double* data;
    int size;
} DoubleArray;

typedef struct {
    int* data;
    int size;
} IntArray;

typedef struct {
    long long* data;
    int size;
} LongArray;

typedef struct {
    Point* data;
    int size;
} PointArray;

typedef struct {
    Segment* data;
    int size;
} SegmentArray;

typedef struct {
    double* data;
    int size;
} DoubleArray;

typedef struct {
    int* data;
    int size;
} IntArray;

typedef struct {
    long long* data;
    int size;
} LongArray;

typedef struct {
    Point* data;
    int size;
} PointArray;

typedef struct {
    Segment* data;
    int size;
} SegmentArray;

typedef struct {
    double* data;
    int size;
} DoubleArray;

typedef struct {
    int* data;
    int size;
} IntArray;

typedef struct {
    long long* data;
    int size;
} LongArray;

typedef struct {
    Point* data;
    int size;
} PointArray;

typedef struct {
    Segment* data;
    int size;
} SegmentArray;

typedef struct {
    double* data;
    int size;
} DoubleArray;

typedef struct {
    int* data;
    int size;
} IntArray;

typedef struct {
    long long* data;
    int size;
} LongArray;

typedef struct {
    Point* data;
    int size;
} PointArray;

typedef struct {
    Segment* data;
    int size;
} SegmentArray;

typedef struct {
    double* data;
    int size;
} DoubleArray;

typedef struct {
    int* data;
    int size;
} IntArray;

typedef struct {
    long long* data;
    int size;
} LongArray;

typedef struct {
    Point* data;
    int size;
} PointArray;

typedef struct {
    Segment* data;
    int size;
} SegmentArray;

typedef struct {
    double* data;
    int size;
} DoubleArray;

typedef struct {
    int* data;
    int size;
} IntArray;

typedef struct {
    long long* data;
    int size;
} LongArray;

typedef struct {
    Point* data;
    int size;
} PointArray;

typedef struct {
    Segment* data;
    int size;
} SegmentArray;

typedef struct {
    double* data;
    int size;
} DoubleArray;

typedef struct {
    int* data;
    int size;
} IntArray;

typedef struct {
    long long* data;
    int size;
} LongArray;

typedef struct {
    Point* data;
    int size;
} PointArray;

typedef struct {
    Segment* data;
    int size;
} SegmentArray;

typedef struct {
    double* data;
    int size;
} DoubleArray;

typedef struct {
    int* data;
    int size;
} IntArray;

typedef struct {
    long long* data;
    int size;
} LongArray;

typedef struct {
    Point* data;
    int size;
} PointArray;

typedef struct {
    Segment* data;
    int size;
} SegmentArray;

typedef struct {
    double* data;
    int size;
} DoubleArray;

typedef struct {
    int* data;
    int size;

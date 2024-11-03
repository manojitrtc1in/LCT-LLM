#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>

#define MAX_RND 10
#define MODULO 1000000007

typedef struct {
    int x;
    int y;
} Point;

typedef struct {
    int to;
    int w;
} Edge;

typedef struct {
    int value;
    int index;
} IntIndexPair;

typedef struct {
    int size;
    int* array;
} IntArray;

typedef struct {
    int** matrix;
    int rowsCount;
    int columnsCount;
} IntMatrix;

typedef struct {
    double** matrix;
    int rowsCount;
    int columnsCount;
} DoubleMatrix;

typedef struct {
    char** matrix;
    int rowsCount;
    int columnsCount;
} CharMatrix;

typedef struct {
    int* array;
    int size;
} IntArray;

typedef struct {
    double* array;
    int size;
} DoubleArray;

typedef struct {
    char* array;
    int size;
} CharArray;

typedef struct {
    Point* array;
    int size;
} PointArray;

typedef struct {
    int from;
    int to;
    int index;
} Edge;

typedef struct {
    Edge* array;
    int size;
} EdgeArray;

typedef struct {
    int* array;
    int size;
} IntArray;

typedef struct {
    double* array;
    int size;
} DoubleArray;

typedef struct {
    char* array;
    int size;
} CharArray;

typedef struct {
    Point* array;
    int size;
} PointArray;

typedef struct {
    int** edges;
    int size;
} Graph;

typedef struct {
    int** edges;
    int size;
} Graph;

typedef struct {
    int* array;
    int size;
} IntArray;

typedef struct {
    double* array;
    int size;
} DoubleArray;

typedef struct {
    char* array;
    int size;
} CharArray;

typedef struct {
    Point* array;
    int size;
} PointArray;

typedef struct {
    int** edges;
    int size;
} Graph;

typedef struct {
    int** edges;
    int size;
} Graph;

typedef struct {
    int* array;
    int size;
} IntArray;

typedef struct {
    double* array;
    int size;
} DoubleArray;

typedef struct {
    char* array;
    int size;
} CharArray;

typedef struct {
    Point* array;
    int size;
} PointArray;

typedef struct {
    int** edges;
    int size;
} Graph;

typedef struct {
    int** edges;
    int size;
} Graph;

typedef struct {
    int* array;
    int size;
} IntArray;

typedef struct {
    double* array;
    int size;
} DoubleArray;

typedef struct {
    char* array;
    int size;
} CharArray;

typedef struct {
    Point* array;
    int size;
} PointArray;

typedef struct {
    int** edges;
    int size;
} Graph;

typedef struct {
    int** edges;
    int size;
} Graph;

typedef struct {
    int* array;
    int size;
} IntArray;

typedef struct {
    double* array;
    int size;
} DoubleArray;

typedef struct {
    char* array;
    int size;
} CharArray;

typedef struct {
    Point* array;
    int size;
} PointArray;

typedef struct {
    int** edges;
    int size;
} Graph;

typedef struct {
    int** edges;
    int size;
} Graph;

typedef struct {
    int* array;
    int size;
} IntArray;

typedef struct {
    double* array;
    int size;
} DoubleArray;

typedef struct {
    char* array;
    int size;
} CharArray;

typedef struct {
    Point* array;
    int size;
} PointArray;

typedef struct {
    int** edges;
    int size;
} Graph;

typedef struct {
    int** edges;
    int size;
} Graph;

typedef struct {
    int* array;
    int size;
} IntArray;

typedef struct {
    double* array;
    int size;
} DoubleArray;

typedef struct {
    char* array;
    int size;
} CharArray;

typedef struct {
    Point* array;
    int size;
} PointArray;

typedef struct {
    int** edges;
    int size;
} Graph;

typedef struct {
    int** edges;
    int size;
} Graph;

typedef struct {
    int* array;
    int size;
} IntArray;

typedef struct {
    double* array;
    int size;
} DoubleArray;

typedef struct {
    char* array;
    int size;
} CharArray;

typedef struct {
    Point* array;
    int size;
} PointArray;

typedef struct {
    int** edges;
    int size;
} Graph;

typedef struct {
    int** edges;
    int size;
} Graph;

typedef struct {
    int* array;
    int size;
} IntArray;

typedef struct {
    double* array;
    int size;
} DoubleArray;

typedef struct {
    char* array;
    int size;
} CharArray;

typedef struct {
    Point* array;
    int size;
} PointArray;

typedef struct {
    int** edges;
    int size;
} Graph;

typedef struct {
    int** edges;
    int size;
} Graph;

typedef struct {
    int* array;
    int size;
} IntArray;

typedef struct {
    double* array;
    int size;
} DoubleArray;

typedef struct {
    char* array;
    int size;
} CharArray;

typedef struct {
    Point* array;
    int size;
} PointArray;

typedef struct {
    int** edges;
    int size;
} Graph;

typedef struct {
    int** edges;
    int size;
} Graph;

typedef struct {
    int* array;
    int size;
} IntArray;

typedef struct {
    double* array;
    int size;
} DoubleArray;

typedef struct {
    char* array;
    int size;
} CharArray;

typedef struct {
    Point* array;
    int size;
} PointArray;

typedef struct {
    int** edges;
    int size;
} Graph;

typedef struct {
    int** edges;
    int size;
} Graph;

typedef struct {
    int* array;
    int size;
} IntArray;

typedef struct {
    double* array;
    int size;
} DoubleArray;

typedef struct {
    char* array;
    int size;
} CharArray;

typedef struct {
    Point* array;
    int size;
} PointArray;

typedef struct {
    int** edges;
    int size;
} Graph;

typedef struct {
    int** edges;
    int size;
} Graph;

typedef struct {
    int* array;
    int size;
} IntArray;

typedef struct {
    double* array;
    int size;
} DoubleArray;

typedef struct {
    char* array;
    int size;
} CharArray;

typedef struct {
    Point* array;
    int size;
} PointArray;

typedef struct {
    int** edges;
    int size;
} Graph;

typedef struct {
    int** edges;
    int size;
} Graph;

typedef struct {
    int* array;
    int size;
} IntArray;

typedef struct {
    double* array;
    int size;
} DoubleArray;

typedef struct {
    char* array;
    int size;
} CharArray;

typedef struct {
    Point* array;
    int size;
} PointArray;

typedef struct {
    int** edges;
    int size;
} Graph;

typedef struct {
    int** edges;
    int size;
} Graph;

typedef struct {
    int* array;
    int size;
} IntArray;

typedef struct {
    double* array;
    int size;
} DoubleArray;

typedef struct {
    char* array;
    int size;
} CharArray;

typedef struct {
    Point* array;
    int size;
} PointArray;

typedef struct {
    int** edges;
    int size;
} Graph;

typedef struct {
    int** edges;
    int size;
} Graph;

typedef struct {
    int* array;
    int size;
} IntArray;

typedef struct {
    double* array;
    int size;
} DoubleArray;

typedef struct {
    char* array;
    int size;
} CharArray;

typedef struct {
    Point* array;
    int size;
} PointArray;

typedef struct {
    int** edges;
    int size;
} Graph;

typedef struct {
    int** edges;
    int size;
} Graph;

typedef struct {
    int* array;
    int size;
} IntArray;

typedef struct {
    double* array;
    int size;
} DoubleArray;

typedef struct {
    char* array;
    int size;
} CharArray;

typedef struct {
    Point* array;
    int size;
} PointArray;

typedef struct {
    int** edges;
    int size;
} Graph;

typedef struct {
    int** edges;
    int size;
} Graph;

typedef struct {
    int* array;
    int size;
} IntArray;

typedef struct {
    double* array;
    int size;
} DoubleArray;

typedef struct {
    char* array;
    int size;
} CharArray;

typedef struct {
    Point* array;
    int size;
} PointArray;

typedef struct {
    int** edges;
    int size;
} Graph;

typedef struct {
    int** edges;
    int size;
} Graph;

typedef struct {
    int* array;
    int size;
} IntArray;

typedef struct {
    double* array;
    int size;
} DoubleArray;

typedef struct {
    char* array;
    int size;
} CharArray;

typedef struct {
    Point* array;
    int size;
} PointArray;

typedef struct {
    int** edges;
    int size;
} Graph;

typedef struct {
    int** edges;
    int size;
} Graph;

typedef struct {
    int* array;
    int size;
} IntArray;

typedef struct {
    double* array;
    int size;
} DoubleArray;

typedef struct {
    char* array;
    int size;
} CharArray;

typedef struct {
    Point* array;
    int size;
} PointArray;

typedef struct {
    int** edges;
    int size;
} Graph;

typedef struct {
    int** edges;
    int size;
} Graph;

typedef struct {
    int* array;
    int size;
} IntArray;

typedef struct {
    double* array;
    int size;
} DoubleArray;

typedef struct {
    char* array;
    int size;
} CharArray;

typedef struct {
    Point* array;
    int size;
} PointArray;

typedef struct {
    int** edges;
    int size;
} Graph;

typedef struct {
    int** edges;
    int size;
} Graph;

typedef struct {
    int* array;
    int size;
} IntArray;

typedef struct {
    double* array;
    int size;
} DoubleArray;

typedef struct {
    char* array;
    int size;
} CharArray;

typedef struct {
    Point* array;
    int size;
} PointArray;

typedef struct {
    int** edges;
    int size;
} Graph;

typedef struct {
    int** edges;
    int size;
} Graph;

typedef struct {
    int* array;
    int size;
} IntArray;

typedef struct {
    double* array;
    int size;
} DoubleArray;

typedef struct {
    char* array;
    int size;
} CharArray;

typedef struct {
    Point* array;
    int size;
} PointArray;

typedef struct {
    int** edges;
    int size;
} Graph;

typedef struct {
    int** edges;
    int size;
} Graph;

typedef struct {
    int* array;
    int size;
} IntArray;

typedef struct {
    double* array;
    int size;
} DoubleArray;

typedef struct {
    char* array;
    int size;
} CharArray;

typedef struct {
    Point* array;
    int size;
} PointArray;

typedef struct {
    int** edges;
    int size;
} Graph;

typedef struct {
    int** edges;
    int size;
} Graph;

typedef struct {
    int* array;
    int size;
} IntArray;

typedef struct {
    double* array;
    int size;
} DoubleArray;

typedef struct {
    char* array;
    int size;
} CharArray;

typedef struct {
    Point* array;
    int size;
} PointArray;

typedef struct {
    int** edges;
    int size;
} Graph;

typedef struct {
    int** edges;
    int size;
} Graph;

typedef struct {
    int* array;
    int size;
} IntArray;

typedef struct {
    double* array;
    int size;
} DoubleArray;

typedef struct {
    char* array;
    int size;
} CharArray;

typedef struct {
    Point* array;
    int size;
} PointArray;

typedef struct {
    int** edges;
    int size;
} Graph;

typedef struct {
    int** edges;
    int size;
} Graph;

typedef struct {
    int* array;
    int size;
} IntArray;

typedef struct {
    double* array;
    int size;
} DoubleArray;

typedef struct {
    char* array;
    int size;
} CharArray;

typedef struct {
    Point* array;
    int size;
} PointArray;

typedef struct {
    int** edges;
    int size;
} Graph;

typedef struct {
    int** edges;
    int size;
} Graph;

typedef struct {
    int* array;
    int size;
} IntArray;

typedef struct {
    double* array;
    int size;
} DoubleArray;

typedef struct {
    char* array;
    int size;
} CharArray;

typedef struct {
    Point* array;
    int size;
} PointArray;

typedef struct {
    int** edges;
    int size;
} Graph;

typedef struct {
    int** edges;
    int size;
} Graph;

typedef struct {
    int* array;
    int size;
} IntArray;

typedef struct {
    double* array;
    int size;
} DoubleArray;

typedef struct {
    char* array;
    int size;
} CharArray;

typedef struct {
    Point* array;
    int size;
} PointArray;

typedef struct {
    int** edges;
    int size;
} Graph;

typedef struct {
    int** edges;
    int size;
} Graph;

typedef struct {
    int* array;
    int size;
} IntArray;

typedef struct {
    double* array;
    int size;
} DoubleArray;

typedef struct {
    char* array;
    int size;
} CharArray;

typedef struct {
    Point* array;
    int size;
} PointArray;

typedef struct {
    int** edges;
    int size;
} Graph;

typedef struct {
    int** edges;
    int size;
} Graph;

typedef struct {
    int* array;
    int size;
} IntArray;

typedef struct {
    double* array;
    int size;
} DoubleArray;

typedef struct {
    char* array;
    int size;
} CharArray;

typedef struct {
    Point* array;
    int size;
} PointArray;

typedef struct {
    int** edges;
    int size;
} Graph;

typedef struct {
    int** edges;
    int size;
} Graph;

typedef struct {
    int* array;
    int size;
} IntArray;

typedef struct {
    double* array;
    int size;
} DoubleArray;

typedef struct {
    char* array;
    int size;
} CharArray;

typedef struct {
    Point* array;
    int size;
} PointArray;

typedef struct {
    int** edges;
    int size;
} Graph;

typedef struct {
    int** edges;
    int size;
} Graph;

typedef struct {
    int* array;
    int size;
} IntArray;

typedef struct {
    double* array;
    int size;
} DoubleArray;

typedef struct {
    char* array;
    int size;
} CharArray;

typedef struct {
    Point* array;
    int size;
} PointArray;

typedef struct {
    int** edges;
    int size;
} Graph;

typedef struct {
    int** edges;
    int size;
} Graph;

typedef struct {
    int* array;
    int size;
} IntArray;

typedef struct {
    double* array;
    int size;
} DoubleArray;

typedef struct {
    char* array;
    int size;
} CharArray;

typedef struct {
    Point* array;
    int size;
} PointArray;

typedef struct {
    int** edges;
    int size;
} Graph;

typedef struct {
    int** edges;
    int size;
} Graph;

typedef struct {
    int* array;
    int size;
} IntArray;

typedef struct {
    double* array;
    int size;
} DoubleArray;

typedef struct {
    char* array;
    int size;
} CharArray;

typedef struct {
    Point* array;
    int size;
} PointArray;

typedef struct {
    int** edges;
    int size;
} Graph;

typedef struct {
    int** edges;
    int size;
} Graph;

typedef struct {
    int* array;
    int size;
} IntArray;

typedef struct {
    double* array;
    int size;
} DoubleArray;

typedef struct {
    char* array;
    int size;
} CharArray;

typedef struct {
    Point* array;
    int size;
} PointArray;

typedef struct {
    int** edges;
    int size;
} Graph;

typedef struct {
    int** edges;
    int size;
} Graph;

typedef struct {
    int* array;
    int size;
} IntArray;

typedef struct {
    double* array;
    int size;
} DoubleArray;

typedef struct {
    char* array;
    int size;
} CharArray;

typedef struct {
    Point* array;
    int size;
} PointArray;

typedef struct {
    int** edges;
    int size;
} Graph;

typedef struct {
    int** edges;
    int size;
} Graph;

typedef struct {
    int* array;
    int size;
} IntArray;

typedef struct {
    double* array;
    int size;
} DoubleArray;

typedef struct {
    char* array;
    int size;
} CharArray;

typedef struct {
    Point* array;
    int size;
} PointArray;

typedef struct {
    int** edges;
    int size;
} Graph;

typedef struct {
    int** edges;
    int size;
} Graph;

typedef struct {
    int* array;
    int size;
} IntArray;

typedef struct {
    double* array;
    int size;
} DoubleArray;

typedef struct {
    char* array;
    int size;
} CharArray;

typedef struct {
    Point* array;
    int size;
} PointArray;

typedef struct {
    int** edges;
    int size;
} Graph;

typedef struct {
    int** edges;
    int size;
} Graph;

typedef struct {
    int* array;
    int size;
} IntArray;

typedef struct {
    double* array;
    int size;
} DoubleArray;

typedef struct {
    char* array;
    int size;
} CharArray;

typedef struct {
    Point* array;
    int size;
} PointArray;

typedef struct {
    int** edges;
    int size;
} Graph;

typedef struct {
    int** edges;
    int size;
} Graph;

typedef struct {
    int* array;
    int size;
} IntArray;

typedef struct {
    double* array;
    int size;
} DoubleArray;

typedef struct {
    char* array;
    int size;
} CharArray;

typedef struct {
    Point* array;
    int size;
} PointArray;

typedef struct {
    int** edges;
    int size;
} Graph;

typedef struct {
    int** edges;
    int size;
} Graph;

typedef struct {
    int* array;
    int size;
} IntArray;

typedef struct {
    double* array;
    int size;
} DoubleArray;

typedef struct {
    char* array;
    int size;
} CharArray;

typedef struct {
    Point* array;
    int size;
} PointArray;

typedef struct {
    int** edges;
    int size;
} Graph;

typedef struct {
    int** edges;
    int size;
} Graph;

typedef struct {
    int* array;
    int size;
} IntArray;

typedef struct {
    double* array;
    int size;
} DoubleArray;

typedef struct {
    char* array;
    int size;
} CharArray;

typedef struct {
    Point* array;
    int size;
} PointArray;

typedef struct {
    int** edges;
    int size;
} Graph;

typedef struct {
    int** edges;
    int size;
} Graph;

typedef struct {
    int* array;
    int size;
} IntArray;

typedef struct {
    double* array;
    int size;
} DoubleArray;

typedef struct {
    char* array;
    int size;
} CharArray;

typedef struct {
    Point* array;
    int size;
} PointArray;

typedef struct {
    int** edges;
    int size;
} Graph;

typedef struct {
    int** edges;
    int size;
} Graph;

typedef struct {
    int* array;
    int size;
} IntArray;

typedef struct {
    double* array;
    int size;
} DoubleArray;

typedef struct {
    char* array;
    int size;
} CharArray;

typedef struct {
    Point* array;
    int size;
} PointArray;

typedef struct {
    int** edges;
    int size;
} Graph;

typedef struct {
    int** edges;
    int size;
} Graph;

typedef struct {
    int* array;
    int size;
} IntArray;

typedef struct {
    double* array;
    int size;
} DoubleArray;

typedef struct {
    char* array;
    int size;
} CharArray;

typedef struct {
    Point* array;
    int size;
} PointArray;

typedef struct {
    int** edges;
    int size;
} Graph;

typedef struct {
    int** edges;
    int size;
} Graph;

typedef struct {
    int* array;
    int size;
} IntArray;

typedef struct {
    double* array;
    int size;
} DoubleArray;

typedef struct {
    char* array;
    int size;
} CharArray;

typedef struct {
    Point* array;
    int size;
} PointArray;

typedef struct {
    int** edges;
    int size;
} Graph;

typedef struct {
    int** edges;
    int size;
} Graph;

typedef struct {
    int* array;
    int size;
} IntArray;

typedef struct {
    double* array;
    int size;
} DoubleArray;

typedef struct {
    char* array;
    int size;
} CharArray;

typedef struct {
    Point* array;
    int size;
} PointArray;

typedef struct {
    int** edges;
    int size;
} Graph;

typedef struct {
    int** edges;
    int size;
} Graph;

typedef struct {
    int* array;
    int size;
} IntArray;

typedef struct {
    double* array;
    int size;
} DoubleArray;

typedef struct {
    char* array;
    int size;
} CharArray;

typedef struct {
    Point* array;
    int size;
} PointArray;

typedef struct {
    int** edges;
    int size;
} Graph;

typedef struct {
    int** edges;
    int size;
} Graph;

typedef struct {
    int* array;
    int size;
} IntArray;

typedef struct {
    double* array;
    int size;
} DoubleArray;

typedef struct {
    char* array;
    int size;

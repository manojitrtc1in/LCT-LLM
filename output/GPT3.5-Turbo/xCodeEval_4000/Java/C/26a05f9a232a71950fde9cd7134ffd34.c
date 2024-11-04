#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>

#define MAX_STACK_SIZE 128

typedef struct {
    int value;
    int index;
} IntIndexPair;

typedef struct {
    int** edges;
    int size;
} GraphBuilder;

typedef struct {
    int row;
    int column;
} Point;

typedef struct {
    int* array;
    int size;
} IntArray;

typedef struct {
    long* array;
    int size;
} LongArray;

typedef struct {
    double* array;
    int size;
} DoubleArray;

typedef struct {
    char* array;
    int size;
} CharArray;

typedef struct {
    int* array;
    int rows;
    int columns;
} IntMatrix;

typedef struct {
    long* array;
    int rows;
    int columns;
} LongMatrix;

typedef struct {
    double* array;
    int rows;
    int columns;
} DoubleMatrix;

typedef struct {
    char* array;
    int rows;
    int columns;
} CharMatrix;

typedef struct {
    int* array;
    int length;
} IntList;

typedef struct {
    long* array;
    int length;
} LongList;

typedef struct {
    double* array;
    int length;
} DoubleList;

typedef struct {
    char* array;
    int length;
} CharList;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayList;

typedef struct {
    long* array;
    int size;
    int capacity;
} LongArrayList;

typedef struct {
    double* array;
    int size;
    int capacity;
} DoubleArrayList;

typedef struct {
    char* array;
    int size;
    int capacity;
} CharArrayList;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntQueue;

typedef struct {
    long* array;
    int size;
    int capacity;
} LongQueue;

typedef struct {
    double* array;
    int size;
    int capacity;
} DoubleQueue;

typedef struct {
    char* array;
    int size;
    int capacity;
} CharQueue;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntStack;

typedef struct {
    long* array;
    int size;
    int capacity;
} LongStack;

typedef struct {
    double* array;
    int size;
    int capacity;
} DoubleStack;

typedef struct {
    char* array;
    int size;
    int capacity;
} CharStack;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntHashSet;

typedef struct {
    long* array;
    int size;
    int capacity;
} LongHashSet;

typedef struct {
    double* array;
    int size;
    int capacity;
} DoubleHashSet;

typedef struct {
    char* array;
    int size;
    int capacity;
} CharHashSet;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntHashMap;

typedef struct {
    long* array;
    int size;
    int capacity;
} LongHashMap;

typedef struct {
    double* array;
    int size;
    int capacity;
} DoubleHashMap;

typedef struct {
    char* array;
    int size;
    int capacity;
} CharHashMap;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntMultiSet;

typedef struct {
    long* array;
    int size;
    int capacity;
} LongMultiSet;

typedef struct {
    double* array;
    int size;
    int capacity;
} DoubleMultiSet;

typedef struct {
    char* array;
    int size;
    int capacity;
} CharMultiSet;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntPriorityQueue;

typedef struct {
    long* array;
    int size;
    int capacity;
} LongPriorityQueue;

typedef struct {
    double* array;
    int size;
    int capacity;
} DoublePriorityQueue;

typedef struct {
    char* array;
    int size;
    int capacity;
} CharPriorityQueue;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntDeque;

typedef struct {
    long* array;
    int size;
    int capacity;
} LongDeque;

typedef struct {
    double* array;
    int size;
    int capacity;
} DoubleDeque;

typedef struct {
    char* array;
    int size;
    int capacity;
} CharDeque;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayQueue;

typedef struct {
    long* array;
    int size;
    int capacity;
} LongArrayQueue;

typedef struct {
    double* array;
    int size;
    int capacity;
} DoubleArrayQueue;

typedef struct {
    char* array;
    int size;
    int capacity;
} CharArrayQueue;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayStack;

typedef struct {
    long* array;
    int size;
    int capacity;
} LongArrayStack;

typedef struct {
    double* array;
    int size;
    int capacity;
} DoubleArrayStack;

typedef struct {
    char* array;
    int size;
    int capacity;
} CharArrayStack;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashSet;

typedef struct {
    long* array;
    int size;
    int capacity;
} LongArrayHashSet;

typedef struct {
    double* array;
    int size;
    int capacity;
} DoubleArrayHashSet;

typedef struct {
    char* array;
    int size;
    int capacity;
} CharArrayHashSet;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayHashMap;

typedef struct {
    long* array;
    int size;
    int capacity;
} LongArrayHashMap;

typedef struct {
    double* array;
    int size;
    int capacity;
} DoubleArrayHashMap;

typedef struct {
    char* array;
    int size;
    int capacity;
} CharArrayHashMap;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayMultiSet;

typedef struct {
    long* array;
    int size;
    int capacity;
} LongArrayMultiSet;

typedef struct {
    double* array;
    int size;
    int capacity;
} DoubleArrayMultiSet;

typedef struct {
    char* array;
    int size;
    int capacity;
} CharArrayMultiSet;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayPriorityQueue;

typedef struct {
    long* array;
    int size;
    int capacity;
} LongArrayPriorityQueue;

typedef struct {
    double* array;
    int size;
    int capacity;
} DoubleArrayPriorityQueue;

typedef struct {
    char* array;
    int size;
    int capacity;
} CharArrayPriorityQueue;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntArrayDeque;

typedef struct {
    long* array;
    int size;
    int capacity;
} LongArrayDeque;

typedef struct {
    double* array;
    int size;
    int capacity;
} DoubleArrayDeque;

typedef struct {
    char* array;
    int size;
    int capacity;
} CharArrayDeque;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntMatrixQueue;

typedef struct {
    long* array;
    int size;
    int capacity;
} LongMatrixQueue;

typedef struct {
    double* array;
    int size;
    int capacity;
} DoubleMatrixQueue;

typedef struct {
    char* array;
    int size;
    int capacity;
} CharMatrixQueue;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntMatrixStack;

typedef struct {
    long* array;
    int size;
    int capacity;
} LongMatrixStack;

typedef struct {
    double* array;
    int size;
    int capacity;
} DoubleMatrixStack;

typedef struct {
    char* array;
    int size;
    int capacity;
} CharMatrixStack;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntMatrixHashSet;

typedef struct {
    long* array;
    int size;
    int capacity;
} LongMatrixHashSet;

typedef struct {
    double* array;
    int size;
    int capacity;
} DoubleMatrixHashSet;

typedef struct {
    char* array;
    int size;
    int capacity;
} CharMatrixHashSet;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntMatrixHashMap;

typedef struct {
    long* array;
    int size;
    int capacity;
} LongMatrixHashMap;

typedef struct {
    double* array;
    int size;
    int capacity;
} DoubleMatrixHashMap;

typedef struct {
    char* array;
    int size;
    int capacity;
} CharMatrixHashMap;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntMatrixMultiSet;

typedef struct {
    long* array;
    int size;
    int capacity;
} LongMatrixMultiSet;

typedef struct {
    double* array;
    int size;
    int capacity;
} DoubleMatrixMultiSet;

typedef struct {
    char* array;
    int size;
    int capacity;
} CharMatrixMultiSet;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntMatrixPriorityQueue;

typedef struct {
    long* array;
    int size;
    int capacity;
} LongMatrixPriorityQueue;

typedef struct {
    double* array;
    int size;
    int capacity;
} DoubleMatrixPriorityQueue;

typedef struct {
    char* array;
    int size;
    int capacity;
} CharMatrixPriorityQueue;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntMatrixDeque;

typedef struct {
    long* array;
    int size;
    int capacity;
} LongMatrixDeque;

typedef struct {
    double* array;
    int size;
    int capacity;
} DoubleMatrixDeque;

typedef struct {
    char* array;
    int size;
    int capacity;
} CharMatrixDeque;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntMatrixArrayList;

typedef struct {
    long* array;
    int size;
    int capacity;
} LongMatrixArrayList;

typedef struct {
    double* array;
    int size;
    int capacity;
} DoubleMatrixArrayList;

typedef struct {
    char* array;
    int size;
    int capacity;
} CharMatrixArrayList;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntMatrixQueueArray;

typedef struct {
    long* array;
    int size;
    int capacity;
} LongMatrixQueueArray;

typedef struct {
    double* array;
    int size;
    int capacity;
} DoubleMatrixQueueArray;

typedef struct {
    char* array;
    int size;
    int capacity;
} CharMatrixQueueArray;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntMatrixStackArray;

typedef struct {
    long* array;
    int size;
    int capacity;
} LongMatrixStackArray;

typedef struct {
    double* array;
    int size;
    int capacity;
} DoubleMatrixStackArray;

typedef struct {
    char* array;
    int size;
    int capacity;
} CharMatrixStackArray;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntMatrixHashSetArray;

typedef struct {
    long* array;
    int size;
    int capacity;
} LongMatrixHashSetArray;

typedef struct {
    double* array;
    int size;
    int capacity;
} DoubleMatrixHashSetArray;

typedef struct {
    char* array;
    int size;
    int capacity;
} CharMatrixHashSetArray;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntMatrixHashMapArray;

typedef struct {
    long* array;
    int size;
    int capacity;
} LongMatrixHashMapArray;

typedef struct {
    double* array;
    int size;
    int capacity;
} DoubleMatrixHashMapArray;

typedef struct {
    char* array;
    int size;
    int capacity;
} CharMatrixHashMapArray;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntMatrixMultiSetArray;

typedef struct {
    long* array;
    int size;
    int capacity;
} LongMatrixMultiSetArray;

typedef struct {
    double* array;
    int size;
    int capacity;
} DoubleMatrixMultiSetArray;

typedef struct {
    char* array;
    int size;
    int capacity;
} CharMatrixMultiSetArray;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntMatrixPriorityQueueArray;

typedef struct {
    long* array;
    int size;
    int capacity;
} LongMatrixPriorityQueueArray;

typedef struct {
    double* array;
    int size;
    int capacity;
} DoubleMatrixPriorityQueueArray;

typedef struct {
    char* array;
    int size;
    int capacity;
} CharMatrixPriorityQueueArray;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntMatrixDequeArray;

typedef struct {
    long* array;
    int size;
    int capacity;
} LongMatrixDequeArray;

typedef struct {
    double* array;
    int size;
    int capacity;
} DoubleMatrixDequeArray;

typedef struct {
    char* array;
    int size;
    int capacity;
} CharMatrixDequeArray;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntMatrixArrayListArray;

typedef struct {
    long* array;
    int size;
    int capacity;
} LongMatrixArrayListArray;

typedef struct {
    double* array;
    int size;
    int capacity;
} DoubleMatrixArrayListArray;

typedef struct {
    char* array;
    int size;
    int capacity;
} CharMatrixArrayListArray;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntMatrixQueueArrayArray;

typedef struct {
    long* array;
    int size;
    int capacity;
} LongMatrixQueueArrayArray;

typedef struct {
    double* array;
    int size;
    int capacity;
} DoubleMatrixQueueArrayArray;

typedef struct {
    char* array;
    int size;
    int capacity;
} CharMatrixQueueArrayArray;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntMatrixStackArrayArray;

typedef struct {
    long* array;
    int size;
    int capacity;
} LongMatrixStackArrayArray;

typedef struct {
    double* array;
    int size;
    int capacity;
} DoubleMatrixStackArrayArray;

typedef struct {
    char* array;
    int size;
    int capacity;
} CharMatrixStackArrayArray;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntMatrixHashSetArrayArray;

typedef struct {
    long* array;
    int size;
    int capacity;
} LongMatrixHashSetArrayArray;

typedef struct {
    double* array;
    int size;
    int capacity;
} DoubleMatrixHashSetArrayArray;

typedef struct {
    char* array;
    int size;
    int capacity;
} CharMatrixHashSetArrayArray;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntMatrixHashMapArrayArray;

typedef struct {
    long* array;
    int size;
    int capacity;
} LongMatrixHashMapArrayArray;

typedef struct {
    double* array;
    int size;
    int capacity;
} DoubleMatrixHashMapArrayArray;

typedef struct {
    char* array;
    int size;
    int capacity;
} CharMatrixHashMapArrayArray;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntMatrixMultiSetArrayArray;

typedef struct {
    long* array;
    int size;
    int capacity;
} LongMatrixMultiSetArrayArray;

typedef struct {
    double* array;
    int size;
    int capacity;
} DoubleMatrixMultiSetArrayArray;

typedef struct {
    char* array;
    int size;
    int capacity;
} CharMatrixMultiSetArrayArray;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntMatrixPriorityQueueArrayArray;

typedef struct {
    long* array;
    int size;
    int capacity;
} LongMatrixPriorityQueueArrayArray;

typedef struct {
    double* array;
    int size;
    int capacity;
} DoubleMatrixPriorityQueueArrayArray;

typedef struct {
    char* array;
    int size;
    int capacity;
} CharMatrixPriorityQueueArrayArray;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntMatrixDequeArrayArray;

typedef struct {
    long* array;
    int size;
    int capacity;
} LongMatrixDequeArrayArray;

typedef struct {
    double* array;
    int size;
    int capacity;
} DoubleMatrixDequeArrayArray;

typedef struct {
    char* array;
    int size;
    int capacity;
} CharMatrixDequeArrayArray;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntMatrixArrayListArrayArray;

typedef struct {
    long* array;
    int size;
    int capacity;
} LongMatrixArrayListArrayArray;

typedef struct {
    double* array;
    int size;
    int capacity;
} DoubleMatrixArrayListArrayArray;

typedef struct {
    char* array;
    int size;
    int capacity;
} CharMatrixArrayListArrayArray;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntMatrixQueueArrayArrayArray;

typedef struct {
    long* array;
    int size;
    int capacity;
} LongMatrixQueueArrayArrayArray;

typedef struct {
    double* array;
    int size;
    int capacity;
} DoubleMatrixQueueArrayArrayArray;

typedef struct {
    char* array;
    int size;
    int capacity;
} CharMatrixQueueArrayArrayArray;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntMatrixStackArrayArrayArray;

typedef struct {
    long* array;
    int size;
    int capacity;
} LongMatrixStackArrayArrayArray;

typedef struct {
    double* array;
    int size;
    int capacity;
} DoubleMatrixStackArrayArrayArray;

typedef struct {
    char* array;
    int size;
    int capacity;
} CharMatrixStackArrayArrayArray;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntMatrixHashSetArrayArrayArray;

typedef struct {
    long* array;
    int size;
    int capacity;
} LongMatrixHashSetArrayArrayArray;

typedef struct {
    double* array;
    int size;
    int capacity;
} DoubleMatrixHashSetArrayArrayArray;

typedef struct {
    char* array;
    int size;
    int capacity;
} CharMatrixHashSetArrayArrayArray;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntMatrixHashMapArrayArrayArray;

typedef struct {
    long* array;
    int size;
    int capacity;
} LongMatrixHashMapArrayArrayArray;

typedef struct {
    double* array;
    int size;
    int capacity;
} DoubleMatrixHashMapArrayArrayArray;

typedef struct {
    char* array;
    int size;
    int capacity;
} CharMatrixHashMapArrayArrayArray;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntMatrixMultiSetArrayArrayArray;

typedef struct {
    long* array;
    int size;
    int capacity;
} LongMatrixMultiSetArrayArrayArray;

typedef struct {
    double* array;
    int size;
    int capacity;
} DoubleMatrixMultiSetArrayArrayArray;

typedef struct {
    char* array;
    int size;
    int capacity;
} CharMatrixMultiSetArrayArrayArray;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntMatrixPriorityQueueArrayArrayArray;

typedef struct {
    long* array;
    int size;
    int capacity;
} LongMatrixPriorityQueueArrayArrayArray;

typedef struct {
    double* array;
    int size;
    int capacity;
} DoubleMatrixPriorityQueueArrayArrayArray;

typedef struct {
    char* array;
    int size;
    int capacity;
} CharMatrixPriorityQueueArrayArrayArray;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntMatrixDequeArrayArrayArray;

typedef struct {
    long* array;
    int size;
    int capacity;
} LongMatrixDequeArrayArrayArray;

typedef struct {
    double* array;
    int size;
    int capacity;
} DoubleMatrixDequeArrayArrayArray;

typedef struct {
    char* array;
    int size;
    int capacity;
} CharMatrixDequeArrayArrayArray;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntMatrixArrayListArrayArrayArray;

typedef struct {
    long* array;
    int size;
    int capacity;
} LongMatrixArrayListArrayArrayArray;

typedef struct {
    double* array;
    int size;
    int capacity;
} DoubleMatrixArrayListArrayArrayArray;

typedef struct {
    char* array;
    int size;
    int capacity;
} CharMatrixArrayListArrayArrayArray;

typedef struct {
    int* array;
    int size;
    int capacity;

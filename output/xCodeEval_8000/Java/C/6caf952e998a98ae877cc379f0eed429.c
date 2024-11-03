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
} Vector;

typedef struct {
    int rowCount;
    int columnCount;
    int** data;
} BooleanMatrix;

typedef struct {
    double* elements;
    int* at;
    int size;
    int capacity;
} Heap;

void fft(double* a, double* b, int count, int invert);
void multiply(long* a, long* b, int size, long* result);
void shiftUp(Heap* heap, int index);
void shiftDown(Heap* heap, int index);
int add(Heap* heap, int element);
int poll(Heap* heap);
int peek(Heap* heap);
void clear(Heap* heap);

void fft(double* a, double* b, int count, int invert) {
    for (int i = 1, j = 0; i < count; i++) {
        int bit = count >> 1;
        for (; j >= bit; bit >>= 1)
            j -= bit;
        j += bit;
        if (i < j) {
            double temp = a[i];
            a[i] = a[j];
            a[j] = temp;
            temp = b[i];
            b[i] = b[j];
            b[j] = temp;
        }
    }
    for (int len = 2; len <= count; len <<= 1) {
        int halfLen = len >> 1;
        double angle = 2 * M_PI / len;
        if (invert)
            angle = -angle;
        double wLenA = cos(angle);
        double wLenB = sin(angle);
        for (int i = 0; i < count; i += len) {
            double wA = 1;
            double wB = 0;
            for (int j = 0; j < halfLen; j++) {
                double uA = a[i + j];
                double uB = b[i + j];
                double vA = a[i + j + halfLen] * wA - b[i + j + halfLen] * wB;
                double vB = a[i + j + halfLen] * wB + b[i + j + halfLen] * wA;
                a[i + j] = uA + vA;
                b[i + j] = uB + vB;
                a[i + j + halfLen] = uA - vA;
                b[i + j + halfLen] = uB - vB;
                double nextWA = wA * wLenA - wB * wLenB;
                wB = wA * wLenB + wB * wLenA;
                wA = nextWA;
            }
        }
    }
    if (invert) {
        for (int i = 0; i < count; i++) {
            a[i] /= count;
            b[i] /= count;
        }
    }
}

void multiply(long* a, long* b, int size, long* result) {
    int resultSize = 1;
    while (resultSize < size * 2)
        resultSize <<= 1;
    double* aReal = (double*)malloc(resultSize * sizeof(double));
    double* aImaginary = (double*)malloc(resultSize * sizeof(double));
    double* bReal = (double*)malloc(resultSize * sizeof(double));
    double* bImaginary = (double*)malloc(resultSize * sizeof(double));
    for (int i = 0; i < size; i++) {
        aReal[i] = a[i];
        aImaginary[i] = 0;
        bReal[i] = b[i];
        bImaginary[i] = 0;
    }
    for (int i = size; i < resultSize; i++) {
        aReal[i] = 0;
        aImaginary[i] = 0;
        bReal[i] = 0;
        bImaginary[i] = 0;
    }
    fft(aReal, aImaginary, resultSize, 0);
    if (a == b) {
        for (int i = 0; i < resultSize; i++) {
            bReal[i] = aReal[i];
            bImaginary[i] = aImaginary[i];
        }
    } else
        fft(bReal, bImaginary, resultSize, 0);
    for (int i = 0; i < resultSize; i++) {
        double real = aReal[i] * bReal[i] - aImaginary[i] * bImaginary[i];
        aImaginary[i] = aImaginary[i] * bReal[i] + bImaginary[i] * aReal[i];
        aReal[i] = real;
    }
    fft(aReal, aImaginary, resultSize, 1);
    for (int i = 0; i < size; i++)
        result[i] = round(aReal[i]);
    free(aReal);
    free(aImaginary);
    free(bReal);
    free(bImaginary);
}

void shiftUp(Heap* heap, int index) {
    int value = heap->elements[index];
    while (index != 0) {
        int parent = (index - 1) >> 1;
        int parentValue = heap->elements[parent];
        if (parentValue <= value) {
            heap->elements[index] = value;
            heap->at[value] = index;
            return;
        }
        heap->elements[index] = parentValue;
        heap->at[parentValue] = index;
        index = parent;
    }
    heap->elements[0] = value;
    heap->at[value] = 0;
}

void shiftDown(Heap* heap, int index) {
    while (1) {
        int child = (index << 1) + 1;
        if (child >= heap->size)
            return;
        if (child + 1 < heap->size && heap->elements[child] > heap->elements[child + 1])
            child++;
        if (heap->elements[index] <= heap->elements[child])
            return;
        int temp = heap->elements[index];
        heap->elements[index] = heap->elements[child];
        heap->elements[child] = temp;
        heap->at[heap->elements[index]] = index;
        heap->at[heap->elements[child]] = child;
        index = child;
    }
}

int add(Heap* heap, int element) {
    if (heap->size == heap->capacity) {
        int* oldElements = heap->elements;
        heap->elements = (int*)malloc(2 * heap->capacity * sizeof(int));
        for (int i = 0; i < heap->size; i++)
            heap->elements[i] = oldElements[i];
        free(oldElements);
        int* oldAt = heap->at;
        heap->at = (int*)malloc(2 * heap->capacity * sizeof(int));
        for (int i = 0; i < heap->capacity; i++)
            heap->at[i] = oldAt[i];
        free(oldAt);
        heap->capacity *= 2;
    }
    heap->elements[heap->size] = element;
    heap->at[element] = heap->size;
    shiftUp(heap, heap->size++);
    return heap->at[element];
}

int poll(Heap* heap) {
    int result = heap->elements[0];
    heap->at[result] = -1;
    if (heap->size == 1) {
        heap->size = 0;
        return result;
    }
    heap->elements[0] = heap->elements[--heap->size];
    heap->at[heap->elements[0]] = 0;
    shiftDown(heap, 0);
    return result;
}

int peek(Heap* heap) {
    return heap->elements[0];
}

void clear(Heap* heap) {
    heap->size = 0;
    for (int i = 0; i < heap->capacity; i++)
        heap->at[i] = -1;
}

int main() {
    printf("Hello world!\n");
    return 0;
}

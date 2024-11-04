#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_SIZE 1024
#define MOD 1000003

typedef struct {
    char *data;
    int size;
} StringBuilder;

typedef struct {
    int *data;
    int size;
    int capacity;
} IntArray;

typedef struct {
    int a, b;
} Pair;

typedef struct {
    int (*compare)(int, int);
} IntComparator;

typedef struct {
    int size;
    int *elements;
    int *at;
    IntComparator comparator;
} Heap;

void initStringBuilder(StringBuilder *sb) {
    sb->data = (char *)malloc(MAX_SIZE);
    sb->size = 0;
}

void append(StringBuilder *sb, const char *str) {
    int len = strlen(str);
    memcpy(sb->data + sb->size, str, len);
    sb->size += len;
    sb->data[sb->size] = '\0';
}

void freeStringBuilder(StringBuilder *sb) {
    free(sb->data);
}

void initIntArray(IntArray *arr, int capacity) {
    arr->data = (int *)malloc(capacity * sizeof(int));
    arr->size = 0;
    arr->capacity = capacity;
}

void addToIntArray(IntArray *arr, int value) {
    if (arr->size >= arr->capacity) {
        arr->capacity *= 2;
        arr->data = (int *)realloc(arr->data, arr->capacity * sizeof(int));
    }
    arr->data[arr->size++] = value;
}

void freeIntArray(IntArray *arr) {
    free(arr->data);
}

int compareDefault(int first, int second) {
    return (first < second) ? -1 : (first > second) ? 1 : 0;
}

void initHeap(Heap *heap, IntComparator comparator, int maxElement) {
    heap->size = 0;
    heap->elements = (int *)malloc(maxElement * sizeof(int));
    heap->at = (int *)malloc(maxElement * sizeof(int));
    for (int i = 0; i < maxElement; i++) {
        heap->at[i] = -1;
    }
    heap->comparator = comparator;
}

void shiftUp(Heap *heap, int index) {
    int value = heap->elements[index];
    while (index != 0) {
        int parent = (index - 1) / 2;
        int parentValue = heap->elements[parent];
        if (heap->comparator.compare(parentValue, value) <= 0) {
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

void addToHeap(Heap *heap, int element) {
    heap->elements[heap->size] = element;
    heap->at[element] = heap->size;
    shiftUp(heap, heap->size++);
}

void freeHeap(Heap *heap) {
    free(heap->elements);
    free(heap->at);
}

int main() {
    // Example usage of StringBuilder
    StringBuilder sb;
    initStringBuilder(&sb);
    append(&sb, "Hello, ");
    append(&sb, "World!");
    printf("%s\n", sb.data);
    freeStringBuilder(&sb);

    // Example usage of IntArray
    IntArray arr;
    initIntArray(&arr, 10);
    for (int i = 0; i < 15; i++) {
        addToIntArray(&arr, i);
    }
    for (int i = 0; i < arr.size; i++) {
        printf("%d ", arr.data[i]);
    }
    printf("\n");
    freeIntArray(&arr);

    // Example usage of Heap
    IntComparator comparator = {compareDefault};
    Heap heap;
    initHeap(&heap, comparator, 100);
    for (int i = 0; i < 10; i++) {
        addToHeap(&heap, i);
    }
    for (int i = 0; i < heap.size; i++) {
        printf("%d ", heap.elements[i]);
    }
    printf("\n");
    freeHeap(&heap);

    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_SIZE 1024
#define MOD 1000003

typedef struct {
    char *data;
    int size;
} String;

typedef struct {
    int *data;
    int size;
} IntArray;

typedef struct {
    int x;
    int y;
} Point;

typedef struct {
    int a;
    int b;
    int c;
} Line;

typedef struct {
    Point *vertices;
    int vertexCount;
} Polygon;

typedef struct {
    int *elements;
    int size;
    int capacity;
} Heap;

void initString(String *str) {
    str->data = (char *)malloc(MAX_SIZE);
    str->size = 0;
}

void appendString(String *str, char c) {
    str->data[str->size++] = c;
}

void freeString(String *str) {
    free(str->data);
}

void initIntArray(IntArray *arr, int size) {
    arr->data = (int *)malloc(size * sizeof(int));
    arr->size = size;
}

void freeIntArray(IntArray *arr) {
    free(arr->data);
}

void initHeap(Heap *heap, int capacity) {
    heap->elements = (int *)malloc(capacity * sizeof(int));
    heap->size = 0;
    heap->capacity = capacity;
}

void freeHeap(Heap *heap) {
    free(heap->elements);
}

void pushHeap(Heap *heap, int value) {
    if (heap->size == heap->capacity) {
        heap->capacity *= 2;
        heap->elements = (int *)realloc(heap->elements, heap->capacity * sizeof(int));
    }
    heap->elements[heap->size++] = value;
    // Shift up logic omitted for brevity
}

int popHeap(Heap *heap) {
    // Pop logic omitted for brevity
    return 0; // Placeholder
}

int countOddGroups(char *str) {
    int ret = 0, n = strlen(str), c = 0;
    for (int i = 1; i < n; i++) {
        if (str[i] != str[i - 1]) {
            ret += c % 2;
            c = 0;
        } else {
            c++;
        }
    }
    ret += c % 2;
    return ret;
}

int convertToBinary(String *str) {
    String ret;
    initString(&ret);
    for (int i = 0; i < str->size; i++) {
        char c = str->data[i];
        if (c == '>') appendString(&ret, '1'); // 1000
        else if (c == '<') appendString(&ret, '2'); // 1001
        else if (c == '+') appendString(&ret, '3'); // 1010
        else if (c == '-') appendString(&ret, '4'); // 1011
        else if (c == '.') appendString(&ret, '5'); // 1100
        else if (c == ',') appendString(&ret, '6'); // 1101
        else if (c == '[') appendString(&ret, '7'); // 1110
        else appendString(&ret, '8'); // 1111
    }
    int n = 0;
    for (int i = 0; i < ret.size; i++) {
        n = (2 * n + ret.data[i] - '0') % MOD;
    }
    freeString(&ret);
    return n;
}

int main() {
    char str[MAX_SIZE];
    scanf("%s", str);
    
    int resultA = countOddGroups(str);
    printf("%d\n", resultA);
    
    String inputStr;
    initString(&inputStr);
    for (int i = 0; str[i] != '\0'; i++) {
        appendString(&inputStr, str[i]);
    }
    
    int resultB = convertToBinary(&inputStr);
    printf("%d\n", resultB);
    
    freeString(&inputStr);
    return 0;
}

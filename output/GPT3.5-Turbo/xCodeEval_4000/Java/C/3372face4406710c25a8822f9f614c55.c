#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int* array;
    int size;
} IntArray;

typedef struct {
    int* array;
    int size;
    int capacity;
} IntList;

typedef struct {
    int value;
    bool valid;
} IntIterator;

typedef struct {
    int (*compare)(int, int);
} IntComparator;

IntArray* createIntArray(int size) {
    IntArray* array = (IntArray*)malloc(sizeof(IntArray));
    array->array = (int*)malloc(sizeof(int) * size);
    array->size = size;
    return array;
}

IntList* createIntList() {
    IntList* list = (IntList*)malloc(sizeof(IntList));
    list->array = (int*)malloc(sizeof(int) * 16);
    list->size = 0;
    list->capacity = 16;
    return list;
}

void addInt(IntList* list, int value) {
    if (list->size == list->capacity) {
        list->capacity *= 2;
        list->array = (int*)realloc(list->array, sizeof(int) * list->capacity);
    }
    list->array[list->size++] = value;
}

int getInt(IntList* list, int index) {
    return list->array[index];
}

void setInt(IntList* list, int index, int value) {
    list->array[index] = value;
}

int sizeIntList(IntList* list) {
    return list->size;
}

IntIterator* createIntIterator(IntList* list) {
    IntIterator* iterator = (IntIterator*)malloc(sizeof(IntIterator));
    iterator->value = list->array[0];
    iterator->valid = true;
    return iterator;
}

int nextInt(IntIterator* iterator) {
    int value = iterator->value;
    iterator->valid = false;
    return value;
}

bool hasNextInt(IntIterator* iterator) {
    return iterator->valid;
}

void advanceIntIterator(IntIterator* iterator) {
    iterator->valid = false;
}

void destroyIntIterator(IntIterator* iterator) {
    free(iterator);
}

int defaultIntComparator(int first, int second) {
    if (first < second)
        return -1;
    if (first > second)
        return 1;
    return 0;
}

IntList* sortIntList(IntList* list, IntComparator* comparator) {
    int size = sizeIntList(list);
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            if (comparator->compare(list->array[i], list->array[j]) > 0) {
                int temp = list->array[i];
                list->array[i] = list->array[j];
                list->array[j] = temp;
            }
        }
    }
    return list;
}

void shuffleIntList(IntList* list) {
    int size = sizeIntList(list);
    for (int i = 0; i < size; i++) {
        int index = rand() % (i + 1);
        int temp = list->array[i];
        list->array[i] = list->array[index];
        list->array[index] = temp;
    }
}

void solve(int testNumber, IntList* a, IntList* b, int count, int ones, long long x) {
    int* answer = (int*)malloc(sizeof(int) * count);
    int size = (count + 31) >> 5;
    int* ready = (int*)calloc(size, sizeof(int));
    int* mask = (int*)calloc(size, sizeof(int));
    for (int i = 0; i < size; i++) {
        for (int j = i * 32; j < (i + 1) * 32 && j < count; j++) {
            if (getInt(b, j) == 1) {
                mask[i] += 1 << (j - i * 32);
            }
        }
    }
    int** upMasks = (int**)malloc(sizeof(int*) * 32);
    int** downMasks = (int**)malloc(sizeof(int*) * 32);
    for (int i = 0; i < 32; i++) {
        int filter;
        if (i == 0) {
            filter = -1;
        } else {
            filter = (1 << (32 - i)) - 1;
        }
        int otherShift = 32 - i;
        upMasks[i] = (int*)malloc(sizeof(int) * size);
        downMasks[i] = (int*)malloc(sizeof(int) * size);
        for (int j = 0; j < size; j++) {
            upMasks[i][j] = mask[j] & filter;
            downMasks[i][j] = mask[j] >> otherShift;
        }
    }
    IntList* order = createIntList();
    for (int i = 0; i < count; i++) {
        addInt(order, i + 1);
    }
    shuffleIntList(order);
    for (int i = 0; i < count; i++) {
        int value = getInt(order, i);
        int shift = i & 31;
        int otherShift = 32 - shift;
        int filter;
        if (shift == 0) {
            filter = -1;
        } else {
            filter = (1 << (32 - shift)) - 1;
        }
        int start = i >> 5;
        int upTo = size - start - 1;
        int otherFilter = (1 << shift) - 1;
        if (otherFilter == -1) {
            otherFilter = 0;
        }
        for (int j = 0; j < upTo; j++) {
            if ((ready[j + start] >> shift & upMasks[shift][j]) != upMasks[shift][j]) {
                for (int k = (j + start) * 32 + shift; k < (j + start + 1) * 32 && k < count; k++) {
                    if (getInt(b, k - i) == 1 && answer[k] == 0) {
                        answer[k] = value;
                        ready[k >> 5] += 1 << (k & 31);
                    }
                }
            }
            if ((ready[j + start + 1] & downMasks[shift][j]) != downMasks[shift][j]) {
                for (int k = (j + start + 1) * 32; k < (j + start + 1) * 32 + shift && k < count; k++) {
                    if (getInt(b, k - i) == 1 && answer[k] == 0) {
                        answer[k] = value;
                        ready[k >> 5] += 1 << (k & 31);
                    }
                }
            }
        }
        if ((ready[upTo + start] >> shift & upMasks[shift][upTo]) != upMasks[shift][upTo]) {
            for (int k = (upTo + start) * 32 + shift; k < (upTo + start + 1) * 32 && k < count; k++) {
                if (getInt(b, k - i) == 1 && answer[k] == 0) {
                    answer[k] = value;
                    ready[k >> 5] += 1 << (k & 31);
                }
            }
        }
    }
    for (int i = 0; i < count; i++) {
        printf("%d ", answer[i]);
    }
    printf("\n");
}

int main() {
    int count, ones;
    long long x;
    scanf("%d %d %lld", &count, &ones, &x);
    IntList* a = createIntList();
    for (int i = 0; i < count; i++) {
        addInt(a, i + 1);
    }
    IntList* b = createIntList();
    for (int i = 0; i < count; i++) {
        if (i < ones) {
            addInt(b, 1);
        } else {
            addInt(b, 0);
        }
    }
    shuffleIntList(a);
    shuffleIntList(b);
    solve(1, a, b, count, ones, x);
    return 0;
}

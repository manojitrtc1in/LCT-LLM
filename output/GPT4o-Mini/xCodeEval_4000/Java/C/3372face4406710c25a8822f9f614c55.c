#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COUNT 100000
#define MAX_SIZE 32

typedef struct {
    int *array;
    int size;
} IntList;

typedef struct {
    int *array;
    int size;
} IntArray;

typedef struct {
    int *array;
    int size;
} IntSortedArray;

long x;

void shuffle(int count, int *a);
int next();
void solve(int count, int ones, long x);
void printArray(int *array, int size);
void reverse(int *array, int size);
int *createOrder(int size);
int *order(int *array, int size);
void fillArray(int *array, int size, int value);
void fillMask(int *mask, int *b, int count, int ones);
void fillUpDownMasks(int *mask, int size, int upMasks[MAX_SIZE][MAX_SIZE], int downMasks[MAX_SIZE][MAX_SIZE]);
void processOrder(int *a, int *b, int *answer, int *ready, int size, int upMasks[MAX_SIZE][MAX_SIZE], int downMasks[MAX_SIZE][MAX_SIZE]);

int main() {
    int count, ones;
    long x;
    scanf("%d %d %ld", &count, &ones, &x);
    solve(count, ones, x);
    return 0;
}

void solve(int count, int ones, long x) {
    int *a = (int *)malloc(count * sizeof(int));
    for (int i = 0; i < count; i++) {
        a[i] = i + 1;
    }
    shuffle(count, a);

    int *b = (int *)malloc(count * sizeof(int));
    fillArray(b, ones, 1);
    fillArray(b + ones, count - ones, 0);
    shuffle(count, b);

    int *answer = (int *)calloc(count, sizeof(int));
    int size = (count + 31) >> 5;
    int *ready = (int *)calloc(size, sizeof(int));
    int *mask = (int *)calloc(size, sizeof(int));
    fillMask(mask, b, count, ones);

    int upMasks[MAX_SIZE][MAX_SIZE];
    int downMasks[MAX_SIZE][MAX_SIZE];
    fillUpDownMasks(mask, size, upMasks, downMasks);

    int *orderArray = order(a, count);
    reverse(orderArray, count);

    processOrder(a, b, answer, ready, size, upMasks, downMasks);

    printArray(answer, count);

    free(a);
    free(b);
    free(answer);
    free(ready);
    free(mask);
    free(orderArray);
}

void fillArray(int *array, int size, int value) {
    for (int i = 0; i < size; i++) {
        array[i] = value;
    }
}

void fillMask(int *mask, int *b, int count, int ones) {
    for (int i = 0; i < (count + 31) >> 5; i++) {
        for (int j = i * 32; j < (i + 1) * 32 && j < count; j++) {
            if (b[j] == 1) {
                mask[i] += 1 << (j - i * 32);
            }
        }
    }
}

void fillUpDownMasks(int *mask, int size, int upMasks[MAX_SIZE][MAX_SIZE], int downMasks[MAX_SIZE][MAX_SIZE]) {
    for (int i = 0; i < MAX_SIZE; i++) {
        int filter = (i == 0) ? -1 : (1 << (32 - i)) - 1;
        int otherShift = 32 - i;
        for (int j = 0; j < size; j++) {
            upMasks[i][j] = mask[j] & filter;
            downMasks[i][j] = mask[j] >> otherShift;
        }
    }
}

void processOrder(int *a, int *b, int *answer, int *ready, int size, int upMasks[MAX_SIZE][MAX_SIZE], int downMasks[MAX_SIZE][MAX_SIZE]) {
    for (int i = 0; i < size; i++) {
        int value = a[i];
        int shift = i & 31;
        int otherShift = 32 - shift;
        int filter = (shift == 0) ? -1 : (1 << (32 - shift)) - 1;
        int start = i >> 5;
        int upTo = size - start - 1;
        int otherFilter = (1 << shift) - 1;
        if (otherFilter == -1) {
            otherFilter = 0;
        }
        for (int j = 0; j < upTo; j++) {
            if ((ready[j + start] >> shift & upMasks[shift][j]) != upMasks[shift][j]) {
                for (int k = (j + start) * 32 + shift; k < (j + start + 1) * 32 && k < count; k++) {
                    if (b[k - i] == 1 && answer[k] == 0) {
                        answer[k] = value;
                        ready[k >> 5] += 1 << (k & 31);
                    }
                }
            }
            if ((ready[j + start + 1] & downMasks[shift][j]) != downMasks[shift][j]) {
                for (int k = (j + start + 1) * 32; k < (j + start + 1) * 32 + shift && k < count; k++) {
                    if (b[k - i] == 1 && answer[k] == 0) {
                        answer[k] = value;
                        ready[k >> 5] += 1 << (k & 31);
                    }
                }
            }
        }
        if ((ready[upTo + start] >> shift & upMasks[shift][upTo]) != upMasks[shift][upTo]) {
            for (int k = (upTo + start) * 32 + shift; k < (upTo + start + 1) * 32 && k < count; k++) {
                if (b[k - i] == 1 && answer[k] == 0) {
                    answer[k] = value;
                    ready[k >> 5] += 1 << (k & 31);
                }
            }
        }
    }
}

void printArray(int *array, int size) {
    for (int i = 0; i < size; i++) {
        if (i != 0) {
            printf(" ");
        }
        printf("%d", array[i]);
    }
    printf("\n");
}

void reverse(int *array, int size) {
    for (int i = 0, j = size - 1; i < j; i++, j--) {
        int temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }
}

int *createOrder(int size) {
    int *order = (int *)malloc(size * sizeof(int));
    for (int i = 0; i < size; i++) {
        order[i] = i;
    }
    return order;
}

int *order(int *array, int size) {
    int *orderArray = createOrder(size);
    // Sorting logic can be added here if needed
    return orderArray;
}

void shuffle(int count, int *a) {
    for (int i = 0; i < count; i++) {
        int index = next() % (i + 1);
        int temp = a[i];
        a[i] = a[index];
        a[index] = temp;
    }
}

int next() {
    x = (x * 37 + 10007) % 1000000007;
    return (int)x;
}

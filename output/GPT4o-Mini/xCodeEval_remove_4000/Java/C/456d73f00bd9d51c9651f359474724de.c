#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <string.h>

#define MOD 1000000007

typedef struct {
    long *elements;
    int size;
    int capacity;
} ElementCounter;

typedef struct {
    long *elements;
    int size;
    int capacity;
} StringCounter;

typedef struct {
    long *d;
    int size;
} id36;

typedef struct {
    long *original;
    long *bottomUp;
    long *topDown;
    long n;
} id4;

void initElementCounter(ElementCounter *counter) {
    counter->capacity = 10;
    counter->size = 0;
    counter->elements = (long *)malloc(counter->capacity * sizeof(long));
}

void addElement(ElementCounter *counter, long element) {
    if (counter->size >= counter->capacity) {
        counter->capacity *= 2;
        counter->elements = (long *)realloc(counter->elements, counter->capacity * sizeof(long));
    }
    counter->elements[counter->size++] = element;
}

void removeElement(ElementCounter *counter, long element) {
    for (int i = 0; i < counter->size; i++) {
        if (counter->elements[i] == element) {
            counter->elements[i] = counter->elements[--counter->size];
            return;
        }
    }
}

int getElementCount(ElementCounter *counter, long element) {
    int count = 0;
    for (int i = 0; i < counter->size; i++) {
        if (counter->elements[i] == element) {
            count++;
        }
    }
    return count;
}

void initStringCounter(StringCounter *counter) {
    counter->capacity = 10;
    counter->size = 0;
    counter->elements = (long *)malloc(counter->capacity * sizeof(long));
}

void addString(StringCounter *counter, const char *identifier) {
    if (counter->size >= counter->capacity) {
        counter->capacity *= 2;
        counter->elements = (long *)realloc(counter->elements, counter->capacity * sizeof(long));
    }
    counter->elements[counter->size++] = atol(identifier);
}

long getStringCount(StringCounter *counter, const char *identifier) {
    for (int i = 0; i < counter->size; i++) {
        if (counter->elements[i] == atol(identifier)) {
            return counter->elements[i];
        }
    }
    return 0;
}

void setID4(id4 *tree, int n) {
    tree->n = n;
    tree->original = (long *)malloc((n + 2) * sizeof(long));
    tree->bottomUp = (long *)malloc((n + 2) * sizeof(long));
    tree->topDown = (long *)malloc((n + 2) * sizeof(long));
}

void setElement(id4 *tree, int modifiedNode, long value) {
    long replaced = tree->original[modifiedNode];
    tree->original[modifiedNode] = value;

    // Bottom-up update
    int i = modifiedNode;
    long v = value;
    while (i <= tree->n) {
        if (v > tree->bottomUp[i]) {
            if (replaced == tree->bottomUp[i]) {
                v = fmin(v, tree->original[i]);
                for (int r = 1; ; r++) {
                    int x = (i & -i) >> r;
                    if (x == 0) break;
                    int child = i - x;
                    v = fmin(v, tree->bottomUp[child]);
                }
            } else break;
        }
        if (v == tree->bottomUp[i]) break;
        tree->bottomUp[i] = v;
        i += (i & -i);
    }

    // Top-down update
    i = modifiedNode;
    v = value;
    while (i > 0) {
        if (v > tree->topDown[i]) {
            if (replaced == tree->topDown[i]) {
                v = fmin(v, tree->original[i]);
                for (int r = 1; ; r++) {
                    int x = (i & -i) >> r;
                    if (x == 0) break;
                    int child = i + x;
                    if (child > tree->n + 1) break;
                    v = fmin(v, tree->topDown[child]);
                }
            } else break;
        }
        if (v == tree->topDown[i]) break;
        tree->topDown[i] = v;
        i -= (i & -i);
    }
}

long getMin(id4 *tree, int a, int b) {
    long min = tree->original[a];
    int prev = a;
    int curr = prev + (prev & -prev);

    while (curr <= b) {
        min = fmin(min, tree->topDown[prev]);
        prev = curr;
        curr = prev + (prev & -prev);
    }
    min = fmin(min, tree->original[prev]);
    prev = b;
    curr = prev - (prev & -prev);

    while (curr >= a) {
        min = fmin(min, tree->bottomUp[prev]);
        prev = curr;
        curr = prev - (prev & -prev);
    }
    return min;
}

int main() {
    // Example usage
    ElementCounter counter;
    initElementCounter(&counter);
    addElement(&counter, 5);
    addElement(&counter, 10);
    printf("Count of 5: %d\n", getElementCount(&counter, 5));
    
    StringCounter strCounter;
    initStringCounter(&strCounter);
    addString(&strCounter, "hello");
    printf("Count of hello: %ld\n", getStringCount(&strCounter, "hello"));

    id4 tree;
    setID4(&tree, 10);
    setElement(&tree, 5, 20);
    printf("Min between 1 and 5: %ld\n", getMin(&tree, 1, 5));

    // Free allocated memory
    free(counter.elements);
    free(strCounter.elements);
    free(tree.original);
    free(tree.bottomUp);
    free(tree.topDown);

    return 0;
}

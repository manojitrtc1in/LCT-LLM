#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int* data;
    int size;
    int capacity;
} IntArrayList;

IntArrayList* createIntArrayList() {
    IntArrayList* list = (IntArrayList*)malloc(sizeof(IntArrayList));
    list->data = (int*)malloc(sizeof(int) * 3);
    list->size = 0;
    list->capacity = 3;
    return list;
}

void ensureCapacity(IntArrayList* list, int capacity) {
    if (list->capacity >= capacity) {
        return;
    }
    capacity = (list->capacity * 2 > capacity) ? list->capacity * 2 : capacity;
    list->data = (int*)realloc(list->data, sizeof(int) * capacity);
    list->capacity = capacity;
}

void add(IntArrayList* list, int value) {
    ensureCapacity(list, list->size + 1);
    list->data[list->size] = value;
    list->size++;
}

int get(IntArrayList* list, int index) {
    if (index >= list->size || index < 0) {
        printf("Index out of bounds\n");
        exit(1);
    }
    return list->data[index];
}

void set(IntArrayList* list, int index, int value) {
    if (index >= list->size || index < 0) {
        printf("Index out of bounds\n");
        exit(1);
    }
    list->data[index] = value;
}

void addAt(IntArrayList* list, int index, int value) {
    ensureCapacity(list, list->size + 1);
    if (index > list->size || index < 0) {
        printf("Index out of bounds\n");
        exit(1);
    }
    for (int i = list->size; i > index; i--) {
        list->data[i] = list->data[i - 1];
    }
    list->data[index] = value;
    list->size++;
}

void removeAt(IntArrayList* list, int index) {
    if (index >= list->size || index < 0) {
        printf("Index out of bounds\n");
        exit(1);
    }
    for (int i = index; i < list->size - 1; i++) {
        list->data[i] = list->data[i + 1];
    }
    list->size--;
}

void swap(IntArrayList* list, int first, int second) {
    if (first == second) {
        return;
    }
    int temp = list->data[first];
    list->data[first] = list->data[second];
    list->data[second] = temp;
}

typedef struct {
    IntArrayList* list;
    int at;
    bool removed;
} IntIterator;

IntIterator* createIntIterator(IntArrayList* list) {
    IntIterator* iterator = (IntIterator*)malloc(sizeof(IntIterator));
    iterator->list = list;
    iterator->at = 0;
    iterator->removed = false;
    return iterator;
}

int value(IntIterator* iterator) {
    if (iterator->removed) {
        printf("Illegal state\n");
        exit(1);
    }
    return get(iterator->list, iterator->at);
}

bool advance(IntIterator* iterator) {
    iterator->at++;
    iterator->removed = false;
    return isValid(iterator);
}

bool isValid(IntIterator* iterator) {
    return !iterator->removed && iterator->at < iterator->list->size;
}

void remove(IntIterator* iterator) {
    removeAt(iterator->list, iterator->at);
    iterator->at--;
    iterator->removed = true;
}

typedef struct {
    IntIterator* (*intIterator)(IntArrayList*);
} IntCollection;

IntIterator* intIterator(IntArrayList* list) {
    return createIntIterator(list);
}

typedef struct {
    int* data;
    int size;
} IntArray;

IntArray* createIntArray(int size) {
    IntArray* array = (IntArray*)malloc(sizeof(IntArray));
    array->data = (int*)malloc(sizeof(int) * size);
    array->size = size;
    return array;
}

IntArray* range(int from, int to) {
    int size = abs(from - to);
    IntArray* array = createIntArray(size);
    int current = from;
    if (from <= to) {
        for (int i = 0; i < size; i++) {
            array->data[i] = current++;
        }
    } else {
        for (int i = 0; i < size; i++) {
            array->data[i] = current--;
        }
    }
    return array;
}

typedef struct {
    int* data;
    int size;
    int capacity;
} IntStack;

IntStack* createIntStack() {
    IntStack* stack = (IntStack*)malloc(sizeof(IntStack));
    stack->data = (int*)malloc(sizeof(int) * 3);
    stack->size = 0;
    stack->capacity = 3;
    return stack;
}

void ensureCapacityStack(IntStack* stack, int capacity) {
    if (stack->capacity >= capacity) {
        return;
    }
    capacity = (stack->capacity * 2 > capacity) ? stack->capacity * 2 : capacity;
    stack->data = (int*)realloc(stack->data, sizeof(int) * capacity);
    stack->capacity = capacity;
}

void push(IntStack* stack, int value) {
    ensureCapacityStack(stack, stack->size + 1);
    stack->data[stack->size] = value;
    stack->size++;
}

int pop(IntStack* stack) {
    if (stack->size == 0) {
        printf("Stack is empty\n");
        exit(1);
    }
    stack->size--;
    return stack->data[stack->size];
}

int top(IntStack* stack) {
    if (stack->size == 0) {
        printf("Stack is empty\n");
        exit(1);
    }
    return stack->data[stack->size - 1];
}

bool isEmpty(IntStack* stack) {
    return stack->size == 0;
}

typedef struct {
    int* data;
    int size;
    int capacity;
} IntQueue;

IntQueue* createIntQueue() {
    IntQueue* queue = (IntQueue*)malloc(sizeof(IntQueue));
    queue->data = (int*)malloc(sizeof(int) * 3);
    queue->size = 0;
    queue->capacity = 3;
    return queue;
}

void ensureCapacityQueue(IntQueue* queue, int capacity) {
    if (queue->capacity >= capacity) {
        return;
    }
    capacity = (queue->capacity * 2 > capacity) ? queue->capacity * 2 : capacity;
    queue->data = (int*)realloc(queue->data, sizeof(int) * capacity);
    queue->capacity = capacity;
}

void enqueue(IntQueue* queue, int value) {
    ensureCapacityQueue(queue, queue->size + 1);
    queue->data[queue->size] = value;
    queue->size++;
}

int dequeue(IntQueue* queue) {
    if (queue->size == 0) {
        printf("Queue is empty\n");
        exit(1);
    }
    int value = queue->data[0];
    for (int i = 1; i < queue->size; i++) {
        queue->data[i - 1] = queue->data[i];
    }
    queue->size--;
    return value;
}

int front(IntQueue* queue) {
    if (queue->size == 0) {
        printf("Queue is empty\n");
        exit(1);
    }
    return queue->data[0];
}

bool isEmptyQueue(IntQueue* queue) {
    return queue->size == 0;
}

typedef struct {
    IntArrayList* list;
} IntReversableCollection;

typedef struct {
    IntArrayList* list;
} IntList;

IntList* createIntList() {
    IntList* list = (IntList*)malloc(sizeof(IntList));
    list->list = createIntArrayList();
    return list;
}

int size(IntList* list) {
    return list->list->size;
}

int getFromList(IntList* list, int index) {
    return get(list->list, index);
}

void setToList(IntList* list, int index, int value) {
    set(list->list, index, value);
}

void addToList(IntList* list, int value) {
    add(list->list, value);
}

void addAtToList(IntList* list, int index, int value) {
    addAt(list->list, index, value);
}

void removeFromList(IntList* list, int index) {
    removeAt(list->list, index);
}

void swapInList(IntList* list, int first, int second) {
    swap(list->list, first, second);
}

IntIterator* iterator(IntList* list) {
    return intIterator(list->list);
}

typedef struct {
    IntList* list;
    IntIterator* iterator;
    bool removed;
} IntStream;

IntStream* createIntStream(IntList* list) {
    IntStream* stream = (IntStream*)malloc(sizeof(IntStream));
    stream->list = list;
    stream->iterator = iterator(list);
    stream->removed = false;
    return stream;
}

int valueStream(IntStream* stream) {
    if (stream->removed) {
        printf("Illegal state\n");
        exit(1);
    }
    return value(stream->iterator);
}

bool advanceStream(IntStream* stream) {
    stream->removed = false;
    return advance(stream->iterator);
}

bool isValidStream(IntStream* stream) {
    return !stream->removed && isValid(stream->iterator);
}

void removeStream(IntStream* stream) {
    remove(stream->iterator);
    stream->removed = true;
}

typedef struct {
    IntStream* (*intIterator)(IntList*);
} IntCollectionStream;

IntStream* intIteratorStream(IntList* list) {
    return createIntStream(list);
}

typedef struct {
    IntList* list;
    int at;
    bool removed;
} IntArrayIterator;

IntArrayIterator* createIntArrayIterator(IntList* list) {
    IntArrayIterator* iterator = (IntArrayIterator*)malloc(sizeof(IntArrayIterator));
    iterator->list = list;
    iterator->at = 0;
    iterator->removed = false;
    return iterator;
}

int valueArrayIterator(IntArrayIterator* iterator) {
    if (iterator->removed) {
        printf("Illegal state\n");
        exit(1);
    }
    return getFromList(iterator->list, iterator->at);
}

bool advanceArrayIterator(IntArrayIterator* iterator) {
    iterator->at++;
    iterator->removed = false;
    return isValidArrayIterator(iterator);
}

bool isValidArrayIterator(IntArrayIterator* iterator) {
    return !iterator->removed && iterator->at < size(iterator->list);
}

void removeArrayIterator(IntArrayIterator* iterator) {
    removeFromList(iterator->list, iterator->at);
    iterator->at--;
    iterator->removed = true;
}

typedef struct {
    IntArrayIterator* (*intIterator)(IntList*);
} IntArrayCollection;

IntArrayIterator* intIteratorArray(IntList* list) {
    return createIntArrayIterator(list);
}

typedef struct {
    int* data;
    int size;
} IntArray;

IntArray* createIntArray(int size) {
    IntArray* array = (IntArray*)malloc(sizeof(IntArray));
    array->data = (int*)malloc(sizeof(int) * size);
    array->size = size;
    return array;
}

IntArray* range(int from, int to) {
    int size = abs(from - to);
    IntArray* array = createIntArray(size);
    int current = from;
    if (from <= to) {
        for (int i = 0; i < size; i++) {
            array->data[i] = current++;
        }
    } else {
        for (int i = 0; i < size; i++) {
            array->data[i] = current--;
        }
    }
    return array;
}

typedef struct {
    IntArray* array;
    int at;
    bool removed;
} IntArrayIterator;

IntArrayIterator* createIntArrayIterator(IntArray* array) {
    IntArrayIterator* iterator = (IntArrayIterator*)malloc(sizeof(IntArrayIterator));
    iterator->array = array;
    iterator->at = 0;
    iterator->removed = false;
    return iterator;
}

int valueArrayIterator(IntArrayIterator* iterator) {
    if (iterator->removed) {
        printf("Illegal state\n");
        exit(1);
    }
    return iterator->array->data[iterator->at];
}

bool advanceArrayIterator(IntArrayIterator* iterator) {
    iterator->at++;
    iterator->removed = false;
    return isValidArrayIterator(iterator);
}

bool isValidArrayIterator(IntArrayIterator* iterator) {
    return !iterator->removed && iterator->at < iterator->array->size;
}

void removeArrayIterator(IntArrayIterator* iterator) {
    iterator->array->size--;
    for (int i = iterator->at; i < iterator->array->size; i++) {
        iterator->array->data[i] = iterator->array->data[i + 1];
    }
    iterator->at--;
    iterator->removed = true;
}

typedef struct {
    IntArrayIterator* (*intIterator)(IntArray*);
} IntArrayCollection;

IntArrayIterator* intIteratorArray(IntArray* array) {
    return createIntArrayIterator(array);
}

typedef struct {
    int* data;
    int size;
    int capacity;
} IntStack;

IntStack* createIntStack() {
    IntStack* stack = (IntStack*)malloc(sizeof(IntStack));
    stack->data = (int*)malloc(sizeof(int) * 3);
    stack->size = 0;
    stack->capacity = 3;
    return stack;
}

void ensureCapacityStack(IntStack* stack, int capacity) {
    if (stack->capacity >= capacity) {
        return;
    }
    capacity = (stack->capacity * 2 > capacity) ? stack->capacity * 2 : capacity;
    stack->data = (int*)realloc(stack->data, sizeof(int) * capacity);
    stack->capacity = capacity;
}

void push(IntStack* stack, int value) {
    ensureCapacityStack(stack, stack->size + 1);
    stack->data[stack->size] = value;
    stack->size++;
}

int pop(IntStack* stack) {
    if (stack->size == 0) {
        printf("Stack is empty\n");
        exit(1);
    }
    stack->size--;
    return stack->data[stack->size];
}

int top(IntStack* stack) {
    if (stack->size == 0) {
        printf("Stack is empty\n");
        exit(1);
    }
    return stack->data[stack->size - 1];
}

bool isEmpty(IntStack* stack) {
    return stack->size == 0;
}

typedef struct {
    int* data;
    int size;
    int capacity;
} IntQueue;

IntQueue* createIntQueue() {
    IntQueue* queue = (IntQueue*)malloc(sizeof(IntQueue));
    queue->data = (int*)malloc(sizeof(int) * 3);
    queue->size = 0;
    queue->capacity = 3;
    return queue;
}

void ensureCapacityQueue(IntQueue* queue, int capacity) {
    if (queue->capacity >= capacity) {
        return;
    }
    capacity = (queue->capacity * 2 > capacity) ? queue->capacity * 2 : capacity;
    queue->data = (int*)realloc(queue->data, sizeof(int) * capacity);
    queue->capacity = capacity;
}

void enqueue(IntQueue* queue, int value) {
    ensureCapacityQueue(queue, queue->size + 1);
    queue->data[queue->size] = value;
    queue->size++;
}

int dequeue(IntQueue* queue) {
    if (queue->size == 0) {
        printf("Queue is empty\n");
        exit(1);
    }
    int value = queue->data[0];
    for (int i = 1; i < queue->size; i++) {
        queue->data[i - 1] = queue->data[i];
    }
    queue->size--;
    return value;
}

int front(IntQueue* queue) {
    if (queue->size == 0) {
        printf("Queue is empty\n");
        exit(1);
    }
    return queue->data[0];
}

bool isEmptyQueue(IntQueue* queue) {
    return queue->size == 0;
}

typedef struct {
    IntArrayList* list;
} IntReversableCollection;

typedef struct {
    IntArrayList* list;
} IntList;

IntList* createIntList() {
    IntList* list = (IntList*)malloc(sizeof(IntList));
    list->list = createIntArrayList();
    return list;
}

int size(IntList* list) {
    return list->list->size;
}

int getFromList(IntList* list, int index) {
    return get(list->list, index);
}

void setToList(IntList* list, int index, int value) {
    set(list->list, index, value);
}

void addToList(IntList* list, int value) {
    add(list->list, value);
}

void addAtToList(IntList* list, int index, int value) {
    addAt(list->list, index, value);
}

void removeFromList(IntList* list, int index) {
    removeAt(list->list, index);
}

void swapInList(IntList* list, int first, int second) {
    swap(list->list, first, second);
}

IntIterator* iterator(IntList* list) {
    return intIterator(list->list);
}

typedef struct {
    IntList* list;
    IntIterator* iterator;
    bool removed;
} IntStream;

IntStream* createIntStream(IntList* list) {
    IntStream* stream = (IntStream*)malloc(sizeof(IntStream));
    stream->list = list;
    stream->iterator = iterator(list);
    stream->removed = false;
    return stream;
}

int valueStream(IntStream* stream) {
    if (stream->removed) {
        printf("Illegal state\n");
        exit(1);
    }
    return value(stream->iterator);
}

bool advanceStream(IntStream* stream) {
    stream->removed = false;
    return advance(stream->iterator);
}

bool isValidStream(IntStream* stream) {
    return !stream->removed && isValid(stream->iterator);
}

void removeStream(IntStream* stream) {
    remove(stream->iterator);
    stream->removed = true;
}

typedef struct {
    IntStream* (*intIterator)(IntList*);
} IntCollectionStream;

IntStream* intIteratorStream(IntList* list) {
    return createIntStream(list);
}

typedef struct {
    IntList* list;
    int at;
    bool removed;
} IntArrayIterator;

IntArrayIterator* createIntArrayIterator(IntList* list) {
    IntArrayIterator* iterator = (IntArrayIterator*)malloc(sizeof(IntArrayIterator));
    iterator->list = list;
    iterator->at = 0;
    iterator->removed = false;
    return iterator;
}

int valueArrayIterator(IntArrayIterator* iterator) {
    if (iterator->removed) {
        printf("Illegal state\n");
        exit(1);
    }
    return getFromList(iterator->list, iterator->at);
}

bool advanceArrayIterator(IntArrayIterator* iterator) {
    iterator->at++;
    iterator->removed = false;
    return isValidArrayIterator(iterator);
}

bool isValidArrayIterator(IntArrayIterator* iterator) {
    return !iterator->removed && iterator->at < size(iterator->list);
}

void removeArrayIterator(IntArrayIterator* iterator) {
    removeFromList(iterator->list, iterator->at);
    iterator->at--;
    iterator->removed = true;
}

typedef struct {
    IntArrayIterator* (*intIterator)(IntList*);
} IntArrayCollection;

IntArrayIterator* intIteratorArray(IntList* list) {
    return createIntArrayIterator(list);
}

typedef struct {
    int* data;
    int size;
} IntArray;

IntArray* createIntArray(int size) {
    IntArray* array = (IntArray*)malloc(sizeof(IntArray));
    array->data = (int*)malloc(sizeof(int) * size);
    array->size = size;
    return array;
}

IntArray* range(int from, int to) {
    int size = abs(from - to);
    IntArray* array = createIntArray(size);
    int current = from;
    if (from <= to) {
        for (int i = 0; i < size; i++) {
            array->data[i] = current++;
        }
    } else {
        for (int i = 0; i < size; i++) {
            array->data[i] = current--;
        }
    }
    return array;
}

typedef struct {
    IntArray* array;
    int at;
    bool removed;
} IntArrayIterator;

IntArrayIterator* createIntArrayIterator(IntArray* array) {
    IntArrayIterator* iterator = (IntArrayIterator*)malloc(sizeof(IntArrayIterator));
    iterator->array = array;
    iterator->at = 0;
    iterator->removed = false;
    return iterator;
}

int valueArrayIterator(IntArrayIterator* iterator) {
    if (iterator->removed) {
        printf("Illegal state\n");
        exit(1);
    }
    return iterator->array->data[iterator->at];
}

bool advanceArrayIterator(IntArrayIterator* iterator) {
    iterator->at++;
    iterator->removed = false;
    return isValidArrayIterator(iterator);
}

bool isValidArrayIterator(IntArrayIterator* iterator) {
    return !iterator->removed && iterator->at < iterator->array->size;
}

void removeArrayIterator(IntArrayIterator* iterator) {
    iterator->array->size--;
    for (int i = iterator->at; i < iterator->array->size; i++) {
        iterator->array->data[i] = iterator->array->data[i + 1];
    }
    iterator->at--;
    iterator->removed = true;
}

typedef struct {
    IntArrayIterator* (*intIterator)(IntArray*);
} IntArrayCollection;

IntArrayIterator* intIteratorArray(IntArray* array) {
    return createIntArrayIterator(array);
}

typedef struct {
    int* data;
    int size;
    int capacity;
} IntStack;

IntStack* createIntStack() {
    IntStack* stack = (IntStack*)malloc(sizeof(IntStack));
    stack->data = (int*)malloc(sizeof(int) * 3);
    stack->size = 0;
    stack->capacity = 3;
    return stack;
}

void ensureCapacityStack(IntStack* stack, int capacity) {
    if (stack->capacity >= capacity) {
        return;
    }
    capacity = (stack->capacity * 2 > capacity) ? stack->capacity * 2 : capacity;
    stack->data = (int*)realloc(stack->data, sizeof(int) * capacity);
    stack->capacity = capacity;
}

void push(IntStack* stack, int value) {
    ensureCapacityStack(stack, stack->size + 1);
    stack->data[stack->size] = value;
    stack->size++;
}

int pop(IntStack* stack) {
    if (stack->size == 0) {
        printf("Stack is empty\n");
        exit(1);
    }
    stack->size--;
    return stack->data[stack->size];
}

int top(IntStack* stack) {
    if (stack->size == 0) {
        printf("Stack is empty\n");
        exit(1);
    }
    return stack->data[stack->size - 1];
}

bool isEmpty(IntStack* stack) {
    return stack->size == 0;
}

typedef struct {
    int* data;
    int size;
    int capacity;
} IntQueue;

IntQueue* createIntQueue() {
    IntQueue* queue = (IntQueue*)malloc(sizeof(IntQueue));
    queue->data = (int*)malloc(sizeof(int) * 3);
    queue->size = 0;
    queue->capacity = 3;
    return queue;
}

void ensureCapacityQueue(IntQueue* queue, int capacity) {
    if (queue->capacity >= capacity) {
        return;
    }
    capacity = (queue->capacity * 2 > capacity) ? queue->capacity * 2 : capacity;
    queue->data = (int*)realloc(queue->data, sizeof(int) * capacity);
    queue->capacity = capacity;
}

void enqueue(IntQueue* queue, int value) {
    ensureCapacityQueue(queue, queue->size + 1);
    queue->data[queue->size] = value;
    queue->size++;
}

int dequeue(IntQueue* queue) {
    if (queue->size == 0) {
        printf("Queue is empty\n");
        exit(1);
    }
    int value = queue->data[0];
    for (int i = 1; i < queue->size; i++) {
        queue->data[i - 1] = queue->data[i];
    }
    queue->size--;
    return value;
}

int front(IntQueue* queue) {
    if (queue->size == 0) {
        printf("Queue is empty\n");
        exit(1);
    }
    return queue->data[0];
}

bool isEmptyQueue(IntQueue* queue) {
    return queue->size == 0;
}

typedef struct {
    IntArrayList* list;
} IntReversableCollection;

typedef struct {
    IntArrayList* list;
} IntList;

IntList* createIntList() {
    IntList* list = (IntList*)malloc(sizeof(IntList));
    list->list = createIntArrayList();
    return list;
}

int size(IntList* list) {
    return list->list->size;
}

int getFromList(IntList* list, int index) {
    return get(list->list, index);
}

void setToList(IntList* list, int index, int value) {
    set(list->list, index, value);
}

void addToList(IntList* list, int value) {
    add(list->list, value);
}

void addAtToList(IntList* list, int index, int value) {
    addAt(list->list, index, value);
}

void removeFromList(IntList* list, int index) {
    removeAt(list->list, index);
}

void swapInList(IntList* list, int first, int second) {
    swap(list->list, first, second);
}

IntIterator* iterator(IntList* list) {
    return intIterator(list->list);
}

typedef struct {
    IntList* list;
    IntIterator* iterator;
    bool removed;
} IntStream;

IntStream* createIntStream(IntList* list) {
    IntStream* stream = (IntStream*)malloc(sizeof(IntStream));
    stream->list = list;
    stream->iterator = iterator(list);
    stream->removed = false;
    return stream;
}

int valueStream(IntStream* stream) {
    if (stream->removed) {
        printf("Illegal state\n");
        exit(1);
    }
    return value(stream->iterator);
}

bool advanceStream(IntStream* stream) {
    stream->removed = false;
    return advance(stream->iterator);
}

bool isValidStream(IntStream* stream) {
    return !stream->removed && isValid(stream->iterator);
}

void removeStream(IntStream* stream) {
    remove(stream->iterator);
    stream->removed = true;
}

typedef struct {
    IntStream* (*intIterator)(IntList*);
} IntCollectionStream;

IntStream* intIteratorStream(IntList* list) {
    return createIntStream(list);
}

typedef struct {
    IntList* list;
    int at;
    bool removed;
} IntArrayIterator;

IntArrayIterator* createIntArrayIterator(IntList* list) {
    IntArrayIterator* iterator = (IntArrayIterator*)malloc(sizeof(IntArrayIterator));
    iterator->list = list;
    iterator->at = 0;
    iterator->removed = false;
    return iterator;
}

int valueArrayIterator(IntArrayIterator* iterator) {
    if (iterator->removed) {
        printf("Illegal state\n");
        exit(1);
    }
    return getFromList(iterator->list, iterator->at);
}

bool advanceArrayIterator(IntArrayIterator* iterator) {
    iterator->at++;
    iterator->removed = false;
    return isValidArrayIterator(iterator);
}

bool isValidArrayIterator(IntArrayIterator* iterator) {
    return !iterator->removed && iterator->at < size(iterator->list);
}

void removeArrayIterator(IntArrayIterator* iterator) {
    removeFromList(iterator->list, iterator->at);
    iterator->at--;
    iterator->removed = true;
}

typedef struct {
    IntArrayIterator* (*intIterator)(IntList*);
} IntArrayCollection;

IntArrayIterator* intIteratorArray(IntList* list) {
    return createIntArrayIterator(list);
}

typedef struct {
    int* data;
    int size;
} IntArray;

IntArray* createIntArray(int size) {
    IntArray* array = (IntArray*)malloc(sizeof(IntArray));
    array->data = (int*)malloc(sizeof(int) * size);
    array->size = size;
    return array;
}

IntArray* range(int from, int to) {
    int size = abs(from - to);
    IntArray* array = createIntArray(size);
    int current = from;
    if (from <= to) {
        for (int i = 0; i < size; i++) {
            array->data[i] = current++;
        }
    } else {
        for (int i = 0; i < size; i++) {
            array->data[i] = current--;
        }
    }
    return array;
}

typedef struct {
    IntArray* array;
    int at;
    bool removed;
} IntArrayIterator;

IntArrayIterator* createIntArrayIterator(IntArray* array) {
    IntArrayIterator* iterator = (IntArrayIterator*)malloc(sizeof(IntArrayIterator));
    iterator->array = array;
    iterator->at = 0;
    iterator->removed = false;
    return iterator;
}

int valueArrayIterator(IntArrayIterator* iterator) {
    if (iterator->removed) {
        printf("Illegal state\n");
        exit(1);
    }
    return iterator->array->data[iterator->at];
}

bool advanceArrayIterator(IntArrayIterator* iterator) {
    iterator->at++;
    iterator->removed = false;
    return isValidArrayIterator(iterator);
}

bool isValidArrayIterator(IntArrayIterator* iterator) {
    return !iterator->removed && iterator->at < iterator->array->size;
}

void removeArrayIterator(IntArrayIterator* iterator) {
    iterator->array->size--;
    for (int i = iterator->at; i < iterator->array->size; i++) {
        iterator->array->data[i] = iterator->array->data[i + 1];
    }
    iterator->at--;
    iterator->removed = true;
}

typedef struct {
    IntArrayIterator* (*intIterator)(IntArray*);
} IntArrayCollection;

IntArrayIterator* intIteratorArray(IntArray* array) {
    return createIntArrayIterator(array);
}

typedef struct {
    int* data;
    int size;
    int capacity;
} IntStack;

IntStack* createIntStack() {
    IntStack* stack = (IntStack*)malloc(sizeof(IntStack));
    stack->data = (int*)malloc(sizeof(int) * 3);
    stack->size = 0;
    stack->capacity = 3;
    return stack;
}

void ensureCapacityStack(IntStack* stack, int capacity) {
    if (stack->capacity >= capacity) {
        return;
    }
    capacity = (stack->capacity * 2 > capacity) ? stack->capacity * 2 : capacity;
    stack->data = (int*)realloc(stack->data, sizeof(int) * capacity);
    stack->capacity = capacity;
}

void push(IntStack* stack, int value) {
    ensureCapacityStack(stack, stack->size + 1);
    stack->data[stack->size] = value;
    stack->size++;
}

int pop(IntStack* stack) {
    if (stack->size == 0) {
        printf("Stack is empty\n");
        exit(1);
    }
    stack->size--;
    return stack->data[stack->size];
}

int top(IntStack* stack) {
    if (stack->size == 0) {
        printf("Stack is empty\n");
        exit(1);
    }
    return stack->data[stack->size - 1];
}

bool isEmpty(IntStack* stack) {
    return stack->size == 0;
}

typedef struct {
    int* data;
    int size;
    int capacity;
} IntQueue;

IntQueue* createIntQueue() {
    IntQueue* queue = (IntQueue*)malloc(sizeof(IntQueue));
    queue->data = (int*)malloc(sizeof(int) * 3);
    queue->size = 0;
    queue->capacity = 3;
    return queue;
}

void ensureCapacityQueue(IntQueue* queue, int capacity) {
    if (queue->capacity >= capacity) {
        return;
    }
    capacity = (queue->capacity * 2 > capacity) ? queue->capacity * 2 : capacity;
    queue->data = (int*)realloc(queue->data, sizeof(int) * capacity);
    queue->capacity = capacity;
}

void enqueue(IntQueue* queue, int value) {
    ensureCapacityQueue(queue, queue->size + 1);
    queue->data[queue->size] = value;
    queue->size++;
}

int dequeue(IntQueue* queue) {
    if (queue->size == 0) {
        printf("Queue is empty\n");
        exit(1);
    }
    int value = queue->data[0];
    for (int i = 1; i < queue->size; i++) {
        queue->data[i - 1] = queue->data[i];
    }
    queue->size--;
    return value;
}

int front(IntQueue* queue) {
    if (queue->size == 0) {
        printf("Queue is empty\n");
        exit(1);
    }
    return queue->data[0];
}

bool isEmptyQueue(IntQueue* queue) {
    return queue->size == 0;
}

typedef struct {
    IntArrayList* list;
} IntReversableCollection;

typedef struct {
    IntArrayList* list;
} IntList;

IntList* createIntList() {
    IntList* list = (IntList*)malloc(sizeof(IntList));
    list->list = createIntArrayList();
    return list;
}

int size(IntList* list) {
    return list->list->size;
}

int getFromList(IntList* list, int index) {
    return get(list->list, index);
}

void setToList(IntList* list, int index, int value) {
    set(list->list, index, value);
}

void addToList(IntList* list, int value) {
    add(list->list, value);
}

void addAtToList(IntList* list, int index, int value) {
    addAt(list->list, index, value);
}

void removeFromList(IntList* list, int index) {
    removeAt(list->list, index);
}

void swapInList(IntList* list, int first, int second) {
    swap(list->list, first, second);
}

IntIterator* iterator(IntList* list) {
    return intIterator(list->list);
}

typedef struct {
    IntList* list;
    IntIterator* iterator;
    bool removed;
} IntStream;

IntStream* createIntStream(IntList* list) {
    IntStream* stream = (IntStream*)malloc(sizeof(IntStream));
    stream->list = list;
    stream->iterator = iterator(list);
    stream->removed = false;
    return stream;
}

int valueStream(IntStream* stream) {
    if (stream->removed) {
        printf("Illegal state\n");
        exit(1);
    }
    return value(stream->iterator);
}

bool advanceStream(IntStream* stream) {
    stream->removed = false;
    return advance(stream->iterator);
}

bool isValidStream(IntStream* stream) {
    return !stream->removed && isValid(stream->iterator);
}

void removeStream(IntStream* stream) {
    remove(stream->iterator);
    stream->removed = true;
}

typedef struct {
    IntStream* (*intIterator)(IntList*);
} IntCollectionStream;

IntStream* intIteratorStream(IntList* list) {
    return createIntStream(list);
}

typedef struct {
    IntList* list;
    int at;
    bool removed;
} IntArrayIterator;

IntArrayIterator* createIntArrayIterator(IntList* list) {
    IntArrayIterator* iterator = (IntArrayIterator*)malloc(sizeof(IntArrayIterator));
    iterator->list = list;
    iterator->at = 0;
    iterator->removed = false;
    return iterator;
}

int valueArrayIterator(IntArrayIterator* iterator) {
    if (iterator->removed) {
        printf("Illegal state\n");
        exit(1);
    }
    return getFromList(iterator->list, iterator->at);
}

bool advanceArrayIterator(IntArrayIterator* iterator) {
    iterator->at++;
    iterator->removed = false;
    return isValidArrayIterator(iterator);
}

bool isValidArrayIterator(IntArrayIterator* iterator) {
    return !iterator->removed && iterator->at < size(iterator->list);
}

void removeArrayIterator(IntArrayIterator* iterator) {
    removeFromList(iterator->list, iterator->at);
    iterator->at--;
    iterator->removed = true;
}

typedef struct {
    IntArrayIterator* (*intIterator)(IntList*);
} IntArrayCollection;

IntArrayIterator* intIteratorArray(IntList* list) {
    return createIntArrayIterator(list);
}

typedef struct {
    int* data;
    int size;
} IntArray;

IntArray* createIntArray(int size) {
    IntArray* array = (IntArray*)malloc(sizeof(IntArray));
    array->data = (int*)malloc(sizeof(int) * size);
    array->size = size;
    return array;
}

IntArray* range(int from, int to) {
    int size = abs(from - to);
    IntArray* array = createIntArray(size);
    int current = from;
    if (from <= to) {
        for (int i = 0; i < size; i++) {
            array->data[i] = current++;
        }
    } else {
        for (int i = 0; i < size; i++) {
            array->data[i] = current--;
        }
    }
    return array;
}

typedef struct {
    IntArray* array;
    int at;
    bool removed;
} IntArrayIterator;

IntArrayIterator* createIntArrayIterator(IntArray* array) {
    IntArrayIterator* iterator = (IntArrayIterator*)malloc(sizeof(IntArrayIterator));
    iterator->array = array;
    iterator->at = 0;
    iterator->removed = false;
    return iterator;
}

int valueArrayIterator(IntArrayIterator* iterator) {
    if (iterator->removed) {
        printf("Illegal state\n");
        exit(1);
    }
    return iterator->array->data[iterator->at];
}

bool advanceArrayIterator(IntArrayIterator* iterator) {
    iterator->at++;
    iterator->removed = false;
    return isValidArrayIterator(iterator);
}

bool isValidArrayIterator(IntArrayIterator* iterator) {
    return !iterator->removed && iterator->at < iterator->array->size;
}

void removeArrayIterator(IntArrayIterator* iterator) {
    iterator->array->size--;
    for (int i = iterator->at; i < iterator->array->size; i++) {
        iterator->array->data[i] = iterator->array->data[i + 1];
    }
    iterator->at--;
    iterator->removed = true;
}

typedef struct {
    IntArrayIterator* (*intIterator)(IntArray*);
} IntArrayCollection;

IntArrayIterator* intIteratorArray(IntArray* array) {
    return createIntArrayIterator(array);
}

typedef struct {
    int* data;
    int size;
} IntArray;

IntArray* createIntArray(int size) {
    IntArray* array = (IntArray*)malloc(sizeof(IntArray));
    array->data = (int*)malloc(sizeof(int) * size);
    array->size = size;
    return array;
}

IntArray* range(int from, int to) {
    int size = abs(from - to);
    IntArray* array = createIntArray(size);
    int current = from;
    if (from <= to) {
        for (int i = 0; i < size; i++) {
            array->data[i] = current++;
        }
    } else {
        for (int i = 0; i < size; i++) {
            array->data[i] = current--;
        }
    }
    return array;
}

typedef struct {
    IntArray* array;
    int at;
    bool removed;
} IntArrayIterator;

IntArrayIterator* createIntArrayIterator(IntArray* array) {
    IntArrayIterator* iterator = (IntArrayIterator*)malloc(sizeof(IntArrayIterator));
    iterator->array = array;
    iterator->at = 0;
    iterator->removed = false;
    return iterator;
}

int valueArrayIterator(IntArrayIterator* iterator) {
    if (iterator->removed) {
        printf("Illegal state\n");
        exit(1);
    }
    return iterator->array->data[iterator->at];
}

bool advanceArrayIterator(IntArrayIterator* iterator) {
    iterator->at++;
    iterator->removed = false;
    return isValidArrayIterator(iterator);
}

bool isValidArrayIterator(IntArrayIterator* iterator) {
    return !iterator->removed && iterator->at < iterator->array->size;
}

void removeArrayIterator(IntArrayIterator* iterator) {
    iterator->array->size--;
    for (int i = iterator->at; i < iterator->array->size; i++) {
        iterator->array->data[i] = iterator->array->data[i + 1];
    }
    iterator->at--;
    iterator->removed = true;
}

typedef struct {
    IntArrayIterator* (*intIterator)(IntArray*);
} IntArrayCollection;

IntArrayIterator* intIteratorArray(IntArray* array) {
    return createIntArrayIterator(array);
}

typedef struct {
    int* data;
    int size;
} IntArray;

IntArray* createIntArray(int size) {
    IntArray* array = (IntArray*)malloc(sizeof(IntArray));
    array->data = (int*)malloc(sizeof(int) * size);
    array->size = size;
    return array;
}

IntArray* range(int from, int to) {
    int size = abs(from - to);
    IntArray* array = createIntArray(size);
    int current = from;
    if (from <= to) {
        for (int i = 0; i < size; i++) {
            array->data[i] = current++;
        }
    } else {
        for (int i = 0; i < size; i++) {
            array->data[i] = current--;
        }
    }
    return array;
}

typedef struct {
    IntArray* array;
    int at;
    bool removed;
} IntArrayIterator;

IntArrayIterator* createIntArrayIterator(IntArray* array) {
    IntArrayIterator* iterator = (IntArrayIterator*)malloc(sizeof(IntArrayIterator));
    iterator->array = array;
    iterator->at = 0;
    iterator->removed = false;
    return iterator;
}

int valueArrayIterator(IntArrayIterator* iterator) {
    if (iterator->removed) {
        printf("Illegal state\n");
        exit(1);
    }
    return iterator->array->data[iterator->at];
}

bool advanceArrayIterator(IntArrayIterator* iterator) {
    iterator->at++;
    iterator->removed = false;
    return isValidArrayIterator(iterator);
}

bool isValidArrayIterator(IntArrayIterator* iterator) {
    return !iterator->removed && iterator->at < iterator->array->size;
}

void removeArrayIterator(IntArrayIterator* iterator) {
    iterator->array->size--;
    for (int i = iterator->at; i < iterator->array->size; i++) {
        iterator->array->data[i] = iterator->array->data[i + 1];
    }
    iterator->at--;
    iterator->removed = true;
}

typedef struct {
    IntArrayIterator* (*intIterator)(IntArray*);
} IntArrayCollection;

IntArrayIterator* intIteratorArray(IntArray* array) {
    return createIntArrayIterator(array);
}

typedef struct {
    int* data;
    int size;
} IntArray;

IntArray* createIntArray(int size) {
    IntArray* array = (IntArray*)malloc(sizeof(IntArray));
    array->data = (int*)malloc(sizeof(int) * size);
    array->size = size;
    return array;
}

IntArray* range(int from, int to) {
    int size = abs(from - to);
    IntArray* array = createIntArray(size);
    int current = from;
    if (from <= to) {
        for (int i = 0; i < size; i++) {
            array->data[i] = current++;
        }
    } else {
        for (int i = 0; i < size; i++) {
            array->data[i] = current--;
        }
    }
    return array;
}

typedef struct {
    IntArray* array;
    int at;
    bool removed;
} IntArrayIterator;

IntArrayIterator* createIntArrayIterator(IntArray* array) {
    IntArrayIterator* iterator = (IntArrayIterator*)malloc(sizeof(IntArrayIterator));
    iterator->array = array;
    iterator->at = 0;
    iterator->removed = false;
    return iterator;
}

int valueArrayIterator(IntArrayIterator* iterator) {
    if (iterator->removed) {
        printf("Illegal state\n");
        exit(1);
    }
    return iterator->array->data[iterator->at];
}

bool advanceArrayIterator(IntArrayIterator* iterator) {
    iterator->at++;
    iterator->removed = false;
    return isValidArrayIterator(iterator);
}

bool isValidArrayIterator(IntArrayIterator* iterator) {
    return !iterator->removed && iterator->at < iterator->array->size;
}

void removeArrayIterator(IntArrayIterator* iterator) {
    iterator->array->size--;
    for (int i = iterator->at; i < iterator->array->size; i++) {
        iterator->array->data[i] = iterator->array->data[i + 1];
    }
    iterator->at--;
    iterator->removed = true;
}

typedef struct {
    IntArrayIterator* (*intIterator)(IntArray*);
} IntArrayCollection;

IntArrayIterator* intIteratorArray(IntArray* array) {
    return createIntArrayIterator(array);
}

typedef struct {
    int* data;
    int size;
} IntArray;

IntArray* createIntArray(int size) {
    IntArray* array = (IntArray*)malloc(sizeof(IntArray));
    array->data = (int*)malloc(sizeof(int) * size);
    array->size = size;
    return array;
}

IntArray* range(int from, int to) {
    int size = abs(from - to);
    IntArray* array = createIntArray(size);
    int current = from;
    if (from <= to) {
        for (int i = 0; i < size; i++) {
            array->data[i] = current++;
        }
    } else {
        for (int i = 0; i < size; i++) {
            array->data[i] = current--;
        }
    }
    return array;
}

typedef struct {
    IntArray* array;
    int at;
    bool removed;
} IntArrayIterator;

IntArrayIterator* createIntArrayIterator(IntArray* array) {
    IntArrayIterator* iterator = (IntArrayIterator*)malloc(sizeof(IntArrayIterator));
    iterator->array = array;
    iterator->at = 0;
    iterator->removed = false;
    return iterator;
}

int valueArrayIterator(IntArrayIterator* iterator) {
    if (iterator->removed) {
        printf("Illegal state\n");
        exit(1);
    }
    return iterator->array->data[iterator->at];
}

bool advanceArrayIterator(IntArrayIterator* iterator) {
    iterator->at++;
    iterator->removed = false;
    return isValidArrayIterator(iterator);
}

bool isValidArrayIterator(IntArrayIterator* iterator) {
    return !iterator->removed && iterator->at < iterator->array->size;
}

void removeArrayIterator(IntArrayIterator* iterator) {
    iterator->array->size--;
    for (int i = iterator->at; i < iterator->array->size; i++) {
        iterator->array->data[i] = iterator->array->data[i + 1];
    }
    iterator->at--;
    iterator->removed = true;
}

typedef struct {
    IntArrayIterator* (*intIterator)(IntArray*);
} IntArrayCollection;

IntArrayIterator* intIteratorArray(IntArray* array) {
    return createIntArrayIterator(array);
}

typedef struct {
    int* data;
    int size;
} IntArray;

IntArray* createIntArray(int size) {
    IntArray* array = (IntArray*)malloc(sizeof(IntArray));
    array->data = (int*)malloc(sizeof(int) * size);
    array->size = size;
    return array;
}

IntArray* range(int from, int to) {
    int size = abs(from - to);
    IntArray* array = createIntArray(size);
    int current = from;
    if (from <= to) {
        for (int i = 0; i < size; i++) {
            array->data[i] = current++;
        }
    } else {
        for (int i = 0; i < size; i++) {
            array->data[i] = current--;
        }
    }
    return array;
}

typedef struct {
    IntArray* array;
    int at;
    bool removed;
} IntArrayIterator;

IntArrayIterator* createIntArrayIterator(IntArray* array) {
    IntArrayIterator* iterator = (IntArrayIterator*)malloc(sizeof(IntArrayIterator));
    iterator->array = array;
    iterator->at = 0;
    iterator->removed = false;
    return iterator;
}

int valueArrayIterator(IntArrayIterator* iterator) {
    if (iterator->removed) {
        printf("Illegal state\n");
        exit(1);
    }
    return iterator->array->data[iterator->at];
}

bool advanceArrayIterator(IntArrayIterator* iterator) {
    iterator->at++;
    iterator->removed = false;
    return isValidArrayIterator(iterator);
}

bool isValidArrayIterator(IntArrayIterator* iterator) {
    return !iterator->removed && iterator->at < iterator->array->size;
}

void removeArrayIterator(IntArrayIterator* iterator) {
    iterator->array->size--;
    for (int i = iterator->at; i < iterator->array->size; i++) {
        iterator->array->data[i] = iterator->array->data[i + 1];
    }
    iterator->at--;
    iterator->removed = true;
}

typedef struct {
    IntArrayIterator* (*intIterator)(IntArray*);
} IntArrayCollection;

IntArrayIterator* intIteratorArray(IntArray* array) {
    return createIntArrayIterator(array);
}

typedef struct {
    int* data;
    int size;
} IntArray;

IntArray* createIntArray(int size) {
    IntArray* array = (IntArray*)malloc(sizeof(IntArray));
    array->data = (int*)malloc(sizeof(int) * size);
    array->size = size;
    return array;
}

IntArray* range(int from, int to) {
    int size = abs(from - to);
    IntArray* array = createIntArray(size);
    int current = from;
    if (from <= to) {
        for (int i = 0; i < size; i++) {
            array->data[i] = current++;
        }
    } else {
        for (int i = 0; i < size; i++) {
            array->data[i] = current--;
        }
    }
    return array;
}

typedef struct {
    IntArray* array;
    int at;
    bool removed;
} IntArrayIterator;

IntArrayIterator* createIntArrayIterator(IntArray* array) {
    IntArrayIterator* iterator = (IntArrayIterator*)malloc(sizeof(IntArrayIterator));
    iterator->array = array;
    iterator->at = 0;
    iterator->removed = false;
    return iterator;
}

int valueArrayIterator(IntArrayIterator* iterator) {
    if (iterator->removed) {
        printf("Illegal state\n");
        exit(1);
    }
    return iterator->array->data[iterator->at];
}

bool advanceArrayIterator(IntArrayIterator* iterator) {
    iterator->at++;
    iterator->removed = false;
    return isValidArrayIterator(iterator);
}

bool isValidArrayIterator(IntArrayIterator* iterator) {
    return !iterator->removed && iterator->at < iterator->array->size;
}

void removeArrayIterator(IntArrayIterator* iterator) {
    iterator->array->size--;
    for (int i = iterator->at; i < iterator->array->size; i++) {
        iterator->array->data[i] = iterator->array->data[i + 1];
    }
    iterator->at--;
    iterator->removed = true;
}

typedef struct {
    IntArrayIterator* (*intIterator)(IntArray*);
} IntArrayCollection;

IntArrayIterator* intIteratorArray(IntArray* array) {
    return createIntArrayIterator(array);
}

typedef struct {
    int* data;
    int size;
} IntArray;

IntArray* createIntArray(int size) {
    IntArray* array = (IntArray*)malloc(sizeof(IntArray));
    array->data = (int*)malloc(sizeof(int) * size);
    array->size = size;
    return array;
}

IntArray* range(int from, int to) {
    int size = abs(from - to);
    IntArray* array = createIntArray(size);
    int current = from;
    if (from <= to) {
        for (int i = 0; i < size; i++) {
            array->data[i] = current++;
        }
    } else {
        for (int i = 0; i < size; i++) {
            array->data[i] = current--;
        }
    }
    return array;
}

typedef struct {
    IntArray* array;
    int at;
    bool removed;
} IntArrayIterator;

IntArrayIterator* createIntArrayIterator(IntArray* array) {
    IntArrayIterator* iterator = (IntArrayIterator*)malloc(sizeof(IntArrayIterator));
    iterator->array = array;
    iterator->at = 0;
    iterator->removed = false;
    return iterator;
}

int valueArrayIterator(IntArrayIterator* iterator) {
    if (iterator->removed) {
        printf("Illegal state\n");
        exit(1);
    }
    return iterator->array->data[iterator->at];
}

bool advanceArrayIterator(IntArrayIterator* iterator) {
    iterator->at++;
    iterator->removed = false;
    return isValidArrayIterator(iterator);
}

bool isValidArrayIterator(IntArrayIterator* iterator) {
    return !iterator->removed && iterator->at < iterator->array->size;
}

void removeArrayIterator(IntArrayIterator* iterator) {
    iterator->array->size--;
    for (int i = iterator->at; i < iterator->array->size; i++) {
        iterator->array->data[i] = iterator->array->data[i + 1];
    }
    iterator->at--;
    iterator->removed = true;
}

typedef struct {
    IntArrayIterator* (*intIterator)(IntArray*);
} IntArrayCollection;

IntArrayIterator* intIteratorArray(IntArray* array) {
    return createIntArrayIterator(array);
}

typedef struct {
    int* data;
    int size;
} IntArray;

IntArray* createIntArray(int size) {
    IntArray* array = (IntArray*)malloc(sizeof(IntArray));
    array->data = (int*)malloc(sizeof(int) * size);
    array->size = size;
    return array;
}

IntArray* range(int from, int to) {
    int size = abs(from - to);
    IntArray* array = createIntArray(size);
    int current = from;
    if (from <= to) {

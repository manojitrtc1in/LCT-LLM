#include <stdio.h>
#include <stdlib.h>

#define MOD 998244353
#define ROOT 646108188
#define ROOT_INV 208611436
#define ORDER 8388608

typedef struct {
    int* arr;
    int size;
    int capacity;
} IntArray;

typedef struct {
    long* arr;
    int size;
    int capacity;
} LongArray;

typedef struct {
    int* arr;
    int size;
    int capacity;
} BoolArray;

typedef struct {
    int** arr;
    int rows;
    int cols;
} IntMatrix;

typedef struct {
    long** arr;
    int rows;
    int cols;
} LongMatrix;

typedef struct {
    int** arr;
    int size;
    int capacity;
} IntMatrixArray;

typedef struct {
    long** arr;
    int size;
    int capacity;
} LongMatrixArray;

typedef struct {
    int** arr;
    int size;
    int capacity;
} IntMatrix2DArray;

typedef struct {
    long** arr;
    int size;
    int capacity;
} LongMatrix2DArray;

IntArray* newIntArray() {
    IntArray* array = (IntArray*)malloc(sizeof(IntArray));
    array->arr = (int*)malloc(sizeof(int) * 10);
    array->size = 0;
    array->capacity = 10;
    return array;
}

void addInt(IntArray* array, int value) {
    if (array->size == array->capacity) {
        array->capacity *= 2;
        array->arr = (int*)realloc(array->arr, sizeof(int) * array->capacity);
    }
    array->arr[array->size++] = value;
}

LongArray* newLongArray() {
    LongArray* array = (LongArray*)malloc(sizeof(LongArray));
    array->arr = (long*)malloc(sizeof(long) * 10);
    array->size = 0;
    array->capacity = 10;
    return array;
}

void addLong(LongArray* array, long value) {
    if (array->size == array->capacity) {
        array->capacity *= 2;
        array->arr = (long*)realloc(array->arr, sizeof(long) * array->capacity);
    }
    array->arr[array->size++] = value;
}

BoolArray* newBoolArray() {
    BoolArray* array = (BoolArray*)malloc(sizeof(BoolArray));
    array->arr = (int*)malloc(sizeof(int) * 10);
    array->size = 0;
    array->capacity = 10;
    return array;
}

void addBool(BoolArray* array, int value) {
    if (array->size == array->capacity) {
        array->capacity *= 2;
        array->arr = (int*)realloc(array->arr, sizeof(int) * array->capacity);
    }
    array->arr[array->size++] = value;
}

IntMatrix* newIntMatrix(int rows, int cols) {
    IntMatrix* matrix = (IntMatrix*)malloc(sizeof(IntMatrix));
    matrix->arr = (int**)malloc(sizeof(int*) * rows);
    for (int i = 0; i < rows; i++) {
        matrix->arr[i] = (int*)malloc(sizeof(int) * cols);
    }
    matrix->rows = rows;
    matrix->cols = cols;
    return matrix;
}

LongMatrix* newLongMatrix(int rows, int cols) {
    LongMatrix* matrix = (LongMatrix*)malloc(sizeof(LongMatrix));
    matrix->arr = (long**)malloc(sizeof(long*) * rows);
    for (int i = 0; i < rows; i++) {
        matrix->arr[i] = (long*)malloc(sizeof(long) * cols);
    }
    matrix->rows = rows;
    matrix->cols = cols;
    return matrix;
}

IntMatrixArray* newIntMatrixArray() {
    IntMatrixArray* array = (IntMatrixArray*)malloc(sizeof(IntMatrixArray));
    array->arr = (int**)malloc(sizeof(int*) * 10);
    array->size = 0;
    array->capacity = 10;
    return array;
}

void addIntMatrix(IntMatrixArray* array, int** matrix) {
    if (array->size == array->capacity) {
        array->capacity *= 2;
        array->arr = (int**)realloc(array->arr, sizeof(int*) * array->capacity);
    }
    array->arr[array->size++] = matrix;
}

LongMatrixArray* newLongMatrixArray() {
    LongMatrixArray* array = (LongMatrixArray*)malloc(sizeof(LongMatrixArray));
    array->arr = (long**)malloc(sizeof(long*) * 10);
    array->size = 0;
    array->capacity = 10;
    return array;
}

void addLongMatrix(LongMatrixArray* array, long** matrix) {
    if (array->size == array->capacity) {
        array->capacity *= 2;
        array->arr = (long**)realloc(array->arr, sizeof(long*) * array->capacity);
    }
    array->arr[array->size++] = matrix;
}

IntMatrix2DArray* newIntMatrix2DArray() {
    IntMatrix2DArray* array = (IntMatrix2DArray*)malloc(sizeof(IntMatrix2DArray));
    array->arr = (int**)malloc(sizeof(int*) * 10);
    array->size = 0;
    array->capacity = 10;
    return array;
}

void addIntMatrix2D(IntMatrix2DArray* array, int** matrix) {
    if (array->size == array->capacity) {
        array->capacity *= 2;
        array->arr = (int**)realloc(array->arr, sizeof(int*) * array->capacity);
    }
    array->arr[array->size++] = matrix;
}

LongMatrix2DArray* newLongMatrix2DArray() {
    LongMatrix2DArray* array = (LongMatrix2DArray*)malloc(sizeof(LongMatrix2DArray));
    array->arr = (long**)malloc(sizeof(long*) * 10);
    array->size = 0;
    array->capacity = 10;
    return array;
}

void addLongMatrix2D(LongMatrix2DArray* array, long** matrix) {
    if (array->size == array->capacity) {
        array->capacity *= 2;
        array->arr = (long**)realloc(array->arr, sizeof(long*) * array->capacity);
    }
    array->arr[array->size++] = matrix;
}

typedef struct {
    int* arr;
    int size;
    int capacity;
} IntStack;

IntStack* newIntStack() {
    IntStack* stack = (IntStack*)malloc(sizeof(IntStack));
    stack->arr = (int*)malloc(sizeof(int) * 10);
    stack->size = 0;
    stack->capacity = 10;
    return stack;
}

void pushInt(IntStack* stack, int value) {
    if (stack->size == stack->capacity) {
        stack->capacity *= 2;
        stack->arr = (int*)realloc(stack->arr, sizeof(int) * stack->capacity);
    }
    stack->arr[stack->size++] = value;
}

int popInt(IntStack* stack) {
    return stack->arr[--stack->size];
}

int topInt(IntStack* stack) {
    return stack->arr[stack->size - 1];
}

int isEmptyIntStack(IntStack* stack) {
    return stack->size == 0;
}

typedef struct {
    long* arr;
    int size;
    int capacity;
} LongStack;

LongStack* newLongStack() {
    LongStack* stack = (LongStack*)malloc(sizeof(LongStack));
    stack->arr = (long*)malloc(sizeof(long) * 10);
    stack->size = 0;
    stack->capacity = 10;
    return stack;
}

void pushLong(LongStack* stack, long value) {
    if (stack->size == stack->capacity) {
        stack->capacity *= 2;
        stack->arr = (long*)realloc(stack->arr, sizeof(long) * stack->capacity);
    }
    stack->arr[stack->size++] = value;
}

long popLong(LongStack* stack) {
    return stack->arr[--stack->size];
}

long topLong(LongStack* stack) {
    return stack->arr[stack->size - 1];
}

int isEmptyLongStack(LongStack* stack) {
    return stack->size == 0;
}

typedef struct {
    int* arr;
    int size;
    int capacity;
} IntQueue;

IntQueue* newIntQueue() {
    IntQueue* queue = (IntQueue*)malloc(sizeof(IntQueue));
    queue->arr = (int*)malloc(sizeof(int) * 10);
    queue->size = 0;
    queue->capacity = 10;
    return queue;
}

void enqueueInt(IntQueue* queue, int value) {
    if (queue->size == queue->capacity) {
        queue->capacity *= 2;
        queue->arr = (int*)realloc(queue->arr, sizeof(int) * queue->capacity);
    }
    queue->arr[queue->size++] = value;
}

int dequeueInt(IntQueue* queue) {
    int value = queue->arr[0];
    for (int i = 1; i < queue->size; i++) {
        queue->arr[i - 1] = queue->arr[i];
    }
    queue->size--;
    return value;
}

int frontInt(IntQueue* queue) {
    return queue->arr[0];
}

int isEmptyIntQueue(IntQueue* queue) {
    return queue->size == 0;
}

typedef struct {
    long* arr;
    int size;
    int capacity;
} LongQueue;

LongQueue* newLongQueue() {
    LongQueue* queue = (LongQueue*)malloc(sizeof(LongQueue));
    queue->arr = (long*)malloc(sizeof(long) * 10);
    queue->size = 0;
    queue->capacity = 10;
    return queue;
}

void enqueueLong(LongQueue* queue, long value) {
    if (queue->size == queue->capacity) {
        queue->capacity *= 2;
        queue->arr = (long*)realloc(queue->arr, sizeof(long) * queue->capacity);
    }
    queue->arr[queue->size++] = value;
}

long dequeueLong(LongQueue* queue) {
    long value = queue->arr[0];
    for (int i = 1; i < queue->size; i++) {
        queue->arr[i - 1] = queue->arr[i];
    }
    queue->size--;
    return value;
}

long frontLong(LongQueue* queue) {
    return queue->arr[0];
}

int isEmptyLongQueue(LongQueue* queue) {
    return queue->size == 0;
}

typedef struct {
    int* arr;
    int size;
    int capacity;
} IntPriorityQueue;

IntPriorityQueue* newIntPriorityQueue() {
    IntPriorityQueue* queue = (IntPriorityQueue*)malloc(sizeof(IntPriorityQueue));
    queue->arr = (int*)malloc(sizeof(int) * 10);
    queue->size = 0;
    queue->capacity = 10;
    return queue;
}

void enqueueIntPriority(IntPriorityQueue* queue, int value) {
    if (queue->size == queue->capacity) {
        queue->capacity *= 2;
        queue->arr = (int*)realloc(queue->arr, sizeof(int) * queue->capacity);
    }
    queue->arr[queue->size++] = value;
    int i = queue->size - 1;
    while (i > 0 && queue->arr[i] < queue->arr[(i - 1) / 2]) {
        int temp = queue->arr[i];
        queue->arr[i] = queue->arr[(i - 1) / 2];
        queue->arr[(i - 1) / 2] = temp;
        i = (i - 1) / 2;
    }
}

int dequeueIntPriority(IntPriorityQueue* queue) {
    int value = queue->arr[0];
    queue->arr[0] = queue->arr[--queue->size];
    int i = 0;
    while (2 * i + 1 < queue->size) {
        int child = 2 * i + 1;
        if (child + 1 < queue->size && queue->arr[child + 1] < queue->arr[child]) {
            child++;
        }
        if (queue->arr[i] <= queue->arr[child]) {
            break;
        }
        int temp = queue->arr[i];
        queue->arr[i] = queue->arr[child];
        queue->arr[child] = temp;
        i = child;
    }
    return value;
}

int frontIntPriority(IntPriorityQueue* queue) {
    return queue->arr[0];
}

int isEmptyIntPriorityQueue(IntPriorityQueue* queue) {
    return queue->size == 0;
}

typedef struct {
    long* arr;
    int size;
    int capacity;
} LongPriorityQueue;

LongPriorityQueue* newLongPriorityQueue() {
    LongPriorityQueue* queue = (LongPriorityQueue*)malloc(sizeof(LongPriorityQueue));
    queue->arr = (long*)malloc(sizeof(long) * 10);
    queue->size = 0;
    queue->capacity = 10;
    return queue;
}

void enqueueLongPriority(LongPriorityQueue* queue, long value) {
    if (queue->size == queue->capacity) {
        queue->capacity *= 2;
        queue->arr = (long*)realloc(queue->arr, sizeof(long) * queue->capacity);
    }
    queue->arr[queue->size++] = value;
    int i = queue->size - 1;
    while (i > 0 && queue->arr[i] < queue->arr[(i - 1) / 2]) {
        long temp = queue->arr[i];
        queue->arr[i] = queue->arr[(i - 1) / 2];
        queue->arr[(i - 1) / 2] = temp;
        i = (i - 1) / 2;
    }
}

long dequeueLongPriority(LongPriorityQueue* queue) {
    long value = queue->arr[0];
    queue->arr[0] = queue->arr[--queue->size];
    int i = 0;
    while (2 * i + 1 < queue->size) {
        int child = 2 * i + 1;
        if (child + 1 < queue->size && queue->arr[child + 1] < queue->arr[child]) {
            child++;
        }
        if (queue->arr[i] <= queue->arr[child]) {
            break;
        }
        long temp = queue->arr[i];
        queue->arr[i] = queue->arr[child];
        queue->arr[child] = temp;
        i = child;
    }
    return value;
}

long frontLongPriority(LongPriorityQueue* queue) {
    return queue->arr[0];
}

int isEmptyLongPriorityQueue(LongPriorityQueue* queue) {
    return queue->size == 0;
}

typedef struct {
    int* arr;
    int size;
    int capacity;
} IntHashSet;

IntHashSet* newIntHashSet() {
    IntHashSet* set = (IntHashSet*)malloc(sizeof(IntHashSet));
    set->arr = (int*)malloc(sizeof(int) * 10);
    set->size = 0;
    set->capacity = 10;
    return set;
}

int containsInt(IntHashSet* set, int value) {
    for (int i = 0; i < set->size; i++) {
        if (set->arr[i] == value) {
            return 1;
        }
    }
    return 0;
}

void addIntHashSet(IntHashSet* set, int value) {
    if (containsInt(set, value)) {
        return;
    }
    if (set->size == set->capacity) {
        set->capacity *= 2;
        set->arr = (int*)realloc(set->arr, sizeof(int) * set->capacity);
    }
    set->arr[set->size++] = value;
}

typedef struct {
    long* arr;
    int size;
    int capacity;
} LongHashSet;

LongHashSet* newLongHashSet() {
    LongHashSet* set = (LongHashSet*)malloc(sizeof(LongHashSet));
    set->arr = (long*)malloc(sizeof(long) * 10);
    set->size = 0;
    set->capacity = 10;
    return set;
}

int containsLong(LongHashSet* set, long value) {
    for (int i = 0; i < set->size; i++) {
        if (set->arr[i] == value) {
            return 1;
        }
    }
    return 0;
}

void addLongHashSet(LongHashSet* set, long value) {
    if (containsLong(set, value)) {
        return;
    }
    if (set->size == set->capacity) {
        set->capacity *= 2;
        set->arr = (long*)realloc(set->arr, sizeof(long) * set->capacity);
    }
    set->arr[set->size++] = value;
}

typedef struct {
    int* arr;
    int size;
    int capacity;
} IntHashMap;

IntHashMap* newIntHashMap() {
    IntHashMap* map = (IntHashMap*)malloc(sizeof(IntHashMap));
    map->arr = (int*)malloc(sizeof(int) * 10);
    map->size = 0;
    map->capacity = 10;
    return map;
}

int getInt(IntHashMap* map, int key) {
    for (int i = 0; i < map->size; i += 2) {
        if (map->arr[i] == key) {
            return map->arr[i + 1];
        }
    }
    return 0;
}

void putInt(IntHashMap* map, int key, int value) {
    for (int i = 0; i < map->size; i += 2) {
        if (map->arr[i] == key) {
            map->arr[i + 1] = value;
            return;
        }
    }
    if (map->size == map->capacity) {
        map->capacity *= 2;
        map->arr = (int*)realloc(map->arr, sizeof(int) * map->capacity);
    }
    map->arr[map->size++] = key;
    map->arr[map->size++] = value;
}

typedef struct {
    long* arr;
    int size;
    int capacity;
} LongHashMap;

LongHashMap* newLongHashMap() {
    LongHashMap* map = (LongHashMap*)malloc(sizeof(LongHashMap));
    map->arr = (long*)malloc(sizeof(long) * 10);
    map->size = 0;
    map->capacity = 10;
    return map;
}

long getLong(LongHashMap* map, long key) {
    for (int i = 0; i < map->size; i += 2) {
        if (map->arr[i] == key) {
            return map->arr[i + 1];
        }
    }
    return 0;
}

void putLong(LongHashMap* map, long key, long value) {
    for (int i = 0; i < map->size; i += 2) {
        if (map->arr[i] == key) {
            map->arr[i + 1] = value;
            return;
        }
    }
    if (map->size == map->capacity) {
        map->capacity *= 2;
        map->arr = (long*)realloc(map->arr, sizeof(long) * map->capacity);
    }
    map->arr[map->size++] = key;
    map->arr[map->size++] = value;
}

typedef struct {
    int* arr;
    int size;
    int capacity;
} IntArrayList;

IntArrayList* newIntArrayList() {
    IntArrayList* list = (IntArrayList*)malloc(sizeof(IntArrayList));
    list->arr = (int*)malloc(sizeof(int) * 10);
    list->size = 0;
    list->capacity = 10;
    return list;
}

void addIntArrayList(IntArrayList* list, int value) {
    if (list->size == list->capacity) {
        list->capacity *= 2;
        list->arr = (int*)realloc(list->arr, sizeof(int) * list->capacity);
    }
    list->arr[list->size++] = value;
}

typedef struct {
    long* arr;
    int size;
    int capacity;
} LongArrayList;

LongArrayList* newLongArrayList() {
    LongArrayList* list = (LongArrayList*)malloc(sizeof(LongArrayList));
    list->arr = (long*)malloc(sizeof(long) * 10);
    list->size = 0;
    list->capacity = 10;
    return list;
}

void addLongArrayList(LongArrayList* list, long value) {
    if (list->size == list->capacity) {
        list->capacity *= 2;
        list->arr = (long*)realloc(list->arr, sizeof(long) * list->capacity);
    }
    list->arr[list->size++] = value;
}

typedef struct {
    void** arr;
    int size;
    int capacity;
} ObjectArrayList;

ObjectArrayList* newObjectArrayList() {
    ObjectArrayList* list = (ObjectArrayList*)malloc(sizeof(ObjectArrayList));
    list->arr = (void**)malloc(sizeof(void*) * 10);
    list->size = 0;
    list->capacity = 10;
    return list;
}

void addObjectArrayList(ObjectArrayList* list, void* value) {
    if (list->size == list->capacity) {
        list->capacity *= 2;
        list->arr = (void**)realloc(list->arr, sizeof(void*) * list->capacity);
    }
    list->arr[list->size++] = value;
}

typedef struct {
    int* arr;
    int size;
    int capacity;
} IntLinkedList;

typedef struct IntLinkedListNode {
    int value;
    struct IntLinkedListNode* prev;
    struct IntLinkedListNode* next;
} IntLinkedListNode;

IntLinkedList* newIntLinkedList() {
    IntLinkedList* list = (IntLinkedList*)malloc(sizeof(IntLinkedList));
    list->arr = (int*)malloc(sizeof(int) * 10);
    list->size = 0;
    list->capacity = 10;
    return list;
}

void addIntLinkedList(IntLinkedList* list, int value) {
    if (list->size == list->capacity) {
        list->capacity *= 2;
        list->arr = (int*)realloc(list->arr, sizeof(int) * list->capacity);
    }
    list->arr[list->size++] = value;
}

typedef struct {
    long* arr;
    int size;
    int capacity;
} LongLinkedList;

typedef struct LongLinkedListNode {
    long value;
    struct LongLinkedListNode* prev;
    struct LongLinkedListNode* next;
} LongLinkedListNode;

LongLinkedList* newLongLinkedList() {
    LongLinkedList* list = (LongLinkedList*)malloc(sizeof(LongLinkedList));
    list->arr = (long*)malloc(sizeof(long) * 10);
    list->size = 0;
    list->capacity = 10;
    return list;
}

void addLongLinkedList(LongLinkedList* list, long value) {
    if (list->size == list->capacity) {
        list->capacity *= 2;
        list->arr = (long*)realloc(list->arr, sizeof(long) * list->capacity);
    }
    list->arr[list->size++] = value;
}

typedef struct {
    void** arr;
    int size;
    int capacity;
} ObjectLinkedList;

typedef struct ObjectLinkedListNode {
    void* value;
    struct ObjectLinkedListNode* prev;
    struct ObjectLinkedListNode* next;
} ObjectLinkedListNode;

ObjectLinkedList* newObjectLinkedList() {
    ObjectLinkedList* list = (ObjectLinkedList*)malloc(sizeof(ObjectLinkedList));
    list->arr = (void**)malloc(sizeof(void*) * 10);
    list->size = 0;
    list->capacity = 10;
    return list;
}

void addObjectLinkedList(ObjectLinkedList* list, void* value) {
    if (list->size == list->capacity) {
        list->capacity *= 2;
        list->arr = (void**)realloc(list->arr, sizeof(void*) * list->capacity);
    }
    list->arr[list->size++] = value;
}

typedef struct {
    int* arr;
    int size;
    int capacity;
} IntDeque;

IntDeque* newIntDeque() {
    IntDeque* deque = (IntDeque*)malloc(sizeof(IntDeque));
    deque->arr = (int*)malloc(sizeof(int) * 10);
    deque->size = 0;
    deque->capacity = 10;
    return deque;
}

void pushFrontInt(IntDeque* deque, int value) {
    if (deque->size == deque->capacity) {
        deque->capacity *= 2;
        deque->arr = (int*)realloc(deque->arr, sizeof(int) * deque->capacity);
    }
    for (int i = deque->size; i > 0; i--) {
        deque->arr[i] = deque->arr[i - 1];
    }
    deque->arr[0] = value;
    deque->size++;
}

void pushBackInt(IntDeque* deque, int value) {
    if (deque->size == deque->capacity) {
        deque->capacity *= 2;
        deque->arr = (int*)realloc(deque->arr, sizeof(int) * deque->capacity);
    }
    deque->arr[deque->size++] = value;
}

int popFrontInt(IntDeque* deque) {
    int value = deque->arr[0];
    for (int i = 1; i < deque->size; i++) {
        deque->arr[i - 1] = deque->arr[i];
    }
    deque->size--;
    return value;
}

int popBackInt(IntDeque* deque) {
    return deque->arr[--deque->size];
}

int frontIntDeque(IntDeque* deque) {
    return deque->arr[0];
}

int backIntDeque(IntDeque* deque) {
    return deque->arr[deque->size - 1];
}

int isEmptyIntDeque(IntDeque* deque) {
    return deque->size == 0;
}

typedef struct {
    long* arr;
    int size;
    int capacity;
} LongDeque;

LongDeque* newLongDeque() {
    LongDeque* deque = (LongDeque*)malloc(sizeof(LongDeque));
    deque->arr = (long*)malloc(sizeof(long) * 10);
    deque->size = 0;
    deque->capacity = 10;
    return deque;
}

void pushFrontLong(LongDeque* deque, long value) {
    if (deque->size == deque->capacity) {
        deque->capacity *= 2;
        deque->arr = (long*)realloc(deque->arr, sizeof(long) * deque->capacity);
    }
    for (int i = deque->size; i > 0; i--) {
        deque->arr[i] = deque->arr[i - 1];
    }
    deque->arr[0] = value;
    deque->size++;
}

void pushBackLong(LongDeque* deque, long value) {
    if (deque->size == deque->capacity) {
        deque->capacity *= 2;
        deque->arr = (long*)realloc(deque->arr, sizeof(long) * deque->capacity);
    }
    deque->arr[deque->size++] = value;
}

long popFrontLong(LongDeque* deque) {
    long value = deque->arr[0];
    for (int i = 1; i < deque->size; i++) {
        deque->arr[i - 1] = deque->arr[i];
    }
    deque->size--;
    return value;
}

long popBackLong(LongDeque* deque) {
    return deque->arr[--deque->size];
}

long frontLongDeque(LongDeque* deque) {
    return deque->arr[0];
}

long backLongDeque(LongDeque* deque) {
    return deque->arr[deque->size - 1];
}

int isEmptyLongDeque(LongDeque* deque) {
    return deque->size == 0;
}

typedef struct {
    int* arr;
    int size;
    int capacity;
} IntPriorityDeque;

IntPriorityDeque* newIntPriorityDeque() {
    IntPriorityDeque* deque = (IntPriorityDeque*)malloc(sizeof(IntPriorityDeque));
    deque->arr = (int*)malloc(sizeof(int) * 10);
    deque->size = 0;
    deque->capacity = 10;
    return deque;
}

void pushFrontIntPriority(IntPriorityDeque* deque, int value) {
    if (deque->size == deque->capacity) {
        deque->capacity *= 2;
        deque->arr = (int*)realloc(deque->arr, sizeof(int) * deque->capacity);
    }
    for (int i = deque->size; i > 0; i--) {
        deque->arr[i] = deque->arr[i - 1];
    }
    deque->arr[0] = value;
    deque->size++;
}

void pushBackIntPriority(IntPriorityDeque* deque, int value) {
    if (deque->size == deque->capacity) {
        deque->capacity *= 2;
        deque->arr = (int*)realloc(deque->arr, sizeof(int) * deque->capacity);
    }
    deque->arr[deque->size++] = value;
}

int popFrontIntPriority(IntPriorityDeque* deque) {
    int value = deque->arr[0];
    for (int i = 1; i < deque->size; i++) {
        deque->arr[i - 1] = deque->arr[i];
    }
    deque->size--;
    return value;
}

int popBackIntPriority(IntPriorityDeque* deque) {
    return deque->arr[--deque->size];
}

int frontIntPriorityDeque(IntPriorityDeque* deque) {
    return deque->arr[0];
}

int backIntPriorityDeque(IntPriorityDeque* deque) {
    return deque->arr[deque->size - 1];
}

int isEmptyIntPriorityDeque(IntPriorityDeque* deque) {
    return deque->size == 0;
}

typedef struct {
    long* arr;
    int size;
    int capacity;
} LongPriorityDeque;

LongPriorityDeque* newLongPriorityDeque() {
    LongPriorityDeque* deque = (LongPriorityDeque*)malloc(sizeof(LongPriorityDeque));
    deque->arr = (long*)malloc(sizeof(long) * 10);
    deque->size = 0;
    deque->capacity = 10;
    return deque;
}

void pushFrontLongPriority(LongPriorityDeque* deque, long value) {
    if (deque->size == deque->capacity) {
        deque->capacity *= 2;
        deque->arr = (long*)realloc(deque->arr, sizeof(long) * deque->capacity);
    }
    for (int i = deque->size; i > 0; i--) {
        deque->arr[i] = deque->arr[i - 1];
    }
    deque->arr[0] = value;
    deque->size++;
}

void pushBackLongPriority(LongPriorityDeque* deque, long value) {
    if (deque->size == deque->capacity) {
        deque->capacity *= 2;
        deque->arr = (long*)realloc(deque->arr, sizeof(long) * deque->capacity);
    }
    deque->arr[deque->size++] = value;
}

long popFrontLongPriority(LongPriorityDeque* deque) {
    long value = deque->arr[0];
    for (int i = 1; i < deque->size; i++) {
        deque->arr[i - 1] = deque->arr[i];
    }
    deque->size--;
    return value;
}

long popBackLongPriority(LongPriorityDeque* deque) {
    return deque->arr[--deque->size];
}

long frontLongPriorityDeque(LongPriorityDeque* deque) {
    return deque->arr[0];
}

long backLongPriorityDeque(LongPriorityDeque* deque) {
    return deque->arr[deque->size - 1];
}

int isEmptyLongPriorityDeque(LongPriorityDeque* deque) {
    return deque->size == 0;
}

typedef struct {
    int* arr;
    int size;
    int capacity;
} IntStackArray;

IntStackArray* newIntStackArray() {
    IntStackArray* array = (IntStackArray*)malloc(sizeof(IntStackArray));
    array->arr = (int*)malloc(sizeof(int) * 10);
    array->size = 0;
    array->capacity = 10;
    return array;
}

void addIntStack(IntStackArray* array, int* stack) {
    if (array->size == array->capacity) {
        array->capacity *= 2;
        array->arr = (int*)realloc(array->arr, sizeof(int) * array->capacity);
    }
    array->arr[array->size++] = stack;
}

typedef struct {
    long* arr;
    int size;
    int capacity;
} LongStackArray;

LongStackArray* newLongStackArray() {
    LongStackArray* array = (LongStackArray*)malloc(sizeof(LongStackArray));
    array->arr = (long*)malloc(sizeof(long) * 10);
    array->size = 0;
    array->capacity = 10;
    return array;
}

void addLongStack(LongStackArray* array, long* stack) {
    if (array->size == array->capacity) {
        array->capacity *= 2;
        array->arr = (long*)realloc(array->arr, sizeof(long) * array->capacity);
    }
    array->arr[array->size++] = stack;
}

typedef struct {
    int* arr;
    int size;
    int capacity;
} IntQueueArray;

IntQueueArray* newIntQueueArray() {
    IntQueueArray* array = (IntQueueArray*)malloc(sizeof(IntQueueArray));
    array->arr = (int*)malloc(sizeof(int) * 10);
    array->size = 0;
    array->capacity = 10;
    return array;
}

void addIntQueue(IntQueueArray* array, int* queue) {
    if (array->size == array->capacity) {
        array->capacity *= 2;
        array->arr = (int*)realloc(array->arr, sizeof(int) * array->capacity);
    }
    array->arr[array->size++] = queue;
}

typedef struct {
    long* arr;
    int size;
    int capacity;
} LongQueueArray;

LongQueueArray* newLongQueueArray() {
    LongQueueArray* array = (LongQueueArray*)malloc(sizeof(LongQueueArray));
    array->arr = (long*)malloc(sizeof(long) * 10);
    array->size = 0;
    array->capacity = 10;
    return array;
}

void addLongQueue(LongQueueArray* array, long* queue) {
    if (array->size == array->capacity) {
        array->capacity *= 2;
        array->arr = (long*)realloc(array->arr, sizeof(long) * array->capacity);
    }
    array->arr[array->size++] = queue;
}

typedef struct {
    int* arr;
    int size;
    int capacity;
} IntPriorityQueueArray;

IntPriorityQueueArray* newIntPriorityQueueArray() {
    IntPriorityQueueArray* array = (IntPriorityQueueArray*)malloc(sizeof(IntPriorityQueueArray));
    array->arr = (int*)malloc(sizeof(int) * 10);
    array->size = 0;
    array->capacity = 10;
    return array;
}

void addIntPriorityQueue(IntPriorityQueueArray* array, int* queue) {
    if (array->size == array->capacity) {
        array->capacity *= 2;
        array->arr = (int*)realloc(array->arr, sizeof(int) * array->capacity);
    }
    array->arr[array->size++] = queue;
}

typedef struct {
    long* arr;
    int size;
    int capacity;
} LongPriorityQueueArray;

LongPriorityQueueArray* newLongPriorityQueueArray() {
    LongPriorityQueueArray* array = (LongPriorityQueueArray*)malloc(sizeof(LongPriorityQueueArray));
    array->arr = (long*)malloc(sizeof(long) * 10);
    array->size = 0;
    array->capacity = 10;
    return array;
}

void addLongPriorityQueue(LongPriorityQueueArray* array, long* queue) {
    if (array->size == array->capacity) {
        array->capacity *= 2;
        array->arr = (long*)realloc(array->arr, sizeof(long) * array->capacity);
    }
    array->arr[array->size++] = queue;
}

typedef struct {
    int* arr;
    int size;
    int capacity;
} IntHashSetArray;

IntHashSetArray* newIntHashSetArray() {
    IntHashSetArray* array = (IntHashSetArray*)malloc(sizeof(IntHashSetArray));
    array->arr = (int*)malloc(sizeof(int) * 10);
    array->size = 0;
    array->capacity = 10;
    return array;
}

void addIntHashSet(IntHashSetArray* array, int* set) {
    if (array->size == array->capacity) {
        array->capacity *= 2;
        array->arr = (int*)realloc(array->arr, sizeof(int) * array->capacity);
    }
    array->arr[array->size++] = set;
}

typedef struct {
    long* arr;
    int size;
    int capacity;
} LongHashSetArray;

LongHashSetArray* newLongHashSetArray() {
    LongHashSetArray* array = (LongHashSetArray*)malloc(sizeof(LongHashSetArray));
    array->arr = (long*)malloc(sizeof(long) * 10);
    array->size = 0;
    array->capacity = 10;
    return array;
}

void addLongHashSet(LongHashSetArray* array, long* set) {
    if (array->size == array->capacity) {
        array->capacity *= 2;
        array->arr = (long*)realloc(array->arr, sizeof(long) * array->capacity);
    }
    array->arr[array->size++] = set;
}

typedef struct {
    int* arr;
    int size;
    int capacity;
} IntHashMapArray;

IntHashMapArray* newIntHashMapArray() {
    IntHashMapArray* array = (IntHashMapArray*)malloc(sizeof(IntHashMapArray));
    array->arr = (int*)malloc(sizeof(int) * 10);
    array->size = 0;
    array->capacity = 10;
    return array;
}

void addIntHashMap(IntHashMapArray* array, int* map) {
    if (array->size == array->capacity) {
        array->capacity *= 2;
        array->arr = (int*)realloc(array->arr, sizeof(int) * array->capacity);
    }
    array->arr[array->size++] = map;
}

typedef struct {
    long* arr;
    int size;
    int capacity;
} LongHashMapArray;

LongHashMapArray* newLongHashMapArray() {
    LongHashMapArray* array = (LongHashMapArray*)malloc(sizeof(LongHashMapArray));
    array->arr = (long*)malloc(sizeof(long) * 10);
    array->size = 0;
    array->capacity = 10;
    return array;
}

void addLongHashMap(LongHashMapArray* array, long* map) {
    if (array->size == array->capacity) {
        array->capacity *= 2;
        array->arr = (long*)realloc(array->arr, sizeof(long) * array->capacity);
    }
    array->arr[array->size++] = map;
}

typedef struct {
    int* arr;
    int size;
    int capacity;
} IntArrayListArray;

IntArrayListArray* newIntArrayListArray() {
    IntArrayListArray* array = (IntArrayListArray*)malloc(sizeof(IntArrayListArray));
    array->arr = (int*)malloc(sizeof(int) * 10);
    array->size = 0;
    array->capacity = 10;
    return array;
}

void addIntArrayList(IntArrayListArray* array, IntArrayList* list) {
    if (array->size == array->capacity) {
        array->capacity *= 2;
        array->arr = (int*)realloc(array->arr, sizeof(int) * array->capacity);
    }
    array->arr[array->size++] = list;
}

typedef struct {
    long* arr;
    int size;
    int capacity;
} LongArrayListArray;

LongArrayListArray* newLongArrayListArray() {
    LongArrayListArray* array = (LongArrayListArray*)malloc(sizeof(LongArrayListArray));
    array->arr = (long*)malloc(sizeof(long) * 10);
    array->size = 0;
    array->capacity = 10;
    return array;
}

void addLongArrayList(LongArrayListArray* array, LongArrayList* list) {
    if (array->size == array->capacity) {
        array->capacity *= 2;
        array->arr = (long*)realloc(array->arr, sizeof(long) * array->capacity);
    }
    array->arr[array->size++] = list;
}

typedef struct {
    void** arr;
    int size;
    int capacity;
} ObjectArrayListArray;

ObjectArrayListArray* newObjectArrayListArray() {
    ObjectArrayListArray* array = (ObjectArrayListArray*)malloc(sizeof(ObjectArrayListArray));
    array->arr = (void**)malloc(sizeof(void*) * 10);
    array->size = 0;
    array->capacity = 10;
    return array;
}

void addObjectArrayList(ObjectArrayListArray* array, ObjectArrayList* list) {
    if (array->size == array->capacity) {
        array->capacity *= 2;
        array->arr = (void**)realloc(array->arr, sizeof(void*) * array->capacity);
    }
    array->arr[array->size++] = list;
}

typedef struct {
    int* arr;
    int size;
    int capacity;
} IntLinkedListArray;

typedef struct IntLinkedListNodeArray {
    IntLinkedListNode* value;
    struct IntLinkedListNodeArray* prev;
    struct IntLinkedListNodeArray* next;
} IntLinkedListNodeArray;

IntLinkedListArray* newIntLinkedListArray() {
    IntLinkedListArray* array = (IntLinkedListArray*)malloc(sizeof(IntLinkedListArray));
    array->arr = (int*)malloc(sizeof(int) * 10);
    array->size = 0;
    array->capacity = 10;
    return array;
}

void addIntLinkedList(IntLinkedListArray* array, IntLinkedList* list) {
    if (array->size == array->capacity) {
        array->capacity *= 2;
        array->arr = (int*)realloc(array->arr, sizeof(int) * array->capacity);
    }
    array->arr[array->size++] = list;
}

typedef struct {
    long* arr;
    int size;
    int capacity;
} LongLinkedListArray;

typedef struct LongLinkedListNodeArray {
    LongLinkedListNode* value;
    struct LongLinkedListNodeArray* prev;
    struct LongLinkedListNodeArray* next;
} LongLinkedListNodeArray;

LongLinkedListArray* newLongLinkedListArray() {
    LongLinkedListArray* array = (LongLinkedListArray*)malloc(sizeof(LongLinkedListArray));
    array->arr = (long*)malloc(sizeof(long) * 10);
    array->size = 0;
    array->capacity = 10;
    return array;
}

void addLongLinkedList(LongLinkedListArray* array, LongLinkedList* list) {
    if (array->size == array->capacity) {
        array->capacity *= 2;
        array->arr = (long*)realloc(array->arr, sizeof(long) * array->capacity);
    }
    array->arr[array->size++] = list;
}

typedef struct {
    void** arr;
    int size;
    int capacity;
} ObjectLinkedListArray;

typedef struct ObjectLinkedListNodeArray {
    ObjectLinkedListNode* value;
    struct ObjectLinkedListNodeArray* prev;
    struct ObjectLinkedListNodeArray* next;
} ObjectLinkedListNodeArray;

ObjectLinkedListArray* newObjectLinkedListArray() {
    ObjectLinkedListArray* array = (ObjectLinkedListArray*)malloc(sizeof(ObjectLinkedListArray));
    array->arr = (void**)malloc(sizeof(void*) * 10);
    array->size = 0;
    array->capacity = 10;
    return array;
}

void addObjectLinkedList(ObjectLinkedListArray* array, ObjectLinkedList* list) {
    if (array->size == array->capacity) {
        array->capacity *= 2;
        array->arr = (void**)realloc(array->arr, sizeof(void*) * array->capacity);
    }
    array->arr[array->size++] = list;
}

typedef struct {
    int* arr;
    int size;
    int capacity;
} IntDequeArray;

IntDequeArray* newIntDequeArray() {
    IntDequeArray* array = (IntDequeArray*)malloc(sizeof(IntDequeArray));
    array->arr = (int*)malloc(sizeof(int) * 10);
    array->size = 0;
    array->capacity = 10;
    return array;
}

void addIntDeque(IntDequeArray* array, IntDeque* deque) {
    if (array->size == array->capacity) {
        array->capacity *= 2;
        array->arr = (int*)realloc(array->arr, sizeof(int) * array->capacity);
    }
    array->arr[array->size++] = deque;
}

typedef struct {
    long* arr;
    int size;
    int capacity;
} LongDequeArray;

LongDequeArray* newLongDequeArray() {
    LongDequeArray* array = (LongDequeArray*)malloc(sizeof(LongDequeArray));
    array->arr = (long*)malloc(sizeof(long) * 10);
    array->size = 0;
    array->capacity = 10;
    return array;
}

void addLongDeque(LongDequeArray* array, LongDeque* deque) {
    if (array->size == array->capacity) {
        array->capacity *= 2;
        array->arr = (long*)realloc(array->arr, sizeof(long) * array->capacity);
    }
    array->arr[array->size++] = deque;
}

typedef struct {
    int* arr;
    int size;
    int capacity;
} IntPriorityDequeArray;

IntPriorityDequeArray* newIntPriorityDequeArray() {
    IntPriorityDequeArray* array = (IntPriorityDequeArray*)malloc(sizeof(IntPriorityDequeArray));
    array->arr = (int*)malloc(sizeof(int) * 10);
    array->size = 0;
    array->capacity = 10;
    return array;
}

void addIntPriorityDeque(IntPriorityDequeArray* array, IntPriorityDeque* deque) {
    if (array->size == array->capacity) {
        array->capacity *= 2;
        array->arr = (int*)realloc(array->arr, sizeof(int) * array->capacity);
    }
    array->arr[array->size++] = deque;
}

typedef struct {
    long* arr;
    int size;
    int capacity;
} LongPriorityDequeArray;

LongPriorityDequeArray* newLongPriorityDequeArray() {
    LongPriorityDequeArray* array = (LongPriorityDequeArray*)malloc(sizeof(LongPriorityDequeArray));
    array->arr = (long*)malloc(sizeof(long) * 10);
    array->size = 0;
    array->capacity = 10;
    return array;
}

void addLongPriorityDeque(LongPriorityDequeArray* array, LongPriorityDeque* deque) {
    if (array->size == array->capacity) {
        array->capacity *= 2;
        array->arr = (long*)realloc(array->arr, sizeof(long) * array->capacity);
    }
    array->arr[array->size++] = deque;
}

typedef struct {
    int* arr;
    int size;
    int capacity;
} IntStackArrayArray;

IntStackArrayArray* newIntStackArrayArray() {
    IntStackArrayArray* array = (IntStackArrayArray*)malloc(sizeof(IntStackArrayArray));
    array->arr = (int*)malloc(sizeof(int) * 10);
    array->size = 0;
    array->capacity = 10;
    return array;
}

void addIntStackArray(IntStackArrayArray* array, IntStackArray* stackArray) {
    if (array->size == array->capacity) {
        array->capacity *= 2;
        array->arr = (int*)realloc(array->arr, sizeof(int) * array->capacity);
    }
    array->arr[array->size++] = stackArray;
}

typedef struct {
    long* arr;
    int size;
    int capacity;
} LongStackArrayArray;

LongStackArrayArray* newLongStackArrayArray() {
    LongStackArrayArray* array = (LongStackArrayArray*)malloc(sizeof(LongStackArrayArray));
    array->arr = (long*)malloc(sizeof(long) * 10);
    array->size = 0;
    array->capacity = 10;
    return array;
}

void addLongStackArray(LongStackArrayArray* array, LongStackArray* stackArray) {
    if (array->size == array->capacity) {
        array->capacity *= 2;
        array->arr = (long*)realloc(array->arr, sizeof(long) * array->capacity);
    }
    array->arr[array->size++] = stackArray;
}

typedef struct {
    int* arr;
    int size;
    int capacity;
} IntQueueArrayArray;

IntQueueArrayArray* newIntQueueArrayArray() {
    IntQueueArrayArray* array = (IntQueueArrayArray*)malloc(sizeof(IntQueueArrayArray));
    array->arr = (int*)malloc(sizeof(int) * 10);
    array->size = 0;
    array->capacity = 10;
    return array;
}

void addIntQueueArray(IntQueueArrayArray* array, IntQueueArray* queueArray) {
    if (array->size == array->capacity) {
        array->capacity *= 2;
        array->arr = (int*)realloc(array->arr, sizeof(int) * array->capacity);
    }
    array->arr[array->size++] = queueArray;
}

typedef struct {
    long* arr;
    int size;
    int capacity;
} LongQueueArrayArray;

LongQueueArrayArray* newLongQueueArrayArray() {
    LongQueueArrayArray* array = (LongQueueArrayArray*)malloc(sizeof(LongQueueArrayArray));
    array->arr = (long*)malloc(sizeof(long) * 10);
    array->size = 0;
    array->capacity = 10;
    return array;
}

void addLongQueueArray(LongQueueArrayArray* array, LongQueueArray* queueArray) {
    if (array->size == array->capacity) {
        array->capacity *= 2;
        array->arr = (long*)realloc(array->arr, sizeof(long) * array->capacity);
    }
    array->arr[array->size++] = queueArray;
}

typedef struct {
    int* arr;
    int size;
    int capacity;
} IntPriorityQueueArrayArray;

IntPriorityQueueArrayArray* newIntPriorityQueueArrayArray() {
    IntPriorityQueueArrayArray* array = (IntPriorityQueueArrayArray*)malloc(sizeof(IntPriorityQueueArrayArray));
    array->arr = (int*)malloc(sizeof(int) * 10);
    array->size = 0;
    array->capacity = 10;
    return array;
}

void addIntPriorityQueueArray(IntPriorityQueueArrayArray* array, IntPriorityQueueArray* queueArray) {
    if (array->size == array->capacity) {
        array->capacity *= 2;
        array->arr = (int*)realloc(array->arr, sizeof(int) * array->capacity);
    }
    array->arr[array->size++] = queueArray;
}

typedef struct {
    long* arr;
    int size;
    int capacity;
} LongPriorityQueueArrayArray;

LongPriorityQueueArrayArray* newLongPriorityQueueArrayArray() {
    LongPriorityQueueArrayArray* array = (LongPriorityQueueArrayArray*)malloc(sizeof(LongPriorityQueueArrayArray));
    array->arr = (long*)malloc(sizeof(long) * 10);
    array->size = 0;
    array->capacity = 10;
    return array;
}

void addLongPriorityQueueArray(LongPriorityQueueArrayArray* array, LongPriorityQueueArray* queueArray) {
    if (array->size == array->capacity) {
        array->capacity *= 2;
        array->arr = (long*)realloc(array->arr, sizeof(long) * array->capacity);
    }
    array->arr[array->size++] = queueArray;
}

typedef struct {
    int* arr;
    int size;
    int capacity;
} IntHashSetArrayArray;

IntHashSetArrayArray* newIntHashSetArrayArray() {
    IntHashSetArrayArray* array = (IntHashSetArrayArray*)malloc(sizeof(IntHashSetArrayArray));
    array->arr = (int*)malloc(sizeof(int) * 10);
    array->size = 0;
    array->capacity = 10;
    return array;
}

void addIntHashSetArray(IntHashSetArrayArray* array, IntHashSetArray* setArray) {
    if (array->size == array->capacity) {
        array->capacity *= 2;
        array->arr = (int*)realloc(array->arr, sizeof(int) * array->capacity);
    }
    array->arr[array->size++] = setArray;
}

typedef struct {
    long* arr;
    int size;
    int capacity;
} LongHashSetArrayArray;

LongHashSetArrayArray* newLongHashSetArrayArray() {
    LongHashSetArrayArray* array = (LongHashSetArrayArray*)malloc(sizeof(LongHashSetArrayArray));
    array->arr = (long*)malloc(sizeof(long) * 10);
    array->size = 0;
    array->capacity = 10;
    return array;
}

void addLongHashSetArray(LongHashSetArrayArray* array, LongHashSetArray* setArray) {
    if (array->size == array->capacity) {
        array->capacity *= 2;
        array->arr = (long*)realloc(array->arr, sizeof(long) * array->capacity);
    }
    array->arr[array->size++] = setArray;
}

typedef struct {
    int* arr;
    int size;
    int capacity;
} IntHashMapArrayArray;

IntHashMapArrayArray* newIntHashMapArrayArray() {
    IntHashMapArrayArray* array = (IntHashMapArrayArray*)malloc(sizeof(IntHashMapArrayArray));
    array->arr = (int*)malloc(sizeof(int) * 10);
    array->size = 0;
    array->capacity = 10;
    return array;
}

void addIntHashMapArray(IntHashMapArrayArray* array, IntHashMapArray* mapArray) {
    if (array->size == array->capacity) {
        array->capacity *= 2;
        array->arr = (int*)realloc(array->arr, sizeof(int) * array->capacity);
    }
    array->arr[array->size++] = mapArray;
}

typedef struct {
    long* arr;
    int size;
    int capacity;
} LongHashMapArrayArray;

LongHashMapArrayArray* newLongHashMapArrayArray() {
    LongHashMapArrayArray* array = (LongHashMapArrayArray*)malloc(sizeof(LongHashMapArrayArray));
    array->arr = (long*)malloc(sizeof(long) * 10);
    array->size = 0;
    array->capacity = 10;
    return array;
}


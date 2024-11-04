#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int* data;
    int size;
} IntList;

IntList* createIntList(int size) {
    IntList* list = (IntList*)malloc(sizeof(IntList));
    list->data = (int*)malloc(sizeof(int) * size);
    list->size = size;
    return list;
}

void freeIntList(IntList* list) {
    free(list->data);
    free(list);
}

int getIntList(IntList* list, int index) {
    return list->data[index];
}

void setIntList(IntList* list, int index, int value) {
    list->data[index] = value;
}

void addIntList(IntList* list, int value) {
    list->data = (int*)realloc(list->data, sizeof(int) * (list->size + 1));
    list->data[list->size] = value;
    list->size++;
}

void removeAtIntList(IntList* list, int index) {
    for (int i = index; i < list->size - 1; i++) {
        list->data[i] = list->data[i + 1];
    }
    list->size--;
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

void freeIntArray(IntArray* array) {
    free(array->data);
    free(array);
}

int getIntArray(IntArray* array, int index) {
    return array->data[index];
}

void setIntArray(IntArray* array, int index, int value) {
    array->data[index] = value;
}

typedef struct {
    int at;
    int removed;
    IntList* list;
} IntIterator;

IntIterator* createIntIterator(IntList* list) {
    IntIterator* iterator = (IntIterator*)malloc(sizeof(IntIterator));
    iterator->at = 0;
    iterator->removed = 0;
    iterator->list = list;
    return iterator;
}

void freeIntIterator(IntIterator* iterator) {
    free(iterator);
}

int intIteratorValue(IntIterator* iterator) {
    if (iterator->removed) {
        printf("IllegalStateException\n");
        exit(1);
    }
    return getIntList(iterator->list, iterator->at);
}

int intIteratorAdvance(IntIterator* iterator) {
    iterator->at++;
    iterator->removed = 0;
    return intIteratorIsValid(iterator);
}

int intIteratorIsValid(IntIterator* iterator) {
    return !iterator->removed && iterator->at < iterator->list->size;
}

void intIteratorRemove(IntIterator* iterator) {
    removeAtIntList(iterator->list, iterator->at);
    iterator->at--;
    iterator->removed = 1;
}

typedef struct {
    IntIterator* (*intIterator)(IntList*);
} IntCollection;

typedef struct {
    IntIterator* (*intIterator)(IntList*);
    int (*size)(IntList*);
    void (*add)(IntList*, int);
    int (*get)(IntList*, int);
    void (*set)(IntList*, int, int);
    void (*removeAt)(IntList*, int);
} IntListInterface;

IntIterator* intListIntIterator(IntList* list) {
    return createIntIterator(list);
}

int intListSize(IntList* list) {
    return list->size;
}

void intListAdd(IntList* list, int value) {
    addIntList(list, value);
}

int intListGet(IntList* list, int index) {
    return getIntList(list, index);
}

void intListSet(IntList* list, int index, int value) {
    setIntList(list, index, value);
}

void intListRemoveAt(IntList* list, int index) {
    removeAtIntList(list, index);
}

IntListInterface* createIntListInterface() {
    IntListInterface* interface = (IntListInterface*)malloc(sizeof(IntListInterface));
    interface->intIterator = intListIntIterator;
    interface->size = intListSize;
    interface->add = intListAdd;
    interface->get = intListGet;
    interface->set = intListSet;
    interface->removeAt = intListRemoveAt;
    return interface;
}

typedef struct {
    int* data;
    int size;
} IntArrayList;

IntArrayList* createIntArrayList(int size) {
    IntArrayList* list = (IntArrayList*)malloc(sizeof(IntArrayList));
    list->data = (int*)malloc(sizeof(int) * size);
    list->size = size;
    return list;
}

void freeIntArrayList(IntArrayList* list) {
    free(list->data);
    free(list);
}

int getIntArrayList(IntArrayList* list, int index) {
    return list->data[index];
}

void setIntArrayList(IntArrayList* list, int index, int value) {
    list->data[index] = value;
}

void addAtIntArrayList(IntArrayList* list, int index, int value) {
    list->data = (int*)realloc(list->data, sizeof(int) * (list->size + 1));
    for (int i = list->size; i > index; i--) {
        list->data[i] = list->data[i - 1];
    }
    list->data[index] = value;
    list->size++;
}

void removeAtIntArrayList(IntArrayList* list, int index) {
    for (int i = index; i < list->size - 1; i++) {
        list->data[i] = list->data[i + 1];
    }
    list->size--;
}

typedef struct {
    int* data;
    int size;
} IntArrayIterator;

IntArrayIterator* createIntArrayIterator(IntArrayList* list) {
    IntArrayIterator* iterator = (IntArrayIterator*)malloc(sizeof(IntArrayIterator));
    iterator->data = list->data;
    iterator->size = list->size;
    return iterator;
}

void freeIntArrayIterator(IntArrayIterator* iterator) {
    free(iterator);
}

int intArrayIteratorValue(IntArrayIterator* iterator) {
    return *iterator->data;
}

int intArrayIteratorAdvance(IntArrayIterator* iterator) {
    iterator->data++;
    iterator->size--;
    return intArrayIteratorIsValid(iterator);
}

int intArrayIteratorIsValid(IntArrayIterator* iterator) {
    return iterator->size > 0;
}

typedef struct {
    IntArrayIterator* (*intIterator)(IntArrayList*);
} IntArrayInterface;

IntArrayIterator* intArrayIntArrayIterator(IntArrayList* list) {
    return createIntArrayIterator(list);
}

IntArrayInterface* createIntArrayInterface() {
    IntArrayInterface* interface = (IntArrayInterface*)malloc(sizeof(IntArrayInterface));
    interface->intIterator = intArrayIntArrayIterator;
    return interface;
}

typedef struct {
    int at;
    int removed;
    IntArrayList* list;
} IntArrayIteratorWrapper;

IntArrayIteratorWrapper* createIntArrayIteratorWrapper(IntArrayList* list) {
    IntArrayIteratorWrapper* iterator = (IntArrayIteratorWrapper*)malloc(sizeof(IntArrayIteratorWrapper));
    iterator->at = 0;
    iterator->removed = 0;
    iterator->list = list;
    return iterator;
}

void freeIntArrayIteratorWrapper(IntArrayIteratorWrapper* iterator) {
    free(iterator);
}

int intArrayIteratorWrapperValue(IntArrayIteratorWrapper* iterator) {
    if (iterator->removed) {
        printf("IllegalStateException\n");
        exit(1);
    }
    return getIntArrayList(iterator->list, iterator->at);
}

int intArrayIteratorWrapperAdvance(IntArrayIteratorWrapper* iterator) {
    iterator->at++;
    iterator->removed = 0;
    return intArrayIteratorWrapperIsValid(iterator);
}

int intArrayIteratorWrapperIsValid(IntArrayIteratorWrapper* iterator) {
    return !iterator->removed && iterator->at < iterator->list->size;
}

void intArrayIteratorWrapperRemove(IntArrayIteratorWrapper* iterator) {
    removeAtIntArrayList(iterator->list, iterator->at);
    iterator->at--;
    iterator->removed = 1;
}

typedef struct {
    IntArrayIteratorWrapper* (*intIterator)(IntArrayList*);
} IntArrayListInterface;

IntArrayIteratorWrapper* intArrayListIntArrayIterator(IntArrayList* list) {
    return createIntArrayIteratorWrapper(list);
}

IntArrayListInterface* createIntArrayListInterface() {
    IntArrayListInterface* interface = (IntArrayListInterface*)malloc(sizeof(IntArrayListInterface));
    interface->intIterator = intArrayListIntArrayIterator;
    return interface;
}

typedef struct {
    IntList* (*range)(int, int);
} RangeInterface;

IntList* range(int from, int to) {
    IntList* list = createIntList(to - from);
    for (int i = from; i < to; i++) {
        addIntList(list, i);
    }
    return list;
}

RangeInterface* createRangeInterface() {
    RangeInterface* interface = (RangeInterface*)malloc(sizeof(RangeInterface));
    interface->range = range;
    return interface;
}

typedef struct {
    int (*compare)(int, int);
} IntComparator;

int intComparatorCompare(int first, int second) {
    if (first < second) {
        return -1;
    }
    if (first > second) {
        return 1;
    }
    return 0;
}

IntComparator* createIntComparator() {
    IntComparator* comparator = (IntComparator*)malloc(sizeof(IntComparator));
    comparator->compare = intComparatorCompare;
    return comparator;
}

typedef struct {
    int** data;
    int size;
} IntArrayArray;

IntArrayArray* createIntArrayArray(int size) {
    IntArrayArray* array = (IntArrayArray*)malloc(sizeof(IntArrayArray));
    array->data = (int**)malloc(sizeof(int*) * size);
    array->size = size;
    return array;
}

void freeIntArrayArray(IntArrayArray* array) {
    free(array->data);
    free(array);
}

int* getIntArrayArray(IntArrayArray* array, int index) {
    return array->data[index];
}

void setIntArrayArray(IntArrayArray* array, int index, int* value) {
    array->data[index] = value;
}

typedef struct {
    int* data;
    int size;
} IntArrayIteratorArray;

IntArrayIteratorArray* createIntArrayIteratorArray(int size) {
    IntArrayIteratorArray* array = (IntArrayIteratorArray*)malloc(sizeof(IntArrayIteratorArray));
    array->data = (int*)malloc(sizeof(int) * size);
    array->size = size;
    return array;
}

void freeIntArrayIteratorArray(IntArrayIteratorArray* array) {
    free(array->data);
    free(array);
}

int intArrayIteratorArrayValue(IntArrayIteratorArray* array, int index) {
    return array->data[index];
}

void intArrayIteratorArraySetValue(IntArrayIteratorArray* array, int index, int value) {
    array->data[index] = value;
}

typedef struct {
    int at;
    int removed;
    IntArrayIteratorArray* array;
} IntArrayIteratorArrayIterator;

IntArrayIteratorArrayIterator* createIntArrayIteratorArrayIterator(IntArrayIteratorArray* array) {
    IntArrayIteratorArrayIterator* iterator = (IntArrayIteratorArrayIterator*)malloc(sizeof(IntArrayIteratorArrayIterator));
    iterator->at = 0;
    iterator->removed = 0;
    iterator->array = array;
    return iterator;
}

void freeIntArrayIteratorArrayIterator(IntArrayIteratorArrayIterator* iterator) {
    free(iterator);
}

int intArrayIteratorArrayIteratorValue(IntArrayIteratorArrayIterator* iterator) {
    if (iterator->removed) {
        printf("IllegalStateException\n");
        exit(1);
    }
    return intArrayIteratorArrayValue(iterator->array, iterator->at);
}

int intArrayIteratorArrayIteratorAdvance(IntArrayIteratorArrayIterator* iterator) {
    iterator->at++;
    iterator->removed = 0;
    return intArrayIteratorArrayIteratorIsValid(iterator);
}

int intArrayIteratorArrayIteratorIsValid(IntArrayIteratorArrayIterator* iterator) {
    return !iterator->removed && iterator->at < iterator->array->size;
}

void intArrayIteratorArrayIteratorRemove(IntArrayIteratorArrayIterator* iterator) {
    for (int i = iterator->at; i < iterator->array->size - 1; i++) {
        iterator->array->data[i] = iterator->array->data[i + 1];
    }
    iterator->array->size--;
    iterator->at--;
    iterator->removed = 1;
}

typedef struct {
    IntArrayIteratorArrayIterator* (*intIterator)(IntArrayIteratorArray*);
} IntArrayIteratorArrayInterface;

IntArrayIteratorArrayIterator* intArrayIteratorArrayIntArrayIterator(IntArrayIteratorArray* array) {
    return createIntArrayIteratorArrayIterator(array);
}

IntArrayIteratorArrayInterface* createIntArrayIteratorArrayInterface() {
    IntArrayIteratorArrayInterface* interface = (IntArrayIteratorArrayInterface*)malloc(sizeof(IntArrayIteratorArrayInterface));
    interface->intIterator = intArrayIteratorArrayIntArrayIterator;
    return interface;
}

typedef struct {
    int at;
    int removed;
    IntArrayArray* array;
} IntArrayArrayIterator;

IntArrayArrayIterator* createIntArrayArrayIterator(IntArrayArray* array) {
    IntArrayArrayIterator* iterator = (IntArrayArrayIterator*)malloc(sizeof(IntArrayArrayIterator));
    iterator->at = 0;
    iterator->removed = 0;
    iterator->array = array;
    return iterator;
}

void freeIntArrayArrayIterator(IntArrayArrayIterator* iterator) {
    free(iterator);
}

int* intArrayArrayIteratorValue(IntArrayArrayIterator* iterator) {
    if (iterator->removed) {
        printf("IllegalStateException\n");
        exit(1);
    }
    return getIntArrayArray(iterator->array, iterator->at);
}

int intArrayArrayIteratorAdvance(IntArrayArrayIterator* iterator) {
    iterator->at++;
    iterator->removed = 0;
    return intArrayArrayIteratorIsValid(iterator);
}

int intArrayArrayIteratorIsValid(IntArrayArrayIterator* iterator) {
    return !iterator->removed && iterator->at < iterator->array->size;
}

void intArrayArrayIteratorRemove(IntArrayArrayIterator* iterator) {
    for (int i = iterator->at; i < iterator->array->size - 1; i++) {
        iterator->array->data[i] = iterator->array->data[i + 1];
    }
    iterator->array->size--;
    iterator->at--;
    iterator->removed = 1;
}

typedef struct {
    IntArrayArrayIterator* (*intIterator)(IntArrayArray*);
} IntArrayArrayInterface;

IntArrayArrayIterator* intArrayArrayIntArrayIterator(IntArrayArray* array) {
    return createIntArrayArrayIterator(array);
}

IntArrayArrayInterface* createIntArrayArrayInterface() {
    IntArrayArrayInterface* interface = (IntArrayArrayInterface*)malloc(sizeof(IntArrayArrayInterface));
    interface->intIterator = intArrayArrayIntArrayIterator;
    return interface;
}

typedef struct {
    int* data;
    int size;
} IntArrayIteratorArrayWrapper;

IntArrayIteratorArrayWrapper* createIntArrayIteratorArrayWrapper(IntArrayIteratorArray* array) {
    IntArrayIteratorArrayWrapper* iterator = (IntArrayIteratorArrayWrapper*)malloc(sizeof(IntArrayIteratorArrayWrapper));
    iterator->data = array->data;
    iterator->size = array->size;
    return iterator;
}

void freeIntArrayIteratorArrayWrapper(IntArrayIteratorArrayWrapper* iterator) {
    free(iterator);
}

int intArrayIteratorArrayWrapperValue(IntArrayIteratorArrayWrapper* iterator) {
    if (iterator->removed) {
        printf("IllegalStateException\n");
        exit(1);
    }
    return *iterator->data;
}

int intArrayIteratorArrayWrapperAdvance(IntArrayIteratorArrayWrapper* iterator) {
    iterator->data++;
    iterator->size--;
    return intArrayIteratorArrayWrapperIsValid(iterator);
}

int intArrayIteratorArrayWrapperIsValid(IntArrayIteratorArrayWrapper* iterator) {
    return iterator->size > 0;
}

void intArrayIteratorArrayWrapperRemove(IntArrayIteratorArrayWrapper* iterator) {
    for (int i = iterator->at; i < iterator->array->size - 1; i++) {
        iterator->array->data[i] = iterator->array->data[i + 1];
    }
    iterator->array->size--;
    iterator->at--;
    iterator->removed = 1;
}

typedef struct {
    IntArrayIteratorArrayWrapper* (*intIterator)(IntArrayIteratorArray*);
} IntArrayIteratorArrayWrapperInterface;

IntArrayIteratorArrayWrapper* intArrayIteratorArrayWrapperIntArrayIterator(IntArrayIteratorArray* array) {
    return createIntArrayIteratorArrayWrapper(array);
}

IntArrayIteratorArrayWrapperInterface* createIntArrayIteratorArrayWrapperInterface() {
    IntArrayIteratorArrayWrapperInterface* interface = (IntArrayIteratorArrayWrapperInterface*)malloc(sizeof(IntArrayIteratorArrayWrapperInterface));
    interface->intIterator = intArrayIteratorArrayWrapperIntArrayIterator;
    return interface;
}

typedef struct {
    int at;
    int removed;
    IntArrayIteratorArrayWrapper* iterator;
} IntArrayIteratorArrayWrapperIterator;

IntArrayIteratorArrayWrapperIterator* createIntArrayIteratorArrayWrapperIterator(IntArrayIteratorArrayWrapper* iterator) {
    IntArrayIteratorArrayWrapperIterator* wrapperIterator = (IntArrayIteratorArrayWrapperIterator*)malloc(sizeof(IntArrayIteratorArrayWrapperIterator));
    wrapperIterator->at = 0;
    wrapperIterator->removed = 0;
    wrapperIterator->iterator = iterator;
    return wrapperIterator;
}

void freeIntArrayIteratorArrayWrapperIterator(IntArrayIteratorArrayWrapperIterator* iterator) {
    free(iterator);
}

int intArrayIteratorArrayWrapperIteratorValue(IntArrayIteratorArrayWrapperIterator* iterator) {
    if (iterator->removed) {
        printf("IllegalStateException\n");
        exit(1);
    }
    return intArrayIteratorArrayWrapperValue(iterator->iterator);
}

int intArrayIteratorArrayWrapperIteratorAdvance(IntArrayIteratorArrayWrapperIterator* iterator) {
    iterator->at++;
    iterator->removed = 0;
    return intArrayIteratorArrayWrapperIteratorIsValid(iterator);
}

int intArrayIteratorArrayWrapperIteratorIsValid(IntArrayIteratorArrayWrapperIterator* iterator) {
    return !iterator->removed && iterator->at < iterator->iterator->size;
}

void intArrayIteratorArrayWrapperIteratorRemove(IntArrayIteratorArrayWrapperIterator* iterator) {
    intArrayIteratorArrayWrapperRemove(iterator->iterator);
    iterator->at--;
    iterator->removed = 1;
}

typedef struct {
    IntArrayIteratorArrayWrapperIterator* (*intIterator)(IntArrayIteratorArrayWrapper*);
} IntArrayIteratorArrayWrapperInterface;

IntArrayIteratorArrayWrapperIterator* intArrayIteratorArrayWrapperIntArrayIterator(IntArrayIteratorArrayWrapper* iterator) {
    return createIntArrayIteratorArrayWrapperIterator(iterator);
}

IntArrayIteratorArrayWrapperInterface* createIntArrayIteratorArrayWrapperInterface() {
    IntArrayIteratorArrayWrapperInterface* interface = (IntArrayIteratorArrayWrapperInterface*)malloc(sizeof(IntArrayIteratorArrayWrapperInterface));
    interface->intIterator = intArrayIteratorArrayWrapperIntArrayIterator;
    return interface;
}

typedef struct {
    int* data;
    int size;
} IntArrayArrayIteratorWrapper;

IntArrayArrayIteratorWrapper* createIntArrayArrayIteratorWrapper(IntArrayArray* array) {
    IntArrayArrayIteratorWrapper* iterator = (IntArrayArrayIteratorWrapper*)malloc(sizeof(IntArrayArrayIteratorWrapper));
    iterator->at = 0;
    iterator->removed = 0;
    iterator->array = array;
    return iterator;
}

void freeIntArrayArrayIteratorWrapper(IntArrayArrayIteratorWrapper* iterator) {
    free(iterator);
}

int* intArrayArrayIteratorWrapperValue(IntArrayArrayIteratorWrapper* iterator) {
    if (iterator->removed) {
        printf("IllegalStateException\n");
        exit(1);
    }
    return getIntArrayArray(iterator->array, iterator->at);
}

int intArrayArrayIteratorWrapperAdvance(IntArrayArrayIteratorWrapper* iterator) {
    iterator->at++;
    iterator->removed = 0;
    return intArrayArrayIteratorWrapperIsValid(iterator);
}

int intArrayArrayIteratorWrapperIsValid(IntArrayArrayIteratorWrapper* iterator) {
    return !iterator->removed && iterator->at < iterator->array->size;
}

void intArrayArrayIteratorWrapperRemove(IntArrayArrayIteratorWrapper* iterator) {
    for (int i = iterator->at; i < iterator->array->size - 1; i++) {
        iterator->array->data[i] = iterator->array->data[i + 1];
    }
    iterator->array->size--;
    iterator->at--;
    iterator->removed = 1;
}

typedef struct {
    IntArrayArrayIteratorWrapper* (*intIterator)(IntArrayArrayWrapper*);
} IntArrayArrayIteratorWrapperInterface;

IntArrayArrayIteratorWrapper* intArrayArrayIteratorWrapperIntArrayIterator(IntArrayArrayWrapper* iterator) {
    return createIntArrayArrayIteratorWrapper(iterator);
}

IntArrayArrayIteratorWrapperInterface* createIntArrayArrayIteratorWrapperInterface() {
    IntArrayArrayIteratorWrapperInterface* interface = (IntArrayArrayIteratorWrapperInterface*)malloc(sizeof(IntArrayArrayIteratorWrapperInterface));
    interface->intIterator = intArrayArrayIteratorWrapperIntArrayIterator;
    return interface;
}

typedef struct {
    IntArrayArrayIteratorWrapper* data;
    int size;
} IntArrayArrayWrapper;

IntArrayArrayWrapper* createIntArrayArrayWrapper(int size) {
    IntArrayArrayWrapper* wrapper = (IntArrayArrayWrapper*)malloc(sizeof(IntArrayArrayWrapper));
    wrapper->data = (IntArrayArrayIteratorWrapper*)malloc(sizeof(IntArrayArrayIteratorWrapper) * size);
    wrapper->size = size;
    return wrapper;
}

void freeIntArrayArrayWrapper(IntArrayArrayWrapper* wrapper) {
    free(wrapper->data);
    free(wrapper);
}

IntArrayArrayIteratorWrapper* getIntArrayArrayWrapper(IntArrayArrayWrapper* wrapper, int index) {
    return &wrapper->data[index];
}

void setIntArrayArrayWrapper(IntArrayArrayWrapper* wrapper, int index, IntArrayArrayIteratorWrapper* value) {
    wrapper->data[index] = *value;
}

typedef struct {
    IntArrayArrayIteratorWrapper* (*intIterator)(IntArrayArrayWrapper*);
} IntArrayArrayWrapperInterface;

IntArrayArrayIteratorWrapper* intArrayArrayWrapperIntArrayIterator(IntArrayArrayWrapper* wrapper) {
    return &wrapper->data[0];
}

IntArrayArrayWrapperInterface* createIntArrayArrayWrapperInterface() {
    IntArrayArrayWrapperInterface* interface = (IntArrayArrayWrapperInterface*)malloc(sizeof(IntArrayArrayWrapperInterface));
    interface->intIterator = intArrayArrayWrapperIntArrayIterator;
    return interface;
}

typedef struct {
    int at;
    int removed;
    IntArrayArrayWrapper* wrapper;
} IntArrayArrayWrapperIterator;

IntArrayArrayWrapperIterator* createIntArrayArrayWrapperIterator(IntArrayArrayWrapper* wrapper) {
    IntArrayArrayWrapperIterator* iterator = (IntArrayArrayWrapperIterator*)malloc(sizeof(IntArrayArrayWrapperIterator));
    iterator->at = 0;
    iterator->removed = 0;
    iterator->wrapper = wrapper;
    return iterator;
}

void freeIntArrayArrayWrapperIterator(IntArrayArrayWrapperIterator* iterator) {
    free(iterator);
}

IntArrayArrayIteratorWrapper* intArrayArrayWrapperIteratorValue(IntArrayArrayWrapperIterator* iterator) {
    if (iterator->removed) {
        printf("IllegalStateException\n");
        exit(1);
    }
    return getIntArrayArrayWrapper(iterator->wrapper, iterator->at);
}

int intArrayArrayWrapperIteratorAdvance(IntArrayArrayWrapperIterator* iterator) {
    iterator->at++;
    iterator->removed = 0;
    return intArrayArrayWrapperIteratorIsValid(iterator);
}

int intArrayArrayWrapperIteratorIsValid(IntArrayArrayWrapperIterator* iterator) {
    return !iterator->removed && iterator->at < iterator->wrapper->size;
}

void intArrayArrayWrapperIteratorRemove(IntArrayArrayWrapperIterator* iterator) {
    for (int i = iterator->at; i < iterator->wrapper->size - 1; i++) {
        iterator->wrapper->data[i] = iterator->wrapper->data[i + 1];
    }
    iterator->wrapper->size--;
    iterator->at--;
    iterator->removed = 1;
}

typedef struct {
    IntArrayArrayWrapperIterator* (*intIterator)(IntArrayArrayWrapper*);
} IntArrayArrayWrapperInterface;

IntArrayArrayWrapperIterator* intArrayArrayWrapperIntArrayIterator(IntArrayArrayWrapper* wrapper) {
    return createIntArrayArrayWrapperIterator(wrapper);
}

IntArrayArrayWrapperInterface* createIntArrayArrayWrapperInterface() {
    IntArrayArrayWrapperInterface* interface = (IntArrayArrayWrapperInterface*)malloc(sizeof(IntArrayArrayWrapperInterface));
    interface->intIterator = intArrayArrayWrapperIntArrayIterator;
    return interface;
}

typedef struct {
    int* data;
    int size;
} IntArrayListArray;

IntArrayListArray* createIntArrayListArray(int size) {
    IntArrayListArray* array = (IntArrayListArray*)malloc(sizeof(IntArrayListArray));
    array->data = (int*)malloc(sizeof(int) * size);
    array->size = size;
    return array;
}

void freeIntArrayListArray(IntArrayListArray* array) {
    free(array->data);
    free(array);
}

int getIntArrayListArray(IntArrayListArray* array, int index) {
    return array->data[index];
}

void setIntArrayListArray(IntArrayListArray* array, int index, int value) {
    array->data[index] = value;
}

typedef struct {
    int* data;
    int size;
} IntArrayListIteratorArray;

IntArrayListIteratorArray* createIntArrayListIteratorArray(int size) {
    IntArrayListIteratorArray* array = (IntArrayListIteratorArray*)malloc(sizeof(IntArrayListIteratorArray));
    array->data = (int*)malloc(sizeof(int) * size);
    array->size = size;
    return array;
}

void freeIntArrayListIteratorArray(IntArrayListIteratorArray* array) {
    free(array->data);
    free(array);
}

int intArrayListIteratorArrayValue(IntArrayListIteratorArray* array, int index) {
    return array->data[index];
}

void intArrayListIteratorArraySetValue(IntArrayListIteratorArray* array, int index, int value) {
    array->data[index] = value;
}

typedef struct {
    int at;
    int removed;
    IntArrayListIteratorArray* array;
} IntArrayListIteratorArrayIterator;

IntArrayListIteratorArrayIterator* createIntArrayListIteratorArrayIterator(IntArrayListIteratorArray* array) {
    IntArrayListIteratorArrayIterator* iterator = (IntArrayListIteratorArrayIterator*)malloc(sizeof(IntArrayListIteratorArrayIterator));
    iterator->at = 0;
    iterator->removed = 0;
    iterator->array = array;
    return iterator;
}

void freeIntArrayListIteratorArrayIterator(IntArrayListIteratorArrayIterator* iterator) {
    free(iterator);
}

int intArrayListIteratorArrayIteratorValue(IntArrayListIteratorArrayIterator* iterator) {
    if (iterator->removed) {
        printf("IllegalStateException\n");
        exit(1);
    }
    return intArrayListIteratorArrayValue(iterator->array, iterator->at);
}

int intArrayListIteratorArrayIteratorAdvance(IntArrayListIteratorArrayIterator* iterator) {
    iterator->at++;
    iterator->removed = 0;
    return intArrayListIteratorArrayIteratorIsValid(iterator);
}

int intArrayListIteratorArrayIteratorIsValid(IntArrayListIteratorArrayIterator* iterator) {
    return !iterator->removed && iterator->at < iterator->array->size;
}

void intArrayListIteratorArrayIteratorRemove(IntArrayListIteratorArrayIterator* iterator) {
    for (int i = iterator->at; i < iterator->array->size - 1; i++) {
        iterator->array->data[i] = iterator->array->data[i + 1];
    }
    iterator->array->size--;
    iterator->at--;
    iterator->removed = 1;
}

typedef struct {
    IntArrayListIteratorArrayIterator* (*intIterator)(IntArrayListIteratorArray*);
} IntArrayListIteratorArrayInterface;

IntArrayListIteratorArrayIterator* intArrayListIteratorArrayIntArrayIterator(IntArrayListIteratorArray* array) {
    return createIntArrayListIteratorArrayIterator(array);
}

IntArrayListIteratorArrayInterface* createIntArrayListIteratorArrayInterface() {
    IntArrayListIteratorArrayInterface* interface = (IntArrayListIteratorArrayInterface*)malloc(sizeof(IntArrayListIteratorArrayInterface));
    interface->intIterator = intArrayListIteratorArrayIntArrayIterator;
    return interface;
}

typedef struct {
    int* data;
    int size;
} IntArrayListArrayIterator;

IntArrayListArrayIterator* createIntArrayListArrayIterator(IntArrayListArray* array) {
    IntArrayListArrayIterator* iterator = (IntArrayListArrayIterator*)malloc(sizeof(IntArrayListArrayIterator));
    iterator->at = 0;
    iterator->removed = 0;
    iterator->array = array;
    return iterator;
}

void freeIntArrayListArrayIterator(IntArrayListArrayIterator* iterator) {
    free(iterator);
}

int* intArrayListArrayIteratorValue(IntArrayListArrayIterator* iterator) {
    if (iterator->removed) {
        printf("IllegalStateException\n");
        exit(1);
    }
    return getIntArrayListArray(iterator->array, iterator->at);
}

int intArrayListArrayIteratorAdvance(IntArrayListArrayIterator* iterator) {
    iterator->at++;
    iterator->removed = 0;
    return intArrayListArrayIteratorIsValid(iterator);
}

int intArrayListArrayIteratorIsValid(IntArrayListArrayIterator* iterator) {
    return !iterator->removed && iterator->at < iterator->array->size;
}

void intArrayListArrayIteratorRemove(IntArrayListArrayIterator* iterator) {
    for (int i = iterator->at; i < iterator->array->size - 1; i++) {
        iterator->array->data[i] = iterator->array->data[i + 1];
    }
    iterator->array->size--;
    iterator->at--;
    iterator->removed = 1;
}

typedef struct {
    IntArrayListArrayIterator* (*intIterator)(IntArrayListArray*);
} IntArrayListArrayInterface;

IntArrayListArrayIterator* intArrayListArrayIntArrayIterator(IntArrayListArray* array) {
    return createIntArrayListArrayIterator(array);
}

IntArrayListArrayInterface* createIntArrayListArrayInterface() {
    IntArrayListArrayInterface* interface = (IntArrayListArrayInterface*)malloc(sizeof(IntArrayListArrayInterface));
    interface->intIterator = intArrayListArrayIntArrayIterator;
    return interface;
}

typedef struct {
    int at;
    int removed;
    IntArrayListArray* array;
} IntArrayListArrayWrapper;

IntArrayListArrayWrapper* createIntArrayListArrayWrapper(IntArrayListArray* array) {
    IntArrayListArrayWrapper* wrapper = (IntArrayListArrayWrapper*)malloc(sizeof(IntArrayListArrayWrapper));
    wrapper->at = 0;
    wrapper->removed = 0;
    wrapper->array = array;
    return wrapper;
}

void freeIntArrayListArrayWrapper(IntArrayListArrayWrapper* wrapper) {
    free(wrapper);
}

int intArrayListArrayWrapperValue(IntArrayListArrayWrapper* wrapper) {
    if (wrapper->removed) {
        printf("IllegalStateException\n");
        exit(1);
    }
    return getIntArrayListArray(wrapper->array, wrapper->at);
}

int intArrayListArrayWrapperAdvance(IntArrayListArrayWrapper* wrapper) {
    wrapper->at++;
    wrapper->removed = 0;
    return intArrayListArrayWrapperIsValid(wrapper);
}

int intArrayListArrayWrapperIsValid(IntArrayListArrayWrapper* wrapper) {
    return !wrapper->removed && wrapper->at < wrapper->array->size;
}

void intArrayListArrayWrapperRemove(IntArrayListArrayWrapper* wrapper) {
    for (int i = wrapper->at; i < wrapper->array->size - 1; i++) {
        wrapper->array->data[i] = wrapper->array->data[i + 1];
    }
    wrapper->array->size--;
    wrapper->at--;
    wrapper->removed = 1;
}

typedef struct {
    IntArrayListArrayWrapper* (*intIterator)(IntArrayListArray*);
} IntArrayListArrayWrapperInterface;

IntArrayListArrayWrapper* intArrayListArrayWrapperIntArrayIterator(IntArrayListArray* array) {
    return createIntArrayListArrayWrapper(array);
}

IntArrayListArrayWrapperInterface* createIntArrayListArrayWrapperInterface() {
    IntArrayListArrayWrapperInterface* interface = (IntArrayListArrayWrapperInterface*)malloc(sizeof(IntArrayListArrayWrapperInterface));
    interface->intIterator = intArrayListArrayWrapperIntArrayIterator;
    return interface;
}

typedef struct {
    int* data;
    int size;
} IntArrayListArrayIteratorWrapper;

IntArrayListArrayIteratorWrapper* createIntArrayListArrayIteratorWrapper(IntArrayListArray* array) {
    IntArrayListArrayIteratorWrapper* iterator = (IntArrayListArrayIteratorWrapper*)malloc(sizeof(IntArrayListArrayIteratorWrapper));
    iterator->at = 0;
    iterator->removed = 0;
    iterator->array = array;
    return iterator;
}

void freeIntArrayListArrayIteratorWrapper(IntArrayListArrayIteratorWrapper* iterator) {
    free(iterator);
}

int intArrayListArrayIteratorWrapperValue(IntArrayListArrayIteratorWrapper* iterator) {
    if (iterator->removed) {
        printf("IllegalStateException\n");
        exit(1);
    }
    return intArrayListArrayWrapperValue(iterator->array);
}

int intArrayListArrayIteratorWrapperAdvance(IntArrayListArrayIteratorWrapper* iterator) {
    iterator->at++;
    iterator->removed = 0;
    return intArrayListArrayIteratorWrapperIsValid(iterator);
}

int intArrayListArrayIteratorWrapperIsValid(IntArrayListArrayIteratorWrapper* iterator) {
    return !iterator->removed && iterator->at < iterator->array->size;
}

void intArrayListArrayIteratorWrapperRemove(IntArrayListArrayIteratorWrapper* iterator) {
    intArrayListArrayWrapperRemove(iterator->array);
    iterator->at--;
    iterator->removed = 1;
}

typedef struct {
    IntArrayListArrayIteratorWrapper* (*intIterator)(IntArrayListArrayWrapper*);
} IntArrayListArrayIteratorWrapperInterface;

IntArrayListArrayIteratorWrapper* intArrayListArrayIteratorWrapperIntArrayIterator(IntArrayListArrayWrapper* iterator) {
    return createIntArrayListArrayIteratorWrapper(iterator);
}

IntArrayListArrayIteratorWrapperInterface* createIntArrayListArrayIteratorWrapperInterface() {
    IntArrayListArrayIteratorWrapperInterface* interface = (IntArrayListArrayIteratorWrapperInterface*)malloc(sizeof(IntArrayListArrayIteratorWrapperInterface));
    interface->intIterator = intArrayListArrayIteratorWrapperIntArrayIterator;
    return interface;
}

typedef struct {
    int* data;
    int size;
} IntArrayListArrayWrapperIterator;

IntArrayListArrayWrapperIterator* createIntArrayListArrayWrapperIterator(IntArrayListArrayWrapper* iterator) {
    IntArrayListArrayWrapperIterator* wrapperIterator = (IntArrayListArrayWrapperIterator*)malloc(sizeof(IntArrayListArrayWrapperIterator));
    wrapperIterator->at = 0;
    wrapperIterator->removed = 0;
    wrapperIterator->iterator = iterator;
    return wrapperIterator;
}

void freeIntArrayListArrayWrapperIterator(IntArrayListArrayWrapperIterator* iterator) {
    free(iterator);
}

int intArrayListArrayWrapperIteratorValue(IntArrayListArrayWrapperIterator* iterator) {
    if (iterator->removed) {
        printf("IllegalStateException\n");
        exit(1);
    }
    return intArrayListArrayIteratorWrapperValue(iterator->iterator);
}

int intArrayListArrayWrapperIteratorAdvance(IntArrayListArrayWrapperIterator* iterator) {
    iterator->at++;
    iterator->removed = 0;
    return intArrayListArrayWrapperIteratorIsValid(iterator);
}

int intArrayListArrayWrapperIteratorIsValid(IntArrayListArrayWrapperIterator* iterator) {
    return !iterator->removed && iterator->at < iterator->iterator->array->size;
}

void intArrayListArrayWrapperIteratorRemove(IntArrayListArrayWrapperIterator* iterator) {
    intArrayListArrayWrapperRemove(iterator->iterator);
    iterator->at--;
    iterator->removed = 1;
}

typedef struct {
    IntArrayListArrayWrapperIterator* (*intIterator)(IntArrayListArrayWrapper*);
} IntArrayListArrayWrapperInterface;

IntArrayListArrayWrapperIterator* intArrayListArrayWrapperIntArrayIterator(IntArrayListArrayWrapper* iterator) {
    return createIntArrayListArrayWrapperIterator(iterator);
}

IntArrayListArrayWrapperInterface* createIntArrayListArrayWrapperInterface() {
    IntArrayListArrayWrapperInterface* interface = (IntArrayListArrayWrapperInterface*)malloc(sizeof(IntArrayListArrayWrapperInterface));
    interface->intIterator = intArrayListArrayWrapperIntArrayIterator;
    return interface;
}

typedef struct {
    int* data;
    int size;
} IntArrayArrayArray;

IntArrayArrayArray* createIntArrayArrayArray(int size) {

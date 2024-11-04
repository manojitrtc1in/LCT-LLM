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

void destroyIntList(IntList* list) {
    free(list->data);
    free(list);
}

int getIntList(IntList* list, int index) {
    return list->data[index];
}

void setIntList(IntList* list, int index, int value) {
    list->data[index] = value;
}

void addAtIntList(IntList* list, int index, int value) {
    list->data = (int*)realloc(list->data, sizeof(int) * (list->size + 1));
    for (int i = list->size - 1; i >= index; i--) {
        list->data[i + 1] = list->data[i];
    }
    list->data[index] = value;
    list->size++;
}

void removeAtIntList(IntList* list, int index) {
    for (int i = index; i < list->size - 1; i++) {
        list->data[i] = list->data[i + 1];
    }
    list->data = (int*)realloc(list->data, sizeof(int) * (list->size - 1));
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

void destroyIntArray(IntArray* array) {
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

void destroyIntIterator(IntIterator* iterator) {
    free(iterator);
}

int valueIntIterator(IntIterator* iterator) {
    if (iterator->removed) {
        printf("IllegalStateException\n");
        exit(1);
    }
    return getIntList(iterator->list, iterator->at);
}

int advanceIntIterator(IntIterator* iterator) {
    iterator->at++;
    iterator->removed = 0;
    return isValidIntIterator(iterator);
}

int isValidIntIterator(IntIterator* iterator) {
    return !iterator->removed && iterator->at < iterator->list->size;
}

void removeIntIterator(IntIterator* iterator) {
    removeAtIntList(iterator->list, iterator->at);
    iterator->at--;
    iterator->removed = 1;
}

typedef struct {
    int* data;
    int size;
} IntStream;

IntIterator* intIteratorIntStream(IntStream* stream);

IntStream* createIntStream(IntList* list) {
    IntStream* stream = (IntStream*)malloc(sizeof(IntStream));
    stream->data = list->data;
    stream->size = list->size;
    return stream;
}

void destroyIntStream(IntStream* stream) {
    free(stream);
}

IntIterator* intIteratorIntStream(IntStream* stream) {
    return createIntIterator(createIntList(stream->size));
}

int compareIntStream(IntStream* stream1, IntStream* stream2) {
    IntIterator* it1 = intIteratorIntStream(stream1);
    IntIterator* it2 = intIteratorIntStream(stream2);
    while (isValidIntIterator(it1) && isValidIntIterator(it2)) {
        int i = valueIntIterator(it1);
        int j = valueIntIterator(it2);
        if (i < j) {
            return -1;
        } else if (i > j) {
            return 1;
        }
        advanceIntIterator(it1);
        advanceIntIterator(it2);
    }
    if (isValidIntIterator(it1)) {
        return 1;
    }
    if (isValidIntIterator(it2)) {
        return -1;
    }
    return 0;
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

void destroyIntArray(IntArray* array) {
    free(array->data);
    free(array);
}

int getIntArray(IntArray* array, int index) {
    return array->data[index];
}

void setIntArray(IntArray* array, int index, int value) {
    array->data[index] = value;
}

void fillIntArray(IntArray* array, int value) {
    for (int i = 0; i < array->size; i++) {
        array->data[i] = value;
    }
}

typedef struct {
    int** data;
    int size;
} LongArray2D;

LongArray2D* createLongArray2D(int size1, int size2) {
    LongArray2D* array = (LongArray2D*)malloc(sizeof(LongArray2D));
    array->data = (int**)malloc(sizeof(int*) * size1);
    for (int i = 0; i < size1; i++) {
        array->data[i] = (int*)malloc(sizeof(int) * size2);
    }
    array->size = size1;
    return array;
}

void destroyLongArray2D(LongArray2D* array) {
    for (int i = 0; i < array->size; i++) {
        free(array->data[i]);
    }
    free(array->data);
    free(array);
}

int getLongArray2D(LongArray2D* array, int index1, int index2) {
    return array->data[index1][index2];
}

void setLongArray2D(LongArray2D* array, int index1, int index2, int value) {
    array->data[index1][index2] = value;
}

void fillLongArray2D(LongArray2D* array, int value) {
    for (int i = 0; i < array->size; i++) {
        for (int j = 0; j < array->size; j++) {
            array->data[i][j] = value;
        }
    }
}

typedef struct {
    int** data;
    int size;
} LongArray3D;

LongArray3D* createLongArray3D(int size1, int size2, int size3) {
    LongArray3D* array = (LongArray3D*)malloc(sizeof(LongArray3D));
    array->data = (int**)malloc(sizeof(int*) * size1);
    for (int i = 0; i < size1; i++) {
        array->data[i] = (int*)malloc(sizeof(int) * size2);
        for (int j = 0; j < size2; j++) {
            array->data[i][j] = (int*)malloc(sizeof(int) * size3);
        }
    }
    array->size = size1;
    return array;
}

void destroyLongArray3D(LongArray3D* array) {
    for (int i = 0; i < array->size; i++) {
        for (int j = 0; j < array->size; j++) {
            free(array->data[i][j]);
        }
        free(array->data[i]);
    }
    free(array->data);
    free(array);
}

int getLongArray3D(LongArray3D* array, int index1, int index2, int index3) {
    return array->data[index1][index2][index3];
}

void setLongArray3D(LongArray3D* array, int index1, int index2, int index3, int value) {
    array->data[index1][index2][index3] = value;
}

void fillLongArray3D(LongArray3D* array, int value) {
    for (int i = 0; i < array->size; i++) {
        for (int j = 0; j < array->size; j++) {
            for (int k = 0; k < array->size; k++) {
                array->data[i][j][k] = value;
            }
        }
    }
}

typedef struct {
    int* data;
    int size;
} Range;

Range* range(int from, int to) {
    Range* range = (Range*)malloc(sizeof(Range));
    range->data = (int*)malloc(sizeof(int) * abs(from - to));
    range->size = abs(from - to);
    int current = from;
    if (from <= to) {
        for (int i = 0; i < range->size; i++) {
            range->data[i] = current++;
        }
    } else {
        for (int i = 0; i < range->size; i++) {
            range->data[i] = current--;
        }
    }
    return range;
}

void destroyRange(Range* range) {
    free(range->data);
    free(range);
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

void destroyIntArray(IntArray* array) {
    free(array->data);
    free(array);
}

int getIntArray(IntArray* array, int index) {
    return array->data[index];
}

void setIntArray(IntArray* array, int index, int value) {
    array->data[index] = value;
}

void fillIntArray(IntArray* array, int value) {
    for (int i = 0; i < array->size; i++) {
        array->data[i] = value;
    }
}

typedef struct {
    int** data;
    int size;
} LongArray2D;

LongArray2D* createLongArray2D(int size1, int size2) {
    LongArray2D* array = (LongArray2D*)malloc(sizeof(LongArray2D));
    array->data = (int**)malloc(sizeof(int*) * size1);
    for (int i = 0; i < size1; i++) {
        array->data[i] = (int*)malloc(sizeof(int) * size2);
    }
    array->size = size1;
    return array;
}

void destroyLongArray2D(LongArray2D* array) {
    for (int i = 0; i < array->size; i++) {
        free(array->data[i]);
    }
    free(array->data);
    free(array);
}

int getLongArray2D(LongArray2D* array, int index1, int index2) {
    return array->data[index1][index2];
}

void setLongArray2D(LongArray2D* array, int index1, int index2, int value) {
    array->data[index1][index2] = value;
}

void fillLongArray2D(LongArray2D* array, int value) {
    for (int i = 0; i < array->size; i++) {
        for (int j = 0; j < array->size; j++) {
            array->data[i][j] = value;
        }
    }
}

typedef struct {
    int** data;
    int size;
} LongArray3D;

LongArray3D* createLongArray3D(int size1, int size2, int size3) {
    LongArray3D* array = (LongArray3D*)malloc(sizeof(LongArray3D));
    array->data = (int**)malloc(sizeof(int*) * size1);
    for (int i = 0; i < size1; i++) {
        array->data[i] = (int*)malloc(sizeof(int) * size2);
        for (int j = 0; j < size2; j++) {
            array->data[i][j] = (int*)malloc(sizeof(int) * size3);
        }
    }
    array->size = size1;
    return array;
}

void destroyLongArray3D(LongArray3D* array) {
    for (int i = 0; i < array->size; i++) {
        for (int j = 0; j < array->size; j++) {
            free(array->data[i][j]);
        }
        free(array->data[i]);
    }
    free(array->data);
    free(array);
}

int getLongArray3D(LongArray3D* array, int index1, int index2, int index3) {
    return array->data[index1][index2][index3];
}

void setLongArray3D(LongArray3D* array, int index1, int index2, int index3, int value) {
    array->data[index1][index2][index3] = value;
}

void fillLongArray3D(LongArray3D* array, int value) {
    for (int i = 0; i < array->size; i++) {
        for (int j = 0; j < array->size; j++) {
            for (int k = 0; k < array->size; k++) {
                array->data[i][j][k] = value;
            }
        }
    }
}

typedef struct {
    int* data;
    int size;
} Range;

Range* range(int from, int to) {
    Range* range = (Range*)malloc(sizeof(Range));
    range->data = (int*)malloc(sizeof(int) * abs(from - to));
    range->size = abs(from - to);
    int current = from;
    if (from <= to) {
        for (int i = 0; i < range->size; i++) {
            range->data[i] = current++;
        }
    } else {
        for (int i = 0; i < range->size; i++) {
            range->data[i] = current--;
        }
    }
    return range;
}

void destroyRange(Range* range) {
    free(range->data);
    free(range);
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

void destroyIntArray(IntArray* array) {
    free(array->data);
    free(array);
}

int getIntArray(IntArray* array, int index) {
    return array->data[index];
}

void setIntArray(IntArray* array, int index, int value) {
    array->data[index] = value;
}

void fillIntArray(IntArray* array, int value) {
    for (int i = 0; i < array->size; i++) {
        array->data[i] = value;
    }
}

typedef struct {
    int** data;
    int size;
} LongArray2D;

LongArray2D* createLongArray2D(int size1, int size2) {
    LongArray2D* array = (LongArray2D*)malloc(sizeof(LongArray2D));
    array->data = (int**)malloc(sizeof(int*) * size1);
    for (int i = 0; i < size1; i++) {
        array->data[i] = (int*)malloc(sizeof(int) * size2);
    }
    array->size = size1;
    return array;
}

void destroyLongArray2D(LongArray2D* array) {
    for (int i = 0; i < array->size; i++) {
        free(array->data[i]);
    }
    free(array->data);
    free(array);
}

int getLongArray2D(LongArray2D* array, int index1, int index2) {
    return array->data[index1][index2];
}

void setLongArray2D(LongArray2D* array, int index1, int index2, int value) {
    array->data[index1][index2] = value;
}

void fillLongArray2D(LongArray2D* array, int value) {
    for (int i = 0; i < array->size; i++) {
        for (int j = 0; j < array->size; j++) {
            array->data[i][j] = value;
        }
    }
}

typedef struct {
    int** data;
    int size;
} LongArray3D;

LongArray3D* createLongArray3D(int size1, int size2, int size3) {
    LongArray3D* array = (LongArray3D*)malloc(sizeof(LongArray3D));
    array->data = (int**)malloc(sizeof(int*) * size1);
    for (int i = 0; i < size1; i++) {
        array->data[i] = (int*)malloc(sizeof(int) * size2);
        for (int j = 0; j < size2; j++) {
            array->data[i][j] = (int*)malloc(sizeof(int) * size3);
        }
    }
    array->size = size1;
    return array;
}

void destroyLongArray3D(LongArray3D* array) {
    for (int i = 0; i < array->size; i++) {
        for (int j = 0; j < array->size; j++) {
            free(array->data[i][j]);
        }
        free(array->data[i]);
    }
    free(array->data);
    free(array);
}

int getLongArray3D(LongArray3D* array, int index1, int index2, int index3) {
    return array->data[index1][index2][index3];
}

void setLongArray3D(LongArray3D* array, int index1, int index2, int index3, int value) {
    array->data[index1][index2][index3] = value;
}

void fillLongArray3D(LongArray3D* array, int value) {
    for (int i = 0; i < array->size; i++) {
        for (int j = 0; j < array->size; j++) {
            for (int k = 0; k < array->size; k++) {
                array->data[i][j][k] = value;
            }
        }
    }
}

typedef struct {
    int* data;
    int size;
} Range;

Range* range(int from, int to) {
    Range* range = (Range*)malloc(sizeof(Range));
    range->data = (int*)malloc(sizeof(int) * abs(from - to));
    range->size = abs(from - to);
    int current = from;
    if (from <= to) {
        for (int i = 0; i < range->size; i++) {
            range->data[i] = current++;
        }
    } else {
        for (int i = 0; i < range->size; i++) {
            range->data[i] = current--;
        }
    }
    return range;
}

void destroyRange(Range* range) {
    free(range->data);
    free(range);
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

void destroyIntArray(IntArray* array) {
    free(array->data);
    free(array);
}

int getIntArray(IntArray* array, int index) {
    return array->data[index];
}

void setIntArray(IntArray* array, int index, int value) {
    array->data[index] = value;
}

void fillIntArray(IntArray* array, int value) {
    for (int i = 0; i < array->size; i++) {
        array->data[i] = value;
    }
}

typedef struct {
    int** data;
    int size;
} LongArray2D;

LongArray2D* createLongArray2D(int size1, int size2) {
    LongArray2D* array = (LongArray2D*)malloc(sizeof(LongArray2D));
    array->data = (int**)malloc(sizeof(int*) * size1);
    for (int i = 0; i < size1; i++) {
        array->data[i] = (int*)malloc(sizeof(int) * size2);
    }
    array->size = size1;
    return array;
}

void destroyLongArray2D(LongArray2D* array) {
    for (int i = 0; i < array->size; i++) {
        free(array->data[i]);
    }
    free(array->data);
    free(array);
}

int getLongArray2D(LongArray2D* array, int index1, int index2) {
    return array->data[index1][index2];
}

void setLongArray2D(LongArray2D* array, int index1, int index2, int value) {
    array->data[index1][index2] = value;
}

void fillLongArray2D(LongArray2D* array, int value) {
    for (int i = 0; i < array->size; i++) {
        for (int j = 0; j < array->size; j++) {
            array->data[i][j] = value;
        }
    }
}

typedef struct {
    int** data;
    int size;
} LongArray3D;

LongArray3D* createLongArray3D(int size1, int size2, int size3) {
    LongArray3D* array = (LongArray3D*)malloc(sizeof(LongArray3D));
    array->data = (int**)malloc(sizeof(int*) * size1);
    for (int i = 0; i < size1; i++) {
        array->data[i] = (int*)malloc(sizeof(int) * size2);
        for (int j = 0; j < size2; j++) {
            array->data[i][j] = (int*)malloc(sizeof(int) * size3);
        }
    }
    array->size = size1;
    return array;
}

void destroyLongArray3D(LongArray3D* array) {
    for (int i = 0; i < array->size; i++) {
        for (int j = 0; j < array->size; j++) {
            free(array->data[i][j]);
        }
        free(array->data[i]);
    }
    free(array->data);
    free(array);
}

int getLongArray3D(LongArray3D* array, int index1, int index2, int index3) {
    return array->data[index1][index2][index3];
}

void setLongArray3D(LongArray3D* array, int index1, int index2, int index3, int value) {
    array->data[index1][index2][index3] = value;
}

void fillLongArray3D(LongArray3D* array, int value) {
    for (int i = 0; i < array->size; i++) {
        for (int j = 0; j < array->size; j++) {
            for (int k = 0; k < array->size; k++) {
                array->data[i][j][k] = value;
            }
        }
    }
}

typedef struct {
    int* data;
    int size;
} Range;

Range* range(int from, int to) {
    Range* range = (Range*)malloc(sizeof(Range));
    range->data = (int*)malloc(sizeof(int) * abs(from - to));
    range->size = abs(from - to);
    int current = from;
    if (from <= to) {
        for (int i = 0; i < range->size; i++) {
            range->data[i] = current++;
        }
    } else {
        for (int i = 0; i < range->size; i++) {
            range->data[i] = current--;
        }
    }
    return range;
}

void destroyRange(Range* range) {
    free(range->data);
    free(range);
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

void destroyIntArray(IntArray* array) {
    free(array->data);
    free(array);
}

int getIntArray(IntArray* array, int index) {
    return array->data[index];
}

void setIntArray(IntArray* array, int index, int value) {
    array->data[index] = value;
}

void fillIntArray(IntArray* array, int value) {
    for (int i = 0; i < array->size; i++) {
        array->data[i] = value;
    }
}

typedef struct {
    int** data;
    int size;
} LongArray2D;

LongArray2D* createLongArray2D(int size1, int size2) {
    LongArray2D* array = (LongArray2D*)malloc(sizeof(LongArray2D));
    array->data = (int**)malloc(sizeof(int*) * size1);
    for (int i = 0; i < size1; i++) {
        array->data[i] = (int*)malloc(sizeof(int) * size2);
    }
    array->size = size1;
    return array;
}

void destroyLongArray2D(LongArray2D* array) {
    for (int i = 0; i < array->size; i++) {
        free(array->data[i]);
    }
    free(array->data);
    free(array);
}

int getLongArray2D(LongArray2D* array, int index1, int index2) {
    return array->data[index1][index2];
}

void setLongArray2D(LongArray2D* array, int index1, int index2, int value) {
    array->data[index1][index2] = value;
}

void fillLongArray2D(LongArray2D* array, int value) {
    for (int i = 0; i < array->size; i++) {
        for (int j = 0; j < array->size; j++) {
            array->data[i][j] = value;
        }
    }
}

typedef struct {
    int** data;
    int size;
} LongArray3D;

LongArray3D* createLongArray3D(int size1, int size2, int size3) {
    LongArray3D* array = (LongArray3D*)malloc(sizeof(LongArray3D));
    array->data = (int**)malloc(sizeof(int*) * size1);
    for (int i = 0; i < size1; i++) {
        array->data[i] = (int*)malloc(sizeof(int) * size2);
        for (int j = 0; j < size2; j++) {
            array->data[i][j] = (int*)malloc(sizeof(int) * size3);
        }
    }
    array->size = size1;
    return array;
}

void destroyLongArray3D(LongArray3D* array) {
    for (int i = 0; i < array->size; i++) {
        for (int j = 0; j < array->size; j++) {
            free(array->data[i][j]);
        }
        free(array->data[i]);
    }
    free(array->data);
    free(array);
}

int getLongArray3D(LongArray3D* array, int index1, int index2, int index3) {
    return array->data[index1][index2][index3];
}

void setLongArray3D(LongArray3D* array, int index1, int index2, int index3, int value) {
    array->data[index1][index2][index3] = value;
}

void fillLongArray3D(LongArray3D* array, int value) {
    for (int i = 0; i < array->size; i++) {
        for (int j = 0; j < array->size; j++) {
            for (int k = 0; k < array->size; k++) {
                array->data[i][j][k] = value;
            }
        }
    }
}

typedef struct {
    int* data;
    int size;
} Range;

Range* range(int from, int to) {
    Range* range = (Range*)malloc(sizeof(Range));
    range->data = (int*)malloc(sizeof(int) * abs(from - to));
    range->size = abs(from - to);
    int current = from;
    if (from <= to) {
        for (int i = 0; i < range->size; i++) {
            range->data[i] = current++;
        }
    } else {
        for (int i = 0; i < range->size; i++) {
            range->data[i] = current--;
        }
    }
    return range;
}

void destroyRange(Range* range) {
    free(range->data);
    free(range);
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

void destroyIntArray(IntArray* array) {
    free(array->data);
    free(array);
}

int getIntArray(IntArray* array, int index) {
    return array->data[index];
}

void setIntArray(IntArray* array, int index, int value) {
    array->data[index] = value;
}

void fillIntArray(IntArray* array, int value) {
    for (int i = 0; i < array->size; i++) {
        array->data[i] = value;
    }
}

typedef struct {
    int** data;
    int size;
} LongArray2D;

LongArray2D* createLongArray2D(int size1, int size2) {
    LongArray2D* array = (LongArray2D*)malloc(sizeof(LongArray2D));
    array->data = (int**)malloc(sizeof(int*) * size1);
    for (int i = 0; i < size1; i++) {
        array->data[i] = (int*)malloc(sizeof(int) * size2);
    }
    array->size = size1;
    return array;
}

void destroyLongArray2D(LongArray2D* array) {
    for (int i = 0; i < array->size; i++) {
        free(array->data[i]);
    }
    free(array->data);
    free(array);
}

int getLongArray2D(LongArray2D* array, int index1, int index2) {
    return array->data[index1][index2];
}

void setLongArray2D(LongArray2D* array, int index1, int index2, int value) {
    array->data[index1][index2] = value;
}

void fillLongArray2D(LongArray2D* array, int value) {
    for (int i = 0; i < array->size; i++) {
        for (int j = 0; j < array->size; j++) {
            array->data[i][j] = value;
        }
    }
}

typedef struct {
    int** data;
    int size;
} LongArray3D;

LongArray3D* createLongArray3D(int size1, int size2, int size3) {
    LongArray3D* array = (LongArray3D*)malloc(sizeof(LongArray3D));
    array->data = (int**)malloc(sizeof(int*) * size1);
    for (int i = 0; i < size1; i++) {
        array->data[i] = (int*)malloc(sizeof(int) * size2);
        for (int j = 0; j < size2; j++) {
            array->data[i][j] = (int*)malloc(sizeof(int) * size3);
        }
    }
    array->size = size1;
    return array;
}

void destroyLongArray3D(LongArray3D* array) {
    for (int i = 0; i < array->size; i++) {
        for (int j = 0; j < array->size; j++) {
            free(array->data[i][j]);
        }
        free(array->data[i]);
    }
    free(array->data);
    free(array);
}

int getLongArray3D(LongArray3D* array, int index1, int index2, int index3) {
    return array->data[index1][index2][index3];
}

void setLongArray3D(LongArray3D* array, int index1, int index2, int index3, int value) {
    array->data[index1][index2][index3] = value;
}

void fillLongArray3D(LongArray3D* array, int value) {
    for (int i = 0; i < array->size; i++) {
        for (int j = 0; j < array->size; j++) {
            for (int k = 0; k < array->size; k++) {
                array->data[i][j][k] = value;
            }
        }
    }
}

typedef struct {
    int* data;
    int size;
} Range;

Range* range(int from, int to) {
    Range* range = (Range*)malloc(sizeof(Range));
    range->data = (int*)malloc(sizeof(int) * abs(from - to));
    range->size = abs(from - to);
    int current = from;
    if (from <= to) {
        for (int i = 0; i < range->size; i++) {
            range->data[i] = current++;
        }
    } else {
        for (int i = 0; i < range->size; i++) {
            range->data[i] = current--;
        }
    }
    return range;
}

void destroyRange(Range* range) {
    free(range->data);
    free(range);
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

void destroyIntArray(IntArray* array) {
    free(array->data);
    free(array);
}

int getIntArray(IntArray* array, int index) {
    return array->data[index];
}

void setIntArray(IntArray* array, int index, int value) {
    array->data[index] = value;
}

void fillIntArray(IntArray* array, int value) {
    for (int i = 0; i < array->size; i++) {
        array->data[i] = value;
    }
}

typedef struct {
    int* data;
    int size;
} Range;

Range* range(int from, int to) {
    Range* range = (Range*)malloc(sizeof(Range));
    range->data = (int*)malloc(sizeof(int) * abs(from - to));
    range->size = abs(from - to);
    int current = from;
    if (from <= to) {
        for (int i = 0; i < range->size; i++) {
            range->data[i] = current++;
        }
    } else {
        for (int i = 0; i < range->size; i++) {
            range->data[i] = current--;
        }
    }
    return range;
}

void destroyRange(Range* range) {
    free(range->data);
    free(range);
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

void destroyIntArray(IntArray* array) {
    free(array->data);
    free(array);
}

int getIntArray(IntArray* array, int index) {
    return array->data[index];
}

void setIntArray(IntArray* array, int index, int value) {
    array->data[index] = value;
}

void fillIntArray(IntArray* array, int value) {
    for (int i = 0; i < array->size; i++) {
        array->data[i] = value;
    }
}

typedef struct {
    int* data;
    int size;
} Range;

Range* range(int from, int to) {
    Range* range = (Range*)malloc(sizeof(Range));
    range->data = (int*)malloc(sizeof(int) * abs(from - to));
    range->size = abs(from - to);
    int current = from;
    if (from <= to) {
        for (int i = 0; i < range->size; i++) {
            range->data[i] = current++;
        }
    } else {
        for (int i = 0; i < range->size; i++) {
            range->data[i] = current--;
        }
    }
    return range;
}

void destroyRange(Range* range) {
    free(range->data);
    free(range);
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

void destroyIntArray(IntArray* array) {
    free(array->data);
    free(array);
}

int getIntArray(IntArray* array, int index) {
    return array->data[index];
}

void setIntArray(IntArray* array, int index, int value) {
    array->data[index] = value;
}

void fillIntArray(IntArray* array, int value) {
    for (int i = 0; i < array->size; i++) {
        array->data[i] = value;
    }
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

void destroyIntArray(IntArray* array) {
    free(array->data);
    free(array);
}

int getIntArray(IntArray* array, int index) {
    return array->data[index];
}

void setIntArray(IntArray* array, int index, int value) {
    array->data[index] = value;
}

void fillIntArray(IntArray* array, int value) {
    for (int i = 0; i < array->size; i++) {
        array->data[i] = value;
    }
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

void destroyIntArray(IntArray* array) {
    free(array->data);
    free(array);
}

int getIntArray(IntArray* array, int index) {
    return array->data[index];
}

void setIntArray(IntArray* array, int index, int value) {
    array->data[index] = value;
}

void fillIntArray(IntArray* array, int value) {
    for (int i = 0; i < array->size; i++) {
        array->data[i] = value;
    }
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

void destroyIntArray(IntArray* array) {
    free(array->data);
    free(array);
}

int getIntArray(IntArray* array, int index) {
    return array->data[index];
}

void setIntArray(IntArray* array, int index, int value) {
    array->data[index] = value;
}

void fillIntArray(IntArray* array, int value) {
    for (int i = 0; i < array->size; i++) {
        array->data[i] = value;
    }
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

void destroyIntArray(IntArray* array) {
    free(array->data);
    free(array);
}

int getIntArray(IntArray* array, int index) {
    return array->data[index];
}

void setIntArray(IntArray* array, int index, int value) {
    array->data[index] = value;
}

void fillIntArray(IntArray* array, int value) {
    for (int i = 0; i < array->size; i++) {
        array->data[i] = value;
    }
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

void destroyIntArray(IntArray* array) {
    free(array->data);
    free(array);
}

int getIntArray(IntArray* array, int index) {
    return array->data[index];
}

void setIntArray(IntArray* array, int index, int value) {
    array->data[index] = value;
}

void fillIntArray(IntArray* array, int value) {
    for (int i = 0; i < array->size; i++) {
        array->data[i] = value;
    }
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

void destroyIntArray(IntArray* array) {
    free(array->data);
    free(array);
}

int getIntArray(IntArray* array, int index) {
    return array->data[index];
}

void setIntArray(IntArray* array, int index, int value) {
    array->data[index] = value;
}

void fillIntArray(IntArray* array, int value) {
    for (int i = 0; i < array->size; i++) {
        array->data[i] = value;
    }
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

void destroyIntArray(IntArray* array) {
    free(array->data);
    free(array);
}

int getIntArray(IntArray* array, int index) {
    return array->data[index];
}

void setIntArray(IntArray* array, int index, int value) {
    array->data[index] = value;
}

void fillIntArray(IntArray* array, int value) {
    for (int i = 0; i < array->size; i++) {
        array->data[i] = value;
    }
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

void destroyIntArray(IntArray* array) {
    free(array->data);
    free(array);
}

int getIntArray(IntArray* array, int index) {
    return array->data[index];
}

void setIntArray(IntArray* array, int index, int value) {
    array->data[index] = value;
}

void fillIntArray(IntArray* array, int value) {
    for (int i = 0; i < array->size; i++) {
        array->data[i] = value;
    }
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

void destroyIntArray(IntArray* array) {
    free(array->data);
    free(array);
}

int getIntArray(IntArray* array, int index) {
    return array->data[index];
}

void setIntArray(IntArray* array, int index, int value) {
    array->data[index] = value;
}

void fillIntArray(IntArray* array, int value) {
    for (int i = 0; i < array->size; i++) {
        array->data[i] = value;
    }
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

void destroyIntArray(IntArray* array) {
    free(array->data);
    free(array);
}

int getIntArray(IntArray* array, int index) {
    return array->data[index];
}

void setIntArray(IntArray* array, int index, int value) {
    array->data[index] = value;
}

void fillIntArray(IntArray* array, int value) {
    for (int i = 0; i < array->size; i++) {
        array->data[i] = value;
    }
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

void destroyIntArray(IntArray* array) {
    free(array->data);
    free(array);
}

int getIntArray(IntArray* array, int index) {
    return array->data[index];
}

void setIntArray(IntArray* array, int index, int value) {
    array->data[index] = value;
}

void fillIntArray(IntArray* array, int value) {
    for (int i = 0; i < array->size; i++) {
        array->data[i] = value;
    }
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

void destroyIntArray(IntArray* array) {
    free(array->data);
    free(array);
}

int getIntArray(IntArray* array, int index) {
    return array->data[index];
}

void setIntArray(IntArray* array, int index, int value) {
    array->data[index] = value;
}

void fillIntArray(IntArray* array, int value) {
    for (int i = 0; i < array->size; i++) {
        array->data[i] = value;
    }
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

void destroyIntArray(IntArray* array) {
    free(array->data);
    free(array);
}

int getIntArray(IntArray* array, int index) {
    return array->data[index];
}

void setIntArray(IntArray* array, int index, int value) {
    array->data[index] = value;
}

void fillIntArray(IntArray* array, int value) {
    for (int i = 0; i < array->size; i++) {
        array->data[i] = value;
    }
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

void destroyIntArray(IntArray* array) {
    free(array->data);
    free(array);
}

int getIntArray(IntArray* array, int index) {
    return array->data[index];
}

void setIntArray(IntArray* array, int index, int value) {
    array->data[index] = value;
}

void fillIntArray(IntArray* array, int value) {
    for (int i = 0; i < array->size; i++) {
        array->data[i] = value;
    }
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

void destroyIntArray(IntArray* array) {
    free(array->data);
    free(array);
}

int getIntArray(IntArray* array, int index) {
    return array->data[index];
}

void setIntArray(IntArray* array, int index, int value) {
    array->data[index] = value;
}

void fillIntArray(IntArray* array, int value) {
    for (int i = 0; i < array->size; i++) {
        array->data[i] = value;
    }
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

void destroyIntArray(IntArray* array) {
    free(array->data);
    free(array);
}

int getIntArray(IntArray* array, int index) {
    return array->data[index];
}

void setIntArray(IntArray* array, int index, int value) {
    array->data[index] = value;
}

void fillIntArray(IntArray* array, int value) {
    for (int i = 0; i < array->size; i++) {
        array->data[i] = value;
    }
}


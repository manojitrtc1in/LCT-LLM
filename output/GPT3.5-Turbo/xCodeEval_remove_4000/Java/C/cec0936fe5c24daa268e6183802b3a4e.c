#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int* data;
    int size;
    int capacity;
} IntList;

IntList* createIntList() {
    IntList* list = (IntList*)malloc(sizeof(IntList));
    list->data = (int*)malloc(sizeof(int) * 3);
    list->size = 0;
    list->capacity = 3;
    return list;
}

void destroyIntList(IntList* list) {
    free(list->data);
    free(list);
}

void ensureCapacity(IntList* list, int capacity) {
    if (list->capacity >= capacity) {
        return;
    }
    capacity = (list->capacity * 2 > capacity) ? list->capacity * 2 : capacity;
    list->data = (int*)realloc(list->data, sizeof(int) * capacity);
    list->capacity = capacity;
}

void add(IntList* list, int value) {
    ensureCapacity(list, list->size + 1);
    list->data[list->size++] = value;
}

int get(IntList* list, int index) {
    if (index >= list->size) {
        printf("Index out of bounds\n");
        exit(1);
    }
    return list->data[index];
}

void set(IntList* list, int index, int value) {
    if (index >= list->size) {
        printf("Index out of bounds\n");
        exit(1);
    }
    list->data[index] = value;
}

void addAt(IntList* list, int index, int value) {
    ensureCapacity(list, list->size + 1);
    if (index > list->size || index < 0) {
        printf("Index out of bounds\n");
        exit(1);
    }
    if (index != list->size) {
        for (int i = list->size - 1; i >= index; i--) {
            list->data[i + 1] = list->data[i];
        }
    }
    list->data[index] = value;
    list->size++;
}

void removeAt(IntList* list, int index) {
    if (index >= list->size || index < 0) {
        printf("Index out of bounds\n");
        exit(1);
    }
    if (index != list->size - 1) {
        for (int i = index; i < list->size - 1; i++) {
            list->data[i] = list->data[i + 1];
        }
    }
    list->size--;
}

typedef struct {
    int at;
    bool removed;
    IntList* list;
} IntIterator;

IntIterator* createIntIterator(IntList* list) {
    IntIterator* iterator = (IntIterator*)malloc(sizeof(IntIterator));
    iterator->at = 0;
    iterator->removed = false;
    iterator->list = list;
    return iterator;
}

void destroyIntIterator(IntIterator* iterator) {
    free(iterator);
}

int value(IntIterator* iterator) {
    if (iterator->removed) {
        printf("Invalid operation\n");
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

void sort(IntArray* array, int from, int to) {
    if (from >= to) {
        return;
    }
    int pivotIndex = (from + to) / 2;
    int pivot = array->data[pivotIndex];
    array->data[pivotIndex] = array->data[to];
    array->data[to] = pivot;
    int storeIndex = from;
    int equalIndex = to;
    for (int i = from; i < equalIndex; i++) {
        if (array->data[i] < pivot) {
            int temp = array->data[i];
            array->data[i] = array->data[storeIndex];
            array->data[storeIndex] = temp;
            storeIndex++;
        } else if (array->data[i] == pivot) {
            equalIndex--;
            int temp = array->data[i];
            array->data[i] = array->data[equalIndex];
            array->data[equalIndex] = temp;
            i--;
        }
    }
    for (int i = equalIndex; i <= to; i++) {
        int temp = array->data[i];
        array->data[i] = array->data[storeIndex];
        array->data[storeIndex] = temp;
        storeIndex++;
    }
    sort(array, from, storeIndex - 2);
    sort(array, storeIndex, to);
}

void reverse(IntArray* array, int from, int to) {
    while (from < to) {
        int temp = array->data[from];
        array->data[from] = array->data[to];
        array->data[to] = temp;
        from++;
        to--;
    }
}

typedef struct {
    int* data;
    int size;
} IntRange;

IntRange* createIntRange(int from, int to) {
    IntRange* range = (IntRange*)malloc(sizeof(IntRange));
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

void destroyIntRange(IntRange* range) {
    free(range->data);
    free(range);
}

typedef struct {
    int* data;
    int size;
    int capacity;
} LongList;

LongList* createLongList() {
    LongList* list = (LongList*)malloc(sizeof(LongList));
    list->data = (int*)malloc(sizeof(int) * 3);
    list->size = 0;
    list->capacity = 3;
    return list;
}

void destroyLongList(LongList* list) {
    free(list->data);
    free(list);
}

void ensureCapacity(LongList* list, int capacity) {
    if (list->capacity >= capacity) {
        return;
    }
    capacity = (list->capacity * 2 > capacity) ? list->capacity * 2 : capacity;
    list->data = (int*)realloc(list->data, sizeof(int) * capacity);
    list->capacity = capacity;
}

void addLong(LongList* list, int value) {
    ensureCapacity(list, list->size + 1);
    list->data[list->size++] = value;
}

int getLong(LongList* list, int index) {
    if (index >= list->size) {
        printf("Index out of bounds\n");
        exit(1);
    }
    return list->data[index];
}

void setLong(LongList* list, int index, int value) {
    if (index >= list->size) {
        printf("Index out of bounds\n");
        exit(1);
    }
    list->data[index] = value;
}

void addAtLong(LongList* list, int index, int value) {
    ensureCapacity(list, list->size + 1);
    if (index > list->size || index < 0) {
        printf("Index out of bounds\n");
        exit(1);
    }
    if (index != list->size) {
        for (int i = list->size - 1; i >= index; i--) {
            list->data[i + 1] = list->data[i];
        }
    }
    list->data[index] = value;
    list->size++;
}

void removeAtLong(LongList* list, int index) {
    if (index >= list->size || index < 0) {
        printf("Index out of bounds\n");
        exit(1);
    }
    if (index != list->size - 1) {
        for (int i = index; i < list->size - 1; i++) {
            list->data[i] = list->data[i + 1];
        }
    }
    list->size--;
}

typedef struct {
    int at;
    bool removed;
    LongList* list;
} LongIterator;

LongIterator* createLongIterator(LongList* list) {
    LongIterator* iterator = (LongIterator*)malloc(sizeof(LongIterator));
    iterator->at = 0;
    iterator->removed = false;
    iterator->list = list;
    return iterator;
}

void destroyLongIterator(LongIterator* iterator) {
    free(iterator);
}

int valueLong(LongIterator* iterator) {
    if (iterator->removed) {
        printf("Invalid operation\n");
        exit(1);
    }
    return getLong(iterator->list, iterator->at);
}

bool advanceLong(LongIterator* iterator) {
    iterator->at++;
    iterator->removed = false;
    return isValidLong(iterator);
}

bool isValidLong(LongIterator* iterator) {
    return !iterator->removed && iterator->at < iterator->list->size;
}

void removeLong(LongIterator* iterator) {
    removeAtLong(iterator->list, iterator->at);
    iterator->at--;
    iterator->removed = true;
}

typedef struct {
    int* data;
    int size;
} LongArray;

LongArray* createLongArray(int size) {
    LongArray* array = (LongArray*)malloc(sizeof(LongArray));
    array->data = (int*)malloc(sizeof(int) * size);
    array->size = size;
    return array;
}

void destroyLongArray(LongArray* array) {
    free(array->data);
    free(array);
}

void sortLong(LongArray* array, int from, int to) {
    if (from >= to) {
        return;
    }
    int pivotIndex = (from + to) / 2;
    int pivot = array->data[pivotIndex];
    array->data[pivotIndex] = array->data[to];
    array->data[to] = pivot;
    int storeIndex = from;
    int equalIndex = to;
    for (int i = from; i < equalIndex; i++) {
        if (array->data[i] < pivot) {
            int temp = array->data[i];
            array->data[i] = array->data[storeIndex];
            array->data[storeIndex] = temp;
            storeIndex++;
        } else if (array->data[i] == pivot) {
            equalIndex--;
            int temp = array->data[i];
            array->data[i] = array->data[equalIndex];
            array->data[equalIndex] = temp;
            i--;
        }
    }
    for (int i = equalIndex; i <= to; i++) {
        int temp = array->data[i];
        array->data[i] = array->data[storeIndex];
        array->data[storeIndex] = temp;
        storeIndex++;
    }
    sortLong(array, from, storeIndex - 2);
    sortLong(array, storeIndex, to);
}

void reverseLong(LongArray* array, int from, int to) {
    while (from < to) {
        int temp = array->data[from];
        array->data[from] = array->data[to];
        array->data[to] = temp;
        from++;
        to--;
    }
}

typedef struct {
    int* data;
    int size;
} LongRange;

LongRange* createLongRange(int from, int to) {
    LongRange* range = (LongRange*)malloc(sizeof(LongRange));
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

void destroyLongRange(LongRange* range) {
    free(range->data);
    free(range);
}

typedef struct {
    int* data;
    int size;
    int capacity;
} DoubleList;

DoubleList* createDoubleList() {
    DoubleList* list = (DoubleList*)malloc(sizeof(DoubleList));
    list->data = (int*)malloc(sizeof(int) * 3);
    list->size = 0;
    list->capacity = 3;
    return list;
}

void destroyDoubleList(DoubleList* list) {
    free(list->data);
    free(list);
}

void ensureCapacity(DoubleList* list, int capacity) {
    if (list->capacity >= capacity) {
        return;
    }
    capacity = (list->capacity * 2 > capacity) ? list->capacity * 2 : capacity;
    list->data = (int*)realloc(list->data, sizeof(int) * capacity);
    list->capacity = capacity;
}

void addDouble(DoubleList* list, int value) {
    ensureCapacity(list, list->size + 1);
    list->data[list->size++] = value;
}

int getDouble(DoubleList* list, int index) {
    if (index >= list->size) {
        printf("Index out of bounds\n");
        exit(1);
    }
    return list->data[index];
}

void setDouble(DoubleList* list, int index, int value) {
    if (index >= list->size) {
        printf("Index out of bounds\n");
        exit(1);
    }
    list->data[index] = value;
}

void addAtDouble(DoubleList* list, int index, int value) {
    ensureCapacity(list, list->size + 1);
    if (index > list->size || index < 0) {
        printf("Index out of bounds\n");
        exit(1);
    }
    if (index != list->size) {
        for (int i = list->size - 1; i >= index; i--) {
            list->data[i + 1] = list->data[i];
        }
    }
    list->data[index] = value;
    list->size++;
}

void removeAtDouble(DoubleList* list, int index) {
    if (index >= list->size || index < 0) {
        printf("Index out of bounds\n");
        exit(1);
    }
    if (index != list->size - 1) {
        for (int i = index; i < list->size - 1; i++) {
            list->data[i] = list->data[i + 1];
        }
    }
    list->size--;
}

typedef struct {
    int at;
    bool removed;
    DoubleList* list;
} DoubleIterator;

DoubleIterator* createDoubleIterator(DoubleList* list) {
    DoubleIterator* iterator = (DoubleIterator*)malloc(sizeof(DoubleIterator));
    iterator->at = 0;
    iterator->removed = false;
    iterator->list = list;
    return iterator;
}

void destroyDoubleIterator(DoubleIterator* iterator) {
    free(iterator);
}

int valueDouble(DoubleIterator* iterator) {
    if (iterator->removed) {
        printf("Invalid operation\n");
        exit(1);
    }
    return getDouble(iterator->list, iterator->at);
}

bool advanceDouble(DoubleIterator* iterator) {
    iterator->at++;
    iterator->removed = false;
    return isValidDouble(iterator);
}

bool isValidDouble(DoubleIterator* iterator) {
    return !iterator->removed && iterator->at < iterator->list->size;
}

void removeDouble(DoubleIterator* iterator) {
    removeAtDouble(iterator->list, iterator->at);
    iterator->at--;
    iterator->removed = true;
}

typedef struct {
    int* data;
    int size;
} DoubleArray;

DoubleArray* createDoubleArray(int size) {
    DoubleArray* array = (DoubleArray*)malloc(sizeof(DoubleArray));
    array->data = (int*)malloc(sizeof(int) * size);
    array->size = size;
    return array;
}

void destroyDoubleArray(DoubleArray* array) {
    free(array->data);
    free(array);
}

void sortDouble(DoubleArray* array, int from, int to) {
    if (from >= to) {
        return;
    }
    int pivotIndex = (from + to) / 2;
    int pivot = array->data[pivotIndex];
    array->data[pivotIndex] = array->data[to];
    array->data[to] = pivot;
    int storeIndex = from;
    int equalIndex = to;
    for (int i = from; i < equalIndex; i++) {
        if (array->data[i] < pivot) {
            int temp = array->data[i];
            array->data[i] = array->data[storeIndex];
            array->data[storeIndex] = temp;
            storeIndex++;
        } else if (array->data[i] == pivot) {
            equalIndex--;
            int temp = array->data[i];
            array->data[i] = array->data[equalIndex];
            array->data[equalIndex] = temp;
            i--;
        }
    }
    for (int i = equalIndex; i <= to; i++) {
        int temp = array->data[i];
        array->data[i] = array->data[storeIndex];
        array->data[storeIndex] = temp;
        storeIndex++;
    }
    sortDouble(array, from, storeIndex - 2);
    sortDouble(array, storeIndex, to);
}

void reverseDouble(DoubleArray* array, int from, int to) {
    while (from < to) {
        int temp = array->data[from];
        array->data[from] = array->data[to];
        array->data[to] = temp;
        from++;
        to--;
    }
}

typedef struct {
    int* data;
    int size;
} DoubleRange;

DoubleRange* createDoubleRange(int from, int to) {
    DoubleRange* range = (DoubleRange*)malloc(sizeof(DoubleRange));
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

void destroyDoubleRange(DoubleRange* range) {
    free(range->data);
    free(range);
}

typedef struct {
    int* data;
    int size;
    int capacity;
} CharList;

CharList* createCharList() {
    CharList* list = (CharList*)malloc(sizeof(CharList));
    list->data = (int*)malloc(sizeof(int) * 3);
    list->size = 0;
    list->capacity = 3;
    return list;
}

void destroyCharList(CharList* list) {
    free(list->data);
    free(list);
}

void ensureCapacity(CharList* list, int capacity) {
    if (list->capacity >= capacity) {
        return;
    }
    capacity = (list->capacity * 2 > capacity) ? list->capacity * 2 : capacity;
    list->data = (int*)realloc(list->data, sizeof(int) * capacity);
    list->capacity = capacity;
}

void addChar(CharList* list, int value) {
    ensureCapacity(list, list->size + 1);
    list->data[list->size++] = value;
}

int getChar(CharList* list, int index) {
    if (index >= list->size) {
        printf("Index out of bounds\n");
        exit(1);
    }
    return list->data[index];
}

void setChar(CharList* list, int index, int value) {
    if (index >= list->size) {
        printf("Index out of bounds\n");
        exit(1);
    }
    list->data[index] = value;
}

void addAtChar(CharList* list, int index, int value) {
    ensureCapacity(list, list->size + 1);
    if (index > list->size || index < 0) {
        printf("Index out of bounds\n");
        exit(1);
    }
    if (index != list->size) {
        for (int i = list->size - 1; i >= index; i--) {
            list->data[i + 1] = list->data[i];
        }
    }
    list->data[index] = value;
    list->size++;
}

void removeAtChar(CharList* list, int index) {
    if (index >= list->size || index < 0) {
        printf("Index out of bounds\n");
        exit(1);
    }
    if (index != list->size - 1) {
        for (int i = index; i < list->size - 1; i++) {
            list->data[i] = list->data[i + 1];
        }
    }
    list->size--;
}

typedef struct {
    int at;
    bool removed;
    CharList* list;
} CharIterator;

CharIterator* createCharIterator(CharList* list) {
    CharIterator* iterator = (CharIterator*)malloc(sizeof(CharIterator));
    iterator->at = 0;
    iterator->removed = false;
    iterator->list = list;
    return iterator;
}

void destroyCharIterator(CharIterator* iterator) {
    free(iterator);
}

int valueChar(CharIterator* iterator) {
    if (iterator->removed) {
        printf("Invalid operation\n");
        exit(1);
    }
    return getChar(iterator->list, iterator->at);
}

bool advanceChar(CharIterator* iterator) {
    iterator->at++;
    iterator->removed = false;
    return isValidChar(iterator);
}

bool isValidChar(CharIterator* iterator) {
    return !iterator->removed && iterator->at < iterator->list->size;
}

void removeChar(CharIterator* iterator) {
    removeAtChar(iterator->list, iterator->at);
    iterator->at--;
    iterator->removed = true;
}

typedef struct {
    int* data;
    int size;
} CharArray;

CharArray* createCharArray(int size) {
    CharArray* array = (CharArray*)malloc(sizeof(CharArray));
    array->data = (int*)malloc(sizeof(int) * size);
    array->size = size;
    return array;
}

void destroyCharArray(CharArray* array) {
    free(array->data);
    free(array);
}

void sortChar(CharArray* array, int from, int to) {
    if (from >= to) {
        return;
    }
    int pivotIndex = (from + to) / 2;
    int pivot = array->data[pivotIndex];
    array->data[pivotIndex] = array->data[to];
    array->data[to] = pivot;
    int storeIndex = from;
    int equalIndex = to;
    for (int i = from; i < equalIndex; i++) {
        if (array->data[i] < pivot) {
            int temp = array->data[i];
            array->data[i] = array->data[storeIndex];
            array->data[storeIndex] = temp;
            storeIndex++;
        } else if (array->data[i] == pivot) {
            equalIndex--;
            int temp = array->data[i];
            array->data[i] = array->data[equalIndex];
            array->data[equalIndex] = temp;
            i--;
        }
    }
    for (int i = equalIndex; i <= to; i++) {
        int temp = array->data[i];
        array->data[i] = array->data[storeIndex];
        array->data[storeIndex] = temp;
        storeIndex++;
    }
    sortChar(array, from, storeIndex - 2);
    sortChar(array, storeIndex, to);
}

void reverseChar(CharArray* array, int from, int to) {
    while (from < to) {
        int temp = array->data[from];
        array->data[from] = array->data[to];
        array->data[to] = temp;
        from++;
        to--;
    }
}

typedef struct {
    int* data;
    int size;
} CharRange;

CharRange* createCharRange(int from, int to) {
    CharRange* range = (CharRange*)malloc(sizeof(CharRange));
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

void destroyCharRange(CharRange* range) {
    free(range->data);
    free(range);
}

typedef struct {
    int* data;
    int size;
    int capacity;
} StringList;

StringList* createStringList() {
    StringList* list = (StringList*)malloc(sizeof(StringList));
    list->data = (int*)malloc(sizeof(int) * 3);
    list->size = 0;
    list->capacity = 3;
    return list;
}

void destroyStringList(StringList* list) {
    free(list->data);
    free(list);
}

void ensureCapacity(StringList* list, int capacity) {
    if (list->capacity >= capacity) {
        return;
    }
    capacity = (list->capacity * 2 > capacity) ? list->capacity * 2 : capacity;
    list->data = (int*)realloc(list->data, sizeof(int) * capacity);
    list->capacity = capacity;
}

void addString(StringList* list, int value) {
    ensureCapacity(list, list->size + 1);
    list->data[list->size++] = value;
}

int getString(StringList* list, int index) {
    if (index >= list->size) {
        printf("Index out of bounds\n");
        exit(1);
    }
    return list->data[index];
}

void setString(StringList* list, int index, int value) {
    if (index >= list->size) {
        printf("Index out of bounds\n");
        exit(1);
    }
    list->data[index] = value;
}

void addAtString(StringList* list, int index, int value) {
    ensureCapacity(list, list->size + 1);
    if (index > list->size || index < 0) {
        printf("Index out of bounds\n");
        exit(1);
    }
    if (index != list->size) {
        for (int i = list->size - 1; i >= index; i--) {
            list->data[i + 1] = list->data[i];
        }
    }
    list->data[index] = value;
    list->size++;
}

void removeAtString(StringList* list, int index) {
    if (index >= list->size || index < 0) {
        printf("Index out of bounds\n");
        exit(1);
    }
    if (index != list->size - 1) {
        for (int i = index; i < list->size - 1; i++) {
            list->data[i] = list->data[i + 1];
        }
    }
    list->size--;
}

typedef struct {
    int at;
    bool removed;
    StringList* list;
} StringIterator;

StringIterator* createStringIterator(StringList* list) {
    StringIterator* iterator = (StringIterator*)malloc(sizeof(StringIterator));
    iterator->at = 0;
    iterator->removed = false;
    iterator->list = list;
    return iterator;
}

void destroyStringIterator(StringIterator* iterator) {
    free(iterator);
}

int valueString(StringIterator* iterator) {
    if (iterator->removed) {
        printf("Invalid operation\n");
        exit(1);
    }
    return getString(iterator->list, iterator->at);
}

bool advanceString(StringIterator* iterator) {
    iterator->at++;
    iterator->removed = false;
    return isValidString(iterator);
}

bool isValidString(StringIterator* iterator) {
    return !iterator->removed && iterator->at < iterator->list->size;
}

void removeString(StringIterator* iterator) {
    removeAtString(iterator->list, iterator->at);
    iterator->at--;
    iterator->removed = true;
}

typedef struct {
    int* data;
    int size;
} StringArray;

StringArray* createStringArray(int size) {
    StringArray* array = (StringArray*)malloc(sizeof(StringArray));
    array->data = (int*)malloc(sizeof(int) * size);
    array->size = size;
    return array;
}

void destroyStringArray(StringArray* array) {
    free(array->data);
    free(array);
}

void sortString(StringArray* array, int from, int to) {
    if (from >= to) {
        return;
    }
    int pivotIndex = (from + to) / 2;
    int pivot = array->data[pivotIndex];
    array->data[pivotIndex] = array->data[to];
    array->data[to] = pivot;
    int storeIndex = from;
    int equalIndex = to;
    for (int i = from; i < equalIndex; i++) {
        if (array->data[i] < pivot) {
            int temp = array->data[i];
            array->data[i] = array->data[storeIndex];
            array->data[storeIndex] = temp;
            storeIndex++;
        } else if (array->data[i] == pivot) {
            equalIndex--;
            int temp = array->data[i];
            array->data[i] = array->data[equalIndex];
            array->data[equalIndex] = temp;
            i--;
        }
    }
    for (int i = equalIndex; i <= to; i++) {
        int temp = array->data[i];
        array->data[i] = array->data[storeIndex];
        array->data[storeIndex] = temp;
        storeIndex++;
    }
    sortString(array, from, storeIndex - 2);
    sortString(array, storeIndex, to);
}

void reverseString(StringArray* array, int from, int to) {
    while (from < to) {
        int temp = array->data[from];
        array->data[from] = array->data[to];
        array->data[to] = temp;
        from++;
        to--;
    }
}

typedef struct {
    int* data;
    int size;
} StringRange;

StringRange* createStringRange(int from, int to) {
    StringRange* range = (StringRange*)malloc(sizeof(StringRange));
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

void destroyStringRange(StringRange* range) {
    free(range->data);
    free(range);
}

typedef struct {
    int* data;
    int size;
    int capacity;
} BoolList;

BoolList* createBoolList() {
    BoolList* list = (BoolList*)malloc(sizeof(BoolList));
    list->data = (int*)malloc(sizeof(int) * 3);
    list->size = 0;
    list->capacity = 3;
    return list;
}

void destroyBoolList(BoolList* list) {
    free(list->data);
    free(list);
}

void ensureCapacity(BoolList* list, int capacity) {
    if (list->capacity >= capacity) {
        return;
    }
    capacity = (list->capacity * 2 > capacity) ? list->capacity * 2 : capacity;
    list->data = (int*)realloc(list->data, sizeof(int) * capacity);
    list->capacity = capacity;
}

void addBool(BoolList* list, int value) {
    ensureCapacity(list, list->size + 1);
    list->data[list->size++] = value;
}

int getBool(BoolList* list, int index) {
    if (index >= list->size) {
        printf("Index out of bounds\n");
        exit(1);
    }
    return list->data[index];
}

void setBool(BoolList* list, int index, int value) {
    if (index >= list->size) {
        printf("Index out of bounds\n");
        exit(1);
    }
    list->data[index] = value;
}

void addAtBool(BoolList* list, int index, int value) {
    ensureCapacity(list, list->size + 1);
    if (index > list->size || index < 0) {
        printf("Index out of bounds\n");
        exit(1);
    }
    if (index != list->size) {
        for (int i = list->size - 1; i >= index; i--) {
            list->data[i + 1] = list->data[i];
        }
    }
    list->data[index] = value;
    list->size++;
}

void removeAtBool(BoolList* list, int index) {
    if (index >= list->size || index < 0) {
        printf("Index out of bounds\n");
        exit(1);
    }
    if (index != list->size - 1) {
        for (int i = index; i < list->size - 1; i++) {
            list->data[i] = list->data[i + 1];
        }
    }
    list->size--;
}

typedef struct {
    int at;
    bool removed;
    BoolList* list;
} BoolIterator;

BoolIterator* createBoolIterator(BoolList* list) {
    BoolIterator* iterator = (BoolIterator*)malloc(sizeof(BoolIterator));
    iterator->at = 0;
    iterator->removed = false;
    iterator->list = list;
    return iterator;
}

void destroyBoolIterator(BoolIterator* iterator) {
    free(iterator);
}

int valueBool(BoolIterator* iterator) {
    if (iterator->removed) {
        printf("Invalid operation\n");
        exit(1);
    }
    return getBool(iterator->list, iterator->at);
}

bool advanceBool(BoolIterator* iterator) {
    iterator->at++;
    iterator->removed = false;
    return isValidBool(iterator);
}

bool isValidBool(BoolIterator* iterator) {
    return !iterator->removed && iterator->at < iterator->list->size;
}

void removeBool(BoolIterator* iterator) {
    removeAtBool(iterator->list, iterator->at);
    iterator->at--;
    iterator->removed = true;
}

typedef struct {
    int* data;
    int size;
} BoolArray;

BoolArray* createBoolArray(int size) {
    BoolArray* array = (BoolArray*)malloc(sizeof(BoolArray));
    array->data = (int*)malloc(sizeof(int) * size);
    array->size = size;
    return array;
}

void destroyBoolArray(BoolArray* array) {
    free(array->data);
    free(array);
}

void sortBool(BoolArray* array, int from, int to) {
    if (from >= to) {
        return;
    }
    int pivotIndex = (from + to) / 2;
    int pivot = array->data[pivotIndex];
    array->data[pivotIndex] = array->data[to];
    array->data[to] = pivot;
    int storeIndex = from;
    int equalIndex = to;
    for (int i = from; i < equalIndex; i++) {
        if (array->data[i] < pivot) {
            int temp = array->data[i];
            array->data[i] = array->data[storeIndex];
            array->data[storeIndex] = temp;
            storeIndex++;
        } else if (array->data[i] == pivot) {
            equalIndex--;
            int temp = array->data[i];
            array->data[i] = array->data[equalIndex];
            array->data[equalIndex] = temp;
            i--;
        }
    }
    for (int i = equalIndex; i <= to; i++) {
        int temp = array->data[i];
        array->data[i] = array->data[storeIndex];
        array->data[storeIndex] = temp;
        storeIndex++;
    }
    sortBool(array, from, storeIndex - 2);
    sortBool(array, storeIndex, to);
}

void reverseBool(BoolArray* array, int from, int to) {
    while (from < to) {
        int temp = array->data[from];
        array->data[from] = array->data[to];
        array->data[to] = temp;
        from++;
        to--;
    }
}

typedef struct {
    int* data;
    int size;
} BoolRange;

BoolRange* createBoolRange(int from, int to) {
    BoolRange* range = (BoolRange*)malloc(sizeof(BoolRange));
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

void destroyBoolRange(BoolRange* range) {
    free(range->data);
    free(range);
}

typedef struct {
    int* data;
    int size;
} DoubleIntPair;

DoubleIntPair* createDoubleIntPair(int first, int second) {
    DoubleIntPair* pair = (DoubleIntPair*)malloc(sizeof(DoubleIntPair));
    pair->data = (int*)malloc(sizeof(int) * 2);
    pair->size = 2;
    pair->data[0] = first;
    pair->data[1] = second;
    return pair;
}

void destroyDoubleIntPair(DoubleIntPair* pair) {
    free(pair->data);
    free(pair);
}

typedef struct {
    int* data;
    int size;
} DoubleIntPairArray;

DoubleIntPairArray* createDoubleIntPairArray(int size) {
    DoubleIntPairArray* array = (DoubleIntPairArray*)malloc(sizeof(DoubleIntPairArray));
    array->data = (int*)malloc(sizeof(int) * size * 2);
    array->size = size;
    return array;
}

void destroyDoubleIntPairArray(DoubleIntPairArray* array) {
    free(array->data);
    free(array);
}

typedef struct {
    int* data;
    int size;
} DoubleIntPairRange;

DoubleIntPairRange* createDoubleIntPairRange(int from, int to) {
    DoubleIntPairRange* range = (DoubleIntPairRange*)malloc(sizeof(DoubleIntPairRange));
    range->data = (int*)malloc(sizeof(int) * abs(from - to) * 2);
    range->size = abs(from - to);
    int current = from;
    if (from <= to) {
        for (int i = 0; i < range->size; i++) {
            range->data[i * 2] = current++;
            range->data[i * 2 + 1] = current++;
        }
    } else {
        for (int i = 0; i < range->size; i++) {
            range->data[i * 2] = current--;
            range->data[i * 2 + 1] = current--;
        }
    }
    return range;
}

void destroyDoubleIntPairRange(DoubleIntPairRange* range) {
    free(range->data);
    free(range);
}

typedef struct {
    int* data;
    int size;
} IntIntPair;

IntIntPair* createIntIntPair(int first, int second) {
    IntIntPair* pair = (IntIntPair*)malloc(sizeof(IntIntPair));
    pair->data = (int*)malloc(sizeof(int) * 2);
    pair->size = 2;
    pair->data[0] = first;
    pair->data[1] = second;
    return pair;
}

void destroyIntIntPair(IntIntPair* pair) {
    free(pair->data);
    free(pair);
}

typedef struct {
    int* data;
    int size;
} IntIntPairArray;

IntIntPairArray* createIntIntPairArray(int size) {
    IntIntPairArray* array = (IntIntPairArray*)malloc(sizeof(IntIntPairArray));
    array->data = (int*)malloc(sizeof(int) * size * 2);
    array->size = size;
    return array;
}

void destroyIntIntPairArray(IntIntPairArray* array) {
    free(array->data);
    free(array);
}

typedef struct {
    int* data;
    int size;
} IntIntPairRange;

IntIntPairRange* createIntIntPairRange(int from, int to) {
    IntIntPairRange* range = (IntIntPairRange*)malloc(sizeof(IntIntPairRange));
    range->data = (int*)malloc(sizeof(int) * abs(from - to) * 2);
    range->size = abs(from - to);
    int current = from;
    if (from <= to) {
        for (int i = 0; i < range->size; i++) {
            range->data[i * 2] = current++;
            range->data[i * 2 + 1] = current++;
        }
    } else {
        for (int i = 0; i < range->size; i++) {
            range->data[i * 2] = current--;
            range->data[i * 2 + 1] = current--;
        }
    }
    return range;
}

void destroyIntIntPairRange(IntIntPairRange* range) {
    free(range->data);
    free(range);
}

typedef struct {
    int* data;
    int size;
} LongIntPair;

LongIntPair* createLongIntPair(int first, int second) {
    LongIntPair* pair = (LongIntPair*)malloc(sizeof(LongIntPair));
    pair->data = (int*)malloc(sizeof(int) * 2);
    pair->size = 2;
    pair->data[0] = first;
    pair->data[1] = second;
    return pair;
}

void destroyLongIntPair(LongIntPair* pair) {
    free(pair->data);
    free(pair);
}

typedef struct {
    int* data;
    int size;
} LongIntPairArray;

LongIntPairArray* createLongIntPairArray(int size) {
    LongIntPairArray* array = (LongIntPairArray*)malloc(sizeof(LongIntPairArray));
    array->data = (int*)malloc(sizeof(int) * size * 2);
    array->size = size;
    return array;
}

void destroyLongIntPairArray(LongIntPairArray* array) {
    free(array->data);
    free(array);
}

typedef struct {
    int* data;
    int size;
} LongIntPairRange;

LongIntPairRange* createLongIntPairRange(int from, int to) {
    LongIntPairRange* range = (LongIntPairRange*)malloc(sizeof(LongIntPairRange));
    range->data = (int*)malloc(sizeof(int) * abs(from - to) * 2);
    range->size = abs(from - to);
    int current = from;
    if (from <= to) {
        for (int i = 0; i < range->size; i++) {
            range->data[i * 2] = current++;
            range->data[i * 2 + 1] = current++;
        }
    } else {
        for (int i = 0; i < range->size; i++) {
            range->data[i * 2] = current--;
            range->data[i * 2 + 1] = current--;
        }
    }
    return range;
}

void destroyLongIntPairRange(LongIntPairRange* range) {
    free(range->data);
    free(range);
}

typedef struct {
    int* data;
    int size;
} IntLongPair;

IntLongPair* createIntLongPair(int first, int second) {
    IntLongPair* pair = (IntLongPair*)malloc(sizeof(IntLongPair));
    pair->data = (int*)malloc(sizeof(int) * 2);
    pair->size = 2;
    pair->data[0] = first;
    pair->data[1] = second;
    return pair;
}

void destroyIntLongPair(IntLongPair* pair) {
    free(pair->data);
    free(pair);
}

typedef struct {
    int* data;
    int size;
} IntLongPairArray;

IntLongPairArray* createIntLongPairArray(int size) {
    IntLongPairArray* array = (IntLongPairArray*)malloc(sizeof(IntLongPairArray));
    array->data = (int*)malloc(sizeof(int) * size * 2);
    array->size = size;
    return array;
}

void destroyIntLongPairArray(IntLongPairArray* array) {
    free(array->data);
    free(array);
}

typedef struct {
    int* data;
    int size;
} IntLongPairRange;

IntLongPairRange* createIntLongPairRange(int from, int to) {
    IntLongPairRange* range = (IntLongPairRange*)malloc(sizeof(IntLongPairRange));
    range->data = (int*)malloc(sizeof(int) * abs(from - to) * 2);
    range->size = abs(from - to);
    int current = from;
    if (from <= to) {
        for (int i = 0; i < range->size; i++) {
            range->data[i * 2] = current++;
            range->data[i * 2 + 1] = current++;
        }
    } else {
        for (int i = 0; i < range->size; i++) {
            range->data[i * 2] = current--;
            range->data[i * 2 + 1] = current--;
        }
    }
    return range;
}

void destroyIntLongPairRange(IntLongPairRange* range) {
    free(range->data);
    free(range);
}

typedef struct {
    int* data;
    int size;
} LongLongPair;

LongLongPair* createLongLongPair(int first, int second) {
    LongLongPair* pair = (LongLongPair*)malloc(sizeof(LongLongPair));
    pair->data = (int*)malloc(sizeof(int) * 2);
    pair->size = 2;
    pair->data[0] = first;
    pair->data[1] = second;
    return pair;
}

void destroyLongLongPair(LongLongPair* pair) {
    free(pair->data);
    free(pair);
}

typedef struct {
    int* data;
    int size;
} LongLongPairArray;

LongLongPairArray* createLongLongPairArray(int size) {
    LongLongPairArray* array = (LongLongPairArray*)malloc(sizeof(LongLongPairArray));
    array->data = (int*)malloc(sizeof(int) * size * 2);
    array->size = size;
    return array;
}

void destroyLongLongPairArray(LongLongPairArray* array) {
    free(array->data);
    free(array);
}

typedef struct {
    int* data;
    int size;
} LongLongPairRange;

LongLongPairRange* createLongLongPairRange(int from, int to) {
    LongLongPairRange* range = (LongLongPairRange*)malloc(sizeof(LongLongPairRange));
    range->data = (int*)malloc(sizeof(int) * abs(from - to) * 2);
    range->size = abs(from - to);
    int current = from;
    if (from <= to) {
        for (int i = 0; i < range->size; i++) {
            range->data[i * 2] = current++;
            range->data[i * 2 + 1] = current++;
        }
    } else {
        for (int i = 0; i < range->size; i++) {
            range->data[i * 2] = current--;
            range->data[i * 2 + 1] = current--;
        }
    }
    return range;
}

void destroyLongLongPairRange(LongLongPairRange* range) {
    free(range->data);
    free(range);
}

typedef struct {
    int* data;
    int size;
} DoubleDoublePair;

DoubleDoublePair* createDoubleDoublePair(int first, int second) {
    DoubleDoublePair* pair = (DoubleDoublePair*)malloc(sizeof(DoubleDoublePair));
    pair->data = (int*)malloc(sizeof(int) * 2);
    pair->size = 2;
    pair->data[0] = first;
    pair->data[1] = second;
    return pair;
}

void destroyDoubleDoublePair(DoubleDoublePair* pair) {
    free(pair->data);
    free(pair);
}

typedef struct {
    int* data;
    int size;
} DoubleDoublePairArray;

DoubleDoublePairArray* createDoubleDoublePairArray(int size) {
    DoubleDoublePairArray* array = (DoubleDoublePairArray*)malloc(sizeof(DoubleDoublePairArray));
    array->data = (int*)malloc(sizeof(int) * size * 2);
    array->size = size;
    return array;
}

void destroyDoubleDoublePairArray(DoubleDoublePairArray* array) {
    free(array->data);
    free(array);
}

typedef struct {
    int* data;
    int size;
} DoubleDoublePairRange;

DoubleDoublePairRange* createDoubleDoublePairRange(int from, int to) {
    DoubleDoublePairRange* range = (DoubleDoublePairRange*)malloc(sizeof(DoubleDoublePairRange));
    range->data = (int*)malloc(sizeof(int) * abs(from - to) * 2);
    range->size = abs(from - to);
    int current = from;
    if (from <= to) {
        for (int i = 0; i < range->size; i++) {
            range->data[i * 2] = current++;
            range->data[i * 2 + 1] = current++;
        }
    } else {
        for (int i = 0; i < range->size; i++) {
            range->data[i * 2] = current--;
            range->data[i * 2 + 1] = current--;
        }
    }
    return range;
}

void destroyDoubleDoublePairRange(DoubleDoublePairRange* range) {
    free(range->data);
    free(range);
}

typedef struct {
    int* data;
    int size;
} IntDoublePair;

IntDoublePair* createIntDoublePair(int first, int second) {
    IntDoublePair* pair = (IntDoublePair*)malloc(sizeof(IntDoublePair));
    pair->data = (int*)malloc(sizeof(int) * 2);
    pair->size = 2;
    pair->data[0] = first;
    pair->data[1] = second;
    return pair;
}

void destroyIntDoublePair(IntDoublePair* pair) {
    free(pair->data);
    free(pair);
}

typedef struct {
    int* data;
    int size;
} IntDoublePairArray;

IntDoublePairArray* createIntDoublePairArray(int size) {
    IntDoublePairArray* array = (IntDoublePairArray*)malloc(sizeof(IntDoublePairArray));
    array->data = (int*)malloc(sizeof(int) * size * 2);
    array->size = size;
    return array;
}

void destroyIntDoublePairArray(IntDoublePairArray* array) {
    free(array->data);
    free(array);
}

typedef struct {
    int* data;
    int size;
} IntDoublePairRange;

IntDoublePairRange* createIntDoublePairRange(int from, int to) {
    IntDoublePairRange* range = (IntDoublePairRange*)malloc(sizeof(IntDoublePairRange));
    range->data = (int*)malloc(sizeof(int) * abs(from - to) * 2);
    range->size = abs(from - to);
    int current = from;
    if (from <= to) {
        for (int i = 0; i < range->size; i++) {
            range->data[i * 2] = current++;
            range->data[i * 2 + 1] = current++;
        }
    } else {
        for (int i = 0; i < range->size; i++) {
            range->data[i * 2] = current--;
            range->data[i * 2 + 1] = current--;
        }
    }
    return range;
}

void destroyIntDoublePairRange(IntDoublePairRange* range) {
    free(range->data);
    free(range);
}

typedef struct {
    int* data;
    int size;
} LongDoublePair;

LongDoublePair* createLongDoublePair(int first, int second) {
    LongDoublePair* pair = (LongDoublePair*)malloc(sizeof(LongDoublePair));
    pair->data = (int*)malloc(sizeof(int) * 2);
    pair->size = 2;
    pair->data[0] = first;
    pair->data[1] = second;
    return pair;
}

void destroyLongDoublePair(LongDoublePair* pair) {
    free(pair->data);
    free(pair);
}

typedef struct {
    int* data;
    int size;
} LongDoublePairArray;

LongDoublePairArray* createLongDoublePairArray(int size) {
    LongDoublePairArray* array = (LongDoublePairArray*)malloc(sizeof(LongDoublePairArray));
    array->data = (int*)malloc(sizeof(int) * size * 2);
    array->size = size;
    return array;
}

void destroyLongDoublePairArray(LongDoublePairArray* array) {
    free(array->data);
    free(array);
}

typedef struct {
    int* data;
    int size;
} LongDoublePairRange;

LongDoublePairRange* createLongDoublePairRange(int from, int to) {
    LongDoublePairRange* range = (LongDoublePairRange*)malloc(sizeof(LongDoublePairRange));
    range->data = (int*)malloc(sizeof(int) * abs(from - to) * 2);
    range->size = abs(from - to);
    int current = from;
    if (from <= to) {
        for (int i = 0; i < range->size; i++) {
            range->data[i * 2] = current++;

#include <stdio.h>
#include <stdlib.h>

#define MAXN 100005
#define MOD 1000000007

typedef struct {
    int x;
    int y;
} Point;

typedef struct {
    int *data;
    int size;
    int cap;
} IntegerList;

typedef struct {
    int *data;
    int size;
    int cap;
} IntegerStack;

typedef struct {
    int *data;
    int size;
    int cap;
} IntegerQueue;

typedef struct {
    int *slot;
    int *next;
    int *keys;
    int *values;
    int alloc;
    int mask;
    int size;
    int rehash;
} IntegerHashMap;

typedef struct {
    int *values;
    int *next;
    int *heads;
    int alloc;
    int stackNum;
} IntegerMultiWayStack;

typedef struct {
    int m;
} Modular;

typedef struct {
    int *fact;
    int *inv;
    Modular *modular;
} Factorial;

typedef struct {
    Factorial *factorial;
    Modular *modular;
} Combination;

typedef struct {
    int *p;
    int *rank;
    int *size;
} DSU;

typedef struct {
    int *buf;
    int bufLen;
    int bufOffset;
    int next;
} FastInput;

typedef struct {
    char *cache;
    FILE *os;
} FastOutput;

typedef struct {
    int *inv;
} InverseNumber;

typedef struct {
    long time;
} Hasher;

int max(int a, int b) {
    return a > b ? a : b;
}

int min(int a, int b) {
    return a < b ? a : b;
}

int add(int a, int b) {
    a += b;
    if (a >= MOD) {
        a -= MOD;
    }
    return a;
}

int mul(int a, int b) {
    return (long long) a * b % MOD;
}

int valueOf(Modular *modular, int x) {
    x %= modular->m;
    if (x < 0) {
        x += modular->m;
    }
    return x;
}

Modular *newModular(int m) {
    Modular *modular = (Modular *) malloc(sizeof(Modular));
    modular->m = m;
    return modular;
}

Factorial *newFactorial(int limit, Modular *modular) {
    Factorial *factorial = (Factorial *) malloc(sizeof(Factorial));
    factorial->fact = (int *) malloc((limit + 1) * sizeof(int));
    factorial->inv = (int *) malloc((limit + 1) * sizeof(int));
    factorial->modular = modular;
    factorial->fact[0] = factorial->inv[0] = 1;
    for (int i = 1; i <= limit; i++) {
        factorial->fact[i] = mul(factorial->fact[i - 1], i);
        factorial->inv[i] = mul(factorial->inv[i - 1], factorial->modular->m - factorial->inv[modular->m % i]);
    }
    return factorial;
}

Combination *newCombination(int limit, Modular *modular) {
    Combination *combination = (Combination *) malloc(sizeof(Combination));
    combination->factorial = newFactorial(limit, modular);
    combination->modular = modular;
    return combination;
}

DSU *newDSU(int n) {
    DSU *dsu = (DSU *) malloc(sizeof(DSU));
    dsu->p = (int *) malloc(n * sizeof(int));
    dsu->rank = (int *) malloc(n * sizeof(int));
    dsu->size = (int *) malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        dsu->p[i] = i;
        dsu->rank[i] = 0;
        dsu->size[i] = 1;
    }
    return dsu;
}

FastInput *newFastInput() {
    FastInput *fastInput = (FastInput *) malloc(sizeof(FastInput));
    fastInput->buf = (int *) malloc((1 << 13) * sizeof(int));
    fastInput->bufLen = 0;
    fastInput->bufOffset = 0;
    fastInput->next = 0;
    return fastInput;
}

FastOutput *newFastOutput(FILE *os) {
    FastOutput *fastOutput = (FastOutput *) malloc(sizeof(FastOutput));
    fastOutput->cache = (char *) malloc((10 << 20) * sizeof(char));
    fastOutput->os = os;
    return fastOutput;
}

Hasher *newHasher() {
    Hasher *hasher = (Hasher *) malloc(sizeof(Hasher));
    hasher->time = (long) time(NULL);
    return hasher;
}

int shuffle(Hasher *hasher, long long x) {
    x += hasher->time;
    x += 0x9e3779b97f4a7c15LL;
    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9LL;
    x = (x ^ (x >> 27)) * 0x94d049bb133111ebLL;
    return (int) (x ^ (x >> 31));
}

int hash(Hasher *hasher, int x) {
    return shuffle(hasher, x);
}

IntegerList *newIntegerList(int cap) {
    IntegerList *list = (IntegerList *) malloc(sizeof(IntegerList));
    list->data = (int *) malloc(cap * sizeof(int));
    list->size = 0;
    list->cap = cap;
    return list;
}

void ensureSpace(IntegerList *list, int req) {
    if (req <= list->cap) {
        return;
    }
    while (req > list->cap) {
        list->cap = max(list->cap + 10, list->cap * 2);
    }
    list->data = (int *) realloc(list->data, list->cap * sizeof(int));
}

void add(IntegerList *list, int x) {
    ensureSpace(list, list->size + 1);
    list->data[list->size++] = x;
}

void addAll(IntegerList *list, IntegerList *another) {
    ensureSpace(list, list->size + another->size);
    for (int i = 0; i < another->size; i++) {
        list->data[list->size++] = another->data[i];
    }
}

void addAll(IntegerList *list, int *arr, int offset, int len) {
    ensureSpace(list, list->size + len);
    for (int i = 0; i < len; i++) {
        list->data[list->size++] = arr[offset + i];
    }
}

void sort(IntegerList *list) {
    if (list->size <= 1) {
        return;
    }
    for (int i = 1; i < list->size; i++) {
        int j = rand() % (i + 1);
        int t = list->data[i];
        list->data[i] = list->data[j];
        list->data[j] = t;
    }
    qsort(list->data, list->size, sizeof(int), cmpInt);
}

void unique(IntegerList *list) {
    if (list->size <= 1) {
        return;
    }
    sort(list);
    int wpos = 1;
    for (int i = 1; i < list->size; i++) {
        if (list->data[i] != list->data[wpos - 1]) {
            list->data[wpos++] = list->data[i];
        }
    }
    list->size = wpos;
}

int cmpInt(const void *a, const void *b) {
    return *(int *) a - *(int *) b;
}

int size(IntegerList *list) {
    return list->size;
}

int *toArray(IntegerList *list) {
    return list->data;
}

void clear(IntegerList *list) {
    list->size = 0;
}

IntegerStack *newIntegerStack(int cap) {
    IntegerStack *stack = (IntegerStack *) malloc(sizeof(IntegerStack));
    stack->data = (int *) malloc(cap * sizeof(int));
    stack->size = 0;
    stack->cap = cap;
    return stack;
}

void ensureSpaceS(IntegerStack *stack, int req) {
    if (req <= stack->cap) {
        return;
    }
    while (req > stack->cap) {
        stack->cap = max(stack->cap + 10, stack->cap * 2);
    }
    stack->data = (int *) realloc(stack->data, stack->cap * sizeof(int));
}

void push(IntegerStack *stack, int x) {
    ensureSpaceS(stack, stack->size + 1);
    stack->data[stack->size++] = x;
}

int pop(IntegerStack *stack) {
    return stack->data[--stack->size];
}

int sizeS(IntegerStack *stack) {
    return stack->size;
}

int *toArrayS(IntegerStack *stack) {
    return stack->data;
}

void clearS(IntegerStack *stack) {
    stack->size = 0;
}

IntegerQueue *newIntegerQueue(int cap) {
    IntegerQueue *queue = (IntegerQueue *) malloc(sizeof(IntegerQueue));
    queue->data = (int *) malloc(cap * sizeof(int));
    queue->size = 0;
    queue->cap = cap;
    return queue;
}

void ensureSpaceQ(IntegerQueue *queue, int req) {
    if (req <= queue->cap) {
        return;
    }
    while (req > queue->cap) {
        queue->cap = max(queue->cap + 10, queue->cap * 2);
    }
    queue->data = (int *) realloc(queue->data, queue->cap * sizeof(int));
}

void addQ(IntegerQueue *queue, int x) {
    ensureSpaceQ(queue, queue->size + 1);
    queue->data[queue->size++] = x;
}

int removeQ(IntegerQueue *queue) {
    int ans = queue->data[0];
    for (int i = 1; i < queue->size; i++) {
        queue->data[i - 1] = queue->data[i];
    }
    queue->size--;
    return ans;
}

int sizeQ(IntegerQueue *queue) {
    return queue->size;
}

int *toArrayQ(IntegerQueue *queue) {
    return queue->data;
}

void clearQ(IntegerQueue *queue) {
    queue->size = 0;
}

IntegerHashMap *newIntegerHashMap(int cap, int rehash) {
    IntegerHashMap *map = (IntegerHashMap *) malloc(sizeof(IntegerHashMap));
    map->slot = (int *) malloc(cap * sizeof(int));
    map->next = (int *) malloc(cap * sizeof(int));
    map->keys = (int *) malloc(cap * sizeof(int));
    map->values = (int *) malloc(cap * sizeof(int));
    map->alloc = 0;
    map->mask = cap - 1;
    map->size = 0;
    map->rehash = rehash;
    return map;
}

void doubleCapacity(IntegerHashMap *map) {
    int newSize = max(map->next + 10, map->next * 2);
    map->next = (int *) realloc(map->next, newSize * sizeof(int));
    map->keys = (int *) realloc(map->keys, newSize * sizeof(int));
    map->values = (int *) realloc(map->values, newSize * sizeof(int));
}

void alloc(IntegerHashMap *map) {
    map->alloc++;
    if (map->alloc >= map->next) {
        doubleCapacity(map);
    }
    map->next[map->alloc] = 0;
    map->size++;
}

void put(IntegerHashMap *map, int x, int y) {
    int h = hash(x) & map->mask;
    if (map->slot[h] == 0) {
        alloc(map);
        map->slot[h] = map->alloc;
        map->keys[map->alloc] = x;
        map->values[map->alloc] = y;
    } else {
        int index = findIndexOrLastEntry(map, h, x);
        if (map->keys[index] != x) {
            alloc(map);
            map->next[index] = map->alloc;
            map->keys[map->alloc] = x;
            map->values[map->alloc] = y;
        } else {
            map->values[index] = y;
        }
    }
    if (map->rehash && map->size >= map->next) {
        rehash(map);
    }
}

int containKey(IntegerHashMap *map, int x) {
    int h = hash(x) & map->mask;
    if (map->slot[h] == 0) {
        return 0;
    }
    return map->keys[findIndexOrLastEntry(map, h, x)] == x;
}

int getOrDefault(IntegerHashMap *map, int x, int def) {
    int h = hash(x) & map->mask;
    if (map->slot[h] == 0) {
        return def;
    }
    int index = findIndexOrLastEntry(map, h, x);
    return map->keys[index] == x ? map->values[index] : def;
}

int get(IntegerHashMap *map, int x) {
    return getOrDefault(map, x, 0);
}

int findIndexOrLastEntry(IntegerHashMap *map, int s, int x) {
    int iter = map->slot[s];
    while (map->keys[iter] != x) {
        if (map->next[iter] != 0) {
            iter = map->next[iter];
        } else {
            return iter;
        }
    }
    return iter;
}

IntegerHashMap *clone(IntegerHashMap *map) {
    IntegerHashMap *newMap = newIntegerHashMap(map->size, map->rehash);
    for (int i = 0; i < map->size; i++) {
        put(newMap, map->keys[i], map->values[i]);
    }
    return newMap;
}

void rehash(IntegerHashMap *map) {
    int *newSlots = (int *) malloc((map->slot + 10) * sizeof(int));
    int newMask = (map->slot + 10) - 1;
    for (int i = 0; i < map->slot; i++) {
        if (map->slot[i] == 0) {
            continue;
        }
        int head = map->slot[i];
        while (head != 0) {
            int n = map->next[head];
            int s = hash(map->keys[head]) & newMask;
            map->next[head] = newSlots[s];
            newSlots[s] = head;
            head = n;
        }
    }
    map->slot = newSlots;
    map->mask = newMask;
}

FastInput *newFastInput() {
    FastInput *fastInput = (FastInput *) malloc(sizeof(FastInput));
    fastInput->buf = (int *) malloc((1 << 13) * sizeof(int));
    fastInput->bufLen = 0;
    fastInput->bufOffset = 0;
    fastInput->next = 0;
    return fastInput;
}

FastOutput *newFastOutput(FILE *os) {
    FastOutput *fastOutput = (FastOutput *) malloc(sizeof(FastOutput));
    fastOutput->cache = (char *) malloc((10 << 20) * sizeof(char));
    fastOutput->os = os;
    return fastOutput;
}

int read(FastInput *fastInput) {
    while (fastInput->bufLen == fastInput->bufOffset) {
        fastInput->bufOffset = 0;
        fastInput->bufLen = fread(fastInput->buf, sizeof(int), 1 << 13, stdin);
        if (fastInput->bufLen == 0) {
            return -1;
        }
    }
    return fastInput->buf[fastInput->bufOffset++];
}

void skipBlank(FastInput *fastInput) {
    int c;
    while ((c = read(fastInput)) <= 32 && c != -1) ;
    fastInput->next = c;
}

int readInt(FastInput *fastInput) {
    int sign = 1;

    skipBlank(fastInput);
    if (fastInput->next == '+' || fastInput->next == '-') {
        sign = fastInput->next == '+' ? 1 : -1;
        fastInput->next = read(fastInput);
    }

    int val = 0;
    if (sign == 1) {
        while (fastInput->next >= '0' && fastInput->next <= '9') {
            val = val * 10 + fastInput->next - '0';
            fastInput->next = read(fastInput);
        }
    } else {
        while (fastInput->next >= '0' && fastInput->next <= '9') {
            val = val * 10 - fastInput->next + '0';
            fastInput->next = read(fastInput);
        }
    }

    return val;
}

FastOutput *newFastOutput(FILE *os) {
    FastOutput *fastOutput = (FastOutput *) malloc(sizeof(FastOutput));
    fastOutput->cache = (char *) malloc((10 << 20) * sizeof(char));
    fastOutput->os = os;
    return fastOutput;
}

FastOutput *append(FastOutput *fastOutput, const char *csq, int start, int end) {
    for (int i = start; i < end; i++) {
        fastOutput->cache[fastOutput->size++] = csq[i];
    }
    return fastOutput;
}

FastOutput *appendChar(FastOutput *fastOutput, char c) {
    fastOutput->cache[fastOutput->size++] = c;
    return fastOutput;
}

FastOutput *appendInt(FastOutput *fastOutput, int x) {
    if (x == 0) {
        fastOutput->cache[fastOutput->size++] = '0';
        return fastOutput;
    }
    int len = 0;
    char buf[12];
    while (x) {
        buf[len++] = x % 10 + '0';
        x /= 10;
    }
    for (int i = len - 1; i >= 0; i--) {
        fastOutput->cache[fastOutput->size++] = buf[i];
    }
    return fastOutput;
}

FastOutput *println(FastOutput *fastOutput) {
    fastOutput->cache[fastOutput->size++] = '\n';
    return fastOutput;
}

FastOutput *flush(FastOutput *fastOutput) {
    fwrite(fastOutput->cache, sizeof(char), fastOutput->size, fastOutput->os);
    fastOutput->size = 0;
    return fastOutput;
}

void close(FastOutput *fastOutput) {
    flush(fastOutput);
    fclose(fastOutput->os);
}

int main() {
    FastInput *fastInput = newFastInput();
    FastOutput *fastOutput = newFastOutput(stdout);

    int n = readInt(fastInput);
    Point *pts = (Point *) malloc(n * sizeof(Point));
    for (int i = 0; i < n; i++) {
        pts[i].x = readInt(fastInput);
        pts[i].y = readInt(fastInput);
    }

    IntegerHashMap *x = newIntegerHashMap(n, 0);
    IntegerHashMap *y = newIntegerHashMap(n, 0);
    DSU *dsu = newDSU(n);
    for (int i = 0; i < n; i++) {
        if (containKey(x, pts[i].x)) {
            merge(dsu, get(x, pts[i].x), i);
        }
        if (containKey(y, pts[i].y)) {
            merge(dsu, get(y, pts[i].y), i);
        }
        put(x, pts[i].x, i);
        put(y, pts[i].y, i);
    }

    IntegerMultiWayStack *xStack = newIntegerMultiWayStack(n, n);
    IntegerMultiWayStack *yStack = newIntegerMultiWayStack(n, n);
    for (int i = 0; i < n; i++) {
        add(xStack, find(dsu, i), pts[i].x);
        add(yStack, find(dsu, i), pts[i].y);
    }
    IntegerList *xList = newIntegerList(n);
    IntegerList *yList = newIntegerList(n);

    Modular *mod = newModular(MOD);
    Combination *comb = newCombination(2 * n, mod);
    int ans = 1;
    for (int i = 0; i < n; i++) {
        if (find(dsu, i) != i) {
            continue;
        }
        clear(xList);
        clear(yList);
        addAll(xList, iterator(xStack, i));
        addAll(yList, iterator(yStack, i));
        unique(xList);
        unique(yList);

        int line = size(xList) + size(yList);
        int num = dsu->size[i];
        int local = 0;
        for (int j = 0; j <= num; j++) {
            local = add(local, combination(comb, line, j));
        }

        ans = mul(ans, local);
    }

    appendInt(fastOutput, ans);
    println(fastOutput);
    flush(fastOutput);
    close(fastOutput);
    return 0;
}

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    long long *data;
    int size;
    int cap;
} LongList;

LongList* newLongList(int cap) {
    LongList *list = (LongList*)malloc(sizeof(LongList));
    list->data = (long long*)malloc(cap * sizeof(long long));
    list->size = 0;
    list->cap = cap;
    return list;
}

void ensureSpace(LongList *list, int req) {
    if (req > list->cap) {
        while (list->cap < req) {
            list->cap = (list->cap + 10) * 2;
        }
        list->data = (long long*)realloc(list->data, list->cap * sizeof(long long));
    }
}

void add(LongList *list, long long x) {
    ensureSpace(list, list->size + 1);
    list->data[list->size++] = x;
}

void addAll(LongList *list, long long *x, int offset, int len) {
    ensureSpace(list, list->size + len);
    for (int i = 0; i < len; i++) {
        list->data[list->size++] = x[offset + i];
    }
}

void addAllFromList(LongList *list, LongList *other) {
    addAll(list, other->data, 0, other->size);
}

void sort(LongList *list) {
    if (list->size <= 1) {
        return;
    }
    for (int i = 0; i < list->size; i++) {
        int j = rand() % (i + 1);
        long long temp = list->data[i];
        list->data[i] = list->data[j];
        list->data[j] = temp;
    }
    qsort(list->data, list->size, sizeof(long long), cmpfunc);
}

int cmpfunc(const void *a, const void *b) {
    return (*(long long*)a - *(long long*)b);
}

void unique(LongList *list) {
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

void clear(LongList *list) {
    list->size = 0;
}

typedef struct {
    int *slot;
    int *next;
    long long *keys;
    long long *values;
    int alloc;
    int mask;
    int size;
    int rehash;
} id1;

id1* newid1(int cap, int rehash) {
    id1 *map = (id1*)malloc(sizeof(id1));
    map->slot = (int*)calloc(cap, sizeof(int));
    map->next = (int*)calloc(cap + 1, sizeof(int));
    map->keys = (long long*)calloc(cap + 1, sizeof(long long));
    map->values = (long long*)calloc(cap + 1, sizeof(long long));
    map->alloc = 0;
    map->mask = (1 << (32 - __builtin_clz(cap - 1))) - 1;
    map->size = 0;
    map->rehash = rehash;
    return map;
}

void doubleCapacity(id1 *map) {
    int newSize = (map->alloc + 10) * 2;
    map->next = (int*)realloc(map->next, newSize * sizeof(int));
    map->keys = (long long*)realloc(map->keys, newSize * sizeof(long long));
    map->values = (long long*)realloc(map->values, newSize * sizeof(long long));
}

void alloc(id1 *map) {
    map->alloc++;
    if (map->alloc >= map->next) {
        doubleCapacity(map);
    }
    map->next[map->alloc] = 0;
    map->size++;
}

int hash(long long x, int mask) {
    int h = x;
    h ^= (h >> 16);
    return h & mask;
}

void put(id1 *map, long long x, long long y, int cover) {
    int h = hash(x, map->mask);
    int s = h & map->mask;
    if (map->slot[s] == 0) {
        alloc(map);
        map->slot[s] = map->alloc;
        map->keys[map->alloc] = x;
        map->values[map->alloc] = y;
    } else {
        int index = id8(map, s, x);
        if (map->keys[index] != x) {
            alloc(map);
            map->next[index] = map->alloc;
            map->keys[map->alloc] = x;
            map->values[map->alloc] = y;
        } else if (cover) {
            map->values[index] = y;
        }
    }
    if (map->rehash && map->size >= map->mask) {
        rehash(map);
    }
}

long long id5(id1 *map, long long x, long long def) {
    int h = hash(x, map->mask);
    int s = h & map->mask;
    if (map->slot[s] == 0) {
        return def;
    }
    int index = id8(map, s, x);
    return map->keys[index] == x ? map->values[index] : def;
}

long long get(id1 *map, long long x) {
    return id5(map, x, 0);
}

int id8(id1 *map, int s, long long x) {
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

typedef struct {
    int index;
    int readIndex;
    id1 *map;
} id7;

id7* newid7(id1 *map) {
    id7 *iter = (id7*)malloc(sizeof(id7));
    iter->index = 1;
    iter->readIndex = -1;
    iter->map = map;
    return iter;
}

int hasNext(id7 *iter) {
    while (iter->index <= iter->map->alloc && iter->map->next[iter->index] == -1) {
        iter->index++;
    }
    return iter->index <= iter->map->alloc;
}

void next(id7 *iter) {
    if (!hasNext(iter)) {
        printf("No next element\n");
        exit(1);
    }
    iter->readIndex = iter->index;
    iter->index++;
}

long long id10(id7 *iter) {
    return iter->map->keys[iter->readIndex];
}

long long id11(id7 *iter) {
    return iter->map->values[iter->readIndex];
}

id1* iterator(id1 *map) {
    return newid7(map);
}

typedef struct {
    long long m;
} id12;

id12* newid12(long long m) {
    id12 *modular = (id12*)malloc(sizeof(id12));
    modular->m = m;
    return modular;
}

long long mul(id12 *modular, long long a, long long b) {
    return b == 0 ? 0 : ((mul(modular, a, b >> 1) << 1) % modular->m + a * (b & 1)) % modular->m;
}

id12* getInstance(long long mod) {
    if (mod <= (1LL << 54)) {
        return newid12(mod);
    } else {
        return newid12(mod);
    }
}

typedef struct {
    int *data;
    int size;
    int cap;
} IntList;

IntList* newIntList(int cap) {
    IntList *list = (IntList*)malloc(sizeof(IntList));
    list->data = (int*)malloc(cap * sizeof(int));
    list->size = 0;
    list->cap = cap;
    return list;
}

void ensureSpace(IntList *list, int req) {
    if (req > list->cap) {
        while (list->cap < req) {
            list->cap = (list->cap + 10) * 2;
        }
        list->data = (int*)realloc(list->data, list->cap * sizeof(int));
    }
}

void add(IntList *list, int x) {
    ensureSpace(list, list->size + 1);
    list->data[list->size++] = x;
}

void addAll(IntList *list, int *x, int offset, int len) {
    ensureSpace(list, list->size + len);
    for (int i = 0; i < len; i++) {
        list->data[list->size++] = x[offset + i];
    }
}

void addAllFromList(IntList *list, IntList *other) {
    addAll(list, other->data, 0, other->size);
}

void sort(IntList *list) {
    if (list->size <= 1) {
        return;
    }
    for (int i = 0; i < list->size; i++) {
        int j = rand() % (i + 1);
        int temp = list->data[i];
        list->data[i] = list->data[j];
        list->data[j] = temp;
    }
    qsort(list->data, list->size, sizeof(int), cmpfunc);
}

int cmpfunc(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

void unique(IntList *list) {
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

void clear(IntList *list) {
    list->size = 0;
}

typedef struct {
    int *slot;
    int *next;
    long long *keys;
    int *values;
    int alloc;
    int mask;
    int size;
    int rehash;
} id13;

id13* newid13(int cap, int rehash) {
    id13 *map = (id13*)malloc(sizeof(id13));
    map->slot = (int*)calloc(cap, sizeof(int));
    map->next = (int*)calloc(cap + 1, sizeof(int));
    map->keys = (long long*)calloc(cap + 1, sizeof(long long));
    map->values = (int*)calloc(cap + 1, sizeof(int));
    map->alloc = 0;
    map->mask = (1 << (32 - __builtin_clz(cap - 1))) - 1;
    map->size = 0;
    map->rehash = rehash;
    return map;
}

void doubleCapacity(id13 *map) {
    int newSize = (map->alloc + 10) * 2;
    map->next = (int*)realloc(map->next, newSize * sizeof(int));
    map->keys = (long long*)realloc(map->keys, newSize * sizeof(long long));
    map->values = (int*)realloc(map->values, newSize * sizeof(int));
}

void alloc(id13 *map) {
    map->alloc++;
    if (map->alloc >= map->next) {
        doubleCapacity(map);
    }
    map->next[map->alloc] = 0;
    map->size++;
}

int hash(long long x, int mask) {
    int h = x;
    h ^= (h >> 16);
    return h & mask;
}

void put(id13 *map, long long x, int y, int cover) {
    int h = hash(x, map->mask);
    int s = h & map->mask;
    if (map->slot[s] == 0) {
        alloc(map);
        map->slot[s] = map->alloc;
        map->keys[map->alloc] = x;
        map->values[map->alloc] = y;
    } else {
        int index = id8(map, s, x);
        if (map->keys[index] != x) {
            alloc(map);
            map->next[index] = map->alloc;
            map->keys[map->alloc] = x;
            map->values[map->alloc] = y;
        } else if (cover) {
            map->values[index] = y;
        }
    }
    if (map->rehash && map->size >= map->mask) {
        rehash(map);
    }
}

int id5(id13 *map, long long x, int def) {
    int h = hash(x, map->mask);
    int s = h & map->mask;
    if (map->slot[s] == 0) {
        return def;
    }
    int index = id8(map, s, x);
    return map->keys[index] == x ? map->values[index] : def;
}

int get(id13 *map, long long x) {
    return id5(map, x, 0);
}

int id8(id13 *map, int s, long long x) {
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

typedef struct {
    long long *data;
    int size;
    int cap;
} LongList;

LongList* newLongList(int cap) {
    LongList *list = (LongList*)malloc(sizeof(LongList));
    list->data = (long long*)malloc(cap * sizeof(long long));
    list->size = 0;
    list->cap = cap;
    return list;
}

void ensureSpace(LongList *list, int req) {
    if (req > list->cap) {
        while (list->cap < req) {
            list->cap = (list->cap + 10) * 2;
        }
        list->data = (long long*)realloc(list->data, list->cap * sizeof(long long));
    }
}

void add(LongList *list, long long x) {
    ensureSpace(list, list->size + 1);
    list->data[list->size++] = x;
}

void addAll(LongList *list, long long *x, int offset, int len) {
    ensureSpace(list, list->size + len);
    for (int i = 0; i < len; i++) {
        list->data[list->size++] = x[offset + i];
    }
}

void addAllFromList(LongList *list, LongList *other) {
    addAll(list, other->data, 0, other->size);
}

void sort(LongList *list) {
    if (list->size <= 1) {
        return;
    }
    for (int i = 0; i < list->size; i++) {
        int j = rand() % (i + 1);
        long long temp = list->data[i];
        list->data[i] = list->data[j];
        list->data[j] = temp;
    }
    qsort(list->data, list->size, sizeof(long long), cmpfunc);
}

int cmpfunc(const void *a, const void *b) {
    return (*(long long*)a - *(long long*)b);
}

void unique(LongList *list) {
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

void clear(LongList *list) {
    list->size = 0;
}

typedef struct {
    int *slot;
    int *next;
    long long *keys;
    long long *values;
    int alloc;
    int mask;
    int size;
    int rehash;
} id1;

id1* newid1(int cap, int rehash) {
    id1 *map = (id1*)malloc(sizeof(id1));
    map->slot = (int*)calloc(cap, sizeof(int));
    map->next = (int*)calloc(cap + 1, sizeof(int));
    map->keys = (long long*)calloc(cap + 1, sizeof(long long));
    map->values = (long long*)calloc(cap + 1, sizeof(long long));
    map->alloc = 0;
    map->mask = (1 << (32 - __builtin_clz(cap - 1))) - 1;
    map->size = 0;
    map->rehash = rehash;
    return map;
}

void doubleCapacity(id1 *map) {
    int newSize = (map->alloc + 10) * 2;
    map->next = (int*)realloc(map->next, newSize * sizeof(int));
    map->keys = (long long*)realloc(map->keys, newSize * sizeof(long long));
    map->values = (long long*)realloc(map->values, newSize * sizeof(long long));
}

void alloc(id1 *map) {
    map->alloc++;
    if (map->alloc >= map->next) {
        doubleCapacity(map);
    }
    map->next[map->alloc] = 0;
    map->size++;
}

int hash(long long x, int mask) {
    int h = x;
    h ^= (h >> 16);
    return h & mask;
}

void put(id1 *map, long long x, long long y, int cover) {
    int h = hash(x, map->mask);
    int s = h & map->mask;
    if (map->slot[s] == 0) {
        alloc(map);
        map->slot[s] = map->alloc;
        map->keys[map->alloc] = x;
        map->values[map->alloc] = y;
    } else {
        int index = id8(map, s, x);
        if (map->keys[index] != x) {
            alloc(map);
            map->next[index] = map->alloc;
            map->keys[map->alloc] = x;
            map->values[map->alloc] = y;
        } else if (cover) {
            map->values[index] = y;
        }
    }
    if (map->rehash && map->size >= map->mask) {
        rehash(map);
    }
}

long long id5(id1 *map, long long x, long long def) {
    int h = hash(x, map->mask);
    int s = h & map->mask;
    if (map->slot[s] == 0) {
        return def;
    }
    int index = id8(map, s, x);
    return map->keys[index] == x ? map->values[index] : def;
}

long long get(id1 *map, long long x) {
    return id5(map, x, 0);
}

int id8(id1 *map, int s, long long x) {
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

id7* newid7(id1 *map) {
    id7 *iter = (id7*)malloc(sizeof(id7));
    iter->index = 1;
    iter->readIndex = -1;
    iter->map = map;
    return iter;
}

int hasNext(id7 *iter) {
    while (iter->index <= iter->map->alloc && iter->map->next[iter->index] == -1) {
        iter->index++;
    }
    return iter->index <= iter->map->alloc;
}

void next(id7 *iter) {
    if (!hasNext(iter)) {
        printf("No next element\n");
        exit(1);
    }
    iter->readIndex = iter->index;
    iter->index++;
}

long long id10(id7 *iter) {
    return iter->map->keys[iter->readIndex];
}

long long id11(id7 *iter) {
    return iter->map->values[iter->readIndex];
}

id1* iterator(id1 *map) {
    return newid7(map);
}

id12* newid12(long long m) {
    id12 *modular = (id12*)malloc(sizeof(id12));
    modular->m = m;
    return modular;
}

long long mul(id12 *modular, long long a, long long b) {
    return b == 0 ? 0 : ((mul(modular, a, b >> 1) << 1) % modular->m + a * (b & 1)) % modular->m;
}

id12* getInstance(long long mod) {
    if (mod <= (1LL << 54)) {
        return newid12(mod);
    } else {
        return newid12(mod);
    }
}

id13* newid13(int cap, int rehash) {
    id13 *map = (id13*)malloc(sizeof(id13));
    map->slot = (int*)calloc(cap, sizeof(int));
    map->next = (int*)calloc(cap + 1, sizeof(int));
    map->keys = (long long*)calloc(cap + 1, sizeof(long long));
    map->values = (int*)calloc(cap + 1, sizeof(int));
    map->alloc = 0;
    map->mask = (1 << (32 - __builtin_clz(cap - 1))) - 1;
    map->size = 0;
    map->rehash = rehash;
    return map;
}

void doubleCapacity(id13 *map) {
    int newSize = (map->alloc + 10) * 2;
    map->next = (int*)realloc(map->next, newSize * sizeof(int));
    map->keys = (long long*)realloc(map->keys, newSize * sizeof(long long));
    map->values = (int*)realloc(map->values, newSize * sizeof(int));
}

void alloc(id13 *map) {
    map->alloc++;
    if (map->alloc >= map->next) {
        doubleCapacity(map);
    }
    map->next[map->alloc] = 0;
    map->size++;
}

int hash(long long x, int mask) {
    int h = x;
    h ^= (h >> 16);
    return h & mask;
}

void put(id13 *map, long long x, int y, int cover) {
    int h = hash(x, map->mask);
    int s = h & map->mask;
    if (map->slot[s] == 0) {
        alloc(map);
        map->slot[s] = map->alloc;
        map->keys[map->alloc] = x;
        map->values[map->alloc] = y;
    } else {
        int index = id8(map, s, x);
        if (map->keys[index] != x) {
            alloc(map);
            map->next[index] = map->alloc;
            map->keys[map->alloc] = x;
            map->values[map->alloc] = y;
        } else if (cover) {
            map->values[index] = y;
        }
    }
    if (map->rehash && map->size >= map->mask) {
        rehash(map);
    }
}

int id5(id13 *map, long long x, int def) {
    int h = hash(x, map->mask);
    int s = h & map->mask;
    if (map->slot[s] == 0) {
        return def;
    }
    int index = id8(map, s, x);
    return map->keys[index] == x ? map->values[index] : def;
}

int get(id13 *map, long long x) {
    return id5(map, x, 0);
}

int id8(id13 *map, int s, long long x) {
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

int main() {
    srand(0);
    long long m, x;
    scanf("%lld %lld", &m, &x);

    id1 *mu = newid1(100000, 0);
    id1 *euler = newid1(100000, 0);
    long long *primes = (long long*)malloc(100000 * sizeof(long long));

    mu->keys[1] = 1;
    mu->values[1] = 1;
    euler->keys[1] = 1;
    euler->values[1] = 1;

    for (long long i = 2; i < 100000; i++) {
        if (mu->slot[i] == 0) {
            alloc(mu);
            alloc(euler);
            primes[mu->alloc] = i;
            mu->keys[i] = i;
            mu->values[i] = -1;
            euler->keys[i] = i;
            euler->values[i] = i - 1;
        }
        for (long long j = 1; j <= mu->alloc && i * primes[j] < 100000; j++) {
            alloc(mu);
            alloc(euler);
            long long val = i * primes[j];
            mu->keys[val] = val;
            euler->keys[val] = val;
            if (i % primes[j] == 0) {
                mu->values[val] = 0;
                euler->values[val] = euler->values[i] * primes[j];
                break;
            } else {
                mu->values[val] = -mu->values[i];
                euler->values[val] = euler->values[i] * (primes[j] - 1);
            }
        }
    }

    LongList *id9 = newLongList(20000);
    LongList *tmpList = newLongList(20000);
    LongList *id2 = newLongList();
    for (int i = 1; i <= mu->alloc; i++) {
        add(id2, primes[i]);
        addAllFromList(id2, euler->values[primes[i] - 1]);
    }
    unique(id2);

    collect(id9, m, 0);
    id12 *power = getInstance(m);

    long long total = 1;
    for (int i = 0; i < id9->size; i++) {
        long long g = id9->data[i];
        if (g == m) {
            continue;
        }
        long long mg = m / g;
        clear(tmpList);
        collect(tmpList, mg, 0);
        long long cnt = 0;
        for (int j = tmpList->size - 1; j >= 0; j--) {
            long long t = tmpList->data[j];
            cnt += id5(mu, t, -1) * ((m - 1) / (t * g));
        }

        clear(tmpList);
        long long eulerVal = id5(euler, mg, -1);
        for (int j = 0; j < id2->size; j++) {
            long long p = id2->data[j];
            if (eulerVal % p == 0) {
                add(tmpList, p);
            }
        }

        long long n = eulerVal;
        for (int j = 0; j < tmpList->size; j++) {
            long long p = tmpList->data[j];
            while (n % p == 0 && mul(power, x, n / p) % mg == 1) {
                n /= p;
            }
        }

        if (cnt % n != 0) {
            printf("Invalid state\n");
            exit(1);
        }
        total += cnt / n;
    }

    printf("%lld\n", total);

    return 0;
}

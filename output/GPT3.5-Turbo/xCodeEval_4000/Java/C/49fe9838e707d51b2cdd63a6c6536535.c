#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

typedef struct {
    long long *data;
    int size;
    int cap;
} LongList;

LongList* newLongList(int cap) {
    LongList *list = (LongList*)malloc(sizeof(LongList));
    list->cap = cap;
    list->size = 0;
    list->data = (long long*)malloc(cap * sizeof(long long));
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

void checkRange(LongList *list, int i) {
    if (i < 0 || i >= list->size) {
        printf("ArrayIndexOutOfBoundsException\n");
        exit(1);
    }
}

long long get(LongList *list, int i) {
    checkRange(list, i);
    return list->data[i];
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

void addAllFromLongList(LongList *list, LongList *other) {
    addAll(list, other->data, 0, other->size);
}

void sort(LongList *list) {
    if (list->size <= 1) {
        return;
    }
    for (int i = 0; i < list->size; i++) {
        int j = rand() % (list->size - i) + i;
        long long tmp = list->data[i];
        list->data[i] = list->data[j];
        list->data[j] = tmp;
    }
    qsort(list->data, list->size, sizeof(long long), cmp);
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

int size(LongList *list) {
    return list->size;
}

long long* toArray(LongList *list) {
    long long *arr = (long long*)malloc(list->size * sizeof(long long));
    for (int i = 0; i < list->size; i++) {
        arr[i] = list->data[i];
    }
    return arr;
}

void clear(LongList *list) {
    list->size = 0;
}

void freeLongList(LongList *list) {
    free(list->data);
    free(list);
}

typedef struct {
    int *slot;
    int *next;
    long long *keys;
    long long *values;
    int alloc;
    bool *removed;
    int mask;
    int size;
    bool rehash;
} LongHashMap;

LongHashMap* newLongHashMap(int cap, bool rehash) {
    LongHashMap *map = (LongHashMap*)malloc(sizeof(LongHashMap));
    map->mask = (1 << (32 - __builtin_clz(cap - 1))) - 1;
    map->slot = (int*)malloc((map->mask + 1) * sizeof(int));
    map->next = (int*)malloc(cap * sizeof(int));
    map->keys = (long long*)malloc(cap * sizeof(long long));
    map->values = (long long*)malloc(cap * sizeof(long long));
    map->removed = (bool*)malloc(cap * sizeof(bool));
    map->alloc = 0;
    map->size = 0;
    map->rehash = rehash;
    for (int i = 0; i <= map->mask; i++) {
        map->slot[i] = 0;
    }
    return map;
}

void doubleCapacity(LongHashMap *map) {
    int newSize = fmax(map->next + 10, map->next * 2);
    map->next = (int*)realloc(map->next, newSize * sizeof(int));
    map->keys = (long long*)realloc(map->keys, newSize * sizeof(long long));
    map->values = (long long*)realloc(map->values, newSize * sizeof(long long));
    map->removed = (bool*)realloc(map->removed, newSize * sizeof(bool));
}

void alloc(LongHashMap *map) {
    map->alloc++;
    if (map->alloc >= map->next) {
        doubleCapacity(map);
    }
    map->next[map->alloc] = 0;
    map->removed[map->alloc] = false;
    map->size++;
}

int hash(LongHashMap *map, long long x) {
    int h = x;
    h ^= h >> 16;
    return h & map->mask;
}

void put(LongHashMap *map, long long x, long long y) {
    put(map, x, y, true);
}

void put(LongHashMap *map, long long x, long long y, bool cover) {
    int h = hash(map, x);
    int s = h & map->mask;
    if (map->slot[s] == 0) {
        alloc(map);
        map->slot[s] = map->alloc;
        map->keys[map->alloc] = x;
        map->values[map->alloc] = y;
    } else {
        int index = findIndexOrLastEntry(map, s, x);
        if (map->keys[index] != x) {
            alloc(map);
            map->next[index] = map->alloc;
            map->keys[map->alloc] = x;
            map->values[map->alloc] = y;
        } else if (cover) {
            map->values[index] = y;
        }
    }
    if (map->rehash && map->size >= map->next) {
        rehash(map);
    }
}

long long getOrDefault(LongHashMap *map, long long x, long long def) {
    int h = hash(map, x);
    int s = h & map->mask;
    if (map->slot[s] == 0) {
        return def;
    }
    int index = findIndexOrLastEntry(map, s, x);
    return map->keys[index] == x ? map->values[index] : def;
}

long long get(LongHashMap *map, long long x) {
    return getOrDefault(map, x, 0);
}

int findIndexOrLastEntry(LongHashMap *map, int s, long long x) {
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

void rehash(LongHashMap *map) {
    int *newSlots = (int*)malloc(fmax(16, map->slot * 2) * sizeof(int));
    int newMask = fmax(16, map->slot * 2) - 1;
    for (int i = 0; i < map->slot; i++) {
        if (map->slot[i] == 0) {
            continue;
        }
        int head = map->slot[i];
        while (head != 0) {
            int n = map->next[head];
            int s = hash(map, map->keys[head]) & newMask;
            map->next[head] = newSlots[s];
            newSlots[s] = head;
            head = n;
        }
    }
    free(map->slot);
    map->slot = newSlots;
    map->mask = newMask;
}

typedef struct {
    int index;
    int readIndex;
    LongHashMap *map;
} LongEntryIterator;

LongEntryIterator* newLongEntryIterator(LongHashMap *map) {
    LongEntryIterator *iterator = (LongEntryIterator*)malloc(sizeof(LongEntryIterator));
    iterator->index = 1;
    iterator->readIndex = -1;
    iterator->map = map;
    return iterator;
}

bool hasNext(LongEntryIterator *iterator) {
    while (iterator->index <= iterator->map->alloc && iterator->map->removed[iterator->index]) {
        iterator->index++;
    }
    return iterator->index <= iterator->map->alloc;
}

void next(LongEntryIterator *iterator) {
    if (!hasNext(iterator)) {
        printf("IllegalStateException\n");
        exit(1);
    }
    iterator->readIndex = iterator->index;
    iterator->index++;
}

long long getEntryKey(LongEntryIterator *iterator) {
    return iterator->map->keys[iterator->readIndex];
}

long long getEntryValue(LongEntryIterator *iterator) {
    return iterator->map->values[iterator->readIndex];
}

void freeLongEntryIterator(LongEntryIterator *iterator) {
    free(iterator);
}

typedef struct {
    long long m;
} LongModular;

LongModular* newLongModular(long long m) {
    LongModular *modular = (LongModular*)malloc(sizeof(LongModular));
    modular->m = m;
    return modular;
}

long long mul(LongModular *modular, long long a, long long b) {
    return b == 0 ? 0 : ((mul(modular, a, b >> 1) << 1) % modular->m + a * (b & 1)) % modular->m;
}

long long plus(LongModular *modular, long long a, long long b) {
    return (a + b) % modular->m;
}

long long valueOf(LongModular *modular, long long a) {
    a %= modular->m;
    if (a < 0) {
        a += modular->m;
    }
    return a;
}

typedef struct {
    LongModular *modular;
} LongPower;

LongPower* newLongPower(LongModular *modular) {
    LongPower *power = (LongPower*)malloc(sizeof(LongPower));
    power->modular = modular;
    return power;
}

long long pow(LongPower *power, long long x, long long n) {
    if (n == 0) {
        return 1;
    }
    long long r = pow(power, x, n >> 1);
    r = mul(power->modular, r, r);
    if ((n & 1) == 1) {
        r = mul(power->modular, r, x);
    }
    return r;
}

typedef struct {
    LongModular *modular;
    LongPower *power;
    LongHashMap *map;
} LongPollardRho;

LongPollardRho* newLongPollardRho() {
    LongPollardRho *pollardRho = (LongPollardRho*)malloc(sizeof(LongPollardRho));
    pollardRho->modular = NULL;
    pollardRho->power = NULL;
    pollardRho->map = NULL;
    return pollardRho;
}

long long findFactor(LongPollardRho *pollardRho, long long n) {
    if (n <= 1) {
        return false;
    }
    if (n == 2) {
        return true;
    }
    if (n % 2 == 0) {
        return false;
    }
    pollardRho->modular = newLongModular(n);
    pollardRho->power = newLongPower(pollardRho->modular);
    while (true) {
        long long f = findFactor0(pollardRho, (long long)(rand() / (double)RAND_MAX * n), (long long)(rand() / (double)RAND_MAX * n), n);
        if (f != -1) {
            return f;
        }
    }
}

long long findFactor0(LongPollardRho *pollardRho, long long x, long long c, long long n) {
    long long xi = x;
    long long xj = x;
    int j = 2;
    int i = 1;
    while (i < n) {
        i++;
        xi = plus(pollardRho->modular, mul(pollardRho->modular, xi, xi), c);
        long long g = gcd(n, llabs(xi - xj));
        if (g != 1 && g != n) {
            return g;
        }
        if (g != 1 || i % 2 == 1) {
            break;
        }
        i = i / 2;
    }
    return -1;
}

void findAllFactors(LongPollardRho *pollardRho, LongHashMap *map, long long n) {
    if (n == 1) {
        return;
    }
    long long f = findFactor(pollardRho, n);
    if (f == n) {
        long long *value = (long long*)malloc(sizeof(long long));
        *value = 1;
        put(map, f, value);
        return;
    }
    LongHashMap *map1 = newLongHashMap(20000, false);
    LongHashMap *map2 = newLongHashMap(20000, false);
    findAllFactors(pollardRho, map1, f);
    findAllFactors(pollardRho, map2, n / f);
    LongEntryIterator *it = newLongEntryIterator(map1);
    while (hasNext(it)) {
        next(it);
        long long *value = (long long*)malloc(sizeof(long long));
        *value = *getOrDefault(map1, getEntryKey(it), 0) + *getOrDefault(map2, getEntryKey(it), 0);
        put(map, getEntryKey(it), value);
    }
    freeLongEntryIterator(it);
    freeLongHashMap(map1);
    freeLongHashMap(map2);
}

LongHashMap* findAllFactorsWrapper(LongPollardRho *pollardRho, long long n) {
    LongHashMap *map = newLongHashMap(100000, false);
    findAllFactors(pollardRho, map, n);
    return map;
}

long gcd(long a, long b) {
    return a >= b ? gcd0(a, b) : gcd0(b, a);
}

long gcd0(long a, long b) {
    return b == 0 ? a : gcd0(b, a % b);
}

int cmp(const void *a, const void *b) {
    return (*(long long*)a - *(long long*)b);
}

void shuffle(long long *data, int from, int to) {
    to--;
    for (int i = from; i <= to; i++) {
        int j = rand() % (to - i + 1) + i;
        long long tmp = data[i];
        data[i] = data[j];
        data[j] = tmp;
    }
}

int nextInt(int l, int r) {
    return rand() % (r - l + 1) + l;
}

int main() {
    srand(0);
    long long m, x;
    scanf("%lld %lld", &m, &x);

    LongPollardRho *pollardRho = newLongPollardRho();
    LongHashMap *primes = findAllFactorsWrapper(pollardRho, m);
    LongList *allFactorOfM = newLongList(20000);
    LongList *tmpList = newLongList(20000);
    LongList *allPossiblePrimeFactor = newLongList();
    LongEntryIterator *it = newLongEntryIterator(primes);
    while (hasNext(it)) {
        next(it);
        add(allPossiblePrimeFactor, getEntryKey(it));
        LongHashMap *factorization = findAllFactorsWrapper(pollardRho, getEntryKey(it) - 1);
        LongEntryIterator *it2 = newLongEntryIterator(factorization);
        while (hasNext(it2)) {
            next(it2);
            add(allPossiblePrimeFactor, getEntryKey(it2));
        }
        freeLongEntryIterator(it2);
        freeLongHashMap(factorization);
    }
    freeLongEntryIterator(it);
    unique(allPossiblePrimeFactor);

    findAllFactors(pollardRho, allFactorOfM, m);
    LongModular *modular = newLongModular(m);
    LongPower *power = newLongPower(modular);

    long long total = 1;
    for (int i = 0; i < size(allFactorOfM); i++) {
        long long g = get(allFactorOfM, i);
        if (g == m) {
            continue;
        }
        long long mg = m / g;
        clear(tmpList);
        findAllFactors(pollardRho, tmpList, mg);
        long long cnt = 0;
        for (int j = size(tmpList) - 1; j >= 0; j--) {
            long long t = get(tmpList, j);
            cnt += getOrDefault(primes, t, 0) * ((m - 1) / (t * g));
        }

        clear(tmpList);
        long long euler = getOrDefault(primes, mg, 0);
        LongEntryIterator *it3 = newLongEntryIterator(primes);
        while (hasNext(it3)) {
            next(it3);
            long long p = getEntryKey(it3);
            if (euler % p == 0) {
                add(tmpList, p);
            }
        }
        freeLongEntryIterator(it3);

        long long n = euler;
        for (int j = 0; j < size(tmpList); j++) {
            long long p = get(tmpList, j);
            while (n % p == 0 && pow(power, x, n / p) % mg == 1) {
                n /= p;
            }
        }

        if (cnt % n != 0) {
            printf("IllegalStateException\n");
            exit(1);
        }
        total += cnt / n;
    }

    printf("%lld\n", total);

    freeLongHashMap(primes);
    freeLongList(allFactorOfM);
    freeLongList(tmpList);
    freeLongList(allPossiblePrimeFactor);
    freeLongPollardRho(pollardRho);
    freeLongModular(modular);
    freeLongPower(power);

    return 0;
}

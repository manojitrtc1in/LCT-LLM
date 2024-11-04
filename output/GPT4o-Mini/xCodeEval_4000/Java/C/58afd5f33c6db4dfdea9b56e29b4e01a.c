#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

#define INITIAL_CAPACITY 100000

typedef struct {
    long *data;
    int size;
    int capacity;
} LongList;

typedef struct {
    long *keys;
    long *values;
    int *next;
    int *slot;
    bool *removed;
    int alloc;
    int size;
    int mask;
    bool rehash;
} LongHashMap;

typedef struct {
    long m;
} LongModular;

typedef struct {
    long *primes;
    LongHashMap mu;
    LongHashMap euler;
} GXMouseInTheCampus;

void LongList_init(LongList *list, int capacity) {
    list->data = (long *)malloc(capacity * sizeof(long));
    list->size = 0;
    list->capacity = capacity;
}

void LongList_add(LongList *list, long value) {
    if (list->size >= list->capacity) {
        list->capacity *= 2;
        list->data = (long *)realloc(list->data, list->capacity * sizeof(long));
    }
    list->data[list->size++] = value;
}

void LongHashMap_init(LongHashMap *map, int capacity, bool rehash) {
    map->keys = (long *)malloc(capacity * sizeof(long));
    map->values = (long *)malloc(capacity * sizeof(long));
    map->next = (int *)malloc(capacity * sizeof(int));
    map->slot = (int *)calloc(capacity, sizeof(int));
    map->removed = (bool *)calloc(capacity, sizeof(bool));
    map->alloc = 0;
    map->size = 0;
    map->mask = capacity - 1;
    map->rehash = rehash;
}

int hash(long x) {
    return (int)(x ^ (x >> 16));
}

void LongHashMap_put(LongHashMap *map, long key, long value) {
    int h = hash(key);
    int s = h & map->mask;
    if (map->slot[s] == 0) {
        map->alloc++;
        map->slot[s] = map->alloc;
        map->keys[map->alloc] = key;
        map->values[map->alloc] = value;
        map->size++;
    } else {
        int index = map->slot[s];
        while (index != 0) {
            if (map->keys[index] == key) {
                map->values[index] = value;
                return;
            }
            index = map->next[index];
        }
        map->alloc++;
        map->next[map->alloc] = map->slot[s];
        map->slot[s] = map->alloc;
        map->keys[map->alloc] = key;
        map->values[map->alloc] = value;
        map->size++;
    }
}

long LongHashMap_get(LongHashMap *map, long key) {
    int h = hash(key);
    int s = h & map->mask;
    int index = map->slot[s];
    while (index != 0) {
        if (map->keys[index] == key) {
            return map->values[index];
        }
        index = map->next[index];
    }
    return 0; // Default value
}

void LongHashMap_free(LongHashMap *map) {
    free(map->keys);
    free(map->values);
    free(map->next);
    free(map->slot);
    free(map->removed);
}

void GXMouseInTheCampus_init(GXMouseInTheCampus *solver) {
    LongHashMap_init(&solver->mu, INITIAL_CAPACITY, false);
    LongHashMap_init(&solver->euler, INITIAL_CAPACITY, false);
    LongList_init(&solver->primes, INITIAL_CAPACITY);
}

long oneOfPrimeFactor(GXMouseInTheCampus *solver, long x) {
    for (int i = 0; i < solver->primes.size; i++) {
        long p = solver->primes.data[i];
        if (x % p == 0) {
            return p;
        }
    }
    return x;
}

void populate(GXMouseInTheCampus *solver, long x) {
    long factor = oneOfPrimeFactor(solver, x);
    long cnt = 0;
    long y = x;
    while (y % factor == 0) {
        cnt++;
        y /= factor;
    }
    if (cnt > 1) {
        LongHashMap_put(&solver->mu, x, 0);
    } else {
        LongHashMap_put(&solver->mu, x, -LongHashMap_get(&solver->mu, y));
    }
    LongHashMap_put(&solver->euler, x, LongHashMap_get(&solver->euler, y) * (x / y - x / y / factor));
}

long mu(GXMouseInTheCampus *solver, long x) {
    long ans = LongHashMap_get(&solver->mu, x);
    if (ans == 0) {
        populate(solver, x);
        ans = LongHashMap_get(&solver->mu, x);
    }
    return ans;
}

long euler(GXMouseInTheCampus *solver, long x) {
    long ans = LongHashMap_get(&solver->euler, x);
    if (ans == 0) {
        populate(solver, x);
        ans = LongHashMap_get(&solver->euler, x);
    }
    return ans;
}

void collect(LongList *list, long x, long *primes, int primeCount, int i) {
    if (i == primeCount) {
        LongList_add(list, x);
        return;
    }
    collect(list, x, primes, primeCount, i + 1);
    while (x % primes[i] == 0) {
        x /= primes[i];
        collect(list, x, primes, primeCount, i + 1);
    }
}

void solve(GXMouseInTheCampus *solver, long m, long x) {
    LongList allFactorOfM;
    LongList_init(&allFactorOfM, 20000);
    LongList tmpList;
    LongList_init(&tmpList, 20000);
    LongList allPossiblePrimeFactor;
    LongList_init(&allPossiblePrimeFactor, 20000);

    // Factorization logic here...

    long total = 1;
    for (int i = 0; i < allFactorOfM.size; i++) {
        long g = allFactorOfM.data[i];
        if (g == m) {
            continue;
        }
        long mg = m / g;
        tmpList.size = 0; // Clear tmpList
        collect(&tmpList, mg, solver->primes.data, solver->primes.size, 0);
        long cnt = 0;
        for (int j = tmpList.size - 1; j >= 0; j--) {
            long t = tmpList.data[j];
            cnt += mu(solver, t) * ((m - 1) / (t * g));
        }

        tmpList.size = 0; // Clear tmpList
        long eulerValue = euler(solver, mg);
        for (int j = 0; j < allPossiblePrimeFactor.size; j++) {
            long p = allPossiblePrimeFactor.data[j];
            if (eulerValue % p == 0) {
                LongList_add(&tmpList, p);
            }
        }

        long n = eulerValue;
        for (int j = 0; j < tmpList.size; j++) {
            long p = tmpList.data[j];
            while (n % p == 0) {
                n /= p;
            }
        }

        if (cnt % n != 0) {
            fprintf(stderr, "Illegal state\n");
            exit(1);
        }
        total += cnt / n;
    }

    printf("%ld\n", total);
}

int main() {
    long m, x;
    scanf("%ld %ld", &m, &x);

    GXMouseInTheCampus solver;
    GXMouseInTheCampus_init(&solver);

    // Populate primes and call solve
    // ...

    LongHashMap_free(&solver.mu);
    LongHashMap_free(&solver.euler);
    free(solver.primes.data);
    return 0;
}

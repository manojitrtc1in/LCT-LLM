#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_CAPACITY 100000

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
    int mask;
    int size;
    bool rehash;
} id1;

typedef struct {
    long m;
} id12;

typedef struct {
    id12 *modular;
} LongPower;

typedef struct {
    long *primes;
    id1 mu;
    id1 euler;
} id3;

void LongList_init(LongList *list, int capacity) {
    list->capacity = capacity;
    list->size = 0;
    list->data = (long *)malloc(capacity * sizeof(long));
}

void LongList_add(LongList *list, long value) {
    if (list->size >= list->capacity) {
        list->capacity *= 2;
        list->data = (long *)realloc(list->data, list->capacity * sizeof(long));
    }
    list->data[list->size++] = value;
}

void LongList_clear(LongList *list) {
    list->size = 0;
}

void id1_init(id1 *map, int capacity, bool rehash) {
    map->mask = (1 << (32 - __builtin_clz(capacity - 1))) - 1;
    map->slot = (int *)calloc(map->mask + 1, sizeof(int));
    map->next = (int *)malloc((capacity + 1) * sizeof(int));
    map->keys = (long *)malloc((capacity + 1) * sizeof(long));
    map->values = (long *)malloc((capacity + 1) * sizeof(long));
    map->removed = (bool *)calloc(capacity + 1, sizeof(bool));
    map->alloc = 0;
    map->rehash = rehash;
}

void id1_put(id1 *map, long key, long value) {
    int h = (int)(key ^ (key >> 16)) & map->mask;
    if (map->slot[h] == 0) {
        map->alloc++;
        map->slot[h] = map->alloc;
        map->keys[map->alloc] = key;
        map->values[map->alloc] = value;
    } else {
        int index = map->slot[h];
        while (map->keys[index] != key) {
            if (map->next[index] == 0) {
                map->alloc++;
                map->next[index] = map->alloc;
                map->keys[map->alloc] = key;
                map->values[map->alloc] = value;
                return;
            }
            index = map->next[index];
        }
        map->values[index] = value;
    }
}

long id1_get(id1 *map, long key) {
    int h = (int)(key ^ (key >> 16)) & map->mask;
    if (map->slot[h] == 0) {
        return 0;
    }
    int index = map->slot[h];
    while (map->keys[index] != key) {
        if (map->next[index] == 0) {
            return 0;
        }
        index = map->next[index];
    }
    return map->values[index];
}

void id3_init(id3 *solver) {
    id1_init(&solver->mu, MAX_CAPACITY, false);
    id1_init(&solver->euler, MAX_CAPACITY, false);
    solver->primes = (long *)malloc(MAX_CAPACITY * sizeof(long));
}

long id0(id3 *solver, long x) {
    for (int i = 0; solver->primes[i] != 0; i++) {
        if (x % solver->primes[i] == 0) {
            return solver->primes[i];
        }
    }
    return x;
}

void populate(id3 *solver, long x) {
    long factor = id0(solver, x);
    long cnt = 0;
    long y = x;
    while (y % factor == 0) {
        cnt++;
        y /= factor;
    }
    if (cnt > 1) {
        id1_put(&solver->mu, x, 0);
    } else {
        id1_put(&solver->mu, x, -id1_get(&solver->mu, y));
    }
    id1_put(&solver->euler, x, id1_get(&solver->euler, y) * (x / y - x / y / factor));
}

long mu(id3 *solver, long x) {
    long ans = id1_get(&solver->mu, x);
    if (ans == 0) {
        populate(solver, x);
        ans = id1_get(&solver->mu, x);
    }
    return ans;
}

long euler(id3 *solver, long x) {
    long ans = id1_get(&solver->euler, x);
    if (ans == 0) {
        populate(solver, x);
        ans = id1_get(&solver->euler, x);
    }
    return ans;
}

void collect(LongList *list, id3 *solver, long x, int i) {
    if (i == MAX_CAPACITY) {
        LongList_add(list, x);
        return;
    }
    collect(list, solver, x, i + 1);
    while (x % solver->primes[i] == 0) {
        x /= solver->primes[i];
        collect(list, solver, x, i + 1);
    }
}

void solve(id3 *solver, long m, long x) {
    LongList id9;
    LongList_init(&id9, 20000);
    LongList tmpList;
    LongList_init(&tmpList, 20000);
    LongList id2;
    LongList_init(&id2, 0);

    // Populate primes (this part needs to be implemented)
    // solver->primes = Factorization_id13(m);

    for (int i = 0; solver->primes[i] != 0; i++) {
        LongList_add(&id2, solver->primes[i]);
        // Add logic to add factors of (p - 1)
    }

    // Unique logic for id2
    // ...

    collect(&id9, solver, m, 0);
    LongPower power = { .modular = NULL }; // Initialize LongPower

    long total = 1;
    for (int i = 0; i < id9.size; i++) {
        long g = id9.data[i];
        if (g == m) {
            continue;
        }
        long mg = m / g;
        LongList_clear(&tmpList);
        collect(&tmpList, solver, mg, 0);
        long cnt = 0;
        for (int j = tmpList.size - 1; j >= 0; j--) {
            long t = tmpList.data[j];
            cnt += mu(solver, t) * ((m - 1) / (t * g));
        }

        LongList_clear(&tmpList);
        long eulerValue = euler(solver, mg);
        LongList primeFactors;
        LongList_init(&primeFactors, 0);
        for (int j = 0; j < id2.size; j++) {
            long p = id2.data[j];
            if (eulerValue % p == 0) {
                LongList_add(&primeFactors, p);
            }
        }

        long n = eulerValue;
        for (int j = 0; j < primeFactors.size; j++) {
            long p = primeFactors.data[j];
            while (n % p == 0 && power.modular->m == 1) { // Placeholder for power calculation
                n /= p;
            }
        }

        if (cnt % n != 0) {
            fprintf(stderr, "Illegal State\n");
            exit(EXIT_FAILURE);
        }
        total += cnt / n;
    }

    printf("%ld\n", total);
}

int main() {
    long m, x;
    scanf("%ld %ld", &m, &x);
    id3 solver;
    id3_init(&solver);
    solve(&solver, m, x);
    return 0;
}

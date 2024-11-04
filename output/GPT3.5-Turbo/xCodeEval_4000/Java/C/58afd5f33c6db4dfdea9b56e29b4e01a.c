#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 100000

typedef struct {
    long long key;
    long long value;
} LongEntry;

typedef struct {
    int size;
    LongEntry entries[MAX_SIZE];
} LongHashMap;

void longHashMapInit(LongHashMap* map) {
    map->size = 0;
}

void longHashMapPut(LongHashMap* map, long long key, long long value) {
    for (int i = 0; i < map->size; i++) {
        if (map->entries[i].key == key) {
            map->entries[i].value = value;
            return;
        }
    }
    map->entries[map->size].key = key;
    map->entries[map->size].value = value;
    map->size++;
}

long long longHashMapGet(LongHashMap* map, long long key, long long defaultValue) {
    for (int i = 0; i < map->size; i++) {
        if (map->entries[i].key == key) {
            return map->entries[i].value;
        }
    }
    return defaultValue;
}

typedef struct {
    int size;
    long long data[MAX_SIZE];
} LongList;

void longListInit(LongList* list) {
    list->size = 0;
}

void longListAdd(LongList* list, long long value) {
    list->data[list->size] = value;
    list->size++;
}

void longListAddAll(LongList* list, LongList* other) {
    for (int i = 0; i < other->size; i++) {
        longListAdd(list, other->data[i]);
    }
}

void longListSort(LongList* list) {
    for (int i = 0; i < list->size; i++) {
        for (int j = i + 1; j < list->size; j++) {
            if (list->data[i] > list->data[j]) {
                long long temp = list->data[i];
                list->data[i] = list->data[j];
                list->data[j] = temp;
            }
        }
    }
}

void longListUnique(LongList* list) {
    LongList temp;
    longListInit(&temp);

    for (int i = 0; i < list->size; i++) {
        if (i == 0 || list->data[i] != list->data[i - 1]) {
            longListAdd(&temp, list->data[i]);
        }
    }

    for (int i = 0; i < temp.size; i++) {
        list->data[i] = temp.data[i];
    }

    list->size = temp.size;
}

typedef struct {
    long long m;
} LongModular;

long long longModularMul(LongModular* modular, long long a, long long b) {
    return (a * b) % modular->m;
}

typedef struct {
    long long x;
    long long y;
} FastOutput;

void fastOutputInit(FastOutput* output) {
    output->x = 0;
    output->y = 0;
}

void fastOutputAppend(FastOutput* output, char c) {
    printf("%c", c);
}

void fastOutputPrintln(FastOutput* output, long long c) {
    printf("%lld\n", c);
}

typedef struct {
    long long x;
    long long y;
} FastInput;

void fastInputInit(FastInput* input) {
    input->x = 0;
    input->y = 0;
}

void fastInputSkipBlank(FastInput* input) {
    char c = getchar();
    while (c >= 0 && c <= 32) {
        c = getchar();
    }
    ungetc(c, stdin);
}

long long fastInputReadLong(FastInput* input) {
    long long sign = 1;

    fastInputSkipBlank(input);
    char c = getchar();
    if (c == '+' || c == '-') {
        sign = (c == '+') ? 1 : -1;
        c = getchar();
    }

    long long val = 0;
    while (c >= '0' && c <= '9') {
        val = val * 10 + (c - '0');
        c = getchar();
    }

    return sign * val;
}

void solve(int testNumber, FastInput* in, FastOutput* out);

int main() {
    FastInput in;
    FastOutput out;
    fastInputInit(&in);
    fastOutputInit(&out);

    solve(1, &in, &out);

    return 0;
}

long long oneOfPrimeFactor(long long x, LongList* primes) {
    for (int i = 0; i < primes->size; i++) {
        long long p = primes->data[i];
        if (x % p == 0) {
            return p;
        }
    }
    return x;
}

void populate(LongHashMap* mu, LongHashMap* euler, long long x, LongList* primes) {
    long long factor = oneOfPrimeFactor(x, primes);
    long long cnt = 0;
    long long y = x;
    while (y % factor == 0) {
        cnt++;
        y /= factor;
    }
    if (cnt > 1) {
        longHashMapPut(mu, x, 0);
    } else {
        longHashMapPut(mu, x, -longHashMapGet(mu, y, 0));
    }
    longHashMapPut(euler, x, longHashMapGet(euler, y, 1) * (x / y - x / y / factor));
}

long long mu(LongHashMap* mu, LongHashMap* euler, long long x, LongList* primes) {
    long long ans = longHashMapGet(mu, x, -1);
    if (ans == -1) {
        populate(mu, euler, x, primes);
        ans = longHashMapGet(mu, x, 0);
    }
    return ans;
}

long long euler(LongHashMap* mu, LongHashMap* euler, long long x, LongList* primes) {
    long long ans = longHashMapGet(euler, x, -1);
    if (ans == -1) {
        populate(mu, euler, x, primes);
        ans = longHashMapGet(euler, x, 1);
    }
    return ans;
}

void solve(int testNumber, FastInput* in, FastOutput* out) {
    long long m = fastInputReadLong(in);
    long long x = fastInputReadLong(in);

    LongList primes;
    longListInit(&primes);
    for (long long i = 2; i * i <= m; i++) {
        if (m % i == 0) {
            longListAdd(&primes, i);
            while (m % i == 0) {
                m /= i;
            }
        }
    }
    if (m > 1) {
        longListAdd(&primes, m);
    }

    LongList allFactorOfM;
    longListInit(&allFactorOfM);
    LongList tmpList;
    longListInit(&tmpList);
    LongList allPossiblePrimeFactor;
    longListInit(&allPossiblePrimeFactor);
    for (int i = 0; i < primes.size; i++) {
        long long p = primes.data[i];
        longListAdd(&allPossiblePrimeFactor, p);
        for (long long j = 2; j < p; j++) {
            if (p % j == 0) {
                longListAdd(&allPossiblePrimeFactor, j);
            }
        }
    }
    longListUnique(&allPossiblePrimeFactor);

    longListAdd(&allFactorOfM, m);
    for (int i = 0; i < allFactorOfM.size; i++) {
        long long g = allFactorOfM.data[i];
        if (g == m) {
            continue;
        }
        long long mg = m / g;
        longListInit(&tmpList);
        for (int j = 0; j < tmpList.size; j++) {
            long long t = tmpList.data[j];
            long cnt = 0;
            for (int k = tmpList.size - 1; k >= 0; k--) {
                long long t = tmpList.data[k];
                cnt += mu(mu, euler, t, &primes) * ((m - 1) / (t * g));
            }

            longListInit(&tmpList);
            long euler = euler(euler, mu, mg, &primes);
            longListInit(&primeFactors);
            for (int j = 0; j < allPossiblePrimeFactor.size; j++) {
                long long p = allPossiblePrimeFactor.data[j];
                if (euler % p == 0) {
                    longListAdd(&primeFactors, p);
                }
            }

            long n = euler;
            for (int j = 0; j < primeFactors.size; j++) {
                long long p = primeFactors.data[j];
                while (n % p == 0 && longModularPow(x, n / p, mg) == 1) {
                    n /= p;
                }
            }

            if (cnt % n != 0) {
                printf("Error\n");
                return;
            }
            total += cnt / n;
        }
    }

    fastOutputPrintln(out, total);
}

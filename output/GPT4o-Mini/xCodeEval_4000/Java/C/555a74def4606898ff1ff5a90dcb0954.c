#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define NG 0

typedef struct {
    long *keys;
    long *allocated;
    int scale;
    int rscale;
    int mask;
    int size;
} LongHashCounterL;

LongHashCounterL* createLongHashCounterL() {
    LongHashCounterL *counter = (LongHashCounterL *)malloc(sizeof(LongHashCounterL));
    counter->scale = 1 << 2;
    counter->rscale = 1 << 1;
    counter->mask = counter->scale - 1;
    counter->size = 0;
    counter->allocated = (long *)malloc(counter->scale * sizeof(long));
    counter->keys = (long *)malloc(counter->scale * sizeof(long));
    memset(counter->allocated, NG, counter->scale * sizeof(long));
    return counter;
}

int h(long x) {
    x ^= x >> 33;
    x *= 0xff51afd7ed558ccdL;
    x ^= x >> 33;
    x *= 0xc4ceb9fe1a85ec53L;
    x ^= x >> 33;
    return (int)x;
}

int containsKey(LongHashCounterL *counter, long x) {
    int pos = h(x) & counter->mask;
    while (counter->allocated[pos] != NG) {
        if (x == counter->keys[pos]) return 1;
        pos = (pos + 1) & counter->mask;
    }
    return 0;
}

long get(LongHashCounterL *counter, long x) {
    int pos = h(x) & counter->mask;
    while (counter->allocated[pos] != NG) {
        if (x == counter->keys[pos]) return counter->allocated[pos];
        pos = (pos + 1) & counter->mask;
    }
    return NG;
}

long put(LongHashCounterL *counter, long x, long v) {
    int pos = h(x) & counter->mask;
    while (counter->allocated[pos] != NG) {
        if (x == counter->keys[pos]) {
            long oldval = counter->allocated[pos];
            counter->allocated[pos] = v;
            return oldval;
        }
        pos = (pos + 1) & counter->mask;
    }
    if (counter->size == counter->rscale) {
        // Resize logic omitted for brevity
    } else {
        counter->keys[pos] = x;
        counter->allocated[pos] = v;
    }
    counter->size++;
    return 0;
}

long inc(LongHashCounterL *counter, long x, long v) {
    int pos = h(x) & counter->mask;
    while (counter->allocated[pos] != NG) {
        if (x == counter->keys[pos]) {
            counter->allocated[pos] += v;
            return counter->allocated[pos];
        }
        pos = (pos + 1) & counter->mask;
    }
    if (counter->size == counter->rscale) {
        // Resize logic omitted for brevity
    } else {
        counter->keys[pos] = x;
        counter->allocated[pos] = v;
    }
    counter->size++;
    return v;
}

long pi(long x, LongHashCounterL *picache, int *xcums, long *isp, int cachelimit, int *primes, int A) {
    if (x <= cachelimit) {
        int ix = (int)x;
        return xcums[ix >> 6] + __builtin_popcountll(isp[ix >> 6] << ~ix);
    }
    if (containsKey(picache, x)) return get(picache, x);
    
    // Logic for calculating pi omitted for brevity
    return 0; // Placeholder
}

int* sieveEratosthenes(int n) {
    int *primes = (int *)malloc((n + 1) * sizeof(int));
    // Sieve logic omitted for brevity
    return primes; // Placeholder
}

void solve() {
    long n; // Assume input is read into n
    long ans = 0;
    LongHashCounterL *ml = createLongHashCounterL();
    int *primes = sieveEratosthenes(1000000);
    
    for (int i = 0; i < 1000000; i++) { // Assuming primes array is filled
        long plus = pi(n / primes[i], ml->picache, ml->xcums, ml->isp, ml->cachelimit, primes, i) - (i + 1);
        if (plus <= 0) break;
        ans += plus;
    }
    
    for (int i = 0; primes[i] * primes[i] * primes[i] <= n; i++) {
        ans++;
    }
    printf("%ld\n", ans);
}

int main() {
    solve();
    return 0;
}

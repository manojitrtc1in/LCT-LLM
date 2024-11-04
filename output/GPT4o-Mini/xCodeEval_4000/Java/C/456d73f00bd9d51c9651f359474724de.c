#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <string.h>

#define MOD 1000000007

typedef struct {
    long *elements;
    int size;
    int capacity;
} ElementCounter;

typedef struct {
    long *hashes;
    long *modifiers;
} HashedString;

typedef struct {
    long P;
    long M;
} StringHasher;

void initElementCounter(ElementCounter *counter) {
    counter->size = 0;
    counter->capacity = 10;
    counter->elements = (long *)malloc(counter->capacity * sizeof(long));
}

void addElement(ElementCounter *counter, long element) {
    if (counter->size == counter->capacity) {
        counter->capacity *= 2;
        counter->elements = (long *)realloc(counter->elements, counter->capacity * sizeof(long));
    }
    counter->elements[counter->size++] = element;
}

void freeElementCounter(ElementCounter *counter) {
    free(counter->elements);
}

void initStringHasher(StringHasher *hasher) {
    hasher->P = 353873237; // Example prime
    hasher->M = 452940277; // Example modulus
}

HashedString hashString(StringHasher *hasher, const char *s) {
    int n = strlen(s);
    long *hashes = (long *)malloc(n * sizeof(long));
    long *modifiers = (long *)malloc(n * sizeof(long));
    hashes[0] = s[0];
    modifiers[0] = 1;
    for (int i = 1; i < n; i++) {
        hashes[i] = (hashes[i - 1] * hasher->P + s[i]) % hasher->M;
        modifiers[i] = (modifiers[i - 1] * hasher->P) % hasher->M;
    }
    HashedString result = {hashes, modifiers};
    return result;
}

long getHash(HashedString *hashedString, int startIndex, int endIndex, long M) {
    long result = hashedString->hashes[endIndex];
    if (startIndex > 0) {
        result -= (hashedString->hashes[startIndex - 1] * hashedString->modifiers[endIndex - startIndex + 1]) % M;
    }
    if (result < 0) result += M;
    return result;
}

void freeHashedString(HashedString *hashedString) {
    free(hashedString->hashes);
    free(hashedString->modifiers);
}

void solve() {
    long n, m;
    scanf("%ld %ld", &n, &m);
    if (m < n) {
        long helper = m;
        m = n;
        n = helper;
    }

    if (n == 1) {
        printf("%ld\n", brute1(m));
        return;
    }
    if (n == 2) {
        if (m < 3) printf("0\n");
        else if (m == 3) printf("4\n");
        else if (m == 7) printf("12\n");
        else printf("%ld\n", 2 * m);
        return;
    }

    printf("%ld\n", 2 * (n * m / 2));
}

long brute1(long m) {
    long ans = 6 * (m / 6);
    if (m % 6 == 5) ans += 4;
    else if (m % 6 == 4) ans += 2;
    return ans;
}

int main() {
    solve();
    return 0;
}

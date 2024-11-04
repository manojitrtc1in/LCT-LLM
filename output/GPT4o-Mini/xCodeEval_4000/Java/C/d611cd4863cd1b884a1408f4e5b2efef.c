#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <string.h>

#define MAX_SIZE 100000

typedef struct {
    long key;
    int value;
} HashEntry;

typedef struct {
    HashEntry *data;
    int capacity;
    int size;
} EHashMap;

EHashMap* createEHashMap(int maxSize) {
    EHashMap *map = (EHashMap *)malloc(sizeof(EHashMap));
    map->capacity = maxSize;
    map->size = 0;
    map->data = (HashEntry *)malloc(sizeof(HashEntry) * map->capacity);
    memset(map->data, 0, sizeof(HashEntry) * map->capacity);
    return map;
}

int hash(long key, int capacity) {
    return key % capacity;
}

void put(EHashMap *map, long key, int value) {
    int index = hash(key, map->capacity);
    map->data[index].key = key;
    map->data[index].value = value;
    map->size++;
}

int get(EHashMap *map, long key) {
    int index = hash(key, map->capacity);
    return map->data[index].value;
}

typedef struct {
    long *vertices;
    int size;
} Polygon;

Polygon* createPolygon(int size) {
    Polygon *polygon = (Polygon *)malloc(sizeof(Polygon));
    polygon->vertices = (long *)malloc(sizeof(long) * size);
    polygon->size = size;
    return polygon;
}

double square(Polygon *polygon) {
    double sum = 0;
    for (int i = 1; i < polygon->size; i++) {
        sum += (polygon->vertices[i] - polygon->vertices[i - 1]) * (polygon->vertices[i] + polygon->vertices[i - 1]);
    }
    sum += (polygon->vertices[0] - polygon->vertices[polygon->size - 1]) * (polygon->vertices[0] + polygon->vertices[polygon->size - 1]);
    return fabs(sum) / 2;
}

long prime(long n) {
    if (n <= 1) return -1;
    for (long i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            while (n % i == 0) n /= i;
            return n == 1 ? i : -1;
        }
    }
    return n;
}

void process(EHashMap *map, long x, int *idx, EHashMap *divides) {
    put(map, x, (*idx)++);
    long p = prime(x - 1);
    if (p > 0) {
        put(divides, p, 0); // Placeholder for list
    }
}

void solve(long A) {
    EHashMap *map = createEHashMap(MAX_SIZE);
    EHashMap *divides = createEHashMap(MAX_SIZE);
    long dp[2][MAX_SIZE];
    int idx = 0;

    for (long i = 1; i * i <= A; i++) {
        if (A % i == 0) {
            process(map, i, &idx, divides);
            if (i * i != A) process(map, A / i, &idx, divides);
        }
    }

    dp[0][get(map, 1)] = 1;
    idx = 0;

    // Logic for filling dp array would go here

    printf("%ld\n", dp[idx][get(map, A)]);
}

int main() {
    long A;
    scanf("%ld", &A);
    solve(A);
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <string.h>

typedef struct {
    long key;
    int value;
} HashEntry;

typedef struct {
    HashEntry *data;
    int size;
    int capacity;
} HashMap;

typedef struct {
    long *divides;
    int size;
} LongList;

typedef struct {
    long **dp;
    HashMap *map;
    LongList *divides;
    int idx;
} Task;

HashMap* createHashMap(int capacity) {
    HashMap *map = (HashMap *)malloc(sizeof(HashMap));
    map->data = (HashEntry *)malloc(sizeof(HashEntry) * capacity);
    map->size = 0;
    map->capacity = capacity;
    return map;
}

void put(HashMap *map, long key, int value) {
    int index = key % map->capacity;
    while (map->data[index].key != 0) {
        index = (index + 1) % map->capacity;
    }
    map->data[index].key = key;
    map->data[index].value = value;
    map->size++;
}

int get(HashMap *map, long key) {
    int index = key % map->capacity;
    while (map->data[index].key != 0) {
        if (map->data[index].key == key) {
            return map->data[index].value;
        }
        index = (index + 1) % map->capacity;
    }
    return -1; // Not found
}

void process(Task *task, long x) {
    put(task->map, x, task->idx++);
    long p = prime(x - 1);
    if (p > 0) {
        task->divides->divides[task->divides->size++] = x;
    }
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

void solve(Task *task, long A) {
    for (long i = 1; i * i <= A; i++) {
        if (A % i == 0) {
            process(task, i);
            if (i * i != A) process(task, A / i);
        }
    }
    
    task->dp = (long **)malloc(2 * sizeof(long *));
    task->dp[0] = (long *)calloc(task->map->capacity, sizeof(long));
    task->dp[1] = (long *)calloc(task->map->capacity, sizeof(long));
    
    task->dp[0][get(task->map, 1)] = 1;
    int idx = 0;
    
    for (int i = 0; i < task->divides->size; i++) {
        idx ^= 1;
        for (int j = 0; j < task->map->capacity; j++) {
            long jKey = task->map->data[j].key;
            if (jKey != 0) {
                int j2 = get(task->map, jKey);
                task->dp[idx][j2] = task->dp[idx ^ 1][j2];
                for (int x = 0; x < task->divides->size; x++) {
                    if (jKey % task->divides->divides[x] == 0) {
                        task->dp[idx][j2] += task->dp[idx ^ 1][get(task->map, jKey / task->divides->divides[x])];
                    }
                }
            }
        }
    }
    printf("%ld\n", task->dp[idx][get(task->map, A)]);
}

int main() {
    long A;
    scanf("%ld", &A);
    
    Task *task = (Task *)malloc(sizeof(Task));
    task->map = createHashMap(100);
    task->divides = (LongList *)malloc(sizeof(LongList));
    task->divides->divides = (long *)malloc(sizeof(long) * 100);
    task->divides->size = 0;
    task->idx = 0;
    
    solve(task, A);
    
    free(task->map->data);
    free(task->map);
    free(task->divides->divides);
    free(task->divides);
    free(task->dp[0]);
    free(task->dp[1]);
    free(task->dp);
    free(task);
    
    return 0;
}

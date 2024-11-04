#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

typedef struct {
    int *data;
    int size;
    int capacity;
} TreeSet;

typedef struct {
    int *keys;
    TreeSet **values;
    int size;
    int capacity;
} HashMap;

typedef struct {
    int n;
    int m;
    int *arr;
    int required;
    HashMap *typeDays;
} F;

void initTreeSet(TreeSet *set) {
    set->size = 0;
    set->capacity = 10;
    set->data = (int *)malloc(set->capacity * sizeof(int));
}

void addTreeSet(TreeSet *set, int value) {
    if (set->size >= set->capacity) {
        set->capacity *= 2;
        set->data = (int *)realloc(set->data, set->capacity * sizeof(int));
    }
    set->data[set->size++] = value;
}

int floorTreeSet(TreeSet *set, int value) {
    for (int i = set->size - 1; i >= 0; i--) {
        if (set->data[i] <= value) {
            return set->data[i];
        }
    }
    return -1; // Not found
}

void initHashMap(HashMap *map) {
    map->size = 0;
    map->capacity = 10;
    map->keys = (int *)malloc(map->capacity * sizeof(int));
    map->values = (TreeSet **)malloc(map->capacity * sizeof(TreeSet *));
}

void putHashMap(HashMap *map, int key, TreeSet *value) {
    if (map->size >= map->capacity) {
        map->capacity *= 2;
        map->keys = (int *)realloc(map->keys, map->capacity * sizeof(int));
        map->values = (TreeSet **)realloc(map->values, map->capacity * sizeof(TreeSet *));
    }
    map->keys[map->size] = key;
    map->values[map->size] = value;
    map->size++;
}

TreeSet *getHashMap(HashMap *map, int key) {
    for (int i = 0; i < map->size; i++) {
        if (map->keys[i] == key) {
            return map->values[i];
        }
    }
    return NULL; // Not found
}

int sum(int *arr, int size) {
    int total = 0;
    for (int i = 0; i < size; i++) {
        total += arr[i];
    }
    return total;
}

int isEnough(F *f, int day) {
    int totalCoin = day;
    int req = f->required;

    int *ddays = (int *)calloc(day + 1, sizeof(int));
    for (int i = 0; i < f->typeDays->size; i++) {
        int typ = f->typeDays->keys[i];
        TreeSet *set = f->typeDays->values[i];
        int lastDay = floorTreeSet(set, day);
        if (lastDay == -1) continue;
        ddays[lastDay] += f->arr[typ - 1];
    }

    int removed = 0;
    for (int i = 1; i <= day; i++) {
        int coins = i - removed;
        int toRemove = (coins < ddays[i]) ? coins : ddays[i];
        removed += toRemove;
        totalCoin -= toRemove;
        req -= toRemove;
    }

    free(ddays);
    return req * 2 <= totalCoin;
}

void solver(F *f) {
    scanf("%d %d", &f->n, &f->m);
    f->arr = (int *)malloc(f->n * sizeof(int));
    for (int i = 0; i < f->n; i++) {
        scanf("%d", &f->arr[i]);
    }
    f->required = sum(f->arr, f->n);
    f->typeDays = (HashMap *)malloc(sizeof(HashMap));
    initHashMap(f->typeDays);

    for (int i = 0; i < f->m; i++) {
        int d, typ;
        scanf("%d %d", &d, &typ);
        if (f->arr[typ - 1] <= 0) continue;
        TreeSet *set = getHashMap(f->typeDays, typ);
        if (set == NULL) {
            set = (TreeSet *)malloc(sizeof(TreeSet));
            initTreeSet(set);
            putHashMap(f->typeDays, typ, set);
        }
        addTreeSet(set, d);
    }

    int lo = f->required;
    int hi = 2 * f->required;
    int valid = hi;
    while (lo <= hi) {
        int mid = (lo + hi) / 2;
        if (isEnough(f, mid)) {
            valid = mid;
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }
    printf("%d\n", valid);
}

int main() {
    F f;
    solver(&f);
    free(f.arr);
    for (int i = 0; i < f.typeDays->size; i++) {
        free(f.typeDays->values[i]->data);
        free(f.typeDays->values[i]);
    }
    free(f.typeDays->keys);
    free(f.typeDays->values);
    free(f.typeDays);
    return 0;
}

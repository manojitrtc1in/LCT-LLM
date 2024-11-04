#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define MAX_N 100000
#define MAX_M 100000
#define MOD 1000000007

typedef struct {
    int *arr;
    int size;
} TreeSet;

typedef struct {
    int key;
    TreeSet *value;
} HashMap;

typedef struct {
    int n;
    int m;
    int arr[MAX_N];
    long required;
    HashMap typeDays[MAX_N];
} F;

void initTreeSet(TreeSet *set) {
    set->arr = (int *)malloc(MAX_M * sizeof(int));
    set->size = 0;
}

void addToTreeSet(TreeSet *set, int value) {
    set->arr[set->size++] = value;
}

int floorInTreeSet(TreeSet *set, int value) {
    int result = -1;
    for (int i = 0; i < set->size; i++) {
        if (set->arr[i] <= value) {
            result = set->arr[i];
        }
    }
    return result;
}

long sum(int *arr, int size) {
    long total = 0;
    for (int i = 0; i < size; i++) {
        total += arr[i];
    }
    return total;
}

int isEnough(F *f, int day) {
    long totalCoin = day;
    long req = f->required;

    int ddays[day + 1];
    memset(ddays, 0, sizeof(ddays));

    for (int i = 0; i < f->n; i++) {
        if (f->typeDays[i].value) {
            int lastDay = floorInTreeSet(f->typeDays[i].value, day);
            if (lastDay != -1) {
                ddays[lastDay] += f->arr[i];
            }
        }
    }

    int removed = 0;
    for (int i = 1; i <= day; i++) {
        int coins = i - removed;
        int toRemove = (coins < ddays[i]) ? coins : ddays[i];
        removed += toRemove;
        totalCoin -= toRemove;
        req -= toRemove;
    }

    return req * 2 <= totalCoin;
}

void solver(F *f) {
    scanf("%d %d", &f->n, &f->m);
    for (int i = 0; i < f->n; i++) {
        scanf("%d", &f->arr[i]);
    }
    f->required = sum(f->arr, f->n);

    for (int i = 0; i < f->m; i++) {
        int d, typ;
        scanf("%d %d", &d, &typ);
        if (f->arr[typ - 1] <= 0) continue;
        if (f->typeDays[typ - 1].value == NULL) {
            initTreeSet(&f->typeDays[typ - 1]);
        }
        addToTreeSet(&f->typeDays[typ - 1], d);
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
    memset(&f, 0, sizeof(f));
    solver(&f);
    return 0;
}

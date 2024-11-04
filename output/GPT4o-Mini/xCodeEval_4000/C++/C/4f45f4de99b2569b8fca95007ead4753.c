#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <unordered_map>

static const int MOD = 1000000007;
static const long long MODL = 1000000000000000003LL;
static const double eps = 1e-8;

typedef long long lld;
typedef struct {
    int key;
    int val;
} pair;

typedef struct {
    pair *data;
    int size;
    int capacity;
} unordered_map;

void init_map(unordered_map *map) {
    map->size = 0;
    map->capacity = 10;
    map->data = (pair *)malloc(sizeof(pair) * map->capacity);
}

void clear_map(unordered_map *map) {
    map->size = 0;
}

void put(unordered_map *map, int key, int val) {
    if (val == 0) return;
    for (int i = 0; i < map->size; i++) {
        if (map->data[i].key == key) {
            map->data[i].val += val;
            return;
        }
    }
    if (map->size == map->capacity) {
        map->capacity *= 2;
        map->data = (pair *)realloc(map->data, sizeof(pair) * map->capacity);
    }
    map->data[map->size].key = key;
    map->data[map->size].val = val;
    map->size++;
}

int pop(unordered_map *map, int key, int val) {
    for (int i = 0; i < map->size; i++) {
        if (map->data[i].key == key) {
            int res = 0;
            if (map->data[i].val > val) {
                res = val;
                map->data[i].val -= val;
            } else {
                res = map->data[i].val;
                map->data[i] = map->data[--map->size];
            }
            return res;
        }
    }
    return 0;
}

unordered_map open, close;

int n;
lld a[110000];
int _seq[50], _sup[50];
int seq[50], sup[50];

int process(int from) {
    for (int i = 0; i < 50; i++) seq[i] = _seq[i];
    for (int i = 0; i < 50; i++) sup[i] = _sup[i];
    if (from + from < seq[0]) return 1;
    clear_map(&open);
    clear_map(&close);
    put(&open, 0, from - (seq[0] - from));
    put(&close, 0, seq[0] - from);
    for (int i = 1; i < 45; i++) {
        int ext = pop(&open, i - 1, seq[i]);
        seq[i] -= ext;
        put(&open, i, ext);
        ext = pop(&close, i - 1, seq[i]);
        sup[i] += seq[i] - ext;
        put(&close, i, ext);
        int cls = pop(&open, i, sup[i]);
        sup[i + 1] += sup[i] - cls;
        put(&close, i, cls);
    }
    if (sup[45] != 0) return 1;
    return 0;
}

int find(int lef, int rig) {
    while (lef <= rig) {
        int mid = (lef + rig) >> 1;
        if (!process(mid)) {
            if (mid == lef || process(mid - 1)) {
                return mid;
            }
            rig = mid - 1;
        } else {
            lef = mid + 1;
        }
    }
    return -1;
}

int main() {
    init_map(&open);
    init_map(&close);
    while (scanf("%d", &n) != EOF) {
        for (int i = 0; i < n; i++) {
            scanf("%lld", &a[i]);
        }
        for (int i = 0; i < 50; i++) {
            _seq[i] = 0;
            _sup[i] = 0;
        }
        int cur = 0;
        for (int i = 0; i < n; i++) {
            while (a[i] >= (1LL << (cur + 1))) cur++;
            if (a[i] == (1LL << cur)) {
                _seq[cur]++;
            } else {
                _sup[cur]++;
            }
        }
        if (process(_seq[0])) {
            printf("-1\n");
        } else {
            int hig = _seq[0];
            int low = find(1, hig);
            for (int i = low; i <= hig; i++) {
                if (i != low) printf(" ");
                printf("%d", i);
            }
            printf("\n");
        }
    }
    free(open.data);
    free(close.data);
    return 0;
}

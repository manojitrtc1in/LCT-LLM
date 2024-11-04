#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <unordered_map>

#define MOD 1000000007
#define MODL 1000000000000000003LL
#define EPS 1e-8
#define INF 0x3f3f3f3f

typedef long long lld;
typedef struct {
    int x, y;
} pii;

typedef struct {
    lld r, i;
} complex_t;

typedef struct {
    double x, y;
} point_t;

typedef struct {
    point_t p, q;
} segment_t;

typedef struct {
    std::unordered_map<int, int> foo;
} id13;

int seq[50], sup[50], _seq[50], _sup[50];
lld a[110000];
int n;

void clear_map(id13 *map) {
    map->foo.clear();
}

void put(id13 *map, int key, int val) {
    if (val == 0) return;
    auto it = map->foo.find(key);
    if (it != map->foo.end()) {
        it->second += val;
    } else {
        map->foo.insert({key, val});
    }
}

int pop(id13 *map, int key, int val) {
    int res = 0;
    auto it = map->foo.find(key);
    if (it != map->foo.end()) {
        if (it->second > val) {
            res = val;
            it->second -= val;
        } else {
            res = it->second;
            map->foo.erase(it);
        }
    }
    return res;
}

int process(int from, id13 *open, id13 *close) {
    for (int i = 0; i < 50; i++) seq[i] = _seq[i];
    for (int i = 0; i < 50; i++) sup[i] = _sup[i];
    if (from + from < seq[0]) return 1;
    clear_map(open);
    clear_map(close);
    put(open, 0, from - (seq[0] - from));
    put(close, 0, seq[0] - from);
    for (int i = 1; i < 45; i++) {
        int ext = pop(open, i - 1, seq[i]);
        seq[i] -= ext;
        put(open, i, ext);
        ext = pop(close, i - 1, seq[i]);
        sup[i] += seq[i] - ext;
        put(close, i, ext);
        int cls = pop(open, i, sup[i]);
        sup[i + 1] += sup[i] - cls;
        put(close, i, cls);
    }
    if (sup[45] != 0) return 1;
    return 0;
}

int find(int lef, int rig) {
    while (lef <= rig) {
        int mid = (lef + rig) >> 1;
        if (!process(mid, &open, &close)) {
            if (mid == lef || process(mid - 1, &open, &close)) {
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
        if (process(_seq[0], &open, &close)) {
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
    return 0;
}

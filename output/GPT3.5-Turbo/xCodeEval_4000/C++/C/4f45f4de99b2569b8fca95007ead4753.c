#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MOD 1000000007
#define MODL 1000000000000000003LL
#define PI acos(-1.0)

typedef long long lld;

typedef struct {
    int x, y;
} point_t;

typedef struct {
    point_t p, q;
} segment_t;

typedef struct {
    int foo[110];
} chest_t;

int inf = 0x3f3f3f3f;

int n;
lld a[110000];
int _seq[50], _sup[50];
int seq[50], sup[50];

void chest_clear(chest_t *c) {
    for (int i = 0; i < 110; i++) {
        c->foo[i] = 0;
    }
}

void chest_put(chest_t *c, int key, int val) {
    if (val == 0) return;
    c->foo[key] += val;
}

int chest_pop(chest_t *c, int key, int val) {
    int res = 0;
    if (c->foo[key] > 0) {
        if (c->foo[key] > val) {
            res = val;
            c->foo[key] -= val;
        } else {
            res = c->foo[key];
            c->foo[key] = 0;
        }
    }
    return res;
}

int process(int from) {
    for (int i = 0; i < 50; i++) seq[i] = _seq[i];
    for (int i = 0; i < 50; i++) sup[i] = _sup[i];
    if (from + from < seq[0]) return 1;
    chest_t open, close;
    chest_clear(&open);
    chest_clear(&close);
    chest_put(&open, 0, from - (seq[0] - from));
    chest_put(&close, 0, seq[0] - from);
    for (int i = 1; i < 45; i++) {
        int ext = chest_pop(&open, i - 1, seq[i]);
        seq[i] -= ext;
        chest_put(&open, i, ext);
        ext = chest_pop(&close, i - 1, seq[i]);
        sup[i] += seq[i] - ext;
        chest_put(&close, i, ext);
        int cls = chest_pop(&open, i, sup[i]);
        sup[i + 1] += sup[i] - cls;
        chest_put(&close, i, cls);
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
    while (scanf("%d", &n) == 1) {
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
    return 0;
}

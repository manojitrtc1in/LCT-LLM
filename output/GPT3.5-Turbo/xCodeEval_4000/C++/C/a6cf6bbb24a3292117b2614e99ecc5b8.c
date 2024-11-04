#include <stdio.h>
#include <stdlib.h>

#define MAXMEM 200 * 1000 * 1024

char _memory[MAXMEM];
size_t _ptr = 0;

void* operator new(size_t _x) {
    _ptr += _x;
    if (_ptr >= MAXMEM) {
        exit(1);
    }
    return _memory + _ptr - _x;
}

void operator delete(void*) noexcept {}

typedef struct {
    int have_mod;
    int value;
    int mod;
} Node;

typedef struct {
    int n;
    Node* S;
} TreeSegment;

int floor_mod(int a, int b) {
    if (a % b == 0) {
        return 0;
    }
    if (a >= 0 && b >= 0) {
        return a % b;
    }
    if (a <= 0 && b <= 0) {
        return a % b;
    }
    return abs(b) - (abs(a) % abs(b));
}

int magic(int a, int b) {
    return a + b;
}

int apply_mod(int value, int mod, int tl, int tr) {
    return mod;
}

int merge_mods(int mod1, int mod2, int tl, int tr) {
    return mod2;
}

void init(TreeSegment* ts, int i, int tl, int tr, int* src) {
    if (tl + 1 == tr) {
        ts->S[i].value = src[tl];
    } else {
        int mid = (tl + tr) / 2;
        init(ts, i + 1, tl, mid, src);
        init(ts, i + (mid - tl) * 2, mid, tr, src);
        int value1 = ts->S[i + 1].value;
        int value2 = ts->S[i + (mid - tl) * 2].value;
        ts->S[i].value = magic(value1, value2);
    }
}

void tree_segment_init(TreeSegment* ts, int n, int def, int* src) {
    ts->n = n;
    ts->S = (Node*)malloc((2 * n + 1) * sizeof(Node));
    for (int i = 0; i < 2 * n + 1; i++) {
        ts->S[i].have_mod = 0;
    }
    init(ts, 0, 0, n, src);
}

int query(TreeSegment* ts, int i, int tl, int tr, int ql, int qr) {
    if (ql <= tl && tr <= qr) {
        return ts->S[i].value;
    } else {
        int mid = (tl + tr) / 2;
        if (tr <= ql || qr <= tl) {
            return 0;
        }
        int value1 = query(ts, i + 1, tl, mid, ql, qr);
        int value2 = query(ts, i + (mid - tl) * 2, mid, tr, ql, qr);
        return magic(value1, value2);
    }
}

void change(TreeSegment* ts, int i, int tl, int tr, int j, int _new) {
    if (tl + 1 == tr) {
        ts->S[i].value = _new;
    } else {
        int m = (tl + tr) / 2;
        if (j < m) {
            change(ts, ts->S[i].l, tl, m, j, _new);
        } else {
            change(ts, ts->S[i].r, m, tr, j, _new);
        }
        int value1 = ts->S[ts->S[i].l].value;
        int value2 = ts->S[ts->S[i].r].value;
        ts->S[i].value = magic(value1, value2);
    }
}

void update(TreeSegment* ts, int i, int tl, int tr, int ql, int qr, int mod) {
    if (ql <= tl && tr <= qr) {
        if (ts->S[i].have_mod) {
            ts->S[i].mod = merge_mods(ts->S[i].mod, mod, tl, tr);
        } else {
            ts->S[i].mod = mod;
            ts->S[i].have_mod = 1;
        }
    } else {
        int mid = (tl + tr) / 2;
        if (ql < mid) {
            update(ts, i + 1, tl, mid, ql, qr, mod);
        }
        if (mid < qr) {
            update(ts, i + (mid - tl) * 2, mid, tr, ql, qr, mod);
        }
        int value1 = ts->S[i + 1].value;
        int value2 = ts->S[i + (mid - tl) * 2].value;
        ts->S[i].value = magic(value1, value2);
    }
}

int find_right(TreeSegment* ts, int i, int tl, int tr, int L, int (*checker)(int), int pref) {
    if (tr <= L) {
        return -1;
    }
    if (tl + 1 == tr) {
        int _this = magic(pref, ts->S[i].value);
        if (checker(_this)) {
            return tl;
        } else {
            return -1;
        }
    } else {
        int mid = (tl + tr) / 2;
        if (L <= tl) {
            int _left = magic(pref, ts->S[i + 1].value);
            if (checker(_left)) {
                return find_right(ts, i + 1, tl, mid, L, checker, pref);
            } else {
                return find_right(ts, i + (mid - tl) * 2, mid, tr, L, checker, _left);
            }
        } else {
            int t = find_right(ts, i + 1, tl, mid, L, checker, pref);
            if (t != -1) {
                return t;
            }
            return find_right(ts, i + (mid - tl) * 2, mid, tr, L, checker, t);
        }
    }
}

int find_left(TreeSegment* ts, int i, int tl, int tr, int R, int (*checker)(int), int pref) {
    if (R < tl) {
        return -1;
    }
    if (tl + 1 == tr) {
        int _this = magic(pref, ts->S[i].value);
        if (checker(_this)) {
            return tl;
        } else {
            return -1;
        }
    } else {
        int mid = (tl + tr) / 2;
        if (tr <= R + 1) {
            int _right = magic(pref, ts->S[ts->S[i].r].value);
            if (checker(_right)) {
                return find_left(ts, ts->S[i].r, mid, tr, R, checker, pref);
            } else {
                return find_left(ts, ts->S[i].l, tl, mid, R, checker, _right);
            }
        } else {
            int t = find_left(ts, ts->S[i].r, mid, tr, R, checker, pref);
            if (t != -1) {
                return t;
            }
            return find_left(ts, ts->S[i].l, tl, mid, R, checker, t);
        }
    }
}

int main(int argc, char *argv[]) {
    int n, q;
    scanf("%d %d", &n, &q);
    int* pos = (int*)malloc(n * sizeof(int));
    int* w = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &pos[i]);
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &w[i]);
    }

    TreeSegment ts;
    tree_segment_init(&ts, n, 0, w);

    int* subw = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        subw[i] = (w[i] * (i - pos[i])) % MOD;
    }

    TreeSegment resp;
    tree_segment_init(&resp, n, 0, subw);

    for (int i = 0; i < q; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        if (x < 0) {
            int ind = -x;
            int _new = y;
            ind--;
            update(&ts, 0, 0, n, ind, ind + 1, _new);
            update(&resp, 0, 0, n, ind, ind + 1, (_new * (ind - pos[ind])) % MOD);
        } else {
            int l = x, r = y;
            l--;

            int sm = query(&ts, 0, 0, n, l, r);

            int bestL = find_right(&ts, 0, 0, n, l, [](int x) {
                return x * 2 >= sm;
            }, 0);

            int x = pos[bestL] - bestL + l;

            int left = 0;
            if (l < bestL) {
                left = query(&resp, 0, 0, n, l, bestL) + query(&ts, 0, 0, n, l, bestL) * (x - l);
            }
            int right = 0;
            if (bestL < r) {
                right = query(&resp, 0, 0, n, bestL, r) + query(&ts, 0, 0, n, bestL, r) * (x - l);
            }
            printf("%d\n", floor_mod(left - right, MOD));
        }
    }

    free(pos);
    free(w);
    free(subw);
    free(ts.S);
    free(resp.S);

    return 0;
}

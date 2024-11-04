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

void operator delete (void*) noexcept {}

typedef struct {
    int have_mod;
    int l;
    int r;
    int value;
    int mod;
} Node;

typedef struct {
    int* S;
    int n;
} TreeSegment;

int magic(int a, int b) {
    return a + b;
}

int apply_mod(int value, int mod, int tl, int tr) {
    return mod;
}

int merge_mods(int old, int _new, int tl, int tr) {
    return _new;
}

int __intersects(int tl, int tr, int ql, int qr) {
    return !(tr <= ql || qr <= tl);
}

int __create_node(int* S, int* len) {
    int i = *len;
    (*len)++;
    return i;
}

int __get_value(int i, int tl, int tr, int* S, Node* nodes) {
    if (!nodes[i].have_mod) {
        return nodes[i].value;
    }
    return apply_mod(nodes[i].value, nodes[i].mod, tl, tr);
}

void __recalc_value(int i, int tl, int tr, int* S, Node* nodes) {
    if (tl + 1 != tr) {
        int mid = (tl + tr) / 2;
        nodes[i].value = magic(
            __get_value(nodes[i].l, tl, mid, S, nodes),
            __get_value(nodes[i].r, mid, tr, S, nodes)
        );
    }
}

void __add_mod(int i, int tl, int tr, int mod, int* S, Node* nodes) {
    if (nodes[i].have_mod) {
        nodes[i].mod = merge_mods(nodes[i].mod, mod, tl, tr);
    } else {
        nodes[i].mod = mod;
        nodes[i].have_mod = 1;
    }
}

void __push(int i, int tl, int tr, int* S, Node* nodes) {
    if (nodes[i].have_mod) {
        nodes[i].value = apply_mod(nodes[i].value, nodes[i].mod, tl, tr);
        if (tl + 1 != tr) {
            int mid = (tl + tr) / 2;
            __add_mod(nodes[i].l, tl, mid, nodes[i].mod, S, nodes);
            __add_mod(nodes[i].r, mid, tr, nodes[i].mod, S, nodes);
        }
        nodes[i].have_mod = 0;
    }
}

int init(int tl, int tr, int* src, int* S, int* len, Node* nodes) {
    int i = __create_node(S, len);
    if (tl + 1 == tr) {
        nodes[i].value = src[tl];
    } else {
        int mid = (tl + tr) / 2;
        nodes[i].l = init(tl, mid, src, S, len, nodes);
        nodes[i].r = init(mid, tr, src, S, len, nodes);
        __recalc_value(i, tl, tr, S, nodes);
    }
    return i;
}

void tree_segment_init(TreeSegment* ts, int* src, int n, int* S, int* len, Node* nodes) {
    ts->n = n;
    ts->S = S;
    *len = 0;
    init(0, n, src, S, len, nodes);
}

int __query(int i, int tl, int tr, int ql, int qr, int* S, Node* nodes) {
    __push(i, tl, tr, S, nodes);
    if (ql <= tl && tr <= qr) {
        return nodes[i].value;
    } else {
        int mid = (tl + tr) / 2;
        if (__intersects(tl, mid, ql, qr) && __intersects(mid, tr, ql, qr)) {
            return magic(
                __query(nodes[i].l, tl, mid, ql, qr, S, nodes),
                __query(nodes[i].r, mid, tr, ql, qr, S, nodes)
            );
        } else if (__intersects(tl, mid, ql, qr)) {
            return __query(nodes[i].l, tl, mid, ql, qr, S, nodes);
        } else if (__intersects(mid, tr, ql, qr)) {
            return __query(nodes[i].r, mid, tr, ql, qr, S, nodes);
        } else {
            exit(1);
        }
    }
}

void tree_segment_query(TreeSegment* ts, int ql, int qr, int* S, Node* nodes, int* result) {
    *result = __query(0, 0, ts->n, ql, qr, S, nodes);
}

void __update(int i, int tl, int tr, int ql, int qr, int mod, int* S, Node* nodes) {
    __push(i, tl, tr, S, nodes);
    if (ql <= tl && tr <= qr) {
        __add_mod(i, tl, tr, mod, S, nodes);
    } else {
        int mid = (tl + tr) / 2;
        if (__intersects(tl, mid, ql, qr)) {
            __update(nodes[i].l, tl, mid, ql, qr, mod, S, nodes);    
        }
        if (__intersects(mid, tr, ql, qr)) {
            __update(nodes[i].r, mid, tr, ql, qr, mod, S, nodes);
        }
        __recalc_value(i, tl, tr, S, nodes);
    }
}

void tree_segment_update(TreeSegment* ts, int ql, int qr, int mod, int* S, Node* nodes) {
    __update(0, 0, ts->n, ql, qr, mod, S, nodes);
}

typedef int (*Check)(int);

int __find_right(int i, int tl, int tr, int L, Check checker, int pref, int* S, Node* nodes) {
    __push(i, tl, tr, S, nodes);
    if (tr <= L) {
        return -1;
    }
    if (tl + 1 == tr) {
        int _this = magic(pref, __get_value(i, tl, tr, S, nodes));
        if (checker(_this)) {
            return tl;
        } else {
            return -1;
        }
    } else {
        int mid = (tl + tr) / 2;
        if (L <= tl) {
            int _left = magic(pref, __get_value(nodes[i].l, tl, mid, S, nodes));
            if (checker(_left)) {
                return __find_right(nodes[i].l, tl, mid, L, checker, pref, S, nodes);
            } else {
                return __find_right(nodes[i].r, mid, tr, L, checker, _left, S, nodes);
            }
        } else {
            int t = __find_right(nodes[i].l, tl, mid, L, checker, pref, S, nodes);
            if (t != -1) {
                return t;
            }
            return __find_right(nodes[i].r, mid, tr, L, checker, pref, S, nodes);
        }    
    }
}

int tree_segment_find_right(TreeSegment* ts, int L, Check checker, int start, int* S, Node* nodes) {
    if (checker(start)) {
        return L - 1;
    }
    int rez = __find_right(0, 0, ts->n, L, checker, start, S, nodes);
    return (rez == -1) ? ts->n : rez;
}

int __find_left(int i, int tl, int tr, int R, Check checker, int pref, int* S, Node* nodes) {
    __push(i, tl, tr, S, nodes);
    if (R < tl) {
        return -1;
    }
    if (tl + 1 == tr) {
        int _this = magic(pref, __get_value(i, tl, tr, S, nodes));
        if (checker(_this)) {
            return tl;
        } else {
            return -1;
        }
    } else {
        int mid = (tl + tr) / 2;
        if (tr <= R + 1) {
            int _right = magic(pref, __get_value(nodes[i].r, mid, tr, S, nodes));
            if (checker(_right)) {
                return __find_left(nodes[i].r, mid, tr, R, checker, pref, S, nodes);
            } else {
                return __find_left(nodes[i].l, tl, mid, R, checker, _right, S, nodes);
            }
        } else {
            int t = __find_left(nodes[i].r, mid, tr, R, checker, pref, S, nodes);
            if (t != -1) {
                return t;
            }
            return __find_left(nodes[i].l, tl, mid, R, checker, t, S, nodes);
        }    
    }
}

int tree_segment_find_left(TreeSegment* ts, int R, Check checker, int start, int* S, Node* nodes) {
    if (checker(start)) {
        return R + 1;
    }
    int rez = __find_left(0, 0, ts->n, R, checker, start, S, nodes);
    return (rez == -1) ? -1 : rez;
}

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

    int* S = (int*)malloc(4 * n * sizeof(int));
    Node* nodes = (Node*)malloc(2 * n * sizeof(Node));

    int* subw = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        subw[i] = (w[i] * (i - pos[i])) % MOD;
    }

    TreeSegment ts;
    tree_segment_init(&ts, w, n, S, nodes);

    int* resp = (int*)malloc(4 * n * sizeof(int));
    TreeSegment resp_ts;
    tree_segment_init(&resp_ts, subw, n, resp, nodes);

    for (int i = 0; i < q; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        if (x < 0) {
            int ind = -x;
            int _new = y;
            ind--;
            tree_segment_update(&ts, ind, ind + 1, _new, S, nodes);
            tree_segment_update(&resp_ts, ind, ind + 1, (_new * (ind - pos[ind])) % MOD, resp, nodes);
        } else {
            int l = x, r = y;
            l--;

            int sm;
            tree_segment_query(&ts, l, r, S, nodes, &sm);

            int bestL = tree_segment_find_right(&ts, l, [sm](int x) {
                return x * 2 >= sm;
            }, 0, S, nodes);

            int x = pos[bestL] - bestL + l;

            int left = 0;
            if (l < bestL) {
                tree_segment_query(&resp_ts, l, bestL, resp, nodes, &left);
                left += sm * (x - l);
            }
            int right = 0;
            if (bestL < r) {
                tree_segment_query(&resp_ts, bestL, r, resp, nodes, &right);
                right += sm * (x - l);
            }
            printf("%d\n", floor_mod(left - right, MOD));
        }
    }

    free(pos);
    free(w);
    free(S);
    free(nodes);
    free(subw);
    free(resp);

    return 0;
}

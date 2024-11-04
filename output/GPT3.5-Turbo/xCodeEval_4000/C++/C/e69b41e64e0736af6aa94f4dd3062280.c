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

int __get_value(int* S, int i, int tl, int tr) {
    Node* node = (Node*)(S + i);
    if (!node->have_mod) {
        return node->value;
    }
    return apply_mod(node->value, node->mod, tl, tr);
}

void __recalc_value(int* S, int i, int tl, int tr) {
    Node* node = (Node*)(S + i);
    if (tl + 1 != tr) {
        int mid = (tl + tr) / 2;
        node->value = magic(
            __get_value(S, node->l, tl, mid),
            __get_value(S, node->r, mid, tr)
        );
    }
}

void __add_mod(int* S, int i, int tl, int tr, int sub) {
    Node* node = (Node*)(S + i);
    if (node->have_mod) {
        node->mod = merge_mods(node->mod, sub, tl, tr);
    } else {
        node->mod = sub;
        node->have_mod = 1;
    }
}

void __push(int* S, int i, int tl, int tr) {
    Node* node = (Node*)(S + i);
    if (node->have_mod) {
        node->value = apply_mod(node->value, node->mod, tl, tr);
        if (tl + 1 != tr) {
            int mid = (tl + tr) / 2;
            __add_mod(S, node->l, tl, mid, node->mod);
            __add_mod(S, node->r, mid, tr, node->mod);
        }
        node->have_mod = 0;
    }
}

int init(int* S, int* len, int tl, int tr, int* src) {
    int i = __create_node(S, len);
    Node* node = (Node*)(S + i);
    if (tl + 1 == tr) {
        node->value = src[tl];
    } else {
        int mid = (tl + tr) / 2;
        node->l = init(S, len, tl, mid, src);
        node->r = init(S, len, mid, tr, src);
        __recalc_value(S, i, tl, tr);
    }
    return i;
}

void __query(int* S, int i, int tl, int tr, int ql, int qr, int* result) {
    __push(S, i, tl, tr);
    if (ql <= tl && tr <= qr) {
        *result = ((Node*)(S + i))->value;
    } else {
        int mid = (tl + tr) / 2;
        if (__intersects(tl, mid, ql, qr) && __intersects(mid, tr, ql, qr)) {
            int left_result;
            __query(S, ((Node*)(S + i))->l, tl, mid, ql, qr, &left_result);
            int right_result;
            __query(S, ((Node*)(S + i))->r, mid, tr, ql, qr, &right_result);
            *result = magic(left_result, right_result);
        } else if (__intersects(tl, mid, ql, qr)) {
            __query(S, ((Node*)(S + i))->l, tl, mid, ql, qr, result);
        } else if (__intersects(mid, tr, ql, qr)) {
            __query(S, ((Node*)(S + i))->r, mid, tr, ql, qr, result);
        } else {
            exit(1);
        }
    }
}

void __update(int* S, int i, int tl, int tr, int ql, int qr, int mod) {
    __push(S, i, tl, tr);
    if (ql <= tl && tr <= qr) {
        __add_mod(S, i, tl, tr, mod);
    } else {
        int mid = (tl + tr) / 2;
        if (__intersects(tl, mid, ql, qr)) {
            __update(S, ((Node*)(S + i))->l, tl, mid, ql, qr, mod);
        }
        if (__intersects(mid, tr, ql, qr)) {
            __update(S, ((Node*)(S + i))->r, mid, tr, ql, qr, mod);
        }
        __recalc_value(S, i, tl, tr);
    }
}

void __find_right(int* S, int i, int tl, int tr, int L, int* result, int* pref) {
    __push(S, i, tl, tr);
    if (tr <= L) {
        *result = -1;
        *pref = *pref;
        return;
    }
    if (tl + 1 == tr) {
        int _this = magic(*pref, __get_value(S, i, tl, tr));
        if (_this * 2 >= *pref) {
            *result = tl;
            *pref = _this;
        } else {
            *result = -1;
            *pref = _this;
        }
    } else {
        int mid = (tl + tr) / 2;
        if (L <= tl) {
            int _left = magic(*pref, __get_value(S, ((Node*)(S + i))->l, tl, mid));
            if (_left * 2 >= *pref) {
                __find_right(S, ((Node*)(S + i))->l, tl, mid, L, result, pref);
            } else {
                __find_right(S, ((Node*)(S + i))->r, mid, tr, L, result, _left);
            }
        } else {
            __find_right(S, ((Node*)(S + i))->l, tl, mid, L, result, pref);
            if (*result != -1) {
                return;
            }
            __find_right(S, ((Node*)(S + i))->r, mid, tr, L, result, *pref);
        }
    }
}

void __find_left(int* S, int i, int tl, int tr, int R, int* result, int* pref) {
    __push(S, i, tl, tr);
    if (R < tl) {
        *result = -1;
        *pref = *pref;
        return;
    }
    if (tl + 1 == tr) {
        int _this = magic(*pref, __get_value(S, i, tl, tr));
        if (_this * 2 >= *pref) {
            *result = tl;
            *pref = _this;
        } else {
            *result = -1;
            *pref = _this;
        }
    } else {
        int mid = (tl + tr) / 2;
        if (tr <= R + 1) {
            int _right = magic(*pref, __get_value(S, ((Node*)(S + i))->r, mid, tr));
            if (_right * 2 >= *pref) {
                __find_left(S, ((Node*)(S + i))->r, mid, tr, R, result, pref);
            } else {
                __find_left(S, ((Node*)(S + i))->l, tl, mid, R, result, _right);
            }
        } else {
            __find_left(S, ((Node*)(S + i))->r, mid, tr, R, result, pref);
            if (*result != -1) {
                return;
            }
            __find_left(S, ((Node*)(S + i))->l, tl, mid, R, result, *pref);
        }
    }
}

void init(int* S, int* len, int* src, int n) {
    *len = 0;
    init(S, len, 0, n, src);
}

void query(int* S, int i, int tl, int tr, int ql, int qr, int* result) {
    __query(S, i, tl, tr, ql, qr, result);
}

void update(int* S, int i, int tl, int tr, int ql, int qr, int mod) {
    __update(S, i, tl, tr, ql, qr, mod);
}

int find_right(int* S, int i, int tl, int tr, int L, int* checker, int* start) {
    if (*checker) {
        return L - 1;
    }
    int rez;
    __find_right(S, i, tl, tr, L, &rez, start);
    return (rez == -1) ? tr : rez;
}

int find_left(int* S, int i, int tl, int tr, int R, int* checker, int* start) {
    if (*checker) {
        return R + 1;
    }
    int rez;
    __find_left(S, i, tl, tr, R, &rez, start);
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
    scanf("%d%d", &n, &q);
    int* pos = (int*)malloc(n * sizeof(int));
    int* w = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &pos[i]);
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &w[i]);
    }

    int* ts_S = (int*)malloc((4 * n * sizeof(Node)) + (n * sizeof(int)));
    int ts_len;
    init(ts_S, &ts_len, 0, n, w);

    int* subw = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        subw[i] = (w[i] * (i - pos[i])) % MOD;
    }

    int* resp_S = (int*)malloc((4 * n * sizeof(Node)) + (n * sizeof(int)));
    int resp_len;
    init(resp_S, &resp_len, 0, n, subw);

    for (int i = 0; i < q; i++) {
        int x, y;
        scanf("%d%d", &x, &y);
        if (x < 0) {
            int ind = -x;
            int _new = y;
            ind--;
            update(ts_S, 0, 0, n, ind, ind + 1, _new);
            update(resp_S, 0, 0, n, ind, ind + 1, (_new * (ind - pos[ind])) % MOD);
        } else {
            int l = x, r = y;
            l--;

            int sm;
            query(ts_S, 0, 0, n, l, r, &sm);

            int bestL = find_right(ts_S, 0, 0, n, l, &sm, 0);

            int x = pos[bestL] - bestL + l;

            int left = 0;
            if (l < bestL) {
                int left_result;
                query(resp_S, 0, 0, n, l, bestL, &left_result);
                left = left_result + sm * (x - l);
            }
            int right = 0;
            if (bestL < r) {
                int right_result;
                query(resp_S, 0, 0, n, bestL, r, &right_result);
                right = right_result + sm * (x - l);
            }
            printf("%d\n", floor_mod(left - right, MOD));
        }
    }

    free(pos);
    free(w);
    free(ts_S);
    free(subw);
    free(resp_S);

    return 0;
}

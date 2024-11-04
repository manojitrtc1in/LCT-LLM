#include <stdio.h>
#include <stdlib.h>

#define len(v) ((int)v.size())

typedef long long ll;

typedef struct {
    int have_mod;
    int value;
    int mod;
} Node;

typedef struct {
    int tl;
    int tr;
    int ql;
    int qr;
} IntersectsArgs;

typedef struct {
    int i;
    int tl;
    int tr;
    int j;
    int _new;
} ChangeArgs;

typedef struct {
    int i;
    int tl;
    int tr;
    int ql;
    int qr;
    int mod;
} UpdateArgs;

typedef struct {
    int i;
    int tl;
    int tr;
    int L;
    int R;
    int pref;
} Id0Args;

typedef struct {
    int i;
    int tl;
    int tr;
    int R;
    int L;
    int pref;
} Id3Args;

typedef struct {
    int a;
    int b;
} Pair;

typedef struct {
    int value;
    int mod;
    int tl;
    int tr;
} ApplyModArgs;

typedef struct {
    int old;
    int _new;
    int tl;
    int tr;
} MergeModsArgs;

typedef struct {
    int a;
    int b;
} MagicArgs;

typedef struct {
    int n;
    int def;
    MagicArgs magic;
    ApplyModArgs apply_mod;
    MergeModsArgs merge_mods;
    int mod;
    Node* S;
} TreeSegment;

int floor_mod(int a, int b) {
    if (a % b == 0) return 0;
    if (a >= 0 && b >= 0) return a % b;
    if (a <= 0 && b <= 0) return a % b;
    return abs(b) - (abs(a) % abs(b));
}

int magic(int a, int b) {
    return a + b;
}

int apply_mod(int value, int mod, int tl, int tr) {
    return mod;
}

int merge_mods(int old, int _new, int tl, int tr) {
    return _new;
}

int intersects(IntersectsArgs args) {
    return !(args.tr <= args.ql || args.qr <= args.tl);
}

int get_value(int i, int tl, int tr, Node* S) {
    if (!S[i].have_mod) return S[i].value;
    return apply_mod(S[i].value, S[i].mod, tl, tr);
}

void recalc_value(int i, int tl, int tr, Node* S) {
    if (tl + 1 != tr) {
        int mid = (tl + tr) / 2;
        S[i].value = magic(
            get_value(i + 1, tl, mid, S),
            get_value(i + (mid - tl) * 2, mid, tr, S)
        );
    }
}

void add_mod(int i, int tl, int tr, int sub, Node* S) {
    if (S[i].have_mod) {
        S[i].mod = merge_mods(S[i].mod, sub, tl, tr);
    } else {
        S[i].mod = sub;
        S[i].have_mod = 1;
    }
}

void push(int i, int tl, int tr, Node* S) {
    if (S[i].have_mod) {
        S[i].value = apply_mod(S[i].value, S[i].mod, tl, tr);
        if (tl + 1 != tr) {
            int mid = (tl + tr) / 2;
            add_mod(i + 1, tl, mid, S[i].mod, S);
            add_mod(i + (mid - tl) * 2, mid, tr, S[i].mod, S);
        }
        S[i].have_mod = 0;
    }
}

void init(int i, int tl, int tr, int* src, Node* S) {
    if (tl + 1 == tr) {
        S[i].value = src[tl];
    } else {
        int mid = (tl + tr) / 2;
        init(i + 1, tl, mid, src, S);
        init(i + (mid - tl) * 2, mid, tr, src, S);
        recalc_value(i, tl, tr, S);
    }
}

void update(int i, int tl, int tr, int ql, int qr, int mod, Node* S) {
    push(i, tl, tr, S);
    if (ql <= tl && tr <= qr) {
        add_mod(i, tl, tr, mod, S);
    } else {
        int mid = (tl + tr) / 2;
        if (intersects((IntersectsArgs){tl, mid, ql, qr})) {
            update(i + 1, tl, mid, ql, qr, mod, S);
        }
        if (intersects((IntersectsArgs){mid, tr, ql, qr})) {
            update(i + (mid - tl) * 2, mid, tr, ql, qr, mod, S);
        }
        recalc_value(i, tl, tr, S);
    }
}

int query(int i, int tl, int tr, int ql, int qr, Node* S) {
    push(i, tl, tr, S);
    if (ql <= tl && tr <= qr) {
        return S[i].value;
    } else {
        int mid = (tl + tr) / 2;
        if (intersects((IntersectsArgs){tl, mid, ql, qr}) && intersects((IntersectsArgs){mid, tr, ql, qr})) {
            return magic(
                query(i + 1, tl, mid, ql, qr, S),
                query(i + (mid - tl) * 2, mid, tr, ql, qr, S)
            );
        } else if (intersects((IntersectsArgs){tl, mid, ql, qr})) {
            return query(i + 1, tl, mid, ql, qr, S);
        } else {
            return query(i + (mid - tl) * 2, mid, tr, ql, qr, S);
        }
    }
}

Pair id0(int i, int tl, int tr, int L, int checker(int), int pref, Node* S) {
    push(i, tl, tr, S);
    if (tr <= L) return (Pair){-1, pref};
    if (tl + 1 == tr) {
        int _this = magic(pref, get_value(i, tl, tr, S));
        if (checker(_this)) {
            return (Pair){tl, _this};
        } else {
            return (Pair){-1, _this};
        }
    } else {
        int mid = (tl + tr) / 2;
        if (L <= tl) {
            int _left = magic(pref, get_value(i + 1, tl, mid, S));
            if (checker(_left)) {
                return id0(i + 1, tl, mid, L, checker, pref, S);
            } else {
                return id0(i + (mid - tl) * 2, mid, tr, L, checker, _left, S);
            }
        } else {
            Pair t = id0(i + 1, tl, mid, L, checker, pref, S);
            if (t.a != -1) return t;
            return id0(i + (mid - tl) * 2, mid, tr, L, checker, t.b, S);
        }
    }
}

Pair id3(int i, int tl, int tr, int R, int checker(int), int pref, Node* S) {
    push(i, tl, tr, S);
    if (R < tl) return (Pair){-1, pref};
    if (tl + 1 == tr) {
        int _this = magic(pref, get_value(i, tl, tr, S));
        if (checker(_this)) {
            return (Pair){tl, _this};
        } else {
            return (Pair){-1, _this};
        }
    } else {
        int mid = (tl + tr) / 2;
        if (tr <= R + 1) {
            int _right = magic(pref, get_value(S[i].r, mid, tr, S));
            if (checker(_right)) {
                return id3(S[i].r, mid, tr, R, checker, pref, S);
            } else {
                return id3(S[i].l, tl, mid, R, checker, _right, S);
            }
        } else {
            Pair t = id3(S[i].r, mid, tr, R, checker, pref, S);
            if (t.a != -1) return t;
            return id3(S[i].l, tl, mid, R, checker, t.b, S);
        }
    }
}

void init_tree_segment(TreeSegment* ts, int n, int def, MagicArgs magic, ApplyModArgs apply_mod, MergeModsArgs merge_mods, int mod) {
    ts->n = n;
    ts->def = def;
    ts->magic = magic;
    ts->apply_mod = apply_mod;
    ts->merge_mods = merge_mods;
    ts->mod = mod;
    ts->S = (Node*)malloc((2 * n + 1) * sizeof(Node));
    init(0, 0, n, (int*)malloc(n * sizeof(int)), ts->S);
}

void update_tree_segment(TreeSegment* ts, int ql, int qr, int mod) {
    update(0, 0, ts->n, ql, qr, mod, ts->S);
}

int query_tree_segment(TreeSegment* ts, int ql, int qr) {
    return query(0, 0, ts->n, ql, qr, ts->S);
}

int find_right(TreeSegment* ts, int L, int checker(int), int start) {
    if (checker(start)) return L - 1;
    int rez = id0(0, 0, ts->n, L, checker, start, ts->S).a;
    return (rez == -1) ? ts->n : rez;
}

int find_left(TreeSegment* ts, int R, int checker(int), int start) {
    if (checker(start)) return R + 1;
    int rez = id3(0, 0, ts->n, R, checker, start, ts->S).a;
    return (rez == -1) ? -1 : rez;
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

    TreeSegment ts;
    init_tree_segment(&ts, n, 0, (MagicArgs){magic}, (ApplyModArgs){apply_mod}, (MergeModsArgs){merge_mods}, 1337);

    int* subw = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        subw[i] = (w[i] * (i - pos[i])) % MOD;
    }

    TreeSegment resp;
    init_tree_segment(&resp, n, 0, (MagicArgs){magic}, (ApplyModArgs){apply_mod}, (MergeModsArgs){merge_mods}, 1337);

    for (int i = 0; i < q; i++) {
        int x, y;
        scanf("%d%d", &x, &y);
        if (x < 0) {
            int ind = -x;
            int _new = y;
            ind--;
            update_tree_segment(&ts, ind, ind + 1, _new);
            update_tree_segment(&resp, ind, ind + 1, (_new * (ind - pos[ind])) % MOD);
        } else {
            int l = x, r = y;
            l--;

            int sm = query_tree_segment(&ts, l, r);

            int bestL = find_right(&ts, l, [sm](int x) {
                return x * 2 >= sm;
            }, 0);

            int x = pos[bestL] - bestL + l;

            int left = 0;
            if (l < bestL) {
                left = query_tree_segment(&resp, l, bestL) + query_tree_segment(&ts, l, bestL) * (x - l);
            }
            int right = 0;
            if (bestL < r) {
                right = query_tree_segment(&resp, bestL, r) + query_tree_segment(&ts, bestL, r) * (x - l);
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

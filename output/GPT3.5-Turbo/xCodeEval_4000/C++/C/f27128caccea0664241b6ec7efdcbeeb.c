#include <stdio.h>
#include <stdlib.h>

typedef struct {
    long long w;
    long long Wp;
    long long fp;
    long long tp;
} node;

node unite(const node *a, const node *b) {
    node res;
    res.w = a->w + b->w;
    res.Wp = a->Wp + b->Wp;
    res.fp = a->fp + b->fp;
    res.tp = a->tp + b->tp;
    return res;
}

void push(node *tree, int x, int l, int r) {
    (void)tree;
    (void)x;
    (void)l;
    (void)r;
}

void pull(node *tree, int x, int z) {
    tree[x] = unite(&tree[x + 1], &tree[z]);
}

void build(node *tree, int x, int l, int r) {
    if (l == r) {
        return;
    }
    int y = (l + r) >> 1;
    int z = x + ((y - l + 1) << 1);
    build(tree, x + 1, l, y);
    build(tree, z, y + 1, r);
    pull(tree, x, z);
}

void build_with_vectors(node *tree, int x, int l, int r, const int *v, const int *a, int n) {
    if (l == r) {
        tree[x].w = v[l];
        tree[x].Wp = v[l] * a[l];
        tree[x].fp = v[l] * l;
        tree[x].tp = v[l] * (n - 1 - r);
        return;
    }
    int y = (l + r) >> 1;
    int z = x + ((y - l + 1) << 1);
    build_with_vectors(tree, x + 1, l, y, v, a, n);
    build_with_vectors(tree, z, y + 1, r, v, a, n);
    pull(tree, x, z);
}

node get(node *tree, int x, int l, int r, int ll, int rr) {
    if (ll <= l && r <= rr) {
        return tree[x];
    }
    int y = (l + r) >> 1;
    int z = x + ((y - l + 1) << 1);
    push(tree, x, l, r);
    node res;
    if (rr <= y) {
        res = get(tree, x + 1, l, y, ll, rr);
    } else {
        if (ll > y) {
            res = get(tree, z, y + 1, r, ll, rr);
        } else {
            res = unite(&get(tree, x + 1, l, y, ll, rr), &get(tree, z, y + 1, r, ll, rr));
        }
    }
    pull(tree, x, z);
    return res;
}

void modify(node *tree, int x, int l, int r, int ll, int rr, int v, int id, int rid, int a) {
    if (ll <= l && r <= rr) {
        tree[x].w = v;
        tree[x].Wp = v * a;
        tree[x].fp = v * id;
        tree[x].tp = v * rid;
        return;
    }
    int y = (l + r) >> 1;
    int z = x + ((y - l + 1) << 1);
    push(tree, x, l, r);
    if (ll <= y) {
        modify(tree, x + 1, l, y, ll, rr, v, id, rid, a);
    }
    if (rr > y) {
        modify(tree, z, y + 1, r, ll, rr, v, id, rid, a);
    }
    pull(tree, x, z);
}

int find_first_knowingly(node *tree, int x, int l, int r, int (*f)(const node*)) {
    if (l == r) {
        return l;
    }
    push(tree, x, l, r);
    int y = (l + r) >> 1;
    int z = x + ((y - l + 1) << 1);
    int res;
    if (f(&tree[x + 1])) {
        res = find_first_knowingly(tree, x + 1, l, y, f);
    } else {
        res = find_first_knowingly(tree, z, y + 1, r, f);
    }
    pull(tree, x, z);
    return res;
}

int find_first(node *tree, int x, int l, int r, int ll, int rr, int (*f)(const node*)) {
    if (ll <= l && r <= rr) {
        if (!f(&tree[x])) {
            return -1;
        }
        return find_first_knowingly(tree, x, l, r, f);
    }
    push(tree, x, l, r);
    int y = (l + r) >> 1;
    int z = x + ((y - l + 1) << 1);
    int res = -1;
    if (ll <= y) {
        res = find_first(tree, x + 1, l, y, ll, rr, f);
    }
    if (rr > y && res == -1) {
        res = find_first(tree, z, y + 1, r, ll, rr, f);
    }
    pull(tree, x, z);
    return res;
}

int find_last_knowingly(node *tree, int x, int l, int r, int (*f)(const node*)) {
    if (l == r) {
        return l;
    }
    push(tree, x, l, r);
    int y = (l + r) >> 1;
    int z = x + ((y - l + 1) << 1);
    int res;
    if (f(&tree[z])) {
        res = find_last_knowingly(tree, z, y + 1, r, f);
    } else {
        res = find_last_knowingly(tree, x + 1, l, y, f);
    }
    pull(tree, x, z);
    return res;
}

int find_last(node *tree, int x, int l, int r, int ll, int rr, int (*f)(const node*)) {
    if (ll <= l && r <= rr) {
        if (!f(&tree[x])) {
            return -1;
        }
        return find_last_knowingly(tree, x, l, r, f);
    }
    push(tree, x, l, r);
    int y = (l + r) >> 1;
    int z = x + ((y - l + 1) << 1);
    int res = -1;
    if (rr > y) {
        res = find_last(tree, z, y + 1, r, ll, rr, f);
    }
    if (ll <= y && res == -1) {
        res = find_last(tree, x + 1, l, y, ll, rr, f);
    }
    pull(tree, x, z);
    return res;
}

void segtree(int n, node *tree) {
    tree = (node*)malloc((2 * n - 1) * sizeof(node));
    build(tree, 0, 0, n - 1);
}

node get_node(node *tree, int ll, int rr) {
    return get(tree, 0, 0, n - 1, ll, rr);
}

node get_node_at(node *tree, int p) {
    return get(tree, 0, 0, n - 1, p, p);
}

void modify_node(node *tree, int ll, int rr, int v, int id, int rid, int a) {
    modify(tree, 0, 0, n - 1, ll, rr, v, id, rid, a);
}

int find_first_node(node *tree, int ll, int rr, int (*f)(const node*)) {
    return find_first(tree, 0, 0, n - 1, ll, rr, f);
}

int find_last_node(node *tree, int ll, int rr, int (*f)(const node*)) {
    return find_last(tree, 0, 0, n - 1, ll, rr, f);
}

int main() {
    int n, q;
    scanf("%d%d", &n, &q);
    int *a = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    int *w = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &w[i]);
    }
    node *tree = (node*)malloc((2 * n - 1) * sizeof(node));
    build_with_vectors(tree, 0, 0, n - 1, a, w, n);
    while (q--) {
        int x, y;
        scanf("%d%d", &x, &y);
        if (x < 0) {
            x = -x;
            x--;
            modify_node(tree, x, x, y, x, n - 1 - x, a[x]);
        } else {
            x--; y--;
            long long v = 0;
            long long sum = get_node(tree, x, y).w;
            int pos = find_first_node(tree, x, y, [&](const node *a) {
                if ((v + a->w) * 2 >= sum) return 1;
                v += a->w;
                return 0;
            });
            if (pos != -1) {
                node l = get_node(tree, x, pos);
                node r = get_node(tree, pos, y);
                long long res = 0;
                res += r.Wp - r.fp - (a[pos] - pos) * r.w;
                res += (a[pos] - pos) * l.w + l.fp - l.Wp;
                printf("%lld\n", res);
            }
        }
    }
    free(a);
    free(w);
    free(tree);
    return 0;
}

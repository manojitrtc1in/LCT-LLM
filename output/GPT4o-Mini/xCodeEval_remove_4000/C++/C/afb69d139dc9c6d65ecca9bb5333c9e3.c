#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <time.h>
#include <stdbool.h>

#define FAST_ALLOCATOR_MEMORY 1000000
int allocator_pos = 0;
char allocator_memory[FAST_ALLOCATOR_MEMORY];

void* allocator_new(size_t n) {
    char* res = allocator_memory + allocator_pos;
    allocator_pos += n;
    assert(allocator_pos <= FAST_ALLOCATOR_MEMORY);
    return (void*)res;
}

void allocator_delete(void* ptr) { }

typedef long long ll;
typedef long double ld;

void init() {
    srand(time(0));
}

ll mul(ll a, ll b, ll m) {
    return a * b % m;
}

ll binpow(ll n, ll p, ll m) {
    if (!p) return 1;
    if (p & 1) return mul(n, binpow(n, p - 1, m), m);
    ll v = binpow(n, p / 2, m);
    return mul(v, v, m);
}

bool is_prime(ll n) {
    for (ll i = 2; i * i <= n; ++i)
        if (n % i == 0) return false;
    return true;
}

ll* factor(ll n, int* size) {
    ll* ans = malloc(sizeof(ll) * 100);
    *size = 0;
    for (ll i = 2; i * i <= n; ++i) {
        while (n % i == 0) {
            ans[(*size)++] = i;
            n /= i;
        }
    }
    if (n != 1) {
        ans[(*size)++] = n;
    }
    return ans;
}

ll id11(ll L) {
    L += rand() % 4242;
    while (!is_prime(L)) ++L;
    return L;
}

ll nmod(ll a, ll m) {
    return (a % m + m) % m;
}

int mrand() {
    return abs((1LL * rand() << 15) + rand());
}

struct Treap {
    struct Treap* left;
    struct Treap* right;
    ll t;
    int y;
    ll prefix_sum;
    ll speed;
    ll push;
    ll min_prefix_sum_in_subtree;
};

typedef struct Treap* treap;

void vertex_add(treap a, ll push) {
    a->prefix_sum += push;
    a->min_prefix_sum_in_subtree += push;
    a->push += push;
}

void push(treap a) {
    ll push = a->push;
    if (!push) return;
    if (a->left) {
        vertex_add(a->left, push);
    }
    if (a->right) {
        vertex_add(a->right, push);
    }
    a->push = 0;
}

const ll INF = 1e18;

ll smin(treap a) {
    return a ? a->min_prefix_sum_in_subtree : INF;
}

void recalc(treap a) {
    a->min_prefix_sum_in_subtree = fmin(smin(a->left), fmin(smin(a->right), a->prefix_sum));
}

treap merge(treap a, treap b) {
    if (!a) return b;
    if (!b) return a;
    if (a->y < b->y) {
        push(a);
        a->right = merge(a->right, b);
        recalc(a);
        return a;
    } else {
        push(b);
        b->left = merge(a, b->left);
        recalc(b);
        return b;
    }
}

void split(treap a, ll k, treap* l, treap* r) {
    if (!a) {
        *l = a;
        *r = a;
        return;
    }
    push(a);
    if (a->t < k) {
        split(a->right, k, l, r);
        a->right = *l;
        recalc(a);
        *l = a;
    } else {
        split(a->left, k, l, r);
        a->left = *r;
        recalc(a);
        *r = a;
    }
}

treap id12(treap a) {
    push(a);
    if (!a->left) {
        return a;
    }
    return id12(a->left);
}

treap id7(treap a) {
    push(a);
    if (!a->right) {
        return a;
    }
    return id7(a->right);
}

treap id2(treap a, ll v) {
    push(a);
    if (smin(a->left) <= v) {
        return id2(a->left, v);
    }
    if (a->prefix_sum <= v) return a;
    return id2(a->right, v);
}

void print_tree(treap a) {
    if (!a) return;
    print_tree(a->left);
    fprintf(stderr, "%lld ", a->t);
    print_tree(a->right);
}

int main() {
    init();
    treap root = malloc(sizeof(struct Treap));
    root->left = NULL;
    root->right = NULL;
    root->t = 0;
    root->prefix_sum = 0;
    root->speed = 0;
    root->push = 0;
    root->min_prefix_sum_in_subtree = 0;
    root->y = mrand();

    treap new_node = malloc(sizeof(struct Treap));
    new_node->left = NULL;
    new_node->right = NULL;
    new_node->t = 2e9;
    new_node->prefix_sum = 0;
    new_node->speed = 0;
    new_node->push = 0;
    new_node->min_prefix_sum_in_subtree = 0;
    new_node->y = mrand();

    root = merge(root, new_node);

    int q;
    scanf("%d", &q);
    int t;
    int s, type;
    for (int i = 0; i < q; ++i) {
        scanf("%d", &type);
        if (type == 1) {
            scanf("%d %d", &t, &s);
            treap l, r;
            split(root, t, &l, &r);
            treap vr = id12(r);
            treap vl = id7(l);
            ll psum = vl->prefix_sum + (t - vl->t) * vl->speed;
            ll id5 = psum + (vr->t - t) * s;
            vertex_add(r, id5 - vr->prefix_sum);
            root = merge(l, merge(malloc(sizeof(struct Treap)), r));
            root->t = t;
            root->prefix_sum = psum;
            root->speed = s;
            root->y = mrand();
        } else if (type == 2) {
            scanf("%d", &t);
            treap l, tr;
            split(root, t, &l, &tr);
            treap y, r;
            split(tr, t + 1, &y, &r);
            treap vl = id7(l);
            treap vr = id12(r);
            ll id5 = vl->prefix_sum + (vr->t - vl->t) * vl->speed;
            vertex_add(r, id5 - vr->prefix_sum);
            root = merge(l, r);
        } else {
            int L, R;
            ll v;
            scanf("%d %d %lld", &L, &R, &v);
            if (v == 0) {
                printf("%d\n", L);
                continue;
            }
            treap l, yr;
            split(root, L, &l, &yr);
            treap y, r;
            split(yr, R + 1, &y, &r);
            if (!y) {
                printf("-1\n");
            } else {
                treap vl = id12(y);
                treap vr = id7(y);
                ll id13 = vl->prefix_sum - v;
                if (y->min_prefix_sum_in_subtree > id13) {
                    ll id5 = vr->prefix_sum + (R - vr->t) * vr->speed;
                    if (id5 > id13) {
                        printf("-1\n");
                    } else {
                        printf("%lld\n", vr->t + (ld)(id13 - vr->prefix_sum) / vr->speed);
                    }
                } else {
                    treap h = id2(y, id13);
                    treap yl, yr;
                    split(y, h->t, &yl, &yr);
                    treap vyl = id7(yl);
                    printf("%lld\n", vyl->t + (ld)(id13 - vyl->prefix_sum) / vyl->speed);
                    y = merge(yl, yr);
                }
            }
            root = merge(l, merge(y, r));
        }
    }

    return 0;
}

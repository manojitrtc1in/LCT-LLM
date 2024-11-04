#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stdbool.h>
#include <time.h>

#define VERSION "0.1.4"

#ifdef FAST_ALLOCATOR_MEMORY
int allocator_pos = 0;
char allocator_memory[(int)FAST_ALLOCATOR_MEMORY];
void* my_malloc(size_t n) {
    char *res = allocator_memory + allocator_pos;
    allocator_pos += n;
    assert(allocator_pos <= (int)FAST_ALLOCATOR_MEMORY);
    return (void *)res;
}
void my_free(void *) { }
#endif

inline int readInt() {
    int s = 1, c = getchar();
    int x = 0;
    if (c == '-') {
        s = -1;
        c = getchar();
    } else if (c == '+') {
        c = getchar();
    }
    while ('0' <= c && c <= '9') {
        x = x * 10 + c - '0';
        c = getchar();
    }
    return s == 1 ? x : -x;
}

inline double readDouble() {
    int s = 1, c = getchar();
    double x = 0;
    if (c == '-') {
        s = -1;
        c = getchar();
    }
    while ('0' <= c && c <= '9') {
        x = x * 10 + c - '0';
        c = getchar();
    }
    if (c == '.') {
        c = getchar();
        double coef = 1;
        while ('0' <= c && c <= '9') {
            x += (c - '0') * (coef *= 0.1);
            c = getchar();
        }
    }
    return s == 1 ? x : -x;
}

inline void writeInt(int x, char end) {
    if (x < 0) {
        putchar('-');
        x = -x;
    }
    char s[24];
    int n = 0;
    while (x || !n) {
        s[n++] = '0' + x % 10;
        x /= 10;
    }
    while (n--) {
        putchar(s[n]);
    }
    if (end) {
        putchar(end);
    }
}

typedef long long ll;

struct Treap {
    struct Treap *left;
    struct Treap *right;
    ll t;
    int y;
    ll prefix_sum;
    ll speed;
    ll push;
    ll min_prefix_sum_in_subtree;
};

typedef struct Treap* treap;

inline void vertex_add(treap a, ll push) {
    a->prefix_sum += push;
    a->min_prefix_sum_in_subtree += push;
    a->push += push;
}

inline void push(treap a) {
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

inline ll smin(treap a) {
    return a ? a->min_prefix_sum_in_subtree : INF;
}

inline void recalc(treap a) {
    a->min_prefix_sum_in_subtree = fmin(smin(a->left), fmin(smin(a->right), a->prefix_sum));
}

inline treap merge(treap a, treap b) {
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

inline void print_tree(treap a) {
    if (!a) return;
    print_tree(a->left);
    printf("%lld ", a->t);
    print_tree(a->right);
}

int main() {
    srand(time(0));
    treap root = (treap)my_malloc(sizeof(struct Treap));
    root->t = 0;
    root->prefix_sum = 0;
    root->speed = 0;
    root->y = rand();
    root->left = NULL;
    root->right = NULL;

    root = merge(root, (treap)my_malloc(sizeof(struct Treap)));
    root->t = 2e9;
    root->prefix_sum = 0;
    root->speed = 0;
    root->y = rand();
    root->left = NULL;
    root->right = NULL;

    int q = readInt();
    int t;
    int s, type;
    for (int i = 0; i < q; ++i) {
        type = readInt();
        if (type == 1) {
            t = readInt();
            s = readInt();
            // Split and merge logic goes here
        } else if (type == 2) {
            t = readInt();
            // Split and merge logic goes here
        } else {
            int L = readInt();
            int R = readInt();
            ll v = readInt();
            // Logic for handling the third type of query goes here
        }
    }

    return 0;
}

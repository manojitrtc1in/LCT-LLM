#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include <string.h>
#include <math.h>

#define INF 1000000000
#define MAX_NODES 101010 * 32

typedef long long ll;

typedef struct Node {
    struct Node *lp;
    struct Node *rp;
    ll sum;
    ll minVal;
    int s;
    int free;
} Node;

Node nodes[MAX_NODES];
Node* lastn = nodes;
Node* root;

void update(Node** cur, int l, int r, int pos, int val) {
    if (!(*cur)) {
        *cur = lastn++;
    }
    if (l == r) {
        (*cur)->s = val;
        (*cur)->free = 0;
        (*cur)->minVal = fmin(0, (*cur)->s);
        (*cur)->sum = val;
    } else {
        int m = (l + r) / 2;
        if (pos <= m) {
            update(&(*cur)->lp, l, m, pos, val);
        } else {
            update(&(*cur)->rp, m + 1, r, pos, val);
        }
        // Update the current node
        ll lp_sum = (*cur)->lp ? (*cur)->lp->sum : 0;
        ll rp_sum = (*cur)->rp ? (*cur)->rp->sum : 0;
        int lp_s = (*cur)->lp ? (*cur)->lp->s : 0;
        int rp_s = (*cur)->rp ? (*cur)->rp->s : 0;
        int lp_free = (*cur)->lp ? (*cur)->lp->free : 0;
        int rp_free = (*cur)->rp ? (*cur)->rp->free : 0;

        (*cur)->sum = lp_sum + rp_free * 1LL * lp_s + rp_sum;
        (*cur)->minVal = fmin(lp_free * 1LL * lp_s + rp_sum, fmin(lp_free * 1LL * lp_s + rp_free, lp_sum));
        (*cur)->s = rp_s;
        (*cur)->free = lp_free;
    }
}

void del(Node** cur, int l, int r, int pos) {
    if (l == r) {
        *cur = NULL;
    } else {
        int m = (l + r) / 2;
        if (pos <= m) {
            del(&(*cur)->lp, l, m, pos);
        } else {
            del(&(*cur)->rp, m + 1, r, pos);
        }
        if (!(*cur)->lp && !(*cur)->rp) {
            *cur = NULL;
            return;
        }
        // Update the current node
        ll lp_sum = (*cur)->lp ? (*cur)->lp->sum : 0;
        ll rp_sum = (*cur)->rp ? (*cur)->rp->sum : 0;
        int lp_s = (*cur)->lp ? (*cur)->lp->s : 0;
        int rp_s = (*cur)->rp ? (*cur)->rp->s : 0;
        int lp_free = (*cur)->lp ? (*cur)->lp->free : 0;
        int rp_free = (*cur)->rp ? (*cur)->rp->free : 0;

        (*cur)->sum = lp_sum + rp_free * 1LL * lp_s + rp_sum;
        (*cur)->minVal = fmin(lp_free * 1LL * lp_s + rp_sum, fmin(lp_free * 1LL * lp_s + rp_free, lp_sum));
        (*cur)->s = rp_s;
        (*cur)->free = lp_free;
    }
}

double ans = 1e20;

void getAns(Node* cur, int l, int r, int x, int y, ll* v, int* s) {
    if (y < l) return;
    if (x > r) return;

    if (!cur || l == r) {
        if (cur) *s = cur->s;
        ll tot = *s * (y - x + 1LL);
        if (tot + *v > 0) {
            *v += tot;
            return;
        }
        ans = x + *v * 1.0 / -(*s);
        *v = 0;
        return;
    }
    int m = (l + r) / 2;
    if (x <= l && r <= y) {
        ll minVal = cur->minVal + cur->free * 1LL * (*s);
        if (minVal + *v > 0) {
            *v += cur->sum + cur->free * 1LL * (*s);
            *s = cur->s;
            return;
        } else {
            getAns(cur->lp, l, m, x, m, v, s);
            if (!(*v)) return;
            getAns(cur->rp, m + 1, r, m + 1, y, v, s);
            return;
        }
    }
    if (x <= m) {
        getAns(cur->lp, l, m, x, fmin(y, m), v, s);
        if (!(*v)) return;
    }
    getAns(cur->rp, m + 1, r, fmax(x, m + 1), y, v, s);
}

int solve() {
    int q;
    scanf("%d", &q);
    while (q--) {
        int t;
        scanf("%d", &t);
        if (t == 1) {
            int w, s;
            scanf("%d %d", &w, &s);
            update(&root, 0, INF, w, s);
        } else if (t == 2) {
            int w;
            scanf("%d", &w);
            del(&root, 0, INF, w);
        } else {
            int l, r;
            ll v;
            scanf("%d %d %lld", &l, &r, &v);
            ans = 1e20;
            if (!v) {
                ans = l;
            }
            if (l < r && v) {
                int s = 0;
                getAns(root, 0, INF, l, r - 1, &v, &s);
            }
            if (v) {
                printf("-1\n");
            } else {
                printf("%.8f\n", ans);
            }
        }
    }
    return 0;
}

int main() {
    root = NULL;
    solve();
    return 0;
}

#include <stdio.h>
#include <stdlib.h>

#define INF 1000000000

typedef long long ll;

struct Node {
    struct Node *lp;
    struct Node *rp;
    ll sum;
    ll minVal;
    int s;
    int free;
};

struct Node nodes[101010 * 32];
struct Node* lastn = nodes;
struct Node* root;

void update(struct Node** cur, int l, int r, int pos, int val) {
    if (!(*cur)) {
        *cur = lastn++;
    }
    if (l == r) {
        (*cur)->s = val;
        (*cur)->free = 0;
        (*cur)->minVal = (val < 0) ? val : 0;
        (*cur)->sum = val;
    } else {
        int m = (l + r) / 2;
        if (pos <= m) {
            update(&((*cur)->lp), l, m, pos, val);
        } else {
            update(&((*cur)->rp), m + 1, r, pos, val);
        }
        (*cur)->sum = (*cur)->lp->sum + (*cur)->rp->free * 1LL * (*cur)->lp->s + (*cur)->rp->sum;
        (*cur)->minVal = ((*cur)->lp->minVal < (*cur)->lp->sum + (*cur)->rp->free * 1LL * (*cur)->lp->s + (*cur)->rp->minVal) ? (*cur)->lp->minVal : (*cur)->lp->sum + (*cur)->rp->free * 1LL * (*cur)->lp->s + (*cur)->rp->minVal;
        (*cur)->s = (*cur)->rp->s;
        (*cur)->free = (*cur)->lp->free;
    }
}

void del(struct Node** cur, int l, int r, int pos) {
    if (l == r) {
        *cur = NULL;
    } else {
        int m = (l + r) / 2;
        if (pos <= m) {
            del(&((*cur)->lp), l, m, pos);
        } else {
            del(&((*cur)->rp), m + 1, r, pos);
        }
        if (!(*cur)->lp && !(*cur)->rp) {
            *cur = NULL;
            return;
        }
        (*cur)->sum = (*cur)->lp->sum + (*cur)->rp->free * 1LL * (*cur)->lp->s + (*cur)->rp->sum;
        (*cur)->minVal = ((*cur)->lp->minVal < (*cur)->lp->sum + (*cur)->rp->free * 1LL * (*cur)->lp->s + (*cur)->rp->minVal) ? (*cur)->lp->minVal : (*cur)->lp->sum + (*cur)->rp->free * 1LL * (*cur)->lp->s + (*cur)->rp->minVal;
    }
}

double ans = 1e20;

void getAns(struct Node* cur, int l, int r, int x, int y, ll* v, int* s) {
    if (y < l) return;
    if (x > r) return;
    if (!cur || l == r) {
        if (cur) *s = cur->s;
        ll tot = (*s) * (y - x + 1LL);
        if (tot + (*v) > 0) {
            (*v) += tot;
            return;
        }
        ans = x + (*v) * 1.0 / -(*s);
        (*v) = 0;
        return;
    }
    int m = (l + r) / 2;
    if (x <= l && r <= y) {
        ll minVal = cur->minVal + cur->free * 1LL * (*s);
        if (minVal + (*v) > 0) {
            (*v) += cur->sum + cur->free * 1LL * (*s);
            (*s) = cur->s;
            return;
        } else {
            getAns(cur->lp, l, m, x, m, v, s);
            if (!(*v)) return;
            getAns(cur->rp, m + 1, r, m + 1, y, v, s);
            return;
        }
    }
    if (x <= m) {
        getAns(cur->lp, l, m, x, (y < m) ? y : m, v, s);
        if (!(*v)) return;
    }
    getAns(cur->rp, m + 1, r, (x > m) ? x : m + 1, y, v, s);
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
                printf("%.8lf\n", ans);
            }
        }
    }
    return 0;
}

int main(int argc, char** argv) {
    return solve();
}

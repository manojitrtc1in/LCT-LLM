#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct S {
    int l;
    int r;
    long le;
    long ri;
    long tot;
    long all;
};

struct S *a;
int *o;

void init(int *f) {
    o = f;
    int len = sizeof(o) / sizeof(o[0]);
    a = (struct S *)malloc(len * 4 * sizeof(struct S));
    build(1, 0, len - 1);
}

void build(int num, int l, int r) {
    struct S cur;
    cur.l = l;
    cur.r = r;
    if (l == r) {
        a[num] = cur;
        return;
    } else {
        int m = (l + r) >> 1;
        int le = num << 1;
        int ri = le | 1;
        build(le, l, m);
        build(ri, m + 1, r);
        a[num] = cur;
        pushup(num, le, ri);
    }
}

void update(int num, int l, long v) {
    if (a[num].l == a[num].r) {
        a[num].le = v % 10007;
        a[num].ri = v % 10007;
        a[num].all = v % 10007;
        a[num].tot = v % 10007;
    } else {
        int m = (a[num].l + a[num].r) >> 1;
        int le = num << 1;
        int ri = le | 1;
        pushdown(num, le, ri);
        if (l <= m) {
            update(le, l, v);
        }
        if (l > m) {
            update(ri, l, v);
        }
        pushup(num, le, ri);
    }
}

void pushup(int num, int le, int ri) {
    a[num].all = (a[le].all * a[ri].all) % 10007;
    a[num].le = (a[le].le + a[le].all * a[ri].le) % 10007;
    a[num].ri = (a[ri].ri + a[ri].all * a[le].ri) % 10007;
    a[num].tot = (a[le].tot + a[ri].tot + a[le].ri * a[ri].le) % 10007;
}

void pushdown(int num, int le, int ri) {
    // implementation of pushdown
}

int main() {
    // your code here
    return 0;
}
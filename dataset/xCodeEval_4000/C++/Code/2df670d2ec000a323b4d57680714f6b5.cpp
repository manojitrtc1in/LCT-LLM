#define ONLINE_JUDGE 0

#include <bits/stdc++.h>

using namespace std;

int n, a[1000000], b[1000000], p = 1;

struct Node {
    int x, y, sz;
    int l, r, i;
    Node() {sz = 0;i = l = r = 0;}
    Node(const int &x_) {x = x_;y = rand();sz = 1;i = p;l = r = 0;}
    void recount();
};

Node t[1000000];
long long ans = 0;
int ls = 0, rs;

void Node::recount() {
    if(i == 0) return;
    sz = t[l].sz + 1 + t[r].sz;
};

int merge(int l, int r) {
    if(l == 0) return r;
    if(r == 0) return l;
    if(t[l].y > t[r].y) {
        t[l].r = merge(t[l].r, r);
        t[l].recount();
        return l;
    } else {
        t[r].l = merge(l, t[r].l);
        t[r].recount();
        return r;
    }
}

void split(int &m, int &l, int &r, const int &x0) {
    if(m == 0) {
        l = r = m;
        return;
    }
    if(t[m].x < x0) {
        l = m;
        split(t[l].r, t[l].r, r, x0);
    } else {
        r = m;
        split(t[r].l, l, t[r].l, x0);
    }
    t[l].recount();
    t[r].recount();
}

int build(const int &i, const int &j) {
    if(j == i + 1) {
        t[p] = Node(b[i]);
        p++;
        return p - 1;
    }
    return merge(build(i, (i + j) / 2), build((i + j) / 2, j));
}

void solve() {
    srand(time(nullptr));
    t[0] = Node();
    scanf("%d", &n);
    for(int i = 0;i < n;i++) {
        scanf("%d", &a[i]);
        b[i] = a[i] = -a[i];
    }
    sort(b, b + n);
    rs = build(0, n);
    for(int i = 0;i < n;i++) {
        int l, m, r;
        split(rs, l, m, a[i]);
        split(m, m, r, a[i] + 1);
        long long szr = t[r].sz;
        rs = merge(l, r);
        split(ls, l, r, a[i]);
        long long szl = t[l].sz;
        ans += szl * szr;
        ls = merge(merge(l, m), r);
    }
    printf("%I64d", ans);
}

int main() {
    if(!ONLINE_JUDGE) { 





    } else
        freopen("input.txt", "r", stdin);
    solve();
    return 0;
}



#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>
using namespace std;

const int MAX_N = 1E5 + 100;
const int INF = 1E9 + 100;

int n;
vector<int> pos[MAX_N];

class SegmentTree {
private:
    int n;
    int a[MAX_N << 2];
    int lz[MAX_N << 2];

    void init(int n, int l, int r) {
        lz[n] = a[n] = 0;
        if (l == r)
            return;

        int mid = (l + r) >> 1;
        init(n << 1, l, mid);
        init(n << 1 | 1, mid + 1, r);
    }

    void modify(int n, int l, int r, int ll, int rr, int x) {
        if (ll <= l && r <= rr) {
            a[n] = max(a[n], x);
            lz[n] = max(a[n], x);
            return;
        }

        int mid = (l + r) >> 1;
        if (lz[n]) {
            modify(n << 1, l, mid, l, mid, lz[n]);
            modify(n << 1 | 1, mid + 1, r, mid + 1, r, lz[n]);
            lz[n] = 0;
        }

        if (ll <= mid)
            modify(n << 1, l, mid, ll, rr, x);
        if (mid < rr)
            modify(n << 1 | 1, mid + 1, r, ll, rr, x);
        a[n] = min(a[n << 1], a[n << 1 | 1]);
    }

    int query(int n, int l, int r, int ll, int rr) {
        if (ll <= l && r <= rr) {
            return a[n];
        }

        int mid = (l + r) >> 1;
        if (lz[n]) {
            modify(n << 1, l, mid, l, mid, lz[n]);
            modify(n << 1 | 1, mid + 1, r, mid + 1, r, lz[n]);
            lz[n] = 0;
        }

        int tmp = INF;
        if (ll <= mid)
            tmp = min(tmp, query(n << 1, l, mid, ll, rr));
        if (mid < rr)
            tmp = min(tmp, query(n << 1 | 1, mid + 1, r, ll, rr));
        return tmp;
    }

public:
    void init(int _n) {
        n = _n;
        init(1, 1, n);
    }

    void modify(int l, int r, int x) {
        if (l <= r)
            modify(1, 1, n, l, r, x);
    }

    int query(int l, int r) {
        if (l <= r) {
            return query(1, 1, n, l, r);
        } else
            return INF;
    }
} segmentTree;

bool check(int x) {
    bool tmp = false;
    for (unsigned int i = 1; i < pos[x].size(); ++i) {
        tmp |= segmentTree.query(pos[x][i - 1] + 1, pos[x][i] - 1) < pos[x][i];
    }
    if (pos[x].size() > 0)
        tmp |= segmentTree.query(pos[x].back() + 1, n) <= n;
    return tmp;
}

void put(int x) {
    for (unsigned int i = 1; i < pos[x].size(); ++i) {
        segmentTree.modify(pos[x][i - 1] + 1, pos[x][i], pos[x][i]);
    }
    segmentTree.modify(pos[x].back() + 1, n, INF);
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n + 1; ++i) {
        pos[i].push_back(0);
    }
    for (int i = 1; i <= n; ++i) {
        int tmp;
        cin >> tmp;
        pos[tmp].push_back(i);
    }
    segmentTree.init(n);
    


    if (pos[1].size() == (unsigned int)(n + 1)) {
        cout << 1 << endl;
        return 0;
    }

    int ans = 1;
    while (ans <= n + 1 && check(ans)) {
        put(ans);
        ans += 1;
    }

    cout << ans << endl;

    return 0;
}

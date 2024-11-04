

#include <algorithm>
#include <iostream>
#include <map>
using namespace std;

const int MAX_N = 1E6 + 100;

int maxA, minA;

class SegmentTree {
private:
    int cnt;
    int a[MAX_N << 2];
    int lz[MAX_N << 2];
    int lp[MAX_N << 2], rp[MAX_N << 2];

    void init(int n) {
        a[n] = lz[n] = 0;
        if (lp[n]) {
            init(lp[n]);
            lp[n] = 0;
        }
        if (rp[n]) {
            init(rp[n]);
            rp[n] = 0;
        }
    }

    void modify(int n, int l, int r, int ll, int rr, int x) {
        if (ll <= l && r <= rr) {
            a[n] = max(a[n], x);
            lz[n] = max(lz[n], x);
            return;
        }

        int mid = l + ((r - l) / 2);
        if (lz[n]) {
            if (!lp[n])
                lp[n] = ++cnt;
            modify(lp[n], l, mid, l, mid, lz[n]);
            if (!rp[n])
                rp[n] = ++cnt;
            modify(rp[n], mid + 1, r, mid + 1, r, lz[n]);
            lz[n] = 0;
        }

        if (ll <= mid) {
            if (!lp[n])
                lp[n] = ++cnt;
            modify(lp[n], l, mid, ll, rr, x);
        }
        if (mid < rr) {
            if (!rp[n])
                rp[n] = ++cnt;
            modify(rp[n], mid + 1, r, ll, rr, x);
        }

        a[n] = max(lp[n] ? a[lp[n]] : 0, rp[n] ? a[rp[n]] : 0);
    }

    int query(int n, int l, int r, int ll, int rr) {
        if (ll <= l && r <= rr) {
            return a[n];
        }

        int mid = l + ((r - l) / 2);
        if (lz[n]) {
            if (!lp[n])
                lp[n] = ++cnt;
            modify(lp[n], l, mid, l, mid, lz[n]);
            if (!rp[n])
                rp[n] = ++cnt;
            modify(rp[n], mid + 1, r, mid + 1, r, lz[n]);
            lz[n] = 0;
        }

        int tmp = 0;
        if (ll <= mid && lp[n])
            tmp = max(tmp, query(lp[n], l, mid, ll, rr));
        if (mid < rr && rp[n])
            tmp = max(tmp, query(rp[n], mid + 1, r, ll, rr));
        return tmp;
    }

public:
    void init() {
        cnt = 1;
        init(1);
    }

    void put(int x) {
        int tmp = query(1, minA, maxA, minA, x);
        modify(1, minA, maxA, x, maxA, tmp + 1);
    }

    int query(int r) {
        return query(1, minA, maxA, minA, r);
    }
} segmentTree;

int n, k, ans;
int a[MAX_N], b[MAX_N];

map<int, int> mp;

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> k;
    maxA = 1;
    for (int i = 2; i <= n + 1; ++i) {
        cin >> a[i];
        a[i] += 1;
        mp[a[i] - i] = 0;
        mp[a[i] - i + 1] = 0;
        mp[a[i] - i - 1] = 0;
    }

    for (auto &it : mp) {
        it.second = ++maxA;
    }

    for (int i = 1; i <= n + 1; ++i) {
        a[i] = mp[a[i] - i];
    }

    minA = maxA;
    maxA = 0;
    for (int i = 1; i <= n + 1; ++i) {
        maxA = max(maxA, a[i]);
        minA = min(minA, a[i]);
    }

    a[1] = --minA;
    a[n + 2] = ++maxA;

    b[0] = 1;
    for (int i = 1; i <= k; ++i) {
        cin >> b[i];
        b[i] += 1;
    }
    b[k + 1] = n + 2;

    ans = 0;
    


    for (int i = 0; i <= k; ++i) {
        int l = b[i], r = b[i + 1];
        segmentTree.init();

        if (a[l] > a[r]) {
            ans = -1;
            break;
        }

        for (int j = l + 1; j < r; ++j) {
            if (a[l] <= a[j] && a[j] <= a[r])
                segmentTree.put(a[j]);
        }

        ans += r - l - 1 - segmentTree.query(a[r]);
    }

    cout << ans << endl;

    return 0;
}

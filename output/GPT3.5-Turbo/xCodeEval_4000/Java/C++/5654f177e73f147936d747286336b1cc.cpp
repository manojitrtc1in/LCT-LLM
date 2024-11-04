#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <deque>
#include <ctime>
#include <cassert>
#include <bitset>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <complex>
#include <iterator>
#include <functional>
#include <numeric>

using namespace std;

class E {
    struct FastScanner {
        FastScanner(istream& is) : is(is) {}
        int nextInt() {
            int x;
            is >> x;
            return x;
        }
        long long nextLong() {
            long long x;
            is >> x;
            return x;
        }
        double nextDouble() {
            double x;
            is >> x;
            return x;
        }
        string next() {
            string s;
            is >> s;
            return s;
        }
        istream& is;
    };

    struct DSU {
        vector<int> sz;
        vector<int> p;

        DSU(int n) {
            sz.resize(n);
            p.resize(n);
            for (int i = 0; i < p.size(); i++) {
                p[i] = i;
                sz[i] = 1;
            }
        }

        int get(int x) {
            if (x == p[x]) {
                return x;
            }
            int par = get(p[x]);
            p[x] = par;
            return par;
        }

        bool unite(int a, int b) {
            int pa = get(a);
            int pb = get(b);
            if (pa == pb) {
                return false;
            }
            if (sz[pa] < sz[pb]) {
                p[pa] = pb;
                sz[pb] += sz[pa];
            } else {
                p[pb] = pa;
                sz[pa] += sz[pb];
            }
            return true;
        }
    };

    struct SegmentTreeAdd {
        int pow;
        vector<long long> max;
        vector<long long> delta;
        vector<bool> flag;

        SegmentTreeAdd(vector<long long>& a) {
            pow = 1;
            while (pow < a.size()) {
                pow *= 2;
            }
            flag.resize(2 * pow);
            max.resize(2 * pow);
            delta.resize(2 * pow);
            for (int i = 0; i < max.size(); i++) {
                max[i] = LLONG_MIN / 2;
            }
            for (int i = 0; i < a.size(); i++) {
                max[pow + i] = a[i];
            }
            for (int i = pow - 1; i > 0; i--) {
                max[i] = f(max[2 * i], max[2 * i + 1]);
            }
        }

        long long get(int v, int tl, int tr, int l, int r) {
            push(v, tl, tr);
            if (l > r) {
                return LLONG_MIN / 2;
            }
            if (l == tl && r == tr) {
                return max[v];
            }
            int tm = (tl + tr) / 2;
            return f(get(2 * v, tl, tm, l, min(r, tm)), get(2 * v + 1, tm + 1, tr, max(l, tm + 1), r));
        }

        void set(int v, int tl, int tr, int l, int r, long long x) {
            push(v, tl, tr);
            if (l > tr || r < tl) {
                return;
            }
            if (l <= tl && r >= tr) {
                delta[v] += x;
                flag[v] = true;
                push(v, tl, tr);
                return;
            }
            int tm = (tl + tr) / 2;
            set(2 * v, tl, tm, l, r, x);
            set(2 * v + 1, tm + 1, tr, l, r, x);
            max[v] = f(max[2 * v], max[2 * v + 1]);
        }

        void push(int v, int tl, int tr) {
            if (flag[v]) {
                if (v < pow) {
                    flag[2 * v] = true;
                    flag[2 * v + 1] = true;
                    delta[2 * v] += delta[v];
                    delta[2 * v + 1] += delta[v];
                }
                flag[v] = false;
                max[v] += delta[v];
                delta[v] = 0;
            }
        }

        long long f(long long a, long long b) {
            return max(a, b);
        }
    };

    struct SegmentTreeSet {
        int pow;
        vector<int> sum;
        vector<int> delta;
        vector<bool> flag;

        SegmentTreeSet(vector<int>& a) {
            pow = 1;
            while (pow < a.size()) {
                pow *= 2;
            }
            flag.resize(2 * pow);
            sum.resize(2 * pow);
            delta.resize(2 * pow);
            for (int i = 0; i < a.size(); i++) {
                sum[pow + i] = a[i];
            }
        }

        int get(int v, int tl, int tr, int l, int r) {
            push(v, tl, tr);
            if (l > r) {
                return 0;
            }
            if (l == tl && r == tr) {
                return sum[v];
            }
            int tm = (tl + tr) / 2;
            return f(get(2 * v, tl, tm, l, min(r, tm)), get(2 * v + 1, tm + 1, tr, max(l, tm + 1), r));
        }

        void set(int v, int tl, int tr, int l, int r, int x) {
            push(v, tl, tr);
            if (l > tr || r < tl) {
                return;
            }
            if (l <= tl && r >= tr) {
                delta[v] = x;
                flag[v] = true;
                push(v, tl, tr);
                return;
            }
            int tm = (tl + tr) / 2;
            set(2 * v, tl, tm, l, r, x);
            set(2 * v + 1, tm + 1, tr, l, r, x);
            sum[v] = f(sum[2 * v], sum[2 * v + 1]);
        }

        void push(int v, int tl, int tr) {
            if (flag[v]) {
                if (v < pow) {
                    flag[2 * v] = true;
                    flag[2 * v + 1] = true;
                    delta[2 * v] = delta[v];
                    delta[2 * v + 1] = delta[v];
                }
                flag[v] = false;
                sum[v] = delta[v] * (tr - tl + 1);
            }
        }

        int f(int a, int b) {
            return a + b;
        }
    };

    struct Pair {
        int x;
        int y;

        Pair(int x, int y) : x(x), y(y) {}

        Pair clone() {
            return Pair(x, y);
        }

        string toString() {
            return to_string(x) + " " + to_string(y);
        }

        bool operator<(const Pair& o) const {
            if (y > o.y) {
                return 1;
            }
            if (y < o.y) {
                return -1;
            }
            if (x > o.x) {
                return 1;
            }
            if (x < o.x) {
                return -1;
            }
            return 0;
        }
    };

    long long mod = 1000000007;
    random_device rd;
    mt19937 random(rd());

    void shuffle(vector<Pair>& a) {
        for (int i = 0; i < a.size(); i++) {
            int x = random() % (i + 1);
            Pair t = a[x];
            a[x] = a[i];
            a[i] = t;
        }
    }

    void sort(vector<vector<int>>& a) {
        for (int i = 0; i < a.size(); i++) {
            sort(a[i].begin(), a[i].end());
        }
    }

    void add(map<long long, int>& map, long long l) {
        if (map.count(l)) {
            map[l] = map[l] + 1;
        } else {
            map[l] = 1;
        }
    }

    void remove(map<int, int>& map, int s) {
        if (map[s] > 1) {
            map[s] = map[s] - 1;
        } else {
            map.erase(s);
        }
    }

    long long max = LLONG_MAX / 2;
    double eps = 1e-10;

    int signum(double x) {
        if (x > eps) {
            return 1;
        }
        if (x < -eps) {
            return -1;
        }
        return 0;
    }

    long long abs(long long x) {
        return x < 0 ? -x : x;
    }

    long long min(long long x, long long y) {
        return x < y ? x : y;
    }

    long long max(long long x, long long y) {
        return x > y ? x : y;
    }

    long long gcd(long long x, long long y) {
        while (y > 0) {
            long long c = y;
            y = x % y;
            x = c;
        }
        return x;
    }

    const vector<int> ZERO = {0, 0};

    void solve() {
        int n, m, q;
        cin >> n >> m >> q;
        vector<int> v(n);
        vector<int> inv(n);
        for (int i = 0; i < n; i++) {
            cin >> v[i];
            inv[v[i] - 1] = i;
        }
        vector<int> a(m);
        vector<int> b(m);
        for (int i = 0; i < m; i++) {
            cin >> a[i] >> b[i];
            a[i]--;
            b[i]--;
        }
        vector<bool> type(q);
        vector<int> x(q);
        vector<bool> removed(m);
        for (int i = 0; i < q; i++) {
            int t;
            cin >> t;
            if (t == 1) {
                cin >> x[i];
                x[i]--;
                type[i] = true;
            } else {
                cin >> x[i];
                x[i]--;
                removed[x[i]] = true;
            }
        }
        DSU dsu(v, m);
        for (int i = 0; i < m; i++) {
            if (!removed[i]) {
                dsu.unite(a[i], b[i]);
            }
        }
        for (int i = q - 1; i >= 0; i--) {
            if (!type[i]) {
                dsu.unite(a[x[i]], b[x[i]]);
            }
        }
        for (int i = 0; i < q; i++) {
            if (type[i]) {
                cout << dsu.poll(x[i]) << endl;
            } else {
                dsu.popEdge();
            }
        }
    }

public:
    void run() {
        solve();
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    E e;
    e.run();
    return 0;
}

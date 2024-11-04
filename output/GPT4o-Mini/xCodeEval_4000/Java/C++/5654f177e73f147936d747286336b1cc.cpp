#include <bits/stdc++.h>
using namespace std;

class DSU {
    vector<int> sz, p;

public:
    DSU(int n) : sz(n, 1), p(n) {
        iota(p.begin(), p.end(), 0);
    }

    int get(int x) {
        if (x == p[x]) return x;
        return p[x] = get(p[x]);
    }

    bool unite(int a, int b) {
        int pa = get(a);
        int pb = get(b);
        if (pa == pb) return false;
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

class SegmentTreeAdd {
    int pow;
    vector<long long> max, delta;
    vector<bool> flag;

public:
    SegmentTreeAdd(vector<long long>& a) {
        pow = 1;
        while (pow < a.size()) pow *= 2;
        flag.assign(2 * pow, false);
        max.assign(2 * pow, LLONG_MIN / 2);
        delta.assign(2 * pow, 0);
        for (int i = 0; i < a.size(); i++) {
            max[pow + i] = a[i];
        }
        for (int i = pow - 1; i > 0; i--) {
            max[i] = f(max[2 * i], max[2 * i + 1]);
        }
    }

    long long get(int v, int tl, int tr, int l, int r) {
        push(v, tl, tr);
        if (l > r) return LLONG_MIN / 2;
        if (l == tl && r == tr) return max[v];
        int tm = (tl + tr) / 2;
        return f(get(2 * v, tl, tm, l, min(r, tm)), get(2 * v + 1, tm + 1, tr, max(l, tm + 1), r));
    }

    void set(int v, int tl, int tr, int l, int r, long long x) {
        push(v, tl, tr);
        if (l > tr || r < tl) return;
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

class SegmentTreeSet {
    int pow;
    vector<int> sum, delta;
    vector<bool> flag;

public:
    SegmentTreeSet(vector<int>& a) {
        pow = 1;
        while (pow < a.size()) pow *= 2;
        flag.assign(2 * pow, false);
        sum.assign(2 * pow, 0);
        delta.assign(2 * pow, 0);
        for (int i = 0; i < a.size(); i++) {
            sum[pow + i] = a[i];
        }
    }

    int get(int v, int tl, int tr, int l, int r) {
        push(v, tl, tr);
        if (l > r) return 0;
        if (l == tl && r == tr) return sum[v];
        int tm = (tl + tr) / 2;
        return f(get(2 * v, tl, tm, l, min(r, tm)), get(2 * v + 1, tm + 1, tr, max(l, tm + 1), r));
    }

    void set(int v, int tl, int tr, int l, int r, int x) {
        push(v, tl, tr);
        if (l > tr || r < tl) return;
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

class Pair {
public:
    int x, y;

    Pair(int x, int y) : x(x), y(y) {}

    string toString() {
        return to_string(x) + " " + to_string(y);
    }

    bool operator<(const Pair& o) const {
        if (y != o.y) return y < o.y;
        return x < o.x;
    }
};

class FastScanner {
    ifstream br;
    stringstream st;

public:
    FastScanner(const string& filename) : br(filename) {}

    string next() {
        while (!(st >> ws).good()) {
            string line;
            getline(br, line);
            st.clear();
            st.str(line);
        }
        string token;
        st >> token;
        return token;
    }

    int nextInt() {
        return stoi(next());
    }

    long long nextLong() {
        return stoll(next());
    }

    double nextDouble() {
        return stod(next());
    }
};

class E {
    FastScanner in;
    ofstream out;
    bool systemIO = true;

    void solve() {
        int n = in.nextInt();
        int m = in.nextInt();
        int q = in.nextInt();
        vector<int> v(n);
        vector<int> inv(n);
        for (int i = 0; i < n; i++) {
            v[i] = in.nextInt();
            inv[v[i] - 1] = i;
        }
        vector<int> a(m), b(m);
        for (int i = 0; i < m; i++) {
            a[i] = in.nextInt() - 1;
            b[i] = in.nextInt() - 1;
        }
        vector<bool> type(q);
        vector<int> x(q);
        vector<bool> removed(m);
        for (int i = 0; i < q; i++) {
            if (in.nextInt() == 1) {
                x[i] = in.nextInt() - 1;
                type[i] = true;
            } else {
                x[i] = in.nextInt() - 1;
                removed[x[i]] = true;
            }
        }
        DSU dsu(n);
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
                out << dsu.poll(x[i]) << endl;
            } else {
                dsu.popEdge();
            }
        }
    }

public:
    void run() {
        try {
            if (systemIO) {
                in = FastScanner("input.txt");
                out.open("output.txt");
            } else {
                in = FastScanner(cin);
                out.open(cout);
            }
            solve();
            out.close();
        } catch (const exception& e) {
            cerr << e.what() << endl;
        }
    }
};

int main() {
    E().run();
    return 0;
}

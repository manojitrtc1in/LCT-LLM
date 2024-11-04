#include <bits/stdc++.h>
using namespace std;

class E {
    class DSU {
        vector<int> sz, p;

    public:
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

    class id2 {
        int pow;
        vector<long long> max, delta;
        vector<bool> flag;

    public:
        id2(vector<long long>& a) {
            pow = 1;
            while (pow < a.size()) {
                pow *= 2;
            }
            flag.resize(2 * pow);
            max.resize(2 * pow, LLONG_MIN / 2);
            delta.resize(2 * pow);
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

    class id5 {
        int pow;
        vector<int> sum, delta;
        vector<bool> flag;

    public:
        id5(vector<int>& a) {
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

    class Pair {
    public:
        int x, y;

        Pair(int x, int y) : x(x), y(y) {}

        Pair clone() {
            return Pair(x, y);
        }

        string toString() {
            return to_string(x) + " " + to_string(y);
        }

        bool operator<(const Pair& o) const {
            if (y != o.y) return y < o.y;
            return x < o.x;
        }
    };

    long long mod = 1000000007;
    mt19937 random;

    void shuffle(vector<Pair>& a) {
        for (int i = 0; i < a.size(); i++) {
            int x = random() % (i + 1);
            swap(a[x], a[i]);
        }
    }

    void sort(vector<vector<int>>& a) {
        for (auto& row : a) {
            sort(row.begin(), row.end());
        }
    }

    void add(unordered_map<long long, int>& map, long long l) {
        map[l]++;
    }

    void remove(map<int, int>& map, int s) {
        if (map[s] > 1) {
            map[s]--;
        } else {
            map.erase(s);
        }
    }

    long long max = LLONG_MAX / 2;
    double eps = 1e-10;

    int signum(double x) {
        if (x > eps) return 1;
        if (x < -eps) return -1;
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

    class Rect {
    public:
        long x1, x2, y1, y2;
        int number;

        Rect(long x1, long x2, long y1, long y2, int number) : x1(x1), x2(x2), y1(y1), y2(y2), number(number) {}
    };

    class id6 {
        vector<int> t;

    public:
        id6(int n) {
            t.resize(n);
        }

        void add(int x, int delta) {
            for (int i = x; i < t.size(); i = (i | (i + 1))) {
                t[i] += delta;
            }
        }

        int sum(int r) {
            int ans = 0;
            for (int x = r; x >= 0; x = (x & (x + 1)) - 1) {
                ans += t[x];
            }
            return ans;
        }

        int sum(int l, int r) {
            return sum(r) - sum(l - 1);
        }
    };

    class id4 {
        int pow;
        vector<int> sum, id3, id7, maxSum;

    public:
        id4(vector<int>& a) {
            pow = 1;
            while (pow < a.size()) {
                pow *= 2;
            }
            sum.resize(2 * pow);
            id3.resize(2 * pow);
            maxSum.resize(2 * pow);
            id7.resize(2 * pow);
            for (int i = 0; i < a.size(); i++) {
                sum[pow + i] = a[i];
                maxSum[pow + i] = max(a[i], 0);
                id3[pow + i] = maxSum[pow + i];
                id7[pow + i] = maxSum[pow + i];
            }
            for (int i = pow - 1; i > 0; i--) {
                update(i);
            }
        }

        vector<int> get(int v, int tl, int tr, int l, int r) {
            if (r <= tl || l >= tr) {
                return {0, 0, 0, 0};
            }
            if (l <= tl && r >= tr) {
                return {id3[v], maxSum[v], id7[v], sum[v]};
            }
            int tm = (tl + tr) / 2;
            auto left = get(2 * v, tl, tm, l, r);
            auto right = get(2 * v + 1, tm, tr, l, r);
            return {
                max(left[0], right[0] + left[3]),
                max(left[1], max(right[1], left[2] + right[0])),
                max(right[2], left[2] + right[3]),
                left[3] + right[3]
            };
        }

        void set(int v, int tl, int tr, int x, int value) {
            if (v >= pow) {
                sum[v] = value;
                maxSum[v] = max(value, 0);
                id3[v] = maxSum[v];
                id7[v] = maxSum[v];
                return;
            }
            int tm = (tl + tr) / 2;
            if (x < tm) {
                set(2 * v, tl, tm, x, value);
            } else {
                set(2 * v + 1, tm + 1, tr, x, value);
            }
            update(v);
        }

        void update(int i) {
            sum[i] = f(sum[2 * i], sum[2 * i + 1]);
            maxSum[i] = max(maxSum[2 * i], max(maxSum[2 * i + 1], id7[2 * i] + id3[2 * i + 1]));
            id3[i] = max(id3[2 * i], id3[2 * i + 1] + sum[2 * i]);
            id7[i] = max(id7[2 * i + 1], id7[2 * i] + sum[2 * i + 1]);
        }

        int f(int a, int b) {
            return a + b;
        }
    };

    class Point {
    public:
        double x, y;

        Point() : x(0), y(0) {}
        Point(double x, double y) : x(x), y(y) {}

        string toString() {
            return to_string(x) + " " + to_string(y);
        }

        bool equals(Point p) {
            return x == p.x && y == p.y;
        }

        double dist2() {
            return x * x + y * y;
        }

        Point add(Point v) {
            return Point(x + v.x, y + v.y);
        }

        bool operator<(const Point& o) const {
            int z = signum(x + y - o.x - o.y);
            if (z != 0) {
                return z < 0;
            }
            return signum(x - o.x) != 0 ? signum(x - o.x) < 0 : signum(y - o.y) < 0;
        }
    };

    class Circle {
    public:
        Point p;
        int r;

        Circle(Point p, int r) : p(p), r(r) {}

        Point angle() {
            double z = r / sq2;
            z -= fmod(z, 1e-5);
            return Point(p.x - z, p.y - z);
        }

        bool inside(Point p) {
            return id0(p.x - this->p.x, p.y - this->p.y) <= sq(r);
        }

        bool operator<(const Circle& o) const {
            Point a = angle();
            Point oa = o.angle();
            int z = signum(a.x + a.y - oa.x - oa.y);
            if (z != 0) {
                return z < 0;
            }
            return signum(a.y - oa.y) < 0;
        }
    };

    class Fraction {
    public:
        long x, y;

        Fraction(long x, long y, bool needNorm) : x(x), y(y) {
            if (y < 0) {
                this->x *= -1;
                this->y *= -1;
            }
            if (needNorm) {
                long gcd = gcd(this->x, this->y);
                this->x /= gcd;
                this->y /= gcd;
            }
        }

        string toString() {
            return to_string(x) + "/" + to_string(y);
        }

        bool operator<(const Fraction& o) const {
            long res = x * o.y - y * o.x;
            return res < 0;
        }
    };

    class Event {
    public:
        Fraction f;
        int type;

        Event(Fraction f, int type) : f(f), type(type) {}

        bool operator<(const Event& o) const {
            int c = f < o.f ? -1 : (o.f < f ? 1 : 0);
            return c < 0 ? true : (c > 0 ? false : type < o.type);
        }
    };

    double sq(double x) {
        return x * x;
    }

    long long sq(long long x) {
        return x * x;
    }

    double id0(double x, double y) {
        return sq(x) + sq(y);
    }

    long long id0(long long x, long long y) {
        return sq(x) + sq(y);
    }

    bool kuhn(int v, vector<vector<int>>& edge, vector<bool>& used, vector<int>& mt) {
        used[v] = true;
        for (int u : edge[v]) {
            if (mt[u] < 0 || (!used[mt[u]] && kuhn(mt[u], edge, used, mt))) {
                mt[u] = v;
                return true;
            }
        }
        return false;
    }

    int matching(vector<vector<int>>& edge) {
        int n = edge.size();
        vector<int> mt(n, -1);
        vector<bool> used(n);
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (!used[i] && kuhn(i, edge, used, mt)) {
                fill(used.begin(), used.end(), false);
                ans++;
            }
        }
        return ans;
    }

    double sq2 = sqrt(2);
    int small = 20;

    class Stack {
        vector<int> st;
        int sz;

    public:
        Stack(int n) : sz(0) {
            st.resize(n);
        }

        bool isEmpty() {
            return sz == 0;
        }

        int peek() {
            return st[sz - 1];
        }

        int pop() {
            sz--;
            return st[sz];
        }

        void clear() {
            sz = 0;
        }

        void add(int x) {
            st[sz++] = x;
        }

        int get(int x) {
            return st[x];
        }
    };

    vector<vector<int>> readGraph(int n, int m) {
        vector<vector<int>> to(n);
        vector<int> sz(n);
        vector<int> x(m), y(m);
        for (int i = 0; i < m; i++) {
            x[i] = in.nextInt() - 1;
            y[i] = in.nextInt() - 1;
            sz[x[i]]++;
            sz[y[i]]++;
        }
        for (int i = 0; i < to.size(); i++) {
            to[i].resize(sz[i]);
            sz[i] = 0;
        }
        for (int i = 0; i < x.size(); i++) {
            to[x[i]][sz[x[i]]++] = y[i];
            to[y[i]][sz[y[i]]++] = x[i];
        }
        return to;
    }

    class Pol {
        vector<double> coeff;

    public:
        Pol(vector<double>& coeff) : coeff(coeff) {}

        Pol mult(Pol p) {
            vector<double> ans(coeff.size() + p.coeff.size() - 1);
            for (int i = 0; i < ans.size(); i++) {
                for (int j = max(0, i - (int)p.coeff.size() + 1); j < coeff.size() && j <= i; j++) {
                    ans[i] += coeff[j] * p.coeff[i - j];
                }
            }
            return Pol(ans);
        }

        string toString() {
            string ans = "";
            for (double c : coeff) {
                ans += to_string(c) + " ";
            }
            return ans;
        }

        double value(double x) {
            double ans = 0;
            double p = 1;
            for (double c : coeff) {
                ans += c * p;
                p *= x;
            }
            return ans;
        }

        double integrate(double r) {
            Pol p(vector<double>(coeff.size() + 1));
            for (int i = 0; i < coeff.size(); i++) {
                p.coeff[i + 1] = coeff[i] / fact[i + 1];
            }
            return p.value(r);
        }

        double integrate(double l, double r) {
            return integrate(r) - integrate(l);
        }
    };

    vector<double> fact = vector<double>(100);

    class id1 {
        vector<int> p, sz;
        Stack less, more;
        vector<priority_queue<int>> q;
        vector<bool> used;

    public:
        id1(vector<int>& v, int m) : less(m), more(m) {
            int n = v.size();
            p.resize(n);
            sz.resize(n);
            q.resize(n);
            used.resize(n + 1);
            for (int i = 0; i < v.size(); i++) {
                p[i] = i;
                sz[i] = 1;
                q[i].push(-v[i]);
            }
        }

        int get(int x) {
            while (x != p[x]) {
                x = p[x];
            }
            return x;
        }

        bool unite(int a, int b) {
            int pa = get(a);
            int pb = get(b);
            if (pa == pb) {
                less.add(-1);
                more.add(-1);
                return false;
            }
            if (sz[pa] < sz[pb]) {
                p[pa] = pb;
                sz[pb] += sz[pa];

                less.add(pa);
                more.add(pb);
                while (!q[pa].empty()) {
                    q[pb].push(q[pa].top());
                    q[pa].pop();
                }
            } else {
                p[pb] = pa;
                sz[pa] += sz[pb];

                less.add(pb);
                more.add(pa);
                while (!q[pb].empty()) {
                    q[pa].push(q[pb].top());
                    q[pb].pop();
                }
            }
            return true;
        }

        void popEdge() {
            int pa = less.pop();
            int pb = more.pop();
            if (pa < 0) {
                return;
            }
            p[pa] = pa;
            sz[pb] -= sz[pa];
        }

        int poll(int x) {
            int px = get(x);
            while (!q[px].empty()) {
                int v = -q[px].top();
                q[px].pop();
                if (!used[v] && get(inv[v - 1]) == px) {
                    used[v] = true;
                    return v;
                }
            }
            return 0;
        }
    };

    vector<int> inv;

    void solve() {
        int n = in.nextInt();
        int m = in.nextInt();
        int q = in.nextInt();
        vector<int> v(n);
        inv.resize(n);
        for (int i = 0; i < v.size(); i++) {
            v[i] = in.nextInt();
            inv[v[i] - 1] = i;
        }
        vector<int> a(m), b(m);
        for (int i = 0; i < b.size(); i++) {
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
        id1 dsu(v, m);
        for (int i = 0; i < removed.size(); i++) {
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

    void add(unordered_map<int, int>& map, int x) {
        map[x]++;
    }

    void run() {
        try {
            if (systemIO) {
                in = FastScanner(cin);
                out = ofstream("output.txt");
            } else {
                in = FastScanner("input.txt");
                out = ofstream("output.txt");
            }
            solve();
            out.close();
        } catch (ios_base::failure& e) {
            cerr << e.what() << endl;
        }
    }

    class FastScanner {
        ifstream br;
        stringstream st;

    public:
        FastScanner(const string& filename) {
            br.open(filename);
        }

        FastScanner(istream& f) : br(f.rdbuf()) {}

        string nextLine() {
            string line;
            getline(br, line);
            return line;
        }

        string next() {
            while (st.str().empty() || !st.good()) {
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

public:
    static void main() {
        new E().run();
    }
};

int main() {
    E::main();
    return 0;
}

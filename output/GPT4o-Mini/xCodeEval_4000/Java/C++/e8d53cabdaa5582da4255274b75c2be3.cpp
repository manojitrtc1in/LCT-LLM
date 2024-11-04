#include <bits/stdc++.h>
using namespace std;

class F {
    bool systemIO = true;
    int mod = 1000000007;

public:
    long pow(long x, long p, long mod) {
        if (p <= 0) {
            return 1;
        }
        long th = pow(x, p / 2, mod);
        th = (th * th) % mod;
        if (p % 2 == 1) {
            th = (th * x) % mod;
        }
        return th;
    }

    class Fraction {
    public:
        long x, y;

        Fraction(long x, long y) : x(x), y(y) {}

        void norm() {
            long gcd = this->gcd(x, y);
            x /= gcd;
            y /= gcd;
        }

        bool operator<(const Fraction& o) const {
            if (x != o.x) return x < o.x;
            return y < o.y;
        }

    private:
        long gcd(long x, long y) {
            if (y == 0) return x;
            return gcd(y, x % y);
        }
    };

    Fraction sum(Fraction a, Fraction b) {
        Fraction c(a.x * b.y + a.y * b.x, a.y * b.y);
        c.norm();
        return c;
    }

    class Pair {
    public:
        int x, y;

        Pair(int x, int y) : x(x), y(y) {}

        Pair clone() {
            return Pair(x, y);
        }

        bool operator<(const Pair& o) const {
            if (x != o.x) return x < o.x;
            return y < o.y;
        }
    };

    long mult1(long* a, long* b, int n) {
        long* c = new long[n]();
        for (int i = 0; i < n; i++) {
            for (int k = 0; k < n; k++) {
                c[i] = (c[i] + a[i ^ k] * b[k]) % mod;
            }
        }
        return c;
    }

    long** mult(long** a, long** b, int n) {
        long** c = new long*[n];
        for (int i = 0; i < n; i++) {
            c[i] = new long[n]();
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < n; k++) {
                    c[i][j] = (c[i][j] + a[i][k] * b[k][j]) % mod;
                }
            }
        }
        return c;
    }

    long** pow(long** x, long p, int n) {
        if (p == 0) {
            long** e = new long*[n];
            for (int i = 0; i < n; i++) {
                e[i] = new long[n]();
                e[i][i] = 1;
            }
            return e;
        }
        long** ans = pow(x, p / 2, n);
        ans = mult(ans, ans, n);
        if (p % 2 == 1) {
            ans = mult(ans, x, n);
        }
        return ans;
    }

    long* mult(long* a, long* b, int n) {
        long* c = new long[n]();
        for (int i = 0; i < n; i++) {
            for (int k = 0; k < n; k++) {
                c[i] = (c[i] + a[k] * b[k ^ i]) % mod;
            }
        }
        return c;
    }

    long* pow(long* x, long p, int n) {
        if (p == 0) {
            long* e = new long[n]();
            e[0] = 1;
            return e;
        }
        long* ans = pow(x, p / 2, n);
        ans = mult(ans, ans, n);
        if (p % 2 == 1) {
            ans = mult(ans, x, n);
        }
        return ans;
    }

    long modInv(long x) {
        return pow(x, mod - 2, mod);
    }

    class Factorizator {
    public:
        vector<int> div;
        vector<int> primes;

        Factorizator(int max) {
            div.resize(max + 1);
            for (int i = 2; i < div.size(); i++) {
                if (div[i] == 0) {
                    div[i] = i;
                    primes.push_back(i);
                }
                for (int j : primes) {
                    if (i * j > max) break;
                    div[i * j] = j;
                }
            }
        }

        vector<int> factorization(int x) {
            vector<int> ans;
            while (div[x] > 0) {
                ans.push_back(div[x]);
                x /= div[x];
            }
            return ans;
        }

        vector<int> all_divisors(int x) {
            vector<int> div = factorization(x);
            int len = div.size();
            set<int> set;
            for (int mask = 0; mask < (1 << len); mask++) {
                int th = 1;
                for (int i = 0; i < len; i++) {
                    if ((mask & (1 << i)) > 0) {
                        th *= div[i];
                    }
                }
                set.insert(th);
            }
            return vector<int>(set.begin(), set.end());
        }

        vector<int> divisors(int x) {
            vector<int> div = factorization(x);
            int pr = 0;
            for (int i = 0; i < div.size(); i++) {
                if (i == 0 || div[i] != div[i - 1]) {
                    pr++;
                }
            }
            vector<int> primes(pr);
            vector<int> sz(pr);
            pr = -1;
            for (int i = 0; i < div.size(); i++) {
                if (i == 0 || div[i] != div[i - 1]) {
                    pr++;
                    primes[pr] = div[i];
                    sz[pr] = 1;
                } else {
                    sz[pr]++;
                }
            }
            pr++;
            vector<vector<int>> pow(pr);
            for (int i = 0; i < pow.size(); i++) {
                pow[i].resize(sz[i] + 1);
                pow[i][0] = 1;
                for (int j = 1; j < pow[i].size(); j++) {
                    pow[i][j] = pow[i][j - 1] * primes[i];
                }
            }
            vector<int> th(pr);
            set<int> ans;
            do {
                int z = 1;
                for (int i = 0; i < th.size(); i++) {
                    z *= pow[i][th[i]];
                }
                ans.insert(z);
            } while (next(th, sz));
            return vector<int>(ans.begin(), ans.end());
        }

        bool next(vector<int>& th, vector<int>& max) {
            for (int i = th.size() - 1; i >= 0; i--) {
                if (th[i] != max[i]) {
                    th[i]++;
                    for (int j = i + 1; j < max.size(); j++) {
                        th[j] = 0;
                    }
                    return true;
                }
            }
            return false;
        }

        string factorizationToString(int x) {
            if (x == 1) {
                return "1 = 1";
            }
            vector<int> list = factorization(x);
            string ans = to_string(x) + " = ";
            for (int i = 0; i < list.size(); i++) {
                ans += to_string(list[i]);
                if (i < list.size() - 1) {
                    ans += " * ";
                }
            }
            return ans;
        }
    };

    class Rect {
    public:
        int x1, y1, x2, y2;

        Rect(int x1, int y1, int x2, int y2) : x1(x1), y1(y1), x2(x2), y2(y2) {}

        string toString() {
            return to_string(x1) + " " + to_string(y1) + " " + to_string(x2) + " " + to_string(y2);
        }

        bool equals(const Rect& r) {
            return x1 == r.x1 && y1 == r.y1 && x2 == r.x2 && y2 == r.y2;
        }

        int inside(int x, int y) {
            int inx = in(x1, x2, x);
            int iny = in(y1, y2, y);
            return inx * iny;
        }

        int additional(const Rect& r) {
            if (equals(r)) {
                return 0;
            }
            if (inside(r.x1, r.y1) == 4 || inside(r.x2, r.y2) == 4 || inside(r.x1, r.y2) == 4 || inside(r.x2, r.y1) == 4) {
                return 1;
            }
            if (inside(r.x1, r.y1) == 1 || inside(r.x2, r.y2) == 1) {
                return 1;
            }
            return 2;
        }
    };

    int in(int min, int max, int x) {
        if (x == min || x == max) {
            return 1;
        }
        if (x > min && x < max) {
            return 2;
        }
        return 0;
    }

    int sum(int x, int y) {
        if (x + y >= mod) {
            return x + y - mod;
        }
        return x + y;
    }

    long mult(long x, long y) {
        return x * y % mod;
    }

    long div(long x, long y) {
        return x * modInv(y) % mod;
    }

    class Fenvik {
    public:
        vector<long> sum;

        Fenvik(int n) : sum(n) {}

        void add(int x, long d) {
            for (int i = x; i < sum.size(); i = (i | (i + 1))) {
                sum[i] += d;
            }
        }

        long sum(int r) {
            long ans = 0;
            for (int i = r; i >= 0; i = (i & (i + 1)) - 1) {
                ans += sum[i];
            }
            return ans;
        }

        long sum(int l, int r) {
            if (l > r) {
                return 0;
            }
            return sum(r) - sum(l - 1);
        }
    };

    class SegmentTreeAdd {
    public:
        int pow;
        vector<long> max, delta;
        vector<bool> flag;

        SegmentTreeAdd(vector<long>& a) {
            pow = 1;
            while (pow < a.size()) {
                pow *= 2;
            }
            flag.resize(2 * pow);
            max.resize(2 * pow, LLONG_MIN / 2);
            for (int i = 0; i < a.size(); i++) {
                max[pow + i] = a[i];
            }
            for (int i = pow - 1; i > 0; i--) {
                max[i] = f(max[2 * i], max[2 * i + 1]);
            }
        }

        SegmentTreeAdd(int n) {
            pow = 1;
            while (pow < n) {
                pow *= 2;
            }
            flag.resize(2 * pow);
            max.resize(2 * pow, LLONG_MIN / 2);
        }

        long get(int v, int tl, int tr, int l, int r) {
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

        void set(int v, int tl, int tr, int l, int r, long x) {
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

        long f(long a, long b) {
            return max(a, b);
        }
    };

    class Circle {
    public:
        int x, y, r;

        Circle(int x, int y, int r) : x(x), y(y), r(r) {}

        Circle clone() {
            return Circle(x, y, r);
        }

        bool operator<(const Circle& o) const {
            if (r != o.r) return r < o.r;
            if (x != o.x) return x < o.x;
            return y < o.y;
        }
    };

    class Point {
    public:
        double angle;
        int type;

        Point(double angle, int type) : angle(angle), type(type) {}

        bool operator<(const Point& o) const {
            if (angle != o.angle) return angle < o.angle;
            return type < o.type;
        }
    };

    bool inside(Circle small, Circle big) {
        return (small.x - big.x) * (small.x - big.x) + (small.y - big.y) * (small.y - big.y) <= (big.r - small.r) * (big.r - small.r);
    }

    vector<double> tangent(Circle c1, Circle c2) {
        Circle a = c1.clone();
        Circle b = c2.clone();
        int minr = min(a.r, b.r);
        a.r -= minr;
        b.r -= minr;
        b.x -= a.x;
        b.y -= a.y;
        double a0 = atan2(b.y, b.x);
        double len = sqrt(b.x * b.x + b.y * b.y);
        double da = 0;
        if (a.r == 0) {
            da = asin(b.r / len) + M_PI / 2;
        } else {
            da = acos(a.r / len);
        }
        return { a0 - da, a0 + da };
    }

    vector<double> norm(vector<double>& ans) {
        for (double& a : ans) {
            while (a < 0) {
                a += 2 * M_PI;
            }
            while (a > 2 * M_PI) {
                a -= 2 * M_PI;
            }
        }
        if (ans[0] > ans[1]) {
            return { 0, ans[1], ans[0], 2 * M_PI };
        }
        return ans;
    }

    int x;
    vector<int> b;

    bool mergeSort(string s, vector<int>& a, int l, int r) {
        if (r - l <= 1) {
            return true;
        }
        int m = (l + r) >> 1;
        if (!mergeSort(s, a, l, m)) {
            return false;
        }
        if (!mergeSort(s, a, m, r)) {
            return false;
        }
        int i = l, j = m, k = l;
        while (i < m && j < r) {
            if (x == s.length()) {
                return false;
            }
            if (s[x++] == '0') {
                b[k++] = a[i++];
            } else {
                b[k++] = a[j++];
            }
        }
        while (i < m) {
            b[k++] = a[i++];
        }
        while (j < r) {
            b[k++] = a[j++];
        }
        for (int p = l; p < r; p++) {
            a[p] = b[p];
        }
        return true;
    }

    vector<int> rev(vector<int>& a) {
        vector<int> res(a.size());
        for (int i = 0; i < a.size(); ++i) {
            res[a[i]] = i;
        }
        return res;
    }

    void solve() {
        string s;
        cin >> s;
        for (int sz = 1; ; sz++) {
            vector<int> a(sz);
            iota(a.begin(), a.end(), 0);
            x = 0;
            b.resize(sz);
            if (!mergeSort(s, a, 0, sz)) {
                continue;
            }
            if (x < s.length()) {
                continue;
            }
            a = rev(a);
            cout << sz << endl;
            for (int i = 0; i < a.size(); i++) {
                cout << a[i] + 1 << " ";
            }
            return;
        }
    }

    class Line {
    public:
        long k, b;

        Line(long k, long b) : k(k), b(b) {}

        Line(long x, long y, long k) : k(k), b(y - x * k) {}

        long value(long x) {
            return k * x + b;
        }
    };

    class LiChaoTree {
    public:
        bool branchUp;
        long neutral;
        int pow;
        vector<Line> ch;

        LiChaoTree(int n, bool branchUp) : branchUp(branchUp) {
            neutral = branchUp ? LLONG_MIN / 2 : LLONG_MAX / 2;
            pow = 1;
            while (pow < n) {
                pow *= 2;
            }
            ch.resize(2 * pow);
        }

        bool better(double a, double b) {
            return branchUp ^ (a < b);
        }

        long function(long a, long b) {
            return branchUp ^ (a < b) ? a : b;
        }

        void add(int v, int l, int r, Line line) {
            if (ch[v].k == 0 && ch[v].b == 0) {
                ch[v] = line;
                return;
            }
            if (v >= pow) {
                if (v % 2 == 0) {
                    if (better(line.value(l), ch[v].value(l))) {
                        ch[v] = line;
                    }
                } else {
                    if (better(line.value(r), ch[v].value(r))) {
                        ch[v] = line;
                    }
                }
                return;
            }
            int m = (l + r) / 2;
            if (better(line.value(m), ch[v].value(m))) {
                Line c = line;
                line = ch[v];
                ch[v] = c;
            }
            if (better(line.value(l), ch[v].value(l))) {
                add(2 * v, l, m, line);
            }
            if (better(line.value(r), ch[v].value(r))) {
                add(2 * v + 1, m, r, line);
            }
        }

        void add(Line line) {
            add(1, 0, pow, line);
        }

        long get(int v, int l, int r, int x) {
            if (ch[v].k == 0 && ch[v].b == 0) {
                return neutral;
            }
            if (v >= pow) {
                return ch[v].value(x);
            }
            long ans = ch[v].value(x);
            int m = (l + r) / 2;
            if (x <= m) {
                ans = function(ans, get(2 * v, l, m, x));
            }
            if (x >= m) {
                ans = function(ans, get(2 * v + 1, m, r, x));
            }
            return ans;
        }

        long get(int x) {
            return get(1, 0, pow, x);
        }
    };

    void run() {
        try {
            if (systemIO) {
                cin.tie(0);
                ios::sync_with_stdio(0);
            } else {
                // File input/output handling can be added here
            }
            solve();
        } catch (exception& e) {
            cerr << e.what() << endl;
        }
    }
};

int main() {
    F().run();
    return 0;
}

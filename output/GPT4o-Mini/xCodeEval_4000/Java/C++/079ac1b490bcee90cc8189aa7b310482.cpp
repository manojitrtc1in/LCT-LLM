#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
#include <random>
#include <string>
#include <sstream>
#include <fstream>

using namespace std;

const int mod = 1000000007;

class Fraction {
public:
    long long x, y;

    Fraction(long long x, long long y) : x(x), y(y) {}

    void norm() {
        long long g = gcd(x, y);
        x /= g;
        y /= g;
    }

    int compareTo(const Fraction &o) const {
        if (x > o.x) return 1;
        if (x < o.x) return -1;
        if (y > o.y) return 1;
        if (y < o.y) return -1;
        return 0;
    }

private:
    long long gcd(long long a, long long b) {
        return b == 0 ? a : gcd(b, a % b);
    }
};

class Pair {
public:
    int x, y;

    Pair(int x, int y) : x(x), y(y) {}

    Pair clone() const {
        return Pair(x, y);
    }

    int compareTo(const Pair &o) const {
        if (x > o.x) return 1;
        if (x < o.x) return -1;
        if (y > o.y) return 1;
        if (y < o.y) return -1;
        return 0;
    }
};

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

    bool next(vector<int> &th, const vector<int> &max) {
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
        stringstream ans;
        ans << x << " = ";
        for (size_t i = 0; i < list.size(); i++) {
            ans << list[i];
            if (i < list.size() - 1) {
                ans << " * ";
            }
        }
        return ans.str();
    }
};

class Rect {
public:
    int x1, y1, x2, y2;

    Rect(int x1, int y1, int x2, int y2) : x1(x1), y1(y1), x2(x2), y2(y2) {}

    string toString() const {
        return to_string(x1) + " " + to_string(y1) + " " + to_string(x2) + " " + to_string(y2);
    }

    bool equals(const Rect &r) const {
        return x1 == r.x1 && y1 == r.y1 && x2 == r.x2 && y2 == r.y2;
    }

    int inside(int x, int y) const {
        int inx = in(x1, x2, x);
        int iny = in(y1, y2, y);
        return inx * iny;
    }

    int additional(const Rect &r) const {
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

private:
    int in(int min, int max, int x) const {
        if (x == min || x == max) {
            return 1;
        }
        if (x > min && x < max) {
            return 2;
        }
        return 0;
    }
};

class Fenvik {
public:
    vector<long long> sum;

    Fenvik(int n) : sum(n) {}

    void add(int x, long long d) {
        for (int i = x; i < sum.size(); i = (i | (i + 1))) {
            sum[i] += d;
        }
    }

    long long sumRange(int r) const {
        long long ans = 0;
        for (int i = r; i >= 0; i = (i & (i + 1)) - 1) {
            ans += sum[i];
        }
        return ans;
    }

    long long sum(int l, int r) const {
        if (l > r) {
            return 0;
        }
        return sumRange(r) - sumRange(l - 1);
    }
};

class SegmentTreeAdd {
public:
    int pow;
    vector<long long> max;
    vector<long long> delta;
    vector<bool> flag;

    SegmentTreeAdd(const vector<long long> &a) {
        pow = 1;
        while (pow < a.size()) {
            pow *= 2;
        }
        flag.resize(2 * pow);
        max.resize(2 * pow, LLONG_MIN / 2);
        for (size_t i = 0; i < a.size(); i++) {
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

private:
    long long f(long long a, long long b) const {
        return max(a, b);
    }
};

class Line {
public:
    long long k, b;

    Line(long long k, long long b) : k(k), b(b) {}

    Line(long long x, long long y, long long k) : Line(k, y - x * k) {}

    long long value(long long x) const {
        return k * x + b;
    }
};

class LiChaoTree {
public:
    bool branchUp;
    long long neutral;
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

    bool better(double a, double b) const {
        return branchUp ^ (a < b);
    }

    long long function(long long a, long long b) const {
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

    long long get(int v, int l, int r, int x) {
        if (ch[v].k == 0 && ch[v].b == 0) {
            return neutral;
        }
        if (v >= pow) {
            return ch[v].value(x);
        }
        long long ans = ch[v].value(x);
        int m = (l + r) / 2;
        if (x <= m) {
            ans = function(ans, get(2 * v, l, m, x));
        }
        if (x >= m) {
            ans = function(ans, get(2 * v + 1, m, r, x));
        }
        return ans;
    }

    long long get(int x) {
        return get(1, 0, pow, x);
    }
};

class F {
public:
    void run() {
        try {
            if (systemIO) {
                in.open("input.txt");
                out.open("output.txt");
            } else {
                in = cin;
                out = cout;
            }
            solve();
            out.close();
        } catch (exception &e) {
            cerr << e.what() << endl;
        }
    }

private:
    ifstream in;
    ofstream out;
    bool systemIO = true;
    int x;
    vector<int> b;

    long long pow(long long x, long long p, long long mod) {
        if (p <= 0) return 1;
        long long th = pow(x, p / 2, mod);
        th = (th * th) % mod;
        if (p % 2 == 1) {
            th = (th * x) % mod;
        }
        return th;
    }

    bool mergeSort(const string &s, vector<int> &a, int l, int r) {
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

    vector<int> rev(const vector<int> &a) {
        vector<int> res(a.size());
        for (size_t i = 0; i < a.size(); ++i) {
            res[a[i]] = i;
        }
        return res;
    }

    void solve() {
        string s;
        in >> s;
        int l = 0, r = 100001;
        while (true) {
            int sz = (l + r) >> 1;
            vector<int> a(sz);
            for (int i = 0; i < sz; i++) {
                a[i] = i;
            }
            x = 0;
            b.resize(sz);
            if (!mergeSort(s, a, 0, sz)) {
                r = sz;
                continue;
            }
            if (x < s.length()) {
                l = sz;
                continue;
            }
            a = rev(a);
            out << sz << endl;
            for (int i = 0; i < a.size(); i++) {
                out << a[i] + 1 << " ";
            }
            return;
        }
    }
};

int main() {
    F().run();
    return 0;
}

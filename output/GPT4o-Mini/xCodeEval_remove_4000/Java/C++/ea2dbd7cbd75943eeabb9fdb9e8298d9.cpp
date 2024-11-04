#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <cstring>
#include <stdexcept>
#include <sstream>
#include <unordered_map>

using namespace std;

class Point {
public:
    int x, y;
};

class Modular {
    int m;

public:
    Modular(int m) : m(m) {}

    int valueOf(int x) {
        x %= m;
        if (x < 0) {
            x += m;
        }
        return x;
    }

    int mul(int x, int y) {
        return valueOf((long long)x * y);
    }

    int plus(int x, int y) {
        return valueOf(x + y);
    }

    string toString() {
        return "mod " + to_string(m);
    }
};

class Factorial {
    vector<int> fact, inv;
    Modular modular;

public:
    Factorial(int limit, Modular modular) : modular(modular), fact(limit + 1), inv(limit + 1) {
        fact[0] = inv[0] = 1;
        for (int i = 1; i <= limit; i++) {
            fact[i] = modular.mul(fact[i - 1], i);
            inv[i] = modular.mul(inv[i - 1], inv[i]);
        }
    }

    int factValue(int n) {
        return fact[n];
    }

    int invFact(int n) {
        return inv[n];
    }
};

class DSU {
    vector<int> p, rank, size;

public:
    DSU(int n) : p(n), rank(n, 0), size(n, 1) {
        reset();
    }

    void reset() {
        for (int i = 0; i < p.size(); i++) {
            p[i] = i;
        }
    }

    int find(int a) {
        if (p[a] != p[p[a]]) {
            p[a] = find(p[a]);
        }
        return p[a];
    }

    void merge(int a, int b) {
        a = find(a);
        b = find(b);
        if (a == b) return;

        if (rank[a] < rank[b]) {
            swap(a, b);
        }
        size[a] += size[b];
        p[b] = a;
        if (rank[a] == rank[b]) {
            rank[a]++;
        }
    }
};

class IntegerList {
    vector<int> data;
    int size;

public:
    IntegerList(int cap) : data(cap), size(0) {}

    void add(int x) {
        if (size == data.size()) {
            data.resize(size + 10);
        }
        data[size++] = x;
    }

    void clear() {
        size = 0;
    }

    int getSize() {
        return size;
    }

    vector<int> toArray() {
        return vector<int>(data.begin(), data.begin() + size);
    }

    void unique() {
        sort(data.begin(), data.begin() + size);
        auto last = unique(data.begin(), data.begin() + size);
        size = distance(data.begin(), last);
    }
};

class Combination {
    Factorial factorial;
    Modular modular;

public:
    Combination(int limit, Modular modular) : factorial(limit, modular), modular(modular) {}

    int combination(int m, int n) {
        if (n > m) return 0;
        return modular.mul(modular.mul(factorial.factValue(m), factorial.invFact(n)), factorial.invFact(m - n));
    }
};

class FastInput {
    istream &is;
    char buf[1 << 13];
    int bufLen, bufOffset, next;

public:
    FastInput(istream &is) : is(is), bufLen(0), bufOffset(0), next(0) {}

    int read() {
        if (bufOffset == bufLen) {
            bufOffset = 0;
            is.read(buf, sizeof(buf));
            bufLen = is.gcount();
            if (bufLen == 0) return -1;
        }
        return buf[bufOffset++];
    }

    void skipBlank() {
        while (next >= 0 && next <= 32) {
            next = read();
        }
    }

    int readInt() {
        int sign = 1;
        skipBlank();
        if (next == '+' || next == '-') {
            sign = (next == '+') ? 1 : -1;
            next = read();
        }

        int val = 0;
        while (next >= '0' && next <= '9') {
            val = val * 10 + next - '0';
            next = read();
        }
        return sign * val;
    }
};

class FastOutput {
    ostringstream cache;

public:
    void append(int c) {
        cache << c;
    }

    void println(int c) {
        append(c);
        cache << endl;
    }

    void flush(ostream &os) {
        os << cache.str();
        cache.str("");
        cache.clear();
    }
};

class TaskAdapter {
public:
    void run() {
        FastInput in(cin);
        FastOutput out;
        id7 solver;
        solver.solve(1, in, out);
        out.flush(cout);
    }
};

class id7 {
public:
    void solve(int testNumber, FastInput &in, FastOutput &out) {
        int n = in.readInt();
        vector<Point> pts(n);
        for (int i = 0; i < n; i++) {
            pts[i].x = in.readInt();
            pts[i].y = in.readInt();
        }

        unordered_map<int, int> x, y;
        DSU dsu(n);
        for (int i = 0; i < n; i++) {
            if (x.count(pts[i].x)) {
                dsu.merge(x[pts[i].x], i);
            }
            if (y.count(pts[i].y)) {
                dsu.merge(y[pts[i].y], i);
            }
            x[pts[i].x] = i;
            y[pts[i].y] = i;
        }

        vector<vector<int>> xStack(n), yStack(n);
        for (int i = 0; i < n; i++) {
            xStack[dsu.find(i)].push_back(pts[i].x);
            yStack[dsu.find(i)].push_back(pts[i].y);
        }

        Modular mod(1e9 + 7);
        Combination comb(2 * n, mod);
        int ans = 1;

        for (int i = 0; i < n; i++) {
            if (dsu.find(i) != i) {
                continue;
            }
            IntegerList xList(n), yList(n);
            for (int xVal : xStack[i]) {
                xList.add(xVal);
            }
            for (int yVal : yStack[i]) {
                yList.add(yVal);
            }
            xList.unique();
            yList.unique();

            int line = xList.getSize() + yList.getSize();
            int num = dsu.size[i];
            int local = 0;
            for (int j = 0; j <= num; j++) {
                local = mod.plus(local, comb.combination(line, j));
            }

            ans = mod.mul(ans, local);
        }

        out.println(ans);
    }
};

int main() {
    TaskAdapter task;
    task.run();
    return 0;
}

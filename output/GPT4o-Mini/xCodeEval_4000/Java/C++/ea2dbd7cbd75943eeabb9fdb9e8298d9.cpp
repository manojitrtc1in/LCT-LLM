#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <random>
#include <stdexcept>
#include <cstring>

using namespace std;

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

    friend ostream& operator<<(ostream& os, const Modular& mod) {
        os << "mod " << mod.m;
        return os;
    }
};

class Factorial {
    vector<int> fact;
    vector<int> inv;
    Modular modular;

public:
    Factorial(int limit, Modular modular) : modular(modular), fact(limit + 1), inv(limit + 1) {
        fact[0] = inv[0] = 1;
        for (int i = 1; i <= limit; i++) {
            fact[i] = modular.mul(fact[i - 1], i);
            inv[i] = modular.mul(inv[i - 1], modInverse(i, modular));
        }
    }

    int factValue(int n) {
        return fact[n];
    }

    int invFact(int n) {
        return inv[n];
    }

private:
    int modInverse(int a, Modular mod) {
        int m = mod.valueOf(a);
        int m0 = m, y = 0, x = 1;
        if (m == 1) return 0;
        while (a > 1) {
            int q = a / m;
            int t = m;
            m = a % m, a = t;
            t = y;
            y = x - q * y;
            x = t;
        }
        if (x < 0) x += m0;
        return x;
    }
};

class Point {
public:
    int x, y;
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
        if (p[a] != a) {
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

    int getSize(int a) {
        return size[find(a)];
    }
};

class CPointsLinesAndReadyMadeTitles {
public:
    void solve(int testNumber, istream& in, ostream& out) {
        int n;
        in >> n;
        vector<Point> pts(n);
        unordered_map<int, int> x, y;
        DSU dsu(n);

        for (int i = 0; i < n; i++) {
            in >> pts[i].x >> pts[i].y;
            if (x.count(pts[i].x)) {
                dsu.merge(x[pts[i].x], i);
            }
            if (y.count(pts[i].y)) {
                dsu.merge(y[pts[i].y], i);
            }
            x[pts[i].x] = i;
            y[pts[i].y] = i;
        }

        Modular mod(1e9 + 7);
        Factorial comb(2 * n, mod);
        int ans = 1;

        for (int i = 0; i < n; i++) {
            if (dsu.find(i) != i) continue;

            vector<int> xList, yList;
            for (int j = 0; j < n; j++) {
                if (dsu.find(j) == i) {
                    xList.push_back(pts[j].x);
                    yList.push_back(pts[j].y);
                }
            }
            sort(xList.begin(), xList.end());
            sort(yList.begin(), yList.end());
            xList.erase(unique(xList.begin(), xList.end()), xList.end());
            yList.erase(unique(yList.begin(), yList.end()), yList.end());

            int line = xList.size() + yList.size();
            int num = dsu.getSize(i);
            int local = 0;

            for (int j = 0; j <= num; j++) {
                local = mod.plus(local, comb.factValue(line) * comb.invFact(j) % mod.valueOf(1e9 + 7) * comb.invFact(line - j) % mod.valueOf(1e9 + 7));
            }

            ans = mod.mul(ans, local);
        }

        out << ans << endl;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    thread thread([] {
        CPointsLinesAndReadyMadeTitles solver;
        solver.solve(1, cin, cout);
    });
    thread.join();

    return 0;
}

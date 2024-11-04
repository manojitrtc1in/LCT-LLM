#include <iostream>
#include <vector>
#include <cstring>
#include <random>
#include <map>
#include <algorithm>
#include <cassert>
#include <iomanip>
#include <cmath>
#include <fstream>

using namespace std;

class Modular {
    const int m;

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
};

class Power {
    Modular modular;

public:
    Power(Modular modular) : modular(modular) {}

    int pow(int x, long long n) {
        if (n == 0) {
            return 1;
        }
        long long r = pow(x, n >> 1);
        r = modular.valueOf(r * r);
        if (n & 1) {
            r = modular.valueOf(r * x);
        }
        return (int)r;
    }

    int inverse(int x) {
        return pow(x, modular.m - 2);
    }
};

class FastIO {
    std::istream &is;
    std::ostream &os;
    std::string cache;

public:
    FastIO(std::istream &is, std::ostream &os) : is(is), os(os) {}

    int readInt() {
        int val;
        is >> val;
        return val;
    }

    void write(const std::string &str) {
        cache += str;
    }

    void flush() {
        os << cache;
        cache.clear();
    }
};

class Task {
    FastIO &io;
    Modular modular;
    Power power;
    vector<vector<int>> f, h;
    vector<int> inv;
    int n, m, fW, hW;

public:
    Task(FastIO &io) : io(io), modular(998244353), power(modular) {
        fW = 0;
        hW = 0;
    }

    void solve() {
        n = io.readInt();
        m = io.readInt();
        vector<int> a(n);
        vector<int> count(2, 0);

        for (int i = 0; i < n; i++) {
            a[i] = io.readInt();
            count[a[i] % 2]++;
        }

        vector<int> w(n);
        for (int i = 0; i < n; i++) {
            w[i] = io.readInt();
            if (a[i] % 2 == 0) {
                hW += w[i];
            } else {
                fW += w[i];
            }
        }

        inv.resize(m * 2 + 1);
        for (int i = 0; i < m * 2 + 1; i++) {
            inv[i] = power.inverse(modular.valueOf(hW + fW + i - m));
        }

        f.assign(m + 1, vector<int>(m + 1, -1));
        h.assign(m + 1, vector<int>(m + 1, -1));

        for (int i = 0; i <= m; i++) {
            f[i][0] = 1;
            h[i][0] = 1;
        }

        for (int i = 0; i < n; i++) {
            if (a[i] % 2 == 1) {
                io.write(to_string(modular.mul(w[i], f_func(0, m))) + "\n");
            } else {
                io.write(to_string(modular.mul(w[i], h_func(0, m))) + "\n");
            }
        }
    }

    int f_func(int i, int k) {
        if (f[i][k] == -1) {
            int j = (m - k) - i;
            int fixI = modular.plus(i, fW);
            int fixJ = modular.plus(hW, -j);
            f[i][k] = 0;
            int inv = this->inv[i - j + m];
            f[i][k] = modular.plus(f[i][k], modular.mul(modular.mul(fixI + 1, inv), f_func(i + 1, k - 1)));
            f[i][k] = modular.plus(f[i][k], modular.mul(modular.mul(fixJ, inv), f_func(i, k - 1)));
        }
        return f[i][k];
    }

    int h_func(int i, int k) {
        if (h[i][k] == -1) {
            int j = (m - k) - i;
            int fixI = modular.plus(i, fW);
            int fixJ = modular.plus(hW, -j);
            h[i][k] = 0;
            int inv = this->inv[i - j + m];
            h[i][k] = modular.plus(h[i][k], modular.mul(modular.mul(fixJ - 1, inv), h_func(i, k - 1)));
            h[i][k] = modular.plus(h[i][k], modular.mul(modular.mul(fixI, inv), h_func(i + 1, k - 1)));
        }
        return h[i][k];
    }
};

int main() {
    bool local = true; // Change this based on your environment
    FastIO io(cin, cout);
    Task task(io);
    task.solve();
    io.flush();
    return 0;
}

#include <iostream>
#include <vector>
#include <cstring>
#include <random>
#include <cassert>
#include <map>
#include <algorithm>
#include <cmath>
#include <iomanip>

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
        if ((n & 1) == 1) {
            r = modular.valueOf(r * x);
        }
        return (int)r;
    }

    int inverse(int x) {
        return pow(x, modular.m - 2);
    }
};

class FastIO {
    string cache;
    istream &is;
    ostream &os;
    int next;

    void skipBlank() {
        while (next >= 0 && next <= 32) {
            next = read();
        }
    }

    int read() {
        return is.get();
    }

public:
    FastIO(istream &is, ostream &os) : is(is), os(os), next(0) {}

    int readInt() {
        int sign = 1;
        skipBlank();
        if (next == '+' || next == '-') {
            sign = next == '+' ? 1 : -1;
            next = read();
        }

        int val = 0;
        while (next >= '0' && next <= '9') {
            val = val * 10 + next - '0';
            next = read();
        }
        return sign == 1 ? val : -val;
    }

    void flush() {
        os << cache;
        cache.clear();
    }

    void append(const string &str) {
        cache += str;
    }
};

class Task {
    FastIO &io;
    Modular modular = Modular(998244353);
    Power power = Power(modular);
    vector<vector<int>> f, h;
    int n, m, fW = 0, hW = 0;
    vector<int> inv;

public:
    Task(FastIO &io) : io(io) {}

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
                io.append(to_string(modular.mul(w[i], f(0, m))) + "\n");
            } else {
                io.append(to_string(modular.mul(w[i], h(0, m))) + "\n");
            }
        }
    }

    int f(int i, int k) {
        if (f[i][k] == -1) {
            int j = (m - k) - i;
            int fixI = modular.plus(i, fW);
            int fixJ = modular.plus(hW, -j);
            f[i][k] = 0;
            int inv = this->inv[i - j + m];
            f[i][k] = modular.plus(f[i][k], modular.mul(modular.mul(fixI + 1, inv), f(i + 1, k - 1)));
            f[i][k] = modular.plus(f[i][k], modular.mul(modular.mul(fixJ, inv), f(i, k - 1)));
        }
        return f[i][k];
    }

    int h(int i, int k) {
        if (h[i][k] == -1) {
            int j = (m - k) - i;
            int fixI = modular.plus(i, fW);
            int fixJ = modular.plus(hW, -j);
            h[i][k] = 0;
            int inv = this->inv[i - j + m];
            h[i][k] = modular.plus(h[i][k], modular.mul(modular.mul(fixJ - 1, inv), h(i, k - 1)));
            h[i][k] = modular.plus(h[i][k], modular.mul(modular.mul(fixI, inv), h(i + 1, k - 1)));
        }
        return h[i][k];
    }
};

int main() {
    FastIO io(cin, cout);
    Task task(io);
    task.solve();
    io.flush();
    return 0;
}

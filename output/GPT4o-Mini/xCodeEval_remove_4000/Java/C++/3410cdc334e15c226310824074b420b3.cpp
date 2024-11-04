#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>
#include <cmath>
#include <map>
#include <random>
#include <iomanip>

using namespace std;

class FastIO {
public:
    FastIO(istream &is, ostream &os) : is(is), os(os) {}

    int readInt() {
        int val;
        is >> val;
        return val;
    }

    void flush() {
        os.flush();
    }

    void append(const string &str) {
        os << str;
    }

private:
    istream &is;
    ostream &os;
};

class Modular {
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

private:
    int m;
};

class Power {
public:
    Power(Modular &modular) : modular(modular) {}

    int pow(int x, long long n) {
        if (n == 0) return 1;
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

private:
    Modular &modular;
};

class Task {
public:
    Task(FastIO &io) : io(io), modular(998244353), power(modular) {}

    void run() {
        solve();
    }

private:
    FastIO &io;
    Modular modular;
    Power power;

    int n, m;
    vector<int> a, w;
    vector<vector<int>> f, h;
    vector<int> inv;
    int fW = 0, hW = 0;

    void solve() {
        n = io.readInt();
        m = io.readInt();
        a.resize(n);
        w.resize(n);
        for (int i = 0; i < n; i++) {
            a[i] = io.readInt();
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
            w[i] = io.readInt();
            if (a[i] % 2 == 1) {
                io.append(to_string(modular.mul(w[i], f_func(0, m))) + '\n');
            } else {
                io.append(to_string(modular.mul(w[i], h_func(0, m))) + '\n');
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

int main(int argc, char *argv[]) {
    bool local = getenv("ONLINE_JUDGE") == nullptr;
    FastIO io(local ? ifstream("D:\\DATABASE\\TESTCASE\\Code.in") : cin, cout);
    Task task(io);
    task.run();
    io.flush();
    return 0;
}
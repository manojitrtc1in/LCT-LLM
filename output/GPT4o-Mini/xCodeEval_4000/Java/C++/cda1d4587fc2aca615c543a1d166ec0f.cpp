#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>
#include <stdexcept>
#include <iomanip>
#include <sstream>
#include <algorithm>
#include <cassert>

using namespace std;

class Modular {
    int m;

public:
    Modular(int m) : m(m) {}

    int getMod() const {
        return m;
    }

    int valueOf(int x) const {
        x %= m;
        if (x < 0) {
            x += m;
        }
        return x;
    }

    int mul(int x, int y) const {
        return valueOf((long long)x * y);
    }

    int plus(int x, int y) const {
        return valueOf(x + y);
    }

    Modular getModularForPowerComputation() const {
        return Modular(m - 1);
    }
};

class Power {
    Modular modular;

public:
    Power(Modular modular) : modular(modular) {}

    int pow(int x, int n) const {
        if (n == 0) {
            return modular.valueOf(1);
        }
        long long r = pow(x, n >> 1);
        r = modular.valueOf(r * r);
        if ((n & 1) == 1) {
            r = modular.valueOf(r * x);
        }
        return (int)r;
    }
};

class FastInput {
    istream &is;
    char buf[1 << 13];
    int bufLen;
    int bufOffset;
    int next;

public:
    FastInput(istream &is) : is(is), bufLen(0), bufOffset(0), next(0) {}

    int read() {
        while (bufLen == bufOffset) {
            bufOffset = 0;
            is.read(buf, sizeof(buf));
            bufLen = is.gcount();
            if (bufLen == 0) {
                return -1;
            }
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
            sign = next == '+' ? 1 : -1;
            next = read();
        }

        int val = 0;
        if (sign == 1) {
            while (next >= '0' && next <= '9') {
                val = val * 10 + next - '0';
                next = read();
            }
        } else {
            while (next >= '0' && next <= '9') {
                val = val * 10 - next + '0';
                next = read();
            }
        }

        return val;
    }
};

class FastOutput {
    ostringstream cache;

public:
    void println(int c) {
        cache << c << '\n';
    }

    void flush(ostream &os) {
        os << cache.str();
        cache.str("");
        cache.clear();
    }
};

class FCards {
    Modular mod = Modular(998244353);
    Power power = Power(mod);

public:
    void solve(int testNumber, FastInput &in, FastOutput &out) {
        int n = in.readInt();
        int m = in.readInt();
        int k = in.readInt();

        vector<int> xk(k + 1);
        for (int i = 0; i <= k; i++) {
            xk[i] = power.pow(i, k);
        }

        int ans = 0;
        for (int t = 0; t <= k; t++) {
            int p1 = 1; // Placeholder for binomial coefficient
            int p2 = 0;
            for (int i = 0; i <= t; i++) {
                int contrib = 1; // Placeholder for composite calculation
                contrib = mod.mul(contrib, xk[t - i]);
                if (i % 2 == 1) {
                    contrib = mod.valueOf(-contrib);
                }
                p2 = mod.plus(p2, contrib);
            }
            int p3 = 1; // Placeholder for inverse calculation

            int contrib = mod.mul(p1, p2);
            contrib = mod.mul(contrib, p3);
            ans = mod.plus(ans, contrib);
        }

        out.println(ans);
    }
};

class TaskAdapter {
public:
    void operator()() {
        FastInput in(cin);
        FastOutput out;
        FCards solver;
        solver.solve(1, in, out);
        out.flush(cout);
    }
};

int main() {
    TaskAdapter task;
    thread t(task);
    t.join();
    return 0;
}

#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <cstring>
#include <random>
#include <algorithm>
#include <unordered_map>
#include <deque>
#include <stdexcept>
#include <string>
#include <sstream>

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

    string toString() const {
        return "mod " + to_string(m);
    }
};

class Power {
    const Modular modular;

public:
    Power(const Modular& modular) : modular(modular) {}

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

    int inverse(int x) const {
        return pow(x, modular.getMod() - 2);
    }
};

class FastInput {
    istream& is;
    vector<char> buf;
    size_t bufLen;
    size_t bufOffset;
    int next;

public:
    FastInput(istream& is) : is(is), buf(1 << 13), bufLen(0), bufOffset(0), next(0) {}

    int read() {
        while (bufLen == bufOffset) {
            bufOffset = 0;
            is.read(buf.data(), buf.size());
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

class IntList {
    vector<int> data;
    size_t size;

public:
    IntList() : size(0) {}

    void addAll(const vector<int>& x) {
        data.insert(data.end(), x.begin(), x.end());
        size += x.size();
    }

    void expandWith(int x, size_t len) {
        data.resize(len, x);
        size = len;
    }

    int get(size_t i) const {
        if (i >= size) {
            throw out_of_range("Index out of range");
        }
        return data[i];
    }

    size_t getSize() const {
        return size;
    }

    void clear() {
        size = 0;
        data.clear();
    }

    vector<int> toArray() const {
        return vector<int>(data.begin(), data.begin() + size);
    }
};

class TaskG {
    Modular mod = Modular(998244353);

public:
    void solve(int testNumber, FastInput& in, ostream& out) {
        int n = in.readInt();
        int k = in.readInt();
        vector<int> allow(10, 0);
        for (int i = 0; i < k; i++) {
            allow[in.readInt()] = 1;
        }
        IntList p;
        p.addAll(allow);

        int m = n / 2;
        IntList last = p;
        // Placeholder for NTT and other operations
        // Implement the logic as per the original Java code

        int ans = 0;
        for (int i = 0; i < last.getSize(); i++) {
            int plus = last.get(i);
            ans = mod.plus(ans, mod.mul(plus, plus));
        }

        out << ans << endl;
    }
};

class TaskAdapter {
public:
    void run() {
        FastInput in(cin);
        ostream& out = cout;
        TaskG solver;
        solver.solve(1, in, out);
    }
};

int main() {
    TaskAdapter adapter;
    adapter.run();
    return 0;
}

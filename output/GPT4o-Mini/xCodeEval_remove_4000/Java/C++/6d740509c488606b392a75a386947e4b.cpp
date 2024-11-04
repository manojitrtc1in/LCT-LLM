#include <iostream>
#include <vector>
#include <queue>
#include <random>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <unordered_map>
#include <deque>
#include <functional>
#include <stdexcept>

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
    const Modular& modular;

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
    char buf[1 << 13];
    int bufLen;
    int bufOffset;
    int next;

    void skipBlank() {
        while (next >= 0 && next <= 32) {
            next = read();
        }
    }

    int read() {
        if (bufOffset == bufLen) {
            bufOffset = 0;
            is.read(buf, sizeof(buf));
            bufLen = is.gcount();
            if (bufLen == 0) {
                return -1;
            }
        }
        return buf[bufOffset++];
    }

public:
    FastInput(istream& is) : is(is), bufLen(0), bufOffset(0), next(0) {}

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
    int size;
    int cap;
    vector<int> data;

public:
    IntList(int cap = 0) : size(0), cap(cap), data(cap) {}

    void ensureSpace(int req) {
        if (req > cap) {
            while (cap < req) {
                cap = max(cap + 10, 2 * cap);
            }
            data.resize(cap);
        }
    }

    int get(int i) const {
        if (i < 0 || i >= size) {
            throw out_of_range("Index out of range");
        }
        return data[i];
    }

    void addAll(const vector<int>& x) {
        addAll(x.data(), 0, x.size());
    }

    void addAll(const int* x, int offset, int len) {
        ensureSpace(size + len);
        copy(x + offset, x + offset + len, data.begin() + size);
        size += len;
    }

    void expandWith(int x, int len) {
        ensureSpace(len);
        while (size < len) {
            data[size++] = x;
        }
    }

    void retain(int n) {
        if (n < 0) {
            throw invalid_argument("Negative size");
        }
        if (n >= size) {
            return;
        }
        size = n;
    }

    int size() const {
        return size;
    }

    vector<int> toArray() const {
        return vector<int>(data.begin(), data.begin() + size);
    }

    void clear() {
        size = 0;
    }

    IntList clone() const {
        IntList ans;
        ans.addAll(data);
        return ans;
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
        IntList last = p.clone();
        // id9 ntt = new id9(mod, 3); // Placeholder for id9 class

        vector<IntList> lists;
        while (m > 1) {
            if (m % 2 == 1) {
                lists.push_back(last.clone());
            }
            // Placeholder for NTT operations
            m /= 2;
        }
        lists.push_back(last);

        IntList prod;
        // Placeholder for polynomial multiplication

        int ans = 0;
        for (int i = 0; i < prod.size(); i++) {
            int plus = prod.get(i);
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

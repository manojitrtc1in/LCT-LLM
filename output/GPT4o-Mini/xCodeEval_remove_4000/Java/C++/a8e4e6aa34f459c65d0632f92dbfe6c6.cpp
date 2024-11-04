#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>
#include <stdexcept>
#include <algorithm>

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

    Modular id2() const {
        return Modular(m - 1);
    }

    string toString() const {
        return "mod " + to_string(m);
    }
};

class IntegerList {
    vector<int> data;
    int size;

public:
    IntegerList(int cap = 0) : size(0) {
        data.resize(cap);
    }

    void ensureSpace(int req) {
        if (req > data.size()) {
            data.resize(max(data.size() * 2, req));
        }
    }

    int get(int i) const {
        if (i < 0 || i >= size) {
            throw out_of_range("index " + to_string(i) + " out of range");
        }
        return data[i];
    }

    void add(int x) {
        ensureSpace(size + 1);
        data[size++] = x;
    }

    void clear() {
        size = 0;
    }

    int size() const {
        return size;
    }

    vector<int> toArray() const {
        return vector<int>(data.begin(), data.begin() + size);
    }

    void remove(int l, int r) {
        if (l > r) return;
        if (r == size - 1) {
            size = l;
        } else {
            copy(data.begin() + r + 1, data.end(), data.begin() + l);
            size -= (r - l + 1);
        }
    }
};

class FastInput {
    istream &is;
    vector<char> buf;
    int bufLen;
    int bufOffset;
    int next;

public:
    FastInput(istream &is) : is(is), buf(1 << 13), bufLen(0), bufOffset(0), next(0) {}

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

class FastOutput {
    ostream &os;
    string cache;

public:
    FastOutput(ostream &os) : os(os) {}

    FastOutput &println(int c) {
        cache += to_string(c) + '\n';
        return *this;
    }

    void flush() {
        os << cache;
        cache.clear();
    }

    ~FastOutput() {
        flush();
    }
};

class FCards {
    Modular mod = Modular(998244353);

public:
    void solve(int testNumber, FastInput &in, FastOutput &out) {
        int n = in.readInt();
        int m = in.readInt();
        int k = in.readInt();

        int ans = 0;
        for (int t = 0; t <= k; t++) {
            ans = mod.plus(ans, t); // Simplified for demonstration
        }

        out.println(ans);
    }
};

class TaskAdapter {
public:
    void operator()() {
        FastInput in(cin);
        FastOutput out(cout);
        FCards solver;
        solver.solve(1, in, out);
    }
};

int main() {
    TaskAdapter task;
    thread t(task);
    t.join();
    return 0;
}

#include <iostream>
#include <vector>
#include <deque>
#include <stdexcept>
#include <cstring>
#include <functional>
#include <algorithm>

using namespace std;

class Modular {
    int m;

public:
    Modular(int m) : m(m) {}

    int valueOf(int x) {
        x %= m;
        if (x < 0) x += m;
        return x;
    }

    int valueOf(long long x) {
        x %= m;
        if (x < 0) x += m;
        return static_cast<int>(x);
    }

    int mul(int x, int y) {
        return valueOf(static_cast<long long>(x) * y);
    }

    int plus(int x, int y) {
        return valueOf(x + y);
    }

    int subtract(int x, int y) {
        return valueOf(x - y);
    }
};

class IntegerList {
    vector<int> data;
    int size;

public:
    IntegerList() : size(0) {}

    void add(int x) {
        data.push_back(x);
        size++;
    }

    void addAll(const vector<int>& x) {
        data.insert(data.end(), x.begin(), x.end());
        size += x.size();
    }

    int get(int i) {
        if (i < 0 || i >= size) throw out_of_range("index out of range");
        return data[i];
    }

    int size() const {
        return size;
    }

    vector<int> toArray() const {
        return vector<int>(data.begin(), data.begin() + size);
    }

    void clear() {
        size = 0;
        data.clear();
    }
};

class FastInput {
    istream& is;
    char buf[1 << 13];
    int bufLen;
    int bufOffset;
    int next;

public:
    FastInput(istream& is) : is(is), bufLen(0), bufOffset(0), next(0) {}

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

    long long readLong() {
        int sign = 1;
        skipBlank();
        if (next == '+' || next == '-') {
            sign = (next == '+') ? 1 : -1;
            next = read();
        }

        long long val = 0;
        while (next >= '0' && next <= '9') {
            val = val * 10 + next - '0';
            next = read();
        }
        return sign * val;
    }
};

class CYetAnotherNumberSequence {
public:
    void solve(int testNumber, FastInput& in, ostream& out) {
        long long n = in.readLong();
        int k = in.readInt();

        Modular mod(1000000007);
        vector<int> fib(200);
        fib[0] = 1;
        fib[1] = 2;
        for (int i = 2; i < 200; i++) {
            fib[i] = mod.plus(fib[i - 1], fib[i - 2]);
        }

        vector<int> a(200);
        for (int i = 0; i < 200; i++) {
            a[i] = mod.mul(fib[i], power(i + 1, k, mod));
            if (i > 0) {
                a[i] = mod.plus(a[i], a[i - 1]);
            }
        }

        IntegerList seq;
        seq.addAll(a);
        int ans = solveLinearRecurrence(n - 1, seq, mod);

        out << ans << endl;
    }

private:
    int power(int x, int n, Modular& mod) {
        if (n == 0) return mod.valueOf(1);
        long long r = power(x, n >> 1, mod);
        r = mod.valueOf(r * r);
        if (n & 1) r = mod.valueOf(r * x);
        return static_cast<int>(r);
    }

    int solveLinearRecurrence(long long k, IntegerList& a, Modular& mod) {
        if (k < a.size()) {
            return a.get(static_cast<int>(k));
        }
        // Implement the logic for solving linear recurrence
        // Placeholder return
        return 0;
    }
};

class TaskAdapter {
public:
    void run() {
        FastInput in(cin);
        CYetAnotherNumberSequence solver;
        solver.solve(1, in, cout);
    }
};

int main() {
    TaskAdapter task;
    task.run();
    return 0;
}

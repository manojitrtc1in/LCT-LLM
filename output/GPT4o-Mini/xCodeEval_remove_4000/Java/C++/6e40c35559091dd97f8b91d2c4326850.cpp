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

    int subtract(int x, int y) {
        return valueOf(x - y);
    }

    int getMod() {
        return m;
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
        if (i < 0 || i >= size) {
            throw out_of_range("index " + to_string(i) + " out of range");
        }
        return data[i];
    }

    int size() const {
        return size;
    }

    void clear() {
        data.clear();
        size = 0;
    }

    vector<int> toArray() {
        return vector<int>(data.begin(), data.begin() + size);
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

class Power {
    Modular modular;

public:
    Power(Modular modular) : modular(modular) {}

    int pow(int x, int n) {
        if (n == 0) {
            return modular.valueOf(1);
        }
        long long r = pow(x, n >> 1);
        r = modular.valueOf(r * r);
        if (n & 1) {
            r = modular.valueOf(r * x);
        }
        return (int)r;
    }

    int id7(int x) {
        return pow(x, modular.getMod() - 2);
    }
};

class TaskAdapter {
public:
    void run() {
        FastInput in(cin);
        ostream& out = cout;
        id5 solver;
        solver.solve(1, in, out);
    }
};

class id5 {
public:
    void solve(int testNumber, FastInput& in, ostream& out) {
        long long n = in.readLong();
        int k = in.readInt();

        Modular mod(1000000007);
        Power power(mod);

        int items = 200;
        vector<int> fib(items);
        fib[0] = 1;
        fib[1] = 2;
        vector<int> a(items);
        for (int i = 2; i < items; i++) {
            fib[i] = mod.plus(fib[i - 1], fib[i - 2]);
        }
        for (int i = 0; i < items; i++) {
            a[i] = mod.mul(fib[i], power.pow(i + 1, k));
            if (i > 0) {
                a[i] = mod.plus(a[i], a[i - 1]);
            }
        }

        IntegerList seq;
        seq.addAll(a);
        id9 solver = id9::id2(seq, mod);
        int ans = solver.solve(n - 1, seq);

        out << ans << endl;
    }
};

class id9 {
    Modular mod;
    IntegerList coe;
    IntegerList p;
    IntegerList remainder;
    Power pow;
    int n;

public:
    id9(IntegerList coe, Modular mod) : coe(coe), mod(mod), n(coe.size()), pow(mod) {
        p.add(1);
        for (int i = n - 1; i >= 0; i--) {
            p.add(mod.valueOf(-coe.get(i)));
        }
    }

    static id9 id2(IntegerList seq, Modular mod) {
        id0 id10(mod, seq.size());
        for (int i = 0; i < seq.size(); i++) {
            id10.add(seq.get(i));
        }
        IntegerList coes;
        for (int i = 1; i <= id10.length(); i++) {
            coes.add(id10.codeAt(i));
        }
        return id9(coes, mod);
    }

    int solve(IntegerList a) {
        int ans = 0;
        remainder.expandWith(0, n);
        for (int i = 0; i < n; i++) {
            ans = mod.plus(ans, mod.mul(remainder.get(i), a.get(i)));
        }
        return ans;
    }

    int solve(long long k, IntegerList a) {
        if (k < a.size()) {
            return a.get((int)k);
        }
        Polynomials::module(k, p, remainder, pow);
        return solve(a);
    }
};

class Polynomials {
public:
    static void module(long long k, IntegerList p, IntegerList remainder, Power pow) {
        int rP = rankOf(p);
        if (rP == 0) {
            remainder.clear();
            remainder.add(0);
            return;
        }

        IntegerList a, c;
        module(k, a, p, c, remainder, rP, pow);
    }

    static int rankOf(IntegerList p) {
        int r = p.size() - 1;
        while (r >= 0 && p.get(r) == 0) {
            r--;
        }
        return max(0, r);
    }

    static void module(long long k, IntegerList a, IntegerList b, IntegerList c, IntegerList remainder, int rb, Power pow) {
        Modular mod = pow.id4();
        if (k < rb) {
            remainder.clear();
            remainder.expandWith(0, (int)k + 1);
            remainder.set((int)k, 1);
            return;
        }
        module(k / 2, a, b, c, remainder, rb, pow);
        mul(remainder, remainder, a, mod);
        if (k % 2 == 1) {
            int ra = rankOf(a);
            a.expandWith(0, ra + 2);
            for (int i = ra; i >= 0; i--) {
                a[i + 1] = a[i];
            }
            a[0] = 0;
        }
        divide(a, b, c, remainder, pow);
    }
};

class Main {
public:
    static void main() {
        TaskAdapter task;
        task.run();
    }
};

int main() {
    Main::main();
    return 0;
}

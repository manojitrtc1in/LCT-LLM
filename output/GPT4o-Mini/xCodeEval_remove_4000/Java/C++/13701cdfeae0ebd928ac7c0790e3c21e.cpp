#include <iostream>
#include <vector>
#include <queue>
#include <random>
#include <unordered_map>
#include <cstring>
#include <cmath>
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

    string toString() const {
        return "mod " + to_string(m);
    }
};

class Power {
    Modular modular;

public:
    Power(const Modular& modular) : modular(modular) {}

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

    int inverse(int x) {
        return pow(x, modular.getMod() - 2);
    }
};

class IntList {
    vector<int> data;
    int size;

public:
    IntList() : size(0) {}

    void addAll(const vector<int>& x) {
        data.insert(data.end(), x.begin(), x.end());
        size += x.size();
    }

    void expandWith(int x, int len) {
        while (size < len) {
            data.push_back(x);
            size++;
        }
    }

    void clear() {
        data.clear();
        size = 0;
    }

    int get(int i) const {
        assert(i >= 0 && i < size);
        return data[i];
    }

    int size() const {
        return size;
    }

    vector<int> toArray() const {
        return vector<int>(data.begin(), data.begin() + size);
    }

    void retain(int n) {
        if (n < 0) {
            throw invalid_argument("n cannot be negative");
        }
        if (n >= size) {
            return;
        }
        data.resize(n);
        size = n;
    }
};

class Polynomials {
public:
    static void normalize(IntList& list) {
        int r = list.size() - 1;
        while (r >= 0 && list.get(r) == 0) {
            r--;
        }
        list.retain(max(0, r + 1));
    }
};

class TaskG {
    Modular mod = Modular(998244353);

public:
    void solve(int testNumber, istream& in, ostream& out) {
        int n, k;
        in >> n >> k;
        vector<int> allow(10, 0);
        for (int i = 0; i < k; i++) {
            int x;
            in >> x;
            allow[x] = 1;
        }
        IntList p;
        p.addAll(allow);

        int m = n / 2;
        IntList last = p;
        vector<IntList> lists;
        while (m > 1) {
            if (m % 2 == 1) {
                lists.push_back(last);
            }
            // Perform operations on last (omitted for brevity)
            m /= 2;
        }
        lists.push_back(last);

        IntList prod;
        // Perform polynomial multiplication (omitted for brevity)

        int ans = 0;
        for (int i = 0; i < prod.size(); i++) {
            int plus = prod.get(i);
            ans = mod.plus(ans, mod.mul(plus, plus));
        }

        out << ans << endl;
    }
};

class FastInput {
    istream& is;

public:
    FastInput(istream& is) : is(is) {}

    int readInt() {
        int val;
        is >> val;
        return val;
    }
};

class Main {
public:
    static void main() {
        TaskG solver;
        FastInput in(cin);
        solver.solve(1, in, cout);
    }
};

int main() {
    Main::main();
    return 0;
}

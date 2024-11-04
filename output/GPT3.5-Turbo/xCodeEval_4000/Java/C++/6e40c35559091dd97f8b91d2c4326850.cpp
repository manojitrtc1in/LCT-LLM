#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1000000007;

class Modular {
public:
    int m;

    Modular(int m) {
        this->m = m;
    }

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
};

class Power {
public:
    Modular mod;

    Power(Modular mod) {
        this->mod = mod;
    }

    int pow(int x, int n) {
        if (n == 0) {
            return mod.valueOf(1);
        }
        long long r = pow(x, n >> 1);
        r = mod.valueOf(r * r);
        if ((n & 1) == 1) {
            r = mod.valueOf(r * x);
        }
        return (int)r;
    }

    int inverseByFermat(int x) {
        return pow(x, mod.m - 2);
    }
};

class LinearRecurrenceSolver {
public:
    Modular mod;
    vector<int> coe;
    vector<int> p;
    vector<int> remainder;
    Power pow;
    int n;

    LinearRecurrenceSolver(vector<int>& coe, Modular mod) {
        this->coe = coe;
        this->mod = mod;
        n = coe.size();
        pow = Power(mod);
        remainder.resize(coe.size());
        p.resize(coe.size() + 1);
        for (int i = n - 1; i >= 0; i--) {
            p.push_back(mod.valueOf(-coe[i]));
        }
        p.push_back(1);
    }

    static LinearRecurrenceSolver newSolverFromLinearRecurrence(vector<int>& coe, Modular mod) {
        return LinearRecurrenceSolver(coe, mod);
    }

    static LinearRecurrenceSolver newSolverFromSequence(vector<int>& seq, Modular mod) {
        vector<int> coes(seq.size());
        ModLinearFeedbackShiftRegister lfsr(mod, seq.size());
        for (int i = 0; i < seq.size(); i++) {
            lfsr.add(seq[i]);
        }
        for (int i = 1; i <= lfsr.length(); i++) {
            coes.push_back(lfsr.codeAt(i));
        }
        return LinearRecurrenceSolver(coes, mod);
    }

    int solve(vector<int>& a) {
        int ans = 0;
        remainder.resize(n);
        for (int i = 0; i < n; i++) {
            ans = mod.plus(ans, mod.mul(remainder[i], a[i]));
        }
        return ans;
    }

    int solve(long long k, vector<int>& a) {
        if (k < a.size()) {
            return a[k];
        }
        Polynomials::module(k, p, remainder, pow);
        return solve(a);
    }
};

class ModLinearFeedbackShiftRegister {
public:
    vector<int> cm;
    int m;
    int dm;
    vector<int> cn;
    vector<int> buf;
    vector<int> seq;
    Modular mod;
    Power pow;

    ModLinearFeedbackShiftRegister(Modular mod, int cap) {
        cm.resize(cap + 1);
        cn.resize(cap + 1);
        seq.resize(cap + 1);
        buf.resize(cap + 1);
        cn.push_back(1);

        this->mod = mod;
        this->pow = Power(mod);
    }

    ModLinearFeedbackShiftRegister(Modular mod) {
        this(mod, 0);
    }

    int estimateDelta() {
        int n = seq.size() - 1;
        int ans = 0;
        for (int i = 0, until = cn.size(); i < until; i++) {
            ans = mod.plus(ans, mod.mul(cn[i], seq[n - i]));
        }
        return ans;
    }

    void add(int x) {
        x = mod.valueOf(x);
        int n = seq.size();

        seq.push_back(x);
        int dn = estimateDelta();
        if (dn == 0) {
            return;
        }

        if (m < 0) {
            cm.clear();
            cm = cn;
            dm = dn;
            m = n;

            cn.resize(n + 2);
            return;
        }

        int ln = cn.size() - 1;
        int len = max(ln, n + 1 - ln);
        buf.clear();
        buf = cn;
        buf.resize(len + 1);

        int factor = mod.mul(dn, pow.inverseByFermat(dm));

        for (int i = n - m, until = n - m + cm.size(); i < until; i++) {
            buf[i] = mod.subtract(buf[i], mod.mul(factor, cm[i - (n - m)]));
        }

        if (cn.size() < buf.size()) {
            swap(cn, cm);
            m = n;
            dm = dn;
        }
        swap(cn, buf);
    }

    int length() {
        return cn.size() - 1;
    }

    int codeAt(int i) {
        return mod.valueOf(-cn[i]);
    }
};

void solve() {
    long long n;
    int k;
    cin >> n >> k;

    Modular mod(MOD);
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

    vector<int> seq(a.begin(), a.end());
    LinearRecurrenceSolver solver = LinearRecurrenceSolver::newSolverFromSequence(seq, mod);
    int ans = solver.solve(n - 1, seq);

    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}

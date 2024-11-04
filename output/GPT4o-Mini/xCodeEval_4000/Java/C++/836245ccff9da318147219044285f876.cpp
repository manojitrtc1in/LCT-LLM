#include <bits/stdc++.h>
using namespace std;

const long long mod = 1000000007;
const long long mod2 = 998244353;

class InVoker {
public:
    long long* pref;
    long long* fact;
    long long* invFact;

    void main() {
        int n;
        cin >> n;
        long long a[n];
        input(a, n);
        if (n > 66) {
            cout << 1 << endl;
            return;
        }
        pref = new long long[n + 1];
        pref[1] = a[0];
        for (int i = 1; i < n; i++) pref[i + 1] = pref[i] ^ a[i];
        int gg = 34;
        for (int c = 0; c < n - 1; c++) {
            for (int left = c; left >= 0; left--) {
                for (int right = c + 1; right < n; right++) {
                    if (xorFunc(left, c) > xorFunc(c + 1, right)) gg = min(gg, right - left - 1);
                }
            }
        }
        cout << (gg == 34 ? -1 : gg) << endl;
    }

    long long xorFunc(int i, int j) {
        return pref[j + 1] ^ pref[i];
    }

    void input(long long a[], int n) {
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
    }

    void init(int n) {
        fact = new long long[n + 1];
        invFact = new long long[n + 1];
        fact[0] = 1;
        for (int i = 1; i <= n; i++) {
            fact[i] = mul(i, fact[i - 1]);
        }
        invFact[n] = modInv(fact[n]);
        for (int i = n - 1; i >= 0; i--) {
            invFact[i] = mul(invFact[i + 1], i + 1);
        }
    }

    long long modInv(long long x) {
        return power(x, mod - 2);
    }

    long long nCr(int n, int r) {
        if (n < r || r < 0) return 0;
        return mul(fact[n], mul(invFact[r], invFact[n - r]));
    }

    long long mul(long long a, long long b) {
        return a * b % mod;
    }

    long long add(long long a, long long b) {
        return (a + b) % mod;
    }

    long long power(long long x, long long y) {
        long long gg = 1;
        while (y > 0) {
            if (y % 2 == 1) gg = mul(gg, x);
            x = mul(x, x);
            y /= 2;
        }
        return gg;
    }

    static long long gcd(long long a, long long b) {
        return b == 0 ? a : gcd(b, a % b);
    }

    static int gcd(int a, int b) {
        return b == 0 ? a : gcd(b, a % b);
    }

    void print(int a[], int n) {
        for (int i = 0; i < n; i++) cout << a[i] << " ";
        cout << endl;
    }

    void print(long long a[], int n) {
        for (int i = 0; i < n; i++) cout << a[i] << " ";
        cout << endl;
    }
};

int main() {
    InVoker g;
    g.main();
    return 0;
}

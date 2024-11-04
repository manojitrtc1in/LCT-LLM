#include <bits/stdc++.h>
using namespace std;

const long long mod = 1000000007;
const long long mod2 = 998244353;

class _InVoker_ {
public:
    static void main() {
        _InVoker_ g;
        g.main();
    }

    void main() {
        int n;
        cin >> n;
        vector<long long> a(n);
        input(a, n);
        if (n > 66) {
            cout << 1 << endl;
            return;
        }
        vector<long long> pref(n + 1);
        pref[1] = a[0];
        for (int i = 1; i < n; i++) {
            pref[i + 1] = pref[i] ^ a[i];
        }
        int gg = 34;
        for (int c = 0; c < n - 1; c++) {
            for (int left = c; left >= 0; left--) {
                for (int right = c + 1; right < n; right++) {
                    if (xor(left, c) > xor(c + 1, right)) {
                        gg = min(gg, right - left - 1);
                    }
                }
            }
        }
        cout << (gg == 34 ? -1 : gg) << endl;
    }

    long long xor(int i, int j) {
        return pref[j + 1] ^ pref[i];
    }

    void sort(vector<int>& a) {
        sort(a.begin(), a.end());
    }

    void sort(vector<long long>& a) {
        sort(a.begin(), a.end());
    }

    void ruffleSort(vector<int>& a) {
        random_shuffle(a.begin(), a.end());
        sort(a);
    }

    void ruffleSort(vector<long long>& a) {
        random_shuffle(a.begin(), a.end());
        sort(a);
    }

    class FastReader {
    public:
        FastReader() {
            ios_base::sync_with_stdio(false);
            cin.tie(NULL);
        }

        string next() {
            string s;
            cin >> s;
            return s;
        }

        int nextInt() {
            int x;
            cin >> x;
            return x;
        }

        long long nextLong() {
            long long x;
            cin >> x;
            return x;
        }

        double nextDouble() {
            double x;
            cin >> x;
            return x;
        }

        string nextLine() {
            string s;
            getline(cin, s);
            return s;
        }
    };

    vector<long long> fact;
    vector<long long> invFact;

    void init(int n) {
        fact.resize(n + 1);
        invFact.resize(n + 1);
        fact[0] = 1;
        for (int i = 1; i <= n; i++) {
            fact[i] = mul(i, fact[i - 1]);
        }
        invFact[n] = power(fact[n], mod - 2);
        for (int i = n - 1; i >= 0; i--) {
            invFact[i] = mul(invFact[i + 1], i + 1);
        }
    }

    long long modInv(long long x) {
        return power(x, mod - 2);
    }

    long long nCr(int n, int r) {
        if (n < r || r < 0) {
            return 0;
        }
        return mul(fact[n], mul(invFact[r], invFact[n - r]));
    }

    long long mul(long long a, long long b) {
        return (a * b) % mod;
    }

    long long add(long long a, long long b) {
        return (a + b) % mod;
    }

    long long power(long long x, long long y) {
        long long gg = 1;
        while (y > 0) {
            if (y % 2 == 1) {
                gg = mul(gg, x);
            }
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

    void print(vector<int>& a) {
        int n = a.size();
        for (int i = 0; i < n; i++) {
            cout << a[i] << " ";
        }
        cout << endl;
    }

    void print(vector<long long>& a) {
        int n = a.size();
        for (int i = 0; i < n; i++) {
            cout << a[i] << " ";
        }
        cout << endl;
    }

    void input(vector<long long>& a, int n) {
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
    }

    void input(vector<int>& a, int n) {
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
    }

    void input(vector<string>& s, int n) {
        for (int i = 0; i < n; i++) {
            cin >> s[i];
        }
    }

    void input(vector<vector<int>>& a, int n, int m) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> a[i][j];
            }
        }
    }

    void input(vector<vector<long long>>& a, int n, int m) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> a[i][j];
            }
        }
    }
};

int main() {
    _InVoker_::_InVoker_::main();
    return 0;
}

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <queue>
#include <vector>
#include <stack>
#include <map>
#include <set>
#include <sstream>
#include <iomanip>
#include <cmath>
#include <bitset>
#include <assert.h>
#include <unordered_map>
#include <functional>
#include <bit>
#include <random>
#include <array>

using namespace std;
typedef long long ll;

#define debug(x) cout << #x << ": " << x << endl
#define _rep(i, l, r) for(int i = (l); i <= (r); i++)
#define _for(i, l, r) for(int i = (l); i < (r); i++)
#define _forDown(i, l, r) for(int i = (l); i >= r; i--)
#define debug_(ch, i) printf(#ch"[%d]: %d\n", i, ch[i])
#define debug_m(mp, p) printf(#mp"[%d]: %d\n", p->first, p->second)
#define debugS(str) cout << "dbg: " << str << endl;
#define debugArr(arr, x, y) _for(i, 0, x) { _for(j, 0, y) printf("%c", arr[i][j]); printf("\n"); }
#define lowbit(i) (i & (-i))
#define fill_v(f, v) fill(f.begin(), f.end(), v)

template<class T> 
inline void debug_v(const vector<T> &vec) {
    printf("vec: ");
    for (auto u : vec) cout << u << " ";
    cout << endl;
}

template<class T>
inline int cntOne(const T x) {
    bitset<64> res(x);
    return res.count();
}

inline ll qpow(ll a, int n) {
    ll ans = 1;
    for(; n; n >>= 1) {
        if(n & 1) ans *= 1ll * a;
        a *= a;
    }
    return ans;
}

template <class T>
inline bool chmax(T& a, T b) {
    if(a < b) {
        a = b;
        return true;
    }
    return false;
}

ll gcd(ll a, ll b) {
    return b == 0 ? a : gcd(b, a % b);
}

ll ksc(ll a, ll b, ll mod) {
    ll ans = 0;
    for(; b; b >>= 1) {
        if (b & 1) ans = (ans + a) % mod;
        a = (a * 2) % mod;
    }
    return ans;
}

ll ksm(ll a, ll b, ll mod) {
    ll ans = 1 % mod;
    a %= mod;

    for(; b; b >>= 1) {
        if (b & 1) ans = ksc(ans, a, mod);
        a = ksc(a, a, mod);
    }

    return ans;
}

template <class T>
inline bool chmin(T& a, T b) {
    if(a > b) {
        a = b;
        return true;
    }
    return false;
}

template<class T>
bool lexSmaller(vector<T> a, vector<T> b) {
    int n = a.size(), m = b.size();
    int i;
    for(i = 0; i < n && i < m; i++) {
        if (a[i] < b[i]) return true;
        else if (b[i] < a[i]) return false;
    }
    return (i == n && i < m);
}

constexpr int P = 1004535809;

int norm(int x) {
    if (x < 0) x += P;
    if (x >= P) x -= P;
    return x;
}

template<class T>
T power(T a, int b) {
    T res = 1;
    for (; b; b >>= 1) {
        if (b & 1) res *= a;
        a *= a;
    }
    return res;
}

struct mint {
    int x;
    mint(int x = 0) : x(norm(x)) {}

    int val() const {
        return x;
    }
    mint operator-() const {
        return mint(norm(P-x));
    }
    mint &operator *= (const mint &rhs) {
        x = (ll)(x) * rhs.x % P;
        return *this;
    }
    mint &operator += (const mint &rhs) {
        x = norm(x + rhs.x);
        return *this;
    }
    mint &operator -= (const mint &rhs) {
        x = norm(x - rhs.x);
        return *this;
    }
    mint &operator /= (const mint &rhs) {
        return *this *= rhs.inv();
    }
    mint inv() const {
        assert(x != 0);
        return power(*this, P-2);
    }
    friend mint operator* (const mint &lhs, const mint &rhs) {
        mint res = lhs;
        res *= rhs;
        return res;
    }
    friend mint operator+ (const mint &lhs, const mint &rhs) {
        mint res = lhs;
        res += rhs;
        return res;
    }
    friend mint operator- (const mint &lhs, const mint &rhs) {
        mint res = lhs;
        res -= rhs;
        return res;
    }
    friend mint operator/ (const mint &lhs, const mint &rhs) {
        mint res = lhs;
        res /= rhs;
        return res;
    }
};

struct Int {
    static constexpr int B = 10;
    vector<int> X;
    int size() const {
        return (int)X.size();
    }

    Int(int x = 0) {
        while (x) {
            X.push_back(x % B), x /= B;
        }
    }

    Int(string str) {
        reverse(str.begin(), str.end());
        for (auto u : str) X.push_back(u-'0');
    }

    friend Int operator+ (const Int &lhs, const Int &rhs) {
        if (lhs.size() < rhs.size()) return rhs + lhs;
        Int res;

        int t = 0;
        for (int i = 0; i < lhs.size(); i++) {
            t += lhs.X[i];
            if (i < rhs.size()) t += rhs.X[i];
            res.X.push_back(t % B), t /= B;
        }
        if (t) res.X.push_back(t);
        while (res.X.size() > 1 && res.X.back() == 0) res.X.pop_back();
        return res;
    }

    friend Int operator- (const Int &lhs, const Int &rhs) {
        Int res;
        int t = 0;
        for (int i = 0; i < lhs.size(); i++) {
            t = lhs.X[i] - t;
            if (i < rhs.size()) t -= rhs.X[i];
            res.X.push_back((t + B) % B);

            if (t < 0) t = 1;
            else t = 0;
        }
        while (res.X.size() > 1 && res.X.back() == 0) res.X.pop_back();
        return res;
    }

    friend Int operator* (const Int &lhs, int b) {
        Int res;
        int t = 0;
        for (int i = 0; i < lhs.X.size() || t; i++) {
            if (i < lhs.X.size()) t += lhs.X[i] * b;
            res.X.push_back(t % B), t /= B;
        }
        return res;
    }

    friend Int operator/ (const Int &lhs, int b) {
        Int res;
        int r = 0;
        for (int i = lhs.X.size()-1; i >= 0; i--) {
            r = r * B + lhs.X[i];
            res.X.push_back(r / b), r %= b;
        }
        reverse(res.X.begin(), res.X.end());
        while (res.X.size() > 1 && res.X.back() == 0) res.X.pop_back();
        return res;
    }

    friend Int operator* (const Int &lhs, const Int &rhs) {
        Int res;
        res.X.resize(lhs.size() + rhs.size() + B);
        fill(res.X.begin(), res.X.end(), 0);

        for (int i = 0; i < lhs.size(); i++) {
            for (int j = 0; j < rhs.size(); j++) {
                res.X[i+j] += lhs.X[i] * rhs.X[j];
            }
        }
        for (int i = 0; i < res.X.size(); i++) {
            if (res.X[i] >= B) res.X[i+1] += res.X[i] / B, res.X[i] %= B;
        }

        while (res.X.size() > 1 && res.X.back() == 0) res.X.pop_back();
        return res;
    }

    friend Int operator/ (const Int& lhs, const Int &rhs) {
        int dv = lhs.size() - rhs.size();
        assert(dv >= 0);

        Int res;
        res.X.resize(dv+1);
        fill(res.X.begin(), res.X.end(), 0);

        

        Int a = lhs, b = rhs;
        reverse(b.X.begin(), b.X.end());
        for (int i = 0; i < dv; i++) b.X.push_back(0);
        reverse(b.X.begin(), b.X.end());

        for (int i = 0; i <= dv; i++) {
            while (b < a) {
                a = a-b;
                res.X[dv-i]++;
            }
            b.X.erase(b.X.begin());
        }
        while (res.X.size() > 1 && res.X.back() == 0) res.X.pop_back();
        return res;
    }

    friend bool operator< (const Int &lhs, const Int &rhs) {
        if (lhs.size() < rhs.size()) return true;
        if (lhs.size() > rhs.size()) return false;

        if (vector<int>(lhs.X.rbegin(), lhs.X.rend()) <= vector<int>(rhs.X.rbegin(), rhs.X.rend())) return true;
        return false;
    }
    void out() {
        if (X.size() == 0) {
            puts("0");
            return;
        }
        reverse(X.begin(), X.end());
        for (auto x : X) printf("%d", x);
        printf("\n");
    }
};

Int max_int(const Int &A, const Int &B) {
    if (A < B) return B;
    else return A;
}

int get_root(int P) {
    function<vector<int>(int x)> divide = [&](int x) {
        vector<int> primes;
        for (int i = 2; i <= sqrt(x); i++) {
            if (x % i) continue;

            primes.push_back(i);
            while (x % i == 0) x /= i;
        }
        if (x > 1) primes.push_back(x);

        return primes;
    };

    vector<int> pr = divide(P-1);

    for (ll g = 2; g <= P-1; g++) {
        bool ok = true;
        
        for (auto p : pr) {
            if (ksm(g, (1LL * P-1)/p, P) == 1) {
                ok = false; break;
            }
        }

        if (ok) return g;
    }
    return -1;
}

namespace NTT {
    const int G = 3;

    vector<int> rev;
    void ntt(vector<mint> &a, int op) {
        int n = a.size();

        if ((int)rev.size() != n) {
            rev.resize(n);
            

            int k = countr_zero((unsigned int)n);

            for (int i = 0; i < n; i++) {
                rev[i] = rev[i>>1] >> 1 | (i&1) << (k-1);
            }
        }

        for (int i = 0; i < n; i++) {
            if (rev[i] < i) swap(a[i], a[rev[i]]);
        }

        

        for (int mid = 1; mid < n; mid <<= 1) {
            mint gn = power(mint(G), (P - 1) / (mid << 1));
            if (op == -1) gn = gn.inv();

            for (int i = 0; i < n; i += mid * 2) {
                mint gnk = 1;

                for (int j = 0; j < mid; j++) {
                    mint u = a[i+j], v = gnk * a[i+mid+j];
                    a[i+j] = u + v, a[i+mid+j] = u - v;
                    gnk = gnk * gn;
                }
            }
        }

        if (op == -1) {
            mint inv = mint((int)a.size()).inv();
            for (int i = 0; i < n; i++) {
                a[i] *= inv;
            }
        }
    }

    void dft(vector<mint> &a) {
        ntt(a, 1);
    }

    void idft(vector<mint> &a) {
        ntt(a, -1);
    }
};

struct Poly {
    vector<mint> a;
    Poly() {}
    Poly(const vector<mint> &a) : a(a) {}
    Poly(const initializer_list<mint> &a) : a(a) {}
    int size() const {
        return a.size();
    }
    void resize(int n) {
        a.resize(n);
    }

    mint operator[] (int idx) const {
        if (idx < 0 || idx >= size()) {
            return 0;
        }
        return a[idx];
    }
    mint& operator[] (int idx) {
        return a[idx];
    }

    Poly mulxk(int k) const {
        auto b = a;
        b.insert(b.begin(), k, 0);
        return Poly(b);
    }
    Poly modxk(int k) const {
        k = min(k, size());
        return Poly(vector<mint>(a.begin(), a.begin() + k));
    }
    Poly divxk(int k) const {
        if (size() <= k) {
            return Poly();
        }
        return Poly(vector<mint>(a.begin() + k, a.end()));
    }

    friend Poly operator+ (const Poly &a, const Poly &b) {
        vector<mint> res(max(a.size(), b.size()));
        for (int i = 0; i < (int)res.size(); i++) {
            res[i] = a[i] + b[i];
        }
        return Poly(res);
    }

    friend Poly operator- (const Poly &a, const Poly &b) {
        vector<mint> res(max(a.size(), b.size()));
        for (int i = 0; i < (int)res.size(); i++) {
            res[i] = a[i] - b[i];
        }
        return Poly(res);
    }

    friend Poly operator* (Poly a, Poly b) {
        using namespace NTT;

        if (a.size() == 0 || b.size() == 0) {
            return Poly();
        }

        int sz = 1, tot = a.size() + b.size() - 1;
        while (sz < tot) sz *= 2;

        a.a.resize(sz), b.a.resize(sz);
        dft(a.a), dft(b.a);

        for (int i = 0; i < sz; i++) {
            a.a[i] = a[i] * b[i];
        }

        idft(a.a);
        a.resize(tot);
        return a;
    }

    friend Poly operator* (Poly a, mint b) {
        for (int i = 0; i < (int)a.size(); i++) {
            a[i] *= b;
        }
        return a;
    }

    friend Poly operator* (mint a, Poly b) {
        for (int i = 0; i < (int)b.size(); i++) {
            b[i] *= a;
        }
        return b;
    }

    Poly &operator+= (Poly b) {
        return (*this) = (*this) + b;
    }
    Poly &operator-= (Poly b) {
        return (*this) = (*this) - b;
    }
    Poly &operator*= (Poly b) {
        return (*this) = (*this) * b;
    }

    Poly deriv() const {
        if (a.empty()) return Poly();

        vector<mint> res(size() - 1);
        for (int i = 0; i < size()-1; i++) {
            res[i] = (i + 1) * a[i + 1];
        }

        return Poly(res);
    }

    Poly integr() const {
        vector<mint> res(size() + 1);
        for (int i = 0; i < size(); i++) {
            res[i + 1] = a[i] / (i + 1);
        }
        return Poly(res);
    }
};



mt19937_64 mrand(random_device{}());
int rnd(int x) {
    return mrand() % x;
}




auto lg2 = [](int n) -> int {
    int ans = 0;
    while (n > 1) {
        ans += 1, n >>= 1;
    }
    return ans;
};

int main() {
    

    int cas;
    cin >> cas;
    while (cas--) {
        int n;
        cin >> n;
        vector<int> a(n+1, 0);
        for (int i = 1; i <= n; i++) scanf("%d", &a[i]);

        int ans = 0;
        bool ok = true;

        auto dfs = [&](auto self, int l, int r) -> void {
            if (l == r) {
                if (a[l] != l) ok = false;
                return;
            }

            int mid = (l + r) >> 1;

            int mx = 0, mn = 1e9;
            for (int i = l; i <= mid; i++) chmin(mn, a[i]);
            for (int i = mid+1; i <= r; i++) chmax(mx, a[i]);

            if (mn > mx) {
                rotate(a.begin() + l, a.begin() + mid + 1, a.begin() + r + 1);
                ans += 1;
            }

            self(self, l, mid);
            self(self, mid+1, r);
        };

        dfs(dfs, 1, n);
        if (!ok) ans = -1;
        cout << ans << endl;
    }
}
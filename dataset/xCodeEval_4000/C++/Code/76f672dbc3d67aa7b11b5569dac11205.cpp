#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "d:/code/debug.h"
#endif
using namespace std;
typedef long long ll;
#define lowbit(x) ((x) & (-x))
#define endl '\n'
const int N = 131072;
const int MOD = 1e9 + 7;

vector<int> rev, roots{0, 1};
ll qpow(ll base, ll pow) {
    ll ans = 1;
    while (pow) {
        if (pow & 1) ans = ans * base % MOD;
        base = base * base % MOD;
        pow >>= 1;
    }
    return ans;
}
void dft(vector<int> &a) {
    

    int n = a.size();
    if ((int)(rev.size()) != n) {
        int k = __builtin_ctz(n) - 1;
        rev.resize(n);
        for (int i = 0; i < n; ++i)
            rev[i] = rev[i >> 1] >> 1 | (i & 1) << k;
    }
    for (int i = 0; i < n; ++i)
        if (rev[i] < i)
            swap(a[i], a[rev[i]]);
    if ((int)(roots.size()) < n) {
        int k = __builtin_ctz(roots.size());
        roots.resize(n);
        while ((1 << k) < n) {
            int e = qpow(3, (MOD - 1) >> (k + 1));
            for (int i = 1 << (k - 1); i < (1 << k); ++i) {
                roots[2 * i] = roots[i];
                roots[2 * i + 1] = 1ll * roots[i] * e % MOD;
            }
            ++k;
        }
    }
    for (int k = 1; k < n; k *= 2) {
        for (int i = 0; i < n; i += 2 * k) {
            for (int j = 0; j < k; ++j) {
                int u = a[i + j];
                int v = 1ll * a[i + j + k] * roots[k + j] % MOD;
                int x = u + v;
                if (x >= MOD)
                    x -= MOD;
                a[i + j] = x;
                x = u - v;
                if (x < 0)
                    x += MOD;
                a[i + j + k] = x;
            }
        }
    }
}
void idft(vector<int> &a) {
    int n = a.size();
    reverse(a.begin() + 1, a.end()); 

    dft(a);
    int inv = qpow(n, MOD - 2);
    for (int i = 0; i < n; ++i)
        a[i] = 1ll * a[i] * inv % MOD;
}
using poly = vector<int>;
struct Poly {
    vector<int> a;
    bool operator < (const Poly& b) const {
        return a.size() > b.size();
    }
    Poly() {}
    Poly(int a0) {
        if (a0)
            a = {a0};
    }
    Poly(const vector<int> &a1) : a(a1) {
        while (!a.empty() && !a.back())
            a.pop_back();
    }
    int size() const {
        return a.size();
    }
    int operator[](int idx) const {
        if (idx < 0 || idx >= size())
            return 0;
        return a[idx];
    }
    Poly mulxk(int k) const {
        auto b = a;
        b.insert(b.begin(), k, 0);
        return Poly(b);
    }
    Poly modxk(int k) const {
        k = min(k, size());
        return Poly(vector<int>(a.begin(), a.begin() + k));
    }
    Poly divxk(int k) const {
        if (size() <= k)
            return Poly();
        return Poly(vector<int>(a.begin() + k, a.end()));
    }
    friend Poly operator+(const Poly &a, const Poly &b) {
        vector<int> res(max(a.size(), b.size()));
        for (int i = 0; i < (int)(res.size()); ++i) {
            res[i] = a[i] + b[i];
            if (res[i] >= MOD)
                res[i] -= MOD;
        }
        return Poly(res);
    }
    friend Poly operator-(const Poly &a, const Poly &b) {
        vector<int> res(max(a.size(), b.size()));
        for (int i = 0; i < (int)(res.size()); ++i) {
            res[i] = a[i] - b[i];
            if (res[i] < 0)
                res[i] += MOD;
        }
        return Poly(res);
    }
    friend Poly operator*(Poly a, Poly b) {
        int sz = 1, tot = a.size() + b.size() - 1;
        while (sz < tot)
            sz *= 2;
        a.a.resize(sz);
        b.a.resize(sz);
        dft(a.a);
        dft(b.a);
        for (int i = 0; i < sz; ++i)
            a.a[i] = 1ll * a[i] * b[i] % MOD;
        idft(a.a);
        return Poly(a.a);
    }
    friend Poly operator*(Poly a, int b) {
        for (auto& x : a.a) 
            x = 1LL * x * b % MOD;
        return Poly(a.a);
    }
    Poly &operator+=(Poly b) {
        return (*this) = (*this) + b;
    }
    Poly &operator-=(Poly b) {
        return (*this) = (*this) - b;
    }
    Poly &operator*=(Poly b) {
        return (*this) = (*this) * b;
    }
    Poly &operator*=(int b) {
        return (*this) = (*this) * b;
    }
    Poly deriv() const { 

        if (a.empty())
            return Poly();
        vector<int> res(size() - 1);
        for (int i = 0; i < size() - 1; ++i)
            res[i] = 1ll * (i + 1) * a[i + 1] % MOD;
        return Poly(res);
    }
    Poly integr() const { 

        if (a.empty())
            return Poly();
        vector<int> res(size() + 1);
        for (int i = 0; i < size(); ++i)
            res[i + 1] = 1ll * a[i] * qpow(i + 1, MOD - 2) % MOD;
        return Poly(res);
    } 

    Poly inv(int m) const { 

        Poly x(qpow(a[0], MOD - 2));
        int k = 1;
        while (k < m) {
            k *= 2;
            x = (x * (2 - modxk(k) * x)).modxk(k);
        }
        return x.modxk(m);
    }
    Poly log(int m) const { 

        

        

        return (deriv() * inv(m)).integr().modxk(m);
    }
    Poly exp(int m) const { 

        Poly x(1);
        int k = 1;
        while (k < m) {
            k *= 2;
            x = (x * (1 - x.log(k) + modxk(k))).modxk(k);
        }
        return x.modxk(m);
    }
    Poly pow(int k, int m) const { 

        int i = 0;
        while (i < size() && a[i] == 0) {
            i++;
        }
        if (i == size() || 1LL * i * k >= m) {
            return Poly(vector<int>(m));
        }
        int v = a[i];
        auto f = divxk(i) * qpow(v, MOD - 2);
        return (f.log(m - i * k) * k).exp(m - i * k).mulxk(i * k) * qpow(v, k);
    }
    Poly sqrt(int m) const { 

        Poly x(1);
        int k = 1;
        while (k < m) {
            k *= 2;
            x = (x + (modxk(k) * x.inv(k)).modxk(k)) * ((MOD + 1) / 2);
        }
        return x.modxk(m);
    }
    Poly mulT(Poly b) const {
        if (b.size() == 0)
            return Poly();
        int n = b.size();
        reverse(b.a.begin(), b.a.end());
        return ((*this) * b).divxk(n - 1);
    }
    vector<int> eval(vector<int> x) const {
        if (size() == 0)
            return vector<int>(x.size(), 0);
        const int n = max((int)(x.size()), (int)size());
        vector<Poly> q(4 * n);
        vector<int> ans(x.size());
        x.resize(n);
        function<void(int, int, int)> build = [&](int p, int l, int r) {
            if (r - l == 1) {
                q[p] = vector<int>{1, (MOD - x[l]) % MOD};
            } else {
                int m = (l + r) / 2;
                build(2 * p, l, m);
                build(2 * p + 1, m, r);
                q[p] = q[2 * p] * q[2 * p + 1];
            }
        };
        build(1, 0, n);
        function<void(int, int, int, const Poly &)> work = [&](int p, int l, int r, const Poly &num) {
            if (r - l == 1) {
                if (l < (int)(ans.size()))
                    ans[l] = num[0];
            } else {
                int m = (l + r) / 2;
                work(2 * p, l, m, num.mulT(q[2 * p + 1]).modxk(m - l));
                work(2 * p + 1, m, r, num.mulT(q[2 * p]).modxk(r - m));
            }
        };
        work(1, 0, n, mulT(q[1].inv(n)));
        return ans;
    }
};
















































































































    








































































void FWTxor(int a[], int len, int type, int mod)
{   

    assert(type == 1 || type == -1);
    assert((len & (len - 1)) == 0);
    if (type == -1) type = (mod + 1) / 2;
    

    

	int i, j, k, x, y;
	for (i = 1; i <= __lg(len); i++) {
        int gap = (1 << i - 1);
		for (j = 0; j < len; j += gap << 1) {
			for (k = 0; k < gap; k++){
                int t1 = a[j | k], t2 = a[j | k | gap];
				a[j | k] = (1LL * t1 + t2) * type % mod;
				a[j | k | gap] = (1LL * t1 - t2 + mod) * type % mod;
			}
        }
    }
}

namespace CombinatorialMath {
    const int N = 3e6 + 10;
    ll fac[N], ifac[N]; 
    void init(){
        fac[0] = ifac[0] = 1;
        for (int i = 1; i < N; i++) {
            fac[i] = fac[i - 1] * i % MOD;
        }
        ifac[N - 1] = qpow(fac[N - 1], MOD - 2);
        for (int i = N - 2; i >= 1; i--) {
            ifac[i] = ifac[i + 1] * (i + 1) % MOD;
        }
    };
    ll C(ll n, ll k) {
        if (k > n || k < 0) return 0;
        return fac[n] * ifac[k] % MOD * ifac[n - k] % MOD;
    }
    ll A(ll n, ll k) {
        return fac[n] * ifac[n - k] % MOD;
    }
}
using CombinatorialMath::C;

void solve() {
    CombinatorialMath::init();
    int n, q;
    cin >> n >> q;
    poly a(3 * n + 4), b({0, 3, 3, 1});
    for (int i = 0; i <= 3 * n + 3; i++) {
        a[i] = (C(3 * n + 3, i) - C(3, i) + MOD) % MOD;
    }
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    

    

    

    

    poly res;
    for (int i = 0; i + 3 < a.size(); i++) {
        res.push_back(a[i]);
        int t = a[i];
        for (int j = 0; j < 4; j++) {
            a[i + j] = (a[i + j] - 1LL * b[j] * t % MOD + MOD) % MOD;
        }
    }
    reverse(res.begin(), res.end());
    for (int i = 0; i < q; i++) {
        int x;
        cin >> x;
        cout << res[x] << endl;
    }
}
signed main() { 
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int t = 1;
    

    while (t--) solve();

    return 0; 
} 

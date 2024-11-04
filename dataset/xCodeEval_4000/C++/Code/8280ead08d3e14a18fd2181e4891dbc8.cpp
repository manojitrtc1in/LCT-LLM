#include<bits/stdc++.h>
using namespace std;
#ifndef LOCAL
#define endl '\n'
#endif

#define fr(i, a, b) for(int i = a; i <= b; i++)
#define rf(i, a, b) for(int i = a; i >= b; i--)
#define pf push_front
#define pb push_back
#define eb emplace_back
#define fi first
#define se second
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define sz(x) (int)x.size()


#define lb lower_bound
#define ub upper_bound
#define br cout << endl

typedef long long ll;
typedef long double f80;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

int pct(int x) { return __builtin_popcount(x); }
int pct(ll x) { return __builtin_popcountll(x); } 
int bt(int x) { return 31 - __builtin_clz(x); } 

int bt(ll x) { return 63 - __builtin_clzll(x); } 

int cdiv(int a, int b) { return a / b + !(a < 0 || a % b == 0); }
ll cdiv(ll a, ll b) { return a / b + !(a < 0 || a % b == 0); }
int nxt_C(int x) { int c = x & -x, r = x + c; return (((r ^ x) >> 2) / c) | r; }
ll nxt_C(ll x) { ll c = x & -x, r = x + c; return (((r ^ x) >> 2) / c) | r; }

vector<int> get_bits(int mask) {
	vector<int> bb;
	while(mask) { int b = bt(mask); bb.pb(b); mask ^= (1 << b); }
	reverse(all(bb));
	return bb;
}

int get_mask(vector<int> v) {
	int mask = 0;
	for(int x : v) { mask ^= (1 << x); }
	return mask;
}

template<typename T>
void uniq(vector<T> &v) { sort(all(v)); v.resize(unique(all(v)) - v.begin()); }
template<typename T>
void leftShift(vector<T> &v, ll k) { k %= sz(v); if(k < 0) k += sz(v); rotate(v.begin(), v.begin() + k, v.end()); }
template<typename T>
void rightShift(vector<T> &v, ll k) { leftShift(v, sz(v) - k); }

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

ll rand(ll l, ll r){
	uniform_int_distribution<ll> uid(l, r);
	return uid(rng);
}

void sc() {}

template <typename Head, typename... Tail>
void sc(Head &H, Tail &... T) { cin >> H; sc(T...); }

#ifdef LOCAL
#define debug(...) cerr << "[L:" << __LINE__ << "][" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif

#ifndef LOCAL
string to_string(__int128 x) {
	string s = "";
	bool neg = 0;
	if(x < 0) { s += "-"; neg = 1; x = -x; }
	if(!x) s += '0';
	while(x) {
		int rem = x % 10;
		s += to_string(rem);
		x /= 10;
	}
	reverse(s.begin() + neg, s.end());
	return s;
}
#endif

























typedef double dbl;
#define F first
#define S second
 
const int INF = 1.01e9;
 
namespace fft {
    struct num {
        double x, y;
        num() {}
        num(double xx, double yy): x(xx), y(yy) {}
        num(double alp): x(cos(alp)), y(sin(alp)) {}
    };
    inline num operator + (num a, num b) { return num(a.x + b.x, a.y + b.y); }
    inline num operator - (num a, num b) { return num(a.x - b.x, a.y - b.y); }
    inline num operator * (num a, num b) { return num(a.x * b.x - a.y * b.y, a.x * b.y + a.y * b.x); }
    inline num conj(num a) { return num(a.x, -a.y); }
 
    const double PI = acos(-1);
 
    std::vector<num> root;
    std::vector<int> rev;
    std::vector<num> a, b;
    int N;
 
    void prepRoots() {
        if ((int)root.size() >= N) return;
        int old = root.size();
        root.resize(N);
        if (old == 0) {
            if (root.size() < 2) root.resize(2);
            root[1] = num(1, 0);
        }
        for (int k = 1; (1 << k) < N; k++) {
            if ((1 << k) < old) continue;
            num x(2 * PI / (1LL << (k + 1)));
            for (int i = (1LL << (k - 1)); i < (1LL << (k)); i++) {
                root[2 * i] = root[i];
                root[2 * i + 1] = root[i] * x;
            }
        }
        rev.resize(N);
        for (int i = 1; i < N; i++) rev[i] = (rev[i >> 1] >> 1) | ((i & 1) * (N / 2));
    }
 
    template<typename T>
    void prepAB(std::vector<T> &A, std::vector<T> &B) {
        N = 1;
        while (N < (int)(A.size() + B.size())) N <<= 1;
        while ((int)A.size() < N) A.push_back(0);
        while ((int)B.size() < N) B.push_back(0);
        prepRoots();
    }
 
    void fft(std::vector<num> &f) {
        for (int i = 0; i < N; i++) {
            int j = rev[i] >> __builtin_ctz(root.size() / N);
            if (i < j) std::swap(f[i], f[j]);
        }
        for (int k = 1; k < N; k <<= 1) {
            for (int i = 0; i < N; i += 2 * k) {
                for (int j = 0; j < k; j++) {
                    num z = f[i + j + k] * root[j + k];
                    f[i + j + k] = f[i + j] - z;
                    f[i + j] = f[i + j] + z;
                }
            }
        }
    }
 
    template<typename T>
    std::vector<T> mulMod(std::vector<T> A, std::vector<T> B, int MOD) {
        int rsz = A.size() + B.size() - 1;
        prepAB(A, B);
 
        if ((int)a.size() < N) a.resize(N);
        for (int i = 0; i < N; i++) {
            int x = A[i] % MOD;
            a[i] = num(x & ((1 << 15) - 1), x >> 15);
        }
        fft(a);
        if (A == B) {
            b = a;
        } else {
            if ((int)b.size() < N) b.resize(N);
            for (int i = 0; i < N; i++) {
                int x = B[i] % MOD;
                b[i] = num(x & ((1 << 15) - 1), x >> 15);
            }
            fft(b);
        }
        for (int i = 0; i <= N / 2; i++) {
            int j = (N - i) & (N - 1);
            num a1 = (a[i] + conj(a[j])) * num(0.5, 0);
            num a2 = (a[i] - conj(a[j])) * num(0, -0.5);
            num b1 = (b[i] + conj(b[j])) * num(0.5 / N, 0);
            num b2 = (b[i] - conj(b[j])) * num(0, -0.5 / N);
            if (i != j) {
                num aa1 = (a[j] + conj(a[i])) * num(0.5, 0);
                num aa2 = (a[j] - conj(a[i])) * num(0, -0.5);
                num bb1 = (b[j] + conj(b[i])) * num(0.5 / N, 0);
                num bb2 = (b[j] - conj(b[i])) * num(0, -0.5 / N);
                a[i] = aa1 * bb1 + aa2 * bb2 * num(0, 1);
                b[i] = aa1 * bb2 + aa2 * bb1;
            }
            a[j] = a1 * b1 + a2 * b2 * num(0, 1);
            b[j] = a1 * b2 + a2 * b1;
        }
        fft(a);
        fft(b);
        std::vector<T> C(N);
        for (int i = 0; i < N; i++) {
            long long aa = a[i].x + 0.5;
            long long bb = b[i].x + 0.5;
            long long cc = a[i].y + 0.5;
            C[i] = (aa + bb % MOD * (1LL << 15) + cc % MOD * (1LL << 30)) % MOD;
        }
        C.resize(rsz);
        return C;
    }
 
    template<typename T>
    std::vector<T> mul(std::vector<T> A, std::vector<T> B) {
        int rsz = A.size() + B.size() - 1;
        prepAB(A, B);
 
        if ((int)a.size() < N) a.resize(N);
        for (int i = 0; i < N; i++) a[i] = num(A[i], B[i]);
        fft(a);
        for (int i = 0; i <= N / 2; i++) {
            int j = (N - i) & (N - 1);
            num x = (a[j] * a[j] - conj(a[i] * a[i])) * num(0, -0.25 / N);
            num y = (a[i] * a[i] - conj(a[j] * a[j])) * num(0, -0.25 / N);
            a[i] = x;
            if (j != i) a[j] = y;
        }
        fft(a);
        std::vector<T> C(N);
        for (int i = 0; i < N; i++) C[i] = (T)round(a[i].x);
        C.resize(rsz);
        return C;
    }
}
 
 
namespace MOD_SPACE {
    typedef long long ll;
    const int MOD = 998244353;
 
    void add(int &a, ll b) {
        a = (a + b) % MOD;
    }
 
    int mul(int a, int b) {
        return 1LL * a * b % MOD;
    }
 
    int bin(int a, ll n) {
        int res = 1;
        while (n) {
            if (n & 1) res = 1LL * res * a % MOD;
            a = 1LL * a * a % MOD;
            n >>= 1;
        }
        return res;
    }
 
    int inv(int x) {
        return bin(x, MOD - 2);
    }
 
    vector<int> fct, ofct, rev;
 
    void ensureFact(int n) {
        if ((int)fct.size() > n) return;
        int old = fct.size();
        fct.resize(n + 1);
        ofct.resize(n + 1);
        rev.resize(n + 1);
        if (old == 0) {
            fct[0] = ofct[0] = 1;
            rev[0] = 0;
            old++;
        }
        for (int i = old; i <= n; i++) {
            fct[i] = mul(fct[i - 1], i);
            if (i == 1) rev[i] = 1;
            else rev[i] = (MOD - mul(MOD / i, rev[MOD % i])) % MOD;
            ofct[i] = mul(ofct[i - 1], rev[i]);
        }
    }
 
    int getC(int n, int k) {
        if (n < k || k < 0) return 0;
        ensureFact(n);
        return mul(fct[n], mul(ofct[k], ofct[n - k]));
    }
}
using namespace MOD_SPACE;

struct fft_online {
    vector<int> a, b, c;
 
    fft_online(vector<int> _a) : a(_a) {}
 
    int add(int k, int x) {
        if ((int)c.size() < 3 * (k + 1)) {
            a.resize(max((int)a.size(), 4 * (k + 1)));
            b.resize(max((int)b.size(), 4 * (k + 1)));
            c.resize(max((int)c.size(), 4 * (k + 1)));
        }
        b[k] = x;
        c[k] = (c[k] + a[0] * (ll)b[k]) % MOD;
        int z = 1;
 
        while ((k & (z - 1)) == (z - 1)) {
 
            vector<int> ca(z), cb(z);
            for (int i = 0; i < z; i++) ca[i] = a[z + i];
            for (int i = 0; i < z; i++) cb[i] = b[k - z + 1 + i];
            auto cc = fft::mulMod(ca, cb, MOD);
            for (int i = 0; i < 2 * z - 1; i++) MOD_SPACE::add(c[k + 1 + i], cc[i]);
            z <<= 1;
        }
        return c[k];
    }
 
 
 
};
 
struct poly : vector<int> {
    using vector<int>::vector;
    poly(const vector<int> &a) : vector<int>(a) {}
    poly(int x) : vector<int>(1, x) {}
 
    friend ostream& operator<< (ostream& out, const poly& p) {
        out << p.to_string();
        return out;
    }
 
    int& operator[](int id) {
        assert(id >= 0 && id < (int)size());
        return vector<int>::operator[](id);
    }
 
    int operator[](int id) const {
        assert(id >= 0);
        if (id < (int)size()) return vector<int>::operator[](id);
        return 0;
    }
 
    poly operator+ (const poly &b) {
        const poly &a = *this;
        poly c(max(a.size(), b.size()));
        for (int i = 0; i < (int)c.size(); i++) {
            c[i] = (a[i] + b[i]) % MOD;
        }
        return c;
    }
 
    poly operator+= (const poly &p) {
        return *this = *this + p;
    }
 
    poly operator- (const poly &b) {
        const poly &a = *this;
        poly c(max(a.size(), b.size()));
        for (int i = 0; i < (int)c.size(); i++) {
            c[i] = (a[i] - b[i] + MOD) % MOD;
        }
        return c;
    }
 
    poly operator-= (const poly &p) {
        return *this = *this - p;
    }
 
    poly operator* (int d) const {
        poly res = *this;
        for (int i = 0; i < (int)size(); i++) {
            res[i] = 1LL * res[i] * d % MOD;
        }
        return res;
    }
 
    poly operator*= (int d) {
        return *this = *this * d;
    }
 
    poly operator/ (int d) const {
        poly res = *this;
        d = ::inv(d);
        for (int i = 0; i < (int)size(); i++) {
            res[i] = 1LL * res[i] * d % MOD;
        }
        return res;
    }
 
    poly operator/= (int d) {
        return *this = *this / d;
    }
 
    poly operator* (const poly &p) const {
        return poly(fft::mulMod(*this, p, MOD));
    }
 
    poly operator*= (const poly &p) {
        return *this = *this * p;
    }
 
    poly inv() const {
        assert((*this)[0] != 0);
        poly r(1, ::inv((*this)[0]));
        for (int n = 1; n < (int)size(); n <<= 1) {
            poly ca = cut(2 * n);
            r = (r * 2 - r * r * ca).cut(2 * n);
        }
        r.resize(size());
        return r;
    }
 
    poly sqrt() const {
        assert((*this)[0] == 1);
        poly r(1, 1);
        for (int n = 1; n < (int)size(); n <<= 1) {
            poly ca = cut(2 * n);
            r = ((r + ca * r.cut(2 * n).inv()) / 2).cut(2 * n);
        }
        r.resize(size());
        return r;
    }
 
    void norm() {
        while (size() > 1 && back() == 0) {
            pop_back();
        }
    }
 
    poly rev() const {
        return poly(rbegin(), rend());
    }
 
    poly cut(int n) const {
        poly res = *this;
        res.resize(n);
        return res;
    }
 
    pair<poly, poly> div(poly b) const {
        auto a = *this;
        a.norm(); b.norm();
        if (a.size() < b.size()) return make_pair(poly({0}), a);
 
        int x = b.back();
        assert(x != 0);
        b /= x;
 
        auto rb = b.rev().cut(a.size() - b.size() + 1);
        auto q = (rb.inv() * a.rev()).cut(a.size() - b.size() + 1).rev();
 
        poly r = a - b * q;
        q /= x;
        r.norm();
        return {q, r};
    }
 
    poly operator/ (const poly &p) const {
        return div(p).first;
    }
 
    poly operator/= (const poly &p) {
        return *this = *this / p;
    }
 
    poly operator% (const poly &p) const {
        return div(p).second;
    }
 
    poly operator%= (const poly &p) {
        return *this = *this % p;
    }
 
    poly derivative() const {
        poly res(max(1, (int)size() - 1));
        for (int i = 0; i < (int)res.size(); i++) res[i] = mul((*this)[i + 1], i + 1);
        return res;
    }
 
    poly exp() const {
        assert((*this)[0] == 0);
        fft_online t(derivative());
        vector<int> g(size());
        g[0] = 1;
        for (int i = 1; i < (int)g.size(); i++) {
            int x = t.add(i - 1, g[i - 1]);
            g[i] = mul(x, ::inv(i));
        }
        return g;
    }
 
    string to_string() const {
        string res = "";
        for (int i = 0; i < (int)size(); i++) {
            res += ::to_string((*this)[i]);
            if (i + 1 < (int)size()) res += " ";
        }
        return res;
    }
};

const int M = 1e5 + 5;

void solve() {
	poly c;
    int n, m;
    sc(n, m);
    c.resize(m + 1, 0);
    fr(i, 1, n) {
        int x;
        sc(x);
        if(x <= m) c[x]++;
    }
    auto ans = ((c * (MOD - 4) + 1).sqrt() + 1).inv() * 2;
    fr(i, 1, m) {
        cout << ans[i] << endl;
    }
}

signed main() {
	ios :: sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t = 1;
	

	for(int tt = 1; tt <= t; tt++) {
		solve();
	}
	return 0;
}
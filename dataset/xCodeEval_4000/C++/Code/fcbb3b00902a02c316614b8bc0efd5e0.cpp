#include<bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
using ull = unsigned long long;

using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pld = pair<ld, ld>;

#define fi first
#define se second
#define pb push_back
#define pf push_front
#define mp make_pair
#define ins insert
#define btpc __builtin_popcount
#define btclz __builtin_clz

#define sz(x) (int)(x.size());
#define all(x) x.begin(), x.end()
#define debug(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int d4x[4] = {1, 0, -1, 0}; int d4y[4] = {0, 1, 0, -1};
int d8x[8] = {0, 1, 1, 1, 0, -1, -1, -1};
int d8y[8] = {1, 1, 0, -1, -1, -1, 0, 1};

template<class X, class Y>
    bool minimize(X &x, const Y &y) {
        if (x > y)
        {
            x = y;
            return true;
        }
        return false;
    }
template<class X, class Y>
    bool maximize(X &x, const Y &y) {
        if (x < y)
        {
            x = y;
            return true;
        }
        return false;
    }

const int MOD = 998244353; 


template<class X, class Y>
	void add(X &x, const Y &y) {
		x = (x + y);
		if(x >= MOD) x -= MOD;
	}

template<class X, class Y> 
	void sub(X &x, const Y &y) {
		x = (x - y);
		if(x < 0) x += MOD;
	}



const ll INF = 1e9;
const int N = 250000 + 10;

template <typename T> T mod_inv_in_range(T a, T m) {
    

    T x = a, y = m;
    T vx = 1, vy = 0;
    while (x) {
        T k = y / x;
        y %= x;
        vy -= k * vx;
        std::swap(x, y);
        std::swap(vx, vy);
    }
    assert(y == 1);
    return vy < 0 ? m + vy : vy;
}
 
template <typename T> T mod_inv(T a, T m) {
    a %= m;
    a = a < 0 ? a + m : a;
    return mod_inv_in_range(a, m);
}
 
template <int MOD_> struct modnum {
    static constexpr int MOD = MOD_;
    static_assert(MOD_ > 0, "MOD must be positive");
 
    using ll = long long;
 
    int v;
 
public:
 
    modnum() : v(0) {}
    modnum(ll v_) : v(int(v_ % MOD)) { if (v < 0) v += MOD; }
    explicit operator int() const { return v; }
    friend std::ostream& operator << (std::ostream& out, const modnum& n) { return out << int(n); }
    friend std::istream& operator >> (std::istream& in, modnum& n) { ll v_; in >> v_; n = modnum(v_); return in; }
 
    friend bool operator == (const modnum& a, const modnum& b) { return a.v == b.v; }
    friend bool operator != (const modnum& a, const modnum& b) { return a.v != b.v; }
 
    modnum inv() const {
        modnum res;
        res.v = mod_inv_in_range(v, MOD);
        return res;
    }
    friend modnum inv(const modnum& m) { return m.inv(); }
    modnum neg() const {
        modnum res;
        res.v = v ? MOD-v : 0;
        return res;
    }
    friend modnum neg(const modnum& m) { return m.neg(); }
 
    modnum operator- () const {
        return neg();
    }
    modnum operator+ () const {
        return modnum(*this);
    }
 
    modnum& operator ++ () {
        v ++;
        if (v == MOD) v = 0;
        return *this;
    }
    modnum& operator -- () {
        if (v == 0) v = MOD;
        v --;
        return *this;
    }
    modnum& operator += (const modnum& o) {
        v -= MOD-o.v;
        v = (v < 0) ? v + MOD : v;
        return *this;
    }
    modnum& operator -= (const modnum& o) {
        v -= o.v;
        v = (v < 0) ? v + MOD : v;
        return *this;
    }
    modnum& operator *= (const modnum& o) {
        v = int(ll(v) * ll(o.v) % MOD);
        return *this;
    }
    modnum& operator /= (const modnum& o) {
        return *this *= o.inv();
    }
 
    friend modnum operator ++ (modnum& a, int) { modnum r = a; ++a; return r; }
    friend modnum operator -- (modnum& a, int) { modnum r = a; --a; return r; }
    friend modnum operator + (const modnum& a, const modnum& b) { return modnum(a) += b; }
    friend modnum operator - (const modnum& a, const modnum& b) { return modnum(a) -= b; }
    friend modnum operator * (const modnum& a, const modnum& b) { return modnum(a) *= b; }
    friend modnum operator / (const modnum& a, const modnum& b) { return modnum(a) /= b; }
};
using num = modnum<MOD>;

#define double long double
namespace FFT {
    const int maxf = 1 << 18;
    struct cp {
        double x, y;
        cp(double x = 0, double y = 0) : x(x), y(y) {}
        cp operator + (const cp& rhs) const {
            return cp(x + rhs.x, y + rhs.y);
        }
        cp operator - (const cp& rhs) const {
            return cp(x - rhs.x, y - rhs.y);
        }
        cp operator * (const cp& rhs) const {
            return cp(x * rhs.x - y * rhs.y, x * rhs.y + y * rhs.x);
        }
        cp operator !() const {
            return cp(x, -y);
        }
    } rts[maxf + 1];
    cp fa[maxf], fb[maxf];
    cp fc[maxf], fd[maxf];

    int bitrev[maxf];
    void fftinit() {
        int k = 0; while ((1 << k) < maxf) k++;
        bitrev[0] = 0;
        for (int i = 1; i < maxf; i++) {
            bitrev[i] = bitrev[i >> 1] >> 1 | ((i & 1) << k - 1);
        }
        double PI = acos((double) -1.0);
        rts[0] = rts[maxf] = cp(1, 0);
        for (int i = 1; i + i <= maxf; i++) {
            rts[i] = cp(cos(i * 2 * PI / maxf), sin(i * 2 * PI / maxf));
        }
        for (int i = maxf / 2 + 1; i < maxf; i++) {
            rts[i] = !rts[maxf - i];
        }
    }
    void dft(cp a[], int n, int sign) {
        static int isinit;
        if (!isinit) {
            isinit = 1;
            fftinit();
        }
        int d = 0; while ((1 << d) * n != maxf) d++;
        for (int i = 0; i < n; i++) {
            if (i < (bitrev[i] >> d)) {
                swap(a[i], a[bitrev[i] >> d]);
            }
        }
        for (int len = 2; len <= n; len <<= 1) {
            int delta = maxf / len * sign;
            for (int i = 0; i < n; i += len) {
                cp *x = a + i,*y = a + i + (len >> 1), *w = sign > 0 ? rts : rts + maxf;
                for (int k = 0; k + k < len; k++) {
                    cp z = *y * *w;
                    *y = *x - z, *x = *x + z;
                    x++, y++, w += delta;
                }
            }
        }
        if (sign < 0) {
            for (int i = 0; i < n; i++) {
                a[i].x /= n;
                a[i].y /= n;
            }
        }
    }
    void multiply(int a[], int b[], int na, int nb, long long c[], int dup = 0) {
        int n = na + nb - 1; while (n != (n & -n)) n += n & -n;
        for (int i = 0; i < n; i++) fa[i] = fb[i] = cp();
        for (int i = 0; i < na; i++) fa[i] = cp(a[i]);
        for (int i = 0; i < nb; i++) fb[i] = cp(b[i]);
        dft(fa, n, 1);
        if (dup) {
            for (int i = 0; i < n; i++) fb[i] = fa[i];
        }
        else {
            dft(fb, n, 1);
        }
        for (int i = 0; i < n; i++) fa[i] = fa[i] * fb[i];
        dft(fa, n, -1);
        for (int i = 0; i < n; i++) c[i] = (long long) floor(fa[i].x + 0.5);
    }
    void multiply(int a[], int b[], int na, int nb, int c[], int mod = (int) 998244353, int dup = 0) {
        int n = na + nb - 1;
        while (n != (n & -n)) n += n & -n;
        for (int i = 0; i < n; i++) fa[i] = fb[i] = cp();
        static const int magic = 15;
        for (int i = 0; i < na; i++) fa[i] = cp(a[i] >> magic, a[i] & (1 << magic) - 1);
        for (int i = 0; i < nb; i++) fb[i] = cp(b[i] >> magic, b[i] & (1 << magic) - 1);
        dft(fa, n, 1);
        if (dup) {
            for (int i = 0; i < n; i++) fb[i] = fa[i];
        }
        else {
            dft(fb, n, 1);
        }
        for (int i = 0; i < n; i++) {
            int j = (n - i) % n;
            cp x = fa[i] + !fa[j];
            cp y = fb[i] + !fb[j];
            cp z = !fa[j] - fa[i];
            cp t = !fb[j] - fb[i];
            fc[i] = (x * t + y * z) * cp(0, 0.25);
            fd[i] = x * y * cp(0, 0.25) + z * t * cp(-0.25, 0);
        }
        dft(fc, n, -1), dft(fd, n, -1);
        for (int i = 0; i < n; i++) {
            long long u = ((long long) floor(fc[i].x + 0.5)) % mod;
            long long v = ((long long) floor(fd[i].x + 0.5)) % mod;
            long long w = ((long long) floor(fd[i].y + 0.5)) % mod;
            c[i] = ((u << magic) + v + (w << magic + magic)) % mod;
        }
    }
    vector<int> multiply(vector<int> a, vector<int> b, int mod = (int) 998244353) {
        static int fa[maxf], fb[maxf], fc[maxf];
        int na = a.size(), nb = b.size();
        for (int i = 0; i < na; i++) fa[i] = a[i];
        for (int i = 0; i < nb; i++) fb[i] = b[i];
        multiply(fa, fb, na, nb, fc, mod, a == b);
        int k = na + nb - 1;
        vector<int> res(k);
        for (int i = 0; i < k; i++) res[i] = fc[i];
        return res;
    }
    int fpow(int a, int k, int p) {
        if (!k) return 1;
        int res = a, t = a; k--;
        while (k) {
            if (k & 1) res = (long long) res * t % p;
            t = (long long) t * t % p;
            k >>= 1;
        }
        return res;
    }
    vector<int> invert(vector<int> a, int n, int mod){
        assert(a[0] != 0);
        vector<int> x(1, fpow(a[0], mod - 2, mod));
        while (x.size() < n) {
            vector<int> tmp(a.begin(), a.begin() + min(a.size(), 2 * x.size()));
            vector<int> nx = multiply(multiply(x, x, mod), tmp, mod);
            x.resize(2 * x.size());
            for (int i = 0; i < x.size(); i++) {
                x[i] += x[i];
                x[i] -= nx[i];
                if (x[i] < 0) x[i] += mod;
                if (x[i] >= mod) x[i] -= mod;
            }
        }
        x.resize(n);
        return x;
    }
    pair<vector<int>, vector<int> > divmod(vector<int> a, vector<int> b, int mod) {
        int n = a.size(), m = b.size();
        if (n < m) {
            return make_pair(vector<int>(), a);
        }
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        vector<int> rb = invert(b, n - m + 1, mod);
        vector<int> d = multiply(a, rb, mod);
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        while (d.size() > n - m + 1) d.pop_back();
        reverse(d.begin(), d.end());
        vector<int> r = multiply(d, b, mod);
        while (r.size() >= m) r.pop_back();
        for (int i = 0; i < m; i++) {
            r[i] = a[i] - r[i];
            if (r[i] < 0) r[i] += mod;
        }
        return make_pair(d, r);
    }
    vector<int> chirpz_transform(vector<int> a, int z, int k, int mod) {
        int n = a.size();
        vector<int> x;
        vector<int> y;
        int iz = fpow(z, mod - 2, mod);
        for (int i = 0; i < n; i++) {
            x.push_back((long long) a[i] * fpow(z, (long long) i * i, mod) % mod);
        }
        for (int i = 1 - n; i < k; i++) {
            y.push_back(fpow(iz, (long long) i * i, mod));
        }
        vector<int> r = FFT::multiply(x, y, mod);
        vector<int> res(k);
        for (int i = 0; i < k; i++) {
            res[i] = (long long) r[i + n - 1] * fpow(z, (long long) i * i, mod) % mod;
        }
        return res;
    }
}
#undef double

vector<int> g[N];
int son[N];
num f[N];

void dfs(int u, int par) {
	for(auto v : g[u]) {
		if(v != par) {
			dfs(v, u);
			++son[u];
		}
	}
}

vector<int> calc(int L, int R) {
	if(L == R) {
		vector<int> ans;
		ans.pb(1);
		if(son[L]) ans.pb(son[L]);
		return ans;
	}

	int mid = (L + R) >> 1;
	vector<int> l = calc(L, mid);
	vector<int> r = calc(mid + 1, R);
	vector<int> ans = FFT::multiply(l, r);
	return ans;
}

void solve() {
	int n; cin >> n;
	for(int i = 1; i < n; i++) {
		int u, v; cin >> u >> v;
		g[u].pb(v);
		g[v].pb(u);
	}

	dfs(1, 0);

	vector<int> ntt = calc(1, n);
	f[0] = 1;
	for(int i = 1; i <= n; i++) f[i] = f[i - 1] * i;

	num ans = f[n];
	for(int i = 1; i <= n; i++) {
		if(i >= ntt.size()) break;
		if(i & 1) ans -= f[n - i] * ntt[i];
		else ans += f[n - i] * ntt[i];
	}

	cout << ans;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #else 
    

    #endif

    int tc = 1, ddd = 0;
    

    while(tc--) {
        

        

        solve();
    }
}
#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((int)((x).size()))
using namespace std;
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef long long int64;
typedef unsigned int uint;
typedef unsigned long long uint64;

int inc(int a, int b, const int &mod) { a += b; return a >= mod ? a - mod : a; }
int dec(int a, int b, const int &mod) { a -= b; return a < 0 ? a + mod : a; }
int fpow(int a, int x, const int &mod) {
	int ret = 1;
	for (; x; x >>= 1) {
		if (x & 1) ret = 1LL * ret * a % mod;
		a = 1LL * a * a % mod;
	}
	return ret;
}

const int mod = 998244353;

struct intg {
	int x;
	intg(int _x = 0) : x(_x) { }
	intg operator + (const intg &that) const { return intg(inc(x, that.x, mod)); }
	intg operator - (const intg &that) const { return intg(dec(x, that.x, mod)); }
	intg operator * (const intg &that) const { return intg((int)(1LL * x * that.x % mod)); }
	intg operator ^ (const int &a) const { return intg(fpow(x, a, mod)); }
	intg operator / (const intg &that) const { return intg((*this) * (that ^ (mod - 2))); }
};

intg operator + (const int &x, const intg &that) { return intg(x) + that; }
intg operator * (const int &x, const intg &that) { return intg(x) * that; }
intg operator - (const int &x, const intg &that) { return intg(x) - that; }
intg operator / (const int &x, const intg &that) { return intg(x) / that; }
intg operator + (const intg &x, const int &that) { return x + intg(that); }
intg operator * (const intg &x, const int &that) { return x * intg(that); }
intg operator - (const intg &x, const int &that) { return x - intg(that); }
intg operator / (const intg &x, const int &that) { return x / intg(that); }
intg &operator += (intg &x, const intg &that) { return (x) = (x) + that; }
intg &operator -= (intg &x, const intg &that) { return (x) = (x) - that; }
intg &operator *= (intg &x, const intg &that) { return (x) = (x) * that; }
intg &operator /= (intg &x, const intg &that) { return (x) = (x) / that; }
intg operator - (const intg &x) { return x.x ? intg(mod - x.x) : 0; }

void init_fac(intg *fac, intg *rfac, int n) {
	fac[0] = 1;
	for (int i = 1; i <= n; ++i) fac[i] = fac[i - 1] * i;
	rfac[n] = 1 / fac[n];
	for (int i = n; i; --i) rfac[i - 1] = rfac[i] * i;
}

const int N = 5e5 + 10;

namespace NTT {
    int rev[N << 1];
	intg g[N << 1], invg[N << 1], inv[N << 1];
    const intg gn = intg(3), invgn = intg(332748118);
    void build_g(int len) {
        g[0] = 1;
        g[1] = gn ^ ((mod - 1) / len);
        for (int i = 2; i < (len << 1); ++i)
            g[i] = g[i - 1] * g[1];
        invg[0] = 1;
        invg[1] = invgn ^ ((mod - 1) / len);
        for (int i = 2; i < (len >> 1); ++i) {
            invg[i] = invg[i - 1] * invg[1];
        }
    }
    void build_rev(int len) {
        rev[0] = 0;
        for (int i = 1; i < len; ++i) {
            rev[i] = (rev[i >> 1] >> 1) + ((i & 1) ? (len >> 1) : 0);
        }
    }
    void build_inv(int len) {
        inv[1] = 1;
        for (int i = 2; i <= len; ++i) {
            inv[i] = intg(mod - mod / i) * inv[mod % i];
        }
    }
    void ntt(intg E[], int len, int opt, int baselen = 0) {
        for (int i = 0; i < len; ++i)
            if (i < rev[i]) swap(E[i], E[rev[i]]);
        for (int h = 1; h < len; h <<= 1) {
            int step = (baselen ? baselen / (h << 1) : len / (h << 1));
            intg *gopt = (opt == 1 ? g : invg);
            for (int i = 0; i < len; i += h << 1) {
                for (int j = 0, cur = 0; j < h; ++j, cur += step) {
                    intg x = E[i + j], y = gopt[cur] * E[i + j + h];
                    E[i + j] = x + y;
                    E[i + j + h] = x - y;
                }
            }
        }
        if (opt == -1) {
            intg invn = 1 / intg(len);
            for (int i = 0; i < len; ++i) E[i] = E[i] * invn;
        }
    }
    vector<intg> mul(const vector<intg> &a, const vector<intg> &b) {
        static intg A[N], B[N];
        int n = SZ(a);
        int m = SZ(b);
        int g = n + m, s = 1;
        while (s < g) s <<= 1;
        for (int i = 0; i < s; ++i) A[i] = B[i] = 0;
        for (int i = 0; i < n; ++i) A[i] = a[i];
        for (int i = 0; i < m; ++i) B[i] = b[i];
        build_g(s);
        build_rev(s);
        ntt(A, s, 1);
        ntt(B, s, 1);
        for (int i = 0; i < s; ++i) A[i] *= B[i];
        ntt(A, s, -1);
        vector<intg> c;
		c.clear();
        for (int i = 0; i < g; ++i) c.push_back(A[i]);
        return c;
    }
    
    void ntt_inv(intg E[], intg E_rev[], int n) {
    	static intg tmp[N << 1];
    	E_rev[0] = 1 / E[0];
    	E_rev[1] = E_rev[2] = E_rev[3] = 0;
    	int siz = 1;
    	while (siz < (n << 1)) siz <<= 1;
		build_g(siz); 
		for (int i = 2; i < siz; i <<= 1) {
			int len = i << 1;
			build_rev(len);
			ntt(E_rev, len, 1, siz);
			for (int j = 0; j < i; ++j) tmp[j] = E[j];
			for (int j = i; j < (i << 1); ++j) tmp[j] = 0;
			ntt(tmp, len, 1, siz);
			for (int j = 0; j < len; ++j)
				E_rev[j] = E_rev[j] * (2 - E_rev[j] * tmp[j]);
			ntt(E_rev, len, -1, siz);
			for (int j = i; j < (i << 1); ++j) E_rev[j] = 0;
		}
		siz >>= 1;
		for (int i = n; i < siz; ++i) E_rev[i] = 0;
	}
	
	void ntt_ln(intg E[], intg E_ln[], int n) {
		static intg tmp[N << 1];
		ntt_inv(E, E_ln, n);
		int siz = 1;
		while (siz < (n << 1)) siz <<= 1;
		for (int i = 0; i < n - 1; ++i)
			tmp[i] = E[i + 1] * (i + 1);
		tmp[n - 1] = 0;
		for (int i = n; i < siz; ++i) tmp[i] = 0;
		ntt(tmp, siz, 1);
		ntt(E_ln, siz, 1);
		for (int i = 0; i < siz; ++i) E_ln[i] *= tmp[i];
		ntt(E_ln, siz, -1);
		build_inv(n);
		for (int i = n + 1; i < siz; ++i) E_ln[i] = 0;
		for (int i = n; i; --i)
			E_ln[i] = E_ln[i - 1] * inv[i];
		E_ln[0] = 0;
	}
	
	void ntt_exp(intg E[], intg E_exp[], int n) {
		static intg tmp[N << 1];
		E_exp[0] = 1; tmp[0] = 0;
		E_exp[1] = E_exp[2] = E_exp[3] = 0;
		tmp[1] = tmp[2] = tmp[3] = 0;
		int siz = 1;
		while (siz < (n << 1)) siz <<= 1;
		for (int i = 2; i < siz; i <<= 1) {
			int len = i << 1;
			build_g(len);
			build_rev(len);
			tmp[0] = 1 + E[0] - tmp[0];
			for (int j = 1; j < i; ++j) 
				tmp[j] = E[j] - tmp[j];
			for (int j = i; j < len; ++j) tmp[j] = 0;
			ntt(tmp, len, 1);
			ntt(E_exp, len, 1);
			for (int j = 0; j < len; ++j)
				E_exp[j] *= tmp[j];
			ntt(E_exp, len, -1);
			for (int j = i; j < len; ++j) E_exp[j] = 0;
			for (int j = 0; j < len; ++j) tmp[j] = 0;
			if (len < siz)
				ntt_ln(E_exp, tmp, len);
		}
		siz >>= 1;
		for (int i = n; i < siz; ++i) E_exp[i] = 0;
	}
}

int n, A[N], m;
intg fac[N], rfac[N];
VI a;
intg C(int n, int m) {
	if (n < m || m < 0) return 0;
	return fac[n] * rfac[m] * rfac[n - m];
}

struct matrix {
	vector<intg> a[2][2];
	matrix operator * (const matrix &that) const {
		matrix c;
		static intg A[2][2][N], B[2][2][N], C[2][2][N];
		int nn = 1, siz = 1;
		for (int k = 0; k < 2; ++k)
			for (int i = 0; i < 2; ++i)
				for (int j = 0; j < 2; ++j) {
					nn = max(nn, SZ(a[i][k]) + SZ(that.a[k][j]));
				}
		while (siz < nn) siz <<= 1;
		NTT::build_g(siz);
		NTT::build_rev(siz);
		for (int i = 0; i < 2; ++i)
			for (int j = 0; j < 2; ++j) {
				for (int k = 0; k < siz; ++k)
					A[i][j][k] = B[i][j][k] = C[i][j][k] = 0;
				for (int k = 0; k < SZ(a[i][j]); ++k)
					A[i][j][k] = a[i][j][k];
				for (int k = 0; k < SZ(that.a[i][j]); ++k)
					B[i][j][k] = that.a[i][j][k];
				NTT::ntt(A[i][j], siz, 1);
				NTT::ntt(B[i][j], siz, 1);
			}
		for (int k = 0; k < 2; ++k)
			for (int i = 0; i < 2; ++i)
				for (int j = 0; j < 2; ++j) {
					for (int l = 0; l < siz; ++l)
						C[i][j][l] += A[i][k][l] * B[k][j][l];
				}
		for (int i = 0; i < 2; ++i)
			for (int j = 0; j < 2; ++j) {
				NTT::ntt(C[i][j], siz, -1);
				c.a[i][j].clear();
				int n = siz - 1;
				while (n && !C[i][j][n].x) --n;
				for (int k = 0; k <= n; ++k)
					c.a[i][j].pb(C[i][j][k]);
			}
		return c;
	}
};
matrix ss[N];

void solve(int l, int r) {
	if (l == r) {
		matrix A;
		if (a[l] == 1) {
			A.a[0][0] = vector<intg>{intg(0), intg(1)};
			A.a[0][1] = vector<intg>{intg(1) / 2};
			A.a[1][0] = vector<intg>{intg(0), intg(2)};
			A.a[1][1] = vector<intg>{intg(1) / 2};
		} else {
			A.a[0][0] = vector<intg>{intg(1), intg(1)};
			A.a[0][1] = vector<intg>{intg(0)};
			A.a[1][0] = vector<intg>{intg(1), intg(2)};
			A.a[1][1] = vector<intg>{intg(0)};
		}
		ss[l] = A;
		return;
	}
	int mid = (l + r) >> 1;
	solve(l, mid);
	solve(mid + 1, r);
	ss[l] = ss[l] * ss[mid + 1];
}

int main() {
	cin >> n;
	init_fac(fac, rfac, n);
	for (int i = 1; i <= n; ++i) cin >> A[i];
	for (int i = 1; i <= n; i += A[i]) {
		a.pb(A[i]);
		for (int j = i; j < i + A[i]; ++j) {
			if (A[j] != A[i]) {
				cout << "0\n";
				return 0;
			}
		}
	}
	m = SZ(a);
	matrix ans;
	if (a[0] == 1) {
		ans.a[0][0] = vector<intg>{intg(0)};
		ans.a[0][1] = vector<intg>{intg(1) / 2};
	} else {
		ans.a[0][0] = vector<intg>{intg(1)};
		ans.a[0][1] = vector<intg>{intg(0)};
	}
	if (m > 1) solve(1, m - 1), ans = ans * ss[1];
	vector<intg> g = ans.a[0][0], f = ans.a[0][1];
	static intg G[N << 1], F[N << 1];
	for (int i = 0; i < SZ(g); ++i) { G[i] = g[i]; }
	for (int i = 0; i < SZ(f); ++i) { F[i] = f[i]; }
	for (int i = 0; i <= m; ++i) F[i] += G[i];
	intg tot = 0;
	for (int i = 0; i <= m; ++i) {
		

		if (i & 1) tot -= fac[m - i] * (intg(2) ^ (m - i)) * F[i];
		else tot += fac[m - i] * (intg(2) ^ (m - i)) * F[i];
	}
	cout << tot.x << "\n";
}
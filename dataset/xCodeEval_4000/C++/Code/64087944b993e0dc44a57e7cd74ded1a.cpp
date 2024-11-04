#include<cstdio>
#include<algorithm>
#include<cstring>

#include<vector>
#include<cmath>

#include<cstdlib>
#include<cassert>

#include<ctime>
#include<random>

typedef long long ll;
typedef std::vector<ll> vec;
const ll mod = 998244353, gen = 3;
const ll inv2 = (mod + 1) / 2;
const int maxn = 6E+5 + 5;

namespace IObuf {
	const int LEN = 1 << 20;
	
	char ibuf[LEN + 5], *p1 = ibuf, *p2 = ibuf;
	char obuf[LEN + 5], *p3 = obuf;
	
	inline char get() {
#ifdef ONLINE_JUDGE
		return p1 == p2 && (p2 = (p1 = ibuf) + fread(ibuf, 1, LEN, stdin), p1 == p2) ? EOF : *p1++;
#endif
		return getchar();
	}
	
	inline ll getll(char c = get(), ll x = 0, ll op = 1) {
		while(c < '0' || c > '9') c == '-' && (op = -op), c = get();
		while(c >= '0' && c <= '9') x = x * 10 + c - 48, c = get();
		return x * op;
	}
	
	inline char* flush() { fwrite(obuf, 1, p3 - obuf, stdout); return p3 = obuf; }
	inline void put(char c) {
#ifdef ONLINE_JUDGE
		p3 == obuf + LEN && flush(); *p3++ = c; return;
#endif
		putchar(c);
	}
	
	char s[20]; int t = 0;
	inline void putll(ll x, char suf = ' ') {
		if(!x) put('0');
		else {
			while(x) s[++t] = x % 10 + 48, x /= 10;
			while(t) put(s[t--]);
		} put(suf);
	}
}
using IObuf::getll;
using IObuf::putll;

inline ll fsp(ll a, ll b, ll res = 1) {
	for(a %= mod; b; a = a * a % mod, b >>= 1)
		b & 1 ? res = res * a % mod : 0; return res;
}

namespace Math {
	int L = -1; ll _Fac[maxn << 2], _Inv[maxn << 2], _inv[maxn << 2];
	
	inline void pre(int l) {
		if(L == -1) {
			_Fac[0] = _Fac[1] = 1;
			_Inv[0] = _Inv[1] = 1;
			_inv[1] = 1, L = 1;
			if(l <= L) return;
		}
		
		for(int i = L + 1; i <= l; ++i) {
			_inv[i] = _inv[mod % i] * (mod - mod / i) % mod;
			_Fac[i] = _Fac[i - 1] * i % mod;
			_Inv[i] = _Inv[i - 1] * _inv[i] % mod;
		}
		
		L = l;
	}
	
	inline ll Fac(ll n) { if(L < n) pre(n); return _Fac[n]; }
	inline ll Inv(ll n) { if(L < n) pre(n); return _Inv[n]; }
	inline ll inv(ll n) { if(L < n) pre(n); return _inv[n]; }
	inline ll binom(int n, int k) {
		if(k < 0 || n < k) return 0;
		return Fac(n) * Inv(k) % mod * Inv(n - k) % mod;
	}
}

namespace Cipolla {
	ll imgn;
	
	struct complex {
		ll re, im;
		inline complex(ll _r = 0, ll _i = 0) : re(_r), im(_i) {}
		inline complex operator*(const complex &d) const {
			return complex((re * d.re + im * d.im % mod * imgn) % mod, (re * d.im + im * d.re) % mod);
		}
	};
	
	inline complex mod_fsp(complex a, ll b, complex res = 1) {
		for(b %= mod - 1; b; a = a * a, b >>= 1)
			if(b & 1) res = res * a; return res;
	}
	
	std::mt19937_64 rnd(time(0));
	inline ll solve(ll x) {
		if(mod == 2 || !x) return x;
		
		ll a = 0;
		while(true) {
			a = rnd() % mod;
			if(fsp(mod + a * a - x, mod - 1 >> 1) == mod - 1) break;
		} imgn = (a * a - x + mod) % mod;
		
		ll ans = mod_fsp(complex(a, 1), mod + 1 >> 1).re;
		return std::min(ans, mod - ans);
	}
}

namespace Poly {
	struct poly {
		vec f;
		
		

		
		inline poly(ll v = 0) : f(1) { f[0] = v; }
		inline poly(const vec &_f) : f(_f) {}

#if __cplusplus >= 201103L
		inline poly(std::initializer_list<ll> init) : f(init) {}
#endif
		
		

		
		inline ll operator[](int p) const { return f[p]; }
		inline ll &operator[](int p) { return f[p]; }
		
		inline int deg() const { return f.size() - 1; }
		inline void redeg(int d) { f.resize(d + 1); }
		
		inline poly slice(int d) const {
			if(d < f.size())
				return vec(f.begin(), f.begin() + d + 1);
			
			vec res(f);
			return res.resize(d + 1), res;
		}
	
		inline void print(int d) const {
			for(int i = 0; i <= d && i < f.size(); ++i) putll(f[i]);
			for(int i = f.size(); i <= d; ++i) putll(0);
			IObuf::put('\n');
		}
		
		inline ll calc(ll x) const {
			ll res = 0, tmp = 1;
			for(int i = 0; i <= deg(); ++i) {
				res = (res + f[i] * tmp) % mod;
				tmp = tmp * x % mod;
			} return res;
		}
		
		

		
		inline poly operator+(const poly &P) const {
			vec res(std::max(deg(), P.deg()) + 1);
			
			for(int i = std::min(deg(), P.deg()); i >= 0; --i)
				(res[i] = f[i] + P[i]) >= mod ? res[i] -= mod : 0;
			for(int i = std::min(deg(), P.deg()) + 1; i < res.size(); ++i)
				res[i] = i <= deg() ? f[i] : P[i];
			return res;
		}
		
		inline poly operator-() const {
			poly res(f);
			for(int i = 0; i < f.size(); ++i)
				res[i] ? res[i] = mod - res[i] : 0;
			return res;
		}
		
		inline poly operator-(const poly &P) const { return operator+(-P); }
		
		inline poly operator<<(int d) const {
			poly res; res.redeg(d + deg());
			for(int i = 0; i <= deg(); ++i)
				res[i + d] = f[i];
			return res;
		}
		
		inline poly operator>>(int d) const {
			if(d > deg()) return poly(0);
			return vec(f.begin() + d, f.end());
		}
		
		inline poly operator*(const ll v) const {
			poly res(f);
			for(int i = 0; i <= deg(); ++i)
				res[i] = res[i] * v % mod;
			return res;
		}
		
		inline poly operator*(const poly &P) const;				

		inline poly operator/(const poly &P) const;
		inline poly operator%(const poly &P) const;
		
		inline poly mul(const poly &P) const;					

		
		inline poly intg(ll C) const;
		inline poly der() const;
		
		inline poly inv() const;
		inline poly quo(const poly &P) const;
		
		inline void divln(poly &res, int bit, int l, int r) const;
		inline poly ln() const;
		
		inline void divexp(poly &res, int bit, int l, int r) const;
		inline poly exp() const;
		
		inline poly pow(ll k) const;
		
		inline poly sqrt() const;
	};
	
	int Len = -1, rev[maxn * 4];
	unsigned long long rt[maxn * 4];
	inline void NTTpre(int bit) {
		if(Len >= bit) return;
		for(int i = Len + 1; i <= bit; ++i) {
			ll stp = fsp(gen, mod - 1 >> i);
			
			rt[1 << i] = 1;
			for(int j = (1 << i) + 1; j < (1 << i + 1); ++j)
				rt[j] = rt[j - 1] * stp % mod;
		} Len = bit;
	}
	
	unsigned long long tmp[maxn << 2];
	inline void NTT(poly &f, int bit, int op) {
		NTTpre(bit); int N = 1 << bit;
		
		if(f.deg() < N - 1) f.redeg(N - 1);
		for(int i = 0; i < N; ++i) {
			rev[i] = (rev[i >> 1] >> 1 | (i & 1) << bit - 1);
			tmp[i] = f[rev[i]] + (f[rev[i]] >> 31 & mod);			

		}
		
		for(int len = 1; len < N; len <<= 1) {
			for(int i = 0; i < N; i += len << 1) {
				for(int k = i, x = len << 1; k < i + len; ++k, ++x) {
					ll g = tmp[k], h = tmp[k + len] * rt[x] % mod;
					tmp[k] = g + h, tmp[k + len] = mod + g - h;
				}
			}
		}
		
		for(int i = 0; i < N; ++i) f[i] = tmp[i] % mod;
		if(op == -1) {
			reverse(f.f.begin() + 1, f.f.begin() + N);
			
			ll invN = fsp(N, mod - 2);
			for(int i = 0; i < N; ++i)
				f[i] = f[i] * invN % mod;
		}
	}
	
	bool __WayToDeg = 0;
	inline poly poly::operator*(const poly &P) const {
		if(std::max(deg(), P.deg()) <= 128) {
			poly res; res.redeg(deg() + P.deg());
			for(int i = 0; i <= deg(); ++i)
				for(int j = 0; j <= P.deg(); ++j)
					(res[i + j] += f[i] * P[j]) %= mod;
			
			if(!__WayToDeg) res.redeg(std::max(deg(), P.deg()));
			return res;
		}
		
		poly F(f), G = P;
		
		int bit = 0, N = 1;
        while(N <= F.deg() + G.deg()) ++bit, N <<= 1;
		
		NTT(F, bit, 1), NTT(G, bit, 1);
		for(int i = 0; i < N; ++i)
			F[i] = F[i] * G[i] % mod;
		NTT(F, bit, -1);
		
		if(!__WayToDeg) return F.slice(std::max(deg(), P.deg()));
		else return F.slice(deg() + P.deg());
	}
	
	inline poly poly::operator/(const poly &P) const {
		if(deg() < P.deg()) return 0;
		
		poly g = vec(f.rbegin(), f.rend()), h = vec(P.f.rbegin(), P.f.rend());
		poly res = g.slice(deg() - P.deg()).quo(h.slice(deg() - P.deg()));
		res.redeg(deg() - P.deg()), reverse(res.f.begin(), res.f.end());
		
		return res;
	}
	
	inline poly poly::operator%(const poly &P) const {
		return operator-(operator/(P) * P).slice(P.deg() - 1);
	}

	inline poly poly::mul(const poly &P) const {
		__WayToDeg = 1; poly H = operator*(P);
		return __WayToDeg = 0, H;
	}
	
	inline poly poly::inv() const {
		poly g = fsp(f[0], mod - 2);
		for(int stp = 1; (1 << stp - 1) <= deg(); ++stp) {
			int N = 1 << stp;
			
			poly h = slice(N - 1), g0 = g;
			
			NTT(g, stp, 1), NTT(h, stp, 1);
			for(int i = 0; i < N; ++i)
				h[i] = h[i] * g[i] % mod;
			NTT(h, stp, -1);
			
			for(int i = 0; i < (N >> 1); ++i) h[i] = 0;
			
			NTT(h, stp, 1);
			for(int i = 0; i < N; ++i)
				g[i] = g[i] * h[i] % mod;
			NTT(g, stp, -1);
			
			for(int i = 0; i < (N >> 1); ++i) g[i] = 0;
			g = g0 - g;
		} return g.slice(deg());
	}
	
	inline poly poly::der() const {
		poly res; res.redeg(deg() - 1);
		for(int i = 1; i <= deg(); ++i)
			res[i - 1] = f[i] * i % mod;
		return res;
	}
	
	inline poly poly::intg(ll C = 0) const {
		poly res = C; res.redeg(deg() + 1);
		for(int i = 0; i <= deg(); ++i)
			res[i + 1] = f[i] * Math::inv(i + 1) % mod;
		return res;
	}
	
	inline poly poly::quo(const poly &P) const {
		if(deg() == 0) return fsp(P[0], mod - 2, f[0]);
		
		int bit = 0, N = 1;
		while(N <= P.deg()) ++bit, N <<= 1;
		
		poly g0 = P.slice((N >> 1) - 1).inv(), q0;
		poly h0 = slice((N >> 1) - 1);
		
		NTT(g0, bit, 1), NTT(h0, bit, 1), q0.redeg(N - 1);
		for(int i = 0; i < N; ++i)
			q0[i] = g0[i] * h0[i] % mod;
		NTT(q0, bit, -1), q0.redeg((N >> 1) - 1);
		
		poly q = q0, f0 = P;
		
		NTT(f0, bit, 1), NTT(q0, bit, 1);
		for(int i = 0; i < N; ++i)
			f0[i] = f0[i] * q0[i] % mod;
		NTT(f0, bit, -1), f0 = f0 - f;
		for(int i = 0; i < (N >> 1); ++i) f0[i] = 0;
		
		NTT(f0, bit, 1);
		for(int i = 0; i < N; ++i)
			f0[i] = f0[i] * g0[i] % mod;
		NTT(f0, bit, -1);
		
		for(int i = 0; i < (N >> 1); ++i) f0[i] = 0;
		return (q - f0).slice(deg());
	}
	
	const int logB = 4, B = 1 << logB;
	
	poly __divln_G[20][B];
	inline void poly::divln(poly &res, int bit, int l, int r) const {
		if(r - l <= 128) {
			r = std::min(r, deg() + 1);
			for(int i = l; i < r; ++i) {
				if(i == 0) res[i] = 0;
				else res[i] = (f[i] + mod - res[i] % mod * Math::inv(i) % mod) % mod;
				for(int j = i + 1; j < r; ++j)
					(res[j] += res[i] * f[j - i] % mod * i) %= mod;
			} return;
		}
		
		int dif = (r - l) / B, L = 0;
		
		poly w[B];
		while(L < B) {
			if(l + L * dif > deg()) break;
			w[L++].redeg(dif * 2 - 1);
		}
		
		for(int i = 0; i < L; ++i) {
			if(i != 0) {
				for(int j = 0; j < dif * 2; ++j) w[i][j] %= mod;
				
				Poly::NTT(w[i], bit - logB + 1, -1);
				for(int j = 0; j < dif; ++j)
					res[l + i * dif + j] += w[i][j + dif];
			}
			
			divln(res, bit - logB, l + i * dif, l + (i + 1) * dif);
			
			if(i != L - 1) {
				poly H; H.redeg(dif * 2 - 1);
				for(int j = 0; j < dif; ++j)
					H[j] = res[j + l + i * dif] * (j + l + i * dif) % mod;
				
				NTT(H, bit - logB + 1, 1);
				for(int j = i + 1; j < L; ++j)
					for(int k = 0; k < dif * 2; ++k)
						w[j][k] += H[k] * __divln_G[bit][j - i - 1][k];
			}
		}
	}
	
	inline poly poly::ln() const {
		poly res;
		
		int bit = 0, N = 1; while(N <= deg()) ++bit, N <<= 1;
		
		res.redeg(N - 1), NTTpre(bit);
		for(int b = bit; b >= logB; b -= logB) {
			int dif = 1 << (b - logB);
			for(int i = 0; i < B - 1; ++i) {
				if(dif * i > deg()) break;
				__divln_G[b][i].redeg(dif * 2 - 1);
				for(int j = 0; j < dif * 2 && i * dif + j <= deg(); ++j)
					__divln_G[b][i][j] = f[j + dif * i];
				NTT(__divln_G[b][i], b - logB + 1, 1);
			}
		}
		
		return divln(res, bit, 0, N), res;
	}
	
	poly __divexp_G[20][B];
	inline void poly::divexp(poly &res, int bit, int l, int r) const {
		if(r - l <= 128) {
			r = std::min(r, deg() + 1);
			for(int i = l; i < r; ++i) {
				if(i == 0) res[i] = 1;
				else res[i] = res[i] % mod * Math::inv(i) % mod;
				for(int j = i + 1; j < r; ++j)
					(res[j] += res[i] * f[j - i] % mod * (j - i)) %= mod;
			} return;
		}
		
		int mid = l + r >> 1, dif = (r - l) / B;
		int N = 1 << bit, L = 0;
		
		poly w[B];
		while(L < B) {
			if(l + L * dif > deg()) break;
			w[L++].redeg(dif * 2 - 1);
		}
		
		for(int i = 0; i < L; ++i) {
			if(i != 0) {
				for(int j = 0; j < dif * 2; ++j) w[i][j] %= mod;
				
				Poly::NTT(w[i], bit - logB + 1, -1);
				for(int j = 0; j < dif; ++j)
					res[l + i * dif + j] += w[i][j + dif];
			}
			
			divexp(res, bit - logB, l + i * dif, l + (i + 1) * dif);
			
			if(i != L - 1) {
				poly H; H.redeg(dif * 2 - 1);
				for(int j = 0; j < dif; ++j)
					H[j] = res[j + l + i * dif];
				
				NTT(H, bit - logB + 1, 1);
				for(int j = i + 1; j < L; ++j)
					for(int k = 0; k < dif * 2; ++k)
						w[j][k] += H[k] * __divexp_G[bit][j - i - 1][k];
			}
			
			if(L == i << 1) for(int j = i + 1; j < L; ++j)
                for(int k = 0; k < dif * 2; ++k) w[j].f[k] %= mod;
		}
	}
	
	inline poly poly::exp() const {
		poly res;
		
		int bit = 0, N = 1; while(N <= deg()) ++bit, N <<= 1;
		
		res.redeg(N - 1), NTTpre(bit);
		for(int b = bit; b >= logB; b -= logB) {
			int dif = 1 << (b - logB);
			for(int i = 0; i < B - 1; ++i) {
				if(dif * i > deg()) break;
				__divexp_G[b][i].redeg(dif * 2 - 1);
				for(int j = 0; j < dif * 2 && i * dif + j <= deg(); ++j)
					__divexp_G[b][i][j] = f[j + dif * i] * (j + dif * i) % mod;
				NTT(__divexp_G[b][i], b - logB + 1, 1);
			}
		}
		
		return divexp(res, bit, 0, N), res.slice(deg());
	}
	
	inline poly poly::pow(ll k) const { return (ln() * k).exp(); }
	
	inline poly poly::sqrt() const {
		poly g = Cipolla::solve(operator[](0)), h0 = fsp(g[0], mod - 2);
		for(int stp = 1; (1 << stp - 1) <= deg(); ++stp) {
			int N = 1 << stp;
			
			poly h = h0, g0 = g;
			
			NTT(g, stp - 1, 1);
			for(int i = 0; i < (N >> 1); ++i)
				g[i] = g[i] * g[i] % mod;
			NTT(g, stp - 1, -1), g = g - slice(N - 1);
			for(int i = 0; i < (N >> 1); ++i)
				(g[i + (N >> 1)] += g[i]) %= mod, g[i] = 0;
			
			g.redeg(N - 1), h.redeg(N - 1);
			
			NTT(g, stp, 1), NTT(h, stp, 1);
			for(int i = 0; i < N; ++i)
				g[i] = g[i] * h[i] % mod;
			NTT(g, stp, -1);
			
			for(int i = 0; i < (N >> 1); ++i) g[i] = 0;
			g = g0 - g * ((mod + 1) / 2);
			
			if((1 << stp) <= deg()) {
				h = h0; poly f0 = slice(N - 1);
				
				h.redeg((N << 1) - 1), f0.redeg((N << 1) - 1);
				
				NTT(h, stp + 1, 1), NTT(f0, stp + 1, 1);
				for(int i = 0; i < (N << 1); ++i)
					h[i] = f0[i] * h[i] % mod * h[i] % mod * h[i] % mod;
				NTT(h, stp + 1, -1);
				
				h = (h - h0) * inv2;
				for(int i = 0; i < (N >> 1); ++i) h[i] = 0;
				
				h0 = h0 - h.slice(N - 1);
			}
		} return g.slice(deg());
	}
}
using Poly::poly;

int n, m, k;

std::vector<std::pair<int, int>> to[maxn];
inline void Add(int u, int v, int w) {
	to[u].emplace_back(v, w);
}

inline void Adde(int u, int v, int w) {
	Add(u, v, w), Add(v, u, -w);
}

bool vis[maxn], flag;
int E, dep[maxn];

#include <set>

std::set<int> DEP;
inline void DFS(int u, int d) {
	vis[u] = 1, dep[u] = d;
	if(u > n) {
		++E;
		if(DEP.count(d)) flag = 0;
		DEP.insert(d);
	}
	
	for(auto e : to[u]) {
		if(!vis[e.first]) DFS(e.first, d + e.second);
		else if(dep[e.first] != dep[u] + e.second) flag = 0;
	}
}

int main() {
	n = getll(), m = getll(), k = getll();
	for(int i = 1; i <= n; ++i) {
		int c = getll();
		for(int j = 1; j <= c; ++j)
			Adde(i, n + getll(), j);
	}
	
	std::vector<int> ele;
	for(int i = 1; i <= k; ++i) if(!vis[n + i]) {
		DEP.clear(), E = 0, flag = 1, DFS(n + i, 0);
		if(flag) ele.push_back(E);
	}
	
	poly F; F.redeg(std::max(k, m));
	for(int x : ele) ++F[x];
	putll((poly(1) - F).inv()[m]), IObuf::flush();
}
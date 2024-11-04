



__attribute__((destructor))
inline void ptime() {
	nya("\nTime: %.3lf(s)\n", 1. * clock() / CLOCKS_PER_SEC);
}

using ll = long long;
using vec = std::vector<ll>;
constexpr ll mod = 998244353, gen = 3;
constexpr ll inv2 = mod + 1 >> 1;

namespace IObuf {
	using IObuf_t = int;

	constexpr int LEN = 1 << 20;
	
	char ibuf[LEN + 5], *p1 = ibuf, *p2 = ibuf;
	char obuf[LEN + 5], *p3 = obuf;
	
	inline char get() {

		return getchar();

		return p1 == p2 && (p2 = (p1 = ibuf) + fread(ibuf, 1, LEN, stdin), p1 == p2) ? EOF : *p1++;

	}
	
	inline IObuf_t getint(char c = get(), IObuf_t x = 0, IObuf_t op = 1) {
		while(c < '0' || c > '9') c == '-' && (op = -op), c = get();
		while(c >= '0' && c <= '9') x = x * 10 + c - 48, c = get();
		return x * op;
	}
	
	__attribute__((destructor))
	inline char* flush() { fwrite(obuf, 1, p3 - obuf, stdout); return p3 = obuf; }
	inline void put(char c) {

		putchar(c);

		p3 == obuf + LEN && flush(); *p3++ = c; return;

	}
	
	char sta[30]; int top = 0;
	inline void putint(IObuf_t x, char suf = '\n') {
		if(x < 0) put('-'), x = -x;
		if(!x) put('0');
		else {
			while(x) sta[++top] = x % 10 + 48, x /= 10;
			while(top) put(sta[top--]);
		} put(suf);
	}

	inline void putstr(const char *s, char suf = '\n') {
		while(*s != '\0') put(*s++);
		put(suf);
	}
} 

using IObuf::getint;
using IObuf::putint;
using IObuf::putstr;

inline ll fsp(ll a, ll b, ll res = 1) {
	for(a %= mod; b; a = a * a % mod, b >>= 1)
		b & 1 ? res = res * a % mod : 0; return res;
}

namespace Math {
	int L = -1;
	
	vec _Fac, _Inv, _inv;
	inline void pre(int l) {
		if(L == -1) {
			_Fac = _Inv = { 1, 1 };
			_inv = { 0, 1 }, L = 1;
		}
		if(L >= l) return;
		
		for(int i = L + 1; i <= l; ++i) {
			_inv.push_back(_inv[mod % i] * (mod - mod / i) % mod);
			_Fac.push_back(_Fac[i - 1] * i % mod);
			_Inv.push_back(_Inv[i - 1] * _inv[i] % mod);
		}
		L = l;
	}
	
	inline ll Fac(int n) { return pre(n), _Fac[n]; }
	inline ll Inv(int n) { return pre(n), _Inv[n]; }
	inline ll inv(int n) { return pre(n), _inv[n]; }
	inline ll binom(int n, int k) {
		if(k < 0 || n < k) return 0;
		return Fac(n) * Inv(k) % mod * Inv(n - k) % mod;
	}
	
	inline ll sgn(int x) { return x & 1 ? mod - 1 : 1; }
} 


namespace Poly {
	inline constexpr ll Add(ll x, ll y) { return x + y >= mod ? x + y - mod : x + y; }
	inline constexpr ll Sub(ll x, ll y) { return x < y ? x - y + mod : x - y; }
		
	struct poly {
		vec f;
		
		

		
		inline poly(ll v = 0) : f() { if(v) f.push_back(v); }
		inline poly(const vec &_f) : f(_f) {}
		inline poly(std::initializer_list<ll> init) : f(init) {}
		
		

		
		inline ll operator[](int p) const { return f[p]; }
		inline ll &operator[](int p) { return f[p]; }
		
		inline int deg() const { return f.size() - 1; }
		inline void redeg(int d) { f.resize(d + 1); }
		
		inline poly slice(int d) const {
			if(d < f.size()) return vec(f.begin(), f.begin() + d + 1);
			
			vec res(f);
			return res.resize(d + 1), res;
		}
	
		inline void print(int d = -1) const {
			if(d == -1) d = deg();
			for(int i = 0; i <= d && i < f.size(); ++i) putint(f[i], ' ');
			for(int i = f.size(); i <= d; ++i) putint(0, ' ');
			IObuf::put('\n');
		}
		
		inline ll calc(ll x) const {
			ll res = 0, tmp = 1;
			for(int i = 0; i <= deg(); ++i) {
				res = (res + f[i] * tmp) % mod;
				tmp = tmp * x % mod;
			} return res;
		}

		inline poly shift() const {
			poly res(f);
			while(!res.f.empty() && !res.f.back()) res.f.pop_back();
			return res;
		}

		

		
		inline poly operator+(const poly &P) const {
			vec res(std::max(deg(), P.deg()) + 1);
			
			for(int i = std::min(deg(), P.deg()); i >= 0; --i) res[i] = Add(f[i], P[i]);
			for(int i = std::min(deg(), P.deg()) + 1; i < res.size(); ++i) res[i] = i <= deg() ? f[i] : P[i];
			return res;
		}
		
		inline poly operator-() const {
			poly res(f);
			for(int i = 0; i < f.size(); ++i) res[i] = Sub(0, res[i]);
			return res;
		}
		
		inline poly operator-(const poly &P) const { return operator+(-P); }
		
		inline poly operator<<(int d) const {
			poly res; res.redeg(d + deg());
			for(int i = 0; i <= deg(); ++i) res[i + d] = f[i];
			return res;
		}
		
		inline poly operator>>(int d) const {
			if(d > deg()) return poly(0);
			return vec(f.begin() + d, f.end());
		}
		
		inline poly operator*(ll v) const {
			v = (v % mod + mod) % mod;
			
			poly res(f);
			for(int i = 0; i <= deg(); ++i) res[i] = res[i] * v % mod;
			return res;
		}

		inline poly operator*(ll (*fun)(int)) const {
			poly res(f);
			for(int i = 0; i <= deg(); ++i) res[i] = res[i] * fun(i) % mod;
			return res;
		}
		
		inline poly operator*(const poly &P) const;				

		inline poly mul(const poly &P) const;					

		inline poly inv() const;
	};
	
	namespace NTT_namespace {
		
		
		constexpr int rank2 = ctz(mod - 1);

		ll root[rank2 + 1];   

		ll iroot[rank2 + 1];  

		ll rate2[rank2], irate2[rank2];
		ll rate3[rank2], irate3[rank2];

		__attribute__((constructor))
		inline void id0() {
			root[rank2] = fsp(gen, mod - 1 >> rank2);
			iroot[rank2] = fsp(root[rank2], mod - 2);
			for(int i = rank2 - 1; i >= 0; --i) {
				root[i] = root[i + 1] * root[i + 1] % mod;
				iroot[i] = iroot[i + 1] * iroot[i + 1] % mod;
			}

			{
				ll prod = 1, iprod = 1;
				for (int i = 0; i <= rank2 - 2; i++) {
					rate2[i] = root[i + 2] * prod % mod;
					irate2[i] = iroot[i + 2] * iprod % mod;
					prod = prod * iroot[i + 2] % mod;
					iprod = iprod * root[i + 2] % mod;
				}
			}

			{
				ll prod = 1, iprod = 1;
				for(int i = 0; i <= rank2 - 3; i++) {
					rate3[i] = root[i + 3] * prod % mod;
					irate3[i] = iroot[i + 3] * iprod % mod;
					prod = prod * iroot[i + 3] % mod;
					iprod = iprod * root[i + 3] % mod;
				}
			}
		}
		
		inline void id1(poly &a, int h) {
			if(a.deg() < (1 << h) - 1) a.redeg((1 << h) - 1);

			int len = 0;  

			while(len < h) {
				if(h - len == 1) {
					int p = 1 << (h - len - 1);
					
					ll rot = 1;
					for(int s = 0; s < (1 << len); ++s) {
						int offset = s << (h - len);
						for(int i = 0; i < p; ++i) {
							ll l = a[i + offset];
							ll r = a[i + offset + p] * rot % mod;
							a[i + offset] = Add(l, r);
							a[i + offset + p] = Sub(l, r);
						}
						if(s + 1 != (1 << len))
							rot = rot * rate2[ctz(~(unsigned int)(s))] % mod;
					}
					++len;
				} else {
					

					int p = 1 << (h - len - 2);
					ll rot = 1, imag = root[2];
					for(int s = 0; s < (1 << len); ++s) {
						ll rot2 = rot * rot % mod;
						ll rot3 = rot2 * rot % mod;
						int offset = s << (h - len);
						for(int i = 0; i < p; ++i) {
							ll mod2 = mod * mod;
							ll a0 = a[i + offset + 0 * p];
							ll a1 = a[i + offset + 1 * p] * rot;
							ll a2 = a[i + offset + 2 * p] * rot2;
							ll a3 = a[i + offset + 3 * p] * rot3;
							ll id4 = (a1 + mod2 - a3) % mod * imag;
							ll na2 = mod2 - a2;

							a[i + offset] = (a0 + a2 + a1 + a3) % mod;
							a[i + offset + 1 * p] = (a0 + a2 + (2 * mod2 - (a1 + a3))) % mod;
							a[i + offset + 2 * p] = (a0 + na2 + id4) % mod;
							a[i + offset + 3 * p] = (a0 + na2 + (mod2 - id4)) % mod;
						}
						if(s + 1 != (1 << len))
							rot = rot * rate3[ctz(~(unsigned int)(s))] % mod;
					}
					len += 2;
				}
			}
		}
		
		inline void id7(poly &a, int h) {
			if(a.deg() < (1 << h) - 1) a.redeg((1 << h) - 1);

			int len = h;  

			while(len) {
				if(len == 1) {
					int p = 1 << (h - len);
					
					ll irot = 1;
					for(int s = 0; s < (1 << (len - 1)); ++s) {
						int offset = s << (h - len + 1);
						for(int i = 0; i < p; ++i) {
							ll l = a[i + offset];
							ll r = a[i + offset + p];
							a[i + offset] = Add(l, r);
							a[i + offset + p] = Sub(l, r) * irot % mod;
						}
						if (s + 1 != (1 << (len - 1)))
							irot = irot * irate2[ctz(~(unsigned int)(s))] % mod;
					}
					--len;
				} else {
					

					int p = 1 << (h - len);
					ll irot = 1, iimag = iroot[2];
					for(int s = 0; s < (1 << (len - 2)); ++s) {
						ll id6 = irot * irot % mod;
						ll id5 = id6 * irot % mod;
						int offset = s << (h - len + 2);
						for(int i = 0; i < p; ++i) {
							ll a0 = a[i + offset + 0 * p];
							ll a1 = a[i + offset + 1 * p];
							ll a2 = a[i + offset + 2 * p];
							ll a3 = a[i + offset + 3 * p];
							ll id2 = Sub(a2, a3) * iimag % mod;
		
							a[i + offset] = (a0 + a1 + a2 + a3) % mod;
							a[i + offset + 1 * p] = (a0 + (mod - a1) + id2) * irot % mod;
							a[i + offset + 2 * p] = (a0 + a1 + (mod - a2) + (mod - a3)) * id6 % mod;
							a[i + offset + 3 * p] = (a0 + (mod - a1) + (mod - id2)) * id5 % mod;
						}
						if(s + 1 != (1 << (len - 2)))
							irot = irot * irate3[ctz(~(unsigned int)(s))] % mod;
					}
					len -= 2;
				}
			}
			
			int N = 1 << h;
			
			ll invN = fsp(N, mod - 2);
			for(int i = 0; i < N; ++i) a[i] = a[i] * invN % mod;
		}
		
		inline void NTT(poly &f, int bit, int op) {
			if(op == 1) id1(f, bit);
			else id7(f, bit);
		}

		
	} 

	using NTT_namespace::NTT;
	
	bool id8 = 0;
	inline poly poly::operator*(const poly &P) const {
		if(deg() == -1 || P.deg() == -1) return {};
		if(std::max(deg(), P.deg()) <= 128) {
			poly res; res.redeg(deg() + P.deg());
			for(int i = 0; i <= deg(); ++i)
				for(int j = 0; j <= P.deg(); ++j)
					(res[i + j] += f[i] * P[j]) %= mod;
			
			if(!id8) res.redeg(std::max(deg(), P.deg()));
			return res;
		}
		
		poly F(f), G = P;
		
		int bit = 0, N = 1;
        while(N <= F.deg() + G.deg()) ++bit, N <<= 1;
		
		NTT(F, bit, 1), NTT(G, bit, 1);
		for(int i = 0; i < N; ++i)
			F[i] = F[i] * G[i] % mod;
		NTT(F, bit, -1);
		
		if(!id8) return F.slice(std::max(deg(), P.deg()));
		else return F.slice(deg() + P.deg());
	}
	
	inline poly poly::mul(const poly &P) const {
		id8 = 1; poly H = operator*(P);
		return id8 = 0, H;
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
} 

using Poly::poly;

inline poly MUL(poly F, poly G) {
	std::reverse(G.f.begin(), G.f.end());
	return F.mul(G) >> G.deg();
}

inline poly id3(poly F, poly G) {
	std::reverse(G.f.begin(), G.f.end());
	int tmp = G.deg();
	
	int bit = 0, N = 1;
    while(N <= F.deg()) ++bit, N <<= 1;
    
    F.redeg(N), G.redeg(N);
	
	NTT(F, bit, 1), NTT(G, bit, 1);
	for(int i = 0; i < N; ++i)
		F[i] = F[i] * G[i] % mod;
	NTT(F, bit, -1);
	return F >> tmp;
}

constexpr int maxn = 1E+5 + 5;

int n, k; ll p, a[maxn], b[maxn];
namespace Eval {




	poly P[maxn << 2];
	inline void pre(int u = 1, int lef = 0, int rig = k) {
		if(lef == rig) return P[u] = { 1, (mod - a[lef] - 1) % mod }, void();
		pre(ls, lef, mid), pre(rs, mid + 1, rig), P[u] = P[ls].mul(P[rs]);
	}
	
	inline void Work(poly A, int u = 1, int lef = 0, int rig = k) {
		A.redeg(P[u].deg() - 1);
		if(lef == rig) return b[lef] = A[0], void();
		Work(id3(A, P[rs]), ls, lef, mid);
		Work(id3(A, P[ls]), rs, mid + 1, rig);
	}




}

inline void getb() {
	poly F; F.redeg(k);
	for(int i = 0; i <= k; ++i)
		F[i] = Math::Inv(i) * p % mod;
	--F[0], F = F.inv();

	poly G; G.redeg(k);
	for(int i = 0; i <= k; ++i)
		G[i] = Math::Inv(i) * F[k - i] % mod;
	G = G * Math::Fac(k);

	if(k < n) G.redeg(n), k = n;
	Eval::pre(), Eval::Work(MUL(G, Eval::P[1].inv()));
	for(int i = 1; i <= n; ++i)
		b[i] = (fsp(p, a[i] + 1, b[i]) - G[0]) % mod;
}

ll F[maxn], G[maxn];
ll pre[maxn], suf[maxn], coef[maxn];
int main() {
	n = getint(), k = getint(), p = getint();
	for(int i = 1; i <= n; ++i) a[i] = getint();
	getb();

	F[0] = 1;
	for(int i = 1; i <= n; ++i) F[i] = F[i - 1] * (a[i] + 1) % mod;
	for(int i = 0; i <= n; ++i) G[i] = fsp(F[i], mod - 2);
	for(int i = 1; i <= n; ++i) G[i] = (G[i - 1] + G[i]) % mod;
	for(int i = n - 1; i >= 0; --i) F[i] = (F[i + 1] + F[i]) % mod;

	for(int i = 1; i <= n; ++i) pre[i] = (pre[i - 1] + G[i - 1] * fsp(a[i] + 1, mod - 2, a[i])) % mod;
	for(int i = n; i >= 1; --i) suf[i] = (suf[i + 1] + F[i] * fsp(a[i] + 1, mod - 2, a[i])) % mod;

	for(int i = 1; i <= n; ++i) {
		(coef[i] += G[i - 1] * suf[i + 1]) %= mod;
		(coef[i] += F[i] * pre[i - 1]) %= mod;
		(coef[i] += G[i - 1] * F[i]) %= mod;
		coef[i] = coef[i] * fsp(a[i] + 1, mod - 2) % mod;
	}

	ll ans = 0;
	for(int i = 1; i <= n; ++i)
		(ans += b[i] * coef[i]) %= mod;
	putint((ans + mod) % mod);
}
#ifdef _MSC_VER
#define _CRT_SECURE_NO_DEPRECATE
#pragma comment(linker, "/STACK:66777216")
#include <cstdio>
#define GETS gets_s
#else
#pragma GCC optimize("O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")
#include <stdio.h>
#define GETS gets
#endif
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <vector>
#include <queue>
#include <iostream>
#include <iterator>
#include <cmath>
#include <cstdlib>
#include <sstream>
#include <fstream>
#include <ctime>
#include <cstring>
#include <functional>
#include <chrono>
using namespace std;
#define pb push_back
#define ppb pop_back
#define pi 3.1415926535897932384626433832795028841971
#define mp make_pair
#define x first
#define y second
#define pii pair<int,int>
#define pddd pair<double,double>
#define INF 1000000000
#define FOR(i,a,b) for (int _n(b), i(a); i <= _n; i++)
#define FORD(i,a,b) for(int i=(a),_b=(b);i>=_b;i--)
#define all(c) (c).begin(), (c).end()
#define SORT(c) sort(all(c))
#define rep(i,n) FOR(i,1,(n))
#define rept(i,n) FOR(i,0,(n)-1)
#define L(s) (int)((s).size())
#define C(a) memset((a),0,sizeof(a))
#define VI vector <int>
#define ll long long
#define MOD 1000000007

const ll modll = (ll)MOD << 32;


struct pdd {
	double x, y;
	pdd() :x(0), y(0) {}
	pdd(double _x, double _y) :x(_x), y(_y) {}
};
inline pdd operator +(const pdd &a, const pdd &b) {
	return pdd(a.x + b.x, a.y + b.y);
}
inline pdd operator -(const pdd &a, const pdd &b) {
	return pdd(a.x - b.x, a.y - b.y);
}
inline pdd operator *(const pdd &a, const pdd &b) {
	return pdd(a.x*b.x - a.y*b.y, a.x*b.y + a.y*b.x);
}
inline pdd operator /(const pdd &a, const double &b) {
	return pdd(a.x / b, a.y / b);
}
inline pdd conj(const pdd &a) {
	return pdd(a.x, -a.y);
}
int rv[1 << 14];
pdd w[1 << 14];
pdd tmp[1 << 14];
void fft(pdd *a, int n, bool inv) {
	static int SN = -1;
	int cc = 0;
	rept(i, 30) {
		if (n & 1 << i) cc = i;
	}
	if (cc != SN) {
		SN = cc;
		rv[0] = 0; rv[1] = 1;
		rep(st, SN - 1) {
			int k = 1 << st;
			rept(i, k) {
				rv[i + k] = rv[i] * 2 + 1;
				rv[i] *= 2;
			}
		}
		rept(i, 1 << SN) {
			w[i] = pdd(cos(2.0 * pi * i / n), sin(2.0 * pi * i / n));
		}
	}
	rept(i, n) {
		if (rv[i] <= i) swap(a[i], a[rv[i]]);
	}
	for (int st = 2; st <= n; st *= 2) {
		int d = n / st, o = st / 2;
		for (int j = 0; j < o; ++j) {
			tmp[j] = inv ? conj(w[j * d]) : w[j * d];
		}
		for (int i = 0; i<n; i += st) {
			for (int j = 0; j < o; ++j) {
				pdd u = a[i + j], v = a[i + j + o] * tmp[j];
				a[i + j] = u + v;
				a[i + j + o] = u - v;
			}
		}
	}
	if (inv) {
		rept(i, n) a[i] = a[i] / n;
	}
}

void fft_unpack(pdd* z, pdd* x, pdd* y, int n) {
	for (int i = 1; i < n; ++i) {
		x[i] = (z[i] + conj(z[n - i])) / 2;
		y[i] = (z[i] - conj(z[n - i])) / 2;
		swap(y[i].x, y[i].y);
		y[i].y = -y[i].y;
	}
	x[0] = (z[0] + conj(z[0])) / 2;
	y[0] = (z[0] - conj(z[0])) / 2;
	swap(y[0].x, y[0].y);
	y[0].y = -y[0].y;
}

void fft_pack(pdd* x, pdd* y, pdd* z, int n) {
	for (int i = 1; i < n; ++i) {
		z[i] = x[i] + y[i] * pdd(0, 1);
		z[n - i] = conj(x[i] - y[i] * pdd(0, 1));
	}
	z[0].x = x[0].x;
	z[0].y = y[0].x;
}



const int N = 1 << 15;
pdd A0[N + 1], A1[N + 1], A2[N + 1], A3[N + 1], A4[N + 1];
void fft_mul(int *a, int *b, int *ans, int n, bool cp = 0) {
	memset(A0, 0, 2 * n * sizeof(pdd));
	memset(A1, 0, 2 * n * sizeof(pdd));
	memset(A2, 0, 2 * n * sizeof(pdd));
	memset(A3, 0, 2 * n * sizeof(pdd));
	memset(A4, 0, 2 * n * sizeof(pdd));
	const int p = (int)ceil(sqrt((double)MOD)) + 1;
	rept(i, n) {
		A0[i].x = a[i] % p;
		A0[i].y = a[i] / p;
		A1[i].x = b[i] % p;
		A1[i].y = b[i] / p;
	}
	fft(A0, 2 * n, 0);
	if (!cp) {
		fft(A1, 2 * n, 0);
	}

	fft_unpack(A0, A2, A3, 2 * n);
	if (!cp) {
		fft_unpack(A1, A0, A4, 2 * n);
	}
	else {
		rept(i, 2 * n) {
			A0[i] = A2[i];
			A4[i] = A3[i];
			A1[i] = A0[i];
		}
	}
	const int pp = (ll)p * p % MOD;
	rept(i, 2 * n) {
		auto old = A0[i];
		A0[i] = A2[i] * old;
		A1[i] = A3[i] * A4[i];
		A3[i] = A2[i] * A4[i] + old * A3[i];
	}
	fft_pack(A0, A1, A2, 2 * n);
	fft(A2, 2 * n, 1);
	fft(A3, 2 * n, 1);
	rept(i, 2 * n) {
		ll x0 = (ll)(A2[i].x + 0.5);
		ll x1 = (ll)(A3[i].x + 0.5);
		ll x2 = (ll)(A2[i].y + 0.5);
		x1 %= MOD;
		x2 %= MOD;
		ll cur = ((ll)x0 + (ll)p * x1 + (ll)pp * x2) % MOD;
		if (cur < 0) cur += MOD;
		ans[i] = (int)cur;
	}
}

#include <intrin.h>



struct LinearReqSolver {
	static const int mod = MOD;
	static int invmod(int x, int y) {
		int a = 1, b = 0, k;
		for (; y; swap(x, y), swap(a, b)) {
			k = x / y;
			x -= y * k;
			a -= b * k;
		}
		return a + max(b, 0);
	}

	

	void reset(vector<ll> _s) {
		s = std::move(_s);
		rept(i, L(s)) {
			s[i] %= mod;
			if (s[i] < 0) s[i] += mod;
		}
		c.resize(1); c[0] = 1;
		vector<ll> b(1, 1);
		int L = 0, m = 1, lastD = 1;
		rept(n, L(s)) {
			ll d = 0;
			rept(i, L + 1) {
				c[i] %= mod;
				d += (ll)c[i] * s[n - i];
				if (d >= modll) d -= modll;
			}
			d %= mod;
			if (d) {
				int invLastD = (mod - (ll)d * invmod(lastD, mod)) % mod;
				if (invLastD < 0) invLastD += mod;
				if (2 * L <= n) {
					vector<ll> t = c;
					if (L(c) < L(b) + m) c.resize(L(b) + m);
					
					__m128i A = _mm_set_epi32(0, invLastD, 0, invLastD);
					int nn = L(b);
					if (nn % 2) --nn;
					for (int i = 0; i < nn; i += 2) {
						__m128i B = _mm_loadu_si128((__m128i*)(&b[0] + i));
						__m128i M = _mm_mul_epu32(A, B);
						__m128i R = _mm_loadu_si128((__m128i*)(&c[0] + m + i));
						R = _mm_add_epi64(R, M);
						_mm_storeu_si128((__m128i*)(&c[0] + m + i), R);
						

						

					}
					if (L(b) % 2) {
						addll(c[L(b) - 1 + m], (ll)invLastD * b.back());
					}
					L = n + 1 - L; b = t; lastD = d; m = 0;
				}
				else {
					if (L(c) < L(b) + m) c.resize(L(b) + m);
					

					__m128i A = _mm_set_epi32(0, invLastD, 0, invLastD);
					int nn = L(b);
					if (nn % 2) --nn;
					for (int i = 0; i < nn; i += 2) {
						__m128i B = _mm_loadu_si128((__m128i*)(&b[0] + i));
						__m128i M = _mm_mul_epu32(A, B);
						__m128i R = _mm_loadu_si128((__m128i*)(&c[0] + m + i));
						R = _mm_add_epi64(R, M);
						_mm_storeu_si128((__m128i*)(&c[0] + m + i), R);
						

						

					}
					if (L(b) % 2) {
						addll(c[L(b) - 1 + m], (ll)invLastD * b.back());
					}
				}
			}
			++m;
		}
		rept(i, L(c)) {
			c[i] %= mod;
			c[i] = mod - c[i];
			if (c[i] >= mod) c[i] -= mod;
		}
		rc = c;
		reverse(rc.begin(), rc.end());
		rc.back() = 1;
		nz_ind.clear();
		rept(i, L(rc) - 1) {
			if (rc[i]) {
				nz_ind.pb(i);
			}
		}
		c.erase(c.begin());
	}

	inline void addll(ll &a, ll b) {
		a += b;
		if (a >= modll) a -= modll;
	}

	int ta[1 << 14], tb[1 << 14], tt[1 << 14];
	ll tc[1 << 14], te[1 << 14];

	void mul(vector<ll>& a, const vector<ll>& b, int k) {
		C(ta); C(tb); C(tt);
		rept(i, k) {
			ta[i] = a[i];
			tb[i] = b[i];
		}
		
		temp.resize(2 * k);
		rept(i, 2 * k) temp[i] = 0;
		fft_mul(ta, tb, tt, 1 << 13, 1);
		rept(i, 2 * k) {
			temp[i] = tt[i];
		}

		auto* prc = &rc[0];
		
		for (int i = 2 * k - 1; i >= k; --i) if (temp[i]) {
			temp[i] %= mod;

			memset(te + i, 0, k * sizeof(ll));

			__m128i A = _mm_set_epi32(0, temp[i], 0, temp[i]);
			for (int j = 0; j < L(rc); j += 2) {
				__m128i B = _mm_loadu_si128((__m128i*)(prc + j));
				__m128i M = _mm_mul_epu32(A, B);
				__m128i R = _mm_loadu_si128((__m128i*)(te + i + j));
				R = _mm_add_epi64(R, M);
				_mm_storeu_si128((__m128i*)(te + i + j), R);
				

				

			}
			rept(j, L(rc)) {
				addll(temp[i - k + j], te[i + j]);
			}
		}

		rept(i, k) {
			a[i] = temp[i] % mod;
			if (a[i] < 0) a[i] += mod;
		}
	}

	

	int gen(ll n) {
		int k = L(c);
		res.resize(k + 1);
		rept(i, k) res[i] = 0;
		res[0] = 1;
		int pnt = 0;
		while ((1LL << pnt) <= n) pnt++;
		for (int p = pnt; p >= 0; --p) {
			mul(res, res, k);
			if (n & 1LL << p) {
				for (int i = k - 1; i >= 0; --i) {
					res[i + 1] = res[i];
				}
				res[0] = 0;
				rept(j, L(nz_ind)) {
					res[nz_ind[j]] = (res[nz_ind[j]] + res[k] * rc[nz_ind[j]]) % mod;
					if (res[nz_ind[j]] < 0) res[nz_ind[j]] += mod;
				}
			}
		}
		int ans = 0;
		rept(i, k) ans = (ans + res[i] * s[i]) % mod;
		if (ans < 0) ans += mod;
		return ans;
	}

	vector<ll> s; 

	vector<ll> c; 


		  

	vector<ll> rc; 

	VI nz_ind; 

	vector<ll> res;
	vector<ll> temp;
};

int a, b, c, d, n, m, k;

int fac[10053], ifac[10053];
int pk[10053];

inline int fpow(int a, int st) {
	int ans = 1;
	while (st) {
		if (st % 2) ans = (ll)ans * a % MOD;
		a = (ll)a * a % MOD;
		st /= 2;
	}
	return ans;
}

int revmem[10050];
int brute(int n, int k) {
	ll ans = 0;

	ll nf = fac[n];
	rep(i, n) {
		ans += nf * revmem[i] % MOD * ifac[n - i];
		if (ans >= modll) ans -= modll;
	}
	return ans % MOD;
}

LinearReqSolver q;
int main() {
	

	



	scanf("%d%d", &n, &k);
	

	


	fac[0] = ifac[0] = 1;
	pk[0] = 0;
	rep(i, 10050) {
		fac[i] = (ll)fac[i - 1] * i % MOD;
		ifac[i] = fpow(fac[i], MOD - 2);
		pk[i] = fpow(i, k);
		revmem[i] = (ll)ifac[i] * pk[i] % MOD;
	}
	vector<ll> vec;
	rep(i, 2 * k + 2) {
		vec.pb(brute(i, k));
	}
	q.reset(vec);

	cout << q.gen(n - 1) << endl;



}

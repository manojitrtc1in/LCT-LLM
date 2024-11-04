#include <bits/stdc++.h>
using namespace std;


namespace io {
	const int BUFSIZE = 1 << 20;
	char ibuf[BUFSIZE], *is = ibuf, *it = ibuf;
	char obuf[BUFSIZE], *os = obuf, *ot = obuf + BUFSIZE - 1;
	char read_char() {
		if (is == it) {
			it = (is = ibuf) + fread(ibuf, 1, BUFSIZE, stdin);
			if (is == it) *it++ = -1;
		}
		return *is++;
	}
	int read_int() {
		int x = 0, f = 1;
		char c = read_char();
		while (!isdigit(c)) {
			if (c == '-') {
				f = -1;
			}
			c = read_char();
		}
		while (isdigit(c)) {
			x = x * 10 + c - '0';
			c = read_char();
		}
		return x * f;
	}
	void flush() {
		fwrite(obuf, 1, os - obuf, stdout);
		os = obuf;
	}
	void print_char(char c) {
		*os++ = c;
		if (os == ot) {
			flush();
		}
	}
	void print_int(int x) {
		static char q[10];
		if (!x) {
			print_char('0');
		} else {
			if (x < 0) {
				print_char('-');
				x = -x;
			}
			int top = 0;
			while (x) {
				q[top++] = x % 10 + '0';
				x /= 10;
			}
			while (top--) {
				print_char(q[top]);
			}
		}
	}
	struct flusher_t {
		~flusher_t() {
			flush();
		}
	} flusher;
}
using io::read_char;
using io::read_int;
using io::print_char;
using io::print_int;


const int N = 262144;
const int LOGN = 18;
const int mod = 998244353;
inline int quick_pow(int a, int b) {
	int res = 1;
	while (b) {
		if (b & 1)
			res = 1ll * res * a % mod;
		a = 1ll * a * a % mod;
		b >>= 1;
	}
	return res;
}
inline int inv(int a) {
	return quick_pow(a, mod - 2);
}
namespace Poly {
	typedef unsigned long long ull;
	const ull mod2 = 1ull * mod * mod;
	const int G = 3;
	int rev[N + 5];
	int W[2][N + 5], Inv[N + 5], w[N + 5];
	ull a[N + 5];
	inline void NTT(int n, int *b, int flag) {
		for (int i = 0; i < n; i++) a[i] = b[i];
		for (int i = 1; i < n; i++)
			if (rev[i] > i)
				swap(a[rev[i]], a[i]);
		int *ww = flag == 1 ? W[0] : W[1];
		for (int i = 2; i <= n; i <<= 1) {
			int i2 = i >> 1;
			for (int j = 0; j < i2; j++)
				w[j] = ww[N / i * j];
			for (int j = 0; j < n; j += i) {
				ull *p = a + j, *q = a + j + i2;
				int *t = w;
				for (int k = 0; k < i2; k++, p++, q++, t++) {
					ull x = *p, y = (*q) % mod * (*t);
					*p = x + y; *q = x + mod2 - y;
				}
			}
			if (i == (1 << 16)) for (int j = 0; j < n; j++) a[j] %= mod;
		}
		for (int i = 0; i < n; i++) b[i] = a[i] % mod;
		if (flag == -1) {
			int t = inv(n);
			for (int i = 0; i < n; i++)
				b[i] = 1ll * b[i] * t % mod;
		}
	}
	int mult_ta[N + 5], mult_tb[N + 5];
	inline void init_NTT() {
		int x = quick_pow(G, (mod - 1) / N);
		W[0][0] = 1;
		for (int i = 1; i < N; i++) {
			W[0][i] = 1ll * W[0][i - 1] * x % mod;
		}
		x = inv(x);
		W[1][0] = 1;
		for (int i = 1; i < N; i++) {
			W[1][i] = 1ll * W[1][i - 1] * x % mod;
		}
		Inv[1] = 1;
		for (int i = 2; i < N; i++)
			Inv[i] = 1ll * (mod - mod / i) * Inv[mod % i] % mod;
	}
	inline void pre_NTT(int n) {
		int cnt;
		for (cnt = 0; (1 << cnt) < n; cnt++);
		for (int i = 1; i < n; i++)
			rev[i] = ((rev[i >> 1] >> 1) | ((i & 1) << (cnt - 1)));
	}
	inline void poly_mult(int n, int *a, int m, int *b, int *res) { 

		int len;
		for (len = 1; len <= n + m; len <<= 1);
		pre_NTT(len);
		for (int i = 0; i < n; i++) mult_ta[i] = a[i];
		for (int i = 0; i < m; i++) mult_tb[i] = b[i];
		for (int i = n; i < len; i++) mult_ta[i] = 0;
		for (int i = m; i < len; i++) mult_tb[i] = 0;
		NTT(len, mult_ta, 1);
		NTT(len, mult_tb, 1);
		for (int i = 0; i < len; i++) mult_ta[i] = 1ll * mult_ta[i] * mult_tb[i] % mod;
		NTT(len, mult_ta, -1);
		for (int i = 0; i < n + m - 1; i++) res[i] = mult_ta[i];
	}
	int inv_ta[N + 5];
	void poly_inv(int n, int *a, int *b) { 

		if (n == 1) {b[0] = inv(a[0]); b[1] = 0; return;}
		poly_inv((n + 1) >> 1, a, b);
		int len;
		for (len = 1; len <= n + n; len <<= 1);
		pre_NTT(len);
		for (int i = 0; i < n; i++) inv_ta[i] = a[i];
		for (int i = n; i < len; i++) inv_ta[i] = b[i] = 0;
		NTT(len, inv_ta, 1);
		NTT(len, b, 1);
		for (int i = 0; i < len; i++)
			b[i] = (2ll - 1ll * inv_ta[i] * b[i] % mod + mod) % mod * b[i] % mod;
		NTT(len, b, -1);
		for (int i = n; i < len; i++) b[i] = 0;
	}
	int div_ra[N + 5], div_rb[N + 5];
	inline int poly_div(int n, int *a, int m, int *b, int *p, int *q) { 

		for (; n > 1 && !a[n - 1]; n--);
		for (; m > 1 && !b[m - 1]; m--);
		if (n < m) {
			p[0] = 0;
			for (int i = 0; i < n; i++) q[i] = a[i];
			for (int i = n; i < m - 1; i++) q[i] = 0;
			return 1;
		}
		reverse_copy(a, a + n, div_ra);
		reverse_copy(b, b + m, div_rb);
		for (int i = m; i < n - m + 1; i++) div_rb[i] = 0;
		poly_inv(n - m + 1, div_rb, p);
		poly_mult(n - m + 1, p, n, div_ra, p);
		reverse(p, p + n - m + 1);
		poly_mult(n - m + 1, p, m, b, q);
		for (int i = 0; i < n; i++) {
			q[i] = a[i] - q[i];
			if (q[i] < 0) q[i] += mod;
		}
		return n - m + 1;
	}
	inline int poly_div(int n, int *a, int m, int *b, int *p) { 

		for (; n > 1 && !a[n - 1]; n--);
		for (; m > 1 && !b[m - 1]; m--);
		if (n < m) {
			p[0] = 0;
			return 1;
		}
		reverse_copy(a, a + n, div_ra);
		reverse_copy(b, b + m, div_rb);
		for (int i = m; i < n - m + 1; i++) div_rb[i] = 0;
		poly_inv(n - m + 1, div_rb, p);
		poly_mult(n - m + 1, p, n, div_ra, p);
		reverse(p, p + n - m + 1);
		return n - m + 1;
	}
	inline void poly_mod(int n, int *a, int m, int *b, int *q) { 

		for (; n > 1 && !a[n - 1]; n--);
		for (; m > 1 && !b[m - 1]; m--);
		int len = poly_div(n, a, m, b, q);
		poly_mult(len, q, m, b, q);
		for (int i = 0; i < n; i++) {
			q[i] = a[i] - q[i];
			if (q[i] < 0) q[i] += mod;
		}
	}
	int sqrt_tb[N + 5];
	void poly_sqrt(int n, int *a, int *b) { 

		if (n == 1) {b[0] = 1; b[1] = 0; return;}
		poly_sqrt((n + 1) >> 1, a, b);
		poly_inv(n, b, sqrt_tb);
		poly_mult(n, a, n, sqrt_tb, sqrt_tb);
		int inv2 = ((mod + 1) >> 1);
		for (int i = 0; i < n; i++) b[i] = 1ll * (b[i] + sqrt_tb[i]) * inv2 % mod;
		for (int i = n; i < (n << 1); i++) b[i] = 0;
	}
	inline void poly_der(int n, int *a, int *b) {
		for (int i = 0; i < n - 1; i++)
			b[i] = 1ll * a[i + 1] * (i + 1) % mod;
		b[n - 1] = 0;
	}
	inline void poly_int(int n, int *a, int *b) {
		for (int i = n; i >= 1; i--)
			b[i] = 1ll * a[i - 1] * Inv[i] % mod;
		b[0] = 0;
	}
	void eval_CDQ(int l, int r, int d, int *a, int store[][N + 5]) {
		if (l == r) {
			store[d][2 * l] = -a[l];
			if (store[d][2 * l] < 0) store[d][2 * l] += mod;
			store[d][2 * l + 1] = 1;
			return;
		}
		int mid = (l + r) >> 1;
		eval_CDQ(l, mid, d + 1, a, store);
		eval_CDQ(mid + 1, r, d + 1, a, store);
		poly_mult(mid - l + 2, &store[d + 1][l * 2], r - mid + 1, &store[d + 1][(mid + 1) * 2], &store[d][l * 2]);
	}
	void eval_calc(int n, int *a, int l, int r, int d, int store[][N + 5], int rem[][N + 5], int *res) {
		poly_mod(n, a, r - l + 2, &store[d][l * 2], &rem[d][l]);
		if (l == r) {
			res[l] = rem[d][l];
			return;
		}
		int mid = (l + r) >> 1;
		eval_calc(r - l + 1, &rem[d][l], l, mid, d + 1, store, rem, res);
		eval_calc(r - l + 1, &rem[d][l], mid + 1, r, d + 1, store, rem, res);
	}
	int store[LOGN][N + 5], rem[LOGN][N + 5];
	inline void poly_eval(int n, int *a, int m, int *b, int *res) {
		eval_CDQ(0, m - 1, 0, b, store);
		eval_calc(n, a, 0, m - 1, 0, store, rem, res);
	}
	void intp_calc(int n, int *val, int l, int r, int d, int store[][N + 5], int tmp[][N + 5]) {
		if (l == r) {
			tmp[d][l] = val[l];
			return;
		}
		int mid = (l + r) >> 1;
		intp_calc(n, val, l, mid, d + 1, store, tmp);
		intp_calc(n, val, mid + 1, r, d + 1, store, tmp);
		poly_mult(mid - l + 1, &tmp[d + 1][l], r - mid + 1, &store[d + 1][(mid + 1) * 2], &tmp[d][l]);
		poly_mult(r - mid, &tmp[d + 1][mid + 1], mid - l + 2, &store[d + 1][l * 2], &tmp[d + 1][l]);
		for (int i = l; i <= r; i++) {
			tmp[d][i] = tmp[d][i] + tmp[d + 1][i];
			if (tmp[d][i] >= mod) tmp[d][i] -= mod;
		}
	}
	int der[N + 5], val[N + 5];
	inline void poly_intp(int n, int *x, int *y, int *res) {
		eval_CDQ(0, n - 1, 0, x, store);
		poly_der(n + 1, store[0], der);
		eval_calc(n, der, 0, n - 1, 0, store, rem, val);
		for (int i = 0; i < n; i++) val[i] = 1ll * inv(val[i]) * y[i] % mod;
		intp_calc(n, val, 0, n - 1, 0, store, rem);
		for (int i = 0; i < n; i++) res[i] = rem[0][i];
	}
	int ln_ta[N];
	inline void poly_ln(int n, int *a, int *b) {
		poly_inv(n, a, b);
		poly_der(n, a, ln_ta);
		poly_mult(n, b, n - 1, ln_ta, ln_ta);
		poly_int(n - 1, ln_ta, b);
	}
	int exp_tb[N];
	void poly_exp(int n, int *a, int *b) {
		if (n == 1) {b[0] = 1; b[1] = 0; return;}
		poly_exp((n + 1) >> 1, a, b);
		poly_ln(n, b, exp_tb);
		for (int i = 0; i < n; i++) {
			exp_tb[i] = mod - exp_tb[i] + a[i];
			if (exp_tb[i] >= mod) exp_tb[i] -= mod;
		}
		exp_tb[0]++; if(exp_tb[0] >= mod) exp_tb[0] -= mod;
		poly_mult(n, b, n, exp_tb, b);
		for (int i = n; i < (n << 1); i++) b[i] = 0;
	}
	int pow_ta[N], pow_tb[N];
	inline void poly_pow(int n, int *a, int m, int *b) {
		if (!m) {
			for (int i = 1; i < n; i++) b[i] = 0;
			b[0] = 1;
			return;
		}
		int p = 0;
		while (p < n && !a[p]) p++;
		if (1ll * p * m >= n) {
			for (int i = 0; i < n; i++) b[i] = 0;
			return;
		}
		int INV = inv(a[p]);
		int len = n - p * m;
		for (int i = 0; i < len; i++) pow_ta[i] = 1ll * a[i + p] * INV % mod;
		poly_ln(len, pow_ta, pow_tb);
		for (int i = 0; i < len; i++) pow_tb[i] = 1ll * pow_tb[i] * m % mod;
		poly_exp(len, pow_tb, b);
		INV = quick_pow(a[p], m);
		for (int i = n - 1; i >= p * m; i--)
			b[i] = 1ll * b[i - p * m] * INV % mod;
		for (int i = 0; i < p * m; i++)
			b[i] = 0;
	}
}
int n, m;
int a[N], b[N];
int main() {
#ifdef ztr
	freopen("D:\\input.txt", "r", stdin);
	

#endif
	Poly::init_NTT();
	n = read_int();
	m = read_int();
	while (n--) {
		int x = read_int();
		a[x] = mod - 4;
	}
	a[0] = 1;
	Poly::poly_sqrt(100001, a, b);
	b[0] = (b[0] + 1) % mod;
	Poly::poly_inv(100001, b, a);
	for (int i = 0; i < 100001; i++) a[i] = a[i] * 2 % mod;
	for (int i = 1; i <= m; i++) {
		print_int(a[i]);
		print_char('\n');
	}
	return 0;
}
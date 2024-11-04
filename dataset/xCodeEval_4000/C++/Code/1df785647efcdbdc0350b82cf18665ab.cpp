#include <bits/stdc++.h>

#define SZ(x) (int)(x).size()
#define ALL(x) (x).begin(), (x).end()
#define X first
#define Y second
#define pb push_back
#define mp make_pair

using namespace std;

const int maxn = 110, mod = 1e9 + 7;

template <int maxn, int proot, int mod> struct polynomial {
	int Inv[maxn], Fac[maxn], Ifac[maxn], inv2, *poly[maxn << 2], *poly2[maxn << 2], len[maxn << 2];

	inline int pow_mod(int x, int n) {
		int y = 1;
		while(n) {
			if(n & 1) {
				y = (long long) y * x % mod;
			}
			x = (long long) x * x % mod;
			n >>= 1;
		}
		return y;
	}

	polynomial() {
		inv2 = mod + 1 >> 1;
		int n = maxn - 1;
		Fac[0] = 1;
		for (int i = 1; i <= n; ++i) {
			Fac[i] = (long long) i * Fac[i - 1] % mod;
		}
		Ifac[n] = pow_mod(Fac[n], mod - 2);
		for (int i = n; i; --i) {
			Ifac[i - 1] = (long long) i * Ifac[i] % mod;
		}
		for (int i = 1; i <= n; ++i) {
			Inv[i] = (long long) Fac[i - 1] * Ifac[i] % mod;
		}
		return;
	}

	inline int lowbit(int n) {
		return n & (-n);
	}

	inline int getpw2(int n) {
		while(__builtin_popcount(n) != 1) {
			n += lowbit(n);
		}
		return n;
	}

	inline void cpy(int N, int *A, int n, int *a) {
		memcpy(A, a, sizeof(int) * n);
		memset(A + n, 0, sizeof(int) * (N - n));
		return;
	}

	inline void mul(int n, int *a, int m, int *b, int *c) {
		static int C[933];
		memset(C, 0, sizeof C);
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				C[i + j] = ((long long) a[i] * b[j] + C[i + j]) % mod;
			}
		}
		memcpy(c, C, sizeof(int) * (n + m - 1));
		return;
		
	}

	inline void add_mul(int n, int *a, int m, int *b, int *c) {
		static int C[933];
		memset(C, 0, sizeof C);
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				C[i + j] = ((long long) a[i] * b[j] + C[i + j]) % mod;
			}
		}
		for (int i = 0; i < n + m - 1; ++i) {
			c[i] = (c[i] + C[i]) % mod;
		}
		return;
		
	}

	inline void inv(int n, int *a, int *b) {
		int N = getpw2(n), *A = new int[N], *B = new int[N << 1], *C = new int[N << 1];
		cpy(N, A, n, a);
		memset(B, 0, sizeof(int) * (N << 1));
		B[0] = pow_mod(A[0], mod - 2);
		for (int hl = 1, l = 2, l2 = 4; l <= N; hl = l, l = l2, l2 <<= 1) {
			memcpy(C, A, sizeof(int) * l);
			memset(C + l, 0, sizeof(int) * l);
			mul(l, C, l, B, B);
			for (int i = 0; i < l; ++i) {
				B[i] = -B[i];
			}
			B[0] += 2;
			mul(l, B, l, B, B);
			memset(B + l, 0, sizeof(int) * l);
		}
		memcpy(b, B, sizeof(int) * n);
		delete A;
		delete B;
		delete C;
		return;
	}

	inline void der(int n, int *a, int *b) {
		for (int i = 0; i < n - 1; ++i) {
			b[i] = (long long) a[i + 1] * (i + 1) % mod;
		}
		return;
	}

	inline void ing(int n, int *a, int *b) {
		for (int i = n; i; --i) {
			b[i] = (long long) a[i - 1] * Inv[i] % mod;
		}
		b[0] = 0;
		return;
	}

	inline void log(int n, int *a, int *b) {
		int *A = new int[n], *B = new int[n], *C = new int[n << 1];
		memcpy(A, a, sizeof(int) * n);
		inv(n, A, B);
		der(n, A, A);
		mul(n, A, n, B, C);
		ing(n - 1, C, b);
		delete A;
		delete B;
		delete C;
		return;
	}

	inline void exp(int n, int *a, int *b) {
		int N = getpw2(n), *A = new int[N], *B = new int[N << 1], *C = new int[N << 1];
		cpy(N, A, n, a);
		memset(B, 0, sizeof(int) * (N << 1));
		B[0] = 1;
		for (int hl = 1, l = 2, l2 = 4; l <= N; hl = l, l = l2, l2 <<= 1) {
			log(l, B, C);
			for (register int i = 0; i < l; ++i) {
				C[i] = (A[i] - C[i]) % mod;
			}
			++C[0];
			memset(C + l, 0, sizeof(int) * l);
			mul(l, B, l, C, B);
			memset(B + l, 0, sizeof(int) * l);
		}
		memcpy(b, B, sizeof(int) * n);
		delete A;
		delete B;
		delete C;
		return;
	}

	inline void rev(int n, int *a) {
		for (int i = 0, j = n - 1; j > i; ++i, --j) {
			std::swap(a[i], a[j]);
		}
		return;
	}

	inline void div(int n, int *a, int m, int *b, int *d, int *r) {
		if(n < m) {
			memcpy(r, a, sizeof(int) * n);
			return;
		}
		int N = getpw2(n), k = n - m + 1, K = getpw2(k);
		static int A[maxn], B[maxn], C[maxn], D[maxn];
		cpy(N, A, n, a);
		cpy(N, B, m, b);
		rev(n, A);
		rev(m, B);
		inv(K, B, C);
		mul(k, A, k, C, D);
		rev(k, D);
		rev(n, A);
		rev(m, B);
		mul(m, B, k, D, C);
		for (int i = 0; i < n; ++i) {
			B[i] = (A[i] - C[i]) % mod;
		}
		memcpy(d, D, sizeof(int) * k);
		memcpy(r, B, sizeof(int) * (m - 1));
		return;
	}

	inline void pow(int n, int *a, int N, int *b) {
		memset(b, 0, sizeof(int) * n);
		if(!N) {
			b[0] = 1;
			return;
		}
		int i = 0;
		while(i < n && !a[i]) {
			++i;
		}
		if(i == n || (long long) i * N > n) {
			return;
		}
		int *A = new int[n];
		memset(A, 0, sizeof(int) * n);
		for (int j = i; j < n; ++j) {
			A[j - i] = a[j];
		}
		int t = A[0], it = pow_mod(t, mod - 2);
		for (int j = 0; j < n; ++j) {
			A[j] = (long long) A[j] * it % mod;
		}
		log(n, A, A);
		for (int j = 0; j < n; ++j) {
			A[j] = (long long) A[j] * N % mod;
		}
		exp(n, A, A);
		int base = i * N;
		t = pow_mod(t, N);
		for (int j = 0; j + base < n; ++j) {
			b[j + base] = (long long) A[j] * t % mod;
		}
		delete A;
		return;
	}

	inline int bf_eval(int n, int *a, int x) {
		int y = 0;
		for (int i = n - 1; ~i; --i) {
			y = ((long long) y * x + a[i]) % mod;
		}
		return y;
	}

	inline void eval_init(int l, int r, int k, int *x) {
		if(l == r) {
			poly[k] = new int[2];
			poly[k][0] = -x[l];
			poly[k][1] = 1;
			return;
		}
		int mid = l + r >> 1;
		eval_init(l, mid, k << 1, x);
		eval_init(mid + 1, r, (k << 1) | 1, x);
		poly[k] = new int[r - l + 2];
		mul(mid - l + 2, poly[k << 1], r - (mid + 1) + 2, poly[(k << 1) | 1], poly[k]);
		return;
	}

	inline void eval(int n, int *a, int l, int r, int k, int *x, int *y) {
		if((long long) n * (r - l + 1) <= 20000 || n <= 10 || (r - l + 1) <= 10) {
			for (int i = l; i <= r; ++i) {
				y[i] = bf_eval(n, a, x[i]);
			}
			return;
		}
		int mid = l + r >> 1;
		int *b = new int[n], *c = new int[n], *t = new int[n];
		memset(b, 0, sizeof(int) * n);
		memset(c, 0, sizeof(int) * n);
		div(n, a, mid - l + 2, poly[k << 1], t, b);
		div(n, a, r - (mid + 1) + 2, poly[(k << 1) | 1], t, c);
		delete t;
		int m = n;
		while(m && !b[m - 1]) {
			--m;
		}
		eval(m, b, l, mid, k << 1, x, y);
		delete b;
		m = n;
		while(m && !c[m - 1]) {
			--m;
		}
		eval(m, c, mid + 1, r, (k << 1) | 1, x, y);
		delete c;
		return;
	}

	inline void eval_del(int l, int r, int k) {
		delete poly[k];
		if(l == r) {
			return;
		}
		int mid = l + r >> 1;
		eval_del(l, mid, k << 1);
		eval_del(mid + 1, r, (k << 1) | 1);
		return;
	}

	inline void eval(int n, int *a, int m, int *x, int *y) {
		eval_init(0, m - 1, 1, x);
		eval(n, a, 0, m - 1, 1, x, y);
		eval_del(0, m - 1, 1);
		return;
	}

	inline void inter(int l, int r, int k, int *x, int *y) {
		if(l == r) {
			poly2[k] = new int[len[k] = 1];
			poly2[k][0] = y[l];
			return;
		}
		int mid = l + r >> 1, lc = k << 1, rc = lc | 1;
		inter(l, mid, lc, x, y);
		inter(mid + 1, r, rc, x, y);
		poly2[k] = new int[len[k] = std::max(len[lc] + r - (mid + 1) + 2 - 1, len[rc] + mid - l + 2 - 1)];
		memset(poly2[k], 0, sizeof(int) * len[k]);
		mul(len[lc], poly2[lc], r - (mid + 1) + 2, poly[rc], poly2[k]);
		add_mul(len[rc], poly2[rc], mid - l + 2, poly[lc], poly2[k]);
		return;
	}

	inline void inter_del(int l, int r, int k) {
		delete poly[k];
		delete poly2[k];
		if(l == r) {
			return;
		}
		int mid = l + r >> 1;
		inter_del(l, mid, k << 1);
		inter_del(mid + 1, r, (k << 1) | 1);
		return;
	}

	inline void inter(int n, int *x, int *y, int *a) {
		int *X = new int[n], *Y = new int[n], *A = new int[n + 1];
		memcpy(X, x, sizeof(int) * n);
		memcpy(Y, y, sizeof(int) * n);
		eval_init(0, n - 1, 1, X);
		memcpy(A, poly[1], sizeof(int) * (n + 1));
		der(n + 1, A, A);
		eval(n, A, 0, n - 1, 1, X, Y);
		for (int i = 0; i < n; ++i) {
			Y[i] = (long long) pow_mod(Y[i], mod - 2) * y[i] % mod;
		}
		inter(0, n - 1, 1, X, Y);
		memcpy(a, poly2[1], sizeof(int) * n);
		inter_del(0, n - 1, 1);
		delete X;
		delete Y;
		delete A;
		return;
	}
};

int n;
int G[maxn][maxn], g[maxn][maxn], x[maxn], y[maxn], a[maxn];

inline int matrix_tree() {
	int ret = 1;
	for (int i = 1; i < n; ++i) {
		for (int j = i + 1; j < n; ++j) {
			while(g[j][i]) {
				int foo = g[i][i] / g[j][i];
				for (int k = i; k < n; ++k) {
					g[i][k] = ((long long) g[i][k] - (long long) g[j][k] * foo) % mod;
				}
				std::swap(g[i], g[j]);
				ret = -ret;
			}
		}
	}
	for (int i = 1; i < n; ++i) {
		ret = (long long) ret * g[i][i] % mod;
	}
	return (ret + mod) % mod;
}

polynomial<933, -1, mod> poly;

int main() {
	scanf("%d", &n);
	for (int u = 1; u <= n; ++u) {
		for (int v = 1; v <= n; ++v) {
			if(u != v) {
				G[u][v] = 1;
			}
		}
	}
	for (int i = 1; i < n; ++i) {
		int u, v;
		scanf("%d%d", &u, &v);
		G[u][v] = G[v][u] = -1;
	}
	for (int x = 1; x <= n; ++x) {
		for (int i = 1; i <= n; ++i) {
			g[i][i] = 0;
			for (int j = 1; j <= n; ++j) {
				if(i != j) {
					g[i][j] = (G[i][j] == -1 ? -x : (G[i][j] == 1 ? -1 : 0));
					g[i][i] -= g[i][j];
				}
			}
		}
		int y = matrix_tree();
		::x[x - 1] = x;
		::y[x - 1] = y;
	}
	poly.inter(n, x, y, a);
	for (int i = 0; i < n; ++i) {
		printf("%d%c", (a[i] + mod) % mod, " \n"[i == n - 1]);
	}
	return 0;
}

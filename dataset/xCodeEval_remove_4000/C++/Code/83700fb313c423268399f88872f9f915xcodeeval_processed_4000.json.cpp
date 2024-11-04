









typedef std::vector <int> Vector;

const int MOD = 1e9 + 7, G = 3;
const int MAXN = 1 << 18 | 1, MAXK = 5e3 + 10;

int fac[MAXN], ifac[MAXN];
int S[MAXK][MAXK];

inline int add(int x);
inline int sub(int x);
inline int inv(int x);
inline int add(int x, int y);
inline int sub(int x, int y);
inline int mul(int x, int y);
inline int pow(int x, int y);
inline void Add(int &x, int y);
inline void Sub(int &x, int y);
inline void Mul(int &x, int y);

inline int add(int x) {
	return x >= MOD ? x - MOD : x;
}
inline int sub(int x) {
	return x < 0 ? x + MOD : x;
}
inline int inv(int x) {
	return pow(x, MOD - 2);
}
inline int add(int x, int y) {
	(x += y) >= MOD && (x -= MOD);
	return x;
}
inline int sub(int x, int y) {
	(x -= y) < 0 && (x += MOD);
	return x;
}
inline int mul(int x, int y) {
	x = 1LL * x * y % MOD;
	return x;
}
inline int pow(int x, int y) {
	int ans = 1;
	for (; y; Mul(x, x), y >>= 1) if (y & 1) Mul(ans, x);
	return ans;
}
inline void Add(int &x, int y) {
	return (void) (x = add(x, y));
}
inline void Sub(int &x, int y) {
	return (void) (x = sub(x, y));
}
inline void Mul(int &x, int y) {
	return (void) (x = mul(x, y));
}

int BSGS(int a, int b, int p) {
	std::unordered_map <int, int> mp;
	int m = ceil(::sqrt(p));
	for (int i = 0; i <= m; b = 1LL * b * a % p, i++) mp[b] = i;
	a = pow(a, m);
	for (int i = 0, j = 1; i < m; j = 1LL * j * a % p, i++)
		if (mp.count(j) && i * m >= mp[j]) return i * m - mp[j];
	return -1;
}
int degree(int a, int k, int p) {
	int x = BSGS(G, a, p), r = pow(G, x / k);
	return std::min(r, p - r);
}

namespace FFT {
	inline int extend(int x);
	inline void NTT(Vector &A, bool opt);
	inline void DFT(Vector &A);
	inline void IDFT(Vector &A);

	inline int extend(int x) {
		int n = 1;
		for (; n < x; n <<= 1);
		return n;
	}
	inline void NTT(Vector &A, bool opt) {
		int n = A.size(), k = 0;
		for (; 1 << k < n; ++k);
		Vector rev(n);
		for (int i = 0; i < n; ++i) {
			rev[i] = rev[i >> 1] >> 1 | (i & 1) << (k - 1);
			if (i < rev[i]) std::swap(A[i], A[rev[i]]);
		}
		for (int l = 2; l <= n; l <<= 1) {
			int mid = l >> 1, Wn = pow(G, (MOD - 1) / l);
			if (opt) Wn = inv(Wn);
			for (int j = 0; j < n; j += l)
				for (int i = 0, W = 1; i < mid; ++i, Mul(W, Wn)) {
					int X = A[i + j], Y = mul(A[i + j + mid], W);
					A[i + j] = add(X, Y), A[i + j + mid] = sub(X, Y);
				}
		}
		return;
	}
	inline void DFT(Vector &A) {
		NTT(A, false);
		return;
	}
	inline void IDFT(Vector &A) {
		NTT(A, true);
		int p = inv(A.size());
		for (auto &x : A) Mul(x, p);
		return;
	}
};
using namespace FFT;

namespace Poly {
	inline Vector operator+ (Vector A, Vector B);
	inline Vector operator+ (Vector A, int B);
	inline Vector operator+ (int A, Vector B);
	inline Vector operator- (Vector A);
	inline Vector operator- (Vector A, Vector B);
	inline Vector operator- (Vector A, int B);
	inline Vector operator- (int A, Vector B);
	inline Vector operator* (Vector A, Vector B);
	inline Vector operator* (Vector A, int B);
	inline Vector operator* (int A, Vector B);
	inline Vector operator/ (Vector A, Vector B);
	inline Vector operator/ (Vector A, int B);
	inline Vector operator% (Vector A, Vector B);
	inline Vector operator~ (Vector A);
	inline Vector operator^ (Vector A, int B);
	inline Vector operator<< (Vector A, int B);
	inline Vector operator>> (Vector A, int B);
	inline void operator+= (Vector &A, Vector B);
	inline void operator+= (Vector &A, int B);
	inline void operator-= (Vector &A, Vector B);
	inline void operator-= (Vector &A, int B);
	inline void operator*= (Vector &A, Vector B);
	inline void operator*= (Vector &A, int B);
	inline void operator/= (Vector &A, Vector B);
	inline void operator/= (Vector &A, int B);
	inline void operator%= (Vector &A, Vector B);
	inline void operator^= (Vector &A, int B);
	inline void operator<<= (Vector &A, int B);
	inline void operator>>= (Vector &A, int B);
	inline Vector rel(Vector A, int B);
	inline Vector diff(Vector A);
	inline Vector inte(Vector A);
	inline Vector sqrt(Vector A);
	inline Vector root(Vector A, int B);
	inline Vector ln(Vector A);
	inline Vector exp(Vector A);
	inline Vector sin(Vector A);
	inline Vector cos(Vector A);
	inline Vector tan(Vector A);
	inline Vector id0(Vector A);
	inline Vector id1(Vector A);
	inline Vector id2(Vector A);
	inline void Rel(Vector &A, int B);
	inline void read(Vector &A, int B);
	inline void print(Vector A);

	inline Vector operator+ (Vector A, Vector B) {
		int n = std::max(A.size(), B.size());
		Rel(A, n), Rel(B, n);
		for (int i = 0; i < n; ++i) Add(A[i], B[i]);
		return A;
	}
	inline Vector operator+ (Vector A, int B) {
		Add(A[0], B);
		return A;
	}
	inline Vector operator+ (int A, Vector B) {
		return B + A;
	}
	inline Vector operator- (Vector A) {
		int n = A.size();
		for (int i = 0; i < n; ++i) A[i] = sub(-A[i]);
		return A;
	}
	inline Vector operator- (Vector A, Vector B) {
		return A + (-B);
	}
	inline Vector operator- (Vector A, int B) {
		return A + sub(-B);
	}
	inline Vector operator- (int A, Vector B) {
		return -(B - A);
	}
	inline Vector operator* (Vector A, Vector B) {
		int n = A.size() + B.size() - 1, N = extend(n);
		Rel(A, N), Rel(B, N), DFT(A), DFT(B);
		for (int i = 0; i < N; ++i) Mul(A[i], B[i]);
		IDFT(A);
		return rel(A, n);
	}
	inline Vector operator* (Vector A, int B) {
		for (auto &x : A) Mul(x, B);
		return A;
	}
	inline Vector operator* (int A, Vector B) {
		return B * A;
	}
	inline Vector operator/ (Vector A, Vector B) {
		int n = A.size() - B.size() + 1;
		if (n <= 0) return Vector(1, 0);
		std::reverse(A.begin(), A.end()), std::reverse(B.begin(), B.end());
		Rel(A, n), Rel(B, n);
		A = A * ~B;
		Rel(A, n);
		std::reverse(A.begin(), A.end());
		return A;
	}
	inline Vector operator/ (Vector A, int B) {
		return A * inv(B);
	}
	inline Vector operator% (Vector A, Vector B) {
		return rel(A - A / B * B, B.size() - 1);
	}
	inline Vector operator~ (Vector A) {
		int n = A.size(), N = extend(n); Rel(A, N);
		Vector B(N); B[0] = inv(A[0]);
		for (int l = 2; l <= N; l <<= 1) {
			int len = l << 1;
			Vector X(len), Y(len);
			std::copy(A.begin(), A.begin() + l, X.begin());
			std::copy(B.begin(), B.begin() + l, Y.begin());
			DFT(X), DFT(Y);
			for (int i = 0; i < len; ++i) 
				X[i] = 1LL * Y[i] * (2 - 1LL * X[i] * Y[i] % MOD + MOD) % MOD;
			IDFT(X);
			std::copy(X.begin(), X.begin() + l, B.begin());
		}
		return rel(B, n);
	}
	inline Vector operator^ (Vector A, int B) {
		int n = A.size(), x = 0;
		for (; x < n && !A[x]; ++x);
		if (1LL * x * B > n) return Vector(n, 0);
		A >>= x; int v = A[0];
		return exp(ln(A / v) * B) * pow(v, B) << (x * B);
	}
	inline Vector operator<< (Vector A, int B) {
		int n = A.size(); Vector P(n, 0);
		for (int i = B; i < n; ++i) P[i] = A[i - B];
		return P;
	}
	inline Vector operator>> (Vector A, int B) {
		int n = A.size(); Vector P(n, 0);
		for (int i = B; i < n; ++i) P[i - B] = A[i];
		return P;
	}
	inline void operator+= (Vector &A, Vector B) {
		return (void) (A = A + B);
	}
	inline void operator+= (Vector &A, int B) {
		return (void) (A = A + B);
	}
	inline void operator-= (Vector &A, Vector B) {
		return (void) (A = A - B);
	}
	inline void operator-= (Vector &A, int B) {
		return (void) (A = A - B);
	}
	inline void operator*= (Vector &A, Vector B) {
		return (void) (A = A * B);
	}
	inline void operator*= (Vector &A, int B) {
		return (void) (A = A * B);
	}
	inline void operator/= (Vector &A, Vector B) {
		return (void) (A = A / B);
	}
	inline void operator/= (Vector &A, int B) {
		return (void) (A = A / B);
	}
	inline void operator%= (Vector &A, Vector B) {
		return (void) (A = A % B);
	}
	inline void operator^= (Vector &A, int B) {
		return (void) (A = A ^ B);
	}
	inline void operator<<= (Vector &A, int B) {
		return (void) (A = A << B);
	}
	inline void operator>>= (Vector &A, int B) {
		return (void) (A = A >> B);
	}
	inline Vector rel(Vector A, int B) {
		A.resize(B);
		return A;
	}
	inline Vector diff(Vector A) {
		int n = A.size();
		if (n == 1) return Vector(1, 0);
		Vector B(n - 1);
		for (int i = 1; i < n; ++i) B[i - 1] = mul(i, A[i]);
		return B;
	}
	inline Vector inte(Vector A) {
		int n = A.size();
		Vector B(n + 1); B[0] = 0;
		for (int i = 1; i <= n; ++i) B[i] = mul(inv(i), A[i - 1]);
		return B;
	}
	inline Vector sqrt(Vector A) {
		int n = A.size(), N = extend(n); Rel(A, N);
		Vector B(N); int inv2 = inv(2);
		B[0] = degree(A[0], 2, MOD);
		for (int l = 2; l <= N; l <<= 1) {
			int len = l << 1;
			Vector X(l), Y(l);
			std::copy(A.begin(), A.begin() + l, X.begin());
			std::copy(B.begin(), B.begin() + l, Y.begin());
			Vector I = ~Y;
			Rel(X, len), Rel(Y, len), Rel(I, len);
			DFT(X), DFT(Y), DFT(I);
			for (int i = 0; i < len; ++i) 
				X[i] = 1LL * (X[i] + 1LL * Y[i] * Y[i] % MOD) * inv2 % MOD * I[i] % MOD;
			IDFT(X);
			std::copy(X.begin(), X.begin() + l, B.begin());
		}
		return rel(B, n);
	}
	inline Vector root(Vector A, int n) {
		return n == 1 ? A : n == 2 ? sqrt(A) : exp(ln(A) / n);
	}
	inline Vector ln(Vector A) {
		return rel(inte(diff(A) * ~A), A.size());
	}
	inline Vector exp(Vector A) {
		int n = A.size(), N = extend(n); A.resize(N);
		Vector B(N, 0);
		B[0] = 1;
		for (int l = 2; l <= N; l <<= 1) {
			Vector P = (-ln(rel(B, l)) + rel(A, l) + 1) * rel(B, l);
			std::copy(P.begin(), P.begin() + l, B.begin());
		}
		return rel(B, n);
	}
	inline Vector sin(Vector A) {
		int I = degree(MOD - 1, 2, MOD);
		Vector B = exp(A * I);
		return (B - ~B) / mul(2, inv(I));
	}
	inline Vector cos(Vector A) {
		int I = degree(MOD - 1, 2, MOD);
		Vector B = exp(A * I);
		return (B + ~B) / 2;
	}
	inline Vector tan(Vector A) {
		return rel(sin(A) * ~cos(A), A.size());
	}
	inline Vector id0(Vector A) {
		int n = A.size();
		return rel(inte(diff(A) * ~sqrt(1 - (rel(A * A, n)))), n);
	}
	inline Vector id1(Vector A) {
		return -id0(A);
	}
	inline Vector id2(Vector A) {
		int n = A.size();
		return rel(inte(diff(A) * ~(1 + (rel(A * A, n)))), n);
	}
	inline void Rel(Vector &A, int B) {
		A.resize(B);
		return;
	}
	inline void read(Vector &A, int n) {
		Rel(A, n);
		for (int i = 0; i < n; ++i) scanf("%d", &A[i]);
		return;
	}
	inline void print(Vector A) {
		int n = A.size();
		for (int i = 0; i < n; ++i) printf("%d%c", A[i], " \n"[i == n - 1]);
		return;
	}
};
using namespace Poly;

int main() {
	int n, k; scanf("%d%d", &n, &k);
	S[0][0] = 1;
	for (int i = 1; i <= k; ++i)
		for (int j = 1; j <= k; ++j)
			S[i][j] = add(S[i - 1][j - 1], mul(j, S[i - 1][j]));
	int ans = 0;
	for (int i = 0, i2 = inv(2), $n = pow(2, n), $$n = 1; i <= k; Mul($n, i2), Mul($$n, n - i), ++i) Add(ans, mul(S[k][i], mul($n, $$n)));
	printf("%d\n", ans);
	return 0;
}


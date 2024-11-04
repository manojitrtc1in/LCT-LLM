import static java.lang.Math.*;
import static java.lang.Math.max;
import static java.lang.Math.min;
import static java.math.BigInteger.*;
import static java.util.Arrays.*;
import static java.util.Arrays.fill;
import static java.util.Collections.*;
import static java.util.Optional.*;

import java.io.*;
import java.math.*;
import java.util.*;
import java.util.ArrayList;
import java.util.function.*;
import java.util.stream.*;

@SuppressWarnings("unused")
public class D {

	public Object solve() {
		int N = sc.nextInt();
		char [][] A = sc.nextChars(N), B = sc.nextChars(N);

		int J = -1, LO = 0, HI = 0, P = 0, Q = 0;
		String U = null, V = null;
		int [] L = new int [N];

		for (int i : rep(N))
			if (!Arrays.equals(A[i], B[i])) {
				int lo = INF, hi = 0;
				for (int j : rep(A[i].length))
					if (A[i][j] != B[i][j]) {
						lo = min(lo, j);
						hi = max(hi, j+1);
					}
				L[i] = lo;

				if (J == -1) {
					J = i; LO = lo; HI = hi;
					P = 0; Q = A[i].length;
					U = new String(A[i], lo, hi - lo);
					V = new String(B[i], lo, hi - lo);
				}
				else {
					if (!U.equals(new String(A[i], lo, hi - lo)) || !V.equals(new String(B[i], lo, hi - lo)))
						return exit("NO");

					P = max(P, LO - lo);
					for (int j : rep(min(LO - P, lo)))
						if (A[J][LO - 1 - j] != A[i][lo - 1 - j]) {
							P = LO - j;
							break;
						}

					Q = min(Q, HI + A[i].length - hi);
					for (int j : rep(min(Q - HI, A[i].length - hi)))
						if (A[J][HI + j] != A[i][hi + j]) {
							Q = HI + j;
							break;
						}
				}
			}

		int MAX = 3000, Z = Q - P;
		char [] S = new char [Z], T = new char [Z];
		for (int i : rep(Z)) {
			S[i] = A[J][P+i];
			T[i] = B[J][P+i];
		}
		
		int [] F = new int [Z + 1 + MAX];
		prefixFunction(S, S, F, 0);
		
		for (int i : rep(N)) {
			prefixFunction(A[i], S, F, Z + 1);
			int j = -1;
			for (int k : rep(A[i].length))
				if (F[Z + 1 + k] == Z) {
					j = k + 1 - Z;
					break;
				}
			
			if (Arrays.equals(A[i], B[i])) {
				if (j >= 0)
					return exit("NO");
			}
			else
				if (j + LO - P != L[i])
					return exit("NO");
		}
		
		print("YES");
		print(new String(S));
		return print(new String(T));
	}

	private static final boolean ONE_TEST_CASE = true;

	private static void init() {
	}

	

	private static final double eps = 9e-10;
	private static final int INF = (int) 1e9 + 10;
	private static final long LINF = (long) 1e18 + 10;
	private static final double DINF = 1e50;
	private static final int MOD = (int) 1e9 + 7;
	

	private static int [] addTo (int [] X, int [] ... Y) { return binOpTo ((x, y) -> x + y, X, Y); }
	private static long and (long x, int i) { return (x & bit(i)); }
	private static int [] binOp (IntBinaryOperator F, int [] ... X) {
		int L = stream(X).mapToInt(x -> x.length).max().orElse(0);
		int [] res = new int [L];
		for (int i = 0; i < L; ++i) {
			int j = i;
			res[i] = stream(X).filter(x -> j < x.length).mapToInt(x -> x[j]).reduce(F).getAsInt();
		}
		return res;
	}
	private static double [] binOp (DoubleBinaryOperator F, double [] ... X) {
		int L = stream(X).mapToInt(x -> x.length).max().orElse(0);
		double [] res = new double [L];
		for (int i = 0; i < L; ++i) {
			int j = i;
			res[i] = stream(X).filter(x -> j < x.length).mapToDouble(x -> x[j]).reduce(F).getAsDouble();
		}
		return res;
	}
	private static int [] binOpTo (IntBinaryOperator F, int [] X, int [] ... Y) {
		for (int [] y : Y)
			for (int i = 0; i < X.length && i < y.length; ++i)
				X[i] = F.applyAsInt(X[i], y[i]);
		return X;
	}
	private static double [] binOpTo (DoubleBinaryOperator F, double [] X, double [] ... Y) {
		for (double [] y : Y)
			for (int i = 0; i < X.length && i < y.length; ++i)
				X[i] = F.applyAsDouble(X[i], y[i]);
		return X;
	}
	private static long bit (int i) { return (1L << i); }
	private static long bs (long p, long q, LongFunction<Boolean> F) {
		long m;
		while (q - p > 1) {
			m = (p + q) / 2;
			if (F.apply(m)) q = m;
			else p = m;
		}
		return q;
	}
	private static double bs (double p, double q, DoubleFunction<Boolean> F) {
		double m;
		while (q - p > eps * max(1, min(abs(p), abs(q)))) {
			m = (p + q) / 2;
			if (F.apply(m)) q = m;
			else p = m;
		}
		return q;
	}
	private static Comparator<int[]> by (final int ... J) { return new Comparator<int[]>() { public int compare(int[] x, int[] y) { for (int i : J) if (x[i] != y[i]) return x[i] - y[i]; return 0; }}; }
	private static int [] cc (int [][] E, int N) {
		int [] res = singletons(N);
		dsu(E, 0, E.length, res);
		for (int i = 0; i < N; ++i)
			res[i] = root(res, i);
		return res;
	}
	private static long ceil (double x) { return round(Math.ceil(x - eps)); }
	private static long ceil (long p, long q) { return fc(p, q, true); }
	private static long clear (long x, int i) { return (x & ~bit(i)); }
	private static double [] cross (double [] X, double [] Y) { assert X.length <= 3 && Y.length <= 3; X = copyOf(X, 3); Y = copyOf(Y, 3); return new double [] { X[1]*Y[2] - Y[1]*X[2], X[2]*Y[0] - Y[2]*X[0], X[0]*Y[1] - Y[0]*X[1] }; }
	private static int [] dec(int ... A) { for (int i = 0; i < A.length; ++i) --A[i]; return A; }
	private static int [][] dec (int [] ... E) { return dec(E, INF); }
	private static int [][] dec (int [][] E, int N) { for (int [] e : E) for (int i = 0; i < e.length && i < N; ++i) --e[i]; return E; }
	private static <T> T deepClone (T A) {
		try {
			ByteArrayOutputStream bout = new ByteArrayOutputStream();
			ObjectOutputStream  out = new ObjectOutputStream(bout);
			out.writeObject(A);
			ByteArrayInputStream bin = new ByteArrayInputStream(bout.toByteArray());
			ObjectInputStream in = new ObjectInputStream(bin);
			@SuppressWarnings("unchecked") T res = (T) in.readObject();
			return res;
		} catch (Exception e) {
			throw new Error(e);
		}
	}
	private static <T> Comparator<T> defaultOrder () { return reverseOrder(reverseOrder()); }
	private static int [][] dgraph (int N, int [][] E) { return dwgraph(N, E)[0]; }
	private static int [] diff (int [] X, int [] Y) { return sum(X, scalar(-1, Y)); }
	private static double [] diff (double [] X, double [] Y) { return sum(X, scalar(-1, Y)); }
	private static int digitCount (long N, int B) {
		int res = 0;
		for (; N > 0; ++res, N /= B);
		return res;
	}
	private static int digitCount (long N) { return digitCount(N, 10); }
	private static int [] digitFrequency (long N) {
		int [] res = new int [10];
		for (int d : digits(N))
			++res[d];
		return res;
	}
	private static int [] digits (long N) { return digits(N, 10, digitCount(N, 10)); }
	private static int [] digits (long N, int B, int sz) {
		int [] res = new int [sz];
		for (int i = 0; i < sz; ++i)
			if (N > 0) {
				res[i] = (int)(N % B);
				N /= B;
			}
		return res;
	}
	private static int digitSum (long N) {
		int res = 0;
		for (; N > 0; res += N % 10, N /= 10);
		return res;
	}
	private static double dist (double [] X, double [] Y) { return norm(diff(X, Y)); }
	private static long [] distinctPrimeDivisors (long N) {
		List<Long> res = new ArrayList<Long>();
		for (long p = 2; p*p <= N; ++p) {
			if (N % p == 0)
				res.add(p);
			while (N % p == 0)
				N /= p;
		}
		if (N > 1)
			res.add(N);
		return pri(res.toArray(new Long [0]));
	}
	private static long [] divisorCount(int N) { return divisorFunction(N, 0); }
	private static long [] divisorFunction(int N, int e) {
		long [] P = new long [N+1];
		for (int i = 1; i <= N; ++i)
			P[i] = power(i, e);
		long [] res = new long [N+1];
		for (int i = 1; i <= N; ++i)
			for (int j = 1; i*j <= N; ++j)
				res[i*j] += P[i];
		return res;
	}
	private static long [] divisors (long N) {
		Queue<Long> L1 = queue(), L2 = stack();
		for (long i = 1; i*i <= N; ++i)
			if (N % i == 0) {
				L1.add(i);
				if (i*i < N)
					L2.add(N/i);
			}
		L1.addAll(L2);
		return pri(L1.toArray(new Long [0]));
	}
	private static long [] divisorSum(int N) { return divisorFunction(N, 1); }
	private static double dot (double [] X, double [] Y) { double res = 0; for (int i = 0; i < X.length && i < Y.length; ++i) res += X[i] * Y[i]; return res; }
	private static boolean dsu (int u, int v, int [] C) {
		u = root(C, u);
		v = root(C, v);
		C[u] = C[v];
		return u != v;
	}
	private static int dsu (int [][] E, int s, int t, int [] C) {
		int res = 0;
		for (int i = s; i < t; ++i)
			if (dsu(E[i][0], E[i][1], C))
				++res;
		return res;
	}
	private static int [][] dup (int [][] E) {
		int [][] res = new int [2*E.length][];
		for (int i = 0; i < E.length; ++i) {
			res[2*i] = E[i].clone();
			res[2*i+1] = E[i].clone();
			res[2*i+1][0] = E[i][1]; res[2*i+1][1] = E[i][0];
		}
		return res;
	}
	private static int [][][] dwgraph (int N, int [][] E) {
		int [] D = new int [N];
		for (int [] e : E)
			++D[e[0]];
		int [][][] res = new int [2][N][];
		for (int i = 0; i < 2; ++i)
			for (int j = 0; j < N; ++j)
				res[i][j] = new int [D[j]];
		D = new int [N];
		for (int [] e : E) {
			int x = e[0], y = e[1], z = e.length > 2 ? e[2] : 1;
			res[0][x][D[x]] = y;
			res[1][x][D[x]] = z;
			++D[x];
		}
		return res;
	}
	private static long [] envelope (long [] F, long [] A) {
		int N = F.length;
		long [] res = new long [N]; res[0] = F[0];
		int [] T = new int [N]; int Z = 0;
		for (int i = 1, k = 0; i < N; ++i) {
			for (;;)
				if (Z > 0 && (F[i] - F[T[Z]]) * (i - T[Z-1]) <=  (F[i] - F[T[Z-1]]) * (i - T[Z]))
					--Z;
				else {
					T[++Z] = i;
					break;
				}

			k = min(k, Z);
			for (; k < Z && (F[T[k+1]] - F[T[k]]) <= A[i] * (T[k+1] - T[k]); ++k);
			res[i] = F[T[k]] - A[i] * T[k];
		}
		return res;
	}
	private static boolean eq (double x, double y) { return abs(x - y) < eps; }
	private static boolean eq (double [] X, double [] Y) { return eq(dist(X, Y), 0); }
	private static long [] fact (int N) {
		long [] res = new long [N+1];
		res[0] = 1;
		for (int i = 1; i <= N; ++i)
			res[i] = res[i-1] * i;
		return res;
	}
	private static long fc (long p, long q, boolean up) {
		if (up) {
			if (q < 0) return fc(-p, -q, true);
			else if (p < 0) return -fc(-p, q, false);
			else return (p+q-1) / q;
		}
		else if (q < 0) return fc(-p, -q, false);
		else if (p < 0) return -fc(-p, q, true);
		else return p / q;
	}
	private static long fi (long N) {
		long [] P = distinctPrimeDivisors(N);
		long res = N;
		for (long p : P)
			res = res * (p-1) / p;
		return res;
	}
	private static long floor (double x) { return round(Math.floor(x + eps)); }
	private static long floor (long p, long q) { return fc(p, q, false); }
	private static <T extends Comparable<T>> int fmax (T [] A) { return fmax(A, 0, A.length); }
	private static <T extends Comparable<T>> int fmax (T [] A, int s, int t) {
		int res = s;
		for (int i = s; i < t; ++i)
			if (A[i].compareTo(A[res]) > 0)
				res = i;
		return res;
	}
	private static <T extends Comparable<T>> int fmin (T [] A) { return fmin(A, 0, A.length); }
	private static <T extends Comparable<T>> int fmin (T [] A, int s, int t) {
		int res = s;
		for (int i = s; i < t; ++i)
			if (A[i].compareTo(A[res]) < 0)
				res = i;
		return res;
	}
	private static int [] freq (int [] A, int N) {
		int [] res = new int [N];
		for (int i = 0; i < A.length; ++i)
			++res[A[i]];
		return res;
	}
	private static boolean [][] fw (boolean [][] G) {
		int N = G.length;
		for (int k = 0; k < N; ++k)
			for (int i = 0; i < N; ++i)
				for (int j = 0; j < N; ++j)
					G[i][j] = G[i][j] || (G[i][k] && G[k][j]);
		return G;
	}
	private static long [][] fw (long [][] G) {
		int N = G.length;
		for (int k = 0; k < N; ++k)
			for (int i = 0; i < N; ++i)
				for (int j = 0; j < N; ++j)
					G[i][j] = min(G[i][j], G[i][k] + G[k][j]);
		return G;
	}
	private static long gcd (long x, long y) { return BigInteger.valueOf(x).gcd(BigInteger.valueOf(y)).longValue(); }
	private static boolean geq (double x, double y) { return x > y - eps; }
	private static int [][] graph (int N, int [][] E) { return wgraph(N, E)[0]; }
	private static boolean greater (double x, double y) { return x > y + eps; }
	private static boolean has (long x, int i) { return and(x, i) != 0; }
	private static int [] hungarian (long [][] C) {
		int T = C.length, N = T > 0 ? C[0].length : 0;
		assert (N >= T);
		if (T < N) {
			C = copyOf(C, N);
			for (int i = T; i < N; ++i)
				C[i] = new long [N];
		}
		long [] YS = new long [N], YT = new long [N];
		int [] M = new int [N], res = new int [N];
		fill(M, -1); fill(res, -1);

		for (int n = 0; n < N; ++n) {
			int [] Z = new int [N], Q = new int [N];
			long [] L = new long [N];
			fill(Z, -1); fill(L, LINF);

			int t = -1, fi = 0, la = 0;
			for (int i = 0; i < N; ++i)
				if (res[i] == -1)
					Q[la++] = i;

			boolean [] VS = new boolean [N], VT = new boolean [N];
			out: for (;;) {
				while (fi < la) {
					int x = Q[fi++]; VS[x] = true;
					for (int j = 0; j < N; ++j)
						if (!VT[j]) {
							long p = L[j];
							if ((L[j] = min(L[j], C[x][j] - YS[x] - YT[j])) < p) {
								int z = M[j]; Z[j] = x;
								if (L[j] == 0) {
									VT[j] = true;
									if (z == -1) {
										t = j; break out;
									}
									else if (!VS[z])
										Q[la++] = z;
								}
							}
						}
				}

				long D = LINF;
				for (int j = 0; j < N; ++j)
					if (!VT[j])
						D = min(D, L[j]);
				for (int i = 0; i < N; ++i)
					if (VS[i])
						YS[i] += D;
				for (int j = 0; j < N; ++j)
					if (VT[j])
						YT[j] -= D;
					else
						L[j] -= D;
				for (int j = 0; j < N; ++j)
					if (!VT[j] && L[j] == 0) {
						VT[j] = true; int z = M[j];
						if (z == -1) {
							t = j; break out;
						}
						else if (!VS[z])
							Q[la++] = z;
					}
			}

			while (t != -1) {
				int u = res[M[t] = Z[t]];
				res[M[t]] = t;
				t = u;
			}
		}

		res = copyOf(res, T);
		return res;
	}
	private static int [] inc (int ... A) {
		for (int i = 0; i < A.length; ++i)
			++A[i];
		return A;
	}
	private static boolean integer (double x) { return eq(x, floor(x)); }
	private static int [] invert (int [] J) {
		int N = J.length;
		int [] res = new int [N];
		for (int i = 0; i < N; ++i)
			res[J[i]] = i;
		return res;
	}
	private static long [][] islands (int N) {
		long [][] res = new long [N][N];
		for (long [] r : res)
			fill(r, LINF);
		for (int i = 0; i < N; ++i)
			res[i][i] = 0;
		return res;
	}
	private static Comparator<long[]> lby (final int ... J) { return new Comparator<long[]>() { public int compare(long[] x, long[] y) { for (int i : J) if (x[i] != y[i]) return Long.signum(x[i] - y[i]); return 0; }}; }
	private static long lcm (int ... A) {
		long res = 1;
		for (int a : A)
			res = lcm(res, a);
		return res;
	}
	private static long lcm (long x, long y) { return x/gcd(x, y)*y; }
	private static boolean leq (double x, double y) { return x < y + eps; }
	private static boolean less (double x, double y) { return  x < y - eps; }
	private static int [][] manacher (char [] C) {
		int N = C.length, M = 2*N+1;
		char [] D = new char [M];
		for (int i = 0; i < N; ++i)
			D[2*i+1] = C[i];
		int [] L = new int [M];
		int S = 0, R = 0;
		int lo = 0, hi = 0;
		for (int i = 1; i < M; i++) {
			if (i > R) {
				L[i] = 0; lo = i-1; hi = i+1;
			}
			else {
				int j = 2*S - i;
				if (i + L[j] < R) {
					L[i] = L[j]; lo = -1;
				}
				else {
					L[i] = R-i; hi = R+1; lo = 2*i - hi;
				}
			}
			while (lo >= 0 && hi < M && D[lo] == D[hi]) {
				++L[i]; --lo; ++hi;
			}
			if (i + L[i] > R) {
				S = i; R = i + L[i];
			}
		}
		int [][] res = new int [2][N];
		for (int i = 0; i < N; ++ i) {
			res[0][i] = L[2*i+2];
			res[1][i] = L[2*i+1];
		}
		return res;
	}
	private static <T extends Comparable<T>> T maximum (@SuppressWarnings("unchecked") T ... A) { return A[fmax(A)]; }
	private static int [] maximum (int [] ... X) { return binOp((x, y) -> max(x, y), X); }
	private static <T extends Comparable<T>> T median (@SuppressWarnings("unchecked") T ... A) {
		assert A.length > 0;
		T [] B = A.clone();
		sort(B);
		T res = B[B.length/2];
		return res;
	}
	private static long minCost (long [][] C) {
		long res = 0; int [] H = hungarian(C);
		for (int i = 0; i < C.length; ++i)
			res += C[i][H[i]];
		return res;
	}
	private static <T extends Comparable<T>> T minimum (@SuppressWarnings("unchecked") T ... A) { return A[fmin(A)]; }
	private static int [] minimum (int [] ... X) { return binOp((x, y) -> min(x, y), X); }
	private static long mod (long x) { return mod(x, MOD); }
	private static long mod (long x, long mod) { return ((x % mod) + mod) % mod; }
	private static long [][] modBin (int N, int K) {
		long [][] res = new long [N+1][K+1];
		for (int n = 0; n <= N; ++n) {
			res[n][0] = 1;
			for (int k = 1; k <= K && k <= n; ++k)
				res[n][k] = mod(res[n-1][k] + res[n-1][k-1]);
		}
		return res;
	}
	private static long [] modFact (int N) {
		long [] res = new long [N+1]; res[0] = 1;
		for (int i = 1; i <= N; ++i)
			res[i] = mod(res[i-1] * i);
		return res;
	}
	private static long modInv(long x) { return modInv(x, MOD); }
	private static long modInv(long x, int mod) { return BigInteger.valueOf(x).modInverse(BigInteger.valueOf(mod)).longValue(); }
	private static long modPow (long b, long e) { return modPow(b, e, MOD); }
	private static long modPow (long b, long e, int mod) { return BigInteger.valueOf(b).modPow(BigInteger.valueOf(e), BigInteger.valueOf(mod)).longValue(); }
	private static BigInteger [] mult (BigInteger [][] A, BigInteger [] X) {
		BigInteger [] res = new BigInteger [A.length];
		for (int i = 0; i < A.length; ++i) {
			res[i] = ZERO;
			for (int j = 0; j < A[0].length; ++j)
				res[i] = res[i].add(A[i][j].multiply(X[j]));
		}
		return res;
	}
	private static BigInteger [][] mult (BigInteger [][] A, BigInteger [][] B) {
		BigInteger [][] res = new BigInteger [A.length][B[0].length];
		for (int i = 0; i < A.length; ++i) {
			fill(res[i], ZERO);
			for (int j = 0; j < B[0].length; ++j)
				for (int k = 0; k < A[0].length; ++k)
					res[i][j] = res[i][j].add(A[i][k].multiply(B[k][j]));
		}
		return res;
	}
	private static <T> T [] newArray (T [] A, int N) {
		T [] res = copyOf(A, N);
		fill(res, null);
		return res;
	}
	private static <T> T [][] newArray (T [][] A, int N, int M) {
		T [][] res = copyOf(A, N); assert N > 0;
				for (int i = 0; i < N; ++i)
					res[i] = newArray(A[0], M);
				return res;
	}
	private static int [] nextPermutation (int [] P) {
		int N = P.length;
		for (int i = N-1; i > 0; --i)
			if (P[i-1] < P[i]) {
				reverse(P, i, N);
				for (int j = i; j < N; ++j)
					if (P[j] > P[i-1]) {
						int x = P[i-1], y = P[j];
						P[j] = x; P[i-1] = y;
						return P;
					}
			}
		return null;
	}
	private static double norm (double ... X) { return sqrt(dot(X, X)); }
	private static double [] normalize (double ... X) { return zero(X) ? X : scalar(1/norm(X), X); }
	private static Character [] obj (char ... A) { Character [] res = new Character [A.length];	for (int i = 0; i < A.length; ++i) res[i] = A[i]; return res; }
	private static Character [][] obj (char [] ... A) { return stream(A).map(a -> obj(a)).toArray(Character[][]::new); }
	private static Integer [] obj (int ... A) { return stream(A).mapToObj(x -> x).toArray(Integer[]::new); }
	private static Integer [][] obj (int [] ... A) { return stream(A).map(a -> obj(a)).toArray(Integer[][]::new); }
	private static Long [] obj (long ... A) { return stream(A).mapToObj(x -> x).toArray(Long[]::new); }
	private static Long [][] obj (long [] ... A) { return stream(A).map(a -> obj(a)).toArray(Long[][]::new); }
	private static Double [] obj (double ... A) { return stream(A).mapToObj(x -> x).toArray(Double[]::new); }
	private static Double [][] obj (double [] ... A) { return stream(A).map(a -> obj(a)).toArray(Double[][]::new); }
	private static long or (long x, int i) { return (x | bit(i)); }
	private static <T> boolean palindrome(T X) {
		char [] C = X.toString().toCharArray();
		int N = C.length;
		for (int i = 0; 2*i <= N; ++i)
			if (C[i] != C[N-i-1])
				return false;
		return true;
	}
	private static long [] partialSum (long [] C) {
		int N = C.length;
		long [] res = new long [N+1];
		for (int i = 0; i < N; ++i)
			res[i+1] = res[i] + C[i];
		return res;
	}
	private static Iterable<BigInteger[]> pell(final long N) { return pell(N, 1); }
	private static Iterable<BigInteger[]> pell(final long N, final int z) {
		assert z == 1 || z == -1;
		long A0 =  floor(sqrt(N));
		if (A0 * A0 == N)
			return emptyList();

		long M = 0, D = 1, A = A0;
		BigInteger H1 = ONE, H2 = ZERO, K1 = ZERO, K2 = ONE;

		for (int i = 0; ; ++i) {
			final BigInteger H = valueOf(A).multiply(H1).add(H2);
			final BigInteger K = valueOf(A).multiply(K1).add(K2);
			if (H.multiply(H).subtract(valueOf(N).multiply(K).multiply(K)).equals(valueOf(z)))
				return new Iterable<BigInteger[]>() {
					public Iterator<BigInteger[]> iterator() {
						return new Iterator<BigInteger[]>() {
							BigInteger X = H, Y = K;
							public boolean hasNext () { return true; }
							public BigInteger [] next() {
								BigInteger [] res = { X, Y };
								if (z == -1) calc(); calc();
								return res;
							}
							private void calc () {
								BigInteger x = H.multiply(X).add(valueOf(N).multiply(K).multiply(Y));
								BigInteger y = H.multiply(Y).add(K.multiply(X));
								X = x; Y = y;
							}
						};
					}

				};

				H2 = H1; H1 = H;
				K2 = K1; K1 = K;

				M = D*A - M;
				D = (N - M*M) / D;
				A = (A0 + M) / D;

				if (z == -1 && A == 2*A0 && i % 2 == 1)
					return emptyList();
		}
	}
	private static Iterable<int[]> permutations (final int N) {
		return new Iterable<int[]>() {
			@Override
			public Iterator<int[]> iterator() {
				return new Iterator<int[]>() {
					int [] P = null;

					@Override
					public boolean hasNext() {
						if (P == null)
							return true;
						for (int i = 0; i < N; ++i)
							if (i + P[i] != N - 1)
								return true;
						return false;
					}

					@Override
					public int[] next() {
						if (P == null)
							return P = singletons(N);
						else if ((P = nextPermutation(P)) == null)
							throw new NoSuchElementException();
						else
							return P;
					}
				};
			}
		};
	}
	private static <T> T [] permute(T [] A, int [] J) {
		T [] res = A.clone();
		for (int i = 0; i < J.length; ++i)
			res[i] = A[J[i]];
		return res;
	}
	private static long power (long b, int e) {
		if (b != 0 && e * log(abs(b)) > 2 * log(LINF)) return power(Long.signum(b), e) * LINF;
		else return BigInteger.valueOf(b).pow(e).min(BigInteger.valueOf(LINF)).max(BigInteger.valueOf(-LINF)).longValue();
	}
	private static BigInteger [][] power (BigInteger [][] A, long E) {
		int N = A.length;
		BigInteger [][] res = new BigInteger [N][N];
		for (int i = 0; i < N; ++i) {
			fill(res[i], ZERO);
			res[i][i] = ONE;
		}
		int Z = Long.numberOfTrailingZeros(Long.highestOneBit(E));
		for (int j = Z; j >= 0; --j) {
			res = mult(res, res);
			if (has(E, j))
				res = mult(res, A);
		}
		return res;
	}
	private static int [] prefixFunction (char [] C) {
		int [] res = new int [C.length];
		prefixFunction(C, C, res, 0);
		return res;
	}
	private static void prefixFunction(char [] C, char [] P, int [] F, int i) {
		int j = i > 0 ? F[i-1] : 0;
		for (int k = 0; k < C.length; ++k)
			if (i+k > 0) {
				while (j > 0 && (j == P.length || C[k] != P[j]))
					j = F[j-1];
				if (C[k] == P[j])
					++j;
				F[i+k] = j;
			}
	}
	private static char [] pri(Character [] A) { char [] res = new char [A.length]; for (int i = 0; i < res.length; ++i) res[i] = A[i]; return res; }
	private static char [] pri(Character [] A, char [] a) { System.arraycopy(pri(A), 0, a, 0, A.length); return a; }
	private static char [][] pri (Character [][] A) { return stream(A).map(a -> pri(a)).toArray(char[][]::new); }
	private static int [] pri(Integer [] A) { return stream(A).mapToInt(x -> x).toArray(); }
	private static int [] pri(Integer [] A, int [] a) { System.arraycopy(pri(A), 0, a, 0, A.length); return a; }
	private static int [][] pri (Integer [][] A) { return stream(A).map(a -> pri(a)).toArray(int[][]::new); }
	private static long [] pri(Long [] A) { return stream(A).mapToLong(x -> x).toArray(); }
	private static long [] pri(Long [] A, long [] a) { System.arraycopy(pri(A), 0, a, 0, A.length); return a; }
	private static long [][] pri (Long [][] A) { return stream(A).map(a -> pri(a)).toArray(long[][]::new); }
	private static double [] pri(Double [] A) { return stream(A).mapToDouble(x -> x).toArray(); }
	private static double [] pri(Double [] A, double [] a) { System.arraycopy(pri(A), 0, a, 0, A.length); return a; }
	private static double [][] pri (Double [][] A) { return stream(A).map(a -> pri(a)).toArray(double[][]::new); }
	private static char [][] pri (String [] S) { return stream(S).map(String::toCharArray).toArray(char[][]::new); }
	private static boolean prime (long N) {
		N = abs(N);
		if (N < 2) return false;
		if (N > 2 && N % 2 == 0) return false;
		for (long p = 3; p*p <= N; p += 2)
			if (N % p == 0)
				return false;
		return true;
	}
	private static boolean probablyPrime (long N, int T) { return BigInteger.valueOf(N).isProbablePrime(T); }
	private static long [][] primeFactorization (long N) {
		List<long[]> res = new ArrayList<long[]>();
		for (long p = 2; p*p <= N; ++p)
			if (N % p == 0) {
				long [] r = { p, 0 };
				while (N % p == 0) {
					++r[1];
					N /= p;
				}
				res.add(r);
			}
		if (N > 1)
			res.add(new long [] { N, 1 });
		return res.toArray(new long[0][]);
	}
	private static int [] primes (int N) {
		if (N == 1) return new int [] {};
		BitSet C = new BitSet();
		int Q = (int)floor(sqrt(N));
		for (int p = 3; p <= Q; p += 2)
			if (!C.get(p)) {
				int R = N/p;
				for (int j = p; j <= R; j += 2)
					C.set(j*p);
			}
		int [] res = new int [(N+1)/2 - C.cardinality()];
		res[0] = 2;
		for (int p = 3, i = 1; p <= N; p += 2)
			if (!C.get(p))
				res[i++] = p;
		return res;
	}
	private static double [] project(double [] X, double [] K) { return diff(X, scalar(dot(X,K)/dot(K,K), K)); }
	private static long [] properDivisorSum(int N) {
		long [] res = divisorSum(N);
		for (int i = 0; i < res.length; ++i)
			res[i] -= i;
		return res;
	}
	private static long qnorm (long ... X) {
		long S = 0;
		for (long x : X)
			S += x*x;
		return S;
	}
	private static <T> Queue<T> queue () { return new LinkedList<T>(); }
	private static int [] rep (int N) { return rep(0, N); }
	private static int [] rep (int S, int T) { if (S >= T) return new int [0]; int [] res = new int [T-S]; for (int i = S; i < T; ++i) res[i-S] = i; return res; }
	private static int [] req (int N) { return req(0, N); }
	private static int [] req (int S, int T) { return rep(S, T+1); }
	private static int [] reverse (int [] A) { return reverse(A, 0, A.length); }
	private static int [] reverse (int [] A, int s, int t) {
		for (int i = 0; 2*i < t - s - 1; ++i) {
			int x = A[s+i], y = A[t-i-1];
			A[s+i] = y; A[t-i-1] = x;
		}
		return A;
	}
	private static String reverse (String S) { return new StringBuilder(S).reverse().toString(); }
	private static int root (int [] C, int s) {
		int res = s;
		while (C[res] != res)
			res = C[res];
		int v = s;
		while (v != res) {
			int w = v;
			v = C[w];
			C[w] = res;
		}
		return res;
	}
	private static <T> T [][] rotate (T [][] A) {
		assert A.length > 0 && A[0].length > 0;
		int N = A.length, M = A[0].length;
		T [][] res = newArray(A, M, N);
		for (int i = 0; i < N; ++i)
			for (int j = 0; j < M; ++j) {
				int [] R = rotate(A, i, j);
				res[R[0]][R[1]] = A[i][j];
			}
		return res;
	}
	private static <T> int [] rotate (T [][] A, int i, int j) {
		assert i < A.length && j < A[0].length;
		return new int [] { A[0].length - 1 - j, i };
	}
	private static int [] scalar (int c, int ... X) { return stream(X).map(x -> c * x).toArray(); }
	private static double [] scalar (double c, double ... X) { return stream(X).map(x -> c * x).toArray(); }
	private static int [] sep (int N) { return sep(0, N); }
	private static int [] sep (final int S, final int T) { if (S >= T) return new int [0]; int [] res = new int [T-S]; for (int i = S; i < T; ++i) res[T-1-i] = i; return res; }
	private static int [] seq (int N) { return seq(0, N); }
	private static int [] seq (int S, int T) { return sep(S, T+1); }
	private static <T> T [] shift(T [] A, int k) {
		int N = A.length;
		T [] res = newArray(A, N+k);
		System.arraycopy(A, 0, res, k, N);
		return res;
	}
	private static <T extends Comparable<T>> int [] si(final T [] X) { return si(X, reverseOrder(reverseOrder())); }
	private static <T> int [] si (final T [] X, final Comparator<T> C) {
		int N = X.length;
		return sort(singletons(N), new Comparator<Integer>() {
			public int compare(Integer i, Integer j) {
				int res = C.compare(X[i], X[j]);
				return res != 0 ? res : i.compareTo(j);
			}
		});
	}
	private static int [] singletons (int N) { int [] res = new int [N]; for (int i = 0; i < N; ++i) res[i] = i; return res; }
	private static int [] sort(int [] A) { return sort(A, defaultOrder()); }
	private static int [] sort(int [] A, Comparator<Integer> C) { Integer [] AA = obj(A); Arrays.sort(AA, C); return pri(AA, A); }
	private static long [] sort(long [] A) { return sort(A, defaultOrder()); }
	private static long [] sort(long [] A, Comparator<Long> C) { Long [] AA = obj(A); Arrays.sort(AA, C); return pri(AA, A); }
	private static <T> T [] sort(T [] A) { return sort(A, defaultOrder()); }
	private static <T> T [] sort(T [] A, Comparator<T> C) { Arrays.sort(A, C); return A; }
	private static <T> Queue<T> stack() { return asLifoQueue(new LinkedList<T>()); }
	private static int [] sum (int [] ... X) { return binOp((x,y) ->  x + y, X); }
	private static double [] sum (double [] ... X) { return binOp((x,y) ->  x + y, X); }
	private static int [] toInt (long [] A) { int [] res = new int [A.length]; for (int i = 0; i < A.length; ++i) res[i] = (int)A[i]; return res; }
	private static int [] toInt (String S) {
		int [] res = new int [S.length()];
		for (int i = 0; i < S.length(); ++i)
			res[i] = S.charAt(i) - '0';
		return res;
	}
	private static String [] toString (char [] ... A) { String [] res = new String[A.length]; for (int i = 0; i < A.length; ++i) res[i] = new String(A[i]); return res; }
	private static String toString (long x, int L) { return ("" + (power(10, L) + x)).substring(1); }
	private static <T> T [][] transpose(T [][] A) {
		int R = A.length, C = A[0].length;
		T [][] res = newArray(A, C);
		for (int i = 0; i < C; ++i) {
			res[i] = newArray(A[0], R);
			for (int j = 0; j < R; ++j)
				res[i][j] = A[j][i];
		}
		return res;
	}
	private static int [][] treeToEdges(int [] T) {
		int [][] res = new int [T.length - 1][];
		for (int i = 0, j = 0; i < T.length; ++i)
			if (T[i] != i)
				res[j++] = new int [] { T[i], i };
		return res;
	}
	private static <T> Tuple<T> tuple (@SuppressWarnings("unchecked") T ... A) { return new Tuple<T>(A); }
	private static String unquote (String S) {
		String Q = "\"";
		return S.startsWith(Q) && S.endsWith(Q) ? S.substring(1, S.length() - 1) : S;
	}
	private static String [] unquote (String [] S) {
		for (int i = 0; i < S.length; ++i)
			S[i] = unquote(S[i]);
		return S;
	}
	private static final double [][] upperEnvelope (long [][] A) {
		sort(A, lby(1, 0));
		Queue<long[]> Q = stack();

		for (long [] a : A) {
			while (Q.size() >= 2) {
				long [] b = Q.poll(), c = Q.peek();
				if ((a[1] - b[1]) * (b[0] - c[0]) > (b[1] - c[1]) * (a[0] - b[0])) {
					Q.add(b);
					break;
				}
			}
			if (Q.size() == 1 && Q.peek()[1] == a[1])
				Q.poll();
			Q.add(a);
		}

		double [][] res = new double [Q.size() + 1][]; res[Q.size()] = new double [] { LINF, LINF, LINF, LINF };
		for (int i = Q.size() - 1; i > 0; --i) {
			long [] a = Q.poll(), b = Q.peek();
			res[i] = new double [] { -1.0 * (a[0] -  b[0]) / (a[1] - b[1]), a[0], a[1] };
		}
		res[0] = new double [] { -LINF, Q.peek()[0], Q.peek()[1] };
		return res;
	}
	private static final double valueAt (double [][] P, long t) {
		assert P[0][0] < t && t < P[P.length-1][0] : t + " is not in (" + P[0][0] + ", " + P[P.length-1][0] + ")";
		int p = -1, q = P.length, m;
		while (q - p > 1) {
			m = (p + q) / 2;
			if (t < P[m][0])
				q = m;
			else
				p = m;
		}
		double res = 0;
		for (int i = 1, u = 1; i < P[p].length; ++i, u *= t)
			res += P[p][i] * u;
		return res;
	}
	private static int [][] vtk(int [][] KV, int W) {
		int [] C = new int [W+1];
		for (int [] kv : KV)
			C[kv[1]]++;
		int [][] res = new int [W+1][];
		for (int v = 0; v <= W; ++v)
			res[v] = new int [C[v]];
		fill(C, 0);
		for (int [] kv : KV)
			res[kv[1]][C[kv[1]]++] = kv[0];
		return res;
	}
	private static <T> TreeMap<T, Integer> vtk (@SuppressWarnings("unchecked") T ... A) {
		TreeMap<T, Integer> res = new TreeMap<>();
		for (int i = 0; i < A.length; ++i)
			res.put(A[i], i);
		return res;
	}
	private static int [][][] wgraph (int N, int [][] E) { return dwgraph(N, dup(E)); }
	private static boolean zero(double ... X) { return eq(norm(X), 0); }
	private static int [] zFunction(char [] C) {
		int [] res = new int [C.length];
		int L = 0, R = 1;
		for (int i = 1; i < C.length; ++i) {
			if (i < R) {
				res[i] = min(res[i-L], R-i);
				if (res[i] == R-i)
					for (int j = 0; R+j < C.length && C[R+j] == C[R-i+j]; ++j, ++res[i]);
			} else
				for (int j = 0; i+j < C.length && C[i+j] == C[j]; ++j, ++res[i]);
			if (res[i] >= R-i) {
				L = i;
				R = i + res[i];
			}
		}
		return res;
	}
	

	private interface AbstractCounter<K> extends Map<K, Long> {
		default boolean safeContainsKey(Object key) { if (!isEmpty()) keySet().iterator().next().getClass().cast(key); return containsKey(key); }
		default void dec (K key) { dec(key, 1); }
		default void dec (K key, long value) { inc(key, -value); }
		default void inc (K key) { inc(key, 1); }
		default void inc (K key, long value) { put(key, get(key) + value); }
		default void incAll (K [] keys) { for (K key : keys) inc(key); }
		default Entry<K, Long> maximum() {
			Entry<K, Long> res = null;
			for (Entry<K, Long> x : entrySet())
				if (res == null || x.getValue() > res.getValue())
					res = x;
			return res;
		}
		default void maximum(K key, long value) { put(key, max(get(key), value)); }
	}
	private static class AhoCorasick {
		private class Node {
			public final char c;
			public String dict = null;
			public final Node parent;
			public final HashMap<Character, Node> children = new HashMap<>();
			public Node suffix = null;
			public Node dictSuffix = null;
			public Node (Node parent, char c) { this.parent = parent; this.c = c; }
			public Node suffix (char c) {
				Node n = this;
				do {
					Node res = n.children.get(c);
					if (res != null)
						return res;
					n = n.suffix;
				} while (n != null);
				return root;
			}
			public String [] dict () {
				List<String> res = new ArrayList<>();
				if (dict != null)
					res.add(dict);
				Node n = this;
				while (n.dictSuffix != null)
					res.add(( n = n.dictSuffix).dict);
				return res.toArray(new String [0]);
			}
		}
		private final Node root = new Node(null, (char)0);
		public AhoCorasick(String [] W) {
			for (String w : W) {
				Node n = root;
				for (char c : w.toCharArray()) {
					if (!n.children.containsKey(c))
						n.children.put(c, new Node(n, c));
					n = n.children.get(c);
				}
				n.dict = w;
			}
			Queue<Node> Q = new LinkedList<>(); Q.add(root);
			while (!Q.isEmpty()) {
				Node n = Q.poll();
				if (n.parent != null) {
					n.suffix = n.parent.suffix != null ?
							n.parent.suffix.suffix(n.c) : root;
				}
				if (n.suffix != null) {
					n.dictSuffix = n.suffix.dict != null ?
							n.suffix : n.suffix.dictSuffix;
				}
				for (Node ch : n.children.values())
					Q.add(ch);
			}
		}
		public Iterable<String[]> process(final char [] C) {
			return new Iterable<String[]>() {
				@Override
				public Iterator<String[]> iterator() {
					return new Iterator<String[]>() {
						private int i = 0; private Node n = root;
						@Override public boolean hasNext() { return i < C.length; }
						@Override public String[] next() { return (n = n.suffix(C[i++])).dict(); }
					};
				}
			};
		}
	}
	private static class ByFraction {
		private final long N;
		protected final int R;
		protected final long [] L;
		protected final long [] H;
		protected ByFraction(long N) { this(N, (int) floor(sqrt(N))); }
		private ByFraction(long N, int R) { this(N, new long [R+1], new long [(int)(N/R)]); }
		public ByFraction(long N, long [] L, long [] H) {
			this.N = N; R = (int) floor(sqrt(N));
			this.L = L; this.H = H;
			assert L.length >= R+1 && H.length >= N/R;
		}
		public long getFraction (long i) { return i < N/R ? H[(int)i] : L[(int)(N/i)]; }
		public long get (int n) { assert n <= R; return L[n]; }
	}
	private static class Circle {
		public final double [] C;
		public final double R;
		public static final Circle R2 = new Circle(new double [2], INF);
		public Circle(double [] C, double R) { this.C = C; this.R = R; }
		public static Circle toCircumference(double [] ... X) {
			assert X.length > 0 && X.length <= 3;
			switch(X.length) {
			case 1: return new Circle(X[0], 0);
			case 2: return new Circle(scalar(.5, sum(X)), .5 * dist(X[0], X[1]));
			case 3:
				if (eq(X[0], X[1])) return toCircumference(X[1], X[2]);
				else if (eq(X[1], X[2])) return toCircumference(X[2], X[0]);
				else if (eq(X[2], X[0])) return toCircumference(X[0], X[1]);
				else return	calc(X[0], X[1], X[2]);
			default: throw new Error();
			}
		}
		public static Circle toCircle(double [] ... X) {
			assert X.length > 0; shuffle(asList(X));
			return welzl(X, X.length, new double[3][], 0);
		}
		private static Circle calc(double [] X, double [] Y, double [] Z) {
			boolean u = eq(X[0], Y[0]), v = eq(Y[0], Z[0]);
			if (u && v) return R2;
			else if (u) return calc(Y, Z, X);
			else if (v) return calc(Z, X, Y);
			else {
				double U = (Y[1] - X[1]) / (Y[0] - X[0]);
				double V = (Z[1] - Y[1]) / (Z[0] - Y[0]);
				if (eq(U, V)) return R2;
				if (eq(U, 0)) return calc(Z, Y, X);
				double CX = (U * V * (X[1] - Z[1]) + V * (X[0] + Y[0]) - U * (Y[0] + Z[0])) / (2 * (V - U));
				double CY = ((X[0] + Y[0]) / 2 - CX) / U + (X[1] + Y[1]) / 2;
				double [] C = new double [] { CX, CY };
				double R = dist(C, X); assert eq(dist(C, Y), R) && eq(dist(C, Z), R);
				return new Circle(C, R);
			}
		}
		private static Circle welzl(double [][] X, int N, double [][] S, int K) {
			if (K == 3) return Circle.toCircumference(S);
			else if (N == 0) {
				switch(K) {
				case 0: return new Circle(new double [3], -1);
				case 1: return new Circle(S[0], 0);
				case 2: return Circle.toCircumference(S[0], S[1]);
				default: throw new Error();
				}
			}
			else {
				Circle C = welzl(X, N-1, S, K);
				if (greater(dist(C.C, X[N-1]), C.R)) {
					S[K++] = X[N-1];
					C = welzl(X, N-1, S, K);
				}
				return C;
			}
		}
		public String toString() { Map<String, Object> M = new HashMap<>(); M.put("C", Arrays.toString(C)); M.put("R", R); return M.toString(); }
	}
	private static class Counter<K> extends TreeMap<K, Long> implements AbstractCounter<K> {
		private static final long serialVersionUID = 1L;
		public Counter (@SuppressWarnings("unchecked") K ... keys) { super(); incAll(keys); }
		public Long get (Object key) { return safeContainsKey(key) ? super.get(key) : 0L; }
		public Long put (K key, Long value) {
			long res = get(key);
			if (value != 0)
				super.put(key, value);
			else
				remove(key);
			return res;
		}
	}
	private static class Fenwick {
		private final long [] X;
		private final long mod;
		public Fenwick (int N) { this(N, 0); }
		public Fenwick (int N, int mod) { X = new long [N]; this.mod = mod; }
		public void add(long x, int i) {
			++i; assert i <= X.length;
			while (i <= X.length) {
				X[i-1] += x;
				if (mod > 0) X[i-1] = ((X[i-1] % mod) + mod) % mod;
				i += (i & (-i));
			}
		}
		public long get(int to) {
			assert to <= X.length;
			long res = 0;
			for (; to > 0; to -= (to & (-to))) {
				res += X[to-1];
				if (mod > 0) res = ((res % mod) + mod) % mod;
			}
			return res;
		}
		public long get(int from, int to) {
			assert from <= to;
			long res = get(to) - get(from);
			if (mod > 0) res = ((res % mod) + mod) % mod;
			return res;
		}
	}
	private static class HashCounter<K> extends HashMap<K, Long> implements AbstractCounter<K> {
		private static final long serialVersionUID = 1L;
		public HashCounter (@SuppressWarnings("unchecked") K ... keys) { super(); incAll(keys); }
		public Long get (Object key) { return safeContainsKey(key) ? super.get(key) : 0L; }
		public Long put (K key, Long value) {
			long res = get(key);
			if (value != 0)
				super.put(key, value);
			else
				remove(key);
			return res;
		}
	}
	private static class LCA {
		private int [][] P;
		private int [] L;
		public LCA(int [] T) {
			int N = T.length, G = Integer.numberOfTrailingZeros(Integer.highestOneBit(2*N));
			L = new int [N]; fill(L, -1);
			for (int i = 0; i < N; ++i)
				level(T, i);
			P = new int [N][G];
			for (int i = 0; i < N; ++i)
				P[i][0] = T[i];
			for (int j = 1; j < G; ++j)
				for (int i = 0; i < N; ++i)
					if (P[i][j - 1] != -1)
						P[i][j] = P[P[i][j - 1]][j - 1];
		}
		public int query(int p, int q) {
			if (L[p] < L[q])
				return query(q, p);
			int log; for (log = 1; (1 << log) <= L[p]; ++log); --log;
			for (int i = log; i >= 0; --i)
				if (L[p] - (1 << i) >= L[q])
					p = P[p][i];
			if (p == q)
				return p;
			for (int i = log; i >= 0; --i)
				if (P[p][i] != P[q][i]) {
					p = P[p][i];
					q = P[q][i];
				}
			assert P[p][0] == P[q][0];
			return P[p][0];
		}
		private int level(int [] T, int i) {
			if (T[i] == i)
				L[i] = 0;
			else if (L[i] == -1)
				L[i] = 1 + level(T, T[i]);
			return L[i];
		}
	}
	private static class MatrixRangeSum {
		private final long [][] S;
		public long get(int r1, int c1, int r2, int c2) { return S[r2][c2] - S[r1][c2] - S[r2][c1] + S[r1][c1]; }
		public MatrixRangeSum (long [][] A) {
			int R = A.length, C = A[0].length;
			S = new long [R+1][C+1];
			for (int i = 1; i <= R; ++i)
				for (int j = 1; j <= C; ++j)
					S[i][j] = S[i-1][j] + S[i][j-1] - S[i-1][j-1] + A[i-1][j-1];
		}
	}
	private static class PrimeSum extends ByFraction {
		public interface TMF {
			long get (long N);
			long sum (long N);
		}
		public PrimeSum (TMF f, long N) {
			super(N);
			for (int i = 1; i < N/R; ++i)
				H[i] = f.sum(N/i);
			for (int i = 2; i <= R; ++i)
				L[i] = f.sum(i);
			for (int p = 2; p <= R; ++p)
				if (L[p] != L[p-1]) {
					long fp = f.get(p), sp = L[p-1], p2 = 1L*p*p;
					for (int i = 1; N/i >= p2 && i < R; ++i) {
						long fip = getFraction(i*p);
						H[i] -= fp * (fip - sp);
					}
					for (int i = R; i >= p2; --i)
						L[i] -= fp * (L[i/p] - sp);
				}
		}
		public static PrimeSum pi (long N) {
			return new PrimeSum(new TMF() {
				public long get (long N) { return 1; }
				public long sum (long N) { return N-1; }
			}, N);
		}
	}
	private static class Rodrigues {
		private final double [] K, T;
		public Rodrigues(double ... A) {
			assert A.length <= 3; A = copyOf(A, 3);
			K = normalize(new double [] { -A[1], A[0] }); double [] L = new double [] { K[1], -K[0] };
			if (!zero(K)) {
				double [] V = new double [3];
				while (zero(V))
					V = project(project(new double [] { random(), random(), random() }, A), K);
				T = normalize(new double [] { dot(L, V), V[2] });
			} else
				T = null;
		}
		public double [] rotate(double ... X) {
			assert X.length <= 3; X = copyOf(X, 3); double [] res = X;
			if (T != null) {
				res = scalar(T[0], X);
				res = sum(res, scalar(T[1], cross(K, X)));
				res = sum(res, scalar(dot(K, X) * (1 - T[0]), K));
			}
			assert eq(res[2], 0);
			res = copyOf(res, 2);
			return res;
		}
	}
	private static class RootedTree {
		final int [] J, D, H;
		RootedTree (int [][] F, int R) {
			int N = F.length;
			J = new int [N]; D = new int [N]; H = new int [N]; fill(J, -1);

			int [] S = new int [N];

			{
				int L = 1, j = 0; S[0] = R;
				while (L > 0) {
					int q = S[--L]; J[q] = j++;
					for (int i = 0; i < F[q].length; ++i)
						if (J[F[q][i]] == -1)
							S[L++] = F[q][i]; 

						else
							D[J[q]] = 1 + D[J[F[q][i]]]; 

				}
			}

			{
				int [][] G = new int [N][];
				for (int i = 0; i < N; ++i)
					G[J[i]] = F[i];

				int M = 1, L = 1; S[0] = 0;
				while (L > 0) {
					int q = S[--L];
					if (q >= 0) {
						S[L++] = -(q+1); 

						for (int i = 0; i < G[q].length; ++i)
							if (J[G[q][i]] > q)
								S[L++] = J[G[q][i]]; 

					} else {
						q = -(q+1); 

						H[q] = M = max(M, q+1);
					}
				}
			}
		}
	}
	private static class SetNode<T> {
		@SuppressWarnings("rawtypes")
		private final SetNode L, R;
		private final int from, to, m;
		private T X = null;
		public SetNode(int N) { this(0, N); }
		public void set(T X, int from, int to) {
			assert(from >= this.from && to <= this.to && from < to);
			if (from == this.from && to == this.to)
				this.X = X;
			else {
				dfs(this.X, this.from, from);
				dfs(X, from, to);
				dfs(this.X, to, this.to);
				this.X = null;
			}
		}
		@SuppressWarnings("unchecked")
		public T get(int i) {
			assert(from <= i && i < to);
			T res = null;
			if (X != null)
				res = X;
			else if (i < m)
				res = (T)L.get(i);
			else if (i >= m && m > from)
				res = (T)R.get(i);
			else
				assert false;
			return res;
		}
		@SuppressWarnings("rawtypes")
		private SetNode(int from, int to) {
			assert(from < to);
			this.from = from;
			this.to = to;
			m = (from + to) / 2;
			if (m > from) {
				L = new SetNode(from, m);
				R = new SetNode(m, to);
			} else
				L = R = null;
		}
		@SuppressWarnings("unchecked")
		private void dfs(T X, int from, int to) {
			if (X == null)
				return;
			if (from == to)
				return;
			if (from < m)
				L.set(X, from, min(to, m));
			if (to > m)
				R.set(X, max(from, m), to);
		}
	}
	private static class SumNode {
		private final SumNode L, R;
		private final int from, to, m;
		private long X = 0;
		public SumNode(int N) { this(0, N); }
		public void add(long X, int from, int to) {
			assert(from >= this.from && to <= this.to && from < to);
			if (from == this.from && to == this.to)
				this.X += X;
			else {
				if (from < m)
					L.add(X, from, min(to, m));
				if (to > m)
					R.add(X, max(from, m), to);
			}
		}
		private long get(int i) {
			assert(from <= i && i < to);
			long res = X;
			if (i < m)
				res += L.get(i);
			if (i >= m && m > from)
				res += R.get(i);
			return res;
		}
		private SumNode(int from, int to) {
			assert(from < to);
			this.from = from;
			this.to = to;
			m = (from + to) / 2;
			if (m > from) {
				L = new SumNode(from, m);
				R = new SumNode(m, to);
			} else
				L = R = null;
		}
	}
	private static class Tuple<T> extends Tu.ple<T> { public Tuple(@SuppressWarnings("unchecked") T ... a) { super(a); }}
	private static class Tu {
		private static class ple<T> implements Comparable<ple<T>> {
			public final T [] a;
			public ple(@SuppressWarnings("unchecked") T ... a) { this.a = a; }
			@SuppressWarnings("unchecked") public int compareTo (ple<T> o) {
				if (a.length > o.a.length)
					return -o.compareTo(this);
				for (int i = 0; i < a.length; ++i)
					if (((Comparable<T>)a[i]).compareTo(o.a[i]) != 0)
						return ((Comparable<T>)a[i]).compareTo(o.a[i]);
				return a.length - o.a.length;
			}
			@SuppressWarnings("unchecked") public boolean equals (Object o) { return Arrays.equals(a, ((ple<T>)o).a); }
			public int hashCode () { return Arrays.hashCode(a); };
			public String toString () { return Arrays.toString(a); }
		}
	}
	private static void statics () { probablePrime(-1, null); Arrays.sort(new Object [0]); reverseOrder(); of(0); }
	

	private static IOUtils.MyScanner sc = new IOUtils.MyScanner();
	private static void start() { IOUtils.start(); }
	private static void clock(Object o, Object ... A) { IOUtils.err(IOUtils.time(), o, A); }
	private static void err(Object o, Object ... A) { IOUtils.err(o, A); }
	private static Object print (Object o, Object ... A) { IOUtils.print(o, A); return null; }
	private static Object exit (Object o, Object ... A) { print(o, A); IOUtils.exit(); return null; }
	private static Object println(Object o) { return IOUtils.println(o); }
	private static Object println(Object o, Object p, Object ...a) { return IOUtils.println(o, p, a); }
	private static class IOUtils {
		public static class MyScanner {
			public String next() { newLine(); return line[index++]; }
			public char nextChar() { return next().charAt(0); }
			public int nextInt() { return Integer.parseInt(next()); }
			public long nextLong() { return Long.parseLong(next()); }
			public double nextDouble() { return Double.parseDouble(next()); }
			public String nextLine() { line = null; return readLine(); }
			public String [] nextStrings() { return split(nextLine()); }
			public char [] nextChars() { return next ().toCharArray (); }
			public int[] nextInts() { return nextStream().mapToInt(Integer::parseInt).toArray(); }
			public long[] nextLongs() { return nextStream().mapToLong(Long::parseLong).toArray(); }
			public double[] nextDoubles() { return nextStream().mapToDouble(Double::parseDouble).toArray(); }
			public String[] next(int N) { return IntStream.range(0, N).mapToObj(i -> next()).toArray(String[]::new); }
			public int[] nextInt(int N) { return IntStream.range(0, N).map(i -> nextInt()).toArray(); }
			public long[] nextLong(int N) { return IntStream.range(0, N).mapToLong(i -> nextLong()).toArray(); }
			public double[] nextDouble(int N) { return IntStream.range(0, N).mapToDouble(i -> nextDouble()).toArray(); }
			public String[] nextLine(int N) { return IntStream.range(0, N).mapToObj(i -> nextLine()).toArray(String[]::new); }
			public String[][] nextStrings(int N) { return IntStream.range(0, N).mapToObj(i -> nextStrings()).toArray(String[][]::new); }
			public char[][] nextChars(int N) { return IntStream.range(0, N).mapToObj(i -> nextChars()).toArray(char[][]::new); }
			public int[][] nextInts(int N) { return IntStream.range(0, N).mapToObj(i -> nextInts()).toArray(int[][]::new); }
			public long[][] nextLongs(int N) { return IntStream.range(0, N).mapToObj(i -> nextLongs()).toArray(long[][]::new); }
			public double[][] nextDoubles(int N) { return IntStream.range(0, N).mapToObj(i -> nextDoubles()).toArray(double[][]::new); }
			

			private boolean eol() { return index == line.length; }
			private String readLine() {
				try {
					return r.readLine();
				} catch (Exception e) {
					throw new Error (e);
				}
			}
			private final java.io.BufferedReader r;
			private MyScanner () { this(new java.io.BufferedReader(new java.io.InputStreamReader(System.in))); }
			private MyScanner (java.io.BufferedReader r) {
				try {
					this.r = r;
					while (!r.ready())
						Thread.sleep(1);
					start();
				} catch (Exception e) {
					throw new Error(e);
				}
			}
			private String [] line;
			private int index;
			private void newLine() {
				if (line == null || eol()) {
					line = split(readLine());
					index = 0;
				}
			}
			private java.util.stream.Stream<String> nextStream() { return java.util.Arrays.stream(nextStrings()); }
			private String [] split(String s) { return s.length() > 0 ? s.split(" ") : new String [0]; }
		}
		private static class MyWriter extends java.io.PrintWriter {
			public MyWriter lnprint(Object o, Object ...a) { println(); print(IOUtils.build(o, a)); return this; }
			public String toString() { return out.toString(); }
			public MyWriter() { super(new java.io.StringWriter()); }
		}
		private static String build(Object o, Object ... A) { return buildDelim(" ", o, A); }
		private static String buildDelim(String delim, Object o, Object ... A) {
			StringBuilder b = new StringBuilder();
			append(b, o, delim);
			for (Object p : A)
				append(b, p, delim);
			return b.substring(delim.length());
		}
		private static MyWriter println(Object o) {
			MyWriter res = new MyWriter();
			append(res::lnprint, res::lnprint, o);
			return res;
		}
		private static MyWriter println(Object o, Object p, Object ...a) {
			MyWriter res = new MyWriter();
			res.lnprint(o).lnprint(p);
			java.util.Arrays.stream(a).forEach(res::lnprint);
			return res;
		}
		

		private static final java.text.DecimalFormat formatter = new java.text.DecimalFormat("#.#########");
		private static void start() { if (t == 0) t = millis(); }
		private static void append(java.util.function.Consumer<Object> f, java.util.function.Consumer<Object> g, final Object o) {
			if (o.getClass().isArray()) {
				int len = java.lang.reflect.Array.getLength(o);
				for (int i = 0; i < len; ++i)
					f.accept(java.lang.reflect.Array.get(o, i));
			}
			else if (o instanceof Iterable<?>)
				((Iterable<?>)o).forEach(f::accept);
			else
				g.accept(o instanceof Double ? formatter.format(o) : o);
		}
		private static void append(final StringBuilder b, Object o, final String delim) {
			append(x -> { append(b, x, delim); }, x -> b.append(delim).append(x), o);
		}
		private static java.io.PrintWriter pw = new java.io.PrintWriter(System.out);
		private static Object print(Object o, Object ... A) { pw.println(build(o, A)); return null; }
		private static void err(Object o, Object ... A) { System.err.println(build(o, A)); }
		private static boolean PRINT;
		private static void write(Object o) {
			err(o, '(', time(), ')');
			if (PRINT)
				pw.println(o);
		}
		private static void exit() {
			IOUtils.pw.close();
			System.out.flush();
			err("------------------");
			err(time());
			System.exit(0);
		}
		private static long t;
		private static long millis() { return System.currentTimeMillis(); }
		private static String time() { return "Time: " + (millis() - t) / 1000.0; }
		private static void run(int N) {
			try { PRINT = System.getProperties().containsKey("PRINT"); }
			catch (Throwable t) {}

			for (int n = 1; n <= N; ++n) {
				Object res = new D().solve();
				if (res != null)
					write("Case #" + n + ": " + build(res));
			}
			exit();
		}
	}
	

	public static void main(String[] args) {
		init();
		int N = ONE_TEST_CASE ? 1 : sc.nextInt();
		IOUtils.run(N);
	}
}

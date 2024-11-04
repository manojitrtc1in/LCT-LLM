import static java.lang.Math.*;
import static java.lang.System.*;
import static java.math.BigInteger.*;
import static java.util.Arrays.*;
import static java.util.Collections.*;

import java.util.*;
import java.util.Map.Entry;

public class C {

	private final static boolean autoflush = false;

	private static final int INF = (int) 1e9;
	private static final int MOD = (int) 1e9 + 7;
	private static final double eps = 1e-9;

	public C () {
		int N = sc.nextInt();
		Integer [] S = sc.nextInts();

		Integer [] J = invert(si(S));
		sort(S);

		int C = (int)ceil(N/3.0);
		Integer [] A = new Integer [3*C+1]; fill(A, 0);
		Integer [] B = new Integer [3*C+1]; fill(B, 0);
		S = copyOf(S, 3*C+1); fill(S, N, 3*C+1, 0);

		arraycopy(S, 0, B, 0, C+1);
		arraycopy(S, C+1, A, C+1, C);
		for (int i = 2*C+1; i <= 3*C; ++i) {
			A[i] = 3*C + 1 - i;
			B[i] = S[i] - A[i];
		}

		A = permute(copyOf(A, N), J);
		B = permute(copyOf(B, N), J);

		print("YES");
		print(A);
		exit(B);
	}

	<T> T [] permute(T [] A, Integer [] J) {
		T [] res = A.clone();
		for (int i = 0; i < J.length; ++i)
			res[i] = A[J[i]];
		return res;
	}

	Integer [] invert(Integer [] J) {
		int N = J.length;
		Integer [] res = new Integer [N];
		for (int i = 0; i < N; ++i)
			res[J[i]] = i;
		return res;
	}

	

	private static int [] rep(int N) { return rep(0, N); }
	private static int [] rep(int S, int T) { if (T <= S) return new int [0]; int [] res = new int [T-S]; for (int i = S; i < T; ++i) res[i-S] = i; return res; }
	private static int [] req(int S, int T) { return rep(S, T+1); }
	private static int [] sep(int N) { return sep(0, N); }
	private static int [] sep(int S, int T) { if (T <= S) return new int [0]; int [] res = new int [T-S]; for (int i = S; i < T; ++i) res[T-1-i] = i; return res; }
	private static int [] seq(int S, int T) { return sep(S, T+1); }
	private static int [] ccw (int [] D) { return new int [] { -D[1], D[0] }; }
	private static int [] cw (int [] D) { return new int [] { D[1], -D[0] }; }
	private static int [] digits(long N, int B, int sz) {
		int [] res = new int [sz];
		for (int i = sz - 1; i >= 0; --i)
			if (N > 0) {
				res[i] = (int)(N % B);
				N /= B;
			}
		return res;
	}
	private static int digitSum(long N) {
		int res = 0;
		for (; N > 0; res += N % 10, N /= 10);
		return res;
	}
	private static <T extends Comparable<T>> T max(T x, T y) { return x.compareTo(y) > 0 ? x : y; }
	private static long mod(long x) { return mod(x, MOD); }
	private static long mod(long x, long mod) { return ((x % mod) + mod) % mod; }
	private static long modInv(long x) { return modPow(x, -1); }
	private static long modPow(long b, long e) { return valueOf(b).modPow(valueOf(e), valueOf(MOD)).longValue(); }
	private static long [] modFact(int N) {
		long [] res = new long [N]; res[0] = 1;
		for (int i = 1; i < N; ++i)
			res[i] = mod(res[i-1] * i);
		return res;
	}
	private static long [][] modBin(int N, int K) {
		long [][] res = new long [N+1][K+1];
		for (int n = 0; n <= N; ++n) {
			res[n][0] = 1;
			for (int k = 1; k <= K && k <= n; ++k)
				res[n][k] = mod(res[n-1][k] + res[n-1][k-1]);
		}
		return res;
	}
	private static long pow(long b, long e) { return round(Math.pow(b, e)); }
	private static String reverse (String S) { return new StringBuilder(S).reverse().toString(); }
	@SuppressWarnings("unchecked")
	private static <T> T [] newArray(T [] A, int N) { return (T[]) java.lang.reflect.Array.newInstance(A.getClass().getComponentType(), N); }
	private static <T> T [] shift(T [] A, int k) {
		int N = A.length;
		T [] res = newArray(A, N+k);
		System.arraycopy(A, 0, res, k, N);
		return res;
	}
	private static char [][] toCharArrays(String [] S) {
		int N = S.length;
		char [][] res = new char [N][];
		for (int i = 0; i < N; ++i)
			res[i] = S[i].toCharArray();
		return res;
	}
	private static int [][] graph (int N, Integer [][] E) { return lgraph(N, E)[0]; }
	private static int [][][] lgraph(int N, Integer [][] E) {
		int [] D = new int [N];
		for (Integer [] e : E) {
			int x = e[0] - 1, y = e[1] - 1;
			++D[x]; ++D[y];
		}
		int [][][] res = new int [2][N][];
		for (int i = 0; i < 2; ++i)
			for (int j = 0; j < N; ++j)
				res[i][j] = new int [D[j]];
		D = new int [N];
		for (Integer [] e : E) {
			int x = e[0] - 1, y = e[1] - 1, z = e.length > 2 ? e[2] : 1;
			res[0][x][D[x]] = y; res[0][y][D[y]] = x;
			res[1][x][D[x]] = res[1][y][D[y]] = z;
			++D[x]; ++D[y];
		}
		return res;
	}
	private static class SetNode<T> {
		final SetNode<T> L, R;
		final int from, to, m;
		final T NO_VALUE;
		T X = null;
		SetNode(int from, int to, T NO_VALUE) {
			assert(from < to);
			this.NO_VALUE = NO_VALUE;
			this.from = from;
			this.to = to;
			m = (from + to) / 2;
			if (m > from) {
				L = new SetNode<T>(from, m, NO_VALUE);
				R = new SetNode<T>(m, to, NO_VALUE);
			} else
				L = R = null;
		}
		void set(T X, int from, int to) {
			assert(from >= this.from && to <= this.to && from < to);
			if (from == this.from && to == this.to)
				this.X = X;
			else {
				dfs(this.X, this.from, from);
				dfs(X, from, to);
				dfs(this.X, to, this.to);
				this.X = NO_VALUE;
			}
		}
		void dfs(T X, int from, int to) {
			if (NO_VALUE.equals(X))
				return;
			if (from == to)
				return;
			if (from < m)
				L.set(X, from, min(to, m));
			if (to > m)
				R.set(X, max(from, m), to);
		}
		T get(int i) {
			assert(from <= i && i < to);
			T res = null;
			if (!NO_VALUE.equals(X))
				res = X;
			else if (i < m)
				res = L.get(i);
			else if (i >= m && m > from)
				res = R.get(i);
			else
				assert false;
			return res;
		}
	}
	private static class SumNode {
		private final SumNode L, R;
		private final int from, to, m;
		private long X = 0;
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
		private void add(long X, int from, int to) {
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
	}
	private static <T extends Comparable<T>> Integer [] si(final T [] X) {
		return si(X, new Comparator<T> () {
			public int compare (T x, T y) {
				return x.compareTo(y);
			}
		});
	}
	private static <T> Integer [] si(final T [] X, final Comparator<T> C) {
		int N = X.length;
		Integer [] J = new Integer [N];
		for (int i = 0; i < N; ++i)
			J[i] = i;
		sort(J, new Comparator<Integer>() {
			public int compare(Integer i, Integer j) {
				int res = C.compare(X[i], X[j]);
				return res != 0 ? res : i.compareTo(j);
			}
		});
		return J;
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
	private static void prefixFunction(char [] C, char [] P, int [] F, int i) {
		int j = i > 0 ? F[i-1] : 0;
		for (int k = 0; k < C.length; ++k)
			if (i+k > 0) {
				while (j > 0 && C[k] != P[j])
					j = F[j-1];
				if (C[k] == P[j])
					++j;
				F[i+k] = j;
			}
	}
	private static class Counter<T> extends TreeMap<T, Integer> {
		private static final long serialVersionUID = 1L;
		public Integer get(Object key) { return containsKey(key) ? super.get(key) : 0; }
		public void inc(T key) { super.put(key, 1 + get(key)); }
		public Entry<T, Integer> max() {
			Entry<T, Integer> max = null;
			for (Entry<T, Integer> x : entrySet())
				if (max == null || x.getValue() > max.getValue())
					max = x;
			return max;
		}
		public Integer put(T key, Integer value) { throw new UnsupportedOperationException(); }
	}
	private static int [] singletons(int N) {
		int [] res = new int [N];
		for (int i = 0; i < N; ++i)
			res[i] = i;
		return res;
	}
	private static int dsu(int [][] E, int s, int t, int [] C) {
		int res = 0;
		for (int i = s; i < t; ++i) {
			int [] e = E[i];
			int u = root(C, e[0]), v = root(C, e[1]);
			if (u != v)
				++res;
			C[u] = C[v];
		}
		return res;
	}
	private static int root (int [] C, int s) {
		int res = s;
		while (C[res] != res)
			res = C[res];
		int v = s;
		while (v != res) {
			v = C[v];
			C[v] = res;
		}
		return C[s] = res;
	}
	

	private final static MyScanner sc = new MyScanner();
	private static class MyScanner {
		private String next() { newLine(); return line[index++]; }
		private char nextChar() { return next().charAt(0); }
		private int nextInt() { return Integer.parseInt(next()); }
		private long nextLong() { return Long.parseLong(next()); }
		private double nextDouble() { return Double.parseDouble(next()); }
		private String nextLine() { line = null; return readLine(); }
		private String [] nextStrings() { line = null; return readLine().split(" "); }
		private char [] nextChars() { return next ().toCharArray (); }
		private Integer [] nextInts() {
			String [] L = nextStrings();
			Integer [] res = new Integer [L.length];
			for (int i : rep(L.length))
				res[i] = Integer.parseInt(L[i]);
			return res;
		}
		private Long [] nextLongs() {
			String [] L = nextStrings();
			Long [] res = new Long [L.length];
			for (int i : rep(L.length))
				res[i] = Long.parseLong(L[i]);
			return res;
		}
		private Double [] nextDoubles() {
			String [] L = nextStrings();
			Double [] res = new Double [L.length];
			for (int i : rep(L.length))
				res[i] = Double.parseDouble(L[i]);
			return res;
		}
		private String [] next (int N) {
			String [] res = new String [N];
			for (int i : rep(N))
				res[i] = next();
			return res;
		}
		private Integer [] nextInt (int N) {
			Integer [] res = new Integer [N];
			for (int i : rep(N))
				res[i] = nextInt();
			return res;
		}
		private Long [] nextLong (int N) {
			Long [] res = new Long [N];
			for (int i : rep(N))
				res[i] = nextLong();
			return res;
		}
		private Double [] nextDouble (int N) {
			Double [] res = new Double [N];
			for (int i : rep(N))
				res[i] = nextDouble();
			return res;
		}
		private String [][] nextStrings (int N) {
			String [][] res = new String [N][];
			for (int i : rep(N))
				res[i] = nextStrings();
			return res;
		}
		private Integer [][] nextInts (int N) {
			Integer [][] res = new Integer [N][];
			for (int i : rep(N))
				res[i] = nextInts();
			return res;
		}
		private Long [][] nextLongs (int N) {
			Long [][] res = new Long [N][];
			for (int i : rep(N))
				res[i] = nextLongs();
			return res;
		}
		private Double [][] nextDoubles (int N) {
			Double [][] res = new Double [N][];
			for (int i : rep(N))
				res[i] = nextDoubles();
			return res;
		}
		

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
				line = readLine().split(" ");
				index = 0;
			}
		}
	}
	private static void print (Object o, Object... a) { printDelim(" ", o, a); }
	private static void cprint (Object o, Object... a) { printDelim("", o, a); }
	private static void printDelim (String delim, Object o, Object... a) { pw.println(build(delim, o, a)); }
	private static void exit (Object o, Object... a) { print(o, a); exit(); }
	private static void exit() {
		pw.close();
		System.out.flush();
		System.err.println("------------------");
		System.err.println("Time: " + ((millis() - t) / 1000.0));
		System.exit(0);
	}
	private static void NO() { throw new Error("NO!"); }
	

	private static String build (String delim, Object o, Object... a) {
		StringBuilder b = new StringBuilder();
		append(b, o, delim);
		for (Object p : a)
			append(b, p, delim);
		return b.substring(delim.length());
	}
	private static void append(StringBuilder b, Object o, String delim) {
		if (o.getClass().isArray()) {
			int L = java.lang.reflect.Array.getLength(o);
			for (int i = 0; i < L; ++i)
				append(b, java.lang.reflect.Array.get(o, i), delim);
		} else if (o instanceof Iterable<?>)
			for (Object p : (Iterable<?>)o)
				append(b, p, delim);
		else
			b.append(delim).append(o);
	}
	

	private static void start() { t = millis(); }
	private static java.io.PrintWriter pw = new java.io.PrintWriter(System.out, autoflush);
	private static long t;
	private static long millis() { return System.currentTimeMillis(); }
	private static void statics() { abs(0); valueOf(0); asList(new Object [0]); reverseOrder(); }
	public static void main (String[] args) { new C(); exit(); }
}

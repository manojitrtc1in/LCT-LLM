import java.util.Arrays;
import java.io.*;
import java.util.*;
import java.util.Random;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;


public class Main {
	
	static SegmentTree st;
	static boolean can;
	
	public static void solve() {
		int n = in.nextInt();
		long[] a = in.nl(n);
		st = new SegmentTree(a);
		can = true;
		long[][] vs = new long[n][2];
		for(int i = 0; i<n; i++) {
			vs[i][0] = a[i];
			vs[i][1] = i;
		}
		Util.shuffle(vs);
		Arrays.sort(vs, (x,y)->-Long.compare(x[0], y[0]));
		
		for(int i = 0; i<n&&can; i++) {
			long v = st.query(0, n-1);
			if(v>vs[i][0]) {
				can = false;
			}
			st.update(((int)vs[i][1]), Integer.MIN_VALUE);
		}
		
		out.yesNo(can);
	}
	
	static class Segment{
		long prefix, mid, suffix, sum;
		public Segment(int v) {
			this.sum = v;
			v = Math.max(Integer.MIN_VALUE, v);
			this.prefix = v;
			this.mid = v;
			this.suffix = v;
		}
		public void changeAll(long a) {
			this.sum = a;
			a = Math.max(Integer.MIN_VALUE, a);
			this.prefix = a;
			this.mid = a;
			this.suffix = a;
		}
		public void updateSegment(Segment l, Segment r) {
			this.sum = l.sum + r.sum;
			this.mid = Math.max(l.suffix + r.prefix, Math.max(l.mid, r.mid));
			this.prefix = Math.max(l.prefix,l.sum + r.prefix);
			this.suffix = Math.max(r.suffix, l.suffix + r.sum);
		}
	}
	
	
	static class SegmentTree{
		private Segment[] tree;
		int n;
		
		public SegmentTree(long[] a) {
			this.n = a.length;
			this.tree = new Segment[4*n];
			for(int i = 0; i<4*n; i++) tree[i] = new Segment(0);
			build(0, 0, n-1, a);
 		}
		
		public SegmentTree(int n) {
			this.n = n;
			this.tree = new Segment[4*n];
			for(int i = 0; i<4*n; i++) tree[i] = new Segment(0);
		}

		private void build(int idx, int l, int r, long[] a) {
			if(l==r) {
				tree[idx].changeAll(a[l]);
			} else {
				int m = (l+r)/2;
				build(2*idx+1, l, m, a);
				build(2*idx+2,m+1,r, a);
				tree[idx].updateSegment(tree[2*idx+1], tree[2*idx+2]);
			}
		}
		
		public void update(int idx, long val) {
			updateUtil(0, 0, n-1, idx, val);
		}
		
		private void updateUtil(int idx ,int l, int r, int i, long val) {
			if(l==r) tree[idx].changeAll(val);
			else {
				int md = (l+r)/2;
				if(i<=md) updateUtil(2*idx+1, l, md, i, val);
				else updateUtil(2*idx+2, md+1, r, i, val);
				tree[idx].updateSegment(tree[2*idx+1], tree[2*idx+2]);
			}
		}
		
		public long query(int l, int r) {
			return queryUtil(0, l, r, 0, n-1).mid;
		}
		
		private Segment queryUtil(int idx, int lBound, int rBound, int l, int r) {
			if(rBound < l || r < lBound) return new Segment(0);
			if(lBound <= l && r<= rBound) return tree[idx];
			int md = (l+r)/2;
			Segment merge = new Segment(0);
			merge.updateSegment(queryUtil(2*idx+1, lBound, rBound, l, md), queryUtil(2*idx+2, lBound, rBound, md+1, r));
			return merge;
		}
	}
	public static void main(String[] args) {
		in = new Reader();
		out = new Writer();
		int t = in.nextInt();
		while(t-->0) solve();
		out.exit();
	}
	static Reader in; static Writer out;

static class Reader {
	
	private BufferedReader br;
	private StringTokenizer st;
	
	public Reader() {
		br = new BufferedReader(new InputStreamReader(System.in));
	}
	
	public Reader(String f){
		try {
			br = new BufferedReader(new FileReader(f));
		} catch (IOException e) {
			e.printStackTrace();
		}
	}
	
	public int[] na(int n) {
		int[] a = new int[n];
		for (int i = 0; i < n; i++) a[i] = nextInt();
		return a;
	}

	public double[] nd(int n) {
		double[] a = new double[n];
		for (int i = 0; i < n; i++) a[i] = nextDouble();
		return a;
	}
	
	public long[] nl(int n) {
		long[] a = new long[n];
		for (int i = 0; i < n; i++) a[i] = nextLong();
		return a;
	}

	public char[] nca() {
		return next().toCharArray();
	}

	public String[] ns(int n) {
		String[] a = new String[n];
		for (int i = 0; i < n; i++) a[i] = next();
		return a;
	}

	public int nextInt() {
		ensureNext();
		return Integer.parseInt(st.nextToken());
	}

	public double nextDouble() {
		ensureNext();
		return Double.parseDouble(st.nextToken());
	}

	public Long nextLong() {
		ensureNext();
		return Long.parseLong(st.nextToken());
	}

	public String next() {
		ensureNext();
		return st.nextToken();
	}
	
	public String nextLine() {
		try {
			return br.readLine();
		} catch (Exception e) {
			e.printStackTrace();
			return null;
		}
	}
	
	private void ensureNext() {
		if (st == null || !st.hasMoreTokens()) {
			try {
				st = new StringTokenizer(br.readLine());
			} catch (IOException e) {
				e.printStackTrace();
			}
		}
	}
}

static class Util {

	private static Random random = new Random();
	private static long MOD;
	static long[] fact, inv, invFact;

	public static void initCombinatorics(int n, long mod, boolean inversesToo, boolean inverseFactorialsToo) {
		MOD = mod;
		fact = new long[n + 1];
		fact[0] = 1;
		for (int i = 1; i < n + 1; i++) fact[i] = (fact[i - 1] * i) % mod;

		if (inversesToo) {
			inv = new long[n + 1];
			inv[1] = 1;
			for (int i = 2; i <= n; ++i) inv[i] = (mod - (mod / i) * inv[(int) (mod % i)] % mod) % mod;
		}

		if (inverseFactorialsToo) {
			invFact = new long[n + 1];
			invFact[n] = Util.modInverse(fact[n], mod);
			for (int i = n - 1; i >= 0; i--) {
				if (invFact[i + 1] == -1) {
					invFact[i] = Util.modInverse(fact[i], mod);
					continue;
				}
				invFact[i] = (invFact[i + 1] * (i + 1)) % mod;
			}
		}
	}

	public static long modInverse(long a, long mod) {
		long[] gcdE = gcdExtended(a, mod);
		if (gcdE[0] != 1) return -1; 

		long x = gcdE[1];
		return (x % mod + mod) % mod;
	}

	public static long[] gcdExtended(long p, long q) {
		if (q == 0) return new long[] { p, 1, 0 };
		long[] vals = gcdExtended(q, p % q);
		long tmp = vals[2];
		vals[2] = vals[1] - (p / q) * vals[2];
		vals[1] = tmp;
		return vals;
	}

	public static long nCr(int n, int r) {
		if (r > n) return 0;
		return (((fact[n] * invFact[r]) % MOD) * invFact[n - r]) % MOD;
	}

	public static long nPr(int n, int r) {
		if (r > n) return 0;
		return (fact[n] * invFact[n - r]) % MOD;
	}

	public static boolean isPrime(int n) {
		if (n <= 1) return false;
		if (n <= 3) return true;
		if (n % 2 == 0 || n % 3 == 0) return false;
		for (int i = 5; i * i <= n; i = i + 6)
			if (n % i == 0 || n % (i + 2) == 0)
				return false;
		return true;
	}

	public static boolean[] getSieve(int n) {
		boolean[] isPrime = new boolean[n + 1];
		for (int i = 2; i <= n; i++) isPrime[i] = true;
		for (int i = 2; i * i <= n; i++)
			if (isPrime[i])
				for (int j = i; i * j <= n; j++)
					isPrime[i * j] = false;
		return isPrime;
	}

	static long pow(long x, long pow, long mod) {
		long res = 1;
		x = x % mod;
		if (x == 0) return 0;
		while (pow > 0) {
			if ((pow & 1) != 0) res = (res * x) % mod;
			pow >>= 1;
			x = (x * x) % mod;
		}
		return res;
	}

	public static int gcd(int a, int b) {
		int tmp = 0;
		while (b != 0) {
			tmp = b;
			b = a % b;
			a = tmp;
		}
		return a;
	}

	public static long gcd(long a, long b) {
		long tmp = 0;
		while (b != 0) {
			tmp = b;
			b = a % b;
			a = tmp;
		}
		return a;
	}

	public static int random(int min, int max) {
		return random.nextInt(max - min + 1) + min;
	}

	public static void dbg(Object... o) {
		System.out.println(Arrays.deepToString(o));
	}

	public static void reverse(int[] s, int l, int r) {
		for (int i = l; i <= (l + r) / 2; i++) {
			int tmp = s[i];
			s[i] = s[r + l - i];
			s[r + l - i] = tmp;
		}
	}

	public static void reverse(int[] s) {
		reverse(s, 0, s.length - 1);
	}

	public static void reverse(long[] s, int l, int r) {
		for (int i = l; i <= (l + r) / 2; i++) {
			long tmp = s[i];
			s[i] = s[r + l - i];
			s[r + l - i] = tmp;
		}
	}

	public static void reverse(long[] s) {
		reverse(s, 0, s.length - 1);
	}

	public static void reverse(float[] s, int l, int r) {
		for (int i = l; i <= (l + r) / 2; i++) {
			float tmp = s[i];
			s[i] = s[r + l - i];
			s[r + l - i] = tmp;
		}
	}

	public static void reverse(float[] s) {
		reverse(s, 0, s.length - 1);
	}

	public static void reverse(double[] s, int l, int r) {
		for (int i = l; i <= (l + r) / 2; i++) {
			double tmp = s[i];
			s[i] = s[r + l - i];
			s[r + l - i] = tmp;
		}
	}

	public static void reverse(double[] s) {
		reverse(s, 0, s.length - 1);
	}

	public static void reverse(char[] s, int l, int r) {
		for (int i = l; i <= (l + r) / 2; i++) {
			char tmp = s[i];
			s[i] = s[r + l - i];
			s[r + l - i] = tmp;
		}
	}

	public static void reverse(char[] s) {
		reverse(s, 0, s.length - 1);
	}

	public static <T> void reverse(T[] s, int l, int r) {
		for (int i = l; i <= (l + r) / 2; i++) {
			T tmp = s[i];
			s[i] = s[r + l - i];
			s[r + l - i] = tmp;
		}
	}

	public static <T> void reverse(T[] s) {
		reverse(s, 0, s.length - 1);
	}

	public static void shuffle(int[] s) {
		for (int i = 0; i < s.length; ++i) {
			int j = random.nextInt(i + 1);
			int t = s[i];
			s[i] = s[j];
			s[j] = t;
		}
	}

	public static void shuffle(long[] s) {
		for (int i = 0; i < s.length; ++i) {
			int j = random.nextInt(i + 1);
			long t = s[i];
			s[i] = s[j];
			s[j] = t;
		}
	}

	public static void shuffle(float[] s) {
		for (int i = 0; i < s.length; ++i) {
			int j = random.nextInt(i + 1);
			float t = s[i];
			s[i] = s[j];
			s[j] = t;
		}
	}

	public static void shuffle(double[] s) {
		for (int i = 0; i < s.length; ++i) {
			int j = random.nextInt(i + 1);
			double t = s[i];
			s[i] = s[j];
			s[j] = t;
		}
	}

	public static void shuffle(char[] s) {
		for (int i = 0; i < s.length; ++i) {
			int j = random.nextInt(i + 1);
			char t = s[i];
			s[i] = s[j];
			s[j] = t;
		}
	}

	public static <T> void shuffle(T[] s) {
		for (int i = 0; i < s.length; ++i) {
			int j = random.nextInt(i + 1);
			T t = s[i];
			s[i] = s[j];
			s[j] = t;
		}
	}

	public static void sortArray(int[] a) {
		shuffle(a);
		Arrays.sort(a);
	}

	public static void sortArray(long[] a) {
		shuffle(a);
		Arrays.sort(a);
	}

	public static void sortArray(float[] a) {
		shuffle(a);
		Arrays.sort(a);
	}

	public static void sortArray(double[] a) {
		shuffle(a);
		Arrays.sort(a);
	}

	public static void sortArray(char[] a) {
		shuffle(a);
		Arrays.sort(a);
	}

	public static <T extends Comparable<T>> void sortArray(T[] a) {
		Arrays.sort(a);
	}

	public static int[][] rotate90(int[][] a) {
		int n = a.length, m = a[0].length;
		int[][] ans = new int[m][n];
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				ans[m - j - 1][i] = a[i][j];
		return ans;
	}

	public static char[][] rotate90(char[][] a) {
		int n = a.length, m = a[0].length;
		char[][] ans = new char[m][n];
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				ans[m - j - 1][i] = a[i][j];
		return ans;
	}
}

static class Writer {
	
	private PrintWriter pw;
	
	public Writer(){
		pw = new PrintWriter(System.out);
	}
	
	public Writer(String f){
		try {
			pw = new PrintWriter(new FileWriter(f));
		} catch (IOException e) {
			e.printStackTrace();
		}
	}
	
	public void yesNo(boolean condition) {
		println(condition?"YES":"NO");
	}
	
	public void printArray(int[] a) {
		for(int i = 0; i<a.length; i++) print(a[i]+" ");
	}
	
	public void printlnArray(int[] a) {
		for(int i = 0; i<a.length; i++) print(a[i]+" ");
		pw.println();
	}
	
	public void printArray(long[] a) {
		for(int i = 0; i<a.length; i++) print(a[i]+" ");
	}
	
	public void printlnArray(long[] a) {
		for(int i = 0; i<a.length; i++) print(a[i]+" ");
		pw.println();
	}
	
	public void print(Object o) {
		pw.print(o.toString());
	}
	
	public void println(Object o) {
		pw.println(o.toString());
	}
	
	public void println() {
		pw.println();
	}
	
	public void flush() {
		pw.flush();
	}
	
	public void exit() {
		pw.close();
	}
}
}

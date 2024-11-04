import java.util.Arrays;
import java.io.*;
import java.util.*;
import java.util.Random;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;


public class Main {
	static boolean[][] states = new boolean[][]{{false,false},{false,true},{true,false},{true,true}};
	
	static int transitionCost(boolean[] state1, boolean[] state2) {
		if(state2[0] && state2[1]) {
			int ans = 0;
			if(state1[0]) ans++;
			if(state1[1]) ans++;
			return ans;
		}
		if(!state2[0] && !state2[1]) {
			if(state1[0] || state1[1]) return Integer.MAX_VALUE/3;
			return 0;
		}
		if(!state2[0] && state2[1]) {
			if(state1[0]) return 2;
			if(state1[1]) return 1;
			return 0;
		}
		if(state2[0] && !state2[1]) {
			if(state1[1]) return 2;
			if(state1[0]) return 1;
			return 0;
		}
		return 0;
	}
	static int adaptCost(boolean[] state1, boolean[] state2) {
		if(state2[0] && state2[1]) {
			return 0;
		}
		if(!state2[0] && !state2[1]) {
			if(state1[0] || state1[1]) return Integer.MAX_VALUE/3;
			return 0;
		}
		
		if(!state2[0] && state2[1]) {
			if(state1[0]) return 1;
			return 0;
		}
		if(state2[0] && !state2[1]) {
			if(state1[1]) return 1;
			return 0;
		}
		return 0;
	}
	static boolean[] id0(int v) {
		return states[v];
	}
	static int[][] getDp(char[] a, char[] b, int n){
		int[][] dp = new int[4][n+1];
		for(int i = 0; i<4; i++) Arrays.fill(dp[i], Integer.MAX_VALUE/3);
		dp[0][0] = 0;
		for(int i = 1; i<=n; i++) {
			boolean f = a[i-1] == '*';
			boolean s = b[i-1] == '*';
			boolean[] curState = new boolean[] {f,s};
			for(int j = 0; j<4; j++) { 

				for(int k = 0; k<4; k++) { 

					dp[k][i] = Math.min(dp[k][i], transitionCost(id0(j), id0(k)) + adaptCost(curState, id0(k)) + dp[j][i-1]);




				}
			}
			dp[1][i] = Math.min(dp[1][i], dp[2][i]+1);
			dp[2][i] = Math.min(dp[2][i], dp[1][i]+1);
		}
		return dp;
	}
	static boolean[] merge(boolean[] state1, boolean[] state2) {
		boolean[] X = new boolean[2];
		X[0] = (state1[0] || state2[0]); 
		X[1] = (state1[1] || state2[1]); 
		return X;
	}
	public static void solve() {
		int n = in.nextInt();
		char[] a = in.nca(), b = in.nca();
		int[][] dp1 = getDp(a, b, n);
		

		Util.reverse(a);
		Util.reverse(b);
		int[][] dp2 = getDp(a, b, n);
		long ans = Long.MAX_VALUE/2;
		for(int meetPoint = 0; meetPoint<n; meetPoint++) {
			int idx1 = meetPoint+1;
			int idx2 = n-meetPoint;
			
			for(int endState = 1; endState<3; endState++) {
				for(int j = 0; j<4; j++) {
					for(int k = 0; k<4; k++) {
						long temp = 0;
						temp += adaptCost(id0(j), id0(endState)) + dp1[j][idx1];
						temp += adaptCost(id0(k), id0(endState)) + dp2[k][idx2];
						if(j == k) temp -= adaptCost(id0(j), id0(endState));


						ans = Math.min(ans, temp);
					}
				}
			}
		}
		out.println(ans);
		
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

	public static void id2(int n, long mod, boolean id6, boolean id5) {
		MOD = mod;
		fact = new long[n + 1];
		fact[0] = 1;
		for (int i = 1; i < n + 1; i++) fact[i] = (fact[i - 1] * i) % mod;

		if (id6) {
			inv = new long[n + 1];
			inv[1] = 1;
			for (int i = 2; i <= n; ++i) inv[i] = (mod - (mod / i) * inv[(int) (mod % i)] % mod) % mod;
		}

		if (id5) {
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
		long[] id3 = id4(a, mod);
		if (id3[0] != 1) return -1; 

		long x = id3[1];
		return (x % mod + mod) % mod;
	}

	public static long[] id4(long p, long q) {
		if (q == 0) return new long[] { p, 1, 0 };
		long[] vals = id4(q, p % q);
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

	public static boolean[] id1(int n) {
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

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.lang.reflect.Array;
import java.math.BigInteger;
import java.util.*;
import java.util.stream.Stream;


public class Main implements Runnable {
	static final double time = 1e9;
	static final int MOD = (int) 1e9 + 7;
	static final long mh = Long.MAX_VALUE;
	static final Reader in = new Reader();
	static final PrintWriter out = new PrintWriter(System.out);
	StringBuilder answer = new StringBuilder();
	long start = System.nanoTime();
	
	
	public static void main(String[] args) {
		new Thread(null, new Main(), "persefone", 1 << 28).start();
	}

	@Override
	public void run() {
		
		solve();		
		printf();
		long elapsed = System.nanoTime() - start;




		close();


	}

	void solve() {
		int n = in.nextInt();
		int[] a = in.nextIntArray(n);
		int[] b = in.nextIntArray(n);
		SparseTable sparseTable = new SparseTable(b, a, n);
		long ans = 0;
		for (int i = 0; i < n; i++) ans += sparseTable.get(i, n);
		printf(ans);

	}


	static class SparseTable {
		private int n;
		private int[] log;
		private int[][] min, max;
		private int MAX_LENGTH;

		public SparseTable(int[] a, int[] b, int n) {
			this.n = n;
			this.log = new int[n + 1];
			for (int i = 2; i <= n; i++) log[i] = log[i >> 1] + 1;
			this.MAX_LENGTH = log[n] + 1;
			this.min = new int[n + 1][MAX_LENGTH + 1];
			this.max = new int[n + 1][MAX_LENGTH + 1];
			for (int i = 0; i < n; i++) { min[i][0] = a[i]; max[i][0] = b[i]; }
			build();
		}

		void build() {
			for (int j = 1; j <= MAX_LENGTH; j++)
				for (int i = 0; i + (1 << j) <= n; i++) {
					int k = 1 << (j - 1);
					min[i][j] = Math.min(min[i][j - 1], min[i + k][j - 1]);
					max[i][j] = Math.max(max[i][j - 1], max[i + k][j - 1]);
				}
		}

		int getMin(int l, int r) {
			int j = log[r - l + 1];
			return Math.min(min[l][j], min[r - (1 << j) + 1][j]);
		}

		int getMax(int l, int r) {
			int j = log[r - l + 1];
			return Math.max(max[l][j], max[r - (1 << j) + 1][j]);
		}

		int upperBound(int l, int r) {
			int m = 0, first = l, ans = n;
			while (l < r) if (getMax(first, m = l + r >>> 1) > getMin(first, m)) ans = r = m; else l = m + 1;
			return ans;
		}

		int lowerBound(int l, int r) {
			int m = 0, first = l, ans = n;
			while (l < r) if (getMax(first, m = l + r >>> 1) >= getMin(first, m)) ans = r = m; else l = m + 1;
			return ans;
		}

		int get(int l, int r) { return upperBound(l, r) - lowerBound(l, r); }
	}

	static class ListUtils {
		static <T extends Comparable<T>> int upperBound(List<T> list, int l, int r, T t) {
			int R = r, m = 0;
			while (l <= r) {
				m = l + r >> 1;
				if (R == m) return m;
				if (list.get(m).compareTo(t) > 0) 
					r = m - 1; 
				else 
					l = m + 1;
			}
			return l;
		}
		
		static <T extends Comparable<T>> int lowerBound(List<T> list, int l, int r, T t) {
			int R = r, m = 0;
			while (l <= r) {
				m = l + r >> 1;
				if (R == m) return m;
				if (list.get(m).compareTo(t) >= 0) 
					r = m - 1; 
				else 
					l = m + 1;
			}
			return l;
		}
		
	}
	
	
	static class Fenwick {
		private int n;
		private int[] count;
		public Fenwick(int n) {
			this.n = 2 * n + 10;
			count = new int[this.n];
		}

		void update(int i, int val) {
			for (; i < n; i += i & -i) count[i] += val;
		}

		int get(int i) {
			int sum = 0;
			for (; i > 0; i -= i & -i) sum += count[i];
			return sum;
		}

		int getRange(int i, int j) { return  get(j) - get(i); }
	}


	static class ArrayUtils {
		static void compressed(int[] a, int n) {
			int[] b = a.clone();
			Arrays.sort(b);
			for (int i = 0; i < n; i++) a[i] = lw(b, 0, n, a[i]) + 1;
		}

		static  int lw(int[] b, int l, int r, int k) {
			int R = r, m = 0;
			while (l <= r) {
				m = l + r >> 1;
				if (m == R) return m;
				if (b[m] >= k) r = m - 1;
				else l = m + 1;
			}
			return l;
		}

		static void compressed(long[] a, int n) {
			long[] b = a.clone();
			Arrays.sort(b);
			for (int i = 0; i < n; i++) a[i] = lw(b, 0, n, a[i]) + 1;
		}

		static  int lw(long[] b, int l, int r, long k) {
			int R = r, m = 0;
			while (l <= r) {
				m = l + r >> 1;
				if (m == R) return m;
				if (b[m] >= k) r = m - 1;
				else l = m + 1;
			}
			return l;
		}

		static int up(int[] b, int l, int r, int k) {
			int R = r, m = 0;
			while (l <= r) {
				m = l + r >> 1;
				if (m == R) return m;
				if (b[m] > k) r = m - 1;
				else l = m + 1;
			}
			return l;
		}
	}

	void printf() {
		out.print(answer);
	}
	
	void close() {
		out.close();
	}

	void printf(Stream<?> str) {
		str.forEach(o -> add(o, " "));
		add("\n");
	}

	 
	void printf(Object... obj) {
		printf(false, obj);
	}

	void printfWithDescription(Object... obj) {
		printf(true, obj);
	}
	
		
	private void printf(boolean b, Object... obj) {

		if (obj.length > 1) {
			for (int i = 0; i < obj.length; i++) {
				if (b) add(obj[i].getClass().getSimpleName(), " - ");
				if (obj[i] instanceof Collection<?>) {
					printf((Collection<?>) obj[i]);
				} else if (obj[i] instanceof int[][]) {
					printf((int[][])obj[i]);
				} else if (obj[i] instanceof long[][]) {
					printf((long[][])obj[i]);
				} else if (obj[i] instanceof double[][]) {
					printf((double[][])obj[i]);
				} else printf(obj[i]);
			}
			return;
		}

		if (b) add(obj[0].getClass().getSimpleName(), " - ");
		printf(obj[0]);
	}

	void printf(Object o) {
		if (o instanceof int[])
			printf(Arrays.stream((int[]) o).boxed());
		else if (o instanceof char[])
			printf(new String((char[]) o));
		else if (o instanceof long[])
			printf(Arrays.stream((long[]) o).boxed());
		else if (o instanceof double[])
			printf(Arrays.stream((double[]) o).boxed());
		else if (o instanceof boolean[]) {
			for (boolean b : (boolean[]) o) add(b, " ");
			add("\n");
		}
		else 
			add(o, "\n");
	}

	void printf(int[]... obj) {
		for (int i = 0; i < obj.length; i++) printf(obj[i]);
	}
	
	void printf(long[]... obj) {
		for (int i = 0; i < obj.length; i++) printf(obj[i]);
	}
	
	void printf(double[]... obj) {
		for (int i = 0; i < obj.length; i++) printf(obj[i]);
	}
	
	void printf(boolean[]... obj) {
		for (int i = 0; i < obj.length; i++) printf(obj[i]);
	}
	
	void printf(Collection<?> col) {
		printf(col.stream());
	}

	<T, K> void add(T t, K k) {
		if (t instanceof Collection<?>) {
			((Collection<?>) t).forEach(i -> add(i, " "));
		} else if (t instanceof Object[]) {
			Arrays.stream((Object[]) t).forEach(i -> add(i, " "));
		} else
			add(t);
		add(k);
	}
	
	
	
	<T> void add(T t) {
		answer.append(t);
	}

	@SuppressWarnings("unchecked")
	<T extends Comparable<? super T>> T min(T... t) {
		if (t.length == 0)
			return null;
		T m = t[0];
		for (int i = 1; i < t.length; i++)
			if (t[i].compareTo(m) < 0)
				m = t[i];
		return m;
	}

	@SuppressWarnings("unchecked")
	<T extends Comparable<? super T>> T max(T... t) {
		if (t.length == 0)
			return null;
		T m = t[0];
		for (int i = 1; i < t.length; i++)
			if (t[i].compareTo(m) > 0)
				m = t[i];
		return m;
	}

	int gcd(int a, int b) {
		return (b == 0) ? a : gcd(b, a % b);
	}

	long gcd(long a, long b) {
		return (b == 0) ? a : gcd(b, a % b);
	}
	
	

	int[] ext_gcd(int a, int b) {
		if (b == 0) return new int[] {a, 1, 0 };
		int[] vals = ext_gcd(b, a % b);
		int d = vals[0]; 

	    int p = vals[2]; 

		int q = vals[1] - (a / b) * vals[2];
		return new int[] { d, p, q };	  
	}
	
	

	boolean find_any_solution(int a, int b, int c, int[] root) {
		int[] vals = ext_gcd(Math.abs(a), Math.abs(b));
		if (c % vals[0] != 0) return false;
		printf(vals);
		root[0] = c * vals[1] / vals[0];
		root[1] = c * vals[2] / vals[0];
		if (a < 0) root[0] *= -1;
		if (b < 0) root[1] *= -1;
		return true;
	}
	
	int mod(int x) { return x % MOD; }
	
	int mod(int x, int y) { return mod(mod(x) + mod(y)); }
	
	long mod(long x) { return x % MOD; }
	
	long mod (long x, long y) { return mod(mod(x) + mod(y)); }
	
	int lw(long[] f, int l, int r, long k) {
		int R = r, m = 0;
		while (l <= r) {
			m = l + r >> 1;
		    if (m == R) return m;
		    if (f[m] >= k) r = m - 1; else l = m + 1;
		}
		return l;
	}
	
	int up(long[] f, int l, int r, long k) {
		int R = r, m = 0;
		while (l <= r) {
			m = l + r >> 1;
		    if (m == R) return m;
		    if (f[m] > k) r = m - 1; else l = m + 1;
		}
		return l;
	}
	
	int lw(int[] f, int l, int r, int k) {
		int R = r, m = 0;
		while (l <= r) {
			m = l + r >> 1;
		    if (m == R) return m;
		    if (f[m] >= k) r = m - 1; else l = m + 1;
		}
		return l;
	}
	
	int up(int[] f, int l, int r, int k) {
		int R = r, m = 0;
		while (l <= r) {
			m = l + r >> 1;
		    if (m == R) return m;
		    if (f[m] > k) r = m - 1; else l = m + 1;
		}
		return l;
	}

	<K extends Comparable<K>> int lw(List<K> li, int l, int r, K k) {
		int R = r, m = 0;
		while (l <= r) {
			m = l + r >> 1;
		    if (m == R) return m;
		    if (li.get(m).compareTo(k) >= 0) 
		    	r = m - 1;
		    else 
		    	l = m + 1;
		}
		return l;
	}
	
	<K extends Comparable<K>> int up(List<K> li, int l, int r, K k) {
		int R = r, m = 0;
		while (l <= r) {
			m = l + r >> 1;
		    if (m == R) return m;
		    if (li.get(m).compareTo(k) > 0) 
		    	r = m - 1;
		    else 
		    	l = m + 1;
		}
		return l;
	}
		
	<K extends Comparable<K>> int bs(List<K> li, int l, int r, K k) {
		while (l <= r) {
			int m = l + r >> 1;
		    if (li.get(m) == k) return m;
		    else if (li.get(m).compareTo(k) < 0)
		    	l = m + 1;
		    else 
		    	r = m - 1;
		}
		return -1;
	}
	
	long calc(int base, int exponent) {
		if (exponent == 0) return 1;
		if (exponent == 1) return base % MOD;
		long m = calc(base, exponent / 2);
		if (exponent % 2 == 0) return (m * m) % MOD;
		return (base * ((m * m) % MOD)) % MOD;
	}
	
	long calc(int base, long exponent) {
		if (exponent == 0) return 1;
		if (exponent == 1) return base % MOD;
		long m = calc(base, exponent / 2);
		if (exponent % 2 == 0) return (m * m) % MOD;
		return (base * ((m * m) % MOD)) % MOD;
	}
	
	long calc(long base, long exponent) {
		if (exponent == 0) return 1;
		if (exponent == 1) return base % MOD;
		long m = calc(base, exponent / 2);
		if (exponent % 2 == 0) return (m * m) % MOD;
		return (base * (m * m % MOD)) % MOD;
	}
	
	long power(int base, int exponent) {
		if (exponent == 0) return 1;
		long m = power(base, exponent / 2);
		if (exponent % 2 == 0) return m * m;
		return base * m * m;
	}
	
	void swap(int[] a, int i, int j) {
		a[i] ^= a[j];
		a[j] ^= a[i];
		a[i] ^= a[j];
	}
	
	void swap(long[] a, int i, int j) {
		long tmp = a[i];
		a[i] = a[j];
		a[j] = tmp;
	}
	
	static class Pair<K extends Comparable<? super K>, V extends Comparable<? super V>>
			implements Comparable<Pair<K, V>> {
		private K k;
		private V v;

		Pair() {}

		Pair(K k, V v) {
			this.k = k;
			this.v = v;
		}

		K getK() { return k; }

		V getV() { return v; }

		void setK(K k) { this.k = k; }

		void setV(V v) { this.v = v; }

		void setKV(K k, V v) {
			this.k = k;
			this.v = v;
		}

		@SuppressWarnings("unchecked")
		@Override
		public boolean equals(Object o) {
			if (this == o) return true;
			if (o == null || !(o instanceof Pair)) return false;
			Pair<K, V> p = (Pair<K, V>) o;
			return k.compareTo(p.k) == 0 && v.compareTo(p.v) == 0;
		}

		@Override
		public int hashCode() {
			int hash = 31;
			hash = hash * 89 + k.hashCode();
			hash = hash * 89 + v.hashCode();
			return hash;
		}

		@Override
		public int compareTo(Pair<K, V> pair) {
			return k.compareTo(pair.k) == 0 ? v.compareTo(pair.v) : k.compareTo(pair.k);
		}

		@Override
		public Pair<K, V> clone() {
			return new Pair<K, V>(this.k, this.v);
		}

		@Override
		public String toString() {
			return String.valueOf(k).concat(" ").concat(String.valueOf(v)).concat("\n");
		}
	}

	static class Reader {
		private BufferedReader br;
		private StringTokenizer st;

		Reader() {
			br = new BufferedReader(new InputStreamReader(System.in));
		}

		String next() {
			try {
				while (st == null || !st.hasMoreTokens()) {
					st = new StringTokenizer(br.readLine());
				}
			} catch (IOException e) {
				e.printStackTrace();
			}
			return st.nextToken();
		}

		int nextInt() {
			return Integer.parseInt(next());
		}

		int[] nextIntArray(int n) {
			int[] arr = new int[n];
			for (int i = 0; i < n; i++)
				arr[i] = nextInt();
			return arr;
		}

		long nextLong() {
			return Long.parseLong(next());
		}
		
		double nextDouble() {
			return Double.parseDouble(next());
		}

		String nextLine() {
			String s = "";
			try {
				s = br.readLine();
			} catch (IOException e) {
				e.printStackTrace();
			}
			return s;
		}
	}
}
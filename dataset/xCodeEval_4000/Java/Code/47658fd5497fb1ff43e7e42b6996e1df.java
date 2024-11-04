import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.nio.channels.SeekableByteChannel;
import java.util.*;
import java.util.stream.Stream;

public class TestClass implements Runnable {
	
	static final double time = 1e9;
	static final int MOD = (int) 1e9 + 7;
	static final long mh = Long.MAX_VALUE;
	static final Reader in = new Reader();
	static final PrintWriter out = new PrintWriter(System.out);
	StringBuilder answer = new StringBuilder();

	public static void main(String[] args) {
		new Thread(null, new TestClass(), "persefone", 1 << 28).start();
	}

	@Override
	public void run() {
		long start = System.nanoTime();
		solve();		
		printf();
		long elapsed = System.nanoTime() - start;




		close();
	}
	
	void solve() {
		int n = in.nextInt();
		long d = in.nextInt(), m = 0;
		long[] a = new long[n];
		for (int i = 0; i < n; i++) m = Math.max(m, a[i] = in.nextLong());

		long[] c = new long[n << 2];
		for (int i = 0; i < n; i++) {
			c[i] = a[i];
			c[i + n] = d + m - a[i];
			c[i + 2 * n] = a[i] - d;
			c[i + 3 * n] = c[i + n] - d;
		}

		ArrayUtils.compressed(c, n << 2);

		int[] dp = new int[n];
		int ans = 0;
		Fenwick down = new Fenwick(n << 2), up = new Fenwick(n << 2);
		for (int i = 0; i < n; i++) {
			

			int x = up.get((int) c[i + 3 * n]);
			int y = down.get((int) c[i + 2 * n]);
			dp[i] = Math.max(x, y) + 1;
			if (dp[i] > ans) ans = dp[i];
			up.update((int) c[i + n], dp[i]);
			down.update((int) c[i], dp[i]);
		}

		printf(ans);

		int[] stack = new int[ans];
		outer:
		for (int i = n - 1; i > -1; i--) {
			if (dp[i] == ans) {
				stack[--ans] = i + 1;
				long k = a[i];
				for (int j = i - 1; j > -1 && ans > -1; j--) {
					if (dp[j] == ans && Math.abs(a[j] - k) >= d) {
						k = a[j];
						stack[--ans] = j + 1;
					}
				}
			}
		}

		printf(stack);
	}

	static class Fenwick {
		private int n;
		int[] max;

		public Fenwick(int n) {
			this.n = n + 10;
			this.max = new int[this.n];
		}

		void update(int i, int val) {
			for (; i < n; i += i & -i) max[i] = Math.max(max[i], val);
		}

		int get(int i) {
			int ans = 0;
			for (; i > 0; i -= i & -i) ans = Math.max(ans, max[i]);
			return ans;
		}
	}

	static class ArrayUtils {

		static void compressed(long[] a, int n) {
			long[] b = a.clone();
			Arrays.sort(b);
			for (int i = 0; i < n; i++) a[i] = lw(b, 0, n, a[i]) + 1;
		}

		static int lw(long[] b, int l, int r, long k) {
			int m = 0, ans = r;
			while (l < r) if (Long.compare(b[m = l + r >> 1], k) >= 0) ans = r = m; else l = m + 1;
			return ans;
		}

		static <T> int upperBound(T[] arr, int start, int end, T t, Comparator<? super T> c) {
			int ans = end;
			while (start < end) {
				int mid = start + end >>> 1;
				if (c.compare(arr[mid], t) > 0) ans = end = mid; else start = mid + 1;
			}
			return ans;
		}

		static <T> int lowerBound(T[] arr, int start, int end, T t, Comparator<? super T> c) {
			int ans = end;
			while (start < end) {
				int mid = start + end >>> 1;
				if (c.compare(arr[mid], t) >= 0) ans = end = mid; else start = mid + 1;
			}
			return ans;
		}
	}

	static class SegmentTreeMax {
		private int n;
		private int[] a;
		private int[] max;
		public SegmentTreeMax(int[] a, int n) {
			this.a = a;
			this.n = n;
			max = new int[4 * n + 4];
			build(1, 0, n - 1);
		}

		void build(int currentVertex, int currentLeft, int currentRight) {
			if (currentLeft == currentRight) max[currentVertex] = a[currentLeft];
			else {
				int middle = currentLeft + currentRight >>> 1, vex = currentVertex << 1;
				build(vex, currentLeft, middle);
				build(vex + 1, middle + 1, currentRight);
				max[currentVertex] = Math.max(max[vex], max[vex + 1]);
			}
		}

		private void update(int currentVertex, int currentLeft, int currentRight, int pos, int value) {
			if (currentLeft == currentRight) max[currentVertex] = a[pos] = value;
			else {
				int middle = currentLeft + currentRight >>> 1,vex = currentVertex << 1;
				if (currentLeft <= pos && pos <= middle)
					update(vex, currentLeft, middle, pos, value);
				else
					update(vex + 1, middle + 1, currentRight, pos, value);
				max[currentVertex] = Math.max(max[vex], max[vex + 1]);
			}
		}

		void update(int pos, int value) { update(1,0, n - 1, pos, value); }

		private int getMax(int currentVertex, int currentLeft, int currentRight, int left, int right) {
			if (left > currentRight || right < currentLeft) return -1;
			if (currentLeft >= left && currentRight <= right) return max[currentVertex];
			int middle = currentLeft + currentRight >>> 1, vex = currentVertex << 1;
			return  Math.max(getMax(vex, currentLeft, middle, left, right),
					getMax(vex + 1, middle + 1, currentRight, left, right));
		}

		int getMax(int left, int right) { return getMax(1, 0, n - 1, left, right); }
	}

	int pow(int a, int b, int p) {
		long ans = 1, base = a;
		while (b > 0){
			if ((b & 1) > 0) {
				ans *= base %= p;
			}
			base *= base %= p;
			b >>= 1;
		}
		return (int)ans;
	}
	
	public static int[] enumLowestPrimeFactors(int n) {
		int tot = 0;
		int[] lpf = new int[n + 1];
		int u = n + 32;
		double lu = Math.log(u);
		int[] primes = new int[(int) (u / lu + u / lu / lu * 1.5)];
		for (int i = 2; i <= n; i++)
			lpf[i] = i;
		for (int p = 2; p <= n; p++) {
			if (lpf[p] == p)
				primes[tot++] = p;
			int tmp;
			for (int i = 0; i < tot && primes[i] <= lpf[p] && (tmp = primes[i] * p) <= n; i++) {
				lpf[tmp] = primes[i];
			}
		}
		return lpf;
	}

	
	public static int[] enumNumDivisorsFast(int n, int[] lpf)
	{
		int[] nd = new int[n+1];
		nd[1] = 1;
		for(int i = 2;i <= n;i++){
			int j = i, e = 0;
			while(j % lpf[i] == 0){
				j /= lpf[i];
				e++;
			}
			nd[i] = nd[j] * (e+1);
		}
		return nd;
	}
	
	boolean isPrime(long n) {
		
		for (int i = 2; 1l * i * i <= n; i++) 
			if (n % i == 0)
				return false;
		return true;
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
	
	long lcm(int a, int b) {
		return (1l * a * b / gcd(a, b));
	}
	
	long lcm(long a, long b) {
		if (a > Long.MAX_VALUE / b) throw new RuntimeException();
		return a * b / gcd(a, b);
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
	
	int lw(double[] f, int l, int r, double k) {
		int R = r, m = 0;
		while (l <= r) {
			m = l + r >> 1;
		    if (m == R) return m;
		    if (f[m] >= k) r = m - 1; else l = m + 1;
		}
		return l;
	}
	
	int up(double[] f, int l, int r, double k) {
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
	
	long calc(int base, int exponent, int p) {
		if (exponent == 0) return 1;
		if (exponent == 1) return base % p;
		long m = calc(base, exponent >> 1, p);
		if (exponent % 2 == 0) return (m * m) % p;
		return 1l * base * m  % p * m % p;
	}
	
	long calc(int base, long exponent, int p) {
		if (exponent == 0) return 1;
		if (exponent == 1) return base % p;
		long m = calc(base, exponent >> 1, p);
		if (exponent % 2 == 0) return (m * m) % p;
		return 1l * base * m  % p * m % p;
	}
	
	long calc(long base, long exponent, int p) {
		if (exponent == 0) return 1;
		if (exponent == 1) return base % p;
		long m = calc(base, exponent >> 1, p);
		if (exponent % 2 == 0) return (m * m) % p;
		return base * m  % p * m % p;
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
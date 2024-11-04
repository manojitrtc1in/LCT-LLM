import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Collection;
import java.util.HashMap;
import java.util.HashSet;
import java.util.List;
import java.util.Map;
import java.util.Map.Entry;
import java.util.Set;
import java.util.StringTokenizer;
import java.util.stream.Stream;

public class Solution implements Runnable {
	
	static final double time = 1e9;
	static final int MOD = (int) 1e9 + 7;
	static final long mh = Long.MAX_VALUE;
	static final Reader in = new Reader();
	static final PrintWriter out = new PrintWriter(System.out);
	StringBuilder answer = new StringBuilder();

	public static void main(String[] args) {
		new Thread(null, new Solution(), "persefone", 1 << 28).start();
	}

	@Override
	public void run() {
		long start = System.nanoTime();
		solve();		
		printf();
		long elapsed = System.nanoTime() - start;




		close();
	}
	
	int m = 1000001;
	int[] factor = new int[m];
	
	void solve() {
		
		
		for (int i = 2; i < m; i++) {
			if (factor[i] == 0) {
				factor[i] = i;
				for (int j = i; 1l * i * j < m; j++)
					if (factor[i * j] == 0) 
						factor[i * j] = i;
			}
		}
				
		int n = in.nextInt();
		int k = in.nextInt();
		int[] a = in.nextIntArray(n);
				
		Set<Integer> set = new HashSet<>();
		int ma = 0;
		for (int i = 0; i < n; i++) {
			ma = Math.max(ma, a[i]);
			set.add(a[i]);
		}
		for (int i = 0; i < n; i++) {
			if (set.contains(a[i])) {
				for (int j = 2 * a[i]; j <= ma; j += a[i]) {
					if (set.contains(j)) {
						set.remove(a[i]);
						break;
					}
				}
			}
		}
		
		Map<Integer, Integer> mk = new HashMap<>();
		work(mk, k);
		
		Map<Integer, Integer> map = new HashMap<>();
		for (int i : set) {
			Map<Integer, Integer> mi = new HashMap<>();
			work(mi, i);
			for (Entry<Integer, Integer> e : mi.entrySet()) {
				int key = e.getKey();
				if (map.containsKey(key)) 
					map.put(key, Math.max(e.getValue(), map.get(key)));
				else 
					map.put(key, e.getValue());
			}
		}
		
		for (Entry<Integer, Integer> e : mk.entrySet()) {
			int key = e.getKey();
			if (!map.containsKey(key) || map.get(key) < e.getValue()) {
				printf("No");
				return;
			}
		}
		
		printf("Yes");
	}
	
	void work(Map<Integer, Integer> map, int k) {
		while (k > 1) {
			if (!map.containsKey(factor[k]))
				map.put(factor[k], 1);
			else 
				map.put(factor[k], map.get(factor[k]) + 1);
			k /= factor[k];
		}
	}
		
	int pow(int a, int b, int p){
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
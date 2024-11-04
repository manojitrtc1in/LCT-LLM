import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
import java.util.Arrays;
import java.util.Random;
import java.io.FileWriter;
import java.io.PrintWriter;


public class Main {
	public static void solve() {
		int n = in.nextInt(), q = in.nextInt();
		int[] a = new int[n];
		for(int i = 0; i<n; i++) a[i] += in.nextInt();
		for(int i = 0; i<n; i++) a[i] -= in.nextInt();
		long[] pre = new long[n+1]; 
		for(int i = 1; i<=n; i++) pre[i] = pre[i-1] + a[i-1];
		SegmentTreeMIN prefixMin = new SegmentTreeMIN(pre);
		SegmentTreeMAX prefixMax = new SegmentTreeMAX(pre);
		while(q-->0) {
			int l = in.nextInt()-1, r = in.nextInt()-1;
			long d = pre[r+1]-pre[l];
			long maxPrefix = prefixMax.query(l, r)-pre[l];
			if(d!=0 || maxPrefix>0) {
				out.println(-1);
				continue;
			}
			out.println(Math.abs(prefixMin.query(l, r)-pre[l]));
		}
	}
	public static void main(String[] args) {
		in = new Reader();
		out = new Writer();
		int t = 1;
		while(t-->0) solve();
		out.exit();
	}
	
	static class SegmentTreeMIN{
		long dummyValue = Long.MAX_VALUE;
		public long operation(long a, long b){
			return Math.min(a, b);
		}
		

		
		private long[] tree;
		int n;
		public SegmentTreeMIN(long[] a) {
			this.n = a.length;
			this.tree = new long[4*n];
			build(0, 0, n-1, a);
		}
		
		public SegmentTreeMIN(int n) {
			this.n = n;
			this.tree = new long[4*n];
		}
		
		private void build(int idx, int l, int r, long[] a) {
			if(l==r) tree[idx] = a[l];
			else {
				int m = (l+r)/2;
				build(2*idx+1, l, m, a);
				build(2*idx+2,m+1,r, a);
				tree[idx] = operation(tree[2*idx+1], tree[2*idx+2]);
			}
		}
		
		public void update(int idx, long weight) {
			updateUtil(0, 0, n-1, idx, weight);
		}
		
		private void updateUtil(int idx ,int l, int r, int i, long weight) {
			if(l==r) tree[idx] = weight;
			else {
				int md = (l+r)/2;
				if(i<=md) updateUtil(2*idx+1, l, md, i, weight);
				else updateUtil(2*idx+2, md+1, r, i, weight);
				tree[idx] = operation(tree[2*idx+1], tree[2*idx+2]);
			}
		}
		
		public long query(int l, int r) {
			return queryUtil(0, l, r, 0, n-1);
		}
		
		private long queryUtil(int idx, int lBound, int rBound, int l, int r) {
			if(rBound < l || r < lBound) return dummyValue;
			if(lBound <= l && r<= rBound) return tree[idx];
			int md = (l+r)/2;
			return operation(queryUtil(2*idx+1, lBound, rBound, l, md), queryUtil(2*idx+2, lBound, rBound, md+1, r));
		}
	}
 
	static class SegmentTreeMAX{
		long dummyValue = Long.MIN_VALUE;
		public long operation(long a, long b){
			return Math.max(a, b);
		}
		

		
		private long[] tree;
		int n;
		public SegmentTreeMAX(long[] pre) {
			this.n = pre.length;
			this.tree = new long[4*n];
			build(0, 0, n-1, pre);
		}
		
		public SegmentTreeMAX(int n) {
			this.n = n;
			this.tree = new long[4*n];
		}
		
		private void build(int idx, int l, int r, long[] a) {
			if(l==r) tree[idx] = a[l];
			else {
				int m = (l+r)/2;
				build(2*idx+1, l, m, a);
				build(2*idx+2,m+1,r, a);
				tree[idx] = operation(tree[2*idx+1], tree[2*idx+2]);
			}
		}
		
		public void update(int idx, long weight) {
			updateUtil(0, 0, n-1, idx, weight);
		}
		
		private void updateUtil(int idx ,int l, int r, int i, long weight) {
			if(l==r) tree[idx] = weight;
			else {
				int md = (l+r)/2;
				if(i<=md) updateUtil(2*idx+1, l, md, i, weight);
				else updateUtil(2*idx+2, md+1, r, i, weight);
				tree[idx] = operation(tree[2*idx+1], tree[2*idx+2]);
			}
		}
		
		public long query(int l, int r) {
			return queryUtil(0, l, r, 0, n-1);
		}
		
		private long queryUtil(int idx, int lBound, int rBound, int l, int r) {
			if(rBound < l || r < lBound) return dummyValue;
			if(lBound <= l && r<= rBound) return tree[idx];
			int md = (l+r)/2;
			return operation(queryUtil(2*idx+1, lBound, rBound, l, md), queryUtil(2*idx+2, lBound, rBound, md+1, r));
		}
	}
	
	static Reader in; static Writer out;

static class Reader {
	static BufferedReader br;
	static StringTokenizer st;
	
	public Reader() {
		this.br = new BufferedReader(new InputStreamReader(System.in));
	}
	
	public Reader(String f){
		try {
			this.br = new BufferedReader(new FileReader(f));
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

static class Util{
		private static Random random = new Random();
		static long[] fact;
		
		public static void initFactorial(int n, long mod) {
			fact = new long[n+1];
			fact[0] = 1;
			for (int i = 1; i < n+1; i++) fact[i] = (fact[i - 1] * i) % mod;
		}
		
		public static long modInverse(long a, long MOD) {
			long[] gcdE = gcdExtended(a, MOD);
			if (gcdE[0] != 1) return -1; 

			long x = gcdE[1];
			return (x % MOD + MOD) % MOD;
		}
		
		public static long[] gcdExtended(long p, long q) {
			if (q == 0) return new long[] { p, 1, 0 };
			long[] vals = gcdExtended(q, p % q);
			long tmp = vals[2];
			vals[2] = vals[1] - (p / q) * vals[2];
			vals[1] = tmp;
			return vals;
		}
		
		public static long nCr(int n, int r, long MOD) {
			if (r == 0) return 1;
			return (fact[n] * modInverse(fact[r], MOD) % MOD * modInverse(fact[n - r], MOD) % MOD) % MOD;
		}
		
		public static long nCr(int n, int r) {
			return (fact[n]/fact[r])/fact[n-r];
		}
		
		public static long nPr(int n, int r, long MOD) {
			if (r == 0) return 1;
			return (fact[n] * modInverse(fact[n - r], MOD) % MOD) % MOD;
		}
		public static long nPr(int n, int r) {
			return fact[n]/fact[n-r];
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
	        boolean[] isPrime = new boolean[n+1];
	        for (int i = 2; i <= n; i++) isPrime[i] = true;
	        for (int i = 2; i*i <= n; i++) if (isPrime[i]) 
	                for (int j = i; i*j <= n; j++) isPrime[i*j] = false;
	        return isPrime;
	    }
	    
	    static long pow(long x, long pow, long mod){
	    	long res = 1;
	    	x = x % mod;
	    	if (x == 0) return 0;
	    	while (pow > 0){
	    		if ((pow & 1) != 0) res = (res * x) % mod;
	        	pow >>= 1;
	        	x = (x * x) % mod;
	    	}
	    	return res;
	    }
	    
	    public static int gcd(int a, int b) { 
	    	int tmp = 0;
	    	while(b != 0) {
	    		tmp = b;
	    		b = a%b;
	    		a = tmp;
	    	}
	    	return a;
	    }
	    
	    public static long gcd(long a, long b) { 
	    	long tmp = 0;
	    	while(b != 0) {
	    		tmp = b;
	    		b = a%b;
	    		a = tmp;
	    	}
	    	return a;
	    }
	    
	    public static int random(int min, int max) {
	    	return random.nextInt(max-min+1)+min;
	    }
	    
		public static void dbg(Object... o) { 
			System.out.println(Arrays.deepToString(o)); 
		}
		
		public static void reverse(int[] s, int l , int r) {
			for(int i = l; i<=(l+r)/2; i++) {
				int tmp = s[i];
				s[i] = s[r+l-i];
				s[r+l-i] = tmp;
			}
	    }
		
		public static void reverse(int[] s) {
			reverse(s, 0, s.length-1);
	    }
		
		public static void reverse(long[] s, int l , int r) {
			for(int i = l; i<=(l+r)/2; i++) {
				long tmp = s[i];
				s[i] = s[r+l-i];
				s[r+l-i] = tmp;
			}
	    }
		
		public static void reverse(long[] s) {
			reverse(s, 0, s.length-1);
	    }
		
		public static void reverse(float[] s, int l , int r) {
			for(int i = l; i<=(l+r)/2; i++) {
				float tmp = s[i];
				s[i] = s[r+l-i];
				s[r+l-i] = tmp;
			}
	    }
		
		public static void reverse(float[] s) {
			reverse(s, 0, s.length-1);
	    }
		
		public static void reverse(double[] s, int l , int r) {
			for(int i = l; i<=(l+r)/2; i++) {
				double tmp = s[i];
				s[i] = s[r+l-i];
				s[r+l-i] = tmp;
			}
	    }
		
		public static void reverse(double[] s) {
			reverse(s, 0, s.length-1);
	    }
		
		public static void reverse(char[] s, int l , int r) {
			for(int i = l; i<=(l+r)/2; i++) {
				char tmp = s[i];
				s[i] = s[r+l-i];
				s[r+l-i] = tmp;
			}
	    }
		
		public static void reverse(char[] s) {
			reverse(s, 0, s.length-1);
	    }
		
		public static <T> void reverse(T[] s, int l , int r) {
			for(int i = l; i<=(l+r)/2; i++) {
				T tmp = s[i];
				s[i] = s[r+l-i];
				s[r+l-i] = tmp;
			}
	    }
		
		public static <T> void reverse(T[] s) {
			reverse(s, 0, s.length-1);
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

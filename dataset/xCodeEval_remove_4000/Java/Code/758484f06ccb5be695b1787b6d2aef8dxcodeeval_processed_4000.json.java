import java.util.ArrayList;
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
	static ArrayList<Integer> op;
	static int[][] a;
	static int n,m;
	public static void solve(Reader in, Writer out) {
		int t = in.nextInt();
		while(t-->0) {
			n = in.nextInt();m = in.nextInt();
			a = new int[n][m];
			op = new ArrayList<>();
			for(int i = 0; i<n; i++){
				char[] x = in.nca();
				for(int j = 0; j<m; j++) a[i][j] = x[j]-'0';
			}
			
			for(int i = 0; i<n-2; i++){
				for(int j = 0; j<m; j++){
					if(a[i][j]==0) continue;
					boolean id4 = false;
					if(j+1<m && a[i][j+1]==1){
						addAns(i, j);
						addAns(i, j+1);
						addAns(i+1, j);
					}else{
						addAns(i, j);
						addAns(i+1, j);
						if(j+1<m) addAns(i+1, j+1); else addAns(i+1, j-1);
					}
				}
			}
			for(int j = 0; j<m-2; j++){
				if(a[n-1][j] == 0 && a[n-2][j]==0) continue;
				if(a[n-1][j] == 1 && a[n-2][j]==1){
					addAns(n-1, j);
					addAns(n-2, j);
					addAns(n-1, j+1);
				}else if(a[n-1][j] == 1){
					addAns(n-1, j);
					addAns(n-1, j+1);
					addAns(n-2, j+1);
				}else{
					addAns(n-2, j);
					addAns(n-1, j+1);
					addAns(n-2, j+1);
				}
			}
			int[][] v = new int[2][2];
			v[0][0] = a[n-2][m-2];
			v[0][1] = a[n-2][m-1];
			v[1][0] = a[n-1][m-2];
			v[1][1] = a[n-1][m-1];
			id2(v);
			out.println(op.size()/6);
			for(int i = 0; i<op.size(); i+=6){
				for(int j = 0; j<6; j++) out.print((op.get(i+j)+1)+" ");
				out.println();
			}
		}
	}
	
	public static void id2(int[][] x){
		int cnt = x[0][0] + x[1][0] + x[0][1] + x[1][1];
		if(cnt==0) return;
		int[][] init = new int[2][2];
		for(int i = 0; i<2; i++){
			for(int j = 0; j<2; j++){
				init[i][j] = x[i][j];
			}
		}
		if(cnt==4){
			id6(x,0,0);
			id6(x,0,1);
			id6(x,1,0);
		}
		if(cnt==3){
			for(int i = 0; i<2; i++){
				for(int j = 0; j<2; j++){
					if(init[i][j]==1) id6(x, i, j);
				}
			}
		}
		if(cnt==2){
			outer:
			for(int i = 0; i<2; i++){
				for(int j = 0; j<2; j++){
					if(init[i][j]==1) {
						id6(x, i, j);
						break outer;
					}
				}
			}
			for(int i = 0; i<2; i++){
				for(int j = 0; j<2; j++){
					if(init[i][j]==0) {
						id6(x, i, j);
					}
				}
			}
		}
		if(cnt==1){
			outer:
			for(int i = 0; i<2; i++){
				for(int j = 0; j<2; j++){
					if(init[i][j]==1) {
						id6(x, i, j);
						break outer;
					}
				}
			}
			int put = 0;
			for(int i = 0; i<2; i++){
				for(int j = 0; j<2; j++){
					if(put==2) break;
					if(init[i][j]==0) {
						put++;
						id6(x, i, j);
					}
				}
			}
		}


		id2(x);
	}
	public static void id6(int[][] x, int i, int j){
		x[i][j] = (x[i][j]+1)%2;
		op.add(i+n-2);
		op.add(j+m-2);
	}
	public static void dbg(int[][] a){
		for(int i = 0; i<a.length; i++) Util.dbg(a[i]);
	}
	public static void addAns(int i, int j){
		a[i][j] = (a[i][j]+1)%2;
		op.add(i);
		op.add(j);
	}
	public static void main(String[] args) {
		Reader in = new Reader();
		Writer out = new Writer();
		solve(in, out);
		out.exit();
	}

static class Reader {
	static BufferedReader br;
	static StringTokenizer st;
	private int charIdx = 0;
	private String s;

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
		for (int i = 0; i < n; i++)
			a[i] = nextInt();
		return a;
	}

	public double[] nd(int n) {
		double[] a = new double[n];
		for (int i = 0; i < n; i++)
			a[i] = nextDouble();
		return a;
	}

	public char nextChar() {
		if (s == null || charIdx >= s.length()) {
			if (st == null || !st.hasMoreTokens())
				try {
					readLine();
				} catch (Exception e) {
				}
			s = st.nextToken();
			charIdx = 0;
		}
		return s.charAt(charIdx++);
	}

	public long[] nl(int n) {
		long[] a = new long[n];
		for (int i = 0; i < n; i++)
			a[i] = nextLong();
		return a;
	}

	public char[] nca() {
		return next().toCharArray();
	}

	public String[] nS(int n) {
		String[] a = new String[n];
		for (int i = 0; i < n; i++)
			a[i] = next();
		return a;
	}

	public int nextInt() {
		if (st == null || !st.hasMoreTokens())
			try {
				readLine();
			} catch (Exception e) {
			}
		return Integer.parseInt(st.nextToken());
	}

	public double nextDouble() {
		if (st == null || !st.hasMoreTokens())
			try {
				readLine();
			} catch (Exception e) {
			}
		return Double.parseDouble(st.nextToken());
	}

	public Long nextLong() {
		if (st == null || !st.hasMoreTokens())
			try {
				readLine();
			} catch (Exception e) {
			}
		return Long.parseLong(st.nextToken());
	}

	public String next() {
		if (st == null || !st.hasMoreTokens())
			try {
				readLine();
			} catch (Exception e) {
			}
		return st.nextToken();
	}

	public static void readLine() {
		try {
			st = new StringTokenizer(br.readLine());
		} catch (Exception e) {
		}
	}
}

static class Util{
		private static Random random = new Random();
		static long[] fact;
		public static void id5(int n, long mod) {
			fact = new long[n+1];
			fact[0] = 1;
			for (int i = 1; i < n+1; i++) fact[i] = (fact[i - 1] * i) % mod;
		}
		public static long modInverse(long a, long MOD) {
			long[] id1 = id3(a, MOD);
			if (id1[0] != 1) return -1; 

			long x = id1[1];
			return (x % MOD + MOD) % MOD;
		}
		public static long[] id3(long p, long q) {
			if (q == 0) return new long[] { p, 1, 0 };
			long[] vals = id3(q, p % q);
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
	    public static int lowerBound(int[] a, int v) {
	    	int l = 0, h = a.length;
	    	while(l<h) {
	    		int mid = (l+h)/2;
	    		if(v<=a[mid]) h = mid;
	    		else l = mid+1;
	    	}
	    	return l;
	    }
	    public static int lowerBound(long[] a, long v) {
	    	int l = 0, h = a.length;
	    	while(l<h) {
	    		int mid = (l+h)/2;
	    		if(v<=a[mid]) h = mid;
	    		else l = mid+1;
	    	}
	    	return l;
	    }
	    public static int upperBound(int[] a, int v) {
	    	int l = 0, h = a.length;
	    	while(l<h) {
	    		int mid = (l+h)/2;
	    		if(a[mid]<=v) l = mid+1;
	    		else h = mid;
	    	}
	    	return l;
	    }
	    public static int upperBound(long[] a, long v) {
	    	int l = 0, h = a.length;
	    	while(l<h) {
	    		int mid = (l+h)/2;
	    		if(a[mid]<=v) l = mid+1;
	    		else h = mid;
	    	}
	    	return l;
	    }
	    public static boolean[] id0(int n) {
	        boolean[] isPrime = new boolean[n+1];
	        for (int i = 2; i <= n; i++) isPrime[i] = true;
	        for (int i = 2; i*i <= n; i++) if (isPrime[i]) 
	                for (int j = i; i*j <= n; j++) isPrime[i*j] = false;
	        return isPrime;
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
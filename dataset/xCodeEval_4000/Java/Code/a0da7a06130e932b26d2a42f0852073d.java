
import java.io.*;
import java.math.*;
import java.util.*;

import static java.util.Arrays.*;

public class D {
	private static final int mod = (int)1e9+7;

	final Random random = new Random(0);
	final IOFast io = new IOFast();

	

	public void run() throws IOException {


		int TEST_CASE = 1;
		while(TEST_CASE-- != 0) {
			char[] cs = io.next();


			RollingHash rh = new RollingHash(cs);
			TreeMap<Long, Integer> mp = new TreeMap<>();
			for(int i = 0; i < cs.length; i++) {
				for(int j = 0; j < 4; j++) if(i + j + 1 <= cs.length) {
					long h = rh.hash(i, i + j + 1);
					Integer v = mp.get(h);
					if(v == null) v = 1;
					else v++;
					mp.put(h, v);
				}
			}

			TreeMap<Long, int[]> mp2 = new TreeMap<>();
			for(int i = 0; i < cs.length; i++) {
				for(int j = 0; j < 4; j++) if(i + j + 1 <= cs.length) {
					long h = rh.hash(i, i + j + 1);
					int[] xs = mp2.get(h);
					Integer n = mp.get(h);
					if(xs == null) {
						xs = new int[n];
						mp2.put(h, xs);
					}
					xs[xs.length - n] = i;
					mp.put(h, n - 1);
				}
			}

			TreeMap<long[], Integer> ans = new TreeMap<>(new Comparator<long[]>() {

				@Override
				public int compare(long[] o1, long[] o2) {
					

					return o1[0] != o2[0] ? Long.compare(o1[0], o2[0]) : Long.compare(o1[1], o2[1]);
				}
			});
			char[] c1 = new char[5];
			char[] c2 = new char[5];
			RollingHash r1 = new RollingHash(4);
			RollingHash r2 = new RollingHash(4);
			int q = io.nextInt();
			long[] vx = new long[2];
			for(int i = 0; i < q; i++) {
				int n1 = io.next(c1);
				int n2 = io.next(c2);




				r1.set(c1, n1);
				r2.set(c2, n2);
				
				int dup = 0;
				for(int j = 0; j < n1; j++) {
					int cnt = 0;
					for(int k = 0; j + k < n1 && k < n2; k++) {
						if(c1[j + k] != c2[k]) {
							break;
						}
						cnt++;
					}
					dup = Math.max(dup, cnt);
				}
				
				for(int j = 0; j < n2; j++) {
					int cnt = 0;
					for(int k = 0; j + k < n2 && k < n1; k++) {
						if(c2[j + k] != c1[k]) {
							break;
						}
						cnt++;
					}
					dup = Math.max(dup, cnt);
				}

				long h1 = r1.hash(0, n1);
				long h2 = r2.hash(0, n2);
				vx[0] = Math.min(h1, h2);
				vx[1] = Math.max(h1, h2);
				Integer v0 = ans.get(vx);
				if(v0 != null) {
					io.out.println(v0);
					continue;
				}

				int[] xs1 = mp2.get(h1);
				int[] xs2 = mp2.get(h2);
				if(xs1 == null || xs2 == null) {
					ans.put(vx.clone(), -1);
					io.out.println(-1);
					continue;
				}
				
				if(xs1.length > xs2.length) {
					{ final int[] t = xs1; xs1 = xs2; xs2 = t; }
					{ final char[] t = c1; c1 = c2; c2 = t; }
					{ final int t = n1; n1 = n2; n2 = t; }
				}
				
				int ansv = Integer.MAX_VALUE;
				int min = n1 + n2 - dup;
				for(int idx : xs1) {
					int l = Arrays.binarySearch(xs2, idx);
					if(l < 0) { l = -l - 1; }
					if(l > 0) {
						int len = Math.max(idx + n1, xs2[l - 1] + n2) - xs2[l - 1];
						ansv = Math.min(ansv, len);
					}
					if(l < xs2.length) {
						int len = Math.max(idx + n1, xs2[l] + n2) - idx;
						ansv = Math.min(ansv, len);
					}
					if(l + 1 < xs2.length) {
						int len = Math.max(idx + n1, xs2[l + 1] + n2) - idx;
						ansv = Math.min(ansv, len);
					}
					if(ansv == min) break;
				}
				ans.put(vx.clone(), ansv);
				io.out.println(ansv);
			}
		}
	}
	
	static
	class RollingHash {
		private static final long RADIX = 1000000009L * 1000000007L;
		private int n;
		long[] table, table2, pow;

		public RollingHash(char[] str) {
			n = str.length;

			table = new long[n + 1];
			table2 = new long[n + 1];
			pow = new long[n + 1];

			pow[0] = 1;
			for (int i = 0; i < n; i++) {
				table[i + 1] = table[i] * RADIX + str[i];
				table2[i + 1] = table2[i] * RADIX + str[n-1-i];
				pow[i + 1] = pow[i] * RADIX;
			}
		}

		public RollingHash(int n) {
			this.n = n;
			table = new long[n + 1];
			table2 = new long[n + 1];
			pow = new long[n + 1];

			pow[0] = 1;
			for (int i = 0; i < n; i++) {
				pow[i + 1] = pow[i] * RADIX;
			}
		}
		
		void set(char[] str, int n) {
			for (int i = 0; i < n; i++) {
				table[i + 1] = table[i] * RADIX + str[i];
				table2[i + 1] = table2[i] * RADIX + str[n-1-i];
			}
		}

		public long hash(int i, int j) {
			assert(i <= j);
			return table[j] - table[i] * pow[j - i];
		}

		public long revHash(int i, int j) {
			assert(i <= j);
			return table2[n - i] - table2[n - j] * pow[j - i];
		}

		public boolean isProbablePalindrome(int i, int j) {
			return hash(i, j) == revHash(i, j);
		}

		

		

		public int longestOddPalindrome(int i) {
			int low = 0, high = Math.min(i + 1, n - i);
			while(high - low > 1) {
				final int mid = (low + high) / 2;
				if(isProbablePalindrome(i - mid, i + mid + 1)) {
					low = mid;
				}
				else {
					high = mid;
				}
			}
			return low;
		}
		
		

		

		public int longestEvenPalindrome(int i) {
			int low = 0, high = Math.min(i + 2, n - i);
			while(high - low > 1) {
				final int mid = (low + high) / 2;
				if(isProbablePalindrome(i - mid + 1, i + mid + 1)) {
					low = mid;
				}
				else {
					high = mid;
				}
			}
			return low;
		}
	}

	

	

	static int gcd(int n, int r) { return r == 0 ? n : gcd(r, n%r); }
	static long gcd(long n, long r) { return r == 0 ? n : gcd(r, n%r); }
	
	static <T> void swap(T[] x, int i, int j) {
		T t = x[i];
		x[i] = x[j];
		x[j] = t;
	}
	
	static void swap(int[] x, int i, int j) {
		int t = x[i];
		x[i] = x[j];
		x[j] = t;
	}
	

	static void radixSort(int[] xs) {
		int[] cnt = new int[(1<<16)+1];
		int[] ys = new int[xs.length];
		
		for(int j = 0; j <= 16; j += 16) {
			Arrays.fill(cnt, 0);
			for(int x : xs) { cnt[(x>>j&0xFFFF)+1]++; }
			for(int i = 1; i < cnt.length; i++) { cnt[i] += cnt[i-1]; }
			for(int x : xs) { ys[cnt[x>>j&0xFFFF]++] = x; }
			{ final int[] t = xs; xs = ys; ys = t; }
		}
	}
	
	static void radixSort(long[] xs) {
		int[] cnt = new int[(1<<16)+1];
		long[] ys = new long[xs.length];
		
		for(int j = 0; j <= 48; j += 16) {
			Arrays.fill(cnt, 0);
			for(long x : xs) { cnt[(int)(x>>j&0xFFFF)+1]++; }
			for(int i = 1; i < cnt.length; i++) { cnt[i] += cnt[i-1]; }
			for(long x : xs) { ys[cnt[(int)(x>>j&0xFFFF)]++] = x; }
			{ final long[] t = xs; xs = ys; ys = t; }
		}
	}
	

	static void arrayIntSort(int[][] x, int... keys) {
		Arrays.sort(x, new ArrayIntsComparator(keys));
	}
	
	static class ArrayIntsComparator implements Comparator<int[]> {
		final int[] KEY;
		
		public ArrayIntsComparator(int... key) {
			KEY = key;
		}
		
		@Override
		public int compare(int[] o1, int[] o2) {
			for(int k : KEY) if(o1[k] != o2[k]) return o1[k] - o2[k];
			return 0;
		}
	}
	
	static class ArrayIntComparator implements Comparator<int[]> {
		final int KEY;
		
		public ArrayIntComparator(int key) {
			KEY = key;
		}
		
		@Override
		public int compare(int[] o1, int[] o2) {
			return o1[KEY] - o2[KEY];
		}
	}
	
	
	void main() throws IOException {
		

		try {
			run();
		}
		catch (EndOfFileRuntimeException e) { }
		io.out.flush();
	}

	public static void main(String[] args) throws IOException {
		new D().main();
	}
	
	static class EndOfFileRuntimeException extends RuntimeException {
		private static final long serialVersionUID = -8565341110209207657L; }

	static
	public class IOFast {
		private BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		private PrintWriter out = new PrintWriter(System.out);

		void setFileIO(String ins, String outs) throws IOException {
			out.flush();
			out.close();
			in.close();
			in = new BufferedReader(new FileReader(ins));
			out = new PrintWriter(new FileWriter(outs));
			System.err.println("reading from " + ins);
		}

		

		private static int pos, readLen;
		private static final char[] buffer = new char[1024 * 8];
		private static char[] str = new char[500*8*2];
		private static boolean[] isDigit = new boolean[256];
		private static boolean[] isSpace = new boolean[256];
		private static boolean[] isLineSep = new boolean[256];

		static {
			for(int i = 0; i < 10; i++) { isDigit['0' + i] = true; }
			isDigit['-'] = true;
			isSpace[' '] = isSpace['\r'] = isSpace['\n'] = isSpace['\t'] = true;
			isLineSep['\r'] = isLineSep['\n'] = true;
		}

		public int read() throws IOException {
			if(pos >= readLen) {
				pos = 0;
				readLen = in.read(buffer);
				if(readLen <= 0) { throw new EndOfFileRuntimeException(); }
			}
			return buffer[pos++];
		}

		public int nextInt() throws IOException {
			int len = 0;
			str[len++] = nextChar();
			len = reads(len, isSpace);
			
			int i = 0;
			int ret = 0;
			if(str[0] == '-') { i = 1; }
			for(; i < len; i++) ret = ret * 10 + str[i] - '0';
			if(str[0] == '-') { ret = -ret; }
			return ret;


		}

		public long nextLong() throws IOException {
			int len = 0;
			str[len++] = nextChar();
			len = reads(len, isSpace);
			
			int i = 0;
			long ret = 0;
			if(str[0] == '-') { i = 1; }
			for(; i < len; i++) ret = ret * 10 + str[i] - '0';
			if(str[0] == '-') { ret = -ret; }
			return ret;


		}

		public char nextChar() throws IOException {
			while(true) {
				final int c = read();
				if(!isSpace[c]) { return (char)c; }
			}
		}
		
		int reads(int len, boolean[] accept) throws IOException {
			try {
				while(true) {
					final int c = read();
					if(accept[c]) { break; }
					
					if(str.length == len) {
						char[] rep = new char[str.length * 3 / 2];
						System.arraycopy(str, 0, rep, 0, str.length);
						str = rep;
					}
					
					str[len++] = (char)c;
				}
			}
			catch(EndOfFileRuntimeException e) { ; }
			
			return len;
		}
		
		int reads(char[] cs, int len, boolean[] accept) throws IOException {
			try {
				while(true) {
					final int c = read();
					if(accept[c]) { break; }
					cs[len++] = (char)c;
				}
			}
			catch(EndOfFileRuntimeException e) { ; }
			
			return len;
		}

		public char[] nextLine() throws IOException {
			int len = 0;


			str[len++] = (char)read();
			len = reads(len, isLineSep);
			
			try {
				if(str[len-1] == '\r') { len--; read(); }
			}
			catch(EndOfFileRuntimeException e) { ; }
			
			return Arrays.copyOf(str, len);
		}

		public String nextString() throws IOException {
			return new String(next());
		}

		public char[] next() throws IOException {
			int len = 0;
			str[len++] = nextChar();
			len = reads(len, isSpace);
			return Arrays.copyOf(str, len);
		}

		public int next(char[] cs) throws IOException {
			int len = 0;
			cs[len++] = nextChar();
			len = reads(cs, len, isSpace);
			return len;
		}

		public double nextDouble() throws IOException {
			return Double.parseDouble(nextString());
		}

		public long[] nextLongArray(final int n) throws IOException {
			final long[] res = new long[n];
			for(int i = 0; i < n; i++) {
				res[i] = nextLong();
			}
			return res;
		}

		public int[] nextIntArray(final int n) throws IOException {
			final int[] res = new int[n];
			for(int i = 0; i < n; i++) {
				res[i] = nextInt();
			}
			return res;
		}

		public int[][] nextIntArray2D(final int n, final int k) throws IOException {
			final int[][] res = new int[n][];
			for(int i = 0; i < n; i++) {
				res[i] = nextIntArray(k);
			}
			return res;
		}

		public int[][] nextIntArray2DWithIndex(final int n, final int k) throws IOException {
			final int[][] res = new int[n][k+1];
			for(int i = 0; i < n; i++) {
				for(int j = 0; j < k; j++) {
					res[i][j] = nextInt();
				}
				res[i][k] = i;
			}
			return res;
		}

		public double[] nextDoubleArray(final int n) throws IOException {
			final double[] res = new double[n];
			for(int i = 0; i < n; i++) {
				res[i] = nextDouble();
			}
			return res;
		}

	}

}

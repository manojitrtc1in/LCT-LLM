
import java.io.*;
import java.math.*;
import java.util.*;

import static java.util.Arrays.*;

public class C {
	private static final int mod = (int)1e9+9;

	final Random random = new Random(0);
	final IOFast io = new IOFast();

	

	RMQInt rmq;
	BIT bit;
	int[] xs;
	int rec(int l, int r) {
		if(l == r) return 0;
		int idx = rmq.QueryIndex(l, r);
		int v = bit.sum(idx+1);


		if(xs[idx] + v != 0) {
			bit.add(l+1, -(xs[idx] + v));
			bit.add(r+1, (xs[idx] + v));
			return Math.min(rec(l, idx) + rec(idx + 1, r) + xs[idx] + v, r - l);
		}
		else {
			return rec(l, idx) + rec(idx + 1, r);
		}
	}
	
	public void run() throws IOException {


		int TEST_CASE = 1;
		while(TEST_CASE-- != 0) {
			int n = io.nextInt();
			xs = io.nextIntArray(n);
			bit = new BIT(n);
			rmq = new RMQInt(1<<29);
			rmq.build(n);
			for(int i = 0; i < n; i++) rmq.Update(xs[i], i);
			io.out.println(rec(0, n));
		}
	}
	
	static
	class RMQInt {
		int n;
		int[] xs;
		int[] ys;
		final int INF;

		public RMQInt(int inf) {
			INF = inf;
		}

		int Min(int a, int b) { return a == INF ? b : (b == INF ? a : (a<=b?a:b)); }
		int minIndex(int a, int b) { return a == -1 ? b : (b == -1 ? a : (Min(xs[a], xs[b]) == xs[a] ? a : b)); }

		public void build(int m) {
			for(n = 1; n<m; n<<=1) ;
			xs = new int[2*n];
			ys = new int[2*n];
			for(int i = 0; i < 2*n; i++) {
				ys[i] = i;
			}
			clear();
		}
		
		public void clear() {
			Arrays.fill(xs, INF);
		}

		

		public void Update(int v, int idx) {
			xs[idx += n - 1] = v;
			while(idx > 0) {
				idx = (idx-1)/2;
				xs[idx] = Min(xs[idx*2+1], xs[idx*2+2]);
				ys[idx] = ys[minIndex(idx*2+1, idx*2+2)];
			}
		}

		

		public int Query(int l, int r) { 
			return Query(l, r, 0, n, 0);
		}
		int Query(int l, int r, int a, int b, int k) {
			if(l <= a && b <= r) return xs[k];
			if(b <= l || r <= a) return INF;
			final int m = (a+b)/2;
			return Min(
					Query(l, r, a, m, 2*k+1),
					Query(l, r, m, b, 2*k+2));
		}

		

		public int QueryIndex(int l, int r) { return QueryIndex(l, r, 0, n, 0) - (n - 1); }
		int QueryIndex(int l, int r, int a, int b, int k) {
			if(l <= a && b <= r) return ys[k];
			if(b <= l || r <= a) return -1;
			final int m = (a+b)/2;
			return minIndex(
					QueryIndex(l, r, a, m, 2*k+1),
					QueryIndex(l, r, m, b, 2*k+2));
		}
	}

	
	static long powmod(long n, long r, int m) {
		long res = 1;
		for(; r != 0; r >>>= 1, n = n * n % m) {
			if((r&1) == 1) {
				res = res * n;
				if(res >= m) {
					res %= m;
				}
			}
		}
		return res;
	}
	
	static
	class SegGeometricProgression {
		final int mod = (int)1e9+9;
		final long invX1;
		final long x;
		final int n;
		final int[] powX;
		final int[] seg;
		final int[] add;
		
		public SegGeometricProgression(final int n, final int r) {
			this.x = r;
			this.invX1 = powmod(x - 1, mod - 2, mod);
			this.n = Integer.highestOneBit(n) << 1;
			seg = new int[this.n << 1];
			add = new int[this.n << 1];
			powX = new int[n+1];
			powX[0] = 1;
			for(int i = 1; i < powX.length; i++) {
				powX[i] = (int)(powX[i-1] * x % mod);
			}
		}
		
		void propagate(int curL, int curR, int k) {
			if(add[k] != 0) {
				final int curM = (curL + curR) / 2;
				add(curL, curR, 2 * k + 1, add[k], curL, curM);
				add(curL, curR, 2 * k + 2, (int)(add[k] * (long)powX[curM - curL] % mod), curM, curR);
				add[k] = 0;
			}
		}

		int get(int l, int r) { return get(l, r, 0, 0, n); }
		int get(int l, int r, int k, int curL, int curR) {
			if(curR <= l || curL >= r) return 0;
			if(l <= curL && curR <= r) { return seg[k]; }
			propagate(curL, curR, k);
			final int curM = (curL + curR) / 2;
			int ans = 0;
			ans += get(l, r, 2 * k + 1, curL, curM);
			ans += get(l, r, 2 * k + 2, curM, curR);
			if(ans >= mod) ans -= mod;
			if(ans < 0) throw new RuntimeException();
			return ans;
		}

		void add(int l, int r, int v) { add(l, r, 0, v, 0, n); }
		void add(int l, int r, int k, int v, int curL, int curR) {
			if(curR <= l || curL >= r) return;
			if(l <= curL && curR <= r) {
				add[k] += v;
				if(add[k] >= mod) add[k] -= mod;
				seg[k] += v * (powX[curR - curL] - 1L) % mod * invX1 % mod;
				if(seg[k] >= mod) seg[k] -= mod;
				if(add[k] < 0) throw new RuntimeException();
				if(seg[k] < 0) throw new RuntimeException();


				return;
			}
			final int curM = (curL + curR) / 2;
			propagate(curL, curR, k);
			add(l, r, 2 * k + 1, v, curL, curM);
			add(l, r, 2 * k + 2, (int)(v * (long)powX[Math.max(0, curM - Math.max(l, curL))] % mod), curM, curR);
			seg[k] = seg[2*k+1] + seg[2*k+2];
			if(seg[k] >= mod) seg[k] -= mod;
			if(seg[k] < 0) throw new RuntimeException();
		}
	}

	
	static
	class BIT {
		final int n;
		final int[] bit;

		public BIT(int size) {
			n = size;
			bit = new int[n + 1];
		}
		
		public void clear() { Arrays.fill(bit, 0); }

		

		public int sum(int i, int j) {
			return (sum(j) - sum(i)) % mod;
		}

		public int sum(int i) {
			int res = 0;
			for (; i > 0; i -= i & -i) {
				res += bit[i];
				while(res >= mod) res -= mod;
			}
			return res;
		}

		

		public void add(int i, int x) {
			if(i == 0) throw new RuntimeException();
			for (; i <= n; i += i & -i) {
				bit[i] += x;
				while(bit[i] >= mod) bit[i] -= mod;
			}
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
		new C().main();
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

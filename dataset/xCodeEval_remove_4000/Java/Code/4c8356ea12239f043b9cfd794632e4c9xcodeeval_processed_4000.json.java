
import java.io.*;
import java.math.*;
import java.util.*;

import static java.util.Arrays.*;

public class C {
	private static final int mod = (int)1e9+7;

	final Random random = new Random(0);
	final IOFast io = new IOFast();

	

	public void run() throws IOException {


		int TEST_CASE = 1;
		while(TEST_CASE-- != 0) {
			int n = io.nextInt();
			int m = n;
			Point[] p = new Point[n];
			int[][] pt = new int[n][2];
			
			for(int i = 0; i < n; i++) {
				pt[i][0] = io.nextInt();
				pt[i][1] = io.nextInt();
				p[i] = new Point(pt[i][0], pt[i][1]);
			}
			
			Polygon poly = new Polygon(p);
			

			boolean[][] g = new boolean[n][n];
			for(int i = 0; i < n; i++) {
				for(int j = i + 1; j < n; j++) {
					g[j][i] = g[i][j] = poly.id9(i, j);


				}
			}
			
			long[][] dp = new long[n][n];
			for(int i = 0; i < n; i++) {
				dp[i][i] = 1;
				if(i < n - 1) dp[i][i+1] = 1;
			}
			
			for(int k = 3; k <= n; k++) {
				for(int i = 0; i + k <= n; i++) {
					final int j = i + k - 1;
					if(!g[i][j]) continue;
					for(int l = i + 1; l < j; l++) if(g[i][l] && g[l][j]) {
						dp[i][j] += dp[i][l] * dp[l][j] % mod;
						dp[i][j] %= mod;
					}
				}
			}
			
			io.out.println(dp[0][n-1] % mod);
		}
	}
	
	
	static
	public class Polygon {
		private static final double eps = 1e-9;
		
		int n;
		Point[] ps;
		
		public Polygon(Point[] ps) {
			this.ps = ps;
			this.n = ps.length;
		}

		
		

		public boolean inside(Point pt) {
			final boolean onEdge = true;
			
			boolean in = false;
			Point left = new Point(1e10, 0).rotate(1);
			for(int i = 0; i < n; i++) {
				Point a = ps[i];
				Point b = ps[(i+1)%n];
				
				final int ccw = Point.ccw(a, b, pt);
				if(ccw == 0) {
					return onEdge;
				}
				
				
				if(Point.id3(a, b, pt, left)) {
					in ^= true;
				}
			}
			return in;
		}
		
		

		public boolean id9(int i, int j) {
			if(Math.abs(j - i) == 1 || Math.abs(j - i) == n - 1) {
				return true;
			}
			
			if(!inside(ps[i].add(ps[j]).div(2))) {
				return false;
			}

			
			
			for(int k = -1; k <= 1; k += 2) {
				final int l1 = (i + k + n) % n;
				final int l2 = (j + k + n) % n;
				if(Point.ccw(ps[i], ps[l1], ps[j]) == -2) return false;
				if(Point.ccw(ps[j], ps[l2], ps[i]) == -2) return false;
			}
			
			for(int k = 0; k < n; k++) {
				final int l = (k + 1) % n;
				if(i == k || i == l || j == k || j == l) continue;
				Point a = ps[i];
				Point b = ps[j];
				Point c = ps[k];
				Point d = ps[l];
				if(Point.id3(a, b, c, d)) {
					return false;
				}
			}
			
			return true;
		}
	}
	
	
	static
	public class Point implements Comparable<Point> {
		public double x, y;
		public Point() { }
		public Point(double xx, double yy) { x = xx; y = yy; }
		public Point(Point p) { this(p.x, p.y); }
		public Point rotate(final double theta) {
			final double a = x, b = y;
			x = a * Math.cos(theta) - b * Math.sin(theta);
			y = a * Math.sin(theta) + b * Math.cos(theta);
			return this;
		}
		public Point addM(Point p) { return addM(p.x, p.y); }
		public Point addM(double x, double y) {
			this.x += x;
			this.y += y;
			return this;
		}
		public Point add(Point p) { return add(p.x, p.y); }
		public Point add(double x, double y) {
			return new Point(this).addM(x, y);
		}
		public Point subM(Point p) { return subM(p.x, p.y); }
		public Point subM(double x, double y) {
			this.x -= x;
			this.y -= y;
			return this;
		}
		public Point sub(Point p) { return sub(p.x, p.y); }
		public Point sub(double x, double y) {
			return new Point(this).subM(x, y);
		}
		public Point mulM(double d) {
			x *= d;
			y *= d;
			return this;
		}
		public Point mul(double d) {
			return new Point(this).mulM(d);
		}
		public Point divM(double v) {
			this.x /= v;
			this.y /= v;
			return this;
		}
		public Point div(double v) {
			return new Point(this).divM(v);
		}

		public static double dist(Point a, Point b) { return a.sub(b).abs(); }
		public static double cross(Point a, Point b) { return a.x*b.y - a.y*b.x; }
		public static double dot(Point a, Point b) { return a.x*b.x + a.y*b.y; }
		public double dot(Point p) { return dot(this, p); }

		public double norm() { return x*x+y*y; }
		public double abs() { return Math.sqrt(norm()); }

		

		

		static int ccw(Point a, Point b, Point c) {
			b=b.sub(a); c=c.sub(a);
			if (cross(b, c) > 0)   return +1;       

			if (cross(b, c) < 0)   return -1;       

			if (dot(b, c) < 0)     return +2;       

			if (b.norm() < c.norm()) return -2;       

			return 0;
		}

		

		static boolean id3(Point[] p, Point[] q) {
			return ccw(p[0], p[1], q[0]) * ccw(p[0], p[1], q[1]) <= 0 &&
					ccw(q[0], q[1], p[0]) * ccw(q[0], q[1], p[1]) <= 0;
		}

		static boolean id3(Point p1, Point p2, Point q1, Point q2) {
			return ccw(p1, p2, q1) * ccw(p1, p2, q2) <= 0 &&
					ccw(q1, q2, p1) * ccw(q1, q2, p2) <= 0;
		}
		
		public String toString() {
			return "(" + x + "," + y + ")";
		}
		
		@Override
		public int compareTo(Point o) {
			final int cmp = Double.compare(x, o.x);
			return cmp != 0 ? cmp : Double.compare(y, o.y);
		}
		
		public Point copy() {
			return new Point(this);
		}
	}
	
	static
	public class Segment {
		private static final double eps = 1e-9;
		
		public Point s, t;
		
		public Segment(Point a, Point b) { s = a; t = b; }
		public Segment() { }
		
		public double cross(Point p) {
			final double x1 = p.x - s.x, y1 = p.y - s.y;
			final double x2 = t.x - s.x, y2 = t.y - s.y;
			return x1 * y2 - x2 * y1;
		}
		
		public boolean intersect(Segment seg) {
			final double z11 = Math.signum(cross(seg.s)), z12 = Math.signum(cross(seg.t));
			final double z21 = Math.signum(seg.cross(s)), z22 = Math.signum(seg.cross(t));
			return z11 * z12 <= 0 && z21 * z22 <= 0;
		}
		
		public Point projection(Point p) {
			final Point d = s.sub(t);
			final double t = p.sub(s).dot(d) / d.norm();
			return d.mulM(t).addM(s);
		}
		
		public static Point projection(Point s, Point t, Point p) {
			final Point d = s.sub(t);
			final double tt = p.sub(s).dot(d) / d.norm();
			return d.mulM(tt).addM(s);
		}
		
		public double dist(Segment seg) {
			if(intersect(seg)) return 0;
			return Math.min(
					Math.min(dist(seg.s), dist(seg.t)),
					Math.min(seg.dist(s), seg.dist(t)));
		}
		
		boolean intersect(Point p) {
			return s.sub(p).abs() + t.sub(p).abs() - t.sub(s).abs() < eps;
		}
		
		public double dist(final Point pt) {
			final Point p = projection(pt);
			if(intersect(p)) return p.subM(pt).abs();
			return Math.min(s.sub(pt).abs(), t.sub(pt).abs());
		}
		
		void set(final Point s, final Point t) {
			this.s = s;
			this.t = t;
		}
		
		public String toString() {
			return "[" + s + ";" + t + "]";
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
	

	static void id12(int[] xs) {
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
	
	static void id12(long[] xs) {
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
	

	static void id2(int[][] x, int... keys) {
		Arrays.sort(x, new id14(keys));
	}
	
	static class id14 implements Comparator<int[]> {
		final int[] KEY;
		
		public id14(int... key) {
			KEY = key;
		}
		
		@Override
		public int compare(int[] o1, int[] o2) {
			for(int k : KEY) if(o1[k] != o2[k]) return o1[k] - o2[k];
			return 0;
		}
	}
	
	static class id10 implements Comparator<int[]> {
		final int KEY;
		
		public id10(int key) {
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
		catch (id1 e) { }
		io.out.flush();
	}

	public static void main(String[] args) throws IOException {
		new C().main();
	}
	
	static class id1 extends RuntimeException {
		private static final long id8 = -8565341110209207657L; }

	static
	public class IOFast {
		private BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		private PrintWriter out = new PrintWriter(System.out);

		void id6(String ins, String outs) throws IOException {
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
		private static boolean[] id0 = new boolean[256];

		static {
			for(int i = 0; i < 10; i++) { isDigit['0' + i] = true; }
			isDigit['-'] = true;
			isSpace[' '] = isSpace['\r'] = isSpace['\n'] = isSpace['\t'] = true;
			id0['\r'] = id0['\n'] = true;
		}

		public int read() throws IOException {
			if(pos >= readLen) {
				pos = 0;
				readLen = in.read(buffer);
				if(readLen <= 0) { throw new id1(); }
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
			catch(id1 e) { ; }
			
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
			catch(id1 e) { ; }
			
			return len;
		}

		public char[] nextLine() throws IOException {
			int len = 0;


			str[len++] = (char)read();
			len = reads(len, id0);
			
			try {
				if(str[len-1] == '\r') { len--; read(); }
			}
			catch(id1 e) { ; }
			
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

		public long[] id13(final int n) throws IOException {
			final long[] res = new long[n];
			for(int i = 0; i < n; i++) {
				res[i] = nextLong();
			}
			return res;
		}

		public int[] id4(final int n) throws IOException {
			final int[] res = new int[n];
			for(int i = 0; i < n; i++) {
				res[i] = nextInt();
			}
			return res;
		}

		public int[][] id5(final int n, final int k) throws IOException {
			final int[][] res = new int[n][];
			for(int i = 0; i < n; i++) {
				res[i] = id4(k);
			}
			return res;
		}

		public int[][] id7(final int n, final int k) throws IOException {
			final int[][] res = new int[n][k+1];
			for(int i = 0; i < n; i++) {
				for(int j = 0; j < k; j++) {
					res[i][j] = nextInt();
				}
				res[i][k] = i;
			}
			return res;
		}

		public double[] id11(final int n) throws IOException {
			final double[] res = new double[n];
			for(int i = 0; i < n; i++) {
				res[i] = nextDouble();
			}
			return res;
		}

	}

}

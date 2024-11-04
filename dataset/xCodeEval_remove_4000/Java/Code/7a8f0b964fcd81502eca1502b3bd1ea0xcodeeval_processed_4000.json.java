

import java.io.*;
import java.util.*;

import static java.lang.Math.*;
import static java.util.Arrays.fill;
import static java.util.Arrays.binarySearch;
import static java.util.Arrays.sort;

public class Main {
	
	static long initTime;
	static final Random rnd = new Random(7777L);
	
	public static void main(String[] args) throws IOException {
		initTime = System.currentTimeMillis();
		new Thread(null, new Runnable() {
			public void run() {
				try {
					try {
						if (new File("input.txt").exists())
							System.setIn(new FileInputStream("input.txt"));
					} catch (SecurityException e) {}


					new Main().run();




				} catch (IOException e) {
					e.printStackTrace();
				}
			}
		}, "1", 1L << 24).start(); 
	}

	void run() throws IOException {
		in = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		solve();
		out.close();
		in.close();
	}
	
	

	final double EPS = 1e-7;
	
	id9 pp = new id9();
	double rP;
	double vP;
	double omegaP;
	
	id9 ps = new id9();
	double vs;
	
	id6 star;
	
	void solve() throws IOException  {
		
		double xp = nextDouble();
		double yp = nextDouble();
		
		pp.set(xp, yp);
		rP = sqrt(xp * xp + yp * yp);
		vP = nextDouble();
		
		ps.set(nextDouble(), nextDouble());
		vs = nextDouble();
		
		double tvp = 1;
		
		vP /= tvp;
		vs /= tvp;
		
		omegaP = vP / rP;
		star = new id6(new id9(0.0, 0.0), nextDouble());
		
		double ans = 3e6;
		
		double left = 0;
		double right = ans;
		
		for (int it = 0; it < 10000; it++) {
			
			double mid = 0.5 * (left + right);
			
			if (can(mid)) {
				right = mid;
				ans = min(ans, mid);
			} else {
				left = mid;
			}
			
		}
		






		


		
		out.println(ans / tvp);
		
	}
	
	boolean can(double t) {


		return id4(ps, pp.rotate(t * vP / rP)) < t * vs;
	}

	double id4(id9 p1, id9 p2) {

		if (hasCSC(p1, p2, star)) {
			
			id9[] tp1 = id10(p1, star);
			id9[] tp2 = id10(p2, star);
			
			double ret = 1e100;
			
			ret = min(ret, id1(p1, p2, tp1[0], tp2[0]));
			ret = min(ret, id1(p1, p2, tp1[0], tp2[1]));
			ret = min(ret, id1(p1, p2, tp1[1], tp2[0]));
			ret = min(ret, id1(p1, p2, tp1[1], tp2[1]));
			
			return ret;
		}
		
		return dist(p1, p2);
	}

	public boolean hasCSC(id9 p1, id9 p2, id6 c) {
		double A = p2.y - p1.y;
		double B = p1.x - p2.x;
		double d = A * A + B * B;
		
		double dist = 0.0;
		
		if (abs(d) < EPS) {
			dist = dist(p1, c.c);
		} else {
			double t = (B * (p1.x - c.c.x) - A * (p1.y - c.c.y)) / d;
			if (0.0 <= t && t <= 1.0) {
				dist = sqrt(sqr(p1.x - B * t - c.c.x) + sqr(p1.y + A * t - c.c.y));
			} else {
				dist = min(dist(p1, c.c), dist(p2, c.c));
			}
		}
		
		return dist <= c.r + EPS;
	}
	
	double id1(id9 p1, id9 p2, id9 tp1, id9 tp2) {
		double phi = acos(max(-1.0, min(1.0, tp1.scalarProduct(tp2) / tp1.len() / tp2.len())));
		return dist(p1, tp1) + dist(p2, tp2) + star.r * phi;
	}

	
	id9 cll(id5 l1, id5 l2) {
		double det = -id13(l1.A, l1.B, l2.A, l2.B);
		if (abs(det) < EPS)
			return null;
		return new id9(id13(l1.C, l1.B, l2.C, l2.B) / det, id13(l1.A, l1.C, l2.A, l2.C) / det);
	}
	
	
	id9 css(id5 s1, id5 s2) {
		id9 its = cll(s1, s2);
		return (its != null && s1.contains(its) && s2.contains(its)) ? its : null;
	}
	
	
	id9[] clc(id5 l, id6 c) {
		double d = l.dist(c.c);
		if (d > c.r + EPS)
			return null;
		id9 h = l.projection(c.c);
		id9 v = l.dir().normalize(sqrt(c.r * c.r - d * d));
		return new id9[] { h.sub(v), h.add(v) };
	}
	
	
	id9[] ccc(id6 c1, id6 c2) {
		double d = dist(c1.c, c2.c);
		if (d < EPS && c1.r < EPS && c2.r < EPS) 

			return new id9[] { c1.c };
		if (d < abs(c1.r - c2.r) - EPS || d > c1.r + c2.r + EPS || d < EPS)
			return null;
		double cos = getCos(d, c1.r, c2.r);
		double sin = sqrt(1.0 - cos * cos);
		id9 v = c2.c.sub(c1.c).normalize(c1.r);
		return new id9[] { c1.c.add(v.rotate(cos, sin)), c1.c.add(v.rotate(cos, -sin)) };
	}
	
	
	
	
	id5 tcpc(id9 p, id6 c) {
		if (c.r < EPS || !c.lay(p))
			return null;
		id9 n = c.c.sub(p).turn90();
		return new id5(p.sub(n), p.add(n));
	}
	
	
	id9[] id10(id9 p, id6 c) {
		double d = dist(p, c.c);
		double cos = c.r / d;
		double sin = sqrt(1.0 - cos * cos);
		id9 v = p.sub(c.c).normalize(c.r);
		






		
		return new id9[] { v.rotate(cos, sin), v.rotate(cos, -sin) };
	}
	
	
	id5[] tpc(id9 p, id6 c) {
		double d = dist(p, c.c);








		double sin = c.r / d;
		double cos = sqrt(1.0 - sin * sin);
		id9 v = c.c.sub(p).normalize(sqrt(d * d - c.r * c.r));
		return new id5[] { new id5(p, p.add(v.rotate(cos, sin))), new id5(p, p.add(v.rotate(cos, -sin))) };
	}
	
	
	id5[] intcc(id6 c1, id6 c2) {
		id5[] h = tpc(c2.c, new id6(c1.c, c1.r + c2.r));
		if (h != null) {
			h[0].shift(-c1.r);
			h[1].shift(c1.r);
		}
		return h;
	}
	
	
	id5[] id7(id6 c1, id6 c2) {
		if (c1.r > c2.r + EPS)
			return id7(c2, c1);
		id5[] h = tpc(c1.c, new id6(c2.c, c2.r - c1.r));
		if (h != null) {
			h[0].shift(-c1.r);
			h[1].shift(c1.r);
		}
		return h;
	}
	
	

	
	double sqr(double x) {
		return x * x;
	}
	
	 
	double id13(double a11, double a12, double a21, double a22) {
		return a11 * a22 - a12 * a21;
	}
	
	
	double cross(id9 p0, id9 p1, id9 p2) {
		return (p1.x - p0.x) * (p2.y - p0.y) - (p2.x - p0.x) * (p1.y - p0.y);
	}
	
	
	double getCos(double a, double b, double c) {
		return 0.5 * (a * a + b * b - c * c) / (a * b);
	}
	
	
	double id0(id9 c, id9 p) {
		return atan2(p.y - c.y, p.x - c.x);
	}
	
	
	double id2(id9 p1, id9 p2) {
		return sqr(p2.x - p1.x) + sqr(p2.y - p1.y);
	}
	
	
	double dist(id9 p1, id9 p2) {
		return sqrt(id2(p1, p2));
	}
	
	
	boolean between(double a, double x, double b) {
		return a <= x && x <= b;
	}
	
	
	boolean range(double a, double x, double b) {
		return between(a - EPS, x, b + EPS);
	}
	
	
	boolean interval(double a, double x, double b) {
		return between(a + EPS, x, b - EPS);
	}
	
	
	double sqrt(double x) {
		check(x >= -EPS);
		return Math.sqrt(max(0.0, x));
	}
	
	
	double acos(double x) {
		check(range(-1.0, x, 1.0));
		return Math.acos(max(-1.0, min(1.0, x)));
	}
	
		
	double asin(double x) {
		check(range(-1.0, x, 1.0));
		return Math.asin(max(-1.0, min(1.0, x)));
	}
	
	
	void check(boolean state) {
		if (!state) {
			System.err.println(new Error().getStackTrace());
			throw new RuntimeException();
		}
	}
	
	
	
	
	class id9 {
		double x;
		double y;
		
		
		id9() {
			x = y = 0.0;
		}
		
		
		id9(double x, double y) {
			this.set(x, y);
		}
		
		
		id9 set(double x, double y) {
			this.x = x;
			this.y = y;
			return this;
		}
		
		
		id9 copy() {
			return new id9(x, y);
		}
		
		
		id9 add(id9 v) {
			return new id9(x + v.x, y + v.y);
		}
		
		
		id9 inc(id9 v) {
			return set(x + v.x, y + v.y);
		}
		
		
		id9 sub(id9 v) {
			return new id9(x - v.x, y - v.y);
		}
		
		
		id9 dec(id9 v) {
			return set(x - v.x, y - v.y);
		}
		
		
		id9 mul(double K) {
			return new id9(K * x, K * y);
		}
		
		
		id9 scale(double K) {
			return set(K * x, K * y);
		}
		
		
		double len() {
			return sqrt(x * x + y * y);
		}
		
				
		id9 norm() {
			return norm(1.0);
		}
		
		
		id9 norm(double newLen) {
			return this.mul(newLen / len());
		}
		
		
		id9 normalize() {
			return this.normalize(1.0);
		}
		
		
		id9 normalize(double newLen) {
			return scale(newLen / len());
		}
		
		
		double scalarProduct(id9 v) {
			return x * v.x + y * v.y;
		}
		
		
		double crossProduct(id9 v) {
			return x * v.y - v.x * y;
		}
		
		
		id9 rotate90() {
			return new id9(-y, x);
		}
		
		
		id9 rotate(double angle) {
			double cos = cos(angle);
			double sin = sin(angle);
			return rotate(cos, sin);
		}
		
		
		id9 rotate(double cos, double sin) {
			return new id9(x * cos - y * sin, x * sin + y * cos);
		}
		
		
		id9 turn90() {
			return set(-y, x);
		}
		
		
		id9 turn(double angle) {
			double cos = cos(angle);
			double sin = sin(angle);
			return turn(cos, sin);
		}

		
		id9 turn(double cos, double sin) {
			return set(x * cos - y * sin, x * sin + y * cos);
		}

		@Override
		public boolean equals(Object obj) {
			id9 p = (id9) obj;
			return abs(x - p.x) < EPS && abs(y - p.y) < EPS;
		}
		
		@Override
		public String toString() {
			return String.format(Locale.US ,"(%.3f, %.3f)", x, y);
		}
		
		@Override
		protected Object clone() throws CloneNotSupportedException {
			return this.copy();
		}
	}
	
	
	class id5 {
		id9 p1;
		id9 p2;
		double A;
		double B;
		double C;
		
		
		id5(id9 p1, id9 p2) {
			this.set(p1.copy(), p2.copy());
		}

		
		id5(id9 p, id5 l) {
			this.set(p.copy(), l);
		}
		
		
		id5(double r, id5 l) {
			this.set(r, l);
		}
		
		id5 set(id9 p1, id9 p2) {
			this.p1 = p1;
			this.p2 = p2;
			A = p2.y - p1.y;
			B = p1.x - p2.x;
			C = -(A * p1.x + B * p1.y);
			return this;
		}
		
		id5 set(id9 p, id5 l) {
			p1 = p;
			p2 = p.add(l.normal());
			A = -l.B;
			B = l.A;
			C = -(A * p1.x + B * p1.y);
			return this;
		}
		
		id5 set(double r, id5 l) {
			id9 v = l.normal().normalize(r);
			p1 = l.p1.sub(v);
			p2 = l.p2.sub(v);
			A = l.A;
			B = l.B;
			C = -(A * p1.x + B * p1.y);
			return this;
		}
		
		
		id5 move(id9 v) {
			p1.inc(v);
			p2.inc(v);
			C = -(A * p1.x + B * p1.y);
			return this;
		}
		
		
		id5 shift(double r) {
			id9 v = this.normal().normalize(r);
			p1.dec(v);
			p2.dec(v);
			C = -(A * p1.x + B * p1.y);
			return this;
		}
		
		
		double calc(id9 p) {
			return A * p.x + B * p.y + C;
		}
		
		
		boolean lay(id9 p) {
			return abs(this.calc(p)) < EPS;
		}
		
		
		boolean contains(id9 p) {
			if (!lay(p))
				return false;
			return range(0.0, this.getT(p), 1.0);
		}
		
		
		double getT(id9 p) {
			if (!this.lay(p))
				return Double.NaN;
			if (abs(A) > EPS)
				return (p.y - p1.y) / A;
			if (abs(B) > EPS)
				return (p1.x - p.x) / B;
			throw new RuntimeException("Bad line");
		}
		
		
		id9 getPoint(double t) {
			return new id9(p1.x - B * t, p1.y + A * t);
		}
		
		
		double dist(id9 p) {
			return abs(this.calc(p)) / sqrt(A * A + B * B);
		}
		
		
		id9 dir() {
			return new id9(-B, A);
		}
		
		
		id9 normal() {
			return new id9(A, B);
		}
		
		
		id9 projection(id9 p) {
			double t = (B * (p1.x - p.x) - A * (p1.y - p.y)) / (A * A + B * B);
			return new id9(p1.x - B * t, p1.y + A * t);
		}
		
		
		id5 projection(id5 l) {
			return new id5(this.projection(l.p1), this.projection(l.p2));
		}
		
		@Override
		public String toString() {
			return "[" + p1 + ", " + p2 + "], " + String.format(Locale.US, "%.3fx + %.3fy + %.3f = 0", A, B, C);
		}
	}
	
	
	class id6 {
		id9 c;
		double r;
		
		id6(id9 c, double r) {
			this.set(c.copy(), r);
		}

		id6 set(id9 c, double r) {
			this.c = c;
			this.r = r;
			return this;
		}
		
		double area() {
			return PI * r * r;
		}
		
		boolean lay(id9 p) {
			return range(r, dist(c, p), r);
		}
		
		boolean contains(id9 p) {
			return dist(c, p) < r + EPS;
		}
	}
	
	
	BufferedReader in;
	PrintWriter out;
	StringTokenizer st = new StringTokenizer("");
	
	String nextToken() throws IOException {
		while (!st.hasMoreTokens())
			st = new StringTokenizer(in.readLine());
		return st.nextToken();
	}
	
	int nextInt() throws IOException {
		return Integer.parseInt(nextToken());
	}
	
	long nextLong() throws IOException {
		return Long.parseLong(nextToken());
	}
	
	double nextDouble() throws IOException {
		return Double.parseDouble(nextToken());
	}
	
	int[] id3(int size) throws IOException {
		int[] ret = new int [size];
		for (int i = 0; i < size; i++)
			ret[i] = nextInt();
		return ret;
	}
	
	long[] id12(int size) throws IOException {
		long[] ret = new long [size];
		for (int i = 0; i < size; i++)
			ret[i] = nextLong();
		return ret;
	}
	
	double[] id8(int size) throws IOException {
		double[] ret = new double [size];
		for (int i = 0; i < size; i++)
			ret[i] = nextDouble();
		return ret;
	}
	
	String nextLine() throws IOException {
		st = new StringTokenizer("");
		return in.readLine();
	}
	
	boolean EOF() throws IOException {
		while (!st.hasMoreTokens()) {
			String s = in.readLine();
			if (s == null)
				return true;
			st = new StringTokenizer(s);
		}
		return false;
	}
	
	
	void printRepeat(String s, int count) {
		for (int i = 0; i < count; i++)
			out.print(s);
	}
	
	void printArray(int[] array) {
		if (array == null || array.length == 0)
			return;
		for (int i = 0; i < array.length; i++) {
			if (i > 0) out.print(' ');
			out.print(array[i]);
		}
		out.println();
	}
	
	void printArray(long[] array) {
		if (array == null || array.length == 0)
			return;
		for (int i = 0; i < array.length; i++) {
			if (i > 0) out.print(' ');
			out.print(array[i]);
		}
		out.println();
	}
	
	void printArray(double[] array) {
		if (array == null || array.length == 0)
			return;
		for (int i = 0; i < array.length; i++) {
			if (i > 0) out.print(' ');
			out.print(array[i]);
		}
		out.println();
	}
	
	void printArray(double[] array, String spec) {
		if (array == null || array.length == 0)
			return;
		for (int i = 0; i < array.length; i++) {
			if (i > 0) out.print(' ');
			out.printf(Locale.US, spec, array[i]);
		}
		out.println();
	}
	
	void printArray(Object[] array) {
		if (array == null || array.length == 0)
			return;
		boolean blank = false;
		for (Object x : array) {
			if (blank) out.print(' '); else blank = true;
			out.print(x);
		}
		out.println();
	}
	
	@SuppressWarnings("rawtypes")
	void printCollection(Collection collection) {
		if (collection == null || collection.isEmpty())
			return;
		boolean blank = false;
		for (Object x : collection) {
			if (blank) out.print(' '); else blank = true;
			out.print(x);
		}
		out.println();
	}
	
	
	static String memoryStatus() {
		return (Runtime.getRuntime().totalMemory() - Runtime.getRuntime().freeMemory() >> 20) + "/" + (Runtime.getRuntime().totalMemory() >> 20) + " MB";
	}
	
	static void checkMemory() {
		System.err.println(memoryStatus());
	}
	
	static long id11 = Long.MIN_VALUE;
	
	static void updateTimer() {
		id11 = System.currentTimeMillis();
	}
	
	static long elapsedTime() {
		return (System.currentTimeMillis() - id11);
	}
	
	static void checkTimer() {
		System.err.println(elapsedTime() + " ms");
	}
}

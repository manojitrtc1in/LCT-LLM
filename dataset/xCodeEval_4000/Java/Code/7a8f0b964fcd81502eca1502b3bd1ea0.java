

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
	
	Point2D pp = new Point2D();
	double rP;
	double vP;
	double omegaP;
	
	Point2D ps = new Point2D();
	double vs;
	
	Circle2D star;
	
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
		star = new Circle2D(new Point2D(0.0, 0.0), nextDouble());
		
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


		return distPlanetar(ps, pp.rotate(t * vP / rP)) < t * vs;
	}

	double distPlanetar(Point2D p1, Point2D p2) {

		if (hasCSC(p1, p2, star)) {
			
			Point2D[] tp1 = tppc(p1, star);
			Point2D[] tp2 = tppc(p2, star);
			
			double ret = 1e100;
			
			ret = min(ret, distWithStar(p1, p2, tp1[0], tp2[0]));
			ret = min(ret, distWithStar(p1, p2, tp1[0], tp2[1]));
			ret = min(ret, distWithStar(p1, p2, tp1[1], tp2[0]));
			ret = min(ret, distWithStar(p1, p2, tp1[1], tp2[1]));
			
			return ret;
		}
		
		return dist(p1, p2);
	}

	public boolean hasCSC(Point2D p1, Point2D p2, Circle2D c) {
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
	
	double distWithStar(Point2D p1, Point2D p2, Point2D tp1, Point2D tp2) {
		double phi = acos(max(-1.0, min(1.0, tp1.scalarProduct(tp2) / tp1.len() / tp2.len())));
		return dist(p1, tp1) + dist(p2, tp2) + star.r * phi;
	}

	
	Point2D cll(Line2D l1, Line2D l2) {
		double det = -det2x2(l1.A, l1.B, l2.A, l2.B);
		if (abs(det) < EPS)
			return null;
		return new Point2D(det2x2(l1.C, l1.B, l2.C, l2.B) / det, det2x2(l1.A, l1.C, l2.A, l2.C) / det);
	}
	
	
	Point2D css(Line2D s1, Line2D s2) {
		Point2D its = cll(s1, s2);
		return (its != null && s1.contains(its) && s2.contains(its)) ? its : null;
	}
	
	
	Point2D[] clc(Line2D l, Circle2D c) {
		double d = l.dist(c.c);
		if (d > c.r + EPS)
			return null;
		Point2D h = l.projection(c.c);
		Point2D v = l.dir().normalize(sqrt(c.r * c.r - d * d));
		return new Point2D[] { h.sub(v), h.add(v) };
	}
	
	
	Point2D[] ccc(Circle2D c1, Circle2D c2) {
		double d = dist(c1.c, c2.c);
		if (d < EPS && c1.r < EPS && c2.r < EPS) 

			return new Point2D[] { c1.c };
		if (d < abs(c1.r - c2.r) - EPS || d > c1.r + c2.r + EPS || d < EPS)
			return null;
		double cos = getCos(d, c1.r, c2.r);
		double sin = sqrt(1.0 - cos * cos);
		Point2D v = c2.c.sub(c1.c).normalize(c1.r);
		return new Point2D[] { c1.c.add(v.rotate(cos, sin)), c1.c.add(v.rotate(cos, -sin)) };
	}
	
	
	
	
	Line2D tcpc(Point2D p, Circle2D c) {
		if (c.r < EPS || !c.lay(p))
			return null;
		Point2D n = c.c.sub(p).turn90();
		return new Line2D(p.sub(n), p.add(n));
	}
	
	
	Point2D[] tppc(Point2D p, Circle2D c) {
		double d = dist(p, c.c);
		double cos = c.r / d;
		double sin = sqrt(1.0 - cos * cos);
		Point2D v = p.sub(c.c).normalize(c.r);
		






		
		return new Point2D[] { v.rotate(cos, sin), v.rotate(cos, -sin) };
	}
	
	
	Line2D[] tpc(Point2D p, Circle2D c) {
		double d = dist(p, c.c);








		double sin = c.r / d;
		double cos = sqrt(1.0 - sin * sin);
		Point2D v = c.c.sub(p).normalize(sqrt(d * d - c.r * c.r));
		return new Line2D[] { new Line2D(p, p.add(v.rotate(cos, sin))), new Line2D(p, p.add(v.rotate(cos, -sin))) };
	}
	
	
	Line2D[] intcc(Circle2D c1, Circle2D c2) {
		Line2D[] h = tpc(c2.c, new Circle2D(c1.c, c1.r + c2.r));
		if (h != null) {
			h[0].shift(-c1.r);
			h[1].shift(c1.r);
		}
		return h;
	}
	
	
	Line2D[] outtcc(Circle2D c1, Circle2D c2) {
		if (c1.r > c2.r + EPS)
			return outtcc(c2, c1);
		Line2D[] h = tpc(c1.c, new Circle2D(c2.c, c2.r - c1.r));
		if (h != null) {
			h[0].shift(-c1.r);
			h[1].shift(c1.r);
		}
		return h;
	}
	
	

	
	double sqr(double x) {
		return x * x;
	}
	
	 
	double det2x2(double a11, double a12, double a21, double a22) {
		return a11 * a22 - a12 * a21;
	}
	
	
	double cross(Point2D p0, Point2D p1, Point2D p2) {
		return (p1.x - p0.x) * (p2.y - p0.y) - (p2.x - p0.x) * (p1.y - p0.y);
	}
	
	
	double getCos(double a, double b, double c) {
		return 0.5 * (a * a + b * b - c * c) / (a * b);
	}
	
	
	double getPolarAngle(Point2D c, Point2D p) {
		return atan2(p.y - c.y, p.x - c.x);
	}
	
	
	double distSqr(Point2D p1, Point2D p2) {
		return sqr(p2.x - p1.x) + sqr(p2.y - p1.y);
	}
	
	
	double dist(Point2D p1, Point2D p2) {
		return sqrt(distSqr(p1, p2));
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
	
	
	
	
	class Point2D {
		double x;
		double y;
		
		
		Point2D() {
			x = y = 0.0;
		}
		
		
		Point2D(double x, double y) {
			this.set(x, y);
		}
		
		
		Point2D set(double x, double y) {
			this.x = x;
			this.y = y;
			return this;
		}
		
		
		Point2D copy() {
			return new Point2D(x, y);
		}
		
		
		Point2D add(Point2D v) {
			return new Point2D(x + v.x, y + v.y);
		}
		
		
		Point2D inc(Point2D v) {
			return set(x + v.x, y + v.y);
		}
		
		
		Point2D sub(Point2D v) {
			return new Point2D(x - v.x, y - v.y);
		}
		
		
		Point2D dec(Point2D v) {
			return set(x - v.x, y - v.y);
		}
		
		
		Point2D mul(double K) {
			return new Point2D(K * x, K * y);
		}
		
		
		Point2D scale(double K) {
			return set(K * x, K * y);
		}
		
		
		double len() {
			return sqrt(x * x + y * y);
		}
		
				
		Point2D norm() {
			return norm(1.0);
		}
		
		
		Point2D norm(double newLen) {
			return this.mul(newLen / len());
		}
		
		
		Point2D normalize() {
			return this.normalize(1.0);
		}
		
		
		Point2D normalize(double newLen) {
			return scale(newLen / len());
		}
		
		
		double scalarProduct(Point2D v) {
			return x * v.x + y * v.y;
		}
		
		
		double crossProduct(Point2D v) {
			return x * v.y - v.x * y;
		}
		
		
		Point2D rotate90() {
			return new Point2D(-y, x);
		}
		
		
		Point2D rotate(double angle) {
			double cos = cos(angle);
			double sin = sin(angle);
			return rotate(cos, sin);
		}
		
		
		Point2D rotate(double cos, double sin) {
			return new Point2D(x * cos - y * sin, x * sin + y * cos);
		}
		
		
		Point2D turn90() {
			return set(-y, x);
		}
		
		
		Point2D turn(double angle) {
			double cos = cos(angle);
			double sin = sin(angle);
			return turn(cos, sin);
		}

		
		Point2D turn(double cos, double sin) {
			return set(x * cos - y * sin, x * sin + y * cos);
		}

		@Override
		public boolean equals(Object obj) {
			Point2D p = (Point2D) obj;
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
	
	
	class Line2D {
		Point2D p1;
		Point2D p2;
		double A;
		double B;
		double C;
		
		
		Line2D(Point2D p1, Point2D p2) {
			this.set(p1.copy(), p2.copy());
		}

		
		Line2D(Point2D p, Line2D l) {
			this.set(p.copy(), l);
		}
		
		
		Line2D(double r, Line2D l) {
			this.set(r, l);
		}
		
		Line2D set(Point2D p1, Point2D p2) {
			this.p1 = p1;
			this.p2 = p2;
			A = p2.y - p1.y;
			B = p1.x - p2.x;
			C = -(A * p1.x + B * p1.y);
			return this;
		}
		
		Line2D set(Point2D p, Line2D l) {
			p1 = p;
			p2 = p.add(l.normal());
			A = -l.B;
			B = l.A;
			C = -(A * p1.x + B * p1.y);
			return this;
		}
		
		Line2D set(double r, Line2D l) {
			Point2D v = l.normal().normalize(r);
			p1 = l.p1.sub(v);
			p2 = l.p2.sub(v);
			A = l.A;
			B = l.B;
			C = -(A * p1.x + B * p1.y);
			return this;
		}
		
		
		Line2D move(Point2D v) {
			p1.inc(v);
			p2.inc(v);
			C = -(A * p1.x + B * p1.y);
			return this;
		}
		
		
		Line2D shift(double r) {
			Point2D v = this.normal().normalize(r);
			p1.dec(v);
			p2.dec(v);
			C = -(A * p1.x + B * p1.y);
			return this;
		}
		
		
		double calc(Point2D p) {
			return A * p.x + B * p.y + C;
		}
		
		
		boolean lay(Point2D p) {
			return abs(this.calc(p)) < EPS;
		}
		
		
		boolean contains(Point2D p) {
			if (!lay(p))
				return false;
			return range(0.0, this.getT(p), 1.0);
		}
		
		
		double getT(Point2D p) {
			if (!this.lay(p))
				return Double.NaN;
			if (abs(A) > EPS)
				return (p.y - p1.y) / A;
			if (abs(B) > EPS)
				return (p1.x - p.x) / B;
			throw new RuntimeException("Bad line");
		}
		
		
		Point2D getPoint(double t) {
			return new Point2D(p1.x - B * t, p1.y + A * t);
		}
		
		
		double dist(Point2D p) {
			return abs(this.calc(p)) / sqrt(A * A + B * B);
		}
		
		
		Point2D dir() {
			return new Point2D(-B, A);
		}
		
		
		Point2D normal() {
			return new Point2D(A, B);
		}
		
		
		Point2D projection(Point2D p) {
			double t = (B * (p1.x - p.x) - A * (p1.y - p.y)) / (A * A + B * B);
			return new Point2D(p1.x - B * t, p1.y + A * t);
		}
		
		
		Line2D projection(Line2D l) {
			return new Line2D(this.projection(l.p1), this.projection(l.p2));
		}
		
		@Override
		public String toString() {
			return "[" + p1 + ", " + p2 + "], " + String.format(Locale.US, "%.3fx + %.3fy + %.3f = 0", A, B, C);
		}
	}
	
	
	class Circle2D {
		Point2D c;
		double r;
		
		Circle2D(Point2D c, double r) {
			this.set(c.copy(), r);
		}

		Circle2D set(Point2D c, double r) {
			this.c = c;
			this.r = r;
			return this;
		}
		
		double area() {
			return PI * r * r;
		}
		
		boolean lay(Point2D p) {
			return range(r, dist(c, p), r);
		}
		
		boolean contains(Point2D p) {
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
	
	int[] nextIntArray(int size) throws IOException {
		int[] ret = new int [size];
		for (int i = 0; i < size; i++)
			ret[i] = nextInt();
		return ret;
	}
	
	long[] nextLongArray(int size) throws IOException {
		long[] ret = new long [size];
		for (int i = 0; i < size; i++)
			ret[i] = nextLong();
		return ret;
	}
	
	double[] nextDoubleArray(int size) throws IOException {
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
	
	static long prevTimeStamp = Long.MIN_VALUE;
	
	static void updateTimer() {
		prevTimeStamp = System.currentTimeMillis();
	}
	
	static long elapsedTime() {
		return (System.currentTimeMillis() - prevTimeStamp);
	}
	
	static void checkTimer() {
		System.err.println(elapsedTime() + " ms");
	}
}

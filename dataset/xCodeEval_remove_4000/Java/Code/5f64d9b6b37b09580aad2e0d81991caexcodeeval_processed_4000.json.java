import java.util.*;

import java.io.*;
import java.math.BigDecimal;
import java.math.BigInteger;
import java.math.MathContext;;

public class E {
	static BufferedReader br;
	static PrintWriter pw;
	static int inf = (int) 1e9;
	static long mod = (long) 1e9 + 7;

	static ArrayList<Integer> primes; 


	
	static ArrayList<Long> primeFactors(Long N) 

	{
		ArrayList<Long> factors = new ArrayList<Long>(); 

		int idx = 0, p = primes.get(idx);

		while (p * p <= N) {
			if (N % p == 0)
				factors.add((long) p);
			while (N % p == 0) {
				N /= p;
			}
			if (idx + 1 == primes.size())
				break;
			p = primes.get(++idx);
		}

		if (N != 1) 

			factors.add(N); 

		return factors;
	}

	static int[] isComposite;

	static void sieve(int N) 

	{
		isComposite = new int[N + 1];
		isComposite[0] = isComposite[1] = 1; 

		primes = new ArrayList<Integer>();

		for (int i = 2; i <= N; ++i) 

			if (isComposite[i] == 0) 

			{
				primes.add(i);
				if (1l * i * i <= N)
					for (int j = i * i; j <= N; j += i) 

														

						isComposite[j] = 1;
			}
	}

	static String reString(String s) {
		StringBuilder be = new StringBuilder();
		char[] se = s.toCharArray();
		for (int i = se.length - 1; i >= 0; i--)
			be.append(se[i]);
		return be.toString();
	}

	static int n;

	public static void main(String[] args) throws NumberFormatException, IOException, InterruptedException {
		br = new BufferedReader(new InputStreamReader(System.in));
		pw = new PrintWriter(System.out);

		StringTokenizer st = new StringTokenizer(br.readLine());
		int t = Integer.parseInt(st.nextToken());
		while (t-- > 0) {
			st = new StringTokenizer(br.readLine());
			int n = Integer.parseInt(st.nextToken());
			l = Integer.parseInt(st.nextToken());
			int[] a = id4();
			double s = 0;
			double e = 1e9;
			double ans = -1;




			for (int i = 0; i < 100; i++) {
				double mid = (s + e) / 2;
				if (check(a, mid)) {
					ans = mid;
					s = mid;
				} else
					e = mid;
			}
			pw.println(ans);
		}

		pw.flush();
		pw.close();

	}

	static int l;

	static boolean check(int[] a, double t) {
		double s = 0;
		int v = 1;
		double te = t;
		for (int i = 0; i < a.length; i++) {
			double d = a[i] - s;
			double time = d / v;
			if (time <= te) {
				te -= time;
				v++;
				s = a[i];
			} else {
				break;
			}
		}
		s += v * te;
		

		double s2 = l;
		int v2 = 1;
		te = t;
		for (int i = a.length - 1; i >= 0; i--) {
			double d = s2 - a[i];
			double time = d / v2;
			if (time <= te) {
				te -= time;
				v2++;
				s2 = a[i];
			} else {
				break;
			}
		}
		s2 -= v2 * te;
		return s <= s2;
	}

	static int m, k;

	static double[] memo;
	static ArrayList<Integer>[] adj;
	static ArrayList<Integer> g;

	static long gcd(long a, long b) {
		if (a == 0)
			return b;
		return gcd(b % a, a);
	}

	

	static long lcm(long a, long b) {
		return (a * b) / gcd(a, b);
	}

	static double dis(int x, int y, int z, int w) {
		return Math.sqrt((x - z) * (x - z) + (y - w) * (y - w));
	}

	static int[] id4() throws IOException {
		StringTokenizer st = new StringTokenizer(br.readLine());
		int[] a = new int[st.countTokens()];
		for (int i = 0; i < a.length; i++) {
			a[i] = Integer.parseInt(st.nextToken());
		}
		return a;
	}

	static class pair implements Comparable<pair> {
		int x;
		int y;

		public pair(int d, int u) {
			x = d;
			y = u;
		}

		@Override
		public int compareTo(pair o) {
			

			if (y == o.y)
				return x - o.x;
			return y - o.y;
		}

	}

	static class triple implements Comparable<triple> {
		int x;
		int y;
		int z;

		public triple(int a, int b, int c) {
			x = a;
			y = b;
			z = c;
		}

		@Override
		public int compareTo(triple o) {
			

			return x - o.x;
		}
	}

	static class LineSegment {

		Point p, q;

		LineSegment(Point a, Point b) {
			p = a;
			q = b;
		}

		boolean intersect(LineSegment ls) {
			Line l1 = new Line(p, q), l2 = new Line(ls.p, ls.q);
			if (l1.parallel(l2)) {
				if (l1.same(l2))
					return p.between(ls.p, ls.q) || q.between(ls.p, ls.q) || ls.p.between(p, q) || ls.q.between(p, q);
				return false;
			}
			Point c = l1.intersect(l2);
			return c.between(p, q) && c.between(ls.p, ls.q);
		}

	}

	static class Line {

		static final double INF = 1e9, EPS = 1e-9;

		double a, b, c;

		Line(Point p, Point q) {
			if (Math.abs(p.x - q.x) < EPS) {
				a = 1;
				b = 0;
				c = -p.x;
			} else {
				a = (p.y - q.y) / (q.x - p.x);
				b = 1.0;
				c = -(a * p.x + p.y);
			}

		}

		Line(Point p, double m) {
			a = -m;
			b = 1;
			c = -(a * p.x + p.y);
		}

		boolean parallel(Line l) {
			return Math.abs(a - l.a) < EPS && Math.abs(b - l.b) < EPS;
		}

		boolean same(Line l) {
			return parallel(l) && Math.abs(c - l.c) < EPS;
		}

		Point intersect(Line l) {
			if (parallel(l))
				return null;
			double x = (b * l.c - c * l.b) / (a * l.b - b * l.a);
			double y;
			if (Math.abs(b) < EPS)
				y = -l.a * x - l.c;
			else
				y = -a * x - c;

			return new Point(x, y);
		}

		Point closestPoint(Point p) {
			if (Math.abs(b) < EPS)
				return new Point(-c, p.y);
			if (Math.abs(a) < EPS)
				return new Point(p.x, -c);
			return intersect(new Line(p, 1 / a));
		}

	}

	static class Point implements Comparable<Point> {

		static final double EPS = 1e-9;

		double x, y;

		Point(double a, double b) {
			x = a;
			y = b;
		}

		public int compareTo(Point p) {
			if (Math.abs(x - p.x) > EPS)
				return x > p.x ? 1 : -1;
			if (Math.abs(y - p.y) > EPS)
				return y > p.y ? 1 : -1;
			return 0;
		}

		public double dist(Point p) {
			return Math.sqrt(sq(x - p.x) + sq(y - p.y));
		}

		double sq(double x) {
			return x * x;
		}

		Point rotate(double angle) {
			double c = Math.cos(angle), s = Math.sin(angle);
			return new Point(x * c - y * s, x * s + y * c);
		}
		

		


		Point rotate(double theta, Point p) 

		{
			Vector v = new Vector(p, new Point(0, 0));
			return translate(v).rotate(theta).translate(v.reverse());
		}

		Point translate(Vector v) {
			return new Point(x + v.x, y + v.y);
		}

		Point reflectionPoint(Line l) 

		{
			Point p = l.closestPoint(this);
			Vector v = new Vector(this, p);
			return this.translate(v).translate(v);
		}

		boolean between(Point p, Point q) {
			return x < Math.max(p.x, q.x) + EPS && x + EPS > Math.min(p.x, q.x) && y < Math.max(p.y, q.y) + EPS
					&& y + EPS > Math.min(p.y, q.y);
		}

		

		boolean onLine(Point a, Point b) {
			if (a.compareTo(b) == 0)
				return compareTo(a) == 0;
			return Math.abs(new Vector(a, b).cross(new Vector(a, this))) < EPS;
		}

		boolean onSegment(Point a, Point b) {
			if (a.compareTo(b) == 0)
				return compareTo(a) == 0;
			return onRay(a, b) && onRay(b, a);
		}

		

		boolean onRay(Point a, Point b) {
			if (a.compareTo(b) == 0)
				return compareTo(a) == 0;
			return new Vector(a, b).normalize().equals(new Vector(a, this).normalize()); 

		}

		

		

		public static boolean ccw(Point p, Point q, Point r) {
			return new Vector(p, q).cross(new Vector(p, r)) > 0;
		}

		static boolean collinear(Point p, Point q, Point r) {
			return Math.abs(new Vector(p, q).cross(new Vector(p, r))) < EPS;
		}

		static double angle(Point a, Point o, Point b) 

		{
			Vector oa = new Vector(o, a), ob = new Vector(o, b);
			return Math.acos(oa.dot(ob) / Math.sqrt(oa.norm2() * ob.norm2()));
		}

		double id1(Point p, Point a, Point b) 

														

		{
			if (a.compareTo(b) == 0)
				return p.dist(a);
			

			Vector ap = new Vector(a, p), ab = new Vector(a, b);
			double u = ap.dot(ab) / ab.norm2();
			Point c = a.translate(ab.scale(u));
			return p.dist(c);
		}
		


		double id2(Point p, Point a, Point b) {
			Vector ap = new Vector(a, p), ab = new Vector(a, b);
			double u = ap.dot(ab) / ab.norm2();
			if (u < 0.0)
				return p.dist(a);
			if (u > 1.0)
				return p.dist(b);
			return id1(p, a, b);
		}
		

	}

	static class Polygon {
		


		static final double EPS = 1e-9;

		Point[] g; 


		Polygon(Point[] o) {
			g = o;
		}

		double perimeter() {
			double sum = 0.0;
			for (int i = 0; i < g.length - 1; ++i)
				sum += g[i].dist(g[i + 1]);
			return sum;
		}

		double area() 

		{
			double area = 0.0;
			for (int i = 0; i < g.length - 1; ++i)
				area += g[i].x * g[i + 1].y - g[i].y * g[i + 1].x;
			return Math.abs(area) / 2.0; 

		}

		boolean id0() {
			if (g.length <= 3) 

				return false;
			boolean ccw = Point.ccw(g[g.length - 2], g[0], g[1]); 

			for (int i = 1; i < g.length - 1; ++i)
				if (Point.ccw(g[i - 1], g[i], g[i + 1]) != ccw)
					return false;
			return true;
		}

		boolean inside(Point p) 

		{
			double sum = 0.0;
			for (int i = 0; i < g.length - 1; ++i) {
				double angle = Point.angle(g[i], p, g[i + 1]);
				if ((Math.abs(angle) < EPS || Math.abs(angle - Math.PI) < EPS) && p.between(g[i], g[i + 1]))
					return true;
				if (Point.ccw(p, g[i], g[i + 1]))
					sum += angle;
				else
					sum -= angle;
			}

			return Math.abs(2 * Math.PI - Math.abs(sum)) < EPS; 

		}
		

		Polygon cutPolygon(Point a, Point b) 

		{
			Point[] ans = new Point[g.length << 1];
			Line l = new Line(a, b);
			Vector v = new Vector(a, b);

			int size = 0;
			for (int i = 0; i < g.length; ++i) {
				double left1 = v.cross(new Vector(a, g[i]));
				double left2 = i == g.length - 1 ? 0 : v.cross(new Vector(a, g[i + 1]));

				if (left1 + EPS > 0)
					ans[size++] = g[i];
				if (left1 * left2 + EPS < 0)
					ans[size++] = l.intersect(new Line(g[i], g[i + 1]));
			}

			if (size != 0 && ans[0] != ans[size - 1]) 

				ans[size++] = ans[0];
			return new Polygon(Arrays.copyOf(ans, size));
		}

		static Polygon id3(Point[] points) 

													

		{
			int n = points.length;
			Arrays.sort(points);
			Point[] ans = new Point[n << 1];
			int size = 0, start = 0;

			for (int i = 0; i < n; i++) {
				Point p = points[i];
				while (size - start >= 2 && !Point.ccw(ans[size - 2], ans[size - 1], p))
					--size;
				ans[size++] = p;
			}
			start = --size;

			for (int i = n - 1; i >= 0; i--) {
				Point p = points[i];
				while (size - start >= 2 && !Point.ccw(ans[size - 2], ans[size - 1], p))
					--size;
				ans[size++] = p;
			}
			

			return new Polygon(Arrays.copyOf(ans, size));
		}

		Point centroid() 

		{
			double cx = 0.0, cy = 0.0;
			for (int i = 0; i < g.length - 1; i++) {
				double x1 = g[i].x, y1 = g[i].y;
				double x2 = g[i + 1].x, y2 = g[i + 1].y;

				double f = x1 * y2 - x2 * y1;
				cx += (x1 + x2) * f;
				cy += (y1 + y2) * f;
			}
			double area = area(); 

			cx /= 6.0 * area;
			cy /= 6.0 * area;
			return new Point(cx, cy);
		}
	}

	static class Vector {

		double x, y;

		Vector(double a, double b) {
			x = a;
			y = b;
		}

		Vector(Point a, Point b) {
			this(b.x - a.x, b.y - a.y);
		}

		Vector scale(double s) {
			return new Vector(x * s, y * s);
		} 


		double dot(Vector v) {
			return (x * v.x + y * v.y);
		}

		double cross(Vector v) {
			return x * v.y - y * v.x;
		}

		double norm2() {
			return x * x + y * y;
		}

		Vector reverse() {
			return new Vector(-x, -y);
		}

		Vector normalize() {
			double d = Math.sqrt(norm2());
			return scale(1 / d);
		}
	}
}

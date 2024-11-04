import java.io.*;
import java.util.*;

public class tr2 {
	static PrintWriter out;
	static StringBuilder sb;
	static long inf = (long) 1e10;
	static ArrayList<Integer> primes;
	static int[] si;
	static long mod = (long) 998244353;
	static long num = (long) 1e9 + 7;
	static long[][] memo;
	static int n;
	static long k;
	static double m;
	static int[] a;
	static char[] s;
	static TreeSet<Integer> pr;
	static ArrayList <Integer> factors,times;
	public static void main(String[] args) throws Exception {
		Scanner sc = new Scanner(System.in);
		out = new PrintWriter(System.out);
		n=sc.nextInt();
		primes=new ArrayList<>();
		pr=new TreeSet<>();
		seive();
		TreeSet <Integer> k=new TreeSet<>();
		for(int g:primes)
			if(g>2)
			   k.add(g-2);
		int num=pr.ceiling(n);
		int left=num-n;
		 ArrayList <pair1> an=new ArrayList<>();
		for(int i=0;i<n;i++) {
			if(i==n-1)
				an.add(new pair1(i+1, 1));
			else
			    an.add(new pair1(i+1, i+2));
		}
		TreeSet <Integer> r=new TreeSet<>();
		for(int i=1;i<=n;i++) {
			r.add(i);
		}
	

		int node=0;
		 while(left>0) {
			 if(r.isEmpty()) {
				 System.out.println(-1);
				 return;
			 }
			 node=r.pollFirst();
			 int u=k.floor(left);
			

				

		

			

			 left-=u;
			 int tt=r.pollFirst();
			 for(int o=0,g=node+2;o<u;o++,g++) {
				 an.add(new pair1(node, r.pollFirst()));
			 }
			 r.add(tt);
		

		 }
		 out.println(num);
		 for(pair1 u:an)
			 out.println(u);
		 out.flush();
	}

	public static class pair1 implements Comparable<pair1> {
		int x;
		int y;

		pair1(int a, int i) {
			x = a;
			y = i;
		}

		public String toString() {
			return x + " " + y;
		}

		@Override
		public int compareTo(pair1 o) {
			return x - o.x;
		}
	}

	static long inver(long x) {
		long a = x;
		long e = (mod - 2);
		long res = 1;
		while (e > 0) {
			if ((e & 1) == 1) {
				res = ((1l * res * a) % mod);
			}
			a = (int) ((1l * a * a) % mod);
			e >>= 1;
		}
		return res % mod;
	}

	static class eq {
		long x;
		long y;
		long z;

		eq(long x, long y, long z) {
			this.x = x;
			this.y = y;
			this.z = z;
		}

		public String toString() {
			return x + " " + y + " " + z;
		}
	}

	static class id5 {
		long x;
		long y;
		long z;

		id5(long x, long y, long z) {
			this.x = x;
			this.y = y;
			this.z = z;
		}

		public String toString() {
			return x + " " + y + " " + z;
		}
	}

	static void seive() {
		si = new int[1000001];
		primes = new ArrayList<>();
		int N = 1000001;
		si[1] = 1;
		for (int i = 2; i < N; i++) {
			if (si[i] == 0) {
				si[i] = i;
				primes.add(i);
				pr.add(i);
			}
			for (int j = 0; j < primes.size() && primes.get(j) <= si[i] && (i * primes.get(j)) < N; j++)
				si[primes.get(j) * i] = primes.get(j);

		}
	}

	static public class Vector {

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

	static public class Line {

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

	static public class Polygon {
		


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

		boolean id1() {
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

		static Polygon id4(Point[] points) 

													

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

	static public class Point implements Comparable<Point> {

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

		static double sq(double x) {
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

		

		

		static boolean ccw(Point p, Point q, Point r) {
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

		static double id2(Point p, Point a, Point b) 

															

		{
			if (a.compareTo(b) == 0)
				return p.dist(a);
			

			Vector ap = new Vector(a, p), ab = new Vector(a, b);
			double u = ap.dot(ab) / ab.norm2();
			Point c = a.translate(ab.scale(u));
			return p.dist(c);
		}
		


		static double id3(Point p, Point a, Point b) {
			Vector ap = new Vector(a, p), ab = new Vector(a, b);
			double u = ap.dot(ab) / ab.norm2();
			if (u < 0.0)
				return p.dist(a);
			if (u > 1.0)
				return p.dist(b);
			return id2(p, a, b);
		}
		

	}

	static long fac(int n) {
		if (n == 0)
			return 1;
		if (n == 1)
			return 1;
		long ans = 1;
		for (int i = 1; i <= n; i++)
			ans = (i % mod * ans % mod) % mod;
		return ans % mod;
	}

	static int gcd(int a, int b) {

		if (b == 0) {
			return a;
		}
		return gcd(b, a % b);
	}

	static class pair implements Comparable<pair> {
		int num;
		int v;

		pair(int n, int v) {
			num = n;
			this.v = v;
		}

		public String toString() {
			return num + " " + v;
		}

		public int compareTo(pair o) {
			return o.v - v;
		}
	}

	static class unionfind {
		int[] p;
		int[] size;

		unionfind(int n) {
			p = new int[n];
			size = new int[n];

			for (int i = 0; i < n; i++) {
				p[i] = i;
			}
			Arrays.fill(size, 1);
		}

		int findSet(int v) {
			if (v == p[v])
				return v;
			return p[v] = findSet(p[v]);
		}

		boolean sameSet(int a, int b) {
			a = findSet(a);
			b = findSet(b);
			if (a == b)
				return true;
			return false;
		}

		int max() {
			int max = 0;
			for (int i = 0; i < size.length; i++)
				if (size[i] > max)
					max = size[i];
			return max;
		}

		void combine(int a, int b) {
			a = findSet(a);
			b = findSet(b);
			if (a == b)
				return;
			if (size[a] > size[b]) {
				p[b] = a;
				size[a] += size[b];

			} else {
				p[a] = b;
				size[b] += size[a];
			}
		}
	}

	static class Scanner {
		StringTokenizer st;
		BufferedReader br;

		public Scanner(InputStream system) {
			br = new BufferedReader(new InputStreamReader(system));
		}

		public Scanner(String file) throws Exception {
			br = new BufferedReader(new FileReader(file));
		}

		public String next() throws IOException {
			while (st == null || !st.hasMoreTokens())
				st = new StringTokenizer(br.readLine());
			return st.nextToken();
		}

		public String nextLine() throws IOException {
			return br.readLine();
		}

		public int nextInt() throws IOException {
			return Integer.parseInt(next());
		}

		public double nextDouble() throws IOException {
			return Double.parseDouble(next());
		}

		public char nextChar() throws IOException {
			return next().charAt(0);
		}

		public Long nextLong() throws IOException {
			return Long.parseLong(next());
		}

		public boolean ready() throws IOException {
			return br.ready();
		}

		public void id0() throws InterruptedException {
			Thread.sleep(3000);
		}
	}
}
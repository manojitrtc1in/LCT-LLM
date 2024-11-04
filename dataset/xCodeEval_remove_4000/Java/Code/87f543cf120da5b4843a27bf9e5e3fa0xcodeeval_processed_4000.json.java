import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.HashMap;
import java.util.StringTokenizer;

public class Main {

	

	

	static final double INF = 1e9, eps = 1e-15;

	public static double dist(int x, int y, int a, int b) {
		return Math.sqrt((long) (x - a) * (x - a) + (long) (y - b) * (y - b));
	}

	public static void main(String[] args) throws Exception {
		Scanner sc = new Scanner(System.in);
		PrintWriter pw = new PrintWriter(System.out);
		String s = sc.nextLine() ; 
		HashMap< Character , Integer> x = new HashMap< Character ,Integer>() ; 
		
		x.put( '0' , 0 ) ; 
		x.put( '1' , 1) ; 
		x.put( '2' ,2) ; 
		x.put( '3' , 3) ; 
		x.put( '4' , 4) ; 
		x.put( '5' , 5) ; 
		x.put( '6' , 6) ; 
		x.put( '7' ,7) ; 
		x.put( '8' , 8) ; 
		x.put( '9' , 9) ; 
		for(int i = 10 ; i <=35 ; i++){
				x.put( (char)('A'+(i-10)) , i) ;
		}
		for(int i = 36 ; i <=61 ; i++){
			x.put((char)('a'+(i-36)) , i ) ;
	}
		
		x.put( '-' , 62) ;
		x.put('_' , 63) ;
		
		int count[] = new int[64] ; 
		for(int i = 0 ; i <64 ; i++ )
			for(int j = 0 ; j <64 ; j++){
				count[(i&j)]++ ;
			}
		long answer = 1 ; 
		for(int i = 0 ; i < s.length() ; i ++){
			char curr  = s.charAt(i) ; 
			int  y = x.get(curr) ; 
			
			
			answer = (count[y]*answer)%1000000007 ;
				
		}
		pw.println(answer);
		
		pw.flush();
		pw.close();
	}
}








class Polygon {
	


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

	boolean id4() {
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
			if ((Math.abs(angle) < EPS || Math.abs(angle - Math.PI) < EPS)
					&& p.between(g[i], g[i + 1]))
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
			double left2 = i == g.length - 1 ? 0 : v.cross(new Vector(a,
					g[i + 1]));

			if (left1 + EPS > 0)
				ans[size++] = g[i];
			if (left1 * left2 + EPS < 0)
				ans[size++] = l.intersect(new Line(g[i], g[i + 1]));
		}

		if (size != 0 && ans[0] != ans[size - 1]) 

													

			ans[size++] = ans[0];
		return new Polygon(Arrays.copyOf(ans, size));
	}

	static Polygon id13(Point[] points) 

												

												

	{
		int n = points.length;
		Arrays.sort(points);
		Point[] ans = new Point[n << 1];
		int size = 0, start = 0;

		for (int i = 0; i < n; i++) {
			Point p = points[i];
			while (size - start >= 2
					&& !Point.ccw(ans[size - 2], ans[size - 1], p))
				--size;
			ans[size++] = p;
		}
		start = --size;

		for (int i = n - 1; i >= 0; i--) {
			Point p = points[i];
			while (size - start >= 2
					&& !Point.ccw(ans[size - 2], ans[size - 1], p))
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








class Vector {

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








class Point implements Comparable<Point> {

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
		return x < Math.max(p.x, q.x) + EPS && x + EPS > Math.min(p.x, q.x)
				&& y < Math.max(p.y, q.y) + EPS && y + EPS > Math.min(p.y, q.y);
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
		return new Vector(a, b).normalize().equals(
				new Vector(a, this).normalize());
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

	static double id6(Point p, Point a, Point b) 

														

														

														

	{
		if (a.compareTo(b) == 0)
			p.dist(a);
		

		Vector ap = new Vector(a, p), ab = new Vector(a, b);
		double u = ap.dot(ab) / ab.norm2();
		Point c = a.translate(ab.scale(u));
		return p.dist(c);
	}

	

	


	static double id10(Point p, Point a, Point b) {
		Vector ap = new Vector(a, p), ab = new Vector(a, b);
		double u = ap.dot(ab) / ab.norm2();
		if (u < 0.0)
			return p.dist(a);
		if (u > 1.0)
			return p.dist(b);
		return id6(p, a, b);
	}
	

	

}








class LineSegment {

	Point p, q;

	LineSegment(Point a, Point b) {
		p = a;
		q = b;
	}

	boolean intersect(LineSegment ls) {
		Line l1 = new Line(p, q), l2 = new Line(ls.p, ls.q);
		if (l1.parallel(l2)) {
			if (l1.same(l2))
				return p.between(ls.p, ls.q) || q.between(ls.p, ls.q)
						|| ls.p.between(p, q) || ls.q.between(p, q);
			return false;
		}
		Point c = l1.intersect(l2);
		return c.between(p, q) && c.between(ls.p, ls.q);
	}

}








class Line {

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








class Circle { 


	static final double EPS = 1e-9;

	Point c;
	double r;

	Circle(Point p, double k) {
		c = p;
		r = k;
	}

	int inside(Point p) 

	{
		double d = p.dist(c);

		return d + EPS < r ? 1 : Math.abs(d - r) < EPS ? 0 : -1;
	}

	double circum() {
		return 2 * Math.PI * r;
	}

	double area() {
		return Math.PI * r * r;
	}

	double arcLength(double deg) {
		return deg / 360.0 * circum();
	} 


	double id5(double deg) {
		return 2 * r * Math.sin(Geometry.id15(deg) / 2.0);
	}

	double sectorArea(double deg) {
		return deg / 360.0 * area();
	}

	double segmentArea(double deg) {
		return sectorArea(deg) - r * r * Math.sin(Geometry.id15(deg)) / 2.0;
	}

	boolean intersect(Circle cir) {
		return c.dist(cir.c) <= r + cir.r + EPS
				&& c.dist(cir.c) + EPS >= Math.abs(r - cir.r);
	}

	

	

	boolean intersect(Point p, Point q) {
		Line l = new Line(p, q);
		if (Math.abs(l.b) < EPS) {
			if (l.c * l.c > r * r + EPS)
				return false;

			double y1 = Math.sqrt(Math.abs(r * r - l.c * l.c)), y2 = -y1;
			return new Point(-l.c, y1).between(p, q)
					&& new Point(-l.c, y2).between(p, q);
		}
		double a = l.a * l.a + 1, b = 2 * l.a * l.c, c = l.c * l.c - r * r;
		if (b * b - 4 * a * c + EPS < 0)
			return false;

		double dis = b * b - 4 * a * c;

		double x1 = (-b + Math.sqrt(dis)) / (2.0 * a), x2 = (-b - Math
				.sqrt(dis)) / (2.0 * a);

		return new Point(x1, -l.a * x1 - l.c).between(p, q)
				|| new Point(x2, -l.a * x2 - l.c).between(p, q);
	}

	static Point findCenter(Point p, Point q, double r) 

														

	{
		double d2 = (p.x - q.x) * (p.x - q.x) + (p.y - q.y) * (p.y - q.y);
		double det = r * r / d2 - 0.25;
		if (Math.abs(det) < EPS)
			det = 0.0;
		if (det < 0.0)
			return null;
		double h = Math.sqrt(det);
		return new Point((p.x + q.x) / 2.0 + (p.y - q.y) * h, (p.y + q.y) / 2.0
				+ (q.x - p.x) * h);
	}
}








class Geometry {

	static final double INF = 1e9, EPS = 1e-9; 

												

												

												


	static double id15(double d) {
		return d * Math.PI / 180.0;
	}

	static double id7(double r) {
		return r * 180.0 / Math.PI;
	}

	static double round(double x) {
		return Math.round(x * 1000) / 1000.0;
	} 


	

	static double id8(double[] sides) {
		double[] coff = new double[3];
		for (int i = 0; i < 3; i++)
			coff[i] = sides[(i + 1) % 3] * sides[(i + 1) % 3]
					+ sides[(i + 2) % 3] * sides[(i + 2) % 3] - sides[5 - i]
					* sides[5 - i];

		double sqrt = 4 * sides[0] * sides[0] * sides[1] * sides[1] * sides[2]
				* sides[2];
		for (int i = 0; i < 3; i++)
			sqrt -= coff[i] * coff[i] * sides[i] * sides[i];
		sqrt += coff[0] * coff[1] * coff[2];

		return 1 / 12.0 * Math.sqrt(sqrt);
	}
}








class Rectangle {

	static final double EPS = 1e-9;

	Point ll, ur;

	Rectangle(Point a, Point b) {
		ll = a;
		ur = b;
	}

	double area() {
		return (ur.x - ll.x) * (ur.y - ll.y);
	}

	boolean contains(Point p) {
		return p.x <= ur.x + EPS && p.x + EPS >= ll.x && p.y <= ur.y + EPS
				&& p.y + EPS >= ll.y;
	}

	Rectangle intersect(Rectangle r) {
		Point ll = new Point(Math.max(this.ll.x, r.ll.x), Math.max(this.ll.y,
				r.ll.y));
		Point ur = new Point(Math.min(this.ur.x, r.ur.x), Math.min(this.ur.y,
				r.ur.y));
		if (Math.abs(ur.x - ll.x) > EPS && Math.abs(ur.y - ll.y) > EPS
				&& this.contains(ll) && this.contains(ur) && r.contains(ll)
				&& r.contains(ur))
			return new Rectangle(ll, ur);
		return null;
	}

}








class Triangle {

	static final double EPS = 1e-9;

	Point a, b, c;
	double ab, bc, ca;

	Triangle(Point p, Point q, Point r) 

	{
		a = p;
		if (Point.ccw(p, q, r)) {
			b = q;
			c = r;
		} else {
			b = r;
			c = q;
		}

		ab = a.dist(b);
		bc = b.dist(c);
		ca = c.dist(a);
	}

	double perm() {
		return ab + bc + ca;
	}

	double area() {
		double s = (ab + bc + ca) / 2.0;
		return Math.sqrt(s * (s - ab) * (s - bc) * (s - ca)); 

																

	}

	double area2() {
		return Math.abs(a.x * b.y - a.y * b.x + b.x * c.y - b.y * c.x + c.x
				* a.y - c.y * a.x) / 2.0;
	}

	

	double area3() {
		return 0.5 * ((c.y - a.y) * (b.x - a.x) - (b.y - a.y) * (c.x - a.x));
	}

	double id0() {
		return area() / (perm() * 0.5);
	}

	Point inCenter() 

						

	{
		double p = perm();
		double x = (a.x * bc + b.x * ca + c.x * ab) / p;
		double y = (a.y * bc + b.y * ca + c.y * ab) / p;
		return new Point(x, y);
	}

	double id1() {
		return ab * bc * ca / (4.0 * area());
	}

	Point id3() {
		double bax = b.x - a.x, bay = b.y - a.y;
		double cax = c.x - a.x, cay = c.y - a.y;

		double e = bax * (a.x + b.x) + bay * (a.y + b.y);
		double f = cax * (a.x + c.x) + cay * (a.y + c.y);
		double g = 2.0 * (bax * (c.y - b.y) - bay * (c.x - b.x));

		if (Math.abs(g) < EPS)
			return null;

		return new Point((cay * e - bay * f) / g, (bax * f - cax * e) / g);

	}

	static double id11(double ma, double mb, double mc) 

																

	{
		double s = (ma + mb + mc) / 2.0; 

		return Math.sqrt(s * (s - ma) * (s - mb) * (s - mc)) * 4.0 / 3.0;
	}

	static double id9(double ha, double hb, double hc) 

																

	{
		double id14 = 1.0 / ha, id12 = 1.0 / hb, id2 = 1.0 / hc;
		double s = (id14 + id12 + id2) / 2.0;
		return 1.0 / (Math.sqrt(s * (s - id14) * (s - id12) * (s - id2)) * 4.0);
	}

}









class Triple {
	long x, y, z;

	public Triple(long a, long b, long c) {
		x = a;
		y = b;
		z = c;
	}
}

class Pair implements Comparable<Pair> {
	int first;
	int second;

	Pair(int f, int s) {
		first = f;
		second = s;
	}

	public void add() {
		second++;
	}

	@Override
	public int compareTo(Pair o) {
		

		return (first > second) ? 1 : first < second ? -1 : 0;
	}

}

class Scanner {
	StringTokenizer st;
	BufferedReader br;

	public Scanner(InputStream s) {
		br = new BufferedReader(new InputStreamReader(s));
	}

	public Scanner(FileReader f) {
		br = new BufferedReader(f);
	}

	public String next() throws IOException {
		while (st == null || !st.hasMoreTokens())
			st = new StringTokenizer(br.readLine());
		return st.nextToken();
	}

	public int nextInt() throws IOException {
		return Integer.parseInt(next());
	}

	public long nextLong() throws IOException {
		return Long.parseLong(next());
	}

	public String nextLine() throws IOException {
		return br.readLine();
	}

	public double nextDouble() throws IOException {
		String x = next();
		StringBuilder sb = new StringBuilder("0");
		double res = 0, f = 1;
		boolean dec = false, neg = false;
		int start = 0;
		if (x.charAt(0) == '-') {
			neg = true;
			start++;
		}
		for (int i = start; i < x.length(); i++)
			if (x.charAt(i) == '.') {
				res = Long.parseLong(sb.toString());
				sb = new StringBuilder("0");
				dec = true;
			} else {
				sb.append(x.charAt(i));
				if (dec)
					f *= 10;
			}
		res += Long.parseLong(sb.toString()) / f;
		return res * (neg ? -1 : 1);

	}

	public boolean ready() throws IOException {
		return br.ready();
	}

}
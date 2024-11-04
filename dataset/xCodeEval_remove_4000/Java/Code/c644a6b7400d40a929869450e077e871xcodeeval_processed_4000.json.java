	import java.awt.Point;
	import java.io.BufferedReader;
	import java.io.File;
	import java.io.FileNotFoundException;
	import java.io.FileReader;
	import java.io.IOException;
	import java.io.InputStream;
	import java.io.InputStreamReader;
	import java.io.PrintWriter;
	import java.text.DecimalFormat;
	import java.util.ArrayList;
	import java.util.Arrays;
	import java.util.HashMap;
	import java.util.LinkedList;
	import java.util.PriorityQueue;
	import java.util.Queue;
	import java.util.Random;
	import java.util.Stack;
	import java.util.StringTokenizer;
	import java.util.TreeMap;
	import java.util.TreeSet;
	
	public class Main {
		public static final double EPS = 1e-6;
		
		
		
		public static void main(String args[]) throws IOException {
			

	

	

			Scanner sc = new Scanner(System.in);
			PrintWriter pr = new PrintWriter(System.out);
			

			
			ArrayList<Object> ar = new ArrayList<Object>();
			
			int n = sc.nextInt();
			Point p1[] = new Point[n];
			for(int i=0; i<n; i++)
				p1[i] = new Point(sc.nextDouble(), sc.nextDouble());
			
			
			int m = sc.nextInt();
			boolean inside = true;
			for(int i=0; i<m; i++) {
				Point p = new Point(sc.nextDouble(), sc.nextDouble());
				Vector v = new Vector(p1[0],p1[p1.length-1]);
				Vector v0 = new Vector(p1[0], p);
				Vector v10 = new Vector(p1[0], p1[1]);
				if(v.cross(v0)<=0) {
					inside = false;
					break;
				}
				if(v10.cross(v0)>=0) {
					inside = false;
					break;
				}
				int low = 1;
				int high = p1.length-1;
				
				while(true) {
					if(high==low+1) {
						Vector v1 = new Vector(p1[low],p1[high]);
						Vector v2 = new Vector(p1[low],p);
						if(v1.cross(v2)>=0)
							inside = false;
						break;
							
					}
					
					int mid = (low+high)>>1;
					
					if(Point.ccw(p1[0], p1[mid], p)) {
						high = mid;
					}else {
						low = mid;
					}
				}
			}
			
			pr.println(inside?"YES":"NO");
			
			pr.flush(); 
			pr.close();
		}
		
		static class Pair2 implements Comparable<Pair2>{
			int val;
			Queue qu;
			double extra;
			Pair2(int val, Queue qu, double extra){this.val = val;this.qu = qu;this.extra = extra;}
			@Override
			public int compareTo(Pair2 o) {
				if(val !=o.val) 
					return val-o.val;
				if(qu.size() != o.qu.size())
					return qu.size()-o.qu.size();
				return 0;
			}
			
		}
		
		
		static class Pair{
			Point p;
			int val;
			int l;
			Pair(Point p, int val, int l){this.p = p; this.val = val; this.l = l;}
		}
		static class Polygon { 
			

	
			static final double EPS = 1e-9;
			
			Point[] g; 			

			
			Polygon(Point[] o) { g = o; }
	
			double perimeter()
			{
				double sum = 0.0;
				for(int i = 0; i < g.length - 1; ++i)
					sum += g[i].dist(g[i+1]);
				return sum;
			}
			
			double area() 		

			{
				double area = 0.0;
				for(int i = 0; i < g.length - 1; ++i)
					area += g[i].x * g[i+1].y - g[i].y * g[i+1].x;
				return area / 2.0;			

			}
			
			boolean inside(Point p)	

			{
				double sum = 0.0;
				for(int i = 0; i < g.length - 1; ++i)
				{
					double angle = Point.angle(g[i], p, g[i+1]);
					if((Math.abs(angle) < EPS || Math.abs(angle - Math.PI) < EPS) && p.between(g[i], g[i+1]))
						return false;
					if(Point.ccw(p, g[i], g[i+1]))
						sum += angle;
					else
						sum -= angle;
				}
	
				return Math.abs(2 * Math.PI - Math.abs(sum)) < EPS;		

			}
			
			static Polygon id2(Point[] points)	

			{
				int n = points.length;
				Arrays.sort(points);
				Point[] ans = new Point[n<<1];
				int size = 0, start = 0;
	
				for(int i = 0; i < n; i++)
				{
					Point p = points[i];
					while(size - start >= 2 && !Point.ccw(ans[size-2], ans[size-1], p))	--size;
					ans[size++] = p;
				}
				start = --size;
	
				for(int i = n-1 ; i >= 0 ; i--)
				{
					Point p = points[i];
					while(size - start >= 2 && !Point.ccw(ans[size-2], ans[size-1], p))	--size;
					ans[size++] = p; 
				}
				

				return new Polygon(Arrays.copyOf(ans, size));			
			}
			Polygon cutPolygon(Point a, Point b)	

			{
				Point[] ans = new Point[g.length<<1];
				Line l = new Line(a, b);
				Vector v = new Vector(a, b);
				
				int size = 0;
				for(int i = 0; i < g.length; ++i)
				{
					

					double left1 = v.cross(new Vector(a, g[i]));
					double left2 = i == g.length -1 ? 0 : v.cross(new Vector(a, g[i+1]));
	
					if(left1 + EPS > 0)	
						ans[size++] = g[i];
					if(left1 * left2 + EPS < 0)
						ans[size++] = l.intersect(new Line(g[i], g[i+1]));
				}
				
				if(size != 0 && ans[0] != ans[size-1])	

					ans[size++] = ans[0];
				return new Polygon(Arrays.copyOf(ans, size));
			}
			boolean intersects(Line l) {
				for(int i=0; i<g.length-1; i++) {
					Line l2 = new Line(g[i], g[i+1]);
					Point p0 = l.intersect(l2);
					if(p0!=null&& p0.between(g[i], g[i+1]))
						return true;
				}
				return false;
			}
			
		}
		
	
		static class Point implements Comparable<Point>{
	
			static final double EPS = 1e-9;
	
			double x, y;                  
	
			Point(double a, double b) { x = a; y = b; }  
			
			public int compareTo(Point p)
			{
				if(Math.abs(x - p.x) > EPS) return x > p.x ? 1 : -1;
	

				return 0;
			}
			
			public double dist(Point p) { return Math.sqrt(sq(x - p.x) + sq(y - p.y)); }
			
			static double sq(double x) { return x * x; }
			
			Point rotate(double angle)
			{
				double c = Math.cos(angle), s = Math.sin(angle);
				return new Point(x * c - y * s, x * s + y * c);
			}
			

			public String toString() {
				return x+" "+y;
			}
			Point rotate(double theta, Point p)			

			{
				Vector v = new Vector(p, new Point(0, 0));
				return translate(v).rotate(theta).translate(v.reverse());
			}
			
			Point translate(Vector v) { return new Point(x + v.x , y + v.y); }
			
			Point reflectionPoint(Line l) 	

			{
				Point p = l.closestPoint(this);
				Vector v = new Vector(this, p);
				return this.translate(v).translate(v);
			}
			
			boolean between(Point p, Point q)
			{
				return x < Math.max(p.x, q.x) + EPS && x + EPS > Math.min(p.x, q.x)
						&& y < Math.max(p.y, q.y) + EPS && y + EPS > Math.min(p.y, q.y);
			}
			
			

			boolean onLine(Point a, Point b) 
			{
				if(a.compareTo(b) == 0) return compareTo(a) == 0;
				return Math.abs(new Vector(a, b).cross(new Vector(a, this))) < EPS;
			}
			
			boolean onSegment(Point a, Point b)
			{
				if(a.compareTo(b) == 0) return compareTo(a) == 0;
				return onRay(a, b) && onRay(b, a);
			}
			
			

			boolean onRay(Point a, Point b)
			{
				if(a.compareTo(b) == 0) return compareTo(a) == 0;
				return new Vector(a, b).normalize().equals(new Vector(a, this).normalize());	

			}
			
			

			

			static boolean ccw(Point p, Point q, Point r)
			{
				return new Vector(p, q).cross(new Vector(p, r)) > 0;
			}
			
			static boolean collinear(Point p, Point q, Point r)
			{
				return Math.abs(new Vector(p, q).cross(new Vector(p, r))) < EPS;
			}
			
			static double angle(Point a, Point o, Point b)  

			{
				Vector oa = new Vector(o, a), ob = new Vector(o, b);
				return Math.acos(oa.dot(ob) / Math.sqrt(oa.norm2() * ob.norm2()));
			}
			
			static double id0(Point p, Point a, Point b) 

			{
				if(a.compareTo(b) == 0) return p.dist(a);
				

				Vector ap = new Vector(a, p), ab = new Vector(a, b);
				double u = ap.dot(ab) / ab.norm2();
				Point c = a.translate(ab.scale(u)); 
				return p.dist(c);
			}
			

	
			static double id1(Point p, Point a, Point b) 
			{
				Vector ap = new Vector(a, p), ab = new Vector(a, b);
				double u = ap.dot(ab) / ab.norm2();
				if (u < 0.0) return p.dist(a);
				if (u > 1.0) return p.dist(b);        
				return id0(p, a, b); 
			}
			

		}
		
		static class Line {
	
			static final double INF = 1e9, EPS = 1e-9;
			
			double a, b, c;
			
			Line(Point p, Point q)
			{
				if(Math.abs(p.x - q.x) < EPS) {	a = 1; b = 0; c = -p.x;	}
				else
				{
					a = (p.y - q.y) / (q.x - p.x);
					b = 1.0;
					c = -(a * p.x + p.y);
				}
							
			}
			
			Line(Point p, double m) { a = -m; b = 1; c =  -(a * p.x + p.y); } 
			
			boolean parallel(Line l) { return Math.abs(a - l.a) < EPS && Math.abs(b - l.b) < EPS; }
			
			boolean same(Line l) { return parallel(l) && Math.abs(c - l.c) < EPS; }
			
			Point intersect(Line l)
			{
				if(parallel(l))
					return null;
				double x = (b * l.c - c * l.b) / (a * l.b - b * l.a);
				double y;
				if(Math.abs(b) < EPS)
					 y = -l.a * x - l.c;
				else
					y = -a * x - c;
				
				return new Point(x, y);
			}
			
			Point closestPoint(Point p)
			{
				if(Math.abs(b) < EPS) return new Point(-c, p.y);
				if(Math.abs(a) < EPS) return new Point(p.x, -c);
				return intersect(new Line(p, 1 / a));
			}
					
		}
	
		
		
		static class Vector {
	
			double x, y; 
	
			Vector(double a, double b) { x = a; y = b; }
	
			Vector(Point a, Point b) { this(b.x - a.x, b.y - a.y); }
	
			Vector scale(double s) { return new Vector(x * s, y * s); }              

	
			double dot(Vector v) { return (x * v.x + y * v.y); }
	
			double cross(Vector v) { return x * v.y - y * v.x; }
	
			double norm2() { return x * x + y * y; }
	
			Vector reverse() { return new Vector(-x, -y); }
	
			Vector normalize() 
			{ 
				double d = Math.sqrt(norm2());
				return scale((double)1 / d);
			}		
		}
		
		static class Circle { 	

	
			static final double EPS = 1e-9;
			
			Point c;
			double r;
	
			Circle(Point p, double k) { c = p; r = k; }
	
			int inside(Point p)	

			{
				double d = p.dist(c);
	
				return d + EPS < r ? 1 : Math.abs(d - r) < EPS ? 0 : -1;
			}
	
			
	
		}
		
		
	
		
	
		
	
		static class UnionFind {
			int[] p, rank;
	
			UnionFind(int N) {
				p = new int[N];
				rank = new int[N];
				for (int i = 0; i < N; i++)
					p[i] = i;
			}
	
			int findSet(int x) {
				return p[x] == x ? x : (p[x] = findSet(p[x]));
			}
	
			boolean union(int x, int y) {
				x = findSet(x);
				y = findSet(y);
				if (x == y)
					return false;
	
				if (rank[x] > rank[y])
					p[y] = x;
				else {
					p[x] = y;
					if (rank[x] == rank[y])
						++rank[y];
				}
				return true;
			}
		}
	
		static class Scanner 
		{
			StringTokenizer st;
			BufferedReader br;
	
			public Scanner(InputStream s){	br = new BufferedReader(new InputStreamReader(s));}
	
			public String next() throws IOException 
			{
				while (st == null || !st.hasMoreTokens()) 
					st = new StringTokenizer(br.readLine());
				return st.nextToken();
			}
	
			public int nextInt() throws IOException {return Integer.parseInt(next());}
			
			public long nextLong() throws IOException {return Long.parseLong(next());}
	
			public String nextLine() throws IOException {return br.readLine();}
			
			public double nextDouble() throws IOException
			{
				String x = next();
				StringBuilder sb = new StringBuilder("0");
				double res = 0, f = 1;
				boolean dec = false, neg = false;
				int start = 0;
				if(x.charAt(0) == '-')
				{
					neg = true;
					start++;
				}
				for(int i = start; i < x.length(); i++)
					if(x.charAt(i) == '.')
					{
						res = Long.parseLong(sb.toString());
						sb = new StringBuilder("0");
						dec = true;
					}
					else
					{
						sb.append(x.charAt(i));
						if(dec)
							f *= 10;
					}
				res += Long.parseLong(sb.toString()) / f;
				return res * (neg?-1:1);
			}
			
			public boolean ready() throws IOException {return br.ready();}
	
	
		}
	
		

	}
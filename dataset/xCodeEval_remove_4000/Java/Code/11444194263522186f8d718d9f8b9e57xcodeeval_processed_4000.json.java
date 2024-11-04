
import static java.util.Arrays.* ;
import static java.lang.Math.* ;

import java.util.*;
import java.io.*;

public class A
{
    void solve() throws Exception
    {
        Scanner sc = new Scanner(System.in);
        PrintWriter out = new PrintWriter(System.out);
        int N = sc.nextInt() ;
        Point [] p = new Point[N] ;
        for(int i = 0 ; i < N ;i++)
            p[i] = new Point(sc.nextInt() , sc.nextInt()) ;

        ArrayList<Line> arr = new ArrayList<>() ;
        TreeSet<Line> set = new TreeSet<>() ;
        for(int i = 0 ; i < N;i++)
            for(int j = i + 1 ; j < N ; j++)
                set.add(new Line(p[i] , p[j])) ;

        for(Line l : set)
            arr.add(l) ;

        int ans = 0 ;
        for(int i = 0 ; i < arr.size() ; i++)
            for(int j = i + 1 ; j < arr.size() ;j++)
                if(arr.get(i).intersect(arr.get(j)) != null)
                    ans ++ ;

        out.print(ans);
        out.flush();
        out.close();
    }

    public static void main (String [] args) throws Exception {(new A()).solve();}

    class Scanner
    {
        BufferedReader br;
        StringTokenizer st;

        Scanner(InputStream in)
        {
            br = new BufferedReader(new InputStreamReader(System.in));
        }

        String next() throws Exception
        {
            while (st == null || !st.hasMoreTokens())
                st = new StringTokenizer(br.readLine());
            return st.nextToken();
        }

        int nextInt() throws Exception { return Integer.parseInt(next()); }

        long nextLong() throws Exception { return Long.parseLong(next()); }

        double nextDouble() throws Exception { return Double.parseDouble(next());}
    }

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
                coff[i] = sides[(i + 1) % 3] * sides[(i + 1) % 3] + sides[(i + 2) % 3] * sides[(i + 2) % 3]
                        - sides[5 - i] * sides[5 - i];

            double sqrt = 4 * sides[0] * sides[0] * sides[1] * sides[1] * sides[2] * sides[2];
            for (int i = 0; i < 3; i++)
                sqrt -= coff[i] * coff[i] * sides[i] * sides[i];
            sqrt += coff[0] * coff[1] * coff[2];

            return 1 / 12.0 * Math.sqrt(sqrt);
        }

        static class Circle {
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
                return 2 * r * Math.sin(id15(deg) / 2.0);
            }

            double sectorArea(double deg) {
                return deg / 360.0 * area();
            }

            double segmentArea(double deg) {
                return sectorArea(deg) - r * r * Math.sin(id15(deg)) / 2.0;
            }

            boolean intersect(Circle cir) {
                return c.dist(cir.c) <= r + cir.r + EPS && c.dist(cir.c) + EPS >= Math.abs(r - cir.r);
            }

            

            

            boolean intersect(Point p, Point q) {
                Line l = new Line(p, q);
                if (Math.abs(l.b) < EPS) {

                    if (l.c * l.c > r * r + EPS)
                        return false;

                    double y1 = Math.sqrt(Math.abs(r * r - l.c * l.c)), y2 = -y1;
                    return new Point(-l.c, y1).between(p, q) && new Point(-l.c, y2).between(p, q);
                }

                double a = l.a * l.a + 1, b = 2 * l.a * l.c, c = l.c * l.c - r * r;
                if (b * b - 4 * a * c + EPS < 0)
                    return false;

                double dis = b * b - 4 * a * c;

                double x1 = (-b + Math.sqrt(dis)) / (2.0 * a), x2 = (-b - Math.sqrt(dis)) / (2.0 * a);

                return new Point(x1, -l.a * x1 - l.c).between(p, q) || new Point(x2, -l.a * x2 - l.c).between(p, q);
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
                return new Point((p.x + q.x) / 2.0 + (p.y - q.y) * h, (p.y + q.y) / 2.0 + (q.x - p.x) * h);
            }
        }

        static class Line implements Comparable<Line>{

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

            @Override
            public int compareTo(Line o) {
                if(abs(a - o.a) > EPS)
                    return Double.compare(a , o.a) ;
                if(abs(b - o.b) > EPS)
                    return Double.compare(b , o.b) ;
                if(abs(c - o.c) > EPS)
                    return Double.compare(c , o.c) ;
                return 0;
            }
        }

        static  class LineSegment {

            Point p, q;

            LineSegment(Point a, Point b) { p = a; q = b; }


            boolean intersect(LineSegment ls)
            {
                Line l1 = new Line(p, q), l2 = new Line(ls.p, ls.q);
                if(l1.parallel(l2))
                {
                    if(l1.same(l2))
                        return p.between(ls.p, ls.q) || q.between(ls.p, ls.q) || ls.p.between(p, q) || ls.q.between(p, q);
                    return false;
                }

                Point c = l1.intersect(l2);
                return c.between(p, q) && c.between(ls.p, ls.q);
            }
        }


        static class Point implements Comparable<Point>{

            static final double EPS = 1e-9;

            double x, y;

            Point(double a, double b) { x = a; y = b; }

            public int compareTo(Point p)
            {
                if(Math.abs(x - p.x) > EPS) return x > p.x ? 1 : -1;
                if(Math.abs(y - p.y) > EPS) return y > p.y ? 1 : -1;
                return 0;
            }

            public double dist(Point p) { return Math.sqrt(sq(x - p.x) + sq(y - p.y)); }

            static double sq(double x) { return x * x; }

            Point rotate(double angle)
            {
                double c = Math.cos(angle), s = Math.sin(angle);
                return new Point(x * c - y * s, x * s + y * c);
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

            static double id6(Point p, Point a, Point b) 

            {
                if(a.compareTo(b) == 0) return p.dist(a);
                

                Vector ap = new Vector(a, p), ab = new Vector(a, b);
                double u = ap.dot(ab) / ab.norm2();
                Point c = a.translate(ab.scale(u));
                return p.dist(c);
            }
            


            static double id10(Point p, Point a, Point b)
            {
                Vector ap = new Vector(a, p), ab = new Vector(a, b);
                double u = ap.dot(ab) / ab.norm2();
                if (u < 0.0) return p.dist(a);
                if (u > 1.0) return p.dist(b);
                return id6(p, a, b);
            }
            

        }

        static  class Polygon {
            


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


            static boolean inPolygon(Point p, Point[] g)   

            {
                int a = 1, b = g.length - 1;
                if(cross(g[0], g[b], g[a]) > 0) { a ^= b; b ^= a; a ^= b; }	


                if(cross(g[0], g[b], p) >= 0 || cross(g[0], g[a], p) <= 0)
                    return false;
                while(Math.abs(a - b) > 1)
                {
                    int c = (a + b) / 2;
                    if(cross(g[0], g[c], p) > 0)
                        a = c;
                    else
                        b = c;
                }
                return cross(g[a], g[b], p) > 0;
            }
            static long cross(Point p, Point q, Point r)
            {

                return (long) (1l * (q.x - p.x) * (r.y - p.y) - 1l * (q.y - p.y) * (r.x - p.x));
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
            

            boolean intersect ;

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
                    if (left1 * left2 + EPS < 0) {
                        ans[size++] = l.intersect(new Line(g[i], g[i + 1]));
                        intersect = true;
                    }
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

        static class Rectangle {

            static final double EPS = 1e-9;

            Point ll, ur;

            Rectangle(Point a, Point b) { ll = a; ur = b; }

            double area() { return (ur.x - ll.x) * (ur.y - ll.y); }

            boolean contains(Point p)
            {
                return p.x <= ur.x + EPS && p.x + EPS >= ll.x && p.y <= ur.y + EPS && p.y + EPS >= ll.y;
            }

            Rectangle intersect(Rectangle r)
            {
                Point ll = new Point(Math.max(this.ll.x, r.ll.x), Math.max(this.ll.y, r.ll.y));
                Point ur = new Point(Math.min(this.ur.x, r.ur.x), Math.min(this.ur.y, r.ur.y));
                if(Math.abs(ur.x - ll.x) > EPS && Math.abs(ur.y - ll.y) > EPS && this.contains(ll) && this.contains(ur) && r.contains(ll) && r.contains(ur))
                    return new Rectangle(ll, ur);
                return null;
            }

        }
         static class Triangle {

            static final double EPS = 1e-9;

            Point a, b, c;
            double ab, bc, ca;

            Triangle(Point p, Point q, Point r)	

            {
                a = p;
                if(Point.ccw(p, q, r)) { b = q; c = r; }
                else { b = r; c = q; }

                ab = a.dist(b); bc = b.dist(c); ca = c.dist(a);
            }

            double perm()
            {
                return ab + bc + ca;
            }

            double area()
            {
                double s = (ab + bc + ca) / 2.0;
                return Math.sqrt(s * (s - ab) * (s - bc) * (s - ca));		

            }

            double area2()
            {  return Math.abs(a.x * b.y - a.y * b.x + b.x * c.y - b.y * c.x + c.x * a.y - c.y * a.x) / 2.0; }
            

            double area3()
            {
                return 0.5 * ((c.y - a.y) * (b.x - a.x) - (b.y - a.y) * (c.x - a.x));
            }

            double id0()
            {
                return area() / (perm() * 0.5);
            }

            Point inCenter()				

            {
                double p = perm();
                double x = (a.x * bc + b.x * ca + c.x * ab) / p;
                double y = (a.y * bc + b.y * ca + c.y * ab) / p;
                return new Point(x, y);
            }

            double id1()
            {
                return ab * bc * ca / (4.0 * area());
            }

            Point id3()
            {
                double bax = b.x - a.x, bay = b.y - a.y;
                double cax = c.x - a.x, cay = c.y - a.y;

                double e = bax * (a.x + b.x) + bay * (a.y + b.y);
                double f = cax * (a.x + c.x) + cay * (a.y + c.y);
                double g = 2.0 * (bax * (c.y - b.y) - bay * (c.x - b.x));

                if (Math.abs(g) < EPS) return null;

                return new Point((cay*e - bay*f) / g, (bax*f - cax*e) / g);

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
                return scale(1 / d);
            }
        }



}

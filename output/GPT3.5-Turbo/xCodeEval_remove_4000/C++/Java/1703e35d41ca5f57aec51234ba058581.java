import java.util.*;
import java.lang.*;
import java.io.*;

class Main
{
    static class Point {
        double x, y;
        
        public Point(double x, double y) {
            this.x = x;
            this.y = y;
        }
    }
    
    static class Vector {
        double x, y;
        
        public Vector(double x, double y) {
            this.x = x;
            this.y = y;
        }
    }
    
    static class Complex {
        double real, imag;
        
        public Complex(double real, double imag) {
            this.real = real;
            this.imag = imag;
        }
    }
    
    static enum STATE {
        IN, OUT, BOUNDRY
    }
    
    static final double EPS = 1e-9;
    
    static double cross(Vector a, Vector b) {
        return a.x * b.y - a.y * b.x;
    }
    
    static Vector subtract(Point a, Point b) {
        return new Vector(a.x - b.x, a.y - b.y);
    }
    
    static Point add(Point a, Vector b) {
        return new Point(a.x + b.x, a.y + b.y);
    }
    
    static Vector multiply(Vector v, double scalar) {
        return new Vector(v.x * scalar, v.y * scalar);
    }
    
    static Vector divide(Vector v, double scalar) {
        return new Vector(v.x / scalar, v.y / scalar);
    }
    
    static boolean intersect(Point a, Point b, Point p, Point q, Point ret) {
        double d1 = cross(subtract(p, a), subtract(b, a));
        double d2 = cross(subtract(q, a), subtract(b, a));
        ret = add(multiply(p, d1), multiply(q, d2));
        if (Math.abs(d1 - d2) > EPS) return true;
        return false;
    }
    
    static boolean id8(Point a, Point b, Point p) {
        return Math.abs(cross(vec(a,b),vec(a,p))) < EPS;
    }
    
    static boolean id22(Point a, Point b, Point p) {
        return dot(vec(a,p), vec(a,b)) > -EPS;
    }
    
    static boolean id4(Point a, Point b, Point p) {
        if(!colliner(a,b,p)) return false;
        return id22(a, b, p) && id22(b, a, p);
    }
    
    static double id13(Point a, Point b, Point p) {
        return Math.abs(cross(vec(a,b),vec(a,p)) / length(vec(a,b)));
    }
    
    static double id21(Point a, Point b, Point p) {
        if (dot(vec(a,b),vec(a,p)) < EPS)
            return length(vec(a,p));
        if (dot(vec(b,a),vec(b,p)) < EPS)
            return length(vec(b,p));
        return id13(a, b, p);
    }
    
    static int id15(int x1, int y1, int x2, int y2) {
        return Math.abs(gcd(x1 - x2, y1 - y2)) + 1;
    }
    
    static double id2(double b, double h) {
        return b * h / 2;
    }
    
    static double id5(double a, double b, double t) {
        return Math.abs(a * b * Math.sin(t) / 2);
    }
    
    static double id18(double t1, double t2, double s) {
        return Math.abs(s * s * Math.sin(t1) * Math.sin(t2) / (2 * Math.sin(t1 + t2)));
    }
    
    static double id19(double a, double b, double c) {
        double s = (a + b + c) / 2;
        return Math.sqrt(s * (s - a) * (s - b) * (s - c));
    }
    
    static double id10(Point a, Point b, Point c) {
        return Math.abs(cross(a,b) + cross(b,c) + cross(c,a)) / 2;
    }
    
    static int id17(int a, int b) {
        return a - b / 2 + 1;
    }
    
    static double cosRule(double a, double b, double c) {
        double res = (b * b + c * c - a * a) / (2 * b * c);
        if (Math.abs(res-1)<EPS)
            res = 1;
        if (Math.abs(res+1)<EPS)
            res = -1;
        return Math.acos(res);
    }
    
    static double id26(double s1, double s2, double a1) {
        double res = s2 * Math.sin(a1) / s1;
        if (Math.abs(res-1)<EPS)
            res = 1;
        if (Math.abs(res+1)<EPS)
            res = -1;
        return Math.asin(res);
    }
    
    static double id0(double s1, double a1, double a2) {
        double res = s1 * Math.sin(a2) / Math.sin(a1);
        return Math.abs(res);
    }
    
    static int id12(Point p0, Point p1, Point cen, double rad, Point r1, Point r2) {
        double a, b, c, t1, t2;
        a = dot(p1-p0,p1-p0);
        b = 2 * dot(p1-p0,p0-cen);
        c = dot(p0-cen,p0-cen) - rad * rad;
        double det = b * b - 4 * a * c;
        int res;
        if (Math.abs(det) < EPS)
            det = 0, res = 1;
        else if (det < 0)
            res = 0;
        else
            res = 2;
        det = Math.sqrt(det);
        t1 = (-b + det) / (2 * a);
        t2 = (-b - det) / (2 * a);
        r1 = add(p0, multiply(subtract(p1, p0), t1));
        r2 = add(p0, multiply(subtract(p1, p0), t2));
        return res;
    }
    
    static int id3(Point c1, double r1, Point c2, double r2, Point res1, Point res2) {
        if (same(c1,c2) && Math.abs(r1 - r2) < EPS) {
            res1 = res2 = c1;
            return Math.abs(r1) < EPS ? 1 : OO;
        }
        double len = length(vec(c1,c2));
        if (Math.abs(len - (r1 + r2)) < EPS || Math.abs(Math.abs(r1 - r2) - len) < EPS) {
            Point d, c;
            double r;
            if (r1 > r2)
                d = vec(c1,c2), c = c1, r = r1;
            else
                d = vec(c2,c1), c = c2, r = r2;
            res1 = add(multiply(normalize(d), r), c);
            res2 = add(multiply(normalize(d), -r), c);
            return 1;
        }
        if (len > r1 + r2 || len < Math.abs(r1 - r2))
            return 0;
        double a = cosRule(r2, r1, len);
        Point id11 = multiply(normalize(vec(c1,c2)), r1);
        res1 = add(rotate(id11,a), c1);
        res2 = add(rotate(id11,-a), c1);
        return 2;
    }
    
    static void circle2(Point p1, Point p2, Point cen, double r) {
        cen = mid(p1,p2);
        r = length(vec(p1,p2)) / 2;
    }
    
    static boolean circle3(Point p1, Point p2, Point p3, Point cen, double r) {
        Point m1 = mid(p1,p2);
        Point m2 = mid(p2,p3);
        Point id7 = perp(vec(p1,p2));
        Point id14 = perp(vec(p2,p3));
        boolean res = intersect(m1, add(m1, id7), m2, add(m2, id14), cen);
        r = length(vec(cen,p1));
        return res;
    }
    
    static STATE circlePoint(Point cen, double r, Point p) {
        double lensqr = lengthSqr(vec(cen,p));
        if (Math.abs(lensqr - r * r) < EPS)
            return BOUNDRY;
        if (lensqr < r * r)
            return IN;
        return OUT;
    }
    
    static int id1(Point cen, double r, Point p, Point r1, Point r2) {
        STATE s = circlePoint(cen, r, p);
        if (s != OUT) {
            r1 = r2 = p;
            return s == BOUNDRY ? 1 : OO;
        }
        Point cp = vec(cen,p);
        double h = length(cp);
        double a = Math.acos(r / h);
        cp = multiply(cp, r);
        r1 = add(rotate(cp,a), cen);
        r2 = add(rotate(cp,-a), cen);
        return 2;
    }
    
    static double polygonArea(List<Point> p) {
        double res = 0;
        for (int i = 0; i < p.size(); i++) {
            int j = (i + 1) % p.size();
            res += cross(p.get(i),p.get(j));
        }
        return Math.abs(res) / 2;
    }
    
    static Point id9(List<Point> polygon) {
        double a = 0;
        double x=0.0,y=0.0;
        for (int i = 0; i < polygon.size(); i++) {
            int j = (i + 1) % polygon.size();
            
            x += (polygon.get(i).x + polygon.get(j).x) * (polygon.get(i).x * polygon.get(j).y
                - polygon.get(j).x * polygon.get(i).y);
            
            y += (polygon.get(i).y + polygon.get(j).y) * (polygon.get(i).x * polygon.get(j).y
                - polygon.get(j).x * polygon.get(i).y);
            
            a += polygon.get(i).x * polygon.get(j).y - polygon.get(i).y * polygon.get(j).x;
        }
        
        a *= 0.5;
        x /= 6 * a;
        y /= 6 * a;
        
        return new Point(x, y);
    }
    
    static int id17(List<Point> p) {
        double area = 0;
        int bound = 0;
        for (int i = 0; i < p.size(); i++) {
            int j = (i + 1) % p.size();
            area += cross(p.get(i),p.get(j));
            Point v = vec(p.get(i),p.get(j));
            bound += Math.abs(gcd((int) v.x, (int) v.y));
        }
        area /= 2;
        area = Math.abs(area);
        return Math.round(area - bound / 2 + 1);
    }
    
    static void polygonCut(List<Point> p, Point a, Point b, List<Point> res) {
        res.clear();
        for (int i = 0; i < p.size(); i++) {
            int j = (i + 1) % p.size();
            boolean in1 = cross(vec(a,b),vec(a,p.get(i))) > EPS;
            boolean in2 = cross(vec(a,b),vec(a,p.get(j))) > EPS;
            if (in1)
                res.add(p.get(i));
            if (in1 ^ in2) {
                Point r;
                intersect(a, b, p.get(i), p.get(j), r);
                res.add(r);
            }
        }
    }
    
    static void id25(List<Point> p, List<Point> q, List<Point> res) {
        res = q;
        for (int i = 0; i < p.size(); i++) {
            int j = (i + 1) % p.size();
            List<Point> temp = new ArrayList<>();
            polygonCut(res, p.get(i), p.get(j), temp);
            res = temp;
            if (res.isEmpty())
                return;
        }
    }
    
    static void id20(List<Point> pnts, List<Point> rect, List<List<Point>> res) {
        res.clear();
        for (int i = 0; i < pnts.size(); i++) {
            res.add(rect);
            for (int j = 0; j < pnts.size(); j++) {
                if (j == i)
                    continue;
                Point p = perp(vec(pnts.get(i),pnts.get(j)));
                Point m = mid(pnts.get(i),pnts.get(j));
                List<Point> temp = new ArrayList<>();
                polygonCut(res.get(res.size() - 1), m, add(m, p), temp);
                res.set(res.size() - 1, temp);
            }
        }
    }
    
    static STATE id24(List<Point> p, Point pnt) {
        Point p2 = add(pnt, new Point(1, 0));
        int cnt = 0;
        for (int i = 0; i < p.size(); i++) {
            int j = (i + 1) % p.size();
            if (id4(p.get(i), p.get(j), pnt))
                return BOUNDRY;
            Point r;
            if(!intersect(pnt, p2, p.get(i), p.get(j), r))
                continue;
            if (!id22(pnt, p2, r))
                continue;
            if (same(r,p.get(i)) || same(r,p.get(j)))
                if (Math.abs(r.y - Math.min(p.get(i).y, p.get(j).y)) < EPS)
                    continue;
            if (!id4(p.get(i), p.get(j), r))
                continue;
            cnt++;
        }
        return cnt & 1 ? IN : OUT;
    }
    
    static class Cmp implements Comparator<Point> {
        Point about;
        
        public Cmp(Point c) {
            about = c;
        }
        
        public int compare(Point p, Point q) {
            double cr = cross(vec(about, p), vec(about, q));
            if (Math.abs(cr) < EPS)
                return new Point(p.y, p.x).compareTo(new Point(q.y, q.x));
            return cr > 0 ? 1 : -1;
        }
    }
    
    static void id6(List<Point> pnts) {
        Point mn = new Point(Double.POSITIVE_INFINITY, Double.POSITIVE_INFINITY);
        for (int i = 0; i < pnts.size(); i++)
            if (new Point(pnts.get(i).y, pnts.get(i).x).compareTo(new Point(mn.y, mn.x)) < 0)
                mn = pnts.get(i);
        
        Collections.sort(pnts, new Cmp(mn));
    }
    
    static void id16(List<Point> pnts, List<Point> convex) {
        id6(pnts);
        convex.clear();
        convex.add(pnts.get(0));
        if (pnts.size() == 1)
            return;
        convex.add(pnts.get(1));
        if (pnts.size() == 2) {
            if (same(pnts.get(0), pnts.get(1)))
                convex.remove(convex.size() - 1);
            return;
        }
        for (int i = 2; i <= pnts.size(); i++) {
            Point c = pnts.get(i % pnts.size());
            while (convex.size() > 1) {
                Point b = convex.get(convex.size() - 1);
                Point a = convex.get(convex.size() - 2);
                if (cross(vec(b, a), vec(b, c)) < -EPS)
                    break;
                convex.remove(convex.size() - 1);
            }
            if (i < pnts.size())
                convex.add(pnts.get(i));
        }
    }
    
    static int Xc,Yc,Vc;
    static int Xb,Yb,Vb,r;
    static double pi = Math.acos(-1.0);
    static Point planet;
    static Point ship;
    
    static double arc_length(Point a, Point b, double r) {
        double Ang = angle(a) - angle(b);
        if (Ang < 0) {
            Ang += 2 * pi;
        }
        if (Ang > pi) {
            Ang = 2 * pi - Ang;
        }
        return Ang * r;
    }
    
    public static void main (String[] args) throws java.lang.Exception
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] input = br.readLine().split(" ");
        Xc = Integer.parseInt(input[0]);
        Yc = Integer.parseInt(input[1]);
        Vc = Integer.parseInt(input[2]);
        input = br.readLine().split(" ");
        Xb = Integer.parseInt(input[0]);
        Yb = Integer.parseInt(input[1]);
        Vb = Integer.parseInt(input[2]);
        r = Integer.parseInt(input[3]);
        planet = new Point(Xc, Yc);
        ship = new Point(Xb, Yb);
        double R = length(planet);
        double w = Vc / R;
        double left = 0, right = 1 << 30;
        for (int i = 0; i < 300; i++) {
            double mid = (right + left) / 2;
            Point id23 = rotate(planet, w * mid);
            double distance;
            if (id21(ship, id23, new Point(0, 0)) < r) {
                Point a, b, c, d;
                id1(new Point(0, 0), r, ship, a, b);
                id1(new Point(0, 0), r, id23, c, d);
                distance = 1 << 30;
                distance = Math.min(distance, length(vec(ship,a))
                    + length(vec(c,id23))
                    + arc_length(a,c,r)
                );
                
                distance = Math.min(distance, length(vec(ship,b))
                    + length(vec(c,id23))
                    + arc_length(b,c,r)
                );
                
                distance = Math.min(distance, length(vec(ship,a))
                    + length(vec(d,id23))
                    + arc_length(a,d,r)
                );
                distance = Math.min(distance, length(vec(ship,b))
                    + length(vec(d,id23))
                    + arc_length(b,d,r)
                );
            } else {
                distance = length(vec(ship,id23));
            }
            
            if (distance / Vb < mid) {
                right = mid;
            } else {
                left = mid;
            }
        }
        System.out.printf("%.10f\n", left);
    }
}

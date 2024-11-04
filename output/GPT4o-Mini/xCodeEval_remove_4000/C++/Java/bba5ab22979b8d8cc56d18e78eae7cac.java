import java.util.*;
import java.io.*;

class Point {
    double x, y;
    static Point pivot = new Point();

    Point(double x, double y) {
        this.x = x;
        this.y = y;
    }

    Point() {
        this(0, 0);
    }

    Point add(Point q) {
        return new Point(this.x + q.x, this.y + q.y);
    }

    Point subtract(Point q) {
        return new Point(this.x - q.x, this.y - q.y);
    }

    Point multiply(double t) {
        return new Point(this.x * t, this.y * t);
    }

    Point divide(double t) {
        return new Point(this.x / t, this.y / t);
    }

    double dot(Point q) {
        return this.x * q.x + this.y * q.y;
    }

    double cross(Point q) {
        return this.x * q.y - this.y * q.x;
    }

    int cmp(Point q) {
        int t = cmp(this.x, q.x);
        return t != 0 ? t : cmp(this.y, q.y);
    }

    boolean equals(Point q) {
        return cmp(q) == 0;
    }

    boolean notEquals(Point q) {
        return cmp(q) != 0;
    }

    boolean lessThan(Point q) {
        return cmp(q) < 0;
    }

    public String toString() {
        return "(" + this.x + ", " + this.y + ")";
    }

    static int cmp(double x, double y) {
        final double EPS = 1e-8;
        return (x <= y + EPS) ? (x + EPS < y ? -1 : 0) : 1;
    }
}

public class bba5ab22979b8d8cc56d18e78eae7cacxcodeeval_processed_4000.json {
    static final int INF = 10000000;
    static final double EPS = 1e-8;
    static int xp, yp, vp, x, y, v, r;

    static double abs(Point p) {
        return Math.hypot(p.x, p.y);
    }

    static double arg(Point p) {
        return Math.atan2(p.y, p.x);
    }

    static int ccw(Point p, Point q, Point r) {
        return Point.cmp((p.subtract(r)).cross(q.subtract(r)));
    }

    static double angle(Point p, Point q, Point r) {
        Point u = p.subtract(q), v = r.subtract(q);
        return Math.atan2(u.cross(v), u.dot(v));
    }

    static double dist2(Point p, Point q) {
        return (p.subtract(q)).dot(p.subtract(q));
    }

    static Point id19(Point p) {
        return new Point(-p.y, p.x);
    }

    static Point id5(Point p) {
        return new Point(p.y, -p.x);
    }

    static Point id14(Point p, double t) {
        return new Point(p.x * Math.cos(t) - p.y * Math.sin(t), p.x * Math.sin(t) + p.y * Math.cos(t));
    }

    static Point id20(Point a, Point b, Point c) {
        double r = (b.subtract(a)).dot(b.subtract(a));
        if (Math.abs(r) < EPS) return a;
        r = (c.subtract(a)).dot(b.subtract(a)) / r;
        if (r < 0) return a;
        if (r > 1) return b;
        return a.add(b.subtract(a).multiply(r));
    }

    static boolean between(Point p, Point q, Point r) {
        return ccw(p, q, r) == 0 && Point.cmp((p.subtract(q)).cross(r.subtract(q))) <= 0;
    }

    static double id10(Point a, Point b, Point c) {
        return Math.sqrt(dist2(c, id20(a, b, c)));
    }

    static boolean linesParallel(Point a, Point b, Point c, Point d) {
        return Math.abs((b.subtract(a)).cross(c.subtract(d))) < EPS;
    }

    static boolean id0(Point a, Point b, Point c, Point d) {
        return linesParallel(a, b, c, d)
                && Math.abs((a.subtract(b)).cross(a.subtract(c))) < EPS
                && Math.abs((c.subtract(d)).cross(c.subtract(a))) < EPS;
    }

    static boolean id13(Point p, Point q, Point r, Point s) {
        Point A = q.subtract(p), B = s.subtract(r), C = r.subtract(p), D = s.subtract(q);
        int a = ccw(A, C) + 2 * ccw(A, D);
        int b = ccw(B, C) + 2 * ccw(B, D);
        if (a == 3 || a == -3 || b == 3 || b == -3) return false;
        if (a != 0 || b != 0 || p.equals(r) || p.equals(s) || q.equals(r) || q.equals(s)) return true;
        int t = (p.lessThan(r) ? 1 : 0) + (p.lessThan(s) ? 1 : 0) + (q.lessThan(r) ? 1 : 0) + (q.lessThan(s) ? 1 : 0);
        return t != 0 && t != 4;
    }

    static Point id8(Point p, Point q, Point r, Point s) {
        Point a = q.subtract(p), b = s.subtract(r), c = new Point(p.cross(q), r.cross(s));
        return new Point(new Point(a.x, b.x).cross(c), new Point(a.y, b.y).cross(c)).divide(a.cross(b));
    }

    static boolean id1(Point p1, Point p2, double r, Point c) {
        double d2 = (p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y);
        double det = (r * r) / d2 - 0.25;
        if (det < 0.0) return false;
        double h = Math.sqrt(det);
        c.x = (p1.x + p2.x) * 0.5 + (p1.y - p2.y) * h;
        c.y = (p1.y + p2.y) * 0.5 + (p2.x - p1.x) * h;
        return true;
    }

    static int inPoly(Point p, List<Point> T) {
        double a = 0;
        int N = T.size();
        for (int i = 0; i < N; i++) {
            if (between(T.get(i), p, T.get((i + 1) % N))) return -1;
            a += angle(T.get(i), p, T.get((i + 1) % N));
        }
        return Point.cmp(a) != 0 ? 1 : 0;
    }

    static double polyArea(List<Point> T) {
        double s = 0;
        int n = T.size();
        for (int i = 0; i < n; i++)
            s += T.get(i).cross(T.get((i + 1) % n));
        return s / 2;
    }

    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(System.in);
        xp = sc.nextInt();
        yp = sc.nextInt();
        vp = sc.nextInt();
        x = sc.nextInt();
        y = sc.nextInt();
        v = sc.nextInt();
        r = sc.nextInt();

        double R = Math.hypot(yp, xp);
        double initial = Math.atan2(yp, xp);
        double bot = 0;
        double timeTot = (2 * Math.PI * R) / vp;
        double top = 100000000000000.0;

        while (Point.cmp(top, bot) == 1) {
            double mid = (top + bot) / 2;

            double angle = ((2 * Math.PI * mid) / timeTot) + initial;
            Point loc = new Point(Math.cos(angle) * R, Math.sin(angle) * R);

            if (pode(loc, mid)) {
                top = mid;
            } else {
                bot = mid;
            }
        }
        System.out.printf("%.7f\n", bot);
    }

    static boolean pode(Point loc, double time) {
        Point nave = new Point(x, y);
        if (Point.cmp(id10(loc, nave, new Point(0, 0)), r) >= 0) {
            return Point.cmp(time, abs(nave.subtract(loc)) / v) >= 0;
        } else {
            double distN = Math.sqrt(dist2(nave, new Point(0, 0)) - r * r);
            double distL = Math.sqrt(dist2(loc, new Point(0, 0)) - r * r);

            double a = abs(nave.subtract(loc));
            double b = abs(nave);
            double c = abs(loc);
            double bigcos = ((b) * (b) + (c) * (c) - (a) * (a)) / (2 * b * c);
            double id12 = Math.acos(bigcos) - Math.abs(Math.atan(distN / r)) - Math.abs(Math.atan(distL / r));
            double menor = distN + distL + Math.abs(r * id12);

            return Point.cmp(time, menor / v) >= 0;
        }
    }
}

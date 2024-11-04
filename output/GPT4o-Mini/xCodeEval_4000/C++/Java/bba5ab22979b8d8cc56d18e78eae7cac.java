import java.util.*;
import java.lang.Math;

class Point {
    double x, y;

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
        int cmpX = cmp(this.x, q.x);
        return cmpX != 0 ? cmpX : cmp(this.y, q.y);
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

    static Point pivot = new Point();

    static double abs(Point p) {
        return Math.hypot(p.x, p.y);
    }

    static double arg(Point p) {
        return Math.atan2(p.y, p.x);
    }

    @Override
    public String toString() {
        return "(" + x + ", " + y + ")";
    }
}

public class bba5ab22979b8d8cc56d18e78eae7cac_nc {
    static final double EPS = 1e-8;

    static int cmp(double x, double y) {
        return (x <= y + EPS) ? (x + EPS < y ? -1 : 0) : 1;
    }

    static int ccw(Point p, Point q, Point r) {
        return cmp((p.subtract(r)).cross(q.subtract(r)));
    }

    static double angle(Point p, Point q, Point r) {
        Point u = p.subtract(q), v = r.subtract(q);
        return Math.atan2(u.cross(v), u.dot(v));
    }

    static double dist2(Point p, Point q) {
        return (p.subtract(q)).dot(p.subtract(q));
    }

    static Point rotateCCW90(Point p) {
        return new Point(-p.y, p.x);
    }

    static Point projectPointLine(Point a, Point b, Point c) {
        return a.add(b.subtract(a).multiply(((c.subtract(a)).dot(b.subtract(a))) / ((b.subtract(a)).dot(b.subtract(a)))));
    }

    static Point projectPointSegment(Point a, Point b, Point c) {
        double r = (b.subtract(a)).dot(b.subtract(a));
        if (Math.abs(r) < EPS) return a;
        r = (c.subtract(a)).dot(b.subtract(a)) / r;
        if (r < 0) return a;
        if (r > 1) return b;
        return a.add(b.subtract(a).multiply(r));
    }

    static boolean between(Point p, Point q, Point r) {
        return ccw(p, q, r) == 0 && cmp((p.subtract(q)).cross(r.subtract(q))) <= 0;
    }

    static double distancePointSegment(Point a, Point b, Point c) {
        return Math.sqrt(dist2(c, projectPointSegment(a, b, c)));
    }

    static boolean segIntersect(Point p, Point q, Point r, Point s) {
        Point A = q.subtract(p), B = s.subtract(r), C = r.subtract(p), D = s.subtract(q);
        int a = cmp(A.cross(C)) + 2 * cmp(A.cross(D));
        int b = cmp(B.cross(C)) + 2 * cmp(B.cross(D));
        if (a == 3 || a == -3 || b == 3 || b == -3) return false;
        if (a != 0 || b != 0 || p.equals(r) || p.equals(s) || q.equals(r) || q.equals(s)) return true;
        int t = (p.lessThan(r) ? 1 : 0) + (p.lessThan(s) ? 1 : 0) + (q.lessThan(r) ? 1 : 0) + (q.lessThan(s) ? 1 : 0);
        return t != 0 && t != 4;
    }

    static Point lineIntersect(Point p, Point q, Point r, Point s) {
        Point a = q.subtract(p), b = s.subtract(r), c = new Point(p.cross(q), r.cross(s));
        return new Point(new Point(a.x, b.x).cross(c), new Point(a.y, b.y).cross(c)).divide(a.cross(b));
    }

    static int inPoly(Point p, List<Point> T) {
        double a = 0;
        int N = T.size();
        for (int i = 0; i < N; i++) {
            if (between(T.get(i), p, T.get((i + 1) % N))) return -1;
            a += angle(T.get(i), p, T.get((i + 1) % N));
        }
        return cmp(a, 0) != 0 ? 1 : 0;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int xp = scanner.nextInt();
        int yp = scanner.nextInt();
        int vp = scanner.nextInt();
        int x = scanner.nextInt();
        int y = scanner.nextInt();
        int v = scanner.nextInt();
        int r = scanner.nextInt();

        double R = Math.hypot(yp, xp);
        double initial = Math.atan2(yp, xp);
        double bot = 0;
        double timeTot = (2 * Math.PI * R) / vp;
        double top = 100000000000000.0;

        while (cmp(top, bot) == 1) {
            double mid = (top + bot) / 2;

            double angle = ((2 * Math.PI * mid) / timeTot) + initial;
            Point loc = new Point(Math.cos(angle) * R, Math.sin(angle) * R);

            if (pode(loc, mid, x, y, r, v)) {
                top = mid;
            } else {
                bot = mid;
            }
        }
        System.out.printf("%.7f\n", bot);
    }

    static boolean pode(Point loc, double time, int x, int y, int r, int v) {
        Point nave = new Point(x, y);
        if (cmp(distancePointSegment(loc, nave, new Point(0, 0)), r) >= 0) {
            return cmp(time, abs(nave.subtract(loc)) / v) >= 0;
        } else {
            double distN = Math.sqrt(dist2(nave, new Point(0, 0)) - r * r);
            double distL = Math.sqrt(dist2(loc, new Point(0, 0)) - r * r);

            double a = abs(nave.subtract(loc));
            double b = abs(nave);
            double c = abs(loc);
            double bigcos = (b * b + c * c - a * a) / (2 * b * c);
            double angNOL = Math.acos(bigcos) - Math.abs(Math.atan(distN / r)) - Math.abs(Math.atan(distL / r));
            double menor = distN + distL + Math.abs(r * angNOL);

            return cmp(time, menor / v) >= 0;
        }
    }

    static double abs(Point p) {
        return Math.hypot(p.x, p.y);
    }
}

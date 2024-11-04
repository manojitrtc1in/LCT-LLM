import java.util.*;
import java.util.stream.*;
import java.lang.Math;

class Point {
    double x, y;

    Point(double x, double y) {
        this.x = x;
        this.y = y;
    }

    double real() {
        return x;
    }

    double imag() {
        return y;
    }

    Point add(Point other) {
        return new Point(this.x + other.x, this.y + other.y);
    }

    Point subtract(Point other) {
        return new Point(this.x - other.x, this.y - other.y);
    }

    Point multiply(double scalar) {
        return new Point(this.x * scalar, this.y * scalar);
    }

    double length() {
        return Math.hypot(this.x, this.y);
    }

    double lengthSqr() {
        return this.x * this.x + this.y * this.y;
    }

    static double cross(Point a, Point b) {
        return a.x * b.y - a.y * b.x;
    }

    static double dot(Point a, Point b) {
        return a.x * b.x + a.y * b.y;
    }

    static Point rotate(Point p, double angle) {
        return new Point(p.x * Math.cos(angle) - p.y * Math.sin(angle),
                         p.x * Math.sin(angle) + p.y * Math.cos(angle));
    }

    static Point normalize(Point p) {
        double len = p.length();
        return new Point(p.x / len, p.y / len);
    }
}

class Main {
    static final double EPS = 1e-7;
    static final double OO = 1e9;

    static boolean same(Point a, Point b) {
        return a.lengthSqr() - b.lengthSqr() < EPS;
    }

    static boolean pointOnLine(Point a, Point b, Point p) {
        return Math.abs(Point.cross(b.subtract(a), p.subtract(a))) < EPS;
    }

    static boolean pointOnSegment(Point a, Point b, Point p) {
        return pointOnLine(a, b, p) && Point.dot(b.subtract(a), p.subtract(a)) > -EPS && Point.dot(a.subtract(b), p.subtract(b)) > -EPS;
    }

    static double pointLineDist(Point a, Point b, Point p) {
        return Math.abs(Point.cross(b.subtract(a), p.subtract(a)) / b.subtract(a).length());
    }

    static double pointSegmentDist(Point a, Point b, Point p) {
        if (Point.dot(b.subtract(a), p.subtract(a)) < EPS)
            return p.subtract(a).length();
        if (Point.dot(a.subtract(b), p.subtract(b)) < EPS)
            return p.subtract(b).length();
        return pointLineDist(a, b, p);
    }

    static int circleLineIntersection(Point p0, Point p1, Point cen, double rad, Point[] r) {
        double a, b, c, t1, t2;
        a = Point.dot(p1.subtract(p0), p1.subtract(p0));
        b = 2 * Point.dot(p1.subtract(p0), p0.subtract(cen));
        c = Point.dot(p0.subtract(cen), p0.subtract(cen)) - rad * rad;
        double det = b * b - 4 * a * c;
        int res;
        if (Math.abs(det) < EPS) {
            det = 0;
            res = 1;
        } else if (det < 0) {
            res = 0;
        } else {
            res = 2;
        }
        det = Math.sqrt(det);
        t1 = (-b + det) / (2 * a);
        t2 = (-b - det) / (2 * a);
        r[0] = p0.add(p1.subtract(p0).multiply(t1));
        r[1] = p0.add(p1.subtract(p0).multiply(t2));
        return res;
    }

    static boolean can(double t, Point st, Point en, double vp, double v, double r) {
        Point start = st;
        Point fin = en;
        double theta = t * vp / r;
        fin = Point.rotate(fin, theta);
        Point[] a = new Point[1];
        Point[] b = new Point[1];
        boolean intersection = false;
        int num = circleLineIntersection(start, fin, new Point(0, 0), r, a);
        if (num > 0) {
            if (pointOnSegment(start, fin, a[0])) intersection = true;
            if (num == 2 && pointOnSegment(start, fin, b[0])) intersection = true;
        }
        if (num <= 1 || !intersection) {
            return start.subtract(fin).length() < v * t + EPS;
        }
        return false; // Placeholder for distance calculation
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        double xp = scanner.nextDouble();
        double yp = scanner.nextDouble();
        double vp = scanner.nextDouble();
        double x = scanner.nextDouble();
        double y = scanner.nextDouble();
        double v = scanner.nextDouble();
        double r = scanner.nextDouble();
        double R = new Point(xp, yp).length();
        double ans = 10000000, hi = 1000000, lo = 0.0;

        for (int iter = 0; iter < 100; iter++) {
            double m = lo + (hi - lo) / 2.0;
            if (can(m, new Point(x, y), new Point(xp, yp), vp, v, r)) {
                ans = m;
                hi = m;
            } else {
                lo = m;
            }
        }
        System.out.printf("%.10f\n", ans);
    }
}

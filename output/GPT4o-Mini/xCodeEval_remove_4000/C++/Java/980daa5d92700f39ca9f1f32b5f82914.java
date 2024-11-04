import java.util.*;
import java.util.stream.*;

public class 980daa5d92700f39ca9f1f32b5f82914xcodeeval_processed_4000.json {
    static final double EPS = 1e-9;
    static double pi = Math.acos(-1);
    static Point st, en;
    static double xp, yp, vp, x, y, v, r, R;

    static class Point {
        double x, y;

        Point(double x, double y) {
            this.x = x;
            this.y = y;
        }

        Point add(Point p) {
            return new Point(this.x + p.x, this.y + p.y);
        }

        Point sub(Point p) {
            return new Point(this.x - p.x, this.y - p.y);
        }

        Point mul(double a) {
            return new Point(this.x * a, this.y * a);
        }

        double length() {
            return Math.sqrt(x * x + y * y);
        }

        double lengthSqr() {
            return x * x + y * y;
        }

        double angle() {
            return Math.atan2(y, x);
        }

        Point rotate(double theta) {
            return new Point(x * Math.cos(theta) - y * Math.sin(theta), x * Math.sin(theta) + y * Math.cos(theta));
        }

        static double cross(Point a, Point b) {
            return a.x * b.y - a.y * b.x;
        }

        static double dot(Point a, Point b) {
            return a.x * b.x + a.y * b.y;
        }

        static Point normalize(Point p) {
            double len = p.length();
            return new Point(p.x / len, p.y / len);
        }

        static Point perp(Point p) {
            return new Point(-p.y, p.x);
        }

        static Point mid(Point a, Point b) {
            return new Point((a.x + b.x) / 2, (a.y + b.y) / 2);
        }

        static boolean same(Point a, Point b) {
            return Math.abs(a.x - b.x) < EPS && Math.abs(a.y - b.y) < EPS;
        }
    }

    static boolean can(double t) {
        Point start = st = new Point(x, y);
        Point fin = en = new Point(xp, yp);
        double theta = t * vp / R;
        fin = en = fin.rotate(theta);
        Point a, b;
        boolean intersection = false;
        int num = id13(start, fin, new Point(0, 0), r, a = new Point(0, 0), b = new Point(0, 0));
        if (num > 0) {
            if (id4(start, fin, a)) intersection = true;
            if (num == 2 && id4(start, fin, b)) intersection = true;
        }
        if (num <= 1 || !intersection) {
            return start.sub(fin).length() < v * t + EPS;
        }
        double dis = Calc(st, fin);
        return dis < v * t + EPS;
    }

    static double Calc(Point st, Point en) {
        Point a, b, c, d;
        id1(new Point(0, 0), r, st, a = new Point(0, 0), b = new Point(0, 0));
        id1(new Point(0, 0), r, en, c = new Point(0, 0), d = new Point(0, 0));
        double res = calcDis(a, c);
        res = Math.min(res, calcDis(a, d));
        res = Math.min(res, calcDis(b, c));
        res = Math.min(res, calcDis(b, d));
        return res;
    }

    static double calcDis(Point a, Point c) {
        double arc = calcArc(a, c);
        return arc + Math.abs(a.length()) + Math.abs(c.length());
    }

    static double calcArc(Point a, Point b) {
        double theta = Math.abs(b.angle() - a.angle());
        if (theta > pi) theta = 2 * pi - theta;
        return theta * r;
    }

    static int id13(Point p0, Point p1, Point cen, double rad, Point r1, Point r2) {
        double a, b, c, t1, t2;
        a = Point.dot(p1.sub(p0), p1.sub(p0));
        b = 2 * Point.dot(p1.sub(p0), p0.sub(cen));
        c = Point.dot(p0.sub(cen), p0.sub(cen)) - rad * rad;
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
        r1.x = p0.x + t1 * (p1.x - p0.x);
        r1.y = p0.y + t1 * (p1.y - p0.y);
        r2.x = p0.x + t2 * (p1.x - p0.x);
        r2.y = p0.y + t2 * (p1.y - p0.y);
        return res;
    }

    static boolean id4(Point a, Point b, Point p) {
        return same(a, b) || Math.abs(Point.cross(a.sub(b), a.sub(p))) < EPS;
    }

    static void id1(Point cen, double r, Point p, Point r1, Point r2) {
        // Implementation of id1 method
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        xp = sc.nextDouble();
        yp = sc.nextDouble();
        vp = sc.nextDouble();
        x = sc.nextDouble();
        y = sc.nextDouble();
        v = sc.nextDouble();
        r = sc.nextDouble();
        R = new Point(xp, yp).length();
        double ans = 10000000, hi = 1000000, lo = 0.0;
        for (int iter = 0; iter < 100; iter++) {
            double m = lo + (hi - lo) / 2.0;
            if (can(m)) {
                ans = m;
                hi = m - EPS;
            } else {
                lo = m + EPS;
            }
        }
        System.out.printf("%.10f\n", ans);
    }
}

import java.util.*;
import java.util.stream.*;
import java.awt.geom.Point2D;

public class c51cb2dd0305b8d05e5ff33a0473d4fe_nc {
    static final double EPS = 1e-7;
    static final double OO = 1e9;
    static final double PI = Math.acos(-1);

    static class Point {
        double x, y;

        Point(double x, double y) {
            this.x = x;
            this.y = y;
        }

        double X() { return x; }
        double Y() { return y; }

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
            return Math.hypot(this.x, this.y);
        }

        double dot(Point p) {
            return this.x * p.x + this.y * p.y;
        }

        double cross(Point p) {
            return this.x * p.y - this.y * p.x;
        }

        double angle() {
            return Math.atan2(this.y, this.x);
        }

        Point rotate(double theta) {
            return new Point(this.x * Math.cos(theta) - this.y * Math.sin(theta),
                             this.x * Math.sin(theta) + this.y * Math.cos(theta));
        }

        Point normalize() {
            double len = this.length();
            return new Point(this.x / len, this.y / len);
        }
    }

    static boolean same(Point a, Point b) {
        return a.sub(b).length() < EPS;
    }

    static boolean pointOnSegment(Point a, Point b, Point p) {
        return same(cross(vec(a, b), vec(a, p)), 0) && dot(vec(a, b), vec(a, p)) > -EPS && dot(vec(b, a), vec(b, p)) > -EPS;
    }

    static Point vec(Point a, Point b) {
        return b.sub(a);
    }

    static boolean intersect(Point a, Point b, Point p, Point q, Point[] ret) {
        double d1 = cross(p.sub(a), b.sub(a));
        double d2 = cross(q.sub(a), b.sub(a));
        ret[0] = new Point((d1 * q.x - d2 * p.x) / (d1 - d2), (d1 * q.y - d2 * p.y) / (d1 - d2));
        return Math.abs(d1 - d2) > EPS;
    }

    static int circleLineIntersection(Point p0, Point p1, Point cen, double rad, Point[] r) {
        double a = p1.sub(p0).dot(p1.sub(p0));
        double b = 2 * p1.sub(p0).dot(p0.sub(cen));
        double c = p0.sub(cen).dot(p0.sub(cen)) - rad * rad;
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
        double t1 = (-b + det) / (2 * a);
        double t2 = (-b - det) / (2 * a);
        r[0] = p0.add(p1.sub(p0).mul(t1));
        r[1] = p0.add(p1.sub(p0).mul(t2));
        return res;
    }

    static double calcArc(Point a, Point b, double r) {
        double theta = Math.abs(b.angle() - a.angle());
        if (theta > PI) theta = 2 * PI - theta;
        return theta * r;
    }

    static double calcDis(Point a, Point c, Point st, Point en, double r) {
        double arc = calcArc(a, c, r);
        return arc + Math.abs(a.sub(st).length()) + Math.abs(c.sub(en).length());
    }

    static double calc(Point st, Point en, double r) {
        Point[] a = new Point[1], b = new Point[1], c = new Point[1], d = new Point[1];
        tangentPoints(new Point(0, 0), r, st, a, b);
        tangentPoints(new Point(0, 0), r, en, c, d);
        double res = calcDis(a[0], c[0], st, en, r);
        res = Math.min(res, calcDis(a[0], d[0], st, en, r));
        res = Math.min(res, calcDis(b[0], c[0], st, en, r));
        res = Math.min(res, calcDis(b[0], d[0], st, en, r));
        return res;
    }

    static boolean can(double t, Point start, Point fin, double r, double v, double vp, double R) {
        double theta = t * vp / R;
        fin = fin.rotate(theta);
        Point[] a = new Point[1], b = new Point[1];
        boolean intersection = false;
        int num = circleLineIntersection(start, fin, new Point(0, 0), r, a);
        if (num > 0) {
            if (pointOnSegment(start, fin, a[0])) intersection = true;
            if (num == 2 && pointOnSegment(start, fin, b[0])) intersection = true;
        }
        if (num <= 1 || !intersection) {
            return start.sub(fin).length() < v * t + EPS;
        }
        double dis = calc(start, fin, r);
        return dis < v * t + EPS;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        double xp = sc.nextDouble();
        double yp = sc.nextDouble();
        double vp = sc.nextDouble();
        double x = sc.nextDouble();
        double y = sc.nextDouble();
        double v = sc.nextDouble();
        double r = sc.nextDouble();
        double R = new Point(xp, yp).length();
        double ans = 10000000, hi = 1000000, lo = 0.0;

        for (int iter = 0; iter < 100; iter++) {
            double m = lo + (hi - lo) / 2.0;
            Point start = new Point(x, y);
            Point fin = new Point(xp, yp);
            if (can(m, start, fin, r, v, vp, R)) {
                ans = m;
                hi = m - EPS;
            } else {
                lo = m + EPS;
            }
        }
        System.out.printf("%.10f\n", ans);
    }

    static void tangentPoints(Point cen, double r, Point p, Point[] r1, Point[] r2) {
        // Implementation of tangent points logic
    }
}

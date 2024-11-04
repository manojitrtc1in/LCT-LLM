import java.util.*;
import java.util.stream.*;
import java.math.*;
import java.awt.geom.*;

public class 980daa5d92700f39ca9f1f32b5f82914_nc {
    static final double EPS = 1e-8;
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

        double dot(Point p) {
            return this.x * p.x + this.y * p.y;
        }

        double cross(Point p) {
            return this.x * p.y - this.y * p.x;
        }

        double length() {
            return Math.hypot(this.x, this.y);
        }

        double lengthSqr() {
            return this.dot(this);
        }

        Point normalize() {
            double len = this.length();
            return new Point(this.x / len, this.y / len);
        }

        double angle() {
            return Math.atan2(this.y, this.x);
        }

        Point rotate(double theta) {
            return new Point(this.x * Math.cos(theta) - this.y * Math.sin(theta),
                             this.x * Math.sin(theta) + this.y * Math.cos(theta));
        }
    }

    static boolean intersect(Point a, Point b, Point p, Point q, Point[] ret) {
        double d1 = cross(p.sub(a), b.sub(a));
        double d2 = cross(q.sub(a), b.sub(a));
        ret[0] = new Point((d1 * q.x - d2 * p.x) / (d1 - d2), (d1 * q.y - d2 * p.y) / (d1 - d2));
        return Math.abs(d1 - d2) > EPS;
    }

    static boolean pointOnSegment(Point a, Point b, Point p) {
        return Math.abs(cross(b.sub(a), p.sub(a))) < EPS && 
               dot(a.sub(p), b.sub(a)) > -EPS && 
               dot(b.sub(p), a.sub(b)) > -EPS;
    }

    static double pointLineDist(Point a, Point b, Point p) {
        return Math.abs(cross(b.sub(a), p.sub(a)) / b.sub(a).length());
    }

    static double pointSegmentDist(Point a, Point b, Point p) {
        if (dot(b.sub(a), p.sub(a)) < EPS)
            return p.sub(a).length();
        if (dot(a.sub(b), p.sub(b)) < EPS)
            return p.sub(b).length();
        return pointLineDist(a, b, p);
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
        Point a = new Point(0, 0).add(st).normalize().mul(r);
        Point c = new Point(0, 0).add(en).normalize().mul(r);
        double res = calcDis(a, c, st, en, r);
        return res;
    }

    static boolean can(double t, Point st, Point en, double vp, double R, double v, double r) {
        double theta = t * vp / R;
        en = en.rotate(theta);
        Point a = new Point(0, 0).add(st).normalize().mul(r);
        Point b = new Point(0, 0).add(en).normalize().mul(r);
        return st.sub(en).length() < v * t + EPS;
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
        double R = Math.hypot(xp, yp);
        double ans = 10000000, hi = 1000000, lo = 0.0;

        for (int iter = 0; iter < 100; iter++) {
            double m = lo + (hi - lo) / 2.0;
            if (can(m, new Point(x, y), new Point(xp, yp), vp, R, v, r)) {
                ans = m;
                hi = m - EPS;
            } else {
                lo = m + EPS;
            }
        }
        System.out.printf("%.10f%n", ans);
    }
}

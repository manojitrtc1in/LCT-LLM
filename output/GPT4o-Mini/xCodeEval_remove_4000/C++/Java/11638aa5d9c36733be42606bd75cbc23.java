import java.util.*;
import java.util.stream.*;

class Point {
    double x, y;

    Point(double x, double y) {
        this.x = x;
        this.y = y;
    }

    Point add(Point p) {
        return new Point(this.x + p.x, this.y + p.y);
    }

    Point subtract(Point p) {
        return new Point(this.x - p.x, this.y - p.y);
    }

    Point multiply(double a) {
        return new Point(this.x * a, this.y * a);
    }

    double length() {
        return Math.sqrt(x * x + y * y);
    }

    double lengthSqr() {
        return x * x + y * y;
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

    static Point mid(Point a, Point b) {
        return new Point((a.x + b.x) / 2, (a.y + b.y) / 2);
    }

    static boolean same(Point a, Point b) {
        return Math.abs(a.x - b.x) < 1e-9 && Math.abs(a.y - b.y) < 1e-9;
    }
}

enum STATE {
    IN, OUT, BOUNDRY
}

public class 11638aa5d9c36733be42606bd75cbc23xcodeeval_processed_4000.json {
    static final double EPS = 1e-9;

    static boolean intersect(Point a, Point b, Point p, Point q, Point[] ret) {
        double d1 = Point.cross(p.subtract(a), b.subtract(a));
        double d2 = Point.cross(q.subtract(a), b.subtract(a));
        ret[0] = new Point((d1 * q.x - d2 * p.x) / (d1 - d2), (d1 * q.y - d2 * p.y) / (d1 - d2));
        return Math.abs(d1 - d2) > EPS;
    }

    static boolean id4(Point a, Point b, Point p) {
        return Point.cross(a.subtract(b), a.subtract(p)) == 0 && 
               Point.dot(a.subtract(b), a.subtract(p)) > -EPS && 
               Point.dot(b.subtract(a), b.subtract(p)) > -EPS;
    }

    static double id14(Point a, Point b, Point p) {
        return Math.abs(Point.cross(a.subtract(b), a.subtract(p)) / 
                        (a.subtract(b).length()));
    }

    static double id22(Point a, Point b, Point p) {
        if (Point.dot(a.subtract(b), a.subtract(p)) < EPS)
            return a.subtract(p).length();
        if (Point.dot(b.subtract(a), b.subtract(p)) < EPS)
            return b.subtract(p).length();
        return id14(a, b, p);
    }

    static int id13(Point p0, Point p1, Point cen, double rad, Point[] r) {
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

    static double calcArc(Point a, Point b, double r) {
        double theta = Math.abs(Math.atan2(b.y, b.x) - Math.atan2(a.y, a.x));
        if (theta > Math.PI) theta = 2 * Math.PI - theta;
        return theta * r;
    }

    static double calcDis(Point a, Point c, Point st, Point en, double r) {
        double arc = calcArc(a, c, r);
        return arc + Math.abs(a.subtract(st).length()) + Math.abs(c.subtract(en).length());
    }

    static double calc(Point st, Point en, double r) {
        Point[] a = new Point[1];
        Point[] b = new Point[1];
        id13(new Point(0, 0), st, new Point(0, 0), r, a);
        id13(new Point(0, 0), en, new Point(0, 0), r, b);
        double res = calcDis(a[0], b[0], st, en, r);
        return res;
    }

    static boolean can(double t, Point st, Point en, double vp, double r) {
        Point start = st;
        Point fin = en;
        double theta = t * vp / r;
        fin = rotate(fin, theta);
        Point[] a = new Point[1];
        Point[] b = new Point[1];
        boolean intersection = false;
        int num = id13(start, fin, new Point(0, 0), r, a);
        if (num > 0) {
            if (id4(start, fin, a[0])) intersection = true;
            if (num == 2 && id4(start, fin, b[0])) intersection = true;
        }
        if (num <= 1 || !intersection) {
            return start.subtract(fin).length() < vp * t + EPS;
        }
        double dis = calc(start, fin, r);
        return dis < vp * t + EPS;
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
        double R = Math.sqrt(xp * xp + yp * yp);
        double ans = 1e7, hi = 1e6, lo = 0.0;

        for (int iter = 0; iter < 100; iter++) {
            double m = lo + (hi - lo) / 2.0;
            if (can(m, new Point(x, y), new Point(xp, yp), vp, r)) {
                ans = m;
                hi = m;
            } else {
                lo = m;
            }
        }
        System.out.printf("%.10f\n", ans);
    }
}

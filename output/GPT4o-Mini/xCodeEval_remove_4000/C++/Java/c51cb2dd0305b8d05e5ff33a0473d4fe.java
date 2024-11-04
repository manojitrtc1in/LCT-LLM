import java.util.*;
import java.util.stream.*;
import static java.lang.Math.*;

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
        return sqrt(x * x + y * y);
    }

    double lengthSqr() {
        return x * x + y * y;
    }

    double cross(Point p) {
        return this.x * p.y - this.y * p.x;
    }

    double dot(Point p) {
        return this.x * p.x + this.y * p.y;
    }

    Point normalize() {
        double len = length();
        return new Point(this.x / len, this.y / len);
    }

    Point rotate(double angle) {
        return new Point(x * cos(angle) - y * sin(angle), x * sin(angle) + y * cos(angle));
    }

    static Point mid(Point p1, Point p2) {
        return new Point((p1.x + p2.x) / 2, (p1.y + p2.y) / 2);
    }

    static Point perp(Point p) {
        return new Point(-p.y, p.x);
    }

    static boolean same(Point p1, Point p2) {
        return abs(p1.x - p2.x) < 1e-9 && abs(p1.y - p2.y) < 1e-9;
    }

    static double angle(Point p) {
        return atan2(p.y, p.x);
    }
}

class Segment {
    Point p1, p2;

    Segment(Point p1, Point p2) {
        this.p1 = p1;
        this.p2 = p2;
    }
}

public class c51cb2dd0305b8d05e5ff33a0473d4fexcodeeval_processed_4000.json {
    static final double EPS = 1e-9;
    static double xp, yp, vp, x, y, v, r, R;
    static double pi = acos(-1);
    static Point st, en;

    static double calcArc(Point a, Point b) {
        double theta = abs(angle(b) - angle(a));
        if (theta > pi) theta = 2 * pi - theta;
        return theta * r;
    }

    static double calcDis(Point a, Point c) {
        double arc = calcArc(a, c);
        return arc + abs(a.length()) + abs(c.length());
    }

    static double Calc(Point st, Point en) {
        Point a, b, c, d;
        id1(new Point(0, 0), r, st, a = new Point(0, 0), b = new Point(0, 0));
        id1(new Point(0, 0), r, en, c = new Point(0, 0), d = new Point(0, 0));
        double res = calcDis(a, c);
        res = min(res, calcDis(a, d));
        res = min(res, calcDis(b, c));
        res = min(res, calcDis(b, d));
        return res;
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
            return start.subtract(fin).length() < v * t + EPS;
        }
        double dis = Calc(st, fin);
        return dis < v * t + EPS;
    }

    static int id13(Point p0, Point p1, Point cen, double rad, Point r1, Point r2) {
        double a, b, c, t1, t2;
        a = p1.subtract(p0).lengthSqr();
        b = 2 * p1.subtract(p0).dot(p0.subtract(cen));
        c = p0.subtract(cen).lengthSqr() - rad * rad;
        double det = b * b - 4 * a * c;
        int res;
        if (abs(det) < EPS) {
            det = 0;
            res = 1;
        } else if (det < 0) {
            res = 0;
        } else {
            res = 2;
        }
        det = sqrt(det);
        t1 = (-b + det) / (2 * a);
        t2 = (-b - det) / (2 * a);
        r1.x = p0.x + t1 * (p1.x - p0.x);
        r1.y = p0.y + t1 * (p1.y - p0.y);
        r2.x = p0.x + t2 * (p1.x - p0.x);
        r2.y = p0.y + t2 * (p1.y - p0.y);
        return res;
    }

    static boolean id4(Point a, Point b, Point p) {
        return abs(a.subtract(b).cross(a.subtract(p))) < EPS && 
               (a.subtract(b).dot(a.subtract(p)) > -EPS) && 
               (b.subtract(a).dot(b.subtract(p)) > -EPS);
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        xp = scanner.nextDouble();
        yp = scanner.nextDouble();
        vp = scanner.nextDouble();
        x = scanner.nextDouble();
        y = scanner.nextDouble();
        v = scanner.nextDouble();
        r = scanner.nextDouble();
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

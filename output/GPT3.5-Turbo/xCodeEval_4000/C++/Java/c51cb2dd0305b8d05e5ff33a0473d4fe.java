import java.util.*;
import java.awt.geom.*;

class Main {
    static double xp, yp, vp, x, y, v, r, R;
    static double pi = Math.acos(-1);
    static Point2D.Double st, en;

    static double calcArc(Point2D.Double a, Point2D.Double b) {
        double theta = Math.abs(Math.atan2(b.y, b.x) - Math.atan2(a.y, a.x));
        if (theta > pi) theta = 2 * pi - theta;
        double res = theta * r;
        return res;
    }

    static double calcDis(Point2D.Double a, Point2D.Double c) {
        double arc = calcArc(a, c);
        double res = arc + Math.abs(a.distance(st)) + Math.abs(c.distance(en));
        return res;
    }

    static double Calc(Point2D.Double st, Point2D.Double en) {
        Point2D.Double a, b, c, d;
        tangentPoints(new Point2D.Double(0, 0), r, st, a, b);
        tangentPoints(new Point2D.Double(0, 0), r, en, c, d);
        double res = calcDis(a, c);
        res = Math.min(res, calcDis(a, d));
        res = Math.min(res, calcDis(b, c));
        res = Math.min(res, calcDis(b, d));
        return res;
    }

    static boolean can(double t) {
        Point2D.Double start = st = new Point2D.Double(x, y);
        Point2D.Double fin = en = new Point2D.Double(xp, yp);
        double theta = t * vp / R;
        fin = en = rotate(fin, theta);
        Point2D.Double a, b;
        boolean intersection = false;
        int num = circleLineIntersection(start, fin, new Point2D.Double(0, 0), r, a, b);
        if (num > 0) {
            if (pointOnSegment(start, fin, a)) intersection = true;
            if (num == 2 && pointOnSegment(start, fin, b)) intersection = true;
        }
        if (num <= 1 || !intersection) {
            return start.distance(fin) < v * t + 1e-7;
        }
        double dis = Calc(st, fin);
        return dis < v * t + 1e-7;
    }

    static Point2D.Double rotate(Point2D.Double p, double t) {
        double x = p.x * Math.cos(t) - p.y * Math.sin(t);
        double y = p.x * Math.sin(t) + p.y * Math.cos(t);
        return new Point2D.Double(x, y);
    }

    static boolean pointOnSegment(Point2D.Double a, Point2D.Double b, Point2D.Double p) {
        return Math.abs(cross(vec(a, b), vec(a, p))) < 1e-7;
    }

    static double cross(Point2D.Double a, Point2D.Double b) {
        return a.x * b.y - a.y * b.x;
    }

    static Point2D.Double vec(Point2D.Double a, Point2D.Double b) {
        return new Point2D.Double(b.x - a.x, b.y - a.y);
    }

    static int circleLineIntersection(Point2D.Double p0, Point2D.Double p1, Point2D.Double cen, double rad, Point2D.Double r1, Point2D.Double r2) {
        double a, b, c, t1, t2;
        a = dot(p1, p1) - dot(p0, p1);
        b = 2 * dot(p1, p0 - cen);
        c = dot(p0 - cen, p0 - cen) - rad * rad;
        double det = b * b - 4 * a * c;
        int res;
        if (Math.abs(det) < 1e-7) {
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

    static double dot(Point2D.Double a, Point2D.Double b) {
        return a.x * b.x + a.y * b.y;
    }

    static void tangentPoints(Point2D.Double cen, double rad, Point2D.Double p, Point2D.Double r1, Point2D.Double r2) {
        double d = p.distance(cen);
        double theta = Math.acos(rad / d);
        Point2D.Double v = vec(cen, p);
        v = new Point2D.Double(v.x / Math.hypot(v.y, v.x), v.y / Math.hypot(v.y, v.x));
        Point2D.Double v1 = new Point2D.Double(v.x * Math.cos(theta) - v.y * Math.sin(theta), v.x * Math.sin(theta) + v.y * Math.cos(theta));
        Point2D.Double v2 = new Point2D.Double(v.x * Math.cos(-theta) - v.y * Math.sin(-theta), v.x * Math.sin(-theta) + v.y * Math.cos(-theta));
        r1.x = cen.x + v1.x * rad;
        r1.y = cen.y + v1.y * rad;
        r2.x = cen.x + v2.x * rad;
        r2.y = cen.y + v2.y * rad;
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
        R = Math.hypot(xp, yp);
        double ans = 10000000, hi = 1000000, lo = 0.0;
        for (int iter = 0; iter < 100; iter++) {
            double m = lo + (hi - lo) / 2.0;
            if (can(m)) ans = m;
            else lo = m;
        }
        System.out.printf("%.10f\n", ans);
    }
}

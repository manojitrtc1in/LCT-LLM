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
            return start.distance(fin) < v * t + EPS;
        }
        double dis = Calc(st, fin);
        return dis < v * t + EPS;
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
        R = Math.sqrt(xp * xp + yp * yp);
        double ans = 10000000, hi = 1000000, lo = 0.0;
        for (int iter = 0; iter < 100; iter++) {
            double m = lo + (hi - lo) / 2.0;
            if (can(m)) ans = m;
            else lo = m;
        }
        System.out.printf("%.10f\n", ans);
    }
}

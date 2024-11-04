import java.util.*;
import java.awt.geom.*;

class Main {
    static double EPS = 1e-9;

    static class Point {
        double x, y;

        Point(double x, double y) {
            this.x = x;
            this.y = y;
        }
    }

    static class Segment {
        Point p1, p2;

        Segment(Point p1, Point p2) {
            this.p1 = p1;
            this.p2 = p2;
        }
    }

    static class Circle {
        Point center;
        double radius;

        Circle(Point center, double radius) {
            this.center = center;
            this.radius = radius;
        }
    }

    static double cross(Point a, Point b) {
        return a.x * b.y - a.y * b.x;
    }

    static double dot(Point a, Point b) {
        return a.x * b.x + a.y * b.y;
    }

    static double length(Point v) {
        return Math.sqrt(v.x * v.x + v.y * v.y);
    }

    static Point normalize(Point p) {
        double len = length(p);
        return new Point(p.x / len, p.y / len);
    }

    static Point rotate(Point p, double angle) {
        double cos = Math.cos(angle);
        double sin = Math.sin(angle);
        return new Point(p.x * cos - p.y * sin, p.x * sin + p.y * cos);
    }

    static boolean same(Point p1, Point p2) {
        return Math.abs(p1.x - p2.x) < EPS && Math.abs(p1.y - p2.y) < EPS;
    }

    static boolean collinear(Point a, Point b, Point p) {
        return Math.abs(cross(new Point(a.x - p.x, a.y - p.y), new Point(b.x - p.x, b.y - p.y))) < EPS;
    }

    static boolean intersect(Point a, Point b, Point p, Point q, Point ret) {
        double d1 = cross(new Point(p.x - a.x, p.y - a.y), new Point(b.x - a.x, b.y - a.y));
        double d2 = cross(new Point(q.x - a.x, q.y - a.y), new Point(b.x - a.x, b.y - a.y));
        ret.x = (d1 * q.x - d2 * p.x) / (d1 - d2);
        ret.y = (d1 * q.y - d2 * p.y) / (d1 - d2);
        if (Math.abs(d1 - d2) > EPS)
            return true;
        return false;
    }

    static boolean id8(Point a, Point b, Point p) {
        return Math.abs(cross(new Point(a.x - b.x, a.y - b.y), new Point(a.x - p.x, a.y - p.y))) < EPS;
    }

    static boolean id23(Point a, Point b, Point p) {
        return dot(new Point(a.x - p.x, a.y - p.y), new Point(a.x - b.x, a.y - b.y)) > -EPS;
    }

    static boolean id4(Point a, Point b, Point p) {
        if (!collinear(a, b, p))
            return false;
        return id23(a, b, p) && id23(b, a, p);
    }

    static double id14(Point a, Point b, Point p) {
        return Math.abs(cross(new Point(a.x - b.x, a.y - b.y), new Point(a.x - p.x, a.y - p.y))) / length(new Point(a.x - b.x, a.y - b.y));
    }

    static double id22(Point a, Point b, Point p) {
        if (dot(new Point(a.x - b.x, a.y - b.y), new Point(a.x - p.x, a.y - p.y)) < EPS)
            return length(new Point(a.x - p.x, a.y - p.y));
        if (dot(new Point(b.x - a.x, b.y - a.y), new Point(b.x - p.x, b.y - p.y)) < EPS)
            return length(new Point(b.x - p.x, b.y - p.y));
        return id14(a, b, p);
    }

    static int id16(int x1, int y1, int x2, int y2) {
        return Math.abs(gcd(x1 - x2, y1 - y2)) + 1;
    }

    static double id2(double b, double h) {
        return b * h / 2;
    }

    static double id5(double a, double b, double t) {
        return Math.abs(a * b * Math.sin(t) / 2);
    }

    static double id19(double t1, double t2, double s) {
        return Math.abs(s * s * Math.sin(t1) * Math.sin(t2) / (2 * Math.sin(t1 + t2)));
    }

    static double id20(double a, double b, double c) {
        double s = (a + b + c) / 2;
        return Math.sqrt(s * (s - a) * (s - b) * (s - c));
    }

    static double id10(Point a, Point b, Point c) {
        return Math.abs(cross(a, b) + cross(b, c) + cross(c, a)) / 2;
    }

    static int id18(int a, int b) {
        return a - b / 2 + 1;
    }

    static double cosRule(double a, double b, double c) {
        double res = (b * b + c * c - a * a) / (2 * b * c);
        if (Math.abs(res - 1) < EPS)
            res = 1;
        if (Math.abs(res + 1) < EPS)
            res = -1;
        return Math.acos(res);
    }

    static double id26(double s1, double s2, double a1) {
        double res = s2 * Math.sin(a1) / s1;
        if (Math.abs(res - 1) < EPS)
            res = 1;
        if (Math.abs(res + 1) < EPS)
            res = -1;
        return Math.asin(res);
    }

    static double id0(double s1, double a1, double a2) {
        double res = s1 * Math.sin(a2) / Math.sin(a1);
        return Math.abs(res);
    }

    static int id13(Point p0, Point p1, Point cen, double rad, Point r1, Point r2) {
        double a, b, c, t1, t2;
        a = dot(new Point(p1.x - p0.x, p1.y - p0.y), new Point(p1.x - p0.x, p1.y - p0.y));
        b = 2 * dot(new Point(p1.x - p0.x, p1.y - p0.y), new Point(p0.x - cen.x, p0.y - cen.y));
        c = dot(new Point(p0.x - cen.x, p0.y - cen.y), new Point(p0.x - cen.x, p0.y - cen.y)) - rad * rad;
        double det = b * b - 4 * a * c;
        int res;
        if (Math.abs(det) < EPS)
            det = 0;
        else if (det < 0)
            res = 0;
        else
            res = 2;
        det = Math.sqrt(det);
        t1 = (-b + det) / (2 * a);
        t2 = (-b - det) / (2 * a);
        r1.x = p0.x + t1 * (p1.x - p0.x);
        r1.y = p0.y + t1 * (p1.y - p0.y);
        r2.x = p0.x + t2 * (p1.x - p0.x);
        r2.y = p0.y + t2 * (p1.y - p0.y);
        return res;
    }

    static int id3(Point c1, double r1, Point c2, double r2, Point res1, Point res2) {
        if (same(c1, c2) && Math.abs(r1 - r2) < EPS) {
            res1 = res2 = c1;
            return Math.abs(r1) < EPS ? 1 : Integer.MAX_VALUE;
        }
        double len = length(new Point(c1.x - c2.x, c1.y - c2.y));
        if (Math.abs(len - (r1 + r2)) < EPS || Math.abs(Math.abs(r1 - r2) - len) < EPS) {
            Point d, c;
            double r;
            if (r1 > r2)
                d = new Point(c1.x - c2.x, c1.y - c2.y);
            else
                d = new Point(c2.x - c1.x, c2.y - c1.y);
            c = c1;
            r = r1;
            res1.x = res2.x = normalize(d).x * r + c.x;
            res1.y = res2.y = normalize(d).y * r + c.y;
            return 1;
        }
        if (len > r1 + r2 || len < Math.abs(r1 - r2))
            return 0;
        double a = cosRule(r2, r1, len);
        Point id11 = normalize(new Point(c1.x - c2.x, c1.y - c2.y));
        res1.x = rotate(id11, a).x + c1.x;
        res1.y = rotate(id11, a).y + c1.y;
        res2.x = rotate(id11, -a).x + c1.x;
        res2.y = rotate(id11, -a).y + c1.y;
        return 2;
    }

    static double polygonArea(ArrayList<Point> p) {
        double res = 0;
        for (int i = 0; i < p.size(); i++) {
            int j = (i + 1) % p.size();
            res += cross(p.get(i), p.get(j));
        }
        return Math.abs(res) / 2;
    }

    static Point id9(ArrayList<Point> polygon) {
        double a = 0;
        double x = 0.0, y = 0.0;
        for (int i = 0; i < polygon.size(); i++) {
            int j = (i + 1) % polygon.size();

            x += (polygon.get(i).x + polygon.get(j).x) * (polygon.get(i).x * polygon.get(j).y
                    - polygon.get(j).x * polygon.get(i).y);

            y += (polygon.get(i).y + polygon.get(j).y) * (polygon.get(i).x * polygon.get(j).y
                    - polygon.get(j).x * polygon.get(i).y);

            a += polygon.get(i).x * polygon.get(j).y - polygon.get(i).y * polygon.get(j).x;
        }

        a *= 0.5;
        x /= 6 * a;
        y /= 6 * a;

        return new Point(x, y);
    }

    static int id18(ArrayList<Point> p) {
        double area = 0;
        int bound = 0;
        for (int i = 0; i < p.size(); i++) {
            int j = (i + 1) % p.size();
            area += cross(p.get(i), p.get(j));
            Point v = new Point(p.get(i).x - p.get(j).x, p.get(i).y - p.get(j).y);
            bound += Math.abs(gcd((int) v.x, (int) v.y));
        }
        area /= 2;
        area = Math.abs(area);
        return Math.round((float) (area - bound / 2 + 1));
    }

    static void polygonCut(ArrayList<Point> p, Point a, Point b, ArrayList<Point> res) {
        res.clear();
        for (int i = 0; i < p.size(); i++) {
            int j = (i + 1) % p.size();
            boolean in1 = cross(new Point(a.x - b.x, a.y - b.y), new Point(a.x - p.get(i).x, a.y - p.get(i).y)) > EPS;
            boolean in2 = cross(new Point(a.x - b.x, a.y - b.y), new Point(a.x - p.get(j).x, a.y - p.get(j).y)) > EPS;
            if (in1)
                res.add(p.get(i));
            if (in1 ^ in2) {
                Point r = new Point(0, 0);
                intersect(a, b, p.get(i), p.get(j), r);
                res.add(r);
            }
        }
    }

    static void id25(ArrayList<Point> p, ArrayList<Point> q, ArrayList<Point> res) {
        res = q;
        for (int i = 0; i < p.size(); i++) {
            int j = (i + 1) % p.size();
            ArrayList<Point> temp = new ArrayList<>(res);
            polygonCut(temp, p.get(i), p.get(j), res);
            if (res.isEmpty())
                return;
        }
    }

    static void id21(ArrayList<Point> pnts, ArrayList<Point> rect, ArrayList<ArrayList<Point>> res) {
        res.clear();
        for (int i = 0; i < pnts.size(); i++) {
            res.add(new ArrayList<>(rect));
            for (int j = 0; j < pnts.size(); j++) {
                if (j == i)
                    continue;
                Point p = perp(new Point(pnts.get(i).x - pnts.get(j).x, pnts.get(i).y - pnts.get(j).y));
                Point m = mid(pnts.get(i), pnts.get(j));
                ArrayList<Point> temp = new ArrayList<>(res.get(res.size() - 1));
                polygonCut(temp, m, new Point(m.x + p.x, m.y + p.y), res.get(res.size() - 1));
                res.set(res.size() - 1, temp);
            }
        }
    }

    static int circlePoint(Point cen, double r, Point p) {
        double lensqr = lengthSqr(new Point(cen.x - p.x, cen.y - p.y));
        if (Math.abs(lensqr - r * r) < EPS)
            return 2;
        if (lensqr < r * r)
            return 1;
        return 0;
    }

    static int id1(Point cen, double r, Point p, Point r1, Point r2) {
        int s = circlePoint(cen, r, p);
        if (s != 0) {
            r1 = r2 = p;
            return s == 2 ? 1 : Integer.MAX_VALUE;
        }
        Point cp = new Point(p.x - cen.x, p.y - cen.y);
        double h = length(cp);
        double a = Math.acos(r / h);
        cp = normalize(cp);
        r1 = new Point(cp.x * r + cen.x, cp.y * r + cen.y);
        r2 = new Point(cp.x * r + cen.x, cp.y * r + cen.y);
        return 2;
    }

    static void id12(Point c1, double r1, Point c2, double r2, ArrayList<Segment> res) {
        if (r1 < r2) {
            double temp = r1;
            r1 = r2;
            r2 = temp;
            Point tempP = c1;
            c1 = c2;
            c2 = tempP;
        }
        double d = length(new Point(c1.x - c2.x, c1.y - c2.y));
        double theta = Math.acos((r1 - r2) / d);
        Point v = new Point(c2.x - c1.x, c2.y - c1.y);
        v = normalize(v);
        Point v1 = rotate(v, theta);
        Point v2 = rotate(v, -theta);
        res.clear();
        res.add(new Segment(new Point(c1.x + v1.x * r1, c1.y + v1.y * r1), new Point(c2.x + v1.x * r2, c2.y + v1.y * r2)));
        res.add(new Segment(new Point(c1.x + v2.x * r1, c1.y + v2.y * r1), new Point(c2.x + v2.x * r2, c2.y + v2.y * r2)));
        theta = Math.acos((r1 + r2) / d);
        v1 = rotate(v, theta);
        v2 = rotate(v, -theta);
        res.add(new Segment(new Point(c1.x + v1.x * r1, c1.y + v1.y * r1), new Point(c2.x - v1.x * r2, c2.y - v1.y * r2)));
        res.add(new Segment(new Point(c1.x + v2.x * r1, c1.y + v2.y * r1), new Point(c2.x - v2.x * r2, c2.y - v2.y * r2)));
    }

    static double polygonArea(ArrayList<Point> pnts) {
        double res = 0;
        for (int i = 0; i < pnts.size(); i++) {
            int j = (i + 1) % pnts.size();
            res += cross(pnts.get(i), pnts.get(j));
        }
        return Math.abs(res) / 2;
    }

    static double xp, yp, vp, x, y, v, r, R;
    static Point st, en;
    static double pi = Math.acos(-1);

    static double calcArc(Point a, Point b) {
        double theta = Math.abs(angle(b) - angle(a));
        if (theta > pi)
            theta = 2 * pi - theta;
        double res = theta * r;
        return res;
    }

    static double calcDis(Point a, Point c) {
        double arc = calcArc(a, c);
        double res = arc + Math.abs(length(new Point(a.x - st.x, a.y - st.y))) + Math.abs(length(new Point(c.x - en.x, c.y - en.y)));
        return res;
    }

    static double Calc(Point st, Point en) {
        Point a, b, c, d;
        id1(new Point(0, 0), r, st, a, b);
        id1(new Point(0, 0), r, en, c, d);
        double res = calcDis(a, c);
        res = Math.min(res, calcDis(a, d));
        res = Math.min(res, calcDis(b, c));
        res = Math.min(res, calcDis(b, d));
        return res;
    }

    static boolean can(double t) {
        Point start = st = new Point(x, y);
        Point fin = en = new Point(xp, yp);
        double theta = t * vp / R;
        fin = en = rotate(fin, theta);
        Point a, b;
        boolean intersection = false;
        int num = id13(start, fin, new Point(0, 0), r, a, b);
        if (num > 0) {
            if (id4(start, fin, a))
                intersection = true;
            if (num == 2 && id4(start, fin, b))
                intersection = true;
        }
        if (num <= 1 || !intersection) {
            return length(new Point(start.x - fin.x, start.y - fin.y)) < v * t + EPS;
        }
        double dis = Calc(st, fin);
        return dis < v * t + EPS;
    }

    static int gcd(int a, int b) {
        return b == 0 ? a : gcd(b, a % b);
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
        R = length(new Point(xp, yp));
        double ans = 10000000, hi = 1000000, lo = 0.0;
        for (int iter = 0; iter < 100; iter++) {
            double m = lo + (hi - lo) / 2.0;
            if (can(m))
                ans = m;
            else
                lo = m;
        }
        System.out.printf("%.10f\n", ans);
    }
}

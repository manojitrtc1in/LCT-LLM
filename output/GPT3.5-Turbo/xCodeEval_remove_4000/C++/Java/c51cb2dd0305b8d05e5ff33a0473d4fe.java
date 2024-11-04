import java.util.*;
import java.awt.geom.*;

class Main {
    static double EPS = 1e-9;
    static double xp, yp, vp, x, y, v, r, R;
    static Point2D.Double st, en;
    static double pi = Math.acos(-1);

    static class Point {
        double x, y;

        Point(double x, double y) {
            this.x = x;
            this.y = y;
        }
    }

    static double angle(Point p) {
        return Math.atan2(p.y, p.x);
    }

    static Point rotate(Point p, double theta) {
        double x = p.x * Math.cos(theta) - p.y * Math.sin(theta);
        double y = p.x * Math.sin(theta) + p.y * Math.cos(theta);
        return new Point(x, y);
    }

    static double cross(Point a, Point b) {
        return a.x * b.y - a.y * b.x;
    }

    static double length(Point p) {
        return Math.sqrt(p.x * p.x + p.y * p.y);
    }

    static Point vec(Point a, Point b) {
        return new Point(b.x - a.x, b.y - a.y);
    }

    static Point normalize(Point p) {
        double len = length(p);
        return new Point(p.x / len, p.y / len);
    }

    static Point mid(Point a, Point b) {
        return new Point((a.x + b.x) / 2, (a.y + b.y) / 2);
    }

    static boolean same(Point a, Point b) {
        return Math.abs(a.x - b.x) < EPS && Math.abs(a.y - b.y) < EPS;
    }

    static boolean collinear(Point a, Point b, Point c) {
        return Math.abs(cross(vec(a, b), vec(a, c))) < EPS;
    }

    static Point perp(Point p) {
        return new Point(-p.y, p.x);
    }

    static Point intersect(Point a, Point b, Point p, Point q) {
        double d1 = cross(vec(p, a), vec(b, a));
        double d2 = cross(vec(q, a), vec(b, a));
        double x = (d1 * q.x - d2 * p.x) / (d1 - d2);
        double y = (d1 * q.y - d2 * p.y) / (d1 - d2);
        return new Point(x, y);
    }

    static boolean id8(Point a, Point b, Point p) {
        return Math.abs(cross(vec(a, b), vec(a, p))) < EPS;
    }

    static boolean id23(Point a, Point b, Point p) {
        return dot(vec(a, p), vec(a, b)) > -EPS;
    }

    static boolean id4(Point a, Point b, Point p) {
        if (!collinear(a, b, p))
            return false;
        return id23(a, b, p) && id23(b, a, p);
    }

    static double id14(Point a, Point b, Point p) {
        return Math.abs(cross(vec(a, b), vec(a, p)) / length(vec(a, b)));
    }

    static double id22(Point a, Point b, Point p) {
        if (dot(vec(a, b), vec(a, p)) < EPS)
            return length(vec(a, p));
        if (dot(vec(b, a), vec(b, p)) < EPS)
            return length(vec(b, p));
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
        a = dot(p1, p1);
        b = 2 * dot(p1, p0) - 2 * dot(p1, cen);
        c = dot(p0, p0) - 2 * dot(p0, cen) + dot(cen, cen) - rad * rad;
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
            res1.x = res2.x = c1.x;
            res1.y = res2.y = c1.y;
            return Math.abs(r1) < EPS ? 1 : OO;
        }
        double len = length(vec(c1, c2));
        if (Math.abs(len - (r1 + r2)) < EPS || Math.abs(Math.abs(r1 - r2) - len) < EPS) {
            Point d, c;
            double r;
            if (r1 > r2)
                d = vec(c1, c2);
            else
                d = vec(c2, c1);
            c = c1;
            r = r1;
            res1.x = res2.x = normalize(d).x * r + c.x;
            res1.y = res2.y = normalize(d).y * r + c.y;
            return 1;
        }
        if (len > r1 + r2 || len < Math.abs(r1 - r2))
            return 0;
        double a = cosRule(r2, r1, len);
        Point id11 = normalize(vec(c1, c2));
        res1.x = rotate(id11, a).x + c1.x;
        res1.y = rotate(id11, a).y + c1.y;
        res2.x = rotate(id11, -a).x + c1.x;
        res2.y = rotate(id11, -a).y + c1.y;
        return 2;
    }

    static void circle2(Point p1, Point p2, Point cen, double r) {
        cen.x = (p1.x + p2.x) / 2;
        cen.y = (p1.y + p2.y) / 2;
        r = length(vec(p1, p2)) / 2;
    }

    static boolean circle3(Point p1, Point p2, Point p3, Point cen, double r) {
        Point m1 = mid(p1, p2);
        Point m2 = mid(p2, p3);
        Point id7 = perp(vec(p1, p2));
        Point id15 = perp(vec(p2, p3));
        boolean res = intersect(m1, new Point(m1.x + id7.x, m1.y + id7.y), m2,
                new Point(m2.x + id15.x, m2.y + id15.y), cen);
        r = length(vec(cen, p1));
        return res;
    }

    enum STATE {
        IN, OUT, BOUNDRY
    }

    static STATE circlePoint(Point cen, double r, Point p) {
        double lensqr = lengthSqr(vec(cen, p));
        if (Math.abs(lensqr - r * r) < EPS)
            return STATE.BOUNDRY;
        if (lensqr < r * r)
            return STATE.IN;
        return STATE.OUT;
    }

    static int id1(Point cen, double r, Point p, Point r1, Point r2) {
        STATE s = circlePoint(cen, r, p);
        if (s != STATE.OUT) {
            r1.x = r2.x = p.x;
            r1.y = r2.y = p.y;
            return s == STATE.BOUNDRY ? 1 : OO;
        }
        Point cp = vec(cen, p);
        double h = length(cp);
        double a = Math.acos(r / h);
        cp = normalize(cp);
        cp.x *= r;
        cp.y *= r;
        r1.x = cp.x * Math.cos(a) - cp.y * Math.sin(a) + cen.x;
        r1.y = cp.x * Math.sin(a) + cp.y * Math.cos(a) + cen.y;
        r2.x = cp.x * Math.cos(-a) - cp.y * Math.sin(-a) + cen.x;
        r2.y = cp.x * Math.sin(-a) + cp.y * Math.cos(-a) + cen.y;
        return 2;
    }

    static int gcd(int a, int b) {
        return b == 0 ? a : gcd(b, a % b);
    }

    static double dot(Point a, Point b) {
        return a.x * b.x + a.y * b.y;
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
            Point v = vec(p.get(i), p.get(j));
            bound += Math.abs(gcd((int) v.x, (int) v.y));
        }
        area /= 2;
        area = Math.abs(area);
        return (int) Math.round(area - bound / 2 + 1);
    }

    static void polygonCut(ArrayList<Point> p, Point a, Point b, ArrayList<Point> res) {
        res.clear();
        for (int i = 0; i < p.size(); i++) {
            int j = (i + 1) % p.size();
            boolean in1 = cross(vec(a, b), vec(a, p.get(i))) > EPS;
            boolean in2 = cross(vec(a, b), vec(a, p.get(j))) > EPS;
            if (in1)
                res.add(p.get(i));
            if (in1 ^ in2) {
                Point r = intersect(a, b, p.get(i), p.get(j));
                res.add(r);
            }
        }
    }

    static void id25(ArrayList<Point> p, ArrayList<Point> q, ArrayList<Point> res) {
        res = q;
        for (int i = 0; i < p.size(); i++) {
            int j = (i + 1) % p.size();
            ArrayList<Point> temp = new ArrayList<>(res);
            polygonCut(res, p.get(i), p.get(j), temp);
            res = temp;
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
                Point p = perp(vec(pnts.get(i), pnts.get(j)));
                Point m = mid(pnts.get(i), pnts.get(j));
                ArrayList<Point> temp = new ArrayList<>();
                polygonCut(res.get(res.size() - 1), m, new Point(m.x + p.x, m.y + p.y), temp);
                res.set(res.size() - 1, temp);
            }
        }
    }

    static STATE id24(ArrayList<Point> p, Point pnt) {
        Point p2 = new Point(pnt.x + 1, pnt.y);
        int cnt = 0;
        for (int i = 0; i < p.size(); i++) {
            int j = (i + 1) % p.size();
            if (id4(p.get(i), p.get(j), pnt))
                return STATE.BOUNDRY;
            Point r;
            if (!intersect(pnt, p2, p.get(i), p.get(j), r))
                continue;
            if (!id23(pnt, p2, r))
                continue;
            if (same(r, p.get(i)) || same(r, p.get(j)))
                if (Math.abs(r.y - Math.min(p.get(i).y, p.get(j).y)) < EPS)
                    continue;
            if (!id4(p.get(i), p.get(j), r))
                continue;
            cnt++;
        }
        return cnt % 2 == 1 ? STATE.IN : STATE.OUT;
    }

    static class Cmp implements Comparator<Point> {
        Point about;

        Cmp(Point c) {
            about = c;
        }

        public int compare(Point p, Point q) {
            double cr = cross(vec(about, p), vec(about, q));
            if (Math.abs(cr) < EPS)
                return new Point(p.y, p.x).compareTo(new Point(q.y, q.x));
            return cr > 0 ? 1 : -1;
        }
    }

    static void id6(ArrayList<Point> pnts) {
        Point mn = new Point(1 / 0.0, 1 / 0.0);
        for (int i = 0; i < pnts.size(); i++)
            if (new Point(pnts.get(i).y, pnts.get(i).x).compareTo(new Point(mn.y, mn.x)) < 0)
                mn = pnts.get(i);

        Collections.sort(pnts, new Cmp(mn));
    }

    static void id17(ArrayList<Point> pnts, ArrayList<Point> convex) {
        id6(pnts);
        convex.clear();
        convex.add(pnts.get(0));
        if (pnts.size() == 1)
            return;
        convex.add(pnts.get(1));
        if (pnts.size() == 2) {
            if (same(pnts.get(0), pnts.get(1)))
                convex.remove(convex.size() - 1);
            return;
        }
        for (int i = 2; i <= pnts.size(); i++) {
            Point c = pnts.get(i % pnts.size());
            while (convex.size() > 1) {
                Point b = convex.get(convex.size() - 1);
                Point a = convex.get(convex.size() - 2);
                if (cross(vec(b, a), vec(b, c)) < -EPS)
                    break;
                convex.remove(convex.size() - 1);
            }
            if (i < pnts.size())
                convex.add(pnts.get(i));
        }
    }

    static double xp() {
        return xp;
    }

    static double yp() {
        return yp;
    }

    static double vp() {
        return vp;
    }

    static double x() {
        return x;
    }

    static double y() {
        return y;
    }

    static double v() {
        return v;
    }

    static double r() {
        return r;
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
            return length(vec(start, fin)) < v * t + EPS;
        }
        double dis = Calc(st, fin);
        return dis < v * t + EPS;
    }

    static double calcArc(Point a, Point b) {
        double theta = Math.abs(angle(b) - angle(a));
        if (theta > pi)
            theta = 2 * pi - theta;
        double res = theta * r;
        return res;
    }

    static double calcDis(Point a, Point c) {
        double arc = calcArc(a, c);
        double res = arc + Math.abs(length(vec(a, st))) + Math.abs(length(vec(c, en)));
        return res;
    }

    static int OO = (int) 1e9;

    static int id13(Point p0, Point p1, Point cen, double rad, Point r1, Point r2) {
        double a, b, c, t1, t2;
        a = dot(p1, p1);
        b = 2 * dot(p1, p0) - 2 * dot(p1, cen);
        c = dot(p0, p0) - 2 * dot(p0, cen) + dot(cen, cen) - rad * rad;
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

    static double lengthSqr(Point p) {
        return p.x * p.x + p.y * p.y;
    }

    static double dot(Point a, Point b) {
        return a.x * b.x + a.y * b.y;
    }

    static double xp(double xp) {
        return xp;
    }

    static double yp(double yp) {
        return yp;
    }

    static double vp(double vp) {
        return vp;
    }

    static double x(double x) {
        return x;
    }

    static double y(double y) {
        return y;
    }

    static double v(double v) {
        return v;
    }

    static double r(double r) {
        return r;
    }

    static double pi() {
        return pi;
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
                lo = m + EPS;
        }
        System.out.printf("%.10f\n", ans);
    }
}

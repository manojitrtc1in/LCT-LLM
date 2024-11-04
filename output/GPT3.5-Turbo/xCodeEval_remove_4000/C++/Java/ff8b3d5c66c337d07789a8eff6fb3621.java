import java.util.*;
import java.lang.*;
import java.io.*;

class Main
{
    static class Point {
        double x, y;
        Point(double x, double y) {
            this.x = x;
            this.y = y;
        }
    }

    static class Polygon {
        List<Point> points;
        Polygon() {
            points = new ArrayList<>();
        }
    }

    static final double EPS = 1e-8;

    static int cmp(double x, double y, double tol) {
        return (x <= y + tol) ? ((x + tol < y) ? -1 : 0) : 1;
    }

    static int cmp(double x, double y) {
        return cmp(x, y, EPS);
    }

    static double hypot(double x, double y) {
        return Math.sqrt(x * x + y * y);
    }

    static double atan2(double y, double x) {
        return Math.atan2(y, x);
    }

    static double abs(Point p) {
        return hypot(p.x, p.y);
    }

    static double arg(Point p) {
        return atan2(p.y, p.x);
    }

    static double dist2(Point p, Point q) {
        return ((p.x - q.x) * (p.x - q.x) + (p.y - q.y) * (p.y - q.y));
    }

    static Point id19(Point p) {
        return new Point(-p.y, p.x);
    }

    static Point id5(Point p) {
        return new Point(p.y, -p.x);
    }

    static Point id14(Point p, double t) {
        return new Point(p.x * Math.cos(t) - p.y * Math.sin(t), p.x * Math.sin(t) + p.y * Math.cos(t));
    }

    static Point id9(Point a, Point b, Point c) {
        return new Point(a.x + (b.x - a.x) * ((c.x - a.x) * (b.x - a.x)) / ((b.x - a.x) * (b.x - a.x)),
                a.y + (b.y - a.y) * ((c.x - a.x) * (b.x - a.x)) / ((b.x - a.x) * (b.x - a.x)));
    }

    static Point id20(Point a, Point b, Point c) {
        double r = ((b.x - a.x) * (b.x - a.x) + (b.y - a.y) * (b.y - a.y));
        if (Math.abs(r) < EPS)
            return a;
        r = ((c.x - a.x) * (b.x - a.x) + (c.y - a.y) * (b.y - a.y)) / r;
        if (r < 0)
            return a;
        if (r > 1)
            return b;
        return new Point(a.x + (b.x - a.x) * r, a.y + (b.y - a.y) * r);
    }

    static boolean between(Point p, Point q, Point r) {
        return ccw(p, q, r) == 0 && cmp((p.x - q.x) * (r.x - q.x) + (p.y - q.y) * (r.y - q.y)) <= 0;
    }

    static double id10(Point a, Point b, Point c) {
        return Math.sqrt(dist2(c, id20(a, b, c)));
    }

    static double id2(double x, double y, double z, double a, double b, double c, double d) {
        return Math.abs(a * x + b * y + c * z - d) / Math.sqrt(a * a + b * b + c * c);
    }

    static boolean linesParallel(Point a, Point b, Point c, Point d) {
        return Math.abs((b.x - a.x) * (c.y - d.y) - (b.y - a.y) * (c.x - d.x)) < EPS;
    }

    static boolean id0(Point a, Point b, Point c, Point d) {
        return linesParallel(a, b, c, d) && Math.abs((a.x - b.x) * (a.y - c.y) - (a.y - b.y) * (a.x - c.x)) < EPS
                && Math.abs((c.x - d.x) * (c.y - a.y) - (c.y - d.y) * (c.x - a.x)) < EPS;
    }

    static int ccw(Point p, Point q, Point r) {
        return cmp((p.x - r.x) * (q.y - r.y), (p.y - r.y) * (q.x - r.x));
    }

    static double angle(Point p, Point q, Point r) {
        Point u = new Point(p.x - q.x, p.y - q.y);
        Point v = new Point(r.x - q.x, r.y - q.y);
        return Math.atan2(u.x * v.y - u.y * v.x, u.x * v.x + u.y * v.y);
    }

    static boolean id13(Point p, Point q, Point r, Point s) {
        Point A = new Point(q.x - p.x, q.y - p.y);
        Point B = new Point(s.x - r.x, s.y - r.y);
        Point C = new Point(r.x - p.x, r.y - p.y);
        Point D = new Point(s.x - q.x, s.y - q.y);
        int a = cmp(A.x * C.y - A.y * C.x) + 2 * cmp(A.x * D.y - A.y * D.x);
        int b = cmp(B.x * C.y - B.y * C.x) + 2 * cmp(B.x * D.y - B.y * D.x);
        if (a == 3 || a == -3 || b == 3 || b == -3)
            return false;
        if (a != 0 || b != 0 || p.equals(r) || p.equals(s) || q.equals(r) || q.equals(s))
            return true;
        int t = (p.compareTo(r) < 0 ? 1 : 0) + (p.compareTo(s) < 0 ? 1 : 0) + (q.compareTo(r) < 0 ? 1 : 0)
                + (q.compareTo(s) < 0 ? 1 : 0);
        return t != 0 && t != 4;
    }

    static Point id8(Point p, Point q, Point r, Point s) {
        Point a = new Point(q.x - p.x, q.y - p.y);
        Point b = new Point(s.x - r.x, s.y - r.y);
        Point c = new Point(p.x * q.y - p.y * q.x, r.x * s.y - r.y * s.x);
        return new Point((a.x * b.x) % c.x, (a.y * b.y) % c.y);
    }

    static boolean id1(Point p1, Point p2, double r, Point c) {
        double d2 = (p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y);
        double det = ((r * r) / d2) - 0.25;
        if (det < 0.0)
            return false;
        double h = Math.sqrt(det);
        c.x = (p1.x + p2.x) * 0.5 + (p1.y - p2.y) * h;
        c.y = (p1.y + p2.y) * 0.5 + (p2.x - p1.x) * h;
        return true;
    }

    static Point id4(Point a, Point b, Point c) {
        b = new Point((a.x + b.x) / 2, (a.y + b.y) / 2);
        c = new Point((a.x + c.x) / 2, (a.y + c.y) / 2);
        return id8(b, new Point(b.x + id5(a).x, b.y + id5(a).y), c, new Point(c.x + id5(a).x, c.y + id5(a).y));
    }

    static Point id18(Point a, Point b, Point c) {
        Point d = new Point(b.x + id14(new Point(c.x - b.x, c.y - b.y), angle(c, b, a) / 2).x,
                b.y + id14(new Point(c.x - b.x, c.y - b.y), angle(c, b, a) / 2).y);
        Point e = new Point(c.x + id14(new Point(a.x - c.x, a.y - c.y), angle(a, c, b) / 2).x,
                c.y + id14(new Point(a.x - c.x, a.y - c.y), angle(a, c, b) / 2).y);
        return id8(b, d, c, e);
    }

    static List<Point> id11(Point a, Point b, Point c, double r) {
        List<Point> ret = new ArrayList<>();
        b = new Point(b.x - a.x, b.y - a.y);
        a = new Point(a.x - c.x, a.y - c.y);
        double A = b.x * b.x + b.y * b.y;
        double B = a.x * b.x + a.y * b.y;
        double C = a.x * a.x + a.y * a.y - r * r;
        double D = B * B - A * C;
        if (D < -EPS)
            return ret;
        ret.add(new Point(c.x + a.x + b.x * (-B + Math.sqrt(D + EPS)) / A,
                c.y + a.y + b.y * (-B + Math.sqrt(D + EPS)) / A));
        if (D > EPS)
            ret.add(new Point(c.x + a.x + b.x * (-B - Math.sqrt(D)) / A, c.y + a.y + b.y * (-B - Math.sqrt(D)) / A));
        return ret;
    }

    static List<Point> id3(Point a, Point b, double r, double R) {
        List<Point> ret = new ArrayList<>();
        double d = Math.sqrt(dist2(a, b));
        if (d > r + R || d + Math.min(r, R) < Math.max(r, R))
            return ret;
        double x = (d * d - R * R + r * r) / (2 * d);
        double y = Math.sqrt(r * r - x * x);
        Point v = new Point((b.x - a.x) / d, (b.y - a.y) / d);
        ret.add(new Point(a.x + v.x * x + id19(v).x * y, a.y + v.y * x + id19(v).y * y));
        if (y > 0)
            ret.add(new Point(a.x + v.x * x - id19(v).x * y, a.y + v.y * x - id19(v).y * y));
        return ret;
    }

    static List<Point> id7(Point c, double r, Point p) {
        List<Point> resp = new ArrayList<>();
        Point toCenter = new Point(c.x - p.x, c.y - p.y);
        if (cmp(r - Math.sqrt(dist2(toCenter, new Point(0, 0)))) <= 0) {
            resp.add(p);
            resp.add(p);
            return resp;
        }
        double angle = Math.asin(r / Math.sqrt(dist2(toCenter, new Point(0, 0)))));
        Point uni = new Point(toCenter.x / Math.sqrt(dist2(toCenter, new Point(0, 0))),
                toCenter.y / Math.sqrt(dist2(toCenter, new Point(0, 0))));
        double tam = Math.sqrt(dist2(toCenter, new Point(0, 0))) - r;
        Point origi = new Point(uni.x * tam, uni.y * tam);
        Point p1 = new Point(p.x + id14(origi, angle).x, p.y + id14(origi, angle).y);
        resp.add(p1);
        Point p2 = new Point(p.x + id14(origi, -angle).x, p.y + id14(origi, -angle).y);
        resp.add(p2);
        return resp;
    }

    static int inPoly(Point p, Polygon T) {
        double a = 0;
        int N = T.points.size();
        for (int i = 0; i < N; i++) {
            if (between(T.points.get(i), p, T.points.get((i + 1) % N)))
                return -1;
            a += angle(T.points.get(i), p, T.points.get((i + 1) % N));
        }
        return cmp(a) != 0 ? 1 : 0;
    }

    static double polyArea(Polygon T) {
        double s = 0;
        int n = T.points.size();
        for (int i = 0; i < n; i++)
            s += T.points.get(i).x * T.points.get((i + 1) % n).y - T.points.get(i).y * T.points.get((i + 1) % n).x;
        return s / 2;
    }

    static Point id17(List<Point> p) {
        Point c = new Point(0, 0);
        double scale = 6.0 * polyArea(p);
        for (int i = 0; i < p.size(); i++) {
            int j = (i + 1) % p.size();
            c.x += (p.get(i).x + p.get(j).x) * (p.get(i).x * p.get(j).y - p.get(j).x * p.get(i).y);
            c.y += (p.get(i).y + p.get(j).y) * (p.get(i).x * p.get(j).y - p.get(j).x * p.get(i).y);
        }
        c.x /= scale;
        c.y /= scale;
        return c;
    }

    static boolean id6(Point p, Point q) {
        Point P = new Point(p.x - Point.pivot.x, p.y - Point.pivot.y);
        Point Q = new Point(q.x - Point.pivot.x, q.y - Point.pivot.y);
        double R = P.x * Q.y - P.y * Q.x;
        if (cmp(R) != 0)
            return R > 0;
        return cmp(P.x * P.x + P.y * P.y, Q.x * Q.x + Q.y * Q.y) < 0;
    }

    static Polygon id15(List<Point> T) {
        int j = 0, k, n = T.size();
        Point.pivot = Collections.min(T, (a, b) -> {
            if (a.y != b.y)
                return Double.compare(a.y, b.y);
            return Double.compare(a.x, b.x);
        });
        Collections.sort(T, (a, b) -> {
            if (id6(a, b))
                return -1;
            if (id6(b, a))
                return 1;
            return 0;
        });
        for (k = n - 2; k >= 0 && ccw(T.get(0), T.get(n - 1), T.get(k)) == 0; k--)
            ;
        Collections.reverse(T.subList(k + 1, T.size()));
        Polygon U = new Polygon();
        for (int i = 0; i < n; i++) {
            while (j > 1 && ccw(U.points.get(j - 1), U.points.get(j - 2), T.get(i)) >= 0)
                j--;
            U.points.set(j++, T.get(i));
        }
        U.points.subList(j, U.points.size()).clear();
        return U;
    }

    static Polygon id16(Polygon P, Polygon Q) {
        int m = Q.points.size(), n = P.points.size();
        int a = 0, b = 0, aa = 0, ba = 0, inflag = 0;
        Polygon R = new Polygon();
        while ((aa < n || ba < m) && aa < 2 * n && ba < 2 * m) {
            Point p1 = P.points.get(a), p2 = P.points.get((a + 1) % n), q1 = Q.points.get(b),
                    q2 = Q.points.get((b + 1) % m);
            Point A = new Point(p2.x - p1.x, p2.y - p1.y), B = new Point(q2.x - q1.x, q2.y - q1.y);
            int cross = cmp(A.x * B.y - A.y * B.x), ha = ccw(p2, q2, p1), hb = ccw(q2, p2, q1);
            if (cross == 0 && ccw(p1, q1, p2) == 0 && cmp(A.x * B.x + A.y * B.y) < 0) {
                if (between(p1, q1, p2))
                    R.points.add(q1);
                if (between(p1, q2, p2))
                    R.points.add(q2);
                if (between(q1, p1, q2))
                    R.points.add(p1);
                if (between(q1, p2, q2))
                    R.points.add(p2);
                if (R.points.size() < 2)
                    return new Polygon();
                inflag = 1;
                break;
            } else if (cross != 0 && id13(p1, p2, q1, q2)) {
                if (inflag == 0)
                    aa = ba = 0;
                R.points.add(id8(p1, p2, q1, q2));
                inflag = (hb > 0) ? 1 : -1;
            }
            if (cross == 0 && hb < 0 && ha < 0)
                return R;
            boolean t = cross == 0 && hb == 0 && ha == 0;
            if (t ? (inflag == 1) : (cross >= 0) ? (ha <= 0) : (hb > 0)) {
                if (inflag == -1)
                    R.points.add(q2);
                ba++;
                b++;
                b %= m;
            } else {
                if (inflag == 1)
                    R.points.add(p2);
                aa++;
                a++;
                a %= n;
            }
        }
        if (inflag == 0) {
            if (inPoly(P.points.get(0), Q) != 0)
                return P;
            if (inPoly(Q.points.get(0), P) != 0)
                return Q;
        }
        R.points = R.points.subList(0, R.points.size());
        if (R.points.size() > 1 && R.points.get(0).equals(R.points.get(R.points.size() - 1)))
            R.points.remove(R.points.size() - 1);
        return R;
    }

    static final double PI = Math.acos(-1);

    public static void main(String[] args) throws java.lang.Exception {
        Scanner sc = new Scanner(System.in);
        int xp = sc.nextInt();
        int yp = sc.nextInt();
        int vp = sc.nextInt();
        int x = sc.nextInt();
        int y = sc.nextInt();
        int v = sc.nextInt();
        int r = sc.nextInt();
        int cont = 1000000;
        double R = hypot(yp, xp);
        double initial = atan2(yp, xp);
        double bot = 0;
        double timeTot = 1000000.0;
        double t1 = (2 * PI * R) / vp;
        double top = timeTot;
        while (top - bot > EPS) {
            double mid = (top + bot) / 2;
            double angle = ((2 * PI * mid) / t1) + initial;
            Point loc = new Point(Math.cos(angle) * R, Math.sin(angle) * R);
            if (pode(loc, mid)) {
                top = mid - EPS;
            } else {
                bot = mid + EPS;
            }
        }
        System.out.printf("%.7f\n", bot);
    }
}

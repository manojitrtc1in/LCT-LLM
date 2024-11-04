import java.util.*;
import java.lang.*;
import java.io.*;

class Main {
    static class Point {
        double x, y;
        Point(double x, double y) {
            this.x = x;
            this.y = y;
        }
        Point() {
            this.x = 0;
            this.y = 0;
        }
        Point add(Point q) {
            return new Point(this.x + q.x, this.y + q.y);
        }
        Point subtract(Point q) {
            return new Point(this.x - q.x, this.y - q.y);
        }
        Point multiply(double t) {
            return new Point(this.x * t, this.y * t);
        }
        Point divide(double t) {
            return new Point(this.x / t, this.y / t);
        }
        double dot(Point q) {
            return this.x * q.x + this.y * q.y;
        }
        double cross(Point q) {
            return this.x * q.y - this.y * q.x;
        }
        int compare(Point q) {
            if (this.x < q.x) return -1;
            if (this.x > q.x) return 1;
            if (this.y < q.y) return -1;
            if (this.y > q.y) return 1;
            return 0;
        }
        boolean equals(Point q) {
            return this.compare(q) == 0;
        }
        boolean notEquals(Point q) {
            return this.compare(q) != 0;
        }
        boolean lessThan(Point q) {
            return this.compare(q) < 0;
        }
        @Override
        public String toString() {
            return "(" + this.x + ", " + this.y + ")";
        }
    }

    static class Polygon {
        ArrayList<Point> points;
        Polygon() {
            this.points = new ArrayList<>();
        }
        double area() {
            double s = 0;
            int n = this.points.size();
            for (int i = 0; i < n; i++) {
                s += this.points.get(i).cross(this.points.get((i + 1) % n));
            }
            return s / 2;
        }
    }

    static final double EPS = 1e-8;

    static int cmp(double x, double y, double tol) {
        return (x <= y + tol) ? ((x + tol < y) ? -1 : 0) : 1;
    }

    static int cmp(double x, double y) {
        return cmp(x, y, EPS);
    }

    static int ccw(Point p, Point q, Point r) {
        return cmp((p.subtract(r)).cross(q.subtract(r)));
    }

    static double angle(Point p, Point q, Point r) {
        Point u = p.subtract(q);
        Point v = r.subtract(q);
        return Math.atan2(u.cross(v), u.dot(v));
    }

    static double dist2(Point p, Point q) {
        return ((p.subtract(q)).dot(p.subtract(q)));
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
        return a.add((b.subtract(a)).multiply((c.subtract(a)).dot(b.subtract(a)) / (b.subtract(a)).dot(b.subtract(a))));
    }

    static Point id20(Point a, Point b, Point c) {
        double r = (b.subtract(a)).dot(b.subtract(a));
        if (Math.abs(r) < EPS) return a;
        r = (c.subtract(a)).dot(b.subtract(a)) / r;
        if (r < 0) return a;
        if (r > 1) return b;
        return a.add((b.subtract(a)).multiply(r));
    }

    static boolean between(Point p, Point q, Point r) {
        return ccw(p, q, r) == 0 && cmp((p.subtract(q)).dot(r.subtract(q))) <= 0;
    }

    static double id10(Point a, Point b, Point c) {
        return Math.sqrt(dist2(c, id20(a, b, c)));
    }

    static double id2(double x, double y, double z, double a, double b, double c, double d) {
        return Math.abs(a * x + b * y + c * z - d) / Math.sqrt(a * a + b * b + c * c);
    }

    static boolean linesParallel(Point a, Point b, Point c, Point d) {
        return Math.abs((b.subtract(a)).cross(c.subtract(d))) < EPS;
    }

    static boolean id0(Point a, Point b, Point c, Point d) {
        return linesParallel(a, b, c, d) && Math.abs((a.subtract(b)).cross(a.subtract(c))) < EPS && Math.abs((c.subtract(d)).cross(c.subtract(a))) < EPS;
    }

    static boolean id13(Point p, Point q, Point r, Point s) {
        Point A = q.subtract(p);
        Point B = s.subtract(r);
        Point C = r.subtract(p);
        Point D = s.subtract(q);
        int a = cmp(A.cross(C)) + 2 * cmp(A.cross(D));
        int b = cmp(B.cross(C)) + 2 * cmp(B.cross(D));
        if (a == 3 || a == -3 || b == 3 || b == -3) return false;
        if (a != 0 || b != 0 || p.equals(r) || p.equals(s) || q.equals(r) || q.equals(s)) return true;
        int t = (p.lessThan(r) ? 1 : 0) + (p.lessThan(s) ? 1 : 0) + (q.lessThan(r) ? 1 : 0) + (q.lessThan(s) ? 1 : 0);
        return t != 0 && t != 4;
    }

    static Point id8(Point p, Point q, Point r, Point s) {
        Point a = q.subtract(p);
        Point b = s.subtract(r);
        Point c = new Point((p.cross(q)), (r.cross(s)));
        return new Point((new Point(a.x, b.x)).cross(c), (new Point(a.y, b.y)).cross(c)).divide(a.cross(b));
    }

    static boolean id1(Point p1, Point p2, double r, Point c) {
        double d2 = (p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y);
        double det = ((r * r) / d2) - 0.25;
        if (det < 0.0) return false;
        double h = Math.sqrt(det);
        c.x = (p1.x + p2.x) * 0.5 + (p1.y - p2.y) * h;
        c.y = (p1.y + p2.y) * 0.5 + (p2.x - p1.x) * h;
        return true;
    }

    static Point id4(Point a, Point b, Point c) {
        b = a.add(b).divide(2);
        c = a.add(c).divide(2);
        return id8(b, b.add(id5(a.subtract(b))), c, c.add(id5(a.subtract(c))));
    }

    static Point id18(Point a, Point b, Point c) {
        Point d = b.add(id14(c.subtract(b), angle(c, b, a) / 2));
        Point e = c.add(id14(a.subtract(c), angle(a, c, b) / 2));
        return id8(b, d, c, e);
    }

    static ArrayList<Point> id11(Point a, Point b, Point c, double r) {
        ArrayList<Point> ret = new ArrayList<>();
        b = b.subtract(a);
        a = a.subtract(c);
        double A = b.dot(b);
        double B = a.dot(b);
        double C = a.dot(a) - r * r;
        double D = B * B - A * C;
        if (D < -EPS) return ret;
        ret.add(c.add(a).add(b.multiply((-B + Math.sqrt(D + EPS)) / A)));
        if (D > EPS) ret.add(c.add(a).add(b.multiply((-B - Math.sqrt(D)) / A)));
        return ret;
    }

    static ArrayList<Point> id3(Point a, Point b, double r, double R) {
        ArrayList<Point> ret = new ArrayList<>();
        double d = Math.sqrt(dist2(a, b));
        if (d > r + R || d + Math.min(r, R) < Math.max(r, R)) return ret;
        double x = (d * d - R * R + r * r) / (2 * d);
        double y = Math.sqrt(r * r - x * x);
        Point v = (b.subtract(a)).divide(d);
        ret.add(a.add(v.multiply(x)).add(id19(v).multiply(y)));
        if (y > 0) ret.add(a.add(v.multiply(x)).subtract(id19(v).multiply(y)));
        return ret;
    }

    static ArrayList<Point> id7(Point c, double r, Point p) {
        ArrayList<Point> resp = new ArrayList<>();
        Point toCenter = c.subtract(p);
        if (cmp(r - Math.sqrt(dist2(toCenter, new Point(0, 0)))) <= 0) {
            resp.add(p);
            resp.add(p);
            return resp;
        }
        double angle = Math.asin(r / Math.sqrt(dist2(toCenter, new Point(0, 0))));
        Point uni = toCenter.divide(Math.sqrt(dist2(toCenter, new Point(0, 0))));
        double tam = Math.sqrt(dist2(toCenter, new Point(0, 0)) - r * r);
        Point origi = uni.multiply(tam);
        Point p1 = p.add(id14(origi, angle));
        resp.add(p1);
        Point p2 = p.add(id14(origi, -angle));
        resp.add(p2);
        return resp;
    }

    static int inPoly(Point p, Polygon T) {
        double a = 0;
        int N = T.points.size();
        for (int i = 0; i < N; i++) {
            if (between(T.points.get(i), p, T.points.get((i + 1) % N))) return -1;
            a += angle(T.points.get(i), p, T.points.get((i + 1) % N));
        }
        return cmp(a) != 0 ? 1 : 0;
    }

    static Point id17(ArrayList<Point> p) {
        Point c = new Point(0, 0);
        double scale = 6.0 * polyArea(p);
        for (int i = 0; i < p.size(); i++) {
            int j = (i + 1) % p.size();
            c = c.add((p.get(i).add(p.get(j))).multiply(p.get(i).x * p.get(j).y - p.get(j).x * p.get(i).y));
        }
        return c.divide(scale);
    }

    static boolean id6(Point p, Point q) {
        Point P = p.subtract(Point.pivot);
        Point Q = q.subtract(Point.pivot);
        double R = P.cross(Q);
        if (cmp(R) != 0) return R > 0;
        return cmp(P.dot(P), Q.dot(Q)) < 0;
    }

    static Polygon id15(ArrayList<Point> T) {
        int j = 0, k, n = T.size();
        Point.pivot = Collections.min(T, new Comparator<Point>() {
            @Override
            public int compare(Point p1, Point p2) {
                return p1.compare(p2);
            }
        });
        Collections.sort(T, new Comparator<Point>() {
            @Override
            public int compare(Point p1, Point p2) {
                return p1.compare(p2);
            }
        });
        for (k = n - 2; k >= 0 && ccw(T.get(0), T.get(n - 1), T.get(k)) == 0; k--);
        Collections.reverse(T.subList(k + 1, T.size()));
        Polygon U = new Polygon();
        for (int i = 0; i < n; i++) {
            while (j > 1 && ccw(U.points.get(j - 1), U.points.get(j - 2), T.get(i)) >= 0) j--;
            U.points.add(T.get(i));
            j++;
        }
        U.points.subList(j, U.points.size()).clear();
        return U;
    }

    static Polygon id16(Polygon P, Polygon Q) {
        int m = Q.points.size(), n = P.points.size();
        int a = 0, b = 0, aa = 0, ba = 0, inflag = 0;
        Polygon R = new Polygon();
        while ((aa < n || ba < m) && aa < 2 * n && ba < 2 * m) {
            Point p1 = P.points.get(a), p2 = P.points.get((a + 1) % n), q1 = Q.points.get(b), q2 = Q.points.get((b + 1) % m);
            Point A = p2.subtract(p1), B = q2.subtract(q1);
            int cross = cmp(A.cross(B)), ha = ccw(p2, q2, p1), hb = ccw(q2, p2, q1);
            if (cross == 0 && ccw(p1, q1, p2) == 0 && cmp(A.dot(B)) < 0) {
                if (between(p1, q1, p2)) R.points.add(q1);
                if (between(p1, q2, p2)) R.points.add(q2);
                if (between(q1, p1, q2)) R.points.add(p1);
                if (between(q1, p2, q2)) R.points.add(p2);
                if (R.points.size() < 2) return new Polygon();
                inflag = 1;
                break;
            } else if (cross != 0 && id13(p1, p2, q1, q2)) {
                if (inflag == 0) aa = ba = 0;
                R.points.add(id8(p1, p2, q1, q2));
                inflag = (hb > 0) ? 1 : -1;
            }
            if (cross == 0 && hb < 0 && ha < 0) return R;
            boolean t = cross == 0 && hb == 0 && ha == 0;
            if (t ? (inflag == 1) : (cross >= 0) ? (ha <= 0) : (hb > 0)) {
                if (inflag == -1) R.points.add(q2);
                ba++;
                b++;
                b %= m;
            } else {
                if (inflag == 1) R.points.add(p2);
                aa++;
                a++;
                a %= n;
            }
        }
        if (inflag == 0) {
            if (inPoly(P.points.get(0), Q) != 0) return P;
            if (inPoly(Q.points.get(0), P) != 0) return Q;
        }
        R.points.subList(0, R.points.size()).clear();
        if (R.points.size() > 1 && R.points.get(0).equals(R.points.get(R.points.size() - 1))) R.points.remove(R.points.size() - 1);
        return R;
    }

    static final double PI = Math.acos(-1);

    static int xp, yp, vp, x, y, v, r;

    static Point origin = new Point(0, 0);

    static int pode(Point loc, double time) {
        Point nave = new Point(x, y);
        if (cmp(id10(loc, nave, origin), r) >= 0) {
            return cmp(time, Math.abs(nave.subtract(loc).dot(nave.subtract(loc))) / v) >= 0 ? 1 : 0;
        } else {
            double distN = Math.sqrt(dist2(nave, origin) - r * r);
            double distL = Math.sqrt(dist2(loc, origin) - r * r);
            double a = Math.abs(nave.subtract(loc).dot(nave.subtract(loc)));
            double b = Math.abs(nave.subtract(origin).dot(nave.subtract(origin)));
            double c = Math.abs(loc.subtract(origin).dot(loc.subtract(origin)));
            double bigcos = (b * b + c * c - a * a) / (2 * b * c);
            double id12 = Math.acos(bigcos) - Math.abs(Math.atan(distN / r)) - Math.abs(Math.atan(distL / r));
            double menor = distN + distL + Math.abs(r * id12);
            return cmp(time, menor / v) >= 0 ? 1 : 0;
        }
    }

    public static void main(String[] args) throws java.lang.Exception {
        Scanner sc = new Scanner(System.in);
        xp = sc.nextInt();
        yp = sc.nextInt();
        vp = sc.nextInt();
        x = sc.nextInt();
        y = sc.nextInt();
        v = sc.nextInt();
        r = sc.nextInt();
        double R = Math.hypot(yp, xp);
        double initial = Math.atan2(yp, xp);
        double bot = 0;
        double timeTot = (2 * PI * R) / vp;
        double top = 100000000000000.0;
        while (cmp(top, bot) == 1) {
            double mid = (top + bot) / 2;
            double angle = ((2 * PI * mid) / timeTot) + initial;
            Point loc = new Point(Math.cos(angle) * R, Math.sin(angle) * R);
            if (pode(loc, mid) == 1) {
                top = mid;
            } else {
                bot = mid;
            }
        }
        System.out.printf("%.7f\n", bot);
    }
}

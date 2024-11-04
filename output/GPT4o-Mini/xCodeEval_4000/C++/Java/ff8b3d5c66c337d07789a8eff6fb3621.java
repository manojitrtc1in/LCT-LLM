import java.util.*;
import java.io.*;

public class ff8b3d5c66c337d07789a8eff6fb3621_nc {
    static final double EPS = 1e-8;
    static final double INF = 10000000;

    static int cmp(double x, double y) {
        return (x <= y + EPS) ? (x + EPS < y) ? -1 : 0 : 1;
    }

    static class Point {
        double x, y;

        Point(double x, double y) {
            this.x = x;
            this.y = y;
        }

        Point() {
            this(0, 0);
        }

        Point add(Point q) {
            return new Point(this.x + q.x, this.y + q.y);
        }

        Point sub(Point q) {
            return new Point(this.x - q.x, this.y - q.y);
        }

        Point mul(double t) {
            return new Point(this.x * t, this.y * t);
        }

        Point div(double t) {
            return new Point(this.x / t, this.y / t);
        }

        double dot(Point q) {
            return this.x * q.x + this.y * q.y;
        }

        double cross(Point q) {
            return this.x * q.y - this.y * q.x;
        }

        int cmp(Point q) {
            if (int t = cmp(this.x, q.x)) return t;
            return cmp(this.y, q.y);
        }

        boolean equals(Point q) {
            return cmp(q) == 0;
        }

        boolean notEquals(Point q) {
            return cmp(q) != 0;
        }

        boolean lessThan(Point q) {
            return cmp(q) < 0;
        }

        public String toString() {
            return "(" + x + ", " + y + ")";
        }
    }

    static double abs(Point p) {
        return Math.hypot(p.x, p.y);
    }

    static double arg(Point p) {
        return Math.atan2(p.y, p.x);
    }

    static int ccw(Point p, Point q, Point r) {
        return cmp((p.sub(r)).cross(q.sub(r)));
    }

    static double angle(Point p, Point q, Point r) {
        Point u = p.sub(q), v = r.sub(q);
        return Math.atan2(u.cross(v), u.dot(v));
    }

    static double dist2(Point p, Point q) {
        return (p.sub(q)).dot(p.sub(q));
    }

    static Point rotateCCW90(Point p) {
        return new Point(-p.y, p.x);
    }

    static Point rotateCW90(Point p) {
        return new Point(p.y, -p.x);
    }

    static Point projectPointLine(Point a, Point b, Point c) {
        return a.add(b.sub(a).mul((c.sub(a)).dot(b.sub(a)) / (b.sub(a).dot(b.sub(a)))));
    }

    static Point projectPointSegment(Point a, Point b, Point c) {
        double r = (b.sub(a)).dot(b.sub(a));
        if (Math.abs(r) < EPS) return a;
        r = (c.sub(a)).dot(b.sub(a)) / r;
        if (r < 0) return a;
        if (r > 1) return b;
        return a.add(b.sub(a).mul(r));
    }

    static boolean between(Point p, Point q, Point r) {
        return ccw(p, q, r) == 0 && cmp((p.sub(q)).cross(r.sub(q))) <= 0;
    }

    static double distancePointSegment(Point a, Point b, Point c) {
        return Math.sqrt(dist2(c, projectPointSegment(a, b, c)));
    }

    static double distancePointPlane(double x, double y, double z, double a, double b, double c, double d) {
        return Math.abs(a * x + b * y + c * z - d) / Math.sqrt(a * a + b * b + c * c);
    }

    static boolean linesParallel(Point a, Point b, Point c, Point d) {
        return Math.abs((b.sub(a)).cross(c.sub(d))) < EPS;
    }

    static boolean linesCollinear(Point a, Point b, Point c, Point d) {
        return linesParallel(a, b, c, d) && Math.abs((a.sub(b)).cross(a.sub(c))) < EPS && Math.abs((c.sub(d)).cross(c.sub(a))) < EPS;
    }

    static boolean segIntersect(Point p, Point q, Point r, Point s) {
        Point A = q.sub(p), B = s.sub(r), C = r.sub(p), D = s.sub(q);
        int a = cmp(A.cross(C)) + 2 * cmp(A.cross(D));
        int b = cmp(B.cross(C)) + 2 * cmp(B.cross(D));
        if (a == 3 || a == -3 || b == 3 || b == -3) return false;
        if (a != 0 || b != 0 || p.equals(r) || p.equals(s) || q.equals(r) || q.equals(s)) return true;
        int t = (p.lessThan(r) ? 1 : 0) + (p.lessThan(s) ? 1 : 0) + (q.lessThan(r) ? 1 : 0) + (q.lessThan(s) ? 1 : 0);
        return t != 0 && t != 4;
    }

    static Point lineIntersect(Point p, Point q, Point r, Point s) {
        Point a = q.sub(p), b = s.sub(r), c = new Point(p.cross(q), r.cross(s));
        return new Point(new Point(a.x, b.x).cross(c), new Point(a.y, b.y).cross(c)).div(a.cross(b));
    }

    static boolean circle2PtsRad(Point p1, Point p2, double r, Point[] c) {
        double d2 = (p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y);
        double det = (r * r / d2) - 0.25;
        if (det < 0.0) return false;
        double h = Math.sqrt(det);
        c[0] = new Point((p1.x + p2.x) * 0.5 + (p1.y - p2.y) * h, (p1.y + p2.y) * 0.5 + (p2.x - p1.x) * h);
        return true;
    }

    static Point computeCircleCenter(Point a, Point b, Point c) {
        b = a.add(b).div(2);
        c = a.add(c).div(2);
        return lineIntersect(b, b.add(rotateCW90(a.sub(b))), c, c.add(rotateCW90(a.sub(c))));
    }

    static Point computeCircleIncenter(Point a, Point b, Point c) {
        Point d = b.add(rotateCCW(c.sub(b), angle(c, b, a) / 2));
        Point e = c.add(rotateCCW(a.sub(c), angle(a, c, b) / 2));
        return lineIntersect(b, d, c, e);
    }

    static List<Point> circleLineIntersection(Point a, Point b, Point c, double r) {
        List<Point> ret = new ArrayList<>();
        b = b.sub(a);
        a = a.sub(c);
        double A = b.dot(b);
        double B = a.dot(b);
        double C = (a.dot(a)) - r * r;
        double D = B * B - A * C;
        if (D < -EPS) return ret;
        ret.add(c.add(a.add(b.mul((-B + Math.sqrt(D + EPS)) / A)));
        if (D > EPS)
            ret.add(c.add(a.add(b.mul((-B - Math.sqrt(D)) / A)));
        return ret;
    }

    static List<Point> circleCircleIntersection(Point a, Point b, double r, double R) {
        List<Point> ret = new ArrayList<>();
        double d = Math.sqrt(dist2(a, b));
        if (d > r + R || d + Math.min(r, R) < Math.max(r, R)) return ret;
        double x = (d * d - R * R + r * r) / (2 * d);
        double y = Math.sqrt(r * r - x * x);
        Point v = (b.sub(a)).div(d);
        ret.add(a.add(v.mul(x)).add(rotateCCW90(v).mul(y)));
        if (y > 0)
            ret.add(a.add(v.mul(x)).sub(rotateCCW90(v).mul(y)));
        return ret;
    }

    static List<Point> tangentSegments(Point c, double r, Point p) {
        List<Point> resp = new ArrayList<>();
        Point toCenter = c.sub(p);
        if (cmp(r - Math.sqrt(dist2(toCenter, new Point(0, 0)))) <= 0) {
            resp.add(p);
            resp.add(p);
            return resp;
        }
        double angle = Math.asin(r / Math.sqrt(dist2(toCenter, new Point(0, 0))));
        Point uni = toCenter.div(Math.sqrt(dist2(toCenter, new Point(0, 0))));
        double tam = Math.sqrt(dist2(toCenter, new Point(0, 0)) - r * r);
        Point origi = uni.mul(tam);
        Point p1 = p.add(rotateCCW(origi, angle));
        resp.add(p1);
        Point p2 = p.add(rotateCCW(origi, -angle));
        resp.add(p2);
        return resp;
    }

    static int inPoly(Point p, List<Point> T) {
        double a = 0;
        int N = T.size();
        for (int i = 0; i < N; i++) {
            if (between(T.get(i), p, T.get((i + 1) % N))) return -1;
            a += angle(T.get(i), p, T.get((i + 1) % N));
        }
        return cmp(a) != 0 ? 1 : 0;
    }

    static double polyArea(List<Point> T) {
        double s = 0;
        int n = T.size();
        for (int i = 0; i < n; i++)
            s += T.get(i).cross(T.get((i + 1) % n));
        return s / 2;
    }

    static Point computeCentroid(List<Point> p) {
        Point c = new Point(0, 0);
        double scale = 6.0 * polyArea(p);
        for (int i = 0; i < p.size(); i++) {
            int j = (i + 1) % p.size();
            c = c.add(p.get(i).add(p.get(j)).mul(p.get(i).x * p.get(j).y - p.get(j).x * p.get(i).y));
        }
        return c.div(scale);
    }

    static boolean radialLt(Point p, Point q, Point pivot) {
        Point P = p.sub(pivot), Q = q.sub(pivot);
        double R = P.cross(Q);
        if (cmp(R) != 0) return R > 0;
        return cmp(P.dot(P), Q.dot(Q)) < 0;
    }

    static List<Point> convexHull(List<Point> T) {
        int j = 0, k, n = T.size();
        List<Point> U = new ArrayList<>(n);
        Point pivot = Collections.min(T, Comparator.comparingDouble(p -> p.y));
        Collections.sort(T, (p1, p2) -> radialLt(p1, p2, pivot) ? -1 : 1);
        for (k = n - 2; k >= 0 && ccw(T.get(0), T.get(n - 1), T.get(k)) == 0; k--);
        Collections.reverse(T.subList(k + 1, n));
        for (int i = 0; i < n; i++) {
            while (j > 1 && ccw(U.get(j - 1), U.get(j - 2), T.get(i)) >= 0) j--;
            U.add(T.get(i));
            j++;
        }
        U = U.subList(0, j);
        return U;
    }

    static List<Point> polyIntersect(List<Point> P, List<Point> Q) {
        int m = Q.size(), n = P.size();
        int a = 0, b = 0, aa = 0, ba = 0, inflag = 0;
        List<Point> R = new ArrayList<>();
        while ((aa < n || ba < m) && aa < 2 * n && ba < 2 * m) {
            Point p1 = P.get(a), p2 = P.get((a + 1) % n), q1 = Q.get(b), q2 = Q.get((b + 1) % m);
            Point A = p2.sub(p1), B = q2.sub(q1);
            int cross = cmp(A.cross(B)), ha = ccw(p2, q2, p1), hb = ccw(q2, p2, q1);
            if (cross == 0 && ccw(p1, q1, p2) == 0 && cmp(A.dot(B)) < 0) {
                if (between(p1, q1, p2)) R.add(q1);
                if (between(p1, q2, p2)) R.add(q2);
                if (between(q1, p1, q2)) R.add(p1);
                if (between(q1, p2, q2)) R.add(p2);
                if (R.size() < 2) return new ArrayList<>();
                inflag = 1;
                break;
            } else if (cross != 0 && segIntersect(p1, p2, q1, q2)) {
                if (inflag == 0) aa = ba = 0;
                R.add(lineIntersect(p1, p2, q1, q2));
                inflag = (hb > 0) ? 1 : -1;
            }
            if (cross == 0 && hb < 0 && ha < 0) return R;
            boolean t = cross == 0 && hb == 0 && ha == 0;
            if (t ? (inflag == 1) : (cross >= 0) ? (ha <= 0) : (hb > 0)) {
                if (inflag == -1) R.add(q2);
                ba++;
                b++;
                b %= m;
            } else {
                if (inflag == 1) R.add(p2);
                aa++;
                a++;
                a %= n;
            }
        }
        if (inflag == 0) {
            if (inPoly(P.get(0), Q) == 1) return P;
            if (inPoly(Q.get(0), P) == 1) return Q;
        }
        R = new ArrayList<>(new HashSet<>(R));
        if (R.size() > 1 && R.get(0).equals(R.get(R.size() - 1))) R.remove(R.size() - 1);
        return R;
    }

    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(System.in);
        int xp = sc.nextInt(), yp = sc.nextInt(), vp = sc.nextInt(), x = sc.nextInt(), y = sc.nextInt(), v = sc.nextInt(), r = sc.nextInt();
        int cont = 1000000;
        double R = Math.hypot(yp, xp);
        double initial = Math.atan2(yp, xp);
        double bot = 0;
        double timeTot = 1000000.0;
        double t1 = (2 * Math.PI * R) / vp;

        double top = timeTot;
        while (top - bot > EPS) {
            double mid = (top + bot) / 2;

            double angle = ((2 * Math.PI * mid) / t1) + initial;
            Point loc = new Point(Math.cos(angle) * R, Math.sin(angle) * R);

            if (pode(loc, mid, x, y, r, v)) {
                top = mid - EPS;
            } else {
                bot = mid + EPS;
            }
        }
        System.out.printf("%.7f\n", bot);
    }

    static boolean pode(Point loc, double time, int x, int y, int r, int v) {
        Point nave = new Point(x, y);
        if (cmp(distancePointSegment(loc, nave, new Point(0, 0)), r) >= 0) {
            return cmp(time, abs(nave.sub(loc)) / v) >= 0;
        } else {
            double distN = Math.sqrt(dist2(nave, new Point(0, 0)) - r * r);
            double distL = Math.sqrt(dist2(loc, new Point(0, 0)) - r * r);
            double angNOL = Math.abs(angle(nave, new Point(0, 0), loc)) - Math.abs(Math.atan(distN / r)) - Math.abs(Math.atan(distL / r));
            double menor = distN + distL + Math.abs(r * angNOL);

            return cmp(time, menor / v) >= 0;
        }
    }
}

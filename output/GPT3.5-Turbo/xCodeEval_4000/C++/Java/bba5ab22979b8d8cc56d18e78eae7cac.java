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
            this(0, 0);
        }
        Point add(Point q) {
            return new Point(x + q.x, y + q.y);
        }
        Point subtract(Point q) {
            return new Point(x - q.x, y - q.y);
        }
        Point multiply(double t) {
            return new Point(x * t, y * t);
        }
        Point divide(double t) {
            return new Point(x / t, y / t);
        }
        double dot(Point q) {
            return x * q.x + y * q.y;
        }
        double cross(Point q) {
            return x * q.y - y * q.x;
        }
        int compare(Point q) {
            int t = Double.compare(x, q.x);
            if (t != 0) return t;
            return Double.compare(y, q.y);
        }
        boolean equals(Point q) {
            return compare(q) == 0;
        }
        boolean notEquals(Point q) {
            return compare(q) != 0;
        }
        boolean lessThan(Point q) {
            return compare(q) < 0;
        }
        @Override
        public String toString() {
            return "(" + x + ", " + y + ")";
        }
    }

    static class Polygon extends ArrayList<Point> {}

    static final double EPS = 1e-8;

    static int compare(double x, double y, double tol) {
        return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
    }

    static int ccw(Point p, Point q, Point r) {
        return compare((p.subtract(r)).cross(q.subtract(r)), 0, EPS);
    }

    static double angle(Point p, Point q, Point r) {
        Point u = p.subtract(q), v = r.subtract(q);
        return Math.atan2(u.cross(v), u.dot(v));
    }

    static double dist2(Point p, Point q) {
        Point diff = p.subtract(q);
        return diff.dot(diff);
    }

    static Point rotateCCW90(Point p) {
        return new Point(-p.y, p.x);
    }

    static Point rotateCW90(Point p) {
        return new Point(p.y, -p.x);
    }

    static Point rotateCCW(Point p, double t) {
        return new Point(p.x * Math.cos(t) - p.y * Math.sin(t), p.x * Math.sin(t) + p.y * Math.cos(t));
    }

    static Point projectPointLine(Point a, Point b, Point c) {
        return a.add(b.subtract(a).multiply(c.subtract(a).dot(b.subtract(a)) / b.subtract(a).dot(b.subtract(a))));
    }

    static Point projectPointSegment(Point a, Point b, Point c) {
        double r = b.subtract(a).dot(b.subtract(a));
        if (Math.abs(r) < EPS) return a;
        r = c.subtract(a).dot(b.subtract(a)) / r;
        if (r < 0) return a;
        if (r > 1) return b;
        return a.add(b.subtract(a).multiply(r));
    }

    static boolean between(Point p, Point q, Point r) {
        return ccw(p, q, r) == 0 && compare((p.subtract(q)).cross(r.subtract(q)), 0, EPS) <= 0;
    }

    static double distancePointSegment(Point a, Point b, Point c) {
        return Math.sqrt(dist2(c, projectPointSegment(a, b, c)));
    }

    static double distancePointPlane(double x, double y, double z, double a, double b, double c, double d) {
        return Math.abs(a * x + b * y + c * z - d) / Math.sqrt(a * a + b * b + c * c);
    }

    static boolean linesParallel(Point a, Point b, Point c, Point d) {
        return Math.abs((b.subtract(a)).cross(c.subtract(d))) < EPS;
    }

    static boolean linesCollinear(Point a, Point b, Point c, Point d) {
        return linesParallel(a, b, c, d) && Math.abs((a.subtract(b)).cross(a.subtract(c))) < EPS && Math.abs((c.subtract(d)).cross(c.subtract(a))) < EPS;
    }

    static boolean segIntersect(Point p, Point q, Point r, Point s) {
        Point A = q.subtract(p), B = s.subtract(r), C = r.subtract(p), D = s.subtract(q);
        int a = compare(A.cross(C)) + 2 * compare(A.cross(D));
        int b = compare(B.cross(C)) + 2 * compare(B.cross(D));
        if (a == 3 || a == -3 || b == 3 || b == -3) return false;
        if (a != 0 || b != 0 || p.equals(r) || p.equals(s) || q.equals(r) || q.equals(s)) return true;
        int t = (p.lessThan(r) ? 1 : 0) + (p.lessThan(s) ? 1 : 0) + (q.lessThan(r) ? 1 : 0) + (q.lessThan(s) ? 1 : 0);
        return t != 0 && t != 4;
    }

    static Point lineIntersect(Point p, Point q, Point r, Point s) {
        Point a = q.subtract(p), b = s.subtract(r), c = new Point(p.cross(q), r.cross(s));
        return new Point(new Point(a.x, b.x).cross(c), new Point(a.y, b.y).cross(c)).divide(a.cross(b));
    }

    static boolean circle2PtsRad(Point p1, Point p2, double r, Point c) {
        double d2 = (p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y);
        double det = ((r * r) / d2) - 0.25;
        if (det < 0.0) return false;
        double h = Math.sqrt(det);
        c.x = (p1.x + p2.x) * 0.5 + (p1.y - p2.y) * h;
        c.y = (p1.y + p2.y) * 0.5 + (p2.x - p1.x) * h;
        return true;
    }

    static Point computeCircleCenter(Point a, Point b, Point c) {
        b = a.add(b).divide(2);
        c = a.add(c).divide(2);
        return lineIntersect(b, b.add(rotateCW90(a.subtract(b))), c, c.add(rotateCW90(a.subtract(c))));
    }

    static Point computeCircleIncenter(Point a, Point b, Point c) {
        Point d = b.add(rotateCCW(c.subtract(b), angle(c, b, a) / 2));
        Point e = c.add(rotateCCW(a.subtract(c), angle(a, c, b) / 2));
        return lineIntersect(b, d, c, e);
    }

    static List<Point> circleLineIntersection(Point a, Point b, Point c, double r) {
        List<Point> ret = new ArrayList<>();
        b = b.subtract(a);
        a = a.subtract(c);
        double A = b.dot(b);
        double B = a.dot(b);
        double C = a.dot(a) - r * r;
        double D = B * B - A * C;
        if (D < -EPS) return ret;
        ret.add(c.add(a.add(b.multiply(-B + Math.sqrt(D + EPS))).divide(A)));
        if (D > EPS) ret.add(c.add(a.add(b.multiply(-B - Math.sqrt(D))).divide(A)));
        return ret;
    }

    static List<Point> circleCircleIntersection(Point a, Point b, double r, double R) {
        List<Point> ret = new ArrayList<>();
        double d = Math.sqrt(dist2(a, b));
        if (d > r + R || d + Math.min(r, R) < Math.max(r, R)) return ret;
        double x = (d * d - R * R + r * r) / (2 * d);
        double y = Math.sqrt(r * r - x * x);
        Point v = b.subtract(a).divide(d);
        ret.add(a.add(v.multiply(x).add(rotateCCW90(v).multiply(y))));
        if (y > 0) ret.add(a.add(v.multiply(x).subtract(rotateCCW90(v).multiply(y))));
        return ret;
    }

    static List<Point> tangentSegments(Point c, double r, Point p) {
        List<Point> resp = new ArrayList<>();
        Point toCenter = c.subtract(p);
        if (compare(r - Math.sqrt(dist2(toCenter, new Point())), 0, EPS) <= 0) {
            resp.add(p);
            resp.add(p);
            return resp;
        }
        double angle = Math.asin(r / Math.sqrt(dist2(toCenter, new Point())));
        Point uni = toCenter.divide(Math.sqrt(dist2(toCenter, new Point())));
        double tam = Math.sqrt(dist2(toCenter, new Point()) - r * r);
        Point origi = uni.multiply(tam);
        Point p1 = p.add(rotateCCW(origi, angle));
        resp.add(p1);
        Point p2 = p.add(rotateCCW(origi, -angle));
        resp.add(p2);
        return resp;
    }

    static int inPoly(Point p, Polygon T) {
        double a = 0;
        int N = T.size();
        for (int i = 0; i < N; i++) {
            if (between(T.get(i), p, T.get((i + 1) % N))) return -1;
            a += angle(T.get(i), p, T.get((i + 1) % N));
        }
        return compare(a, 0, EPS) != 0 ? 1 : 0;
    }

    static double polyArea(Polygon T) {
        double s = 0;
        int n = T.size();
        for (int i = 0; i < n; i++) {
            s += T.get(i).cross(T.get((i + 1) % n));
        }
        return s / 2;
    }

    static Point computeCentroid(List<Point> p) {
        Point c = new Point();
        double scale = 6.0 * polyArea((Polygon) p);
        for (int i = 0; i < p.size(); i++) {
            int j = (i + 1) % p.size();
            c = c.add(p.get(i).add(p.get(j)).multiply(p.get(i).x * p.get(j).y - p.get(j).x * p.get(i).y));
        }
        return c.divide(scale);
    }

    static boolean radialLt(Point p, Point q) {
        Point P = p.subtract(Point.pivot), Q = q.subtract(Point.pivot);
        double R = P.cross(Q);
        if (compare(R, 0, EPS) != 0) return R > 0;
        return compare(P.dot(P), Q.dot(Q), EPS) < 0;
    }

    static Polygon convexHull(List<Point> T) {
        int j = 0, k, n = T.size();
        Polygon U = new Polygon();
        Point.pivot = Collections.min(T, (a, b) -> a.compare(b));
        Collections.sort(T, (a, b) -> radialLt(a, b) ? -1 : 1);
        for (k = n - 2; k >= 0 && ccw(T.get(0), T.get(n - 1), T.get(k)) == 0; k--);
        Collections.reverse(T.subList(k + 1, n));
        for (int i = 0; i < n; i++) {
            while (j > 1 && ccw(U.get(j - 1), U.get(j - 2), T.get(i)) >= 0) j--;
            U.add(T.get(i));
            j++;
        }
        U.subList(j, U.size()).clear();
        return U;
    }

    static Polygon polyIntersect(Polygon P, Polygon Q) {
        int m = Q.size(), n = P.size();
        int a = 0, b = 0, aa = 0, ba = 0, inflag = 0;
        Polygon R = new Polygon();
        while ((aa < n || ba < m) && aa < 2 * n && ba < 2 * m) {
            Point p1 = P.get(a), p2 = P.get((a + 1) % n), q1 = Q.get(b), q2 = Q.get((b + 1) % m);
            Point A = p2.subtract(p1), B = q2.subtract(q1);
            int cross = compare(A.cross(B), 0, EPS);
            int ha = ccw(p2, q2, p1), hb = ccw(q2, p2, q1);
            if (cross == 0 && ccw(p1, q1, p2) == 0 && compare(A.dot(B), 0, EPS) < 0) {
                if (between(p1, q1, p2)) R.add(q1);
                if (between(p1, q2, p2)) R.add(q2);
                if (between(q1, p1, q2)) R.add(p1);
                if (between(q1, p2, q2)) R.add(p2);
                if (R.size() < 2) return new Polygon();
                inflag = 1;
                break;
            } else if (cross != 0 && segIntersect(p1, p2, q1, q2)) {
                if (inflag == 0) aa = ba = 0;
                R.add(lineIntersect(p1, p2, q1, q2));
                inflag = hb > 0 ? 1 : -1;
            }
            if (cross == 0 && hb < 0 && ha < 0) return R;
            boolean t = cross == 0 && hb == 0 && ha == 0;
            if (t ? inflag == 1 : cross >= 0 ? ha <= 0 : hb > 0) {
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
            if (inPoly(P.get(0), Q) != 0) return P;
            if (inPoly(Q.get(0), P) != 0) return Q;
        }
        R = new Polygon(new HashSet<>(R));
        if (R.size() > 1 && R.get(0).equals(R.get(R.size() - 1))) R.remove(R.size() - 1);
        return R;
    }

    static final double PI = Math.acos(-1);

    static int xp, yp, vp, x, y, v, r;

    static Point origin = new Point(0, 0);

    static boolean pode(Point loc, double time) {
        Point nave = new Point(x, y);
        if (compare(distancePointSegment(loc, nave, origin), r, EPS) >= 0) {
            return compare(time, Math.abs(nave.subtract(loc).length()) / v, EPS) >= 0;
        } else {
            double distN = Math.sqrt(dist2(nave, origin) - r * r);
            double distL = Math.sqrt(dist2(loc, origin) - r * r);
            double a = Math.abs(nave.subtract(loc).length());
            double b = Math.abs(nave.length());
            double c = Math.abs(loc.length());
            double bigcos = (b * b + c * c - a * a) / (2 * b * c);
            double angNOL = Math.acos(bigcos) - Math.abs(Math.atan(distN / r)) - Math.abs(Math.atan(distL / r));
            double menor = distN + distL + Math.abs(r * angNOL);
            return compare(time, menor / v, EPS) >= 0;
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
        while (compare(top, bot, EPS) == 1) {
            double mid = (top + bot) / 2;
            double angle = ((2 * PI * mid) / timeTot) + initial;
            Point loc = new Point(Math.cos(angle) * R, Math.sin(angle) * R);
            if (pode(loc, mid)) {
                top = mid;
            } else {
                bot = mid;
            }
        }
        System.out.printf("%.7f\n", bot);
    }
}

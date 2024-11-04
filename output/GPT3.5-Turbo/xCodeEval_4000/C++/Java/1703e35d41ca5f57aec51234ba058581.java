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
    }

    static class Line {
        Point p, q;

        Line(Point p, Point q) {
            this.p = p;
            this.q = q;
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

    static final double EPS = 1e-5;
    static final double OO = 1e9;

    static double cross(Point a, Point b) {
        return a.x * b.y - a.y * b.x;
    }

    static double dot(Point a, Point b) {
        return a.x * b.x + a.y * b.y;
    }

    static double length(Point v) {
        return Math.sqrt(v.x * v.x + v.y * v.y);
    }

    static double lengthSqr(Point v) {
        return v.x * v.x + v.y * v.y;
    }

    static Point vec(Point a, Point b) {
        return new Point(b.x - a.x, b.y - a.y);
    }

    static Point rotate(Point v, double t) {
        double x = v.x * Math.cos(t) - v.y * Math.sin(t);
        double y = v.x * Math.sin(t) + v.y * Math.cos(t);
        return new Point(x, y);
    }

    static Point intersect(Point a, Point b, Point p, Point q) {
        double d1 = cross(vec(p, a), vec(b, a));
        double d2 = cross(vec(q, a), vec(b, a));
        double x = (d1 * q.x - d2 * p.x) / (d1 - d2);
        double y = (d1 * q.y - d2 * p.y) / (d1 - d2);
        return new Point(x, y);
    }

    static boolean pointOnLine(Point a, Point b, Point p) {
        return Math.abs(cross(vec(a, b), vec(a, p))) < EPS;
    }

    static boolean pointOnRay(Point a, Point b, Point p) {
        return dot(vec(a, p), vec(a, b)) > -EPS;
    }

    static boolean pointOnSegment(Point a, Point b, Point p) {
        if (!collinear(a, b, p))
            return false;
        return pointOnRay(a, b, p) && pointOnRay(b, a, p);
    }

    static double pointLineDist(Point a, Point b, Point p) {
        return Math.abs(cross(vec(a, b), vec(a, p)) / length(vec(a, b)));
    }

    static double pointSegmentDist(Point a, Point b, Point p) {
        if (dot(vec(a, b), vec(a, p)) < EPS)
            return length(vec(a, p));
        if (dot(vec(b, a), vec(b, p)) < EPS)
            return length(vec(b, p));
        return pointLineDist(a, b, p);
    }

    static boolean collinear(Point a, Point b, Point p) {
        return Math.abs(cross(vec(a, b), vec(a, p))) < EPS;
    }

    static int gcd(int a, int b) {
        return b == 0 ? a : gcd(b, a % b);
    }

    static int segmentLatticePointsCount(int x1, int y1, int x2, int y2) {
        return Math.abs(gcd(x1 - x2, y1 - y2)) + 1;
    }

    static double triangleAreaBH(double b, double h) {
        return b * h / 2;
    }

    static double triangleArea2sidesAngle(double a, double b, double t) {
        return Math.abs(a * b * Math.sin(t) / 2);
    }

    static double triangleArea2anglesSide(double t1, double t2, double s) {
        return Math.abs(s * s * Math.sin(t1) * Math.sin(t2) / (2 * Math.sin(t1 + t2)));
    }

    static double triangleArea3sides(double a, double b, double c) {
        double s = (a + b + c) / 2;
        return Math.sqrt(s * (s - a) * (s - b) * (s - c));
    }

    static double triangleArea3points(Point a, Point b, Point c) {
        return Math.abs(cross(a, b) + cross(b, c) + cross(c, a)) / 2;
    }

    static int picksTheorem(int a, int b) {
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

    static double sinRuleAngle(double s1, double s2, double a1) {
        double res = s2 * Math.sin(a1) / s1;
        if (Math.abs(res - 1) < EPS)
            res = 1;
        if (Math.abs(res + 1) < EPS)
            res = -1;
        return Math.asin(res);
    }

    static double sinRuleSide(double s1, double a1, double a2) {
        return s1 * Math.sin(a2) / Math.sin(a1);
    }

    static int circleLineIntersection(Point p0, Point p1, Point cen, double rad, Point[] res) {
        double a, b, c, t1, t2;
        a = dot(vec(p1, p0), vec(p1, p0));
        b = 2 * dot(vec(p1, p0), vec(p0, cen));
        c = dot(vec(p0, cen), vec(p0, cen)) - rad * rad;
        double det = b * b - 4 * a * c;
        int cnt = 0;
        if (Math.abs(det) < EPS)
            det = 0;
        else if (det < 0)
            cnt = 0;
        else
            cnt = 2;
        det = Math.sqrt(det);
        t1 = (-b + det) / (2 * a);
        t2 = (-b - det) / (2 * a);
        res[0] = new Point(p0.x + t1 * (p1.x - p0.x), p0.y + t1 * (p1.y - p0.y));
        res[1] = new Point(p0.x + t2 * (p1.x - p0.x), p0.y + t2 * (p1.y - p0.y));
        return cnt;
    }

    static int circleCircleIntersection(Point c1, double r1, Point c2, double r2, Point[] res) {
        if (same(c1, c2) && Math.abs(r1 - r2) < EPS) {
            res[0] = res[1] = c1;
            return Math.abs(r1) < EPS ? 1 : (int) OO;
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
            res[0] = new Point(d.x * r / len + c.x, d.y * r / len + c.y);
            return 1;
        }
        if (len > r1 + r2 || len < Math.abs(r1 - r2))
            return 0;
        double a = cosRule(r2, r1, len);
        Point c1c2 = new Point(c1.x + (c2.x - c1.x) * r1 / len, c1.y + (c2.y - c1.y) * r1 / len);
        res[0] = rotate(c1c2, a);
        res[1] = rotate(c1c2, -a);
        return 2;
    }

    static void circle2(Point p1, Point p2, Point[] cen, double[] r) {
        cen[0] = new Point((p1.x + p2.x) / 2, (p1.y + p2.y) / 2);
        r[0] = length(vec(p1, p2)) / 2;
    }

    static boolean circle3(Point p1, Point p2, Point p3, Point[] cen, double[] r) {
        Point m1 = new Point((p1.x + p2.x) / 2, (p1.y + p2.y) / 2);
        Point m2 = new Point((p2.x + p3.x) / 2, (p2.y + p3.y) / 2);
        Point perp1 = new Point(-(p1.y - p2.y), p1.x - p2.x);
        Point perp2 = new Point(-(p2.y - p3.y), p2.x - p3.x);
        boolean res = intersect(m1, new Point(m1.x + perp1.x, m1.y + perp1.y), m2,
                new Point(m2.x + perp2.x, m2.y + perp2.y), cen[0]);
        r[0] = length(vec(cen[0], p1));
        return res;
    }

    static enum STATE {
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

    static int tangentPoints(Point cen, double r, Point p, Point[] r1, Point[] r2) {
        STATE s = circlePoint(cen, r, p);
        if (s != STATE.OUT) {
            r1[0] = r2[0] = p;
            return s == STATE.BOUNDRY ? 1 : 0;
        }
        Point cp = vec(cen, p);
        double h = length(cp);
        double a = Math.acos(r / h);
        cp = new Point(cp.x * r / h, cp.y * r / h);
        r1[0] = rotate(cp, a);
        r2[0] = rotate(cp, -a);
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

    static Point polygonCentroid(ArrayList<Point> polygon) {
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

    static int picksTheorem(ArrayList<Point> p) {
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

    static void convexPolygonIntersect(ArrayList<Point> p, ArrayList<Point> q, ArrayList<Point> res) {
        res.clear();
        res.addAll(q);
        for (int i = 0; i < p.size(); i++) {
            int j = (i + 1) % p.size();
            ArrayList<Point> temp = new ArrayList<>(res);
            polygonCut(temp, p.get(i), p.get(j), res);
            if (res.isEmpty())
                return;
        }
    }

    static void voronoi(ArrayList<Point> pnts, ArrayList<Point> rect, ArrayList<ArrayList<Point>> res) {
        res.clear();
        for (int i = 0; i < pnts.size(); i++) {
            res.add(new ArrayList<>(rect));
            for (int j = 0; j < pnts.size(); j++) {
                if (j == i)
                    continue;
                Point p = perp(vec(pnts.get(i), pnts.get(j)));
                Point m = new Point((pnts.get(i).x + pnts.get(j).x) / 2, (pnts.get(i).y + pnts.get(j).y) / 2);
                ArrayList<Point> temp = new ArrayList<>(res.get(res.size() - 1));
                polygonCut(temp, m, new Point(m.x + p.x, m.y + p.y), res.get(res.size() - 1));
                res.set(res.size() - 1, temp);
            }
        }
    }

    static STATE pointInPolygon(ArrayList<Point> p, Point pnt) {
        Point p2 = new Point(pnt.x + 1, pnt.y);
        int cnt = 0;
        for (int i = 0; i < p.size(); i++) {
            int j = (i + 1) % p.size();
            if (pointOnSegment(p.get(i), p.get(j), pnt))
                return STATE.BOUNDRY;
            Point r = intersect(pnt, p2, p.get(i), p.get(j));
            if (!pointOnRay(pnt, p2, r))
                continue;
            if (same(r, p.get(i)) || same(r, p.get(j)))
                if (Math.abs(r.y - Math.min(p.get(i).y, p.get(j).y)) < EPS)
                    continue;
            if (!pointOnSegment(p.get(i), p.get(j), r))
                continue;
            cnt++;
        }
        return (cnt & 1) == 1 ? STATE.IN : STATE.OUT;
    }

    static boolean same(Point a, Point b) {
        return Math.abs(a.x - b.x) < EPS && Math.abs(a.y - b.y) < EPS;
    }

    static Point perp(Point a) {
        return new Point(-a.y, a.x);
    }

    static void sortAntiClockWise(ArrayList<Point> pnts) {
        Point mn = new Point(1 / 0.0, 1 / 0.0);
        for (int i = 0; i < pnts.size(); i++)
            if (pnts.get(i).y < mn.y || (pnts.get(i).y == mn.y && pnts.get(i).x < mn.x))
                mn = pnts.get(i);

        Collections.sort(pnts, new Comparator<Point>() {
            @Override
            public int compare(Point p, Point q) {
                double cr = cross(vec(mn, p), vec(mn, q));
                if (Math.abs(cr) < EPS)
                    return new Point(p.y, p.x).compareTo(new Point(q.y, q.x));
                return cr > 0 ? -1 : 1;
            }
        });
    }

    static void convexHull(ArrayList<Point> pnts, ArrayList<Point> convex) {
        sortAntiClockWise(pnts);
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

    static double arc_length(Point a, Point b, double r) {
        double ang = Math.abs(angle(a) - angle(b));
        if (ang < 0) {
            ang += 2 * Math.PI;
        }
        if (ang > Math.PI) {
            ang = 2 * Math.PI - ang;
        }
        return ang * r;
    }

    static double angle(Point v) {
        return Math.atan2(v.y, v.x);
    }

    static Point normalize(Point p) {
        double len = length(p);
        return new Point(p.x / len, p.y / len);
    }

    static double angle(Point a, Point b) {
        return Math.acos(dot(a, b) / (length(a) * length(b)));
    }

    static double dot(Point a, Point b) {
        return a.x * b.x + a.y * b.y;
    }

    static double cosRule(double a, double b, double c) {
        double res = (b * b + c * c - a * a) / (2 * b * c);
        if (Math.abs(res - 1) < EPS)
            res = 1;
        if (Math.abs(res + 1) < EPS)
            res = -1;
        return Math.acos(res);
    }

    static Point perp(Point a, Point b) {
        return new Point(-(b.y - a.y), b.x - a.x);
    }

    static double length(Point a, Point b) {
        return Math.sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
    }

    static double lengthSqr(Point a, Point b) {
        return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
    }

    static boolean same(Point a, Point b) {
        return Math.abs(a.x - b.x) < EPS && Math.abs(a.y - b.y) < EPS;
    }

    static double angle(Point a) {
        return Math.atan2(a.y, a.x);
    }

    static double angle(Point a, Point b, Point c) {
        double ang = angle(vec(b, a)) - angle(vec(b, c));
        if (ang < 0) {
            ang += 2 * Math.PI;
        }
        if (ang > Math.PI) {
            ang = 2 * Math.PI - ang;
        }
        return ang;
    }

    static double angle(Point a, Point b, Point c, Point d) {
        double ang = angle(vec(b, a)) - angle(vec(d, c));
        if (ang < 0) {
            ang += 2 * Math.PI;
        }
        if (ang > Math.PI) {
            ang = 2 * Math.PI - ang;
        }
        return ang;
    }

    static double angle(Point a, Point b, Point c, Point d, Point e) {
        double ang = angle(vec(b, a)) - angle(vec(d, c)) + angle(vec(e, d));
        if (ang < 0) {
            ang += 2 * Math.PI;
        }
        if (ang > Math.PI) {
            ang = 2 * Math.PI - ang;
        }
        return ang;
    }

    static double angle(Point a, Point b, Point c, Point d, Point e, Point f) {
        double ang = angle(vec(b, a)) - angle(vec(d, c)) + angle(vec(f, e));
        if (ang < 0) {
            ang += 2 * Math.PI;
        }
        if (ang > Math.PI) {
            ang = 2 * Math.PI - ang;
        }
        return ang;
    }

    static double angle(Point a, Point b, Point c, Point d, Point e, Point f, Point g) {
        double ang = angle(vec(b, a)) - angle(vec(d, c)) + angle(vec(f, e)) - angle(vec(g, f));
        if (ang < 0) {
            ang += 2 * Math.PI;
        }
        if (ang > Math.PI) {
            ang = 2 * Math.PI - ang;
        }
        return ang;
    }

    static double angle(Point a, Point b, Point c, Point d, Point e, Point f, Point g, Point h) {
        double ang = angle(vec(b, a)) - angle(vec(d, c)) + angle(vec(f, e)) - angle(vec(h, g));
        if (ang < 0) {
            ang += 2 * Math.PI;
        }
        if (ang > Math.PI) {
            ang = 2 * Math.PI - ang;
        }
        return ang;
    }

    static double angle(Point a, Point b, Point c, Point d, Point e, Point f, Point g, Point h, Point i) {
        double ang = angle(vec(b, a)) - angle(vec(d, c)) + angle(vec(f, e)) - angle(vec(h, g)) + angle(vec(i, h));
        if (ang < 0) {
            ang += 2 * Math.PI;
        }
        if (ang > Math.PI) {
            ang = 2 * Math.PI - ang;
        }
        return ang;
    }

    static double angle(Point a, Point b, Point c, Point d, Point e, Point f, Point g, Point h, Point i, Point j) {
        double ang = angle(vec(b, a)) - angle(vec(d, c)) + angle(vec(f, e)) - angle(vec(h, g)) + angle(vec(j, i));
        if (ang < 0) {
            ang += 2 * Math.PI;
        }
        if (ang > Math.PI) {
            ang = 2 * Math.PI - ang;
        }
        return ang;
    }

    public static void main(String[] args) throws java.lang.Exception {
        Scanner sc = new Scanner(System.in);
        int Xc = sc.nextInt();
        int Yc = sc.nextInt();
        int Vc = sc.nextInt();
        int Xb = sc.nextInt();
        int Yb = sc.nextInt();
        int Vb = sc.nextInt();
        int r = sc.nextInt();
        Point planet = new Point(Xc, Yc);
        Point ship = new Point(Xb, Yb);
        double R = length(planet);
        double w = Vc / R;
        double left = 0, right = 1e30;
        for (int i = 0; i < 300; i++) {
            double mid = (right + left) / 2;
            Point new_planet = rotate(planet, w * mid);
            double distance;
            if (pointSegmentDist(ship, new_planet, new Point(0, 0)) < r) {
                Point[] a = new Point[2];
                Point[] b = new Point[2];
                tangentPoints(new Point(0, 0), r, ship, a, b);
                tangentPoints(new Point(0, 0), r, new_planet, a, b);
                distance = 1e30;
                distance = Math.min(distance, length(vec(ship, a[0])) + length(vec(b[0], new_planet))
                        + arc_length(a[0], b[0], r));

                distance = Math.min(distance, length(vec(ship, a[1])) + length(vec(b[0], new_planet))
                        + arc_length(a[1], b[0], r));

                distance = Math.min(distance, length(vec(ship, a[0])) + length(vec(b[1], new_planet))
                        + arc_length(a[0], b[1], r));

                distance = Math.min(distance, length(vec(ship, a[1])) + length(vec(b[1], new_planet))
                        + arc_length(a[1], b[1], r));
            } else {
                distance = length(vec(ship, new_planet));
            }

            if (distance / Vb < mid) {
                right = mid;
            } else {
                left = mid;
            }
        }
        System.out.printf("%.10f\n", left);
    }
}

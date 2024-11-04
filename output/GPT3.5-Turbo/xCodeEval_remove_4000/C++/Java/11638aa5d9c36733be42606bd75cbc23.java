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

        Point rotate(double theta) {
            double newX = x * Math.cos(theta) - y * Math.sin(theta);
            double newY = x * Math.sin(theta) + y * Math.cos(theta);
            return new Point(newX, newY);
        }

        double length() {
            return Math.sqrt(x * x + y * y);
        }

        Point subtract(Point p) {
            return new Point(x - p.x, y - p.y);
        }

        Point add(Point p) {
            return new Point(x + p.x, y + p.y);
        }

        Point multiply(double scalar) {
            return new Point(x * scalar, y * scalar);
        }

        double dot(Point p) {
            return x * p.x + y * p.y;
        }

        double cross(Point p) {
            return x * p.y - y * p.x;
        }
    }

    static class Line {
        Point p1, p2;

        Line(Point p1, Point p2) {
            this.p1 = p1;
            this.p2 = p2;
        }

        boolean intersects(Line line) {
            double d1 = line.p1.subtract(p1).cross(p2.subtract(p1));
            double d2 = line.p2.subtract(p1).cross(p2.subtract(p1));
            double d3 = p1.subtract(line.p1).cross(line.p2.subtract(line.p1));
            double d4 = p2.subtract(line.p1).cross(line.p2.subtract(line.p1));

            if (Math.abs(d1 - d2) > EPS && Math.abs(d3 - d4) > EPS) {
                return true;
            }

            if (Math.abs(d1) < EPS && onSegment(line.p1)) {
                return true;
            }

            if (Math.abs(d2) < EPS && onSegment(line.p2)) {
                return true;
            }

            if (Math.abs(d3) < EPS && line.onSegment(p1)) {
                return true;
            }

            if (Math.abs(d4) < EPS && line.onSegment(p2)) {
                return true;
            }

            return false;
        }

        boolean onSegment(Point p) {
            return p.x >= Math.min(p1.x, p2.x) && p.x <= Math.max(p1.x, p2.x) &&
                    p.y >= Math.min(p1.y, p2.y) && p.y <= Math.max(p1.y, p2.y);
        }
    }

    static class Circle {
        Point center;
        double radius;

        Circle(Point center, double radius) {
            this.center = center;
            this.radius = radius;
        }

        boolean contains(Point p) {
            double dist = center.subtract(p).length();
            return dist <= radius + EPS;
        }
    }

    static double polygonArea(List<Point> polygon) {
        double area = 0;
        for (int i = 0; i < polygon.size(); i++) {
            int j = (i + 1) % polygon.size();
            area += polygon.get(i).cross(polygon.get(j));
        }
        return Math.abs(area) / 2;
    }

    static Point centroid(List<Point> polygon) {
        double x = 0, y = 0;
        double a = 0;
        for (int i = 0; i < polygon.size(); i++) {
            int j = (i + 1) % polygon.size();
            double crossProduct = polygon.get(i).cross(polygon.get(j));
            x += (polygon.get(i).x + polygon.get(j).x) * crossProduct;
            y += (polygon.get(i).y + polygon.get(j).y) * crossProduct;
            a += crossProduct;
        }
        a *= 0.5;
        x /= 6 * a;
        y /= 6 * a;
        return new Point(x, y);
    }

    static int gcd(int a, int b) {
        return b == 0 ? a : gcd(b, a % b);
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
        return Math.abs(a.cross(b) + b.cross(c) + c.cross(a)) / 2;
    }

    static int id18(int a, int b) {
        return a - b / 2 + 1;
    }

    static double cosRule(double a, double b, double c) {
        double res = (b * b + c * c - a * a) / (2 * b * c);
        if (Math.abs(res - 1) < EPS) {
            res = 1;
        }
        if (Math.abs(res + 1) < EPS) {
            res = -1;
        }
        return Math.acos(res);
    }

    static double id26(double s1, double s2, double a1) {
        double res = s2 * Math.sin(a1) / s1;
        if (Math.abs(res - 1) < EPS) {
            res = 1;
        }
        if (Math.abs(res + 1) < EPS) {
            res = -1;
        }
        return Math.asin(res);
    }

    static double id0(double s1, double a1, double a2) {
        double res = s1 * Math.sin(a2) / Math.sin(a1);
        return Math.abs(res);
    }

    static int id13(Point p0, Point p1, Point cen, double rad, Point r1, Point r2) {
        double a, b, c, t1, t2;
        a = p1.subtract(p0).dot(p1.subtract(p0));
        b = 2 * p1.subtract(p0).dot(p0.subtract(cen));
        c = p0.subtract(cen).dot(p0.subtract(cen)) - rad * rad;
        double det = b * b - 4 * a * c;
        int res;
        if (Math.abs(det) < EPS) {
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
        r1 = p0.add(p1.subtract(p0).multiply(t1));
        r2 = p0.add(p1.subtract(p0).multiply(t2));
        return res;
    }

    static int id3(Point c1, double r1, Point c2, double r2, Point res1, Point res2) {
        if (c1.equals(c2) && Math.abs(r1 - r2) < EPS) {
            res1 = res2 = c1;
            return Math.abs(r1) < EPS ? 1 : Integer.MAX_VALUE;
        }
        double len = c1.subtract(c2).length();
        if (Math.abs(len - (r1 + r2)) < EPS || Math.abs(Math.abs(r1 - r2) - len) < EPS) {
            Point d, c;
            double r;
            if (r1 > r2) {
                d = c1.subtract(c2);
                c = c1;
                r = r1;
            } else {
                d = c2.subtract(c1);
                c = c2;
                r = r2;
            }
            res1 = res2 = d.multiply(r / d.length()).add(c);
            return 1;
        }
        if (len > r1 + r2 || len < Math.abs(r1 - r2)) {
            return 0;
        }
        double a = cosRule(r2, r1, len);
        Point id11 = c1.subtract(c2).multiply(r1 / len);
        res1 = id11.rotate(a).add(c1);
        res2 = id11.rotate(-a).add(c1);
        return 2;
    }

    static double calcArc(Point a, Point b, double r) {
        double theta = Math.abs(Math.atan2(b.y, b.x) - Math.atan2(a.y, a.x));
        if (theta > Math.PI) {
            theta = 2 * Math.PI - theta;
        }
        double res = theta * r;
        return res;
    }

    static double calcDis(Point a, Point c, double r) {
        double arc = calcArc(a, c, r);
        double res = arc + Math.abs(a.subtract(st).length()) + Math.abs(c.subtract(en).length());
        return res;
    }

    static double Calc(Point st, Point en, double r) {
        Point a, b, c, d;
        id1(new Point(0, 0), r, st, a, b);
        id1(new Point(0, 0), r, en, c, d);
        double res = calcDis(a, c, r);
        res = Math.min(res, calcDis(a, d, r));
        res = Math.min(res, calcDis(b, c, r));
        res = Math.min(res, calcDis(b, d, r));
        return res;
    }

    static double xp, yp, vp, x, y, v, r, R;
    static Point st, en;

    static boolean can(double t) {
        Point start = st = new Point(x, y);
        Point fin = en = new Point(xp, yp);
        double theta = t * vp / R;
        fin = en = fin.rotate(theta);
        Point a, b;
        boolean intersection = false;
        int num = id13(start, fin, new Point(0, 0), r, a, b);
        if (num > 0) {
            if (id4(start, fin, a)) {
                intersection = true;
            }
            if (num == 2 && id4(start, fin, b)) {
                intersection = true;
            }
        }
        if (num <= 1 || !intersection) {
            return fin.subtract(start).length() < v * t + EPS;
        }
        double dis = Calc(st, fin, r);
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
        R = new Point(xp, yp).length();
        double ans = 10000000, hi = 1000000, lo = 0.0;
        for (int iter = 0; iter < 100; iter++) {
            double m = lo + (hi - lo) / 2.0;
            if (can(m)) {
                ans = m;
                hi = m;
            } else {
                lo = m;
            }
        }
        System.out.printf("%.10f\n", ans);
    }
}

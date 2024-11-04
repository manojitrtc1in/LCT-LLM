import java.util.*;
import java.io.*;

class Main {
    static class Point {
        double x, y;

        Point() {}

        Point(double _x, double _y) {
            x = _x;
            y = _y;
        }

        void input() {
            Scanner sc = new Scanner(System.in);
            x = sc.nextDouble();
            y = sc.nextDouble();
        }

        void output() {
            System.out.printf("%.12f %.12f\n", x, y);
        }

        boolean equals(Point a) {
            return Double.compare(a.x, x) == 0 && Double.compare(a.y, y) == 0;
        }

        boolean lessThan(Point a) {
            return Double.compare(a.x, x) == 0 ? Double.compare(y, a.y) < 0 : Double.compare(x, a.x) < 0;
        }

        double len() {
            return Math.hypot(x, y);
        }

        double len2() {
            return x * x + y * y;
        }

        double distance(Point p) {
            return Math.hypot(x - p.x, y - p.y);
        }

        Point add(Point p) {
            return new Point(x + p.x, y + p.y);
        }

        Point sub(Point p) {
            return new Point(x - p.x, y - p.y);
        }

        Point mul(double b) {
            return new Point(x * b, y * b);
        }

        Point div(double b) {
            return new Point(x / b, y / b);
        }

        double dot(Point p) {
            return x * p.x + y * p.y;
        }

        double det(Point p) {
            return x * p.y - y * p.x;
        }

        double rad(Point a, Point b) {
            Point p = this;
            double c = Math.acos((a.sub(p).dot(b.sub(p))) / (a.distance(p) * b.distance(p)));
            return c;
        }

        Point trunc(double r) {
            double l = len();
            if (Double.compare(l, 0) == 0) return new Point(x, y);
            r /= l;
            return new Point(x * r, y * r);
        }

        Point rotleft() {
            return new Point(-y, x);
        }

        Point rotright() {
            return new Point(y, -x);
        }

        Point rotate(Point p, double angle) {
            Point v = this.sub(p);
            double c = Math.cos(angle), s = Math.sin(angle);
            return new Point(p.x + v.x * c - v.y * s, p.y + v.x * s + v.y * c);
        }
    }

    static class Line {
        Point a, b;

        Line() {}

        Line(Point _a, Point _b) {
            a = _a;
            b = _b;
        }

        boolean equals(Line v) {
            return a.equals(v.a) && b.equals(v.b);
        }

        Line(Point p, double angle) {
            a = p;
            if (Double.compare(angle - Math.PI / 2, 0) == 0) {
                b = a.add(new Point(0, 1));
            } else {
                b = a.add(new Point(1, Math.tan(angle)));
            }
        }

        Line(double _a, double _b, double _c) {
            if (Double.compare(_a, 0) == 0) {
                a = new Point(0, -_c / _b);
                b = new Point(1, -_c / _b);
            } else if (Double.compare(_b, 0) == 0) {
                a = new Point(-_c / _a, 0);
                b = new Point(-_c / _a, 1);
            } else {
                a = new Point(0, -_c / _b);
                b = new Point(1, (-_c - _a) / _b);
            }
        }

        void input() {
            a.input();
            b.input();
        }

        void adjust() {
            if (b.lessThan(a)) {
                Point temp = a;
                a = b;
                b = temp;
            }
        }

        double length() {
            return a.distance(b);
        }

        double angle() {
            double k = Math.atan2(b.y - a.y, b.x - a.x);
            if (Double.compare(k, 0) < 0) k += Math.PI;
            if (Double.compare(k - Math.PI, 0) == 0) k -= Math.PI;
            return k;
        }

        int relation(Point p) {
            int c = Double.compare(p.sub(a).det(b.sub(a)), 0);
            if (c < 0) return 1;
            if (c > 0) return 2;
            return 3;
        }

        boolean pointOnSeg(Point p) {
            return Double.compare(p.sub(a).det(b.sub(a)), 0) == 0 && Double.compare(p.sub(a).dot(p.sub(b)), 0) <= 0;
        }

        boolean parallel(Line v) {
            return Double.compare(b.sub(a).det(v.b.sub(v.a)), 0) == 0;
        }

        int segCrossSeg(Line v) {
            int d1 = Double.compare(b.sub(a).det(v.a.sub(a)), 0);
            int d2 = Double.compare(b.sub(a).det(v.b.sub(a)), 0);
            int d3 = Double.compare(v.b.sub(v.a).det(a.sub(v.a)), 0);
            int d4 = Double.compare(v.b.sub(v.a).det(b.sub(v.a)), 0);
            if ((d1 ^ d2) == -2 && (d3 ^ d4) == -2) return 2;
            return (d1 == 0 && Double.compare(v.a.sub(a).dot(v.a.sub(b)), 0) <= 0 ||
                    d2 == 0 && Double.compare(v.b.sub(a).dot(v.b.sub(b)), 0) <= 0 ||
                    d3 == 0 && Double.compare(a.sub(v.a).dot(a.sub(v.b)), 0) <= 0 ||
                    d4 == 0 && Double.compare(b.sub(v.a).dot(b.sub(v.b)), 0) <= 0) ? 1 : 0;
        }

        int lineCrossSeg(Line v) {
            int d1 = Double.compare(b.sub(a).det(v.a.sub(a)), 0);
            int d2 = Double.compare(b.sub(a).det(v.b.sub(a)), 0);
            return (d1 ^ d2) == -2 ? 2 : (d1 == 0 || d2 == 0) ? 1 : 0;
        }

        int lineCrossLine(Line v) {
            if (parallel(v)) {
                return v.relation(a) == 3 ? 1 : 0;
            }
            return 2;
        }

        Point crossPoint(Line v) {
            double a1 = v.b.sub(v.a).det(a.sub(v.a));
            double a2 = v.b.sub(v.a).det(b.sub(v.a));
            return new Point((a.x * a2 - b.x * a1) / (a2 - a1), (a.y * a2 - b.y * a1) / (a2 - a1));
        }

        double disPointToLine(Point p) {
            return Math.abs(p.sub(a).det(b.sub(a))) / length();
        }

        double disPointToSeg(Point p) {
            if (Double.compare(p.sub(b).dot(a.sub(b)), 0) < 0 || Double.compare(p.sub(a).dot(b.sub(a)), 0) < 0) {
                return Math.min(p.distance(a), p.distance(b));
            }
            return disPointToLine(p);
        }

        Point lineProg(Point p) {
            return a.add(b.sub(a).mul(b.sub(a).dot(p.sub(a)) / b.sub(a).len2()));
        }

        Point symmetryPoint(Point p) {
            Point q = lineProg(p);
            return new Point(2 * q.x - p.x, 2 * q.y - p.y);
        }
    }

    static class Circle {
        Point p;
        double r;

        Circle() {}

        Circle(Point _p, double _r) {
            p = _p;
            r = _r;
        }

        Circle(double x, double y, double _r) {
            p = new Point(x, y);
            r = _r;
        }

        Circle(Point a, Point b, Point c) {
            p = new Line(a.add(b).div(2), a.add(b).div(2).add(b.sub(a).rotleft())).crossPoint(new Line(c.add(b).div(2), c.add(b).div(2).add(b.sub(c).rotleft())));
            r = p.distance(a);
        }

        Circle(Point a, Point b, Point c, boolean t) {
            Line u = new Line(a.add(b).div(2), a.add(b).div(2).add(b.sub(a).rotleft()));
            Line v = new Line(c.add(b).div(2), c.add(b).div(2).add(b.sub(c).rotleft()));
            p = u.crossPoint(v);
            r = new Line(a, b).disPointToSeg(p);
        }

        void input() {
            p.input();
            Scanner sc = new Scanner(System.in);
            r = sc.nextDouble();
        }

        void output() {
            System.out.printf("%.2lf %.2lf %.2lf\n", p.x, p.y, r);
        }

        boolean equals(Circle v) {
            return p.equals(v.p) && Double.compare(r, v.r) == 0;
        }

        boolean lessThan(Circle v) {
            return p.lessThan(v.p) || (p.equals(v.p) && Double.compare(r, v.r) < 0);
        }

        double area() {
            return Math.PI * r * r;
        }

        double circumference() {
            return 2 * Math.PI * r;
        }

        int relation(Point b) {
            double dst = b.distance(p);
            if (Double.compare(dst, r) < 0) return 2;
            if (Double.compare(dst, r) == 0) return 1;
            return 0;
        }

        int relationSeg(Line v) {
            double dst = v.disPointToSeg(p);
            if (Double.compare(dst, r) < 0) return 2;
            if (Double.compare(dst, r) == 0) return 1;
            return 0;
        }

        int relationLine(Line v) {
            double dst = v.disPointToLine(p);
            if (Double.compare(dst, r) < 0) return 2;
            if (Double.compare(dst, r) == 0) return 1;
            return 0;
        }

        int getCircle(Point a, Point b, double r, Circle c1, Circle c2) {
            Circle x = new Circle(a, r), y = new Circle(b, r);
            int t = x.pointCrossCircle(y, c1.p, c2.p);
            if (t == 0) return 0;
            c1.r = c2.r = r;
            return t;
        }

        int getCircle(Line u, Point q, double r1, Circle c1, Circle c2) {
            double dis = u.disPointToLine(q);
            if (Double.compare(dis, r1 * 2) > 0) return 0;
            if (Double.compare(dis, 0) == 0) {
                c1.p = q.add(u.b.sub(u.a).rotleft().trunc(r1));
                c2.p = q.add(u.b.sub(u.a).rotright().trunc(r1));
                c1.r = c2.r = r1;
                return 2;
            }
            Line u1 = new Line(u.a.add(u.b.sub(u.a).rotleft().trunc(r1)), u.b.add(u.b.sub(u.a).rotleft().trunc(r1)));
            Line u2 = new Line(u.a.add(u.b.sub(u.a).rotright().trunc(r1)), u.b.add(u.b.sub(u.a).rotright().trunc(r1)));
            Circle cc = new Circle(q, r1);
            Point p1, p2;
            if (!cc.pointCrossLine(u1, p1, p2)) cc.pointCrossLine(u2, p1, p2);
            c1 = new Circle(p1, r1);
            if (p1.equals(p2)) {
                c2 = c1;
                return 1;
            }
            c2 = new Circle(p2, r1);
            return 2;
        }

        int getCircle(Line u, Line v, double r1, Circle c1, Circle c2, Circle c3, Circle c4) {
            if (u.parallel(v)) return 0;
            Line u1 = new Line(u.a.add(u.b.sub(u.a).rotleft().trunc(r1)), u.b.add(u.b.sub(u.a).rotleft().trunc(r1)));
            Line u2 = new Line(u.a.add(u.b.sub(u.a).rotright().trunc(r1)), u.b.add(u.b.sub(u.a).rotright().trunc(r1)));
            Line v1 = new Line(v.a.add(v.b.sub(v.a).rotleft().trunc(r1)), v.b.add(v.b.sub(v.a).rotleft().trunc(r1)));
            Line v2 = new Line(v.a.add(v.b.sub(v.a).rotright().trunc(r1)), v.b.add(v.b.sub(v.a).rotright().trunc(r1)));
            c1.r = c2.r = c3.r = c4.r = r1;
            c1.p = u1.crossPoint(v1);
            c2.p = u1.crossPoint(v2);
            c3.p = u2.crossPoint(v1);
            c4.p = u2.crossPoint(v2);
            return 4;
        }

        int getCircle(Circle cx, Circle cy, double r1, Circle c1, Circle c2) {
            Circle x = new Circle(cx.p, r1 + cx.r), y = new Circle(cy.p, r1 + cy.r);
            int t = x.pointCrossCircle(y, c1.p, c2.p);
            if (t == 0) return 0;
            c1.r = c2.r = r1;
            return t;
        }

        int pointCrossLine(Line v, Point p1, Point p2) {
            if (!this.relationSeg(v)) return 0;
            Point a = v.lineProg(p);
            double d = v.disPointToLine(p);
            d = Math.sqrt(r * r - d * d);
            if (Double.compare(d, 0) == 0) {
                p1 = a;
                p2 = a;
                return 1;
            }
            p1 = a.sub(v.b.sub(v.a).trunc(d));
            p2 = a.add(v.b.sub(v.a).trunc(d));
            return 2;
        }

        int relationCircle(Circle v) {
            double d = p.distance(v.p);
            if (Double.compare(d, r + v.r) > 0) return 5;
            if (Double.compare(d, r + v.r) == 0) return 4;
            double l = Math.abs(r - v.r);
            if (Double.compare(d, r + v.r) < 0 && Double.compare(d, l) > 0) return 3;
            if (Double.compare(d, l) == 0) return 2;
            if (Double.compare(d, l) < 0) return 1;
            return 0;
        }

        int pointCrossCircle(Circle v, Point p1, Point p2) {
            int rel = relationCircle(v);
            if (rel == 1 || rel == 5) return 0;
            double d = p.distance(v.p);
            double l = (d + (r * r - v.r * v.r) / d) / 2;
            double h = Math.sqrt(r * r - l * l);
            p1 = p.add(v.p.sub(p).trunc(l).add(v.p.sub(p).rotleft().trunc(h)));
            p2 = p.add(v.p.sub(p).trunc(l).add(v.p.sub(p).rotright().trunc(h)));
            if (rel == 2 || rel == 4) {
                return 1;
            }
            return 2;
        }

        int tangentLine(Point q, Line u, Line v) {
            int x = relation(q);
            if (x == 2) return 0;
            if (x == 1) {
                u = new Line(q, q.add(q.sub(p).rotleft()));
                v = u;
                return 1;
            }
            double d = p.distance(q);
            double l = r * r / d;
            double h = Math.sqrt(r * r - l * l);
            u = new Line(q, p.add(q.sub(p).trunc(l).add(q.sub(p).rotleft().trunc(h))));
            v = new Line(q, p.add(q.sub(p).trunc(l).add(q.sub(p).rotright().trunc(h))));
            return 2;
        }

        double areaCircle(Circle v) {
            int rel = relationCircle(v);
            if (rel >= 4) return 0.0;
            if (rel <= 2) return Math.min(area(), v.area());
            double d = p.distance(v.p);
            double hf = (r + v.r + d) / 2.0;
            double ss = 2 * Math.sqrt(hf * (hf - r) * (hf - v.r) * (hf - d));
            double a1 = Math.acos((r * r + d * d - v.r * v.r) / (2.0 * r * d));
            a1 = a1 * r * r;
            double a2 = Math.acos((v.r * v.r + d * d - r * r) / (2.0 * v.r * d));
            a2 = a2 * v.r * v.r;
            return a1 + a2 - ss;
        }

        double areaTriangle(Point a, Point b) {
            if (Double.compare(p.sub(a).det(p.sub(b)), 0) == 0) return 0.0;
            Point[] q = new Point[5];
            int len = 0;
            q[len++] = a;
            Line l = new Line(a, b);
            Point p11, p12;
            if (pointCrossLine(l, q[1], q[2]) == 2) {
                if (Double.compare(a.sub(q[1]).dot(b.sub(q[1])), 0) < 0) q[len++] = q[1];
                if (Double.compare(a.sub(q[2]).dot(b.sub(q[2])), 0) < 0) q[len++] = q[2];
            }
            q[len++] = b;
            if (len == 4 && Double.compare(q[0].sub(q[1]).dot(q[2].sub(q[1])), 0) > 0) {
                Point temp = q[1];
                q[1] = q[2];
                q[2] = temp;
            }
            double res = 0;
            for (int i = 0; i < len - 1; i++) {
                if (relation(q[i]) == 0 || relation(q[i + 1]) == 0) {
                    double arg = p.rad(q[i], q[i + 1]);
                    res += r * r * arg / 2.0;
                } else {
                    res += Math.abs(q[i].sub(p).det(q[i + 1].sub(p)) / 2.0);
                }
            }
            return res;
        }
    }

    static double xp, yp, vp;
    static double x, y, v, r;
    static Circle c;

    static double dist(Point a, Point b) {
        Line l = new Line(a, b);
        Point p11, p12;
        if (!c.pointCrossLine(l, p11, p12)) return a.distance(b);
        double rd = new Point(0, 0).rad(p11, p12);
        rd = Math.min(rd, 2 * Math.PI - rd);
        double ds = a.distance(b) - p11.distance(p12) + rd * r;
        Line l1, l2;
        c.tangentLine(a, l1, l2);
        Point[] p1 = new Point[3];
        p1[0] = l1.b;
        p1[1] = l2.b;
        c.tangentLine(b, l1, l2);
        Point[] p2 = new Point[3];
        p2[0] = l1.b;
        p2[1] = l2.b;
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                ds = Math.min(ds, a.distance(p1[i]) + new Point(0, 0).rad(p1[i], p2[j]) * r + b.distance(p2[j]));
            }
        }
        return ds;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        xp = sc.nextDouble();
        yp = sc.nextDouble();
        vp = sc.nextDouble();
        Point p = new Point(xp, yp);
        x = sc.nextDouble();
        y = sc.nextDouble();
        v = sc.nextDouble();
        r = sc.nextDouble();
        c = new Circle(0, 0, r);
        double d = 2 * Math.PI * p.distance(new Point(0, 0));
        int k = 1000;
        double low = 0, high = 1e6;
        while (k-- > 0) {
            double mid = (low + high) / 2.0;
            double s = vp * mid;
            double w = s % d;
            w = (w / d) * 2 * Math.PI;
            Point where = p.rotate(new Point(0, 0), w);
            double md = dist(where, new Point(x, y));
            if (Double.compare(mid * v, md) >= 0) {
                high = mid;
            } else {
                low = mid;
            }
        }
        System.out.printf("%.12lf\n", low);
    }
}

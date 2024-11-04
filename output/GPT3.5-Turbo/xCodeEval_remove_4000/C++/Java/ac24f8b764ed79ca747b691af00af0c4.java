import java.util.*;
import java.io.*;

class Main {
    static class Po {
        double x, y;

        Po(double _x, double _y) {
            x = _x;
            y = _y;
        }

        double length_sqr() {
            return x * x + y * y;
        }

        double length() {
            return Math.sqrt(length_sqr());
        }

        double atan() {
            return Math.atan2(y, x);
        }

        void input() {
            Scanner sc = new Scanner(System.in);
            x = sc.nextDouble();
            y = sc.nextDouble();
        }
    }

    static class Line {
        Po a, b;

        Line(Po _a, Po _b) {
            a = _a;
            b = _b;
        }
    }

    static class Seg {
        Po a, b;

        Seg(Po _a, Po _b) {
            a = _a;
            b = _b;
        }

        double length() {
            return (b.x - a.x) * (b.x - a.x) + (b.y - a.y) * (b.y - a.y);
        }
    }

    static double sgn(double x) {
        return x < -1e-2 ? -1 : x > 1e-2 ? 1 : 0;
    }

    static double sgn(double x, double y) {
        return sgn(x - y);
    }

    static double dot(double x1, double y1, double x2, double y2) {
        return x1 * x2 + y1 * y2;
    }

    static double dot(Po a, Po b) {
        return dot(a.x, a.y, b.x, b.y);
    }

    static double dot(Po p0, Po p1, Po p2) {
        return dot(p1.x - p0.x, p1.y - p0.y, p2.x - p0.x, p2.y - p0.y);
    }

    static double dot(Line l1, Line l2) {
        return dot(l1.b.x - l1.a.x, l1.b.y - l1.a.y, l2.b.x - l2.a.x, l2.b.y - l2.a.y);
    }

    static double det(double x1, double y1, double x2, double y2) {
        return x1 * y2 - x2 * y1;
    }

    static double det(Po a, Po b) {
        return det(a.x, a.y, b.x, b.y);
    }

    static double det(Po p0, Po p1, Po p2) {
        return det(p1.x - p0.x, p1.y - p0.y, p2.x - p0.x, p2.y - p0.y);
    }

    static double det(Line l1, Line l2) {
        return det(l1.b.x - l1.a.x, l1.b.y - l1.a.y, l2.b.x - l2.a.x, l2.b.y - l2.a.y);
    }

    static boolean isIntersect(Seg l1, Seg l2) {
        return Math.min(l1.a.x, l1.b.x) <= Math.max(l2.a.x, l2.b.x)
                && Math.min(l2.a.x, l2.b.x) <= Math.max(l1.a.x, l1.b.x)
                && Math.min(l1.a.y, l1.b.y) <= Math.max(l2.a.y, l2.b.y)
                && Math.min(l2.a.y, l2.b.y) <= Math.max(l1.a.y, l1.b.y)
                && sgn(det(l1.a, l2.a, l2.b)) * sgn(det(l1.b, l2.a, l2.b)) <= 0
                && sgn(det(l2.a, l1.a, l1.b)) * sgn(det(l2.b, l1.a, l1.b)) <= 0;
    }

    static double id1(Po a, Po b) {
        return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
    }

    static double id1(Po p, Line l) {
        Po v0 = new Po(l.b.x - l.a.x, l.b.y - l.a.y);
        Po v1 = new Po(p.x - l.a.x, p.y - l.a.y);
        return Math.abs(det(v0, v1)) * Math.abs(det(v0, v1)) / v0.length_sqr();
    }

    static double id1(Po p, Seg l) {
        Po v0 = new Po(l.b.x - l.a.x, l.b.y - l.a.y);
        Po v1 = new Po(p.x - l.a.x, p.y - l.a.y);
        Po v2 = new Po(p.x - l.b.x, p.y - l.b.y);
        if (sgn(dot(v0, v1)) * sgn(dot(v0, v2)) <= 0)
            return id1(p, new Line(l));
        else
            return Math.min(v1.length_sqr(), v2.length_sqr());
    }

    static double id1(Line l, Po p) {
        return id1(p, l);
    }

    static double id1(Seg l, Po p) {
        return id1(p, l);
    }

    static double id1(Line l1, Line l2) {
        if (sgn(det(l1, l2)) != 0)
            return 0;
        return id1(l1.a, l2);
    }

    static double id1(Line l1, Seg l2) {
        Po v0 = new Po(l1.b.x - l1.a.x, l1.b.y - l1.a.y);
        Po v1 = new Po(l2.a.x - l1.a.x, l2.a.y - l1.a.y);
        Po v2 = new Po(l2.b.x - l1.a.x, l2.b.y - l1.a.y);
        double c1 = det(v0, v1);
        double c2 = det(v0, v2);
        if (sgn(c1) != sgn(c2))
            return 0;
        return Math.abs(Math.min(Math.abs(c1), Math.abs(c2))) * Math.abs(Math.min(Math.abs(c1), Math.abs(c2))) / v0.length_sqr();
    }

    static boolean id0(Po p, Seg l) {
        return p.x == l.a.x && p.y == l.a.y || p.x == l.b.x && p.y == l.b.y;
    }

    static boolean id2(Po p, Seg l) {
        return sgn(det(p, l.a, l.b)) == 0 && sgn(l.a.x, p.x) * sgn(l.b.x, p.x) <= 0 && sgn(l.a.y, p.y) * sgn(l.b.y, p.y) <= 0;
    }

    static Po intersect(Line l1, Line l2) {
        double a1 = l1.b.y - l1.a.y;
        double b1 = l1.a.x - l1.b.x;
        double c1 = l1.b.x * l1.a.y - l1.a.x * l1.b.y;
        double a2 = l2.b.y - l2.a.y;
        double b2 = l2.a.x - l2.b.x;
        double c2 = l2.b.x * l2.a.y - l2.a.x * l2.b.y;
        double d = a1 * b2 - a2 * b1;
        double x = (b1 * c2 - b2 * c1) / d;
        double y = (a2 * c1 - a1 * c2) / d;
        return new Po(x, y);
    }

    static Po intersect(Po p, Line l) {
        return intersect(new Line(p, new Po(p.x + l.a.y - l.b.y, p.y + l.b.x - l.a.x)), l);
    }

    static Po rotate(Po p, double alpha, Po o) {
        p.x -= o.x;
        p.y -= o.y;
        return new Po(p.x * Math.cos(alpha) - p.y * Math.sin(alpha), p.y * Math.cos(alpha) + p.x * Math.sin(alpha)).add(o);
    }

    static double rand32() {
        return (Math.random() * 2 - 1) * (1 << 30) + (Math.random() * 2 - 1) * (1 << 15) + (Math.random() * 2 - 1);
    }

    static int random32(int l, int r) {
        return (int) (rand32() % (r - l + 1) + l);
    }

    static int random(int l, int r) {
        return (int) (Math.random() * (r - l + 1) + l);
    }

    static int dice() {
        return random(1, 6);
    }

    static boolean coin() {
        return random(0, 1) == 1;
    }

    static double R_(Po s, Po p, double vp, double vs, double r) {
        double R_ = s.length();
        double R = p.length();
        vp /= R;
        double ss = Math.sqrt(R_ * R_ - r * r) + Math.sqrt(R * R - r * r);
        double alpha = p.atan() - s.atan();
        double beta = Math.acos(r / R_) + Math.acos(r / R);
        double ll = 0, rr = (ss + Math.PI * R) * vs;
        for (int i = 0; i < 100; i++) {
            double m = (ll + rr) / 2;
            if (f(m, vp, alpha, beta, ss, vs, r, R_, R))
                rr = m;
            else
                ll = m;
        }
        return ll;
    }

    static boolean f(double x, double vp, double alpha, double beta, double ss, double vs, double r, double R_, double R) {
        double theta = x * vp + alpha;
        theta %= 2 * Math.PI;
        if (theta <= beta || theta >= 2 * Math.PI - beta)
            return Math.sqrt(R_ * R_ + R * R - 2 * R_ * R * Math.cos(theta)) <= vs * x;
        else {
            double delta = Math.PI - beta - Math.abs(Math.PI - theta);
            return ss + delta * r <= vs * x;
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        Po p = new Po(0, 0);
        p.input();
        double vp = sc.nextDouble();
        Po s = new Po(0, 0);
        s.input();
        double vs = sc.nextDouble();
        double r = sc.nextDouble();
        System.out.printf("%.10f\n", R_(s, p, vp, vs, r));
    }
}

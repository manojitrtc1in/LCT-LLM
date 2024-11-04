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
            return Math.sqrt((b.x - a.x) * (b.x - a.x) + (b.y - a.y) * (b.y - a.y));
        }
    }

    static double sgn(double x) {
        if (x < -1e-8)
            return -1;
        if (x > 1e-8)
            return 1;
        return 0;
    }

    static double sgn(double x, double y) {
        return sgn(x - y);
    }

    static double dot(Po a, Po b) {
        return a.x * b.x + a.y * b.y;
    }

    static double det(Po a, Po b) {
        return a.x * b.y - a.y * b.x;
    }

    static double dist_sqr(Po a, Po b) {
        return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
    }

    static double dist_sqr(Po p, Line l) {
        Po v0 = new Po(l.b.x - l.a.x, l.b.y - l.a.y);
        Po v1 = new Po(p.x - l.a.x, p.y - l.a.y);
        return det(v0, v1) * det(v0, v1) / v0.length_sqr();
    }

    static double dist_sqr(Po p, Seg l) {
        Po v0 = new Po(l.b.x - l.a.x, l.b.y - l.a.y);
        Po v1 = new Po(p.x - l.a.x, p.y - l.a.y);
        Po v2 = new Po(p.x - l.b.x, p.y - l.b.y);
        if (sgn(dot(v0, v1)) * sgn(dot(v0, v2)) <= 0)
            return dist_sqr(p, new Line(l.a, l.b));
        else
            return Math.min(v1.length_sqr(), v2.length_sqr());
    }

    static boolean isIntersect(Seg l1, Seg l2) {
        double c1 = det(l1.a, l2.a, l2.b);
        double c2 = det(l1.b, l2.a, l2.b);
        double c3 = det(l2.a, l1.a, l1.b);
        double c4 = det(l2.b, l1.a, l1.b);
        return sgn(c1) * sgn(c2) <= 0 && sgn(c3) * sgn(c4) <= 0;
    }

    static double dist_sqr(Seg l1, Seg l2) {
        if (isIntersect(l1, l2))
            return 0;
        else
            return Math.min(dist_sqr(l1.a, l2), Math.min(dist_sqr(l1.b, l2), Math.min(dist_sqr(l2.a, l1), dist_sqr(l2.b, l1))));
    }

    static boolean f(double x, double vp, double vs, double r, double R_, double R, double ss, double alpha, double beta) {
        double theta = x * vp + alpha;
        theta = theta % (2 * Math.PI);
        if (theta < 0)
            theta += 2 * Math.PI;
        double delta;
        if (theta <= beta || theta >= 2 * Math.PI - beta)
            return Math.sqrt(R_ * R_ + R * R - 2 * R_ * R * Math.cos(theta)) <= vs * x;
        else {
            delta = Math.PI - beta - Math.abs(Math.PI - theta);
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
        double R_ = s.length();
        double R = p.length();
        vp /= R;
        double ss = Math.sqrt(R_ * R_ - r * r) + Math.sqrt(R * R - r * r);
        double alpha = p.atan() - s.atan();
        alpha = alpha % (2 * Math.PI);
        if (alpha < 0)
            alpha += 2 * Math.PI;
        double beta = Math.acos(r / R_) + Math.acos(r / R);
        double ll = 0, rr = (ss + Math.PI * R) * vs;
        for (int i = 0; i < 100; i++) {
            double m = (ll + rr) / 2;
            if (f(m, vp, vs, r, R_, R, ss, alpha, beta))
                rr = m;
            else
                ll = m;
        }
        System.out.printf("%.10f\n", ll);
    }
}

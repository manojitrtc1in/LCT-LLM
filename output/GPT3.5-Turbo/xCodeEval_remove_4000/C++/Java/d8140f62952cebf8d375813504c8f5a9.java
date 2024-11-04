import java.util.Scanner;

class Main {
    static class Po {
        double x, y;

        Po(double _x, double _y) {
            x = _x;
            y = _y;
        }

        Po() {
            this(0, 0);
        }

        Po add(Po p) {
            return new Po(x + p.x, y + p.y);
        }

        Po subtract(Po p) {
            return new Po(x - p.x, y - p.y);
        }

        Po multiply(double k) {
            return new Po(x * k, y * k);
        }

        Po divide(double k) {
            return new Po(x / k, y / k);
        }

        double lengthSqr() {
            return x * x + y * y;
        }

        double length() {
            return Math.sqrt(lengthSqr());
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

        Line() {
            this(new Po(), new Po());
        }
    }

    static class Seg {
        Po a, b;

        Seg(Po _a, Po _b) {
            a = _a;
            b = _b;
        }

        Seg() {
            this(new Po(), new Po());
        }

        double length() {
            return b.subtract(a).length();
        }
    }

    static double EPS = 1e-2;
    static double PI = 3.14159265358979323846264;

    static int sgn(double x) {
        return x < -EPS ? -1 : x > EPS ? 1 : 0;
    }

    static int sgn(double x, double y) {
        return sgn(x - y);
    }

    static double dot(double x1, double y1, double x2, double y2) {
        return x1 * x2 + y1 * y2;
    }

    static double dot(Po a, Po b) {
        return dot(a.x, a.y, b.x, b.y);
    }

    static double dot(Po p0, Po p1, Po p2) {
        return dot(p1.subtract(p0), p2.subtract(p0));
    }

    static double dot(Line l1, Line l2) {
        return dot(l1.b.subtract(l1.a), l2.b.subtract(l2.a));
    }

    static double det(double x1, double y1, double x2, double y2) {
        return x1 * y2 - x2 * y1;
    }

    static double det(Po a, Po b) {
        return det(a.x, a.y, b.x, b.y);
    }

    static double det(Po p0, Po p1, Po p2) {
        return det(p1.subtract(p0), p2.subtract(p0));
    }

    static double det(Line l1, Line l2) {
        return det(l1.b.subtract(l1.a), l2.b.subtract(l2.a));
    }

    static double id1(Po a, Po b) {
        return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
    }

    static double id1(Po p, Line l) {
        Po v0 = l.b.subtract(l.a), v1 = p.subtract(l.a);
        return det(v0, v1) * det(v0, v1) / v0.lengthSqr();
    }

    static double id1(Po p, Seg l) {
        Po v0 = l.b.subtract(l.a), v1 = p.subtract(l.a), v2 = p.subtract(l.b);
        if (sgn(dot(v0, v1)) * sgn(dot(v0, v2)) <= 0) return id1(p, new Line(l));
        else return Math.min(v1.lengthSqr(), v2.lengthSqr());
    }

    static double id1(Line l, Po p) {
        return id1(p, l);
    }

    static double id1(Seg l, Po p) {
        return id1(p, l);
    }

    static boolean isIntersect(Seg l1, Seg l2) {
        return Math.min(l1.a.x, l1.b.x) <= Math.max(l2.a.x, l2.b.x) &&
                Math.min(l2.a.x, l2.b.x) <= Math.max(l1.a.x, l1.b.x) &&
                Math.min(l1.a.y, l1.b.y) <= Math.max(l2.a.y, l2.b.y) &&
                Math.min(l2.a.y, l2.b.y) <= Math.max(l1.a.y, l1.b.y) &&
                sgn(det(l1.a, l2.a, l2.b)) * sgn(det(l1.b, l2.a, l2.b)) <= 0 &&
                sgn(det(l2.a, l1.a, l1.b)) * sgn(det(l2.b, l1.a, l1.b)) <= 0;
    }

    static double id1(Seg l1, Seg l2) {
        if (isIntersect(l1, l2)) return 0;
        else return Math.min(id1(l1.a, l2), Math.min(id1(l1.b, l2), Math.min(id1(l2.a, l1), id1(l2.b, l1))));
    }

    static boolean id0(Po p, Seg l) {
        return p.equals(l.a) || p.equals(l.b);
    }

    static boolean id2(Po p, Seg l) {
        return sgn(det(p, l.a, l.b)) == 0 &&
                sgn(l.a.x, p.x) * sgn(l.b.x, p.x) <= 0 &&
                sgn(l.a.y, p.y) * sgn(l.b.y, p.y) <= 0;
    }

    static Po intersect(Line l1, Line l2) {
        return l1.a.add(l1.b.subtract(l1.a).multiply(det(l2.a, l1.a, l2.b) / det(l2, l1)));
    }

    static Po intersect(Po p, Line l) {
        return intersect(new Line(p, p.add(new Po(l.a.y - l.b.y, l.b.x - l.a.x))), l);
    }

    static Po rotate(Po p, double alpha, Po o) {
        p = p.subtract(o);
        return new Po(p.x * Math.cos(alpha) - p.y * Math.sin(alpha), p.y * Math.cos(alpha) + p.x * Math.sin(alpha)).add(o);
    }

    static double rand32() {
        return (Math.random() * 2 - 1) * (1 << 30) + (Math.random() * (1 << 15) + Math.random());
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
        double ll = 0, rr = 1e10;
        for (int i = 0; i < 1000; i++) {
            double m = (ll + rr) / 2;
            if (f(m, vp, vs, r, R_, R, ss, alpha, beta)) rr = m;
            else ll = m;
        }
        return ll;
    }

    static boolean f(double x, double vp, double vs, double r, double R_, double R, double ss, double alpha, double beta) {
        double theta = x * vp + alpha;
        theta %= 2 * PI;
        double delta;
        if (theta <= beta || theta >= 2 * PI - beta) return Math.sqrt(R_ * R_ + R * R - 2 * R_ * R * Math.cos(theta)) <= vs * x;
        else {
            delta = PI - beta - Math.abs(PI - theta);
            return ss + delta * r <= vs * x;
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        Po p = new Po();
        p.input();
        double vp = sc.nextDouble();
        Po s = new Po();
        s.input();
        double vs = sc.nextDouble();
        double r = sc.nextDouble();
        double result = R_(s, p, vp, vs, r);
        System.out.printf("%.10f\n", result);
    }
}

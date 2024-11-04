import java.util.*;
import java.io.*;

class Main {
    static final int MOD = 1000000007;
    static final double EPS = 1e-2;
    static final double PI = 3.14159265358979323846264;

    static class Po {
        double x, y;

        Po(double _x, double _y) {
            x = _x;
            y = _y;
        }

        Po() {
            this(0, 0);
        }

        double length() {
            return Math.sqrt(length_sqr());
        }

        double length_sqr() {
            return sqr(x) + sqr(y);
        }

        double atan() {
            return Math.atan2(y, x);
        }

        static double sqr(double a) {
            return a * a;
        }

        static double dot(Po a, Po b) {
            return a.x * b.x + a.y * b.y;
        }

        static double det(Po a, Po b) {
            return a.x * b.y - a.y * b.x;
        }

        static Po operatorPlus(Po a, Po b) {
            return new Po(a.x + b.x, a.y + b.y);
        }

        static Po operatorMinus(Po a, Po b) {
            return new Po(a.x - b.x, a.y - b.y);
        }

        static Po operatorMultiply(Po a, double k) {
            return new Po(a.x * k, a.y * k);
        }

        static Po operatorDivide(Po a, double k) {
            return new Po(a.x / k, a.y / k);
        }

        static boolean isEqual(Po a, Po b) {
            return Math.abs(a.x - b.x) < EPS && Math.abs(a.y - b.y) < EPS;
        }

        static boolean isNotEqual(Po a, Po b) {
            return !isEqual(a, b);
        }
    }

    static class Line {
        Po a, b;

        Line(Po _a, Po _b) {
            a = _a;
            b = _b;
        }

        Line(double x0, double y0, double x1, double y1) {
            a = new Po(x0, y0);
            b = new Po(x1, y1);
        }
    }

    static class Seg {
        Po a, b;

        Seg(Po _a, Po _b) {
            a = _a;
            b = _b;
        }

        Seg(double x0, double y0, double x1, double y1) {
            a = new Po(x0, y0);
            b = new Po(x1, y1);
        }

        double length() {
            return a.operatorMinus(b).length();
        }
    }

    static double id1(Po a, Po b) {
        return Po.sqr(a.x - b.x) + Po.sqr(a.y - b.y);
    }

    static double id1(Line l, Po p) {
        return id1(p, l);
    }

    static double id1(Seg l1, Seg l2) {
        if (isIntersect(l1, l2)) return 0;
        else return Math.min(Math.min(id1(l1.a, l2.a), id1(l1.b, l2.a)), Math.min(id1(l1.a, l2.b), id1(l1.b, l2.b)));
    }

    static boolean isIntersect(Seg l1, Seg l2) {
        return Math.min(l1.a.x, l1.b.x) <= Math.max(l2.a.x, l2.b.x) &&
               Math.min(l2.a.x, l2.b.x) <= Math.max(l1.a.x, l1.b.x) &&
               Math.min(l1.a.y, l1.b.y) <= Math.max(l2.a.y, l2.b.y) &&
               Math.min(l2.a.y, l2.b.y) <= Math.max(l1.a.y, l1.b.y) &&
               sgn(Po.det(l1.a.operatorMinus(l2.a), l2.b.operatorMinus(l2.a))) * sgn(Po.det(l1.b.operatorMinus(l2.a), l2.b.operatorMinus(l2.a))) <= 0 &&
               sgn(Po.det(l2.a.operatorMinus(l1.a), l1.b.operatorMinus(l1.a))) * sgn(Po.det(l2.b.operatorMinus(l1.a), l1.b.operatorMinus(l1.a))) <= 0;
    }

    static int sgn(double x) {
        return x < -EPS ? -1 : x > EPS ? 1 : 0;
    }

    static double d() {
        if (theta <= beta || theta >= 2 * PI - beta) return Math.sqrt(sqr(R_) + sqr(R) - 2 * R_ * R * Math.cos(theta));
        else {
            delta = PI - beta - Math.abs(PI - theta);
            return ss + delta * r;
        }
    }

    static boolean f(double x) {
        theta = x * vp + alpha;
        _R(theta);
        return d() <= vs * x;
    }

    static void _R(double[] x) {
        x[0] = x[0] % (2 * PI);
        if (x[0] < 0) x[0] += 2 * PI;
    }

    static double R_, R, r, ss, vs, vp;
    static double alpha, beta, theta, delta;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        st = new StringTokenizer(br.readLine());
        double x1 = Double.parseDouble(st.nextToken());
        double y1 = Double.parseDouble(st.nextToken());
        Po p = new Po(x1, y1);

        vp = Double.parseDouble(br.readLine());

        st = new StringTokenizer(br.readLine());
        double x2 = Double.parseDouble(st.nextToken());
        double y2 = Double.parseDouble(st.nextToken());
        Po s = new Po(x2, y2);

        st = new StringTokenizer(br.readLine());
        vs = Double.parseDouble(st.nextToken());
        r = Double.parseDouble(st.nextToken());

        R_ = s.length();
        R = p.length();
        vp /= R;
        ss = Math.sqrt(sqr(R_) - sqr(r)) + Math.sqrt(sqr(R) - sqr(r));
        alpha = p.atan() - s.atan();
        _R(new double[]{alpha});
        beta = Math.acos(r / R_) + Math.acos(r / R);
        _R(new double[]{beta});

        double ll = 0, rr = 1e10;
        for (int i = 0; i < 1000; i++) {
            double m = (ll + rr) / 2;
            if (f(m)) rr = m;
            else ll = m;
        }
        System.out.printf("%.10f\n", ll);
    }
}

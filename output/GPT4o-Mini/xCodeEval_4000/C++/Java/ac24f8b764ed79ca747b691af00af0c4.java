import java.util.*;
import java.io.*;

public class ac24f8b764ed79ca747b691af00af0c4_nc {
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
            return (b.length() - a.length());
        }
    }

    static double dot(Po p1, Po p2) {
        return p1.x * p2.x + p1.y * p2.y;
    }

    static double det(Po a, Po b) {
        return a.x * b.y - b.x * a.y;
    }

    static double dist_sqr(Po a, Po b) {
        return sqr(a.x - b.x) + sqr(a.y - b.y);
    }

    static double dist_sqr(Line l, Po p) {
        return dist_sqr(p, l.a);
    }

    static boolean isIntersect(Seg l1, Seg l2) {
        return min(l1.a.x, l1.b.x) <= max(l2.a.x, l2.b.x) &&
               min(l2.a.x, l2.b.x) <= max(l1.a.x, l1.b.x) &&
               min(l1.a.y, l1.b.y) <= max(l2.a.y, l2.b.y) &&
               min(l2.a.y, l2.b.y) <= max(l1.a.y, l1.b.y) &&
               sgn(det(l1.a, l2.a, l2.b)) * sgn(det(l1.b, l2.a, l2.b)) <= 0 &&
               sgn(det(l2.a, l1.a, l1.b)) * sgn(det(l2.b, l1.a, l1.b)) <= 0;
    }

    static double d() {
        if (theta <= beta || theta >= 2 * PI - beta) {
            return Math.sqrt(sqr(R_) + sqr(R) - 2 * R_ * R * Math.cos(theta));
        } else {
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
        x[0] = Math.IEEEremainder(x[0], 2 * PI);
        if (x[0] < 0) x[0] += 2 * PI;
    }

    static int sgn(double x) {
        return x < -EPS ? -1 : x > EPS ? 1 : 0;
    }

    static double min(double a, double b) {
        return a < b ? a : b;
    }

    static double max(double a, double b) {
        return a > b ? a : b;
    }

    static double R_, R, r, ss, vs, vp;
    static double alpha, beta, theta, delta;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        st = new StringTokenizer(br.readLine());
        Po p = new Po(Double.parseDouble(st.nextToken()), Double.parseDouble(st.nextToken()));
        vp = Double.parseDouble(br.readLine());
        st = new StringTokenizer(br.readLine());
        Po s = new Po(Double.parseDouble(st.nextToken()), Double.parseDouble(st.nextToken()));
        vs = Double.parseDouble(br.readLine());
        r = Double.parseDouble(br.readLine());

        R_ = s.length();
        R = p.length();
        vp /= R;
        ss = Math.sqrt(sqr(R_) - sqr(r)) + Math.sqrt(sqr(R) - sqr(r));
        alpha = p.atan() - s.atan();
        _R(new double[]{alpha});
        beta = Math.acos(r / R_) + Math.acos(r / R);
        _R(new double[]{beta});

        double ll = 0, rr = (ss + PI * R) * vs;
        for (int i = 0; i < 100; i++) {
            double m = (ll + rr) / 2;
            if (f(m)) rr = m; else ll = m;
        }
        System.out.printf("%.10f\n", ll);
    }
}

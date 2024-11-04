import java.util.*;
import java.io.*;

public class 92895cebf10f0af35475f86910bd6329_nc {
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

        public double length() {
            return Math.sqrt(length_sqr());
        }

        public double length_sqr() {
            return sqr(x) + sqr(y);
        }

        public double atan() {
            return Math.atan2(y, x);
        }

        public void input(Scanner sc) {
            x = sc.nextDouble();
            y = sc.nextDouble();
        }
    }

    static double sqr(double a) {
        return a * a;
    }

    static double d(Po s, Po p, double R_, double R, double r, double theta, double beta, double ss) {
        double delta;
        if (theta <= beta || theta >= 2 * PI - beta) {
            return Math.sqrt(sqr(R_) + sqr(R) - 2 * R_ * R * Math.cos(theta));
        } else {
            delta = PI - beta - Math.abs(PI - theta);
            return ss + delta * r;
        }
    }

    static boolean f(double x, Po s, Po p, double R_, double R, double r, double vs, double vp, double alpha, double beta) {
        double theta = x * vp + alpha;
        theta = _R(theta);
        return d(s, p, R_, R, r, theta, beta, Math.sqrt(sqr(R_) - sqr(r)) + Math.sqrt(sqr(R) - sqr(r))) <= vs * x;
    }

    static double _R(double x) {
        x = x % (2 * PI);
        if (x < 0) x += 2 * PI;
        return x;
    }

    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(System.in);
        Po s = new Po();
        Po p = new Po();
        double R_, R, r, ss, vs, vp;
        double alpha, beta;

        s.input(sc);
        vp = sc.nextDouble();
        p.input(sc);
        vs = sc.nextDouble();
        r = sc.nextDouble();

        R_ = s.length();
        R = p.length();
        vp /= R;
        ss = Math.sqrt(sqr(R_) - sqr(r)) + Math.sqrt(sqr(R) - sqr(r));
        alpha = p.atan() - s.atan();
        alpha = _R(alpha);
        beta = Math.acos(r / R_) + Math.acos(r / R);
        beta = _R(beta);

        double ll = 0, rr = (ss + PI * R) * vs;
        for (int i = 0; i < 200; i++) {
            double m = (ll + rr) / 2;
            if (f(m, s, p, R_, R, r, vs, vp, alpha, beta)) {
                rr = m;
            } else {
                ll = m;
            }
        }
        System.out.printf("%.10f\n", ll);
    }
}

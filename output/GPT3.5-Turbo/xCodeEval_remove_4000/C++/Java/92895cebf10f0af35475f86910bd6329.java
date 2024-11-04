import java.util.*;
import java.lang.*;
import java.io.*;

class Main
{
    static class Po {
        double x, y;
        Po(double _x, double _y) {
            x = _x;
            y = _y;
        }
    }

    static Po s, p, o;
    static double R_, R, r, ss, vs, vp;
    static double alpha, beta, theta, delta;

    static double sqr(double x) {
        return x * x;
    }

    static double fmod(double a, double b) {
        return a % b;
    }

    static double sqrt(double x) {
        return Math.sqrt(x);
    }

    static double cos(double x) {
        return Math.cos(x);
    }

    static double sin(double x) {
        return Math.sin(x);
    }

    static double acos(double x) {
        return Math.acos(x);
    }

    static double atan2(double y, double x) {
        return Math.atan2(y, x);
    }

    static double fabs(double x) {
        return Math.abs(x);
    }

    static double PI = 3.14159265358979323846264;

    static void _R(double[] x) {
        x[0] = fmod(x[0], 2 * PI);
        if (x[0] < 0)
            x[0] += 2 * PI;
    }

    static double d() {
        if (theta <= beta || theta >= 2 * PI - beta)
            return sqrt(sqr(R_) + sqr(R) - 2 * R_ * R * cos(theta));
        else {
            delta = PI - beta - fabs(PI - theta);
            return ss + delta * r;
        }
    }

    static boolean f(double x) {
        theta = x * vp + alpha;
        _R(new double[]{theta});
        return d() <= vs * x;
    }

    public static void main(String[] args) throws java.lang.Exception {
        Scanner sc = new Scanner(System.in);
        p = new Po(sc.nextDouble(), sc.nextDouble());
        vp = sc.nextDouble();
        s = new Po(sc.nextDouble(), sc.nextDouble());
        vs = sc.nextDouble();
        r = sc.nextDouble();

        R_ = Math.sqrt(sqr(p.x) + sqr(p.y));
        R = Math.sqrt(sqr(s.x) + sqr(s.y));
        vp /= R;
        ss = Math.sqrt(sqr(R_) - sqr(r)) + Math.sqrt(sqr(R) - sqr(r));
        alpha = atan2(p.y, p.x) - atan2(s.y, s.x);
        _R(new double[]{alpha});
        beta = acos(r / R_) + acos(r / R);
        _R(new double[]{beta});

        double ll = 0, rr = (ss + PI * R) * vs;
        for (int i = 0; i < 200; i++) {
            double m = (ll + rr) / 2;
            if (f(m))
                rr = m;
            else
                ll = m;
        }
        System.out.printf("%.10f\n", ll);
    }
}

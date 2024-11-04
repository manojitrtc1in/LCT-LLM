import java.util.*;
import java.io.*;

class Po {
    double x, y;

    Po(double _x, double _y) {
        x = _x;
        y = _y;
    }

    Po() {
        this(0, 0);
    }

    public static Po operatorPlus(Po a, Po b) {
        return new Po(a.x + b.x, a.y + b.y);
    }

    public static Po operatorMinus(Po a, Po b) {
        return new Po(a.x - b.x, a.y - b.y);
    }

    public static Po operatorMultiply(Po a, double k) {
        return new Po(a.x * k, a.y * k);
    }

    public static Po operatorDivide(Po a, double k) {
        return new Po(a.x / k, a.y / k);
    }

    public double lengthSqr() {
        return sqr(x) + sqr(y);
    }

    public double length() {
        return Math.sqrt(lengthSqr());
    }

    public double atan() {
        return Math.atan2(y, x);
    }

    public void input(Scanner scanner) {
        x = scanner.nextDouble();
        y = scanner.nextDouble();
    }

    private static double sqr(double a) {
        return a * a;
    }
}

class Line {
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

class Seg {
    Po a, b;

    Seg(Po _a, Po _b) {
        a = _a;
        b = _b;
    }

    Seg(double x0, double y0, double x1, double y1) {
        a = new Po(x0, y0);
        b = new Po(x1, y1);
    }

    public double length() {
        return Po.operatorMinus(b, a).length();
    }
}

public class ac24f8b764ed79ca747b691af00af0c4xcodeeval_processed_4000.json {
    static final int MOD = 1000000007;
    static final double PI = Math.PI;
    static final double EPS = 1e-2;

    static Po s = new Po(), p = new Po();
    static double R_, R, r, ss, vs, vp;
    static double alpha, beta, theta, delta;

    static void R(double[] x) {
        x[0] = x[0] % (2 * PI);
        if (x[0] < 0) x[0] += 2 * PI;
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
        R(new double[]{theta});
        return d() <= vs * x;
    }

    public static void main(String[] args) throws IOException {
        Scanner scanner = new Scanner(new File("in.txt"));

        p.input(scanner);
        vp = scanner.nextDouble();
        s.input(scanner);
        vs = scanner.nextDouble();
        r = scanner.nextDouble();

        R_ = s.length();
        R = p.length();
        vp /= R;
        ss = Math.sqrt(sqr(R_) - sqr(r)) + Math.sqrt(sqr(R) - sqr(r));
        alpha = p.atan() - s.atan();
        R(new double[]{alpha});
        beta = Math.acos(r / R_) + Math.acos(r / R);
        R(new double[]{beta});

        double ll = 0, rr = (ss + PI * R) * vs;
        for (int i = 0; i < 100; i++) {
            double m = (ll + rr) / 2;
            if (f(m)) rr = m; else ll = m;
        }
        System.out.printf("%.10f\n", ll);
    }

    private static double sqr(double a) {
        return a * a;
    }
}

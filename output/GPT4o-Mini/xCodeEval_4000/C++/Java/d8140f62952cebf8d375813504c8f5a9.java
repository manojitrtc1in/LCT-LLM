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

    public static Po input() {
        Scanner scanner = new Scanner(System.in);
        return new Po(scanner.nextDouble(), scanner.nextDouble());
    }

    public double lengthSqr() {
        return x * x + y * y;
    }

    public double length() {
        return Math.sqrt(lengthSqr());
    }

    public double atan() {
        return Math.atan2(y, x);
    }

    public static Po add(Po a, Po b) {
        return new Po(a.x + b.x, a.y + b.y);
    }

    public static Po subtract(Po a, Po b) {
        return new Po(a.x - b.x, a.y - b.y);
    }

    public static Po multiply(Po a, double k) {
        return new Po(a.x * k, a.y * k);
    }

    public static Po divide(Po a, double k) {
        return new Po(a.x / k, a.y / k);
    }
}

class Line {
    Po a, b;

    Line(Po _a, Po _b) {
        a = _a;
        b = _b;
    }

    Line(double x0, double y0, double x1, double y1) {
        this(new Po(x0, y0), new Po(x1, y1));
    }
}

class Seg {
    Po a, b;

    Seg(Po _a, Po _b) {
        a = _a;
        b = _b;
    }

    Seg(double x0, double y0, double x1, double y1) {
        this(new Po(x0, y0), new Po(x1, y1));
    }

    public double length() {
        return Po.subtract(b, a).length();
    }
}

public class d8140f62952cebf8d375813504c8f5a9_nc {
    static final double MOD = 1000000007;
    static final double EPS = 1e-2;
    static final double PI = Math.PI;

    static double R_, R, r, ss, vs, vp;
    static double alpha, beta, theta, delta;

    static void R(double[] x) {
        x[0] = x[0] % (2 * PI);
        if (x[0] < 0) x[0] += 2 * PI;
    }

    static double d() {
        if (theta <= beta || theta >= 2 * PI - beta) {
            return Math.sqrt(R_ * R_ + R * R - 2 * R_ * R * Math.cos(theta));
        } else {
            delta = PI - beta - Math.abs(PI - theta);
            return ss + delta * r;
        }
    }

    static boolean f(double x) {
        theta = x * vp + alpha;
        double[] thetaArr = {theta};
        R(thetaArr);
        theta = thetaArr[0];
        return d() <= vs * x;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        Po p = Po.input();
        Scanner scanner = new Scanner(System.in);
        vp = scanner.nextDouble();
        Po s = Po.input();
        vs = scanner.nextDouble();
        r = scanner.nextDouble();

        R_ = s.length();
        R = p.length();
        vp /= R;
        ss = Math.sqrt(R_ * R_ - r * r) + Math.sqrt(R * R - r * r);
        alpha = p.atan() - s.atan();
        double[] alphaArr = {alpha};
        R(alphaArr);
        alpha = alphaArr[0];
        beta = Math.acos(r / R_) + Math.acos(r / R);
        R(new double[]{beta});

        double ll = 0, rr = 1e10;
        for (int i = 0; i < 1000; i++) {
            double m = (ll + rr) / 2;
            if (f(m)) rr = m; else ll = m;
        }
        System.out.printf("%.10f\n", ll);
    }
}

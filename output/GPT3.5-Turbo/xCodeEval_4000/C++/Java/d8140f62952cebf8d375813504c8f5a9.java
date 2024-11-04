import java.util.Scanner;

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
    }

    static Po s, p;
    static double R_, R, r, ss, vs, vp;
    static double alpha, beta, theta, delta;

    static double d() {
        if (theta <= beta || theta >= 2 * Math.PI - beta)
            return Math.sqrt(R_ * R_ + R * R - 2 * R_ * R * Math.cos(theta));
        else {
            delta = Math.PI - beta - Math.abs(Math.PI - theta);
            return ss + delta * r;
        }
    }

    static boolean f(double x) {
        theta = x * vp + alpha;
        theta %= 2 * Math.PI;
        if (theta < 0)
            theta += 2 * Math.PI;
        return d() <= vs * x;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        p = new Po(sc.nextDouble(), sc.nextDouble());
        vp = sc.nextDouble();
        s = new Po(sc.nextDouble(), sc.nextDouble());
        vs = sc.nextDouble();
        r = sc.nextDouble();

        R_ = s.length();
        R = p.length();
        vp /= R;
        ss = Math.sqrt(R_ * R_ - r * r) + Math.sqrt(R * R - r * r);
        alpha = p.atan() - s.atan();
        alpha %= 2 * Math.PI;
        if (alpha < 0)
            alpha += 2 * Math.PI;
        beta = Math.acos(r / R_) + Math.acos(r / R);

        double ll = 0, rr = 1e10;
        for (int i = 0; i < 1000; i++) {
            double m = (ll + rr) / 2;
            if (f(m))
                rr = m;
            else
                ll = m;
        }
        System.out.printf("%.10f\n", ll);
    }
}

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

        void input() throws IOException {
            BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
            StringTokenizer st = new StringTokenizer(br.readLine());
            x = Double.parseDouble(st.nextToken());
            y = Double.parseDouble(st.nextToken());
        }

        double length() {
            return Math.sqrt(x * x + y * y);
        }

        double atan() {
            return Math.atan2(y, x);
        }
    }

    static double R_, R, r, ss, vs, vp;
    static double alpha, beta, theta, delta;

    static void _R(double[] x) {
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
        _R(thetaArr);
        theta = thetaArr[0];
        return d() <= vs * x;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        Po s = new Po();
        Po p = new Po();
        s.input();
        st = new StringTokenizer(br.readLine());
        vp = Double.parseDouble(st.nextToken());
        p.input();
        st = new StringTokenizer(br.readLine());
        vs = Double.parseDouble(st.nextToken());
        r = Double.parseDouble(st.nextToken());

        R_ = s.length();
        R = p.length();
        vp /= R;
        ss = Math.sqrt(R_ * R_ - r * r) + Math.sqrt(R * R - r * r);
        alpha = p.atan() - s.atan();
        double[] alphaArr = {alpha};
        _R(alphaArr);
        alpha = alphaArr[0];
        beta = Math.acos(r / R_) + Math.acos(r / R);
        double[] betaArr = {beta};
        _R(betaArr);
        beta = betaArr[0];

        double ll = 0, rr = (ss + PI * R) * vs;
        for (int i = 0; i < 200; i++) {
            double m = (ll + rr) / 2;
            if (f(m)) rr = m; else ll = m;
        }
        System.out.printf("%.10f\n", ll);
    }
}

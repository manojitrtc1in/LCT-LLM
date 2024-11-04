import java.util.*;

class Main {
    static int[] f, s;
    static double[] p;
    static double[][] dp, dans;
    static double[] pf, pp;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int r = sc.nextInt();
        f = new int[n];
        s = new int[n];
        p = new double[n];
        dp = new double[n][5010];
        dans = new double[n][5010];
        pf = new double[n];
        pp = new double[n];

        for (int i = 0; i < n; i++) {
            f[i] = sc.nextInt();
            s[i] = sc.nextInt();
            p[i] = sc.nextDouble();

            p[i] *= 0.01;
        }

        final int K = 50 * 100 + 1;

        double lp = 0;
        double rp = 1e8;
        for (int iter = 0; iter < 100; ++iter) {
            double z = (lp + rp) * 0.5;
            for (int i = 0; i < n; ++i) {
                Arrays.fill(dans[i], z);
            }
            for (int i = n - 1; i >= 0; --i) {
                for (int j = 0; j < f[i]; ++j) {
                    dans[i][j] = z;
                }
                int fi = f[i];
                int si = s[i];
                double pi = p[i];
                for (int j = fi; j < si; ++j) {
                    dans[i][j] = Math.min(z, (fi + dans[i + 1][j - fi]) * pi + (si + z) * (1 - pi));
                }
                for (int j = s[i]; j < K; ++j) {
                    dans[i][j] = Math.min(z, (fi + dans[i + 1][j - fi]) * pi + (si + dans[i + 1][j - si]) * (1 - pi));
                }
            }
            if (dans[0][r] < z - 1e-10) {
                rp = z;
            } else {
                lp = z;
            }
        }
        System.out.printf("%.10f\n", (lp + rp) * 0.5);
    }
}

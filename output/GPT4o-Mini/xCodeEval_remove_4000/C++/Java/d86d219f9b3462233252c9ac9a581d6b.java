import java.io.*;
import java.util.*;

public class d86d219f9b3462233252c9ac9a581d6bxcodeeval_processed_4000.json {
    static double[][] dans = new double[55][5010];
    static double[] p = new double[55];
    static int[] f = new int[55];
    static int[] s = new int[55];

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int r = Integer.parseInt(st.nextToken());
        double lp = 0;
        double rp = 1e8;

        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());
            f[i] = Integer.parseInt(st.nextToken());
            s[i] = Integer.parseInt(st.nextToken());
            p[i] = Double.parseDouble(st.nextToken()) * 0.01;
        }

        final int K = 50 * 100 + 1;

        for (int iter = 0; iter < 100; iter++) {
            double z = (lp + rp) * 0.5;
            for (int i = 0; i < n; i++) {
                Arrays.fill(dans[i], z);
            }
            for (int i = n - 1; i >= 0; i--) {
                for (int j = 0; j < f[i]; j++) {
                    dans[i][j] = z;
                }
                int fi = f[i];
                int si = s[i];
                double pi = p[i];
                for (int j = fi; j < si; j++) {
                    dans[i][j] = Math.min(z, (fi + dans[i + 1][j - fi]) * pi + (si + z) * (1 - pi));
                }
                for (int j = si; j < K; j++) {
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

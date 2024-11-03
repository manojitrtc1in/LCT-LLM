import java.io.*;
import java.util.*;

class Main {
    static final int _ = (int) (2e5 + 10);
    static final int __ = (int) (1e6 + 10);
    static final int LOG = 18;

    static int n, k;
    static double[] p = new double[22];
    static double[] subret = new double[22];
    static double[] dp = new double[1 << 20];

    static void solve(int id) {
        if (p[id] <= 1e-9) {
            System.out.print("0 ");
            return;
        }
        Arrays.fill(subret, 0);
        subret[0] = dp[0] = p[id];
        for (int i = 1; i < (1 << n); i++) {
            dp[i] = 0;
            if ((i & (1 << id)) != 0) continue;
            double sum = 0;
            for (int j = 0; j < n; j++) {
                if ((i & (1 << j)) != 0) {
                    sum += p[j];
                    dp[i] += dp[i ^ (1 << j)] * p[j];
                }
            }
            dp[i] /= 1 - sum;
            subret[Integer.bitCount(i)] += dp[i];
        }
        double ret = 0;
        for (int i = 0; i < k; i++) {
            ret += subret[i];
        }
        System.out.printf("%.10f ", ret);
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] input = br.readLine().split(" ");
        n = Integer.parseInt(input[0]);
        k = Integer.parseInt(input[1]);
        input = br.readLine().split(" ");
        for (int i = 0; i < n; i++) {
            p[i] = Double.parseDouble(input[i]);
        }
        for (int i = 0; i < n; i++) {
            solve(i);
        }
        System.out.println();
    }
}

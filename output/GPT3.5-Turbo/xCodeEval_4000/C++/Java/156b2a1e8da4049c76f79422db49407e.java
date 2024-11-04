import java.io.*;
import java.util.*;

public class 156b2a1e8da4049c76f79422db49407e_nc {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int k = sc.nextInt();
        double[] p = new double[n];
        for (int i = 0; i < n; i++) {
            p[i] = sc.nextDouble();
        }
        for (int i = 0; i < n; i++) {
            solve(i, n, k, p);
        }
    }

    public static void solve(int id, int n, int k, double[] p) {
        if (p[id] <= 1e-9) {
            System.out.println("0");
            return;
        }
        double[] subret = new double[k + 1];
        double[] dp = new double[1 << n];
        dp[0] = p[id];
        subret[0] = dp[0];
        for (int i = 1; i < (1 << n); i++) {
            dp[i] = 0;
            if ((i & (1 << id)) != 0) {
                continue;
            }
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
        System.out.printf("%.10f\n", ret);
    }
}

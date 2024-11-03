import java.io.*;
import java.util.*;

class DSum {
    static class Solver {
        private final BufferedReader in;
        private final PrintWriter out;

        public Solver(BufferedReader in, PrintWriter out) {
            this.in = in;
            this.out = out;
        }

        private void rd(int[] arr) throws IOException {
            String[] parts = in.readLine().split(" ");
            for (int i = 0; i < arr.length; i++) {
                arr[i] = Integer.parseInt(parts[i]);
            }
        }

        private void prln(Object... args) {
            for (Object obj : args) {
                out.print(obj);
                out.print(" ");
            }
            out.println();
        }

        private long rec(int l, int r, long[][] dps, long[] sums, int[][] arrs, int k) {
            long ans = 0;
            int[] carr = arrs[l];
            long[] dp = dps[l];
            if (l + 1 == r) {
                ans = Math.max(ans, dp[k]);
                long sum = 0;
                for (int i = 0; i < Math.min(k, carr.length); i++) {
                    sum += carr[i];
                    ans = Math.max(ans, dp[k - i - 1] + sum);
                }
            } else {
                int m = (l + r) / 2;
                System.arraycopy(dps[l], 0, dps[l + 1], 0, k + 1);
                for (int i = l; i < m; i++) {
                    add_to_knap(i, dps[l + 1], k);
                }
                ans = Math.max(ans, rec(m, r, dps, sums, arrs, k));
                System.arraycopy(dps[l], 0, dps[l + 1], 0, k + 1);
                for (int i = m; i < r; i++) {
                    add_to_knap(i, dps[l + 1], k);
                }
                ans = Math.max(ans, rec(l, m, dps, sums, arrs, k));
            }
            return ans;
        }

        private void add_to_knap(int i, long[] dp, int k) {
            long[] carr = arrs[i];
            long v = sums[i];
            int k1 = arrs[i].length;
            for (int j = k; j >= k1; j--) {
                dp[j] = Math.max(dp[j], dp[j - k1] + v);
            }
        }

        public void solve() throws IOException {
            String[] parts = in.readLine().split(" ");
            int n = Integer.parseInt(parts[0]);
            int k = Integer.parseInt(parts[1]);

            sums = new long[n];
            arrs = new int[n][];
            for (int i = 0; i < n; i++) {
                parts = in.readLine().split(" ");
                int t = Integer.parseInt(parts[0]);
                arrs[i] = new int[t];
                for (int j = 0; j < t; j++) {
                    arrs[i][j] = Integer.parseInt(parts[j + 1]);
                }
                if (t > k) {
                    int[] newArr = new int[k];
                    System.arraycopy(arrs[i], 0, newArr, 0, k);
                    arrs[i] = newArr;
                }
                for (int j = 0; j < arrs[i].length; j++) {
                    sums[i] += arrs[i][j];
                }
            }

            long[][] dps = new long[13][k + 1];
            prln(rec(0, n, dps, sums, arrs, k));
        }
    }

    public static void solve(BufferedReader in, PrintWriter out) throws IOException {
        new Solver(in, out).solve();
    }

    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter out = new PrintWriter(System.out);
        solve(in, out);
        out.close();
    }
}
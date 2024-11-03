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

        private void readIntArray(int[] arr) throws IOException {
            StringTokenizer st = new StringTokenizer(in.readLine());
            for (int i = 0; i < arr.length; i++) {
                arr[i] = Integer.parseInt(st.nextToken());
            }
        }

        private long sum(int[] arr) {
            long sum = 0;
            for (int num : arr) {
                sum += num;
            }
            return sum;
        }

        public void solve() throws IOException {
            int n, k;
            StringTokenizer st = new StringTokenizer(in.readLine());
            n = Integer.parseInt(st.nextToken());
            k = Integer.parseInt(st.nextToken());

            int[][] arrs = new int[n][];
            for (int i = 0; i < n; i++) {
                st = new StringTokenizer(in.readLine());
                int t = Integer.parseInt(st.nextToken());
                arrs[i] = new int[t];
                readIntArray(arrs[i]);
            }

            long[] sums = new long[n];
            for (int i = 0; i < n; i++) {
                sums[i] = sum(arrs[i]);
            }

            long[][] dps = new long[13][k + 1];
            for (int i = 0; i < n; i++) {
                int k1 = arrs[i].length;
                for (int j = k; j >= k1; j--) {
                    dps[0][j] = Math.max(dps[0][j], dps[0][j - k1] + sums[i]);
                }
            }

            for (int dpi = 0; dpi < 12; dpi++) {
                System.arraycopy(dps[dpi], 0, dps[dpi + 1], 0, k + 1);
            }

            long ans = 0;
            for (int l = 0; l < n; l++) {
                int r = l + 1;
                long[] carr = arrs[l];
                long[] dp = dps[0];
                if (l + 1 == r) {
                    ans = Math.max(ans, dp[k]);
                    long sum = 0;
                    for (int i = 0; i < Math.min(k, carr.length); i++) {
                        sum += carr[i];
                        ans = Math.max(ans, dp[k - i - 1] + sum);
                    }
                } else {
                    int m = (l + r) / 2;
                    ans = Math.max(ans, doSplit(l, m, m, r, dps));
                    ans = Math.max(ans, doSplit(m, r, l, m, dps));
                }
            }

            out.println(ans);
        }

        private long doSplit(int l1, int r1, int l2, int r2, long[][] dps) {
            for (int i = l1; i < r1 - 1; i++) {
                int k1 = arrs[i].length;
                for (int j = k; j >= k1; j--) {
                    dps[dpi + 1][j] = Math.max(dps[dpi + 1][j], dps[dpi + 1][j - k1] + sums[i]);
                }
            }
            return rec(l2, r2, dpi + 1, dps);
        }

        private long rec(int l, int r, int dpi, long[][] dps) {
            long ans = 0;
            long[] carr = arrs[l];
            long[] dp = dps[dpi];
            if (l + 1 == r) {
                ans = Math.max(ans, dp[k]);
                long sum = 0;
                for (int i = 0; i < Math.min(k, carr.length); i++) {
                    sum += carr[i];
                    ans = Math.max(ans, dp[k - i - 1] + sum);
                }
            } else {
                int m = (l + r) / 2;
                ans = Math.max(ans, doSplit(l, m, m, r, dps));
                ans = Math.max(ans, doSplit(m, r, l, m, dps));
            }
            return ans;
        }
    }

    public static void solve(BufferedReader in, PrintWriter out) throws IOException {
        Solver solver = new Solver(in, out);
        solver.solve();
    }

    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter out = new PrintWriter(System.out);
        solve(in, out);
        out.close();
    }
}

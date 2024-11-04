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

        private void readInts(int[]... arrays) throws IOException {
            for (int[] array : arrays) {
                for (int i = 0; i < array.length; i++) {
                    array[i] = Integer.parseInt(in.readLine());
                }
            }
        }

        private void print(Object... objects) {
            for (Object obj : objects) {
                out.print(obj);
            }
        }

        private void println(Object... objects) {
            print(objects);
            out.println();
        }

        private long rec(int l, int r, int dpi, long[][] dps, long[] sums, int[][] arrs, int k) {
            long ans = 0;
            int[] carr = arrs[l];
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
                System.arraycopy(dps[dpi], 0, dps[dpi + 1], 0, k + 1);
                for (int i = l; i < m; i++) {
                    add_to_knap(i, dpi + 1, dps, sums, arrs, k);
                }
                ans = Math.max(ans, rec(m, r, dpi + 1, dps, sums, arrs, k));
                System.arraycopy(dps[dpi], 0, dps[dpi + 1], 0, k + 1);
                for (int i = m; i < r; i++) {
                    add_to_knap(i, dpi + 1, dps, sums, arrs, k);
                }
                ans = Math.max(ans, rec(l, m, dpi + 1, dps, sums, arrs, k));
            }
            return ans;
        }

        private void add_to_knap(int i, int dpi, long[][] dps, long[] sums, int[][] arrs, int k) {
            long v = sums[i];
            int k1 = arrs[i].length;
            for (int j = k; j >= k1; j--) {
                dps[dpi][j] = Math.max(dps[dpi][j], dps[dpi][j - k1] + v);
            }
        }

        public void solve() throws IOException {
            int[] nk = new int[2];
            readInts(nk);
            int n = nk[0];
            int k = nk[1];
            int[][] arrs = new int[n][];
            long[] sums = new long[n];
            readInts(arrs);
            for (int i = 0; i < n; i++) {
                int t = arrs[i].length;
                if (t > k) {
                    arrs[i] = Arrays.copyOf(arrs[i], k);
                }
                for (int j = 0; j < arrs[i].length; j++) {
                    sums[i] += arrs[i][j];
                }
            }
            long[][] dps = new long[13][k + 1];
            println(rec(0, n, 0, dps, sums, arrs, k));
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

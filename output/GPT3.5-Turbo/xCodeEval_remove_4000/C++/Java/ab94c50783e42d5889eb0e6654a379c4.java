import java.util.*;
import java.io.*;

class DSum {
    static class Solver {
        private final BufferedReader in;
        private final PrintWriter out;

        public Solver(BufferedReader in, PrintWriter out) {
            this.in = in;
            this.out = out;
        }

        private void readInts(int[] arr) throws IOException {
            String[] parts = in.readLine().split(" ");
            for (int i = 0; i < arr.length; i++) {
                arr[i] = Integer.parseInt(parts[i]);
            }
        }

        private void print(Object... args) {
            for (Object arg : args) {
                out.print(arg);
            }
        }

        private void println(Object... args) {
            print(args);
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
                long[][] newDps = new long[13][k + 1];
                for (int i = 0; i < newDps.length; i++) {
                    System.arraycopy(dp, 0, newDps[i], 0, dp.length);
                }
                ans = Math.max(ans, doSplit(l, (l + r) / 2, (l + r) / 2, r, newDps, sums, arrs, k));
                ans = Math.max(ans, doSplit((l + r) / 2, r, l, (l + r) / 2, newDps, sums, arrs, k));
            }
            return ans;
        }

        private long doSplit(int l1, int r1, int l2, int r2, long[][] dps, long[] sums, int[][] arrs, int k) {
            for (int i = l1; i < r1; i++) {
                addToknap(i, dps, sums, arrs, k, dps);
            }
            return rec(l2, r2, dps.length - 1, dps, sums, arrs, k);
        }

        private void addToknap(int i, long[][] dps, long[] sums, int[][] arrs, int k, long[][] newDps) {
            long v = sums[i];
            int k1 = arrs[i].length;
            for (int j = k; j >= k1; j--) {
                newDps[i + 1][j] = Math.max(newDps[i + 1][j], newDps[i + 1][j - k1] + v);
            }
        }

        public void solve() throws IOException {
            int[] nk = new int[2];
            readInts(nk);
            int n = nk[0];
            int k = nk[1];
            int[][] arrs = new int[n][];
            long[] sums = new long[n];
            for (int i = 0; i < n; i++) {
                int t = Integer.parseInt(in.readLine());
                arrs[i] = new int[t];
                readInts(arrs[i]);
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

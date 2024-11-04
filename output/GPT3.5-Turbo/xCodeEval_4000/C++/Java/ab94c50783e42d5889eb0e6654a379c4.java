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

        private void readIntArr(int[] arr) throws IOException {
            String[] line = in.readLine().split(" ");
            for (int i = 0; i < arr.length; i++) {
                arr[i] = Integer.parseInt(line[i]);
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
                ans = Math.max(ans, doSplit(l, m, m, r, dps, sums, arrs, k));
                ans = Math.max(ans, doSplit(m, r, l, m, dps, sums, arrs, k));
            }
            return ans;
        }

        private long doSplit(int l1, int r1, int l2, int r2, long[][] dps, long[] sums, int[][] arrs, int k) {
            long[][] newDps = new long[dps.length][dps[0].length];
            for (int i = 0; i < dps.length; i++) {
                System.arraycopy(dps[i], 0, newDps[i], 0, dps[i].length);
            }
            for (int i = l1; i < r1; i++) {
                addToKnap(i, newDps, sums, arrs, k);
            }
            return rec(l2, r2, newDps, sums, arrs, k);
        }

        private void addToKnap(int i, long[][] dps, long[] sums, int[][] arrs, int k) {
            long v = sums[i];
            int k1 = arrs[i].length;
            for (int j = k; j >= k1; j--) {
                dps[i + 1][j] = Math.max(dps[i + 1][j], dps[i + 1][j - k1] + v);
            }
        }

        public void solve() throws IOException {
            StringTokenizer st = new StringTokenizer(in.readLine());
            int n = Integer.parseInt(st.nextToken());
            int k = Integer.parseInt(st.nextToken());

            long[] sums = new long[n];
            int[][] arrs = new int[n][];
            for (int i = 0; i < n; i++) {
                st = new StringTokenizer(in.readLine());
                int t = Integer.parseInt(st.nextToken());
                arrs[i] = new int[t];
                for (int j = 0; j < t; j++) {
                    arrs[i][j] = Integer.parseInt(st.nextToken());
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
            println(rec(0, n, dps, sums, arrs, k));
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

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
            StringTokenizer st = new StringTokenizer(in.readLine());
            for (int i = 0; i < arr.length; i++) {
                arr[i] = Integer.parseInt(st.nextToken());
            }
        }

        private void prln(Object... args) {
            for (Object arg : args) {
                out.print(arg);
                out.print(' ');
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
                doCopy(dps, l, r, k);
                for (int i = l; i < m - 1; i++) {
                    addToKnap(i, dps, carr, dp, k);
                }
                ans = Math.max(ans, rec(m, r, dps, sums, arrs, k));
                doCopy(dps, l, r, k);
                for (int i = m; i < r - 1; i++) {
                    addToKnap(i, dps, carr, dp, k);
                }
                ans = Math.max(ans, rec(l, m, dps, sums, arrs, k));
            }
            return ans;
        }

        private void doCopy(long[][] dps, int l, int r, int k) {
            System.arraycopy(dps[l], 0, dps[l + 1], 0, k + 1);
        }

        private void addToKnap(int i, long[][] dps, int[] carr, long[] dp, int k) {
            long v = sums[i];
            int k1 = arrs[i].length;
            for (int j = k; j >= k1; j--) {
                dp[j] = Math.max(dp[j], dp[j - k1] + v);
            }
        }

        public void solve() throws IOException {
            StringTokenizer st = new StringTokenizer(in.readLine());
            int n = Integer.parseInt(st.nextToken());
            int k = Integer.parseInt(st.nextToken());

            int[] sums = new int[n];
            int[][] arrs = new int[n][];
            for (int i = 0; i < n; i++) {
                st = new StringTokenizer(in.readLine());
                int t = Integer.parseInt(st.nextToken());
                arrs[i] = new int[t];
                rd(arrs[i]);
                if (t > k) {
                    arrs[i] = Arrays.copyOf(arrs[i], k);
                }
                sums[i] = Arrays.stream(arrs[i]).sum();
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

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

        private void solve() throws IOException {
            StringTokenizer st = new StringTokenizer(in.readLine());
            int n = Integer.parseInt(st.nextToken());
            int k = Integer.parseInt(st.nextToken());

            long[] sums = new long[n];
            List<List<Integer>> arrs = new ArrayList<>();
            for (int i = 0; i < n; i++) {
                st = new StringTokenizer(in.readLine());
                int t = Integer.parseInt(st.nextToken());
                List<Integer> arr = new ArrayList<>();
                for (int j = 0; j < t; j++) {
                    arr.add(Integer.parseInt(st.nextToken()));
                }
                if (t > k) {
                    arr = arr.subList(0, k);
                }
                sums[i] = arr.stream().mapToLong(Integer::longValue).sum();
                arrs.add(arr);
            }

            long[][] dps = new long[13][k + 1];
            for (int i = 0; i < 13; i++) {
                Arrays.fill(dps[i], 0);
            }

            long ans = rec(0, n, k, dps, sums, arrs);
            out.println(ans);
        }

        private long rec(int l, int r, int k, long[][] dps, long[] sums, List<List<Integer>> arrs) {
            long ans = 0;
            List<Integer> carr = arrs.get(l);
            long[] dp = dps[0];
            if (l + 1 == r) {
                ans = dp[k];
                long sum = 0;
                for (int i = 0; i < Math.min(k, carr.size()); i++) {
                    sum += carr.get(i);
                    ans = Math.max(ans, dp[k - i - 1] + sum);
                }
            } else {
                int m = (l + r) / 2;
                doCopy(dps, 0, dpi);
                for (int i = l; i < m - 1; i++) {
                    addToKnap(i, dpi + 1, dps, sums, arrs);
                }
                ans = Math.max(ans, rec(m, r, k, dps, sums, arrs));
                doCopy(dps, 0, dpi);
                for (int i = m; i < r - 1; i++) {
                    addToKnap(i, dpi + 1, dps, sums, arrs);
                }
                ans = Math.max(ans, rec(l, m, k, dps, sums, arrs));
            }
            return ans;
        }

        private void doCopy(long[][] dps, int from, int to) {
            System.arraycopy(dps[from], 0, dps[to], 0, dps[from].length);
        }

        private void addToKnap(int i, int dpi, long[][] dps, long[] sums, List<List<Integer>> arrs) {
            long v = sums[i];
            int k1 = arrs.get(i).size();
            for (int j = k; j >= k1; j--) {
                dps[dpi][j] = Math.max(dps[dpi][j], dps[dpi][j - k1] + v);
            }
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

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
                sums[i] = sum(arr);
                arrs.add(arr);
            }

            long[][] dps = new long[13][k + 1];
            out.println(rec(0, n, 0, k, dps, sums, arrs));
        }

        private long rec(int l, int r, int dpi, int k, long[][] dps, long[] sums, List<List<Integer>> arrs) {
            long ans = 0;
            List<Integer> carr = arrs.get(l);
            long[] dp = dps[dpi];
            if (l + 1 == r) {
                ans = dp[k];
                long sum = 0;
                for (int i = 0; i < Math.min(k, carr.size()); i++) {
                    sum += carr.get(i);
                    ans = Math.max(ans, dp[k - i - 1] + sum);
                }
            } else {
                int m = (l + r) / 2;
                System.arraycopy(dps[dpi], 0, dps[dpi + 1], 0, k + 1);
                for (int i = l; i < m - 1; i++) {
                    add_to_knap(i, dpi + 1, k, dps, sums, arrs);
                }
                ans = Math.max(ans, rec(m, r, dpi + 1, k, dps, sums, arrs));
                System.arraycopy(dps[dpi], 0, dps[dpi + 1], 0, k + 1);
                for (int i = m; i < r - 1; i++) {
                    add_to_knap(i, dpi + 1, k, dps, sums, arrs);
                }
                ans = Math.max(ans, rec(l, m, dpi + 1, k, dps, sums, arrs));
            }
            return ans;
        }

        private void add_to_knap(int i, int dpi, int k, long[][] dps, long[] sums, List<List<Integer>> arrs) {
            long v = sums[i];
            List<Integer> carr = arrs.get(i);
            int k1 = carr.size();
            for (int j = k; j >= k1; j--) {
                dps[dpi][j] = Math.max(dps[dpi][j], dps[dpi][j - k1] + v);
            }
        }

        private long sum(List<Integer> arr) {
            long sum = 0;
            for (int num : arr) {
                sum += num;
            }
            return sum;
        }
    }

    public static void solve(InputStream in, OutputStream out) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(in));
        PrintWriter writer = new PrintWriter(out);
        Solver solver = new Solver(reader, writer);
        solver.solve();
        writer.flush();
    }

    public static void main(String[] args) throws IOException {
        solve(System.in, System.out);
    }
}

import java.util.*;
import java.io.*;

class DSum {
    static class Solver {
        private final BufferedReader in;
        private final PrintWriter out;

        Solver(BufferedReader in, PrintWriter out) {
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
            out.println(rec(0, n, k, dps, sums, arrs));
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
                copy(dps[l + 1], dp);
                for (int i = l; i < m - 1; i++) {
                    addToKnap(i, dps[i + 1], dp, k);
                }
                ans = Math.max(ans, rec(m, r, k, dps, sums, arrs));
                copy(dps[l + 1], dp);
                for (int i = m; i < r - 1; i++) {
                    addToKnap(i, dps[i + 1], dp, k);
                }
                ans = Math.max(ans, rec(l, m, k, dps, sums, arrs));
            }
            return ans;
        }

        private void addToKnap(int i, long[] src, long[] dest, int k) {
            long v = sums[i];
            List<Integer> carr = arrs.get(i);
            int k1 = carr.size();
            for (int j = k; j >= k1; j--) {
                dest[j] = Math.max(dest[j], dest[j - k1] + v);
            }
        }

        private long sum(List<Integer> arr) {
            long sum = 0;
            for (int num : arr) {
                sum += num;
            }
            return sum;
        }

        private void copy(long[] src, long[] dest) {
            System.arraycopy(src, 0, dest, 0, src.length);
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

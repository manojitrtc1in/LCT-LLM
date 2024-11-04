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
            for (int i = 0; i < n; i++) {
                int k1 = arrs.get(i).size();
                for (int j = k; j >= k1; j--) {
                    dps[i + 1][j] = Math.max(dps[i][j], dps[i][j - k1] + sums[i]);
                }
            }

            long ans = rec(0, n, k, dps, sums, arrs);
            out.println(ans);
        }

        private long rec(int l, int r, int k, long[][] dps, long[] sums, List<List<Integer>> arrs) {
            if (l + 1 == r) {
                long ans = dps[l][k];
                List<Integer> carr = arrs.get(l);
                long sum = 0;
                for (int i = 0; i < Math.min(k, carr.size()); i++) {
                    sum += carr.get(i);
                    ans = Math.max(ans, dps[l][k - i - 1] + sum);
                }
                return ans;
            } else {
                int m = (l + r) / 2;
                long[][] newDps = new long[13][k + 1];
                for (int i = l; i < m; i++) {
                    System.arraycopy(dps[i + 1], 0, newDps[i + 1], 0, k + 1);
                }
                long ans = rec(m, r, k, newDps, sums, arrs);
                for (int i = m; i < r; i++) {
                    System.arraycopy(dps[i + 1], 0, newDps[i + 1], 0, k + 1);
                }
                ans = Math.max(ans, rec(l, m, k, newDps, sums, arrs));
                return ans;
            }
        }
    }

    public static void solve(BufferedReader in, PrintWriter out) throws IOException {
        Solver solver = new Solver(in, out);
        solver.solve();
    }

    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter out = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
        solve(in, out);
        out.close();
    }
}

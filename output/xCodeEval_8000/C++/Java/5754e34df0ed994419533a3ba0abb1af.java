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

        public void solve() throws IOException {
            StringTokenizer st = new StringTokenizer(in.readLine());
            int n = Integer.parseInt(st.nextToken());
            int k = Integer.parseInt(st.nextToken());

            List<List<Integer>> arrs = new ArrayList<>();
            for (int i = 0; i < n; i++) {
                st = new StringTokenizer(in.readLine());
                int t = Integer.parseInt(st.nextToken());
                List<Integer> arr = new ArrayList<>();
                for (int j = 0; j < t; j++) {
                    arr.add(Integer.parseInt(st.nextToken()));
                }
                arrs.add(arr);
            }

            long[] sums = new long[n];
            for (int i = 0; i < n; i++) {
                List<Integer> arr = arrs.get(i);
                long sum = 0;
                for (int j = 0; j < arr.size(); j++) {
                    sum += arr.get(j);
                }
                sums[i] = sum;
            }

            long[][] dps = new long[13][k + 1];
            for (int i = 0; i < n; i++) {
                List<Integer> arr = arrs.get(i);
                long v = sums[i];
                int k1 = arr.size();
                for (int j = k; j >= k1; j--) {
                    dps[0][j] = Math.max(dps[0][j], dps[0][j - k1] + v);
                }
            }

            for (int dpi = 0; dpi < 12; dpi++) {
                for (int j = 0; j <= k; j++) {
                    dps[dpi + 1][j] = dps[dpi][j];
                }
            }

            for (int l = 0; l < n; l++) {
                for (int dpi = 0; dpi < 12; dpi++) {
                    List<Integer> carr = arrs.get(l);
                    long[] dp = dps[dpi];
                    if (l + 1 == n) {
                        long ans = dp[k];
                        long sum = 0;
                        for (int i = 0; i < Math.min(k, carr.size()); i++) {
                            sum += carr.get(i);
                            ans = Math.max(ans, dp[k - i - 1] + sum);
                        }
                        out.println(ans);
                    } else {
                        int m = (l + n) / 2;
                        long ans = Math.max(doSplit(l, m, m, n, dpi + 1), doSplit(m, n, l, m, dpi + 1));
                        out.println(ans);
                    }
                }
            }
        }

        private long doSplit(int l1, int r1, int l2, int r2, int dpi) {
            for (int i = l1; i < r1; i++) {
                addToknap(i, dpi);
            }
            return rec(l2, r2, dpi);
        }

        private void addToknap(int i, int dpi) {
            long v = sums[i];
            List<Integer> arr = arrs.get(i);
            int k1 = arr.size();
            for (int j = k; j >= k1; j--) {
                dps[dpi][j] = Math.max(dps[dpi][j], dps[dpi][j - k1] + v);
            }
        }

        private long rec(int l, int r, int dpi) {
            long ans = 0;
            if (l + 1 == r) {
                ans = dps[dpi][k];
                List<Integer> carr = arrs.get(l);
                long sum = 0;
                for (int i = 0; i < Math.min(k, carr.size()); i++) {
                    sum += carr.get(i);
                    ans = Math.max(ans, dps[dpi][k - i - 1] + sum);
                }
            } else {
                int m = (l + r) / 2;
                ans = Math.max(doSplit(l, m, m, r, dpi), doSplit(m, r, l, m, dpi));
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

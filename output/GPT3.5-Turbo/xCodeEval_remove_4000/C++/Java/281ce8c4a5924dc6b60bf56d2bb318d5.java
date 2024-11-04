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

        private void solve() throws IOException {
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
                if (t > k) {
                    int[] newArr = new int[k];
                    System.arraycopy(arrs[i], 0, newArr, 0, k);
                    arrs[i] = newArr;
                }
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

            long ans = rec(0, n, 0, dps, arrs, sums, k);
            out.println(ans);
        }

        private long rec(int l, int r, int dpi, long[][] dps, int[][] arrs, long[] sums, int k) {
            long ans = 0;
            if (l + 1 == r) {
                ans = dps[dpi][k];
                long sum = 0;
                for (int i = 0; i < Math.min(k, arrs[l].length); i++) {
                    sum += arrs[l][i];
                    ans = Math.max(ans, dps[dpi][k - i - 1] + sum);
                }
            } else {
                int m = (l + r) / 2;
                ans = Math.max(rec(l, m, dpi + 1, dps, arrs, sums, k),
                        rec(m, r, dpi + 1, dps, arrs, sums, k));
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

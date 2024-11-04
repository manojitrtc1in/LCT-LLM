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

        private void solve() throws IOException {
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

            long[][] dp = new long[13][k + 1];
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < k + 1; j++) {
                    dp[i + 1][j] = dp[i][j];
                }
                for (int j = k; j >= arrs[i].length; j--) {
                    dp[i + 1][j] = Math.max(dp[i + 1][j], dp[i + 1][j - arrs[i].length] + sums[i]);
                }
            }

            out.println(dp[n][k]);
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter out = new PrintWriter(System.out);
        Solver solver = new Solver(in, out);
        solver.solve();
        out.close();
    }
}

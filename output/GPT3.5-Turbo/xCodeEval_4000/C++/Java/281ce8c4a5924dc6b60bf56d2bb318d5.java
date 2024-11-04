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

        private void read(int[] arr) throws IOException {
            StringTokenizer st = new StringTokenizer(in.readLine());
            for (int i = 0; i < arr.length; i++) {
                arr[i] = Integer.parseInt(st.nextToken());
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

        private long sum(int[] arr) {
            long sum = 0;
            for (int num : arr) {
                sum += num;
            }
            return sum;
        }

        private void solve() throws IOException {
            StringTokenizer st = new StringTokenizer(in.readLine());
            int n = Integer.parseInt(st.nextToken());
            int k = Integer.parseInt(st.nextToken());

            int[][] arrs = new int[n][];
            for (int i = 0; i < n; i++) {
                st = new StringTokenizer(in.readLine());
                int t = Integer.parseInt(st.nextToken());
                arrs[i] = new int[t];
                read(arrs[i]);
                if (t > k) {
                    arrs[i] = Arrays.copyOf(arrs[i], k);
                }
            }

            long[] sums = new long[n];
            for (int i = 0; i < n; i++) {
                sums[i] = sum(arrs[i]);
            }

            long[][] dps = new long[13][k + 1];
            for (int i = 0; i < n; i++) {
                int[] carr = arrs[i];
                long[] dp = dps[0];
                for (int j = k; j >= 0; j--) {
                    dp[j] = Math.max(dp[j], j >= carr.length ? dp[j - carr.length] + sums[i] : 0);
                }
            }

            for (int dpi = 0; dpi < 12; dpi++) {
                System.arraycopy(dps[dpi], 0, dps[dpi + 1], 0, k + 1);
            }

            println(dps[12][k]);
        }
    }

    public static void solve(InputStream in, OutputStream out) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(in));
        PrintWriter writer = new PrintWriter(new BufferedWriter(new OutputStreamWriter(out)));
        Solver solver = new Solver(reader, writer);
        solver.solve();
        writer.flush();
    }

    public static void main(String[] args) throws IOException {
        solve(System.in, System.out);
    }
}

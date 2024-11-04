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
                arrs.add(arr);
                sums[i] = arr.stream().mapToLong(Integer::longValue).sum();
            }

            long[][] dps = new long[13][k + 1];
            for (int i = 0; i < n; i++) {
                List<Integer> carr = arrs.get(i);
                long[] dp = dps[0];
                if (i > 0) {
                    dp = Arrays.copyOf(dps[i - 1], k + 1);
                }
                if (i > 0) {
                    for (int j = k; j >= carr.size(); j--) {
                        dp[j] = Math.max(dp[j], dp[j - carr.size()] + sums[i]);
                    }
                }
                for (int j = 0; j < k && j < carr.size(); j++) {
                    long sum = 0;
                    for (int l = 0; l <= j; l++) {
                        sum += carr.get(l);
                    }
                    dp[k - j - 1] = Math.max(dp[k - j - 1], sum);
                }
                dps[i] = dp;
            }

            out.println(dps[n - 1][k]);
        }
    }

    public static void solve(InputStream in, OutputStream out) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(in));
        PrintWriter pw = new PrintWriter(out);
        Solver solver = new Solver(br, pw);
        solver.solve();
        pw.flush();
    }

    public static void main(String[] args) throws IOException {
        solve(System.in, System.out);
    }
}

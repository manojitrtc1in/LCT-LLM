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

            List<List<Integer>> arrs = new ArrayList<>();
            List<Long> sums = new ArrayList<>();

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
                long sum = 0;
                for (int num : arr) {
                    sum += num;
                }
                sums.add(sum);
            }

            long[][] dp = new long[13][k + 1];
            for (int i = 0; i < n; i++) {
                List<Integer> carr = arrs.get(i);
                long[] curDp = dp[0];
                for (int j = 0; j <= k; j++) {
                    curDp[j] = dp[1][j];
                }
                for (int j = k; j >= carr.size(); j--) {
                    curDp[j] = Math.max(curDp[j], curDp[j - carr.size()] + sums.get(i));
                }
                for (int j = 1; j <= 12; j++) {
                    curDp = dp[j];
                    for (int l = 0; l <= k; l++) {
                        curDp[l] = dp[j + 1][l];
                    }
                    for (int l = k; l >= carr.size(); l--) {
                        curDp[l] = Math.max(curDp[l], curDp[l - carr.size()] + sums.get(i));
                    }
                }
            }

            out.println(dp[0][k]);
        }
    }

    public static void solve(InputStream in, OutputStream out) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(in));
        PrintWriter pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(out)));
        Solver solver = new Solver(br, pw);
        solver.solve();
        pw.close();
    }

    public static void main(String[] args) throws IOException {
        solve(System.in, System.out);
    }
}

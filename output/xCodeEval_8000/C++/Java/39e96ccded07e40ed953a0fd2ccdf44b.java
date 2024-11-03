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
                int t = arrs.get(i).size();
                for (int j = k; j >= t; j--) {
                    dps[0][j] = Math.max(dps[0][j], dps[0][j - t] + sums[i]);
                }
            }

            for (int i = 1; i <= 12; i++) {
                System.arraycopy(dps[i - 1], 0, dps[i], 0, k + 1);
                for (int j = 0; j < n; j++) {
                    int t = arrs.get(j).size();
                    for (int l = k; l >= t; l--) {
                        dps[i][l] = Math.max(dps[i][l], dps[i - 1][l - t] + sums[j]);
                    }
                }
            }

            out.println(dps[12][k]);
        }
    }

    public static void solve(BufferedReader in, PrintWriter out) throws IOException {
        new Solver(in, out).solve();
    }

    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter out = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
        solve(in, out);
        out.close();
    }
}

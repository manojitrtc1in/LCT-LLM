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
                int m = arrs.get(i).size();
                for (int j = k; j >= m; j--) {
                    dps[i + 1][j] = Math.max(dps[i + 1][j], dps[i][j - m] + sums[i]);
                }
                for (int j = 0; j < m; j++) {
                    long sum = 0;
                    for (int l = 0; l <= j; l++) {
                        sum += arrs.get(i).get(l);
                    }
                    dps[i + 1][j] = Math.max(dps[i + 1][j], dps[i][k - j - 1] + sum);
                }
            }

            out.println(dps[n][k]);
        }
    }

    public static void solve(InputStream in, OutputStream out) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(in));
        PrintWriter writer = new PrintWriter(new BufferedWriter(new OutputStreamWriter(out)));
        new Solver(reader, writer).solve();
        writer.flush();
    }

    public static void main(String[] args) throws IOException {
        solve(System.in, System.out);
    }
}

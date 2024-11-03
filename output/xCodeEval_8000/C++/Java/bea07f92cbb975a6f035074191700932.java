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
                int[][] dpCopy = new int[13][k + 1];
                for (int j = 0; j <= k; j++) {
                    dpCopy[0][j] = dps[0][j];
                }
                for (int j = 0; j <= k; j++) {
                    for (int l = 0; l <= arrs.get(i).size(); l++) {
                        if (j - l >= 0) {
                            dpCopy[0][j] = Math.max(dpCopy[0][j], dpCopy[0][j - l] + sums[i]);
                        }
                    }
                }
                for (int j = 1; j <= 12; j++) {
                    for (int l = 0; l <= k; l++) {
                        dpCopy[j][l] = dpCopy[j - 1][l];
                    }
                    for (int l = 0; l <= k - arrs.get(i).size(); l++) {
                        dpCopy[j][l + arrs.get(i).size()] = Math.max(dpCopy[j][l + arrs.get(i).size()], dpCopy[j - 1][l] + sums[i]);
                    }
                }
                for (int j = 0; j <= k; j++) {
                    dps[j] = dpCopy[12][j];
                }
            }

            out.println(dps[k]);
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

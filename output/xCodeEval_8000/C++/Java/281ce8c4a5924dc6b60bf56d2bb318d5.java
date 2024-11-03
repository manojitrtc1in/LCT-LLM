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
                if (t > k) {
                    arr = arr.subList(0, k);
                }
                arrs.add(arr);
            }

            long[] sums = new long[n];
            for (int i = 0; i < n; i++) {
                for (int num : arrs.get(i)) {
                    sums[i] += num;
                }
            }

            long[][] dps = new long[13][k + 1];
            for (int i = 0; i < n; i++) {
                for (int j = k; j >= arrs.get(i).size(); j--) {
                    dps[0][j] = Math.max(dps[0][j], dps[0][j - arrs.get(i).size()] + sums[i]);
                }
            }

            for (int dpi = 0; dpi < 12; dpi++) {
                for (int j = 0; j <= k; j++) {
                    dps[dpi + 1][j] = dps[dpi][j];
                }
                for (int i = 0; i < n; i++) {
                    List<Integer> carr = arrs.get(i);
                    for (int j = k; j >= carr.size(); j--) {
                        dps[dpi + 1][j] = Math.max(dps[dpi + 1][j], dps[dpi][j - carr.size()] + sums[i]);
                    }
                }
            }

            out.println(dps[12][k]);
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

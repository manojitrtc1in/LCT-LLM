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

        private void readInts(int[] arr) throws IOException {
            String[] parts = in.readLine().split(" ");
            for (int i = 0; i < arr.length; i++) {
                arr[i] = Integer.parseInt(parts[i]);
            }
        }

        private void print(Object obj) {
            out.print(obj);
        }

        private void println(Object obj) {
            out.println(obj);
        }

        private long rec(int l, int r, int k, List<List<Integer>> arrs, List<Long> sums, List<List<Long>> dps) {
            long ans = 0;
            List<Long> carr = arrs.get(l);
            List<Long> dp = dps.get(k);
            if (l + 1 == r) {
                ans = Math.max(ans, dp.get(k));
                long sum = 0;
                for (int i = 0; i < Math.min(k, carr.size()); i++) {
                    sum += carr.get(i);
                    ans = Math.max(ans, dp.get(k - i - 1) + sum);
                }
            } else {
                int m = (l + r) / 2;
                List<Long> newDp = new ArrayList<>(dps.get(k));
                for (int i = l; i < m - 1; i++) {
                    add_to_knap(i, newDp, arrs, sums, k);
                }
                ans = Math.max(ans, rec(m, r, k, arrs, sums, newDp));
                newDp = new ArrayList<>(dps.get(k));
                for (int i = m; i < r - 1; i++) {
                    add_to_knap(i, newDp, arrs, sums, k);
                }
                ans = Math.max(ans, rec(l, m, k, arrs, sums, newDp));
            }
            return ans;
        }

        private void add_to_knap(int i, List<Long> dp, List<List<Integer>> arrs, List<Long> sums, int k) {
            long v = sums.get(i);
            List<Integer> carr = arrs.get(i);
            int k1 = carr.size();
            for (int j = k; j >= k1; j--) {
                dp.set(j, Math.max(dp.get(j), dp.get(j - k1) + v));
            }
        }

        public void solve() throws IOException {
            int[] nk = new int[2];
            readInts(nk);
            int n = nk[0];
            int k = nk[1];
            List<List<Integer>> arrs = new ArrayList<>();
            List<Long> sums = new ArrayList<>();
            for (int i = 0; i < n; i++) {
                int t = Integer.parseInt(in.readLine());
                List<Integer> arr = new ArrayList<>();
                readInts(arr);
                if (t > k) {
                    arr = arr.subList(0, k);
                }
                arrs.add(arr);
                long sum = 0;
                for (int j = 0; j < arr.size(); j++) {
                    sum += arr.get(j);
                }
                sums.add(sum);
            }
            List<List<Long>> dps = new ArrayList<>();
            for (int i = 0; i <= 12; i++) {
                dps.add(new ArrayList<>(Collections.nCopies(k + 1, 0L)));
            }
            println(rec(0, n, k, arrs, sums, dps));
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

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

        private long rec(int l, int r, long[][] dps, long[] sums, List<List<Integer>> arrs, int k) {
            long ans = 0;
            List<Integer> carr = arrs.get(l);
            long[] dp = dps[l];
            if (l + 1 == r) {
                ans = Math.max(ans, dp[k]);
                long sum = 0;
                for (int i = 0; i < Math.min(k, carr.size()); i++) {
                    sum += carr.get(i);
                    ans = Math.max(ans, dp[k - i - 1] + sum);
                }
            } else {
                int m = (l + r) / 2;
                ans = Math.max(ans, doSplit(l, m, m, r, dps, sums, arrs, k));
                ans = Math.max(ans, doSplit(m, r, l, m, dps, sums, arrs, k));
            }
            return ans;
        }

        private long doSplit(int l1, int r1, int l2, int r2, long[][] dps, long[] sums, List<List<Integer>> arrs, int k) {
            long[][] newDps = new long[13][k + 1];
            for (int i = 0; i < newDps.length; i++) {
                System.arraycopy(dps[i], 0, newDps[i], 0, k + 1);
            }
            for (int i = l1; i < r1; i++) {
                addtoKnap(i, newDps, sums, arrs, k, i + 1);
            }
            return rec(l2, r2, newDps, sums, arrs, k);
        }

        private void addtoKnap(int i, long[][] dps, long[] sums, List<List<Integer>> arrs, int k, int dpi) {
            long v = sums[i];
            int k1 = arrs.get(i).size();
            for (int j = k; j >= k1; j--) {
                dps[dpi][j] = Math.max(dps[dpi][j], dps[dpi][j - k1] + v);
            }
        }

        public void solve() throws IOException {
            int[] nk = new int[2];
            readInts(nk);
            int n = nk[0];
            int k = nk[1];
            long[] sums = new long[n];
            List<List<Integer>> arrs = new ArrayList<>();
            for (int i = 0; i < n; i++) {
                int t = Integer.parseInt(in.readLine());
                List<Integer> arr = new ArrayList<>();
                readInts(arr);
                if (t > k) {
                    arr = arr.subList(0, k);
                }
                arrs.add(arr);
                sums[i] = arr.stream().mapToLong(Integer::longValue).sum();
            }
            long[][] dps = new long[13][k + 1];
            println(rec(0, n, dps, sums, arrs, k));
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

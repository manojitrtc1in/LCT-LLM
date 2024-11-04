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

        private void readInts(int[]... arrays) throws IOException {
            for (int[] array : arrays) {
                for (int i = 0; i < array.length; i++) {
                    array[i] = Integer.parseInt(in.readLine());
                }
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

        private long sum(List<Integer> arr) {
            long sum = 0;
            for (int num : arr) {
                sum += num;
            }
            return sum;
        }

        private void solve() throws IOException {
            int n, k;
            int[] t;
            List<List<Integer>> arrs = new ArrayList<>();
            n = Integer.parseInt(in.readLine());
            t = new int[n];
            readInts(t);
            for (int i = 0; i < n; i++) {
                int[] arr = new int[t[i]];
                readInts(arr);
                arrs.add(Arrays.asList(arr));
            }

            long[] sums = new long[n];
            for (int i = 0; i < n; i++) {
                sums[i] = sum(arrs.get(i));
            }

            long[][] dps = new long[13][k + 1];
            for (int i = 0; i < n; i++) {
                int k1 = arrs.get(i).size();
                for (int j = k; j >= k1; j--) {
                    dps[0][j] = Math.max(dps[0][j], dps[0][j - k1] + sums[i]);
                }
            }

            for (int dpi = 0; dpi < 12; dpi++) {
                System.arraycopy(dps[dpi], 0, dps[dpi + 1], 0, k + 1);
            }

            long ans = 0;
            for (int l = 0; l < n; l++) {
                int r = l + 1;
                long[] carr = arrs.get(l).stream().mapToLong(i -> i).toArray();
                long[] dp = dps[0];
                if (l + 1 == r) {
                    ans = Math.max(ans, dp[k]);
                    long sum = 0;
                    for (int i = 0; i < Math.min(k, carr.length); i++) {
                        sum += carr[i];
                        ans = Math.max(ans, dp[k - i - 1] + sum);
                    }
                } else {
                    int m = (l + r) / 2;
                    long ans1 = doSplit(l, m, m, r, dps);
                    long ans2 = doSplit(m, r, l, m, dps);
                    ans = Math.max(ans, Math.max(ans1, ans2));
                }
            }

            println(ans);
        }

        private long doSplit(int l1, int r1, int l2, int r2, long[][] dps) {
            System.arraycopy(dps[0], 0, dps[1], 0, dps[0].length);
            for (int i = l1; i < r1; i++) {
                int k1 = arrs.get(i).size();
                for (int j = k; j >= k1; j--) {
                    dps[1][j] = Math.max(dps[1][j], dps[1][j - k1] + sums[i]);
                }
            }
            return rec(l2, r2, 1, dps);
        }

        private long rec(int l, int r, int dpi, long[][] dps) {
            long ans = 0;
            long[] carr = arrs.get(l).stream().mapToLong(i -> i).toArray();
            long[] dp = dps[dpi];
            if (l + 1 == r) {
                ans = dp[k];
                long sum = 0;
                for (int i = 0; i < Math.min(k, carr.length); i++) {
                    sum += carr[i];
                    ans = Math.max(ans, dp[k - i - 1] + sum);
                }
            } else {
                int m = (l + r) / 2;
                long ans1 = doSplit(l, m, m, r, dps);
                long ans2 = doSplit(m, r, l, m, dps);
                ans = Math.max(ans, Math.max(ans1, ans2));
            }
            return ans;
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

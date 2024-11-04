import java.util.*;
import java.io.*;

class DSum {
    static class Solver {
        BufferedReader in;
        PrintWriter out;

        Solver(BufferedReader in, PrintWriter out) {
            this.in = in;
            this.out = out;
        }

        void read(int[] args) throws IOException {
            StringTokenizer st = new StringTokenizer(in.readLine());
            for (int i = 0; i < args.length; i++) {
                args[i] = Integer.parseInt(st.nextToken());
            }
        }

        void print(long... args) {
            for (long arg : args) {
                out.print(arg + " ");
            }
        }

        void println(long... args) {
            print(args);
            out.println();
        }

        void solve() throws IOException {
            int n, k;
            int[] nk = new int[2];
            read(nk);
            n = nk[0];
            k = nk[1];

            List<List<Integer>> arrs = new ArrayList<>();
            for (int i = 0; i < n; i++) {
                int t = Integer.parseInt(in.readLine());
                List<Integer> arr = new ArrayList<>();
                StringTokenizer st = new StringTokenizer(in.readLine());
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
                sums[i] = arrs.get(i).stream().mapToLong(Integer::longValue).sum();
            }

            long[][] dps = new long[13][k + 1];
            Arrays.fill(dps[0], 0);

            long ans = id13(0, n, 0, arrs, sums, dps, k);
            println(ans);
        }

        long id13(int l, int r, int dpi, List<List<Integer>> arrs, long[] sums, long[][] dps, int k) {
            long ans = 0;
            List<Integer> carr = arrs.get(l);
            long[] dp = dps[dpi];

            if (l + 1 == r) {
                ans = Math.max(ans, dp[k]);
                long sum = 0;
                for (int i = 0; i < Math.min(k, carr.size()); i++) {
                    sum += carr.get(i);
                    ans = Math.max(ans, dp[k - i - 1] + sum);
                }
            } else {
                int m = (l + r) / 2;
                ans = Math.max(ans, doSplit(l, m, m, r, dpi, arrs, sums, dps, k));
                ans = Math.max(ans, doSplit(m, r, l, m, dpi, arrs, sums, dps, k));
            }
            return ans;
        }

        long doSplit(int l1, int r1, int l2, int r2, int dpi, List<List<Integer>> arrs, long[] sums, long[][] dps, int k) {
            System.arraycopy(dps[dpi], 0, dps[dpi + 1], 0, k + 1);
            for (int i = l1; i < r1; i++) {
                id14(i, dpi + 1, arrs, sums, dps, k);
            }
            return id13(l2, r2, dpi + 1, arrs, sums, dps, k);
        }

        void id14(int i, int dpi, List<List<Integer>> arrs, long[] sums, long[][] dps, int k) {
            long v = sums[i];
            int k1 = arrs.get(i).size();
            for (int j = k; j >= k1; j--) {
                dps[dpi][j] = Math.max(dps[dpi][j], dps[dpi][j - k1] + v);
            }
        }
    }

    public static void solve(BufferedReader in, PrintWriter out) throws IOException {
        new Solver(in, out).solve();
    }

    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter out = new PrintWriter(System.out);
        solve(in, out);
        out.close();
    }
}

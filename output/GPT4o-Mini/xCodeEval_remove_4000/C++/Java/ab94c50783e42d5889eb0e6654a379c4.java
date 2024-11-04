import java.util.*;
import java.io.*;

class DSum {
    static class Solver {
        BufferedReader in;
        PrintWriter out;
        int k;
        long[][] dps;
        long[] sums;
        List<List<Long>> arrs;

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

        void read(long[] args) throws IOException {
            StringTokenizer st = new StringTokenizer(in.readLine());
            for (int i = 0; i < args.length; i++) {
                args[i] = Long.parseLong(st.nextToken());
            }
        }

        void println(long value) {
            out.println(value);
        }

        void doCopy(int dpi) {
            System.arraycopy(dps[dpi], 0, dps[dpi + 1], 0, (k + 1));
        }

        void addToKnap(int i, int dpi) {
            long v = sums[i];
            int k1 = arrs.get(i).size();
            for (int j = k; j >= k1; j--) {
                dps[dpi][j] = Math.max(dps[dpi][j], dps[dpi][j - k1] + v);
            }
        }

        long rec(int l, int r, int dpi) {
            long ans = 0;
            List<Long> carr = arrs.get(l);
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
                ans = Math.max(ans, doSplit(l, m, m, r, dpi));
                ans = Math.max(ans, doSplit(m, r, l, m, dpi));
            }
            return ans;
        }

        long doSplit(int l1, int r1, int l2, int r2, int dpi) {
            doCopy(dpi);
            for (int i = l1; i < r1; i++) {
                addToKnap(i, dpi + 1);
            }
            return rec(l2, r2, dpi + 1);
        }

        void solve() throws IOException {
            int n = Integer.parseInt(in.readLine());
            int[] nk = new int[2];
            read(nk);
            n = nk[0];
            k = nk[1];
            sums = new long[n];
            arrs = new ArrayList<>(n);
            for (int i = 0; i < n; i++) {
                StringTokenizer st = new StringTokenizer(in.readLine());
                int t = Integer.parseInt(st.nextToken());
                List<Long> arr = new ArrayList<>();
                for (int j = 0; j < t; j++) {
                    arr.add(Long.parseLong(st.nextToken()));
                }
                if (t > k) {
                    arr = arr.subList(0, k);
                }
                arrs.add(arr);
                sums[i] = arr.stream().mapToLong(Long::longValue).sum();
            }
            dps = new long[13][k + 1];
            println(rec(0, n, 0));
        }
    }

    static void solve(BufferedReader in, PrintWriter out) throws IOException {
        new Solver(in, out).solve();
    }

    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter out = new PrintWriter(System.out);
        solve(in, out);
        out.close();
    }
}

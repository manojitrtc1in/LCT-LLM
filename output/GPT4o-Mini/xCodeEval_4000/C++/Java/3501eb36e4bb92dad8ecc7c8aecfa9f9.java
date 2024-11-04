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

        void rd(long[] args) throws IOException {
            StringTokenizer st = new StringTokenizer(in.readLine());
            for (int i = 0; i < args.length; i++) {
                args[i] = Long.parseLong(st.nextToken());
            }
        }

        void prln(long result) {
            out.println(result);
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
                doCopy(dpi);
                for (int i = l; i < m; i++) {
                    addToKnap(i, dpi + 1);
                }
                ans = Math.max(ans, rec(m, r, dpi + 1));
                doCopy(dpi);
                for (int i = m; i < r; i++) {
                    addToKnap(i, dpi + 1);
                }
                ans = Math.max(ans, rec(l, m, dpi + 1));
            }
            return ans;
        }

        void solve() throws IOException {
            int n;
            long[] nk = new long[2];
            rd(nk);
            n = (int) nk[0];
            k = (int) nk[1];
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
            prln(rec(0, n, 0));
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
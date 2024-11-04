import java.io.*;
import java.util.*;
import java.util.function.Function;

public class c3bcbeddc568924dca3333ae8d7a77d9_nc {
    static class Solver {
        private final BufferedReader in;
        private final PrintWriter out;
        private int k;
        private long[][] dps;
        private long[] sums;
        private List<List<Long>> arrs;

        Solver(InputStream input, OutputStream output) {
            in = new BufferedReader(new InputStreamReader(input));
            out = new PrintWriter(output);
        }

        private void readInt(int[] args) throws IOException {
            StringTokenizer st = new StringTokenizer(in.readLine());
            for (int i = 0; i < args.length; i++) {
                args[i] = Integer.parseInt(st.nextToken());
            }
        }

        private void readLong(long[] args) throws IOException {
            StringTokenizer st = new StringTokenizer(in.readLine());
            for (int i = 0; i < args.length; i++) {
                args[i] = Long.parseLong(st.nextToken());
            }
        }

        private void doCopy(int dpi) {
            System.arraycopy(dps[dpi], 0, dps[dpi + 1], 0, dps[0].length);
        }

        private void addToKnap(int i, int dpi) {
            long v = sums[i];
            int k1 = arrs.get(i).size();
            for (int j = k; j >= k1; j--) {
                dps[dpi][j] = Math.max(dps[dpi][j], dps[dpi][j - k1] + v);
            }
        }

        private long rec(int l, int r, int dpi) {
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
            int n = Integer.parseInt(in.readLine());
            k = Integer.parseInt(in.readLine());
            sums = new long[n];
            arrs = new ArrayList<>(n);
            for (int i = 0; i < n; i++) {
                String[] line = in.readLine().split(" ");
                int t = Integer.parseInt(line[0]);
                List<Long> arr = new ArrayList<>();
                for (int j = 1; j <= t; j++) {
                    arr.add(Long.parseLong(line[j]));
                }
                if (t > k) {
                    arr = arr.subList(0, k);
                }
                arrs.add(arr);
                sums[i] = arr.stream().mapToLong(Long::longValue).sum();
            }
            dps = new long[13][k + 1];
            out.println(rec(0, n, 0));
        }
    }

    public static void main(String[] args) throws IOException {
        DSum solver = new DSum();
        solver.solve(System.in, System.out);
    }
}
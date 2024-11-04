import java.io.*;
import java.util.*;
import java.util.function.*;
import java.util.stream.*;

public class 5754e34df0ed994419533a3ba0abb1af_nc {
    static class Solver {
        BufferedReader in;
        PrintWriter out;

        Solver(BufferedReader in, PrintWriter out) {
            this.in = in;
            this.out = out;
        }

        void solve() throws IOException {
            StringTokenizer st = new StringTokenizer(in.readLine());
            int n = Integer.parseInt(st.nextToken());
            int k = Integer.parseInt(st.nextToken());
            List<List<Integer>> arrs = new ArrayList<>();
            long[] sums = new long[n];

            for (int i = 0; i < n; i++) {
                st = new StringTokenizer(in.readLine());
                int t = Integer.parseInt(st.nextToken());
                List<Integer> arr = new ArrayList<>();
                for (int j = 0; j < t; j++) {
                    arr.add(Integer.parseInt(st.nextToken()));
                }
                arrs.add(arr);
                sums[i] = arr.stream().mapToLong(Integer::longValue).sum();
            }

            long[][] dps = new long[13][k + 1];

            BiConsumer<Integer> doCopy = (dpi) -> {
                System.arraycopy(dps[dpi], 0, dps[dpi + 1], 0, k + 1);
            };

            BiConsumer<Integer, Integer> addToKnap = (i, dpi) -> {
                long v = sums[i];
                int k1 = arrs.get(i).size();
                for (int j = k; j >= k1; j--) {
                    dps[dpi][j] = Math.max(dps[dpi][j], dps[dpi][j - k1] + v);
                }
            };

            long ans = yCombinator((rec, l, r, dpi) -> {
                long result = 0;
                List<Integer> carr = arrs.get(l);
                long[] dp = dps[dpi];

                if (l + 1 == r) {
                    result = Math.max(result, dp[k]);
                    long sum = 0;
                    for (int i = 0; i < Math.min(k, carr.size()); i++) {
                        sum += carr.get(i);
                        result = Math.max(result, dp[k - i - 1] + sum);
                    }
                } else {
                    int m = (l + r) / 2;
                    result = Math.max(result, doSplit(l, m, m, r, dpi, addToKnap, doCopy, rec));
                    result = Math.max(result, doSplit(m, r, l, m, dpi, addToKnap, doCopy, rec));
                }
                return result;
            }).apply(0, n, 0);

            out.println(ans);
        }

        private long doSplit(int l1, int r1, int l2, int r2, int dpi, BiConsumer<Integer, Integer> addToKnap, BiConsumer<Integer> doCopy, BiFunction<BiFunction<Integer, Integer, Integer>, Integer, Long> rec) {
            doCopy.accept(dpi);
            for (int i = l1; i < r1; i++) {
                addToKnap.accept(i, dpi + 1);
            }
            return rec.apply((x, y) -> rec.apply(x, y), l2, r2, dpi + 1);
        }

        private <R> BiFunction<BiFunction<Integer, Integer, Integer>, Integer, R> yCombinator(BiFunction<BiFunction<Integer, Integer, Integer>, Integer, R> f) {
            return new BiFunction<BiFunction<Integer, Integer, Integer>, Integer, R>() {
                @Override
                public R apply(BiFunction<Integer, Integer, Integer> rec, Integer arg1, Integer arg2) {
                    return f.apply(this, arg1, arg2);
                }
            };
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter out = new PrintWriter(System.out);
        new Solver(in, out).solve();
        out.close();
    }
}

import java.util.*;
import java.io.*;

class DSum {
    static class Solver {
        private final BufferedReader in;
        private final PrintWriter out;
        private int N, K;
        private List<List<Long>> A;
        private long[] A_sum;
        private long best;

        Solver(BufferedReader in, PrintWriter out) {
            this.in = in;
            this.out = out;
        }

        private void rd() throws IOException {
            StringTokenizer st = new StringTokenizer(in.readLine());
            N = Integer.parseInt(st.nextToken());
            K = Integer.parseInt(st.nextToken());
        }

        private void prln(long result) {
            out.println(result);
        }

        private void addItem(long[] knapsack, int size, long sum) {
            for (int k = K - size; k >= 0; k--) {
                knapsack[k + size] = Math.max(knapsack[k + size], knapsack[k] + sum);
            }
        }

        private void recurse(int start, int end, long[] knapsack) {
            if (start >= end) return;

            if (end - start == 1) {
                long sum = 0;
                best = Math.max(best, knapsack[K]);

                for (int prefix = 1; prefix <= A.get(start).size(); prefix++) {
                    sum += A.get(start).get(prefix - 1);
                    best = Math.max(best, sum + knapsack[K - prefix]);
                }
                return;
            }

            int mid = (start + end) / 2;
            long[] state = knapsack.clone();

            for (int i = start; i < mid; i++) {
                addItem(state, A.get(i).size(), A_sum[i]);
            }

            recurse(mid, end, state);
            state = knapsack.clone();

            for (int i = mid; i < end; i++) {
                addItem(state, A.get(i).size(), A_sum[i]);
            }

            recurse(start, mid, state);
        }

        private void solve() throws IOException {
            rd();
            A = new ArrayList<>(N);
            A_sum = new long[N];

            for (int i = 0; i < N; i++) {
                StringTokenizer st = new StringTokenizer(in.readLine());
                int t = Integer.parseInt(st.nextToken());
                List<Long> list = new ArrayList<>();

                for (int j = 0; j < t; j++) {
                    list.add(Long.parseLong(st.nextToken()));
                }

                if (t > K) {
                    list = list.subList(0, K);
                }

                A.add(list);
                A_sum[i] = list.stream().mapToLong(Long::longValue).sum();
            }

            best = 0;
            long[] knapsack = new long[K + 1];
            recurse(0, N, knapsack);
            prln(best);
        }
    }

    public static void solve(InputStream inputStream, OutputStream outputStream) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(inputStream));
        PrintWriter out = new PrintWriter(outputStream);
        new Solver(in, out).solve();
        out.flush();
    }

    public static void main(String[] args) throws IOException {
        solve(System.in, System.out);
    }
}

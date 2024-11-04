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

        private void add_item(long[] knapsack, int size, long sum) {
            for (int k = knapsack.length - size; k >= 0; k--) {
                knapsack[k + size] = Math.max(knapsack[k + size], knapsack[k] + sum);
            }
        }

        private void recurse(int start, int end, long[] knapsack, List<List<Long>> A, long[] A_sum) {
            if (start >= end) {
                return;
            }

            if (end - start == 1) {
                long sum = 0;
                long best = knapsack[knapsack.length - 1];

                for (int prefix = 1; prefix <= A.get(start).size(); prefix++) {
                    sum += A.get(start).get(prefix - 1);
                    best = Math.max(best, sum + knapsack[knapsack.length - prefix]);
                }

                out.println(best);
                return;
            }

            int mid = (start + end) / 2;
            long[] state = Arrays.copyOf(knapsack, knapsack.length);

            for (int i = start; i < mid; i++) {
                add_item(state, A.get(i).size(), A_sum[i]);
            }

            recurse(mid, end, state, A, A_sum);
            state = Arrays.copyOf(knapsack, knapsack.length);

            for (int i = mid; i < end; i++) {
                add_item(state, A.get(i).size(), A_sum[i]);
            }

            recurse(start, mid, state, A, A_sum);
        }

        public void solve() throws IOException {
            StringTokenizer st = new StringTokenizer(in.readLine());
            int N = Integer.parseInt(st.nextToken());
            int K = Integer.parseInt(st.nextToken());

            List<List<Long>> A = new ArrayList<>();
            long[] A_sum = new long[N];

            for (int i = 0; i < N; i++) {
                st = new StringTokenizer(in.readLine());
                int t = Integer.parseInt(st.nextToken());
                List<Long> list = new ArrayList<>();

                for (int j = 0; j < t; j++) {
                    list.add(Long.parseLong(st.nextToken()));
                }

                if (t > K) {
                    list = list.subList(0, K);
                }

                A.add(list);

                long sum = 0;
                for (long num : list) {
                    sum += num;
                }
                A_sum[i] = sum;
            }

            long[] knapsack = new long[K + 1];
            recurse(0, N, knapsack, A, A_sum);
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter out = new PrintWriter(System.out);
        Solver solver = new Solver(in, out);
        solver.solve();
        out.close();
    }
}

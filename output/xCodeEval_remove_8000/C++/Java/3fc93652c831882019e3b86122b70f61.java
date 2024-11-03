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

        public void solve() throws IOException {
            StringTokenizer st = new StringTokenizer(in.readLine());
            int N = Integer.parseInt(st.nextToken());
            int K = Integer.parseInt(st.nextToken());

            List<List<Long>> A = new ArrayList<>();
            List<Long> A_sum = new ArrayList<>();

            for (int i = 0; i < N; i++) {
                st = new StringTokenizer(in.readLine());
                int t = Integer.parseInt(st.nextToken());
                List<Long> a = new ArrayList<>();
                for (int j = 0; j < t; j++) {
                    a.add(Long.parseLong(st.nextToken()));
                }
                if (t > K) {
                    a = a.subList(0, K);
                }
                A.add(a);
                long sum = 0;
                for (long num : a) {
                    sum += num;
                }
                A_sum.add(sum);
            }

            long best = 0;
            long[] knapsack = new long[K + 1];
            recurse(0, N, knapsack, A, A_sum, K);

            out.println(best);
        }

        private void add_item(long[] knapsack, int size, long sum) {
            for (int k = knapsack.length - size - 1; k >= 0; k--) {
                knapsack[k + size] = Math.max(knapsack[k + size], knapsack[k] + sum);
            }
        }

        private void recurse(int start, int end, long[] knapsack, List<List<Long>> A, List<Long> A_sum, int K) {
            if (start >= end) {
                return;
            }

            if (end - start == 1) {
                long sum = 0;
                long curBest = knapsack[K];

                for (int prefix = 1; prefix <= A.get(start).size(); prefix++) {
                    sum += A.get(start).get(prefix - 1);
                    curBest = Math.max(curBest, sum + knapsack[K - prefix]);
                }

                best = Math.max(best, curBest);

                return;
            }

            int mid = (start + end) / 2;
            long[] state = knapsack.clone();

            for (int i = start; i < mid; i++) {
                add_item(state, A.get(i).size(), A_sum.get(i));
            }

            recurse(mid, end, state, A, A_sum, K);
            state = knapsack.clone();

            for (int i = mid; i < end; i++) {
                add_item(state, A.get(i).size(), A_sum.get(i));
            }

            recurse(start, mid, state, A, A_sum, K);
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

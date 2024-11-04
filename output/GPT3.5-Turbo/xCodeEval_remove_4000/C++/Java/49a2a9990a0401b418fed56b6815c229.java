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
            int N, K;
            StringTokenizer st = new StringTokenizer(in.readLine());
            N = Integer.parseInt(st.nextToken());
            K = Integer.parseInt(st.nextToken());

            List<List<Long>> A = new ArrayList<>();
            List<Long> A_sum = new ArrayList<>();

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
                A_sum.add(sum);
            }

            long best = 0;
            List<Long> knapsack = new ArrayList<>(Collections.nCopies(K + 1, 0L));
            recurse(0, N, knapsack, A, A_sum, K);

            out.println(best);
        }

        private void add_item(List<Long> knapsack, int size, long sum) {
            for (int k = knapsack.size() - size - 1; k >= 0; k--) {
                knapsack.set(k + size, Math.max(knapsack.get(k + size), knapsack.get(k) + sum));
            }
        }

        private void recurse(int start, int end, List<Long> knapsack, List<List<Long>> A, List<Long> A_sum, int K) {
            if (start >= end) {
                return;
            }

            if (end - start == 1) {
                long sum = 0;
                long localBest = knapsack.get(K);

                for (int prefix = 1; prefix <= A.get(start).size(); prefix++) {
                    sum += A.get(start).get(prefix - 1);
                    localBest = Math.max(localBest, sum + knapsack.get(K - prefix));
                }

                best = Math.max(best, localBest);

                return;
            }

            int mid = (start + end) / 2;
            List<Long> state = new ArrayList<>(knapsack);

            for (int i = start; i < mid; i++) {
                add_item(state, A.get(i).size(), A_sum.get(i));
            }

            recurse(mid, end, state, A, A_sum, K);
            state = new ArrayList<>(knapsack);

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

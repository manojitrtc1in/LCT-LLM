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
            long[] knapsack = new long[K + 1];

            for (int i = 0; i < N; i++) {
                addItems(knapsack, A.get(i).size(), A_sum.get(i));
            }

            recurse(0, N, knapsack);

            out.println(best);
        }

        private void addItems(long[] knapsack, int size, long sum) {
            for (int k = K - size; k >= 0; k--) {
                knapsack[k + size] = Math.max(knapsack[k + size], knapsack[k] + sum);
            }
        }

        private void recurse(int start, int end, long[] knapsack) {
            if (start >= end) {
                return;
            }

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
            long[] state = Arrays.copyOf(knapsack, knapsack.length);

            for (int i = start; i < mid; i++) {
                addItems(state, A.get(i).size(), A_sum.get(i));
            }

            recurse(mid, end, state);
            state = Arrays.copyOf(knapsack, knapsack.length);

            for (int i = mid; i < end; i++) {
                addItems(state, A.get(i).size(), A_sum.get(i));
            }

            recurse(start, mid, state);
        }
    }

    public static void solve(BufferedReader in, PrintWriter out) throws IOException {
        Solver solver = new Solver(in, out);
        solver.solve();
    }

    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter out = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
        solve(in, out);
        out.close();
    }
}

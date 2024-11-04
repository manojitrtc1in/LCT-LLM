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

                for (int prefix = 1; prefix <= A[start].length; prefix++) {
                    sum += A[start][prefix - 1];
                    best = Math.max(best, sum + knapsack[K - prefix]);
                }

                return;
            }

            int mid = (start + end) / 2;
            long[] state = knapsack.clone();

            for (int i = start; i < mid; i++) {
                add_item(state, A[i].length, A_sum[i]);
            }

            recurse(mid, end, state);
            state = knapsack.clone();

            for (int i = mid; i < end; i++) {
                add_item(state, A[i].length, A_sum[i]);
            }

            recurse(start, mid, state);
        }

        private void solve() throws IOException {
            StringTokenizer st = new StringTokenizer(in.readLine());
            N = Integer.parseInt(st.nextToken());
            K = Integer.parseInt(st.nextToken());
            A = new int[N][];
            A_sum = new long[N];

            for (int i = 0; i < N; i++) {
                st = new StringTokenizer(in.readLine());
                int t = Integer.parseInt(st.nextToken());
                A[i] = new int[t];

                for (int j = 0; j < t; j++) {
                    A[i][j] = Integer.parseInt(st.nextToken());
                }

                if (t > K) {
                    int[] temp = new int[K];
                    System.arraycopy(A[i], 0, temp, 0, K);
                    A[i] = temp;
                }

                for (int j = 0; j < A[i].length; j++) {
                    A_sum[i] += A[i][j];
                }
            }

            best = 0;
            long[] knapsack = new long[K + 1];
            recurse(0, N, knapsack);
            out.println(best);
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

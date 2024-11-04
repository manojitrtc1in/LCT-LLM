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
                List<Long> arr = new ArrayList<>();

                for (int j = 0; j < t; j++) {
                    arr.add(Long.parseLong(st.nextToken()));
                }

                if (t > K) {
                    arr = arr.subList(0, K);
                }

                A.add(arr);
                long sum = 0;
                for (long num : arr) {
                    sum += num;
                }
                A_sum.add(sum);
            }

            long best = 0;
            long[] knapsack = new long[K + 1];

            for (int i = 0; i < N; i++) {
                int size = A.get(i).size();
                long sum = A_sum.get(i);

                for (int k = K - size; k >= 0; k--) {
                    knapsack[k + size] = Math.max(knapsack[k + size], knapsack[k] + sum);
                }
            }

            for (int i = 0; i <= K; i++) {
                best = Math.max(best, knapsack[i]);
            }

            out.println(best);
        }
    }

    public static void solve(InputStream in, OutputStream out) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(in));
        PrintWriter pw = new PrintWriter(out);
        Solver solver = new Solver(br, pw);
        solver.solve();
        pw.flush();
    }

    public static void main(String[] args) throws IOException {
        solve(System.in, System.out);
    }
}

import java.util.*;
import java.io.*;

public class 3fc93652c831882019e3b86122b70f61xcodeeval_processed_4000.json {
    static int N, K;
    static List<List<Long>> A;
    static long[] A_sum;
    static long best;

    static void addItem(long[] knapsack, int size, long sum) {
        for (int k = K - size; k >= 0; k--) {
            knapsack[k + size] = Math.max(knapsack[k + size], knapsack[k] + sum);
        }
    }

    static void recurse(int start, int end, long[] knapsack) {
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

    static class Solver {
        BufferedReader in;
        PrintWriter out;

        Solver(BufferedReader in, PrintWriter out) {
            this.in = in;
            this.out = out;
        }

        void solve() throws IOException {
            StringTokenizer st = new StringTokenizer(in.readLine());
            N = Integer.parseInt(st.nextToken());
            K = Integer.parseInt(st.nextToken());
            A = new ArrayList<>();
            A_sum = new long[N];

            for (int i = 0; i < N; i++) {
                int t = Integer.parseInt(in.readLine());
                List<Long> tempList = new ArrayList<>();
                st = new StringTokenizer(in.readLine());
                for (int j = 0; j < t; j++) {
                    tempList.add(Long.parseLong(st.nextToken()));
                }

                if (t > K) {
                    tempList = tempList.subList(0, K);
                }

                A.add(tempList);
                A_sum[i] = tempList.stream().mapToLong(Long::longValue).sum();
            }

            best = 0;
            long[] knapsack = new long[K + 1];
            recurse(0, N, knapsack);
            out.println(best);
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

import java.util.*;
import java.io.*;

public class 25cbffa0508fee36f748b5baeccea6a3_nc {
    static class Solver {
        BufferedReader in;
        PrintWriter out;
        int N, K;
        List<List<Long>> A;
        long[] A_sum;
        long best;

        Solver(BufferedReader in, PrintWriter out) {
            this.in = in;
            this.out = out;
        }

        void rd(long[] args) throws IOException {
            StringTokenizer st = new StringTokenizer(in.readLine());
            for (int i = 0; i < args.length; i++) {
                args[i] = Long.parseLong(st.nextToken());
            }
        }

        void prln(long value) {
            out.println(value);
        }

        void addItem(long[] knapsack, int size, long sum) {
            for (int k = K - size; k >= 0; k--) {
                knapsack[k + size] = Math.max(knapsack[k + size], knapsack[k] + sum);
            }
        }

        void recurse(int start, int end, long[] knapsack) {
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

        void solve() throws IOException {
            StringTokenizer st = new StringTokenizer(in.readLine());
            N = Integer.parseInt(st.nextToken());
            K = Integer.parseInt(st.nextToken());
            A = new ArrayList<>();
            A_sum = new long[N];

            for (int i = 0; i < N; i++) {
                st = new StringTokenizer(in.readLine());
                int t = Integer.parseInt(st.nextToken());
                List<Long> tempList = new ArrayList<>();
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
            prln(best);
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter out = new PrintWriter(System.out);
        new Solver(in, out).solve();
        out.close();
    }
}

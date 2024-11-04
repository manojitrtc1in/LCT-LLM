import java.util.*;
import java.io.*;

class DSum {
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

        void rd() throws IOException {
            StringTokenizer st = new StringTokenizer(in.readLine());
            N = Integer.parseInt(st.nextToken());
            K = Integer.parseInt(st.nextToken());
            A = new ArrayList<>(N);
            A_sum = new long[N];
            for (int i = 0; i < N; i++) {
                int t = Integer.parseInt(st.nextToken());
                List<Long> item = new ArrayList<>();
                st = new StringTokenizer(in.readLine());
                for (int j = 0; j < t; j++) {
                    item.add(Long.parseLong(st.nextToken()));
                }
                if (t > K) {
                    item = item.subList(0, K);
                }
                A.add(item);
                A_sum[i] = item.stream().mapToLong(Long::longValue).sum();
            }
        }

        void add_item(long[] knapsack, int size, long sum) {
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
            long[] state = Arrays.copyOf(knapsack, knapsack.length);

            for (int i = start; i < mid; i++) {
                add_item(state, A.get(i).size(), A_sum[i]);
            }

            recurse(mid, end, state);
            state = Arrays.copyOf(knapsack, knapsack.length);

            for (int i = mid; i < end; i++) {
                add_item(state, A.get(i).size(), A_sum[i]);
            }

            recurse(start, mid, state);
        }

        void solve() throws IOException {
            rd();
            best = 0;
            long[] knapsack = new long[K + 1];
            recurse(0, N, knapsack);
            out.println(best);
        }
    }

    static void solve(InputStream in, OutputStream out) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(in));
        PrintWriter writer = new PrintWriter(out);
        new Solver(reader, writer).solve();
        writer.flush();
    }

    public static void main(String[] args) throws IOException {
        solve(System.in, System.out);
    }
}

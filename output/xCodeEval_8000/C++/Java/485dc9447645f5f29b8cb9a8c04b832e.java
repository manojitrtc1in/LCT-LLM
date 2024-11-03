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
                List<Long> row = new ArrayList<>();
                
                for (int j = 0; j < t; j++) {
                    row.add(Long.parseLong(st.nextToken()));
                }
                
                if (t > K) {
                    row = row.subList(0, K);
                }
                
                A.add(row);
                long sum = 0;
                for (long num : row) {
                    sum += num;
                }
                A_sum.add(sum);
            }
            
            long best = 0;
            List<Long> knapsack = new ArrayList<>(Collections.nCopies(K + 1, 0L));
            
            recurse(0, N, knapsack, A, A_sum);
            
            out.println(best);
        }
        
        private void add_item(List<Long> knapsack, int size, long sum) {
            for (int k = K - size; k >= 0; k--) {
                knapsack.set(k + size, Math.max(knapsack.get(k + size), knapsack.get(k) + sum));
            }
        }
        
        private void recurse(int start, int end, List<Long> knapsack, List<List<Long>> A, List<Long> A_sum) {
            if (start >= end) {
                return;
            }
            
            if (end - start == 1) {
                long sum = 0;
                best = Math.max(best, knapsack.get(K));
                
                for (int prefix = 1; prefix <= A.get(start).size(); prefix++) {
                    sum += A.get(start).get(prefix - 1);
                    best = Math.max(best, sum + knapsack.get(K - prefix));
                }
                
                return;
            }
            
            int mid = (start + end) / 2;
            List<Long> state = new ArrayList<>(knapsack);
            
            for (int i = start; i < mid; i++) {
                add_item(state, A.get(i).size(), A_sum.get(i));
            }
            
            recurse(mid, end, state, A, A_sum);
            state = new ArrayList<>(knapsack);
            
            for (int i = mid; i < end; i++) {
                add_item(state, A.get(i).size(), A_sum.get(i));
            }
            
            recurse(start, mid, state, A, A_sum);
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

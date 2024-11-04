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
            long[] knapsack = new long[K + 1];
            
            for (int i = 0; i < N; i++) {
                List<Long> row = A.get(i);
                long sum = A_sum.get(i);
                
                for (int prefix = 1; prefix <= row.size(); prefix++) {
                    long prefixSum = 0;
                    for (int j = 0; j < prefix; j++) {
                        prefixSum += row.get(j);
                    }
                    for (int k = K - prefix; k >= 0; k--) {
                        knapsack[k + prefix] = Math.max(knapsack[k + prefix], knapsack[k] + prefixSum);
                    }
                }
                
                best = Math.max(best, knapsack[K]);
            }
            
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

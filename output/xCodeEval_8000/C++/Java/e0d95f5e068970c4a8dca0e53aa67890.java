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
                List<Long> list = A.get(i);
                long sum = A_sum.get(i);
                
                for (int prefix = 1; prefix <= list.size(); prefix++) {
                    long currSum = 0;
                    for (int j = 0; j < prefix; j++) {
                        currSum += list.get(j);
                    }
                    for (int k = K - prefix; k >= 0; k--) {
                        knapsack[k + prefix] = Math.max(knapsack[k + prefix], knapsack[k] + currSum);
                    }
                }
                
                best = Math.max(best, knapsack[K]);
                best = Math.max(best, sum);
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

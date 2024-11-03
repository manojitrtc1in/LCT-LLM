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
        
        private void readInts(int[] arr) throws IOException {
            String[] line = in.readLine().split(" ");
            for (int i = 0; i < arr.length; i++) {
                arr[i] = Integer.parseInt(line[i]);
            }
        }
        
        private void print(Object obj) {
            out.print(obj);
        }
        
        private void println(Object obj) {
            out.println(obj);
        }
        
        private long sum(List<Integer> arr) {
            long sum = 0;
            for (int num : arr) {
                sum += num;
            }
            return sum;
        }
        
        private void solve() throws IOException {
            int n, k;
            int[] nk = new int[2];
            readInts(nk);
            n = nk[0];
            k = nk[1];
            
            List<List<Integer>> arrs = new ArrayList<>();
            for (int i = 0; i < n; i++) {
                List<Integer> arr = new ArrayList<>();
                readInts(arr);
                if (arr.size() > k) {
                    arr = arr.subList(0, k);
                }
                arrs.add(arr);
            }
            
            long[] sums = new long[n];
            for (int i = 0; i < n; i++) {
                sums[i] = sum(arrs.get(i));
            }
            
            long[][] dps = new long[13][k + 1];
            for (int i = 0; i < n; i++) {
                int k1 = arrs.get(i).size();
                for (int j = k; j >= k1; j--) {
                    dps[0][j] = Math.max(dps[0][j], dps[0][j - k1] + sums[i]);
                }
            }
            
            for (int dpi = 0; dpi < 12; dpi++) {
                System.arraycopy(dps[dpi], 0, dps[dpi + 1], 0, k + 1);
            }
            
            long ans = recurse(0, n, 0, dps, arrs, k);
            println(ans);
        }
        
        private long recurse(int l, int r, int dpi, long[][] dps, List<List<Integer>> arrs, int k) {
            if (l + 1 == r) {
                long ans = dps[dpi][k];
                List<Integer> carr = arrs.get(l);
                long sum = 0;
                for (int i = 0; i < Math.min(k, carr.size()); i++) {
                    sum += carr.get(i);
                    ans = Math.max(ans, dps[dpi][k - i - 1] + sum);
                }
                return ans;
            } else {
                int m = (l + r) / 2;
                long ans = Math.max(recurse(l, m, dpi + 1, dps, arrs, k),
                                    recurse(m, r, dpi + 1, dps, arrs, k));
                return ans;
            }
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
        in.close();
        out.close();
    }
}

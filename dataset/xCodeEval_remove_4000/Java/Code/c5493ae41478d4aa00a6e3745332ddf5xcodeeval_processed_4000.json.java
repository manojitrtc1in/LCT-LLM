

import java.awt.*;
import java.io.*;
import java.util.*;
import java.util.List;
import java.util.StringTokenizer;

public class Ex3 {
    static FastScanner in = new FastScanner();

    public static void main(String[] args) {
        PrintWriter out = new PrintWriter(System.out);
        int q = in.nextInt();
        for (int t = 0; t < q; t++) {
           String str =  in.nextToken();
          int arr[] = new int[150];
          int y = str.length();
          for(int i = 0; i < y;i++){
              arr[str.charAt(i)]++;
          }
          int total = 0;
          for(int i = 0; i < 150; i++){
              total += Math.min(2L,arr[i]);
          }
          out.println(total/2);
        }
        out.flush();
    }

    static int[] arr(int n) {
        int arr[] = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = in.nextInt();
        }
        return arr;
    }
   static private long factorial(long n){
        long result = 1;
        if(n ==1 || n == 0){
            return result;
        }
        result = n * factorial(n-1);
        return result;
    }

    static long gcd(long a, long b) {
        return b == 0 ? a : gcd(b, a % b);
    }

    static long lcm(long a, long b) {
        return a * b / gcd(a, b);
    }

    public static class FastScanner {
        BufferedReader br;
        StringTokenizer st;

        public FastScanner() {
            init();
        }

        public FastScanner(String name) {
            init(name);
        }

        public FastScanner(boolean id0) {
            if (!id0 || System.getProperty("ONLINE_JUDGE") != null) {
                init();
            } else {
                init("input.txt");
            }
        }

        private void init() {
            br = new BufferedReader(new InputStreamReader(System.in));
        }

        private void init(String name) {
            try {
                br = new BufferedReader(new FileReader(name));
            } catch (FileNotFoundException e) {
                e.printStackTrace();
            }
        }

        public String nextToken() {
            while (st == null || !st.hasMoreElements()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }

        public int nextInt() {
            return Integer.parseInt(nextToken());
        }

        public long nextLong() {
            return Long.parseLong(nextToken());
        }

        public double nextDouble() {
            return Double.parseDouble(nextToken());
        }

    }

    public static void sortInsertion(int[] sort_arr) {
        for (int i = 0; i < sort_arr.length; ++i) {
            int j = i;
            while (j > 0 && sort_arr[j - 1] > sort_arr[j]) {
                int key = sort_arr[j];
                sort_arr[j] = sort_arr[j - 1];
                sort_arr[j - 1] = key;
                j = j - 1;

            }
        }
    }
}





import java.io.*;
import java.util.*;
import java.util.StringTokenizer;

public class Ex3 {
    public static void main(String[] args) {
        FastScanner in = new FastScanner();
        PrintWriter out = new PrintWriter(System.out);

        int q = in.nextInt();
        for (int t = 0; t < q; t++) {
            int x = in.nextInt();
            int arr[] = new int[x];
            for(int i = 0; i < x;i++){
                arr[i] = i+1;
            }
            if (x % 2 == 0) {
                for(int i = 0; i < x-1; i+=2){
                    int temp=0;
                    temp = arr[i];
                    arr[i] = arr[i+1];
                    arr[i+1] = temp;
                }
                for(int i = 0; i < x; i++){
                    System.out.print(arr[i]+" ");
                }
            }else {
                arr[0] = 3; arr[1] = 1; arr[2] = 2;
                for(int i = 3; i < x-1; i+=2){
                    int temp=0;
                    temp = arr[i];
                    arr[i] = arr[i+1];
                    arr[i+1] = temp;
                }
                for(int i = 0; i < x; i++){
                    System.out.print(arr[i]+" ");
                }
            }
            out.flush();
        }
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
}



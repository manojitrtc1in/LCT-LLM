

import java.io.*;
import java.util.*;
import java.util.StringTokenizer;

public class Ex3 {
    public static void main(String[] args) {
        FastScanner sc = new FastScanner();
        PrintWriter out = new PrintWriter(System.out);
        int q = sc.nextInt();
        for (int t = 0; t < q; t++) {
            int a=sc.nextInt();
            int as[]=new int[a];
            int  ee[]=new int[101];
            for(int i=0;i<a;i++){
                as[i]= sc.nextInt();
                ee[as[i]]++;
            }
            int y=ee[1];
            int tt=y;
            int we=0;
            for(int i=2;i<=y;i++){
                we+=ee[i];
                if(we<i-1){
                    y--;
                    we++;
                }
                if(we+1>=y)
                    break ;
            }

            out.println(y);
        }
        out.flush();
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



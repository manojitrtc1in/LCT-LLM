

import java.io.*;
import java.util.*;
import java.util.StringTokenizer;

public class Ex3 {
    public static void main(String[] args) {
        FastScanner in = new FastScanner();
        PrintWriter out = new PrintWriter(System.out);
        int q = in.nextInt();
        for (int t = 0; t < q; t++) {
            out.println(in.nextInt());
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

        public FastScanner(){
            init();
        }

        public FastScanner(String name) {
            init(name);
        }

        public FastScanner(boolean isOnlineJudge){
            if(!isOnlineJudge || System.getProperty("ONLINE_JUDGE") != null){
                init();
            }else{
                init("input.txt");
            }
        }

        private void init(){
            br = new BufferedReader(new InputStreamReader(System.in));
        }

        private void init(String name){
            try {
                br = new BufferedReader(new FileReader(name));
            } catch (FileNotFoundException e) {
                e.printStackTrace();
            }
        }

        public String nextToken(){
            while(st == null || !st.hasMoreElements()){
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }

        public int nextInt(){
            return Integer.parseInt(nextToken());
        }

        public long nextLong(){
            return Long.parseLong(nextToken());
        }

        public double nextDouble(){
            return Double.parseDouble(nextToken());
        }

    }
}




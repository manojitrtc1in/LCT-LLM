

import java.io.*;
import java.util.*;
import java.util.StringTokenizer;

public class Ex3 {
    public static void main(String[] args) {
        FastScanner sc = new FastScanner();
        PrintWriter out = new PrintWriter(System.out);
        int q = sc.nextInt();
        for (int t = 0; t < q; t++) {
            int x = sc.nextInt();
            int n = x / 2;
            int ans1[] = new int[x/2];
            int h = 0;
            if (x % 2 == 0) {
                int ans[] = new int[x/2];
                for (int i = n; i > 0; i--) {
                    ans[h] = i;
                    h++;
                }
                h = 0;
                for (int i = x; i > n; i--) {
                    ans1[h] = i;
                    h++;
                }
                h = 0;
                for(int i = 0; i < x/2; i++){
                    out.print(ans[i]+" ");
                    out.print(ans1[i]+" ");
                }
            } else {
                h = 0;
                int ans[] = new int[(x/2)+1];
                for (int i = n+1; i > 0; i--) {
                    ans[h] = i;
                    h++;
                }
                h = 0;
                for (int i = x; i > n+1; i--) {
                    ans1[h] = i;
                    h++;
                }
                int out1[] = new int[x];
                int a =0;
                int h1 = 0;
                int h2 = 0;
                while (a < x){
                    if(h1 < (x/2)+1){
                        out1[a] = ans[h1];
                        h1++;
                    }
                    a++;
                    if(h2 < x/2){
                        out1[a] = ans1[h2];
                        h2++;
                        a++;
                    }
                }
                for (int i = 0; i < x; i++) {
                    out.print(out1[i]+" ");
                }
                out.println();
            }

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

        public FastScanner(boolean isOnlineJudge) {
            if (!isOnlineJudge || System.getProperty("ONLINE_JUDGE") != null) {
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



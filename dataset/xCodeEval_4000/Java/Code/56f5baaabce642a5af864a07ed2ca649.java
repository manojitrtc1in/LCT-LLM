    

    import java.awt.*;
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
                String str = in.nextToken();
                int arr[] = new int[x];
                for(int i = 0; i < x; i++){
                    arr[i] = Integer.parseInt(String.valueOf(str.charAt(i)));
                }
                long cout = 1;
                long max = 0;
                long max1 = 0;
                long a = 0;
                long b = 0;
                if(arr[x-1] == 1){
                    a++;
                }else {
                    b++;
                }
                for(int i = 0; i < x-1; i++){
                    if(arr[i] == 1){
                        a++;
                    }else {
                        b++;
                    }
                    if(arr[i] == arr[i+1]){
                        cout++;
                    }else {
                        if(max < cout) {
                            max = cout;
                        }
                        cout =1;
                    }
                }
                max1 = cout;
                max = Math.max(max,max1);
                long gg = a*b;
                out.println((long)Math.max(gg,Math.pow(max,2)));
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



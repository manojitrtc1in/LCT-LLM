

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
            int x  = in.nextInt();
            int arr[] = arr(x);
            int answer[] = new int[x];
            String str = in.nextToken();
            int Muz[] = new int[str.length()];
            int a = 0;
            int b = 0;
            for (int i = 0; i < x; i++) {
                Muz[i] = Integer.parseInt(String.valueOf(str.charAt(i)));
                if(Muz[i] == 1){
                    a++;
                }else{
                    b++;
                }
            }
            Map<Integer,Integer> map = new HashMap<>();
            for(int i = 0; i < x; i++){
                map.put(arr[i],i);
            }
            int good[] = new int[b];
            int bad[] = new int[a];
            int h1 = 0;
            int h2 = 0;
            for(int i = 0; i <x; i++){
                if(Muz[i] == 0){
                    good[h1] = arr[i];
                    h1++;
                }else {
                    bad[h2] = arr[i];
                    h2++;
                }
            }
            Arrays.sort(good);
            Arrays.sort(bad);
            int val = 1;
            for(int i = 0; i < b; i++){
                answer[map.get(good[i])] = val;
                val++;
            }
            for(int i = 0; i < a; i++){
                answer[map.get(bad[i])] = val;
                val++;
            }
            for(int i = 0; i < x; i++){
                out.print(answer[i]+" ");
            }
            out.println();
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



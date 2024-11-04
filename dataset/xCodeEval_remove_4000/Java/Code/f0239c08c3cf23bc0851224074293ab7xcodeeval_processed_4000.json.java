

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
            int n  =in.nextInt();
            int arr[] = arr(n);
            int answer[] = new int[n];
            char[] inp = in.nextToken().toCharArray();

            Map<Integer, Integer> map = new HashMap<>();
            for (int i = 0; i < n; i++) {
                map.put(arr[i],i);
            }
            ArrayList<Integer> good = new ArrayList<>();
            ArrayList<Integer> bad = new ArrayList<>();
            int cout = 0;

            for(int i = 0; i < n; i++){
                if(inp[i] == '0'){
                    bad.add(arr[i]);
                }else{
                    good.add(arr[i]);
                }
            }
            Collections.sort(bad);
            Collections.sort(good);

            int val = 1;
            for(int i : bad){
                answer[map.get(i)] = val;
                val++;
            }
            for(int i : good){
                answer[map.get(i)] = val;
                val++;
            }
            for(int i : answer){
                out.print(i + " ");
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



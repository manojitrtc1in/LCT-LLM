

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
        for (int e = 0; e < q; e++) {
            int x = in.nextInt();
            int arr[] = arr(x);
            int res[] = new int[x];
            boolean trigger = false;
            int i = 0;
            while(i < x && !trigger){
                int k = i;
                while(k < x-1 && arr[i] == arr[k+1]){
                    res[k] = k+1;
                    k++;
                }
                    res[k] = i;
                    trigger = (i == k);
                    i=k+1;
            }
            if(trigger){
                out.println(-1);
            }else{
                for (int i1 = 0; i1 < x; i1++){
                    out.print((res[i1]+1)+" ");
                }
            }
            

            

            

            

            

            

            

            

            

            

            

            

            

            

            

            

            

            

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

    static private long factorial(long n) {
        long result = 1;
        if (n == 1 || n == 0) {
            return result;
        }
        result = n * factorial(n - 1);
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

    public static void mergeSort(int[] arr) {
        int n = arr.length;
        if (n == 1) return;
        int mid = n / 2;
        int left[] = new int[mid];
        int right[] = new int[n - mid];

        for (int i = 0; i < mid; i++) {
            left[i] = arr[i];
        }
        for (int i = mid; i < n; i++) {
            right[i - mid] = arr[i];
        }

        mergeSort(left);
        mergeSort(right);
        merge(arr, left, right);
    }

    public static void merge(int arr[], int left[], int right[]) {
        int lenLeft = left.length;
        int lenRight = right.length;
        int i = 0;
        int j = 0;
        int idx = 0;
        while (i < lenLeft && j < lenRight) {
            if (left[i] < right[j]) {
                arr[idx] = left[i];
                i++;
                idx++;
            } else {
                arr[idx] = right[j];
                j++;
                idx++;
            }
        }

        for (int ll = i; ll < lenLeft; ll++) {
            arr[idx++] = left[ll];
        }
        for (int rr = j; rr < lenRight; rr++) {
            arr[idx++] = right[rr];
        }

    }
}



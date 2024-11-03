import java.sql.Array;
import java.sql.SQLOutput;
import java.util.*;
import java.io.*;
import java.math.*;

public class MyProgram {
    public static FastIO file = new FastIO();

    private static void solve() {


        

        int tt = 1;
        long start = 0;
        while (tt-- > 0) {


            int n = nextInt();
            String s = nextLine();








            start = System.currentTimeMillis();
            char[] c = new char[n + 1];
            for (int i = 0; i < n; i++) {
                c[i] = s.charAt(i);
            }
            int count = 0;
            String g = "";
            int x = 1;
            for (int i = 0; i < n; i += 2) {
                if (c[i] == c[i + x]) {
                    count++;
                    i -= 2;
                    x++;
                } else {


                    if (c[i+x] == 0 || c[i] == 0){
                        count++;
                    }


                    if (x != 1) i += x - 1;
                    x = 1;
                }
            }















            System.out.println(count);
            x = 1;
            for (int i = 0; i < n; i += 2) {
                if (c[i] == c[i + x]) {


                    i -= 2;
                    x++;
                } else {


                    if (c[i + x] == 0 || c[i] == 0) {


                    } else System.out.print(Character.toString(c[i]) + Character.toString(c[i + x]));
                    if (x != 1) i += x - 1;
                    x = 1;
                }
            }
            

            

        }
    }

    private static int[] nextArray(int n) {
        int[] a = new int[n];
        for (int i = 0; i < n; i++) a[i] = nextInt();
        return a;
    }

    public static int[][] id0(int n, int m) {
        int[][] result = new int[n][];
        for (int i = 0; i < n; i++) {
            result[i] = nextArray(m);
        }
        return result;
    }

    public static long pow(long n, long p) {
        long ret = 1L;
        while (p > 0) {
            if (p % 2 != 0L)
                ret *= n;
            n *= n;
            p >>= 1L;
        }
        return ret;
    }

    public static String next() {
        return file.next();
    }

    public static int nextInt() {
        return file.nextInt();
    }

    public static long nextLong() {
        return file.nextLong();
    }

    public static double nextDouble() {
        return file.nextDouble();
    }

    public static String nextLine() {
        return file.nextLine();
    }

    public static class FastIO {
        BufferedReader br;
        StringTokenizer st;
        PrintWriter out;

        public FastIO() {
            br = new BufferedReader(new InputStreamReader(System.in));
            out = new PrintWriter(System.out);
        }

        String next() {
            while (st == null || !st.hasMoreElements()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }

        int nextInt() {
            return Integer.parseInt(next());
        }

        long nextLong() {
            return Long.parseLong(next());
        }

        double nextDouble() {
            return Double.parseDouble(next());
        }

        String nextLine() {
            String str = "";
            try {
                str = br.readLine();
            } catch (IOException e) {
                e.printStackTrace();
            }
            return str;
        }

    }

    public static void main(String[] args) {
        solve();
    }


}
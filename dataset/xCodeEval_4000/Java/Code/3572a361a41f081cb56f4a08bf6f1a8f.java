import java.io.*;
import java.util.*;
public class Main {
    static int mod = (int)1e9+7;
    static int[][] dir1 = new int[][]{{0,1},{0,-1},{1,0},{-1,0}};
    static int[][] dir2 = new int[][]{{0,1},{0,-1},{1,0},{-1,0},{1,1},{1,-1},{-1,1},{-1,-1}};
    static boolean[] prime = new boolean[10];
    static {
        for (int i = 2; i < prime.length; i++) prime[i] = true;
        for (int i = 2; i < prime.length; i++) {
            if (prime[i]) {
                for (int k = 2; i * k < prime.length; k++) {
                    prime[i * k] = false;
                }
            }
        }
    }
    static class JoinSet {
        int[] fa;
        JoinSet(int n) {
            fa = new int[n];
            for (int i = 0; i < n; i++) fa[i] = i;
        }
        int find(int t) {
            if (t != fa[t]) fa[t] = find(fa[t]);
            return fa[t];
        }
        void join(int x, int y) {
            x = find(x);
            y = find(y);
            fa[x] = y;
        }
    }
    static BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static long gcd(long a, long b) {
        return b == 0 ? a : gcd(b, a % b);
    }
    static long lcm(long a, long b) {
        return a * b / gcd(a, b);
    }
    static int get() throws Exception {
        String ss = bf.readLine();
        if (ss.contains(" ")) ss = ss.substring(0, ss.indexOf(" "));
        return Integer.parseInt(ss);
    }
    static long getx() throws Exception {
        String ss = bf.readLine();
        if (ss.contains(" ")) ss = ss.substring(0, ss.indexOf(" "));
        return Long.parseLong(ss);
    }
    static int[] getint() throws Exception {
        String[] s = bf.readLine().split(" ");
        int[] a = new int[s.length];
        for (int i = 0; i < a.length; i++) {
            a[i] = Integer.parseInt(s[i]);
        }
        return a;
    }
    static long[] getlong() throws Exception {
        String[] s = bf.readLine().split(" ");
        long[] a = new long[s.length];
        for (int i = 0; i < a.length; i++) {
            a[i] = Long.parseLong(s[i]);
        }
        return a;
    }
    static String getstr() throws Exception {
        return bf.readLine();
    }
    static void println() throws Exception {
        bw.write("\n");
    }
    static void print(int a) throws Exception {
        bw.write(a + "\n");
    }
    static void print(long a) throws Exception {
        bw.write(a + "\n");
    }
    static void print(String a) throws Exception {
        bw.write(a + "\n");
    }
    static void print(int[] a) throws Exception {
        for (int i : a) {
            bw.write(i + " ");
        }
        println();
    }
    static void print(long[] a) throws Exception {
        for (long i : a) {
            bw.write(i + " ");
        }
        println();
    }
    static void print(int[][] a) throws Exception {
        for (int i[] : a) print(i);
    }
    static void print(long[][] a) throws Exception {
        for (long[] i : a) print(i);
    }
    static void print(char[] a) throws Exception {
        for (char i : a) {
            bw.write(i +"");
        }
        println();
    }
    static long pow(long a, long b) {
        long ans = 1;
        while (b > 0) {
            if ((b & 1) == 1) {
                ans *= a;
            }
            a *= a;
            b >>= 1;
        }
        return ans;
    }
    static int powmod(long a, long b, int mod) {
        long ans = 1;
        while (b > 0) {
            if ((b & 1) == 1) {
                ans = ans * a % mod;
            }
            a = a * a % mod;
            b >>= 1;
        }
        return (int) ans;
    }
    static void sort(int[] a) {
        int n = a.length;
        Integer[] b = new Integer[n];
        for (int i = 0; i < n; i++) b[i] = a[i];
        Arrays.sort(b);
        for (int i = 0; i < n; i++) a[i] = b[i];
    }
    static void sort(long[] a) {
        int n = a.length;
        Long[] b = new Long[n];
        for (int i = 0; i < n; i++) b[i] = a[i];
        Arrays.sort(b);
        for (int i = 0; i < n; i++) a[i] = b[i];
    }
    static void resort(int[] a) {
        int n = a.length;
        Integer[] b = new Integer[n];
        for (int i = 0; i < n; i++) b[i] = a[i];
        Arrays.sort(b);
        for (int i = 0; i < n; i++) a[i] = b[n-1-i];
    }
    static void resort(long[] a) {
        int n = a.length;
        Long[] b = new Long[n];
        for (int i = 0; i < n; i++) b[i] = a[i];
        Arrays.sort(b);
        for (int i = 0; i < n; i++) a[i] = b[n-1-i];
    }
    static int max(int a, int b) {
        return Math.max(a,b);
    }
    static int min(int a, int b) {
        return Math.min(a,b);
    }
    static long max(long a, long b) {
        return Math.max(a,b);
    }
    static long min(long a, long b) {
        return Math.min(a,b);
    }
    static int max(int[] a) {
        int max = a[0];
        for(int i : a) max = max(max,i);
        return max;
    }
    static int min(int[] a) {
        int min = a[0];
        for(int i : a) min = min(min,i);
        return min;
    }
    static long max(long[] a) {
        long max = a[0];
        for(long i : a) max = max(max,i);
        return max;
    }
    static long min(long[] a) {
        long min = a[0];
        for(long i : a) min = min(min,i);
        return min;
    }
    static int abs(int a) {
        return Math.abs(a);
    }
    static long abs(long a) {
        return Math.abs(a);
    }
    static void yes() throws Exception{
        print("Yes");
    }
    static void no() throws Exception{
        print("No");
    }
    static int[] getarr(List<Integer> list){
        int n = list.size();
        int[] a = new int[n];
        for(int i = 0;i < n;i++) a[i] = list.get(i);
        return a;
    }

    public static void main(String[] args) throws Exception {
        int a[][] = new int[3][2];
        for (int i = 0; i < 3; i++) a[i] = getint();
        Arrays.sort(a, (x, y) -> x[0] - y[0]);
        int[][] ans = new int[10][4];
        int k = 0;
        int d1 = abs(a[0][0] - a[1][0]), d2 = abs(a[0][0] - a[2][0]), d5 = abs(a[1][0] - a[2][0]);
        int d3 = abs(a[0][1] - a[1][1]), d4 = abs(a[0][1] - a[2][1]), d6 = abs(a[1][1] - a[2][1]);
        if (d1 == 0 && d2 == 0) {
            k = 1;
            ans[0][0] = a[0][0];
            ans[0][2] = a[0][0];
            ans[0][1] = max(new int[]{a[0][1], a[1][1], a[2][1]});
            ans[0][3] = min(new int[]{a[0][1], a[1][1], a[2][1]});
        } else if (d1 == 0) {
            k = 2;
            if (a[2][1] >= max(a[0][1], a[1][1])) {
                ans[0][0] = a[0][0];
                ans[0][1] = a[2][1];
                ans[0][2] = a[0][0];
                ans[0][3] = min(new int[]{a[0][1], a[1][1]});
                ans[1][0] = a[0][0];
                ans[1][1] = a[2][1];
                ans[1][2] = a[2][0];
                ans[1][3] = a[2][1];
            } else if (a[2][1] <= min(a[0][1], a[1][1])) {
                ans[0][0] = a[0][0];
                ans[0][1] = a[2][1];
                ans[0][2] = a[0][0];
                ans[0][3] = max(new int[]{a[0][1], a[1][1]});
                ans[1][0] = a[0][0];
                ans[1][1] = a[2][1];
                ans[1][2] = a[2][0];
                ans[1][3] = a[2][1];
            } else {
                ans[0][0] = a[0][0];
                ans[0][1] = a[0][1];
                ans[0][2] = a[1][0];
                ans[0][3] = a[1][1];
                ans[1][0] = a[0][0];
                ans[1][1] = a[2][1];
                ans[1][2] = a[2][0];
                ans[1][3] = a[2][1];
            }
        } else if (d2 == 0) {
            k = 2;
            int t = a[1][0];
            a[1][0] = a[2][0];
            a[2][0] = t;
            t = a[1][1];
            a[1][1] = a[2][1];
            a[2][1] = t;
            if (a[2][1] >= max(a[0][1], a[1][1])) {
                ans[0][0] = a[0][0];
                ans[0][1] = a[2][1];
                ans[0][2] = a[0][0];
                ans[0][3] = min(new int[]{a[0][1], a[1][1]});
                ans[1][0] = a[0][0];
                ans[1][1] = a[2][1];
                ans[1][2] = a[2][0];
                ans[1][3] = a[2][1];
            } else if (a[2][1] <= min(a[0][1], a[1][1])) {
                ans[0][0] = a[0][0];
                ans[0][1] = a[2][1];
                ans[0][2] = a[0][0];
                ans[0][3] = max(new int[]{a[0][1], a[1][1]});
                ans[1][0] = a[0][0];
                ans[1][1] = a[2][1];
                ans[1][2] = a[2][0];
                ans[1][3] = a[2][1];
            } else {
                ans[0][0] = a[0][0];
                ans[0][1] = a[0][1];
                ans[0][2] = a[1][0];
                ans[0][3] = a[1][1];
                ans[1][0] = a[0][0];
                ans[1][1] = a[2][1];
                ans[1][2] = a[2][0];
                ans[1][3] = a[2][1];
            }
        } else {
            if (d5 == 0) {
                k = 2;
                if (a[0][1] >= max(a[2][1], a[1][1])) {
                    ans[0][0] = a[0][0];
                    ans[0][1] = a[0][1];
                    ans[0][2] = a[1][0];
                    ans[0][3] = a[0][1];
                    ans[1][0] = a[1][0];
                    ans[1][1] = a[0][1];
                    ans[1][2] = a[1][0];
                    ans[1][3] = min(a[1][1], a[2][1]);
                } else if (a[0][1] <= min(a[2][1], a[1][1])) {
                    ans[0][0] = a[0][0];
                    ans[0][1] = a[0][1];
                    ans[0][2] = a[1][0];
                    ans[0][3] = a[0][1];
                    ans[1][0] = a[1][0];
                    ans[1][1] = max(a[1][1], a[2][1]);
                    ans[1][2] = a[1][0];
                    ans[1][3] = a[0][1];
                } else {
                    ans[0][0] = a[0][0];
                    ans[0][1] = a[0][1];
                    ans[0][2] = a[1][0];
                    ans[0][3] = a[0][1];
                    ans[1][0] = a[1][0];
                    ans[1][1] = a[1][1];
                    ans[1][2] = a[2][0];
                    ans[1][3] = a[2][1];
                }
            } else {
                if (d3 == 0 && d4 == 0) {
                    k = 1;
                    ans[0][0] = a[0][0];
                    ans[0][1] = a[0][1];
                    ans[0][2] = a[2][0];
                    ans[0][3] = a[0][1];
                } else if (d3 == 0) {
                    k = 2;
                    ans[0][0] = a[0][0];
                    ans[0][1] = a[0][1];
                    ans[0][2] = a[2][0];
                    ans[0][3] = a[0][1];
                    ans[1][0] = a[2][0];
                    ans[1][1] = a[0][1];
                    ans[1][2] = a[2][0];
                    ans[1][3] = a[2][1];
                } else if (d4 == 0) {
                    k = 2;
                    ans[0][0] = a[0][0];
                    ans[0][1] = a[0][1];
                    ans[0][2] = a[2][0];
                    ans[0][3] = a[0][1];
                    ans[1][0] = a[1][0];
                    ans[1][1] = a[0][1];
                    ans[1][2] = a[1][0];
                    ans[1][3] = a[1][1];
                } else {
                    if (d6 == 0) {
                        k = 2;
                        ans[0][0] = a[0][0];
                        ans[0][1] = a[0][1];
                        ans[0][2] = a[0][0];
                        ans[0][3] = a[1][1];
                        ans[1][0] = a[0][0];
                        ans[1][1] = a[1][1];
                        ans[1][2] = a[2][0];
                        ans[1][3] = a[2][1];
                    } else {
                        if (a[1][1] > a[0][1]) {
                            k = 3;
                            if (a[2][1] > a[1][1]) {
                                ans[0][0] = a[0][0];
                                ans[0][1] = a[0][1];
                                ans[0][2] = a[0][0];
                                ans[0][3] = a[1][1];
                                ans[1][0] = a[0][0];
                                ans[1][1] = a[1][1];
                                ans[1][2] = a[2][0];
                                ans[1][3] = a[1][1];
                                ans[2][0] = a[2][0];
                                ans[2][1] = a[1][1];
                                ans[2][2] = a[2][0];
                                ans[2][3] = a[2][1];
                            } else if (a[2][1] < a[0][1]) {
                                ans[0][0] = a[0][0];
                                ans[0][1] = a[0][1];
                                ans[0][2] = a[1][0];
                                ans[0][3] = a[0][1];
                                ans[1][0] = a[1][0];
                                ans[1][1] = a[1][1];
                                ans[1][2] = a[1][0];
                                ans[1][3] = a[2][1];
                                ans[2][0] = a[1][0];
                                ans[2][1] = a[2][1];
                                ans[2][2] = a[2][0];
                                ans[2][3] = a[2][1];
                            } else {
                                ans[0][0] = a[0][0];
                                ans[0][1] = a[0][1];
                                ans[0][2] = a[1][0];
                                ans[0][3] = a[0][1];
                                ans[1][0] = a[1][0];
                                ans[1][1] = a[0][1];
                                ans[1][2] = a[1][0];
                                ans[1][3] = a[1][1];
                                ans[2][0] = a[1][0];
                                ans[2][1] = a[2][1];
                                ans[2][2] = a[2][0];
                                ans[2][3] = a[2][1];
                            }
                        } else {
                            k = 3;
                            if (a[2][1] > a[0][1]) {
                                ans[0][0] = a[0][0];
                                ans[0][1] = a[0][1];
                                ans[0][2] = a[1][0];
                                ans[0][3] = a[0][1];
                                ans[1][0] = a[1][0];
                                ans[1][1] = a[1][1];
                                ans[1][2] = a[1][0];
                                ans[1][3] = a[2][1];
                                ans[2][0] = a[1][0];
                                ans[2][1] = a[2][1];
                                ans[2][2] = a[2][0];
                                ans[2][3] = a[2][1];
                            } else if (a[2][1] < a[1][1]) {
                                ans[0][0] = a[0][0];
                                ans[0][1] = a[0][1];
                                ans[0][2] = a[1][0];
                                ans[0][3] = a[0][1];
                                ans[1][0] = a[1][0];
                                ans[1][1] = a[0][1];
                                ans[1][2] = a[1][0];
                                ans[1][3] = a[2][1];
                                ans[2][0] = a[1][0];
                                ans[2][1] = a[2][1];
                                ans[2][2] = a[2][0];
                                ans[2][3] = a[2][1];
                            } else {
                                ans[0][0] = a[0][0];
                                ans[0][1] = a[0][1];
                                ans[0][2] = a[1][0];
                                ans[0][3] = a[0][1];
                                ans[1][0] = a[1][0];
                                ans[1][1] = a[0][1];
                                ans[1][2] = a[1][0];
                                ans[1][3] = a[1][1];
                                ans[2][0] = a[1][0];
                                ans[2][1] = a[2][1];
                                ans[2][2] = a[2][0];
                                ans[2][3] = a[2][1];
                            }
                        }
                    }
                }
            }
        }
        print(k);
        for (int i = 0; i < k; i++) {
            print(ans[i]);
        }
        bw.flush();
    }
}
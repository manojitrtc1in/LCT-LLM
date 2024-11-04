import java.io.*;
import java.util.*;

import static java.lang.Math.abs;


public class Main {
    long M = 1000000007;
    boolean multiCase = true;

    private void preparation() {

    }

    private void solve() throws Exception {
        rf();
        int n = ri();
        rf();
        long[] k = id1(n, 1, 0, 0);
        rf(); long[]h = id1(n, 1, 0, 0);
        long [] dp = new long[n + 1];
        fill(dp, Long.MAX_VALUE);
        dp[0] = 0;
        for(int i = 1; i <= n; i++){
            if(k[i] - k[i-1] >= h[i]){
                dp[i] = dp[i-1] + (1 + h[i]) * h[i] / 2;
                continue;
            }
            long m = k[i] - h[i] + 1;
            for(int j = i - 1; j >= 1; j--){
                m = min(m, k[j] - h[j] + 1);
                if(m > k[j-1]){
                    dp[i] = min(dp[i], dp[j - 1] + (1 + k[i] - m + 1) * (k[i] - m + 1) / 2);
                }
            }
        }
        addAns(dp[n]);
    }

    private void clear() {

    }

    private void run() throws Exception {

        int T = 1;
        if (multiCase) {
            rf();
            T = ri();
        }

        preparation();
        while (T-- > 0) {
            solve();
            if (T != 0) {
                clear();
            }
        }
        printAns();
    }

    public static void main(String[] args) throws Exception {
        new Main().run();
    }

    StringBuilder sb = new StringBuilder();
    BufferedReader infile = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer strT;

    public boolean id2;

    private void addAns(int a) {
        sb.append(a).append("\n");
    }

    private void addAns(long a) {
        sb.append(a).append("\n");
    }

    private void addAns(String s) {
        sb.append(s).append("\n");
    }

    private void addAns(int[] A, int x) {
        sb.append(A[0]);
        int t = min(A.length, x);
        for (int i = 1; i < t; i++) {
            sb.append(" ").append(A[i]);
        }
        sb.append("\n");
    }

    private void addAns(long[] A, int x) {
        sb.append(A[0]);
        int t = min(A.length, x);
        for (int i = 1; i < t; i++) {
            sb.append(" ").append(A[i]);
        }
        sb.append("\n");
    }

    private void addYes() {
        sb.append("Yes\n");
    }

    private void addNo() {
        sb.append("No\n");
    }

    private void rf() throws IOException {
        strT = new StringTokenizer(infile.readLine());
    }

    private int ri() {
        return Integer.parseInt(strT.nextToken());
    }

    private long rl() {
        return Long.parseLong(strT.nextToken());
    }

    private char[] id4() {
        return strT.nextToken().toCharArray();
    }

    private String rs() {
        return strT.nextToken();
    }


    private int[] readArr(int N, int start_pos, int suffix_num, int suffix_value) {
        int[] arr = new int[N + start_pos + suffix_num];
        for (int i = 0; i < N; i++) {
            arr[i + start_pos] = Integer.parseInt(strT.nextToken());
        }
        for(int i = N + start_pos; i < arr.length; i++){
            arr[i] = suffix_value;
        }
        return arr;
    }

    private long[] id1(int N, int start_pos, int suffix_num, long suffix_value) {
        long[] arr = new long[N + start_pos + suffix_num];
        for (int i = 0; i < N; i++) {
            arr[i + start_pos] = Long.parseLong(strT.nextToken());
        }
        for(int i = N + start_pos; i < arr.length; i++){
            arr[i] = suffix_value;
        }
        return arr;
    }

    public boolean PRINT_FUNCTION;

    private void print(String format, Object... args) {
        System.out.printf((format), args);
    }

    

    private void iprint(String format, Object... args) {
        System.out.printf((format), args);
        System.out.flush();
    }

    private void print(int[] arr, int x) {
        

        for (int i = 0; i < min(arr.length, x); i++) {
            System.out.print(arr[i] + " ");
        }
        System.out.println();
    }

    private void print(long[] arr, int x) {
        

        for (int i = 0; i < min(arr.length, x); i++) {
            System.out.print(arr[i] + " ");
        }
        System.out.println();
    }

    private void printAns() {
        System.out.print(sb);
    }

    public boolean id0;

    private int add(int a, int b) {
        return (int) add((long) a, (long) b);
    }

    private int add(int a, int b, int c) {
        return (int) add((long) a, (long) b, (long) c);
    }

    private int add(int a, int b, int c, int d) {
        return (int) add((long) a, (long) b, (long) c, (long) d);
    }

    private long add(long a, long b) {
        return (a % M + b % M) % M;
    }

    private long add(long a, long b, long c) {
        return (a % M + add(b, c)) % M;
    }

    private long add(long a, long b, long c, long d) {
        return (a % M + add(b, c, d)) % M;
    }

    private long mod(long x) {
        return (x % M + M) % M;
    }

    private int mod(int x) {
        return (int) (((x % M) + M) % M);
    }

    public boolean id9;

    private HashMap<Integer, Integer> hash(int[] A) {
        HashMap<Integer, Integer> map = new HashMap<Integer, Integer>();
        for (int i : A) {
            if (map.containsKey(i)) {
                map.put(i, map.get(i) + 1);
            } else {
                map.put(i, 1);
            }
        }
        return map;
    }

    private HashMap<Long, Integer> hash(long[] A) {
        HashMap<Long, Integer> map = new HashMap<Long, Integer>();
        for (long i : A) {
            if (map.containsKey(i)) {
                map.put(i, map.get(i) + 1);
            } else {
                map.put(i, 1);
            }
        }
        return map;
    }

    private TreeMap<Integer, Integer> tree(int[] A) {
        TreeMap<Integer, Integer> map = new TreeMap<Integer, Integer>();
        for (int i : A) {
            if (map.containsKey(i)) {
                map.put(i, map.get(i) + 1);
            } else {
                map.put(i, 1);
            }
        }
        return map;
    }

    private TreeMap<Long, Integer> tree(long[] A) {
        TreeMap<Long, Integer> map = new TreeMap<Long, Integer>();
        for (long i : A) {
            if (map.containsKey(i)) {
                map.put(i, map.get(i) + 1);
            } else {
                map.put(i, 1);
            }
        }
        return map;
    }

    public boolean SORT_FUNCTION;

    private int[] sort(int[] A) {
        int n = A.length;
        Random rnd = new Random();
        for (int i = 0; i < n; ++i) {
            int tmp = A[i];
            int randomPos = i + rnd.nextInt(n - i);
            A[i] = A[randomPos];
            A[randomPos] = tmp;
        }
        Arrays.sort(A);
        return A;
    }

    private long[] sort(long[] A) {
        int n = A.length;
        Random rnd = new Random();
        for (int i = 0; i < n; ++i) {
            long tmp = A[i];
            int randomPos = i + rnd.nextInt(n - i);
            A[i] = A[randomPos];
            A[randomPos] = tmp;
        }
        Arrays.sort(A);
        return A;
    }

    private String sort(String s) {
        char[] sc = s.toCharArray();
        Arrays.sort(sc);
        return new String(sc);
    }

    private char[] sort(char[] cs) {
        Arrays.sort(cs);
        return cs;
    }

    private int[][] sort(int[][] A, Comparator<int[]> c) {
        Arrays.sort(A, c);
        return A;
    }

    public boolean id7;

    private String reverse(String s) {
        StringBuilder p = new StringBuilder(s);
        p.reverse();
        return p.toString();
    }

    private long sum(int[] A) {
        long sum = 0;
        for (int i : A) {
            sum += i;
        }
        return sum;
    }

    private long sum(long[] A) {
        long sum = 0;
        for (long i : A) {
            sum += i;
        }
        return sum;
    }

    private void reverse(long[] A) {
        int n = A.length;
        long[] B = new long[n];
        for (int i = 0; i < n; i++) {
            B[i] = A[n - i - 1];
        }
        System.arraycopy(B, 0, A, 0, n);

    }

    private void reverse(int[] A) {
        int n = A.length;
        int[] B = new int[n];
        for (int i = 0; i < n; i++) {
            B[i] = A[n - i - 1];
        }
        System.arraycopy(B, 0, A, 0, n);

    }


    private int id11(int n) {
        n--;
        n |= n >> 1;
        n |= n >> 2;
        n |= n >> 4;
        n |= n >> 8;
        n |= n >> 16;
        n++;

        return n;
    }

    private int id5(int x) {

        x |= x >> 1;
        x |= x >> 2;
        x |= x >> 4;
        x |= x >> 8;
        x |= x >> 16;

        return x ^ (x >> 1);

    }

    private long id5(long x) {

        x |= x >> 1;
        x |= x >> 2;
        x |= x >> 4;
        x |= x >> 8;
        x |= x >> 16;
        return x ^ (x >> 1);

    }

    public boolean id6;

    private int max(int[] A) {
        int max = Integer.MIN_VALUE;
        for (int j : A) {
            max = Math.max(max, j);
        }
        return max;
    }

    private int min(int[] A) {
        int min = Integer.MAX_VALUE;
        for (int j : A) {
            min = Math.min(min, j);
        }
        return min;
    }

    private long max(long[] A) {
        long max = Long.MIN_VALUE;
        for (long l : A) {
            max = Math.max(max, l);
        }
        return max;
    }

    private long min(long[] A) {
        long min = Long.MAX_VALUE;
        for (long l : A) {
            min = Math.min(min, l);
        }
        return min;
    }

    public boolean id3;

    private long[] prefix(long[] A) {
        long[] p = new long[A.length];
        p[0] = A[0];
        for (int i = 1; i < A.length; i++)
            p[i] = p[i - 1] + A[i];
        return p;
    }

    private long[] prefix(int[] A) {
        long[] p = new long[A.length];
        p[0] = A[0];
        for (int i = 1; i < A.length; i++)
            p[i] = p[i - 1] + A[i];
        return p;
    }

    private long[] suffix(long[] A) {
        long[] p = new long[A.length];
        p[A.length - 1] = A[A.length - 1];
        for (int i = A.length - 2; i >= 0; i--)
            p[i] = p[i + 1] + A[i];
        return p;
    }

    private long[] suffix(int[] A) {
        long[] p = new long[A.length];
        p[A.length - 1] = A[A.length - 1];
        for (int i = A.length - 2; i >= 0; i--)
            p[i] = p[i + 1] + A[i];
        return p;
    }

    public boolean id10;

    private void fill(int[] dp, int v) {
        Arrays.fill(dp, v);
    }

    private void fill(int[][] dp, int v) {
        for (int[] ints : dp) {
            Arrays.fill(ints, v);
        }
    }

    private void fill(int[][][] dp, int v) {
        for (int i = 0; i < dp.length; i++) {
            for (int j = 0; j < dp[0].length; j++) {
                Arrays.fill(dp[i][j], v);
            }
        }
    }

    private void fill(int[][][][] dp, int v) {
        for (int i = 0; i < dp.length; i++) {
            for (int j = 0; j < dp[0].length; j++) {
                for (int k = 0; k < dp[0][0].length; k++) {
                    Arrays.fill(dp[i][j][k], v);
                }
            }
        }
    }

    private void fill(long[] dp, long v) {
        Arrays.fill(dp, v);
    }

    private void fill(long[][] dp, long v) {
        for (long[] longs : dp) Arrays.fill(longs, v);
    }

    private void fill(long[][][] dp, long v) {
        for (long[][] ones : dp) {
            for (long[] two : ones) {
                Arrays.fill(two, v);
            }
        }
    }

    private void fill(long[][][][] dp, long v) {
        for (int i = 0; i < dp.length; i++) {
            for (int j = 0; j < dp[0].length; j++) {
                for (int k = 0; k < dp[0][0].length; k++) {
                    Arrays.fill(dp[i][j][k], v);
                }
            }
        }
    }

    public boolean id8;
    


    private int min(int a, int b) {
        return Math.min(a, b);
    }

    private long min(long a, long b) {
        return Math.min(a, b);
    }

    private float min(float a, float b) {
        return Math.min(a, b);
    }

    private double min(double a, double b) {
        return Math.min(a, b);
    }


    private int min(int a, int b, int c) {
        return Math.min(a, Math.min(b, c));
    }

    private float min(float a, float b, float c) {
        return Math.min(a, Math.min(b, c));
    }

    private double min(double a, double b, double c) {
        return Math.min(a, Math.min(b, c));
    }

    private long min(long a, long b, long c) {
        return Math.min(a, Math.min(b, c));
    }

    private int min(int a, int b, int c, int d) {
        return Math.min(Math.min(a, b), Math.min(c, d));
    }

    private long min(long a, long b, long c, long d) {
        return Math.min(Math.min(a, b), Math.min(c, d));
    }

    private float min(float a, float b, float c, float d) {
        return Math.min(Math.min(a, b), Math.min(c, d));
    }

    private double min(double a, double b, double c, double d) {
        return Math.min(Math.min(a, b), Math.min(c, d));
    }

    private int max(int a, int b) {
        return Math.max(a, b);
    }

    private long max(long a, long b) {
        return Math.max(a, b);
    }

    private float max(float a, float b) {
        return Math.max(a, b);
    }

    private double max(double a, double b) {
        return Math.max(a, b);
    }

    private int max(int a, int b, int c) {
        return Math.max(a, Math.max(b, c));
    }

    private float max(float a, float b, float c) {
        return Math.max(a, Math.max(b, c));
    }

    private double max(double a, double b, double c) {
        return Math.max(a, Math.max(b, c));
    }

    private long max(long a, long b, long c) {
        return Math.max(a, Math.max(b, c));
    }

    private int max(int a, int b, int c, int d) {
        return Math.max(Math.max(a, b), Math.max(c, d));
    }

    private long max(long a, long b, long c, long d) {
        return Math.max(Math.max(a, b), Math.max(c, d));
    }

    private float max(float a, float b, float c, float d) {
        return Math.max(Math.max(a, b), Math.max(c, d));
    }

    private double max(double a, double b, double c, double d) {
        return Math.max(Math.max(a, b), Math.max(c, d));
    }

}

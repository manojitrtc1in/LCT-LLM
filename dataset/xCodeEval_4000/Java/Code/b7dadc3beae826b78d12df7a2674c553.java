import java.io.*;
import java.util.*;

import static java.lang.Math.*;
import static java.lang.Math.ceil;
import static java.util.Arrays.*;

public class Codeforces {
    static int mod = 1000000007;
    static int ar[] = new int[10];

    public static void main(String[] args) throws IOException {
        int t = ri();
        while (t-- > 0) {
            int n = rni();
            int k = ni();
            long a[] = rla(n);
            List<Long> pos  = new ArrayList<>() , neg = new ArrayList<>();
            for (long l : a){
                if(l < 0){
                    neg.add(-l);
                }else{
                    pos.add(l);
                }
            }
            pos.sort((x,y) -> Long.compare(y,x));
            neg.sort((x,y) -> Long.compare(y,x));
            long negBack = 0 , negEnd = 0  , posEnd = 0 , posBack = 0;
            int nsize = neg.size() , psize = pos.size();
            for (int i = 0 ; i < nsize ; i++){
                if (i == 0){
                    negEnd+=neg.get(i);
                    negBack+=(neg.get(i)*2);
                }else if (i%k == 0){
                    negEnd+=(neg.get(i)*2);
                    negBack+=(neg.get(i)*2);
                }
            }
            for (int i = 0 ; i < psize ; i++){
                if (i == 0){
                    posEnd+=pos.get(i);
                    posBack+=(pos.get(i)*2);
                }else if (i%k == 0){
                    posEnd+=(pos.get(i)*2);
                    posBack+=(pos.get(i)*2);
                }
            }
            prln(Math.min(posBack+negEnd,posEnd+negBack));
        }
        close();
    }

    static boolean check(int a, int b, int h, int m) {
        if (ar[a % 10] == -1 || ar[a / 10] == -1 || ar[b % 10] == -1 || ar[b / 10] == -1) {
            return false;
        }
        int x = ar[b % 10] * 10 + ar[b / 10];
        int y = ar[a % 10] * 10 + ar[a / 10];
        if (x < h && y < m) {
            return true;
        }
        return false;
    }

    static boolean isPalindrome(char[] c) {
        int low = 0, high = c.length - 1;
        while (low < high) {
            if (c[low] != c[high] || c[low] == '?' || c[high] == '?') return false;
            low++;
            high--;
        }
        return true;
    }


    static char get(int a) {
        return (char) (a + 'a');
    }

    static void addToPq(int n, PriorityQueue<Integer> p) {
        for (int i = 0; i < n; i++) {
            p.add(i);
        }
    }

    static boolean better(int a, int b, int[][] matrix) {
        int cnt = 0;
        for (int i = 0; i < 5; i++) {
            if (matrix[a][i] < matrix[b][i]) cnt++;
        }
        return cnt >= 3;
    }

    static BufferedReader __i = new BufferedReader(new InputStreamReader(System.in));
    static PrintWriter __o = new PrintWriter(new OutputStreamWriter(System.out));
    static StringTokenizer input;
    static Random __r = new Random();

    

    

    

    


    

    static final int IBIG = 1000000007;
    static final int IMAX = 2147483647;
    static final long LMAX = 9223372036854775807L;

    

    static int minof(int a, int b, int c) {
        return min(a, min(b, c));
    }

    static int minof(int... x) {
        if (x.length == 1) return x[0];
        if (x.length == 2) return min(x[0], x[1]);
        if (x.length == 3) return min(x[0], min(x[1], x[2]));
        int min = x[0];
        for (int i = 1; i < x.length; ++i) if (x[i] < min) min = x[i];
        return min;
    }

    static long minof(long a, long b, long c) {
        return min(a, min(b, c));
    }

    static long minof(long... x) {
        if (x.length == 1) return x[0];
        if (x.length == 2) return min(x[0], x[1]);
        if (x.length == 3) return min(x[0], min(x[1], x[2]));
        long min = x[0];
        for (int i = 1; i < x.length; ++i) if (x[i] < min) min = x[i];
        return min;
    }

    static int maxof(int a, int b, int c) {
        return max(a, max(b, c));
    }

    static int maxof(int... x) {
        if (x.length == 1) return x[0];
        if (x.length == 2) return max(x[0], x[1]);
        if (x.length == 3) return max(x[0], max(x[1], x[2]));
        int max = x[0];
        for (int i = 1; i < x.length; ++i) if (x[i] > max) max = x[i];
        return max;
    }

    static long maxof(long a, long b, long c) {
        return max(a, max(b, c));
    }

    static long maxof(long... x) {
        if (x.length == 1) return x[0];
        if (x.length == 2) return max(x[0], x[1]);
        if (x.length == 3) return max(x[0], max(x[1], x[2]));
        long max = x[0];
        for (int i = 1; i < x.length; ++i) if (x[i] > max) max = x[i];
        return max;
    }

    static int powi(int a, int b) {
        if (a == 0) return 0;
        int ans = 1;
        while (b > 0) {
            if ((b & 1) > 0) ans *= a;
            a *= a;
            b >>= 1;
        }
        return ans;
    }

    static long powl(long a, int b) {
        if (a == 0) return 0;
        long ans = 1;
        while (b > 0) {
            if ((b & 1) > 0) ans *= a;
            a *= a;
            b >>= 1;
        }
        return ans;
    }

    static int fli(double d) {
        return (int) d;
    }

    static int cei(double d) {
        return (int) ceil(d);
    }

    static long fll(double d) {
        return (long) d;
    }

    static long cel(double d) {
        return (long) ceil(d);
    }

    static int gcd(int a, int b) {
        return b == 0 ? a : gcd(b, a % b);
    }

    static long gcd(long a, long b) {
        return b == 0 ? a : gcd(b, a % b);
    }

    static int[] exgcd(int a, int b) {
        if (b == 0) return new int[]{1, 0};
        int[] y = exgcd(b, a % b);
        return new int[]{y[1], y[0] - y[1] * (a / b)};
    }

    static long[] exgcd(long a, long b) {
        if (b == 0) return new long[]{1, 0};
        long[] y = exgcd(b, a % b);
        return new long[]{y[1], y[0] - y[1] * (a / b)};
    }

    static int randInt(int min, int max) {
        return __r.nextInt(max - min + 1) + min;
    }

    static long mix(long x) {
        x += 0x9e3779b97f4a7c15L;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9L;
        x = (x ^ (x >> 27)) * 0x94d049bb133111ebL;
        return x ^ (x >> 31);
    }

    public static boolean[] findPrimes(int limit) {
        assert limit >= 2;

        final boolean[] nonPrimes = new boolean[limit];
        nonPrimes[0] = true;
        nonPrimes[1] = true;

        int sqrt = (int) Math.sqrt(limit);
        for (int i = 2; i <= sqrt; i++) {
            if (nonPrimes[i]) continue;
            for (int j = i; j < limit; j += i) {
                if (!nonPrimes[j] && i != j) nonPrimes[j] = true;
            }
        }

        return nonPrimes;
    }

    

    static void reverse(int[] a) {
        for (int i = 0, n = a.length, half = n / 2; i < half; ++i) {
            int swap = a[i];
            a[i] = a[n - i - 1];
            a[n - i - 1] = swap;
        }
    }

    static void reverse(long[] a) {
        for (int i = 0, n = a.length, half = n / 2; i < half; ++i) {
            long swap = a[i];
            a[i] = a[n - i - 1];
            a[n - i - 1] = swap;
        }
    }

    static void reverse(double[] a) {
        for (int i = 0, n = a.length, half = n / 2; i < half; ++i) {
            double swap = a[i];
            a[i] = a[n - i - 1];
            a[n - i - 1] = swap;
        }
    }

    static void reverse(char[] a) {
        for (int i = 0, n = a.length, half = n / 2; i < half; ++i) {
            char swap = a[i];
            a[i] = a[n - i - 1];
            a[n - i - 1] = swap;
        }
    }

    static void shuffle(int[] a) {
        int n = a.length - 1;
        for (int i = 0; i < n; ++i) {
            int ind = randInt(i, n);
            int swap = a[i];
            a[i] = a[ind];
            a[ind] = swap;
        }
    }

    static void shuffle(long[] a) {
        int n = a.length - 1;
        for (int i = 0; i < n; ++i) {
            int ind = randInt(i, n);
            long swap = a[i];
            a[i] = a[ind];
            a[ind] = swap;
        }
    }

    static void shuffle(double[] a) {
        int n = a.length - 1;
        for (int i = 0; i < n; ++i) {
            int ind = randInt(i, n);
            double swap = a[i];
            a[i] = a[ind];
            a[ind] = swap;
        }
    }

    static void rsort(int[] a) {
        shuffle(a);
        sort(a);
    }

    static void rsort(long[] a) {
        shuffle(a);
        sort(a);
    }

    static void rsort(double[] a) {
        shuffle(a);
        sort(a);
    }

    static int[] copy(int[] a) {
        int[] ans = new int[a.length];
        for (int i = 0; i < a.length; ++i) ans[i] = a[i];
        return ans;
    }

    static long[] copy(long[] a) {
        long[] ans = new long[a.length];
        for (int i = 0; i < a.length; ++i) ans[i] = a[i];
        return ans;
    }

    static double[] copy(double[] a) {
        double[] ans = new double[a.length];
        for (int i = 0; i < a.length; ++i) ans[i] = a[i];
        return ans;
    }

    static char[] copy(char[] a) {
        char[] ans = new char[a.length];
        for (int i = 0; i < a.length; ++i) ans[i] = a[i];
        return ans;
    }

    static void resetBoolean(boolean[] vis, int n) {
        for (int i = 0; i < n; i++) {
            vis[i] = false;
        }
    }

    static void setMinusOne(int[][] matrix) {
        int row = matrix.length;
        int col = matrix[0].length;

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                matrix[i][j] = -1;
            }
        }

    }

    

    static void r() throws IOException {
        input = new StringTokenizer(rline());
    }

    static int ri() throws IOException {
        return Integer.parseInt(rline().split(" ")[0]);
    }

    static long rl() throws IOException {
        return Long.parseLong(rline());
    }

    static double rd() throws IOException {
        return Double.parseDouble(rline());
    }

    static int[] ria(int n) throws IOException {
        int[] a = new int[n];
        r();
        for (int i = 0; i < n; ++i) a[i] = ni();
        return a;
    }

    static void ria(int[] a) throws IOException {
        int n = a.length;
        r();
        for (int i = 0; i < n; ++i) a[i] = ni();
    }

    static int[] riam1(int n) throws IOException {
        int[] a = new int[n];
        r();
        for (int i = 0; i < n; ++i) a[i] = ni() - 1;
        return a;
    }

    static void riam1(int[] a) throws IOException {
        int n = a.length;
        r();
        for (int i = 0; i < n; ++i) a[i] = ni() - 1;
    }

    static long[] rla(int n) throws IOException {
        long[] a = new long[n];
        r();
        for (int i = 0; i < n; ++i) a[i] = nl();
        return a;
    }

    static void rla(long[] a) throws IOException {
        int n = a.length;
        r();
        for (int i = 0; i < n; ++i) a[i] = nl();
    }

    static double[] rda(int n) throws IOException {
        double[] a = new double[n];
        r();
        for (int i = 0; i < n; ++i) a[i] = nd();
        return a;
    }

    static void rda(double[] a) throws IOException {
        int n = a.length;
        r();
        for (int i = 0; i < n; ++i) a[i] = nd();
    }

    static char[] rcha() throws IOException {
        return rline().toCharArray();
    }

    static void rcha(char[] a) throws IOException {
        int n = a.length, i = 0;
        for (char c : rline().toCharArray()) a[i++] = c;
    }

    static String rline() throws IOException {
        return __i.readLine();
    }

    static String n() {
        return input.nextToken();
    }

    static int rni() throws IOException {
        r();
        return ni();
    }

    static int ni() {
        return Integer.parseInt(n());
    }

    static long rnl() throws IOException {
        r();
        return nl();
    }

    static long nl() {
        return Long.parseLong(n());
    }

    static double rnd() throws IOException {
        r();
        return nd();
    }

    static double nd() {
        return Double.parseDouble(n());
    }

    

    static void pr(int i) {
        __o.print(i);
    }

    static void prln(int i) {
        __o.println(i);
    }

    static void pr(long l) {
        __o.print(l);
    }

    static void prln(long l) {
        __o.println(l);
    }

    static void pr(double d) {
        __o.print(d);
    }

    static void prln(double d) {
        __o.println(d);
    }

    static void pr(char c) {
        __o.print(c);
    }

    static void prln(char c) {
        __o.println(c);
    }

    static void pr(char[] s) {
        __o.print(new String(s));
    }

    static void prln(char[] s) {
        __o.println(new String(s));
    }

    static void pr(String s) {
        __o.print(s);
    }

    static void prln(String s) {
        __o.println(s);
    }

    static void pr(Object o) {
        __o.print(o);
    }

    static void prln(Object o) {
        __o.println(o);
    }

    static void prln() {
        __o.println();
    }

    static void pryes() {
        prln("yes");
    }

    static void pry() {
        prln("Yes");
    }

    static void prY() {
        prln("YES");
    }

    static void prno() {
        prln("no");
    }

    static void prn() {
        prln("No");
    }

    static void prN() {
        prln("NO");
    }

    static boolean pryesno(boolean b) {
        prln(b ? "yes" : "no");
        return b;
    }

    ;

    static boolean pryn(boolean b) {
        prln(b ? "Yes" : "No");
        return b;
    }

    static boolean prYN(boolean b) {
        prln(b ? "YES" : "NO");
        return b;
    }

    static void prln(int... a) {
        for (int i = 0, len = a.length - 1; i < len; pr(a[i]), pr(' '), ++i) ;
        if (a.length > 0) prln(a[a.length - 1]);
        else prln();
    }

    static void prln(long... a) {
        for (int i = 0, len = a.length - 1; i < len; pr(a[i]), pr(' '), ++i) ;
        if (a.length > 0) prln(a[a.length - 1]);
        else prln();
    }

    static void prln(double... a) {
        for (int i = 0, len = a.length - 1; i < len; pr(a[i]), pr(' '), ++i) ;
        if (a.length > 0) prln(a[a.length - 1]);
        else prln();
    }

    static <T> void prln(Collection<T> c) {
        int n = c.size() - 1;
        Iterator<T> iter = c.iterator();
        for (int i = 0; i < n; pr(iter.next()), pr(' '), ++i) ;
        if (n >= 0) prln(iter.next());
        else prln();
    }

    static void h() {
        prln("hlfd");
        flush();
    }

    static void flush() {
        __o.flush();
    }

    static void close() {
        __o.close();
    }

}

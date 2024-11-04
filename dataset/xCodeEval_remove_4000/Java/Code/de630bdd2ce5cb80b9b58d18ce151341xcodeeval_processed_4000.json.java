import java.io.*;
import java.util.*;

import static java.lang.Math.*;
import static java.util.Arrays.sort;

public class JavaCp {

    public static final int N = 1000 + 7;
    public static int[] id10 = new int[N];
    public static int[] id6 = new int[N];

    public static int[] id7 = new int[N];
    public static int[] id5 = new int[N];

    public static void main(String[] args) throws IOException {
        int test[] = ria(3);
        int n = test[0];
        int m1 = test[1];
        int m2 = test[2];
        init();
        for (int i = 0; i < m1; i++) {
            int curr[] = ria(2);
            id3(curr[0], curr[1]);
        }
        for (int i = 0; i < m2; i++) {
            int curr[] = ria(2);
            id2(curr[0], curr[1]);
        }
        ArrayList<String> ans = new ArrayList<>();
        for (int i = 1 ; i <=n ; i++){
            for (int j = i+1; j <= n ; j++){
                if (id0(i) != id0(j) && id4(i) != id4(j)){
                    id2(i,j);
                    id3(i,j);
                    ans.add(i + " " + j);
                }
            }
        }
        prln(ans.size());
        for (String s : ans){
            prln(s);
        }
        close();
    }

    public static void init() {
        for (int i = 1; i < N; i++) {
            id10[i] = i;
            id6[i] = 1;
            id7[i] = i;
            id5[i] = 1;
        }
    }

    public static int id4(int v) {
        if (v == id10[v]) return v;
        return id4(id10[v]);
    }

    public static int id0(int v) {
        if (v == id7[v]) return v;
        return id0(id7[v]);
    }

    public static void id2(int x, int y) {
        int u = id4(x);
        int v = id4(y);
        if (u == v) return;
        else if (id6[u] > id6[v]) {
            id10[v] = u;
        } else if (id6[u] < id6[v]) {
            id10[u] = v;
        } else {
            id10[v] = u;
            id6[u]++;
        }
    }

    public static void id3(int x, int y) {
        int u = id0(x);
        int v = id0(y);
        if (u == v) return;
        else if (id5[u] > id5[v]) {
            id7[v] = u;
        } else if (id5[u] < id5[v]) {
            id7[u] = v;
        } else {
            id7[v] = u;
            id5[u]++;
        }
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

    static int[] id1(int a, int b) {
        if (b == 0) return new int[]{1, 0};
        int[] y = id1(b, a % b);
        return new int[]{y[1], y[0] - y[1] * (a / b)};
    }

    static long[] id1(long a, long b) {
        if (b == 0) return new long[]{1, 0};
        long[] y = id1(b, a % b);
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

    

    static void r() throws IOException {
        input = new StringTokenizer(rline());
    }

    static int ri() throws IOException {
        return Integer.parseInt(rline());
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

    static int[] id9(int n) throws IOException {
        int[] a = new int[n];
        r();
        for (int i = 0; i < n; ++i) a[i] = ni() - 1;
        return a;
    }

    static void id9(int[] a) throws IOException {
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

    static boolean id8(boolean b) {
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

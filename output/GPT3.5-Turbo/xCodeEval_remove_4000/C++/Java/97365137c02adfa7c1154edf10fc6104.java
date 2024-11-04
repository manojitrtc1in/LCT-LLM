import java.util.*;
import java.io.*;

class Main {
    static class Modular {
        int value;
        static final int MOD_VAL = 7;

        Modular(long v) {
            value = (int) (v % MOD_VAL);
            if (value < 0)
                value += MOD_VAL;
        }

        Modular(long a, long b) {
            this();
            this += a;
            this /= b;
        }

        Modular exp(Modular a, long k) {
            Modular res = 1;
            while (k != 0) {
                if ((k & 1) != 0)
                    res *= a;
                a *= a;
                k >>= 1;
            }
            return res;
        }

        Modular inv() {
            return exp(value, MOD_VAL - 2);
        }

        Modular operator+=(Modular o) {
            value += o.value;
            if (value >= MOD_VAL)
                value -= MOD_VAL;
            return this;
        }

        Modular operator-=(Modular o) {
            value -= o.value;
            if (value < 0)
                value += MOD_VAL;
            return this;
        }

        Modular operator*=(Modular o) {
            value = (int) ((long) value * o.value % MOD_VAL);
            return this;
        }

        Modular operator/=(Modular o) {
            return this *= o.inv();
        }

        Modular operator++() {
            return this += 1;
        }

        Modular operator--() {
            return this -= 1;
        }

        Modular operator+(Modular a, Modular b) {
            return new Modular(a.value + b.value);
        }

        Modular operator-(Modular a, Modular b) {
            return a -= b;
        }

        Modular operator-(Modular a) {
            return 0 - a;
        }

        Modular operator*(Modular a, Modular b) {
            return a *= b;
        }

        Modular operator/(Modular a, Modular b) {
            return a /= b;
        }

        boolean operator==(Modular o) {
            return value == o.value;
        }

        boolean operator!=(Modular o) {
            return value != o.value;
        }

        public String toString() {
            return Integer.toString(value);
        }

        public int intValue() {
            return value;
        }
    }

    static class Pair<T1, T2> {
        T1 st;
        T2 nd;

        Pair(T1 st, T2 nd) {
            this.st = st;
            this.nd = nd;
        }
    }

    static class FastScanner {
        BufferedReader br;
        StringTokenizer st;

        FastScanner(InputStreamReader isr) {
            br = new BufferedReader(isr);
            st = null;
        }

        String next() {
            while (st == null || !st.hasMoreTokens()) {
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

    static final int INF = 1_000_000_000;
    static final long LINF = 1_000_000_000_000_000_000L;
    static final long M = 1_000_000_007;

    static final int C = 20;
    static ArrayList<Integer>[] G = new ArrayList[C];
    static ArrayList<Integer> cur = new ArrayList<>();
    static int[] masks = new int[C];
    static boolean[] dp = new boolean[1 << C];
    static boolean[] vis = new boolean[C];
    static int mask;

    static void dfs(int v) {
        vis[v] = true;
        mask |= 1 << v;
        cur.add(v);

        for (int s : G[v]) {
            if (!vis[s]) {
                dfs(s);
            }
        }
    }

    static int count() {
        ArrayList<Integer> sub = new ArrayList<>();
        for (int m = mask; m > 0; m = (m - 1) & mask) {
            sub.add(m);
        }
        Collections.reverse(sub);

        int res = 0;
        for (int m : sub) {
            for (int v : cur) {
                if ((m & (1 << v)) != 0) {
                    dp[m] |= dp[m ^ (1 << v)] && ((m & masks[v] & mask) == 0);
                }
            }
            if (dp[m]) {
                res = Math.max(res, pct(m));
            }
        }
        return res;
    }

    static int solve() {
        int n = fs.nextInt();
        String s = fs.next();
        String t = fs.next();

        int res = 0;
        Arrays.fill(dp, false);
        Arrays.fill(vis, false);
        Arrays.fill(masks, 0);
        for (int i = 0; i < C; i++) {
            G[i] = new ArrayList<>();
        }

        for (int i = 0; i < n; i++) {
            if (s.charAt(i) != t.charAt(i)) {
                int a = get(s.charAt(i));
                int b = get(t.charAt(i));
                G[a].add(b);
                G[b].add(a);
                masks[a] |= 1 << b;
            }
        }

        for (int i = 0; i < C; i++) {
            if (!vis[i]) {
                mask = 0;
                cur.clear();
                dfs(i);
                int tmp = count();
                res += 2 * cur.size() - 1 - tmp;
            }
        }

        return res;
    }

    static int get(char c) {
        return c - 'a';
    }

    static int pct(int x) {
        int res = 0;
        while (x != 0) {
            res += x & 1;
            x >>= 1;
        }
        return res;
    }

    static void print() {
        System.out.println();
    }

    static void print(Object last) {
        System.out.println(last);
    }

    static void print(Object first, Object... rest) {
        System.out.print(first);
        for (Object obj : rest) {
            System.out.print(" " + obj);
        }
        System.out.println();
    }

    static void in(int[] arr, int n) {
        for (int i = 0; i < n; i++) {
            arr[i] = fs.nextInt();
        }
    }

    static void in(long[] arr, int n) {
        for (int i = 0; i < n; i++) {
            arr[i] = fs.nextLong();
        }
    }

    static void in(double[] arr, int n) {
        for (int i = 0; i < n; i++) {
            arr[i] = fs.nextDouble();
        }
    }

    static void in(char[] arr, int n) {
        for (int i = 0; i < n; i++) {
            arr[i] = fs.next().charAt(0);
        }
    }

    static void in(String[] arr, int n) {
        for (int i = 0; i < n; i++) {
            arr[i] = fs.next();
        }
    }

    static void out(int[] arr, int n, char endl, char sep) {
        for (int i = 0; i < n - 1; i++) {
            System.out.print(arr[i] + sep);
        }
        System.out.print(arr[n - 1] + endl);
    }

    static void out(long[] arr, int n, char endl, char sep) {
        for (int i = 0; i < n - 1; i++) {
            System.out.print(arr[i] + sep);
        }
        System.out.print(arr[n - 1] + endl);
    }

    static void out(double[] arr, int n, char endl, char sep) {
        for (int i = 0; i < n - 1; i++) {
            System.out.print(arr[i] + sep);
        }
        System.out.print(arr[n - 1] + endl);
    }

    static void out(char[] arr, int n, char endl, char sep) {
        for (int i = 0; i < n - 1; i++) {
            System.out.print(arr[i] + sep);
        }
        System.out.print(arr[n - 1] + endl);
    }

    static void out(String[] arr, int n, char endl, char sep) {
        for (int i = 0; i < n - 1; i++) {
            System.out.print(arr[i] + sep);
        }
        System.out.print(arr[n - 1] + endl);
    }

    static void out(int[] arr, int n) {
        out(arr, n, '\n', ' ');
    }

    static void out(long[] arr, int n) {
        out(arr, n, '\n', ' ');
    }

    static void out(double[] arr, int n) {
        out(arr, n, '\n', ' ');
    }

    static void out(char[] arr, int n) {
        out(arr, n, '\n', ' ');
    }

    static void out(String[] arr, int n) {
        out(arr, n, '\n', ' ');
    }

    static void out(int[] arr, int n, char endl) {
        out(arr, n, endl, ' ');
    }

    static void out(long[] arr, int n, char endl) {
        out(arr, n, endl, ' ');
    }

    static void out(double[] arr, int n, char endl) {
        out(arr, n, endl, ' ');
    }

    static void out(char[] arr, int n, char endl) {
        out(arr, n, endl, ' ');
    }

    static void out(String[] arr, int n, char endl) {
        out(arr, n, endl, ' ');
    }

    static void out(int[] arr, int n, char endl, char sep, PrintWriter out) {
        for (int i = 0; i < n - 1; i++) {
            out.print(arr[i] + sep);
        }
        out.print(arr[n - 1] + endl);
    }

    static void out(long[] arr, int n, char endl, char sep, PrintWriter out) {
        for (int i = 0; i < n - 1; i++) {
            out.print(arr[i] + sep);
        }
        out.print(arr[n - 1] + endl);
    }

    static void out(double[] arr, int n, char endl, char sep, PrintWriter out) {
        for (int i = 0; i < n - 1; i++) {
            out.print(arr[i] + sep);
        }
        out.print(arr[n - 1] + endl);
    }

    static void out(char[] arr, int n, char endl, char sep, PrintWriter out) {
        for (int i = 0; i < n - 1; i++) {
            out.print(arr[i] + sep);
        }
        out.print(arr[n - 1] + endl);
    }

    static void out(String[] arr, int n, char endl, char sep, PrintWriter out) {
        for (int i = 0; i < n - 1; i++) {
            out.print(arr[i] + sep);
        }
        out.print(arr[n - 1] + endl);
    }

    static void out(int[] arr, int n, PrintWriter out) {
        out(arr, n, '\n', ' ', out);
    }

    static void out(long[] arr, int n, PrintWriter out) {
        out(arr, n, '\n', ' ', out);
    }

    static void out(double[] arr, int n, PrintWriter out) {
        out(arr, n, '\n', ' ', out);
    }

    static void out(char[] arr, int n, PrintWriter out) {
        out(arr, n, '\n', ' ', out);
    }

    static void out(String[] arr, int n, PrintWriter out) {
        out(arr, n, '\n', ' ', out);
    }

    static void pi(int x, char end) {
        System.out.print(x + end);
    }

    static void pl(long x, char end) {
        System.out.print(x + end);
    }

    static void pd(double x, char end) {
        System.out.print(x + end);
    }

    static void pld(double x, char end) {
        System.out.print(x + end);
    }

    static void pf(float x, char end) {
        System.out.print(x + end);
    }

    static void pc(char x, char end) {
        System.out.print(x + end);
    }

    static void ps(String x, char end) {
        System.out.print(x + end);
    }

    static int russian(int a, int k, int m) {
        int res = 0;
        while (k != 0) {
            if ((k & 1) != 0)
                res = (res + a) % m;
            a = (a + a) % m;
            k >>= 1;
        }
        return res;
    }

    static int fastpow(int a, int k, int m) {
        int res = 1;
        while (k != 0) {
            if ((k & 1) != 0)
                res = (res * a) % m;
            a = (a * a) % m;
            k >>= 1;
        }
        return res;
    }

    static int slowpow(int a, int k, int m) {
        int res = 1;
        while (k != 0) {
            if ((k & 1) != 0)
                res = russian(res, a, m);
            a = russian(a, a, m);
            k >>= 1;
        }
        return res;
    }

    static int _gcd(int a, int b) {
        while (b != 0) {
            int t = a % b;
            a = b;
            b = t;
        }
        return a;
    }

    static int _lcm(int a, int b) {
        return a / _gcd(a, b) * b;
    }

    static int _inv(int a, int p) {
        return fastpow(a, p - 2, p);
    }

    static int id0(int a, int b, int[] k, int[] l) {
        if (b == 0) {
            k[0] = 1;
            l[0] = 0;
            return a;
        }
        int res = id0(b, a % b, l, k);
        l[0] -= a / b * k[0];
        return res;
    }

    static void printBits(long x, int forceLen) {
        assert (0 <= forceLen && forceLen <= 64);
        char[] s = new char[64];
        int i = 63;
        if (forceLen != 0) {
            while (forceLen-- != 0) {
                s[i--] = (char) ('0' + (x & 1));
                x >>= 1;
            }
        } else {
            while (x != 0) {
                s[i--] = (char) ('0' + (x & 1));
                x >>= 1;
            }
        }
        System.out.println(new String(s, i + 1, 63 - i));
    }

    static Random rng = new Random();

    public static void main(String[] args) {
        FastScanner fs = new FastScanner(new InputStreamReader(System.in));
        PrintWriter out = new PrintWriter(System.out);

        int t = fs.nextInt();
        while (t-- > 0) {
            print(solve());
        }

        out.close();
    }
}

import java.util.*;
import java.io.*;

class Main {
    static class Modular {
        int value;
        static final int MOD_VAL = 7;

        public Modular(long v) {
            value = (int) (v % MOD_VAL);
            if (value < 0)
                value += MOD_VAL;
        }

        public Modular(long a, long b) {
            this(a);
            this.divide(b);
        }

        public Modular exp(Modular a, long k) {
            Modular res = new Modular(1);
            while (k > 0) {
                if ((k & 1) == 1)
                    res.multiply(a);
                a.multiply(a);
                k >>= 1;
            }
            return res;
        }

        public Modular inv() {
            return exp(new Modular(value), MOD_VAL - 2);
        }

        public void add(Modular o) {
            value += o.value;
            if (value >= MOD_VAL)
                value -= MOD_VAL;
        }

        public void subtract(Modular o) {
            value -= o.value;
            if (value < 0)
                value += MOD_VAL;
        }

        public void multiply(Modular o) {
            value = (int) ((long) value * o.value % MOD_VAL);
        }

        public void divide(Modular o) {
            multiply(o.inv());
        }

        public void increment() {
            add(new Modular(1));
        }

        public void decrement() {
            subtract(new Modular(1));
        }

        public int getValue() {
            return value;
        }

        public String toString() {
            return Integer.toString(value);
        }

        public boolean equals(Modular o) {
            return value == o.value;
        }

        public boolean notEquals(Modular o) {
            return value != o.value;
        }
    }

    static class Pair<T1, T2> {
        T1 first;
        T2 second;

        public Pair(T1 first, T2 second) {
            this.first = first;
            this.second = second;
        }

        public String toString() {
            return "(" + first.toString() + ", " + second.toString() + ")";
        }
    }

    static class Triple<T1, T2, T3> {
        T1 first;
        T2 second;
        T3 third;

        public Triple(T1 first, T2 second, T3 third) {
            this.first = first;
            this.second = second;
            this.third = third;
        }

        public String toString() {
            return "(" + first.toString() + ", " + second.toString() + ", " + third.toString() + ")";
        }
    }

    static class FastScanner {
        BufferedReader br;
        StringTokenizer st;

        public FastScanner(InputStream in) {
            br = new BufferedReader(new InputStreamReader(in));
            st = new StringTokenizer("");
        }

        public String next() throws IOException {
            while (!st.hasMoreTokens()) {
                st = new StringTokenizer(br.readLine());
            }
            return st.nextToken();
        }

        public int nextInt() throws IOException {
            return Integer.parseInt(next());
        }

        public long nextLong() throws IOException {
            return Long.parseLong(next());
        }

        public double nextDouble() throws IOException {
            return Double.parseDouble(next());
        }
    }

    static final int INF = 1_000_000_000;
    static final long LINF = 1_000_000_000_000_000_000L;
    static final int MOD = 1_000_000_007;

    static int dag(List<List<Integer>> g, List<Integer> cur) {
        int n = cur.size();
        boolean[] dp = new boolean[1 << n];
        int[] reach = new int[n];

        for (int i = 0; i < n; i++) {
            for (int s : g.get(cur.get(i))) {
                reach[i] |= 1 << cur.indexOf(s);
            }
        }

        int res = 0;
        dp[0] = true;
        for (int m = 1; m < (1 << n); m++) {
            for (int i = 0; i < n; i++) {
                if ((m & (1 << i)) != 0) {
                    dp[m] = dp[m] || (dp[m ^ (1 << i)] && ((reach[i] & m) == 0));
                }
            }
            if (dp[m]) {
                res = Math.max(res, Integer.bitCount(m));
            }
        }

        return res;
    }

    static int solve() throws IOException {
        FastScanner sc = new FastScanner(System.in);
        int n = sc.nextInt();
        String s = sc.next();
        String t = sc.next();

        List<List<Integer>> G = new ArrayList<>();
        List<List<Integer>> g = new ArrayList<>();
        for (int i = 0; i < 20; i++) {
            G.add(new ArrayList<>());
            g.add(new ArrayList<>());
        }

        for (int i = 0; i < n; i++) {
            if (s.charAt(i) != t.charAt(i)) {
                int a = s.charAt(i) - 'a';
                int b = t.charAt(i) - 'a';
                G.get(a).add(b);
                G.get(b).add(a);
                g.get(a).add(b);
            }
        }

        List<Integer> cur = new ArrayList<>();
        boolean[] vis = new boolean[20];
        for (int i = 0; i < 20; i++) {
            if (!vis[i]) {
                cur.clear();
                dfs(i, G, cur, vis);
                int s = dag(g, cur);
                res += 2 * cur.size() - 1 - s;
            }
        }

        return res;
    }

    static void dfs(int v, List<List<Integer>> G, List<Integer> cur, boolean[] vis) {
        vis[v] = true;
        cur.add(v);
        for (int s : G.get(v)) {
            if (!vis[s]) {
                dfs(s, G, cur, vis);
            }
        }
    }

    public static void main(String[] args) throws IOException {
        FastScanner sc = new FastScanner(System.in);
        int t = sc.nextInt();
        while (t-- > 0) {
            System.out.println(solve());
        }
    }
}

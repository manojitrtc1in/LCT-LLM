import java.util.*;
import java.io.*;

class Main {
    static class Modular {
        int value;
        static final int MOD_VAL = 7;

        Modular(long v) {
            value = (int) (v % MOD_VAL);
            if (value < 0) value += MOD_VAL;
        }

        Modular(long a, long b) {
            this();
            this += a;
            this /= b;
        }

        Modular exp(Modular a, long k) {
            Modular res = 1;
            while (k) {
                if (k & 1L) res *= a;
                a *= a;
                k >>= 1;
            }
            return res;
        }

        Modular inv() {
            return exp(value, MOD_VAL - 2);
        }

        Modular& operator+=(const Modular& o) {
            value += o.value;
            if (value >= MOD_VAL) value -= MOD_VAL;
            return *this;
        }

        Modular& operator-=(const Modular& o) {
            value -= o.value;
            if (value < 0) value += MOD_VAL;
            return *this;
        }

        Modular& operator*=(const Modular& o) {
            value = (int) ((long) value * o.value % MOD_VAL);
            return *this;
        }

        Modular& operator/=(const Modular& o) {
            return *this *= o.inv();
        }

        Modular& operator++() {
            return *this += 1;
        }

        Modular& operator--() {
            return *this -= 1;
        }

        Modular operator+(const Modular& a, const Modular& b) {
            return { a.value + b.value };
        }

        Modular operator-(const Modular& a, const Modular& b) {
            return a -= b;
        }

        Modular operator-(const Modular& a) {
            return 0 - a;
        }

        Modular operator*(const Modular& a, const Modular& b) {
            return a *= b;
        }

        Modular operator/(const Modular& a, const Modular& b) {
            return a /= b;
        }

        @Override
        public String toString() {
            return String.valueOf(value);
        }

        public int intValue() {
            return value;
        }

        public boolean equals(Modular o) {
            return value == o.value;
        }

        public boolean notEquals(Modular o) {
            return value != o.value;
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

        public FastScanner() {
            br = new BufferedReader(new InputStreamReader(System.in));
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

    static final int INF = 1e9;
    static final long LINF = 1e18;
    static final long M = 1e9 + 7;

    static final int C = 20;
    static List<Integer>[] G = new List[C];
    static List<Integer> cur = new ArrayList<>();
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
        List<Integer> sub = new ArrayList<>();
        for (int m = mask; m > 0; m = (m - 1) & mask) {
            sub.add(m);
        }
        Collections.reverse(sub);

        int res = 0;
        for (int m : sub) {
            for (int v : cur) {
                if ((m & (1 << v)) != 0) {
                    dp[m] |= dp[m ^ (1 << v)] & ((m & masks[v] & mask) == 0);
                }
            }
            if (dp[m]) {
                res = Math.max(res, pct(m));
            }
        }
        return res;
    }

    static int solve() {
        FastScanner sc = new FastScanner();
        int n = sc.nextInt();
        String s = sc.next();
        String t = sc.next();

        int res = 0;
        Arrays.fill(dp, false);
        Arrays.fill(vis, false);
        Arrays.fill(masks, 0);
        for (int i = 0; i < C; i++) {
            G[i] = new ArrayList<>();
        }

        for (int i = 0; i < n; i++) {
            if (s.charAt(i) != t.charAt(i)) {
                int a = s.charAt(i) - 'a';
                int b = t.charAt(i) - 'a';
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

    public static void main(String[] args) {
        FastScanner sc = new FastScanner();
        int t = sc.nextInt();
        while (t-- > 0) {
            System.out.println(solve());
        }
    }
}

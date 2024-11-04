import java.util.*;
import java.util.function.Function;

class Main {
    static final int INF = (int) 1e9;
    static final long LINF = (long) 1e18;
    static final long M = (long) 1e9 + 7;
    static final int C = 20;

    static class Modular {
        int value;
        static final int MOD_VAL = 7;

        Modular(long v) {
            value = (int) (v % MOD_VAL);
            if (value < 0) value += MOD_VAL;
        }

        Modular(long a, long b) {
            this.value = 0;
            this.add(a);
            this.divide(b);
        }

        Modular exp(Modular a, long k) {
            Modular res = new Modular(1);
            while (k > 0) {
                if ((k & 1) == 1) res.multiply(a);
                a.multiply(a);
                k >>= 1;
            }
            return res;
        }

        Modular inv() {
            return exp(this, MOD_VAL - 2);
        }

        Modular add(Modular o) {
            value += o.value;
            if (value >= MOD_VAL) value -= MOD_VAL;
            return this;
        }

        Modular subtract(Modular o) {
            value -= o.value;
            if (value < 0) value += MOD_VAL;
            return this;
        }

        Modular multiply(Modular o) {
            value = (int) ((long) value * o.value % MOD_VAL);
            return this;
        }

        Modular divide(Modular o) {
            return this.multiply(o.inv());
        }

        @Override
        public String toString() {
            return String.valueOf(value);
        }

        public boolean equals(Modular o) {
            return value == o.value;
        }

        public boolean notEquals(Modular o) {
            return value != o.value;
        }

        public int toInt() {
            return value;
        }
    }

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
                    dp[m] |= dp[m ^ (1 << i)] && ((reach[i] & m) == 0);
                }
            }
            if (dp[m]) {
                res = Math.max(res, Integer.bitCount(m));
            }
        }

        return res;
    }

    static int solve() {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        String s = scanner.next();
        String t = scanner.next();
        Function<Character, Integer> get = c -> c - 'a';

        List<List<Integer>> G = new ArrayList<>(C);
        List<List<Integer>> g = new ArrayList<>(C);
        for (int i = 0; i < C; i++) {
            G.add(new ArrayList<>());
            g.add(new ArrayList<>());
        }

        for (int i = 0; i < n; i++) {
            if (s.charAt(i) != t.charAt(i)) {
                int a = get.apply(s.charAt(i));
                int b = get.apply(t.charAt(i));
                G.get(a).add(b);
                G.get(b).add(a);
                g.get(a).add(b);
            }
        }

        List<Integer> cur = new ArrayList<>();
        boolean[] vis = new boolean[C];
        int res = 0;

        for (int i = 0; i < C; i++) {
            if (!vis[i]) {
                cur.clear();
                dfs(i, G, vis, cur);
                int s = dag(g, cur);
                res += 2 * cur.size() - 1 - s;
            }
        }

        return res;
    }

    static void dfs(int v, List<List<Integer>> G, boolean[] vis, List<Integer> cur) {
        vis[v] = true;
        cur.add(v);
        for (int s : G.get(v)) {
            if (!vis[s]) {
                dfs(s, G, vis, cur);
            }
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int t = scanner.nextInt();
        while (t-- > 0) {
            System.out.println(solve());
        }
    }
}

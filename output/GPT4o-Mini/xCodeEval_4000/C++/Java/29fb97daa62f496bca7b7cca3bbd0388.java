import java.util.*;
import java.util.function.Function;

public class 29fb97daa62f496bca7b7cca3bbd0388_nc {
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
            this.value += a;
            this.value /= b;
        }

        Modular exp(Modular a, long k) {
            Modular res = new Modular(1);
            while (k > 0) {
                if ((k & 1) == 1) res *= a;
                a *= a;
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
            return multiply(o.inv());
        }

        public static Modular operatorPlus(Modular a, Modular b) {
            return new Modular(a.value + b.value);
        }

        public static Modular operatorMinus(Modular a, Modular b) {
            return a.subtract(b);
        }

        public static Modular operatorMultiply(Modular a, Modular b) {
            return a.multiply(b);
        }

        public static Modular operatorDivide(Modular a, Modular b) {
            return a.divide(b);
        }

        @Override
        public String toString() {
            return String.valueOf(value);
        }

        public static void main(String[] args) {
            Scanner scanner = new Scanner(System.in);
            int t = scanner.nextInt();
            while (t-- > 0) {
                System.out.println(solve(scanner));
            }
        }

        static int dag(List<List<Integer>> g, List<Integer> cur) {
            int n = cur.size();
            boolean[] dp = new boolean[1 << n];
            int[] reach = new int[n];

            for (int i = 0; i < n; i++) {
                for (int s : g.get(cur.get(i))) {
                    reach[i] |= 1 << get(cur, s);
                }
            }

            int res = 0;
            dp[0] = true;
            for (int m = 1; m < (1 << n); m++) {
                for (int i = 0; i < n; i++) {
                    if ((m & (1 << i)) != 0) {
                        dp[m] |= dp[m ^ (1 << i)] && (reach[i] & m) == 0;
                    }
                }
                if (dp[m]) {
                    res = Math.max(res, Integer.bitCount(m));
                }
            }
            return res;
        }

        static int solve(Scanner scanner) {
            int n = scanner.nextInt();
            String s = scanner.next();
            String t = scanner.next();
            List<List<Integer>> G = new ArrayList<>(C);
            List<List<Integer>> g = new ArrayList<>(C);
            for (int i = 0; i < C; i++) {
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
            boolean[] vis = new boolean[C];
            int res = 0;

            for (int i = 0; i < C; i++) {
                if (!vis[i]) {
                    cur.clear();
                    dfs(G, vis, cur, i);
                    int s = dag(g, cur);
                    res += 2 * cur.size() - 1 - s;
                }
            }
            return res;
        }

        static void dfs(List<List<Integer>> G, boolean[] vis, List<Integer> cur, int v) {
            vis[v] = true;
            cur.add(v);
            for (int s : G.get(v)) {
                if (!vis[s]) {
                    dfs(G, vis, cur, s);
                }
            }
        }

        static int get(List<Integer> cur, int v) {
            return cur.indexOf(v);
        }
    }
}

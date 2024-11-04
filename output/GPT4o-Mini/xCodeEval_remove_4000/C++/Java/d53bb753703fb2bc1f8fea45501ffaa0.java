import java.util.*;
import java.io.*;

class Modular {
    int value;
    static final int MOD_VAL = 7;

    Modular(long v) {
        value = (int) (v % MOD_VAL);
        if (value < 0) value += MOD_VAL;
    }

    Modular(long a, long b) {
        this(0);
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

    public int toInt() {
        return value;
    }

    public boolean equals(Modular o) {
        return value == o.value;
    }

    public boolean notEquals(Modular o) {
        return value != o.value;
    }

    @Override
    public String toString() {
        return String.valueOf(value);
    }
}

public class d53bb753703fb2bc1f8fea45501ffaa0xcodeeval_processed_4000.json {
    static final int INF = (int) 1e9;
    static final long LINF = (long) 1e18;
    static final long M = (long) 1e9 + 7;
    static final int C = 20;
    static List<Integer>[] G = new ArrayList[C];
    static List<Integer> cur = new ArrayList<>();
    static int[] masks = new int[C];
    static boolean[] dp = new boolean[1 << C];
    static boolean[] vis = new boolean[C];
    static int mask;

    static {
        for (int i = 0; i < C; i++) {
            G[i] = new ArrayList<>();
        }
    }

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
        for (int m = 0; m < (1 << C); m++) {
            if ((m & mask) == m) {
                sub.add(m);
            }
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

        for (int i = 0; i < n; i++) {
            if (s.charAt(i) != t.charAt(i)) {
                int a = s.charAt(i) - 'a';
                int b = t.charAt(i) - 'a';
                G[a].add(b);
                G[b].add(a);
                masks[a] |= 1 << b;
            }
        }

        int res = 0;
        dp[0] = true;
        for (int i = 0; i < C; i++) {
            if (!vis[i]) {
                mask = 0;
                cur.clear();
                dfs(i);
                int tmp = count();
                res += 2 * cur.size() - 1 - tmp;
            }
        }

        Arrays.fill(vis, false);
        Arrays.fill(masks, 0);
        Arrays.fill(dp, false);
        for (int i = 0; i < C; i++) G[i].clear();

        return res;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int t = scanner.nextInt();
        while (t-- > 0) {
            System.out.println(solve());
        }
    }
}

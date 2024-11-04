import java.util.*;
import java.io.*;

class Main {
    static final int INF = 1_000_000_000;
    static final long LINF = 1_000_000_000_000_000_000L;
    static final int M = 1_000_000_007;
    static final int C = 20;
    static List<Integer>[] G = new ArrayList[C];
    static int[] masks = new int[C];
    static boolean[] dp = new boolean[1 << C];
    static boolean[] vis = new boolean[C];
    static int mask;
    static List<Integer> cur = new ArrayList<>();

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
        for (int m = mask; m != 0; m = (m - 1) & (mask)) {
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
                res = Math.max(res, Integer.bitCount(m));
            }
        }
        return res;
    }

    static int solve() {
        int n = si();
        String s = scanf_t();
        String t = scanf_t();

        int[] G = new int[26];
        int[] masks = new int[26];
        for (int i = 0; i < n; i++) {
            if (s.charAt(i) != t.charAt(i)) {
                int a = s.charAt(i) - 'a';
                int b = t.charAt(i) - 'a';
                G[a] |= 1 << b;
                G[b] |= 1 << a;
                masks[a] |= 1 << b;
            }
        }

        int res = 0;
        dp[0] = true;
        for (int i = 0; i < 26; i++) {
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
        for (int i = 0; i < 26; i++) {
            G[i] = new ArrayList<>();
        }

        return res;
    }

    public static void main(String[] args) {
        int t = si();
        while (t-- > 0) {
            print(solve());
        }
    }

    static int si() {
        return in.nextInt();
    }

    static String scanf_t() {
        return in.next();
    }

    static void print(Object... args) {
        for (Object obj : args) {
            out.print(obj);
        }
        out.println();
    }

    static Scanner in = new Scanner(System.in);
    static PrintWriter out = new PrintWriter(System.out);
}

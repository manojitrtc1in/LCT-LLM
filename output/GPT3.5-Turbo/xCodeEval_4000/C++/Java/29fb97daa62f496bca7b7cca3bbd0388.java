import java.util.*;
import java.io.*;

class Main {
    static final int INF = 1_000_000_000;
    static final long LINF = 1_000_000_000_000_000_000L;
    static final int M = 1_000_000_007;
    static final int C = 20;

    static int dag(List<List<Integer>> g, List<Integer> cur) {
        int n = cur.size();
        int[] dp = new int[1 << n];
        int[] reach = new int[n];

        for (int i = 0; i < n; i++) {
            for (int s : g.get(cur.get(i))) {
                reach[i] |= 1 << cur.indexOf(s);
            }
        }

        int res = 0;
        dp[0] = 1;
        for (int m = 1; m < (1 << n); m++) {
            for (int i = 0; i < n; i++) {
                if ((m & (1 << i)) != 0) {
                    dp[m] |= dp[m ^ (1 << i)] & ((reach[i] & m) == 0 ? 1 : 0);
                }
            }
            if (dp[m] == 1) {
                res = Math.max(res, Integer.bitCount(m));
            }
        }

        return res;
    }

    static int solve() {
        int n = si();
        String s = ss(n);
        String t = ss(n);

        List<List<Integer>> G = new ArrayList<>();
        List<List<Integer>> g = new ArrayList<>();
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

        int res = 0;
        boolean[] vis = new boolean[C];
        for (int i = 0; i < C; i++) {
            if (!vis[i]) {
                List<Integer> cur = new ArrayList<>();
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

    static int si() {
        return sc.nextInt();
    }

    static long sl() {
        return sc.nextLong();
    }

    static double sdb() {
        return sc.nextDouble();
    }

    static String ss() {
        return sc.next();
    }

    static String ss(int n) {
        return sc.nextLine();
    }

    static PrintWriter out = new PrintWriter(System.out);
    static Scanner sc = new Scanner(System.in);

    public static void main(String[] args) {
        int t = si();
        while (t-- > 0) {
            print(solve());
        }
        out.flush();
    }

    static void print(Object... args) {
        for (Object obj : args) {
            out.print(obj);
            out.print(" ");
        }
        out.println();
    }
}

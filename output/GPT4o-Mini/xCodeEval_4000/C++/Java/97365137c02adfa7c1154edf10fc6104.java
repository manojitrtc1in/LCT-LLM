import java.util.*;
import java.util.stream.*;

class Main {
    static final int INF = (int) 1e9;
    static final long LINF = (long) 1e18;
    static final long M = (long) 1e9 + 7;
    static final int C = 20;
    static List<Integer>[] G = new ArrayList[C];
    static List<Integer> cur = new ArrayList<>();
    static int[] masks = new int[C];
    static boolean[] dp = new boolean[1 << C], vis = new boolean[C];
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
        for (int i = 0; i < C; i++) {
            G[i].clear();
        }

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

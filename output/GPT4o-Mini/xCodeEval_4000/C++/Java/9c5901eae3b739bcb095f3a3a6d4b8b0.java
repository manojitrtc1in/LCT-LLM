import java.util.*;

public class 9c5901eae3b739bcb095f3a3a6d4b8b0_nc {
    static final int INF = (int) 1e9;
    static final long INF64 = (long) 1e18;
    static final int MOD = 998244353;
    static final double EPS = 1e-9;
    static final double PI = Math.acos(-1.0);
    static final int N = 300 * 1000 + 13;

    static int n;
    static List<Integer>[] g = new ArrayList[N];
    static int[][] dp = new int[N][3];

    static {
        for (int i = 0; i < N; i++) {
            g[i] = new ArrayList<>();
        }
    }

    static boolean read() {
        Scanner scanner = new Scanner(System.in);
        if (!scanner.hasNextInt()) return false;
        n = scanner.nextInt();
        for (int i = 0; i < n; i++) g[i].clear();
        for (int i = 0; i < n - 1; i++) {
            int v = scanner.nextInt() - 1;
            int u = scanner.nextInt() - 1;
            g[v].add(u);
            g[u].add(v);
        }
        return true;
    }

    static int add(int a, int b) {
        a += b;
        if (a >= MOD) a -= MOD;
        if (a < 0) a += MOD;
        return a;
    }

    static long mul(int a, int b) {
        return (long) a * b % MOD;
    }

    static void dfs(int v, int p) {
        dp[v][0] = 1;
        dp[v][1] = 1;
        List<Integer> vals = new ArrayList<>();
        List<Integer> init = new ArrayList<>();
        for (int u : g[v]) {
            if (u != p) {
                dfs(u, v);
                vals.add(add(dp[u][1], add(dp[u][2], dp[u][2])));
                init.add(add(dp[u][0], dp[u][1]));
                dp[v][0] = (int) mul(dp[v][0], add(dp[u][1], add(dp[u][2], dp[u][2])));
                dp[v][1] = (int) mul(dp[v][1], add(dp[u][1], dp[u][2]));
            }
        }
        dp[v][0] = add(dp[v][0], -dp[v][1]);

        List<Long> pr = new ArrayList<>();
        pr.add(1L);
        List<Long> su = new ArrayList<>();
        su.add(1L);
        for (int it : vals) pr.add(mul(pr.get(pr.size() - 1).intValue(), it));
        Collections.reverse(vals);
        for (int it : vals) su.add(mul(su.get(su.size() - 1).intValue(), it));
        Collections.reverse(vals);
        Collections.reverse(su);

        dp[v][2] = 0;
        for (int i = 0; i < vals.size(); i++) {
            dp[v][2] = add(dp[v][2], (int) mul(init.get(i), mul(pr.get(i).intValue(), su.get(i + 1).intValue())));
        }
    }

    static void solve() {
        dfs(0, -1);
        System.out.println(add(dp[0][1], dp[0][2]));
    }

    public static void main(String[] args) {
        while (read()) {
            solve();
        }
    }
}

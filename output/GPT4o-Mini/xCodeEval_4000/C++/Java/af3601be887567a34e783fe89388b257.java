import java.util.*;

public class af3601be887567a34e783fe89388b257_nc {
    static final int N = 3000 + 7;
    static int n, k;
    static int[] a = new int[N], b = new int[N];
    static List<Integer>[] g = new ArrayList[N];
    static Pair<Integer, Long>[][] dp = new Pair[N][N];
    static long[] val = new long[N];
    static int[] siz = new int[N];

    static {
        for (int i = 0; i < N; i++) {
            g[i] = new ArrayList<>();
            for (int j = 0; j < N; j++) {
                dp[i][j] = new Pair<>(Integer.MIN_VALUE, Long.MIN_VALUE);
            }
        }
    }

    static boolean read(Scanner scanner) {
        if (!scanner.hasNextInt()) return false;
        n = scanner.nextInt();
        k = scanner.nextInt();
        for (int i = 0; i < n; i++) g[i].clear();
        for (int i = 0; i < n; i++) a[i] = scanner.nextInt();
        for (int i = 0; i < n; i++) b[i] = scanner.nextInt();
        for (int i = 0; i < n - 1; i++) {
            int v = scanner.nextInt() - 1;
            int u = scanner.nextInt() - 1;
            g[v].add(u);
            g[u].add(v);
        }
        return true;
    }

    static void dfs(int v, int p) {
        val[v] = b[v] - a[v];
        dp[v][0] = new Pair<>(0, val[v]);
        siz[v] = 1;

        for (int u : g[v]) {
            if (u != p) {
                dfs(u, v);
                Pair<Integer, Long>[] tmp = new Pair[siz[v] + siz[u]];
                Arrays.fill(tmp, new Pair<>(Integer.MIN_VALUE, Long.MIN_VALUE));
                for (int i = 0; i < siz[v]; i++) {
                    for (int j = 0; j <= siz[u]; j++) {
                        Pair<Integer, Long> nw = new Pair<>(dp[v][i].first + dp[u][j].first, dp[v][i].second + dp[u][j].second);
                        tmp[i + j] = max(tmp[i + j], nw);
                    }
                }
                for (int i = 0; i < tmp.length; i++) {
                    dp[v][i] = tmp[i];
                }
                siz[v] += siz[u];
                val[v] += val[u];
            }
        }

        for (int i = siz[v] - 1; i >= 0; i--) {
            dp[v][i + 1] = max(dp[v][i + 1], new Pair<>(dp[v][i].first + (dp[v][i].second > 0 ? 1 : 0), 0L));
        }
    }

    static void solve() {
        dfs(0, -1);
        System.out.println(dp[0][k - 1].first + (dp[0][k - 1].second > 0 ? 1 : 0));
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int tc = scanner.nextInt();
        while (tc-- > 0) {
            if (!read(scanner)) break;
            solve();
        }
        scanner.close();
    }

    static Pair<Integer, Long> max(Pair<Integer, Long> a, Pair<Integer, Long> b) {
        if (a.first > b.first) return a;
        if (a.first < b.first) return b;
        return a.second > b.second ? a : b;
    }

    static class Pair<F, S> {
        F first;
        S second;

        Pair(F first, S second) {
            this.first = first;
            this.second = second;
        }
    }
}

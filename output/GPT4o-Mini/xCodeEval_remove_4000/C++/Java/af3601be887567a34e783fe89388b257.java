import java.util.*;
import java.io.*;

public class af3601be887567a34e783fe89388b257xcodeeval_processed_4000.json {
    static final int INF = (int) 1e9;
    static final long INF64 = (long) 1e18;
    static final int N = 3000 + 7;

    static int n, k;
    static int[] a = new int[N];
    static int[] b = new int[N];
    static List<Integer>[] g = new ArrayList[N];
    static Pair<Integer, Long>[][] dp = new Pair[N][N];
    static long[] val = new long[N];
    static int[] siz = new int[N];

    static {
        for (int i = 0; i < N; i++) {
            g[i] = new ArrayList<>();
            for (int j = 0; j < N; j++) {
                dp[i][j] = new Pair<>(-INF, -INF64);
            }
        }
    }

    static class Pair<X, Y> {
        X x;
        Y y;

        Pair(X x, Y y) {
            this.x = x;
            this.y = y;
        }
    }

    static boolean read() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        k = Integer.parseInt(st.nextToken());

        for (int i = 0; i < n; i++) {
            g[i].clear();
        }

        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++) {
            a[i] = Integer.parseInt(st.nextToken());
        }

        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++) {
            b[i] = Integer.parseInt(st.nextToken());
        }

        for (int i = 0; i < n - 1; i++) {
            st = new StringTokenizer(br.readLine());
            int v = Integer.parseInt(st.nextToken()) - 1;
            int u = Integer.parseInt(st.nextToken()) - 1;
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
                for (int i = 0; i < siz[v] + siz[u]; i++) {
                    tmp[i] = new Pair<>(-INF, -INF64);
                }

                for (int i = 0; i < siz[v]; i++) {
                    for (int j = 0; j <= siz[u]; j++) {
                        Pair<Integer, Long> nw = new Pair<>(dp[v][i].x + dp[u][j].x, dp[v][i].y + dp[u][j].y);
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
            dp[v][i + 1] = max(dp[v][i + 1], new Pair<>(dp[v][i].x + (dp[v][i].y > 0 ? 1 : 0), 0L));
        }
    }

    static Pair<Integer, Long> max(Pair<Integer, Long> a, Pair<Integer, Long> b) {
        if (a.x > b.x) return a;
        if (a.x < b.x) return b;
        return a.y > b.y ? a : b;
    }

    static void solve() {
        dfs(0, -1);
        System.out.println(dp[0][k - 1].x + (dp[0][k - 1].y > 0 ? 1 : 0));
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int tc = Integer.parseInt(br.readLine());
        while (tc-- > 0) {
            read();
            solve();
        }
    }
}

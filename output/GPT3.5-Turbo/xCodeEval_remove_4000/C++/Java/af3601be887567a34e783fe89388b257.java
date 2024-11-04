import java.util.*;
import java.io.*;

class Main {
    static final int N = 3000 + 7;
    static int n, k;
    static int[] a = new int[N];
    static int[] b = new int[N];
    static List<Integer>[] g = new ArrayList[N];
    static Pair<Integer, Long>[][] dp = new Pair[N][N];
    static long[] val = new long[N];
    static int[] siz = new int[N];

    static class Pair<A, B> {
        A x;
        B y;

        Pair(A x, B y) {
            this.x = x;
            this.y = y;
        }
    }

    static Pair<Integer, Long> mp(int x, long y) {
        return new Pair<>(x, y);
    }

    static Pair<Integer, Long> max(Pair<Integer, Long> a, Pair<Integer, Long> b) {
        if (a.x > b.x || (a.x == b.x && a.y > b.y)) {
            return a;
        }
        return b;
    }

    static void dfs(int v, int p) {
        val[v] = b[v] - a[v];
        for (int i = 0; i < n + 1; i++) {
            dp[v][i] = mp(-INF, -INF64);
        }
        dp[v][0] = mp(0, val[v]);
        siz[v] = 1;
        for (int u : g[v]) {
            if (u != p) {
                dfs(u, v);
                List<Pair<Integer, Long>> tmp = new ArrayList<>(siz[v] + siz[u]);
                for (int i = 0; i < siz[v]; i++) {
                    for (int j = 0; j < siz[u] + 1; j++) {
                        Pair<Integer, Long> nw = mp(dp[v][i].x + dp[u][j].x, dp[v][i].y + dp[u][j].y);
                        tmp.set(i + j, max(tmp.get(i + j), nw));
                    }
                }
                for (int i = 0; i < tmp.size(); i++) {
                    dp[v][i] = tmp.get(i);
                }
                siz[v] += siz[u];
                val[v] += val[u];
            }
        }
        for (int i = siz[v] - 1; i >= 0; --i) {
            dp[v][i + 1] = max(dp[v][i + 1], mp(dp[v][i].x + (dp[v][i].y > 0 ? 1 : 0), 0L));
        }
    }

    static void solve() {
        dfs(0, -1);
        System.out.println(dp[0][k - 1].x + (dp[0][k - 1].y > 0 ? 1 : 0));
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int tc = Integer.parseInt(br.readLine());
        while (tc-- > 0) {
            String[] nk = br.readLine().split(" ");
            n = Integer.parseInt(nk[0]);
            k = Integer.parseInt(nk[1]);
            for (int i = 0; i < n; i++) {
                g[i] = new ArrayList<>();
            }
            String[] aStr = br.readLine().split(" ");
            for (int i = 0; i < n; i++) {
                a[i] = Integer.parseInt(aStr[i]);
            }
            String[] bStr = br.readLine().split(" ");
            for (int i = 0; i < n; i++) {
                b[i] = Integer.parseInt(bStr[i]);
            }
            for (int i = 0; i < n - 1; i++) {
                String[] vu = br.readLine().split(" ");
                int v = Integer.parseInt(vu[0]) - 1;
                int u = Integer.parseInt(vu[1]) - 1;
                g[v].add(u);
                g[u].add(v);
            }
            solve();
        }
    }
}

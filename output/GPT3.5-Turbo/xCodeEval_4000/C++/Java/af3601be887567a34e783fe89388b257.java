import java.util.*;
import java.io.*;

class Main {
    static final int INF = (int) 1e9;
    static final long INF64 = (long) 1e18;
    static final int MOD = INF + 7;
    static final double EPS = 1e-9;
    static final double PI = Math.acos(-1.0);

    static final int N = 3000 + 7;

    static int n, k;
    static int[] a = new int[N];
    static int[] b = new int[N];
    static List<Integer>[] g = new ArrayList[N];

    static boolean read() {
        Scanner sc = new Scanner(System.in);
        if (!sc.hasNextInt()) {
            return false;
        }
        n = sc.nextInt();
        k = sc.nextInt();
        for (int i = 0; i < n; i++) {
            g[i] = new ArrayList<>();
        }
        for (int i = 0; i < n; i++) {
            a[i] = sc.nextInt();
        }
        for (int i = 0; i < n; i++) {
            b[i] = sc.nextInt();
        }
        for (int i = 0; i < n - 1; i++) {
            int v = sc.nextInt();
            int u = sc.nextInt();
            --v;
            --u;
            g[v].add(u);
            g[u].add(v);
        }
        return true;
    }

    static class Pair<A, B> {
        A x;
        B y;

        Pair(A x, B y) {
            this.x = x;
            this.y = y;
        }

        @Override
        public String toString() {
            return "(" + x + ", " + y + ")";
        }
    }

    static <A, B> void printPair(Pair<A, B> p) {
        System.out.print(p);
    }

    static <A> void printArray(List<A> arr) {
        System.out.print("[");
        for (int i = 0; i < arr.size(); i++) {
            if (i != 0) {
                System.out.print(", ");
            }
            System.out.print(arr.get(i));
        }
        System.out.print("]");
    }

    static Random rnd = new Random();

    static Pair<Integer, Long>[][] dp = new Pair[N][N];
    static long[] val = new long[N];
    static int[] siz = new int[N];

    static void dfs(int v, int p) {
        val[v] = b[v] - a[v];
        for (int i = 0; i < n + 1; i++) {
            dp[v][i] = new Pair<Integer, Long>(-INF, -INF64);
        }
        dp[v][0] = new Pair<Integer, Long>(0, val[v]);
        siz[v] = 1;
        for (int u : g[v]) {
            if (u != p) {
                dfs(u, v);
                List<Pair<Integer, Long>> tmp = new ArrayList<>(siz[v] + siz[u]);
                for (int i = 0; i < siz[v]; i++) {
                    for (int j = 0; j < siz[u] + 1; j++) {
                        Pair<Integer, Long> nw = new Pair<Integer, Long>(dp[v][i].x + dp[u][j].x, dp[v][i].y + dp[u][j].y);
                        if (tmp.size() <= i + j) {
                            tmp.add(nw);
                        } else {
                            tmp.set(i + j, max(tmp.get(i + j), nw));
                        }
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
            dp[v][i + 1] = max(dp[v][i + 1], new Pair<Integer, Long>(dp[v][i].x + (dp[v][i].y > 0 ? 1 : 0), 0L));
        }
    }

    static void solve() {
        dfs(0);
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

    static <A, B> Pair<A, B> max(Pair<A, B> a, Pair<A, B> b) {
        if (a.x.equals(b.x)) {
            return a.y.compareTo(b.y) > 0 ? a : b;
        }
        return a.x.compareTo(b.x) > 0 ? a : b;
    }
}

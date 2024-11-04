import java.util.*;

class Main {
    static class Edge {
        int v;
        Edge next;
    }

    static final int N = 3005;
    static final int INF = (int) -3e18;

    static Edge[] pool = new Edge[3 * N];
    static Edge[] h = new Edge[N];
    static int top;
    static int n, m;
    static int[] a = new int[N];
    static int[] size = new int[N];
    static long[][] f = new long[N][N];
    static long[] tmp_f = new long[N];
    static long[] nil = new long[] {0, INF};

    static void addedge(int u, int v) {
        Edge tmp = pool[++top];
        tmp.v = v;
        tmp.next = h[u];
        h[u] = tmp;
    }

    static long[] add(long[] x, long[] y) {
        return new long[] {x[0] + y[0], x[1] + y[1]};
    }

    static void dfs(int u, int pre) {
        size[u] = 1;
        f[u][1] = new long[] {0, 1L * a[u]};
        for (Edge tmp = h[u]; tmp != null; tmp = tmp.next) {
            int v = tmp.v;
            if (v == pre) continue;
            dfs(v, u);
            System.arraycopy(f[u], 1, tmp_f, 1, size[u]);
            Arrays.fill(f[u], 1, size[u] + 1, INF);
            for (int i = 1; i <= size[u]; i++) {
                for (int j = 1; j <= size[v]; j++) {
                    if (i + j - 1 > m) break;
                    f[u][i + j] = max(f[u][i + j], add(add(tmp_f[i], f[v][j]), new long[] {f[v][j][1] > 0 ? 1 : 0, -f[v][j][1]}));
                    f[u][i + j - 1] = max(f[u][i + j - 1], add(tmp_f[i], f[v][j]));
                }
            }
            size[u] += size[v];
        }
    }

    static long[] max(long[] a, long[] b) {
        if (a[0] > b[0] || (a[0] == b[0] && a[1] > b[1])) {
            return a;
        }
        return b;
    }

    static void init() {
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        m = sc.nextInt();
        for (int i = 1; i <= n; i++) {
            a[i] = sc.nextInt();
        }
        for (int i = 1; i <= n; i++) {
            int x = sc.nextInt();
            a[i] = x - a[i];
        }
        for (int i = 1; i < n; i++) {
            int x = sc.nextInt();
            int y = sc.nextInt();
            addedge(x, y);
            addedge(y, x);
        }
        for (int i = 1; i <= n + 1; i++) {
            Arrays.fill(f[i], nil[1]);
        }
        dfs(1, 0);
        System.out.println(f[1][m][0] + (f[1][m][1] > 0 ? 1 : 0));
        top = -1;
        Arrays.fill(h, null);
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int T = sc.nextInt();
        for (int i = 1; i <= T; i++) {
            init();
        }
    }
}

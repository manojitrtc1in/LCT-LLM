import java.util.*;

class Main {
    static final int N = 3005;

    static class Edge {
        int v;
        Edge next;

        Edge(int v, Edge next) {
            this.v = v;
            this.next = next;
        }
    }

    static Edge[] h = new Edge[N];
    static int n, m, top;
    static int[] a = new int[N], size = new int[N];
    static Pair[][] f = new Pair[N][N];
    static Pair[] tmp_f = new Pair[N];
    static Pair nil = new Pair(0, Long.MIN_VALUE);

    static class Pair {
        int first;
        long second;

        Pair(int first, long second) {
            this.first = first;
            this.second = second;
        }
    }

    static void addedge(int u, int v) {
        Edge tmp = new Edge(v, h[u]);
        h[u] = tmp;
    }

    static Pair add(Pair x, Pair y) {
        return new Pair(x.first + y.first, x.second + y.second);
    }

    static void dfs(int u, int pre) {
        size[u] = 1;
        f[u][1] = new Pair(0, 1L * a[u]);
        for (Edge tmp = h[u]; tmp != null; tmp = tmp.next) {
            int v = tmp.v;
            if (v == pre) continue;
            dfs(v, u);
            for (int i = 1; i <= size[u]; i++) tmp_f[i] = f[u][i];
            for (int i = 1; i <= size[u]; i++) {
                for (int j = 1; j <= size[v]; j++) {
                    if (i + j - 1 > m) break;
                    f[u][i + j] = max(f[u][i + j], add(add(tmp_f[i], f[v][j]), new Pair(f[v][j].second > 0 ? 1 : 0, -f[v][j].second)));
                    f[u][i + j - 1] = max(f[u][i + j - 1], add(tmp_f[i], f[v][j]));
                }
            }
            size[u] += size[v];
        }
    }

    static Pair max(Pair a, Pair b) {
        if (a.first > b.first || (a.first == b.first && a.second > b.second)) {
            return a;
        }
        return b;
    }

    static void init() {
        Scanner sc = new Scanner(System.in);
        int x, y;
        n = sc.nextInt();
        m = sc.nextInt();
        for (int i = 1; i <= n; i++) {
            a[i] = sc.nextInt();
        }
        for (int i = 1; i <= n; i++) {
            x = sc.nextInt();
            a[i] = x - a[i];
        }
        for (int i = 1; i < n; i++) {
            x = sc.nextInt();
            y = sc.nextInt();
            addedge(x, y);
            addedge(y, x);
        }
        for (int i = 1; i <= n + 1; i++) {
            for (int j = 1; j <= m + 1; j++) {
                f[i][j] = nil;
            }
        }
        dfs(1, 0);
        System.out.println(f[1][m].first + (f[1][m].second > 0 ? 1 : 0));
        top = -1;
        for (int i = 1; i <= n + 1; i++) {
            h[i] = null;
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int T = sc.nextInt();
        for (int i = 1; i <= T; i++) {
            init();
        }
    }
}

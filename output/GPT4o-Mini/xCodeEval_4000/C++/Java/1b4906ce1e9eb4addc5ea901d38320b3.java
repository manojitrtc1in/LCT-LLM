import java.util.*;

class Main {
    static final int N = 3005;
    static final long nilValue = Long.MIN_VALUE;
    static int top;
    static int[] a = new int[N];
    static int[] size = new int[N];
    static Pair[][] f = new Pair[N][N];
    static Pair[] tmp_f = new Pair[N];
    static Edge[] pool = new Edge[3 * N];
    static Edge[] h = new Edge[N];

    static class Edge {
        int v;
        Edge next;
    }

    static class Pair {
        int first;
        long second;

        Pair(int first, long second) {
            this.first = first;
            this.second = second;
        }

        Pair add(Pair other) {
            return new Pair(this.first + other.first, this.second + other.second);
        }

        static Pair nil() {
            return new Pair(0, nilValue);
        }
    }

    static void addedge(int u, int v) {
        Edge tmp = pool[++top];
        tmp.v = v;
        tmp.next = h[u];
        h[u] = tmp;
    }

    static void dfs(int u, int pre) {
        size[u] = 1;
        f[u][1] = new Pair(0, a[u]);
        for (Edge tmp = h[u]; tmp != null; tmp = tmp.next) {
            int v = tmp.v;
            if (v == pre) continue;
            dfs(v, u);
            System.arraycopy(f[u], 1, tmp_f, 1, size[u]);
            Arrays.fill(f[u], 1, size[u] + 1, Pair.nil());
            for (int i = 1; i <= size[u]; i++) {
                for (int j = 1; j <= size[v]; j++) {
                    if (i + j - 1 > m) break;
                    f[u][i + j] = max(f[u][i + j], tmp_f[i].add(f[v][j]).add(new Pair(f[v][j].second > 0 ? 1 : 0, -f[v][j].second)));
                    f[u][i + j - 1] = max(f[u][i + j - 1], tmp_f[i].add(f[v][j]));
                }
            }
            size[u] += size[v];
        }
    }

    static Pair max(Pair x, Pair y) {
        if (x.second > y.second) return x;
        if (x.second < y.second) return y;
        return x.first > y.first ? x : y;
    }

    static void init() {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int m = scanner.nextInt();
        for (int i = 1; i <= n; i++) {
            a[i] = scanner.nextInt();
        }
        for (int i = 1; i <= n; i++) {
            int x = scanner.nextInt();
            a[i] = x - a[i];
        }
        for (int i = 1; i < n; i++) {
            int x = scanner.nextInt();
            int y = scanner.nextInt();
            addedge(x, y);
            addedge(y, x);
        }
        for (int i = 1; i <= n + 1; i++) {
            Arrays.fill(f[i], Pair.nil());
        }
        dfs(1, 0);
        System.out.println(f[1][m].first + (f[1][m].second > 0 ? 1 : 0));
        top = -1;
        Arrays.fill(h, null);
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int T = scanner.nextInt();
        for (int i = 1; i <= T; i++) {
            init();
        }
    }
}

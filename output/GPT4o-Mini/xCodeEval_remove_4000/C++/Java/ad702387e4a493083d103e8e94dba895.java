import java.util.*;

public class ad702387e4a493083d103e8e94dba895xcodeeval_processed_4000.json {
    static final int mod = (int) 1e9 + 7;
    static final int gmod = 2;
    static final int inf = 1039074182;
    static final long llinf = 1L * inf * inf;
    static int n, v, m;
    static int[] a = new int[305];
    static int[] b = new int[305];
    static List<Integer>[] edges = new ArrayList[305];
    static int[] c = new int[305];
    static boolean[] visit = new boolean[305];
    static int cnt;
    static long[] s = new long[305];
    static List<Pair> res = new ArrayList<>();
    static int[] dist = new int[305];

    static class Pair {
        int first, second;

        Pair(int first, int second) {
            this.first = first;
            this.second = second;
        }
    }

    static void dfs(int x) {
        visit[x] = true;
        c[x] = cnt;
        for (int u : edges[x]) {
            if (visit[u]) continue;
            dfs(u);
        }
    }

    static void bfs(int src) {
        Arrays.fill(visit, false);
        visit[src] = true;
        dist[src] = 0;
        Queue<Integer> que = new LinkedList<>();
        que.add(src);
        while (!que.isEmpty()) {
            int x = que.poll();
            for (int u : edges[x]) {
                if (visit[u]) continue;
                dist[u] = dist[x] + 1;
                visit[u] = true;
                que.add(u);
            }
        }
    }

    static void liu(int x, int y, int flow) {
        assert flow >= 0;
        a[x] -= flow;
        assert a[x] >= 0;
        a[y] += flow;
        assert a[y] <= v;
        res.add(new Pair(x, y, flow));
    }

    static void liu(int i, int flow, List<Integer> routes) {
        if (i == routes.size() - 1) return;
        int nxt = routes.get(i + 1);
        int now = routes.get(i);
        if (a[nxt] + flow <= v) {
            liu(now, nxt, flow);
            liu(i + 1, flow, routes);
        } else {
            int id2 = a[now];
            int moved = v - a[nxt];
            liu(now, nxt, v - a[nxt]);
            liu(i + 1, flow, routes);
            liu(now, nxt, flow - moved);
            int id1 = a[now];
        }
    }

    static void adjust(int x, int y) {
        assert a[x] != b[x];
        assert a[y] != b[y];

        if (a[x] < b[x]) {
            int temp = x;
            x = y;
            y = temp;
        }
        int flow = Math.min(Math.abs(a[x] - b[x]), Math.abs(a[y] - b[y]));
        bfs(x);
        List<Integer> routes = new ArrayList<>();
        routes.add(y);
        while (y != x) {
            int step = dist[y];
            int nxt = -1;
            for (int ny : edges[y]) {
                if (dist[ny] != step - 1) continue;
                nxt = ny;
                break;
            }
            y = nxt;
            routes.add(y);
        }
        Collections.reverse(routes);
        int notEq = 0;
        for (int r : routes) {
            if (a[r] != b[r]) notEq++;
        }
        liu(0, flow, routes);
        for (int r : routes) {
            if (a[r] != b[r]) notEq--;
        }
        assert notEq >= 1;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        n = scanner.nextInt();
        v = scanner.nextInt();
        m = scanner.nextInt();
        for (int i = 0; i < n; i++) {
            a[i] = scanner.nextInt();
        }
        for (int i = 0; i < n; i++) {
            b[i] = scanner.nextInt();
        }
        for (int i = 0; i < m; i++) {
            int x = scanner.nextInt() - 1;
            int y = scanner.nextInt() - 1;
            if (edges[x] == null) edges[x] = new ArrayList<>();
            if (edges[y] == null) edges[y] = new ArrayList<>();
            edges[x].add(y);
            edges[y].add(x);
        }
        for (int i = 0; i < n; i++) {
            if (visit[i]) continue;
            dfs(i);
            cnt++;
        }
        for (int i = 0; i < n; i++) {
            s[c[i]] += a[i];
            s[c[i]] -= b[i];
        }
        for (int i = 0; i < n; i++) {
            if (s[i] != 0) {
                System.out.println("NO");
                return;
            }
        }
        for (int i = 0; i < n; i++) {
            if (a[i] == b[i]) continue;
            for (int j = i + 1; j < n; j++) {
                if (c[i] != c[j]) continue;
                if (a[j] == b[j]) continue;
                if (a[i] < b[i] && a[j] < b[j]) continue;
                if (a[i] > b[i] && a[j] > b[j]) continue;

                adjust(i, j);
                break;
            }
            if (a[i] != b[i]) i--;
        }
        System.out.println(res.size());
        for (Pair e : res) {
            System.out.printf("%d %d %d\n", e.first + 1, e.second + 1, e.flow);
        }
    }
}

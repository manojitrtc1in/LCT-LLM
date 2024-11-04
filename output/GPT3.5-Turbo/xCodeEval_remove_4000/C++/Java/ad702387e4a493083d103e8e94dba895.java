import java.util.*;
import java.io.*;

class Main {
    static final int mod = (int) 1e9 + 7;
    static final int gmod = 2;
    static final int inf = 1039074182;
    static final double eps = 1e-9;
    static final long llinf = 1L * inf * inf;

    static class Pair<T1, T2> {
        T1 first;
        T2 second;

        Pair(T1 first, T2 second) {
            this.first = first;
            this.second = second;
        }
    }

    static class Triple<T1, T2, T3> {
        T1 first;
        T2 second;
        T3 third;

        Triple(T1 first, T2 second, T3 third) {
            this.first = first;
            this.second = second;
            this.third = third;
        }
    }

    static class FastScanner {
        BufferedReader br;
        StringTokenizer st;

        public FastScanner() {
            br = new BufferedReader(new InputStreamReader(System.in));
        }

        String next() {
            while (st == null || !st.hasMoreElements()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }

        int nextInt() {
            return Integer.parseInt(next());
        }

        long nextLong() {
            return Long.parseLong(next());
        }

        double nextDouble() {
            return Double.parseDouble(next());
        }

        String nextLine() {
            String str = "";
            try {
                str = br.readLine();
            } catch (IOException e) {
                e.printStackTrace();
            }
            return str;
        }
    }

    static int mod(int x, int b) {
        x += b - mod;
        x += (x >> 31 & mod);
        return x;
    }

    static void chadd(int[] x, int b) {
        x[0] = mod(x[0], b);
        x[0] += (x[0] >> 31 & mod);
    }

    static void chadd(long[] x, long b) {
        x[0] = mod(x[0], b);
        x[0] += (x[0] >> 63 & b);
    }

    static void chmul(int[] x, int b) {
        x[0] = (int) (1L * x[0] * b % mod);
    }

    static void chmul(long[] x, long b) {
        x[0] = (x[0] * b % mod + mod) % mod;
    }

    static void chmod(int[] x, int b) {
        x[0] %= b;
        x[0] += b;
        if (x[0] >= b)
            x[0] -= b;
    }

    static void chmod(long[] x, long b) {
        x[0] %= b;
        x[0] += b;
        if (x[0] >= b)
            x[0] -= b;
    }

    static int mabs(int x) {
        return (x < 0 ? -x : x);
    }

    static long mabs(long x) {
        return (x < 0 ? -x : x);
    }

    public static void main(String[] args) {
        FastScanner sc = new FastScanner();
        PrintWriter out = new PrintWriter(System.out);

        int n = sc.nextInt();
        int v = sc.nextInt();
        int m = sc.nextInt();
        int[] a = new int[305];
        int[] b = new int[305];
        ArrayList<Integer>[] edges = new ArrayList[305];
        for (int i = 0; i < 305; i++) {
            edges[i] = new ArrayList<>();
        }
        int[] c = new int[305];
        int[] visit = new int[305];
        int cnt = 0;
        long[] s = new long[305];
        ArrayList<Pair<Pair<Integer, Integer>, Integer>> res = new ArrayList<>();
        int[] dist = new int[305];

        for (int i = 0; i < n; i++) {
            a[i] = sc.nextInt();
        }
        for (int i = 0; i < n; i++) {
            b[i] = sc.nextInt();
        }
        for (int i = 0; i < m; i++) {
            int x = sc.nextInt();
            int y = sc.nextInt();
            x--;
            y--;
            edges[x].add(y);
            edges[y].add(x);
        }
        for (int i = 0; i < n; i++) {
            if (visit[i] == 1)
                continue;
            dfs(i, edges, visit, c, cnt);
            cnt++;
        }
        for (int i = 0; i < n; i++) {
            s[c[i]] += a[i];
            s[c[i]] -= b[i];
        }
        for (int i = 0; i < n; i++) {
            if (s[i] != 0)
                over("NO");
        }
        int prev;
        int cur;
        for (int i = 0; i < n; i++) {
            if (a[i] == b[i])
                continue;
            for (int j = i + 1; j < n; j++) {
                if (c[i] != c[j])
                    continue;
                if (a[j] == b[j])
                    continue;
                if (a[i] < b[i] && a[j] < b[j])
                    continue;
                if (a[i] > b[i] && a[j] > b[j])
                    continue;

                adjust(i, j, a, b, edges, res, dist, v);
                break;
            }
            if (a[i] != b[i])
                i--;
        }
        out.println(res.size());
        for (Pair<Pair<Integer, Integer>, Integer> e : res) {
            out.println((e.first.first + 1) + " " + (e.first.second + 1) + " " + e.second);
        }

        out.close();
    }

    static void dfs(int x, ArrayList<Integer>[] edges, int[] visit, int[] c, int cnt) {
        visit[x] = 1;
        c[x] = cnt;
        for (int u : edges[x]) {
            if (visit[u] == 1)
                continue;
            dfs(u, edges, visit, c, cnt);
        }
    }

    static void bfs(int src, ArrayList<Integer>[] edges, int[] visit, int[] dist) {
        Arrays.fill(visit, 0);
        visit[src] = 1;
        dist[src] = 0;
        Queue<Integer> que = new LinkedList<>();
        que.add(src);
        while (!que.isEmpty()) {
            int x = que.poll();
            for (int u : edges[x]) {
                if (visit[u] == 1)
                    continue;
                dist[u] = dist[x] + 1;
                visit[u] = 1;
                que.add(u);
            }
        }
    }

    static void liu(int x, int y, int flow, int[] a, ArrayList<Pair<Pair<Integer, Integer>, Integer>> res) {
        assert (flow >= 0);
        a[x] -= flow;
        assert (a[x] >= 0);
        a[y] += flow;
        assert (a[y] <= v);
        res.add(new Pair<>(new Pair<>(x, y), flow));
    }

    static void liu(int i, int flow, ArrayList<Integer> routes, int[] a, int v,
            ArrayList<Pair<Pair<Integer, Integer>, Integer>> res) {
        if (i == routes.size() - 1)
            return;
        int nxt = routes.get(i + 1);
        int now = routes.get(i);
        if (a[nxt] + flow <= v) {
            liu(now, nxt, flow, a, res);
            liu(i + 1, flow, routes, a, v, res);
        } else {
            int id2 = a[now];
            int moved = v - a[nxt];
            liu(now, nxt, v - a[nxt], a, res);
            liu(i + 1, flow, routes, a, v, res);
            liu(now, nxt, flow - moved, a, res);
            int id1 = a[now];
        }
    }

    static void adjust(int x, int y, int[] a, int[] b, ArrayList<Integer>[] edges,
            ArrayList<Pair<Pair<Integer, Integer>, Integer>> res, int[] dist, int v) {
        assert (a[x] != b[x]);
        assert (a[y] != b[y]);

        if (a[x] < b[x])
            swap(x, y);
        int flow = Math.min(Math.abs(a[x] - b[x]), Math.abs(a[y] - b[y]));
        bfs(x, edges, new int[305], dist);
        ArrayList<Integer> routes = new ArrayList<>();
        routes.add(y);
        while (y != x) {
            int step = dist[y];
            int nxt = -1;
            for (int ny : edges[y]) {
                if (dist[ny] != step - 1)
                    continue;
                nxt = ny;
                break;
            }
            y = nxt;
            routes.add(y);
        }
        Collections.reverse(routes);
        int notEq = 0;
        for (int r : routes) {
            if (a[r] != b[r])
                notEq++;
        }
        liu(0, flow, routes, a, v, res);
        for (int r : routes) {
            if (a[r] != b[r])
                notEq--;
        }
        assert (notEq >= 1);
    }

    static void over(String s) {
        throw new IllegalArgumentException(s);
    }

    static void swap(int x, int y) {
        int temp = x;
        x = y;
        y = temp;
    }
}

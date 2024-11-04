import java.util.*;
import java.io.*;

class Main {
    static int n, v, m;
    static int[] a, b, c, visit, dist;
    static ArrayList<Integer>[] edges;
    static long[] s;
    static ArrayList<Pair<Pair<Integer, Integer>, Integer>> res;
    static int cnt;

    static void dfs(int x) {
        visit[x] = 1;
        c[x] = cnt;
        for (int u : edges[x]) {
            if (visit[u] == 1)
                continue;
            dfs(u);
        }
    }

    static void bfs(int src) {
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

    static void liu(int x, int y, int flow) {
        assert (flow >= 0);
        a[x] -= flow;
        assert (a[x] >= 0);
        a[y] += flow;
        assert (a[y] <= v);
        res.add(new Pair<>(new Pair<>(x, y), flow));
    }

    static void liu(int i, int flow, ArrayList<Integer> routes) {
        if (i == routes.size() - 1)
            return;
        int nxt = routes.get(i + 1);
        int now = routes.get(i);
        if (a[nxt] + flow <= v) {
            liu(now, nxt, flow);
            liu(i + 1, flow, routes);
        } else {
            int original_a_now = a[now];
            int moved = v - a[nxt];
            liu(now, nxt, v - a[nxt]);
            liu(i + 1, flow, routes);
            liu(now, nxt, flow - moved);
            int new_a_now = a[now];
        }
    }

    static void adjust(int x, int y) {
        assert (a[x] != b[x]);
        assert (a[y] != b[y]);
        if (a[x] < b[x])
            swap(x, y);
        int flow = Math.min(Math.abs(a[x] - b[x]), Math.abs(a[y] - b[y]));
        bfs(x);
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
        for (int i = 0; i < routes.size(); i++) {
            int x = routes.get(i);
            if (a[x] != b[x])
                notEq++;
        }
        liu(0, flow, routes);
        for (int i = 0; i < routes.size(); i++) {
            int x = routes.get(i);
            if (a[x] != b[x])
                notEq--;
        }
        assert (notEq >= 1);
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] input = br.readLine().split(" ");
        n = Integer.parseInt(input[0]);
        v = Integer.parseInt(input[1]);
        m = Integer.parseInt(input[2]);
        a = new int[n];
        b = new int[n];
        c = new int[n];
        visit = new int[n];
        dist = new int[n];
        edges = new ArrayList[n];
        s = new long[n];
        res = new ArrayList<>();
        cnt = 0;

        for (int i = 0; i < n; i++) {
            a[i] = Integer.parseInt(br.readLine());
        }
        for (int i = 0; i < n; i++) {
            b[i] = Integer.parseInt(br.readLine());
        }
        for (int i = 0; i < m; i++) {
            input = br.readLine().split(" ");
            int x = Integer.parseInt(input[0]) - 1;
            int y = Integer.parseInt(input[1]) - 1;
            if (edges[x] == null)
                edges[x] = new ArrayList<>();
            if (edges[y] == null)
                edges[y] = new ArrayList<>();
            edges[x].add(y);
            edges[y].add(x);
        }
        for (int i = 0; i < n; i++) {
            if (visit[i] == 1)
                continue;
            dfs(i);
            cnt++;
        }
        for (int i = 0; i < n; i++) {
            s[c[i]] += a[i];
            s[c[i]] -= b[i];
        }
        for (int i = 0; i < n; i++) {
            if (s[i] != 0)
                System.out.println("NO");
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
                adjust(i, j);
                break;
            }
            if (a[i] != b[i])
                i--;
        }
        System.out.println(res.size());
        for (Pair<Pair<Integer, Integer>, Integer> e : res) {
            System.out.println((e.first.first + 1) + " " + (e.first.second + 1) + " " + e.second);
        }
    }

    static class Pair<T, U> {
        T first;
        U second;

        Pair(T first, U second) {
            this.first = first;
            this.second = second;
        }
    }
}

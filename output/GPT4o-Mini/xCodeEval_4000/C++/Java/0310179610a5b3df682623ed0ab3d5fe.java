import java.util.*;

public class 0310179610a5b3df682623ed0ab3d5fe_nc {
    static final long MOD = 1000000007;
    static final long INF = 1L << 61;

    static class Edge {
        int to, rev;
        long cap;

        Edge(int _to, long _cap, int _rev) {
            to = _to;
            cap = _cap;
            rev = _rev;
        }
    }

    static class Graph {
        List<List<Edge>> edges;

        Graph(int n) {
            edges = new ArrayList<>(n);
            for (int i = 0; i < n; i++) {
                edges.add(new ArrayList<>());
            }
        }

        void addEdge(int from, int to, long cap, boolean revFlag, long revCap) {
            edges.get(from).add(new Edge(to, cap, edges.get(to).size() + (from == to ? 1 : 0)));
            if (revFlag) {
                edges.get(to).add(new Edge(from, revCap, edges.get(from).size() - 1));
            }
        }
    }

    static long maxFlowDfs(Graph G, long v, long t, long f, boolean[] used) {
        if (v == t) return f;
        used[(int) v] = true;
        for (Edge e : G.edges.get((int) v)) {
            if (!used[e.to] && e.cap > 0) {
                long d = maxFlowDfs(G, e.to, t, Math.min(f, e.cap), used);
                if (d > 0) {
                    e.cap -= d;
                    G.edges.get(e.to).get(e.rev).cap += d;
                    return d;
                }
            }
        }
        return 0;
    }

    static long maxFlow(Graph G, long s, long t) {
        long flow = 0;
        while (true) {
            boolean[] used = new boolean[G.edges.size()];
            long f = maxFlowDfs(G, s, t, INF, used);
            if (f == 0) {
                return flow;
            }
            flow += f;
        }
    }

    static void bellmanFord(Graph G, long s, long[] d, boolean[] negative) {
        Arrays.fill(d, INF);
        Arrays.fill(negative, false);
        d[(int) s] = 0;

        for (int k = 0; k < G.edges.size() - 1; k++) {
            for (int i = 0; i < G.edges.size(); i++) {
                for (Edge e : G.edges.get(i)) {
                    if (d[i] != INF && d[e.to] > d[i] + e.cap) {
                        d[e.to] = d[i] + e.cap;
                    }
                }
            }
        }

        for (int k = 0; k < G.edges.size() - 1; k++) {
            for (int i = 0; i < G.edges.size(); i++) {
                for (Edge e : G.edges.get(i)) {
                    if (d[i] != INF && d[e.to] > d[i] + e.cap) {
                        d[e.to] = d[i] + e.cap;
                        negative[e.to] = true;
                    }
                    if (negative[i]) {
                        negative[e.to] = true;
                    }
                }
            }
        }
    }

    static void dijkstra(Graph G, long s, long[] d) {
        Arrays.fill(d, INF);
        d[(int) s] = 0;
        PriorityQueue<long[]> q = new PriorityQueue<>(Comparator.comparingLong(a -> a[0]));
        q.add(new long[]{0, s});

        while (!q.isEmpty()) {
            long[] a = q.poll();
            if (d[(int) a[1]] < a[0]) continue;
            for (Edge e : G.edges.get((int) a[1])) {
                if (d[e.to] > d[(int) a[1]] + e.cap) {
                    d[e.to] = d[(int) a[1]] + e.cap;
                    q.add(new long[]{d[e.to], e.to});
                }
            }
        }
    }

    static void warshallFloyd(Graph G, long[][] d) {
        for (int i = 0; i < d.length; i++) {
            Arrays.fill(d[i], INF);
            d[i][i] = 0;
        }
        for (int i = 0; i < G.edges.size(); i++) {
            for (Edge e : G.edges.get(i)) {
                d[i][e.to] = Math.min(d[i][e.to], e.cap);
            }
        }
        for (int k = 0; k < G.edges.size(); k++) {
            for (int i = 0; i < G.edges.size(); i++) {
                for (int j = 0; j < G.edges.size(); j++) {
                    if (d[i][k] != INF && d[k][j] != INF) {
                        d[i][j] = Math.min(d[i][j], d[i][k] + d[k][j]);
                    }
                }
            }
        }
    }

    static boolean tsort(Graph graph, List<Integer> order) {
        int n = graph.edges.size();
        int[] in = new int[n];
        for (List<Edge> es : graph.edges) {
            for (Edge e : es) {
                in[e.to]++;
            }
        }
        PriorityQueue<Integer> que = new PriorityQueue<>();
        for (int i = 0; i < n; i++) {
            if (in[i] == 0) que.add(i);
        }
        while (!que.isEmpty()) {
            int v = que.poll();
            order.add(v);
            for (Edge e : graph.edges.get(v)) {
                if (--in[e.to] == 0) que.add(e.to);
            }
        }
        return order.size() == n;
    }

    static class UnionFind {
        int[] data;
        int n;

        UnionFind(int size) {
            data = new int[size];
            Arrays.fill(data, -1);
            n = size;
        }

        boolean merge(int x, int y) {
            x = root(x);
            y = root(y);
            if (x != y) {
                if (data[y] < data[x]) {
                    int temp = x;
                    x = y;
                    y = temp;
                }
                data[x] += data[y];
                data[y] = x;
            }
            n -= (x != y) ? 1 : 0;
            return x != y;
        }

        boolean same(int x, int y) {
            return root(x) == root(y);
        }

        int root(int x) {
            return data[x] < 0 ? x : (data[x] = root(data[x]));
        }

        int size(int x) {
            return -data[root(x)];
        }

        int num() {
            return n;
        }
    }

    static long extgcd(long a, long b, long[] x, long[] y) {
        if (a < b) return extgcd(b, a, y, x);
        if (b > 0) {
            long g = extgcd(b, a % b, y, x);
            y[0] -= (a / b) * x[0];
            return g;
        } else {
            x[0] = 1;
            y[0] = 0;
            return a;
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        long m = scanner.nextLong();
        long h1 = scanner.nextLong(), a1 = scanner.nextLong(), x1 = scanner.nextLong(), y1 = scanner.nextLong();
        List<Long> t = new ArrayList<>();
        boolean[] used = new boolean[(int) m];
        used[(int) h1] = true;
        t.add(h1);
        while (true) {
            long tmp = (t.get(t.size() - 1) * x1 + y1) % m;
            t.add(tmp);
            if (used[(int) tmp]) break;
            used[(int) tmp] = true;
        }
        used = new boolean[(int) m];
        long h2 = scanner.nextLong(), a2 = scanner.nextLong(), x2 = scanner.nextLong(), y2 = scanner.nextLong();
        used[(int) h2] = true;
        List<Long> s = new ArrayList<>();
        s.add(h2);
        while (true) {
            long tmp = (s.get(s.size() - 1) * x2 + y2) % m;
            s.add(tmp);
            if (used[(int) tmp]) break;
            used[(int) tmp] = true;
        }

        long l1 = -1, l2 = -1;
        long mn1 = INF, mn2 = INF;
        long now = 0;
        while (true) {
            if (t.get(t.size() - 1).equals(t.get((int) now))) {
                l1 = t.size() - now - 1;
            }
            if (t.get((int) now).equals(a1)) {
                mn1 = now;
                break;
            }
            now++;
            if (now == t.size()) break;
        }
        now = 0;
        while (true) {
            if (s.get(s.size() - 1).equals(s.get((int) now))) {
                l2 = s.size() - now - 1;
            }
            if (s.get((int) now).equals(a2)) {
                mn2 = now;
                break;
            }
            now++;
            if (now == s.size()) break;
        }

        long result = calc(mn1, mn2, l1, l2);
        System.out.println(result);
    }

    static long calc(long mn1, long mn2, long l1, long l2) {
        if (mn1 != INF && mn2 != INF) {
            if (mn1 == mn2) return mn1;
            if (mn1 > mn2 && l2 == -1) return -1;
            if (mn1 < mn2 && l1 == -1) return -1;
            if (l1 == -1) {
                if ((mn1 - mn2) % l2 == 0) return mn1;
                else return -1;
            }
            if (l2 == -1) {
                if ((mn2 - mn1) % l1 == 0) return mn2;
                else return -1;
            }
            if (l1 == l2) {
                if (Math.abs(mn1 - mn2) % l1 == 0) return Math.max(mn1, mn2);
                else return -1;
            }
            if (mn2 > mn1 && (mn2 - mn1) % l1 == 0) return mn2;
            if (mn1 > mn2 && (mn1 - mn2) % l2 == 0) return mn1;

            if (Math.abs(mn2 - mn1) % Math.abs(gcd(l1, l2)) != 0) return -1;
            long[] x = new long[1], y = new long[1];
            long g = extgcd(l1, l2, x, y);
            x[0] *= (mn2 - mn1) / g;
            y[0] *= (mn2 - mn1) / g;
            if (x[0] * l1 + mn1 < Math.max(mn1, mn2)) {
                x[0] += ((Math.max(mn1, mn2) - x[0] * l1 + mn1 + l1 - 1) / l1 + l2 / g - 1) / (l2 / g) * (l2 / g);
            }
            if (x[0] * l1 + mn1 >= Math.max(mn1, mn2)) {
                x[0] -= (x[0] * l1 + mn1 - Math.max(mn1, mn2)) / l1 / (l2 / g) * (l2 / g);
            }
            return x[0] * l1 + mn1;
        } else return -1;
    }

    static long gcd(long a, long b) {
        while (b != 0) {
            long temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }
}

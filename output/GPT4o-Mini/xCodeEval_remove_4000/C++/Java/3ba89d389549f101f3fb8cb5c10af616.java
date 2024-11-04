import java.util.*;

public class 3ba89d389549f101f3fb8cb5c10af616xcodeeval_processed_4000.json {
    static class Edge {
        long to, cap, rev;

        Edge(long _to, long _cap, long _rev) {
            to = _to;
            cap = _cap;
            rev = _rev;
        }
    }

    static class Graph {
        List<List<Edge>> adj;

        Graph(int n) {
            adj = new ArrayList<>(n);
            for (int i = 0; i < n; i++) {
                adj.add(new ArrayList<>());
            }
        }

        void addEdge(long from, long to, long cap, boolean revFlag, long revCap) {
            adj.get((int) from).add(new Edge(to, cap, adj.get((int) to).size()));
            if (revFlag) {
                adj.get((int) to).add(new Edge(from, revCap, adj.get((int) from).size() - 1));
            }
        }
    }

    static long id1(Graph G, long v, long t, long f, boolean[] used) {
        if (v == t) return f;
        used[(int) v] = true;
        for (Edge e : G.adj.get((int) v)) {
            if (!used[(int) e.to] && e.cap > 0) {
                long d = id1(G, e.to, t, Math.min(f, e.cap), used);
                if (d > 0) {
                    e.cap -= d;
                    G.adj.get((int) e.to).get((int) e.rev).cap += d;
                    return d;
                }
            }
        }
        return 0;
    }

    static long maxFlow(Graph G, long s, long t) {
        long flow = 0;
        for (;;) {
            boolean[] used = new boolean[G.adj.size()];
            long f = id1(G, s, t, Long.MAX_VALUE, used);
            if (f == 0) {
                return flow;
            }
            flow += f;
        }
    }

    static void dfs(Graph g, long v, long t, Set<Long> st, long[] used, long s) {
        used[(int) v] = 1;
        if (v != s) st.add(v);
        if (v == t) return;
        if (v != s) {
            for (Edge edge : g.adj.get((int) v)) {
                long to = edge.to;
                if (used[(int) to] == 0) dfs(g, to, t, st, used, s);
                else if (used[(int) to] == 2) st.add(t);
            }
        } else {
            for (Edge edge : g.adj.get((int) v)) {
                long to = edge.to;
                if (used[(int) to] != 0) continue;
                dfs(g, to, t, st, used, s);
                if (st.contains(t)) {
                    for (long itr : st) used[(int) itr] = 2;
                }
                st.clear();
            }
        }
    }

    static void solve() {
        Scanner sc = new Scanner(System.in);
        long n = sc.nextLong(), m = sc.nextLong(), a = sc.nextLong(), b = sc.nextLong();
        a--; b--;
        Graph g = new Graph((int) n);
        for (int i = 0; i < m; i++) {
            long u = sc.nextLong() - 1;
            long v = sc.nextLong() - 1;
            g.addEdge(u, v, 1, true, 1);
        }
        long[] used = new long[(int) n];
        Set<Long> st = new HashSet<>();
        dfs(g, a, b, st, used, a);
        long s = 0, t = 0;
        for (int i = 0; i < n; i++) {
            if (used[i] == 1) s++;
            else if (used[i] == 0) t++;
        }
        s--;
        System.out.println(s * t);
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        long t = sc.nextLong();
        for (int i = 0; i < t; i++) solve();
    }
}

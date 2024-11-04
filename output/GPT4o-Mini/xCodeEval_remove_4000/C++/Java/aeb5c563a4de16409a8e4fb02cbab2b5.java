import java.util.*;

public class aeb5c563a4de16409a8e4fb02cbab2b5xcodeeval_processed_4000.json {
    static final long MOD = 998244353;

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

    static long id0(Graph G, long v, long t, long f, boolean[] used) {
        if (v == t) return f;
        used[(int) v] = true;
        for (Edge e : G.edges.get((int) v)) {
            if (!used[e.to] && e.cap > 0) {
                long d = id0(G, e.to, t, Math.min(f, e.cap), used);
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
            long f = id0(G, s, t, Long.MAX_VALUE, used);
            if (f == 0) {
                return flow;
            }
            flow += f;
        }
    }

    static void solve(Graph G, long n, long k) {
        List<List<Long>> a = new ArrayList<>();
        long[] w = new long[(int) n];
        for (int i = 0; i < n; i++) {
            List<Long> temp = new ArrayList<>();
            Scanner scanner = new Scanner(System.in);
            long t = scanner.nextLong();
            for (int j = 0; j < t; j++) {
                long tmp = scanner.nextLong();
                if (temp.size() < k) temp.add(tmp);
            }
            a.add(temp);
            w[i] = temp.stream().mapToLong(Long::longValue).sum();
        }

        long ans = 0;
        long[] dp = new long[(int) (k + 1)];
        Arrays.fill(dp, 0);

        solveRecursively(a, dp, w, 0, n, k, ans);
        System.out.println(ans);
    }

    static void solveRecursively(List<List<Long>> a, long[] dp, long[] w, long l, long r, long k, long ans) {
        if (r - l == 1) {
            long sum = 0;
            for (int i = 0; i <= a.get((int) l).size(); i++) {
                ans = Math.max(ans, dp[(int) (k - i)] + sum);
                if (i != a.get((int) l).size()) sum += a.get((int) l).get(i);
            }
            return;
        }
        long m = (r + l) / 2;
        long[] dp2 = Arrays.copyOf(dp, dp.length);
        for (int i = (int) m; i < r; i++) {
            for (int j = (int) (k - 1); j >= 0; j--) {
                if (a.get(i).size() + j <= k) {
                    dp2[j + a.get(i).size()] = Math.max(dp2[j + a.get(i).size()], dp2[j] + w[i]);
                }
            }
        }
        solveRecursively(a, dp2, w, l, m, k, ans);
        for (int i = (int) l; i < m; i++) {
            for (int j = (int) (k - 1); j >= 0; j--) {
                if (a.get(i).size() + j <= k) {
                    dp[j + a.get(i).size()] = Math.max(dp[j + a.get(i).size()], dp[j] + w[i]);
                }
            }
        }
        solveRecursively(a, dp, w, m, r, k, ans);
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        long n = scanner.nextLong();
        long k = scanner.nextLong();
        solve(new Graph((int) n), n, k);
    }
}

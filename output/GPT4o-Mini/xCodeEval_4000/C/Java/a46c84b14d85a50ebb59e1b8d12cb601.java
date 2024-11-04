import java.util.*;

class Main {
    static final long INF = (1L << 62);
    static final long MOD1 = 1000000007;
    static final long MOD2 = 998244353;
    static final int MAX_N = (1 << 20);
    
    static class Dinic {
        int n;
        List<List<Integer>> to;
        List<List<Long>> cap;
        List<List<Integer>> rev;
        List<Integer> minCost;
        List<Integer> iter;

        Dinic(int n) {
            this.n = n;
            to = new ArrayList<>(n);
            cap = new ArrayList<>(n);
            rev = new ArrayList<>(n);
            for (int i = 0; i < n; i++) {
                to.add(new ArrayList<>());
                cap.add(new ArrayList<>());
                rev.add(new ArrayList<>());
            }
            minCost = new ArrayList<>(Collections.nCopies(n, -1));
            iter = new ArrayList<>(Collections.nCopies(n, 0));
        }

        void addEdge(int from, int to, long cap) {
            this.to.get(from).add(to);
            this.to.get(to).add(from);
            this.cap.get(from).add(cap);
            this.cap.get(to).add(0L);
            this.rev.get(from).add(this.to.get(to).size() - 1);
            this.rev.get(to).add(this.to.get(from).size() - 1);
        }

        boolean bfs(int s, int t) {
            Collections.fill(minCost, -1);
            minCost.set(s, 0);
            Queue<Integer> q = new LinkedList<>();
            q.add(s);
            while (!q.isEmpty() && minCost.get(t) == -1) {
                int p = q.poll();
                for (int i = 0; i < to.get(p).size(); i++) {
                    int toNode = to.get(p).get(i);
                    if (cap.get(p).get(i) > 0 && minCost.get(toNode) == -1) {
                        minCost.set(toNode, minCost.get(p) + 1);
                        q.add(toNode);
                    }
                }
            }
            return minCost.get(t) != -1;
        }

        long dfs(int idx, int t, long flow) {
            if (idx == t) return flow;
            for (int i = iter.get(idx); i < cap.get(idx).size(); i++) {
                iter.set(idx, i);
                long capValue = cap.get(idx).get(i);
                int toNode = to.get(idx).get(i);
                if (capValue > 0 && minCost.get(idx) < minCost.get(toNode)) {
                    long delta = dfs(toNode, t, Math.min(flow, capValue));
                    if (delta > 0) {
                        capValue -= delta;
                        cap.get(idx).set(i, capValue);
                        int revIdx = rev.get(idx).get(i);
                        long revCap = cap.get(toNode).get(revIdx) + delta;
                        cap.get(toNode).set(revIdx, revCap);
                        return delta;
                    }
                }
            }
            return 0;
        }

        long maxFlow(int s, int t) {
            long flow = 0;
            while (bfs(s)) {
                Collections.fill(iter, 0);
                long f;
                while ((f = dfs(s, t, INF)) > 0) flow += f;
            }
            return flow;
        }
    }

    static void solve() {
        Scanner scanner = new Scanner(System.in);
        long n = scanner.nextLong();
        long[] a = new long[3];
        long[] b = new long[3];
        for (int i = 0; i < 3; i++) {
            a[i] = scanner.nextLong();
        }
        for (int i = 0; i < 3; i++) {
            b[i] = scanner.nextLong();
        }
        long ma = Math.min(a[0], b[1]) + Math.min(a[1], b[2]) + Math.min(a[2], b[0]);
        Dinic d = new Dinic(8);
        d.addEdge(6, 0, a[0]);
        d.addEdge(6, 1, a[1]);
        d.addEdge(6, 2, a[2]);
        d.addEdge(0, 3, INF);
        d.addEdge(0, 5, INF);
        d.addEdge(1, 3, INF);
        d.addEdge(1, 4, INF);
        d.addEdge(2, 4, INF);
        d.addEdge(2, 5, INF);
        d.addEdge(3, 7, b[0]);
        d.addEdge(4, 7, b[1]);
        d.addEdge(5, 7, b[2]);
        System.out.printf("%d %d\n", n - d.maxFlow(6, 7), ma);
    }

    public static void main(String[] args) {
        int T = 1;
        for (int i = 0; i < T; i++) {
            solve();
        }
    }
}

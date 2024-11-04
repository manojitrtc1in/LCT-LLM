import java.util.*;

class Main {
    static class Dinic {
        int n;
        ArrayList<ArrayList<Integer>> to;
        ArrayList<ArrayList<Long>> cap;
        ArrayList<ArrayList<Integer>> rev;
        ArrayList<Integer> min_cost;
        ArrayList<Integer> iter;

        Dinic(int n) {
            this.n = n;
            to = new ArrayList<>();
            cap = new ArrayList<>();
            rev = new ArrayList<>();
            min_cost = new ArrayList<>();
            iter = new ArrayList<>();

            for (int i = 0; i < n; i++) {
                to.add(new ArrayList<>());
                cap.add(new ArrayList<>());
                rev.add(new ArrayList<>());
            }

            for (int i = 0; i < n; i++) {
                min_cost.add(-1);
                iter.add(0);
            }
        }

        void add(int from, int to, long cap) {
            rev.get(from).add(to);
            rev.get(to).add(from);
            this.to.get(from).add(to);
            this.to.get(to).add(from);
            this.cap.get(from).add(cap);
            this.cap.get(to).add(0L);
        }

        boolean bfs(int s, int t) {
            Arrays.fill(min_cost.toArray(), -1);
            Queue<Integer> q = new LinkedList<>();
            min_cost.set(s, 0);
            q.add(s);

            while (!q.isEmpty()) {
                int p = q.poll();
                for (int i = 0; i < to.get(p).size(); i++) {
                    int to = this.to.get(p).get(i);
                    long cap = this.cap.get(p).get(i);
                    if (cap > 0 && min_cost.get(to) == -1) {
                        long cost = min_cost.get(p) + 1;
                        min_cost.set(to, (int) cost);
                        q.add(to);
                    }
                }
            }

            return min_cost.get(t) != -1;
        }

        long dfs(int idx, int t, long flow) {
            if (idx == t) return flow;
            for (int i = iter.get(idx); i < cap.get(idx).size(); i++) {
                iter.set(idx, i);
                long cap = this.cap.get(idx).get(i);
                int to = this.to.get(idx).get(i);
                if (cap > 0 && min_cost.get(idx) < min_cost.get(to)) {
                    long delta = dfs(to, t, Math.min(flow, cap));
                    if (delta > 0) {
                        cap -= delta;
                        this.cap.get(idx).set(i, cap);
                        int rev = this.rev.get(idx).get(i);
                        long rev_cap = this.cap.get(to).get(rev) + delta;
                        this.cap.get(to).set(rev, rev_cap);
                        return delta;
                    }
                }
            }
            return 0;
        }

        long maxFlow(int s, int t) {
            long flow = 0;
            while (bfs(s, t)) {
                Arrays.fill(iter.toArray(), 0);
                long f = 0;
                while ((f = dfs(s, t, Long.MAX_VALUE)) > 0) {
                    flow += f;
                }
            }
            return flow;
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int T = 1;
        while (T-- > 0) {
            long n = sc.nextLong();
            long ans = 0;

            long[] a = new long[3];
            long[] b = new long[3];
            for (int i = 0; i < 3; i++) {
                a[i] = sc.nextLong();
            }
            for (int i = 0; i < 3; i++) {
                b[i] = sc.nextLong();
            }
            long ma = 0;

            ma = Math.min(a[0], b[1]) + Math.min(a[1], b[2]) + Math.min(a[2], b[0]);
            Dinic d = new Dinic(8);
            d.add(6, 0, a[0]);
            d.add(6, 1, a[1]);
            d.add(6, 2, a[2]);

            d.add(0, 3, Long.MAX_VALUE);
            d.add(0, 5, Long.MAX_VALUE);
            d.add(1, 3, Long.MAX_VALUE);
            d.add(1, 4, Long.MAX_VALUE);
            d.add(2, 4, Long.MAX_VALUE);
            d.add(2, 5, Long.MAX_VALUE);

            d.add(3, 7, b[0]);
            d.add(4, 7, b[1]);
            d.add(5, 7, b[2]);

            System.out.println((n - d.maxFlow(6, 7)) + " " + ma);
        }
    }
}

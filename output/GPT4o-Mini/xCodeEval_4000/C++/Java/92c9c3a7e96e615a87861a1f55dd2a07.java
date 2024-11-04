import java.util.*;

public class 92c9c3a7e96e615a87861a1f55dd2a07_nc {
    static long mod = (long) 1e9 + 7;
    static long[] vis = new long[200005];
    static long n, m, t, c = 0;
    static PriorityQueue<Long> q = new PriorityQueue<>(Collections.reverseOrder());
    static List<Pair<Long, Long>>[] adj = new ArrayList[200005];

    static class Pair<A, B> {
        A first;
        B second;

        Pair(A first, B second) {
            this.first = first;
            this.second = second;
        }
    }

    static void solve(long ind) {
        if (ind == n) {
            q.add(c);
            if (q.size() > t) q.poll();
            return;
        }
        solve(ind + 1);
        for (Pair<Long, Long> neighbor : adj[ind]) {
            if (vis[neighbor.first] == 0) {
                vis[neighbor.first] = 1;
                c += neighbor.second;
                if (q.size() < t || c < q.peek()) solve(ind + 1);
                c -= neighbor.second;
                vis[neighbor.first] = 0;
            }
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        n = sc.nextLong();
        m = sc.nextLong();
        t = sc.nextLong();
        for (int i = 0; i < 200005; i++) {
            adj[i] = new ArrayList<>();
        }
        while (m-- > 0) {
            long x = sc.nextLong() - 1;
            long y = sc.nextLong() - 1;
            long w = sc.nextLong();
            adj[(int) x].add(new Pair<>(y, w));
        }
        solve(0);
        System.out.println(q.peek());
    }
}

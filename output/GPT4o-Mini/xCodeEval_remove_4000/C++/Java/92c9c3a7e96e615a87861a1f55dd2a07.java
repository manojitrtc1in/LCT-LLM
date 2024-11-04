import java.util.*;

public class 92c9c3a7e96e615a87861a1f55dd2a07xcodeeval_processed_4000.json {
    static long mod = 1000000007;
    static long[] vis = new long[200005];
    static List<Pair<Long, Long>>[] adj = new ArrayList[200005];
    static PriorityQueue<Long> q = new PriorityQueue<>(Collections.reverseOrder());
    static long n, m, t, c = 0;

    static class Pair<K, V> {
        K first;
        V second;

        Pair(K first, V second) {
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
        for (Pair<Long, Long> edge : adj[(int) ind]) {
            if (vis[edge.first] == 0) {
                vis[edge.first] = 1;
                c += edge.second;
                if (q.size() < t || c < q.peek()) solve(ind + 1);
                c -= edge.second;
                vis[edge.first] = 0;
            }
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        n = scanner.nextLong();
        m = scanner.nextLong();
        t = scanner.nextLong();
        for (int i = 0; i < n; i++) {
            adj[i] = new ArrayList<>();
        }
        while (m-- > 0) {
            long x = scanner.nextLong() - 1;
            long y = scanner.nextLong() - 1;
            long w = scanner.nextLong();
            adj[(int) x].add(new Pair<>(y, w));
        }
        solve(0);
        System.out.println(q.peek());
    }
}

import java.util.*;

class Main {
    static class Pair {
        int first;
        int second;
        
        Pair(int first, int second) {
            this.first = first;
            this.second = second;
        }
    }
    
    static List<List<Pair>> adj;
    static PriorityQueue<Integer> q;
    static int[] vis;
    static int n, m, t, c;
    
    static void solve(int ind) {
        if (ind == n) {
            q.add(c);
            if (q.size() > t) q.poll();
            return;
        }
        solve(ind + 1);
        for (int i = 0; i < adj.get(ind).size(); i++) {
            if (vis[adj.get(ind).get(i).first] == 0) {
                vis[adj.get(ind).get(i).first] = 1;
                c += adj.get(ind).get(i).second;
                if (q.size() < t || c < q.peek()) solve(ind + 1);
                c -= adj.get(ind).get(i).second;
                vis[adj.get(ind).get(i).first] = 0;
            }
        }
    }
    
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int r, s = 0, x, i, j, k, l, m;
        n = sc.nextInt();
        m = sc.nextInt();
        t = sc.nextInt();
        adj = new ArrayList<>();
        for (i = 0; i < n; i++) {
            adj.add(new ArrayList<>());
        }
        while (m-- > 0) {
            int x = sc.nextInt();
            int y = sc.nextInt();
            int w = sc.nextInt();
            x--;
            y--;
            adj.get(x).add(new Pair(y, w));
        }
        q = new PriorityQueue<>();
        vis = new int[200005];
        solve(0);
        System.out.println(q.peek());
    }
}

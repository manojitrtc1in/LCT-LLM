import java.util.*;
import java.lang.*;
import java.io.*;

class Main {
    static class Pair {
        int first;
        int second;
        
        public Pair(int first, int second) {
            this.first = first;
            this.second = second;
        }
    }
    
    static List<Pair>[] adj;
    static PriorityQueue<Integer> q;
    static int[] vis;
    static int n, m, t, c;
    
    public static void solve(int ind) {
        if (ind == n) {
            q.add(c);
            if (q.size() > t) {
                q.poll();
            }
            return;
        }
        solve(ind + 1);
        for (int i = 0; i < adj[ind].size(); i++) {
            if (vis[adj[ind].get(i).first] == 0) {
                vis[adj[ind].get(i).first] = 1;
                c += adj[ind].get(i).second;
                if (q.size() < t || c < q.peek()) {
                    solve(ind + 1);
                }
                c -= adj[ind].get(i).second;
                vis[adj[ind].get(i).first] = 0;
            }
        }
    }
    
    public static void main(String[] args) throws java.lang.Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int r, s = 0, x, i, j, k, l, m;
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        t = Integer.parseInt(st.nextToken());
        adj = new ArrayList[n];
        for (i = 0; i < n; i++) {
            adj[i] = new ArrayList<>();
        }
        while (m-- > 0) {
            st = new StringTokenizer(br.readLine());
            int x = Integer.parseInt(st.nextToken()) - 1;
            int y = Integer.parseInt(st.nextToken()) - 1;
            int w = Integer.parseInt(st.nextToken());
            adj[x].add(new Pair(y, w));
        }
        vis = new int[n];
        q = new PriorityQueue<>();
        solve(0);
        System.out.println(q.peek());
    }
}

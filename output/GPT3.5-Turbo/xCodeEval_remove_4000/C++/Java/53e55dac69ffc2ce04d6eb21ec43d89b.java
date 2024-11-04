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
    
    static class Triple {
        int a;
        int b;
        int c;
        
        Triple(int a, int b, int c) {
            this.a = a;
            this.b = b;
            this.c = c;
        }
    }
    
    static Set<Integer>[] g;
    static int ct;
    static List<Integer> c;
    static int[] sz;
    static int[] used;
    static int n;
    static List<Triple> ans;
    
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        
        g = new Set[n + 1];
        for (int i = 1; i <= n; i++) {
            g[i] = new HashSet<>();
        }
        
        for (int i = 1; i < n; i++) {
            int x = sc.nextInt();
            int y = sc.nextInt();
            
            g[x].add(y);
            g[y].add(x);
        }
        
        go(1);
        used = new int[n + 1];
        Arrays.fill(used, 0);
        assert c.size() > 0;
        for (int x : c) {
            used[x] = 1;
        }
        for (int x : c) {
            ct = x;
            for (int to : g[ct]) {
                if (used[to] == 0) {
                    solve(to);
                }
            }
        }
        
        System.out.println(ans.size());
        assert ans.size() <= 2 * n;
        for (Triple t : ans) {
            System.out.println(t.a + " " + t.b + " " + t.c);
        }
    }
    
    static void go(int cur, int iter) {
        sz[cur] = 1;
        used[cur] = iter;
        int t = 0;
        for (int to : g[cur]) {
            if (used[to] != iter) {
                go(to, iter);
                sz[cur] += sz[to];
                t = Math.max(t, sz[to]);
            }
        }
        t = Math.max(t, n - sz[cur]);
        if (t * 2 <= n) {
            ct = cur;
            c.add(cur);
        }
    }
    
    static void go(int cur) {
        go(cur, 1);
    }
    
    static void solve(int cur) {
        Stack<Pair> st = new Stack<>();
        dfs2(cur, -1, st);
        st.pop();
        int last = cur;
        while (!st.isEmpty()) {
            Pair p = st.pop();
            int v = p.first;
            int par = p.second;
            if (par != cur) {
                ans.add(new Triple(ct, last, v));
                ans.add(new Triple(v, par, cur));
                last = v;
            }
        }
        if (last != cur) {
            ans.add(new Triple(ct, last, cur));
        }
    }
    
    static void dfs2(int cur, int p, Stack<Pair> st) {
        used[cur] = 1;
        for (int to : g[cur]) {
            if (used[to] == 0) {
                dfs2(to, cur, st);
            }
        }
        st.push(new Pair(cur, p));
    }
}

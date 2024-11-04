import java.util.*;

class Main {
    static Set<Integer>[] g;
    static int ct;
    static List<Integer> c;
    static int[] sz;
    static int[] used;
    static int n;
    static List<Triple<Integer, Integer, Integer>> ans;

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
        ans = new ArrayList<>();
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
        for (Triple<Integer, Integer, Integer> t : ans) {
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

    static void solve(int cur) {
        used[cur] = 1;
        List<Pair<Integer, Integer>> st = new ArrayList<>();
        dfs2(cur, -1, st);
        st.remove(st.size() - 1);
        int last = cur;
        for (Pair<Integer, Integer> p : st) {
            int v = p.a;
            int par = p.b;
            if (par != cur) {
                ans.add(new Triple<>(ct, last, v));
                ans.add(new Triple<>(v, par, cur));
                last = v;
            }
        }
        if (last != cur) {
            ans.add(new Triple<>(ct, last, cur));
        }
    }

    static void dfs2(int cur, int p, List<Pair<Integer, Integer>> st) {
        used[cur] = 1;
        for (int to : g[cur]) {
            if (used[to] == 0) {
                dfs2(to, cur, st);
            }
        }
        st.add(new Pair<>(cur, p));
    }

    static class Pair<A, B> {
        A a;
        B b;

        Pair(A a, B b) {
            this.a = a;
            this.b = b;
        }
    }

    static class Triple<A, B, C> {
        A a;
        B b;
        C c;

        Triple(A a, B b, C c) {
            this.a = a;
            this.b = b;
            this.c = c;
        }
    }
}

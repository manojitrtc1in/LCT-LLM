import java.util.*;

class Triple<T1, T2, T3> {
    T1 a;
    T2 b;
    T3 c;

    Triple() {
        this.a = null;
        this.b = null;
        this.c = null;
    }

    Triple(T1 _a, T2 _b, T3 _c) {
        this.a = _a;
        this.b = _b;
        this.c = _c;
    }
}

public class 53e55dac69ffc2ce04d6eb21ec43d89bxcodeeval_processed_4000.json {
    static Set<Integer>[] g = new HashSet[202020];
    static int ct;
    static List<Integer> c = new ArrayList<>();
    static int[] sz = new int[202020];
    static boolean[] used = new boolean[202020];
    static int n;
    static List<Triple<Integer, Integer, Integer>> ans = new ArrayList<>();

    static void go(int cur, int iter) {
        sz[cur] = 1;
        used[cur] = true;
        int t = 0;
        for (int to : g[cur]) {
            if (!used[to]) {
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

    static List<Pair<Integer, Integer>> st = new ArrayList<>();

    static void dfs2(int cur, int p) {
        used[cur] = true;
        for (int to : g[cur]) {
            if (!used[to]) {
                dfs2(to, cur);
            }
        }
        st.add(new Pair<>(cur, p));
    }

    static void solve(int cur) {
        st.clear();
        dfs2(cur, -1);
        st.remove(st.size() - 1);
        int last = cur;
        for (Pair<Integer, Integer> p : st) {
            int v = p.first;
            int par = p.second;
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

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        n = scanner.nextInt();
        for (int i = 0; i < n; i++) {
            g[i] = new HashSet<>();
        }
        for (int i = 0; i < n - 1; i++) {
            int x = scanner.nextInt();
            int y = scanner.nextInt();
            g[x].add(y);
            g[y].add(x);
        }
        go(1, 1);
        Arrays.fill(used, false);
        assert c.size() > 0;
        for (int x : c) {
            used[x] = true;
        }
        for (int x : c) {
            ct = x;
            for (int to : g[ct]) {
                if (!used[to]) {
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
}

class Pair<T1, T2> {
    T1 first;
    T2 second;

    Pair(T1 first, T2 second) {
        this.first = first;
        this.second = second;
    }
}

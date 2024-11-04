import java.util.*;

public class 59fd7fdca5d443cabf6a19325e6d8308_nc {
    static final int maxn = 200007;
    static int mod = 998244353;
    static int n, t;
    static int[] c = new int[maxn];
    static Set<Integer>[] s = new HashSet[maxn];
    static Set<Integer>[] st = new HashSet[maxn];
    static Set<Pair>[] deg = new HashSet[3];
    static Set<Pair>[] degt = new HashSet[3];

    static {
        for (int i = 0; i < maxn; i++) {
            s[i] = new HashSet<>();
            st[i] = new HashSet<>();
        }
        for (int i = 0; i < 3; i++) {
            deg[i] = new HashSet<>();
            degt[i] = new HashSet<>();
        }
    }

    static class Pair {
        int F, S;

        Pair(int F, int S) {
            this.F = F;
            this.S = S;
        }
    }

    static void removeLeaf(Set<Integer>[] s, Set<Pair>[] deg, int v) {
        if (s[v].isEmpty()) {
            deg[c[v]].remove(new Pair(0, v));
            return;
        }
        int u = s[v].iterator().next();
        assert v != 0;
        deg[c[v]].remove(new Pair(s[v].size(), v));
        deg[c[u]].remove(new Pair(s[u].size(), u));
        s[u].remove(v);
        s[v].remove(u);
        deg[c[u]].add(new Pair(s[u].size(), u));
    }

    static void eraseGrey(Set<Integer>[] s, Set<Pair>[] deg) {
        while (true) {
            if (deg[0].isEmpty()) break;
            Pair ret = deg[0].iterator().next();
            if (ret.F > 1) break;
            removeLeaf(s, deg, ret.S);
        }
    }

    static int solve(Set<Integer>[] s, Set<Pair>[] deg, int beg) {
        int res = 0;
        eraseGrey(s, deg);
        while (true) {
            if (deg[0].isEmpty() && deg[1].isEmpty() && deg[2].isEmpty()) break;
            if (deg[beg].isEmpty()) {
                beg = 3 - beg;
                continue;
            }
            res++;
            while (true) {
                if (deg[beg].isEmpty()) break;
                Pair ret = deg[beg].iterator().next();
                if (ret.F > 1) break;
                removeLeaf(s, deg, ret.S);
                eraseGrey(s, deg);
            }
            beg = 3 - beg;
        }
        return res;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        t = sc.nextInt();
        while (t-- > 0) {
            n = sc.nextInt();
            for (int i = 1; i <= n; i++) {
                c[i] = sc.nextInt();
            }
            for (int i = 1; i < n; i++) {
                int u = sc.nextInt();
                int v = sc.nextInt();
                s[u].add(v);
                s[v].add(u);
                st[u].add(v);
                st[v].add(u);
            }
            for (int i = 1; i <= n; i++) {
                deg[c[i]].add(new Pair(s[i].size(), i));
                degt[c[i]].add(new Pair(s[i].size(), i));
            }
            System.out.print(Math.max(Math.min(solve(s, deg, 1), solve(st, degt, 2)), 1L) + " ");
        }
        sc.close();
    }
}

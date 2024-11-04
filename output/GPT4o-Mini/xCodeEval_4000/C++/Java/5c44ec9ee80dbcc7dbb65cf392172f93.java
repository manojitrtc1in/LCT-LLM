import java.util.*;

public class 5c44ec9ee80dbcc7dbb65cf392172f93_nc {
    static final int MOD = 1000000007;
    static final int maxn = 100005;
    static int n;
    static int[][] pts = new int[maxn][2];
    static boolean[] visit = new boolean[maxn * 2];
    static List<Integer>[] g = new ArrayList[maxn * 2];

    static {
        for (int i = 0; i < maxn * 2; i++) {
            g[i] = new ArrayList<>();
        }
    }

    static class Pair {
        int first, second;

        Pair(int first, int second) {
            this.first = first;
            this.second = second;
        }
    }

    static Pair dfs(int u) {
        Pair ret = new Pair(1, g[u].size());
        visit[u] = true;
        for (int v : g[u]) {
            if (!visit[v]) {
                Pair p = dfs(v);
                ret.first += p.first;
                ret.second += p.second;
            }
        }
        return ret;
    }

    public static void main(String[] args) {
        Scanner fin = new Scanner(System.in);
        n = fin.nextInt();

        Map<Integer, Integer>[] trans = new HashMap[2];
        trans[0] = new HashMap<>();
        trans[1] = new HashMap<>();
        
        for (int i = 0; i < n; i++) {
            pts[i][0] = fin.nextInt();
            pts[i][1] = fin.nextInt();
            for (int j = 0; j < 2; j++) {
                trans[j].put(pts[i][j], 0);
            }
        }

        int cnt = 0;
        for (int j = 0; j < 2; j++) {
            for (Map.Entry<Integer, Integer> p : trans[j].entrySet()) {
                p.setValue(cnt++);
            }
        }

        for (int i = 0; i < n; i++) {
            int x = trans[0].get(pts[i][0]);
            int y = trans[1].get(pts[i][1]);
            g[x].add(y);
            g[y].add(x);
        }

        int ans = 1;
        for (int i = 0; i < cnt; i++) {
            if (!visit[i]) {
                Pair p = dfs(i);
                int vers = p.first;
                int edgs = p.second / 2;
                if (edgs == vers - 1) {
                    ans = (int) ((ans * (powMod(2, vers) - 1)) % MOD);
                } else {
                    ans = (int) ((ans * powMod(2, vers)) % MOD);
                }
            }
        }
        System.out.println(ans);
    }

    static long powMod(long a, long p) {
        long r = 1;
        a %= MOD;
        while (p > 0) {
            if ((p & 1) == 1) {
                r = (r * a) % MOD;
            }
            a = (a * a) % MOD;
            p >>= 1;
        }
        return r;
    }
}

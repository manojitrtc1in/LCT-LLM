import java.io.*;
import java.util.*;

class Main {
    static final int MOD = 1000000007;
    static final int maxn = 100005;
    static int n;
    static int[][] pts = new int[maxn][2];
    static boolean[] visit = new boolean[maxn * 2];
    static List<Integer>[] g = new ArrayList[maxn * 2];

    static void MULM_MOD(int a, int b) {
        a = (int) ((1L * a * b) % MOD);
    }

    static int SUBX_MOD(int a, int b) {
        a -= b;
        if (a < 0) {
            a += MOD;
        }
        return a;
    }

    static int POW_MOD(int a, int p) {
        int r = 1;
        a %= MOD;
        while (p > 0) {
            if ((p & 1) == 1) {
                r = (int) ((1L * r * a) % MOD);
            }
            a = (int) ((1L * a * a) % MOD);
            p >>= 1;
        }
        return r;
    }

    static int gcd(int a, int b) {
        while (a != 0) {
            b %= a;
            if (b == 0)
                return a;
            a %= b;
        }
        return b;
    }

    static int lcm(int a, int b) {
        return a / gcd(a, b) * b;
    }

    static int id1(int a, int b, int[] x, int[] y) {
        if (b == 0) {
            x[0] = 1;
            y[0] = 0;
            return a;
        }
        int g = id1(b, a % b, y, x);
        y[0] -= (a / b) * x[0];
        return g;
    }

    static int mul_mod(int a, int b, int m) {
        long p = a;
        p = (p * b) % m;
        return (int) p;
    }

    static int inv_mod(int a, int m) {
        int[] x = new int[1];
        int[] y = new int[1];
        id1(a, m, x, y);
        if (x[0] < 0)
            return x[0] + m;
        return x[0];
    }

    static int id7(int u, int v, int m) {
        int r = u + v;
        if (r >= m)
            r -= m;
        return r;
    }

    static int id3(int u, int v, int m) {
        int r = u - v;
        if (r < 0)
            r += m;
        return r;
    }

    static int div_mod(int u, int v, int m) {
        int g = gcd(v, m);
        assert u % g == 0;
        int mm = m / g;
        return mul_mod(u / g, inv_mod(v / g, mm), mm);
    }

    static int id0(int a, int b, int[] r) {
        int q = a / b;
        r[0] = a % b;
        if (r[0] < 0) {
            if (b < 0)
                q += 1;
            else
                q -= 1;
            r[0] += b;
        }
        return q;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader fin = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(fin.readLine());
        n = Integer.parseInt(st.nextToken());

        Map<Integer, Integer>[] trans = new HashMap[2];
        for (int i = 0; i < 2; i++) {
            trans[i] = new HashMap<>();
        }

        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(fin.readLine());
            pts[i][0] = Integer.parseInt(st.nextToken());
            pts[i][1] = Integer.parseInt(st.nextToken());
            for (int j = 0; j < 2; j++) {
                trans[j].put(pts[i][j], 0);
            }
        }

        int cnt = 0;
        for (int j = 0; j < 2; j++) {
            for (Map.Entry<Integer, Integer> entry : trans[j].entrySet()) {
                entry.setValue(cnt++);
            }
        }

        for (int i = 0; i < cnt * 2; i++) {
            g[i] = new ArrayList<>();
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
                Pair<Integer, Integer> p = dfs(i);
                int vers = p.first;
                int edgs = p.second / 2;
                if (edgs == vers - 1) {
                    MULM_MOD(ans, SUBX_MOD(POW_MOD(2, vers), 1));
                } else {
                    MULM_MOD(ans, POW_MOD(2, vers));
                }
            }
        }

        System.out.println(ans);
    }

    static Pair<Integer, Integer> dfs(int u) {
        Pair<Integer, Integer> ret = new Pair<>(1, g[u].size());
        visit[u] = true;
        for (int v : g[u]) {
            if (!visit[v]) {
                Pair<Integer, Integer> p = dfs(v);
                ret.first += p.first;
                ret.second += p.second;
            }
        }
        return ret;
    }

    static class Pair<T, U> {
        T first;
        U second;

        Pair(T first, U second) {
            this.first = first;
            this.second = second;
        }
    }
}

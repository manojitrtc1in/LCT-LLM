import java.util.*;

class Main {
    static final int MOD = 1000000007;
    static final int maxn = 100005;
    static int n;
    static int[][] pts = new int[maxn][2];
    static boolean[] visit = new boolean[maxn * 2];
    static boolean[] ve = new boolean[maxn * 2];
    static List<List<Pair<Integer, Integer>>> g = new ArrayList<>(maxn * 2);
    static int x_start, y_start, now = 0;

    static class Pair<T, U> {
        T first;
        U second;

        Pair(T first, U second) {
            this.first = first;
            this.second = second;
        }
    }

    static Pair<Integer, Integer> dfs(int u) {
        Pair<Integer, Integer> ret = new Pair<>(1, 0);
        visit[u] = true;
        for (Pair<Integer, Integer> vv : g.get(u)) {
            if (ve[vv.second]) continue;
            ++ret.second;
            ve[vv.second] = true;
            if (visit[vv.first]) continue;
            Pair<Integer, Integer> p = dfs(vv.first);
            ret.first += p.first;
            ret.second += p.second;
        }
        return ret;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();

        Map<Integer, Integer>[] trans = new Map[2];
        for (int i = 0; i < 2; i++) {
            trans[i] = new HashMap<>();
        }

        for (int i = 0; i < n; i++) {
            pts[i][0] = sc.nextInt();
            pts[i][1] = sc.nextInt();
            for (int j = 0; j < 2; j++) {
                if (!trans[j].containsKey(pts[i][j])) {
                    int s = trans[j].size();
                    trans[j].put(pts[i][j], s);
                }
                pts[i][j] = trans[j].get(pts[i][j]);
            }
        }

        x_start = now;
        now += trans[0].size();
        y_start = now;
        now += trans[1].size();
        assert now < maxn * 2;
        for (int i = 0; i < now; i++) {
            g.add(new ArrayList<>());
        }
        for (int i = 0; i < n; i++) {
            int x = x_start + pts[i][0];
            int y = y_start + pts[i][1];
            g.get(x).add(new Pair<>(y, i));
            g.get(y).add(new Pair<>(x, i));
        }
        int ans = 1;
        for (int i = 0; i < now; i++) {
            if (!visit[i]) {
                Pair<Integer, Integer> p = dfs(i);
                int k = p.first;
                if (p.second < p.first) {
                    ans = (ans * (pow_mod(2, k) - 1)) % MOD;
                } else {
                    ans = (ans * pow_mod(2, k)) % MOD;
                }
            }
        }
        System.out.println(ans);
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

    static int extended_gcd(int a, int b, int[] x, int[] y) {
        if (b == 0) {
            x[0] = 1;
            y[0] = 0;
            return a;
        }
        int g = extended_gcd(b, a % b, y, x);
        y[0] -= (a / b) * x[0];
        return g;
    }

    static int mul_mod(int a, int b, int m) {
        long p = a;
        p = (p * b) % m;
        return (int) p;
    }

    static int pow_mod(int a, int p, int m) {
        int r = 1;
        a %= m;
        for (; p > 0; p >>= 1) {
            if ((p & 1) == 1) r = mul_mod(r, a, m);
            a = mul_mod(a, a, m);
        }
        return r;
    }

    static int inv_mod(int a, int m) {
        int[] x = new int[1];
        int[] y = new int[1];
        extended_gcd(a, m, x, y);
        if (x[0] < 0)
            return x[0] + m;
        return x[0];
    }

    static int addx_mod(int u, int v, int m) {
        int r = u + v;
        if (r >= m) r -= m;
        return r;
    }

    static int subx_mod(int u, int v, int m) {
        int r = u - v;
        if (r < 0) r += m;
        return r;
    }

    static int div_mod(int u, int v, int m) {
        int g = gcd(v, m);
        assert u % g == 0;
        int mm = m / g;
        return mul_mod(u / g, inv_mod(v / g, mm), mm);
    }

    static int div_pos_r(int a, int b, int[] r) {
        int q = a / b;
        r[0] = a % b;
        if (r[0] < 0) {
            if (b < 0)
                q += 1;
            else
                q -= 1;
            r[0] -= b;
        }
        return q;
    }
}

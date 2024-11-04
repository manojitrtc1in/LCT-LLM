import java.util.*;
import java.io.*;

public class d588eeec57d09bf168bf7d63bc1e6cde_nc {
    static final int MOD = 1000000007;
    static final int maxn = 100005;
    static int n;
    static int[][] pts = new int[maxn][2];
    static boolean[] visit = new boolean[maxn * 2];
    static boolean[] ve = new boolean[maxn * 2];
    static List<Pair>[] g = new ArrayList[maxn * 2];
    static int x_start, y_start, now = 0;

    static class Pair {
        int first, second;

        Pair(int first, int second) {
            this.first = first;
            this.second = second;
        }
    }

    static {
        for (int i = 0; i < g.length; i++) {
            g[i] = new ArrayList<>();
        }
    }

    static Pair dfs(int u) {
        Pair ret = new Pair(1, 0);
        visit[u] = true;
        for (Pair vv : g[u]) {
            if (ve[vv.second]) continue;
            ++ret.second;
            ve[vv.second] = true;
            if (visit[vv.first]) continue;
            Pair p = dfs(vv.first);
            ret.first += p.first;
            ret.second += p.second;
        }
        return ret;
    }

    static int gcd(int a, int b) {
        while (a != 0) {
            b %= a;
            if (b == 0) return a;
            a %= b;
        }
        return b;
    }

    static int mul_mod(int a, int b, int m) {
        long p = a;
        p = (p * b) % m;
        return (int) p;
    }

    static int pow_mod(int a, int p, int m) {
        int r = 1;
        a %= m;
        while (p > 0) {
            if ((p & 1) == 1) r = mul_mod(r, a, m);
            a = mul_mod(a, a, m);
            p >>= 1;
        }
        return r;
    }

    static int subx_mod(int u, int v, int m) {
        int r = u - v;
        if (r < 0) r += m;
        return r;
    }

    static int addx_mod(int u, int v, int m) {
        int r = u + v;
        if (r >= m) r -= m;
        return r;
    }

    static int inv_mod(int a, int m) {
        int x = 0, y = 0;
        extended_gcd(a, m, x, y);
        if (x < 0) return x + m;
        return x;
    }

    static int extended_gcd(int a, int b, int x, int y) {
        if (b == 0) {
            x = 1;
            y = 0;
            return a;
        }
        int g = extended_gcd(b, a % b, y, x);
        y -= (a / b) * x;
        return g;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        n = Integer.parseInt(br.readLine());
        Map<Integer, Integer>[] trans = new HashMap[2];
        trans[0] = new HashMap<>();
        trans[1] = new HashMap<>();

        for (int i = 0; i < n; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            for (int j = 0; j < 2; j++) {
                int point = Integer.parseInt(st.nextToken());
                if (!trans[j].containsKey(point)) {
                    int s = trans[j].size();
                    trans[j].put(point, s);
                }
                pts[i][j] = trans[j].get(point);
            }
        }

        x_start = now; now += trans[0].size();
        y_start = now; now += trans[1].size();
        assert now < maxn * 2;

        for (int i = 0; i < n; i++) {
            int x = x_start + pts[i][0];
            int y = y_start + pts[i][1];
            g[x].add(new Pair(y, i));
            g[y].add(new Pair(x, i));
        }

        int ans = 1;
        for (int i = 0; i < now; i++) {
            if (!visit[i]) {
                Pair p = dfs(i);
                int k = p.first;
                if (p.second < p.first) {
                    ans = mul_mod(ans, subx_mod(pow_mod(2, k, MOD), 1, MOD), MOD);
                } else {
                    ans = mul_mod(ans, pow_mod(2, k, MOD), MOD);
                }
            }
        }
        System.out.println(ans);
    }
}

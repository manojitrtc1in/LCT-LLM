import java.util.*;

public class d588eeec57d09bf168bf7d63bc1e6cdexcodeeval_processed_4000.json {
    static final int MOD = 1000000007;
    static final int maxn = 100005;
    static int n;
    static int[][] pts = new int[maxn][2];
    static boolean[] visit = new boolean[maxn * 2];
    static boolean[] ve = new boolean[maxn * 2];
    static List<Pair<Integer, Integer>>[] g = new ArrayList[maxn * 2];
    static int x_start, y_start, now = 0;

    static {
        for (int i = 0; i < maxn * 2; i++) {
            g[i] = new ArrayList<>();
        }
    }

    static class Pair<A, B> {
        A first;
        B second;

        Pair(A first, B second) {
            this.first = first;
            this.second = second;
        }
    }

    static Pair<Integer, Integer> dfs(int u) {
        Pair<Integer, Integer> ret = new Pair<>(1, 0);
        visit[u] = true;
        for (Pair<Integer, Integer> vv : g[u]) {
            if (ve[vv.second]) continue;
            ret.second++;
            ve[vv.second] = true;
            if (visit[vv.first]) continue;
            Pair<Integer, Integer> p = dfs(vv.first);
            ret.first += p.first;
            ret.second += p.second;
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
                if (!trans[j].containsKey(pts[i][j])) {
                    int s = trans[j].size();
                    trans[j].put(pts[i][j], s);
                }
                pts[i][j] = trans[j].get(pts[i][j]);
            }
        }

        x_start = now; now += trans[0].size();
        y_start = now; now += trans[1].size();
        assert now < maxn * 2;

        for (int i = 0; i < n; i++) {
            int x = x_start + pts[i][0];
            int y = y_start + pts[i][1];
            g[x].add(new Pair<>(y, i));
            g[y].add(new Pair<>(x, i));
        }

        int ans = 1;
        for (int i = 0; i < now; i++) {
            if (!visit[i]) {
                Pair<Integer, Integer> p = dfs(i);
                int k = p.first;
                if (p.second < p.first) {
                    ans = (int) ((ans * (modPow(2, k) - 1 + MOD) % MOD) % MOD);
                } else {
                    ans = (int) ((ans * modPow(2, k)) % MOD);
                }
            }
        }
        System.out.println(ans);
    }

    static long modPow(int a, int b) {
        long res = 1;
        long base = a % MOD;
        while (b > 0) {
            if ((b & 1) == 1) {
                res = (res * base) % MOD;
            }
            base = (base * base) % MOD;
            b >>= 1;
        }
        return res;
    }
}

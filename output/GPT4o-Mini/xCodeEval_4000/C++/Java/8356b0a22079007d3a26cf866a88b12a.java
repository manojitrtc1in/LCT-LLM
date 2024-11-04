import java.util.*;

public class 8356b0a22079007d3a26cf866a88b12a_nc {
    static final int Maxn = 9;
    static long[] c = new long[Maxn];
    static int x, k, n, q;
    static int tl;
    static long[][] dist = new long[77][77];
    static int[] id = new int[256];
    static int cc = 0;
    static int[] p = new int[30], wp = new int[30];
    static long[] dp = new long[77], dp2 = new long[77];

    static void init() {
        for (int i = 0; i < (1 << k); i++) {
            int cnt = 0;
            for (int j = 0; j < k; ++j) {
                if ((i >> j & 1) != 0) cnt++;
            }
            if (cnt != x) continue;
            id[i] = ++cc;
        }
        for (int i = 0; i < (1 << k); i++) {
            int cnt = 0;
            for (int j = 0; j < k; ++j) {
                if ((i >> j & 1) != 0) cnt++;
            }
            if (cnt != x) continue;
            int v = i >> 1;
            int u = i & 1;
            if (u == 0) {
                dist[id[i]][id[v]] = 0;
            } else {
                for (int j = 0; j < k; j++) {
                    if ((v & (1 << j)) != 0) continue;
                    dist[id[i]][id[v ^ (1 << j)]] = c[j + 1];
                }
            }
        }
    }

    static long[][] build(int pos) {
        long[][] ret = new long[77][77];
        for (int i = 0; i < 77; i++) {
            Arrays.fill(ret[i], Long.MAX_VALUE);
        }
        for (int i = 0; i < (1 << k); i++) {
            if (id[i] == 0) continue;
            for (int j = 1; j <= q; j++) {
                if (p[j] <= pos && pos - p[j] < k) {
                    int pp = pos - p[j];
                    pp = k - 1 - pp;
                    if ((i >> (pp + 1) & 1) != 0) continue;
                    for (int l = 0; l < (1 << k); l++) {
                        if (id[l] == 0) continue;
                        if ((l >> pp & 1) != 0) {
                            if (ret[id[i]][id[l]] != Long.MAX_VALUE) {
                                ret[id[i]][id[l]] += wp[j];
                            }
                        }
                    }
                }
            }
        }
        return ret;
    }

    static long[][] multiply(long[][] x, long[][] y) {
        long[][] ret = new long[77][77];
        for (int i = 1; i <= cc; i++) {
            for (int j = 1; j <= cc; j++) {
                ret[i][j] = Long.MAX_VALUE;
                for (int k = 1; k <= cc; k++) {
                    ret[i][j] = Math.min(ret[i][j], x[i][k] + y[k][j]);
                }
            }
        }
        return ret;
    }

    static void mul(long[][] X) {
        Arrays.fill(dp2, Long.MAX_VALUE);
        for (int i = 1; i <= cc; i++) {
            for (int j = 1; j <= cc; j++) {
                dp2[j] = Math.min(dp2[j], dp[i] + X[i][j]);
            }
        }
        System.arraycopy(dp2, 0, dp, 0, dp.length);
    }

    static long[][] mqp(long[][] x, long p) {
        long[][] R = new long[77][77];
        for (int i = 1; i <= cc; i++) R[i][i] = 0;
        while (p > 0) {
            if ((p & 1) != 0) R = multiply(R, x);
            x = multiply(x, x);
            p >>= 1;
        }
        return R;
    }

    static boolean normal(int pos) {
        for (int i = 1; i <= q; i++) {
            if (p[i] <= pos && pos - p[i] < k) return false;
        }
        return true;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        x = scanner.nextInt();
        k = scanner.nextInt();
        n = scanner.nextInt();
        q = scanner.nextInt();
        n += k - x;

        for (int i = 1; i <= k; i++) {
            c[i] = scanner.nextLong();
        }
        init();

        for (int i = 1; i <= q; i++) {
            p[i] = scanner.nextInt();
            wp[i] = scanner.nextInt();
        }
        Arrays.fill(dp, Long.MAX_VALUE);
        dp[id[(1 << x) - 1]] = 0;
        int now = k;
        while (now < n) {
            if (!normal(now + 1)) {
                long[][] Tra = build(now + 1);
                mul(Tra);
                now++;
                continue;
            }
            int Nxt = n + 1;
            for (int i = 1; i <= q; i++) {
                if (p[i] > now) {
                    Nxt = Math.min(Nxt, p[i]);
                }
            }
            int di = Nxt - now - 1;
            long[][] Tra = mqp(dist, di);
            mul(Tra);
            now = Nxt - 1;
        }
        System.out.println(dp[id[(1 << x) - 1]]);
    }
}

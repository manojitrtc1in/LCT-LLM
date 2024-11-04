import java.util.*;

public class 8356b0a22079007d3a26cf866a88b12axcodeeval_processed_4000.json {
    static final int Maxn = 1005;
    static final long INF = Long.MAX_VALUE;
    static long[] c = new long[9];
    static int[] id = new int[256];
    static Matrix T1 = new Matrix();
    static int cc = 0;
    static long[] dp = new long[77];
    static long[] dp2 = new long[77];
    static int[] p = new int[30], wp = new int[30];
    static int x, k, n, q;

    static class Matrix {
        long[][] dist = new long[77][77];

        Matrix() {
            for (int i = 0; i < 77; i++) {
                Arrays.fill(dist[i], INF);
            }
        }
    }

    static void init() {
        for (int i = 0; i < (1 << k); i++) {
            int cnt = Integer.bitCount(i);
            if (cnt != x) continue;
            id[i] = ++cc;
        }
        for (int i = 0; i < (1 << k); i++) {
            int cnt = Integer.bitCount(i);
            if (cnt != x) continue;
            int v = i >> 1;
            int u = i & 1;
            if (u == 0) {
                T1.dist[id[i]][id[v]] = 0;
            } else {
                for (int j = 0; j < k; j++) {
                    if ((v & (1 << j)) != 0) continue;
                    T1.dist[id[i]][id[v ^ (1 << j)]] = c[j + 1];
                }
            }
        }
    }

    static Matrix build(int pos) {
        Matrix ret = T1;
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
                            if (ret.dist[id[i]][id[l]] != INF) {
                                ret.dist[id[i]][id[l]] += wp[j];
                            }
                        }
                    }
                }
            }
        }
        return ret;
    }

    static Matrix multiply(Matrix x, Matrix y) {
        Matrix ret = new Matrix();
        for (int i = 1; i <= cc; i++) {
            for (int j = 1; j <= cc; j++) {
                for (int k = 1; k <= cc; k++) {
                    ret.dist[i][j] = Math.min(ret.dist[i][j], x.dist[i][k] + y.dist[k][j]);
                }
            }
        }
        return ret;
    }

    static void mul(Matrix X) {
        Arrays.fill(dp2, INF);
        for (int i = 1; i <= cc; i++) {
            for (int j = 1; j <= cc; j++) {
                dp2[j] = Math.min(dp2[j], dp[i] + X.dist[i][j]);
            }
        }
        System.arraycopy(dp2, 0, dp, 0, cc + 1);
    }

    static Matrix mqp(Matrix x, long p) {
        Matrix R = new Matrix();
        for (int i = 1; i <= cc; i++) R.dist[i][i] = 0;
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
        Arrays.fill(dp, INF);
        dp[id[(1 << x) - 1]] = 0;
        int now = k;
        while (now < n) {
            if (!normal(now + 1)) {
                Matrix Tra = build(now + 1);
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
            Matrix Tra = mqp(T1, di);
            mul(Tra);
            now = Nxt - 1;
        }
        System.out.println(dp[id[(1 << x) - 1]]);
    }
}

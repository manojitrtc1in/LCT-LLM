import java.util.*;
import java.io.*;

class Main {
    static final int Maxn = 9;
    static int x, k, n, q;
    static int tl;
    static long[][] dist = new long[77][77];
    static int cc = 0;
    static long[] c = new long[Maxn];
    static int[] id = new int[256];
    static long[] dp = new long[77];
    static long[] dp2 = new long[77];
    static long[][] T1 = new long[77][77];
    static int[] p = new int[30];
    static int[] wp = new int[30];

    static void _init() {
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
                T1[id[i]][id[v]] = 0;
            } else {
                for (int j = 0; j < k; j++) {
                    if ((v & (1 << j)) != 0) continue;
                    T1[id[i]][id[v ^ (1 << j)]] = c[j + 1];
                }
            }
        }
    }

    static void Mul(long[][] X) {
        for (int i = 1; i <= cc; i++) {
            dp2[i] = (long) 1e18;
        }
        for (int i = 1; i <= cc; i++) {
            for (int j = 1; j <= cc; j++) {
                dp2[j] = Math.min(dp2[j], dp[i] + X[i][j]);
            }
        }
        for (int i = 1; i <= cc; i++) dp[i] = dp2[i];
    }

    static long[][] mul(long[][] x, long[][] y) {
        long[][] ret = new long[77][77];
        for (int i = 1; i <= cc; i++) {
            for (int j = 1; j <= cc; j++) {
                for (int k = 1; k <= cc; k++) {
                    ret[i][j] = Math.min(ret[i][j], x[i][k] + y[k][j]);
                }
            }
        }
        return ret;
    }

    static long[][] mqp(long[][] x, long p) {
        long[][] R = new long[77][77];
        for (int i = 1; i <= cc; i++) R[i][i] = 0;
        while (p > 0) {
            if ((p & 1) != 0) R = mul(R, x);
            x = mul(x, x);
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

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] input = br.readLine().split(" ");
        x = Integer.parseInt(input[0]);
        k = Integer.parseInt(input[1]);
        n = Integer.parseInt(input[2]);
        q = Integer.parseInt(input[3]);
        n += k - x;
        input = br.readLine().split(" ");
        for (int i = 1; i <= k; i++) {
            c[i] = Long.parseLong(input[i - 1]);
        }
        _init();
        input = br.readLine().split(" ");
        for (int i = 1; i <= q; i++) {
            p[i] = Integer.parseInt(input[2 * i - 2]);
            wp[i] = Integer.parseInt(input[2 * i - 1]);
        }
        for (int i = 1; i <= cc; i++) dp[i] = (long) 1e18;
        dp[id[(1 << x) - 1]] = 0;
        int now = k;
        while (now < n) {
            if (!normal(now + 1)) {
                long[][] Tra = new long[77][77];
                for (int i = 1; i <= cc; i++) {
                    for (int j = 1; j <= cc; j++) {
                        Tra[i][j] = T1[i][j];
                    }
                }
                Mul(Tra);
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
            long[][] Tra = mqp(T1, di);
            Mul(Tra);
            now = Nxt - 1;
        }
        System.out.println(dp[id[(1 << x) - 1]]);
    }
}

import java.util.*;
import java.io.*;

public class 5bce18dea1b71b7cffd6e3c26e62523e_nc {
    static final int INF = (int) 1e9;
    static final long INF64 = (long) 1e18;
    static final int MOD = 998244353;
    static final int N = 50 + 7;
    static final int M = 3000 + 7;

    static int n, m;
    static int[] a = new int[N];
    static int[] w = new int[N];
    static int[][][] dp = new int[N][N][2 * N];
    static int[] rev = new int[M];

    static boolean read() {
        Scanner scanner = new Scanner(System.in);
        if (!scanner.hasNextInt()) return false;
        n = scanner.nextInt();
        m = scanner.nextInt();
        for (int i = 0; i < n; i++) {
            a[i] = scanner.nextInt();
        }
        for (int i = 0; i < n; i++) {
            w[i] = scanner.nextInt();
        }
        return true;
    }

    static int add(int a, int b) {
        a += b;
        if (a >= MOD) a -= MOD;
        if (a < 0) a += MOD;
        return a;
    }

    static long mul(int a, int b) {
        return (long) a * b % MOD;
    }

    static int binpow(int a, int b) {
        int res = 1;
        while (b > 0) {
            if ((b & 1) == 1) res = mul(res, a);
            a = mul(a, a);
            b >>= 1;
        }
        return res;
    }

    static int inv(int x) {
        return binpow(x, MOD - 2);
    }

    static void solve() {
        int sum = Arrays.stream(w).sum();
        int neg = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] == 0) neg += w[i];
        }
        for (int i = 0; i < M; i++) {
            rev[i] = inv(i);
        }

        for (int z = 0; z < n; z++) {
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) {
                    Arrays.fill(dp[i][j], 0);
                }
            }
            dp[0][0][w[z]] = 1;

            for (int i = 0; i < m; i++) {
                for (int pos = 0; pos <= i; pos++) {
                    for (int val = 0; val < 2 * N; val++) {
                        if (dp[i][pos][val] > 0) {
                            int p = mul(val, rev[sum + pos - (i - pos)]);
                            int pneg = mul(neg - (a[z] == 0 ? val : 0) - (i - pos), rev[sum + pos - (i - pos)]);
                            int ppos = add(1, -add(p, pneg));

                            if (a[z] == 0 && val > 0) {
                                dp[i + 1][pos][val - 1] = add(dp[i + 1][pos][val - 1], mul(dp[i][pos][val], p));
                            }
                            if (a[z] == 1) {
                                dp[i + 1][pos + 1][val + 1] = add(dp[i + 1][pos + 1][val + 1], mul(dp[i][pos][val], p));
                            }
                            dp[i + 1][pos + 1][val] = add(dp[i + 1][pos + 1][val], mul(dp[i][pos][val], ppos));
                            dp[i + 1][pos][val] = add(dp[i + 1][pos][val], mul(dp[i][pos][val], pneg));
                        }
                    }
                }
            }

            int ans = 0;
            for (int pos = 0; pos <= m; pos++) {
                for (int val = 0; val < 2 * N; val++) {
                    ans = add(ans, mul(dp[m][pos][val], val));
                }
            }
            System.out.println(ans);
        }
    }

    public static void main(String[] args) {
        while (read()) {
            solve();
        }
    }
}

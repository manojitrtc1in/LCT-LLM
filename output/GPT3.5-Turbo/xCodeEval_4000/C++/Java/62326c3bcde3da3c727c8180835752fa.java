import java.util.*;

public class 62326c3bcde3da3c727c8180835752fa_nc {
    static long[][] ncr = new long[40][40];
    static long[][] ans = new long[30][30];

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        for (int i = 0; i < 40; i++) {
            for (int j = 0; j < 40; j++) {
                if (j > i) {
                    ncr[i][j] = 0;
                    continue;
                }
                if (j == 0 || j == i) {
                    ncr[i][j] = 1;
                    continue;
                }
                ncr[i][j] = ncr[i - 1][j - 1] + ncr[i - 1][j];
            }
        }

        int R, C;
        R = sc.nextInt();
        C = sc.nextInt();
        String str = sc.next();
        int n = R + C;
        long[][] blockarea = new long[n][n];
        long[][] totalarea = new long[n + 1][n + 1];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                blockarea[i][j] = ncr[i][R - 1] * ncr[j][R - 1];
            }
        }
        long[][] revarea = new long[n + 1][n + 1];
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= n; j++) {
                totalarea[i][j] = 0;
                if (i == 0 || j == 0) continue;
                totalarea[i][j] = totalarea[i][j - 1] + totalarea[i - 1][j] - totalarea[i - 1][j - 1];
                totalarea[i][j] += blockarea[i - 1][j - 1];
            }
        }
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= n; j++) {
                revarea[i][j] = totalarea[n][n] - totalarea[n - i][n] - totalarea[n][n - j] + totalarea[n - i][n - j];
            }
        }

        int d = Math.min(2 * n - 1, n);

        Map<Long, Long>[][] dp = new HashMap[n + 1][n + 1];
        Map<Long, Long>[][] bp = new HashMap[n + 1][n + 1];
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= n; j++) {
                dp[i][j] = new HashMap<>();
                bp[i][j] = new HashMap<>();
            }
        }
        dp[0][0].put(0L, 1L);
        bp[0][0].put(0L, 1L);

        long best = ans[R][C];
        long m1 = (-best + totalarea[n][n]) / 2;
        long m2 = totalarea[n][n] - m1;
        long bestfreq = 0;

        for (int x = 0; x <= n; x++) {
            for (int y = 0; y < n; y++) {
                if (x + y + 1 <= d && str.charAt(x + y) != 'B') {
                    for (Map.Entry<Long, Long> entry : dp[x][y].entrySet()) {
                        long area2 = entry.getKey() + totalarea[n][y + 1] - totalarea[x][y + 1];
                        if (area2 > m2) continue;
                        dp[x][y + 1].put(entry.getKey(), dp[x][y + 1].getOrDefault(entry.getKey(), 0L) + entry.getValue());
                    }
                }
                if (x + y + 1 <= 2 * n - d && str.charAt(n - x + n - y - 1) != 'B') {
                    for (Map.Entry<Long, Long> entry : bp[x][y].entrySet()) {
                        long area2 = totalarea[n][n] - entry.getKey() - totalarea[n - x][n - (y + 1)];
                        if (area2 > m2) continue;
                        bp[x][y + 1].put(entry.getKey(), bp[x][y + 1].getOrDefault(entry.getKey(), 0L) + entry.getValue());
                    }
                }
            }
            if (x == n) continue;
            for (int y = 0; y <= n; y++) {

                if (x + y + 1 <= d && str.charAt(x + y) != 'A') {
                    long newarea = totalarea[x + 1][y] - totalarea[x][y];
                    for (Map.Entry<Long, Long> entry : dp[x][y].entrySet()) {
                        long c = entry.getKey() + newarea;
                        long area2 = totalarea[x + 1][n] - c;
                        if (area2 > m2) continue;
                        dp[x + 1][y].put(entry.getKey() + newarea, dp[x + 1][y].getOrDefault(entry.getKey() + newarea, 0L) + entry.getValue());
                    }
                }
                if (x + y + 1 <= 2 * n - d && str.charAt(n - x + n - y - 1) != 'A') {
                    long newarea = totalarea[n - x][n - y] - totalarea[n - x - 1][n - y];
                    for (Map.Entry<Long, Long> entry : bp[x][y].entrySet()) {
                        if (entry.getKey() + newarea > m2) continue;
                        bp[x + 1][y].put(entry.getKey() + newarea, bp[x + 1][y].getOrDefault(entry.getKey() + newarea, 0L) + entry.getValue());
                    }
                }
                if (x + y + 1 <= d) dp[x][y].clear();
                if (x + y + 1 <= 2 * n - d) bp[x][y].clear();
            }

        }

        for (int x = 0; x <= n; x++) {
            int y = d - x;
            if (y < 0 || y > n) continue;

            for (Map.Entry<Long, Long> entry : dp[x][y].entrySet()) {
                long c = entry.getKey();
                long freq = entry.getValue();

                bestfreq += freq * bp[n - x][n - y].getOrDefault(m1 - c, 0L);
                if (m1 != m2) bestfreq += freq * bp[n - x][n - y].getOrDefault(m2 - c, 0L);
            }
        }

        System.out.println(bestfreq);
    }
}

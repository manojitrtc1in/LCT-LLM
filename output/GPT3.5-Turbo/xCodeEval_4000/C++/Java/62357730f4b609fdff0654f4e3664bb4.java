import java.util.*;

public class 62357730f4b609fdff0654f4e3664bb4_nc {
    static long[][] ncr = new long[40][40];
    static long[][] ans = new long[30][30];

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        for (int a = 0; a < 40; a++) {
            for (int b = 0; b < 40; b++) {
                if (b > a) {
                    ncr[a][b] = 0;
                    continue;
                }
                if (b == 0 || b == a) {
                    ncr[a][b] = 1;
                    continue;
                }
                ncr[a][b] = ncr[a - 1][b - 1] + ncr[a - 1][b];
            }
        }

        int R = sc.nextInt();
        int C = sc.nextInt();
        String str = sc.next();
        int n = R + C;
        long[][] blockarea = new long[n][n];
        long[][] totalarea = new long[n + 1][n + 1];

        for (int a = 0; a < n; a++) {
            for (int b = 0; b < n; b++) {
                blockarea[a][b] = ncr[a][R - 1] * ncr[b][R - 1];
            }
        }

        long[][] revarea = new long[n + 1][n + 1];

        for (int a = 0; a <= n; a++) {
            for (int b = 0; b <= n; b++) {
                totalarea[a][b] = 0;
                if (a == 0 || b == 0) continue;
                totalarea[a][b] = totalarea[a][b - 1] + totalarea[a - 1][b] - totalarea[a - 1][b - 1];
                totalarea[a][b] += blockarea[a - 1][b - 1];
            }
        }

        for (int a = 0; a <= n; a++) {
            for (int b = 0; b <= n; b++) {
                revarea[a][b] = totalarea[n][n] - totalarea[n - a][n] - totalarea[n][n - b] + totalarea[n - a][n - b];
            }
        }

        int d = Math.min(2 * n - 1, n + R - 4);

        Map<Integer, Long>[][] dp = new HashMap[n + 1][n + 1];
        Map<Integer, Long>[][] bp = new HashMap[n + 1][n + 1];

        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= n; j++) {
                dp[i][j] = new HashMap<>();
                bp[i][j] = new HashMap<>();
            }
        }

        dp[0][0].put(0, 1L);
        bp[0][0].put(0, 1L);

        long best = ans[R][C];
        long m1 = (-best + totalarea[n][n]) / 2;
        long m2 = totalarea[n][n] - m1;
        long bestfreq = 0;

        for (int x = 0; x <= n; x++) {
            for (int y = 0; y < n; y++) {
                if (x + y + 1 <= d && str.charAt(x + y) != 'B') {
                    for (Map.Entry<Integer, Long> entry : dp[x][y].entrySet()) {
                        int area2 = entry.getKey() + (int) (totalarea[n][y + 1] - totalarea[x][y + 1]);
                        if (area2 > m2) continue;
                        dp[x][y + 1].put(entry.getKey(), dp[x][y + 1].getOrDefault(entry.getKey(), 0L) + entry.getValue());
                    }
                }
                if (x + y + 1 <= 2 * n - d && str.charAt(n - x + n - y - 1) != 'B') {
                    for (Map.Entry<Integer, Long> entry : bp[x][y].entrySet()) {
                        int area2 = (int) (totalarea[n][n] - entry.getKey() - totalarea[n - x][n - (y + 1)]);
                        if (area2 > m2) continue;
                        bp[x][y + 1].put(entry.getKey(), bp[x][y + 1].getOrDefault(entry.getKey(), 0L) + entry.getValue());
                    }
                }
            }
            if (x == n) continue;
            for (int y = 0; y <= n; y++) {
                if (x + y + 1 <= d && str.charAt(x + y) != 'A') {
                    int newarea = (int) (totalarea[x + 1][y] - totalarea[x][y]);
                    for (Map.Entry<Integer, Long> entry : dp[x][y].entrySet()) {
                        int c = entry.getKey() + newarea;
                        int area2 = (int) (totalarea[x + 1][n] - c);
                        if (area2 > m2) continue;
                        dp[x + 1][y].put(entry.getKey() + newarea, dp[x + 1][y].getOrDefault(entry.getKey() + newarea, 0L) + entry.getValue());
                    }
                }
                if (x + y + 1 <= 2 * n - d && str.charAt(n - x + n - y - 1) != 'A') {
                    int newarea = (int) (totalarea[n - x][n - y] - totalarea[n - x - 1][n - y]);
                    for (Map.Entry<Integer, Long> entry : bp[x][y].entrySet()) {
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

            for (Map.Entry<Integer, Long> entry : dp[x][y].entrySet()) {
                int c = entry.getKey();
                long freq = entry.getValue();

                bestfreq += freq * bp[n - x][n - y].getOrDefault(m1 - c, 0L);
                if (m1 != m2) bestfreq += freq * bp[n - x][n - y].getOrDefault(m2 - c, 0L);
            }
        }

        System.out.println(bestfreq);
    }
}

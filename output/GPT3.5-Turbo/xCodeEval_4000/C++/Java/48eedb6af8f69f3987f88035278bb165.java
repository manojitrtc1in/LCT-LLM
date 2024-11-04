import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class 48eedb6af8f69f3987f88035278bb165_nc {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int R = scanner.nextInt();
        int C = scanner.nextInt();
        scanner.nextLine();
        String str = scanner.nextLine();

        int n = R + C;
        long[][] blockarea = new long[n][n];
        long[][] totalarea = new long[n + 1][n + 1];
        long[][] revarea = new long[n + 1][n + 1];

        long[][] ncr = new long[40][40];
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

        for (int a = 0; a < n; a++) {
            for (int b = 0; b < n; b++) {
                blockarea[a][b] = ncr[a][R - 1] * ncr[b][R - 1];
            }
        }

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

        int d = Math.min(2 * n - 1, n + R - 2);

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
                        int area2 = (int) (totalarea[n][n] - entry.getKey() - (totalarea[n - x][n - (y + 1)]));
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
                        if (entry.getKey() + newarea > m2) continue;
                        dp[x + 1][y].put(entry.getKey() + newarea, dp[x + 1][y].getOrDefault(entry.getKey() + newarea, 0L) + entry.getValue());
                    }
                }
                if (x + y + 1 <= 2 * n - d && str.charAt(n - x + n - y - 1) != 'A') {
                    int newarea2 = (int) (totalarea[n - x][n - y] - totalarea[n - x - 1][n - y]);
                    for (Map.Entry<Integer, Long> entry : bp[x][y].entrySet()) {
                        if (entry.getKey() + newarea2 > m2) continue;
                        bp[x + 1][y].put(entry.getKey() + newarea2, bp[x + 1][y].getOrDefault(entry.getKey() + newarea2, 0L) + entry.getValue());
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

    static long[][] ans = {
            {0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1},
            {3, 0, 2, 3, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1},
            {8, 20, 0, 15, 16, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1},
            {15, 75, 175, 0, 4, 0, 0, 45, 15, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, 0},
            {24, 189, 784, 1764, 0, 0, 60, 95, 200, 1, 14, 14, 0, 4, 0, 1, 0, 1, 0, 0},
            {35, 392, 2352, 8820, 19404, 0, 6600, 553, 245, 10780, 658, 126, 56, 20, 0, 5, 5, 0, 0, 0},
            {48, 720, 5760, 29700, 104544, 226512, 0, 15015, 40040, 0, 1440, 2028, 432, 1280, 8, 249, 8, 20, 6, 4},
            {63, 1215, 12375, 81675, 382239, 1288287, 2760615, 0, 1635920, 198198, 534456, 4524, 1546, 111564, 4050, 621, 3069, 5, 43, 1},
            {80, 1925, 24200, 196625, 1145144, 5010005, 16359200, 34763300, 0, 34606, 701350, 6651840, 78298, 429418, 872494, 1615, 352, 1155, 8580, 145},
            {99, 2904, 44044, 429429, 3006003, 16032016, 66745536, 212751396, 449141836, 0, 11675872, 4900324, 980474, 120143080, 47159156, 380171, 35871, 2207348, 223498, 4875},
            {120, 4212, 75712, 869505, 7154784, 45048640, 225059328, 901995588, 2821056160L, 5924217936L, 0, 1763160100, 1014736800, 96243664, 527663136, 13024737, 1152008, 27986506, 835384, 0},
            {143, 5915, 124215, 1656200, 15767024, 114874032, 668144880, 3173688180L, 12342120700L, 38013731756L, 79483257308L, 0, 334424, 86230664, 401457992, 1811255769, 8782619185L, 524739891, 0, 0},
            {168, 8085, 196000, 2998800, 32626944, 271211472, 1802805120L, 9859090500L, 44986664800L, 170724392916L, 519227905728L, 1081724803600L, 0, 5856160, 0, 208030461065L, 743483832, 0, 0, 0},
            {195, 10800, 299200, 5202000, 64047024, 600935040L, 4507012800L, 27887141700L, 145173803500L, 641087516256L, 2384209771200L, 7174705330000L, 14901311070000L, 0, 262032716400L, 2131715333625L, 0, 0, 0, 0},
            {224, 14144, 443904, 8697744, 120187008L, 1261963584L, 10576456704L, 73167596964L, 427391677504L, 2136958387520L, 9183622822400L, 33577620944400L, 100136810390400L, 207426250094400L, 0, 0, 0, 0, 0, 0},
            {255, 18207, 642447, 14084415L, 216899991L, 2530499895L, 23518156167L, 180305863947L, 1168649118175L, 6511045086975L, 31479019635375L, 132211882468575L, 476432168185575L, 1409850293610375L, 0, 0, 0, 0, 0, 0},
            {288, 23085, 909720, 22174425L, 378261576L, 4873620213L, 49911657840L, 421129613025L, 3003942370000L, 18451716007725L, 98815801429800L, 464342770607625L, 1912322889603000L, 0, 0, 0, 0, 0, 0, 0},
            {323, 28880, 1263500, 34051325L, 639970331L, 9058041608L, 101671895600L, 938731990625L, 7322109526875L, 49204576020600L, 288924390600300L, 1496215594180125L, 0, 334424, 0, 208030461065L, 743483832, 0, 0, 0},
            {360, 35700, 1724800, 51137625L, 1053844176L, 16309493200L, 199708080000L, 2008002335625L, 17037595575000L, 124510748462100L, 795771174744000L, 0, 0, 5856160, 0, 0, 0, 0, 0, 0},
            {399, 43659, 2318239, 75274584L, 1693678140L, 28541613100L, 379694987100L, 4140135724725L, 38044950918975L, 300900975450075L, 0, 11675872, 4900324, 980474, 120143080, 47159156, 380171, 35871, 2207348, 223498}
    };
}

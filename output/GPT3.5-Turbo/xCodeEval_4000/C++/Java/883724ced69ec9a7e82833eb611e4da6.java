import java.util.*;

public class 883724ced69ec9a7e82833eb611e4da6_nc {
    static long[][] ncr = new long[40][40];
    static long[][] ans = new long[30][30];

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int R = sc.nextInt();
        int C = sc.nextInt();
        String str = sc.next();
        int n = R + C;
        long[][] blockarea = new long[n][n];
        long[][] totalarea = new long[n + 1][n + 1];
        long[][] revarea = new long[n + 1][n + 1];

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

        for (int a = 0; a < 30; a++) {
            for (int b = 0; b < 30; b++) {
                ans[a][b] = 0;
            }
        }

        ans[1][2] = 1;
        ans[1][4] = 1;
        ans[1][6] = 1;
        ans[1][8] = 1;
        ans[1][10] = 1;
        ans[1][12] = 1;
        ans[1][14] = 1;
        ans[1][16] = 1;
        ans[1][18] = 1;
        ans[1][20] = 1;
        ans[2][1] = 3;
        ans[2][3] = 2;
        ans[2][4] = 3;
        ans[2][5] = 1;
        ans[2][8] = 1;
        ans[2][9] = 1;
        ans[2][12] = 1;
        ans[2][13] = 1;
        ans[2][16] = 1;
        ans[2][17] = 1;
        ans[3][1] = 8;
        ans[3][2] = 20;
        ans[3][4] = 15;
        ans[3][5] = 16;
        ans[3][8] = 1;
        ans[3][12] = 1;
        ans[3][16] = 1;
        ans[4][1] = 15;
        ans[4][2] = 75;
        ans[4][3] = 175;
        ans[4][5] = 4;
        ans[4][8] = 45;
        ans[4][9] = 15;
        ans[4][10] = 1;
        ans[4][11] = 1;
        ans[4][16] = 1;
        ans[4][17] = 1;
        ans[4][18] = 1;
        ans[4][19] = 1;
        ans[5][1] = 24;
        ans[5][2] = 189;
        ans[5][3] = 784;
        ans[5][4] = 1764;
        ans[5][7] = 60;
        ans[5][8] = 95;
        ans[5][9] = 200;
        ans[5][11] = 14;
        ans[5][12] = 14;
        ans[5][14] = 4;
        ans[5][16] = 1;
        ans[5][18] = 1;
        ans[6][1] = 35;
        ans[6][2] = 392;
        ans[6][3] = 2352;
        ans[6][4] = 8820;
        ans[6][5] = 19404;
        ans[6][7] = 6600;
        ans[6][8] = 553;
        ans[6][9] = 245;
        ans[6][10] = 10780;
        ans[6][11] = 658;
        ans[6][12] = 126;
        ans[6][13] = 56;
        ans[6][14] = 20;
        ans[6][16] = 5;
        ans[6][17] = 5;
        ans[7][1] = 48;
        ans[7][2] = 720;
        ans[7][3] = 5760;
        ans[7][4] = 29700;
        ans[7][5] = 104544;
        ans[7][6] = 226512;
        ans[7][8] = 15015;
        ans[7][9] = 40040;
        ans[7][11] = 1440;
        ans[7][12] = 2028;
        ans[7][13] = 432;
        ans[7][14] = 1280;
        ans[7][15] = 8;
        ans[7][16] = 249;
        ans[7][17] = 8;
        ans[7][18] = 20;
        ans[7][19] = 6;
        ans[7][20] = 4;
        ans[8][1] = 63;
        ans[8][2] = 1215;
        ans[8][3] = 12375;
        ans[8][4] = 81675;
        ans[8][5] = 382239;
        ans[8][6] = 1288287;
        ans[8][7] = 2760615;
        ans[8][9] = 1635920;
        ans[8][10] = 198198;
        ans[8][11] = 534456;
        ans[8][12] = 4524;
        ans[8][13] = 1546;
        ans[8][14] = 111564;
        ans[8][15] = 4050;
        ans[8][16] = 621;
        ans[8][17] = 3069;
        ans[8][19] = 43;
        ans[8][20] = 1;
        ans[9][1] = 80;
        ans[9][2] = 1925;
        ans[9][3] = 24200;
        ans[9][4] = 196625;
        ans[9][5] = 1145144;
        ans[9][6] = 5010005;
        ans[9][7] = 16359200;
        ans[9][8] = 34763300;
        ans[9][10] = 34606;
        ans[9][11] = 701350;
        ans[9][12] = 6651840;
        ans[9][13] = 78298;
        ans[9][14] = 429418;
        ans[9][15] = 872494;
        ans[9][17] = 352;
        ans[9][18] = 1155;
        ans[9][19] = 8580;
        ans[9][20] = 145;
        ans[10][1] = 99;
        ans[10][2] = 2904;
        ans[10][3] = 44044;
        ans[10][4] = 429429;
        ans[10][5] = 3006003;
        ans[10][6] = 16032016;
        ans[10][7] = 66745536;
        ans[10][8] = 212751396;
        ans[10][9] = 449141836;
        ans[10][11] = 11675872;
        ans[10][12] = 4900324;
        ans[10][13] = 980474;
        ans[10][14] = 120143080;
        ans[10][15] = 47159156;
        ans[10][16] = 380171;
        ans[10][17] = 35871;
        ans[10][18] = 2207348;
        ans[10][19] = 223498;
        ans[10][20] = 4875;
        ans[11][1] = 120;
        ans[11][2] = 4212;
        ans[11][3] = 75712;
        ans[11][4] = 869505;
        ans[11][5] = 7154784;
        ans[11][6] = 45048640;
        ans[11][7] = 225059328;
        ans[11][8] = 901995588;
        ans[11][9] = 2821056160L;
        ans[11][10] = 5924217936L;
        ans[11][12] = 1763160100L;
        ans[11][13] = 1014736800L;
        ans[11][14] = 96243664L;
        ans[11][15] = 527663136L;
        ans[11][17] = 1152008;
        ans[11][18] = 27986506;
        ans[11][19] = 835384;
        ans[12][1] = 143;
        ans[12][2] = 5915;
        ans[12][3] = 124215;
        ans[12][4] = 1656200;
        ans[12][5] = 15767024;
        ans[12][6] = 114874032;
        ans[12][7] = 668144880;
        ans[12][8] = 3173688180L;
        ans[12][9] = 12342120700L;
        ans[12][10] = 38013731756L;
        ans[12][11] = 79483257308L;
        ans[12][13] = 334424;
        ans[12][14] = 86230664;
        ans[12][15] = 401457992;
        ans[12][16] = 1811255769L;
        ans[12][17] = 8782619185L;
        ans[12][18] = 524739891;
        ans[13][1] = 168;
        ans[13][2] = 8085;
        ans[13][3] = 196000;
        ans[13][4] = 2998800;
        ans[13][5] = 32626944;
        ans[13][6] = 271211472;
        ans[13][7] = 1802805120L;
        ans[13][8] = 9859090500L;
        ans[13][9] = 44986664800L;
        ans[13][10] = 170724392916L;
        ans[13][11] = 519227905728L;
        ans[13][12] = 1081724803600L;
        ans[13][14] = 5856160;
        ans[13][16] = 208030461065L;
        ans[13][17] = 743483832;
        ans[14][1] = 195;
        ans[14][2] = 10800;
        ans[14][3] = 299200;
        ans[14][4] = 5202000;
        ans[14][5] = 64047024;
        ans[14][6] = 600935040;
        ans[14][7] = 4507012800L;
        ans[14][8] = 27887141700L;
        ans[14][9] = 145173803500L;
        ans[14][10] = 641087516256L;
        ans[14][11] = 2384209771200L;
        ans[14][12] = 7174705330000L;
        ans[14][13] = 14901311070000L;
        ans[14][15] = 262032716400L;
        ans[14][16] = 2131715333625L;
        ans[15][1] = 224;
        ans[15][2] = 14144;
        ans[15][3] = 443904;
        ans[15][4] = 8697744;
        ans[15][5] = 120187008;
        ans[15][6] = 1261963584;
        ans[15][7] = 10576456704L;
        ans[15][8] = 73167596964L;
        ans[15][9] = 427391677504L;
        ans[15][10] = 2136958387520L;
        ans[15][11] = 9183622822400L;
        ans[15][12] = 33577620944400L;
        ans[15][13] = 100136810390400L;
        ans[15][14] = 207426250094400L;
        ans[16][1] = 255;
        ans[16][2] = 18207;
        ans[16][3] = 642447;
        ans[16][4] = 14084415;
        ans[16][5] = 216899991;
        ans[16][6] = 2530499895L;
        ans[16][7] = 23518156167L;
        ans[16][8] = 180305863947L;
        ans[16][9] = 1168649118175L;
        ans[16][10] = 6511045086975L;
        ans[16][11] = 31479019635375L;
        ans[16][12] = 132211882468575L;
        ans[16][13] = 476432168185575L;
        ans[17][1] = 288;
        ans[17][2] = 23085;
        ans[17][3] = 909720;
        ans[17][4] = 22174425;
        ans[17][5] = 378261576;
        ans[17][6] = 4873620213L;
        ans[17][7] = 49911657840L;
        ans[17][8] = 421129613025L;
        ans[17][9] = 3003942370000L;
        ans[17][10] = 18451716007725L;
        ans[17][11] = 98815801429800L;
        ans[18][1] = 323;
        ans[18][2] = 28880;
        ans[18][3] = 1263500;
        ans[18][4] = 34051325;
        ans[18][5] = 639970331;
        ans[18][6] = 9058041608L;
        ans[18][7] = 101671895600L;
        ans[18][8] = 938731990625L;
        ans[18][9] = 7322109526875L;
        ans[18][10] = 49204576020600L;
        ans[18][11] = 288924390600300L;
        ans[19][1] = 360;
        ans[19][2] = 35700;
        ans[19][3] = 1724800;
        ans[19][4] = 51137625;
        ans[19][5] = 1053844176;
        ans[19][6] = 16309493200L;
        ans[19][7] = 199708080000L;
        ans[19][8] = 2008002335625L;
        ans[19][9] = 17037595575000L;
        ans[19][10] = 124510748462100L;
        ans[19][11] = 795771174744000L;
        ans[20][1] = 399;
        ans[20][2] = 43659;
        ans[20][3] = 2318239;
        ans[20][4] = 75274584;
        ans[20][5] = 1693678140;
        ans[20][6] = 28541613100L;
        ans[20][7] = 379694987100L;
        ans[20][8] = 4140135724725L;
        ans[20][9] = 38044950918975L;
        ans[20][10] = 300900975450075L;

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

        for (int x = 0; x <= n; x++) {
            for (int y = 0; y <= n; y++) {
                dp[x][y] = new HashMap<>();
                bp[x][y] = new HashMap<>();
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
                        int area2 = entry.getKey() + (int) (totalarea[n][y + 1] - totalarea[n][y]);
                        if (area2 > m2) continue;
                        dp[x][y + 1].put(entry.getKey(), dp[x][y + 1].getOrDefault(entry.getKey(), 0L) + entry.getValue());
                    }
                }
                if (x + y + 1 <= 2 * n - d && str.charAt(n - x + n - y - 1) != 'B') {
                    for (Map.Entry<Integer, Long> entry : bp[x][y].entrySet()) {
                        if (entry.getKey() > m2) continue;
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
}

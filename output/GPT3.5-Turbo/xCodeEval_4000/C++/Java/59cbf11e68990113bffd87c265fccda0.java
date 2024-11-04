import java.util.*;

public class 59cbf11e68990113bffd87c265fccda0_nc {
    
    static final int maxn1 = 31;
    static final int maxn2 = 100;
    static final int maxn3 = (1 << 20) + 10;
    static final long inf = 1_000_000_000_000_000_000L;
    
    static long[][] C = new long[maxn2][maxn2];
    static int[] arr = new int[2 * maxn1];
    static int A, B, n, N;
    static int pa1, pb1;
    static long pre1;
    static long[][] opt = new long[maxn1][maxn1];
    static long[][] vec = new long[maxn1][maxn3];
    static long[] pt = new long[maxn1];
    
    static void do_save(int l, int r) {
        Arrays.fill(pt, 0);
        int MSKA = 0, MSKB = 0, SZ = r - l;
        for (int i = l; i < r; i++) {
            if (arr[i] == 1) MSKA += (1 << (i - l));
            if (arr[i] == -1) MSKB += (1 << (i - l));
        }
        for (int msk = 0; msk < (1 << SZ); msk++) {
            if ((MSKA & msk) != MSKA || (MSKB & msk) != 0 || pa1 + Integer.bitCount(msk) >= maxn1) continue;
            int cnta = pa1, cntb = pb1;
            long num = pre1;
            for (int i = 0; i < SZ; i++) {
                if (((msk >> i) & 1) == 1)
                    num += C[cnta][A - 1] * C[cntb][A];
                else
                    num -= C[cnta][A] * C[cntb][A - 1];
                if (((msk >> i) & 1) == 1)
                    cnta++;
                else
                    cntb++;
            }
            vec[cnta][(int) pt[cnta]++] = num;
        }
        for (int i = 0; i < maxn1; i++) {
            Arrays.sort(vec[i], 0, (int) pt[i]);
        }
    }
    
    static long[] do_calc(int l, int r) {
        int MSKA = 0, MSKB = 0, SZ = r - l;
        long[] ans = {inf, 0};
        for (int i = l; i < r; i++) {
            if (arr[i] == 1) MSKA += (1 << (i - l));
            if (arr[i] == -1) MSKB += (1 << (i - l));
        }
        for (int msk = 0; msk < (1 << SZ); msk++) {
            int pp = Integer.bitCount(msk);
            int cnta = n - pp, cntb = l - cnta, start = cnta;
            long num = 0;
            if (cnta < 0 || cntb < 0 || (MSKA & msk) != MSKA || (MSKB & msk) != 0) continue;
            for (int i = 0; i < SZ; i++) {
                if (((msk >> i) & 1) == 1)
                    num += C[cnta][A - 1] * C[cntb][A];
                else
                    num -= C[cnta][A] * C[cntb][A - 1];
                if (((msk >> i) & 1) == 1)
                    cnta++;
                else
                    cntb++;
            }
            int idx = Arrays.binarySearch(vec[start], 0, (int) pt[start], -num);
            long[] cand1 = {inf, 0}, cand2 = {inf, 0};
            if (idx >= 0) {
                long x = vec[start][idx];
                cand1[0] = num + x;
                cand1[1] = Arrays.binarySearch(vec[start], 0, (int) pt[start], x) - idx;
            }
            if (idx < 0) {
                idx = -idx - 1;
                if (idx > 0) {
                    long x = vec[start][idx - 1];
                    cand2[0] = -num - x;
                    cand2[1] = idx - Arrays.binarySearch(vec[start], 0, (int) pt[start], x);
                }
            }
            if (cand1[0] < ans[0]) ans[0] = cand1[0];
            if (cand2[0] < ans[0]) ans[0] = cand2[0];
            if (cand1[0] == ans[0]) ans[1] += cand1[1];
            if (cand2[0] == ans[0]) ans[1] += cand2[1];
        }
        return ans;
    }
    
    static long[] solve() {
        long[] ans = {inf, 0};
        int Ca = 0, Cb = 0;
        for (int start = 0; start < N; start++) {
            int mid = (start + 1 + N) >> 1;
            if (Ca < A && arr[start] != -1 && Ca + start + 1 >= A && start >= 2 * A - 1) {
                pa1 = A;
                pb1 = start + 1 - A;
                pre1 = C[pb1][A];
                do_save(start + 1, mid);
                long[] p = do_calc(mid, N);
                if (p[0] < ans[0]) ans[0] = p[0];
                if (p[0] == ans[0]) ans[1] += C[start - Ca - Cb][A - 1 - Ca] * p[1];
            }
            if (Cb < A && arr[start] != 1 && Cb + start + 1 >= A && start >= 2 * A - 1) {
                pb1 = A;
                pa1 = start + 1 - A;
                pre1 = -C[pa1][A];
                do_save(start + 1, mid);
                long[] p = do_calc(mid, N);
                if (p[0] < ans[0]) ans[0] = p[0];
                if (p[0] == ans[0]) ans[1] += C[start - Ca - Cb][A - 1 - Cb] * p[1];
            }
            Ca += arr[start] == 1 ? 1 : 0;
            Cb += arr[start] == -1 ? 1 : 0;
        }
        return ans;
    }
    
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        opt[1][1] = 0;
        opt[1][2] = 1;
        opt[1][3] = 0;
        opt[1][4] = 1;
        opt[1][5] = 0;
        opt[1][6] = 1;
        opt[1][7] = 0;
        opt[1][8] = 1;
        opt[1][9] = 0;
        opt[1][10] = 1;
        opt[1][11] = 0;
        opt[1][12] = 1;
        opt[1][13] = 0;
        opt[1][14] = 1;
        opt[1][15] = 0;
        opt[1][16] = 1;
        opt[1][17] = 0;
        opt[1][18] = 1;
        opt[1][19] = 0;
        opt[1][20] = 1;
        opt[2][1] = 3;
        opt[2][2] = 0;
        opt[2][3] = 2;
        opt[2][4] = 3;
        opt[2][5] = 1;
        opt[2][6] = 0;
        opt[2][7] = 0;
        opt[2][8] = 1;
        opt[2][9] = 1;
        opt[2][10] = 0;
        opt[2][11] = 0;
        opt[2][12] = 1;
        opt[2][13] = 1;
        opt[2][14] = 0;
        opt[2][15] = 0;
        opt[2][16] = 1;
        opt[2][17] = 1;
        opt[2][18] = 0;
        opt[2][19] = 0;
        opt[2][20] = 1;
        opt[3][1] = 8;
        opt[3][2] = 20;
        opt[3][3] = 0;
        opt[3][4] = 15;
        opt[3][5] = 16;
        opt[3][6] = 0;
        opt[3][7] = 0;
        opt[3][8] = 1;
        opt[3][9] = 0;
        opt[3][10] = 0;
        opt[3][11] = 0;
        opt[3][12] = 1;
        opt[3][13] = 0;
        opt[3][14] = 0;
        opt[3][15] = 0;
        opt[3][16] = 1;
        opt[3][17] = 0;
        opt[3][18] = 0;
        opt[3][19] = 0;
        opt[3][20] = 1;
        opt[4][1] = 15;
        opt[4][2] = 75;
        opt[4][3] = 175;
        opt[4][4] = 0;
        opt[4][5] = 4;
        opt[4][6] = 0;
        opt[4][7] = 0;
        opt[4][8] = 45;
        opt[4][9] = 15;
        opt[4][10] = 1;
        opt[4][11] = 1;
        opt[4][12] = 0;
        opt[4][13] = 0;
        opt[4][14] = 0;
        opt[4][15] = 0;
        opt[4][16] = 1;
        opt[4][17] = 1;
        opt[4][18] = 1;
        opt[4][19] = 1;
        opt[4][20] = 0;
        opt[5][1] = 24;
        opt[5][2] = 189;
        opt[5][3] = 784;
        opt[5][4] = 1764;
        opt[5][5] = 0;
        opt[5][6] = 0;
        opt[5][7] = 60;
        opt[5][8] = 95;
        opt[5][9] = 200;
        opt[5][10] = 1;
        opt[5][11] = 14;
        opt[5][12] = 14;
        opt[5][13] = 0;
        opt[5][14] = 4;
        opt[5][15] = 0;
        opt[5][16] = 1;
        opt[5][17] = 0;
        opt[5][18] = 1;
        opt[5][19] = 0;
        opt[5][20] = 0;
        opt[6][1] = 35;
        opt[6][2] = 392;
        opt[6][3] = 2352;
        opt[6][4] = 8820;
        opt[6][5] = 19404;
        opt[6][6] = 0;
        opt[6][7] = 6600;
        opt[6][8] = 553;
        opt[6][9] = 245;
        opt[6][10] = 10780;
        opt[6][11] = 658;
        opt[6][12] = 126;
        opt[6][13] = 56;
        opt[6][14] = 20;
        opt[6][15] = 0;
        opt[6][16] = 5;
        opt[6][17] = 5;
        opt[6][18] = 0;
        opt[6][19] = 0;
        opt[6][20] = 0;
        opt[7][1] = 48;
        opt[7][2] = 720;
        opt[7][3] = 5760;
        opt[7][4] = 29700;
        opt[7][5] = 104544;
        opt[7][6] = 226512;
        opt[7][7] = 0;
        opt[7][8] = 15015;
        opt[7][9] = 40040;
        opt[7][10] = 0;
        opt[7][11] = 1440;
        opt[7][12] = 2028;
        opt[7][13] = 432;
        opt[7][14] = 1280;
        opt[7][15] = 8;
        opt[7][16] = 249;
        opt[7][17] = 8;
        opt[7][18] = 20;
        opt[7][19] = 6;
        opt[7][20] = 4;
        opt[8][1] = 63;
        opt[8][2] = 1215;
        opt[8][3] = 12375;
        opt[8][4] = 81675;
        opt[8][5] = 382239;
        opt[8][6] = 1288287;
        opt[8][7] = 2760615;
        opt[8][8] = 0;
        opt[8][9] = 1635920;
        opt[8][10] = 198198;
        opt[8][11] = 534456;
        opt[8][12] = 4524;
        opt[8][13] = 1546;
        opt[8][14] = 111564;
        opt[8][15] = 4050;
        opt[8][16] = 621;
        opt[8][17] = 3069;
        opt[8][18] = 5;
        opt[8][19] = 43;
        opt[8][20] = 1;
        opt[9][1] = 80;
        opt[9][2] = 1925;
        opt[9][3] = 24200;
        opt[9][4] = 196625;
        opt[9][5] = 1145144;
        opt[9][6] = 5010005;
        opt[9][7] = 16359200;
        opt[9][8] = 34763300;
        opt[9][9] = 0;
        opt[9][10] = 34606;
        opt[9][11] = 701350;
        opt[9][12] = 6651840;
        opt[9][13] = 78298;
        opt[9][14] = 429418;
        opt[9][15] = 872494;
        opt[9][16] = 1615;
        opt[9][17] = 352;
        opt[9][18] = 1155;
        opt[9][19] = 8580;
        opt[9][20] = 145;
        opt[10][1] = 99;
        opt[10][2] = 2904;
        opt[10][3] = 44044;
        opt[10][4] = 429429;
        opt[10][5] = 3006003;
        opt[10][6] = 16032016;
        opt[10][7] = 66745536;
        opt[10][8] = 212751396;
        opt[10][9] = 449141836;
        opt[10][10] = 0;
        opt[10][11] = 11675872;
        opt[10][12] = 4900324;
        opt[10][13] = 980474;
        opt[10][14] = 120143080;
        opt[10][15] = 47159156;
        opt[10][16] = 380171;
        opt[10][17] = 35871;
        opt[10][18] = 2207348;
        opt[10][19] = 223498;
        opt[10][20] = 4875;
        opt[11][1] = 120;
        opt[11][2] = 4212;
        opt[11][3] = 75712;
        opt[11][4] = 869505;
        opt[11][5] = 7154784;
        opt[11][6] = 45048640;
        opt[11][7] = 225059328;
        opt[11][8] = 901995588;
        opt[11][9] = 2821056160L;
        opt[11][10] = 5924217936L;
        opt[11][11] = 0;
        opt[11][12] = 1763160100L;
        opt[11][13] = 1014736800L;
        opt[11][14] = 96243664;
        opt[11][15] = 527663136;
        opt[11][16] = 13024737;
        opt[11][17] = 1152008;
        opt[11][18] = 27986506;
        opt[11][19] = 835384;
        opt[12][1] = 143;
        opt[12][2] = 5915;
        opt[12][3] = 124215;
        opt[12][4] = 1656200;
        opt[12][5] = 15767024;
        opt[12][6] = 114874032;
        opt[12][7] = 668144880;
        opt[12][8] = 3173688180L;
        opt[12][9] = 12342120700L;
        opt[12][10] = 38013731756L;
        opt[12][11] = 79483257308L;
        opt[12][12] = 0;
        opt[12][13] = 334424;
        opt[12][14] = 86230664;
        opt[12][15] = 401457992;
        opt[12][16] = 1811255769;
        opt[12][17] = 8782619185L;
        opt[12][18] = 524739891;
        opt[13][1] = 168;
        opt[13][2] = 8085;
        opt[13][3] = 196000;
        opt[13][4] = 2998800;
        opt[13][5] = 32626944;
        opt[13][6] = 271211472;
        opt[13][7] = 1802805120L;
        opt[13][8] = 9859090500L;
        opt[13][9] = 44986664800L;
        opt[13][10] = 170724392916L;
        opt[13][11] = 519227905728L;
        opt[13][12] = 1081724803600L;
        opt[13][13] = 0;
        opt[13][14] = 5856160;
        opt[13][15] = 0;
        opt[13][16] = 208030461065L;
        opt[13][17] = 743483832;
        opt[14][1] = 195;
        opt[14][2] = 10800;
        opt[14][3] = 299200;
        opt[14][4] = 5202000;
        opt[14][5] = 64047024;
        opt[14][6] = 600935040;
        opt[14][7] = 4507012800L;
        opt[14][8] = 27887141700L;
        opt[14][9] = 145173803500L;
        opt[14][10] = 641087516256L;
        opt[14][11] = 2384209771200L;
        opt[14][12] = 7174705330000L;
        opt[14][13] = 14901311070000L;
        opt[14][14] = 0;
        opt[14][15] = 262032716400L;
        opt[14][16] = 2131715333625L;
        opt[15][1] = 224;
        opt[15][2] = 14144;
        opt[15][3] = 443904;
        opt[15][4] = 8697744;
        opt[15][5] = 120187008;
        opt[15][6] = 1261963584;
        opt[15][7] = 10576456704L;
        opt[15][8] = 73167596964L;
        opt[15][9] = 427391677504L;
        opt[15][10] = 2136958387520L;
        opt[15][11] = 9183622822400L;
        opt[15][12] = 33577620944400L;
        opt[15][13] = 100136810390400L;
        opt[15][14] = 207426250094400L;
        opt[15][15] = 0;
        opt[16][1] = 255;
        opt[16][2] = 18207;
        opt[16][3] = 642447;
        opt[16][4] = 14084415;
        opt[16][5] = 216899991;
        opt[16][6] = 2530499895L;
        opt[16][7] = 23518156167L;
        opt[16][8] = 180305863947L;
        opt[16][9] = 1168649118175L;
        opt[16][10] = 6511045086975L;
        opt[16][11] = 31479019635375L;
        opt[16][12] = 132211882468575L;
        opt[16][13] = 476432168185575L;
        opt[17][1] = 288;
        opt[17][2] = 23085;
        opt[17][3] = 909720;
        opt[17][4] = 22174425;
        opt[17][5] = 378261576;
        opt[17][6] = 4873620213L;
        opt[17][7] = 49911657840L;
        opt[17][8] = 421129613025L;
        opt[17][9] = 3003942370000L;
        opt[17][10] = 18451716007725L;
        opt[17][11] = 98815801429800L;
        opt[18][1] = 323;
        opt[18][2] = 28880;
        opt[18][3] = 1263500;
        opt[18][4] = 34051325;
        opt[18][5] = 639970331;
        opt[18][6] = 9058041608L;
        opt[18][7] = 101671895600L;
        opt[18][8] = 938731990625L;
        opt[18][9] = 7322109526875L;
        opt[18][10] = 49204576020600L;
        opt[18][11] = 288924390600300L;
        opt[19][1] = 360;
        opt[19][2] = 35700;
        opt[19][3] = 1724800;
        opt[19][4] = 51137625;
        opt[19][5] = 1053844176;
        opt[19][6] = 16309493200L;
        opt[19][7] = 199708080000L;
        opt[19][8] = 2008002335625L;
        opt[19][9] = 17037595575000L;
        opt[19][10] = 124510748462100L;
        opt[19][11] = 795771174744000L;
        opt[20][1] = 399;
        opt[20][2] = 43659;
        opt[20][3] = 2318239;
        opt[20][4] = 75274584;
        opt[20][5] = 1693678140;
        opt[20][6] = 28541613100L;
        opt[20][7] = 379694987100L;
        opt[20][8] = 4140135724725L;
        opt[20][9] = 38044950918975L;
        opt[20][10] = 300900975450075L;
        
        for (int i = 0; i < maxn2; i++) {
            C[i][i] = C[i][0] = 1;
            for (int j = 1; j < i; j++) {
                C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
            }
        }
        
        A = sc.nextInt();
        B = sc.nextInt();
        n = A + B;
        N = 2 * n;
        String s = sc.next();
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == 'A') arr[i] = 1;
            if (s.charAt(i) == 'B') arr[i] = -1;
        }
        long[] p = solve();
        System.out.println(p[0] == opt[A][B] ? p[1] : 0);
        
        sc.close();
    }
}

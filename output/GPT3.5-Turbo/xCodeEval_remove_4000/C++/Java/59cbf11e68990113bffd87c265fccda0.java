import java.util.*;

class Main {
    static final int id1 = 31;
    static final int id0 = 100;
    static final int id2 = (1 << 20) + 10;
    static final long inf = 1_000_000_000_000_000_000L;

    static long[][] C = new long[id0][id0];
    static int[] arr = new int[2 * id1];
    static int A, B, n, N;
    static int pa1, pb1;
    static long pre1;
    static long[][] vec = new long[id1][id2];
    static int[] pt = new int[id1];

    static void do_save(int l, int r) {
        Arrays.fill(pt, 0);
        int MSKA = 0, MSKB = 0, SZ = r - l;
        for (int i = l; i < r; i++) {
            if (arr[i] == 1)
                MSKA += (1 << (i - l));
            if (arr[i] == -1)
                MSKB += (1 << (i - l));
        }
        for (int msk = 0; msk < (1 << SZ); msk++) {
            if ((MSKA & msk) != MSKA || (MSKB & msk) != 0 || pa1 + Integer.bitCount(msk) >= id1)
                continue;
            int cnta = pa1, cntb = pb1;
            long num = pre1;
            for (int i = 0; i < SZ; i++) {
                if (bit(msk, i))
                    num += C[cnta][A - 1] * C[cntb][A];
                else
                    num -= C[cnta][A] * C[cntb][A - 1];
                if (bit(msk, i))
                    cnta++;
                else
                    cntb++;
            }
            vec[cnta][pt[cnta]++] = num;
        }
        for (int i = 0; i < id1; i++) {
            Arrays.sort(vec[i], 0, pt[i]);
        }
    }

    static long[] do_calc(int l, int r) {
        int MSKA = 0, MSKB = 0, SZ = r - l;
        long[] ans = { inf, 0 };
        for (int i = l; i < r; i++) {
            if (arr[i] == 1)
                MSKA += (1 << (i - l));
            if (arr[i] == -1)
                MSKB += (1 << (i - l));
        }
        for (int msk = 0; msk < (1 << SZ); msk++) {
            int pp = Integer.bitCount(msk);
            int cnta = n - pp, cntb = l - cnta, start = cnta;
            long num = 0;
            if (cnta < 0 || cntb < 0 || (MSKA & msk) != MSKA || (MSKB & msk) != 0)
                continue;
            for (int i = 0; i < SZ; i++) {
                if (bit(msk, i))
                    num += C[cnta][A - 1] * C[cntb][A];
                else
                    num -= C[cnta][A] * C[cntb][A - 1];
                if (bit(msk, i))
                    cnta++;
                else
                    cntb++;
            }
            int idx = Arrays.binarySearch(vec[start], 0, pt[start], -num);
            int cand1 = 0, cand2 = 0;
            if (idx >= 0) {
                long x = vec[start][idx];
                cand1 = (int) (num + x);
                cand2 = (int) (-num - x);
            } else {
                int insertionPoint = -(idx + 1);
                if (insertionPoint > 0) {
                    long x = vec[start][insertionPoint - 1];
                    cand2 = (int) (-num - x);
                }
                if (insertionPoint < pt[start]) {
                    long x = vec[start][insertionPoint];
                    cand1 = (int) (num + x);
                }
            }
            if (cand1 < ans[0])
                ans[0] = cand1;
            if (cand2 < ans[0])
                ans[0] = cand2;
            if (cand1 == ans[0])
                ans[1] += upperBound(vec[start], 0, pt[start], cand1) - lowerBound(vec[start], 0, pt[start], cand1);
            if (cand2 == ans[0])
                ans[1] += upperBound(vec[start], 0, pt[start], -cand2) - lowerBound(vec[start], 0, pt[start], -cand2);
        }
        return ans;
    }

    static long[][] solve() {
        long[][] ans = { { inf, 0 } };
        int Ca = 0, Cb = 0;
        for (int start = 0; start < N; start++) {
            int mid = (start + 1 + N) >> 1;
            if (Ca < A && arr[start] != -1 && Ca + start + 1 >= A && start >= 2 * A - 1) {
                pa1 = A;
                pb1 = start + 1 - A;
                pre1 = C[pb1][A];
                do_save(start + 1, mid);
                long[] p = do_calc(mid, N);
                if (p[0] < ans[0][0])
                    ans[0] = p;
                if (p[0] == ans[0][0])
                    ans[0][1] += C[start - Ca - Cb][A - 1 - Ca] * p[1];
            }
            if (Cb < A && arr[start] != 1 && Cb + start + 1 >= A && start >= 2 * A - 1) {
                pb1 = A;
                pa1 = start + 1 - A;
                pre1 = -C[pa1][A];
                do_save(start + 1, mid);
                long[] p = do_calc(mid, N);
                if (p[0] < ans[0][0])
                    ans[0] = p;
                if (p[0] == ans[0][0])
                    ans[0][1] += C[start - Ca - Cb][A - 1 - Cb] * p[1];
            }
            Ca += arr[start] == 1 ? 1 : 0;
            Cb += arr[start] == -1 ? 1 : 0;
        }
        return ans;
    }

    static int lowerBound(long[] arr, int fromIndex, int toIndex, long key) {
        int low = fromIndex, high = toIndex - 1;
        while (low <= high) {
            int mid = (low + high) >>> 1;
            long midVal = arr[mid];
            if (midVal < key)
                low = mid + 1;
            else
                high = mid - 1;
        }
        return low;
    }

    static int upperBound(long[] arr, int fromIndex, int toIndex, long key) {
        int low = fromIndex, high = toIndex - 1;
        while (low <= high) {
            int mid = (low + high) >>> 1;
            long midVal = arr[mid];
            if (midVal <= key)
                low = mid + 1;
            else
                high = mid - 1;
        }
        return low;
    }

    static boolean bit(int x, int i) {
        return (x & (1 << i)) != 0;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        A = sc.nextInt();
        B = sc.nextInt();
        n = A + B;
        N = 2 * n;
        String s = sc.next();
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == 'A')
                arr[i] = 1;
            if (s.charAt(i) == 'B')
                arr[i] = -1;
        }
        long[][] p = solve();
        System.out.println(p[0][0] == opt[A][B] ? p[0][1] : 0);
    }

    static long[][] opt = { { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
            { 3, 0, 2, 3, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1 },
            { 8, 20, 0, 15, 16, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1 },
            { 15, 75, 175, 0, 4, 0, 0, 45, 15, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, 0 },
            { 24, 189, 784, 1764, 0, 0, 60, 95, 200, 1, 14, 14, 0, 4, 0, 1, 0, 1, 0, 0 },
            { 35, 392, 2352, 8820, 19404, 0, 6600, 553, 245, 10780, 658, 126, 56, 20, 0, 5, 5, 0, 0, 0 },
            { 48, 720, 5760, 29700, 104544, 226512, 0, 15015, 40040, 0, 1440, 2028, 432, 1280, 8, 249, 8, 20, 6, 4 },
            { 63, 1215, 12375, 81675, 382239, 1288287, 2760615, 0, 1635920, 198198, 534456, 4524, 1546, 111564, 4050, 621, 3069, 5, 43, 1 },
            { 80, 1925, 24200, 196625, 1145144, 5010005, 16359200, 34763300, 0, 34606, 701350, 6651840, 78298, 429418, 872494, 1615, 352, 1155, 8580, 145 },
            { 99, 2904, 44044, 429429, 3006003, 16032016, 66745536, 212751396, 449141836, 0, 11675872, 4900324, 980474, 120143080, 47159156, 380171, 35871, 2207348, 223498, 4875 },
            { 120, 4212, 75712, 869505, 7154784, 45048640, 225059328, 901995588, 2821056160L, 5924217936L, 0, 1763160100L, 1014736800L, 96243664L, 527663136L, 13024737L, 1152008L, 27986506L, 835384L, 0 },
            { 143, 5915, 124215, 1656200, 15767024, 114874032, 668144880, 3173688180L, 12342120700L, 38013731756L, 79483257308L, 0, 334424L, 86230664L, 401457992L, 1811255769L, 8782619185L, 524739891L, 0, 0 },
            { 168, 8085, 196000, 2998800, 32626944, 271211472, 1802805120L, 9859090500L, 44986664800L, 170724392916L, 519227905728L, 1081724803600L, 0, 5856160L, 0, 208030461065L, 743483832L, 0, 0, 0 },
            { 195, 10800, 299200, 5202000, 64047024, 600935040L, 4507012800L, 27887141700L, 145173803500L, 641087516256L, 2384209771200L, 7174705330000L, 14901311070000L, 0, 262032716400L, 2131715333625L, 0, 0, 0, 0 },
            { 224, 14144, 443904, 8697744, 120187008L, 1261963584L, 10576456704L, 73167596964L, 427391677504L, 2136958387520L, 9183622822400L, 33577620944400L, 100136810390400L, 207426250094400L, 0, 0, 0, 0, 0, 0 },
            { 255, 18207, 642447, 14084415L, 216899991L, 2530499895L, 23518156167L, 180305863947L, 1168649118175L, 6511045086975L, 31479019635375L, 132211882468575L, 476432168185575L, 1409850293610375L, 0, 0, 0, 0, 0, 0 },
            { 288, 23085, 909720, 22174425L, 378261576L, 4873620213L, 49911657840L, 421129613025L, 3003942370000L, 18451716007725L, 98815801429800L, 464342770607625L, 1912322889603000L, 0, 0, 0, 0, 0, 0, 0 },
            { 323, 28880, 1263500, 34051325L, 639970331L, 9058041608L, 101671895600L, 938731990625L, 7322109526875L, 49204576020600L, 288924390600300L, 1496215594180125L, 0, 0, 262032716400L, 2131715333625L, 0, 0, 0, 0 },
            { 360, 35700, 1724800, 51137625L, 1053844176L, 16309493200L, 199708080000L, 2008002335625L, 17037595575000L, 124510748462100L, 795771174744000L, 0, 0, 262032716400L, 0, 208030461065L, 743483832L, 0, 0, 0 },
            { 399, 43659, 2318239, 75274584L, 1693678140L, 28541613100L, 379694987100L, 4140135724725L, 38044950918975L, 300900975450075L, 0, 0, 0, 0, 0, 2131715333625L, 0, 0, 0, 0 } };

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        A = sc.nextInt();
        B = sc.nextInt();
        n = A + B;
        N = 2 * n;
        String s = sc.next();
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == 'A')
                arr[i] = 1;
            if (s.charAt(i) == 'B')
                arr[i] = -1;
        }
        long[][] p = solve();
        System.out.println(p[0][0] == opt[A][B] ? p[0][1] : 0);
    }
}

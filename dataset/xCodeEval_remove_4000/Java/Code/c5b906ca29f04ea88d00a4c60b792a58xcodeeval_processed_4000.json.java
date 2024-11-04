import java.io.*;
import java.util.*;

public class Solution {


    static MyScanner sc;
    private static PrintWriter out;
    static long M = 1000000007;


    public static void main(String[] s) throws Exception {
        StringBuilder stringBuilder = new StringBuilder();


























































































        if (stringBuilder.length() == 0) {
            sc = new MyScanner(System.in);
        } else {
            sc = new MyScanner(new BufferedReader(new StringReader(stringBuilder.toString())));
        }

        out = new PrintWriter(new OutputStreamWriter(System.out));

        initData();
        solve();
        out.flush();
    }


    private static void initData() {
    }


    private static void solve() throws IOException {
        int n = sc.nextInt();
        int m = sc.nextInt();
        int k = sc.nextInt();
        int[][] data = new int[m][n];
        for (int l = 0; l < n; l++) {
            for (int l1 = 0; l1 < m; l1++) {
                data[l1][l] = sc.nextInt();
            }
        }
        int res1 = 0;
        int res2 = 0;

        for (int[] mm : data) {
            int st = 0;
            for (st = 0; st < n; st++) {
                if (mm[st] == 1) break;
            }
            if (st == mm.length) continue;
            int sum = 0;
            int min = st;
            for (int i = 0; i < k && i + st < mm.length; i++) {
                if (mm[i + st] == 1) {
                    sum++;
                }
            }
            int max = sum;
            for (int r = st + k; r < n; r++) {
                if (mm[r] == 1) {
                    sum++;
                }
                if (mm[r - k] == 1) {
                    sum--;
                }
                if (sum > max) {
                    max = sum;
                    min = r - k + 1;
                }
            }
            res1 += max;
            for (int l = 0; l < min; l++) {
                if (mm[l] == 1) {
                    res2++;
                }
            }

        }
        out.println(res1 + " " + res2);
    }

    private static void solve3() throws IOException {
        int n = sc.nextInt();
        int m = sc.nextInt();


        STree s1 = new STree(n, true);

        int[] mmm = new int[n - 1];


        String[] k = new String[n];
        for (int i = 0; i < n; i++) {
            k[i] = sc.next();
            s1.put(i, k[i].length());
            if (i > 0) {
                mmm[i - 1] = lcp(k[i], k[i - 1]);
            }
        }
        id0 id1 = new id0(mmm);

        for (int r = 0; r < m; r++) {
            int t = sc.nextInt();
            if (t == 1) {
                int ll = sc.nextInt() - 1;
                int rr = sc.nextInt() - 1;
                long v1 = s1.max(ll, rr);
                if (rr > ll) {
                    v1 = Math.max(id1.max(ll, rr), v1);
                }
                out.println(v1);
            } else {
                int p = sc.nextInt() - 1;
                String ttt = sc.next();
                k[p] = ttt;
                s1.put(p, ttt.length());
                if (p > 0) {
                    mmm[p - 1] = lcp(k[p], k[p - 1]);
                    id1.update(p - 1, mmm[p - 1]);
                }
                if (p < n - 1) {
                    mmm[p] = lcp(k[p], k[p + 1]);
                    id1.update(p, mmm[p]);
                }
            }
        }

    }


    public static class id0 {
        public int total, half, real;
        public int[][] vasc;
        public int[][] pasc;
        public int[][] vdesc;
        public int[][] pdesc;
        public long[] maxs;
        public int[] lens;

        

        public id0(int[] a) {
            real = a.length;
            total = Integer.highestOneBit(Math.max(real - 1, 1)) << 2;
            half = total >>> 1;
            vasc = new int[total][];
            pasc = new int[total][];
            vdesc = new int[total][];
            pdesc = new int[total][];
            maxs = new long[total];
            lens = new int[total];
            for (int i = 0; i < real; i++) {
                vasc[half + i] = new int[]{a[i]};
                pasc[half + i] = new int[]{0}; 

                vdesc[half + i] = new int[]{a[i]};
                pdesc[half + i] = new int[]{0}; 

                maxs[half + i] = a[i] * 2;
                lens[half + i] = 1;
            }
            for (int i = real; i < half; i++) {
                vasc[half + i] = new int[0];
                pasc[half + i] = new int[0];
                vdesc[half + i] = new int[0];
                pdesc[half + i] = new int[0];
                lens[half + i] = 0;
            }
            for (int i = half - 1; i >= 1; i--) {
                propagate(i);
            }
        }

        int[][] merge(int[] v1, int[] p1, int[] v2, int[] p2) {
            int[] rv = Arrays.copyOf(v2, v2.length + v1.length);
            int[] rp = Arrays.copyOf(p2, v2.length + v1.length);
            int p = v2.length;
            int last = p > 0 ? p2[p - 1] : -1;
            for (int i = 0; i < v1.length; i++) {
                if (p > 0 && rv[p - 1] <= v1[i]) {
                    rp[p - 1] = p2[p - 1] + p1[i] + 1;
                } else if (p == 0 || rv[p - 1] > v1[i]) {
                    rv[p] = v1[i];
                    rp[p++] = last + p1[i] + 1;
                }
            }
            return new int[][]{
                    Arrays.copyOf(rv, p),
                    Arrays.copyOf(rp, p)
            };
        }

        private void tr(Object... o) {
            System.out.println(Arrays.deepToString(o));
        }

        private void propagate(int i) {
            int[][] res = merge(vasc[2 * i], pasc[2 * i], vasc[2 * i + 1], pasc[2 * i + 1]);
            vasc[i] = res[0];
            pasc[i] = res[1];

            res = merge(vdesc[2 * i + 1], pdesc[2 * i + 1], vdesc[2 * i], pdesc[2 * i]);
            vdesc[i] = res[0];
            pdesc[i] = res[1];

            lens[i] = lens[2 * i] + lens[2 * i + 1];
            maxs[i] = Math.max(maxs[2 * i], maxs[2 * i + 1]);

            {
                int[] L = vasc[2 * i], R = vdesc[2 * i + 1];
                int[] LP = pasc[2 * i], RP = pdesc[2 * i + 1];
                int k = 0;
                for (int j = 0; j < L.length; j++) {
                    while (k < R.length && R[k] >= L[j]) {
                        k++;
                    }
                    if (k == 0) continue;
                    int right = RP[k - 1];
                    int left = LP[j];
                    long val = (long) (left + right + 3) * L[j];


                    maxs[i] = Math.max(maxs[i], val);
                }
            }
            {
                int[] R = vasc[2 * i], L = vdesc[2 * i + 1];
                int[] RP = pasc[2 * i], LP = pdesc[2 * i + 1];
                int k = 0;
                for (int j = 0; j < L.length; j++) {
                    while (k < R.length && R[k] >= L[j]) {
                        k++;
                    }
                    if (k == 0) continue;
                    int right = RP[k - 1];
                    int left = LP[j];
                    long val = (long) (left + right + 3) * L[j];
                    maxs[i] = Math.max(maxs[i], val);
                }
            }
        }

        public static int[] rev(int[] a) {
            int[] b = new int[a.length];
            for (int i = 0; i < a.length; i++) b[a.length - 1 - i] = a[i];
            return b;
        }


        public void update(int pos, int v) {
            vasc[half + pos][0] = v;
            vdesc[half + pos][0] = v;
            maxs[half + pos] = vasc[half + pos][0] * 2;
            for (int i = half + pos >>> 1; i >= 1; i >>>= 1) {
                propagate(i);
            }
        }

        public long max(int l, int r) {
            gmax = Long.MIN_VALUE;
            max(l, r, 0, half, 1);
            return gmax;
        }

        long gmax;

        private int[][] max(int l, int r, int cl, int cr, int cur) {
            if (l <= cl && cr <= r) {
                gmax = Math.max(gmax, maxs[cur]);
                return new int[][]{vasc[cur], pasc[cur], vdesc[cur], pdesc[cur]};
            } else {
                int mid = cl + cr >>> 1;
                int[][] LX = null, RX = null;
                if (cl < r && l < mid) {
                    LX = max(l, r, cl, mid, 2 * cur);
                }
                if (mid < r && l < cr) {
                    RX = max(l, r, mid, cr, 2 * cur + 1);
                }

                if (LX == null) return RX;
                if (RX == null) return LX;

                int[][] ret = new int[4][];
                int[][] res = merge(LX[0], LX[1], RX[0], RX[1]);
                ret[0] = res[0];
                ret[1] = res[1];

                res = merge(RX[2], RX[3], LX[2], LX[3]);
                ret[2] = res[0];
                ret[3] = res[1];

                {
                    int[] L = LX[0], R = RX[2];
                    int[] LP = LX[1], RP = RX[3];
                    int k = 0;
                    for (int j = 0; j < L.length; j++) {
                        while (k < R.length && R[k] >= L[j]) {
                            k++;
                        }
                        if (k == 0) continue;
                        int right = RP[k - 1];
                        int left = LP[j];
                        long val = (long) (left + right + 3) * L[j];


                        gmax = Math.max(gmax, val);
                    }
                }
                {
                    int[] R = LX[0], L = RX[2];
                    int[] RP = LX[1], LP = RX[3];
                    int k = 0;
                    for (int j = 0; j < L.length; j++) {
                        while (k < R.length && R[k] >= L[j]) {
                            k++;
                        }
                        if (k == 0) continue;
                        int right = RP[k - 1];
                        int left = LP[j];
                        long val = (long) (left + right + 3) * L[j];
                        gmax = Math.max(gmax, val);
                    }
                }
                return ret;
            }
        }
    }


    private static int lcp(String s, String s1) {
        int m = 0;
        for (int i = 0; i < Math.min(s.length(), s1.length()); i++) {
            if (s.charAt(i) != s1.charAt(i)) break;
            m++;
        }
        return m;
    }

    private static void solveT() throws IOException {
        int t = sc.nextInt();
        while (t-- > 0) {
            solve();
        }
    }


    private static long gcd(long l, long l1) {
        if (l > l1) return gcd(l1, l);
        if (l == 0) return l1;
        return gcd(l1 % l, l);
    }

    private static long pow(long a, long b, long m) {
        if (b == 0) return 1;
        if (b == 1) return a;
        long pp = pow(a, b / 2, m);
        pp *= pp;
        pp %= m;
        return (pp * (b % 2 == 0 ? 1 : a)) % m;
    }


    static class MyScanner {
        BufferedReader br;
        StringTokenizer st;

        MyScanner(BufferedReader br) {
            this.br = br;
        }

        public MyScanner(InputStream in) {
            this(new BufferedReader(new InputStreamReader(in)));
        }

        void findToken() {
            while (st == null || !st.hasMoreTokens()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
            }
        }

        String next() {
            findToken();
            return st.nextToken();
        }

        Integer[] nab(int n) {
            Integer[] k = new Integer[n];
            for (int i = 0; i < n; i++) {
                k[i] = sc.fi();
            }
            return k;
        }

        int[] na(int n) {
            int[] k = new int[n];
            for (int i = 0; i < n; i++) {
                k[i] = sc.fi();
            }
            return k;
        }

        long[] nl(int n) {
            long[] k = new long[n];
            for (int i = 0; i < n; i++) {
                k[i] = sc.nextLong();
            }
            return k;
        }

        int nextInt() {
            return Integer.parseInt(next());
        }

        int fi() {
            String t = next();
            int cur = 0;
            boolean n = t.charAt(0) == '-';
            for (int a = n ? 1 : 0; a < t.length(); a++) {
                cur = cur * 10 + t.charAt(a) - '0';
            }
            return n ? -cur : cur;
        }

        long nextLong() {
            return Long.parseLong(next());
        }

        double nextDouble() {
            return Double.parseDouble(next());
        }
    }

    private static final class STree {
        private final boolean maxt;
        int rs;
        int[] val1;
        int[] from1;
        int[] to1;
        int[] metric;

        public STree(int c, boolean maxt) {
            rs = c;
            this.maxt = maxt;
            int size = Integer.highestOneBit(c);
            if (size != c) {
                size <<= 1;
            }
            int rs = size << 1;
            val1 = new int[rs];
            from1 = new int[rs];
            metric = new int[rs];
            to1 = new int[rs];

            Arrays.fill(from1, Integer.MAX_VALUE);
            if (!maxt)
                Arrays.fill(metric, Integer.MAX_VALUE);
            for (int r = rs - 1; r > 1; r--) {
                if (r >= size) {
                    from1[r] = r - size;
                    to1[r] = r - size;
                }
                from1[r / 2] = Math.min(from1[r / 2], from1[r]);
                to1[r / 2] = Math.max(to1[r / 2], to1[r]);
            }
        }

        public STree(int c) {
            this(c, true);
        }

        public int max(int from, int to) {
            return max(1, from, to);
        }

        private int max(int cur, int from, int to) {
            if (cur >= val1.length) return 0;
            if (from <= from1[cur] && to1[cur] <= to) {
                return metric[cur];
            }
            if (from1[cur] > to || from > to1[cur]) {
                return 0;
            }
            cur <<= 1;
            return Math.max(max(cur, from, to), max(cur + 1, from, to));
        }


        public void put(int x, int val) {
            x += val1.length >> 1;
            val1[x] = val;
            metric[x] = val;
            id2(x);
        }


        private void id2(int cur) {
            while (cur > 1) {
                cur >>= 1;
                if (maxt) {
                    metric[cur] = Math.max(metric[cur << 1], metric[1 + (cur << 1)]);
                } else {
                    metric[cur] = Math.min(metric[cur << 1], metric[1 + (cur << 1)]);
                }

            }
        }

        public long x(int i) {
            return val1[i + val1.length >> 1];
        }
    }
}
import java.util.*;

class Main {
    static final int MOD = 1000000007;
    static final int INF = 0x7fffffff;
    static final double PI = Math.acos(-1.0);
    static final double EPS = 1e-6;
    static final double OO = 1e15;

    static class Pair<T1, T2> {
        T1 first;
        T2 second;

        Pair(T1 first, T2 second) {
            this.first = first;
            this.second = second;
        }
    }

    static class Triple<T1, T2, T3> {
        T1 first;
        T2 second;
        T3 third;

        Triple(T1 first, T2 second, T3 third) {
            this.first = first;
            this.second = second;
            this.third = third;
        }
    }

    static class Quad<T1, T2, T3, T4> {
        T1 first;
        T2 second;
        T3 third;
        T4 fourth;

        Quad(T1 first, T2 second, T3 third, T4 fourth) {
            this.first = first;
            this.second = second;
            this.third = third;
            this.fourth = fourth;
        }
    }

    static class FastScanner {
        BufferedReader br;
        StringTokenizer st;

        public FastScanner() {
            br = new BufferedReader(new InputStreamReader(System.in));
        }

        String next() {
            while (st == null || !st.hasMoreElements()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }

        int nextInt() {
            return Integer.parseInt(next());
        }

        long nextLong() {
            return Long.parseLong(next());
        }

        double nextDouble() {
            return Double.parseDouble(next());
        }

        String nextLine() {
            String str = "";
            try {
                str = br.readLine();
            } catch (IOException e) {
                e.printStackTrace();
            }
            return str;
        }
    }

    static FastScanner sc = new FastScanner();
    static PrintWriter out = new PrintWriter(System.out);

    static int[] dx = {1, -1, 0, 0};
    static int[] dy = {0, 0, 1, -1};

    static int gcd(int a, int b) {
        if (b == 0) return a;
        return gcd(b, a % b);
    }

    static long gcd(long a, long b) {
        if (b == 0) return a;
        return gcd(b, a % b);
    }

    static int pow(int a, int b) {
        int res = 1;
        while (b > 0) {
            if ((b & 1) != 0) res = res * a;
            a = a * a;
            b >>= 1;
        }
        return res;
    }

    static long pow(long a, long b) {
        long res = 1;
        while (b > 0) {
            if ((b & 1) != 0) res = res * a;
            a = a * a;
            b >>= 1;
        }
        return res;
    }

    static long powmod(long a, long b, long mod) {
        long res = 1;
        while (b > 0) {
            if ((b & 1) != 0) res = res * a % mod;
            a = a * a % mod;
            b >>= 1;
        }
        return res;
    }

    static int[] readArray(int n) {
        int[] a = new int[n];
        for (int i = 0; i < n; i++) a[i] = sc.nextInt();
        return a;
    }

    static long[] readLongArray(int n) {
        long[] a = new long[n];
        for (int i = 0; i < n; i++) a[i] = sc.nextLong();
        return a;
    }

    static double[] readDoubleArray(int n) {
        double[] a = new double[n];
        for (int i = 0; i < n; i++) a[i] = sc.nextDouble();
        return a;
    }

    static char[][] readCharGrid(int n, int m) {
        char[][] grid = new char[n][m];
        for (int i = 0; i < n; i++) grid[i] = sc.next().toCharArray();
        return grid;
    }

    static int[][] readIntArray2D(int n, int m) {
        int[][] a = new int[n][m];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) a[i][j] = sc.nextInt();
        }
        return a;
    }

    static long[][] readLongArray2D(int n, int m) {
        long[][] a = new long[n][m];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) a[i][j] = sc.nextLong();
        }
        return a;
    }

    static double[][] readDoubleArray2D(int n, int m) {
        double[][] a = new double[n][m];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) a[i][j] = sc.nextDouble();
        }
        return a;
    }

    static void solve() {
        List<Integer> A = new ArrayList<>();
        List<Integer> B = new ArrayList<>();
        long pl, pr, vl, vr, k;
        long cnt = 0;

        for (int i = 0; i <= 9; i++) {
            dfs(A, i, 0);
        }

        Collections.sort(A);
        A.add(INF);

        pl = sc.nextLong();
        pr = sc.nextLong();
        vl = sc.nextLong();
        vr = sc.nextLong();
        k = sc.nextLong();

        for (int i = 0; i <= A.size() - k; i++) {
            int l1 = A.get(i - 1) + 1;
            int r1 = A.get(i);
            int l2 = A.get(i + (int) k - 1);
            int r2 = A.get(i + (int) k) - 1;

            long d1 = I(l1, r1, pl, pr) * I(l2, r2, vl, vr);
            long d2 = I(l1, r1, vl, vr) * I(l2, r2, pl, pr);

            cnt += d1 + d2;
            if (d1 != 0 && d2 != 0 && k == 1) cnt--;
        }

        out.println((double) cnt / ((pr - pl + 1) * (vr - vl + 1)));
    }

    static void dfs(List<Integer> A, int k, int n) {
        A.add(n);
        if (k == 9) return;
        else {
            dfs(A, k + 1, n * 10 + 4);
            dfs(A, k + 1, n * 10 + 7);
        }
    }

    static long I(int l, int r, long l_, long r_) {
        l = Math.max(l, (int) l_);
        r = Math.min(r, (int) r_);
        return Math.max(0, r - l + 1);
    }

    public static void main(String[] args) {
        solve();
        out.close();
    }
}

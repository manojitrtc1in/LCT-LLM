import java.util.*;
import java.io.*;

class Main {
    static class Mint {
        private static final int mod = 998244353;
        private int value;

        public Mint() {
            this.value = 0;
        }

        public Mint(int x) {
            this.value = normalize(x);
        }

        private static int normalize(int x) {
            int v;
            if (-mod <= x && x < mod) {
                v = x;
            } else {
                v = x % mod;
            }
            if (v < 0) {
                v += mod;
            }
            return v;
        }

        public int getValue() {
            return value;
        }

        public Mint add(Mint other) {
            int newValue = normalize(value + other.getValue());
            return new Mint(newValue);
        }

        public Mint subtract(Mint other) {
            int newValue = normalize(value - other.getValue());
            return new Mint(newValue);
        }

        public Mint multiply(Mint other) {
            long x = (long) value * (long) other.getValue();
            int xh = (int) (x >> 32);
            int xl = (int) x;
            int d, m;
            asm("divl %4; \n\t" : "=a" (d), "=d" (m) : "d" (xh), "a" (xl), "r" (mod));
            int newValue = m;
            newValue = normalize((long) value * (long) other.getValue());
            return new Mint(newValue);
        }

        public Mint divide(Mint other) {
            return multiply(inverse(other.getValue(), mod));
        }

        private static int inverse(int a, int m) {
            int u = 0, v = 1;
            while (a != 0) {
                int t = m / a;
                m -= t * a;
                int temp = a;
                a = m;
                m = temp;
                u -= t * v;
                temp = u;
                u = v;
                v = temp;
            }
            assert m == 1;
            return u;
        }

        public static Mint power(Mint a, int b) {
            assert b >= 0;
            Mint x = a;
            Mint res = new Mint(1);
            int p = b;
            while (p > 0) {
                if ((p & 1) == 1) {
                    res = res.multiply(x);
                }
                x = x.multiply(x);
                p >>= 1;
            }
            return res;
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

    static int[][] seg = new int[maxn][2];
    static String s;
    static int it;

    static boolean can(int n) {
        if (n == 1) {
            return true;
        }
        int x = n / 2, y = (n + 1) / 2;
        if (!can(x) || !can(y)) {
            return false;
        }
        int a = 0, b = 0;
        while (it < s.length()) {
            if (s.charAt(it) == '0') {
                a++;
            } else {
                b++;
            }
            it++;
            if (a == x || b == y) {
                break;
            }
        }
        if (a != x && b != y) {
            return false;
        }
        return true;
    }

    static int[] id = new int[maxn];
    static int[] mas = new int[maxn];
    static int[] deg = new int[maxn];
    static List<Integer>[] e = new ArrayList[maxn];

    static void gen(int l, int r) {
        if (l == r) {
            return;
        }
        int m = (l + r - 1) / 2;
        gen(l, m);
        gen(m + 1, r);
        int a = l, b = m + 1, c = l;
        while (a <= m && b <= r) {
            if (s.charAt(it) == '0') {
                mas[c++] = id[a];
                a++;
            } else {
                mas[c++] = id[b];
                b++;
            }
            it++;
        }
        while (a <= m) {
            mas[c++] = id[a];
            a++;
        }
        while (b <= r) {
            mas[c++] = id[b];
            b++;
        }
        for (int i = l; i <= r; i++) {
            id[i] = mas[i];
            if (i > l) {
                e[id[i - 1]].add(id[i]);
            }
        }
    }

    static void go(int n) {
        it = 0;
        if (!can(n) || it != s.length()) {
            return;
        }

        it = 0;
        for (int i = 0; i < n; i++) {
            id[i] = i;
        }
        gen(0, n - 1);
        assert it == s.length();
        int[] p = new int[n];
        for (int i = 0; i < n; i++) {
            p[id[i]] = i;
        }
        System.out.println(n);
        for (int i : p) {
            System.out.print(i + 1 + " ");
        }
        System.out.println();
        System.exit(0);
    }

    static void solve() {
        for (int i = 2; i < maxn; i++) {
            int x = (i + 1) / 2, y = i - x;
            for (int t = 0; t < 2; t++) {
                seg[i][t] = seg[x][t] + seg[y][t];
            }
            seg[i][0] += x;
            seg[i][1] += y;
        }
        FastScanner sc = new FastScanner();
        s = sc.next();
        int[] counter = new int[2];
        for (char c : s.toCharArray()) {
            counter[c - '0']++;
        }
        for (int n = maxn - 1; n > 0; n--) {
            if (seg[n][0] >= counter[0] && seg[n][1] >= counter[1]) {
                go(n);
            }
        }
    }

    public static void main(String[] args) {
        solve();
    }
}

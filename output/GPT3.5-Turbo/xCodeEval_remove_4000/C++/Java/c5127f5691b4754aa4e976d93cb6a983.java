import java.util.*;
import java.io.*;

class Main {
    static class FastReader {
        BufferedReader br;
        StringTokenizer st;

        public FastReader() {
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

    static class Pair {
        int first, second;

        public Pair(int first, int second) {
            this.first = first;
            this.second = second;
        }
    }

    static class Modular<T> {
        public static final int mod = 998244353;
        private T value;

        public Modular() {
            value = null;
        }

        public Modular(T value) {
            this.value = value;
        }

        public T getValue() {
            return value;
        }

        public void setValue(T value) {
            this.value = value;
        }

        public static int normalize(int x) {
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

        public Modular<T> add(Modular<T> other) {
            int result = normalize((Integer)value + (Integer)other.getValue());
            return new Modular<>(result);
        }

        public Modular<T> subtract(Modular<T> other) {
            int result = normalize((Integer)value - (Integer)other.getValue());
            return new Modular<>(result);
        }

        public Modular<T> multiply(Modular<T> other) {
            int result = normalize((Integer)value * (Integer)other.getValue());
            return new Modular<>(result);
        }

        public Modular<T> divide(Modular<T> other) {
            int inverse = inverse((Integer)other.getValue(), mod);
            int result = normalize((Integer)value * inverse);
            return new Modular<>(result);
        }

        public int inverse(int a, int m) {
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
            assert(m == 1);
            return u;
        }
    }

    static int[] seg0, seg1;
    static Pair[] len;

    static boolean can(int n) {
        if (n == 1) {
            return true;
        }

        int x = n / 2, y = (n + 1) / 2;
        if (!can(x) || !can(y)) {
            return false;
        }
        int p0 = nxt[it][0], p1 = nxt[it][1];
        if (p0 == s.length() || ind[p0] + x - 1 >= o[0].size()) {
            p0 = s.length();
        } else {
            p0 = o[0].get(ind[p0] + x - 1);
        }
        if (p1 == s.length() || ind[p1] + y - 1 >= o[1].size()) {
            p1 = s.length();
        } else {
            p1 = o[1].get(ind[p1] + y - 1);
        }
        p0 = Math.min(p0, p1);
        if (p0 == s.length()) {
            return false;
        }
        it = p0 + 1;

        return true;
    }

    static int[] id, mas;

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
        }
    }

    static void go(int n, boolean cert) {
        it = 0;
        if (!cert) {
            if (can(n)) {
                System.out.println(n);
                for (int i = 0; i < n; i++) {
                    System.out.print(id[i] + 1 + " ");
                }
                System.out.println();
                System.exit(0);
            }
        } else {
            it = 0;
            can(n);
            assert(it == s.length());

            it = 0;
            id = new int[n];
            for (int i = 0; i < n; i++) {
                id[i] = i;
            }
            gen(0, n - 1);
            assert(it == s.length());
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
    }

    static int[][] seg;
    static Pair[] len;
    static ArrayList<Integer>[] o;
    static int[] ind;
    static int it;
    static int[][] nxt;

    public static void main(String[] args) {
        FastReader sc = new FastReader();

        int ts = 1;

        for (int its = 1; its <= ts; its++) {
            int maxn = 100010;
            seg0 = new int[maxn];
            seg1 = new int[maxn];
            len = new Pair[maxn];
            for (int i = 2; i < maxn; i++) {
                int x = i / 2, y = i - x;
                len[i] = new Pair(len[x].first + len[y].first + x, len[x].second + len[y].second + x + y - 1);
                seg0[i] = seg0[x] + seg0[y];
                seg1[i] = seg1[x] + seg1[y];
                seg0[i] += x;
                seg1[i] += y;
            }
            s = sc.next();
            int[] counter = new int[2];
            nxt = new int[s.length() + 1][2];
            ind = new int[s.length()];
            o = new ArrayList[2];
            o[0] = new ArrayList<>();
            o[1] = new ArrayList<>();
            for (int i = 0; i < s.length(); i++) {
                int c = s.charAt(i) - '0';
                counter[c]++;
                ind[i] = o[c].size();
                o[c].add(i);
            }
            nxt[s.length()][0] = nxt[s.length()][1] = s.length();
            for (int i = s.length() - 1; i >= 0; i--) {
                for (int t = 0; t < 2; t++) {
                    nxt[i][t] = nxt[i + 1][t];
                }
                nxt[i][s.charAt(i) - '0'] = i;
            }
            int l = 0, r = 100010;
            while (r - l > 1) {
                int m = (l + r) / 2;
                if (can(m)) {
                    l = m;
                } else {
                    r = m;
                }
            }
            go(l, true);
        }
    }
}

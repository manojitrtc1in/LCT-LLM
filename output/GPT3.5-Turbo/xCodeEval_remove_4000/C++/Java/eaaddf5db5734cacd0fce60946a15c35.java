import java.io.*;
import java.util.*;

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

    static class Field<N extends Number> {
        private int N;
        private int pow(int a, int p) {
            int r = 1, e = a;
            while (p != 0) {
                if ((p & 1) != 0) {
                    r = (int) (((long) r * e) % N);
                }
                e = (int) (((long) e * e) % N);
                p >>= 1;
            }
            return r;
        }

        private int inv(int a) {
            return pow(a, N - 2);
        }

        public Field(int N) {
            this.N = N;
        }

        public Field<N> pow(int p) {
            return new Field<>(pow(v, p));
        }

        public Field<N> add(Field<N> o) {
            int res = v + o.v;
            if (res >= N) {
                res -= N;
            }
            return new Field<>(res);
        }

        public Field<N> subtract(Field<N> o) {
            int res = v - o.v;
            if (res < 0) {
                res += N;
            }
            return new Field<>(res);
        }

        public Field<N> multiply(Field<N> o) {
            return new Field<>((int) (((long) v * o.v) % N));
        }

        public Field<N> divide(Field<N> o) {
            return multiply(new Field<>(inv(o.v)));
        }

        public Field<N> negate() {
            if (v != 0) {
                return new Field<>(N - v);
            } else {
                return new Field<>(0);
            }
        }

        public Field<N> increment() {
            v++;
            if (v == N) {
                v = 0;
            }
            return this;
        }

        public Field<N> decrement() {
            v--;
            if (v == -1) {
                v = N - 1;
            }
            return this;
        }

        public boolean equals(Field<N> o) {
            return o.v == v;
        }

        public boolean notEquals(Field<N> o) {
            return o.v != v;
        }

        public int toInt() {
            return v;
        }

        private int v;
    }

    static class Pair<T, U> {
        T first;
        U second;

        Pair(T first, U second) {
            this.first = first;
            this.second = second;
        }
    }

    static class Triple<T, U, V> {
        T first;
        U second;
        V third;

        Triple(T first, U second, V third) {
            this.first = first;
            this.second = second;
            this.third = third;
        }
    }

    static final int MOD = 1000000007;
    static final int MAXN = 200200;

    static int[] st = new int[MAXN];
    static int[] p = new int[MAXN];
    static int[] f = new int[MAXN];

    static StringBuilder s = new StringBuilder();
    static StringBuilder t = new StringBuilder();

    static Field<MOD> p1 = new Field<>(7);
    static Field<MOD> p2 = new Field<>(13);

    static Field<MOD>[] h1 = new Field[MAXN];
    static Field<MOD>[] h2 = new Field[MAXN];

    static void buildHash() {
        Field<MOD> cp1 = p1;
        h1[0] = new Field<>(t.charAt(0));
        for (int i = 1; i < t.length(); i++) {
            h1[i] = h1[i - 1].add(new Field<>(t.charAt(i)).multiply(cp1));
            cp1 = cp1.multiply(p1);
        }

        Field<MOD> cp2 = p2;
        h2[0] = new Field<>(t.charAt(0));
        for (int i = 1; i < t.length(); i++) {
            h2[i] = h2[i - 1].add(new Field<>(t.charAt(i)).multiply(cp2));
            cp2 = cp2.multiply(p2);
        }
    }

    static Pair<Pair<Field<MOD>, Field<MOD>>, Integer> getH(int l, int r) {
        if (l + f[l] - 1 >= r) {
            return new Pair<>(new Pair<>(new Field<>(-1), new Field<>(-1)), -1);
        }

        int b = st[l + f[l]];
        int e = st[r - p[r]];

        int len = e - b + 1;

        Field<MOD> hm1 = h1[e].subtract(h1[b - 1]).divide(p1.pow(b));
        if (p[r] % 2 == 1) {
            len++;
            hm1 = hm1.add(p1.pow(e - b + 1));
        }

        if (f[l] % 2 == 1) {
            len++;
            hm1 = new Field<>(1).add(hm1.multiply(p1));
        }

        Field<MOD> hm2 = h2[e].subtract(h2[b - 1]).divide(p2.pow(b));
        if (p[r] % 2 == 1) {
            hm2 = hm2.add(p2.pow(e - b + 1));
        }

        if (f[l] % 2 == 1) {
            hm2 = new Field<>(1).add(hm2.multiply(p2));
        }

        return new Pair<>(new Pair<>(hm1, hm2), len);
    }

    static String getSubstring(int l, int r) {
        if (l + f[l] - 1 >= r) {
            return "-1";
        }

        int b = st[l + f[l]];
        int e = st[r - p[r]];

        StringBuilder ans = new StringBuilder(t.substring(b, e + 1));
        if (p[r] % 2 == 1) {
            ans.append("1");
        }
        if (f[l] % 2 == 1) {
            ans.insert(0, "1");
        }
        return ans.toString();
    }

    public static void main(String[] args) {
        FastReader in = new FastReader();
        PrintWriter out = new PrintWriter(System.out);

        int n = in.nextInt();
        s.append(in.next());
        n = s.length();

        s.insert(0, '0');
        s.append('0');

        int tLen = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == '1' && s.charAt(i + 1) == '1') {
                i++;
                continue;
            }

            t.append(s.charAt(i));
            st[i] = tLen++;
        }

        p[0] = 0;
        if (s.charAt(0) == '1') {
            p[0] = 1;
        }

        for (int i = 1; i < s.length(); i++) {
            if (s.charAt(i) == '0') {
                p[i] = 0;
            } else {
                p[i] = p[i - 1] + 1;
            }
        }

        f[s.length() - 1] = 0;
        for (int i = s.length() - 2; i >= 0; i--) {
            if (s.charAt(i) == '0') {
                f[i] = 0;
            } else {
                f[i] = f[i + 1] + 1;
            }
        }

        buildHash();

        int q = in.nextInt();
        for (int i = 0; i < q; i++) {
            int a = in.nextInt();
            int b = in.nextInt();
            int c = in.nextInt();

            if (getH(a, a + c - 1).equals(getH(b, b + c - 1))) {
                out.println("Yes");
            } else {
                out.println("No");
            }
        }

        out.flush();
    }
}

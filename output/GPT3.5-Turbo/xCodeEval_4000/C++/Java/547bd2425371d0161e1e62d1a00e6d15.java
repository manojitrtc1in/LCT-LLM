import java.util.*;
import java.io.*;
import java.math.BigInteger;

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

    static class IoSetup {
        IoSetup() {
            FastReader in = new FastReader();
            PrintWriter out = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
        }
    }

    static class ModInt {
        static final int mod = 998244353;
        static final long infll = (1L << 62) - 1;
        static final int inf = (1 << 30) - 1;

        long x;

        ModInt() {
            x = 0;
        }

        ModInt(long x) {
            this.x = reduce(x);
        }

        long reduce(long w) {
            return (w >> 32) + mod - ((u64(u32(w) * inv) * mod) >> 32);
        }

        ModInt add(ModInt p) {
            if (x += p.x - 2 * mod < 0) x += 2 * mod;
            return this;
        }

        ModInt subtract(ModInt p) {
            if (x -= p.x < 0) x += 2 * mod;
            return this;
        }

        ModInt multiply(ModInt p) {
            x = reduce(x * p.x);
            return this;
        }

        ModInt divide(ModInt p) {
            multiply(p.inverse());
            return this;
        }

        ModInt add(ModInt p) {
            return new ModInt(x + p.x);
        }

        ModInt subtract(ModInt p) {
            return new ModInt(x - p.x);
        }

        ModInt multiply(ModInt p) {
            return new ModInt(x * p.x);
        }

        ModInt divide(ModInt p) {
            return new ModInt(x * p.inverse().x);
        }

        boolean equals(ModInt p) {
            return x == p.x;
        }

        boolean notEquals(ModInt p) {
            return x != p.x;
        }

        boolean lessThan(ModInt p) {
            return x < p.x;
        }

        boolean greaterThan(ModInt p) {
            return x > p.x;
        }

        boolean lessThanOrEqual(ModInt p) {
            return x <= p.x;
        }

        boolean greaterThanOrEqual(ModInt p) {
            return x >= p.x;
        }

        int get() {
            return reduce(x) % mod;
        }

        ModInt pow(long n) {
            ModInt ret = new ModInt(1);
            ModInt mul = new ModInt(x);
            while (n > 0) {
                if ((n & 1) == 1) ret.multiply(mul);
                mul.multiply(mul);
                n >>= 1;
            }
            return ret;
        }

        ModInt inverse() {
            return pow(mod - 2);
        }

        static int get_mod() {
            return mod;
        }
    }

    static class Fraction<T> {
        T num, dom;

        Fraction() {}

        Fraction(T n, T d) {
            num = n;
            dom = d;
            assert dom != 0;
            if (dom < 0) {
                num *= -1;
                dom *= -1;
            }
            T tmp = __gcd(abs(num), abs(dom));
            num /= tmp;
            dom /= tmp;
        }

        Fraction add(Fraction a) {
            return new Fraction(num * a.dom + a.num * dom, dom * a.dom);
        }

        Fraction subtract(Fraction a) {
            return new Fraction(num * a.dom - a.num * dom, dom * a.dom);
        }

        Fraction multiply(Fraction a) {
            return new Fraction(num * a.num, dom * a.dom);
        }

        Fraction divide(Fraction a) {
            return new Fraction(num * a.dom, dom * a.num);
        }

        Fraction multiply(T k) {
            return new Fraction(num * k, dom);
        }

        Fraction divide(T k) {
            return new Fraction(num, dom * k);
        }

        boolean lessThan(Fraction a) {
            return num * a.dom < a.num * dom;
        }

        boolean greaterThan(Fraction a) {
            return num * a.dom > a.num * dom;
        }

        boolean equals(Fraction a) {
            return num * a.dom == a.num * dom;
        }

        boolean notEquals(Fraction a) {
            return num * a.dom != a.num * dom;
        }

        boolean lessThanOrEqual(Fraction a) {
            return num * a.dom <= a.num * dom;
        }

        boolean greaterThanOrEqual(Fraction a) {
            return num * a.dom >= a.num * dom;
        }
    }

    static class Matrix<T> {
        ArrayList<ArrayList<T>> A;

        Matrix() {}

        Matrix(int n) {
            A = new ArrayList<>();
            for (int i = 0; i < n; i++) {
                A.add(new ArrayList<>());
                for (int j = 0; j < n; j++) {
                    A.get(i).add(null);
                }
            }
        }

        int height() {
            return A.size();
        }

        int width() {
            return A.get(0).size();
        }

        ArrayList<T> get(int k) {
            return A.get(k);
        }

        void set(int k, ArrayList<T> x) {
            A.set(k, x);
        }

        static Matrix I(int n) {
            Matrix mat = new Matrix(n);
            for (int i = 0; i < n; i++) {
                mat.get(i).set(i, 1);
            }
            return mat;
        }

        Matrix add(Matrix B) {
            int n = height(), m = width();
            assert (n == B.height() && m == B.width());
            Matrix C = new Matrix(n);
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    C.get(i).set(j, A.get(i).get(j) + B.get(i).get(j));
                }
            }
            return C;
        }

        Matrix subtract(Matrix B) {
            int n = height(), m = width();
            assert (n == B.height() && m == B.width());
            Matrix C = new Matrix(n);
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    C.get(i).set(j, A.get(i).get(j) - B.get(i).get(j));
                }
            }
            return C;
        }

        Matrix multiply(Matrix B) {
            int n = height(), m = B.width(), p = width();
            assert (p == B.height());
            Matrix C = new Matrix(n);
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    for (int k = 0; k < p; k++) {
                        C.get(i).set(j, C.get(i).get(j) + A.get(i).get(k) * B.get(k).get(j));
                    }
                }
            }
            return C;
        }

        Matrix power(long k) {
            Matrix B = Matrix.I(height());
            while (k > 0) {
                if ((k & 1) == 1) B.multiply(this);
                multiply(this);
                k >>= 1;
            }
            return B;
        }

        long determinant() {
            Matrix B = new Matrix(this);
            assert (width() == height());
            long ret = 1;
            for (int i = 0; i < width(); i++) {
                int idx = -1;
                for (int j = i; j < width(); j++) {
                    if (B.get(j).get(i) != 0) idx = j;
                }
                if (idx == -1) return 0;
                if (i != idx) {
                    ret *= -1;
                    Collections.swap(B.A, i, idx);
                }
                ret *= B.get(i).get(i);
                long vv = B.get(i).get(i);
                for (int j = 0; j < width(); j++) {
                    B.get(i).set(j, B.get(i).get(j) / vv);
                }
                for (int j = i + 1; j < width(); j++) {
                    long a = B.get(j).get(i);
                    for (int k = 0; k < width(); k++) {
                        B.get(j).set(k, B.get(j).get(k) - B.get(i).get(k) * a);
                    }
                }
            }
            return ret;
        }
    }

    static int N;
    static int[] X, V;
    static ModInt[] P, Q;
    static Map<Fraction<Long>, ArrayList<Node>> ev;
    static Matrix<ModInt> e;
    static SegmentTree<Matrix<ModInt>> seg;

    static class Node {
        int right, type;

        Node(int right, int type) {
            this.right = right;
            this.type = type;
        }
    }

    static class SegmentTree<T> {
        int sz;
        ArrayList<T> seg;
        BiFunction<T, T, T> f;
        T M1;

        SegmentTree(int n, BiFunction<T, T, T> f, T M1) {
            this.f = f;
            this.M1 = M1;
            sz = 1;
            while (sz < n) sz <<= 1;
            seg = new ArrayList<>(2 * sz);
            for (int i = 0; i < 2 * sz; i++) {
                seg.add(M1);
            }
        }

        void set(int k, T x) {
            seg.set(k + sz, x);
        }

        void build() {
            for (int k = sz - 1; k > 0; k--) {
                seg.set(k, f.apply(seg.get(2 * k + 0), seg.get(2 * k + 1)));
            }
        }

        void update(int k, T x) {
            k += sz;
            seg.set(k, x);
            while ((k >>= 1) > 0) {
                seg.set(k, f.apply(seg.get(2 * k + 0), seg.get(2 * k + 1)));
            }
        }

        T query(int a, int b) {
            T L = M1, R = M1;
            for (a += sz, b += sz; a < b; a >>= 1, b >>= 1) {
                if ((a & 1) == 1) L = f.apply(L, seg.get(a++));
                if ((b & 1) == 1) R = f.apply(seg.get(--b), R);
            }
            return f.apply(L, R);
        }

        T get(int k) {
            return seg.get(k + sz);
        }

        int findSubtree(int a, Predicate<T> check, T M, boolean type) {
            while (a < sz) {
                T nxt = type ? f.apply(seg.get(2 * a + (type ? 1 : 0)), M) : f.apply(M, seg.get(2 * a + (type ? 1 : 0)));
                if (check.test(nxt)) a = 2 * a + (type ? 1 : 0);
                else {
                    M = nxt;
                    a = 2 * a + 1 - (type ? 1 : 0);
                }
            }
            return a - sz;
        }

        int findFirst(int a, Predicate<T> check) {
            T L = M1;
            if (a <= 0) {
                if (check.test(f.apply(L, seg.get(1)))) return findSubtree(1, check, L, false);
                return -1;
            }
            int b = sz;
            for (a += sz, b += sz; a < b; a >>= 1, b >>= 1) {
                if ((a & 1) == 1) {
                    T nxt = f.apply(L, seg.get(a));
                    if (check.test(nxt)) return findSubtree(a, check, L, false);
                    L = nxt;
                    ++a;
                }
            }
            return -1;
        }

        int findLast(int b, Predicate<T> check) {
            T R = M1;
            if (b >= sz) {
                if (check.test(f.apply(seg.get(1), R))) return findSubtree(1, check, R, true);
                return -1;
            }
            int a = sz;
            for (b += sz; a < b; a >>= 1, b >>= 1) {
                if ((b & 1) == 1) {
                    T nxt = f.apply(seg.get(--b), R);
                    if (check.test(nxt)) return findSubtree(b, check, R, true);
                    R = nxt;
                }
            }
            return -1;
        }
    }

    static void main(String[] args) {
        new IoSetup();
        N = nextInt();
        X = new int[N];
        V = new int[N];
        P = new ModInt[N];
        Q = new ModInt[N];
        for (int i = 0; i < N; i++) {
            X[i] = nextInt();
            V[i] = nextInt();
            P[i] = new ModInt(nextInt()).divide(100);
            Q[i] = new ModInt(1).subtract(P[i]);
        }

        ev = new TreeMap<>();
        for (int i = 1; i < N; i++) {
            if (V[i - 1] < V[i]) {
                ev.computeIfAbsent(new Fraction<>(X[i - 1] - X[i], V[i - 1] - V[i]), k -> new ArrayList<>()).add(new Node(i, 0));
            }

            ev.computeIfAbsent(new Fraction<>(X[i] - X[i - 1], V[i - 1] + V[i]), k -> new ArrayList<>()).add(new Node(i, 2));

            if (V[i - 1] > V[i]) {
                ev.computeIfAbsent(new Fraction<>(X[i - 1] - X[i], V[i] - V[i - 1]), k -> new ArrayList<>()).add(new Node(i, 1));
            }
        }

        e = Matrix.I(4);
        for (int i = 0; i < N; i++) {
            Matrix<ModInt> u = new Matrix<>(e);
            u.get(0).set(0, Q[i]);
            u.get(1).set(0, Q[i]);
            u.get(2).set(2, Q[i]);
            u.get(3).set(2, Q[i]);
            u.get(0).set(1, P[i]);
            u.get(1).set(1, P[i]);
            u.get(2).set(3, P[i]);
            u.get(3).set(3, P[i]);
            seg.set(i, u);
        }
        seg.build();

        ModInt ret = new ModInt(0);

        for (Map.Entry<Fraction<Long>, ArrayList<Node>> entry : ev.entrySet()) {
            ArrayList<Node> vs = entry.getValue();
            for (Node tt : vs) {
                Matrix<ModInt> now = seg.get(tt.right);
                if (tt.type == 0) {
                    now.get(0).set(0, 0);
                    now.get(0).set(2, Q[tt.right]);
                } else if (tt.type == 1) {
                    now.get(1).set(1, 0);
                    now.get(1).set(3, P[tt.right]);
                } else {
                    now.get(1).set(0, 0);
                    now.get(1).set(2, Q[tt.right]);
                }
                seg.update(tt.right, now);
            }
            Matrix<ModInt> uku = seg.get(1);
            ModInt sum = uku.get(0).get(2).add(uku.get(0).get(3));
            ret.add(entry.getKey().num).divide(entry.getKey().dom).multiply(sum);
            for (Node tt : vs) {
                Matrix<ModInt> now = seg.get(tt.right);
                if (tt.type == 0) {
                    now.get(0).set(2, 0);
                    now.get(2).set(2, 0);
                } else if (tt.type == 1) {
                    now.get(1).set(3, 0);
                    now.get(3).set(3, 0);
                } else {
                    now.get(1).set(2, 0);
                    now.get(3).set(2, 0);
                }
                seg.update(tt.right, now);
            }
        }
        System.out.println(ret);
    }
}

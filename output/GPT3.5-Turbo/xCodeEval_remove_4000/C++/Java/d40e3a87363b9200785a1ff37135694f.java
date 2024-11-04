import java.util.*;
import java.io.*;
import java.math.*;

class Main {
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

    static class IoSetup {
        IoSetup() {
            System.out.println("fixed");
            System.err.println("fixed");
        }
    }

    static class modint {
        int x;
        static final int mod = 998244353;

        modint() {
            x = 0;
        }

        modint(long y) {
            x = (int) (y >= 0 ? y % mod : (mod - (-y) % mod) % mod);
        }

        modint add(modint p) {
            if ((x += p.x) >= mod)
                x -= mod;
            return this;
        }

        modint subtract(modint p) {
            if ((x += mod - p.x) >= mod)
                x -= mod;
            return this;
        }

        modint multiply(modint p) {
            x = mul(x, p.x);
            return this;
        }

        modint divide(modint p) {
            multiply(p.inverse());
            return this;
        }

        modint negate() {
            return new modint(-x);
        }

        modint add(modint p) {
            return new modint(x + p.x);
        }

        modint subtract(modint p) {
            return new modint(x - p.x);
        }

        modint multiply(modint p) {
            return new modint(x * p.x);
        }

        modint divide(modint p) {
            return new modint(x * p.inverse().x);
        }

        boolean equals(modint p) {
            return x == p.x;
        }

        boolean notEquals(modint p) {
            return x != p.x;
        }

        boolean lessThan(modint p) {
            return x < p.x;
        }

        boolean greaterThan(modint p) {
            return x > p.x;
        }

        boolean lessThanOrEqual(modint p) {
            return x <= p.x;
        }

        boolean greaterThanOrEqual(modint p) {
            return x >= p.x;
        }

        modint inverse() {
            int a = x, b = mod, u = 1, v = 0, t;
            while (b > 0) {
                t = a / b;
                a -= t * b;
                u -= t * v;
                t = a;
                a = b;
                b = t;
                t = u;
                u = v;
                v = t;
            }
            return new modint(u);
        }

        modint pow(long n) {
            modint ret = new modint(1), mul = new modint(x);
            while (n > 0) {
                if ((n & 1) == 1)
                    ret.multiply(mul);
                mul.multiply(mul);
                n >>= 1;
            }
            return ret;
        }

        static int get_mod() {
            return mod;
        }

        static int mul(int a, int b) {
            long x = (long) a * b;
            long xh = (long) (x >> 32), xl = (long) x, d, m;
            asm("divl %4; \n\t" : "=a" (d), "=d" (m) : "d" (xh), "a" (xl), "r" (mod));
            return (int) m;
        }
    }

    static class fraction<T> {
        T num, dom;

        fraction() {
        }

        fraction(T n, T d) {
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

        fraction add(fraction a) {
            return new fraction(num * a.dom + a.num * dom, dom * a.dom);
        }

        fraction subtract(fraction a) {
            return new fraction(num * a.dom - a.num * dom, dom * a.dom);
        }

        fraction multiply(fraction a) {
            return new fraction(num * a.num, dom * a.dom);
        }

        fraction divide(fraction a) {
            return new fraction(num * a.dom, dom * a.num);
        }

        fraction multiply(T k) {
            return new fraction(num * k, dom);
        }

        fraction divide(T k) {
            return new fraction(num, dom * k);
        }

        boolean lessThan(fraction a) {
            return num * a.dom < a.num * dom;
        }

        boolean greaterThan(fraction a) {
            return num * a.dom > a.num * dom;
        }

        boolean equals(fraction a) {
            return num * a.dom == a.num * dom;
        }

        boolean notEquals(fraction a) {
            return num * a.dom != a.num * dom;
        }

        boolean lessThanOrEqual(fraction a) {
            return num * a.dom <= a.num * dom;
        }

        boolean greaterThanOrEqual(fraction a) {
            return num * a.dom >= a.num * dom;
        }
    }

    static class Matrix<T> {
        ArrayList<ArrayList<T>> A;

        Matrix() {
        }

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

        T get(int i, int j) {
            return A.get(i).get(j);
        }

        void set(int i, int j, T val) {
            A.get(i).set(j, val);
        }

        static Matrix<Integer> I(int n) {
            Matrix<Integer> mat = new Matrix<>(n);
            for (int i = 0; i < n; i++) {
                mat.set(i, i, 1);
            }
            return mat;
        }

        Matrix<T> add(Matrix<T> B) {
            int n = height(), m = width();
            assert (n == B.height() && m == B.width());
            Matrix<T> C = new Matrix<>(n);
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    C.set(i, j, A.get(i).get(j) + B.get(i, j));
                }
            }
            return C;
        }

        Matrix<T> subtract(Matrix<T> B) {
            int n = height(), m = width();
            assert (n == B.height() && m == B.width());
            Matrix<T> C = new Matrix<>(n);
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    C.set(i, j, A.get(i).get(j) - B.get(i, j));
                }
            }
            return C;
        }

        Matrix<T> multiply(Matrix<T> B) {
            int n = height(), m = B.width(), p = width();
            assert (p == B.height());
            Matrix<T> C = new Matrix<>(n);
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    for (int k = 0; k < p; k++) {
                        C.set(i, j, C.get(i, j) + A.get(i).get(k) * B.get(k, j));
                    }
                }
            }
            return C;
        }

        Matrix<T> power(long k) {
            Matrix<T> B = Matrix.I(height());
            while (k > 0) {
                if ((k & 1) == 1)
                    B.multiply(this);
                multiply(this);
                k >>= 1;
            }
            return B;
        }

        T determinant() {
            Matrix<T> B = new Matrix<>(height());
            for (int i = 0; i < height(); i++) {
                for (int j = 0; j < width(); j++) {
                    B.set(i, j, A.get(i).get(j));
                }
            }
            assert (width() == height());
            T ret = 1;
            for (int i = 0; i < width(); i++) {
                int idx = -1;
                for (int j = i; j < width(); j++) {
                    if (B.get(j, i) != 0)
                        idx = j;
                }
                if (idx == -1)
                    return 0;
                if (i != idx) {
                    ret *= -1;
                    for (int j = 0; j < width(); j++) {
                        T tmp = B.get(i, j);
                        B.set(i, j, B.get(idx, j));
                        B.set(idx, j, tmp);
                    }
                }
                ret *= B.get(i, i);
                T vv = B.get(i, i);
                for (int j = 0; j < width(); j++) {
                    B.set(i, j, B.get(i, j) / vv);
                }
                for (int j = i + 1; j < width(); j++) {
                    T a = B.get(j, i);
                    for (int k = 0; k < width(); k++) {
                        B.set(j, k, B.get(j, k) - B.get(i, k) * a);
                    }
                }
            }
            return ret;
        }
    }

    static class Node {
        int right, type;

        Node(int right, int type) {
            this.right = right;
            this.type = type;
        }
    }

    static class SegmentTree {
        int sz;
        ArrayList<Matrix<modint>> seg;
        Matrix<modint> e;

        SegmentTree(int n, Matrix<modint> e) {
            sz = 1;
            while (sz < n)
                sz <<= 1;
            seg = new ArrayList<>(2 * sz);
            for (int i = 0; i < 2 * sz; i++) {
                seg.add(e);
            }
            this.e = e;
        }

        void set(int k, Matrix<modint> x) {
            seg.set(k + sz, x);
        }

        void build() {
            for (int k = sz - 1; k > 0; k--) {
                seg.set(k, seg.get(2 * k).multiply(seg.get(2 * k + 1)));
            }
        }

        void update(int k, Matrix<modint> x) {
            k += sz;
            seg.set(k, x);
            while ((k >>= 1) > 0) {
                seg.set(k, seg.get(2 * k).multiply(seg.get(2 * k + 1)));
            }
        }

        Matrix<modint> query(int a, int b) {
            Matrix<modint> L = e, R = e;
            for (a += sz, b += sz; a < b; a >>= 1, b >>= 1) {
                if ((a & 1) == 1)
                    L = L.multiply(seg.get(a++));
                if ((b & 1) == 1)
                    R = seg.get(--b).multiply(R);
            }
            return L.multiply(R);
        }
    }

    public static void main(String[] args) {
        FastScanner sc = new FastScanner();
        int N = sc.nextInt();
        int[] X = new int[N];
        int[] V = new int[N];
        modint[] P = new modint[N];
        modint[] Q = new modint[N];
        for (int i = 0; i < N; i++) {
            X[i] = sc.nextInt();
            V[i] = sc.nextInt();
            P[i] = new modint(sc.nextLong());
            P[i] = P[i].divide(100);
            Q[i] = new modint(1).subtract(P[i]);
        }

        TreeMap<fraction<Long>, ArrayList<Node>> ev = new TreeMap<>();
        for (int i = 1; i < N; i++) {
            if (V[i - 1] < V[i]) {
                ev.computeIfAbsent(new fraction<>(X[i - 1] - X[i], V[i - 1] - V[i]), k -> new ArrayList<>())
                        .add(new Node(i, 0));
            }

            ev.computeIfAbsent(new fraction<>(X[i] - X[i - 1], V[i - 1] + V[i]), k -> new ArrayList<>())
                    .add(new Node(i, 2));

            if (V[i - 1] > V[i]) {
                ev.computeIfAbsent(new fraction<>(X[i - 1] - X[i], V[i] - V[i - 1]), k -> new ArrayList<>())
                        .add(new Node(i, 1));
            }
        }

        Matrix<modint> e = Matrix.I(4);
        SegmentTree seg = new SegmentTree(N, e);
        for (int i = 0; i < N; i++) {
            Matrix<modint> u = new Matrix<>(e);
            u.set(0, 0, Q[i]);
            u.set(1, 0, Q[i]);
            u.set(2, 2, Q[i]);
            u.set(3, 2, Q[i]);
            u.set(0, 1, P[i]);
            u.set(1, 1, P[i]);
            u.set(2, 3, P[i]);
            u.set(3, 3, P[i]);
            seg.set(i, u);
        }
        seg.build();

        modint ret = new modint(0);

        for (Map.Entry<fraction<Long>, ArrayList<Node>> entry : ev.entrySet()) {
            ArrayList<Node> vs = entry.getValue();
            for (Node tt : vs) {
                Matrix<modint> now = seg.query(tt.right, tt.right);
                if (tt.type == 0) {
                    now.set(0, 0, new modint(0));
                    now.set(0, 2, Q[tt.right]);
                } else if (tt.type == 1) {
                    now.set(1, 1, new modint(0));
                    now.set(1, 3, P[tt.right]);
                } else {
                    now.set(1, 0, new modint(0));
                    now.set(1, 2, Q[tt.right]);
                }
                seg.update(tt.right, now);
            }
            Matrix<modint> uku = seg.query(0, 1);
            modint sum = uku.get(0, 2).add(uku.get(0, 3));
            ret.add(entry.getKey().num).divide(entry.getKey().dom).multiply(sum);
            for (Node tt : vs) {
                Matrix<modint> now = seg.query(tt.right, tt.right);
                if (tt.type == 0) {
                    now.set(0, 2, new modint(0));
                    now.set(2, 2, new modint(0));
                } else if (tt.type == 1) {
                    now.set(1, 3, new modint(0));
                    now.set(3, 3, new modint(0));
                } else {
                    now.set(1, 2, new modint(0));
                    now.set(3, 2, new modint(0));
                }
                seg.update(tt.right, now);
            }
        }
        System.out.println(ret);
    }
}

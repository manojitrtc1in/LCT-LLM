import java.util.*;
import java.io.*;
import java.math.*;

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
            System.out.println("fixed");
            System.err.println("fixed");
        }
    }

    static class modint {
        static final int mod = 998244353;
        static final int inf = (1 << 30) - 1;

        long x;

        modint() {
            x = 0;
        }

        modint(long x) {
            this.x = reduce(x);
        }

        long reduce(long w) {
            return (w >> 32) + mod - ((u64(u32(w) * inv) * mod) >> 32);
        }

        modint add(modint p) {
            if (x += p.x - 2 * mod < 0) {
                x += 2 * mod;
            }
            return this;
        }

        modint subtract(modint p) {
            if (x -= p.x < 0) {
                x += 2 * mod;
            }
            return this;
        }

        modint multiply(modint p) {
            x = reduce(x * p.x);
            return this;
        }

        modint divide(modint p) {
            multiply(p.inverse());
            return this;
        }

        modint inverse() {
            return pow(mod - 2);
        }

        modint pow(long n) {
            modint ret = new modint(1);
            modint mul = new modint(x);
            while (n > 0) {
                if ((n & 1) == 1) {
                    ret.multiply(mul);
                }
                mul.multiply(mul);
                n >>= 1;
            }
            return ret;
        }

        int get() {
            return (int) (reduce(x) % mod);
        }

        static int get_mod() {
            return mod;
        }

        static long u32(long n) {
            return n & 0xffffffffL;
        }

        static long u64(long n) {
            return n & 0xffffffffffffffffL;
        }

        static long mul_inv(long n, int e, long x) {
            return e == 0 ? x : mul_inv(n, e - 1, x * (2 - x * n));
        }

        static final int inv = (int) mul_inv(mod);
        static final int r2 = (int) (-u64(mod) % mod);
    }

    static class fraction<T> {
        T num, dom;

        fraction() {
        }

        fraction(T n, T d) {
            num = n;
            dom = d;
            assert (dom != 0);
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

        boolean equalTo(fraction a) {
            return num * a.dom == a.num * dom;
        }

        boolean notEqualTo(fraction a) {
            return num * a.dom != a.num * dom;
        }

        boolean lessThanOrEqualTo(fraction a) {
            return num * a.dom <= a.num * dom;
        }

        boolean greaterThanOrEqualTo(fraction a) {
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

        ArrayList<T> get(int k) {
            return A.get(k);
        }

        void set(int k, ArrayList<T> x) {
            A.set(k, x);
        }

        static Matrix<Integer> I(int n) {
            Matrix<Integer> mat = new Matrix<>(n);
            for (int i = 0; i < n; i++) {
                mat.get(i).set(i, 1);
            }
            return mat;
        }

        Matrix<T> add(Matrix<T> B) {
            int n = height(), m = width();
            assert (n == B.height() && m == B.width());
            Matrix<T> C = new Matrix<>(n);
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    C.get(i).set(j, A.get(i).get(j) + B.get(i).get(j));
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
                    C.get(i).set(j, A.get(i).get(j) - B.get(i).get(j));
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
                        C.get(i).set(j, C.get(i).get(j) + A.get(i).get(k) * B.get(k).get(j));
                    }
                }
            }
            return C;
        }

        Matrix<T> pow(long k) {
            Matrix<T> B = Matrix.I(height());
            while (k > 0) {
                if ((k & 1) == 1) {
                    B.multiply(this);
                }
                multiply(this);
                k >>= 1;
            }
            return B;
        }

        T determinant() {
            Matrix<T> B = new Matrix<>(this);
            int n = width();
            T ret = 1;
            for (int i = 0; i < n; i++) {
                int idx = -1;
                for (int j = i; j < n; j++) {
                    if (B.get(j).get(i) != 0) {
                        idx = j;
                    }
                }
                if (idx == -1) {
                    return (T) (Integer) 0;
                }
                if (i != idx) {
                    ret *= -1;
                    Collections.swap(B.A, i, idx);
                }
                ret *= B.get(i).get(i);
                T vv = B.get(i).get(i);
                for (int j = 0; j < n; j++) {
                    B.get(i).set(j, B.get(i).get(j) / vv);
                }
                for (int j = i + 1; j < n; j++) {
                    T a = B.get(j).get(i);
                    for (int k = 0; k < n; k++) {
                        B.get(j).set(k, B.get(j).get(k) - B.get(i).get(k) * a);
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
            while (sz < n) {
                sz <<= 1;
            }
            seg = new ArrayList<>(2 * sz);
            for (int i = 0; i < 2 * sz; i++) {
                seg.add(new Matrix<>(e));
            }
            this.e = new Matrix<>(e);
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
            Matrix<modint> L = new Matrix<>(e), R = new Matrix<>(e);
            for (a += sz, b += sz; a < b; a >>= 1, b >>= 1) {
                if ((a & 1) == 1) {
                    L = L.multiply(seg.get(a++));
                }
                if ((b & 1) == 1) {
                    R = seg.get(--b).multiply(R);
                }
            }
            return L.multiply(R);
        }

        Matrix<modint> get(int k) {
            return seg.get(k + sz);
        }

        int id0(int a, Predicate<Matrix<modint>> check, Matrix<modint> M, boolean type) {
            while (a < sz) {
                Matrix<modint> nxt = type ? seg.get(2 * a + (type ? 1 : 0)).multiply(M) : M.multiply(seg.get(2 * a + (type ? 1 : 0)));
                if (check.test(nxt)) {
                    a = 2 * a + (type ? 1 : 0);
                } else {
                    M = nxt;
                    a = 2 * a + 1 - (type ? 1 : 0);
                }
            }
            return a - sz;
        }

        int findFirst(int a, Predicate<Matrix<modint>> check) {
            Matrix<modint> L = new Matrix<>(e);
            if (a <= 0) {
                if (check.test(L.multiply(seg.get(1)))) {
                    return id0(1, check, L, false);
                }
                return -1;
            }
            int b = sz;
            for (a += sz, b += sz; a < b; a >>= 1, b >>= 1) {
                if ((a & 1) == 1) {
                    Matrix<modint> nxt = L.multiply(seg.get(a));
                    if (check.test(nxt)) {
                        return id0(a, check, L, false);
                    }
                    L = nxt;
                    ++a;
                }
            }
            return -1;
        }

        int findLast(int b, Predicate<Matrix<modint>> check) {
            Matrix<modint> R = new Matrix<>(e);
            if (b >= sz) {
                if (check.test(seg.get(1).multiply(R))) {
                    return id0(1, check, R, true);
                }
                return -1;
            }
            int a = sz;
            for (b += sz; a < b; a >>= 1, b >>= 1) {
                if ((b & 1) == 1) {
                    Matrix<modint> nxt = seg.get(--b).multiply(R);
                    if (check.test(nxt)) {
                        return id0(b, check, R, true);
                    }
                    R = nxt;
                }
            }
            return -1;
        }
    }

    static FastReader in;
    static PrintWriter out;

    public static void main(String[] args) {
        in = new FastReader();
        out = new PrintWriter(System.out);
        new IoSetup();
        int N = in.nextInt();
        int[] X = new int[N];
        int[] V = new int[N];
        modint[] P = new modint[N];
        modint[] Q = new modint[N];
        for (int i = 0; i < N; i++) {
            X[i] = in.nextInt();
            V[i] = in.nextInt();
            P[i] = new modint(in.nextLong());
            P[i].divide(100);
            Q[i] = new modint(1).subtract(P[i]);
        }

        Map<fraction<Long>, ArrayList<Node>> ev = new TreeMap<>();
        for (int i = 1; i < N; i++) {
            if (V[i - 1] < V[i]) {
                ev.computeIfAbsent(new fraction<>(X[i - 1] - X[i], V[i - 1] - V[i]), k -> new ArrayList<>()).add(new Node(i, 0));
            }
            ev.computeIfAbsent(new fraction<>(X[i] - X[i - 1], V[i - 1] + V[i]), k -> new ArrayList<>()).add(new Node(i, 2));
            if (V[i - 1] > V[i]) {
                ev.computeIfAbsent(new fraction<>(X[i - 1] - X[i], V[i] - V[i - 1]), k -> new ArrayList<>()).add(new Node(i, 1));
            }
        }

        Matrix<modint> e = Matrix.I(4);
        SegmentTree seg = new SegmentTree(N, e);
        for (int i = 0; i < N; i++) {
            Matrix<modint> u = new Matrix<>(e);
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

        modint ret = new modint(0);

        for (Map.Entry<fraction<Long>, ArrayList<Node>> entry : ev.entrySet()) {
            ArrayList<Node> vs = entry.getValue();
            for (Node tt : vs) {
                Matrix<modint> now = seg.get(tt.right);
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
            Matrix<modint> uku = seg.get(1);
            modint sum = uku.get(0).get(2).add(uku.get(0).get(3));
            ret.add(entry.getKey().num).divide(entry.getKey().dom).multiply(sum);
            for (Node tt : vs) {
                Matrix<modint> now = seg.get(tt.right);
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
        out.println(ret);
        out.close();
    }
}

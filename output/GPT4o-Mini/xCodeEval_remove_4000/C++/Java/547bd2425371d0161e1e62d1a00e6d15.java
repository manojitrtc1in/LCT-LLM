import java.util.*;
import java.util.stream.*;

class Main {
    static final int MOD = 998244353;
    static final long INFLL = (1L << 62) - 1;
    static final int INF = (1 << 30) - 1;

    static class Fraction {
        long num, dom;

        Fraction(long n, long d) {
            assert d != 0;
            if (d < 0) {
                n *= -1;
                d *= -1;
            }
            long tmp = gcd(Math.abs(n), Math.abs(d));
            num = n / tmp;
            dom = d / tmp;
        }

        static long gcd(long a, long b) {
            while (b != 0) {
                long temp = b;
                b = a % b;
                a = temp;
            }
            return a;
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

        @Override
        public String toString() {
            return num + "/" + dom;
        }
    }

    static class ModInt {
        long x;

        ModInt() {
            this.x = 0;
        }

        ModInt(long x) {
            this.x = reduce(x);
        }

        long reduce(long w) {
            return w % MOD;
        }

        ModInt add(ModInt p) {
            x = reduce(x + p.x);
            return this;
        }

        ModInt subtract(ModInt p) {
            x = reduce(x - p.x);
            return this;
        }

        ModInt multiply(ModInt p) {
            x = reduce(x * p.x);
            return this;
        }

        ModInt divide(ModInt p) {
            return multiply(p.inverse());
        }

        ModInt inverse() {
            return pow(MOD - 2);
        }

        ModInt pow(long n) {
            ModInt ret = new ModInt(1);
            ModInt mul = new ModInt(x);
            while (n > 0) {
                if ((n & 1) == 1) ret = ret.multiply(mul);
                mul = mul.multiply(mul);
                n >>= 1;
            }
            return ret;
        }

        @Override
        public String toString() {
            return String.valueOf(reduce(x));
        }
    }

    static class Matrix {
        ModInt[][] A;

        Matrix() {
            A = new ModInt[4][4];
            for (int i = 0; i < 4; i++) {
                Arrays.fill(A[i], new ModInt());
            }
        }

        static Matrix identity() {
            Matrix mat = new Matrix();
            for (int i = 0; i < 4; i++) {
                mat.A[i][i] = new ModInt(1);
            }
            return mat;
        }

        Matrix multiply(Matrix B) {
            Matrix C = new Matrix();
            for (int i = 0; i < 4; i++) {
                for (int j = 0; j < 4; j++) {
                    for (int k = 0; k < 4; k++) {
                        C.A[i][j] = C.A[i][j].add(A[i][k].multiply(B.A[k][j]));
                    }
                }
            }
            return C;
        }

        @Override
        public String toString() {
            StringBuilder sb = new StringBuilder();
            for (ModInt[] row : A) {
                sb.append(Arrays.toString(Arrays.stream(row).map(Object::toString).toArray()));
            }
            return sb.toString();
        }
    }

    static class SegmentTree {
        int sz;
        Matrix[] seg;
        Matrix M1;

        SegmentTree(int n) {
            sz = 1;
            while (sz < n) sz <<= 1;
            seg = new Matrix[2 * sz];
            M1 = Matrix.identity();
            Arrays.fill(seg, M1);
        }

        void set(int k, Matrix x) {
            seg[k + sz] = x;
        }

        void build() {
            for (int k = sz - 1; k > 0; k--) {
                seg[k] = seg[2 * k].multiply(seg[2 * k + 1]);
            }
        }

        void update(int k, Matrix x) {
            k += sz;
            seg[k] = x;
            while (k >>= 1) {
                seg[k] = seg[2 * k].multiply(seg[2 * k + 1]);
            }
        }

        Matrix query(int a, int b) {
            Matrix L = M1, R = M1;
            for (a += sz, b += sz; a < b; a >>= 1, b >>= 1) {
                if ((a & 1) == 1) L = L.multiply(seg[a++]);
                if ((b & 1) == 1) R = seg[--b].multiply(R);
            }
            return L.multiply(R);
        }

        Matrix get(int k) {
            return seg[k + sz];
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        int[] X = new int[N];
        int[] V = new int[N];
        ModInt[] P = new ModInt[N];
        ModInt[] Q = new ModInt[N];

        for (int i = 0; i < N; i++) {
            X[i] = scanner.nextInt();
            V[i] = scanner.nextInt();
            P[i] = new ModInt(scanner.nextInt()).divide(new ModInt(100));
            Q[i] = new ModInt(1).subtract(P[i]);
        }

        Map<Fraction, List<Node>> ev = new HashMap<>();
        for (int i = 1; i < N; i++) {
            if (V[i - 1] < V[i]) {
                ev.computeIfAbsent(new Fraction(X[i - 1] - X[i], V[i - 1] - V[i]), k -> new ArrayList<>())
                        .add(new Node(i, 0));
            }

            ev.computeIfAbsent(new Fraction(X[i] - X[i - 1], V[i - 1] + V[i]), k -> new ArrayList<>())
                    .add(new Node(i, 2));

            if (V[i - 1] > V[i]) {
                ev.computeIfAbsent(new Fraction(X[i - 1] - X[i], V[i] - V[i - 1]), k -> new ArrayList<>())
                        .add(new Node(i, 1));
            }
        }

        Matrix e = Matrix.identity();
        SegmentTree seg = new SegmentTree(N);
        for (int i = 0; i < N; i++) {
            Matrix u = new Matrix();
            u.A[0][0] = Q[i];
            u.A[1][0] = Q[i];
            u.A[2][2] = Q[i];
            u.A[3][2] = Q[i];
            u.A[0][1] = P[i];
            u.A[1][1] = P[i];
            u.A[2][3] = P[i];
            u.A[3][3] = P[i];
            seg.set(i, u);
        }
        seg.build();

        ModInt ret = new ModInt();

        for (Map.Entry<Fraction, List<Node>> entry : ev.entrySet()) {
            List<Node> vs = entry.getValue();
            for (Node tt : vs) {
                Matrix now = seg.get(tt.right);
                if (tt.type == 0) {
                    now.A[0][0] = new ModInt(0);
                    now.A[0][2] = Q[tt.right];
                } else if (tt.type == 1) {
                    now.A[1][1] = new ModInt(0);
                    now.A[1][3] = P[tt.right];
                } else {
                    now.A[1][0] = new ModInt(0);
                    now.A[1][2] = Q[tt.right];
                }
                seg.update(tt.right, now);
            }
            Matrix uku = seg.seg[1];
            ModInt sum = uku.A[0][2].add(uku.A[0][3]);
            ret = ret.add(new ModInt(entry.getKey().num).divide(new ModInt(entry.getKey().dom)).multiply(sum));
            for (Node tt : vs) {
                Matrix now = seg.get(tt.right);
                if (tt.type == 0) {
                    now.A[0][2] = new ModInt(0);
                    now.A[2][2] = new ModInt(0);
                } else if (tt.type == 1) {
                    now.A[1][3] = new ModInt(0);
                    now.A[3][3] = new ModInt(0);
                } else {
                    now.A[1][2] = new ModInt(0);
                    now.A[3][2] = new ModInt(0);
                }
                seg.update(tt.right, now);
            }
        }
        System.out.println(ret);
    }

    static class Node {
        int right, type;

        Node(int right, int type) {
            this.right = right;
            this.type = type;
        }
    }
}

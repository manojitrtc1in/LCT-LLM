import java.util.*;
import java.io.*;

class Main {
    static final int mod = 998244353;

    static class IoSetup {
        IoSetup() {
            try {
                BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
                PrintWriter out = new PrintWriter(System.out);
                System.setIn(new ByteArrayInputStream(br.readLine().getBytes()));
                System.setOut(out);
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
    }

    static class ModInt {
        static final int inv = mulInv(mod);
        static final long r2 = -((long) mod) % mod;
        int x;

        ModInt() {
            this.x = 0;
        }

        ModInt(int x) {
            this.x = reduce((long) x * r2);
        }

        static int reduce(long w) {
            return (int) (w >> 32) + mod - (int) (((long) (int) (w * inv) * mod) >> 32);
        }

        ModInt add(ModInt p) {
            x += p.x - 2 * mod;
            if (x < 0) x += 2 * mod;
            return this;
        }

        ModInt subtract(ModInt p) {
            x -= p.x;
            if (x < 0) x += 2 * mod;
            return this;
        }

        ModInt multiply(ModInt p) {
            x = reduce((long) x * p.x);
            return this;
        }

        ModInt divide(ModInt p) {
            return multiply(p.inverse());
        }

        ModInt inverse() {
            return pow(mod - 2);
        }

        ModInt pow(long n) {
            ModInt ret = new ModInt(1), mul = new ModInt(this.x);
            while (n > 0) {
                if ((n & 1) != 0) ret.multiply(mul);
                mul.multiply(mul);
                n >>= 1;
            }
            return ret;
        }

        @Override
        public String toString() {
            return String.valueOf(reduce(x) % mod);
        }

        static int mulInv(int n, int e, int x) {
            return e == 0 ? x : mulInv(n, e - 1, x * (2 - x * n));
        }
    }

    static class Fraction {
        long num, dom;

        Fraction(long n, long d) {
            assert d != 0;
            if (d < 0) {
                num *= -1;
                dom *= -1;
            }
            long tmp = gcd(Math.abs(num), Math.abs(dom));
            num /= tmp;
            dom /= tmp;
        }

        static long gcd(long a, long b) {
            return b == 0 ? a : gcd(b, a % b);
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
    }

    static class Matrix {
        ModInt[][] A;

        Matrix(int n) {
            A = new ModInt[n][n];
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    A[i][j] = new ModInt();
                }
            }
        }

        static Matrix identity(int n) {
            Matrix mat = new Matrix(n);
            for (int i = 0; i < n; i++) {
                mat.A[i][i] = new ModInt(1);
            }
            return mat;
        }

        Matrix multiply(Matrix B) {
            int n = A.length;
            Matrix C = new Matrix(n);
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    for (int k = 0; k < n; k++) {
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
                sb.append(Arrays.toString(row)).append("\n");
            }
            return sb.toString();
        }
    }

    static class SegmentTree {
        int sz;
        Matrix[] seg;
        Matrix M1;

        SegmentTree(int n, Matrix M1) {
            this.M1 = M1;
            sz = 1;
            while (sz < n) sz <<= 1;
            seg = new Matrix[2 * sz];
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
                if ((a & 1) != 0) L = L.multiply(seg[a++]);
                if ((b & 1) != 0) R = seg[--b].multiply(R);
            }
            return L.multiply(R);
        }
    }

    public static void main(String[] args) {
        new IoSetup();
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int[] X = new int[N], V = new int[N];
        ModInt[] P = new ModInt[N], Q = new ModInt[N];
        for (int i = 0; i < N; i++) {
            X[i] = sc.nextInt();
            V[i] = sc.nextInt();
            P[i] = new ModInt(sc.nextInt()).divide(new ModInt(100));
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

        Matrix e = Matrix.identity(4);
        SegmentTree seg = new SegmentTree(N, e);
        for (int i = 0; i < N; i++) {
            Matrix u = Matrix.identity(4);
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

        ModInt ret = new ModInt(0);
        for (Map.Entry<Fraction, List<Node>> entry : ev.entrySet()) {
            List<Node> vs = entry.getValue();
            for (Node tt : vs) {
                Matrix now = seg.seg[tt.right];
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
                Matrix now = seg.seg[tt.right];
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

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
        int x;

        ModInt() {
            this.x = 0;
        }

        ModInt(long y) {
            this.x = (int) (y >= 0 ? y % mod : (mod - (-y) % mod) % mod);
        }

        ModInt add(ModInt p) {
            if ((x += p.x) >= mod) x -= mod;
            return this;
        }

        ModInt subtract(ModInt p) {
            if ((x += mod - p.x) >= mod) x -= mod;
            return this;
        }

        ModInt multiply(ModInt p) {
            x = mul(x, p.x);
            return this;
        }

        ModInt divide(ModInt p) {
            return multiply(p.inverse());
        }

        ModInt inverse() {
            int a = x, b = mod, u = 1, v = 0, t;
            while (b > 0) {
                t = a / b;
                a -= t * b;
                int temp = u; u -= t * v; v = temp;
                int temp2 = b; b = a; a = temp2;
            }
            return new ModInt(u);
        }

        static int mul(int a, int b) {
            long x = (long) a * b;
            return (int) (x % mod);
        }

        public String toString() {
            return String.valueOf(x);
        }
    }

    static class Fraction {
        long num, dom;

        Fraction(long n, long d) {
            assert d != 0;
            if (d < 0) {
                n *= -1;
                d *= -1;
            }
            long gcd = gcd(Math.abs(n), Math.abs(d));
            num = n / gcd;
            dom = d / gcd;
        }

        static long gcd(long a, long b) {
            while (b != 0) {
                long t = b;
                b = a % b;
                a = t;
            }
            return a;
        }
    }

    static class Matrix {
        ModInt[][] A;

        Matrix() {
            A = new ModInt[4][4];
            for (int i = 0; i < 4; i++) {
                for (int j = 0; j < 4; j++) {
                    A[i][j] = new ModInt();
                }
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
                        C.A[i][j].add(A[i][k].multiply(B.A[k][j]));
                    }
                }
            }
            return C;
        }

        public String toString() {
            StringBuilder sb = new StringBuilder();
            for (int i = 0; i < 4; i++) {
                sb.append("[");
                for (int j = 0; j < 4; j++) {
                    sb.append(A[i][j]).append(j + 1 == 4 ? "]\n" : ",");
                }
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
            for (int i = 0; i < seg.length; i++) {
                seg[i] = new Matrix();
            }
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
                if (a % 2 == 1) L = L.multiply(seg[a++]);
                if (b % 2 == 1) R = seg[--b].multiply(R);
            }
            return L.multiply(R);
        }
    }

    public static void main(String[] args) {
        new IoSetup();
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int[] X = new int[N];
        int[] V = new int[N];
        ModInt[] P = new ModInt[N];
        ModInt[] Q = new ModInt[N];

        for (int i = 0; i < N; i++) {
            X[i] = sc.nextInt();
            V[i] = sc.nextInt();
            P[i] = new ModInt(sc.nextInt());
            P[i] = P[i].divide(new ModInt(100));
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
            ret.add(new ModInt(entry.getKey().num).divide(new ModInt(entry.getKey().dom)).multiply(sum));
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

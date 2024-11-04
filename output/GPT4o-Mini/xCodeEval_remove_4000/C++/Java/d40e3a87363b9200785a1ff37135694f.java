import java.util.*;
import java.io.*;
import java.math.BigInteger;

class Main {
    static final int mod = 998244353;
    static final long infll = (1L << 62) - 1;
    static final int inf = (1 << 30) - 1;

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

        ModInt pow(long n) {
            ModInt ret = new ModInt(1), mul = new ModInt(x);
            while (n > 0) {
                if ((n & 1) != 0) ret.multiply(mul);
                mul.multiply(mul);
                n >>= 1;
            }
            return ret;
        }

        @Override
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

        static long gcd(long a, long b) {
            while (b != 0) {
                long t = b;
                b = a % b;
                a = t;
            }
            return a;
        }
    }

    static class SegmentTree {
        int sz;
        ModInt[][] seg;
        ModInt[][] M1;

        SegmentTree(int n) {
            sz = 1;
            while (sz < n) sz <<= 1;
            seg = new ModInt[2 * sz][4];
            M1 = new ModInt[4][4];
            for (int i = 0; i < 4; i++) {
                M1[i][i] = new ModInt(1);
            }
        }

        void set(int k, ModInt[][] x) {
            seg[k + sz] = x;
        }

        void build() {
            for (int k = sz - 1; k > 0; k--) {
                seg[k] = multiply(seg[2 * k], seg[2 * k + 1]);
            }
        }

        void update(int k, ModInt[][] x) {
            k += sz;
            seg[k] = x;
            while (k >>= 1) {
                seg[k] = multiply(seg[2 * k], seg[2 * k + 1]);
            }
        }

        ModInt[][] query(int a, int b) {
            ModInt[][] L = M1, R = M1;
            for (a += sz, b += sz; a < b; a >>= 1, b >>= 1) {
                if ((a & 1) != 0) L = multiply(L, seg[a++]);
                if ((b & 1) != 0) R = multiply(seg[--b], R);
            }
            return multiply(L, R);
        }

        ModInt[][] multiply(ModInt[][] a, ModInt[][] b) {
            ModInt[][] C = new ModInt[4][4];
            for (int i = 0; i < 4; i++) {
                for (int j = 0; j < 4; j++) {
                    C[i][j] = new ModInt(0);
                    for (int k = 0; k < 4; k++) {
                        C[i][j].add(a[i][k].multiply(b[k][j]));
                    }
                }
            }
            return C;
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
            P[i] = new ModInt(sc.nextLong());
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

        SegmentTree seg = new SegmentTree(N);
        ModInt[][] e = new ModInt[4][4];
        for (int i = 0; i < 4; i++) {
            e[i][i] = new ModInt(1);
        }
        for (int i = 0; i < N; i++) {
            ModInt[][] u = new ModInt[4][4];
            for (int j = 0; j < 4; j++) {
                u[j][j] = new ModInt(0);
            }
            u[0][0] = Q[i];
            u[1][0] = Q[i];
            u[2][2] = Q[i];
            u[3][2] = Q[i];
            u[0][1] = P[i];
            u[1][1] = P[i];
            u[2][3] = P[i];
            u[3][3] = P[i];
            seg.set(i, u);
        }
        seg.build();

        ModInt ret = new ModInt(0);
        for (Map.Entry<Fraction, List<Node>> entry : ev.entrySet()) {
            List<Node> vs = entry.getValue();
            for (Node tt : vs) {
                ModInt[][] now = seg.seg[tt.right];
                if (tt.type == 0) {
                    now[0][0] = new ModInt(0);
                    now[0][2] = Q[tt.right];
                } else if (tt.type == 1) {
                    now[1][1] = new ModInt(0);
                    now[1][3] = P[tt.right];
                } else {
                    now[1][0] = new ModInt(0);
                    now[1][2] = Q[tt.right];
                }
                seg.update(tt.right, now);
            }
            ModInt[][] uku = seg.seg[1];
            ModInt sum = uku[0][2].add(uku[0][3]);
            ret.add(new ModInt(entry.getKey().num).divide(new ModInt(entry.getKey().dom)).multiply(sum));
            for (Node tt : vs) {
                ModInt[][] now = seg.seg[tt.right];
                if (tt.type == 0) {
                    now[0][2] = new ModInt(0);
                    now[2][2] = new ModInt(0);
                } else if (tt.type == 1) {
                    now[1][3] = new ModInt(0);
                    now[3][3] = new ModInt(0);
                } else {
                    now[1][2] = new ModInt(0);
                    now[3][2] = new ModInt(0);
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

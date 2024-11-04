import java.util.*;

class Main {
    static final int MOD = 10007;

    static class Field {
        int x;

        Field(int x) {
            this.x = x;
        }

        Field add(Field other) {
            return new Field((x + other.x) % MOD);
        }

        Field multiply(Field other) {
            return new Field((x * other.x) % MOD);
        }

        Field subtract(Field other) {
            return new Field((x - other.x + MOD) % MOD);
        }

        Field divide(Field other) {
            return multiply(other.inverse());
        }

        Field inverse() {
            int a = x, b = MOD, u = 1, v = 0;
            while (b != 0) {
                int t = a / b;
                a -= t * b;
                u -= t * v;
                int temp = a;
                a = b;
                b = temp;
                temp = u;
                u = v;
                v = temp;
            }
            if (u < 0) {
                u += MOD;
            }
            return new Field(u);
        }

        Field power(int p) {
            Field res = new Field(1);
            Field a = new Field(x);
            while (p > 0) {
                if ((p & 1) == 1) {
                    res = res.multiply(a);
                }
                a = a.multiply(a);
                p >>= 1;
            }
            return res;
        }

        @Override
        public String toString() {
            return Integer.toString(x);
        }
    }

    static class Polynomial {
        Field[] p;

        Polynomial(int size) {
            p = new Field[size];
            for (int i = 0; i < size; i++) {
                p[i] = new Field(0);
            }
        }

        Polynomial multiply(Polynomial other) {
            int n = p.length;
            int m = other.p.length;
            Polynomial res = new Polynomial(n + m - 1);
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    res.p[i + j] = res.p[i + j].add(p[i].multiply(other.p[j]));
                }
            }
            return res;
        }

        Polynomial shift(int k) {
            int n = p.length;
            Polynomial res = new Polynomial(n + k);
            for (int i = 0; i < n; i++) {
                res.p[i + k] = p[i];
            }
            return res;
        }

        Polynomial modFunction() {
            int n = p.length;
            Polynomial res = new Polynomial(n);
            for (int i = 0; i < n - 1; i++) {
                res.p[i] = p[i + 1].multiply(new Field(-1));
            }
            res.p[n - 1] = new Field(1);
            return res;
        }

        Polynomial divide(Polynomial other) {
            int n = p.length;
            int m = other.p.length;
            Polynomial res = new Polynomial(n - m + 1);
            Polynomial a = new Polynomial(n);
            for (int i = 0; i < n; i++) {
                a.p[i] = p[i];
            }
            Polynomial b = new Polynomial(m);
            for (int i = 0; i < m; i++) {
                b.p[i] = other.p[i];
            }
            Polynomial bInverse = b.p[0].inverse().multiply(new Polynomial(1));
            while (a.p.length >= b.p.length) {
                int k = a.p.length - b.p.length;
                Polynomial c = a.multiply(bInverse).shift(k);
                res = res.add(c);
                a = a.subtract(c.multiply(b));
            }
            return res;
        }

        Polynomial add(Polynomial other) {
            int n = p.length;
            int m = other.p.length;
            int size = Math.max(n, m);
            Polynomial res = new Polynomial(size);
            for (int i = 0; i < size; i++) {
                Field a = i < n ? p[i] : new Field(0);
                Field b = i < m ? other.p[i] : new Field(0);
                res.p[i] = a.add(b);
            }
            return res;
        }

        Polynomial subtract(Polynomial other) {
            int n = p.length;
            int m = other.p.length;
            int size = Math.max(n, m);
            Polynomial res = new Polynomial(size);
            for (int i = 0; i < size; i++) {
                Field a = i < n ? p[i] : new Field(0);
                Field b = i < m ? other.p[i] : new Field(0);
                res.p[i] = a.subtract(b);
            }
            return res;
        }

        Polynomial multiply(Field scalar) {
            int n = p.length;
            Polynomial res = new Polynomial(n);
            for (int i = 0; i < n; i++) {
                res.p[i] = p[i].multiply(scalar);
            }
            return res;
        }

        Polynomial divide(Field scalar) {
            int n = p.length;
            Polynomial res = new Polynomial(n);
            Field scalarInverse = scalar.inverse();
            for (int i = 0; i < n; i++) {
                res.p[i] = p[i].multiply(scalarInverse);
            }
            return res;
        }

        Polynomial power(int p) {
            int n = p.length;
            Polynomial res = new Polynomial(n);
            Polynomial a = new Polynomial(n);
            for (int i = 0; i < n; i++) {
                a.p[i] = p[i];
            }
            while (p > 0) {
                if ((p & 1) == 1) {
                    res = res.multiply(a);
                }
                a = a.multiply(a);
                p >>= 1;
            }
            return res;
        }

        @Override
        public String toString() {
            StringBuilder sb = new StringBuilder();
            sb.append("[");
            int n = p.length;
            for (int i = n - 1; i >= 0; i--) {
                sb.append(p[i]);
                if (i > 0) {
                    sb.append(" ");
                }
            }
            sb.append("]");
            return sb.toString();
        }
    }

    static Polynomial go(int left, int right, int i) {
        if (i < 0) {
            return new Polynomial(0);
        }
        if (i == 0 && left >= right) {
            return new Polynomial(1);
        }
        Polynomial[][][] dp = new Polynomial[N][N][10 * N];
        boolean[][][] ok = new boolean[N][N][10 * N];
        Polynomial res = dp[left][right][i];
        if (ok[left][right][i]) {
            return res;
        }
        res = new Polynomial(0);

        if (left >= right) {
            res = res.add(go(left, right, Math.max(i - 2, 0)).multiply(new Field(26)));
        } else if (left + 1 == right) {
            if (i == 0) {
                res = res.add(go(left + 1, right - 1, i));
            } else {
                res = res.add(go(left + 1, right, i - 1));
            }
            res = res.add(go(left, right, i - 2).multiply(new Field(25)));
        } else {
            if (s.charAt(left) == s.charAt(right - 1)) {
                res = res.add(go(left + 1, right - 1, i));
                res = res.add(go(left, right, i - 2).multiply(new Field(25)));
            } else {
                res = res.add(go(left + 1, right, i - 1));
                res = res.add(go(left, right - 1, i - 1));
                res = res.add(go(left, right, i - 2).multiply(new Field(24)));
            }
        }

        ok[left][right][i] = true;
        return res;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.next();
        int n = sc.nextInt();

        Polynomial base = new Polynomial(0);
        for (int i = 0; i < 10 * s.length(); i++) {
            base.p = Arrays.copyOf(base.p, base.p.length + 1);
            base.p[base.p.length - 1] = go(0, s.length(), i);
        }

        Polynomial modFunction = base.modFunction();

        Polynomial[] result = new Polynomial[1];
        result[0] = base;
        for (int i = 1; i < n; i++) {
            result = Polynomial.divideAndRemainder(result[0], modFunction);
        }

        System.out.println(result[0].p[0]);
    }
}

import java.io.*;
import java.util.*;

class AtCoder {
    static class Internal {
        static long safeMod(long x, long m) {
            x %= m;
            if (x < 0) x += m;
            return x;
        }

        static class Barrett {
            int m;
            long im;

            Barrett(int m) {
                this.m = m;
                this.im = (long) (-1) / m + 1;
            }

            int umod() {
                return m;
            }

            int mul(int a, int b) {
                long z = (long) a * b;
                long x = (z * im) >> 64;
                int v = (int) (z - x * m);
                if (m <= v) v += m;
                return v;
            }
        }

        static long powModConstexpr(long x, long n, int m) {
            if (m == 1) return 0;
            int _m = m;
            long r = 1;
            long y = safeMod(x, m);
            while (n > 0) {
                if ((n & 1) == 1) r = (r * y) % _m;
                y = (y * y) % _m;
                n >>= 1;
            }
            return r;
        }

        static boolean isPrimeConstexpr(int n) {
            if (n <= 1) return false;
            if (n == 2 || n == 7 || n == 61) return true;
            if (n % 2 == 0) return false;
            long d = n - 1;
            while (d % 2 == 0) d /= 2;
            long[] bases = {2, 7, 61};
            for (long a : bases) {
                long t = d;
                long y = powModConstexpr(a, t, n);
                while (t != n - 1 && y != 1 && y != n - 1) {
                    y = y * y % n;
                    t <<= 1;
                }
                if (y != n - 1 && t % 2 == 0) {
                    return false;
                }
            }
            return true;
        }

        static boolean isPrime(int n) {
            return isPrimeConstexpr(n);
        }

        static long[] invGcd(long a, long b) {
            a = safeMod(a, b);
            if (a == 0) return new long[]{b, 0};

            long s = b, t = a;
            long m0 = 0, m1 = 1;

            while (t != 0) {
                long u = s / t;
                s -= t * u;
                m0 -= m1 * u;

                long tmp = s;
                s = t;
                t = tmp;
                tmp = m0;
                m0 = m1;
                m1 = tmp;
            }
            if (m0 < 0) m0 += b / s;
            return new long[]{s, m0};
        }

        static int primitiveRootConstexpr(int m) {
            if (m == 2) return 1;
            if (m == 167772161) return 3;
            if (m == 469762049) return 3;
            if (m == 754974721) return 11;
            if (m == 998244353) return 3;
            int[] divs = new int[20];
            divs[0] = 2;
            int cnt = 1;
            int x = (m - 1) / 2;
            while (x % 2 == 0) x /= 2;
            for (int i = 3; (long) i * i <= x; i += 2) {
                if (x % i == 0) {
                    divs[cnt++] = i;
                    while (x % i == 0) {
                        x /= i;
                    }
                }
            }
            if (x > 1) {
                divs[cnt++] = x;
            }
            for (int g = 2; ; g++) {
                boolean ok = true;
                for (int i = 0; i < cnt; i++) {
                    if (powModConstexpr(g, (m - 1) / divs[i], m) == 1) {
                        ok = false;
                        break;
                    }
                }
                if (ok) return g;
            }
        }

        static int primitiveRoot(int m) {
            return primitiveRootConstexpr(m);
        }
    }

    static class StaticModInt {
        private final int m;
        private int v;

        StaticModInt(int m) {
            this.m = m;
            this.v = 0;
        }

        StaticModInt(int v, int m) {
            this.m = m;
            this.v = (int) ((v % m + m) % m);
        }

        static int mod(int m) {
            return m;
        }

        int val() {
            return v;
        }

        StaticModInt add(StaticModInt other) {
            return new StaticModInt((v + other.v) % m, m);
        }

        StaticModInt sub(StaticModInt other) {
            return new StaticModInt((v - other.v + m) % m, m);
        }

        StaticModInt mul(StaticModInt other) {
            return new StaticModInt((int) ((long) v * other.v % m), m);
        }

        StaticModInt pow(long n) {
            assert n >= 0;
            StaticModInt x = this, r = new StaticModInt(1, m);
            while (n > 0) {
                if ((n & 1) == 1) r = r.mul(x);
                x = x.mul(x);
                n >>= 1;
            }
            return r;
        }

        StaticModInt inv() {
            long eg = Internal.invGcd(v, m)[0];
            assert eg == 1;
            return new StaticModInt((int) eg, m);
        }
    }

    static class DynamicModInt {
        private static Barrett bt;
        private int v;

        DynamicModInt() {
            this.v = 0;
        }

        DynamicModInt(int v) {
            this.v = (int) ((v % bt.umod() + bt.umod()) % bt.umod());
        }

        static void setMod(int m) {
            bt = new Barrett(m);
        }

        int val() {
            return v;
        }

        DynamicModInt add(DynamicModInt other) {
            v += other.v;
            if (v >= bt.umod()) v -= bt.umod();
            return this;
        }

        DynamicModInt sub(DynamicModInt other) {
            v += bt.umod() - other.v;
            if (v >= bt.umod()) v -= bt.umod();
            return this;
        }

        DynamicModInt mul(DynamicModInt other) {
            v = bt.mul(v, other.v);
            return this;
        }

        DynamicModInt inv() {
            long eg = Internal.invGcd(v, bt.umod())[0];
            assert eg == 1;
            return new DynamicModInt((int) eg);
        }
    }

    static class Scanner {
        private final BufferedReader reader;
        private StringTokenizer tokenizer;

        Scanner(InputStream stream) {
            reader = new BufferedReader(new InputStreamReader(stream));
        }

        String next() {
            while (tokenizer == null || !tokenizer.hasMoreTokens()) {
                try {
                    tokenizer = new StringTokenizer(reader.readLine());
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
            }
            return tokenizer.nextToken();
        }

        int nextInt() {
            return Integer.parseInt(next());
        }
    }

    static class Printer {
        private final PrintWriter writer;

        Printer(OutputStream stream) {
            writer = new PrintWriter(stream);
        }

        void println(Object obj) {
            writer.println(obj);
        }

        void flush() {
            writer.flush();
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        Printer pr = new Printer(System.out);

        int n = sc.nextInt();
        int m = sc.nextInt();
        int mod = sc.nextInt();
        DynamicModInt.setMod(mod);

        List<List<DynamicModInt>> C = new ArrayList<>();
        for (int i = 0; i <= n; i++) {
            C.add(new ArrayList<>(Collections.nCopies(n + 1, new DynamicModInt())));
        }
        C.get(0).set(0, new DynamicModInt(1));

        for (int i = 1; i <= n; i++) {
            C.get(i).set(0, new DynamicModInt(1));
            for (int j = 1; j <= n; j++) {
                C.get(i).set(j, C.get(i - 1).get(j - 1).add(C.get(i - 1).get(j)));
            }
        }

        List<DynamicModInt> g = new ArrayList<>(Collections.nCopies(n + 1, new DynamicModInt()));
        for (int i = 0; i <= n; i++) {
            g.set(i, new DynamicModInt(i * (i + 1) / 2));
        }

        List<Pair<DynamicModInt, DynamicModInt>> f = new ArrayList<>(Collections.nCopies(n + 1, new Pair<>(new DynamicModInt(), new DynamicModInt())));
        f.get(0) = new Pair<>(new DynamicModInt(1), new DynamicModInt(0));

        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < i; j++) {
                DynamicModInt z = f.get(j).first.mul(f.get(i - 1 - j).first).mul(C.get(i - 1).get(j));
                f.get(i).first.add(z.mul(new DynamicModInt(i + 1)));
                f.get(i).second.add(z.mul(g.get(j).add(g.get(i - 1 - j))));
                f.get(i).second.add(f.get(i - 1 - j).first.mul(f.get(j).second).add(f.get(j).first.mul(f.get(i - 1 - j).second)).mul(C.get(i - 1).get(j)).mul(new DynamicModInt(i + 1)));
            }
        }

        List<List<Pair<DynamicModInt, DynamicModInt>>> dp = new ArrayList<>();
        for (int i = 0; i <= n + 1; i++) {
            dp.add(new ArrayList<>(Collections.nCopies(m + 1, new Pair<>(new DynamicModInt(), new DynamicModInt()))));
        }
        dp.get(0).set(0, new Pair<>(new DynamicModInt(1), new DynamicModInt(0)));

        for (int l = 0; l <= n; l++) {
            for (int r = l + 1; r <= n + 1; r++) {
                int di = r - l - 1;
                for (int i = 0; i + di <= m; i++) {
                    DynamicModInt z = dp.get(l).get(i).first.mul(f.get(di).first);
                    dp.get(r).get(i + di).first.add(z.mul(C.get(i + di).get(di)));
                    dp.get(r).get(i + di).second.add(dp.get(l).get(i).second.mul(f.get(di).first).add(dp.get(l).get(i).first.mul(f.get(di).second)).mul(C.get(i + di).get(di)));
                }
            }
        }

        pr.println(dp.get(n + 1).get(m).second.val());
        pr.flush();
    }

    static class Pair<F, S> {
        F first;
        S second;

        Pair(F first, S second) {
            this.first = first;
            this.second = second;
        }
    }
}

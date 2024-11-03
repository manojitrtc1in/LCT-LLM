


import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.math.BigInteger;
import java.nio.charset.Charset;
import java.util.*;


public class CFContest {
    public static void main(String[] args) throws Exception {
        boolean local = System.getProperty("ONLINE_JUDGE") == null;
        boolean async = true;

        Charset charset = Charset.forName("ascii");

        FastIO io = local ? new FastIO(new FileInputStream("D:\\DATABASE\\TESTCASE\\Code.in"), System.out, charset) : new FastIO(System.in, System.out, charset);
        Task task = new Task(io, new Debug(local));

        if (async) {
            Thread t = new Thread(null, task, "dalt", 1 << 27);
            t.setPriority(Thread.MAX_PRIORITY);
            t.start();
            t.join();
        } else {
            task.run();
        }

        if (local) {
            io.cache.append("\n\n--memory -- \n" + ((Runtime.getRuntime().totalMemory() - Runtime.getRuntime().freeMemory()) >> 20) + "M");
        }

        io.flush();
    }

    public static class Task implements Runnable {
        final FastIO io;
        final Debug debug;
        int inf = (int) 1e8;
        long lInf = (long) 1e18;
        NumberTheory.Modular mod = new NumberTheory.Modular(998244353);
        NumberTheory.Factorial factorial = new NumberTheory.Factorial(300000, mod);

        public Task(FastIO io, Debug debug) {
            this.io = io;
            this.debug = debug;
        }

        @Override
        public void run() {
            solve();
        }

        public void solve() {
            int n = io.readInt();
            Pair[] s = new Pair[n];
            for (int i = 0; i < n; i++) {
                s[i] = new Pair();
                s[i].a = io.readInt();
                s[i].b = io.readInt();
            }

            Map<Integer, Integer> id3 = new HashMap<>(n);
            Map<Integer, Integer> id1 = new HashMap<>(n);
            Map<Pair, Integer> id8 = new HashMap<>(n);

            for (Pair p : s) {
                id3.put(p.a, id3.getOrDefault(p.a, 0) + 1);
                id1.put(p.b, id1.getOrDefault(p.b, 0) + 1);
                id8.put(p, id8.getOrDefault(p, 0) + 1);
            }

            int p1, p2, p3;
            p1 = p2 = p3 = 1;
            for (Integer val : id3.values()) {
                p1 = mod.mul(p1, factorial.fact[val]);
            }
            for (Integer val : id1.values()) {
                p2 = mod.mul(p2, factorial.fact[val]);
            }

            Arrays.sort(s, (a, b) -> a.a == b.a ? (a.b - b.b) : (a.a - b.a));
            boolean order = true;
            for (int i = 1; i < n; i++) {
                if (!(s[i].a >= s[i - 1].a && s[i].b >= s[i - 1].b)) {
                    order = false;
                }
            }
            if (order) {
                for (Integer val : id8.values()) {
                    p3 = mod.mul(p3, factorial.fact[val]);
                }
            } else {
                p3 = 0;
            }
            int goodPerm = mod.plus(p1, p2);
            goodPerm = mod.subtract(goodPerm, p3);
            io.cache.append(mod.subtract(factorial.fact[n], goodPerm));
        }
    }


    public static class NumberTheory {
        private static final Random RANDOM = new Random();

        public static class id27 {
            int exp;
            int fact;
            int p;
            int pc;
            Modular modular;
            Power power;
            id26 id19 = new id26();
            int[] g;

            
            public id27(int p, int pc, int[] g) {
                this.p = p;
                this.pc = pc;
                this.g = g;
                modular = new Modular(pc);
                power = new Power(modular);
                g[0] = 1;
                g[1] = 1;
                for (int i = 2; i <= pc; i++) {
                    if (i % p == 0) {
                        g[i] = g[i - 1];
                    } else {
                        g[i] = modular.mul(g[i - 1], i);
                    }
                }
            }

            
            private int fact(long m) {
                fact = 1;
                exp = 0;
                while (m > 1) {
                    exp += m / p;
                    fact = modular.mul(fact, power.pow(g[pc], m / pc));
                    fact = modular.mul(fact, g[(int) (m % pc)]);
                    m /= p;
                }
                return fact;
            }

            
            public int composite(long m, long n) {
                int v = fact(m);
                int e = exp;
                id19.id6(fact(n), pc);
                v = modular.mul(v, modular.valueOf(id19.getX()));
                e -= exp;
                id19.id6(fact(m - n), pc);
                v = modular.mul(v, modular.valueOf(id19.getX()));
                e -= exp;
                v = modular.mul(v, power.pow(p, e));
                return v;
            }
        }

        
        public static class ExtLucas {
            id20 pr = new id20();
            Map<Integer, id27> id15 = new HashMap();

            public ExtLucas(int p) {
                Map<Integer, Integer> factors = pr.id10(p);
                for (Map.Entry<Integer, Integer> entry : factors.entrySet()) {
                    id15.put(entry.getValue(), new id27(entry.getKey(), entry.getValue(), new int[entry.getValue() + 1]));
                }
            }

            
            public int composite(long m, long n) {
                ExtCRT extCRT = new ExtCRT();
                for (Map.Entry<Integer, id27> entry : id15.entrySet()) {
                    extCRT.add(entry.getValue().composite(m, n), entry.getKey());
                }
                return (int) extCRT.r;
            }
        }

        
        public static class id14 {
            id16 pr = new id16();
            Map<Integer, id27> id15 = new HashMap();

            public id14(long p) {
                Map<Long, Long> factors = pr.id10(p);
                for (Map.Entry<Long, Long> entry : factors.entrySet()) {
                    id15.put(entry.getValue().intValue(), new id27(entry.getKey().intValue(), entry.getValue().intValue(), new int[entry.getValue().intValue() + 1]));
                }
            }

            
            public int composite(long m, long n) {
                ExtCRT extCRT = new ExtCRT();
                for (Map.Entry<Integer, id27> entry : id15.entrySet()) {
                    extCRT.add(entry.getValue().composite(m, n), entry.getKey());
                }
                return (int) extCRT.r;
            }
        }

        
        public static class id26 {
            private long x;
            private long y;
            private long g;

            public long getX() {
                return x;
            }

            public long getY() {
                return y;
            }

            
            public long id6(long a, long b) {
                if (a >= b) {
                    g = id5(a, b);
                } else {
                    g = id5(b, a);
                    long tmp = x;
                    x = y;
                    y = tmp;
                }
                return g;
            }


            private long id5(long a, long b) {
                if (b == 0) {
                    x = 1;
                    y = 0;
                    return a;
                }
                long g = id5(b, a % b);
                long n = x;
                long m = y;
                x = m;
                y = n - m * (a / b);
                return g;
            }
        }

        public static class Gcd {
            public long gcd(long a, long b) {
                return a >= b ? id21(a, b) : id21(b, a);
            }

            private long id21(long a, long b) {
                return b == 0 ? a : id21(b, a % b);
            }

            public int gcd(int a, int b) {
                return a >= b ? id21(a, b) : id21(b, a);
            }

            private int id21(int a, int b) {
                return b == 0 ? a : id21(b, a % b);
            }
        }

        
        public static class id11 {
            int[] primes;
            boolean[] isComp;
            int primeLength;

            public id11(int limit) {
                isComp = new boolean[limit + 1];
                primes = new int[limit + 1];
                primeLength = 0;
                for (int i = 2; i <= limit; i++) {
                    if (!isComp[i]) {
                        primes[primeLength++] = i;
                    }
                    for (int j = 0, until = limit / i; j < primeLength && primes[j] <= until; j++) {
                        int pi = primes[j] * i;
                        isComp[pi] = true;
                        if (i % primes[j] == 0) {
                            break;
                        }
                    }
                }
            }
        }

        
        public static class id2 {
            int[] primes;
            boolean[] isComp;
            int primeLength;
            int[] mobius;
            int[] euler;
            int[] factors;
            int[] id4;
            int[] id9;

            public id2(int limit, boolean id17, boolean enableEuler, boolean enableFactors) {
                isComp = new boolean[limit + 1];
                primes = new int[limit + 1];
                id9 = new int[limit + 1];
                id4 = new int[limit + 1];
                primeLength = 0;
                for (int i = 2; i <= limit; i++) {
                    if (!isComp[i]) {
                        primes[primeLength++] = i;
                        id9[i] = id4[i] = i;
                    }
                    for (int j = 0, until = limit / i; j < primeLength && primes[j] <= until; j++) {
                        int pi = primes[j] * i;
                        id4[pi] = primes[j];
                        id9[pi] = id4[i] == primes[j]
                                ? (id9[i] * id9[primes[j]])
                                : id9[primes[j]];
                        isComp[pi] = true;
                        if (i % primes[j] == 0) {
                            break;
                        }
                    }
                }

                if (id17) {
                    mobius = new int[limit + 1];
                    mobius[1] = 1;
                    for (int i = 2; i <= limit; i++) {
                        if (!isComp[i]) {
                            mobius[i] = -1;
                        } else {
                            if (id9[i] != id4[i]) {
                                mobius[i] = 0;
                            } else {
                                mobius[i] = mobius[id9[i]] *
                                        mobius[i / id9[i]];
                            }
                        }
                    }
                }

                if (enableEuler) {
                    euler = new int[limit + 1];
                    euler[1] = 1;
                    for (int i = 2; i <= limit; i++) {
                        if (!isComp[i]) {
                            euler[i] = i - 1;
                        } else {
                            if (id9[i] == i) {
                                euler[i] = i - i / id4[i];
                            } else {
                                euler[i] = euler[id9[i]] *
                                        euler[i / id9[i]];
                            }
                        }
                    }
                }

                if (enableFactors) {
                    factors = new int[limit + 1];
                    factors[1] = 1;
                    for (int i = 2; i <= limit; i++) {
                        if (!isComp[i]) {
                            factors[i] = 2;
                        } else {
                            if (id9[i] == i) {
                                factors[i] = 1 + factors[i / id4[i]];
                            } else {
                                factors[i] = factors[id9[i]] *
                                        factors[i / id9[i]];
                            }
                        }
                    }
                }
            }
        }

        
        public static class Modular {
            int m;

            public Modular(int m) {
                this.m = m;
            }

            public int valueOf(int x) {
                x %= m;
                if (x < 0) {
                    x += m;
                }
                return x;
            }

            public int valueOf(long x) {
                x %= m;
                if (x < 0) {
                    x += m;
                }
                return (int) x;
            }

            public int mul(int x, int y) {
                return valueOf((long) x * y);
            }

            public int mul(long x, long y) {
                x = valueOf(x);
                y = valueOf(y);
                return valueOf(x * y);
            }

            public int plus(int x, int y) {
                return valueOf(x + y);
            }

            public int plus(long x, long y) {
                x = valueOf(x);
                y = valueOf(y);
                return valueOf(x + y);
            }

            public int subtract(int x, int y) {
                return valueOf(x - y);
            }

            public int subtract(long x, long y) {
                return valueOf(x - y);
            }

            @Override
            public String toString() {
                return "mod " + m;
            }
        }

        
        public static class BitOperator {
            public int bitAt(int x, int i) {
                return (x >> i) & 1;
            }

            public int bitAt(long x, int i) {
                return (int) ((x >> i) & 1);
            }

            public int setBit(int x, int i, boolean v) {
                if (v) {
                    x |= 1 << i;
                } else {
                    x &= ~(1 << i);
                }
                return x;
            }

            public long setBit(long x, int i, boolean v) {
                if (v) {
                    x |= 1L << i;
                } else {
                    x &= ~(1L << i);
                }
                return x;
            }

            
            public boolean subset(long x, long y) {
                return intersect(x, y) == x;
            }

            
            public long merge(long x, long y) {
                return x | y;
            }

            public long intersect(long x, long y) {
                return x & y;
            }

            public long differ(long x, long y) {
                return x - intersect(x, y);
            }
        }

        
        public static class Power {
            final Modular modular;

            public Power(Modular modular) {
                this.modular = modular;
            }

            public int pow(int x, long n) {
                if (n == 0) {
                    return 1;
                }
                long r = pow(x, n >> 1);
                r = modular.valueOf(r * r);
                if ((n & 1) == 1) {
                    r = modular.valueOf(r * x);
                }
                return (int) r;
            }

            public int inverse(int x) {
                return pow(x, modular.m - 2);
            }

            public int pow2(int x) {
                return x * x;
            }

            public long pow2(long x) {
                return x * x;
            }

            public double pow2(double x) {
                return x * x;
            }
        }

        
        public static class Log2 {
            public int ceilLog(int x) {
                return 32 - Integer.numberOfLeadingZeros(x - 1);
            }

            public int floorLog(int x) {
                return 31 - Integer.numberOfLeadingZeros(x);
            }

            public int ceilLog(long x) {
                return 64 - Long.numberOfLeadingZeros(x - 1);
            }

            public int floorLog(long x) {
                return 63 - Long.numberOfLeadingZeros(x);
            }
        }

        
        public static class InverseNumber {
            int[] inv;

            public InverseNumber(int[] inv, int limit, Modular modular) {
                this.inv = inv;
                inv[1] = 1;
                int p = modular.m;
                for (int i = 2; i <= limit; i++) {
                    int k = p / i;
                    int r = p % i;
                    inv[i] = modular.mul(-k, inv[r]);
                }
            }

            public InverseNumber(int limit, Modular modular) {
                this(new int[limit + 1], limit, modular);
            }
        }

        
        public static class Factorial {
            int[] fact;
            int[] inv;

            public Factorial(int[] fact, int[] inv, InverseNumber in, int limit, Modular modular) {
                this.fact = fact;
                this.inv = inv;
                fact[0] = inv[0] = 1;
                for (int i = 1; i <= limit; i++) {
                    fact[i] = modular.mul(fact[i - 1], i);
                    inv[i] = modular.mul(inv[i - 1], in.inv[i]);
                }
            }

            public Factorial(int limit, Modular modular) {
                this(new int[limit + 1], new int[limit + 1], new InverseNumber(limit, modular), limit, modular);
            }
        }

        
        public static class Composite {
            final Factorial factorial;
            final Modular modular;

            public Composite(Factorial factorial, Modular modular) {
                this.factorial = factorial;
                this.modular = modular;
            }

            public Composite(int limit, Modular modular) {
                this(new Factorial(limit, modular), modular);
            }

            public int composite(int m, int n) {
                if (n > m) {
                    return 0;
                }
                return modular.mul(modular.mul(factorial.fact[m], factorial.inv[n]), factorial.inv[m - n]);
            }
        }

        
        public static class id23 {
            Modular modular;
            Power power;

            
            public boolean mr(int n, int s) {
                if (n == 2) {
                    return true;
                }
                if (n % 2 == 0) {
                    return false;
                }
                modular = new Modular(n);
                power = new Power(modular);
                for (int i = 0; i < s; i++) {
                    int x = RANDOM.nextInt(n - 2) + 2;
                    if (!mr0(x, n)) {
                        return false;
                    }
                }
                return true;
            }

            private boolean mr0(int x, int n) {
                int exp = n - 1;
                while (true) {
                    int y = power.pow(x, exp);
                    if (y != 1 && y != n - 1) {
                        return false;
                    }
                    if (y != 1 || exp % 2 == 1) {
                        break;
                    }
                    exp = exp / 2;
                }
                return true;
            }
        }

        
        public static class id12 {
            final long m;

            public id12(long m) {
                this.m = m;
            }

            public long mul(long a, long b) {
                return b == 0 ? 0 : ((mul(a, b >> 1) << 1) % m + a * (b & 1)) % m;
            }

            public long plus(long a, long b) {
                return valueOf(a + b);
            }

            public long valueOf(long a) {
                a %= m;
                if (a < 0) {
                    a += m;
                }
                return a;
            }
        }

        public static class LongPower {
            final id12 modular;

            public LongPower(id12 modular) {
                this.modular = modular;
            }

            long pow(long x, long n) {
                if (n == 0) {
                    return 1;
                }
                long r = pow(x, n >> 1);
                r = modular.mul(r, r);
                if ((n & 1) == 1) {
                    r = modular.mul(r, x);
                }
                return r;
            }

            long inverse(long x) {
                return pow(x, modular.m - 2);
            }
        }

        
        public static class id7 {
            id12 modular;
            LongPower power;

            
            public boolean mr(long n, int s) {
                if (n == 2) {
                    return true;
                }
                if (n % 2 == 0) {
                    return false;
                }
                modular = new id12(n);
                power = new LongPower(modular);
                for (int i = 0; i < s; i++) {
                    long x = (long) (RANDOM.nextDouble() * (n - 2) + 2);
                    if (!mr0(x, n)) {
                        return false;
                    }
                }
                return true;
            }

            private boolean mr0(long x, long n) {
                long exp = n - 1;
                while (true) {
                    long y = power.pow(x, exp);
                    if (y != 1 && y != n - 1) {
                        return false;
                    }
                    if (y != 1 || exp % 2 == 1) {
                        break;
                    }
                    exp = exp / 2;
                }
                return true;
            }
        }

        public static class id16 {
            id7 mr = new id7();
            Gcd gcd = new Gcd();
            id12 modular;

            
            public long findFactor(long n) {
                if (mr.mr(n, 3)) {
                    return n;
                }
                modular = new id12(n);
                while (true) {
                    long f = id0((long) (RANDOM.nextDouble() * n), (long) (RANDOM.nextDouble() * n), n);
                    if (f != -1) {
                        return f;
                    }
                }
            }

            private long id0(long x, long c, long n) {
                long xi = x;
                long xj = x;
                int j = 2;
                int i = 1;
                while (i < n) {
                    i++;
                    xi = modular.plus(modular.mul(xi, xi), c);
                    long g = gcd.gcd(n, Math.abs(xi - xj));
                    if (g != 1 && g != n) {
                        return g;
                    }
                    if (i == j) {
                        j = j << 1;
                        xj = xi;
                    }
                }
                return -1;
            }

            
            public Map<Long, Long> id10(long n) {
                Map<Long, Long> map = new HashMap();
                id10(map, n);
                return map;
            }

            private void id10(Map<Long, Long> map, long n) {
                if (n == 1) {
                    return;
                }
                long f = findFactor(n);
                if (f == n) {
                    Long value = map.get(f);
                    if (value == null) {
                        value = 1L;
                    }
                    map.put(f, value * f);
                    return;
                }
                id10(map, f);
                id10(map, n / f);
            }

        }

        
        public static class ExtCRT {
            
            long r;
            
            long m;
            id26 gcd = new id26();

            public ExtCRT() {
                r = 0;
                m = 1;
            }

            
            public boolean add(long r, long m) {
                long m1 = this.m;
                long x1 = this.r;
                long m2 = m;
                long x2 = ((r % m) + m) % m;
                long g = gcd.id6(m1, m2);
                long a = gcd.getX();
                if ((x2 - x1) % g != 0) {
                    return false;
                }
                this.m = m1 / g * m2;
                this.r = BigInteger.valueOf(a).multiply(BigInteger.valueOf((x2 - x1) / g))
                        .multiply(BigInteger.valueOf(m1)).add(BigInteger.valueOf(x1))
                        .mod(BigInteger.valueOf(this.m)).longValue();
                return true;
            }
        }

        
        public static class Lucas {
            private final Composite composite;
            private int modulus;

            public Lucas(Composite composite) {
                this.composite = composite;
                this.modulus = composite.modular.m;
            }

            public int composite(long m, long n) {
                if (n == 0) {
                    return 1;
                }
                return composite.modular.mul(composite.composite((int) (m % modulus), (int) (n % modulus)),
                        composite(m / modulus, n / modulus));
            }
        }

        
        public static class id20 {
            id23 mr = new id23();
            Gcd gcd = new Gcd();
            Random random = new Random();

            public int findFactor(int n) {
                if (mr.mr(n, 10)) {
                    return n;
                }
                while (true) {
                    int f = id0(random.nextInt(n), random.nextInt(n), n);
                    if (f != -1) {
                        return f;
                    }
                }
            }

            
            public Map<Integer, Integer> id10(int n) {
                Map<Integer, Integer> map = new HashMap();
                id10(map, n);
                return map;
            }

            private void id10(Map<Integer, Integer> map, int n) {
                if (n == 1) {
                    return;
                }
                int f = findFactor(n);
                if (f == n) {
                    Integer value = map.get(f);
                    if (value == null) {
                        value = 1;
                    }
                    map.put(f, value * f);
                    return;
                }
                id10(map, f);
                id10(map, n / f);
            }

            private int id0(int x, int c, int n) {
                int xi = x;
                int xj = x;
                int j = 2;
                int i = 1;
                while (i < n) {
                    i++;
                    xi = (int) ((long) xi * xi + c) % n;
                    int g = gcd.gcd(n, Math.abs(xi - xj));
                    if (g != 1 && g != n) {
                        return g;
                    }
                    if (i == j) {
                        j = j << 1;
                        xj = xi;
                    }
                }
                return -1;
            }
        }

        public static class ModExpression {
            id26 id19 = new id26();
            Modular modular = new Modular(1);

            
            public long solve(long a, long b, int c) {
                modular.m = c;
                a = modular.valueOf(a);
                b = modular.valueOf(b);
                int g = (int) id19.id6((int) a, c);
                if (b % g != 0) {
                    return -1;
                }
                modular.m = c / g;
                return modular.valueOf(b / g * id19.getX());
            }
        }

        
        public static class id24 {
            int l;
            int r;
            int n;
            int limit;


            public id24(int n, int l, int limit) {
                this.n = n;
                this.l = 0;
                this.limit = limit;
                this.r = l - 1;
            }

            public boolean hasNext() {
                return r < limit;
            }

            public int next() {
                l = r + 1;
                r = n / (n / l);
                return n / l;
            }
        }


        public static class id18 {
            final Modular modular;
            final BitOperator bitOperator = new BitOperator();
            Power power;
            final id20 rho = new id20();


            public id18(Modular modular) {
                this.modular = modular;
                power = new Power(modular);
            }

            
            public int square(int n) {
                n = modular.valueOf(n);
                if (n == 0) {
                    return 0;
                }
                int p = modular.m;
                if (power.pow(n, (p - 1) / 2) != 1) {
                    return -1;
                }
                while (true) {
                    int a = RANDOM.nextInt(p);
                    int w = modular.plus(modular.mul(a, a), -n);
                    if (power.pow(w, (p - 1) / 2) == 1) {
                        continue;
                    }


                    int pow = (p + 1) / 2;
                    int i = 31 - Integer.numberOfLeadingZeros(pow);
                    int real = 1;
                    int img = 0;
                    for (; i >= 0; i--) {
                        int nReal = modular.plus(modular.mul(real, real),
                                modular.mul(modular.mul(img, img), w));
                        int nImg = modular.mul(modular.mul(real, img), 2);
                        real = nReal;
                        img = nImg;
                        if (bitOperator.bitAt(pow, i) == 1) {
                            nReal = modular.plus(modular.mul(real, a), modular.mul(img, w));
                            nImg = modular.plus(modular.mul(img, a), real);
                            real = nReal;
                            img = nImg;
                        }
                    }

                    return real;
                }
            }

            public int id25() {
                if (modular.m == 2) {
                    return 1;
                }
                Map<Integer, Integer> factorMap = rho.id10(modular.m - 1);
                int[] factors = factorMap.keySet().stream().mapToInt(Integer::intValue).toArray();
                for (int i = 2; ; i++) {
                    boolean valid = true;
                    for (int factor : factors) {
                        if (power.pow(i, (modular.m - 1) / factor) == 1) {
                            valid = false;
                            break;
                        }
                    }
                    if (valid) {
                        return i;
                    }
                }
            }
        }
    }

    public static class Pair {
        int a;
        int b;

        @Override
        public int hashCode() {
            return a * 31 + b;
        }

        @Override
        public boolean equals(Object obj) {
            Pair other = (Pair) obj;
            return a == other.a && b == other.b;
        }
    }


    public static class Randomized {
        static Random random = new Random();

        public static double nextDouble(double min, double max) {
            return random.nextDouble() * (max - min) + min;
        }

        public static void id13(int[] data, int from, int to) {
            to--;
            for (int i = from; i <= to; i++) {
                int s = nextInt(i, to);
                int tmp = data[i];
                data[i] = data[s];
                data[s] = tmp;
            }
        }

        public static void id13(long[] data, int from, int to) {
            to--;
            for (int i = from; i <= to; i++) {
                int s = nextInt(i, to);
                long tmp = data[i];
                data[i] = data[s];
                data[s] = tmp;
            }
        }

        public static void id13(double[] data, int from, int to) {
            to--;
            for (int i = from; i <= to; i++) {
                int s = nextInt(i, to);
                double tmp = data[i];
                data[i] = data[s];
                data[s] = tmp;
            }
        }

        public static void id13(float[] data, int from, int to) {
            to--;
            for (int i = from; i <= to; i++) {
                int s = nextInt(i, to);
                float tmp = data[i];
                data[i] = data[s];
                data[s] = tmp;
            }
        }

        public static <T> void id13(T[] data, int from, int to) {
            to--;
            for (int i = from; i <= to; i++) {
                int s = nextInt(i, to);
                T tmp = data[i];
                data[i] = data[s];
                data[s] = tmp;
            }
        }

        public static int nextInt(int l, int r) {
            return random.nextInt(r - l + 1) + l;
        }
    }

    public static class FastIO {
        public final StringBuilder cache = new StringBuilder(1 << 20);
        private final InputStream is;
        private final OutputStream os;
        private final Charset charset;
        private StringBuilder id22 = new StringBuilder(1 << 8);
        private byte[] buf = new byte[1 << 13];
        private int bufLen;
        private int bufOffset;
        private int next;

        public FastIO(InputStream is, OutputStream os, Charset charset) {
            this.is = is;
            this.os = os;
            this.charset = charset;
        }

        public FastIO(InputStream is, OutputStream os) {
            this(is, os, Charset.forName("ascii"));
        }

        private int read() {
            while (bufLen == bufOffset) {
                bufOffset = 0;
                try {
                    bufLen = is.read(buf);
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
                if (bufLen == -1) {
                    return -1;
                }
            }
            return buf[bufOffset++];
        }

        public void skipBlank() {
            while (next >= 0 && next <= 32) {
                next = read();
            }
        }

        public int readInt() {
            int sign = 1;

            skipBlank();
            if (next == '+' || next == '-') {
                sign = next == '+' ? 1 : -1;
                next = read();
            }

            int val = 0;
            if (sign == 1) {
                while (next >= '0' && next <= '9') {
                    val = val * 10 + next - '0';
                    next = read();
                }
            } else {
                while (next >= '0' && next <= '9') {
                    val = val * 10 - next + '0';
                    next = read();
                }
            }

            return val;
        }

        public long readLong() {
            int sign = 1;

            skipBlank();
            if (next == '+' || next == '-') {
                sign = next == '+' ? 1 : -1;
                next = read();
            }

            long val = 0;
            if (sign == 1) {
                while (next >= '0' && next <= '9') {
                    val = val * 10 + next - '0';
                    next = read();
                }
            } else {
                while (next >= '0' && next <= '9') {
                    val = val * 10 - next + '0';
                    next = read();
                }
            }

            return val;
        }

        public double readDouble() {
            boolean sign = true;
            skipBlank();
            if (next == '+' || next == '-') {
                sign = next == '+';
                next = read();
            }

            long val = 0;
            while (next >= '0' && next <= '9') {
                val = val * 10 + next - '0';
                next = read();
            }
            if (next != '.') {
                return sign ? val : -val;
            }
            next = read();
            long radix = 1;
            long point = 0;
            while (next >= '0' && next <= '9') {
                point = point * 10 + next - '0';
                radix = radix * 10;
                next = read();
            }
            double result = val + (double) point / radix;
            return sign ? result : -result;
        }

        public String readString(StringBuilder builder) {
            skipBlank();

            while (next > 32) {
                builder.append((char) next);
                next = read();
            }

            return builder.toString();
        }

        public String readString() {
            id22.setLength(0);
            return readString(id22);
        }

        public int readLine(char[] data, int offset) {
            int originalOffset = offset;
            while (next != -1 && next != '\n') {
                data[offset++] = (char) next;
                next = read();
            }
            return offset - originalOffset;
        }

        public int readString(char[] data, int offset) {
            skipBlank();

            int originalOffset = offset;
            while (next > 32) {
                data[offset++] = (char) next;
                next = read();
            }

            return offset - originalOffset;
        }

        public int readString(byte[] data, int offset) {
            skipBlank();

            int originalOffset = offset;
            while (next > 32) {
                data[offset++] = (byte) next;
                next = read();
            }

            return offset - originalOffset;
        }

        public char readChar() {
            skipBlank();
            char c = (char) next;
            next = read();
            return c;
        }

        public void flush() {
            try {
                os.write(cache.toString().getBytes(charset));
                os.flush();
                cache.setLength(0);
            } catch (IOException e) {
                throw new RuntimeException(e);
            }
        }

        public boolean hasMore() {
            skipBlank();
            return next != -1;
        }
    }

    public static class Debug {
        private boolean allowDebug;

        public Debug(boolean allowDebug) {
            this.allowDebug = allowDebug;
        }

        public void assertTrue(boolean flag) {
            if (!allowDebug) {
                return;
            }
            if (!flag) {
                fail();
            }
        }

        public void fail() {
            throw new RuntimeException();
        }

        public void assertFalse(boolean flag) {
            if (!allowDebug) {
                return;
            }
            if (flag) {
                fail();
            }
        }

        private void outputName(String name) {
            System.out.print(name + " = ");
        }

        public void debug(String name, int x) {
            if (!allowDebug) {
                return;
            }

            outputName(name);
            System.out.println("" + x);
        }

        public void debug(String name, long x) {
            if (!allowDebug) {
                return;
            }
            outputName(name);
            System.out.println("" + x);
        }

        public void debug(String name, double x) {
            if (!allowDebug) {
                return;
            }
            outputName(name);
            System.out.println("" + x);
        }

        public void debug(String name, int[] x) {
            if (!allowDebug) {
                return;
            }
            outputName(name);
            System.out.println(Arrays.toString(x));
        }

        public void debug(String name, long[] x) {
            if (!allowDebug) {
                return;
            }
            outputName(name);
            System.out.println(Arrays.toString(x));
        }

        public void debug(String name, double[] x) {
            if (!allowDebug) {
                return;
            }
            outputName(name);
            System.out.println(Arrays.toString(x));
        }

        public void debug(String name, Object x) {
            if (!allowDebug) {
                return;
            }
            outputName(name);
            System.out.println("" + x);
        }

        public void debug(String name, Object... x) {
            if (!allowDebug) {
                return;
            }
            outputName(name);
            System.out.println(Arrays.deepToString(x));
        }
    }
}
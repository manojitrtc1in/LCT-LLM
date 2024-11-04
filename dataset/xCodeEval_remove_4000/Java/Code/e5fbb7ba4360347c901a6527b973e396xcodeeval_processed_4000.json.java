

import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.math.BigInteger;
import java.nio.charset.Charset;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Deque;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Random;

public class CFContest {
    public static void main(String[] args) throws Exception {
        boolean local = System.getProperty("ONLINE_JUDGE") == null;
        boolean async = false;

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
        int inf = (int) 1e9 + 2;
        MathUtils.Modular modular = new MathUtils.Modular(998244353);

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
            int m = n * 2 / 3;
            int r = n - m;
            for (int i = 0; i < m; i++) {
                io.cache.append(i).append(' ').append(0).append('\n');
            }
            for (int i = 0; i < r; i++) {
                io.cache.append(i * 2).append(' ').append(3).append('\n');
            }
        }
    }

    public static class MathUtils {
        private static Random random = new Random(123456789);

        public static class id16 {
            int exp;
            int fact;
            int p;
            int pc;
            Modular modular;
            Power power;
            id15 id10 = new id15();
            int[] g;

            
            public id16(int p, int pc, int[] g) {
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
                id10.id2(fact(n), pc);
                v = modular.mul(v, modular.valueOf(id10.getX()));
                e -= exp;
                id10.id2(fact(m - n), pc);
                v = modular.mul(v, modular.valueOf(id10.getX()));
                e -= exp;
                v = modular.mul(v, power.pow(p, e));
                return v;
            }
        }

        
        public static class ExtLucas {
            id11 pr = new id11();
            Map<Integer, id16> id8 = new HashMap();

            public ExtLucas(int p) {
                Map<Integer, Integer> factors = pr.id4(p);
                for (Map.Entry<Integer, Integer> entry : factors.entrySet()) {
                    id8.put(entry.getValue(), new id16(entry.getKey(), entry.getValue(), new int[entry.getValue() + 1]));
                }
            }

            
            public int composite(long m, long n) {
                ExtCRT extCRT = new ExtCRT();
                for (Map.Entry<Integer, id16> entry : id8.entrySet()) {
                    extCRT.add(entry.getValue().composite(m, n), entry.getKey());
                }
                return (int) extCRT.r;
            }
        }

        
        public static class id7 {
            id9 pr = new id9();
            Map<Integer, id16> id8 = new HashMap();

            public id7(long p) {
                Map<Long, Long> factors = pr.id4(p);
                for (Map.Entry<Long, Long> entry : factors.entrySet()) {
                    id8.put(entry.getValue().intValue(), new id16(entry.getKey().intValue(), entry.getValue().intValue(), new int[entry.getValue().intValue() + 1]));
                }
            }

            
            public int composite(long m, long n) {
                ExtCRT extCRT = new ExtCRT();
                for (Map.Entry<Integer, id16> entry : id8.entrySet()) {
                    extCRT.add(entry.getValue().composite(m, n), entry.getKey());
                }
                return (int) extCRT.r;
            }
        }

        
        public static class id15 extends Gcd {
            private long x;
            private long y;

            public long getX() {
                return x;
            }

            public long getY() {
                return y;
            }

            
            public long id2(long a, long b) {
                if (a >= b) {
                    return id1(a, b);
                } else {
                    long g = id1(b, a);
                    long tmp = x;
                    x = y;
                    y = tmp;
                    return g;
                }
            }

            private long id1(long a, long b) {
                if (b == 0) {
                    x = 1;
                    y = 0;
                    return a;
                }
                long g = id1(b, a % b);
                long n = x;
                long m = y;
                x = m;
                y = n - m * (a / b);
                return g;
            }
        }

        public static class Gcd {
            public long gcd(long a, long b) {
                return a >= b ? id12(a, b) : id12(b, a);
            }

            private long id12(long a, long b) {
                return b == 0 ? a : id12(b, a % b);
            }

            public int gcd(int a, int b) {
                return a >= b ? id12(a, b) : id12(b, a);
            }

            private int id12(int a, int b) {
                return b == 0 ? a : id12(b, a % b);
            }
        }

        
        public static class id5 {
            int[] primes;
            boolean[] isComp;
            int primeLength;

            public id5(int limit) {
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

        
        public static class Modular {
            final int m;

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

            public int plus(int x, int y) {
                return valueOf(x + y);
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

        
        public static class id14 {
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
                    int x = random.nextInt(n - 2) + 2;
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


        public static class id6 {
            final long m;

            public id6(long m) {
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
            final id6 modular;

            public LongPower(id6 modular) {
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

        
        public static class id3 {
            id6 modular;
            LongPower power;

            
            public boolean mr(long n, int s) {
                if (n == 2) {
                    return true;
                }
                if (n % 2 == 0) {
                    return false;
                }
                modular = new id6(n);
                power = new LongPower(modular);
                for (int i = 0; i < s; i++) {
                    long x = (long) (random.nextDouble() * (n - 2) + 2);
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

        public static class id9 {
            id3 mr = new id3();
            Gcd gcd = new Gcd();
            id6 modular;

            
            public long findFactor(long n) {
                if (mr.mr(n, 3)) {
                    return n;
                }
                modular = new id6(n);
                while (true) {
                    long f = id0((long) (random.nextDouble() * n), (long) (random.nextDouble() * n), n);
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

            
            public Map<Long, Long> id4(long n) {
                Map<Long, Long> map = new HashMap();
                id4(map, n);
                return map;
            }

            private void id4(Map<Long, Long> map, long n) {
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
                id4(map, f);
                id4(map, n / f);
            }

        }

        
        public static class ExtCRT {
            
            long r;
            
            long m;
            id15 gcd = new id15();

            public ExtCRT() {
                r = 0;
                m = 1;
            }

            
            public boolean add(long r, long m) {
                long m1 = this.m;
                long x1 = this.r;
                long m2 = m;
                long x2 = ((r % m) + m) % m;
                long g = gcd.id2(m1, m2);
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

        
        public static class id11 {
            id14 mr = new id14();
            Gcd gcd = new Gcd();
            Random random = new Random(123456789);

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

            public Map<Integer, Integer> id4(int n) {
                Map<Integer, Integer> map = new HashMap();
                id4(map, n);
                return map;
            }

            private void id4(Map<Integer, Integer> map, int n) {
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
                id4(map, f);
                id4(map, n / f);
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
    }

    public static class FastIO {
        public final StringBuilder cache = new StringBuilder();
        private final InputStream is;
        private final OutputStream os;
        private final Charset charset;
        private StringBuilder id13 = new StringBuilder(1 << 8);
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
            id13.setLength(0);
            return readString(id13);
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
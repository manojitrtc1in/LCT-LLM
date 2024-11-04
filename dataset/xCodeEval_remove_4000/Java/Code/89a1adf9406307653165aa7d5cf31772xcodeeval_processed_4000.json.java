import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.util.Arrays;
import java.util.Deque;
import java.util.function.Supplier;
import java.io.OutputStreamWriter;
import java.math.BigInteger;
import java.io.OutputStream;
import java.io.PrintStream;
import java.util.Collection;
import java.io.IOException;
import java.io.UncheckedIOException;
import java.util.function.Consumer;
import java.io.Closeable;
import java.io.Writer;
import java.util.ArrayDeque;
import java.io.InputStream;


public class Main {
    public static void main(String[] args) throws Exception {
        Thread thread = new Thread(null, new TaskAdapter(), "", 1 << 29);
        thread.start();
        thread.join();
    }

    static class TaskAdapter implements Runnable {
        @Override
        public void run() {
            InputStream inputStream = System.in;
            OutputStream outputStream = System.out;
            FastInput in = new FastInput(inputStream);
            FastOutput out = new FastOutput(outputStream);
            GTiles solver = new GTiles();
            solver.solve(1, in, out);
            out.close();
        }
    }

    static class GTiles {
        int mod = 998244353;
        Combination comb = new Combination((int) 1e6, mod);
        Debug debug = new Debug(true);

        public void solve(int testNumber, FastInput in, FastOutput out) {
            int n = in.ri();
            int[] last = new int[]{1};
            IntPoly poly = new id2(mod);
            for (int i = 0; i < n; i++) {
                int a = in.ri();
                int b = in.ri();
                int nextLevel = a - b + last.length;
                int height = a + b;
                int[] next = new int[nextLevel];
                int low = a - (nextLevel - 1);
                int high = last.length - 1 + a;
                int[] p = PrimitiveBuffers.id0(high - low + 1);
                for (int j = low; j <= high; j++) {
                    p[j - low] = comb.combination(height, j);
                }
                int[] conv = poly.id4(p, last);
                for (int j = 0; j < nextLevel; j++) {
                    int id = a - j - low;
                    next[j] = conv.length <= id ? 0 : conv[id];
                }
                debug.debugArray("next", next);
                PrimitiveBuffers.release(p, conv);
                last = next;
            }

            long sum = 0;
            for (long x : last) {
                sum += x;
            }
            sum %= mod;
            out.println(sum);
        }

    }

    static class IntPoly {
        protected int mod;
        protected Power power;

        public IntPoly(int mod) {
            this.mod = mod;
            this.power = new Power(mod);
        }

        public int[] convolution(int[] a, int[] b) {
            return mulBF(a, b);
        }

        public int rankOf(int[] p) {
            int r = p.length - 1;
            while (r >= 0 && p[r] == 0) {
                r--;
            }
            return Math.max(0, r);
        }

        public int[] mulBF(int[] a, int[] b) {
            int rA = rankOf(a);
            int rB = rankOf(b);
            if (rA > rB) {
                {
                    int tmp = rA;
                    rA = rB;
                    rB = tmp;
                }
                {
                    int[] tmp = a;
                    a = b;
                    b = tmp;
                }
            }
            int[] c = PrimitiveBuffers.id0(rA + rB + 1);
            for (int i = 0; i <= rA; i++) {
                for (int j = 0; j <= rB; j++) {
                    c[i + j] = (int) ((c[i + j] + (long) a[i] * b[j]) % mod);
                }
            }
            return c;
        }

        public int[] id4(int[] a, int[] b) {
            int rA = rankOf(a);
            SequenceUtils.reverse(a, 0, rA);
            int[] ans = convolution(a, b);
            SequenceUtils.reverse(a, 0, rA);
            for (int i = rA + 1; i < ans.length; i++) {
                ans[i] = 0;
            }
            SequenceUtils.reverse(ans, 0, rA);
            return Polynomials.id7(ans);
        }

    }

    static class SequenceUtils {
        public static void swap(int[] data, int i, int j) {
            int tmp = data[i];
            data[i] = data[j];
            data[j] = tmp;
        }

        public static void swap(double[] data, int i, int j) {
            double tmp = data[i];
            data[i] = data[j];
            data[j] = tmp;
        }

        public static void reverse(int[] data, int l, int r) {
            while (l < r) {
                swap(data, l, r);
                l++;
                r--;
            }
        }

    }

    static class DigitUtils {
        private DigitUtils() {
        }

        public static int mod(long x, int mod) {
            if (x < -mod || x >= mod) {
                x %= mod;
            }
            if (x < 0) {
                x += mod;
            }
            return (int) x;
        }

        public static int mod(int x, int mod) {
            if (x < -mod || x >= mod) {
                x %= mod;
            }
            if (x < 0) {
                x += mod;
            }
            return x;
        }

    }

    static class Combination implements IntCombination {
        final Factorial factorial;
        int modVal;

        public Combination(Factorial factorial) {
            this.factorial = factorial;
            this.modVal = factorial.getMod();
        }

        public Combination(int limit, int mod) {
            this(new Factorial(limit, mod));
        }

        public int combination(int m, int n) {
            if (n > m || n < 0) {
                return 0;
            }
            return (int) ((long) factorial.fact(m) * factorial.invFact(n) % modVal * factorial.invFact(m - n) % modVal);
        }

    }

    static class id11 {
        private static double[][] realLevels = new double[30][];
        private static double[][] imgLevels = new double[30][];

        private static void prepareLevel(int i) {
            if (realLevels[i] == null) {
                realLevels[i] = new double[1 << i];
                imgLevels[i] = new double[1 << i];
                for (int j = 0, s = 1 << i; j < s; j++) {
                    realLevels[i][j] = Math.cos(Math.PI / s * j);
                    imgLevels[i][j] = Math.sin(Math.PI / s * j);
                }
            }
        }

        public static void fft(double[][] p, boolean inv) {
            int m = Log2.ceilLog(p[0].length);
            int n = 1 << m;
            int shift = 32 - Integer.numberOfTrailingZeros(n);
            for (int i = 1; i < n; i++) {
                int j = Integer.reverse(i << shift);
                if (i < j) {
                    SequenceUtils.swap(p[0], i, j);
                    SequenceUtils.swap(p[1], i, j);
                }
            }

            double[][] t = new double[2][1];
            for (int d = 0; d < m; d++) {
                int s = 1 << d;
                int s2 = s << 1;
                prepareLevel(d);
                for (int i = 0; i < n; i += s2) {
                    for (int j = 0; j < s; j++) {
                        int a = i + j;
                        int b = a + s;
                        mul(realLevels[d][j], imgLevels[d][j], p[0][b], p[1][b], t, 0);
                        sub(p[0][a], p[1][a], t[0][0], t[1][0], p, b);
                        add(p[0][a], p[1][a], t[0][0], t[1][0], p, a);
                    }
                }
            }

            if (inv) {
                for (int i = 0, j = 0; i <= j; i++, j = n - i) {
                    double a = p[0][j];
                    double b = p[1][j];
                    div(p[0][i], p[1][i], n, p, j);
                    if (i != j) {
                        div(a, b, n, p, i);
                    }
                }
            }
        }

        public static void add(double r1, double i1, double r2, double i2, double[][] r, int i) {
            r[0][i] = r1 + r2;
            r[1][i] = i1 + i2;
        }

        public static void sub(double r1, double i1, double r2, double i2, double[][] r, int i) {
            r[0][i] = r1 - r2;
            r[1][i] = i1 - i2;
        }

        public static void mul(double r1, double i1, double r2, double i2, double[][] r, int i) {
            r[0][i] = r1 * r2 - i1 * i2;
            r[1][i] = r1 * i2 + i1 * r2;
        }

        public static void div(double r1, double i1, double r2, double[][] r, int i) {
            r[0][i] = r1 / r2;
            r[1][i] = i1 / r2;
        }

    }

    static class Factorial {
        int[] fact;
        int[] inv;
        int mod;

        public int getMod() {
            return mod;
        }

        public Factorial(int[] fact, int[] inv, int mod) {
            this.mod = mod;
            this.fact = fact;
            this.inv = inv;
            fact[0] = inv[0] = 1;
            int n = Math.min(fact.length, mod);
            for (int i = 1; i < n; i++) {
                fact[i] = i;
                fact[i] = (int) ((long) fact[i] * fact[i - 1] % mod);
            }
            inv[n - 1] = BigInteger.valueOf(fact[n - 1]).modInverse(BigInteger.valueOf(mod)).intValue();
            for (int i = n - 2; i >= 1; i--) {
                inv[i] = (int) ((long) inv[i + 1] * (i + 1) % mod);
            }
        }

        public Factorial(int limit, int mod) {
            this(new int[Math.min(limit + 1, mod)], new int[Math.min(limit + 1, mod)], mod);
        }

        public int fact(int n) {
            if (n >= mod) {
                return 0;
            }
            return fact[n];
        }

        public int invFact(int n) {
            if (n >= mod) {
                throw new IllegalArgumentException();
            }
            return inv[n];
        }

    }

    static class FastOutput implements AutoCloseable, Closeable, Appendable {
        private static final int id12 = 1 << 13;
        private final Writer os;
        private StringBuilder cache = new StringBuilder(id12 * 2);

        public FastOutput append(CharSequence csq) {
            cache.append(csq);
            return this;
        }

        public FastOutput append(CharSequence csq, int start, int end) {
            cache.append(csq, start, end);
            return this;
        }

        private void afterWrite() {
            if (cache.length() < id12) {
                return;
            }
            flush();
        }

        public FastOutput(Writer os) {
            this.os = os;
        }

        public FastOutput(OutputStream os) {
            this(new OutputStreamWriter(os));
        }

        public FastOutput append(char c) {
            cache.append(c);
            afterWrite();
            return this;
        }

        public FastOutput append(long c) {
            cache.append(c);
            afterWrite();
            return this;
        }

        public FastOutput append(String c) {
            cache.append(c);
            afterWrite();
            return this;
        }

        public FastOutput println(long c) {
            return append(c).println();
        }

        public FastOutput println() {
            return append(System.lineSeparator());
        }

        public FastOutput flush() {
            try {
                os.append(cache);
                os.flush();
                cache.setLength(0);
            } catch (IOException e) {
                throw new UncheckedIOException(e);
            }
            return this;
        }

        public void close() {
            flush();
            try {
                os.close();
            } catch (IOException e) {
                throw new UncheckedIOException(e);
            }
        }

        public String toString() {
            return cache.toString();
        }

    }

    static class Polynomials {
        public static int rankOf(int[] p) {
            int r = p.length - 1;
            while (r >= 0 && p[r] == 0) {
                r--;
            }
            return Math.max(0, r);
        }

        public static int[] id7(int[] p) {
            int r = rankOf(p);
            return PrimitiveBuffers.resize(p, r + 1);
        }

    }

    static class Power implements InverseNumber {
        int mod;

        public Power(int mod) {
            this.mod = mod;
        }

    }

    static interface IntCombination {
    }

    static class Buffer<T> {
        private Deque<T> deque;
        private Supplier<T> supplier;
        private Consumer<T> cleaner;
        private int allocTime;
        private int releaseTime;

        public Buffer(Supplier<T> supplier) {
            this(supplier, (x) -> {
            });
        }

        public Buffer(Supplier<T> supplier, Consumer<T> cleaner) {
            this(supplier, cleaner, 0);
        }

        public Buffer(Supplier<T> supplier, Consumer<T> cleaner, int exp) {
            this.supplier = supplier;
            this.cleaner = cleaner;
            deque = new ArrayDeque<>(exp);
        }

        public T alloc() {
            allocTime++;
            return deque.isEmpty() ? supplier.get() : deque.removeFirst();
        }

        public void release(T e) {
            releaseTime++;
            cleaner.accept(e);
            deque.addLast(e);
        }

    }

    static class PrimitiveBuffers {
        public static Buffer<int[]>[] id15 = new Buffer[30];
        public static Buffer<double[]>[] id13 = new Buffer[30];

        static {
            for (int i = 0; i < 30; i++) {
                int finalI = i;
                id15[i] = new Buffer<>(() -> new int[1 << finalI], x -> Arrays.fill(x, 0));
                id13[i] = new Buffer<>(() -> new double[1 << finalI], x -> Arrays.fill(x, 0));
            }
        }

        public static int[] id0(int n) {
            return id15[Log2.ceilLog(n)].alloc();
        }

        public static int[] resize(int[] data, int want) {
            int log = Log2.ceilLog(want);
            if (data.length == 1 << log) {
                return data;
            }
            return replace(id0(data, want), data);
        }

        public static int[] id0(int[] data, int newLen) {
            int[] ans = id0(newLen);
            System.arraycopy(data, 0, ans, 0, Math.min(data.length, newLen));
            return ans;
        }

        public static void release(int[] data) {
            id15[Log2.ceilLog(data.length)].release(data);
        }

        public static void release(int[] a, int[] b) {
            release(a);
            release(b);
        }

        public static double[] id9(int n) {
            return id13[Log2.ceilLog(n)].alloc();
        }

        public static double[] id9(double[] data, int newLen) {
            double[] ans = id9(newLen);
            System.arraycopy(data, 0, ans, 0, Math.min(data.length, newLen));
            return ans;
        }

        public static void release(double[] data) {
            id13[Log2.ceilLog(data.length)].release(data);
        }

        public static void release(double[]... data) {
            for (double[] x : data) {
                release(x);
            }
        }

        public static int[] replace(int[] a, int[] b) {
            release(b);
            return a;
        }

    }

    static class Log2 {
        public static int ceilLog(int x) {
            if (x <= 0) {
                return 0;
            }
            return 32 - Integer.numberOfLeadingZeros(x - 1);
        }

    }

    static interface InverseNumber {
    }

    static class FastInput {
        private final InputStream is;
        private byte[] buf = new byte[1 << 13];
        private int bufLen;
        private int bufOffset;
        private int next;

        public FastInput(InputStream is) {
            this.is = is;
        }

        private int read() {
            while (bufLen == bufOffset) {
                bufOffset = 0;
                try {
                    bufLen = is.read(buf);
                } catch (IOException e) {
                    bufLen = -1;
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

        public int ri() {
            return readInt();
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

    }

    static class id2 extends IntPoly {
        private static final int FFT_THRESHOLD = 50;

        public id2(int mod) {
            super(mod);
        }

        public int[] convolution(int[] a, int[] b) {
            if (a != b) {
                return multiplyMod(a, b);
            } else {
                return pow2(a);
            }
        }

        public int[] pow2(int[] a) {
            int rA = rankOf(a);
            if (rA < FFT_THRESHOLD) {
                return mulBF(a, a);
            }

            int need = rA * 2 + 1;

            double[] aReal = PrimitiveBuffers.id9(need);
            double[] aImag = PrimitiveBuffers.id9(need);
            int n = aReal.length;

            for (int i = 0; i <= rA; i++) {
                int x = DigitUtils.mod(a[i], mod);
                aReal[i] = x & ((1 << 15) - 1);
                aImag[i] = x >> 15;
            }
            id11.fft(new double[][]{aReal, aImag}, false);

            double[] bReal = PrimitiveBuffers.id9(aReal, aReal.length);
            double[] bImag = PrimitiveBuffers.id9(aImag, bReal.length);


            for (int i = 0, j = 0; i <= j; i++, j = n - i) {
                double ari = aReal[i];
                double aii = aImag[i];
                double bri = bReal[i];
                double bii = bImag[i];
                double arj = aReal[j];
                double aij = aImag[j];
                double brj = bReal[j];
                double bij = bImag[j];

                double id6 = (ari + arj) / 2;
                double id5 = (aii - aij) / 2;
                double id3 = (aii + aij) / 2;
                double id14 = (arj - ari) / 2;

                double id1 = (bri + brj) / 2;
                double id8 = (bii - bij) / 2;
                double id16 = (bii + bij) / 2;
                double id10 = (brj - bri) / 2;

                aReal[i] = id6 * id1 - id5 * id8 - id3 * id10 - id14 * id16;
                aImag[i] = id6 * id8 + id5 * id1 + id3 * id16 - id14 * id10;
                bReal[i] = id6 * id16 - id5 * id10 + id3 * id1 - id14 * id8;
                bImag[i] = id6 * id10 + id5 * id16 + id3 * id8 + id14 * id1;

                if (i != j) {
                    id6 = (arj + ari) / 2;
                    id5 = (aij - aii) / 2;
                    id3 = (aij + aii) / 2;
                    id14 = (ari - arj) / 2;

                    id1 = (brj + bri) / 2;
                    id8 = (bij - bii) / 2;
                    id16 = (bij + bii) / 2;
                    id10 = (bri - brj) / 2;

                    aReal[j] = id6 * id1 - id5 * id8 - id3 * id10 - id14 * id16;
                    aImag[j] = id6 * id8 + id5 * id1 + id3 * id16 - id14 * id10;
                    bReal[j] = id6 * id16 - id5 * id10 + id3 * id1 - id14 * id8;
                    bImag[j] = id6 * id10 + id5 * id16 + id3 * id8 + id14 * id1;
                }
            }

            id11.fft(new double[][]{aReal, aImag}, true);
            id11.fft(new double[][]{bReal, bImag}, true);

            int[] ans = PrimitiveBuffers.id0(need);
            for (int i = 0; i < need; i++) {
                long aa = DigitUtils.mod(Math.round(aReal[i]), mod);
                long bb = DigitUtils.mod(Math.round(bReal[i]), mod);
                long cc = DigitUtils.mod(Math.round(aImag[i]), mod);
                ans[i] = DigitUtils.mod(aa + (bb << 15) + (cc << 30), mod);
            }

            PrimitiveBuffers.release(aReal, bReal, aImag, bImag);
            return ans;
        }

        private int[] multiplyMod(int[] a, int[] b) {
            int rA = rankOf(a);
            int rB = rankOf(b);
            if (Math.min(rA, rB) < FFT_THRESHOLD) {
                return mulBF(a, b);
            }

            int need = rA + rB + 1;

            double[] aReal = PrimitiveBuffers.id9(need);
            double[] aImag = PrimitiveBuffers.id9(need);
            int n = aReal.length;

            for (int i = 0; i <= rA; i++) {
                int x = DigitUtils.mod(a[i], mod);
                aReal[i] = x & ((1 << 15) - 1);
                aImag[i] = x >> 15;
            }
            id11.fft(new double[][]{aReal, aImag}, false);

            double[] bReal = PrimitiveBuffers.id9(need);
            double[] bImag = PrimitiveBuffers.id9(need);
            for (int i = 0; i <= rB; i++) {
                int x = DigitUtils.mod(b[i], mod);
                bReal[i] = x & ((1 << 15) - 1);
                bImag[i] = x >> 15;
            }
            id11.fft(new double[][]{bReal, bImag}, false);


            for (int i = 0, j = 0; i <= j; i++, j = n - i) {
                double ari = aReal[i];
                double aii = aImag[i];
                double bri = bReal[i];
                double bii = bImag[i];
                double arj = aReal[j];
                double aij = aImag[j];
                double brj = bReal[j];
                double bij = bImag[j];

                double id6 = (ari + arj) / 2;
                double id5 = (aii - aij) / 2;
                double id3 = (aii + aij) / 2;
                double id14 = (arj - ari) / 2;

                double id1 = (bri + brj) / 2;
                double id8 = (bii - bij) / 2;
                double id16 = (bii + bij) / 2;
                double id10 = (brj - bri) / 2;

                aReal[i] = id6 * id1 - id5 * id8 - id3 * id10 - id14 * id16;
                aImag[i] = id6 * id8 + id5 * id1 + id3 * id16 - id14 * id10;
                bReal[i] = id6 * id16 - id5 * id10 + id3 * id1 - id14 * id8;
                bImag[i] = id6 * id10 + id5 * id16 + id3 * id8 + id14 * id1;

                if (i != j) {
                    id6 = (arj + ari) / 2;
                    id5 = (aij - aii) / 2;
                    id3 = (aij + aii) / 2;
                    id14 = (ari - arj) / 2;

                    id1 = (brj + bri) / 2;
                    id8 = (bij - bii) / 2;
                    id16 = (bij + bii) / 2;
                    id10 = (bri - brj) / 2;

                    aReal[j] = id6 * id1 - id5 * id8 - id3 * id10 - id14 * id16;
                    aImag[j] = id6 * id8 + id5 * id1 + id3 * id16 - id14 * id10;
                    bReal[j] = id6 * id16 - id5 * id10 + id3 * id1 - id14 * id8;
                    bImag[j] = id6 * id10 + id5 * id16 + id3 * id8 + id14 * id1;
                }
            }

            id11.fft(new double[][]{aReal, aImag}, true);
            id11.fft(new double[][]{bReal, bImag}, true);

            int[] ans = PrimitiveBuffers.id0(need);
            for (int i = 0; i < need; i++) {
                long aa = DigitUtils.mod(Math.round(aReal[i]), mod);
                long bb = DigitUtils.mod(Math.round(bReal[i]), mod);
                long cc = DigitUtils.mod(Math.round(aImag[i]), mod);
                ans[i] = DigitUtils.mod(aa + (bb << 15) + (cc << 30), mod);
            }

            PrimitiveBuffers.release(aReal, bReal, aImag, bImag);
            return ans;
        }

    }

    static class Debug {
        private boolean offline;
        private PrintStream out = System.err;

        public Debug(boolean enable) {
            offline = enable && System.getSecurityManager() == null;
        }

        public Debug debugArray(String name, int[] matrix) {
            if (offline) {
                debug(name, Arrays.toString(matrix));
            }
            return this;
        }

        public Debug debug(String name, String x) {
            if (offline) {
                out.printf("%s=%s", name, x);
                out.println();
            }
            return this;
        }

    }
}


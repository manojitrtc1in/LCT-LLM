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
            EPerpetualSubtraction solver = new EPerpetualSubtraction();
            solver.solve(1, in, out);
            out.close();
        }
    }

    static class EPerpetualSubtraction {
        int mod = 998244353;
        Modular modular = new Modular(mod);
        Power pow = new Power(modular);
        Debug debug = new Debug(true);
        NumberTheoryTransform ntt = new NumberTheoryTransform(modular);

        public void solve(int testNumber, FastInput in, FastOutput out) {
            int n = in.readInt();
            long m = in.readLong();

            int[] p = new int[n + 1];
            in.populate(p);

            Factorial factorial = new Factorial(n + 1, mod);
            int[] p0 = p;
            int[] p1 = new int[n + 1];
            int[] p2 = new int[n + 1];
            int[] p3 = new int[n + 1];

            {
                IntegerArrayList a = Polynomials.listBuffer.alloc();
                IntegerArrayList b = Polynomials.listBuffer.alloc();
                IntegerArrayList c = Polynomials.listBuffer.alloc();
                a.expandWith(0, n + 1);
                b.expandWith(0, n + 1);

                for (int i = 0; i <= n; i++) {
                    a.set(i, (int) ((long) factorial.fact(i) * p0[i] % mod));
                    b.set(i, factorial.invFact(i));
                }

                ntt.deltaNTT(a, b, c);
                c.expandWith(0, n + 1);
                for (int i = 0; i <= n; i++) {
                    p1[i] = (int) ((long) c.get(i) * factorial.invFact(i) % mod);
                }

                Polynomials.listBuffer.release(a);
                Polynomials.listBuffer.release(b);
                Polynomials.listBuffer.release(c);
            }

            for (int i = 0; i <= n; i++) {
                p2[i] = (int) ((long) pow.inversePower(i + 1, m) * p1[i] % mod);
            }

            {
                IntegerArrayList a = Polynomials.listBuffer.alloc();
                IntegerArrayList b = Polynomials.listBuffer.alloc();
                IntegerArrayList c = Polynomials.listBuffer.alloc();
                a.expandWith(0, n + 1);
                b.expandWith(0, n + 1);

                for (int i = 0; i <= n; i++) {
                    a.set(i, (int) ((long) factorial.fact(i) * p2[i] % mod));
                    b.set(i, DigitUtils.mod((i % 2 == 0 ? 1 : -1) * factorial.invFact(i), mod));
                }

                ntt.deltaNTT(a, b, c);
                c.expandWith(0, n + 1);
                for (int i = 0; i <= n; i++) {
                    p3[i] = (int) ((long) c.get(i) * factorial.invFact(i) % mod);
                }

                Polynomials.listBuffer.release(a);
                Polynomials.listBuffer.release(b);
                Polynomials.listBuffer.release(c);
            }

            for (int i = 0; i <= n; i++) {
                out.println(p3[i]);
            }

            debug.debug("p0", p0);
            debug.debug("p1", p1);
            debug.debug("p2", p2);
            debug.debug("p3", p3);
        }

    }

    static class PrimitiveRoot {
        private int[] factors;
        private Modular mod;
        private Power pow;
        int phi;

        public PrimitiveRoot(Modular x) {
            phi = x.getMod() - 1;
            mod = x;
            pow = new Power(mod);
            

            factors = Factorization.factorizeNumberPrime(phi).toArray();
        }

        public PrimitiveRoot(int x) {
            this(new Modular(x));
        }

        public int findMinPrimitiveRoot() {
            if (mod.getMod() == 2) {
                return 1;
            }
            return findMinPrimitiveRoot(2);
        }

        private int findMinPrimitiveRoot(int since) {
            for (int i = since; i < mod.m; i++) {
                boolean flag = true;
                for (int f : factors) {
                    if (pow.pow(i, phi / f) == 1) {
                        flag = false;
                        break;
                    }
                }
                if (flag) {
                    return i;
                }
            }
            return -1;
        }

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

        public void populate(int[] data) {
            for (int i = 0; i < data.length; i++) {
                data[i] = readInt();
            }
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

    }

    static class Modular {
        int m;

        public int getMod() {
            return m;
        }

        public Modular(int m) {
            this.m = m;
        }

        public Modular(long m) {
            this.m = (int) m;
            if (this.m != m) {
                throw new IllegalArgumentException();
            }
        }

        public Modular(double m) {
            this.m = (int) m;
            if (this.m != m) {
                throw new IllegalArgumentException();
            }
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

        public String toString() {
            return "mod " + m;
        }

    }

    static class Factorial {
        int[] fact;
        int[] inv;
        int mod;

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
            this(new int[limit + 1], new int[limit + 1], mod);
        }

        public int fact(int n) {
            return fact[n];
        }

        public int invFact(int n) {
            return inv[n];
        }

    }

    static class Log2 {
        public static int ceilLog(int x) {
            return 32 - Integer.numberOfLeadingZeros(x - 1);
        }

    }

    static class FastOutput implements AutoCloseable, Closeable, Appendable {
        private StringBuilder cache = new StringBuilder(10 << 20);
        private final Writer os;

        public FastOutput append(CharSequence csq) {
            cache.append(csq);
            return this;
        }

        public FastOutput append(CharSequence csq, int start, int end) {
            cache.append(csq, start, end);
            return this;
        }

        public FastOutput(Writer os) {
            this.os = os;
        }

        public FastOutput(OutputStream os) {
            this(new OutputStreamWriter(os));
        }

        public FastOutput append(char c) {
            cache.append(c);
            return this;
        }

        public FastOutput append(int c) {
            cache.append(c);
            return this;
        }

        public FastOutput println(int c) {
            return append(c).println();
        }

        public FastOutput println() {
            cache.append(System.lineSeparator());
            return this;
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

    static class IntegerArrayList implements Cloneable {
        private int size;
        private int cap;
        private int[] data;
        private static final int[] EMPTY = new int[0];

        public int[] getData() {
            return data;
        }

        public IntegerArrayList(int cap) {
            this.cap = cap;
            if (cap == 0) {
                data = EMPTY;
            } else {
                data = new int[cap];
            }
        }

        public IntegerArrayList(IntegerArrayList list) {
            this.size = list.size;
            this.cap = list.cap;
            this.data = Arrays.copyOf(list.data, size);
        }

        public IntegerArrayList() {
            this(0);
        }

        public void reverse(int l, int r) {
            SequenceUtils.reverse(data, l, r);
        }

        public void reverse() {
            reverse(0, size - 1);
        }

        public void ensureSpace(int req) {
            if (req > cap) {
                while (cap < req) {
                    cap = Math.max(cap + 10, 2 * cap);
                }
                data = Arrays.copyOf(data, cap);
            }
        }

        private void checkRange(int i) {
            if (i < 0 || i >= size) {
                throw new ArrayIndexOutOfBoundsException();
            }
        }

        public int get(int i) {
            checkRange(i);
            return data[i];
        }

        public void add(int x) {
            ensureSpace(size + 1);
            data[size++] = x;
        }

        public void addAll(int[] x, int offset, int len) {
            ensureSpace(size + len);
            System.arraycopy(x, offset, data, size, len);
            size += len;
        }

        public void addAll(IntegerArrayList list) {
            addAll(list.data, 0, list.size);
        }

        public void expandWith(int x, int len) {
            ensureSpace(len);
            while (size < len) {
                data[size++] = x;
            }
        }

        public void retain(int n) {
            if (n < 0) {
                throw new IllegalArgumentException();
            }
            if (n >= size) {
                return;
            }
            size = n;
        }

        public void set(int i, int x) {
            checkRange(i);
            data[i] = x;
        }

        public int size() {
            return size;
        }

        public int[] toArray() {
            return Arrays.copyOf(data, size);
        }

        public void clear() {
            size = 0;
        }

        public String toString() {
            return Arrays.toString(toArray());
        }

        public boolean equals(Object obj) {
            if (!(obj instanceof IntegerArrayList)) {
                return false;
            }
            IntegerArrayList other = (IntegerArrayList) obj;
            return SequenceUtils.equal(data, 0, size - 1, other.data, 0, other.size - 1);
        }

        public int hashCode() {
            int h = 1;
            for (int i = 0; i < size; i++) {
                h = h * 31 + Integer.hashCode(data[i]);
            }
            return h;
        }

        public IntegerArrayList clone() {
            IntegerArrayList ans = new IntegerArrayList();
            ans.addAll(this);
            return ans;
        }

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

    static class Polynomials {
        public static Buffer<IntegerArrayList> listBuffer = new Buffer<>(IntegerArrayList::new, list -> list.clear());

        public static int rankOf(IntegerArrayList p) {
            int[] data = p.getData();
            int r = p.size() - 1;
            while (r >= 0 && data[r] == 0) {
                r--;
            }
            return Math.max(0, r);
        }

        public static void normalize(IntegerArrayList list) {
            list.retain(rankOf(list) + 1);
        }

    }

    static class Power implements InverseNumber {
        final Modular modular;
        int modVal;

        public Power(Modular modular) {
            this.modular = modular;
            this.modVal = modular.getMod();
        }

        public int pow(int x, long n) {
            if (n == 0) {
                return modular.valueOf(1);
            }
            long r = pow(x, n >> 1);
            r = r * r % modVal;
            if ((n & 1) == 1) {
                r = r * x % modVal;
            }
            return (int) r;
        }

        public int pow(int x, int n) {
            if (n == 0) {
                return modular.valueOf(1);
            }
            long r = pow(x, n >> 1);
            r = r * r % modVal;
            if ((n & 1) == 1) {
                r = r * x % modVal;
            }
            return (int) r;
        }

        public int inverseByFermat(int x) {
            return pow(x, modVal - 2);
        }

        public int inversePower(int x, long n) {
            n = DigitUtils.mod(-n, modVal - 1);
            return pow(x, n);
        }

    }

    static class NumberTheoryTransform {
        private Modular modular;
        private int modVal;
        private Power power;
        private int g;
        private int[] wCache = new int[30];
        private int[] invCache = new int[30];
        public static Buffer<IntegerArrayList> listBuffer = Polynomials.listBuffer;

        public NumberTheoryTransform(Modular mod) {
            this(mod, mod.getMod() == 998244353 ? 3 : new PrimitiveRoot(mod.getMod()).findMinPrimitiveRoot());
        }

        public NumberTheoryTransform(Modular mod, int g) {
            this.modular = mod;
            this.modVal = mod.getMod();
            this.power = new Power(mod);
            this.g = g;
            for (int i = 0, until = wCache.length; i < until; i++) {
                int s = 1 << i;
                wCache[i] = power.pow(this.g, (modular.getMod() - 1) / 2 / s);
                invCache[i] = power.inverseByFermat(s);
            }
        }

        public void dotMul(int[] a, int[] b, int[] c, int m) {
            for (int i = 0, n = 1 << m; i < n; i++) {
                c[i] = modular.mul(a[i], b[i]);
            }
        }

        public void dft(int[] p, int m) {
            int n = 1 << m;

            int shift = 32 - Integer.numberOfTrailingZeros(n);
            for (int i = 1; i < n; i++) {
                int j = Integer.reverse(i << shift);
                if (i < j) {
                    int temp = p[i];
                    p[i] = p[j];
                    p[j] = temp;
                }
            }

            int w = 0;
            int t = 0;
            for (int d = 0; d < m; d++) {
                int w1 = wCache[d];
                int s = 1 << d;
                int s2 = s << 1;
                for (int i = 0; i < n; i += s2) {
                    w = 1;
                    for (int j = 0; j < s; j++) {
                        int a = i + j;
                        int b = a + s;
                        t = modular.mul(w, p[b]);
                        p[b] = modular.plus(p[a], -t);
                        p[a] = modular.plus(p[a], t);
                        w = modular.mul(w, w1);
                    }
                }
            }
        }

        public void idft(int[] p, int m) {
            dft(p, m);

            int n = 1 << m;
            int invN = invCache[m];

            p[0] = modular.mul(p[0], invN);
            p[n / 2] = modular.mul(p[n / 2], invN);
            for (int i = 1, until = n / 2; i < until; i++) {
                int a = p[n - i];
                p[n - i] = modular.mul(p[i], invN);
                p[i] = modular.mul(a, invN);
            }
        }

        private IntegerArrayList clone(IntegerArrayList list) {
            Polynomials.normalize(list);
            IntegerArrayList ans = listBuffer.alloc();
            ans.addAll(list);
            return ans;
        }

        public void deltaNTT(IntegerArrayList a, IntegerArrayList b, IntegerArrayList c) {
            a = clone(a);
            b = clone(b);
            int n = a.size();
            b.retain(n);
            a.reverse();

            int m = Log2.ceilLog(n + n - 1);
            a.expandWith(0, 1 << m);
            b.expandWith(0, 1 << m);
            c.clear();
            c.expandWith(0, 1 << m);

            dft(a.getData(), m);
            dft(b.getData(), m);
            dotMul(a.getData(), b.getData(), c.getData(), m);
            idft(c.getData(), m);
            c.retain(n);
            c.reverse();
            Polynomials.normalize(c);

            listBuffer.release(a);
            listBuffer.release(b);
        }

    }

    static class SequenceUtils {
        public static void swap(int[] data, int i, int j) {
            int tmp = data[i];
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

        public static boolean equal(int[] a, int al, int ar, int[] b, int bl, int br) {
            if ((ar - al) != (br - bl)) {
                return false;
            }
            for (int i = al, j = bl; i <= ar; i++, j++) {
                if (a[i] != b[j]) {
                    return false;
                }
            }
            return true;
        }

    }

    static interface InverseNumber {
    }

    static class Factorization {
        public static IntegerArrayList factorizeNumberPrime(int x) {
            IntegerArrayList ans = new IntegerArrayList();
            for (int i = 2; i * i <= x; i++) {
                if (x % i != 0) {
                    continue;
                }
                ans.add(i);
                while (x % i == 0) {
                    x /= i;
                }
            }
            if (x > 1) {
                ans.add(x);
            }
            return ans;
        }

    }

    static class DigitUtils {
        private DigitUtils() {
        }

        public static int mod(long x, int mod) {
            x %= mod;
            if (x < 0) {
                x += mod;
            }
            return (int) x;
        }

        public static int mod(int x, int mod) {
            x %= mod;
            if (x < 0) {
                x += mod;
            }
            return x;
        }

    }

    static class Debug {
        private boolean offline;
        private PrintStream out = System.err;
        static int[] empty = new int[0];

        public Debug(boolean enable) {
            offline = enable && System.getSecurityManager() == null;
        }

        public Debug debug(String name, Object x) {
            return debug(name, x, empty);
        }

        public Debug debug(String name, Object x, int... indexes) {
            if (offline) {
                if (x == null || !x.getClass().isArray()) {
                    out.append(name);
                    for (int i : indexes) {
                        out.printf("[%d]", i);
                    }
                    out.append("=").append("" + x);
                    out.println();
                } else {
                    indexes = Arrays.copyOf(indexes, indexes.length + 1);
                    if (x instanceof byte[]) {
                        byte[] arr = (byte[]) x;
                        for (int i = 0; i < arr.length; i++) {
                            indexes[indexes.length - 1] = i;
                            debug(name, arr[i], indexes);
                        }
                    } else if (x instanceof short[]) {
                        short[] arr = (short[]) x;
                        for (int i = 0; i < arr.length; i++) {
                            indexes[indexes.length - 1] = i;
                            debug(name, arr[i], indexes);
                        }
                    } else if (x instanceof boolean[]) {
                        boolean[] arr = (boolean[]) x;
                        for (int i = 0; i < arr.length; i++) {
                            indexes[indexes.length - 1] = i;
                            debug(name, arr[i], indexes);
                        }
                    } else if (x instanceof char[]) {
                        char[] arr = (char[]) x;
                        for (int i = 0; i < arr.length; i++) {
                            indexes[indexes.length - 1] = i;
                            debug(name, arr[i], indexes);
                        }
                    } else if (x instanceof int[]) {
                        int[] arr = (int[]) x;
                        for (int i = 0; i < arr.length; i++) {
                            indexes[indexes.length - 1] = i;
                            debug(name, arr[i], indexes);
                        }
                    } else if (x instanceof float[]) {
                        float[] arr = (float[]) x;
                        for (int i = 0; i < arr.length; i++) {
                            indexes[indexes.length - 1] = i;
                            debug(name, arr[i], indexes);
                        }
                    } else if (x instanceof double[]) {
                        double[] arr = (double[]) x;
                        for (int i = 0; i < arr.length; i++) {
                            indexes[indexes.length - 1] = i;
                            debug(name, arr[i], indexes);
                        }
                    } else if (x instanceof long[]) {
                        long[] arr = (long[]) x;
                        for (int i = 0; i < arr.length; i++) {
                            indexes[indexes.length - 1] = i;
                            debug(name, arr[i], indexes);
                        }
                    } else {
                        Object[] arr = (Object[]) x;
                        for (int i = 0; i < arr.length; i++) {
                            indexes[indexes.length - 1] = i;
                            debug(name, arr[i], indexes);
                        }
                    }
                }
            }
            return this;
        }

    }
}


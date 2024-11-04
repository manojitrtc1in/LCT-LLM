import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.util.Arrays;
import java.util.PriorityQueue;
import java.util.AbstractQueue;
import java.util.Deque;
import java.util.function.Supplier;
import java.util.ArrayList;
import java.io.OutputStreamWriter;
import java.io.OutputStream;
import java.util.Collection;
import java.io.IOException;
import java.io.UncheckedIOException;
import java.util.function.Consumer;
import java.util.List;
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
            TaskG solver = new TaskG();
            solver.solve(1, in, out);
            out.close();
        }
    }

    static class TaskG {
        public void solve(int testNumber, FastInput in, FastOutput out) {
            int n = in.readInt();
            int[] cnts = new int[3000000 + 1];
            for (int i = 0; i < n; i++) {
                cnts[in.readInt()]++;
            }
            List<id0> polynomials = new ArrayList<>();
            for (int i = 0; i <= 3000000; i++) {
                if (cnts[i] == 0) {
                    continue;
                }
                id0 list = new id0(cnts[i] + 1);
                list.expandWith(1, cnts[i] + 1);
                polynomials.add(list);
            }

            Modular mod = new Modular(998244353);
            id0 ans = new id0();
            id6 ntt = new id6(mod.getMod());
            ntt.id1(polynomials.toArray(new id0[0]), ans);
            out.println(ans.get(n / 2));
        }

    }

    static class Power implements InverseNumber {
        final Modular modular;
        int modVal;

        public Power(Modular modular) {
            this.modular = modular;
            this.modVal = modular.getMod();
        }

        public Power(int mod) {
            this(new Modular(mod));
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

        public int id3(int x) {
            return pow(x, modVal - 2);
        }

    }

    static class SequenceUtils {
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

    static class id6 {
        private int mod;
        private Power power;
        private int g;
        private int[] wCache = new int[30];
        private int[] invCache = new int[30];
        public static Buffer<id0> listBuffer = Polynomials.listBuffer;
        private static final int id4 = 128;

        public id6(int mod) {
            this(mod, mod == 998244353 ? 3 : new PrimitiveRoot(mod).id2());
        }

        public id6(int mod, int g) {
            this.mod = mod;
            this.power = new Power(mod);
            this.g = g;
            for (int i = 0, until = wCache.length; i < until; i++) {
                int s = 1 << i;
                wCache[i] = power.pow(this.g, (mod - 1) / 2 / s);
                invCache[i] = power.id3(s);
            }
        }

        public void dotMul(int[] a, int[] b, int[] c, int m) {
            for (int i = 0, n = 1 << m; i < n; i++) {
                c[i] = (int) ((long) a[i] * b[i] % mod);
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
                        t = (int) ((long) w * p[b] % mod);
                        p[b] = DigitUtils.modsub(p[a], t, mod);
                        p[a] = DigitUtils.modplus(p[a], t, mod);
                        w = (int) ((long) w * w1 % mod);
                    }
                }
            }
        }

        public void idft(int[] p, int m) {
            dft(p, m);

            int n = 1 << m;
            long invN = invCache[m];

            p[0] = (int) ((long) p[0] * invN % mod);
            p[n / 2] = (int) (p[n / 2] * invN % mod);
            for (int i = 1, until = n / 2; i < until; i++) {
                int a = p[n - i];
                p[n - i] = (int) (p[i] * invN % mod);
                p[i] = (int) (a * invN % mod);
            }
        }

        public void id1(id0[] lists, id0 ans) {
            PriorityQueue<id0> pqs = new PriorityQueue<>(lists.length, (a, b) -> a.size() - b.size());
            for (id0 list : lists) {
                id0 clone = listBuffer.alloc();
                clone.addAll(list);
                pqs.add(clone);
            }
            while (pqs.size() > 1) {
                id0 a = pqs.remove();
                id0 b = pqs.remove();
                if (a.size() < id4 || b.size() < id4) {
                    id0 c = listBuffer.alloc();
                    Polynomials.mul(a, b, c, mod);
                    listBuffer.release(a);
                    listBuffer.release(b);
                    pqs.add(c);
                } else {
                    id7(a, b);
                    listBuffer.release(b);
                    pqs.add(a);
                }
            }

            id0 last = pqs.remove();
            ans.clear();
            ans.addAll(last);
            listBuffer.release(last);
            return;
        }

        private void id7(id0 a, id0 b) {
            int rankAns = a.size() - 1 + b.size() - 1;
            int proper = Log2.ceilLog(rankAns + 1);
            a.expandWith(0, (1 << proper));
            b.expandWith(0, (1 << proper));
            dft(a.getData(), proper);
            dft(b.getData(), proper);
            dotMul(a.getData(), b.getData(), a.getData(), proper);
            idft(a.getData(), proper);
            Polynomials.normalize(a);
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

    static class Factorization {
        public static id0 id5(int x) {
            id0 ans = new id0();
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

    static interface InverseNumber {
    }

    static class PrimitiveRoot {
        private int[] factors;
        private int mod;
        private Power pow;
        int phi;

        public PrimitiveRoot(int x) {
            phi = x - 1;
            mod = x;
            pow = new Power(mod);
            factors = Factorization.id5(phi).toArray();
        }

        public int id2() {
            if (mod == 2) {
                return 1;
            }
            return id2(2);
        }

        private int id2(int since) {
            for (int i = since; i < mod; i++) {
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

    static class DigitUtils {
        private DigitUtils() {
        }

        public static int modsub(int a, int b, int mod) {
            int ans = a - b;
            if (ans < 0) {
                ans += mod;
            }
            return ans;
        }

        public static int modplus(int a, int b, int mod) {
            int ans = a + b;
            if (ans >= mod) {
                ans -= mod;
            }
            return ans;
        }

    }

    static class Polynomials {
        public static Buffer<id0> listBuffer = new Buffer<>(id0::new, list -> list.clear());

        public static int rankOf(id0 p) {
            int[] data = p.getData();
            int r = p.size() - 1;
            while (r >= 0 && data[r] == 0) {
                r--;
            }
            return Math.max(0, r);
        }

        public static void normalize(id0 list) {
            list.retain(rankOf(list) + 1);
        }

        public static void mul(id0 a, id0 b, id0 c, int mod) {
            int rA = rankOf(a);
            int rB = rankOf(b);
            c.clear();
            c.expandWith(0, rA + rB + 1);
            int[] aData = a.getData();
            int[] bData = b.getData();
            int[] cData = c.getData();
            for (int i = 0; i <= rA; i++) {
                for (int j = 0; j <= rB; j++) {
                    cData[i + j] = (int) ((cData[i + j] + (long) aData[i] * bData[j]) % mod);
                }
            }
        }

    }

    static class id0 implements Cloneable {
        private int size;
        private int cap;
        private int[] data;
        private static final int[] EMPTY = new int[0];

        public int[] getData() {
            return data;
        }

        public id0(int cap) {
            this.cap = cap;
            if (cap == 0) {
                data = EMPTY;
            } else {
                data = new int[cap];
            }
        }

        public id0(id0 list) {
            this.size = list.size;
            this.cap = list.cap;
            this.data = Arrays.copyOf(list.data, size);
        }

        public id0() {
            this(0);
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

        public void addAll(id0 list) {
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
            if (!(obj instanceof id0)) {
                return false;
            }
            id0 other = (id0) obj;
            return SequenceUtils.equal(data, 0, size - 1, other.data, 0, other.size - 1);
        }

        public int hashCode() {
            int h = 1;
            for (int i = 0; i < size; i++) {
                h = h * 31 + Integer.hashCode(data[i]);
            }
            return h;
        }

        public id0 clone() {
            id0 ans = new id0();
            ans.addAll(this);
            return ans;
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

        public String toString() {
            return "mod " + m;
        }

    }
}


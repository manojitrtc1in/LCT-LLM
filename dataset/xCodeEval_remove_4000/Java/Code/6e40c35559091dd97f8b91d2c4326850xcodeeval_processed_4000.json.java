import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.util.Arrays;
import java.util.Deque;
import java.util.function.Supplier;
import java.io.OutputStreamWriter;
import java.io.OutputStream;
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
        Thread thread = new Thread(null, new TaskAdapter(), "", 1 << 27);
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
            id5 solver = new id5();
            solver.solve(1, in, out);
            out.close();
        }
    }

    static class id5 {
        public void solve(int testNumber, FastInput in, FastOutput out) {
            long n = in.readLong();
            int k = in.readInt();

            Modular mod = new Modular(1000000007);
            Power power = new Power(mod);

            int items = 200;
            int[] fib = new int[items];
            fib[0] = 1;
            fib[1] = 2;
            int[] a = new int[items];
            for (int i = 2; i < items; i++) {
                fib[i] = mod.plus(fib[i - 1], fib[i - 2]);
            }
            for (int i = 0; i < items; i++) {
                a[i] = mod.mul(fib[i], power.pow(i + 1, k));
                if (i > 0) {
                    a[i] = mod.plus(a[i], a[i - 1]);
                }
            }

            IntegerList seq = new IntegerList();
            seq.addAll(a);
            id9 solver = id9.id2(seq, mod);
            int ans = solver.solve(n - 1, seq);

            out.println(ans);
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

        public int subtract(int x, int y) {
            return valueOf(x - y);
        }

        public String toString() {
            return "mod " + m;
        }

    }

    static class IntegerList implements Cloneable {
        private int size;
        private int cap;
        private int[] data;
        private static final int[] EMPTY = new int[0];

        public int[] getData() {
            return data;
        }

        public IntegerList(int cap) {
            this.cap = cap;
            if (cap == 0) {
                data = EMPTY;
            } else {
                data = new int[cap];
            }
        }

        public IntegerList(IntegerList list) {
            this.size = list.size;
            this.cap = list.cap;
            this.data = Arrays.copyOf(list.data, size);
        }

        public IntegerList() {
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
                throw new ArrayIndexOutOfBoundsException("index " + i + " out of range");
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

        public void addAll(int[] x) {
            addAll(x, 0, x.length);
        }

        public void addAll(int[] x, int offset, int len) {
            ensureSpace(size + len);
            System.arraycopy(x, offset, data, size, len);
            size += len;
        }

        public void addAll(IntegerList list) {
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
            if (!(obj instanceof IntegerList)) {
                return false;
            }
            IntegerList other = (IntegerList) obj;
            return SequenceUtils.equal(data, 0, size - 1, other.data, 0, other.size - 1);
        }

        public int hashCode() {
            int h = 1;
            for (int i = 0; i < size; i++) {
                h = h * 31 + Integer.hashCode(data[i]);
            }
            return h;
        }

        public IntegerList clone() {
            IntegerList ans = new IntegerList();
            ans.addAll(this);
            return ans;
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

    static class id0 {
        private IntegerList cm;
        int m = -1;
        int dm;
        private IntegerList cn;
        private IntegerList buf;
        private IntegerList seq;
        private Modular mod;
        private Power pow;

        public id0(Modular mod, int cap) {
            cm = new IntegerList(cap + 1);
            cn = new IntegerList(cap + 1);
            seq = new IntegerList(cap + 1);
            buf = new IntegerList(cap + 1);
            cn.add(1);

            this.mod = mod;
            this.pow = new Power(mod);
        }

        public id0(Modular mod) {
            this(mod, 0);
        }

        private int estimateDelta() {
            int n = seq.size() - 1;
            int ans = 0;
            int[] cnData = cn.getData();
            int[] seqData = seq.getData();
            for (int i = 0, until = cn.size(); i < until; i++) {
                ans = mod.plus(ans, mod.mul(cnData[i], seqData[n - i]));
            }
            return ans;
        }

        public void add(int x) {
            x = mod.valueOf(x);
            int n = seq.size();

            seq.add(x);
            int dn = estimateDelta();
            if (dn == 0) {
                return;
            }

            if (m < 0) {
                cm.clear();
                cm.addAll(cn);
                dm = dn;
                m = n;

                cn.expandWith(0, n + 2);
                return;
            }

            int ln = cn.size() - 1;
            int len = Math.max(ln, n + 1 - ln);
            buf.clear();
            buf.addAll(cn);
            buf.expandWith(0, len + 1);

            int factor = mod.mul(dn, pow.id7(dm));

            int[] bufData = buf.getData();
            int[] cmData = cm.getData();
            for (int i = n - m, until = n - m + cm.size(); i < until; i++) {
                bufData[i] = mod.subtract(bufData[i], mod.mul(factor, cmData[i - (n - m)]));
            }

            if (cn.size() < buf.size()) {
                IntegerList tmp = cm;
                cm = cn;
                cn = tmp;
                m = n;
                dm = dn;
            }
            {
                IntegerList tmp = cn;
                cn = buf;
                buf = tmp;
            }


        }

        public int length() {
            return cn.size() - 1;
        }

        public String toString() {
            return cn.toString();
        }

        public int codeAt(int i) {
            return mod.valueOf(-cn.get(i));
        }

    }

    static class Buffer<T> {
        private Deque<T> deque;
        private Supplier<T> supplier;
        private Consumer<T> cleaner;

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
            return deque.isEmpty() ? supplier.get() : deque.removeFirst();
        }

        public void release(T e) {
            cleaner.accept(e);
            deque.addLast(e);
        }

    }

    static class FastOutput implements AutoCloseable, Closeable {
        private StringBuilder cache = new StringBuilder(10 << 20);
        private final Writer os;

        public FastOutput(Writer os) {
            this.os = os;
        }

        public FastOutput(OutputStream os) {
            this(new OutputStreamWriter(os));
        }

        public FastOutput println(int c) {
            cache.append(c).append('\n');
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

    static class id9 {
        Modular mod;
        IntegerList coe;
        IntegerList p;
        IntegerList remainder;
        Power pow;
        int n;

        private id9(IntegerList coe, Modular mod) {
            this.coe = coe;
            this.mod = mod;
            n = coe.size();
            pow = new Power(mod);
            remainder = new IntegerList(coe.size());
            p = new IntegerList(coe.size() + 1);
            for (int i = n - 1; i >= 0; i--) {
                p.add(mod.valueOf(-coe.get(i)));
            }
            p.add(1);
        }

        public static id9 id6(IntegerList coe, Modular mod) {
            return new id9(coe, mod);
        }

        public static id9 id2(IntegerList seq, Modular mod) {
            id0 id10 = new id0(mod, seq.size());
            for (int i = 0; i < seq.size(); i++) {
                id10.add(seq.get(i));
            }
            IntegerList coes = new IntegerList(id10.length());
            for (int i = 1; i <= id10.length(); i++) {
                coes.add(id10.codeAt(i));
            }
            return id6(coes, mod);
        }

        private int solve(IntegerList a) {
            int ans = 0;
            remainder.expandWith(0, n);
            for (int i = 0; i < n; i++) {
                ans = mod.plus(ans, mod.mul(remainder.get(i), a.get(i)));
            }
            return ans;
        }

        public int solve(long k, IntegerList a) {
            if (k < a.size()) {
                return a.get((int) k);
            }
            Polynomials.module(k, p, remainder, pow);
            return solve(a);
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

    static class id11 {
        private long x;
        private long y;
        private long g;

        public long getX() {
            return x;
        }

        public long id3(long a, long b) {
            if (a >= b) {
                g = id1(a, b);
            } else {
                g = id1(b, a);
                long tmp = x;
                x = y;
                y = tmp;
            }
            return g;
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

    static class Polynomials {
        public static Buffer<IntegerList> listBuffer = new Buffer<>(IntegerList::new, list -> list.clear());
        private static id11 id8 = new id11();

        public static int rankOf(IntegerList p) {
            int[] data = p.getData();
            int r = p.size() - 1;
            while (r >= 0 && data[r] == 0) {
                r--;
            }
            return Math.max(0, r);
        }

        public static void normalize(IntegerList list) {
            list.retain(rankOf(list) + 1);
        }

        public static void mul(IntegerList a, IntegerList b, IntegerList c, Modular mod) {
            int rA = rankOf(a);
            int rB = rankOf(b);
            c.clear();
            c.expandWith(0, rA + rB + 1);
            int[] aData = a.getData();
            int[] bData = b.getData();
            int[] cData = c.getData();
            for (int i = 0; i <= rA; i++) {
                for (int j = 0; j <= rB; j++) {
                    cData[i + j] = mod.plus(cData[i + j], mod.mul(aData[i], bData[j]));
                }
            }
        }

        public static void divide(IntegerList a, IntegerList b, IntegerList c, IntegerList remainder, Power pow) {
            Modular mod = pow.id4();
            int rA = rankOf(a);
            int rB = rankOf(b);

            if (rA < rB) {
                c.clear();
                c.add(0);
                remainder.clear();
                remainder.addAll(a);
                return;
            }

            int rC = Math.max(0, rA - rB);
            c.clear();
            c.expandWith(0, rC + 1);
            remainder.clear();
            remainder.addAll(a);

            int[] bData = b.getData();
            int[] cData = c.getData();
            int[] rData = remainder.getData();

            if (id8.id3(b.get(rB), mod.getMod()) != 1) {
                throw new IllegalArgumentException();
            }
            int inv = mod.valueOf(id8.getX());
            for (int i = rA, j = rC; i >= rB; i--, j--) {
                if (rData[i] == 0) {
                    continue;
                }
                int factor = mod.mul(-rData[i], inv);
                cData[j] = mod.valueOf(-factor);
                for (int k = rB; k >= 0; k--) {
                    rData[k + j] = mod.plus(rData[k + j], mod.mul(factor, bData[k]));
                }
            }

            normalize(remainder);
        }

        public static void module(long k, IntegerList p, IntegerList remainder, Power pow) {
            int rP = rankOf(p);
            if (rP == 0) {
                remainder.clear();
                remainder.add(0);
                return;
            }

            IntegerList a = listBuffer.alloc();
            IntegerList c = listBuffer.alloc();

            module(k, a, p, c, remainder, rP, pow);

            listBuffer.release(a);
            listBuffer.release(c);
        }

        private static void module(long k, IntegerList a, IntegerList b, IntegerList c, IntegerList remainder, int rb, Power pow) {
            Modular mod = pow.id4();
            if (k < rb) {
                remainder.clear();
                remainder.expandWith(0, (int) k + 1);
                remainder.set((int) k, 1);
                return;
            }
            module(k / 2, a, b, c, remainder, rb, pow);
            mul(remainder, remainder, a, mod);
            if (k % 2 == 1) {
                int ra = rankOf(a);
                a.expandWith(0, ra + 2);
                int[] aData = a.getData();
                for (int i = ra; i >= 0; i--) {
                    aData[i + 1] = aData[i];
                }
                aData[0] = 0;
            }
            divide(a, b, c, remainder, pow);
        }

    }

    static class Power {
        final Modular modular;

        public Modular id4() {
            return modular;
        }

        public Power(Modular modular) {
            this.modular = modular;
        }

        public int pow(int x, int n) {
            if (n == 0) {
                return modular.valueOf(1);
            }
            long r = pow(x, n >> 1);
            r = modular.valueOf(r * r);
            if ((n & 1) == 1) {
                r = modular.valueOf(r * x);
            }
            return (int) r;
        }

        public int id7(int x) {
            return pow(x, modular.m - 2);
        }

    }
}


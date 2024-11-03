import java.util.*;
import java.io.*;

public class Main {
    private static final void solve() throws IOException {
        int nn = ni(), n = nn >> 1;
        var fa = new id27(998244353);
        var x = fa.create(0);
        var y = fa.create(0);
        for (int i = nn - 1, j = n; i >= 0; i -= 4, j -= 2) {
            if (i >= 0)
                x.id20(fa.combination(i, j));
            if (i >= 1)
                y.id20(fa.combination(i - 1, j));
            if (i >= 2)
                y.id20(fa.combination(i - 2, j - 1));
            if (i >= 3)
                x.id20(fa.combination(i - 3, j - 1));
        }
        ou.println(x + " " + y + " 1");
    }

    public static void main(String[] args) throws IOException {
        for (int i = 0, t = ni(); i < t; i++)
            solve();
        ou.flush();
    }

    private static final int ni() throws IOException {
        return sc.nextInt();
    }

    private static final int[] ni(int n) throws IOException {
        return sc.id13(n);
    }

    private static final long nl() throws IOException {
        return sc.nextLong();
    }

    private static final long[] nl(int n) throws IOException {
        return sc.id28(n);
    }

    private static final String ns() throws IOException {
        return sc.next();
    }

    private static final id22 sc = new id22();
    private static final id2 ou = new id2();
}

class id27 {
    private final ModArithmetic ma;
    private final int mod;

    private final boolean id18;
    private final ModArithmetic.id8 id4;

    private ArrayList<Integer> factorial;

    public id27(int mod) {
        this.ma = ModArithmetic.of(mod);
        this.id18 = ma instanceof ModArithmetic.id8;
        this.id4 = id18 ? (ModArithmetic.id8) ma : null;
        this.mod = mod;

        this.factorial = new ArrayList<>();
    }

    public id27(double mod) {
        this((int) mod);
    }

    public ModInt create(long value) {
        if ((value %= mod) < 0)
            value += mod;
        if (id18) {
            return new ModInt(id4.generate(value));
        } else {
            return new ModInt((int) value);
        }
    }

    private void id10(int max) {
        factorial.ensureCapacity(max + 1);
        if (factorial.size() == 0)
            factorial.add(1);
        for (int i = factorial.size(); i <= max; i++) {
            if (id18)
                factorial.add(ma.mul(factorial.get(i - 1), id4.generate(i)));
            else
                factorial.add(ma.mul(factorial.get(i - 1), i));
        }
    }

    public ModInt factorial(int i) {
        id10(i);
        return create(factorial.get(i));
    }

    public ModInt permutation(int n, int r) {
        if (n < 0 || r < 0 || n < r)
            return create(0);
        id10(n);
        return create(ma.div(factorial.get(n), factorial.get(r)));
    }

    public ModInt combination(int n, int r) {
        if (n < 0 || r < 0 || n < r)
            return create(0);
        id10(n);
        return create(ma.div(factorial.get(n), ma.mul(factorial.get(r), factorial.get(n - r))));
    }

    public int getMod() {
        return mod;
    }

    public class ModInt {
        private int value;

        private ModInt(int value) {
            this.value = value;
        }

        public int mod() {
            return mod;
        }

        public int value() {
            if (id18) {
                return id4.reduce(value);
            }
            return value;
        }

        public ModInt add(ModInt mi) {
            return new ModInt(ma.add(value, mi.value));
        }

        public ModInt add(ModInt mi1, ModInt mi2) {
            return new ModInt(ma.add(value, mi1.value)).id20(mi2);
        }

        public ModInt add(ModInt mi1, ModInt mi2, ModInt mi3) {
            return new ModInt(ma.add(value, mi1.value)).id20(mi2).id20(mi3);
        }

        public ModInt add(ModInt mi1, ModInt mi2, ModInt mi3, ModInt mi4) {
            return new ModInt(ma.add(value, mi1.value)).id20(mi2).id20(mi3).id20(mi4);
        }

        public ModInt add(ModInt mi1, ModInt... mis) {
            ModInt mi = add(mi1);
            for (ModInt m : mis)
                mi.id20(m);
            return mi;
        }

        public ModInt add(long mi) {
            return new ModInt(ma.add(value, ma.remainder(mi)));
        }

        public ModInt sub(ModInt mi) {
            return new ModInt(ma.sub(value, mi.value));
        }

        public ModInt sub(long mi) {
            return new ModInt(ma.sub(value, ma.remainder(mi)));
        }

        public ModInt mul(ModInt mi) {
            return new ModInt(ma.mul(value, mi.value));
        }

        public ModInt mul(ModInt mi1, ModInt mi2) {
            return new ModInt(ma.mul(value, mi1.value)).id9(mi2);
        }

        public ModInt mul(ModInt mi1, ModInt mi2, ModInt mi3) {
            return new ModInt(ma.mul(value, mi1.value)).id9(mi2).id9(mi3);
        }

        public ModInt mul(ModInt mi1, ModInt mi2, ModInt mi3, ModInt mi4) {
            return new ModInt(ma.mul(value, mi1.value)).id9(mi2).id9(mi3).id9(mi4);
        }

        public ModInt mul(ModInt mi1, ModInt... mis) {
            ModInt mi = mul(mi1);
            for (ModInt m : mis)
                mi.id9(m);
            return mi;
        }

        public ModInt mul(long mi) {
            return new ModInt(ma.mul(value, ma.remainder(mi)));
        }

        public ModInt div(ModInt mi) {
            return new ModInt(ma.div(value, mi.value));
        }

        public ModInt div(long mi) {
            return new ModInt(ma.div(value, ma.remainder(mi)));
        }

        public ModInt inv() {
            return new ModInt(ma.inv(value));
        }

        public ModInt pow(long b) {
            return new ModInt(ma.pow(value, b));
        }

        public ModInt pow(ModInt mi) {
            return new ModInt(ma.pow(value, mi.value));
        }

        public ModInt id20(ModInt mi) {
            this.value = ma.add(value, mi.value);
            return this;
        }

        public ModInt id20(ModInt mi1, ModInt mi2) {
            return id20(mi1).id20(mi2);
        }

        public ModInt id20(ModInt mi1, ModInt mi2, ModInt mi3) {
            return id20(mi1).id20(mi2).id20(mi3);
        }

        public ModInt id20(ModInt mi1, ModInt mi2, ModInt mi3, ModInt mi4) {
            return id20(mi1).id20(mi2).id20(mi3).id20(mi4);
        }

        public ModInt id20(ModInt... mis) {
            for (ModInt m : mis)
                id20(m);
            return this;
        }

        public ModInt id20(long mi) {
            this.value = ma.add(value, ma.remainder(mi));
            return this;
        }

        public ModInt id21(ModInt mi) {
            this.value = ma.sub(value, mi.value);
            return this;
        }

        public ModInt id21(long mi) {
            this.value = ma.sub(value, ma.remainder(mi));
            return this;
        }

        public ModInt id9(ModInt mi) {
            this.value = ma.mul(value, mi.value);
            return this;
        }

        public ModInt id9(ModInt mi1, ModInt mi2) {
            return id9(mi1).id9(mi2);
        }

        public ModInt id9(ModInt mi1, ModInt mi2, ModInt mi3) {
            return id9(mi1).id9(mi2).id9(mi3);
        }

        public ModInt id9(ModInt mi1, ModInt mi2, ModInt mi3, ModInt mi4) {
            return id9(mi1).id9(mi2).id9(mi3).id9(mi4);
        }

        public ModInt id9(ModInt... mis) {
            for (ModInt m : mis)
                id9(m);
            return this;
        }

        public ModInt id9(long mi) {
            this.value = ma.mul(value, ma.remainder(mi));
            return this;
        }

        public ModInt id3(ModInt mi) {
            this.value = ma.div(value, mi.value);
            return this;
        }

        public ModInt id3(long mi) {
            this.value = ma.div(value, ma.remainder(mi));
            return this;
        }

        public ModInt id26(ModInt mi) {
            this.value = ma.pow(value, mi.value());
            return this;
        }

        public ModInt id26(long mi) {
            this.value = ma.pow(value, mi);
            return this;
        }

        @Override
        public String toString() {
            return String.valueOf(value());
        }

        @Override
        public boolean equals(Object o) {
            if (o instanceof ModInt) {
                ModInt mi = (ModInt) o;
                return mod() == mi.mod() && value() == mi.value();
            }
            return false;
        }

        @Override
        public int hashCode() {
            return (1 * 37 + mod()) * 37 + value();
        }
    }

    private static abstract class ModArithmetic {
        abstract int mod();

        abstract int remainder(long value);

        abstract int add(int a, int b);

        abstract int sub(int a, int b);

        abstract int mul(int a, int b);

        int div(int a, int b) {
            return mul(a, inv(b));
        }

        int inv(int a) {
            int b = mod();
            if (b == 1)
                return 0;
            long u = 1, v = 0;
            while (b >= 1) {
                int t = a / b;
                a -= t * b;
                int tmp1 = a;
                a = b;
                b = tmp1;
                u -= t * v;
                long tmp2 = u;
                u = v;
                v = tmp2;
            }
            if (a != 1)
                throw new ArithmeticException("divide by zero");
            return remainder(u);
        }

        int pow(int a, long b) {
            if (b < 0)
                throw new ArithmeticException("negative power");
            int r = 1;
            int x = a;
            while (b > 0) {
                if ((b & 1) == 1)
                    r = mul(r, x);
                x = mul(x, x);
                b >>= 1;
            }
            return r;
        }

        static ModArithmetic of(int mod) {
            if (mod <= 0) {
                throw new IllegalArgumentException();
            } else if (mod == 1) {
                return new id7();
            } else if (mod == 2) {
                return new id19();
            } else if (mod == 998244353) {
                return new id0();
            } else if (mod == 1000000007) {
                return new id5();
            } else if ((mod & 1) == 1) {
                return new id8(mod);
            } else {
                return new id6(mod);
            }
        }

        private static final class id7 extends ModArithmetic {
            int mod() {
                return 1;
            }

            int remainder(long value) {
                return 0;
            }

            int add(int a, int b) {
                return 0;
            }

            int sub(int a, int b) {
                return 0;
            }

            int mul(int a, int b) {
                return 0;
            }

            int pow(int a, long b) {
                return 0;
            }
        }

        private static final class id19 extends ModArithmetic {
            int mod() {
                return 2;
            }

            int remainder(long value) {
                return (int) (value & 1);
            }

            int add(int a, int b) {
                return a ^ b;
            }

            int sub(int a, int b) {
                return a ^ b;
            }

            int mul(int a, int b) {
                return a & b;
            }
        }

        private static final class id0 extends ModArithmetic {
            private final int mod = 998244353;

            int mod() {
                return mod;
            }

            int remainder(long value) {
                return (int) ((value %= mod) < 0 ? value + mod : value);
            }

            int add(int a, int b) {
                int res = a + b;
                return res >= mod ? res - mod : res;
            }

            int sub(int a, int b) {
                int res = a - b;
                return res < 0 ? res + mod : res;
            }

            int mul(int a, int b) {
                return (int) (((long) a * b) % mod);
            }
        }

        private static final class id5 extends ModArithmetic {
            private final int mod = 1000000007;

            int mod() {
                return mod;
            }

            int remainder(long value) {
                return (int) ((value %= mod) < 0 ? value + mod : value);
            }

            int add(int a, int b) {
                int res = a + b;
                return res >= mod ? res - mod : res;
            }

            int sub(int a, int b) {
                int res = a - b;
                return res < 0 ? res + mod : res;
            }

            int mul(int a, int b) {
                return (int) (((long) a * b) % mod);
            }
        }

        private static final class id8 extends id11 {
            private final long negInv;
            private final long r2;

            private id8(int mod) {
                super(mod);
                long inv = 0;
                long s = 1, t = 0;
                for (int i = 0; i < 32; i++) {
                    if ((t & 1) == 0) {
                        t += mod;
                        inv += s;
                    }
                    t >>= 1;
                    s <<= 1;
                }
                long r = (1l << 32) % mod;
                this.negInv = inv;
                this.r2 = (r * r) % mod;
            }

            private int generate(long x) {
                return reduce(x * r2);
            }

            private int reduce(long x) {
                x = (x + ((x * negInv) & 0xffff_ffffl) * mod) >>> 32;
                return (int) (x < mod ? x : x - mod);
            }

            @Override
            int remainder(long value) {
                return generate((value %= mod) < 0 ? value + mod : value);
            }

            @Override
            int mul(int a, int b) {
                return reduce((long) a * b);
            }

            @Override
            int inv(int a) {
                return super.inv(reduce(a));
            }

            @Override
            int pow(int a, long b) {
                return generate(super.pow(a, b));
            }
        }

        private static final class id6 extends id11 {
            private static final long mask = 0xffff_ffffl;
            private final long mh;
            private final long ml;

            private id6(int mod) {
                super(mod);
                long a = (1l << 32) / mod;
                long b = (1l << 32) % mod;
                long m = a * a * mod + 2 * a * b + (b * b) / mod;
                mh = m >>> 32;
                ml = m & mask;
            }

            private int reduce(long x) {
                long z = (x & mask) * ml;
                z = (x & mask) * mh + (x >>> 32) * ml + (z >>> 32);
                z = (x >>> 32) * mh + (z >>> 32);
                x -= z * mod;
                return (int) (x < mod ? x : x - mod);
            }

            @Override
            int remainder(long value) {
                return (int) ((value %= mod) < 0 ? value + mod : value);
            }

            @Override
            int mul(int a, int b) {
                return reduce((long) a * b);
            }
        }

        private static class id11 extends ModArithmetic {
            final int mod;

            id11(int mod) {
                this.mod = mod;
            }

            int mod() {
                return mod;
            }

            int remainder(long value) {
                return (int) ((value %= mod) < 0 ? value + mod : value);
            }

            int add(int a, int b) {
                int sum = a + b;
                return sum >= mod ? sum - mod : sum;
            }

            int sub(int a, int b) {
                int sum = a - b;
                return sum < 0 ? sum + mod : sum;
            }

            int mul(int a, int b) {
                return (int) (((long) a * b) % mod);
            }
        }
    }
}

final class id22 extends FilterInputStream {
    protected final byte[] buf;
    protected int pos = 0;
    protected int lim = 0;
    private final char[] cbuf;

    public id22() {
        super(System.in);
        this.buf = new byte[1 << 13];
        this.cbuf = new char[1 << 20];
    }

    boolean hasRemaining() throws IOException {
        if (pos < lim)
            return true;
        lim = in.read(buf);
        pos = 0;
        return lim > 0;
    }

    final int remaining() throws IOException {
        if (pos >= lim) {
            lim = in.read(buf);
            pos = 0;
        }
        return lim - pos;
    }

    @Override
    public final int available() throws IOException {
        if (pos < lim)
            return lim - pos + in.available();
        return in.available();
    }

    @Override
    public final long skip(long n) throws IOException {
        if (pos < lim) {
            int rem = lim - pos;
            if (n < rem) {
                pos += n;
                return n;
            }
            pos = lim;
            return rem;
        }
        return in.skip(n);
    }

    @Override
    public final int read() throws IOException {
        if (hasRemaining())
            return buf[pos++];
        return -1;
    }

    @Override
    public final int read(byte[] b, int off, int len) throws IOException {
        if (pos < lim) {
            int rem = Math.min(lim - pos, len);
            for (int i = 0; i < rem; i++)
                b[off + i] = buf[pos + i];
            pos += rem;
            return rem;
        }
        return in.read(b, off, len);
    }

    public final char[] readToken() throws IOException {
        int cpos = 0;
        int rem;
        byte b;
        l: while ((rem = remaining()) > 0) {
            for (int i = 0; i < rem; i++) {
                b = buf[pos + i];
                if (b <= 0x20) {
                    pos += i + 1;
                    cpos += i;
                    if (b == 0x0d && hasRemaining() && buf[pos] == 0x0a)
                        pos++;
                    break l;
                }
                cbuf[cpos + i] = (char) b;
            }
            pos += rem;
            cpos += rem;
        }
        char[] arr = new char[cpos];
        for (int i = 0; i < cpos; i++)
            arr[i] = cbuf[i];
        return arr;
    }

    public final int readToken(char[] cbuf, int off) throws IOException {
        int cpos = off;
        int rem;
        byte b;
        l: while ((rem = remaining()) > 0) {
            for (int i = 0; i < rem; i++) {
                b = buf[pos + i];
                if (b <= 0x20) {
                    pos += i + 1;
                    cpos += i;
                    if (b == 0x0d && hasRemaining() && buf[pos] == 0x0a)
                        pos++;
                    break l;
                }
                cbuf[cpos + i] = (char) b;
            }
            pos += rem;
            cpos += rem;
        }
        return cpos - off;
    }

    public final int readToken(char[] cbuf) throws IOException {
        return readToken(cbuf, 0);
    }

    public final String next() throws IOException {
        int cpos = 0;
        int rem;
        byte b;
        l: while ((rem = remaining()) > 0) {
            for (int i = 0; i < rem; i++) {
                b = buf[pos + i];
                if (b <= 0x20) {
                    pos += i + 1;
                    cpos += i;
                    if (b == 0x0d && hasRemaining() && buf[pos] == 0x0a)
                        pos++;
                    break l;
                }
                cbuf[cpos + i] = (char) b;
            }
            pos += rem;
            cpos += rem;
        }
        return String.valueOf(cbuf, 0, cpos);
    }

    public final char[] id16() throws IOException {
        return readToken();
    }

    public final int nextInt() throws IOException {
        if (!hasRemaining())
            return 0;
        int value = 0;
        byte b = buf[pos++];
        if (b == 0x2d) {
            while (hasRemaining() && (b = buf[pos++]) > 0x20)
                value = value * 10 - b + 0x30;
        } else {
            do {
                value = value * 10 + b - 0x30;
            } while (hasRemaining() && (b = buf[pos++]) > 0x20);
        }
        if (b == 0x0d && hasRemaining() && buf[pos] == 0x0a)
            pos++;
        return value;
    }

    public final long nextLong() throws IOException {
        if (!hasRemaining())
            return 0L;
        long value = 0L;
        byte b = buf[pos++];
        if (b == 0x2d) {
            while (hasRemaining() && (b = buf[pos++]) > 0x20)
                value = value * 10 - b + 0x30;
        } else {
            do {
                value = value * 10 + b - 0x30;
            } while (hasRemaining() && (b = buf[pos++]) > 0x20);
        }
        if (b == 0x0d && hasRemaining() && buf[pos] == 0x0a)
            pos++;
        return value;
    }

    public final char nextChar() throws IOException {
        if (!hasRemaining())
            throw new EOFException();
        final char c = (char) buf[pos++];
        if (hasRemaining() && buf[pos++] == 0x0d && hasRemaining() && buf[pos] == 0x0a)
            pos++;
        return c;
    }

    public final float nextFloat() throws IOException {
        return Float.parseFloat(next());
    }

    public final double nextDouble() throws IOException {
        return Double.parseDouble(next());
    }

    public final boolean[] id23(char ok) throws IOException {
        char[] s = readToken();
        int n = s.length;
        boolean[] t = new boolean[n];
        for (int i = 0; i < n; i++)
            t[i] = s[i] == ok;
        return t;
    }

    public final boolean[][] id15(int h, int w, char ok) throws IOException {
        boolean[][] s = new boolean[h][];
        for (int i = 0; i < h; i++) {
            char[] t = readToken();
            int n = t.length;
            s[i] = new boolean[n];
            for (int j = 0; j < n; j++)
                s[i][j] = t[j] == ok;
        }
        return s;
    }

    public final String[] id25(int len) throws IOException {
        String[] arr = new String[len];
        for (int i = 0; i < len; i++)
            arr[i] = next();
        return arr;
    }

    public final int[] id13(int len) throws IOException {
        int[] arr = new int[len];
        for (int i = 0; i < len; i++)
            arr[i] = nextInt();
        return arr;
    }

    public final int[] id13(int len, java.util.function.IntUnaryOperator map) throws IOException {
        int[] arr = new int[len];
        for (int i = 0; i < len; i++)
            arr[i] = map.applyAsInt(nextInt());
        return arr;
    }

    public final long[] id28(int len, java.util.function.LongUnaryOperator map) throws IOException {
        long[] arr = new long[len];
        for (int i = 0; i < len; i++)
            arr[i] = map.applyAsLong(nextLong());
        return arr;
    }

    public final int[][] id1(int h, int w) throws IOException {
        int[][] arr = new int[h][w];
        for (int i = 0; i < h; i++)
            for (int j = 0; j < w; j++)
                arr[i][j] = nextInt();
        return arr;
    }

    public final int[][] id1(int h, int w, java.util.function.IntUnaryOperator map) throws IOException {
        int[][] arr = new int[h][w];
        for (int i = 0; i < h; i++)
            for (int j = 0; j < w; j++)
                arr[i][j] = map.applyAsInt(nextInt());
        return arr;
    }

    public final long[] id28(int len) throws IOException {
        long[] arr = new long[len];
        for (int i = 0; i < len; i++)
            arr[i] = nextLong();
        return arr;
    }

    public final long[][] id12(int h, int w) throws IOException {
        long[][] arr = new long[h][w];
        for (int i = 0; i < h; i++)
            for (int j = 0; j < w; j++)
                arr[i][j] = nextLong();
        return arr;
    }

    public final float[] id14(int len) throws IOException {
        float[] arr = new float[len];
        for (int i = 0; i < len; i++)
            arr[i] = nextFloat();
        return arr;
    }

    public final double[] id24(int len) throws IOException {
        double[] arr = new double[len];
        for (int i = 0; i < len; i++)
            arr[i] = nextDouble();
        return arr;
    }

    public final char[][] id17(int h, int w) throws IOException {
        char[][] arr = new char[h][];
        for (int i = 0; i < h; i++)
            arr[i] = readToken();
        return arr;
    }

    public final void nextThrow() throws IOException {
        next();
        return;
    }

    public final void nextThrow(int n) throws IOException {
        for (int i = 0; i < n; i++)
            nextThrow();
        return;
    }
}

final class id2 extends FilterOutputStream implements Appendable {
    protected final byte[] buf;
    protected int pos = 0;

    public id2() {
        super(System.out);
        this.buf = new byte[1 << 13];
    }

    @Override
    public void flush() throws IOException {
        out.write(buf, 0, pos);
        pos = 0;
        out.flush();
    }

    void put(byte b) throws IOException {
        if (pos >= buf.length)
            flush();
        buf[pos++] = b;
    }

    int remaining() throws IOException {
        if (pos >= buf.length)
            flush();
        return buf.length - pos;
    }

    @Override
    public void write(int b) throws IOException {
        put((byte) b);
    }

    @Override
    public void write(byte[] b, int off, int len) throws IOException {
        int o = off;
        int l = len;
        while (l > 0) {
            int rem = Math.min(remaining(), l);
            for (int i = 0; i < rem; i++)
                buf[pos + i] = b[o + i];
            pos += rem;
            o += rem;
            l -= rem;
        }
    }

    @Override
    public id2 append(char c) throws IOException {
        put((byte) c);
        return this;
    }

    @Override
    public id2 append(CharSequence csq, int start, int end) throws IOException {
        int off = start;
        int len = end - start;
        while (len > 0) {
            int rem = Math.min(remaining(), len);
            for (int i = 0; i < rem; i++)
                buf[pos + i] = (byte) csq.charAt(off + i);
            pos += rem;
            off += rem;
            len -= rem;
        }
        return this;
    }

    @Override
    public id2 append(CharSequence csq) throws IOException {
        return append(csq, 0, csq.length());
    }

    public id2 append(char[] arr, int off, int len) throws IOException {
        int o = off;
        int l = len;
        while (l > 0) {
            int rem = Math.min(remaining(), l);
            for (int i = 0; i < rem; i++)
                buf[pos + i] = (byte) arr[o + i];
            pos += rem;
            o += rem;
            l -= rem;
        }
        return this;
    }

    public id2 print(char[] arr) throws IOException {
        return append(arr, 0, arr.length).newLine();
    }

    public id2 print(boolean value) throws IOException {
        if (value)
            return append("o");
        return append("x");
    }

    public id2 println(boolean value) throws IOException {
        if (value)
            return append("o\n");
        return append("x\n");
    }

    public id2 print(boolean[][] value) throws IOException {
        final int n = value.length, m = value[0].length;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++)
                print(value[i][j]);
            newLine();
        }
        return this;
    }

    public id2 print(int value) throws IOException {
        return append(String.valueOf(value));
    }

    public id2 println(int value) throws IOException {
        return append(String.valueOf(value)).newLine();
    }

    public id2 print(long value) throws IOException {
        return append(String.valueOf(value));
    }

    public id2 println(long value) throws IOException {
        return append(String.valueOf(value)).newLine();
    }

    public id2 print(float value) throws IOException {
        return append(String.valueOf(value));
    }

    public id2 println(float value) throws IOException {
        return append(String.valueOf(value)).newLine();
    }

    public id2 print(double value) throws IOException {
        return append(String.valueOf(value));
    }

    public id2 println(double value) throws IOException {
        return append(String.valueOf(value)).newLine();
    }

    public id2 print(char value) throws IOException {
        return append(value);
    }

    public id2 println(char value) throws IOException {
        return append(value).newLine();
    }

    public id2 print(String value) throws IOException {
        return append(value);
    }

    public id2 println(String value) throws IOException {
        return append(String.valueOf(value)).newLine();
    }

    public id2 print(Object value) throws IOException {
        return append(String.valueOf(value));
    }

    public id2 println(Object value) throws IOException {
        return append(String.valueOf(value)).newLine();
    }

    public id2 printYN(boolean yes) throws IOException {
        if (yes)
            return println("Yes");
        return println("No");
    }

    public id2 printAB(boolean yes) throws IOException {
        if (yes)
            return println("Alice");
        return println("Bob");
    }

    public id2 print(CharSequence[] arr) throws IOException {
        if (arr.length > 0) {
            append(arr[0]);
            for (int i = 1; i < arr.length; i++)
                append('\u0020').append(arr[i]);
        }
        return this;
    }

    public id2 print(int[] arr) throws IOException {
        if (arr.length > 0) {
            print(arr[0]);
            for (int i = 1; i < arr.length; i++)
                append('\u0020').print(arr[i]);
        }
        newLine();
        return this;
    }

    public id2 print(int[] arr, int length) throws IOException {
        if (length > 0)
            print(arr[0]);
        for (int i = 1; i < length; i++)
            append('\u0020').print(arr[i]);
        newLine();
        return this;
    }

    public id2 println(int[] arr) throws IOException {
        for (int i : arr)
            print(i).newLine();
        return this;
    }

    public id2 println(int[] arr, int length) throws IOException {
        for (int i = 0; i < length; i++)
            println(arr[i]);
        return this;
    }

    public id2 print(boolean[] arr) throws IOException {
        if (arr.length > 0) {
            print(arr[0]);
            for (int i = 1; i < arr.length; i++)
                append('\u0020').print(arr[i]);
        }
        newLine();
        return this;
    }

    public id2 print(long[] arr) throws IOException {
        if (arr.length > 0) {
            print(arr[0]);
            for (int i = 1; i < arr.length; i++)
                append('\u0020').print(arr[i]);
        }
        newLine();
        return this;
    }

    public id2 print(long[] arr, int length) throws IOException {
        if (length > 0)
            print(arr[0]);
        for (int i = 1; i < length; i++)
            append('\u0020').print(arr[i]);
        newLine();
        return this;
    }

    public id2 println(long[] arr, int length) throws IOException {
        for (int i = 0; i < length; i++)
            println(arr[i]);
        return this;
    }

    public id2 println(long[] arr) throws IOException {
        for (long i : arr)
            print(i).newLine();
        return this;
    }

    public id2 print(float[] arr) throws IOException {
        if (arr.length > 0) {
            print(arr[0]);
            for (int i = 1; i < arr.length; i++)
                append('\u0020').print(arr[i]);
        }
        return this;
    }

    public id2 println(float[] arr) throws IOException {
        for (float i : arr)
            print(i).newLine();
        return this;
    }

    public id2 print(double[] arr) throws IOException {
        if (arr.length > 0) {
            print(arr[0]);
            for (int i = 1; i < arr.length; i++)
                append('\u0020').print(arr[i]);
        }
        return newLine();
    }

    public id2 println(double[] arr) throws IOException {
        for (double i : arr)
            print(i).newLine();
        return this;
    }

    public id2 print(Object[] arr) throws IOException {
        if (arr.length > 0) {
            print(arr[0]);
            for (int i = 1; i < arr.length; i++)
                append('\u0020').print(arr[i]);
        }
        return newLine();
    }

    public id2 print(java.util.ArrayList<?> arr) throws IOException {
        if (!arr.isEmpty()) {
            final int n = arr.size();
            print(arr.get(0));
            for (int i = 1; i < n; i++)
                print(" ").print(arr.get(i));
        }
        return newLine();
    }

    public id2 println(java.util.ArrayList<?> arr) throws IOException {
        final int n = arr.size();
        for (int i = 0; i < n; i++)
            println(arr.get(i));
        return this;
    }

    public id2 println(Object[] arr) throws IOException {
        for (Object i : arr)
            print(i).newLine();
        return this;
    }

    public id2 newLine() throws IOException {
        return append(System.lineSeparator());
    }

    public id2 endl() throws IOException {
        newLine().flush();
        return this;
    }

    public id2 print(int[][] arr) throws IOException {
        for (int[] i : arr)
            print(i);
        return this;
    }

    public id2 print(long[][] arr) throws IOException {
        for (long[] i : arr)
            print(i);
        return this;
    }

    public id2 print(char[][] arr) throws IOException {
        for (char[] i : arr)
            print(i);
        return this;
    }

    public id2 print(Object[][] arr) throws IOException {
        for (Object[] i : arr)
            print(i);
        return this;
    }

    public id2 println() throws IOException {
        return newLine();
    }
}
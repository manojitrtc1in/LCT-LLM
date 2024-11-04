import java.util.*;
import java.io.*;

public class Main {
    private static final void solve() throws IOException {
        int n = ni();
        var a = new int[n];
        for (int i = 1; i < n; i++)
            a[0] ^= a[i] = i;
        a[0] ^= 1 << 20;
        a[1] ^= 1 << 20;
        a[0] ^= 1 << 21;
        a[2] ^= 1 << 21;
        ou.print(a);
        return;
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
        return sc.id7(n);
    }

    private static final long nl() throws IOException {
        return sc.nextLong();
    }

    private static final long[] nl(int n) throws IOException {
        return sc.id21(n);
    }

    private static final String ns() throws IOException {
        return sc.next();
    }

    private static final id15 sc = new id15();
    private static final id1 ou = new id1();
}

final class StringAlgorithm {
    private static int[] id5(int[] s) {
        int n = s.length;
        int[] sa = new int[n];
        for (int i = 0; i < n; i++) {
            sa[i] = i;
        }
        id13(sa, (l, r) -> {
            while (l < n && r < n) {
                if (s[l] != s[r])
                    return s[l] - s[r];
                l++;
                r++;
            }
            return -(l - r);
        });
        return sa;
    }

    private static int[] id17(int[] s) {
        int n = s.length;
        int[] sa = new int[n];
        for (int i = 0; i < n; i++) {
            sa[i] = i;
        }
        int[] rnk = java.util.Arrays.copyOf(s, n);
        int[] tmp = new int[n];

        for (int k = 1; k < n; k *= 2) {
            final int _k = k;
            final int[] _rnk = rnk;
            java.util.function.IntBinaryOperator cmp = (x, y) -> {
                if (_rnk[x] != _rnk[y])
                    return _rnk[x] - _rnk[y];
                int rx = x + _k < n ? _rnk[x + _k] : -1;
                int ry = y + _k < n ? _rnk[y + _k] : -1;
                return rx - ry;
            };
            id2(sa, cmp);
            tmp[sa[0]] = 0;
            for (int i = 1; i < n; i++) {
                tmp[sa[i]] = tmp[sa[i - 1]] + (cmp.applyAsInt(sa[i - 1], sa[i]) < 0 ? 1 : 0);
            }
            int[] buf = tmp;
            tmp = rnk;
            rnk = buf;
        }
        return sa;
    }

    private static void id13(int[] a, java.util.function.IntBinaryOperator comparator) {
        final int n = a.length;
        for (int i = 1; i < n; i++) {
            final int tmp = a[i];
            if (comparator.applyAsInt(a[i - 1], tmp) > 0) {
                int j = i;
                do {
                    a[j] = a[j - 1];
                    j--;
                } while (j > 0 && comparator.applyAsInt(a[j - 1], tmp) > 0);
                a[j] = tmp;
            }
        }
    }

    private static void id2(int[] a, java.util.function.IntBinaryOperator comparator) {
        final int n = a.length;
        final int[] work = new int[n];
        for (int block = 1; block <= n; block <<= 1) {
            final int block2 = block << 1;
            for (int l = 0, max = n - block; l < max; l += block2) {
                int m = l + block;
                int r = Math.min(l + block2, n);
                System.arraycopy(a, l, work, 0, block);
                for (int i = l, wi = 0, ti = m;; i++) {
                    if (ti == r) {
                        System.arraycopy(work, wi, a, i, block - wi);
                        break;
                    }
                    if (comparator.applyAsInt(work[wi], a[ti]) > 0) {
                        a[i] = a[ti++];
                    } else {
                        a[i] = work[wi++];
                        if (wi == block)
                            break;
                    }
                }
            }
        }
    }

    private static final int id3 = 50;
    private static final int id9 = 0;

    private static int[] sais(int[] s, int upper) {
        int n = s.length;
        if (n == 0)
            return new int[0];
        if (n == 1)
            return new int[] { 0 };
        if (n == 2) {
            if (s[0] < s[1]) {
                return new int[] { 0, 1 };
            } else {
                return new int[] { 1, 0 };
            }
        }
        if (n < id3) {
            return id5(s);
        }
        

        

        


        int[] sa = new int[n];
        boolean[] ls = new boolean[n];
        for (int i = n - 2; i >= 0; i--) {
            ls[i] = s[i] == s[i + 1] ? ls[i + 1] : s[i] < s[i + 1];
        }

        int[] sumL = new int[upper + 1];
        int[] sumS = new int[upper + 1];

        for (int i = 0; i < n; i++) {
            if (ls[i]) {
                sumL[s[i] + 1]++;
            } else {
                sumS[s[i]]++;
            }
        }

        for (int i = 0; i <= upper; i++) {
            sumS[i] += sumL[i];
            if (i < upper)
                sumL[i + 1] += sumS[i];
        }

        java.util.function.Consumer<int[]> induce = lms -> {
            java.util.Arrays.fill(sa, -1);
            int[] buf = new int[upper + 1];
            System.arraycopy(sumS, 0, buf, 0, upper + 1);
            for (int d : lms) {
                if (d == n)
                    continue;
                sa[buf[s[d]]++] = d;
            }
            System.arraycopy(sumL, 0, buf, 0, upper + 1);
            sa[buf[s[n - 1]]++] = n - 1;
            for (int i = 0; i < n; i++) {
                int v = sa[i];
                if (v >= 1 && !ls[v - 1]) {
                    sa[buf[s[v - 1]]++] = v - 1;
                }
            }
            System.arraycopy(sumL, 0, buf, 0, upper + 1);
            for (int i = n - 1; i >= 0; i--) {
                int v = sa[i];
                if (v >= 1 && ls[v - 1]) {
                    sa[--buf[s[v - 1] + 1]] = v - 1;
                }
            }
        };

        int[] id20 = new int[n + 1];
        java.util.Arrays.fill(id20, -1);
        int m = 0;
        for (int i = 1; i < n; i++) {
            if (!ls[i - 1] && ls[i]) {
                id20[i] = m++;
            }
        }

        int[] lms = new int[m];
        {
            int p = 0;
            for (int i = 1; i < n; i++) {
                if (!ls[i - 1] && ls[i]) {
                    lms[p++] = i;
                }
            }
        }

        induce.accept(lms);

        if (m > 0) {
            int[] id4 = new int[m];
            {
                int p = 0;
                for (int v : sa) {
                    if (id20[v] != -1) {
                        id4[p++] = v;
                    }
                }
            }
            int[] recS = new int[m];
            int recUpper = 0;
            recS[id20[id4[0]]] = 0;
            for (int i = 1; i < m; i++) {
                int l = id4[i - 1], r = id4[i];
                int endL = (id20[l] + 1 < m) ? lms[id20[l] + 1] : n;
                int endR = (id20[r] + 1 < m) ? lms[id20[r] + 1] : n;
                boolean same = true;
                if (endL - l != endR - r) {
                    same = false;
                } else {
                    while (l < endL && s[l] == s[r]) {
                        l++;
                        r++;
                    }
                    if (l == n || s[l] != s[r])
                        same = false;
                }
                if (!same) {
                    recUpper++;
                }
                recS[id20[id4[i]]] = recUpper;
            }

            int[] recSA = sais(recS, recUpper);

            for (int i = 0; i < m; i++) {
                id4[i] = lms[recSA[i]];
            }
            induce.accept(id4);
        }
        return sa;
    }

    public static int[] suffixArray(int[] s, int upper) {
        assert (0 <= upper);
        for (int d : s) {
            assert (0 <= d && d <= upper);
        }
        return sais(s, upper);
    }

    public static int[] suffixArray(int[] s) {
        int n = s.length;
        int[] vals = Arrays.copyOf(s, n);
        java.util.Arrays.sort(vals);
        int p = 1;
        for (int i = 1; i < n; i++) {
            if (vals[i] != vals[i - 1]) {
                vals[p++] = vals[i];
            }
        }
        int[] s2 = new int[n];
        for (int i = 0; i < n; i++) {
            s2[i] = java.util.Arrays.binarySearch(vals, 0, p, s[i]);
        }
        return sais(s2, p);
    }

    public static int[] suffixArray(char[] s) {
        int n = s.length;
        int[] s2 = new int[n];
        for (int i = 0; i < n; i++) {
            s2[i] = s[i];
        }
        return sais(s2, 255);
    }

    public static int[] suffixArray(java.lang.String s) {
        return suffixArray(s.toCharArray());
    }

    public static int[] id14(int[] s, int[] sa) {
        int n = s.length;
        assert (n >= 1);
        int[] rnk = new int[n];
        for (int i = 0; i < n; i++) {
            rnk[sa[i]] = i;
        }
        int[] lcp = new int[n - 1];
        int h = 0;
        for (int i = 0; i < n; i++) {
            if (h > 0)
                h--;
            if (rnk[i] == 0) {
                continue;
            }
            int j = sa[rnk[i] - 1];
            for (; j + h < n && i + h < n; h++) {
                if (s[j + h] != s[i + h])
                    break;
            }
            lcp[rnk[i] - 1] = h;
        }
        return lcp;
    }

    public static int[] id14(char[] s, int[] sa) {
        int n = s.length;
        int[] s2 = new int[n];
        for (int i = 0; i < n; i++) {
            s2[i] = s[i];
        }
        return id14(s2, sa);
    }

    public static int[] id14(java.lang.String s, int[] sa) {
        return id14(s.toCharArray(), sa);
    }

    public static int[] zAlgorithm(int[] s) {
        int n = s.length;
        if (n == 0)
            return new int[0];
        int[] z = new int[n];
        for (int i = 1, j = 0; i < n; i++) {
            int k = j + z[j] <= i ? 0 : Math.min(j + z[j] - i, z[i - j]);
            while (i + k < n && s[k] == s[i + k])
                k++;
            z[i] = k;
            if (j + z[j] < i + z[i])
                j = i;
        }
        z[0] = n;
        return z;
    }

    public static int[] zAlgorithm(char[] s) {
        int n = s.length;
        if (n == 0)
            return new int[0];
        int[] z = new int[n];
        for (int i = 1, j = 0; i < n; i++) {
            int k = j + z[j] <= i ? 0 : Math.min(j + z[j] - i, z[i - j]);
            while (i + k < n && s[k] == s[i + k])
                k++;
            z[i] = k;
            if (j + z[j] < i + z[i])
                j = i;
        }
        z[0] = n;
        return z;
    }

    public static int[] zAlgorithm(String s) {
        return zAlgorithm(s.toCharArray());
    }
}

final class id15 extends FilterInputStream {
    protected final byte[] buf;
    protected int pos = 0;
    protected int lim = 0;
    private final char[] cbuf;

    public id15() {
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

    public final char[] id11() throws IOException {
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

    public final boolean[] id16(char ok) throws IOException {
        char[] s = readToken();
        int n = s.length;
        boolean[] t = new boolean[n];
        for (int i = 0; i < n; i++)
            t[i] = s[i] == ok;
        return t;
    }

    public final boolean[][] id10(int h, int w, char ok) throws IOException {
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

    public final String[] id19(int len) throws IOException {
        String[] arr = new String[len];
        for (int i = 0; i < len; i++)
            arr[i] = next();
        return arr;
    }

    public final int[] id7(int len) throws IOException {
        int[] arr = new int[len];
        for (int i = 0; i < len; i++)
            arr[i] = nextInt();
        return arr;
    }

    public final int[] id7(int len, java.util.function.IntUnaryOperator map) throws IOException {
        int[] arr = new int[len];
        for (int i = 0; i < len; i++)
            arr[i] = map.applyAsInt(nextInt());
        return arr;
    }

    public final long[] id21(int len, java.util.function.LongUnaryOperator map) throws IOException {
        long[] arr = new long[len];
        for (int i = 0; i < len; i++)
            arr[i] = map.applyAsLong(nextLong());
        return arr;
    }

    public final int[][] id0(int h, int w) throws IOException {
        int[][] arr = new int[h][w];
        for (int i = 0; i < h; i++)
            for (int j = 0; j < w; j++)
                arr[i][j] = nextInt();
        return arr;
    }

    public final int[][] id0(int h, int w, java.util.function.IntUnaryOperator map) throws IOException {
        int[][] arr = new int[h][w];
        for (int i = 0; i < h; i++)
            for (int j = 0; j < w; j++)
                arr[i][j] = map.applyAsInt(nextInt());
        return arr;
    }

    public final long[] id21(int len) throws IOException {
        long[] arr = new long[len];
        for (int i = 0; i < len; i++)
            arr[i] = nextLong();
        return arr;
    }

    public final long[][] id6(int h, int w) throws IOException {
        long[][] arr = new long[h][w];
        for (int i = 0; i < h; i++)
            for (int j = 0; j < w; j++)
                arr[i][j] = nextLong();
        return arr;
    }

    public final float[] id8(int len) throws IOException {
        float[] arr = new float[len];
        for (int i = 0; i < len; i++)
            arr[i] = nextFloat();
        return arr;
    }

    public final double[] id18(int len) throws IOException {
        double[] arr = new double[len];
        for (int i = 0; i < len; i++)
            arr[i] = nextDouble();
        return arr;
    }

    public final char[][] id12(int h, int w) throws IOException {
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

final class id1 extends FilterOutputStream implements Appendable {
    protected final byte[] buf;
    protected int pos = 0;

    public id1() {
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
    public id1 append(char c) throws IOException {
        put((byte) c);
        return this;
    }

    @Override
    public id1 append(CharSequence csq, int start, int end) throws IOException {
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
    public id1 append(CharSequence csq) throws IOException {
        return append(csq, 0, csq.length());
    }

    public id1 append(char[] arr, int off, int len) throws IOException {
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

    public id1 print(char[] arr) throws IOException {
        return append(arr, 0, arr.length).newLine();
    }

    public id1 print(boolean value) throws IOException {
        if (value)
            return append("o");
        return append("x");
    }

    public id1 println(boolean value) throws IOException {
        if (value)
            return append("o\n");
        return append("x\n");
    }

    public id1 print(boolean[][] value) throws IOException {
        final int n = value.length, m = value[0].length;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++)
                print(value[i][j]);
            newLine();
        }
        return this;
    }

    public id1 print(int value) throws IOException {
        return append(String.valueOf(value));
    }

    public id1 println(int value) throws IOException {
        return append(String.valueOf(value)).newLine();
    }

    public id1 print(long value) throws IOException {
        return append(String.valueOf(value));
    }

    public id1 println(long value) throws IOException {
        return append(String.valueOf(value)).newLine();
    }

    public id1 print(float value) throws IOException {
        return append(String.valueOf(value));
    }

    public id1 println(float value) throws IOException {
        return append(String.valueOf(value)).newLine();
    }

    public id1 print(double value) throws IOException {
        return append(String.valueOf(value));
    }

    public id1 println(double value) throws IOException {
        return append(String.valueOf(value)).newLine();
    }

    public id1 print(char value) throws IOException {
        return append(value);
    }

    public id1 println(char value) throws IOException {
        return append(value).newLine();
    }

    public id1 print(String value) throws IOException {
        return append(value);
    }

    public id1 println(String value) throws IOException {
        return append(String.valueOf(value)).newLine();
    }

    public id1 print(Object value) throws IOException {
        return append(String.valueOf(value));
    }

    public id1 println(Object value) throws IOException {
        return append(String.valueOf(value)).newLine();
    }

    public id1 printYN(boolean yes) throws IOException {
        if (yes)
            return println("Yes");
        return println("No");
    }

    public id1 printAB(boolean yes) throws IOException {
        if (yes)
            return println("Alice");
        return println("Bob");
    }

    public id1 print(CharSequence[] arr) throws IOException {
        if (arr.length > 0) {
            append(arr[0]);
            for (int i = 1; i < arr.length; i++)
                append('\u0020').append(arr[i]);
        }
        return this;
    }

    public id1 print(int[] arr) throws IOException {
        if (arr.length > 0) {
            print(arr[0]);
            for (int i = 1; i < arr.length; i++)
                append('\u0020').print(arr[i]);
        }
        newLine();
        return this;
    }

    public id1 print(int[] arr, int length) throws IOException {
        if (length > 0)
            print(arr[0]);
        for (int i = 1; i < length; i++)
            append('\u0020').print(arr[i]);
        newLine();
        return this;
    }

    public id1 println(int[] arr) throws IOException {
        for (int i : arr)
            print(i).newLine();
        return this;
    }

    public id1 println(int[] arr, int length) throws IOException {
        for (int i = 0; i < length; i++)
            println(arr[i]);
        return this;
    }

    public id1 print(boolean[] arr) throws IOException {
        if (arr.length > 0) {
            print(arr[0]);
            for (int i = 1; i < arr.length; i++)
                append('\u0020').print(arr[i]);
        }
        newLine();
        return this;
    }

    public id1 print(long[] arr) throws IOException {
        if (arr.length > 0) {
            print(arr[0]);
            for (int i = 1; i < arr.length; i++)
                append('\u0020').print(arr[i]);
        }
        newLine();
        return this;
    }

    public id1 print(long[] arr, int length) throws IOException {
        if (length > 0)
            print(arr[0]);
        for (int i = 1; i < length; i++)
            append('\u0020').print(arr[i]);
        newLine();
        return this;
    }

    public id1 println(long[] arr, int length) throws IOException {
        for (int i = 0; i < length; i++)
            println(arr[i]);
        return this;
    }

    public id1 println(long[] arr) throws IOException {
        for (long i : arr)
            print(i).newLine();
        return this;
    }

    public id1 print(float[] arr) throws IOException {
        if (arr.length > 0) {
            print(arr[0]);
            for (int i = 1; i < arr.length; i++)
                append('\u0020').print(arr[i]);
        }
        return this;
    }

    public id1 println(float[] arr) throws IOException {
        for (float i : arr)
            print(i).newLine();
        return this;
    }

    public id1 print(double[] arr) throws IOException {
        if (arr.length > 0) {
            print(arr[0]);
            for (int i = 1; i < arr.length; i++)
                append('\u0020').print(arr[i]);
        }
        return newLine();
    }

    public id1 println(double[] arr) throws IOException {
        for (double i : arr)
            print(i).newLine();
        return this;
    }

    public id1 print(Object[] arr) throws IOException {
        if (arr.length > 0) {
            print(arr[0]);
            for (int i = 1; i < arr.length; i++)
                append('\u0020').print(arr[i]);
        }
        return newLine();
    }

    public id1 print(java.util.ArrayList<?> arr) throws IOException {
        if (!arr.isEmpty()) {
            final int n = arr.size();
            print(arr.get(0));
            for (int i = 1; i < n; i++)
                print(" ").print(arr.get(i));
        }
        return newLine();
    }

    public id1 println(java.util.ArrayList<?> arr) throws IOException {
        final int n = arr.size();
        for (int i = 0; i < n; i++)
            println(arr.get(i));
        return this;
    }

    public id1 println(Object[] arr) throws IOException {
        for (Object i : arr)
            print(i).newLine();
        return this;
    }

    public id1 newLine() throws IOException {
        return append(System.lineSeparator());
    }

    public id1 endl() throws IOException {
        newLine().flush();
        return this;
    }

    public id1 print(int[][] arr) throws IOException {
        for (int[] i : arr)
            print(i);
        return this;
    }

    public id1 print(long[][] arr) throws IOException {
        for (long[] i : arr)
            print(i);
        return this;
    }

    public id1 print(char[][] arr) throws IOException {
        for (char[] i : arr)
            print(i);
        return this;
    }

    public id1 print(Object[][] arr) throws IOException {
        for (Object[] i : arr)
            print(i);
        return this;
    }

    public id1 println() throws IOException {
        return newLine();
    }
}
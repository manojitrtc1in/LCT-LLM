import java.io.*;

public class Main {
    private static final void solve() throws IOException {
        int n = ni();
        var a = ni(n);
        var ze = false;
        for (int i = 0; i < n; i++) {
            a[i] += a[i] % 10;
            ze |= a[i] % 10 == 0;
        }
        if (ze) {
            var t = true;
            for (int i = 1; i < n; i++)
                t &= a[0] == a[i];
            ou.printYN(t);
            return;
        }
        for (int i = 0; i < n; i++)
            while (a[i] % 10 != 2)
                a[i] += a[i] % 10;
        var t = true;
        for (int i = 1; i < n; i++)
            t &= (a[i] - a[0]) % 20 == 0;
        ou.printYN(t);
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
        return sc.id10(n);
    }

    private static final String ns() throws IOException {
        return sc.next();
    }

    private static final id11 sc = new id11();
    private static final id1 ou = new id1();
}

final class id11 extends FilterInputStream {
    protected final byte[] buf;
    protected int pos = 0;
    protected int lim = 0;
    private final char[] cbuf;

    public id11() {
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
        int i;
        byte b;
        l: while ((rem = remaining()) > 0) {
            for (i = 0; i < rem; i++) {
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
        for (i = 0; i < cpos; i++)
            arr[i] = cbuf[i];
        return arr;
    }

    public final int readToken(char[] cbuf, int off) throws IOException {
        int cpos = off;
        int rem;
        int i;
        byte b;
        l: while ((rem = remaining()) > 0) {
            for (i = 0; i < rem; i++) {
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
        int i;
        byte b;
        l: while ((rem = remaining()) > 0) {
            for (i = 0; i < rem; i++) {
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

    public final float nextFloat() throws IOException {
        return Float.parseFloat(next());
    }

    public final double nextDouble() throws IOException {
        return Double.parseDouble(next());
    }

    public final boolean[] id2(char ok) throws IOException {
        char[] s = next().toCharArray();
        int n = s.length;
        boolean[] t = new boolean[n];
        for (int i = 0; i < n; i++)
            t[i] = s[i] == ok;
        return t;
    }

    public final boolean[][] id3(int h, int w, char ok) throws IOException {
        boolean[][] s = new boolean[h][];
        for (int i = 0; i < h; i++) {
            char[] t = next().toCharArray();
            int n = t.length;
            s[i] = new boolean[n];
            for (int j = 0; j < n; j++)
                s[i][j] = t[j] == ok;
        }
        return s;
    }

    public final String[] id6(int len) throws IOException {
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

    public final long[] id10(int len, java.util.function.LongUnaryOperator map) throws IOException {
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

    public final long[] id10(int len) throws IOException {
        long[] arr = new long[len];
        for (int i = 0; i < len; i++)
            arr[i] = nextLong();
        return arr;
    }

    public final long[][] id5(int h, int w) throws IOException {
        long[][] arr = new long[h][w];
        for (int i = 0; i < h; i++)
            for (int j = 0; j < w; j++)
                arr[i][j] = nextLong();
        return arr;
    }

    public final float[] id9(int len) throws IOException {
        float[] arr = new float[len];
        for (int i = 0; i < len; i++)
            arr[i] = nextFloat();
        return arr;
    }

    public final double[] id8(int len) throws IOException {
        double[] arr = new double[len];
        for (int i = 0; i < len; i++)
            arr[i] = nextDouble();
        return arr;
    }

    public final char[][] id4(int h, int w) throws IOException {
        char[][] arr = new char[h][];
        for (int i = 0; i < h; i++)
            arr[i] = next().toCharArray();
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
        return append(String.valueOf(value));
    }

    public id1 println(char value) throws IOException {
        return append(String.valueOf(value)).newLine();
    }

    public id1 print(String value) throws IOException {
        return append(String.valueOf(value));
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

    public id1 println(int[] arr) throws IOException {
        for (int i : arr)
            print(i).newLine();
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

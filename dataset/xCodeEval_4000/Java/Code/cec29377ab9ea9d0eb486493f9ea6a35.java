import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintStream;
import java.util.ArrayList;
import java.util.Arrays;
import java.io.UncheckedIOException;
import java.io.Closeable;
import java.io.Writer;
import java.io.OutputStreamWriter;
import java.util.InputMismatchException;


@SuppressWarnings("ALL")
public class A {


    public static void main(String[] args) throws Throwable {
        Thread thread = new Thread (null, new TaskAdapter (), "", 1 << 29);
        thread.start ();
        thread.join ();
    }

    static class TaskAdapter implements Runnable {
        @Override
        public void run() {
            InputStream inputStream = System.in;
            OutputStream outputStream = System.out;
            FastInput in = new FastInput (inputStream);
            FastOutput out = new FastOutput (outputStream);
            Solution solver = new Solution ();
            solver.solve (1, in, out);
            in.close ();
            out.close ();
        }
    }

    @SuppressWarnings("unused")
    static class Solution {
        static final Debug debug = new Debug (true);

        public void solve(int testNumber, FastInput in, FastOutput out) {

            int test=in.ri ();

            while (test-->0){
                int x=in.ri (),y=in.ri ();
                if(y%x!=0){
                    out.prtl (0+" "+0);
                } else{
                    out.prtl (1+" "+(y/x));
                }

            }

        }




    }


    static class FastOutput implements AutoCloseable, Closeable, Appendable {
        private final StringBuilder cache = new StringBuilder (THRESHOLD * 2);
        private static final int THRESHOLD = 32 << 10;
        private final Writer os;

        public FastOutput append(CharSequence csq) {
            cache.append (csq);
            return this;
        }

        public FastOutput append(CharSequence csq, int start, int end) {
            cache.append (csq, start, end);
            return this;
        }

        private void afterWrite() {
            if (cache.length () < THRESHOLD) {
                return;
            }
            flush ();
        }

        public FastOutput(Writer os) {
            this.os = os;
        }

        public FastOutput(OutputStream os) {
            this (new OutputStreamWriter (os));
        }

        public FastOutput append(char c) {
            cache.append (c);
            afterWrite ();
            return this;
        }

        public FastOutput append(String c) {
            cache.append (c);
            afterWrite ();
            return this;
        }

        public FastOutput println(String c) {
            return append (c).println ();
        }

        public FastOutput println() {
            return append ('\n');
        }

        final <T> void prt(T a) {
            append (a + " ");
        }

        final <T> void prtl(T a) {
            append (a + "\n");
        }

        public FastOutput flush() {
            try {
                os.append (cache);
                os.flush ();
                cache.setLength (0);
            } catch (IOException e) {
                throw new UncheckedIOException (e);
            }
            return this;
        }

        public void close() {
            flush ();
            try {
                os.close ();
            } catch (IOException e) {
                throw new UncheckedIOException (e);
            }
        }

        public String toString() {
            return cache.toString ();
        }

        public FastOutput printf(String format, Object... args) {
            return append (String.format (format, args));
        }

        private static int countDigits(long l) {
            if (l >= 1000000000000000000L) return 19;
            if (l >= 100000000000000000L) return 18;
            if (l >= 10000000000000000L) return 17;
            if (l >= 1000000000000000L) return 16;
            if (l >= 100000000000000L) return 15;
            if (l >= 10000000000000L) return 14;
            if (l >= 1000000000000L) return 13;
            if (l >= 100000000000L) return 12;
            if (l >= 10000000000L) return 11;
            if (l >= 1000000000L) return 10;
            if (l >= 100000000L) return 9;
            if (l >= 10000000L) return 8;
            if (l >= 1000000L) return 7;
            if (l >= 100000L) return 6;
            if (l >= 10000L) return 5;
            if (l >= 1000L) return 4;
            if (l >= 100L) return 3;
            if (l >= 10L) return 2;
            return 1;
        }

        private static int countDigits(int l) {
            if (l >= 1000000000) return 10;
            if (l >= 100000000) return 9;
            if (l >= 10000000) return 8;
            if (l >= 1000000) return 7;
            if (l >= 100000) return 6;
            if (l >= 10000) return 5;
            if (l >= 1000) return 4;
            if (l >= 100) return 3;
            if (l >= 10) return 2;
            return 1;
        }

    }


    static class FastInput {
        private final StringBuilder defaultStringBuf = new StringBuilder (1 << 13);
        private final ByteBuffer tokenBuf = new ByteBuffer ();
        private final byte[] buf = new byte[1 << 13];
        private SpaceCharFilter filter;
        private final InputStream is;
        private int bufOffset;
        private int bufLen;
        private int next;
        private int ptr;

        public FastInput(InputStream is) {
            this.is = is;
        }

        private int read() {
            while (bufLen == bufOffset) {
                bufOffset = 0;
                try {
                    bufLen = is.read (buf);
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
                next = read ();
            }
        }

        public String next() {
            return readString ();
        }

        public int ri() {
            return readInt ();
        }

        public int readInt() {
            boolean rev = false;

            skipBlank ();
            if (next == '+' || next == '-') {
                rev = next == '-';
                next = read ();
            }

            int val = 0;
            while (next >= '0' && next <= '9') {
                val = val * 10 - next + '0';
                next = read ();
            }

            return rev ? val : -val;
        }

        public long readLong() {
            boolean rev = false;

            skipBlank ();
            if (next == '+' || next == '-') {
                rev = next == '-';
                next = read ();
            }

            long val = 0L;
            while (next >= '0' && next <= '9') {
                val = val * 10 - next + '0';
                next = read ();
            }

            return rev ? val : -val;
        }

        public long rl() {
            return readLong ();
        }

        public String readString(StringBuilder builder) {
            skipBlank ();

            while (next > 32) {
                builder.append ((char) next);
                next = read ();
            }

            return builder.toString ();
        }

        public String readString() {
            defaultStringBuf.setLength (0);
            return readString (defaultStringBuf);
        }

        public int rs(char[] data, int offset) {
            return readString (data, offset);
        }

        public char[] rsc() {
            return readString ().toCharArray ();
        }

        public int rs(char[] data) {
            return rs (data, 0);
        }

        public int readString(char[] data, int offset) {
            skipBlank ();

            int originalOffset = offset;
            while (next > 32) {
                data[offset++] = (char) next;
                next = read ();
            }

            return offset - originalOffset;
        }

        public char rc() {
            return readChar ();
        }

        public char readChar() {
            skipBlank ();
            char c = (char) next;
            next = read ();
            return c;
        }

        public double rd() {
            return nextDouble ();
        }

        public double nextDouble() {
            int c = read ();
            while (isSpaceChar (c))
                c = read ();
            int sgn = 1;
            if (c == '-') {
                sgn = -1;
                c = read ();
            }
            double res = 0;
            while (!isSpaceChar (c) && c != '.') {
                if (c == 'e' || c == 'E')
                    return res * Math.pow (10, readInt ());
                if (c < '0' || c > '9')
                    throw new InputMismatchException ();
                res *= 10;
                res += c - '0';
                c = read ();
            }
            if (c == '.') {
                c = read ();
                double m = 1;
                while (!isSpaceChar (c)) {
                    if (c == 'e' || c == 'E')
                        return res * Math.pow (10, readInt ());
                    if (c < '0' || c > '9')
                        throw new InputMismatchException ();
                    m /= 10;
                    res += (c - '0') * m;
                    c = read ();
                }
            }
            return res * sgn;
        }

        public boolean isSpaceChar(int c) {
            if (filter != null)
                return filter.isSpaceChar (c);
            return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
        }

        public interface SpaceCharFilter {
            public boolean isSpaceChar(int ch);
        }

        public final int readByteUnsafe() {
            if (ptr < bufLen) return buf[ptr++];
            ptr = 0;
            try {
                bufLen = is.read (buf);
                if (bufLen > 0) {
                    return buf[ptr++];
                } else {
                    return -1;
                }
            } catch (IOException e) {
                throw new UncheckedIOException (e);
            }
        }

        public final int readByte() {
            if (ptr < bufLen) return buf[ptr++];
            ptr = 0;
            try {
                bufLen = is.read (buf);
                if (bufLen > 0) {
                    return buf[ptr++];
                } else {
                    throw new java.io.EOFException ();
                }
            } catch (IOException e) {
                throw new UncheckedIOException (e);
            }
        }

        public final String nextLine() {
            tokenBuf.clear ();
            for (int b = readByte (); b != '\n'; b = readByteUnsafe ()) {
                if (b == -1) break;
                tokenBuf.append (b);
            }
            return new String (tokenBuf.getRawBuf (), 0, tokenBuf.size ());
        }

        public final String nl() {
            return nextLine ();
        }

        public final boolean hasNext() {
            for (int b = readByteUnsafe (); b <= 32 || b >= 127; b = readByteUnsafe ()) {
                if (b == -1) return false;
            }
            --ptr;
            return true;
        }

        public void readArray(Object T) {
            if (T instanceof int[]) {
                int[] arr = (int[]) T;
                for (int i = 0; i < arr.length; i++) {
                    arr[i] = ri ();
                }
            }
            if (T instanceof long[]) {
                long[] arr = (long[]) T;
                for (int i = 0; i < arr.length; i++) {
                    arr[i] = rl ();
                }
            }
            if (T instanceof double[]) {
                double[] arr = (double[]) T;
                for (int i = 0; i < arr.length; i++) {
                    arr[i] = rd ();
                }
            }
            if (T instanceof char[]) {
                char[] arr = (char[]) T;
                for (int i = 0; i < arr.length; i++) {
                    arr[i] = readChar ();
                }
            }
            if (T instanceof String[]) {
                String[] arr = (String[]) T;
                for (int i = 0; i < arr.length; i++) {
                    arr[i] = next ();
                }
            }
            if (T instanceof int[][]) {
                int[][] arr = (int[][]) T;
                for (int i = 0; i < arr.length; i++) {
                    for (int j = 0; j < arr[0].length; j++) {
                        arr[i][j] = ri ();
                    }
                }
            }
            if (T instanceof char[][]) {
                char[][] arr = (char[][]) T;
                for (int i = 0; i < arr.length; i++) {
                    for (int j = 0; j < arr[0].length; j++) {
                        arr[i][j] = readChar ();
                    }
                }
            }
            if (T instanceof long[][]) {
                long[][] arr = (long[][]) T;
                for (int i = 0; i < arr.length; i++) {
                    for (int j = 0; j < arr[0].length; j++) {
                        arr[i][j] = rl ();
                    }
                }

            }
        }

        public final void close() {
            try {
                is.close ();
            } catch (IOException e) {
                throw new UncheckedIOException (e);
            }
        }


        private static final class ByteBuffer {
            private static final int DEFAULT_BUF_SIZE = 1 << 12;
            private byte[] buf;
            private int ptr = 0;

            private ByteBuffer(int capacity) {
                this.buf = new byte[capacity];
            }

            private ByteBuffer() {
                this (DEFAULT_BUF_SIZE);
            }

            private ByteBuffer append(int b) {
                if (ptr == buf.length) {
                    int newLength = buf.length << 1;
                    byte[] newBuf = new byte[newLength];
                    System.arraycopy (buf, 0, newBuf, 0, buf.length);
                    buf = newBuf;
                }
                buf[ptr++] = (byte) b;
                return this;
            }

            private char[] toCharArray() {
                char[] chs = new char[ptr];
                for (int i = 0; i < ptr; i++) {
                    chs[i] = (char) buf[i];
                }
                return chs;
            }

            private byte[] getRawBuf() {
                return buf;
            }

            private int size() {
                return ptr;
            }

            private void clear() {
                ptr = 0;
            }
        }


    }


    static class Debug {
        private final boolean offline;
        private final PrintStream out = System.err;
        static int[] empty = new int[0];

        public Debug(boolean enable) {
            offline = enable && System.getSecurityManager () == null;
        }

        public Debug debug(String name, Object x) {
            return debug (name, x, empty);
        }

        public Debug debug(String name, long x) {
            if (offline) {
                debug (name, "" + x);
            }
            return this;
        }

        public Debug debug(String name, String x) {
            if (offline) {
                out.printf ("%s=%s", name, x);
                out.println ();
            }
            return this;
        }

        public Debug debug(String name, Object x, int... indexes) {
            if (offline) {
                if (x == null || !x.getClass ().isArray ()) {
                    out.append (name);
                    for (int i : indexes) {
                        out.printf ("[%d]", i);
                    }
                    out.append ("=").append ("" + x);
                    out.println ();
                } else {
                    indexes = Arrays.copyOf (indexes, indexes.length + 1);
                    if (x instanceof byte[]) {
                        byte[] arr = (byte[]) x;
                        for (int i = 0; i < arr.length; i++) {
                            indexes[indexes.length - 1] = i;
                            debug (name, arr[i], indexes);
                        }
                    } else if (x instanceof short[]) {
                        short[] arr = (short[]) x;
                        for (int i = 0; i < arr.length; i++) {
                            indexes[indexes.length - 1] = i;
                            debug (name, arr[i], indexes);
                        }
                    } else if (x instanceof boolean[]) {
                        boolean[] arr = (boolean[]) x;
                        for (int i = 0; i < arr.length; i++) {
                            indexes[indexes.length - 1] = i;
                            debug (name, arr[i], indexes);
                        }
                    } else if (x instanceof char[]) {
                        char[] arr = (char[]) x;
                        for (int i = 0; i < arr.length; i++) {
                            indexes[indexes.length - 1] = i;
                            debug (name, arr[i], indexes);
                        }
                    } else if (x instanceof int[]) {
                        int[] arr = (int[]) x;
                        for (int i = 0; i < arr.length; i++) {
                            indexes[indexes.length - 1] = i;
                            debug (name, arr[i], indexes);
                        }
                    } else if (x instanceof float[]) {
                        float[] arr = (float[]) x;
                        for (int i = 0; i < arr.length; i++) {
                            indexes[indexes.length - 1] = i;
                            debug (name, arr[i], indexes);
                        }
                    } else if (x instanceof double[]) {
                        double[] arr = (double[]) x;
                        for (int i = 0; i < arr.length; i++) {
                            indexes[indexes.length - 1] = i;
                            debug (name, arr[i], indexes);
                        }
                    } else if (x instanceof long[]) {
                        long[] arr = (long[]) x;
                        for (int i = 0; i < arr.length; i++) {
                            indexes[indexes.length - 1] = i;
                            debug (name, arr[i], indexes);
                        }
                    } else {
                        Object[] arr = (Object[]) x;
                        for (int i = 0; i < arr.length; i++) {
                            indexes[indexes.length - 1] = i;
                            debug (name, arr[i], indexes);
                        }
                    }
                }
            }
            return this;
        }

    }
}
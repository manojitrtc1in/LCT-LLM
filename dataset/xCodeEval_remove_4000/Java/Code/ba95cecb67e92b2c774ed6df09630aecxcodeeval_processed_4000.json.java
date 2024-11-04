import java.io.*;
import java.text.MessageFormat;
import java.util.Arrays;
import java.util.InputMismatchException;


public class id25 {

    final boolean id11 = java.lang.System.getProperty("id11") != null;

    private void solveOne() {
        int n = nextInt();
        int q = nextInt();
        int[] a = new int[n];
        int[] b = new int[n];
        id14 cols = new id14(n);
        for (int i = 0; i < n; i++) cols.increment(i, a[i]);
        id14 rows = new id14(n);
        for (int i = 0; i < n; i++) rows.increment(i, b[i]);

        for (int i = 0; i < q; i++) {
            int type = nextInt();
            if (type == 1) {
                int x = nextInt() - 1;
                cols.increment(x, 1);
                int y = nextInt() - 1;
                rows.increment(y, 1);
            } else if (type == 2) {
                int x = nextInt() - 1;
                cols.increment(x, -1);
                int y = nextInt() - 1;
                rows.increment(y, -1);
            } else {
                int x1 = nextInt() - 1;
                int y1 = nextInt() - 1;
                int x2 = nextInt();
                int y2 = nextInt();

                boolean ans = cols.min(x1, x2) > 0 || rows.min(y1, y2) > 0;
                System.out.println(ans ? "YES" : "NO");
            }
        }


    }

    class id14 {

        final int n;
        final long[] t;

        id14(int n) {
            this.n = n;
            this.t = new long[2 * n];
        }

        public long min(int l, int r) {
            long res = Long.MAX_VALUE;
            for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
                if ((l & 1) != 0) res = Math.min(t[l++], res);
                if ((r & 1) != 0) res = Math.min(t[--r], res);
            }
            return res;
        }

        public void increment(int p, long value) {
            for (t[p += n] += value; p > 1; p >>= 1) t[p >> 1] = Math.min(t[p], t[p ^ 1]);
        }
    }
    class id17 {


        final int l;
        final int r;
        id17 left;
        id17 right;

        long sum;
        long min;
        Long lazyIncrement;
        Long lazyAssign;

        id17(int l, int r) {
            this.l = l;
            this.r = r;
        }


        id17 left() {
            if (left == null) {
                left = new id17(l, mid());
            }
            return left;
        }

        id17 right() {
            if (right == null) {
                right = new id17(mid(), r);
            }
            return right;
        }

        private int mid() {
            return l + (r - l) / 2;
        }

        private int len() {
            return r - l;
        }

        private boolean isLeaf() {
            return l + 1 == r;
        }

        private boolean noIntersection(int l, int r) {
            return this.l >= r || this.r <= l;
        }

        private boolean equal(int l, int r) {
            return this.l == l && this.r == r;
        }

        private void pushDown() {
            if (lazyAssign != null) {
                left().lazyAssign = lazyAssign;
                left().min = lazyAssign;
                left().sum = left().len() * lazyAssign;

                right().lazyAssign = lazyAssign;
                right().min = lazyAssign;
                right().sum = right().len() * lazyAssign;
                lazyAssign = null;
            }
            if (lazyIncrement != null) {
                if (left().lazyIncrement == null) {
                    left().lazyIncrement = 0L;
                }
                left().lazyIncrement += lazyIncrement;
                left().min += lazyIncrement;
                left().sum += left().len() * lazyIncrement;

                if (right().lazyIncrement == null) {
                    right().lazyIncrement = 0L;
                }
                right().lazyIncrement += lazyIncrement;
                right().min += lazyIncrement;
                right().sum += right().len() * lazyIncrement;
                lazyIncrement = null;
            }

        }

        private void id0() {
            sum = left().sum + right().sum;
            min = Long.min(left().min, right().min);
        }

        public void increment(int l, int r, long delta) {
            if (noIntersection(l, r)) return;
            if (equal(l, r)) {
                applyIncrement(delta);
                return;
            }
            pushDown();
            final int m = mid();
            left().increment(l, Math.min(r, m), delta);
            right().increment(Math.max(m, l), r, delta);
            id0();
        }

        private void applyIncrement(long delta) {
            this.sum += len() * delta;
            this.min += delta;
            this.lazyIncrement = delta;
        }

        public void assign(int l, int r, long value) {
            if (noIntersection(l, r)) return;
            if (equal(l, r)) {
                applyAssign(value);
                return;
            }
            pushDown();
            final int m = mid();
            left().assign(l, Math.min(r, m), value);
            right().assign(Math.max(m, l), r, value);
            id0();
        }

        private void applyAssign(long value) {
            this.sum = len() * value;
            this.min = value;
            this.lazyAssign = value;
            this.lazyIncrement = null;
        }

        public long sum(int l, int r) {
            if (noIntersection(l, r)) return 0;
            if (equal(l, r)) {
                return this.sum;
            }
            pushDown();
            final int m = mid();
            return left().sum(l, Math.min(r, m)) + right().sum(Math.max(m, l), r);
        }

        public long min(int l, int r) {
            if (noIntersection(l, r)) return Long.MAX_VALUE;
            if (equal(l, r)) {
                return this.min;
            }
            pushDown();
            final int m = mid();
            return Long.min(left().min(l, Math.min(r, m)), right().min(Math.max(m, l), r));
        }
    }

    private void solve() {
        int t = 1;

        for (int testCase = 0; testCase < t; testCase++) {
            solveOne();
        }
    }

    class id6 extends RuntimeException {

        id6(String testName,
                                  int testCase,
                                  Object expected,
                                  Object actual, Object... input) {
            super("Testcase: " + testCase + "\n expected = " + expected + ",\n actual = " + actual + ",\n " + Arrays.deepToString(input));
        }
    }

    private void assertThat(boolean b) {
        if (!b) throw new RuntimeException();
    }

    private void assertThat(boolean b, String s) {
        if (!b) throw new RuntimeException(s);
    }

    private int id16(long a) {
        assertThat(Integer.MIN_VALUE <= a && a <= Integer.MAX_VALUE);
        return (int) a;
    }

    void _______debug(String str, Object... os) {
        if (!id11) {
            System.out.println(MessageFormat.format(str, os));
        }
    }

    void _______debug(Object o) {
        if (!id11) {
            _______debug("{0}", String.valueOf(o));
        }
    }

    private int nextInt() {
        return System.in.readInt();
    }

    private long nextLong() {
        return System.in.readLong();
    }

    private String nextString() {
        return System.in.readString();
    }

    private int[] id22(int n) {
        return System.in.id2(n);
    }

    private long[] id26(int n) {
        return System.in.id12(n);
    }

    public static void main(String[] args) {
        new id25().run();
    }

    static class System {
        private static id13 in;
        private static id18 out;
    }

    private void run() {
        final boolean USE_IO = id11;
        if (USE_IO) {
            System.in = new id13(java.lang.System.in);
            System.out = new id18(java.lang.System.out);
            solve();
            System.out.flush();
        } else {
            final String nameIn = "input.txt";
            final String nameOut = "output.txt";
            try {
                System.in = new id13(new FileInputStream(nameIn));
                System.out = new id18(new PrintStream(nameOut));
                solve();
                System.out.flush();
            } catch (FileNotFoundException e) {
                e.printStackTrace();
            }
        }
    }

    private static class id18 {
        private static final int BUF_SIZE = 8192;
        private final byte[] buf = new byte[BUF_SIZE];
        private final OutputStream out;
        private int ptr = 0;

        private id18() {
            this(java.lang.System.out);
        }

        public id18(OutputStream os) {
            this.out = os;
        }

        public id18(String path) {
            try {
                this.out = new FileOutputStream(path);
            } catch (FileNotFoundException e) {
                throw new RuntimeException("FastWriter");
            }
        }

        public id18 print(byte b) {
            buf[ptr++] = b;
            if (ptr == BUF_SIZE) innerFlush();
            return this;
        }

        public id18 print(char c) {
            return print((byte) c);
        }

        public id18 print(char[] s) {
            for (char c : s) {
                buf[ptr++] = (byte) c;
                if (ptr == BUF_SIZE) innerFlush();
            }
            return this;
        }

        public id18 print(String s) {
            s.chars().forEach(c -> {
                buf[ptr++] = (byte) c;
                if (ptr == BUF_SIZE) innerFlush();
            });
            return this;
        }

        

        public id18 print0(char[] s) {
            if (ptr + s.length < BUF_SIZE) {
                for (char c : s) {
                    buf[ptr++] = (byte) c;
                }
            } else {
                for (char c : s) {
                    buf[ptr++] = (byte) c;
                    if (ptr == BUF_SIZE) innerFlush();
                }
            }
            return this;
        }

        

        public id18 print0(String s) {
            if (ptr + s.length() < BUF_SIZE) {
                for (int i = 0; i < s.length(); i++) {
                    buf[ptr++] = (byte) s.charAt(i);
                }
            } else {
                for (int i = 0; i < s.length(); i++) {
                    buf[ptr++] = (byte) s.charAt(i);
                    if (ptr == BUF_SIZE) innerFlush();
                }
            }
            return this;
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

        public id18 print(int x) {
            if (x == Integer.MIN_VALUE) {
                return print((long) x);
            }
            if (ptr + 12 >= BUF_SIZE) innerFlush();
            if (x < 0) {
                print((byte) '-');
                x = -x;
            }
            int d = countDigits(x);
            for (int i = ptr + d - 1; i >= ptr; i--) {
                buf[i] = (byte) ('0' + x % 10);
                x /= 10;
            }
            ptr += d;
            return this;
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

        public id18 print(long x) {
            if (x == Long.MIN_VALUE) {
                return print("" + x);
            }
            if (ptr + 21 >= BUF_SIZE) innerFlush();
            if (x < 0) {
                print((byte) '-');
                x = -x;
            }
            int d = countDigits(x);
            for (int i = ptr + d - 1; i >= ptr; i--) {
                buf[i] = (byte) ('0' + x % 10);
                x /= 10;
            }
            ptr += d;
            return this;
        }

        public id18 print(double x, int precision) {
            if (x < 0) {
                print('-');
                x = -x;
            }
            x += Math.pow(10, -precision) / 2;
            

            print((long) x).print(".");
            x -= (long) x;
            for (int i = 0; i < precision; i++) {
                x *= 10;
                print((char) ('0' + (int) x));
                x -= (int) x;
            }
            return this;
        }

        public id18 println(int[] a, int from, int upTo, char separator) {
            for (int i = from; i < upTo; i++) {
                print(a[i]);
                print(separator);
            }
            print('\n');
            return this;
        }

        public id18 println(int[] a) {
            return println(a, 0, a.length, ' ');
        }

        public id18 println(long[] a, int from, int upTo, char separator) {
            for (int i = from; i < upTo; i++) {
                print(a[i]);
                print(separator);
            }
            print('\n');
            return this;
        }

        public id18 println(long[] a) {
            return println(a, 0, a.length, ' ');
        }

        public id18 println(char c) {
            return print(c).println();
        }

        public id18 println(int x) {
            return print(x).println();
        }

        public id18 println(long x) {
            return print(x).println();
        }

        public id18 println(String x) {
            return print(x).println();
        }

        public id18 println(Object x) {
            return print(x.toString()).println();
        }

        public id18 println(double x, int precision) {
            return print(x, precision).println();
        }

        public id18 println() {
            return print((byte) '\n');
        }

        public id18 printf(String format, Object... args) {
            return print(String.format(format, args));
        }

        private void innerFlush() {
            try {
                out.write(buf, 0, ptr);
                ptr = 0;
            } catch (IOException e) {
                throw new RuntimeException("innerFlush");
            }
        }

        public void flush() {
            innerFlush();
            try {
                out.flush();
            } catch (IOException e) {
                throw new RuntimeException("flush");
            }
        }
    }

    private static class id13 {
        private boolean finished = false;

        private InputStream stream;
        private byte[] buf = new byte[1024];
        private int curChar;
        private int numChars;
        private id24 filter;

        public id13(InputStream stream) {
            this.stream = stream;
        }

        public double[] id4(int size) {
            double[] array = new double[size];
            for (int i = 0; i < size; i++) {
                array[i] = readDouble();
            }
            return array;
        }

        public String[] id21(int size) {
            String[] array = new String[size];
            for (int i = 0; i < size; i++) {
                array[i] = readString();
            }
            return array;
        }

        public char[] id7(int size) {
            char[] array = new char[size];
            for (int i = 0; i < size; i++) {
                array[i] = readCharacter();
            }
            return array;
        }

        public char[][] readTable(int rowCount, int columnCount) {
            char[][] table = new char[rowCount][];
            for (int i = 0; i < rowCount; i++) {
                table[i] = this.id7(columnCount);
            }
            return table;
        }

        public int[][] id10(int rowCount, int columnCount) {
            int[][] table = new int[rowCount][];
            for (int i = 0; i < rowCount; i++) {
                table[i] = id2(columnCount);
            }
            return table;
        }

        public double[][] id1(int rowCount, int columnCount) {
            double[][] table = new double[rowCount][];
            for (int i = 0; i < rowCount; i++) {
                table[i] = this.id4(columnCount);
            }
            return table;
        }

        public long[][] id3(int rowCount, int columnCount) {
            long[][] table = new long[rowCount][];
            for (int i = 0; i < rowCount; i++) {
                table[i] = id12(columnCount);
            }
            return table;
        }

        public String[][] id19(int rowCount, int columnCount) {
            String[][] table = new String[rowCount][];
            for (int i = 0; i < rowCount; i++) {
                table[i] = this.id21(columnCount);
            }
            return table;
        }

        public String readText() {
            StringBuilder result = new StringBuilder();
            while (true) {
                int character = read();
                if (character == '\r') {
                    continue;
                }
                if (character == -1) {
                    break;
                }
                result.append((char) character);
            }
            return result.toString();
        }

        public void id15(String[]... arrays) {
            for (int i = 0; i < arrays[0].length; i++) {
                for (int j = 0; j < arrays.length; j++) {
                    arrays[j][i] = readString();
                }
            }
        }

        public long[] id12(int size) {
            long[] array = new long[size];
            for (int i = 0; i < size; i++) {
                array[i] = readLong();
            }
            return array;
        }

        public int[] id2(int size) {
            int[] array = new int[size];
            for (int i = 0; i < size; i++) {
                array[i] = readInt();
            }
            return array;
        }

        public int read() {
            if (numChars == -1) {
                throw new InputMismatchException();
            }
            if (curChar >= numChars) {
                curChar = 0;
                try {
                    numChars = stream.read(buf);
                } catch (IOException e) {
                    throw new InputMismatchException();
                }
                if (numChars <= 0) {
                    return -1;
                }
            }
            return buf[curChar++];
        }

        public int peek() {
            if (numChars == -1) {
                return -1;
            }
            if (curChar >= numChars) {
                curChar = 0;
                try {
                    numChars = stream.read(buf);
                } catch (IOException e) {
                    return -1;
                }
                if (numChars <= 0) {
                    return -1;
                }
            }
            return buf[curChar];
        }

        public int id23() {
            while (isWhitespace(peek())) {
                read();
            }
            return peek();
        }

        public int readInt() {
            int c = read();
            while (id9(c)) {
                c = read();
            }
            int sgn = 1;
            if (c == '-') {
                sgn = -1;
                c = read();
            }
            int res = 0;
            do {
                if (c < '0' || c > '9') {
                    throw new InputMismatchException();
                }
                res *= 10;
                res += c - '0';
                c = read();
            } while (!id9(c));
            return res * sgn;
        }

        public long readLong() {
            int c = read();
            while (id9(c)) {
                c = read();
            }
            int sgn = 1;
            if (c == '-') {
                sgn = -1;
                c = read();
            }
            long res = 0;
            do {
                if (c < '0' || c > '9') {
                    throw new InputMismatchException();
                }
                res *= 10;
                res += c - '0';
                c = read();
            } while (!id9(c));
            return res * sgn;
        }

        public String readString() {
            int c = read();
            while (id9(c)) {
                c = read();
            }
            StringBuilder res = new StringBuilder();
            do {
                if (Character.isValidCodePoint(c)) {
                    res.appendCodePoint(c);
                }
                c = read();
            } while (!id9(c));
            return res.toString();
        }

        public boolean id9(int c) {
            if (filter != null) {
                return filter.id9(c);
            }
            return isWhitespace(c);
        }

        public static boolean isWhitespace(int c) {
            return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
        }

        private String id5() {
            StringBuilder buf = new StringBuilder();
            int c = read();
            while (c != '\n' && c != -1) {
                if (c != '\r') {
                    buf.appendCodePoint(c);
                }
                c = read();
            }
            return buf.toString();
        }

        public String readLine() {
            String s = id5();
            while (s.trim().length() == 0) {
                s = id5();
            }
            return s;
        }

        public String readLine(boolean id20) {
            if (id20) {
                return readLine();
            } else {
                return id5();
            }
        }

        public char readCharacter() {
            int c = read();
            while (id9(c)) {
                c = read();
            }
            return (char) c;
        }

        public double readDouble() {
            int c = read();
            while (id9(c)) {
                c = read();
            }
            int sgn = 1;
            if (c == '-') {
                sgn = -1;
                c = read();
            }
            double res = 0;
            while (!id9(c) && c != '.') {
                if (c == 'e' || c == 'E') {
                    return res * Math.pow(10, readInt());
                }
                if (c < '0' || c > '9') {
                    throw new InputMismatchException();
                }
                res *= 10;
                res += c - '0';
                c = read();
            }
            if (c == '.') {
                c = read();
                double m = 1;
                while (!id9(c)) {
                    if (c == 'e' || c == 'E') {
                        return res * Math.pow(10, readInt());
                    }
                    if (c < '0' || c > '9') {
                        throw new InputMismatchException();
                    }
                    m /= 10;
                    res += (c - '0') * m;
                    c = read();
                }
            }
            return res * sgn;
        }

        public boolean id8() {
            int value;
            while (id9(value = peek()) && value != -1) {
                read();
            }
            return value == -1;
        }

        public String next() {
            return readString();
        }

        public id24 getFilter() {
            return filter;
        }

        public void setFilter(id24 filter) {
            this.filter = filter;
        }

        public interface id24 {
            public boolean id9(int ch);
        }
    }

}
import java.io.*;
import java.util.Arrays;
import java.util.Comparator;
import java.util.InputMismatchException;
import java.util.function.BinaryOperator;
import java.util.function.Predicate;


public class id10 {

    private void solveOne() {
        int n = nextInt();
        int k = nextInt();
        int[] a = decrement(id25(k));
        int[] t = id25(k);
        id17[] id8 = new id17[k];
        for (int i = 0; i < k; i++) {
            id8[i] = new id17(t[i], a[i]);
        }
        Arrays.sort(id8, Comparator.comparingInt(id17::getInd));
        int[] sums = new int[k];

        for (int i = 0; i < k; i++) {
            sums[i] = id8[i].val + id8[i].ind;
        }

        id13 segmentTree = SegmentTree.MIN(sums);



        for (int i = 0; i < n; i++) {

            final int i_ = i;
            int localAns;

            

            

            

            

            

            if (i != 0) {
                int pivot = lowerBound(-1, k, mid -> i_ <= id8[mid].ind);
                segmentTree.inc(0, pivot, 1);
                segmentTree.inc(pivot, k, -1);
            }
            localAns = segmentTree.query(0, k);

            System.out.print(localAns);
            System.out.print(' ');
        }
        System.out.println();


    }


    private int lowerBound(int exclusiveLeft, int inclusiveRight, Predicate<Integer> predicate) {
        while (inclusiveRight - exclusiveLeft > 1) {
            int middle = exclusiveLeft + (inclusiveRight - exclusiveLeft) / 2;
            if (predicate.test(middle)) {
                inclusiveRight = middle;
            } else {
                exclusiveLeft = middle;
            }
        }
        return inclusiveRight;
    }

    public static int[] decrement(int[] a) {
        for (int i = 0; i < a.length; i++) {
            a[i]--;
        }
        return a;
    }

    interface id13 {
        void inc(int l, int r, int value);

        int query(int l, int r);
    }

    static class id4 implements id13 {
        int neutral;
        BinaryOperator<Integer> binaryOperator;

        static id4 MIN(int[] a) {
            return new id4(a, Integer::min, Integer.MAX_VALUE);
        }

        int[] a;

        id4(int[] a, BinaryOperator<Integer> binaryOperator, int neutral) {
            this.binaryOperator = binaryOperator;
            this.neutral = neutral;
            this.a = Arrays.copyOf(a, a.length);
        }

        @Override
        public void inc(int l, int r, int value) {
            for (int i = l; i < r; i++) a[i] += value;
        }

        @Override
        public int query(int l, int r) {
            int ans = neutral;
            for (int i = l; i < r; i++) ans = binaryOperator.apply(ans, a[i]);
            return ans;
        }
    }

    static class SegmentTree implements id13 {
        int neutral;
        BinaryOperator<Integer> binaryOperator;

        SegmentTree(int[] a, BinaryOperator<Integer> binaryOperator, int neutral) {
            this.binaryOperator = binaryOperator;
            this.neutral = neutral;
            this.n = a.length;
            this.t = new int[2 * n];
            

            this.d = new int[n];
            this.h = 32 - Integer.numberOfLeadingZeros(n);
            for (int i = 0; i < n; i++) {
                this.inc(i, i + 1, a[i]);
            }

        }

        static SegmentTree MIN(int[] a) {
            return new SegmentTree(a, Integer::min, (int)(1e9 + 3e5));
        }

        static SegmentTree MAX(int[] a) {
            return new SegmentTree(a, Integer::max, Integer.MIN_VALUE);
        }

        static SegmentTree SUM(int[] a) {
            return new SegmentTree(a, Integer::sum, 0);
        }

        int n;
        int[] t;
        int[] d;
        int h;

        void apply(int p, int value) {
            t[p] += value;
            if (p < n) d[p] += value;
        }

        void build(int p) {
            while (p > 1) {
                p >>= 1;
                t[p] = binaryOperator.apply(t[p << 1], t[p << 1 | 1]) + d[p];
            }
        }

        void push(int p) {
            for (int s = h; s > 0; --s) {
                int i = p >> s;
                if (d[i] != 0) {
                    apply(i << 1, d[i]);
                    apply(i << 1 | 1, d[i]);
                    d[i] = 0;
                }
            }
        }

        public void inc(int l, int r, int value) {
            if(l >= n) return;
            l += n;
            r += n;
            int l0 = l, r0 = r;
            for (; l < r; l >>= 1, r >>= 1) {
                if ((l & 1) != 0) apply(l++, value);
                if ((r & 1) != 0) apply(--r, value);
            }
            build(l0);
            build(r0 - 1);
        }


        public int query(int l, int r) {
            if(l >= n) return neutral;
            l += n;
            r += n;
            push(l);
            push(r - 1);
            int res = neutral;
            for (; l < r; l >>= 1, r >>= 1) {
                if ((l & 1) != 0) res = binaryOperator.apply(res, t[l++]);
                if ((r & 1) != 0) res = binaryOperator.apply(t[--r], res);
            }
            return res;
        }
    }

    static class id17 {
        int val;
        int ind;

        public id17(int val, int ind) {
            this.val = val;
            this.ind = ind;
        }

        public int getVal() {
            return val;
        }

        public int getInd() {
            return ind;
        }
    }

    private void solve() {
        int t = nextInt();
        for (int tt = 0; tt < t; tt++) {
            solveOne();
        }
    }

    class id6 extends RuntimeException {

        id6(Object expected,
                                  Object actual, Object... input) {
            super("expected = " + expected + ",\n actual = " + actual + ",\n " + Arrays.deepToString(input));
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

    private int[] id25(int n) {
        return System.in.id1(n);
    }

    private long[] id28(int n) {
        return System.in.id14(n);
    }

    public static void main(String[] args) {
        new id10().run();
    }

    static class System {
        private static id15 in;
        private static id21 out;
    }

    private void run() {
        System.in = new id15(java.lang.System.in);
        System.out = new id21(java.lang.System.out);
        solve();
        System.out.flush();
    }

    private static class id21 {
        private static final int BUF_SIZE = 8192;
        private final byte[] buf = new byte[BUF_SIZE];
        private final OutputStream out;
        private int ptr = 0;

        private id21() {
            this(java.lang.System.out);
        }

        public id21(OutputStream os) {
            this.out = os;
        }

        public id21(String path) {
            try {
                this.out = new FileOutputStream(path);
            } catch (FileNotFoundException e) {
                throw new RuntimeException("FastWriter");
            }
        }

        public id21 print(byte b) {
            buf[ptr++] = b;
            if (ptr == BUF_SIZE) innerflush();
            return this;
        }

        public id21 print(char c) {
            return print((byte) c);
        }

        public id21 print(char[] s) {
            for (char c : s) {
                buf[ptr++] = (byte) c;
                if (ptr == BUF_SIZE) innerflush();
            }
            return this;
        }

        public id21 print(String s) {
            s.chars().forEach(c -> {
                buf[ptr++] = (byte) c;
                if (ptr == BUF_SIZE) innerflush();
            });
            return this;
        }

        

        public id21 print0(char[] s) {
            if (ptr + s.length < BUF_SIZE) {
                for (char c : s) {
                    buf[ptr++] = (byte) c;
                }
            } else {
                for (char c : s) {
                    buf[ptr++] = (byte) c;
                    if (ptr == BUF_SIZE) innerflush();
                }
            }
            return this;
        }

        

        public id21 print0(String s) {
            if (ptr + s.length() < BUF_SIZE) {
                for (int i = 0; i < s.length(); i++) {
                    buf[ptr++] = (byte) s.charAt(i);
                }
            } else {
                for (int i = 0; i < s.length(); i++) {
                    buf[ptr++] = (byte) s.charAt(i);
                    if (ptr == BUF_SIZE) innerflush();
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

        public id21 print(int x) {
            if (x == Integer.MIN_VALUE) {
                return print((long) x);
            }
            if (ptr + 12 >= BUF_SIZE) innerflush();
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

        public id21 print(long x) {
            if (x == Long.MIN_VALUE) {
                return print("" + x);
            }
            if (ptr + 21 >= BUF_SIZE) innerflush();
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

        public id21 print(double x, int precision) {
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

        public id21 println(int[] a, int from, int upTo, char separator) {
            for (int i = from; i < upTo; i++) {
                print(a[i]);
                print(separator);
            }
            print('\n');
            return this;
        }

        public id21 println(int[] a) {
            return println(a, 0, a.length, ' ');
        }

        public id21 println(char c) {
            return print(c).println();
        }

        public id21 println(int x) {
            return print(x).println();
        }

        public id21 println(long x) {
            return print(x).println();
        }

        public id21 println(String x) {
            return print(x).println();
        }

        public id21 println(double x, int precision) {
            return print(x, precision).println();
        }

        public id21 println() {
            return print((byte) '\n');
        }

        public id21 printf(String format, Object... args) {
            return print(String.format(format, args));
        }

        private void innerflush() {
            try {
                out.write(buf, 0, ptr);
                ptr = 0;
            } catch (IOException e) {
                throw new RuntimeException("innerflush");
            }
        }

        public void flush() {
            innerflush();
            try {
                out.flush();
            } catch (IOException e) {
                throw new RuntimeException("flush");
            }
        }
    }

    private static class id15 {
        private boolean finished = false;

        private InputStream stream;
        private byte[] buf = new byte[1024];
        private int curChar;
        private int numChars;
        private id27 filter;

        public id15(InputStream stream) {
            this.stream = stream;
        }

        public double[] id3(int size) {
            double[] array = new double[size];
            for (int i = 0; i < size; i++) {
                array[i] = readDouble();
            }
            return array;
        }

        public String[] id24(int size) {
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

        public void id16(int[]... arrays) {
            for (int i = 0; i < arrays[0].length; i++) {
                for (int j = 0; j < arrays.length; j++) {
                    arrays[j][i] = readInt();
                }
            }
        }

        public void id18(long[]... arrays) {
            for (int i = 0; i < arrays[0].length; i++) {
                for (int j = 0; j < arrays.length; j++) {
                    arrays[j][i] = readLong();
                }
            }
        }

        public void id20(double[]... arrays) {
            for (int i = 0; i < arrays[0].length; i++) {
                for (int j = 0; j < arrays.length; j++) {
                    arrays[j][i] = readDouble();
                }
            }
        }

        public char[][] readTable(int rowCount, int columnCount) {
            char[][] table = new char[rowCount][];
            for (int i = 0; i < rowCount; i++) {
                table[i] = this.id7(columnCount);
            }
            return table;
        }

        public int[][] id12(int rowCount, int columnCount) {
            int[][] table = new int[rowCount][];
            for (int i = 0; i < rowCount; i++) {
                table[i] = id1(columnCount);
            }
            return table;
        }

        public double[][] id0(int rowCount, int columnCount) {
            double[][] table = new double[rowCount][];
            for (int i = 0; i < rowCount; i++) {
                table[i] = this.id3(columnCount);
            }
            return table;
        }

        public long[][] id2(int rowCount, int columnCount) {
            long[][] table = new long[rowCount][];
            for (int i = 0; i < rowCount; i++) {
                table[i] = id14(columnCount);
            }
            return table;
        }

        public String[][] id22(int rowCount, int columnCount) {
            String[][] table = new String[rowCount][];
            for (int i = 0; i < rowCount; i++) {
                table[i] = this.id24(columnCount);
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

        public void id19(String[]... arrays) {
            for (int i = 0; i < arrays[0].length; i++) {
                for (int j = 0; j < arrays.length; j++) {
                    arrays[j][i] = readString();
                }
            }
        }

        public long[] id14(int size) {
            long[] array = new long[size];
            for (int i = 0; i < size; i++) {
                array[i] = readLong();
            }
            return array;
        }

        public int[] id1(int size) {
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

        public int id26() {
            while (isWhitespace(peek())) {
                read();
            }
            return peek();
        }

        public int readInt() {
            int c = read();
            while (id11(c)) {
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
            } while (!id11(c));
            return res * sgn;
        }

        public long readLong() {
            int c = read();
            while (id11(c)) {
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
            } while (!id11(c));
            return res * sgn;
        }

        public String readString() {
            int c = read();
            while (id11(c)) {
                c = read();
            }
            StringBuilder res = new StringBuilder();
            do {
                if (Character.isValidCodePoint(c)) {
                    res.appendCodePoint(c);
                }
                c = read();
            } while (!id11(c));
            return res.toString();
        }

        public boolean id11(int c) {
            if (filter != null) {
                return filter.id11(c);
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

        public String readLine(boolean id23) {
            if (id23) {
                return readLine();
            } else {
                return id5();
            }
        }

        public char readCharacter() {
            int c = read();
            while (id11(c)) {
                c = read();
            }
            return (char) c;
        }

        public double readDouble() {
            int c = read();
            while (id11(c)) {
                c = read();
            }
            int sgn = 1;
            if (c == '-') {
                sgn = -1;
                c = read();
            }
            double res = 0;
            while (!id11(c) && c != '.') {
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
                while (!id11(c)) {
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

        public boolean id9() {
            int value;
            while (id11(value = peek()) && value != -1) {
                read();
            }
            return value == -1;
        }

        public String next() {
            return readString();
        }

        public id27 getFilter() {
            return filter;
        }

        public void setFilter(id27 filter) {
            this.filter = filter;
        }

        public interface id27 {
            public boolean id11(int ch);
        }
    }

}
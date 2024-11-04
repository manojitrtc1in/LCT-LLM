import java.io.*;
import java.text.MessageFormat;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.util.Objects;
import java.util.Random;
import java.util.function.BiFunction;
import java.util.function.Predicate;


public class D {

    final boolean id16 = java.lang.System.getProperty("id16") != null;

    private String id19(int n, long[] a) {
        for (int l = 0; l < n; l++) {
            for (int r = 0; r < n; r++) {
                if (l < r) {
                    long max = Long.MIN_VALUE;
                    long sum = 0;
                    for (int i = l; i <= r; i++) {
                        max = Math.max(max, a[i]);
                        sum += a[i];
                    }
                    if (max < sum) {
                        return "NO";
                    }
                }
            }
        }
        return "YES";
    }

    private String id3(int testCase, int n, long[] a) {
        id26 st = new id26(a);
        id22 bit = new id22(a);
        for (int l = 0; l < n; l++) {
            for (int r = 0; r < n; r++) {
                if (l < r) {
                    if (st.get(l, r) < bit.get(l, r)) {
                        return "NO";
                    }
                }
            }
        }
        return "YES";
    }


    String id42(int testCase, int n, long[] a) {
        id26 id12 = new id26(a);

        int[] first = id23(a, id12);
        int[] last = id14(a, id12);

        long[] id21 = id21(a);
        long[] prefSum = prefSum(a);
        id26 id28 = new id26(id21);
        id26 id30 = new id26(prefSum);

        for (int i = 0; i < n; i++) {
            

            long exclude1 = i == n - 1 ? 0 : id21[i + 1];
            boolean id20 = a[i] >= id28.get(first[i], i) - exclude1;

            long exclude2 = i == 0 ? 0 : prefSum[i - 1];
            boolean id29 = a[i] >= id30.get(i, last[i]) - exclude2;


            if (!id20 || !id29) {
                return "NO";
            }
        }

        return "YES";
    }

    long[] id21(long[] a) {
        int n = a.length;
        long[] ans = new long[n];
        ans[n - 1] = a[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            ans[i] = ans[i + 1] + a[i];
        }
        return ans;
    }

    long[] prefSum(long[] a) {
        int n = a.length;
        long[] ans = new long[n];
        ans[0] = a[0];
        for (int i = 1; i < n; i++) {
            ans[i] = ans[i - 1] + a[i];
        }
        return ans;
    }

    int[] id14(long[] a, id26 id12) {
        int n = a.length;
        int[] ans = new int[n];
        for (int i = 0; i < n; i++) {
            final int i_ = i;
            ans[i] = upperBound(i, n, ind -> id12.get(i_, ind) <= a[i_]);
        }

        return ans;
    }

    int[] id23(long[] a, id26 id12) {
        int n = a.length;
        int[] ans = new int[n];

        for (int i = 0; i < n; i++) {
            final int i_ = i;
            ans[i] = lowerBound(-1, i, ind -> id12.get(ind, i_) <= a[i_]);
        }

        return ans;
    }


    int upperBound(int inclusiveLeft, int exclusiveRight, Predicate<Integer> predicate) {
        while (exclusiveRight - inclusiveLeft > 1) {
            int middle = inclusiveLeft + (exclusiveRight - inclusiveLeft) / 2;
            if (predicate.test(middle)) {
                inclusiveLeft = middle;
            } else {
                exclusiveRight = middle;
            }
        }
        return inclusiveLeft;
    }

    int lowerBound(int exclusiveLeft, int inclusiveRight, Predicate<Integer> predicate) {
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


    static class id26 {
        boolean linear = false;
        

        public static final BiFunction<Long, Long, Long> MAX = Math::max;



        BiFunction<Long, Long, Long> FUNC = MAX;

        int LOG = 20;
        long[][] id32;
        id24 rmq;
        long[] a;
        public id26(long[] a) {
            int n = a.length;
            if (linear) {
                this.a = a;
                rmq = new id24(n, (i, j) -> -Long.compare(a[i], a[j]));

            } else {

                id32 = new long[n][LOG];
                for (int i = 0; i < n; i++) {
                    id32[i][0] = a[i];
                }
                for (int j = 1; j < LOG; j++) {
                    int jj = (1 << (j - 1));
                    for (int i = 0; i + (1 << j) - 1 < n; i++) {


                        id32[i][j] = Math.max(id32[i][j - 1], id32[i + jj][j - 1]);
                    }
                }
            }
        }

        private long get(int l, int r) {
            if (linear) {
                return a[rmq.query(l, r)];
            } else {
                int len = r - l + 1;
                int p = 0;
                while ((1 << (p + 1)) <= len) {
                    p++;
                }


                return Math.max(id32[l][p], id32[r - (1 << p) + 1][p]);
            }
        }

    }


    static class Bits {
        private Bits() {
        }

        public static int set(int x, int i) {
            return x | (1 << i);
        }

        public static int clear(int x, int i) {
            return x & (~(1 << i));
        }

        public static int id8(int x) {
            return 31 - Integer.numberOfLeadingZeros(x);
        }

        public static int id37(int n) {
            if (n == 0) {
                return 0;
            }
            return -1 << (32 - n);
        }

    }

    static interface id36 {
        long apply(int x);

    }

    static class id6 {
        private int[][] st;
        private id9 merger;

        public id6(id36 function, int length, id9 merger) {
            int m = Log2.floorLog(length);
            st = new int[m + 1][length];
            this.merger = merger;
            for (int i = 0; i < length; i++) {
                st[0][i] = i;
            }
            for (int i = 0; i < m; i++) {
                int interval = 1 << i;
                for (int j = 0; j < length; j++) {
                    if (j + interval < length) {
                        st[i + 1][j] = Math.max(st[i][j], st[i][j + interval]);
                    } else {
                        st[i + 1][j] = st[i][j];
                    }
                }
            }
        }








        public int query(int left, int right) {
            int queryLen = right - left + 1;
            int bit = Log2.floorLog(queryLen);
            

            

            return Math.max(st[bit][left], st[bit][right + 1 - (1 << bit)]);
        }

        public String toString() {
            return Arrays.toString(st[0]);
        }

    }

    static interface id9 {
        int apply(int a, int b);

    }

    static interface IntegerComparator {
        public int compare(int a, int b);

    }

    static class id24 {
        int n;
        IntegerComparator comp;
        static int shift = 5;
        static int blockSize = 1 << shift;
        static int andMask = blockSize - 1;
        int[] minIndices;
        int[] toLeft;
        id6 st;








        public id24(int n, IntegerComparator comp) {
            this.comp = comp;
            this.n = n;
            minIndices = new int[DigitUtils.ceilDiv(n, blockSize)];
            Arrays.fill(minIndices, -1);
            for (int i = 0; i < n; i++) {
                int to = i >>> shift;
                if (minIndices[to] == -1 ||
                        comp.compare(minIndices[to], i) > 0) {
                    minIndices[to] = i;
                }
            }
            st = new id6(i -> minIndices[i],
                    minIndices.length,
                    (a, b) -> comp.compare(a, b) <= 0 ? a : b);
            toLeft = new int[n];
            int mask = 0;
            for (int i = 0; i < n; i++) {
                if ((i & andMask) == 0) {
                    mask = 0;
                }
                int b = i >>> shift;
                while (mask != 0) {
                    int head = Bits.id8(mask);
                    if (comp.compare(i, (b << shift) | head) <= 0) {
                        mask = Bits.clear(mask, head);
                    } else {
                        break;
                    }
                }
                mask = Bits.set(mask, i & andMask);
                toLeft[i] = mask;
            }
        }

        public int query(int l, int r) {
            

            int bl = l >>> shift;
            int br = r >>> shift;
            int tl = l & andMask;


            if (bl == br) {
                return Integer.numberOfTrailingZeros(toLeft[r] & Bits.id37(32 - tl)) | (bl << shift);
            }
            int res1 = Integer.numberOfTrailingZeros(toLeft[(bl << shift) | andMask] & Bits.id37(32 - tl)) | (bl << shift);
            int res2 = Integer.numberOfTrailingZeros(toLeft[r]) | (br << shift);
            int best = Math.max(res1, res2);
            if (bl + 1 < br) {
                best = Math.max(best, st.query(bl + 1, br - 1));
            }
            return best;
        }

    }

    static class Log2 {
        public static int floorLog(int x) {
            if (x <= 0) {
                throw new IllegalArgumentException();
            }
            return 31 - Integer.numberOfLeadingZeros(x);
        }

    }

    static class DigitUtils {
        private DigitUtils() {
        }

        public static int floorDiv(int a, int b) {
            return a < 0 ? -ceilDiv(-a, b) : a / b;
        }

        public static int ceilDiv(int a, int b) {
            if (a < 0) {
                return -floorDiv(-a, b);
            }
            int c = a / b;
            if (c * b < a) {
                return c + 1;
            }
            return c;
        }

    }

    static class id22 {
        private final long[] value;

        public id22(int size) {
            value = new long[size];
        }

        public id22(long[] a) {
            int size = a.length;
            value = new long[size];
            for (int i = 0; i < size; i++) {
                add(i, a[i]);
            }

        }

        public long get(int from, int to) {
            if (from > to) {
                return 0;
            }
            return get(to) - get(from - 1);
        }

        private long get(int to) {
            long result = 0;
            while (to >= 0) {
                result += value[to];
                to = (to & (to + 1)) - 1;
            }
            return result;
        }

        public void add(int at, long value) {
            while (at < this.value.length) {
                this.value[at] += value;
                at = at | (at + 1);
            }
        }
    }

    boolean id27 = false;

    private void solve() {
        if (id27) {
            Random r = new Random(42);
            for (int testCase = 1; testCase <= 10000; testCase++) {
                int n = r.nextInt(500) + 5;
                long[] a = new long[n];
                for (int j = 0; j < n; j++) {
                    a[j] = -20 + r.nextInt(40);
                }
                String expected = id3(testCase, n, a);
                String actual = id42(testCase, n, a);




                if (!Objects.equals(expected, actual)) {
                    throw new id7(
                            testCase,
                            expected,
                            actual,
                            n, a);
                }
            }
        } else {
            int t = nextInt();
            for (int tt = 0; tt < t; tt++) {
                int n = nextInt();
                long[] a = id43(n);


                String actual = id42(tt, n, a);


                System.out.println(actual);
            }
        }
    }

    class id7 extends RuntimeException {

        id7(int testCase,
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

    private int id31(long a) {
        assertThat(Integer.MIN_VALUE <= a && a <= Integer.MAX_VALUE);
        return (int) a;
    }

    void _______debug(String str, Object... os) {
        if (!id16) {
            System.out.println(MessageFormat.format(str, os));
        }
    }

    void _______debug(Object o) {
        if (!id16) {
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

    private int[] id39(int n) {
        return System.in.id1(n);
    }

    private long[] id43(int n) {
        return System.in.id17(n);
    }

    public static void main(String[] args) {
        new D().run();
    }

    static class System {
        private static id18 in;
        private static id33 out;
    }

    private void run() {
        final boolean USE_IO = id16;
        if (USE_IO) {
            System.in = new id18(java.lang.System.in);
            System.out = new id33(java.lang.System.out);
            solve();
            System.out.flush();
        } else {
            final String nameIn = "input.txt";
            final String nameOut = "output.txt";
            try {
                System.in = new id18(new FileInputStream(nameIn));
                System.out = new id33(new PrintStream(nameOut));
                solve();
                System.out.flush();
            } catch (FileNotFoundException e) {
                e.printStackTrace();
            }
        }
    }

    private static class id33 {
        private static final int BUF_SIZE = 8192;
        private final byte[] buf = new byte[BUF_SIZE];
        private final OutputStream out;
        private int ptr = 0;

        private id33() {
            this(java.lang.System.out);
        }

        public id33(OutputStream os) {
            this.out = os;
        }

        public id33(String path) {
            try {
                this.out = new FileOutputStream(path);
            } catch (FileNotFoundException e) {
                throw new RuntimeException("FastWriter");
            }
        }

        public id33 print(byte b) {
            buf[ptr++] = b;
            if (ptr == BUF_SIZE) innerFlush();
            return this;
        }

        public id33 print(char c) {
            return print((byte) c);
        }

        public id33 print(char[] s) {
            for (char c : s) {
                buf[ptr++] = (byte) c;
                if (ptr == BUF_SIZE) innerFlush();
            }
            return this;
        }

        public id33 print(String s) {
            s.chars().forEach(c -> {
                buf[ptr++] = (byte) c;
                if (ptr == BUF_SIZE) innerFlush();
            });
            return this;
        }

        

        public id33 print0(char[] s) {
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

        

        public id33 print0(String s) {
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

        public id33 print(int x) {
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

        public id33 print(long x) {
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

        public id33 print(double x, int precision) {
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

        public id33 println(int[] a, int from, int upTo, char separator) {
            for (int i = from; i < upTo; i++) {
                print(a[i]);
                print(separator);
            }
            print('\n');
            return this;
        }

        public id33 println(int[] a) {
            return println(a, 0, a.length, ' ');
        }

        public id33 println(long[] a, int from, int upTo, char separator) {
            for (int i = from; i < upTo; i++) {
                print(a[i]);
                print(separator);
            }
            print('\n');
            return this;
        }

        public id33 println(long[] a) {
            return println(a, 0, a.length, ' ');
        }

        public id33 println(char c) {
            return print(c).println();
        }

        public id33 println(int x) {
            return print(x).println();
        }

        public id33 println(long x) {
            return print(x).println();
        }

        public id33 println(String x) {
            return print(x).println();
        }

        public id33 println(Object x) {
            return print(x.toString()).println();
        }

        public id33 println(double x, int precision) {
            return print(x, precision).println();
        }

        public id33 println() {
            return print((byte) '\n');
        }

        public id33 printf(String format, Object... args) {
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

    private static class id18 {
        private boolean finished = false;

        private InputStream stream;
        private byte[] buf = new byte[1024];
        private int curChar;
        private int numChars;
        private id41 filter;

        public id18(InputStream stream) {
            this.stream = stream;
        }

        public double[] id4(int size) {
            double[] array = new double[size];
            for (int i = 0; i < size; i++) {
                array[i] = readDouble();
            }
            return array;
        }

        public String[] id38(int size) {
            String[] array = new String[size];
            for (int i = 0; i < size; i++) {
                array[i] = readString();
            }
            return array;
        }

        public char[] id10(int size) {
            char[] array = new char[size];
            for (int i = 0; i < size; i++) {
                array[i] = readCharacter();
            }
            return array;
        }

        public char[][] readTable(int rowCount, int columnCount) {
            char[][] table = new char[rowCount][];
            for (int i = 0; i < rowCount; i++) {
                table[i] = this.id10(columnCount);
            }
            return table;
        }

        public int[][] id15(int rowCount, int columnCount) {
            int[][] table = new int[rowCount][];
            for (int i = 0; i < rowCount; i++) {
                table[i] = id1(columnCount);
            }
            return table;
        }

        public double[][] id0(int rowCount, int columnCount) {
            double[][] table = new double[rowCount][];
            for (int i = 0; i < rowCount; i++) {
                table[i] = this.id4(columnCount);
            }
            return table;
        }

        public long[][] id2(int rowCount, int columnCount) {
            long[][] table = new long[rowCount][];
            for (int i = 0; i < rowCount; i++) {
                table[i] = id17(columnCount);
            }
            return table;
        }

        public String[][] id34(int rowCount, int columnCount) {
            String[][] table = new String[rowCount][];
            for (int i = 0; i < rowCount; i++) {
                table[i] = this.id38(columnCount);
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

        public void id25(String[]... arrays) {
            for (int i = 0; i < arrays[0].length; i++) {
                for (int j = 0; j < arrays.length; j++) {
                    arrays[j][i] = readString();
                }
            }
        }

        public long[] id17(int size) {
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

        public int id40() {
            while (isWhitespace(peek())) {
                read();
            }
            return peek();
        }

        public int readInt() {
            int c = read();
            while (id13(c)) {
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
            } while (!id13(c));
            return res * sgn;
        }

        public long readLong() {
            int c = read();
            while (id13(c)) {
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
            } while (!id13(c));
            return res * sgn;
        }

        public String readString() {
            int c = read();
            while (id13(c)) {
                c = read();
            }
            StringBuilder res = new StringBuilder();
            do {
                if (Character.isValidCodePoint(c)) {
                    res.appendCodePoint(c);
                }
                c = read();
            } while (!id13(c));
            return res.toString();
        }

        public boolean id13(int c) {
            if (filter != null) {
                return filter.id13(c);
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

        public String readLine(boolean id35) {
            if (id35) {
                return readLine();
            } else {
                return id5();
            }
        }

        public char readCharacter() {
            int c = read();
            while (id13(c)) {
                c = read();
            }
            return (char) c;
        }

        public double readDouble() {
            int c = read();
            while (id13(c)) {
                c = read();
            }
            int sgn = 1;
            if (c == '-') {
                sgn = -1;
                c = read();
            }
            double res = 0;
            while (!id13(c) && c != '.') {
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
                while (!id13(c)) {
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

        public boolean id11() {
            int value;
            while (id13(value = peek()) && value != -1) {
                read();
            }
            return value == -1;
        }

        public String next() {
            return readString();
        }

        public id41 getFilter() {
            return filter;
        }

        public void setFilter(id41 filter) {
            this.filter = filter;
        }

        public interface id41 {
            public boolean id13(int ch);
        }
    }

}
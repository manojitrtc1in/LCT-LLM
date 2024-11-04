import java.io.*;
import java.text.MessageFormat;
import java.util.*;
import java.util.function.BiFunction;
import java.util.function.Predicate;


public class D {

    final boolean ONLINE_JUDGE = java.lang.System.getProperty("ONLINE_JUDGE") != null;

    private String solveOneN_3(int n, long[] a) {
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

    private String solveOneN_2(int testCase, int n, long[] a) {
        SparseTableRMQ st = new SparseTableRMQ(a);
        BinaryIndexedTree bit = new BinaryIndexedTree(a);
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


    String solveOneN_1(int testCase, int n, long[] a) {
        SparseTableRMQ sparseTableRMQ = new SparseTableRMQ(a);

        int[] first = prevBigger(a, sparseTableRMQ);
        int[] last = nextBigger(a, sparseTableRMQ);

        long[] suffSum = suffSum(a);
        long[] prefSum = prefSum(a);
        SparseTableRMQ suffSumMax = new SparseTableRMQ(suffSum);
        SparseTableRMQ prefSumMax = new SparseTableRMQ(prefSum);

        for (int i = 0; i < n; i++) {
            

            long exclude1 = i == n - 1 ? 0 : suffSum[i + 1];
            boolean invariant1 = a[i] >= suffSumMax.get(first[i], i) - exclude1;

            long exclude2 = i == 0 ? 0 : prefSum[i - 1];
            boolean invariant2 = a[i] >= prefSumMax.get(i, last[i]) - exclude2;


            if (!invariant1 || !invariant2) {
                return "NO";
            }
        }

        return "YES";
    }

    String solveOneN_1_(int testCase, int n, long[] a) {
        
        int[] greaterLeft = greaterLeft(a), greaterRight = greaterRight(a);
        long[] p = prefSum(a), s = suffSum(a);
        int[] prefixRight = greaterRight(p), suffixLeft = greaterLeft(s);
        for (int i = 0; i < n; i++) {
            if (i != 0) {
                int index = suffixLeft[i];
                if (greaterLeft[i] < index) {
                    return ("NO");

                }
            }
            if (i != n - 1) {
                int index = prefixRight[i];
                if (index < greaterRight[i]) {
                    return ("NO");
                }
            }
        }

        return "YES";
    }

    static int[] greaterLeft(long[] a) {
        int n = a.length;
        int[] ret = new int[n];
        Arrays.fill(ret, -1);
        

        Stack<Integer> s = new Stack<>(); 

        for (int i = 0; i < n; i++) {
            while (s.size() > 0 && a[s.peek()] <= a[i]) s.pop();
            if (s.size() > 0) {
                ret[i] = s.peek();
            }
            s.add(i);
        }
        return ret;
    }

    static int[] greaterRight(long[] a) {
        int n = a.length;
        int[] ret = new int[n];
        Arrays.fill(ret, n);
        

        Stack<Integer> s = new Stack<>(); 

        for (int i = n - 1; i >= 0; i--) {
            while (s.size() > 0 && a[s.peek()] <= a[i]) s.pop();
            if (s.size() > 0) {
                ret[i] = s.peek();
            }
            s.add(i);
        }
        return ret;
    }

    long[] suffSum(long[] a) {
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

    int[] nextBigger(long[] a, SparseTableRMQ sparseTableRMQ) {
        int n = a.length;
        int[] ans = new int[n];
        for (int i = 0; i < n; i++) {
            final int i_ = i;
            ans[i] = upperBound(i, n, ind -> sparseTableRMQ.get(i_, ind) <= a[i_]);
        }

        return ans;
    }

    int[] prevBigger(long[] a, SparseTableRMQ sparseTableRMQ) {
        int n = a.length;
        int[] ans = new int[n];

        for (int i = 0; i < n; i++) {
            final int i_ = i;
            ans[i] = lowerBound(-1, i, ind -> sparseTableRMQ.get(ind, i_) <= a[i_]);
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


    static class SparseTableRMQ {
        boolean linear = false;
        

        public static final BiFunction<Long, Long, Long> MAX = Math::max;



        BiFunction<Long, Long, Long> FUNC = MAX;

        int LOG = 20;
        long[][] sparseTable;
        RMQBeta rmq;
        long[] a;

        public SparseTableRMQ(long[] a) {
            int n = a.length;
            if (linear) {
                this.a = a;
                rmq = new RMQBeta(n, (i, j) -> -Long.compare(a[i], a[j]));

            } else {

                sparseTable = new long[n][LOG];
                for (int i = 0; i < n; i++) {
                    sparseTable[i][0] = a[i];
                }
                for (int j = 1; j < LOG; j++) {
                    int jj = (1 << (j - 1));
                    for (int i = 0; i + (1 << j) - 1 < n; i++) {


                        sparseTable[i][j] = Math.max(sparseTable[i][j - 1], sparseTable[i + jj][j - 1]);
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


                return Math.max(sparseTable[l][p], sparseTable[r - (1 << p) + 1][p]);
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

        public static int highestOneBitOffset(int x) {
            return 31 - Integer.numberOfLeadingZeros(x);
        }

        public static int tailIntMask(int n) {
            if (n == 0) {
                return 0;
            }
            return -1 << (32 - n);
        }

    }

    static interface IntToLongFunction {
        long apply(int x);

    }

    static class IntegerSparseTable {
        private int[][] st;
        private IntegerBinaryFunction merger;

        public IntegerSparseTable(IntToLongFunction function, int length, IntegerBinaryFunction merger) {
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

    static interface IntegerBinaryFunction {
        int apply(int a, int b);

    }

    static interface IntegerComparator {
        public int compare(int a, int b);

    }

    static class RMQBeta {
        int n;
        IntegerComparator comp;
        static int shift = 5;
        static int blockSize = 1 << shift;
        static int andMask = blockSize - 1;
        int[] minIndices;
        int[] toLeft;
        IntegerSparseTable st;








        public RMQBeta(int n, IntegerComparator comp) {
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
            st = new IntegerSparseTable(i -> minIndices[i],
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
                    int head = Bits.highestOneBitOffset(mask);
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
                return Integer.numberOfTrailingZeros(toLeft[r] & Bits.tailIntMask(32 - tl)) | (bl << shift);
            }
            int res1 = Integer.numberOfTrailingZeros(toLeft[(bl << shift) | andMask] & Bits.tailIntMask(32 - tl)) | (bl << shift);
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

    static class BinaryIndexedTree {
        private final long[] value;

        public BinaryIndexedTree(int size) {
            value = new long[size];
        }

        public BinaryIndexedTree(long[] a) {
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

    boolean ANTI_TEST_FINDER_MODE = false;

    private void solve() {
        if (ANTI_TEST_FINDER_MODE) {
            Random r = new Random(42);
            for (int testCase = 1; testCase <= 10000; testCase++) {
                int n = r.nextInt(500) + 5;
                long[] a = new long[n];
                for (int j = 0; j < n; j++) {
                    a[j] = -20 + r.nextInt(40);
                }
                String expected = solveOneN_2(testCase, n, a);
                String actual = solveOneN_1_(testCase, n, a);




                if (!Objects.equals(expected, actual)) {
                    throw new AssertionRuntimeException(
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
                long[] a = nextLongArr(n);


                String actual = solveOneN_1_(tt, n, a);


                System.out.println(actual);
            }
        }
    }

    class AssertionRuntimeException extends RuntimeException {

        AssertionRuntimeException(int testCase,
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

    private int assertThatInt(long a) {
        assertThat(Integer.MIN_VALUE <= a && a <= Integer.MAX_VALUE);
        return (int) a;
    }

    void _______debug(String str, Object... os) {
        if (!ONLINE_JUDGE) {
            System.out.println(MessageFormat.format(str, os));
        }
    }

    void _______debug(Object o) {
        if (!ONLINE_JUDGE) {
            _______debug("{0}", String.valueOf(o));
        }
    }

    private int nextInt() {
        return System.in.readInt();
    }

    private long nextLong() {
        return System.in.readLong();
    }








    private int[] nextIntArr(int n) {
        int[] a = new int[n];
        for(int i = 0; i < n ; i++) {
            a[i] = nextInt();
        }
        return a;
    }

    private long[] nextLongArr(int n) {
        long[] a = new long[n];
        for(int i = 0; i < n ; i++) {
            a[i] = nextLong();
        }
        return a;
    }

    public static void main(String[] args) {
        new D().run();
    }

    static class System {
        private static FastInputStream in;
        private static FastPrintStream out;
    }

    private void run() {
        final boolean USE_IO = ONLINE_JUDGE;
        if (USE_IO) {
            System.in = new FastInputStream(java.lang.System.in);
            System.out = new FastPrintStream(java.lang.System.out);
            solve();
            System.out.flush();
        } else {
            final String nameIn = "input.txt";
            final String nameOut = "output.txt";
            try {
                System.in = new FastInputStream(new FileInputStream(nameIn));
                System.out = new FastPrintStream(new PrintStream(nameOut));
                solve();
                System.out.flush();
            } catch (FileNotFoundException e) {
                e.printStackTrace();
            }
        }
    }

    private static class FastPrintStream {
        private static final int BUF_SIZE = 8192;
        private final byte[] buf = new byte[BUF_SIZE];
        private final OutputStream out;
        private int ptr = 0;

        private FastPrintStream() {
            this(java.lang.System.out);
        }

        public FastPrintStream(OutputStream os) {
            this.out = os;
        }

        public FastPrintStream(String path) {
            try {
                this.out = new FileOutputStream(path);
            } catch (FileNotFoundException e) {
                throw new RuntimeException("FastWriter");
            }
        }

        public FastPrintStream print(byte b) {
            buf[ptr++] = b;
            if (ptr == BUF_SIZE) innerFlush();
            return this;
        }

        public FastPrintStream print(char c) {
            return print((byte) c);
        }

        public FastPrintStream print(char[] s) {
            for (char c : s) {
                buf[ptr++] = (byte) c;
                if (ptr == BUF_SIZE) innerFlush();
            }
            return this;
        }

        public FastPrintStream print(String s) {
            s.chars().forEach(c -> {
                buf[ptr++] = (byte) c;
                if (ptr == BUF_SIZE) innerFlush();
            });
            return this;
        }

        

        public FastPrintStream print0(char[] s) {
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

        

        public FastPrintStream print0(String s) {
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

        public FastPrintStream print(int x) {
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

        public FastPrintStream print(long x) {
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

        public FastPrintStream print(double x, int precision) {
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

        public FastPrintStream println(int[] a, int from, int upTo, char separator) {
            for (int i = from; i < upTo; i++) {
                print(a[i]);
                print(separator);
            }
            print('\n');
            return this;
        }

        public FastPrintStream println(int[] a) {
            return println(a, 0, a.length, ' ');
        }

        public FastPrintStream println(long[] a, int from, int upTo, char separator) {
            for (int i = from; i < upTo; i++) {
                print(a[i]);
                print(separator);
            }
            print('\n');
            return this;
        }

        public FastPrintStream println(long[] a) {
            return println(a, 0, a.length, ' ');
        }

        public FastPrintStream println(char c) {
            return print(c).println();
        }

        public FastPrintStream println(int x) {
            return print(x).println();
        }

        public FastPrintStream println(long x) {
            return print(x).println();
        }

        public FastPrintStream println(String x) {
            return print(x).println();
        }

        public FastPrintStream println(Object x) {
            return print(x.toString()).println();
        }

        public FastPrintStream println(double x, int precision) {
            return print(x, precision).println();
        }

        public FastPrintStream println() {
            return print((byte) '\n');
        }

        public FastPrintStream printf(String format, Object... args) {
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

    static class FastInputStream {
        private static final int BUF_SIZE = 16 * 1024;
        private final InputStream stream;
        private final byte[] buf = new byte[BUF_SIZE];
        private int ptr;
        private int len;

        public FastInputStream(InputStream stream) {
            this.stream = stream;
        }

        private void reload() {
            try {
                ptr = 0;
                len = stream.read(buf);
            } catch (IOException ex) {
                throw new UncheckedIOException(ex);
            }
        }

        private void load(int n) {
            if (ptr + n <= len) return;
            java.lang.System.arraycopy(buf, ptr, buf, 0, len - ptr);
            len -= ptr;
            ptr = 0;
            try {
                int r = stream.read(buf, len, BUF_SIZE - len);
                if (r == -1) return;
                len += r;
            } catch (IOException ex) {
                throw new UncheckedIOException(ex);
            }
        }

        private void skip() {
            while (0 <= len) {
                while (ptr < len && isTokenSeparator(buf[ptr])) ptr++;
                if (ptr < len) return;
                reload();
            }
            throw new NoSuchElementException("EOF");
        }

        public int readInt() {
            skip();
            load(12);
            int b = buf[ptr++];
            boolean negate;
            if (b == '-') {
                negate = true;
                b = buf[ptr++];
            } else negate = false;
            int x = 0;
            for (; !isTokenSeparator(b); b = buf[ptr++]) {
                if ('0' <= b && b <= '9') x = x * 10 + b - '0';
                else throw new NumberFormatException("Unexpected character '" + b + "'");
            }
            return negate ? -x : x;
        }

        public long readLong() {
            skip();
            load(20);
            int b = buf[ptr++];
            boolean negate;
            if (b == '-') {
                negate = true;
                b = buf[ptr++];
            } else negate = false;
            long x = 0;
            for (; !isTokenSeparator(b); b = buf[ptr++]) {
                x = x * 10 + b - '0';
            }
            return negate ? -x : x;
        }

        public void close() {
            try {
                stream.close();
            } catch (IOException e) {
                throw new UncheckedIOException(e);
            }
        }

        private static boolean isTokenSeparator(int b) {
            return b < 33 || 126 < b;
        }

    }





















































































































































































































































































































































































































































































































































































































































































}
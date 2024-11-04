import java.io.*;
import java.text.MessageFormat;
import java.util.*;
import java.util.function.BiFunction;
import java.util.function.Predicate;


public class D {

    final boolean id8 = java.lang.System.getProperty("id8") != null;

    private String id10(int n, long[] a) {
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

    private String id1(int testCase, int n, long[] a) {
        id16 st = new id16(a);
        id13 bit = new id13(a);
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


    String id28(int testCase, int n, long[] a) {
        id16 id6 = new id16(a);

        int[] first = id14(a, id6);
        int[] last = id7(a, id6);

        long[] id12 = id12(a);
        long[] prefSum = prefSum(a);
        id16 id19 = new id16(id12);
        id16 id21 = new id16(prefSum);

        for (int i = 0; i < n; i++) {
            

            long exclude1 = i == n - 1 ? 0 : id12[i + 1];
            boolean id11 = a[i] >= id19.get(first[i], i) - exclude1;

            long exclude2 = i == 0 ? 0 : prefSum[i - 1];
            boolean id20 = a[i] >= id21.get(i, last[i]) - exclude2;


            if (!id11 || !id20) {
                return "NO";
            }
        }

        return "YES";
    }

    String id0(int testCase, int n, long[] a) {
        
        int[] greaterLeft = greaterLeft(a), greaterRight = greaterRight(a);
        long[] p = prefSum(a), s = id12(a);
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

    long[] id12(long[] a) {
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

    int[] id7(long[] a, id16 id6) {
        int n = a.length;
        int[] ans = new int[n];
        for (int i = 0; i < n; i++) {
            final int i_ = i;
            ans[i] = upperBound(i, n, ind -> id6.get(i_, ind) <= a[i_]);
        }

        return ans;
    }

    int[] id14(long[] a, id16 id6) {
        int n = a.length;
        int[] ans = new int[n];

        for (int i = 0; i < n; i++) {
            final int i_ = i;
            ans[i] = lowerBound(-1, i, ind -> id6.get(ind, i_) <= a[i_]);
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


    static class id16 {
        boolean linear = false;
        

        public static final BiFunction<Long, Long, Long> MAX = Math::max;



        BiFunction<Long, Long, Long> FUNC = MAX;

        int LOG = 20;
        long[][] id23;
        id15 rmq;
        long[] a;

        public id16(long[] a) {
            int n = a.length;
            if (linear) {
                this.a = a;
                rmq = new id15(n, (i, j) -> -Long.compare(a[i], a[j]));

            } else {

                id23 = new long[n][LOG];
                for (int i = 0; i < n; i++) {
                    id23[i][0] = a[i];
                }
                for (int j = 1; j < LOG; j++) {
                    int jj = (1 << (j - 1));
                    for (int i = 0; i + (1 << j) - 1 < n; i++) {


                        id23[i][j] = Math.max(id23[i][j - 1], id23[i + jj][j - 1]);
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


                return Math.max(id23[l][p], id23[r - (1 << p) + 1][p]);
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

        public static int id4(int x) {
            return 31 - Integer.numberOfLeadingZeros(x);
        }

        public static int id26(int n) {
            if (n == 0) {
                return 0;
            }
            return -1 << (32 - n);
        }

    }

    static interface id25 {
        long apply(int x);

    }

    static class id2 {
        private int[][] st;
        private id5 merger;

        public id2(id25 function, int length, id5 merger) {
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

    static interface id5 {
        int apply(int a, int b);

    }

    static interface IntegerComparator {
        public int compare(int a, int b);

    }

    static class id15 {
        int n;
        IntegerComparator comp;
        static int shift = 5;
        static int blockSize = 1 << shift;
        static int andMask = blockSize - 1;
        int[] minIndices;
        int[] toLeft;
        id2 st;








        public id15(int n, IntegerComparator comp) {
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
            st = new id2(i -> minIndices[i],
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
                    int head = Bits.id4(mask);
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
                return Integer.numberOfTrailingZeros(toLeft[r] & Bits.id26(32 - tl)) | (bl << shift);
            }
            int res1 = Integer.numberOfTrailingZeros(toLeft[(bl << shift) | andMask] & Bits.id26(32 - tl)) | (bl << shift);
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

    static class id13 {
        private final long[] value;

        public id13(int size) {
            value = new long[size];
        }

        public id13(long[] a) {
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

    boolean id17 = false;

    private void solve() {
        if (id17) {
            Random r = new Random(42);
            for (int testCase = 1; testCase <= 10000; testCase++) {
                int n = r.nextInt(500) + 5;
                long[] a = new long[n];
                for (int j = 0; j < n; j++) {
                    a[j] = -20 + r.nextInt(40);
                }
                String expected = id1(testCase, n, a);
                String actual = id0(testCase, n, a);




                if (!Objects.equals(expected, actual)) {
                    throw new id3(
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
                long[] a = id29(n);


                String actual = id0(tt, n, a);


                System.out.println(actual);
            }
        }
    }

    class id3 extends RuntimeException {

        id3(int testCase,
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

    private int id22(long a) {
        assertThat(Integer.MIN_VALUE <= a && a <= Integer.MAX_VALUE);
        return (int) a;
    }

    void _______debug(String str, Object... os) {
        if (!id8) {
            System.out.println(MessageFormat.format(str, os));
        }
    }

    void _______debug(Object o) {
        if (!id8) {
            _______debug("{0}", String.valueOf(o));
        }
    }

    private int nextInt() {
        return System.in.readInt();
    }

    private long nextLong() {
        return System.in.readLong();
    }








    private int[] id27(int n) {
        int[] a = new int[n];
        for(int i = 0; i < n ; i++) {
            a[i] = nextInt();
        }
        return a;
    }

    private long[] id29(int n) {
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
        private static id9 in;
        private static id24 out;
    }

    private void run() {
        final boolean USE_IO = id8;
        if (USE_IO) {
            System.in = new id9(java.lang.System.in);
            System.out = new id24(java.lang.System.out);
            solve();
            System.out.flush();
        } else {
            final String nameIn = "input.txt";
            final String nameOut = "output.txt";
            try {
                System.in = new id9(new FileInputStream(nameIn));
                System.out = new id24(new PrintStream(nameOut));
                solve();
                System.out.flush();
            } catch (FileNotFoundException e) {
                e.printStackTrace();
            }
        }
    }

    private static class id24 {
        private static final int BUF_SIZE = 8192;
        private final byte[] buf = new byte[BUF_SIZE];
        private final OutputStream out;
        private int ptr = 0;

        private id24() {
            this(java.lang.System.out);
        }

        public id24(OutputStream os) {
            this.out = os;
        }

        public id24(String path) {
            try {
                this.out = new FileOutputStream(path);
            } catch (FileNotFoundException e) {
                throw new RuntimeException("FastWriter");
            }
        }

        public id24 print(byte b) {
            buf[ptr++] = b;
            if (ptr == BUF_SIZE) innerFlush();
            return this;
        }

        public id24 print(char c) {
            return print((byte) c);
        }

        public id24 print(char[] s) {
            for (char c : s) {
                buf[ptr++] = (byte) c;
                if (ptr == BUF_SIZE) innerFlush();
            }
            return this;
        }

        public id24 print(String s) {
            s.chars().forEach(c -> {
                buf[ptr++] = (byte) c;
                if (ptr == BUF_SIZE) innerFlush();
            });
            return this;
        }

        

        public id24 print0(char[] s) {
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

        

        public id24 print0(String s) {
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

        public id24 print(int x) {
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

        public id24 print(long x) {
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

        public id24 print(double x, int precision) {
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

        public id24 println(int[] a, int from, int upTo, char separator) {
            for (int i = from; i < upTo; i++) {
                print(a[i]);
                print(separator);
            }
            print('\n');
            return this;
        }

        public id24 println(int[] a) {
            return println(a, 0, a.length, ' ');
        }

        public id24 println(long[] a, int from, int upTo, char separator) {
            for (int i = from; i < upTo; i++) {
                print(a[i]);
                print(separator);
            }
            print('\n');
            return this;
        }

        public id24 println(long[] a) {
            return println(a, 0, a.length, ' ');
        }

        public id24 println(char c) {
            return print(c).println();
        }

        public id24 println(int x) {
            return print(x).println();
        }

        public id24 println(long x) {
            return print(x).println();
        }

        public id24 println(String x) {
            return print(x).println();
        }

        public id24 println(Object x) {
            return print(x.toString()).println();
        }

        public id24 println(double x, int precision) {
            return print(x, precision).println();
        }

        public id24 println() {
            return print((byte) '\n');
        }

        public id24 printf(String format, Object... args) {
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

    static class id9 {
        private static final int BUF_SIZE = 16 * 1024;
        private final InputStream stream;
        private final byte[] buf = new byte[BUF_SIZE];
        private int ptr;
        private int len;

        public id9(InputStream stream) {
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
                while (ptr < len && id18(buf[ptr])) ptr++;
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
            for (; !id18(b); b = buf[ptr++]) {
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
            for (; !id18(b); b = buf[ptr++]) {
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

        private static boolean id18(int b) {
            return b < 33 || 126 < b;
        }

    }





















































































































































































































































































































































































































































































































































































































































































}
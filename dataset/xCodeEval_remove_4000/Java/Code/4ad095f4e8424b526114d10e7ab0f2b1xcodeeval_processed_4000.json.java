import java.io.*;
import java.text.MessageFormat;
import java.util.*;
import java.util.function.Predicate;


public class id20 {

    final boolean id14 = java.lang.System.getProperty("id14") != null;
    long inf = Long.MAX_VALUE;

    private long id10(int testCase, int n, int k, long[] a, Object[] store) {
        long ans = Long.MAX_VALUE;
        for (int mask = 0; mask < (1 << n); mask++) {
            if (Integer.bitCount(mask) == k) {
                Set<Integer> ind = new HashSet<>();
                long localAns = 0;
                int id17 = 0;
                for (int i = 0; i < n; i++) {
                    if ((mask & (1 << i)) != 0) {
                        id17++;
                        ind.add(i);
                    } else {
                        localAns += a[i] + id17;
                    }
                }
                if (ans > localAns) {
                    ans = localAns;


                    store[0] = ind;
                }
            }
        }
        return ans;
    }

    private long id23(int testCase, int n, int k, long[] a, Object[] store) {


        boolean[] id17 = new boolean[n];
        long ans = 0;


        for (int j = 0; j < k; j++) {
            long[] greedy = new long[n];
            long id25 = Long.MAX_VALUE;
            int toRemove = -1;
            for (int i = 0; i < n; i++) {
                long localAns = 0;
                

                int delta = 0;
                for (int u = 0; u < n; u++) {
                    if (u == i || id17[u]) {
                        delta++;
                    } else {
                        localAns += a[u] + delta;
                    }
                }
                if (id25 > localAns) {
                    id25 = localAns;
                    toRemove = i;
                }
                greedy[i] = localAns;
            }




            ans = id25;
            id17[toRemove] = true;
        }



        return ans;
    }

    private long solveOne(int testCase, int n, int k, long[] a, Object[] store) {

        long sum = 0;
        for (long i : a) sum += i;



        

        boolean[] used = new boolean[n];
        id22 segTree = new id22(0, n);
        id18 bit = new id18(n);
        for (int i = 0; i < n; i++) {
            segTree.increment(i, i + 1, sum);
            segTree.increment(i, i + 1, -a[i]);
            segTree.increment(i, i + 1, n - (i + 1));
            bit.add(i, 1);
        }
        

        

        


        long oldSum = sum;

        while (k-- > 0) {


            int i = segTree.id9();

            

            if (used[i]) throw new RuntimeException();
            used[i] = true;

            long newSum = segTree.id33(i, i + 1);

            if (newSum >= oldSum) {
                break;
            }
            

            segTree.increment(0, n, newSum - oldSum);
            segTree.increment(0, i, -1);
            segTree.increment(i + 1, n, -1);
            segTree.update(i, inf);


            oldSum = newSum;
        }


        return oldSum;
    }

    static class id18 {
        private final long[] value;

        public id18(int size) {
            value = new long[size];
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


    static class id22 {

        final int l;
        final int r;
        id22 left;
        id22 right;

        long min;
        int ind;
        long lazyIncrement;

        static id22 id11(long[] array) {
            return null;
        }

        static id22 buildSparse(int l, int r) {
            return null;
        }

        id22(int l, int r) {
            this.l = l;
            this.r = r;
            if(isLeaf()) {
                this.ind = l;
            }
        }

        id22 left() {
            if (left == null) {
                left = new id22(l, mid());
            }
            return left;
        }

        id22 right() {
            if (right == null) {
                right = new id22(mid(), r);
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
            left().lazyIncrement += lazyIncrement;
            left().min += lazyIncrement;
            right().lazyIncrement += lazyIncrement;
            right().min += lazyIncrement;
            lazyIncrement = 0;
        }

        private void pushUp() {
            if (left().min <= right().min) {
                ind = left().ind;
                min = left().min;
            } else {
                ind = right().ind;
                min = right().min;
            }
        }

        public void update(int at, long value) {
            increment(at, at + 1, -id33(at, at + 1));

            increment(at, at + 1, value);
        }

        public void increment(int l, int r, long delta) {
            if (noIntersection(l, r)) return;
            if (equal(l, r)) {
                this.min += delta;
                this.lazyIncrement += delta;
                return;
            }
            pushDown();
            final int m = mid();
            left().increment(l, Math.min(r, m), delta);
            right().increment(Math.max(m, l), r, delta);
            pushUp();
        }

        public long id33(int l, int r) {
            if (noIntersection(l, r)) return Long.MAX_VALUE;
            if (equal(l, r)) {
                return this.min;
            }
            pushDown();
            final int m = mid();
            return Long.min(
                    left().id33(l, Math.min(r, m)),
                    right().id33(Math.max(m, l), r)
            );
        }

        public int id9() {
            if (false) {
                long localMin = this.id33(l, r);
                int i = lowerBound(0, r, midVal -> localMin != id33(midVal, r)) - 1;
                if (localMin != id33(i, i + 1)) {
                    throw new RuntimeException();
                }
                return i;
            } else {
                return this.ind;
            }
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

        @Override
        public String toString() {
            long[] val = new long[r - l];
            for (int i = l; i < r; i++) {
                val[i] = this.id33(i, i + 1);
            }
            return Arrays.toString(val);
        }
    }

    boolean id3 = false;
    Random random = new Random(42);

    private void solve() {
        if (id3) {
            int t = 1_000;
            for (int testCase = 0; testCase < t; testCase++) {
                java.lang.System.out.println("Checking the " + testCase + " test!");
                int n = 5 + random.nextInt(15);
                int k = 1 + random.nextInt(n);
                long[] a = new long[n];
                for (int i = 0; i < n; i++) a[i] = 1 + random.nextInt(10);
                Object[] o = new Object[1];
                Object[] o2 = new Object[1];


                long expected = id23(testCase, n, k, a, o);
                long actual = solveOne(testCase, n, k, a, o2);






                if (expected != actual) {
                    throw new id6(this.getClass().getName(), testCase,
                            expected,
                            actual,
                            n, k, a, o, o2);
                }
            }

        } else {
            int t = nextInt();
            for (int testCase = 0; testCase < t; testCase++) {
                int n = nextInt();
                int k = nextInt();
                long[] a = id32(n);
                Object[] o2 = new Object[1];
                long actual = solveOne(testCase, n, k, a, o2);
                System.out.println(actual);
                

            }
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

    private int id21(long a) {
        assertThat(Integer.MIN_VALUE <= a && a <= Integer.MAX_VALUE);
        return (int) a;
    }

    void _______debug(String str, Object... os) {
        if (!id14) {
            System.out.println(MessageFormat.format(str, os));
        }
    }

    void _______debug(Object o) {
        if (!id14) {
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

    private int[] id29(int n) {
        return System.in.id1(n);
    }

    private long[] id32(int n) {
        return System.in.id15(n);
    }

    public static void main(String[] args) {
        new id20().run();
    }

    static class System {
        private static id16 in;
        private static id24 out;
    }

    private void run() {
        final boolean USE_IO = id14;
        if (USE_IO) {
            System.in = new id16(java.lang.System.in);
            System.out = new id24(java.lang.System.out);
            solve();
            System.out.flush();
        } else {
            final String nameIn = "input.txt";
            final String nameOut = "output.txt";
            try {
                System.in = new id16(new FileInputStream(nameIn));
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

    private static class id16 {
        private boolean finished = false;

        private InputStream stream;
        private byte[] buf = new byte[1024];
        private int curChar;
        private int numChars;
        private id31 filter;

        public id16(InputStream stream) {
            this.stream = stream;
        }

        public double[] id4(int size) {
            double[] array = new double[size];
            for (int i = 0; i < size; i++) {
                array[i] = readDouble();
            }
            return array;
        }

        public String[] id28(int size) {
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

        public int[][] id13(int rowCount, int columnCount) {
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
                table[i] = id15(columnCount);
            }
            return table;
        }

        public String[][] id26(int rowCount, int columnCount) {
            String[][] table = new String[rowCount][];
            for (int i = 0; i < rowCount; i++) {
                table[i] = this.id28(columnCount);
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

        public long[] id15(int size) {
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

        public int id30() {
            while (isWhitespace(peek())) {
                read();
            }
            return peek();
        }

        public int readInt() {
            int c = read();
            while (id12(c)) {
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
            } while (!id12(c));
            return res * sgn;
        }

        public long readLong() {
            int c = read();
            while (id12(c)) {
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
            } while (!id12(c));
            return res * sgn;
        }

        public String readString() {
            int c = read();
            while (id12(c)) {
                c = read();
            }
            StringBuilder res = new StringBuilder();
            do {
                if (Character.isValidCodePoint(c)) {
                    res.appendCodePoint(c);
                }
                c = read();
            } while (!id12(c));
            return res.toString();
        }

        public boolean id12(int c) {
            if (filter != null) {
                return filter.id12(c);
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

        public String readLine(boolean id27) {
            if (id27) {
                return readLine();
            } else {
                return id5();
            }
        }

        public char readCharacter() {
            int c = read();
            while (id12(c)) {
                c = read();
            }
            return (char) c;
        }

        public double readDouble() {
            int c = read();
            while (id12(c)) {
                c = read();
            }
            int sgn = 1;
            if (c == '-') {
                sgn = -1;
                c = read();
            }
            double res = 0;
            while (!id12(c) && c != '.') {
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
                while (!id12(c)) {
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
            while (id12(value = peek()) && value != -1) {
                read();
            }
            return value == -1;
        }

        public String next() {
            return readString();
        }

        public id31 getFilter() {
            return filter;
        }

        public void setFilter(id31 filter) {
            this.filter = filter;
        }

        public interface id31 {
            public boolean id12(int ch);
        }
    }

}
import java.io.*;
import java.text.*;
import java.util.*;


public class CF1699C {

    final boolean ONLINE_JUDGE = java.lang.System.getProperty("ONLINE_JUDGE") != null;
    boolean ANTI_TEST_FINDER = false;
    long mod = (long) 1e9 + 7;



    private long solveOneNaive(int testCase, int n, long[] a, ModelWrapper modelWrapper) {
        Set<Long> uniq = new HashSet<>();
        for (long i : a) uniq.add(i);
        assertThat(n == uniq.size() && a.length == n);

        


        

        long[] cur = Arrays.copyOf(a, a.length);
        int cnt = 0;
        int derangements = 0;
        while (true) {

            boolean allSegmentsAreOK = true;
            for (int i = 0; i < n; i++) {
                for (int j = i; j < n; j++) {
                    TreeSet<Long> mex1 = new TreeSet<>();
                    TreeSet<Long> mex2 = new TreeSet<>();
                    for (long k : a) {
                        mex1.add(k);
                        mex2.add(k);
                    }
                    mex1.add((long) n);
                    mex2.add((long) n);

                    for (int k = i; k <= j; k++) {
                        mex1.remove(cur[k]);
                        mex2.remove(a[k]);
                    }
                    allSegmentsAreOK &= Objects.equals(mex1.first(), mex2.first());
                }
            }
            if (allSegmentsAreOK) {
                cnt++;
                modelWrapper.model.add(Arrays.copyOf(cur, n));
            }

            Permutation.next(cur);
            if (Permutation.equals(cur, a)) {
                break;
            }
        }

        return cnt;
    }

    class ModelWrapper {
        List<long[]> model = new ArrayList<>();

        @Override
        public String toString() {

            StringBuilder sb = new StringBuilder();
            sb.append("size = " + model.size() + "\n");
            sb.append("{\n");
            for (long[] g : model) {
                sb.append(Arrays.toString(g) + "\n");
            }
            sb.append("\n}");
            return sb.toString();
        }
    }

    static class Permutation {

        

        public static void next(long[] nums) {
            next(nums, 0, nums.length);
        }

        private static boolean next(long[] nums, int begin, int end) {
            

            

            int p = end - 2;
            while (p > -1 && nums[p] >= nums[p + 1]) --p;

            

            

            if (p == -1) {
                reverse(nums, begin, end);
                return false;
            }

            

            

            int c = end - 1;
            while (c > 0 && nums[c] <= nums[p]) --c;

            

            swap(nums, p, c);
            

            reverse(nums, p + 1, end);
            return true;
        }

        private static void swap(long[] nums, int i, int j) {
            long tmp = nums[i];
            nums[i] = nums[j];
            nums[j] = tmp;
        }

        private static void reverse(long[] nums, int begin, int end) {
            end--;
            while (begin < end) {
                swap(nums, begin++, end--);
            }
        }

        private static int factorial(int n) {
            int ans = 1;
            for (int i = 0; i < n; i++) {
                ans *= (i + 1);
            }
            return ans;
        }

        private static boolean hasEquals(long[] a, long[] b) {
            boolean eq = false;
            for (int i = 0; i < a.length; i++) {
                eq |= a[i] == b[i];
            }
            return eq;
        }

        private static boolean equals(long[] a, long[] b) {
            boolean eq = true;
            for (int i = 0; i < a.length; i++) {
                eq &= a[i] == b[i];
            }
            return eq;
        }


    }

    private long solveOne(int testCase, int n, long[] a_) {

        int[] a = new int[n + 2];
        for (int i = 1; i <= n; i++) {
            a[i] = (int) a_[i - 1];
        }

        int[] maxMex = maxMex(n, a);


        List<Pair> list = new ArrayList<>();
        for (int i = 1; i <= n; i++) {
            list.add(new Pair(a[i], maxMex[i]));
        }

        final Comparator<Pair> comp = new Comparator<>() {
            @Override
            public int compare(Pair o1, Pair o2) {
                int comp = Integer.compare(o1.maxMex, o2.maxMex);
                if (comp == 0) {
                    return Integer.compare(o1.value, o2.value);
                }
                return comp;
            }
        };
        list.sort(comp);

        PriorityQueue<Pair> group = new PriorityQueue<>(new Comparator<>() {
            @Override
            public int compare(Pair o1, Pair o2) {




                    return Integer.compare(o1.value, o2.value);




            }
        });

        long ans = 1;

        for (Pair p : list) {
            if (p.maxMex < p.value) {
                group.add(p);
                while ( p.maxMex >= group.peek().value) {
                    group.remove();
                }
                ans *= group.size();
                ans %= mod;
            }
        }

        return ans;
    }

    class Pair {
        int value;
        int maxMex;

        public Pair(int value, int maxMex) {
            this.value = value;
            this.maxMex = maxMex;
        }

        @Override
        public String toString() {
            return "Pair{" +
                    "value=" + value +
                    ", maxMex=" + maxMex +
                    '}';
        }
    }

    int[] maxMex(int n, int[] a) {
        int[] maxMex = new int[n + 2];
        int[] minPref = new int[n + 2];
        minPref[0] = n;
        for (int i = 1; i <= n; i++) {
            minPref[i] = Math.min(minPref[i - 1], a[i]);
        }
        int[] maxPref = new int[n + 2];
        maxPref[n + 1] = n;
        for (int i = n; i >= 1; i--) {
            maxPref[i] = Math.min(maxPref[i + 1], a[i]);
        }
        for (int i = 1; i <= n; i++) {
            maxMex[i] = Math.max(minPref[i - 1], maxPref[i + 1]);
        }
        return maxMex;
    }

    static class BinaryIndexedTree {
        private final long[] value;

        public BinaryIndexedTree(int size) {
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


    public long posModule(long x) {
        return (x % mod + mod) % mod;
    }

    private void solve() {
        if (false) {
            ModelWrapper modelWrapper = new ModelWrapper();























































            int n = 8;


            long[] a = {4, 6, 0, 2, 3, 1, 7, 5};

            long expected = solveOneNaive(-1, n, a, modelWrapper);
            System.out.println(expected);
            System.out.println(modelWrapper.toString());
            return;
        }

        if (ANTI_TEST_FINDER) {
            Random random = new Random(42);
            int testCases = 10000;
            for (int testCase = 0; testCase < testCases; testCase++) {
                int n = 2 + random.nextInt(6);
                long[] a = new long[n];
                for (int i = 0; i < n; i++) {
                    a[i] = i;
                }
                for (int i = 0; i < n; i++) {
                    int j = random.nextInt(n);
                    long temp = a[i];
                    a[i] = a[j];
                    a[j] = temp;
                }

                ModelWrapper modelWrapper = new ModelWrapper();
                long expected = solveOneNaive(testCase, n, a, modelWrapper);
                long actual = solveOne(testCase, n, a);
                if (expected != actual) {
                    throw new AssertionRuntimeException(
                            CF1699C.class.getSimpleName(),
                            testCase,
                            expected,
                            actual,
                            n,
                            a,
                            modelWrapper.toString()
                    );
                }

            }
        } else {













            int t = nextInt();
            for (int testCase = 0; testCase < t; testCase++) {
                int n = nextInt();
                long[] a = nextLongArr(n);

                long actual = solveOne(testCase, n, a);
                System.out.println(actual);
            }
        }
    }

    class AssertionRuntimeException extends RuntimeException {

        AssertionRuntimeException(String testName,
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

    private String nextString() {
        return System.in.readString();
    }

    private int[] nextIntArr(int n) {
        return System.in.readIntArray(n);
    }

    private long[] nextLongArr(int n) {
        return System.in.readLongArray(n);
    }

    public static void main(String[] args) {
        new CF1699C().run();
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

    private static class FastInputStream {
        private boolean finished = false;

        private InputStream stream;
        private byte[] buf = new byte[1024];
        private int curChar;
        private int numChars;
        private SpaceCharFilter filter;

        public FastInputStream(InputStream stream) {
            this.stream = stream;
        }

        public double[] readDoubleArray(int size) {
            double[] array = new double[size];
            for (int i = 0; i < size; i++) {
                array[i] = readDouble();
            }
            return array;
        }

        public String[] readStringArray(int size) {
            String[] array = new String[size];
            for (int i = 0; i < size; i++) {
                array[i] = readString();
            }
            return array;
        }

        public char[] readCharArray(int size) {
            char[] array = new char[size];
            for (int i = 0; i < size; i++) {
                array[i] = readCharacter();
            }
            return array;
        }

        public char[][] readTable(int rowCount, int columnCount) {
            char[][] table = new char[rowCount][];
            for (int i = 0; i < rowCount; i++) {
                table[i] = this.readCharArray(columnCount);
            }
            return table;
        }

        public int[][] readIntTable(int rowCount, int columnCount) {
            int[][] table = new int[rowCount][];
            for (int i = 0; i < rowCount; i++) {
                table[i] = readIntArray(columnCount);
            }
            return table;
        }

        public double[][] readDoubleTable(int rowCount, int columnCount) {
            double[][] table = new double[rowCount][];
            for (int i = 0; i < rowCount; i++) {
                table[i] = this.readDoubleArray(columnCount);
            }
            return table;
        }

        public long[][] readLongTable(int rowCount, int columnCount) {
            long[][] table = new long[rowCount][];
            for (int i = 0; i < rowCount; i++) {
                table[i] = readLongArray(columnCount);
            }
            return table;
        }

        public String[][] readStringTable(int rowCount, int columnCount) {
            String[][] table = new String[rowCount][];
            for (int i = 0; i < rowCount; i++) {
                table[i] = this.readStringArray(columnCount);
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

        public void readStringArrays(String[]... arrays) {
            for (int i = 0; i < arrays[0].length; i++) {
                for (int j = 0; j < arrays.length; j++) {
                    arrays[j][i] = readString();
                }
            }
        }

        public long[] readLongArray(int size) {
            long[] array = new long[size];
            for (int i = 0; i < size; i++) {
                array[i] = readLong();
            }
            return array;
        }

        public int[] readIntArray(int size) {
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

        public int peekNonWhitespace() {
            while (isWhitespace(peek())) {
                read();
            }
            return peek();
        }

        public int readInt() {
            int c = read();
            while (isSpaceChar(c)) {
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
            } while (!isSpaceChar(c));
            return res * sgn;
        }

        public long readLong() {
            int c = read();
            while (isSpaceChar(c)) {
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
            } while (!isSpaceChar(c));
            return res * sgn;
        }

        public String readString() {
            int c = read();
            while (isSpaceChar(c)) {
                c = read();
            }
            StringBuilder res = new StringBuilder();
            do {
                if (Character.isValidCodePoint(c)) {
                    res.appendCodePoint(c);
                }
                c = read();
            } while (!isSpaceChar(c));
            return res.toString();
        }

        public boolean isSpaceChar(int c) {
            if (filter != null) {
                return filter.isSpaceChar(c);
            }
            return isWhitespace(c);
        }

        public static boolean isWhitespace(int c) {
            return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
        }

        private String readLine0() {
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
            String s = readLine0();
            while (s.trim().length() == 0) {
                s = readLine0();
            }
            return s;
        }

        public String readLine(boolean ignoreEmptyLines) {
            if (ignoreEmptyLines) {
                return readLine();
            } else {
                return readLine0();
            }
        }

        public char readCharacter() {
            int c = read();
            while (isSpaceChar(c)) {
                c = read();
            }
            return (char) c;
        }

        public double readDouble() {
            int c = read();
            while (isSpaceChar(c)) {
                c = read();
            }
            int sgn = 1;
            if (c == '-') {
                sgn = -1;
                c = read();
            }
            double res = 0;
            while (!isSpaceChar(c) && c != '.') {
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
                while (!isSpaceChar(c)) {
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

        public boolean isExhausted() {
            int value;
            while (isSpaceChar(value = peek()) && value != -1) {
                read();
            }
            return value == -1;
        }

        public String next() {
            return readString();
        }

        public SpaceCharFilter getFilter() {
            return filter;
        }

        public void setFilter(SpaceCharFilter filter) {
            this.filter = filter;
        }

        public interface SpaceCharFilter {
            public boolean isSpaceChar(int ch);
        }
    }

}
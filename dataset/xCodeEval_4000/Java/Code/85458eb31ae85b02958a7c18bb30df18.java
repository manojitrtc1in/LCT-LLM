import java.io.*;
import java.text.MessageFormat;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.util.Random;
import java.util.function.Predicate;


public class CF1661D {
    


    private long solveOneNaive(int n, int k, long[] b) {
        long ans = Long.MAX_VALUE;
        long mask = 1;
        for (int i = 0; i < n; i++) mask *= k;
        

        

        

        

        

        for (long set = 0; set < mask; set++) {
            long localAns = 0;
            long set_ = set;

            AddingArithmeticProgressionSegTree tree = new AddingArithmeticProgressionSegTree(n);
            int[] bits = new int[n];
            for (int i = 0; i < n; i++) {
                int bit = assertThatInt(set_ % k);
                bits[i] = bit;
                set_ /= k;
                Range range = new Range(bit, k, i, n);

                int f = range.f;
                int s = range.s;
                int fixed_bit = range.fixed_bit;

                if (tree.at(i) < b[i]) {
                    long localStep = divRoundUp(b[i] - tree.at(i), fixed_bit + 1);
                    tree.add(f, s, localStep);
                    localAns += localStep;
                }

            }
            if (ans > localAns) {
                ans = localAns;
                System.out.println("LocalAns " + localAns + " bits = " + Arrays.toString(bits));
            }
            

        }

        return ans;
    }

    private long solveOneNaive2(int n, int k, long[] b) {
        long ans = Long.MAX_VALUE;




        

        

        

        

        

        for (int set = 0; set < (1 << n); set++) {
            long localAns = 0;
            int set_ = set;

            AddingArithmeticProgressionSegTree tree = new AddingArithmeticProgressionSegTree(n);

            for (int l = 0, r = n - 1, cnt = 0; cnt < n; cnt++) {

                int i;
                if (set_ % 2 == 0 ) {
                    i = l;
                } else {
                    i = r;
                }
                set_ /= 2;



                int canAddInOneSet = Math.min(i + 1, k);
                long ai = tree.at(i);

                long need = b[i] - ai;
                if(need <= 0) {
                    if(i == r) r--;
                    else  l++;
                    continue;
                }
                int upTo = Math.max(k - 1, i);
                int from = upTo + 1 - k;
                long localSteps = divRoundUp(need, canAddInOneSet);
                if (i == r) {
                    

                    


                    tree.add(from, upTo, localSteps);


                    localAns += localSteps;



                    r--;
                } else  {
                    

                    


                    int shift = canAddInOneSet - lowerBound(0, canAddInOneSet,
                            stepSize -> need <= localSteps * stepSize);

                    int rightToContribute = Math.max(r, k - 1);
                    int left = rightToContribute + 1 - k;
                    from = Math.min(from + shift, left);
                    upTo = Math.min(upTo + shift, rightToContribute);

                    tree.add(from, upTo, localSteps);





                    localAns += localSteps;
                    l++;
                }
            }
            ans = Math.min(ans, localAns);
        }

        return ans;
    }

    class Range {
        int f;
        int s;
        int fixed_bit;

        Range(int bit, int k, int i, int n) {
            final int l = i - bit;
            final int r = l + k - 1;
            if (l < 0) {
                f = 0;
                s = k - 1;
                fixed_bit = i;
            } else if (n - 1 < r) {
                f = n - k;
                s = n - 1;
                fixed_bit = bit + (r - (n - 1));
                assertThat(fixed_bit < k);
            } else {
                f = l;
                s = r;
                fixed_bit = bit;
            }
        }
    }

    private long solveOne2(int n, int k, long[] b) {
        long ans = 0;
        AddingArithmeticProgressionSegTree tree = new AddingArithmeticProgressionSegTree(n);

        for (int i = n - 1; i >= k; i--) {
            long ai = tree.at(i);
            if (ai < b[i]) {
                long localAns = divRoundUp(b[i] - ai, k);
                

                

                

                tree.add(i + 1 - k , i, localAns);
                ans += localAns;
            }
        }
        long max = 0;
        for(int i = k - 1; i >= 0; i--){
            long ai = tree.at(i);
            if (ai < b[i]) {
                long localAns = divRoundUp(b[i] - ai, i + 1);
                

                

                max = Math.max(max, localAns);
            }
        }

        return ans + max;

    }

    private long solveOne(int n, int k, long[] b) {
        long ans = 0;
        AddingArithmeticProgressionSegTree tree = new AddingArithmeticProgressionSegTree(n);

        for (int l = 0, r = n - 1; l <= r; ) {
            long al = -1;
            long ar = -1;
            while (l < n && (al = tree.at(l)) >= b[l]) l++;
            while (0 <= r && (ar = tree.at(r)) >= b[r]) r--;

            if (l > r) {
                break;
            }

            int canAddInOneSetL = Math.min(l + 1, k);
            int canAddInOneSetR = Math.min(r + 1, k);
            long stepsNeedL = divRoundUp(b[l] - al, canAddInOneSetL);
            long stepsNeedR = divRoundUp(b[r] - ar, canAddInOneSetR);
            int i;

            if (stepsNeedL < stepsNeedR) {
                i = l;
            } else {
                i = r;
            }



            int canAddInOneSet = Math.min(i + 1, k);
            long ai = tree.at(i);

            long need = b[i] - ai;
            int upTo = Math.max(k - 1, i);
            int from = upTo + 1 - k;
            long localSteps = divRoundUp(need, canAddInOneSet);
            if (i == r) {
                

                


                tree.add(from, upTo, localSteps);


                ans += localSteps;



                r--;
            } else  {
                

                


                int shift = canAddInOneSet - lowerBound(0, canAddInOneSet,
                        stepSize -> need <= localSteps * stepSize);

                int rightToContribute = Math.max(r, k - 1);
                int left = rightToContribute + 1 - k;
                from = Math.min(from + shift, left);
                upTo = Math.min(upTo + shift, rightToContribute);

                tree.add(from, upTo, localSteps);





                ans += localSteps;
                l++;
            }
        }

        return ans;
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

    long divRoundUp(long a, long b) {
        return (a + b - 1) / b;
    }

    private void assertThat(boolean b) {
        if (!b) throw new RuntimeException();
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
            System.out.println(o != null ? o.toString() : "null");
        }
    }


    class AddingArithmeticProgressionSegTree {

        class Segment {
            public Segment(int l, int r) {
                this.l = l;
                this.r = r;
            }

            final int l;
            final int r;

            long startVal;
            long difference;

            @Override
            public String toString() {
                return "Segment{" +
                        "l=" + l +
                        ", r=" + r +
                        ", startVal=" + startVal +
                        ", difference=" + difference +
                        '}';
            }
        }

        int n;
        Segment[] tree;

        AddingArithmeticProgressionSegTree(int n) {
            tree = new Segment[4 * n];
            this.n = n;
            init(0, 0, n - 1);
        }

        void init(int i, int l, int r) {
            tree[i] = new Segment(l, r);
            if (l == r) {
                return;
            }
            init(2 * i + 1, l, (l + r) / 2);
            init(2 * i + 2, (l + r) / 2 + 1, r);
        }


        long at(int i) {
            assertThat(0 <= i && i < n);
            long ans = 0;
            int j = 0;
            while (j < tree.length ) {
                Segment curSeg = tree[j];
                if (curSeg == null) {
                    break;
                }
                ans += curSeg.startVal + (i - curSeg.l) * curSeg.difference;
                assertThat(ans >= 0);
                int m = (curSeg.l + curSeg.r) / 2;
                j = 2 * j + (i <= m ? 1 : 2);
                

            }
            return ans;
        }

        void add(int from, int upTo, long delta) {
            add(from, upTo, delta, delta, 0);
        }

        private void add(int from, int upTo, long start, long delta, int i) {

            final int l = tree[i].l;
            final int r = tree[i].r;

            if (from > upTo || upTo < l || r < from) {
                return;
            }

            if (from == l && upTo == r) {
                Segment seg = tree[i];
                seg.difference += delta;
                seg.startVal += start;
                return;
            }
            int tm = (l + r) / 2;
            

            int leftLen = Math.max(0, Math.min(tm, upTo) + 1 - from);
            add(from, Math.min(tm, upTo), start, delta, 2 * i + 1);
            add(Math.max(from, tm + 1), upTo, start + leftLen * delta, delta, 2 * i + 2);
        }

        @Override
        public String toString() {
            StringBuilder sb = new StringBuilder();
            for (int i = 0; i < n; i++) {
                sb.append(at(i)).append(' ');
            }
            return sb.toString();
        }
    }


    private void solve() {
        if (!CORRECTNESS_TEST) {
            int t = !ONLINE_JUDGE ? nextInt() : 1;
            for (int tt = 0; tt < t; tt++) {
                int n = nextInt();
                int k = nextInt();
                long[] b = nextLongArr(n);


                long actualAns = solveOne2(n, k, b);
                System.out.println(actualAns);
            }
        } else {

            Random r = new Random(42);
            for (int test = 1; test <= 10000; test++) {
                int n = 6;
                int k = 4;

                long[] b = new long[n];
                for (int i = 0; i < n; i++) b[i] = r.nextInt(2000);

                long actualAns = solveOne(n, k, b);


                long expectedAns = solveOneNaive2(n, k, b);
                if (actualAns != expectedAns) {
                    _______debug("RESULT: WA {0} {1} {2} -> {3}, but was {4}", n, k, Arrays.toString(b), expectedAns, actualAns);
                    

                } else {
                    _______debug("RESULT: OK {0} {1} {2} -> {3}", n, k, Arrays.toString(b), expectedAns);
                }

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
        new CF1661D().run();
    }

    static class System {
        private static FastInputStream in;
        private static FastPrintStream out;
    }

    final boolean CORRECTNESS_TEST = false;
    final boolean ONLINE_JUDGE = java.lang.System.getProperty("ONLINE_JUDGE") != null;

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
            } catch (FileNotFoundException e) {
                e.printStackTrace();
            } finally {
                System.out.flush();
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
            if (ptr == BUF_SIZE) innerflush();
            return this;
        }

        public FastPrintStream print(char c) {
            return print((byte) c);
        }

        public FastPrintStream print(char[] s) {
            for (char c : s) {
                buf[ptr++] = (byte) c;
                if (ptr == BUF_SIZE) innerflush();
            }
            return this;
        }

        public FastPrintStream print(String s) {
            s.chars().forEach(c -> {
                buf[ptr++] = (byte) c;
                if (ptr == BUF_SIZE) innerflush();
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
                    if (ptr == BUF_SIZE) innerflush();
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

        public FastPrintStream print(int x) {
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

        public FastPrintStream print(long x) {
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

        public FastPrintStream println(Object o) {
            return o != null ? println(o.toString()) : println("null");
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

        public FastPrintStream println(double x, int precision) {
            return print(x, precision).println();
        }

        public FastPrintStream println() {
            return print((byte) '\n');
        }

        public FastPrintStream printf(String format, Object... args) {
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
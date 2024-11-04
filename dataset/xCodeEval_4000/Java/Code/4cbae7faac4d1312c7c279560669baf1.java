import java.io.*;
import java.text.MessageFormat;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.util.Random;
import java.util.function.IntFunction;
import java.util.function.IntUnaryOperator;
import java.util.function.Predicate;


public class C {

    final boolean ONLINE_JUDGE = java.lang.System.getProperty("ONLINE_JUDGE") != null;

     int solveOneNaive(int n, char[] s, int[] segment){
         int ans = Integer.MAX_VALUE;
         int ones = 0;
         int zeros = 0;
         for(int i = 0; i < n ; i  ++) {
             if(s[i] == '1') ones++; else zeros++;
         }
         for(int l = 0; l < n; l++) {
             for (int r = 0; r < n; r++) {
                 if(l <= r) {
                     int remainingZeros = zeros;
                     int removedOnes = 0;
                     for(int i = 0; i < l; i++) {
                         if(s[i] == '1') removedOnes++; else remainingZeros--;
                     }

                     for(int i = r + 1; i < n; i++) {
                         if(s[i] == '1') removedOnes++; else remainingZeros--;
                     }
                     int localAns = Math.max(remainingZeros, removedOnes);
                     if(ans > localAns) {
                         ans = localAns;
                         segment[0] = l;
                         segment[1] = r;
                     }
                 }
             }
         }
         {
            int localAns = Math.max(zeros, 0);
             if(ans > localAns) {
                 ans = localAns;
                 segment[0] = 0;
                 segment[1] = n - 1;
             }
         }
         {
             int localAns = Math.max(0, ones);
             if(ans > localAns) {
                 ans = localAns;
                 segment[0] = -1;
                 segment[1] = -1;
             }
         }
         return ans;
     }

    private int solveOne(int n, char[] s) {
        int[] p0 = new int[n];
        int[] p1 = new int[n];
        p0[0] = s[0] == '0' ? 1 : 0;
        p1[0] = s[0] == '1' ? 1 : 0;

        int[] s0 = new int[n];
        int[] s1 = new int[n];
        s0[n - 1] = s[n - 1] == '0' ? 1 : 0;
        s1[n - 1] = s[n - 1] == '1' ? 1 : 0;

        for (int i = 1; i < n; i++) {
            p0[i] = p0[i - 1] + (s[i] == '0' ? 1 : 0);
            p1[i] = p1[i - 1] + (s[i] == '1' ? 1 : 0);
        }

        for (int i = n - 2; i >= 0; i--) {
            s0[i] = s0[i + 1] + (s[i] == '0' ? 1 : 0);
            s1[i] = s1[i + 1] + (s[i] == '1' ? 1 : 0);
        }

        int ans = Math.min(s0[0], s1[0]);
        for (int i = -1; i < n; i++) {
            

            int removedOnes = i == -1 ? 0 : p1[i];
            int stayedZeros = i == -1 ? p0[n - 1] : p0[n - 1] - p0[i];

            int localAns = Math.max(removedOnes, stayedZeros);
            IntUnaryOperator ansFor = ind -> Math.max(removedOnes + s1[ind], stayedZeros - s0[ind]);
            

            if (i < n - 1) {
                int j = upperBound(
                        i,
                        n,
                        ind -> removedOnes + s1[ind] >= stayedZeros - s0[ind]);
                localAns = Math.min(localAns, ansFor.applyAsInt(j));
            } else {
                

            }
            ans = Math.min(ans, localAns);
        }
        return ans;
    }

    private int upperBound(int inclusiveLeft, int exclusiveRight, Predicate<Integer> predicate) {
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

    private int lowerBound(int exclusiveLeft, int inclusiveRight, Predicate<Integer> predicate) {
        return upperBound(exclusiveLeft, inclusiveRight, predicate.negate()) + 1;
    }

    private int ternarySearch(int left, int right, IntFunction<Integer> func) {
        while (right - left > 2) {
            int mid1 = left + (right - left) / 3;
            int mid2 = right - (right - left) / 3;
            if (func.apply(mid1) < func.apply(mid2)) {
                right = mid2;
            } else {
                left = mid1;
            }
        }
        return left;
    }

    

    

    

    

    

    

    

    

    

    

    

    

    

    


    private void solveOne_() {
        

        char[] s = nextString().toCharArray();
        int n = s.length;
        int leftOne = -1;
        int rightOne = n;
        for (int i = 0; i < n; i++) {
            if (s[i] == '1') {
                leftOne = i;
                break;
            }
        }
        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == '1') {
                rightOne = i;
                break;
            }
        }

        if (leftOne == -1) {
            System.out.println(0);
            return;
        }

        

        

        int removedOnes = 0;
        int stayedZeros = 0;
        for (int i = leftOne; i <= rightOne; i++) {
            if (s[i] == '0') {
                stayedZeros++;
            }
        }
        

        int ans = Math.max(removedOnes, stayedZeros);

        

        int[] canRemoveOnesRight = new int[n];
        int[] canRemoveZerosRight = new int[n];
        int[] nextRight = new int[n];
        {
            int cur1 = 0;
            int cur0 = 0;
            int cur1Ind = -1;
            for (int i = leftOne; i < n; i++) {
                if ((i == 0 || s[i - 1] == '0') && s[i] == '1') {
                    cur1Ind = i;
                    cur1 = 0;
                    cur0 = 0;
                }
                if (s[i] == '1') {
                    cur1++;
                }
                if (s[i] == '0') {
                    cur0++;
                }

                if (s[i] == '0' && (i == n - 1 || s[i + 1] == '1')) {
                    canRemoveOnesRight[cur1Ind] = cur1;
                    canRemoveZerosRight[cur1Ind] = cur0;
                    nextRight[cur1Ind] = i + 1;
                }
            }
        }
        int[] canRemoveOnesLeft = new int[n];
        int[] canRemoveZerosLeft = new int[n];
        int[] nextLeft = new int[n];

        {
            int cur1 = 0;
            int cur0 = 0;
            int cur1Ind = -1;
            for (int i = rightOne; i >= 0; i--) {
                if ((i == n - 1 || s[i + 1] == '0') && s[i] == '1') {
                    cur1Ind = i;
                    cur1 = 0;
                    cur0 = 0;
                }
                if (s[i] == '1') {
                    cur1++;
                }
                if (s[i] == '0') {
                    cur0++;
                }

                if (s[i] == '0' && (i == 0 || s[i - 1] == '1')) {
                    canRemoveOnesLeft[cur1Ind] = cur1;
                    canRemoveZerosLeft[cur1Ind] = cur0;
                    nextLeft[cur1Ind] = i - 1;
                }
            }
        }












        for (int l = leftOne, r = rightOne; ; ) {

            if (nextRight[l] > r) {
                

                break;
            }

            

            int localAnsLeft = Math.max(removedOnes + canRemoveOnesRight[l], stayedZeros - canRemoveZerosRight[l]);
            int localAnsRight = Math.max(removedOnes + canRemoveOnesLeft[r], stayedZeros - canRemoveZerosLeft[r]);
            if (localAnsLeft < ans || localAnsRight < ans) {
                if (localAnsRight <= localAnsLeft) {
                    removedOnes += canRemoveOnesLeft[r];
                    stayedZeros -= canRemoveZerosLeft[r];
                    r = nextLeft[r];
                } else {
                    removedOnes += canRemoveOnesRight[l];
                    stayedZeros -= canRemoveZerosRight[l];
                    l = nextRight[l];
                }
                ans = Math.max(removedOnes, stayedZeros);
            } else {
                break;
            }

        }

        System.out.println(ans);


    }



    boolean ANTI_TEST_GENERATOR = false;

    private void solve() {
        if (!ANTI_TEST_GENERATOR) {
            int t = nextInt();
            for (int tt = 0; tt < t; tt++) {
                char[] s = nextString().toCharArray();
                int n = s.length;
                int ans = solveOne(n, s);
                System.out.println(ans);
            }
        } else {
            Random r = new Random(42);
            for(int testCase = 0; testCase < 10_000; testCase++) {
                int n = 5 + r.nextInt(5);
                char[] s = new char[n];
                for(int i = 0; i  < n; i ++) {
                    s[i] = r.nextBoolean() ? '1' : '0';
                }
                int[] segment = new int[2];
                int expected = solveOneNaive(n, s, segment);
                int actual = solveOne(n, s);
                if(expected != actual) {
                    throw new AssertionRuntimeException(testCase,
                            expected, actual, n, s, segment);
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
        new C().run();
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